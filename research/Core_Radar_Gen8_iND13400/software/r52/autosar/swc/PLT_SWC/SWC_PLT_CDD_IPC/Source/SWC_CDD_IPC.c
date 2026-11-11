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
 *             File:  SWC_CDD_IPC.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_CDD_IPC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_CDD_IPC>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dt_Fault_name_FHTI
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_Wdg_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_CDD_IPC.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* This header file is included to fetch the IPC data types defined */
#include "debug_stream.h"
#include "ipc_data.h"
/* This header file is included to get the memcpy functions */
#include "VSE_Core.h"
#include "VSE_Teststub.h"
#include "WdgM_Cfg.h"
#include "crc_calc.h"
#include "ipc_mss.h"
#include "program_flow_monitor.h"
#include "sh_module_cfg.h"
#include "sra_types.h"
#include "string.h"
#define ENABLE_VSE_TEST_STUBS FALSE

#if ENABLE_VSE_TEST_STUBS

static double g_vse_time = 0.0;
#endif

#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint8_t test_ipc_crc_var         = 0;
volatile uint8 test_Injection_control_ipc = 0;
volatile uint8 test_Failure_Type_ipc      = 0;
void Test_IPC_Alignment_Data_Set(Dt_Alignment_IPC_Data *alignment_ipc_data);
void Test_IPC_SIT_Fault_Injection(Dt_RadarCapability_Faults *diag_ipc_faults);
#endif
#if (TRUE == ENABLE_SQT_TEST_STUBS)
void Test_IPC_SQT_RadarCapability_Faults_Set(void);
#endif
#ifdef XCP_FAULT_INJECTION
   #define FIT_IPC_FAILURE   0x03U
   #define INJECT_R52_FAULT  0x00U
   #define INJECT_BBE_FAULT  0x01U
   #define REMOVE_ALL_FAULTS 0x02U
#endif
#define NS_2_S (1.0e-9f)
volatile uint8_t Pfm_Monitor_Status = FALSE; /* TODO: Can be removed once program flow monitor is enabled*/

/* TODO: Move this API to ipc_mss.c, once RTE cleanup is done between
         Rte_SWC_PLT_CDD_Radar_Control.h and Rte
         _SWC_CDD_IPC.h */
void Fetch_IPC_Data(D2M_Msg_T *);
/*To Do to be handled via RTE*/
#if defined(VEH_AL_CAN_STANDALONE)
extern void Populate_Veh_Data_On_Ipc(void);
#endif
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
 * Rte_DT_Dt_StaticRegCheckFailureInfo_0: Integer in interval [0...255]
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_Fault_name_FHTI: Enumeration of integer in interval [0...255] with enumerators
 *   SMC_CHECKSUM_FAULT (0U)
 *   USC_VALIDATION_FAULT (1U)
 *   MMIC_B_ID_FAULT (2U)
 *   MMIC_TEMPERATURE_HIGH_FAULT (3U)
 *   MMIC_TEMPERATURE_LOW_FAULT (4U)
 *   MMIC_A_SAFESTART (5U)
 *   MMIC_B_SAFESTART (6U)
 *   MMIC_A_SAFETY_INTEGRITY_RFBIST (7U)
 *   MMIC_A_SENSOR_FAULT (8U)
 *   MMIC_TEMPERATURE_CONSISTANCY_FAILURE (9U)
 *   PLATFORM_TIME_FAULT (10U)
 *   TX_BALL_BREAK_FAULT (11U)
 *   BLOCKAGE_ALGO_ERROR_FAULT (12U)
 *   MCU_STARTUP_FAULT (13U)
 *   MCU_REPETATIVE_RESET_FAULT (14U)
 *   A53_TO_CM7_IPC_FAULT (15U)
 *   CM7_TO_DSP_IPC_FAULT (16U)
 *   EDMA_FAULT_CALIBRATION (17U)
 *   DSP_TO_A53_IPC_FAULT (18U)
 *   DSP_TO_CM7_IPC_FAULT (19U)
 *   MAX_FAULT_NUMBER (20U)
 * Dt_Wdg_Type: Enumeration of integer in interval [0...255] with enumerators
 *   INT_WDG (0U)
 *   EXT_WDG (1U)
 *   INT_EXT_WDG (2U)
 *
 * Array Types:
 * ============
 * Dt_StaticRegCheckFailureInfo: Array with 35 element(s) of type Rte_DT_Dt_StaticRegCheckFailureInfo_0
 * Rte_DT_Dt_DRA_Core_Log_Data_22: Array with 24 element(s) of type uint32
 * Rte_DT_Dt_DRA_Core_Log_Data_23: Array with 24 element(s) of type uint32
 * Rte_DT_Dt_DRA_Core_Log_Data_42: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Dynamic_Alignment_Data_30: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Dynamic_Alignment_Data_6: Array with 4 element(s) of type float32
 *
 * Record Types:
 * =============
 * Dt_Alignment_IPC_Data: Record with elements
 *   dra_core_log_data of type Dt_DRA_Core_Log_Data
 *   sra_core_log_data of type Dt_SRA_Core_Log_Data
 *   alignment_static of type Dt_Alignment_Static
 *   veh_info of type Dt_Veh_Info
 *   alignment_stream of type Dt_Alignment_Stream
 *   alignment_mode of type uint8
 *   interference_detected of type uint8
 *   blockage_active of type boolean
 *   operation_mode_status of type uint8
 *   data_qualifier of type uint8
 *   look_index of type uint32
 * Dt_Alignment_M2D_Data: Record with elements
 *   static_alignment_data of type Dt_Static_Alignment_Data
 *   dynamic_alignment_data of type Dt_Dynamic_Alignment_Data
 * Dt_Alignment_Static: Record with elements
 *   StatusOfPlate of type uint8
 *   StatusOfAzimuth of type uint8
 *   StatusOfElevation of type uint8
 * Dt_Alignment_Stream: Record with elements
 *   horiz_misalign_ang of type float32
 *   vert_misalign_ang of type float32
 *   std_azimuth of type float32
 *   std_elevation of type float32
 *   meas_plate_range of type float32
 *   meas_plate_r_dot of type float32
 *   meas_plate_rcs of type float32
 *   std_range of type float32
 *   std_r_dot of type float32
 *   complete_percentage of type float32
 *   status_of_plate of type uint8
 *   status_horiz_misalign_ang of type uint8
 *   status_vert_misalign_ang of type uint8
 * Dt_DRA_Core_Log_Data: Record with elements
 *   vacs_boresight_az_estimated of type float32
 *   vacs_boresight_el_estimated of type float32
 *   estimated_standard_deviation_az of type float32
 *   estimated_standard_deviation_el of type float32
 *   alignment_complete_percent_az of type float32
 *   alignment_complete_percent_el of type float32
 *   total_time_since_start of type float32
 *   total_time_running_az_scf of type float32
 *   total_time_running_el of type float32
 *   total_distance_since_start of type float32
 *   total_distance_running_az_scf of type float32
 *   total_distance_running_el of type float32
 *   avg_spd_since_start of type float32
 *   avg_spd_running_az_scf of type float32
 *   avg_spd_running_el of type float32
 *   estimated_pos_error_bound_az of type float32
 *   estimated_pos_error_bound_el of type float32
 *   estimated_neg_error_bound_az of type float32
 *   estimated_neg_error_bound_el of type float32
 *   speed_compensation_factor_estimated of type float32
 *   n_updates_azimuth of type uint32
 *   n_updates_elevation of type uint32
 *   detection_used_az of type Rte_DT_Dt_DRA_Core_Log_Data_22
 *   detection_used_el of type Rte_DT_Dt_DRA_Core_Log_Data_23
 *   alignment_mode of type uint8
 *   error_status_detection_input of type uint8
 *   azimuth_estimation_qf of type uint8
 *   elevation_estimation_qf of type uint8
 *   error_status_az_est_out_of_bounds of type uint8
 *   error_status_el_est_out_of_bounds of type uint8
 *   error_status_initialization of type uint8
 *   error_status_excessive_blockage of type uint8
 *   error_status_vehicle_input of type uint8
 *   detection_coordinate_system of type uint8
 *   error_status_scf_out_of_bounds of type uint8
 *   error_status_combined of type uint8
 *   error_status_interference of type uint8
 *   scf_estimation_qf of type uint8
 *   n_updates_roll of type uint32
 *   vacs_boresight_roll_initial of type float32
 *   vacs_boresight_roll_kf_internal of type float32
 *   vacs_boresight_roll_estimated of type float32
 *   el_roll_kf_covariance of type Rte_DT_Dt_DRA_Core_Log_Data_42
 *   alignment_index of type uint32
 *   vacs_boresight_az_kf_internal of type float32
 *   vacs_boresight_el_kf_internal of type float32
 *   estimated_standard_deviation_rl of type float32
 *   estimated_pos_error_bound_rl of type float32
 *   estimated_neg_error_bound_rl of type float32
 *   num_cycles_since_well_converged of type uint32
 *   flag_well_converged_az_el of type uint8
 *   interference_detected of type uint8
 *   blockage_active of type boolean
 *   coordinate_system of type uint8
 *   error_status_sudden_state_change of type uint8
 *   error_status_parking_accident of type uint8
 *   vacs_boresight_az_nominal of type float32
 *   vacs_boresight_el_nominal of type float32
 *   error_status_trailer_detected of type uint8
 * Dt_Dynamic_Alignment_Data: Record with elements
 *   initial_vacs_boresight_az_estimated of type float32
 *   initial_vacs_boresight_el_estimated of type float32
 *   initial_speed_compensation_factor of type float32
 *   max_abs_misalignment_az of type float32
 *   short_track_target_height of type float32
 *   short_track_target_range_rate of type float32
 *   az_scf_kf_covariance of type Rte_DT_Dt_Dynamic_Alignment_Data_6
 *   el_kf_covariance of type float32
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
 *   initial_vacs_boresight_rl_estimated of type float32
 *   initial_num_updates_rl of type uint8
 *   el_roll_kf_covariance of type Rte_DT_Dt_Dynamic_Alignment_Data_30
 *   Align_RadarOperation_Mode of type uint8
 *   coordinate_system_input of type uint8
 * Dt_IPC_Faults: Record with elements
 *   IPC_M2D_Crc_Err_Cnt of type uint32
 *   IPC_D2M_Crc_Err_Cnt of type uint32
 *   IPC_D2A_Crc_Err_Cnt of type uint32
 *   IPC_A2M_Crc_Err_Cnt of type uint32
 * Dt_RadarCapability_Faults: Record with elements
 *   SLL_Fault of type uint8
 *   Range_Estimation_Fault of type uint8
 *   Blockage_Fault of type uint8
 *   Damping_Estimation_Fault of type uint8
 *   SPT_Fault of type uint8
 *   Safety_Integrity_Fault of type uint8
 *   Core_Self_Test_Fault of type uint8
 *   Detection_Procession_Loop_Overrun_Fault of type uint8
 *   Firstpass_Saturation_Fault of type uint8
 *   Dsp_Internal_Fault of type uint8
 *   Detection_Data_Integrity_Fault of type uint8
 * Dt_SRA_Core_Log_Data: Record with elements
 *   vacs_boresight_az_nominal of type float32
 *   vacs_boresight_az_estimated of type float32
 *   vacs_boresight_el_nominal of type float32
 *   vacs_boresight_el_estimated of type float32
 *   estimated_standard_deviation_az of type float32
 *   estimated_standard_deviation_el of type float32
 *   target_mean_azimuth of type float32
 *   target_mean_elevation of type float32
 *   target_mean_range of type float32
 *   target_mean_r_dot of type float32
 *   target_mean_raw_amp of type float32
 *   target_mean_snr of type float32
 *   target_std_dev_azimuth of type float32
 *   target_std_dev_elevation of type float32
 *   target_std_dev_range of type float32
 *   target_std_dev_r_dot of type float32
 *   target_std_dev_raw_amp of type float32
 *   target_std_dev_snr of type float32
 *   complete_percentage of type float32
 *   n_updates_az_el of type uint32
 *   AlgoStatus of type uint8
 *   ErrorAzimuthEstimate of type uint8
 *   ErrorElevationEstimate of type uint8
 *   ErrorStatusInterference of type uint8
 *   ErrorStatusIntialisation of type uint8
 *   ErrorStatusDetection of type uint8
 *   ErrorStatusVehical of type uint8
 *   f_interference_detected of type uint8
 *   az_qf of type uint8
 *   el_qf of type uint8
 *   alignment_mode of type uint8
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
 *   max_abs_misalignment_az of type float32
 *   max_abs_misalignment_el_sky of type float32
 *   max_abs_misalignment_el_ground of type float32
 *   target_height_over_ground of type float32
 *   k_num_valid_scan_needed of type uint16
 *   k_max_number_of_scans_allowed of type uint16
 *   f_data_valid of type uint8
 * Dt_Veh_Info: Record with elements
 *   veh_speed of type float32
 *   veh_yaw of type float32
 *   veh_speed_qf of type uint8
 *   veh_yaw_qf of type uint8
 *   lros_drive_reverse of type uint8
 *
 *********************************************************************************************************************/

#define SWC_CDD_IPC_START_SEC_CODE
#include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_IPC_Fault_Injection
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_IPC_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_IPC_Fault_Injection(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_IPC_Fault_Injection_doc
 *********************************************************************************************************************/
volatile uint8_t Sra_Target_type = SRA_FLAT_PLATE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE)
CS_IPC_Fault_Injection(uint8 Injection_control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_IPC_Fault_Injection
    *********************************************************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   test_Injection_control_ipc = Injection_control;
   test_Failure_Type_ipc      = Failure_Type;
#endif
#ifdef XCP_FAULT_INJECTION
   if (FIT_IPC_FAILURE == Failure_Type)
   {
      if (INJECT_R52_FAULT == Injection_control)
      {
         Set_IPC_XCP_Fault_Injn_Var(R52_To_BBE_Fault);
      }
      else if (INJECT_BBE_FAULT == Injection_control)
      {
         Set_IPC_XCP_Fault_Injn_Var(BBE_To_R52_Fault);
      }
      else if (REMOVE_ALL_FAULTS == Injection_control)
      {
         Set_IPC_XCP_Fault_Injn_Var(NO_Fault);
      }
      else
      {
         /*Do nothing*/
      }
   }

#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dsp_sp_post_processing_complete
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by InternalTriggerOccurredEvent for InternalTriggeringPoint
 *<ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete> of runnable <RE_IPC_Trigger_50ms>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dsp_sp_post_processing_complete_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) Dsp_sp_post_processing_complete(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: Dsp_sp_post_processing_complete
    *********************************************************************************************************************/
   D2M_Msg_T *ipc_sp_post_buf_read_addr_raw = Get_IPC_Sp_Post_Buf_Read_Addr_Raw();
   volatile M2D_Msg_T *m2d_msg_ptr          = Get_MSS_IPC_M2D_Msg_Buffer();
   uint8_t hil_mode_active                  = m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled;

   if (CODED_TRUE == Check_D2M_Crc_Header(ipc_sp_post_buf_read_addr_raw) || (CODED_TRUE == hil_mode_active))
   {
      IPC_Sp_Post_Proc_Buf_Read_Addr = ipc_sp_post_buf_read_addr_raw;
      IPC_Sp_Post_Proc_Buf_Read_Idx  = Get_IPC_Sp_Post_Buf_Read_Idx_Raw();
   }
   if (NULL != IPC_Sp_Post_Proc_Buf_Read_Addr)
   {
      Fetch_IPC_Data(IPC_Sp_Post_Proc_Buf_Read_Addr);
   }
   else
   {
      /* Do Nothing */
   }

   Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream();
   Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream();
   Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream();

#ifdef ENABLE_CRC_TESTS
   /* Test CRC Channel 0 and SW CRC with known test vectors */
   g_crc_test_result = Test_CRC_Channels();
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CDD_IPC_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CDD_IPC_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_CDD_IPC_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_CDD_IPC_Init
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IPC_Rx_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(Dt_Alignment_M2D_Data *data)
 *
 * Trigger Interfaces:
 * ===================
 *   void Rte_Trigger_Pp_HIL_Periodic_Handler_Trigger(void)
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IPC_Rx_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Rx_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_IPC_Rx_50ms
    *********************************************************************************************************************/

   Dt_Alignment_M2D_Data alignment_m2d_data;
   volatile M2D_Msg_T *m2d_msg_ptr = Get_MSS_IPC_M2D_Msg_Buffer();
   Dynamic_Alignment_Data_T *p_dyn_align_data =
      (Dynamic_Alignment_Data_T *)&m2d_msg_ptr->payload.alignment_Info.dynamic_alignment_data;
   Static_Alignment_Data_T *p_static_align_data =
      (Static_Alignment_Data_T *)&m2d_msg_ptr->payload.alignment_Info.static_alignment_data;

   (void)Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(&alignment_m2d_data);

   if (PFM_NO_ERROR == PFM_Get_Status())
   {
      Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached(
         WdgMConf_WdgMCheckpoint_CP_Alive_Program_Flow_Monitoring);
   }

   // /* Update input data for Dyn alignment*/
   p_dyn_align_data->f_data_valid          = alignment_m2d_data.dynamic_alignment_data.f_data_valid;
   p_dyn_align_data->operation_mode_status = alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode;
   p_dyn_align_data->align_cmd             = alignment_m2d_data.dynamic_alignment_data.align_cmd;
   p_dyn_align_data->mount_loc             = alignment_m2d_data.dynamic_alignment_data.mount_loc;
   p_dyn_align_data->iso_sensor_yaw        = alignment_m2d_data.dynamic_alignment_data.iso_sensor_yaw;
   p_dyn_align_data->iso_sensor_pitch      = alignment_m2d_data.dynamic_alignment_data.iso_sensor_pitch;
   p_dyn_align_data->iso_sensor_roll       = alignment_m2d_data.dynamic_alignment_data.iso_sensor_roll;
   p_dyn_align_data->iso_sensor_y_posn     = alignment_m2d_data.dynamic_alignment_data.iso_sensor_y_posn;
   p_dyn_align_data->iso_sensor_x_posn     = alignment_m2d_data.dynamic_alignment_data.iso_sensor_x_posn;
   p_dyn_align_data->iso_sensor_z_posn     = alignment_m2d_data.dynamic_alignment_data.iso_sensor_z_posn;
   p_dyn_align_data->distance_rear_axle_to_front_bumper =
      alignment_m2d_data.dynamic_alignment_data.distance_rear_axle_to_front_bumper;
   p_dyn_align_data->initial_vacs_boresight_az_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated;
   p_dyn_align_data->initial_vacs_boresight_el_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated;
   p_dyn_align_data->initial_vacs_boresight_rl_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated;
   p_dyn_align_data->initial_speed_compensation_factor =
      alignment_m2d_data.dynamic_alignment_data.initial_speed_compensation_factor;
   p_dyn_align_data->initial_num_updates_az         = alignment_m2d_data.dynamic_alignment_data.initial_num_updates_az;
   p_dyn_align_data->initial_num_updates_el         = alignment_m2d_data.dynamic_alignment_data.initial_num_updates_el;
   p_dyn_align_data->initial_num_updates_rl         = alignment_m2d_data.dynamic_alignment_data.initial_num_updates_rl;
   p_dyn_align_data->max_abs_misalignment_az        = alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_az;
   p_dyn_align_data->max_abs_misalignment_el_ground = alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_ground;
   p_dyn_align_data->max_abs_misalignment_el_sky    = alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_sky;
   p_dyn_align_data->short_track_target_height      = alignment_m2d_data.dynamic_alignment_data.short_track_target_height;
   p_dyn_align_data->short_track_target_range_rate  = alignment_m2d_data.dynamic_alignment_data.short_track_target_range_rate;
   p_dyn_align_data->az_scf_kf_covariance[0]        = alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[0];
   p_dyn_align_data->az_scf_kf_covariance[1]        = alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[1];
   p_dyn_align_data->az_scf_kf_covariance[2]        = alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[2];
   p_dyn_align_data->az_scf_kf_covariance[3]        = alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[3];
   p_dyn_align_data->el_roll_kf_covariance[0]       = alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[0];
   p_dyn_align_data->el_roll_kf_covariance[1]       = alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[1];
   p_dyn_align_data->el_roll_kf_covariance[2]       = alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[2];
   p_dyn_align_data->el_roll_kf_covariance[3]       = alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[3];
   p_dyn_align_data->short_track_exit_condition     = alignment_m2d_data.dynamic_alignment_data.short_track_exit_condition;
   p_dyn_align_data->coordinate_system_input =
      (DRA_Detection_Coordinate_System_T)alignment_m2d_data.dynamic_alignment_data.coordinate_system_input;

   p_dyn_align_data->alignment_handler_out.auto_align_status   = alignment_m2d_data.dynamic_alignment_data.auto_align_status;
   p_dyn_align_data->alignment_handler_out.aacurrent_azimuth   = alignment_m2d_data.dynamic_alignment_data.aacurrent_azimuth;
   p_dyn_align_data->alignment_handler_out.aacurrent_elevation = alignment_m2d_data.dynamic_alignment_data.aacurrent_elevation;

   p_dyn_align_data->azimuth_estimation_qf   = (uint8_t)alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_az;
   p_dyn_align_data->elevation_estimation_qf = (uint8_t)alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_el;
   p_dyn_align_data->scf_estimation_qf       = (uint8_t)alignment_m2d_data.dynamic_alignment_data.iso_sensor_z_posn;

   /* Update input data for Static alignment*/
   p_static_align_data->f_data_valid                   = alignment_m2d_data.static_alignment_data.f_data_valid;
   p_static_align_data->align_cmd                      = alignment_m2d_data.static_alignment_data.align_cmd;
   p_static_align_data->mount_loc                      = alignment_m2d_data.static_alignment_data.mount_loc;
   p_static_align_data->plate_lat_position             = alignment_m2d_data.static_alignment_data.plate_lat_position;
   p_static_align_data->vert_angle_max                 = alignment_m2d_data.static_alignment_data.vert_angle_max;
   p_static_align_data->vert_angle_min                 = alignment_m2d_data.static_alignment_data.vert_angle_min;
   p_static_align_data->horz_angle_max                 = alignment_m2d_data.static_alignment_data.horz_angle_max;
   p_static_align_data->horz_angle_min                 = alignment_m2d_data.static_alignment_data.horz_angle_min;
   p_static_align_data->polarity                       = alignment_m2d_data.static_alignment_data.polarity;
   p_static_align_data->plate_distance                 = alignment_m2d_data.static_alignment_data.plate_distance;
   p_static_align_data->plate_angle_deg_scs            = alignment_m2d_data.static_alignment_data.plate_angle_deg_scs;
   p_static_align_data->pitch                          = alignment_m2d_data.static_alignment_data.pitch;
   p_static_align_data->yaw                            = alignment_m2d_data.static_alignment_data.yaw;
   p_static_align_data->max_abs_misalignment_az        = alignment_m2d_data.static_alignment_data.max_abs_misalignment_az;
   p_static_align_data->max_abs_misalignment_el_sky    = alignment_m2d_data.static_alignment_data.max_abs_misalignment_el_sky;
   p_static_align_data->max_abs_misalignment_el_ground = alignment_m2d_data.static_alignment_data.max_abs_misalignment_el_ground;
   p_static_align_data->target_height_over_ground      = alignment_m2d_data.static_alignment_data.target_height_over_ground;
   p_static_align_data->k_num_valid_scan_needed        = alignment_m2d_data.static_alignment_data.k_num_valid_scan_needed;
   p_static_align_data->k_max_number_of_scans_allowed  = alignment_m2d_data.static_alignment_data.k_max_number_of_scans_allowed;
   p_static_align_data->target_type_select             = Sra_Target_type;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IPC_Trigger_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(Dt_Fault_name_FHTI data)
 *
 * Internal Trigger Interfaces:
 * ============================
 *   Unqueued Internal Triggering:
 *   -----------------------------
 *   void Rte_IrTrigger_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms(void)
 *   void Rte_IrTrigger_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Wdg_Disable_Read(Dt_Wdg_Type Wdg_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation(void)
 *     Asynchronous Server Invocation
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IPC_Trigger_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Trigger_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_IPC_Trigger_50ms
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IPC_Tx_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data(const Dt_Alignment_IPC_Data *data)
 *   Std_ReturnType Rte_Write_Pp_IPC_Faults_De_IPC_Faults(const Dt_IPC_Faults *data)
 *   Std_ReturnType Rte_Write_Pp_RadarCapability_Faults_De_RadarCapability_Faults(const Dt_RadarCapability_Faults *data)
 *   Std_ReturnType Rte_Write_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(const Rte_DT_Dt_StaticRegCheckFailureInfo_0
 **data) Argument data: Rte_DT_Dt_StaticRegCheckFailureInfo_0* is of type Dt_StaticRegCheckFailureInfo
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IPC_Tx_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_Tx_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_IPC_Tx_50ms
    *********************************************************************************************************************/

#if (TRUE == ENABLE_SQT_TEST_STUBS)
   Test_IPC_SQT_RadarCapability_Faults_Set();
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IPC_VSE_Handler_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IPC_VSE_Handler_10ms_doc
 *********************************************************************************************************************/
#if ENABLE_VSE_TEST_STUBS
void VSE_Input_Stub_Update(M2D_Msg_T *m2d_msg_ptr)
{
   build_vse_cycle(g_vse_time, &m2d_msg_ptr->payload.veh_data.veh_raw_data[0], &m2d_msg_ptr->payload.veh_data.veh_raw_misc,
                   &m2d_msg_ptr->payload.veh_data.veh_params, &m2d_msg_ptr->payload.veh_data.latest_raw_index);

   g_vse_time += 0.010;
   if (g_vse_time >= 9.0)
   {
      g_vse_time = 0.0;
   }
}
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_CDD_IPC_CODE) RE_IPC_VSE_Handler_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_IPC_VSE_Handler_10ms
    *********************************************************************************************************************/
   volatile M2D_Msg_T *m2d_msg_ptr = Get_MSS_IPC_M2D_Msg_Buffer();
#if ENABLE_VSE_TEST_STUBS
   VSE_Input_Stub_Update((M2D_Msg_T *)m2d_msg_ptr);
#endif
#ifdef VEH_AL_CAN_STANDALONE
   Populate_Veh_Data_On_Ipc();
   if ((CODED_TRUE != m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled) &&
       (CODED_TRUE != m2d_msg_ptr->payload.hil_ipc_info.hil_enabled_streams[VSE]))
   {
      Run_VSE(m2d_msg_ptr);
   }
#else
   (void)m2d_msg_ptr;
#endif // Temporarily moved this to also block Run_VSE until VID->VSE is completely fixed
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_CDD_IPC_STOP_SEC_CODE
#include "SWC_CDD_IPC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: runnable implementation:SWC_CDD_IPC_Init)  *******************************/
/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
 *. Name: Fetch_IPC_Data
 *. Extracts and forwards DSP-to-Master (D2M) IPC payload data to the R52 AUTOSAR layer.
 *.
 *. Reads the following from the D2M IPC buffer and writes via RTE:
 *.   - BBE32 static register readback fault flag
 *.   - Radar capability faults (Blockage, Damping, Range, SLL, Safety Integrity,
 *.     Core Self Test)
 *.   - IPC CRC error counters (M2D/D2M channels)
 *.   - DRA core log data (boresight estimates, alignment percentages, error statuses,
 *.     update counts, covariances)
 *.   - Vehicle info (speed, yaw, quality factors, drive direction)
 *.   - Static alignment stream output (misalignment angles, standard deviations,
 *.     plate measurements, status flags)
 *.
 *. Parameters:
 *.   d2m_msg_ptr [in] - Pointer to the current D2M IPC message buffer.
 *.                      Must not be NULL (caller is responsible for NULL check).
 *.
 *. Return Value: None
 *.
 *. Shared Variables:
 *.   Get_MSS_IPC_M2D_Msg_Buffer() [in]  - Current M2D buffer (vehicle data)
 *.   Get_IPC_M2D_Crc_Err_Cnt()   [in]  - M2D CRC error counter
 ******************************************************************************/
void Fetch_IPC_Data(D2M_Msg_T *d2m_msg_ptr)
{
   volatile M2D_Msg_T *m2d_msg_ptr                              = Get_MSS_IPC_M2D_Msg_Buffer();
   static Dt_StaticRegCheckFailureInfo bbe32_regChkFailed       = {0};
   Dt_Alignment_IPC_Data alignment_ipc_data                     = {0};
   Dt_RadarCapability_Faults diag_ipc_faults                    = {0};
   Dt_IPC_Faults ipc_crc_faults                                 = {0};
   DRA_Core_Log_Data_T *d2m_dra_core_data                       = &d2m_msg_ptr->payload.dynamic_alignment_log_stream.dra_core_data;
   Static_Alignment_Log_Stream_T *sfa_d2m_alignment_stream_data = &d2m_msg_ptr->payload.alignment_stream_data;
   volatile Vse_Output_T *p_vse_ouput                           = &m2d_msg_ptr->payload.veh_data.vse_output;
   volatile Veh_Raw_Misc_T *p_veh_raw_misc                      = &m2d_msg_ptr->payload.veh_data.veh_raw_misc;
   if ((uint8)d2m_msg_ptr->payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag == CODED_TRUE)
   {
      bbe32_regChkFailed[0] = TRUE;
      /* static register readback failed in DSS core. */
      (void)Rte_Write_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(&bbe32_regChkFailed[0]);
   }
   /* Blockage algo error*/
   diag_ipc_faults.Blockage_Fault = (uint8)d2m_msg_ptr->payload.radar_capability_data.fault_table.Blockage_Algo_Error;
   if (diag_ipc_faults.Blockage_Fault == TRUE)
   {
      diag_ipc_faults.Blockage_Fault = CODED_TRUE;
   }
   else
   {
      diag_ipc_faults.Blockage_Fault = CODED_FALSE;
   }
   /* Damping algo error*/
   diag_ipc_faults.Damping_Estimation_Fault = (uint8)d2m_msg_ptr->payload.radar_capability_data.fault_table.Damping_Algo_Error;
   if (diag_ipc_faults.Damping_Estimation_Fault == TRUE)
   {
      diag_ipc_faults.Damping_Estimation_Fault = CODED_TRUE;
   }
   else
   {
      diag_ipc_faults.Damping_Estimation_Fault = CODED_FALSE;
   }
   /*Range algo error*/
   diag_ipc_faults.Range_Estimation_Fault = (uint8)d2m_msg_ptr->payload.radar_capability_data.fault_table.Range_Algo_Error;
   if (diag_ipc_faults.Range_Estimation_Fault == TRUE)
   {
      diag_ipc_faults.Range_Estimation_Fault = CODED_TRUE;
   }
   else
   {
      diag_ipc_faults.Range_Estimation_Fault = CODED_FALSE;
   }
   /*Side lobe level monitoring error*/
   diag_ipc_faults.SLL_Fault = (uint8)d2m_msg_ptr->payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error;
   if (diag_ipc_faults.SLL_Fault == TRUE)
   {
      diag_ipc_faults.SLL_Fault = CODED_TRUE;
   }
   else
   {
      diag_ipc_faults.SLL_Fault = CODED_FALSE;
   }
   /*Safety Integrity Fault*/
   diag_ipc_faults.Safety_Integrity_Fault = d2m_msg_ptr->payload.diag_data.dsp_self_test_failure_flag;
   /*Core Self Test Fault*/
   diag_ipc_faults.Core_Self_Test_Fault = d2m_msg_ptr->payload.diag_data.dsp_self_test_failure_flag;
   /*Detection Processing Loop Overrun Fault*/
   if (CODED_TRUE == d2m_msg_ptr->payload.diag_data.detection_processing_loop_overrun_fault)
   {
      diag_ipc_faults.Detection_Procession_Loop_Overrun_Fault = CODED_TRUE;
   }
   else
   {
      diag_ipc_faults.Detection_Procession_Loop_Overrun_Fault = CODED_FALSE;
   }
   // if (CODED_TRUE == d2m_msg_ptr->payload.diag_data.detection_data_integrity_fault)
   // {
   //    diag_ipc_faults.Detection_Data_Integrity_Fault = CODED_TRUE;
   // }
   // else
   // {
   //    diag_ipc_faults.Detection_Data_Integrity_Fault = CODED_FALSE;
   // }
   /*Dsp_Internal_Fault*/
   diag_ipc_faults.Dsp_Internal_Fault = Get_HW_Accel_Test_Fault();

#if (TRUE == ENABLE_SIT_TEST_STUBS)
   Test_IPC_SIT_Fault_Injection(&diag_ipc_faults);
#endif

   (void)Rte_Write_Pp_RadarCapability_Faults_De_RadarCapability_Faults(&diag_ipc_faults);

   ipc_crc_faults.IPC_M2D_Crc_Err_Cnt = Get_IPC_M2D_Crc_Err_Cnt();
   ipc_crc_faults.IPC_D2M_Crc_Err_Cnt = Get_IPC_D2M_Crc_Err_Cnt();

#if (TRUE == ENABLE_SIT_TEST_STUBS)
   if (test_ipc_crc_var == 1)
   {
      ipc_crc_faults.IPC_M2D_Crc_Err_Cnt = CODED_TRUE;
      ipc_crc_faults.IPC_D2M_Crc_Err_Cnt = CODED_TRUE;
      ipc_crc_faults.IPC_D2A_Crc_Err_Cnt = CODED_TRUE;
      ipc_crc_faults.IPC_A2M_Crc_Err_Cnt = CODED_TRUE;
   }
   else if (test_ipc_crc_var == 2)
   {
      ipc_crc_faults.IPC_M2D_Crc_Err_Cnt = CODED_FALSE;
      ipc_crc_faults.IPC_D2M_Crc_Err_Cnt = CODED_FALSE;
      ipc_crc_faults.IPC_D2A_Crc_Err_Cnt = CODED_FALSE;
      ipc_crc_faults.IPC_A2M_Crc_Err_Cnt = CODED_FALSE;
   }
#endif
   Rte_Write_Pp_IPC_Faults_De_IPC_Faults(&ipc_crc_faults);
#if (TRUE == ENABLE_SQT_TEST_STUBS)
   Test_IPC_SQT_RadarCapability_Faults_Set();
#endif
   alignment_ipc_data.alignment_mode = d2m_msg_ptr->payload.alignment_stream_data.sra_core_data.alignment_mode;
   /*alignment_ipc_data.dra_core_log_data.interference_detected =
      d2m_msg_ptr->payload.interference_detection_data.interference_detected;*/
   alignment_ipc_data.dra_core_log_data.blockage_active = d2m_msg_ptr->payload.radar_capability_data.blockage.blockage_active;

   /*Detections are stored in detection_used_az and detection_used_el in binary bitwise encoded
   To get no_of_detections no of 1's in detection_used_az and detection_used_el to be counted*/
   (void)memcpy(alignment_ipc_data.dra_core_log_data.detection_used_az, d2m_dra_core_data->detection_used_az,
                sizeof(d2m_dra_core_data->detection_used_az));
   (void)memcpy(alignment_ipc_data.dra_core_log_data.detection_used_el, d2m_dra_core_data->detection_used_el,
                sizeof(d2m_dra_core_data->detection_used_el));

   alignment_ipc_data.dra_core_log_data.alignment_mode                  = d2m_dra_core_data->alignment_mode;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated     = d2m_dra_core_data->vacs_boresight_az_estimated;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated     = d2m_dra_core_data->vacs_boresight_el_estimated;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_az_nominal       = d2m_dra_core_data->vacs_boresight_az_nominal;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_el_nominal       = d2m_dra_core_data->vacs_boresight_el_nominal;
   alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_az = d2m_dra_core_data->estimated_standard_deviation_az;
   alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_el = d2m_dra_core_data->estimated_standard_deviation_el;
   alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_rl =
      0.0F; /*ToDo - To be updated once Algo Provides the data */
   alignment_ipc_data.dra_core_log_data.alignment_complete_percent_az = d2m_dra_core_data->alignment_complete_percent_az;
   alignment_ipc_data.dra_core_log_data.alignment_complete_percent_el = d2m_dra_core_data->alignment_complete_percent_el;
   alignment_ipc_data.dra_core_log_data.total_time_since_start        = d2m_dra_core_data->total_time_since_start;
   alignment_ipc_data.dra_core_log_data.total_time_running_az_scf     = d2m_dra_core_data->total_time_running_az_scf;
   alignment_ipc_data.dra_core_log_data.total_time_running_el         = d2m_dra_core_data->total_time_running_el;
   alignment_ipc_data.dra_core_log_data.total_distance_since_start    = d2m_dra_core_data->total_distance_since_start;
   alignment_ipc_data.dra_core_log_data.total_distance_running_az_scf = d2m_dra_core_data->total_distance_running_az_scf;
   alignment_ipc_data.dra_core_log_data.total_distance_running_el     = d2m_dra_core_data->total_distance_running_el;
   alignment_ipc_data.dra_core_log_data.avg_spd_since_start           = d2m_dra_core_data->avg_spd_since_start;
   alignment_ipc_data.dra_core_log_data.avg_spd_running_az_scf        = d2m_dra_core_data->avg_spd_running_az_scf;
   alignment_ipc_data.dra_core_log_data.avg_spd_running_el            = d2m_dra_core_data->avg_spd_running_el;
   alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_az  = d2m_dra_core_data->estimated_pos_error_bound_az;
   alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_el  = d2m_dra_core_data->estimated_pos_error_bound_el;
   alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_az  = d2m_dra_core_data->estimated_neg_error_bound_az;
   alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_el  = d2m_dra_core_data->estimated_neg_error_bound_el;
   alignment_ipc_data.dra_core_log_data.speed_compensation_factor_estimated =
      d2m_dra_core_data->speed_compensation_factor_estimated;
   alignment_ipc_data.dra_core_log_data.n_updates_azimuth                 = d2m_dra_core_data->n_updates_azimuth;
   alignment_ipc_data.dra_core_log_data.n_updates_elevation               = d2m_dra_core_data->n_updates_elevation;
   alignment_ipc_data.dra_core_log_data.n_updates_roll                    = d2m_dra_core_data->n_updates_roll;
   alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf             = d2m_dra_core_data->azimuth_estimation_qf;
   alignment_ipc_data.dra_core_log_data.elevation_estimation_qf           = d2m_dra_core_data->elevation_estimation_qf;
   alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds = d2m_dra_core_data->error_status_az_est_out_of_bounds;
   alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds = d2m_dra_core_data->error_status_el_est_out_of_bounds;
   alignment_ipc_data.dra_core_log_data.error_status_initialization       = d2m_dra_core_data->error_status_initialization;
   alignment_ipc_data.dra_core_log_data.error_status_excessive_blockage   = d2m_dra_core_data->error_status_excessive_blockage;
   alignment_ipc_data.dra_core_log_data.error_status_vehicle_input        = d2m_dra_core_data->error_status_vehicle_input;
   alignment_ipc_data.dra_core_log_data.detection_coordinate_system       = d2m_dra_core_data->detection_coordinate_system;
   alignment_ipc_data.dra_core_log_data.error_status_scf_out_of_bounds    = d2m_dra_core_data->error_status_scf_out_of_bounds;
   alignment_ipc_data.dra_core_log_data.error_status_combined             = d2m_dra_core_data->error_status_combined;
   alignment_ipc_data.dra_core_log_data.error_status_interference         = d2m_dra_core_data->error_status_interference;
   alignment_ipc_data.dra_core_log_data.error_status_detection_input      = d2m_dra_core_data->error_status_detection_input;
   alignment_ipc_data.dra_core_log_data.error_status_sudden_state_change  = d2m_dra_core_data->error_status_sudden_state_change;
   alignment_ipc_data.dra_core_log_data.error_status_parking_accident     = d2m_dra_core_data->error_status_parking_accident;
   alignment_ipc_data.dra_core_log_data.scf_estimation_qf                 = d2m_dra_core_data->scf_estimation_qf;

   /*Updating the Veh_info data to alignment */
   alignment_ipc_data.veh_info.veh_speed          = p_vse_ouput->raw_speed_mps;
   alignment_ipc_data.veh_info.veh_yaw            = p_vse_ouput->raw_yaw_rate_rps;
   alignment_ipc_data.veh_info.veh_speed_qf       = p_veh_raw_misc->ego_vehicle_speed_qf;
   alignment_ipc_data.veh_info.veh_yaw_qf         = p_veh_raw_misc->ego_yaw_rate_qf;
   alignment_ipc_data.veh_info.lros_drive_reverse = (p_veh_raw_misc->gear_pos == 1u) ? 1 : 0;

   /*Updating the alignment_stream data to alignment */
   alignment_ipc_data.sra_core_log_data.vacs_boresight_az_nominal =
      sfa_d2m_alignment_stream_data->sra_core_data.vacs_boresight_az_nominal;
   alignment_ipc_data.sra_core_log_data.vacs_boresight_az_estimated =
      sfa_d2m_alignment_stream_data->sra_core_data.vacs_boresight_az_estimated;
   alignment_ipc_data.sra_core_log_data.vacs_boresight_el_nominal =
      sfa_d2m_alignment_stream_data->sra_core_data.vacs_boresight_el_nominal;
   alignment_ipc_data.sra_core_log_data.vacs_boresight_el_estimated =
      sfa_d2m_alignment_stream_data->sra_core_data.vacs_boresight_el_estimated;
   alignment_ipc_data.sra_core_log_data.estimated_standard_deviation_az =
      sfa_d2m_alignment_stream_data->sra_core_data.estimated_standard_deviation_az;
   alignment_ipc_data.sra_core_log_data.estimated_standard_deviation_el =
      sfa_d2m_alignment_stream_data->sra_core_data.estimated_standard_deviation_el;
   alignment_ipc_data.sra_core_log_data.target_mean_azimuth = sfa_d2m_alignment_stream_data->sra_core_data.target_mean_azimuth_raw;
   alignment_ipc_data.sra_core_log_data.target_mean_elevation =
      sfa_d2m_alignment_stream_data->sra_core_data.target_mean_elevation_raw;
   alignment_ipc_data.sra_core_log_data.target_mean_range   = sfa_d2m_alignment_stream_data->sra_core_data.target_mean_range;
   alignment_ipc_data.sra_core_log_data.target_mean_r_dot   = sfa_d2m_alignment_stream_data->sra_core_data.target_mean_range_rate;
   alignment_ipc_data.sra_core_log_data.target_mean_raw_amp = sfa_d2m_alignment_stream_data->sra_core_data.target_mean_raw_amp;
   alignment_ipc_data.sra_core_log_data.target_mean_snr     = sfa_d2m_alignment_stream_data->sra_core_data.target_mean_snr;
   alignment_ipc_data.sra_core_log_data.target_std_dev_azimuth =
      sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_azimuth_raw;
   alignment_ipc_data.sra_core_log_data.target_std_dev_elevation =
      sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_elevation_raw;
   alignment_ipc_data.sra_core_log_data.target_std_dev_range = sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_range;
   alignment_ipc_data.sra_core_log_data.target_std_dev_r_dot =
      sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_range_rate;
   alignment_ipc_data.sra_core_log_data.target_std_dev_raw_amp =
      sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_raw_amp;
   alignment_ipc_data.sra_core_log_data.target_std_dev_snr = sfa_d2m_alignment_stream_data->sra_core_data.target_std_dev_snr;
   alignment_ipc_data.sra_core_log_data.complete_percentage =
      sfa_d2m_alignment_stream_data->sra_core_data.alignment_complete_percentage;
   alignment_ipc_data.sra_core_log_data.n_updates_az_el = sfa_d2m_alignment_stream_data->sra_core_data.n_updates_az_el;
   alignment_ipc_data.sra_core_log_data.AlgoStatus      = sfa_d2m_alignment_stream_data->sra_core_data.algo_status;
   alignment_ipc_data.sra_core_log_data.ErrorAzimuthEstimate =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_az_est_out_of_bounds;
   alignment_ipc_data.sra_core_log_data.ErrorElevationEstimate =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_el_est_out_of_bounds;
   alignment_ipc_data.sra_core_log_data.ErrorStatusInterference =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_interference;
   alignment_ipc_data.sra_core_log_data.ErrorStatusIntialisation =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_initialization;
   alignment_ipc_data.sra_core_log_data.ErrorStatusDetection =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_detection_input;
   alignment_ipc_data.sra_core_log_data.ErrorStatusVehical =
      sfa_d2m_alignment_stream_data->sra_core_data.error_status_vehicle_input;
   alignment_ipc_data.sra_core_log_data.f_interference_detected =
      sfa_d2m_alignment_stream_data->sra_core_data.f_interference_detected;
   alignment_ipc_data.sra_core_log_data.az_qf          = sfa_d2m_alignment_stream_data->sra_core_data.azimuth_estimation_qf;
   alignment_ipc_data.sra_core_log_data.el_qf          = sfa_d2m_alignment_stream_data->sra_core_data.elevation_estimation_qf;
   alignment_ipc_data.sra_core_log_data.alignment_mode = sfa_d2m_alignment_stream_data->sra_core_data.alignment_mode;

   alignment_ipc_data.dra_core_log_data.vacs_boresight_az_kf_internal = d2m_dra_core_data->vacs_boresight_az_kf_internal;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_el_kf_internal = d2m_dra_core_data->vacs_boresight_el_kf_internal;
   alignment_ipc_data.dra_core_log_data.alignment_index               = d2m_dra_core_data->alignment_index;
   alignment_ipc_data.look_index                                      = d2m_dra_core_data->look_index;

   /*alignment_ipc_data.dra_core_log_data.num_cycles_since_well_converged = d2m_dra_core_data->num_cycles_since_well_converged;
   alignment_ipc_data.dra_core_log_data.flag_well_converged_az_el       = d2m_dra_core_data->flag_well_converged_az_el;*/
   alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_kf_internal = d2m_dra_core_data->vacs_boresight_roll_kf_internal;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_initial     = d2m_dra_core_data->vacs_boresight_roll_initial;
   alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_estimated   = d2m_dra_core_data->vacs_boresight_roll_estimated;

   alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_rl = 0.0F;
   alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_rl    = 0.0F;
   alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_rl    = 0.0F;

/* data qualifier data */
#if (DOWNSELECTION_ENABLE == 1U)
   alignment_ipc_data.data_qualifier = (d2m_msg_ptr->payload.toi_ds_stream_data.toi_op_data.data_qualifier);
#else
   alignment_ipc_data.data_qualifier = (d2m_msg_ptr->payload.toi_stream_data.toi_op_data.data_qualifier);
#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   Test_IPC_Alignment_Data_Set(&alignment_ipc_data);
#endif

   /*Sending the Alignment data from IPC to Alignment*/
   Rte_Write_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data(&alignment_ipc_data);
}

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
