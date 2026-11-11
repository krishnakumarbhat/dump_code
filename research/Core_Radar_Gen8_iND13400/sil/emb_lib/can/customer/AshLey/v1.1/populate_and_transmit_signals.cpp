#include "populate_and_transmit_signals.h"
#include "autogen_message_decode_types.h"
#include "autogen_message_decode_types_VCAN.h"
#include "autogen_message_encoded_types.h"
#include "autogen_message_encoded_types_VCAN.h"
#include "can_message_id.h"
#include "can_sil_driver.h"
#include "cust_can_sil_iface.h"
#include "emblib_ipc_data.h"
#include "sil_version.h"
#include "sil_wrapper_common.h"

#include <cassert>
#include <cstring>

// D2M_Msg_T *ipc_d2m = Get_IPC_D2M_Buffer();
// A2M_Msg_T *ipc_a2m = Get_IPC_A2M_Buffer();

uint8_t buffer[MAX_CAN_MESSAGES];

extern "C" uint8_t RL_bsis_alert_level;
extern "C" uint8_t RL_BlindSpotDetectionState;
extern "C" uint8_t RL_BendOffPrbablityofMstImportatObj;
extern "C" uint8_t RL_BlindSpotWarnigRelevantObjDetect;

Sensor_decoded_types_t data_ptr;
Sensor_decoded_types_VCAN_t vcan_data_ptr;
Sensor_encoded_types_t e_ptr;
Sensor_encoded_types_VCAN_t vcan_e_ptr;

D2M_Msg_T *ipc_d2m                 = Get_IPC_D2M_Buffer();
M2D_Msg_T *ipc_m2d                 = Get_IPC_M2D_Buffer();
Status_Stream_T *status_stream_ptr = Get_Status_Log_Data_Ptr();
#if (DOWNSELECTION_ENABLE == 1U)
AF_DS_Str_Detection_T *af_target_report_ptr = ipc_d2m->payload.downselection_data.af_ds_dets;
TOI_DS_Det_List_Std_T *TOI_DS_Stream_Ptr    = &ipc_d2m->payload.toi_ds_stream_data.toi_op_data.toi_det_std;
#else
AF_Str_Detection_T *af_target_report_ptr = &ipc_d2m->payload.det_data.af_dets;
TOI_Stream_T *TOI_Stream_Ptr             = &ipc_d2m->payload.toi_stream_data.toi_op_data.toi_det_std;
#endif

void populate_Rear_can_signals(void);

void populate_FLR_object_data(void)
{
   SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr = Get_Sil_Radar_Input_Symbol_Ptr();

   memset(&data_ptr, 0, sizeof(Sensor_decoded_types_t));

   // FLR_IFV_SWVersion_decoded_msg_t
   data_ptr.FCM_IFV_SWVersion.SWVersion_MAJOR = 0;
   data_ptr.FCM_IFV_SWVersion.SWVersion_MINOR = 0;
   data_ptr.FCM_IFV_SWVersion.SWVersion_PATCH = 0;

   // FLR_HEADER_001_decoded_msg_t
   data_ptr.FLR_HEADER_001.HED_ALIGN_HOR_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal;
   data_ptr.FLR_HEADER_001.HED_ALIGN_VER_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal;
   data_ptr.FLR_HEADER_001.HED_Auth_CRC32 = 0; // need to be check
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.FLR_HEADER_001.HED_DATA_QUALIFIER = (ipc_d2m->payload.toi_ds_stream_data.toi_op_data.data_qualifier) - 1U;
#else
   data_ptr.FLR_HEADER_001.HED_DATA_QUALIFIER             = ipc_d2m->payload.toi_stream_data.toi_op_data.data_qualifier;
#endif
   data_ptr.FLR_HEADER_001.HED_DET_BI_STATIC_COUNT = CAN_SIG_NOT_IMPLEMENTED;

#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.FLR_HEADER_001.HED_DET_NUM_OF_1PASS        = ipc_d2m->payload.downselection_data.det_list_property.num_fp_detections;
   data_ptr.FLR_HEADER_001.HED_DET_NUM_OF_2PASS        = ipc_d2m->payload.downselection_data.det_list_property.num_sp_detections;
   data_ptr.FLR_HEADER_001.HED_NUM_OF_VALID_DETECTIONS = ipc_d2m->payload.downselection_data.num_af_ds_det;
   data_ptr.FLR_HEADER_001.HED_SENSOR_TIME_STAMP_NS    = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.FLR_HEADER_001.HED_SENSOR_TIME_STAMP_SEC   = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#else
   data_ptr.FLR_HEADER_001.HED_DET_NUM_OF_1PASS           = ipc_d2m->payload.det_data.det_list_property.num_fp_detections;
   data_ptr.FLR_HEADER_001.HED_DET_NUM_OF_2PASS           = ipc_d2m->payload.det_data.det_list_property.num_sp_detections;
   data_ptr.FLR_HEADER_001.HED_NUM_OF_VALID_DETECTIONS    = ipc_d2m->payload.det_data.num_af_ds_det;
   data_ptr.FLR_HEADER_001.HED_SENSOR_TIME_STAMP_NS       = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.FLR_HEADER_001.HED_SENSOR_TIME_STAMP_SEC      = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#endif

   data_ptr.FLR_HEADER_001.HED_FOV_HOR_MIN           = FXP2FLP_Fnc(k_fov_hor_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.FLR_HEADER_001.HED_FOV_HOR_MAX           = FXP2FLP_Fnc(k_fov_hor_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.FLR_HEADER_001.HED_FOV_VER_MIN           = FXP2FLP_Fnc(k_fov_ver_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.FLR_HEADER_001.HED_FOV_VER_MAX           = FXP2FLP_Fnc(k_fov_ver_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.FLR_HEADER_001.HED_LOOK_ID               = ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   data_ptr.FLR_HEADER_001.HED_SCAN_INDEX            = Get_Current_Scan_Index();
   data_ptr.FLR_HEADER_001.HED_MAX_NUM_OF_DETECTIONS = static_cast<uint8_t>(MAX_FLR_DETECTIONS);
   data_ptr.FLR_HEADER_001.HED_MH_CRC16              = 0;
   data_ptr.FLR_HEADER_001.HED_MH_CYCLE_COUNTER      = 0;

   data_ptr.FLR_HEADER_001.HED_NUM_OF_RESTBINS_USED = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_HEADER_001.HED_OPERATION_MODE       = 0x02; // 0x02 for Operational Mode
   data_ptr.FLR_HEADER_001.HED_PROCESSED_RANGE      = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_HEADER_001.HED_R_WRAPPING           = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_HEADER_001.HED_Rain_Level           = 0;
   data_ptr.FLR_HEADER_001.HED_LOOK_INDEX           = ipc_d2m->payload.rdd_stream_data.look_data.look_index;

   data_ptr.FLR_HEADER_001.HED_TRIGGER_TIME             = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_HEADER_001.HED_SLOPE_CORR_EXECUTIONFLAG = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_HEADER_001.HED_TIME_SYNC_VALIDITY_FLAG  = 0; // need to check
   data_ptr.FLR_HEADER_001.HED_TIME_SYNC_SRC_MASTER     = 0; // need to check

   Radar_Look_T hdr_look_type;
   hdr_look_type = (Radar_Look_T)ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   if (hdr_look_type < RADAR_LOOK_D)
   {
      data_ptr.FLR_HEADER_001.HED_DET_RANGE_MAX       = k_detection_range_max_smc[(uint8_t)hdr_look_type];
      data_ptr.FLR_HEADER_001.HED_DET_RANGE_MIN       = k_detection_range_min_smc[(uint8_t)hdr_look_type];
      data_ptr.FLR_HEADER_001.HED_DET_SPEED_RANGE_MAX = k_detection_range_rate_max_smc[(uint8_t)hdr_look_type];
      data_ptr.FLR_HEADER_001.HED_DET_SPEED_RANGE_MIN = k_detection_range_rate_min_smc[(uint8_t)hdr_look_type];
   }
   else
   {
      data_ptr.FLR_HEADER_001.HED_DET_RANGE_MAX       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.FLR_HEADER_001.HED_DET_RANGE_MIN       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.FLR_HEADER_001.HED_DET_SPEED_RANGE_MAX = Init_Fixed_Point(0, s7p8_T);
      data_ptr.FLR_HEADER_001.HED_DET_SPEED_RANGE_MIN = Init_Fixed_Point(0, s7p8_T);
   }

   // FLR_STATUS_001
   data_ptr.FLR_STATUS_001.STS_MH_001_CYCLE_COUNTER     = 0;
   data_ptr.FLR_STATUS_001.STS_MH_001_CRC16             = 0;
   data_ptr.FLR_STATUS_001.STS_USC_CAL_VER_MAJOR        = Get_USC_Cal_Major();
   data_ptr.FLR_STATUS_001.STS_USC_CAL_VER_MINOR        = Get_USC_Cal_Minor();
   data_ptr.FLR_STATUS_001.STS_USC_SECTION_COMPTBLITY   = Get_USC_Cal_Major();
   data_ptr.FLR_STATUS_001.STS_SMC_CAL_VER_MAJOR        = Get_SMC_Cal_Major();
   data_ptr.FLR_STATUS_001.STS_SMC_CAL_VER_MINOR        = Get_SMC_Cal_Minor();
   data_ptr.FLR_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = Get_SMC_Cal_Major();
   data_ptr.FLR_STATUS_001.STS_SMC_PLATFROM_VERSION     = Get_SMC_Cal_Platform();
   data_ptr.FLR_STATUS_001.STS_SENSOR_POSITION          = Get_Radar_Position();
   data_ptr.FLR_STATUS_001.STS_HARDWARE_VERSION         = status_stream_ptr->app_version_Info.board_type;
   data_ptr.FLR_STATUS_001.STS_PCAN_PROTOCOL_VER_MAJOR  = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.FLR_STATUS_001.STS_PCAN_PROTOCOL_VER_MINOR  = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.FLR_STATUS_001.STS_PLATFORM_VARIANT         = Get_SMC_Cal_Platform();
   data_ptr.FLR_STATUS_001.STS_SERIAL_NUM_JULIAN_DAY    = k_Julian_Production_Date_USC;
   data_ptr.FLR_STATUS_001.STS_SERIAL_NUM_JULIAN_YEAR   = k_Julian_Year_USC;
   data_ptr.FLR_STATUS_001.STS_SERIAL_NUMBER_SEQUENCE   = k_Mfg_Sequence_Number_USC;
   data_ptr.FLR_STATUS_001.STS_SW_VERSION_FIELD1        = status_stream_ptr->app_version_Info.appl_variant;
   data_ptr.FLR_STATUS_001.STS_SW_VERSION_FIELD2        = status_stream_ptr->app_version_Info.major_release_revision;
   data_ptr.FLR_STATUS_001.STS_SW_VERSION_FIELD3        = status_stream_ptr->app_version_Info.minor_release_revision;
   data_ptr.FLR_STATUS_001.STS_SW_VERSION_FIELD4        = status_stream_ptr->app_version_Info.patch_release_revision;
   data_ptr.FLR_STATUS_001.STS_PBL_VERSION_FIELD1       = status_stream_ptr->pbl_version_maj;
   data_ptr.FLR_STATUS_001.STS_PBL_VERSION_FIELD2       = status_stream_ptr->pbl_version_min;
   data_ptr.FLR_STATUS_001.STS_PBL_VERSION_FIELD3       = status_stream_ptr->pbl_version_patch;
   data_ptr.FLR_STATUS_001.STS_PBL_VERSION_FIELD4       = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_ORNT_YAW    = *k_sensor_mount_ornt_yaw_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_POLARITY          = 0;
   data_ptr.FLR_STATUS_001.STS_DIST_FRNT_BMPR_TO_RR_AXL = 0;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_ORNT_PITCH  = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_ORNT_ROLL   = *k_sensor_mount_ornt_roll_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_POS_X       = *k_sensor_mount_pos_x_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_POS_Y       = *k_sensor_mount_pos_y_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_MOUNT_POS_Z       = *k_sensor_mount_pos_z_list_smc;
   data_ptr.FLR_STATUS_001.STS_SENSOR_HEIGHT            = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.FLR_STATUS_001.STS_DET_DBC_BASE_VER_MAJOR   = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.FLR_STATUS_001.STS_DET_DBC_BASE_VER_MINOR   = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.FLR_STATUS_001.STS_TIME_SINCE_POWER_ON      = 0;
   data_ptr.FLR_STATUS_001.STS_AF_TIME_PEAK             = 0;
   data_ptr.FLR_STATUS_001.STS_AF_TIME_INST             = 0;
   data_ptr.FLR_STATUS_001.STS_MAIN_CORE_TIME_INST      = 0;
   data_ptr.FLR_STATUS_001.STS_MAIN_CORE_TIME_PEAK      = 0;
   data_ptr.FLR_STATUS_001.STS_RDD_CORE_TIME_INST       = 0;
   data_ptr.FLR_STATUS_001.STS_RDD_CORE_TIME_PEAK       = 0;
   data_ptr.FLR_STATUS_001.STS_SP_CORE_TIME_INST        = 0;
   data_ptr.FLR_STATUS_001.STS_SP_CORE_TIME_PEAK        = 0;
   data_ptr.FLR_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = 0;

   // FLR_STATUS_002
   data_ptr.FLR_STATUS_002.STS_MH_002_CYCLE_COUNTER   = 0;
   data_ptr.FLR_STATUS_002.STS_MH_002_CRC16           = 0;
   data_ptr.FLR_STATUS_002.STS_VEHICLE_SUPPLY_VOLTAGE = 0; // need to check
   data_ptr.FLR_STATUS_002.STS_YAW_RATE_BIAS          = ipc_m2d->payload.veh_data.vse_output.yaw_rate_bias;
   data_ptr.FLR_STATUS_002.STS_STEERING_ANGLE         = ipc_m2d->payload.veh_data.vse_output.comp_steering_angle_deg;

   if (!(ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_OUT) &&
       (ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_BASE))
   {
      data_ptr.FLR_STATUS_002.STS_NO_TSYN_ERROR = 1;
   }
   else
   {
      data_ptr.FLR_STATUS_002.STS_NO_TSYN_ERROR = 0;
   }

   data_ptr.FLR_STATUS_002.STS_BRR_STATUS         = 0; // need to be checked
   data_ptr.FLR_STATUS_002.STS_XCVR_OPERATIONAL   = 0; // need to be checked
   data_ptr.FLR_STATUS_002.STS_MMIC_RE_INIT_COUNT = 0;
   data_ptr.FLR_STATUS_002.STS_POINT_OF_TRIGGER   = CAN_SIG_NOT_IMPLEMENTED;
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.FLR_STATUS_002.STS_SCAN_TYPE = ipc_d2m->payload.downselection_data.det_list_property.look_type;
#else
   data_ptr.FLR_STATUS_002.STS_SCAN_TYPE                  = ipc_d2m->payload.det_data.det_list_property.look_type;
#endif
   data_ptr.FLR_STATUS_002.STS_Gear_Position              = 0;
   data_ptr.FLR_STATUS_002.STS_CAN_NM_State               = 0;
   data_ptr.FLR_STATUS_002.STS_MMIC_TEMP_TX1_2            = 0; // status_stream_ptr->mmic_temp_rx1;// need to checked
   data_ptr.FLR_STATUS_002.STS_MMIC_TEMP_TX3_4            = 0; // status_stream_ptr->mmic_temp_tx1;// need to checked
   data_ptr.FLR_STATUS_002.STS_MCU_TEMP                   = 0;
   data_ptr.FLR_STATUS_002.STS_CORE_ACTV_FLT_BYTE_4_to_7  = 0;
   data_ptr.FLR_STATUS_002.STS_AF_CORE_THROUGHPUT         = 0;
   data_ptr.FLR_STATUS_002.STS_Vehicle_Speed_Calc_QF      = 0;
   data_ptr.FLR_STATUS_002.STS_RDD_CORE_THROUGHPUT        = 0;
   data_ptr.FLR_STATUS_002.STS_Yaw_Rate_Calc_QF           = 0;
   data_ptr.FLR_STATUS_002.STS_MMIC_TEMP_RX               = 0; // need to checked
   data_ptr.FLR_STATUS_002.STS_TIME_SYNC_OFFSET           = 0;
   data_ptr.FLR_STATUS_002.STS_MMIC_TEMP_TX0              = 0;
   data_ptr.FLR_STATUS_002.STS_STEERING_ANGLE_SIGN        = 0; // ipc_m2d->payload.veh_data.vse_output.veh_steering_sign_status;
   data_ptr.FLR_STATUS_002.STS_VEH_SPEED_DIRECTION        = 0; //(ipc_m2d->payload.veh_data.vse_output.lros_drive_reverse) ? 1 : 0;
   data_ptr.FLR_STATUS_002.STS_VEHICLE_SPEED_CALC         = 0; // ipc_m2d->payload.veh_data.vse_output.veh_speed;
   data_ptr.FLR_STATUS_002.STS_CORE_ACTV_FLT_BYTE_0_to_3  = 0;
   data_ptr.FLR_STATUS_002.STS_CORE_ACTV_FLT_BYTE_8_to_11 = 0;
   data_ptr.FLR_STATUS_002.STS_CORE_ACTV_FLT_BYTE_11_to_15  = 0;
   data_ptr.FLR_STATUS_002.STS_Project_ACTV_FLT_BYTE_0_to_3 = 0;
   data_ptr.FLR_STATUS_002.STS_Project_ACTV_FLT_BYTE_4_to_5 = 0;
   data_ptr.FLR_STATUS_002.STS_Last_CAN_Det_Inst_Latency    = 0;
   data_ptr.FLR_STATUS_002.STS_First_CAN_Det_Inst_Latency   = 0;
   data_ptr.FLR_STATUS_002.STS_RAIN_COUNT                   = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_STATUS_002.STS_INTRFC_VERSION_ID_MAJOR      = 0;
   data_ptr.FLR_STATUS_002.STS_INTRFC_VERSION_ID_MINOR      = 0;
   data_ptr.FLR_STATUS_002.STS_INTRFC_VERSION_ID_PATCH      = 0;

   // FLR_ALIGNMENT_STATUS_001
   data_ptr.FLR_ALIGNMENT_STATUS_001.AL_STS_001_MH_CRC16      = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.AL_STS_001_CYCLE_COUNTER = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AAAzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AACurrentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AACurrentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AAElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentAutoStatus = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentError = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentModeIn =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AlignmentModeOut =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AutoAlignmentFailRootCause = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AzimuthErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_az;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AzimuthErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_az;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_AzimuthUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_CalDisplay = 1;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_CalTime    = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_CoordinateSystemInput =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.detection_coordinate_system;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_ElevationErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_el;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_ElevationErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_el;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_ElevationUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_HostSpdCompensationFactorQF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_HostSpeedCompensationFactor =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitAlignmentResultElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitAlignmentResultAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitAlignResultAzimuthUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_ElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitAlignRsltElevationUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitAlignRsltHostSpdCompFac =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_StartAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   uint8_t Complete_Percent_Az =
      (uint8_t)ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_az;
   uint8_t Complete_Percent_El =
      (uint8_t)0; // ipc_a2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_el;
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_ProgressPercent             = (uint8_t)((Complete_Percent_Az + Complete_Percent_El) / 2U);
   data_ptr.FLR_ALIGNMENT_STATUS_001.STS_InitLastSuccessfulAlignMode = 0;

   // FLR_ALIGNMENT_STATUS_002
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_AlignmentServiceStatus = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_ImpactByInterference   = 0; // TODO: check what to be filled
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_AlignmentStaticStatus  = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_Measured_Range =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_range;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_MeasuredRangeStd =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_range;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_MeasuredRangeRate =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_r_dot;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_MeasuredRangeRateStd =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_MeasuredRawAmplitude =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_rcs;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_MeasuredAmpSTD =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_AlignmentShortTrackStatus = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_VehicleCondition          = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_DistanceAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_since_start;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_AverageNumberOfDetections = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_DistanceEffective =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el >
            (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf) ?
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el) :
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf);
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_DurationAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_since_start;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_AverageSpeed =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.avg_spd_since_start;
   data_ptr.FLR_ALIGNMENT_STATUS_002.STS_DurationEffective =
      (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el) >
            (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf) ?
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el) :
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf);
   data_ptr.FLR_ALIGNMENT_STATUS_002.AL_STS_002_MH_CRC16      = 0;
   data_ptr.FLR_ALIGNMENT_STATUS_002.AL_STS_002_CYCLE_COUNTER = 0;

   // FLR_CAPABILITY
   data_ptr.FLR_CAPABILITY.CAP_FreeSightCheckActive  = ipc_d2m->payload.radar_capability_data.fsc.run_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageStatus        = ipc_d2m->payload.radar_capability_data.blockage.blockage_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageActive        = ipc_d2m->payload.radar_capability_data.blockage.blockage_active;
   data_ptr.FLR_CAPABILITY.CAP_BlockageSensitivity   = ipc_d2m->payload.radar_capability_data.sensitivity_level;
   data_ptr.FLR_CAPABILITY.CAP_DampingStatus         = ipc_d2m->payload.radar_capability_data.dm.dm_status;
   data_ptr.FLR_CAPABILITY.CAP_FreeSightCheckStatus  = ipc_d2m->payload.radar_capability_data.fsc.fault_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageValue         = ipc_d2m->payload.radar_capability_data.blockage.blockage.value;
   data_ptr.FLR_CAPABILITY.CAP_DampingActive         = ipc_d2m->payload.radar_capability_data.dm.dm_active;
   data_ptr.FLR_CAPABILITY.CAP_BlockageProbability   = ipc_d2m->payload.radar_capability_data.blockage.blockage.probability;
   data_ptr.FLR_CAPABILITY.CAP_RangeEstimationActive = ipc_d2m->payload.radar_capability_data.re.re_active;
   data_ptr.FLR_CAPABILITY.CAP_SLBlockageFilterValue = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_CAPABILITY.CAP_SLBlockageFlag        = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_CAPABILITY.CAP_DampingCurrent        = ipc_d2m->payload.radar_capability_data.dm.damping.current_dB;
   data_ptr.FLR_CAPABILITY.CAP_DampingStandardDeviation =
      Float2Fix(ipc_d2m->payload.radar_capability_data.dm.damping.std_dB, u8p0_T);
   data_ptr.FLR_CAPABILITY.CAP_SLLMonitoringStatus   = ipc_d2m->payload.radar_capability_data.pbd.status;
   data_ptr.FLR_CAPABILITY.CAP_SLLMonitoringActive   = ipc_d2m->payload.radar_capability_data.pbd.pbd_active;
   data_ptr.FLR_CAPABILITY.CAP_RangeEstimationStatus = ipc_d2m->payload.radar_capability_data.re.re_status;
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_AngleAzimuthRangeStart =
      Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_begin_rad[0], s15p0_T);
   data_ptr.FLR_CAPABILITY.CAP_AngleAzimuthRangeEnd = Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_end_rad[0], s15p0_T);
   data_ptr.FLR_CAPABILITY.CAP_SideLobeLevelBeamformer = ipc_d2m->payload.radar_capability_data.pbd.az_sector[0].side_lobe_level;
   data_ptr.FLR_CAPABILITY.CAP_MH_CRC16                = 0;
   data_ptr.FLR_CAPABILITY.CAP_CYCLE_COUNTER           = 0;

   // FLR_DETECTION_001_004_decoded_msg_t
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_001 = af_target_report_ptr[0].ran;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_002 = af_target_report_ptr[1].ran;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_003 = af_target_report_ptr[2].ran;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_004 = af_target_report_ptr[3].ran;

   data_ptr.FLR_DETECTION_001_004.DET_AZIMUTH_001 = af_target_report_ptr[0].theta;
   data_ptr.FLR_DETECTION_001_004.DET_AZIMUTH_002 = af_target_report_ptr[1].theta;
   data_ptr.FLR_DETECTION_001_004.DET_AZIMUTH_003 = af_target_report_ptr[2].theta;
   data_ptr.FLR_DETECTION_001_004.DET_AZIMUTH_004 = af_target_report_ptr[3].theta;

   data_ptr.FLR_DETECTION_001_004.DET_BELOW_RAIN_THOLD_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_BELOW_RAIN_THOLD_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_BELOW_RAIN_THOLD_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_BELOW_RAIN_THOLD_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_001_004.DET_BI_STATIC_FLAG_004 = af_target_report_ptr[3].f_bistatic;
   data_ptr.FLR_DETECTION_001_004.DET_BI_STATIC_FLAG_003 = af_target_report_ptr[2].f_bistatic;
   data_ptr.FLR_DETECTION_001_004.DET_BI_STATIC_FLAG_002 = af_target_report_ptr[1].f_bistatic;
   data_ptr.FLR_DETECTION_001_004.DET_BI_STATIC_FLAG_001 = af_target_report_ptr[0].f_bistatic;

   data_ptr.FLR_DETECTION_001_004.DET_CONFD_AZIMUTH_001 = af_target_report_ptr[0].az_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_AZIMUTH_002 = af_target_report_ptr[1].az_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_AZIMUTH_003 = af_target_report_ptr[2].az_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_AZIMUTH_004 = af_target_report_ptr[3].az_conf;

   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_001 = af_target_report_ptr[0].phi;
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_002 = af_target_report_ptr[1].phi;
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_003 = af_target_report_ptr[2].phi;
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_004 = af_target_report_ptr[3].phi;

   data_ptr.FLR_DETECTION_001_004.DET_CONFD_ELEVATION_001 = af_target_report_ptr[0].el_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_ELEVATION_002 = af_target_report_ptr[1].el_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_ELEVATION_003 = af_target_report_ptr[2].el_conf;
   data_ptr.FLR_DETECTION_001_004.DET_CONFD_ELEVATION_004 = af_target_report_ptr[3].el_conf;

   data_ptr.FLR_DETECTION_001_004.DET_EXISTENCE_PROB_001 = TOI_DS_Stream_Ptr->existence_prob[0];
   data_ptr.FLR_DETECTION_001_004.DET_EXISTENCE_PROB_002 = TOI_DS_Stream_Ptr->existence_prob[1];
   data_ptr.FLR_DETECTION_001_004.DET_EXISTENCE_PROB_003 = TOI_DS_Stream_Ptr->existence_prob[2];
   data_ptr.FLR_DETECTION_001_004.DET_EXISTENCE_PROB_004 = TOI_DS_Stream_Ptr->existence_prob[3];

   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_ERR_001 = TOI_DS_Stream_Ptr->std_phi[0];
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_ERR_002 = TOI_DS_Stream_Ptr->std_phi[1];
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_ERR_003 = TOI_DS_Stream_Ptr->std_phi[2];
   data_ptr.FLR_DETECTION_001_004.DET_ELEVATION_ERR_004 = TOI_DS_Stream_Ptr->std_phi[3];

   data_ptr.FLR_DETECTION_001_004.DET_HVC_FLAG_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_HVC_FLAG_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_HVC_FLAG_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_HVC_FLAG_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_001_004.DET_IDM_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_IDM_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_IDM_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_IDM_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_001_004.DET_MH_CYCLE_COUNTER_001_004   = 0;
   data_ptr.FLR_DETECTION_001_004.DET_MH_CRC16_001_004           = 0;
   data_ptr.FLR_DETECTION_001_004.DET_MH_SCAN_INDEX_4LSB_001_004 = 0;

   data_ptr.FLR_DETECTION_001_004.DET_MTD_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_MTD_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_MTD_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_MTD_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_001_004.DET_PROB_1STAZHYPO_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_PROB_1STAZHYPO_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_PROB_1STAZHYPO_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_001_004.DET_PROB_1STAZHYPO_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_001_004.DET_RANGE_ERR_001 = TOI_DS_Stream_Ptr->std_ran[0];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_ERR_002 = TOI_DS_Stream_Ptr->std_ran[1];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_ERR_003 = TOI_DS_Stream_Ptr->std_ran[2];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_ERR_004 = TOI_DS_Stream_Ptr->std_ran[3];

   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_001 = af_target_report_ptr[0].vel;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_002 = af_target_report_ptr[1].vel;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_003 = af_target_report_ptr[2].vel;
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_004 = af_target_report_ptr[3].vel;

   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_001 = TOI_DS_Stream_Ptr->std_vel[0];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_002 = TOI_DS_Stream_Ptr->std_vel[1];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_003 = TOI_DS_Stream_Ptr->std_vel[2];
   data_ptr.FLR_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_004 = TOI_DS_Stream_Ptr->std_vel[3];

   data_ptr.FLR_DETECTION_001_004.DET_RCS_001 = af_target_report_ptr[0].rcs;
   data_ptr.FLR_DETECTION_001_004.DET_RCS_002 = af_target_report_ptr[1].rcs;
   data_ptr.FLR_DETECTION_001_004.DET_RCS_003 = af_target_report_ptr[2].rcs;
   data_ptr.FLR_DETECTION_001_004.DET_RCS_004 = af_target_report_ptr[3].rcs;

   data_ptr.FLR_DETECTION_001_004.DET_SNR_001 = af_target_report_ptr[0].snr;
   data_ptr.FLR_DETECTION_001_004.DET_SNR_002 = af_target_report_ptr[1].snr;
   data_ptr.FLR_DETECTION_001_004.DET_SNR_003 = af_target_report_ptr[2].snr;
   data_ptr.FLR_DETECTION_001_004.DET_SNR_004 = af_target_report_ptr[3].snr;

   data_ptr.FLR_DETECTION_001_004.DET_SUPER_RES_TARGET_001 = af_target_report_ptr[0].f_superres_target;
   data_ptr.FLR_DETECTION_001_004.DET_SUPER_RES_TARGET_002 = af_target_report_ptr[1].f_superres_target;
   data_ptr.FLR_DETECTION_001_004.DET_SUPER_RES_TARGET_003 = af_target_report_ptr[2].f_superres_target;
   data_ptr.FLR_DETECTION_001_004.DET_SUPER_RES_TARGET_004 = af_target_report_ptr[3].f_superres_target;

   // FLR_DETECTION_005_008_decoded_msg_t
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_005 = af_target_report_ptr[4].ran;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_006 = af_target_report_ptr[5].ran;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_007 = af_target_report_ptr[6].ran;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_008 = af_target_report_ptr[7].ran;

   data_ptr.FLR_DETECTION_005_008.DET_AZIMUTH_005 = af_target_report_ptr[4].theta;
   data_ptr.FLR_DETECTION_005_008.DET_AZIMUTH_006 = af_target_report_ptr[5].theta;
   data_ptr.FLR_DETECTION_005_008.DET_AZIMUTH_007 = af_target_report_ptr[6].theta;
   data_ptr.FLR_DETECTION_005_008.DET_AZIMUTH_008 = af_target_report_ptr[7].theta;

   data_ptr.FLR_DETECTION_005_008.DET_BELOW_RAIN_THOLD_005 = 0;
   data_ptr.FLR_DETECTION_005_008.DET_BELOW_RAIN_THOLD_006 = 0;
   data_ptr.FLR_DETECTION_005_008.DET_BELOW_RAIN_THOLD_007 = 0;
   data_ptr.FLR_DETECTION_005_008.DET_BELOW_RAIN_THOLD_008 = 0;

   data_ptr.FLR_DETECTION_005_008.DET_BI_STATIC_FLAG_005 = af_target_report_ptr[4].f_bistatic;
   data_ptr.FLR_DETECTION_005_008.DET_BI_STATIC_FLAG_006 = af_target_report_ptr[5].f_bistatic;
   data_ptr.FLR_DETECTION_005_008.DET_BI_STATIC_FLAG_007 = af_target_report_ptr[6].f_bistatic;
   data_ptr.FLR_DETECTION_005_008.DET_BI_STATIC_FLAG_008 = af_target_report_ptr[7].f_bistatic;

   data_ptr.FLR_DETECTION_005_008.DET_CONFD_AZIMUTH_005 = af_target_report_ptr[4].az_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_AZIMUTH_006 = af_target_report_ptr[5].az_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_AZIMUTH_007 = af_target_report_ptr[6].az_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_AZIMUTH_008 = af_target_report_ptr[7].az_conf;

   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_005 = af_target_report_ptr[4].phi;
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_006 = af_target_report_ptr[5].phi;
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_007 = af_target_report_ptr[6].phi;
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_008 = af_target_report_ptr[7].phi;

   data_ptr.FLR_DETECTION_005_008.DET_CONFD_ELEVATION_005 = af_target_report_ptr[4].el_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_ELEVATION_006 = af_target_report_ptr[5].el_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_ELEVATION_007 = af_target_report_ptr[6].el_conf;
   data_ptr.FLR_DETECTION_005_008.DET_CONFD_ELEVATION_008 = af_target_report_ptr[7].el_conf;

   data_ptr.FLR_DETECTION_005_008.DET_EXISTENCE_PROB_005 = TOI_DS_Stream_Ptr->existence_prob[4];
   data_ptr.FLR_DETECTION_005_008.DET_EXISTENCE_PROB_006 = TOI_DS_Stream_Ptr->existence_prob[5];
   data_ptr.FLR_DETECTION_005_008.DET_EXISTENCE_PROB_007 = TOI_DS_Stream_Ptr->existence_prob[6];
   data_ptr.FLR_DETECTION_005_008.DET_EXISTENCE_PROB_008 = TOI_DS_Stream_Ptr->existence_prob[7];

   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_ERR_005 = TOI_DS_Stream_Ptr->std_phi[4];
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_ERR_006 = TOI_DS_Stream_Ptr->std_phi[5];
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_ERR_007 = TOI_DS_Stream_Ptr->std_phi[6];
   data_ptr.FLR_DETECTION_005_008.DET_ELEVATION_ERR_008 = TOI_DS_Stream_Ptr->std_phi[7];

   data_ptr.FLR_DETECTION_005_008.DET_HVC_FLAG_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_HVC_FLAG_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_HVC_FLAG_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_HVC_FLAG_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_005_008.DET_IDM_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_IDM_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_IDM_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_IDM_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_005_008.DET_MH_CYCLE_COUNTER_005_008   = 0;
   data_ptr.FLR_DETECTION_005_008.DET_MH_CRC16_005_008           = 0;
   data_ptr.FLR_DETECTION_005_008.DET_MH_SCAN_INDEX_4LSB_005_008 = 0;

   data_ptr.FLR_DETECTION_005_008.DET_MTD_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_MTD_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_MTD_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_MTD_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_005_008.DET_PROB_1STAZHYPO_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_PROB_1STAZHYPO_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_PROB_1STAZHYPO_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_005_008.DET_PROB_1STAZHYPO_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_005_008.DET_RANGE_ERR_005 = TOI_DS_Stream_Ptr->std_ran[4];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_ERR_006 = TOI_DS_Stream_Ptr->std_ran[5];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_ERR_007 = TOI_DS_Stream_Ptr->std_ran[6];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_ERR_008 = TOI_DS_Stream_Ptr->std_ran[7];

   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_005 = af_target_report_ptr[4].vel;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_006 = af_target_report_ptr[5].vel;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_007 = af_target_report_ptr[6].vel;
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_008 = af_target_report_ptr[7].vel;

   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_005 = TOI_DS_Stream_Ptr->std_vel[4];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_006 = TOI_DS_Stream_Ptr->std_vel[5];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_007 = TOI_DS_Stream_Ptr->std_vel[6];
   data_ptr.FLR_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_008 = TOI_DS_Stream_Ptr->std_vel[7];

   data_ptr.FLR_DETECTION_005_008.DET_RCS_005 = af_target_report_ptr[4].rcs;
   data_ptr.FLR_DETECTION_005_008.DET_RCS_006 = af_target_report_ptr[5].rcs;
   data_ptr.FLR_DETECTION_005_008.DET_RCS_007 = af_target_report_ptr[6].rcs;
   data_ptr.FLR_DETECTION_005_008.DET_RCS_008 = af_target_report_ptr[7].rcs;

   data_ptr.FLR_DETECTION_005_008.DET_SNR_005 = af_target_report_ptr[4].snr;
   data_ptr.FLR_DETECTION_005_008.DET_SNR_006 = af_target_report_ptr[5].snr;
   data_ptr.FLR_DETECTION_005_008.DET_SNR_007 = af_target_report_ptr[6].snr;
   data_ptr.FLR_DETECTION_005_008.DET_SNR_008 = af_target_report_ptr[7].snr;

   data_ptr.FLR_DETECTION_005_008.DET_SUPER_RES_TARGET_005 = af_target_report_ptr[4].f_superres_target;
   data_ptr.FLR_DETECTION_005_008.DET_SUPER_RES_TARGET_006 = af_target_report_ptr[5].f_superres_target;
   data_ptr.FLR_DETECTION_005_008.DET_SUPER_RES_TARGET_007 = af_target_report_ptr[6].f_superres_target;
   data_ptr.FLR_DETECTION_005_008.DET_SUPER_RES_TARGET_008 = af_target_report_ptr[7].f_superres_target;

   // FLR_DETECTION_009_012_decoded_msg_t
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_009 = af_target_report_ptr[8].ran;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_010 = af_target_report_ptr[9].ran;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_011 = af_target_report_ptr[10].ran;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_012 = af_target_report_ptr[11].ran;

   data_ptr.FLR_DETECTION_009_012.DET_AZIMUTH_009 = af_target_report_ptr[8].theta;
   data_ptr.FLR_DETECTION_009_012.DET_AZIMUTH_010 = af_target_report_ptr[9].theta;
   data_ptr.FLR_DETECTION_009_012.DET_AZIMUTH_011 = af_target_report_ptr[10].theta;
   data_ptr.FLR_DETECTION_009_012.DET_AZIMUTH_012 = af_target_report_ptr[11].theta;

   data_ptr.FLR_DETECTION_009_012.DET_BELOW_RAIN_THOLD_009 = 0;
   data_ptr.FLR_DETECTION_009_012.DET_BELOW_RAIN_THOLD_010 = 0;
   data_ptr.FLR_DETECTION_009_012.DET_BELOW_RAIN_THOLD_011 = 0;
   data_ptr.FLR_DETECTION_009_012.DET_BELOW_RAIN_THOLD_012 = 0;

   data_ptr.FLR_DETECTION_009_012.DET_BI_STATIC_FLAG_009 = af_target_report_ptr[8].f_bistatic;
   data_ptr.FLR_DETECTION_009_012.DET_BI_STATIC_FLAG_010 = af_target_report_ptr[9].f_bistatic;
   data_ptr.FLR_DETECTION_009_012.DET_BI_STATIC_FLAG_011 = af_target_report_ptr[10].f_bistatic;
   data_ptr.FLR_DETECTION_009_012.DET_BI_STATIC_FLAG_012 = af_target_report_ptr[11].f_bistatic;

   data_ptr.FLR_DETECTION_009_012.DET_CONFD_AZIMUTH_009 = af_target_report_ptr[8].az_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_AZIMUTH_010 = af_target_report_ptr[9].az_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_AZIMUTH_011 = af_target_report_ptr[10].az_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_AZIMUTH_012 = af_target_report_ptr[11].az_conf;

   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_009 = af_target_report_ptr[8].phi;
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_010 = af_target_report_ptr[9].phi;
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_011 = af_target_report_ptr[10].phi;
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_012 = af_target_report_ptr[11].phi;

   data_ptr.FLR_DETECTION_009_012.DET_CONFD_ELEVATION_009 = af_target_report_ptr[8].el_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_ELEVATION_010 = af_target_report_ptr[9].el_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_ELEVATION_011 = af_target_report_ptr[10].el_conf;
   data_ptr.FLR_DETECTION_009_012.DET_CONFD_ELEVATION_012 = af_target_report_ptr[11].el_conf;

   data_ptr.FLR_DETECTION_009_012.DET_EXISTENCE_PROB_009 = TOI_DS_Stream_Ptr->existence_prob[8];
   data_ptr.FLR_DETECTION_009_012.DET_EXISTENCE_PROB_010 = TOI_DS_Stream_Ptr->existence_prob[9];
   data_ptr.FLR_DETECTION_009_012.DET_EXISTENCE_PROB_011 = TOI_DS_Stream_Ptr->existence_prob[10];
   data_ptr.FLR_DETECTION_009_012.DET_EXISTENCE_PROB_012 = TOI_DS_Stream_Ptr->existence_prob[11];

   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_ERR_009 = TOI_DS_Stream_Ptr->std_phi[8];
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_ERR_010 = TOI_DS_Stream_Ptr->std_phi[9];
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_ERR_011 = TOI_DS_Stream_Ptr->std_phi[10];
   data_ptr.FLR_DETECTION_009_012.DET_ELEVATION_ERR_012 = TOI_DS_Stream_Ptr->std_phi[11];

   data_ptr.FLR_DETECTION_009_012.DET_HVC_FLAG_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_HVC_FLAG_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_HVC_FLAG_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_HVC_FLAG_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_009_012.DET_IDM_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_IDM_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_IDM_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_IDM_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_009_012.DET_MH_CYCLE_COUNTER_009_012   = 0;
   data_ptr.FLR_DETECTION_009_012.DET_MH_CRC16_009_012           = 0;
   data_ptr.FLR_DETECTION_009_012.DET_MH_SCAN_INDEX_4LSB_009_012 = 0;

   data_ptr.FLR_DETECTION_009_012.DET_MTD_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_MTD_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_MTD_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_MTD_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_009_012.DET_PROB_1STAZHYPO_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_PROB_1STAZHYPO_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_PROB_1STAZHYPO_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_009_012.DET_PROB_1STAZHYPO_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_009_012.DET_RANGE_ERR_009 = TOI_DS_Stream_Ptr->std_ran[8];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_ERR_010 = TOI_DS_Stream_Ptr->std_ran[9];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_ERR_011 = TOI_DS_Stream_Ptr->std_ran[10];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_ERR_012 = TOI_DS_Stream_Ptr->std_ran[11];

   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_009 = af_target_report_ptr[8].vel;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_010 = af_target_report_ptr[9].vel;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_011 = af_target_report_ptr[10].vel;
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_012 = af_target_report_ptr[11].vel;

   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_009 = TOI_DS_Stream_Ptr->std_vel[8];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_010 = TOI_DS_Stream_Ptr->std_vel[9];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_011 = TOI_DS_Stream_Ptr->std_vel[10];
   data_ptr.FLR_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_012 = TOI_DS_Stream_Ptr->std_vel[11];

   data_ptr.FLR_DETECTION_009_012.DET_RCS_009 = af_target_report_ptr[8].rcs;
   data_ptr.FLR_DETECTION_009_012.DET_RCS_010 = af_target_report_ptr[9].rcs;
   data_ptr.FLR_DETECTION_009_012.DET_RCS_011 = af_target_report_ptr[10].rcs;
   data_ptr.FLR_DETECTION_009_012.DET_RCS_012 = af_target_report_ptr[11].rcs;

   data_ptr.FLR_DETECTION_009_012.DET_SNR_009 = af_target_report_ptr[8].snr;
   data_ptr.FLR_DETECTION_009_012.DET_SNR_010 = af_target_report_ptr[9].snr;
   data_ptr.FLR_DETECTION_009_012.DET_SNR_011 = af_target_report_ptr[10].snr;
   data_ptr.FLR_DETECTION_009_012.DET_SNR_012 = af_target_report_ptr[11].snr;

   data_ptr.FLR_DETECTION_009_012.DET_SUPER_RES_TARGET_009 = af_target_report_ptr[8].f_superres_target;
   data_ptr.FLR_DETECTION_009_012.DET_SUPER_RES_TARGET_010 = af_target_report_ptr[9].f_superres_target;
   data_ptr.FLR_DETECTION_009_012.DET_SUPER_RES_TARGET_011 = af_target_report_ptr[10].f_superres_target;
   data_ptr.FLR_DETECTION_009_012.DET_SUPER_RES_TARGET_012 = af_target_report_ptr[11].f_superres_target;

   // FLR_DETECTION_013_016_decoded_msg_t
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_013 = af_target_report_ptr[12].ran;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_014 = af_target_report_ptr[13].ran;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_015 = af_target_report_ptr[14].ran;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_016 = af_target_report_ptr[15].ran;

   data_ptr.FLR_DETECTION_013_016.DET_AZIMUTH_013 = af_target_report_ptr[12].theta;
   data_ptr.FLR_DETECTION_013_016.DET_AZIMUTH_014 = af_target_report_ptr[13].theta;
   data_ptr.FLR_DETECTION_013_016.DET_AZIMUTH_015 = af_target_report_ptr[14].theta;
   data_ptr.FLR_DETECTION_013_016.DET_AZIMUTH_016 = af_target_report_ptr[15].theta;

   data_ptr.FLR_DETECTION_013_016.DET_BI_STATIC_FLAG_013 = af_target_report_ptr[12].f_bistatic;
   data_ptr.FLR_DETECTION_013_016.DET_BI_STATIC_FLAG_014 = af_target_report_ptr[13].f_bistatic;
   data_ptr.FLR_DETECTION_013_016.DET_BI_STATIC_FLAG_015 = af_target_report_ptr[14].f_bistatic;
   data_ptr.FLR_DETECTION_013_016.DET_BI_STATIC_FLAG_016 = af_target_report_ptr[15].f_bistatic;

   data_ptr.FLR_DETECTION_013_016.DET_CONFD_AZIMUTH_013 = af_target_report_ptr[12].az_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_AZIMUTH_014 = af_target_report_ptr[13].az_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_AZIMUTH_015 = af_target_report_ptr[14].az_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_AZIMUTH_016 = af_target_report_ptr[15].az_conf;

   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_013 = af_target_report_ptr[12].phi;
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_014 = af_target_report_ptr[13].phi;
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_015 = af_target_report_ptr[14].phi;
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_016 = af_target_report_ptr[15].phi;

   data_ptr.FLR_DETECTION_013_016.DET_CONFD_ELEVATION_013 = af_target_report_ptr[12].el_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_ELEVATION_014 = af_target_report_ptr[13].el_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_ELEVATION_015 = af_target_report_ptr[14].el_conf;
   data_ptr.FLR_DETECTION_013_016.DET_CONFD_ELEVATION_016 = af_target_report_ptr[15].el_conf;

   data_ptr.FLR_DETECTION_013_016.DET_EXISTENCE_PROB_013 = TOI_DS_Stream_Ptr->existence_prob[12];
   data_ptr.FLR_DETECTION_013_016.DET_EXISTENCE_PROB_014 = TOI_DS_Stream_Ptr->existence_prob[13];
   data_ptr.FLR_DETECTION_013_016.DET_EXISTENCE_PROB_015 = TOI_DS_Stream_Ptr->existence_prob[14];
   data_ptr.FLR_DETECTION_013_016.DET_EXISTENCE_PROB_016 = TOI_DS_Stream_Ptr->existence_prob[15];

   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_ERR_013 = TOI_DS_Stream_Ptr->std_phi[12];
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_ERR_014 = TOI_DS_Stream_Ptr->std_phi[13];
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_ERR_015 = TOI_DS_Stream_Ptr->std_phi[14];
   data_ptr.FLR_DETECTION_013_016.DET_ELEVATION_ERR_016 = TOI_DS_Stream_Ptr->std_phi[15];

   data_ptr.FLR_DETECTION_013_016.DET_IDM_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_IDM_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_IDM_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_IDM_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_013_016.DET_MTD_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_MTD_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_MTD_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_MTD_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_013_016.DET_PROB_1STAZHYPO_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_PROB_1STAZHYPO_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_PROB_1STAZHYPO_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_PROB_1STAZHYPO_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_013_016.DET_RANGE_ERR_013 = TOI_DS_Stream_Ptr->std_ran[12];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_ERR_014 = TOI_DS_Stream_Ptr->std_ran[13];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_ERR_015 = TOI_DS_Stream_Ptr->std_ran[14];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_ERR_016 = TOI_DS_Stream_Ptr->std_ran[15];

   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_013 = af_target_report_ptr[12].vel;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_014 = af_target_report_ptr[13].vel;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_015 = af_target_report_ptr[14].vel;
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_016 = af_target_report_ptr[15].vel;

   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_013 = TOI_DS_Stream_Ptr->std_vel[12];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_014 = TOI_DS_Stream_Ptr->std_vel[13];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_015 = TOI_DS_Stream_Ptr->std_vel[14];
   data_ptr.FLR_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_016 = TOI_DS_Stream_Ptr->std_vel[15];

   data_ptr.FLR_DETECTION_013_016.DET_RCS_013 = af_target_report_ptr[12].rcs;
   data_ptr.FLR_DETECTION_013_016.DET_RCS_014 = af_target_report_ptr[13].rcs;
   data_ptr.FLR_DETECTION_013_016.DET_RCS_015 = af_target_report_ptr[14].rcs;
   data_ptr.FLR_DETECTION_013_016.DET_RCS_016 = af_target_report_ptr[15].rcs;

   data_ptr.FLR_DETECTION_013_016.DET_SNR_013 = af_target_report_ptr[12].snr;
   data_ptr.FLR_DETECTION_013_016.DET_SNR_014 = af_target_report_ptr[13].snr;
   data_ptr.FLR_DETECTION_013_016.DET_SNR_015 = af_target_report_ptr[14].snr;
   data_ptr.FLR_DETECTION_013_016.DET_SNR_016 = af_target_report_ptr[15].snr;

   data_ptr.FLR_DETECTION_013_016.DET_SUPER_RES_TARGET_013 = af_target_report_ptr[12].f_superres_target;
   data_ptr.FLR_DETECTION_013_016.DET_SUPER_RES_TARGET_014 = af_target_report_ptr[13].f_superres_target;
   data_ptr.FLR_DETECTION_013_016.DET_SUPER_RES_TARGET_015 = af_target_report_ptr[14].f_superres_target;
   data_ptr.FLR_DETECTION_013_016.DET_SUPER_RES_TARGET_016 = af_target_report_ptr[15].f_superres_target;

   data_ptr.FLR_DETECTION_013_016.DET_BELOW_RAIN_THOLD_013 = 0;
   data_ptr.FLR_DETECTION_013_016.DET_BELOW_RAIN_THOLD_014 = 0;
   data_ptr.FLR_DETECTION_013_016.DET_BELOW_RAIN_THOLD_015 = 0;
   data_ptr.FLR_DETECTION_013_016.DET_BELOW_RAIN_THOLD_016 = 0;

   data_ptr.FLR_DETECTION_013_016.DET_HVC_FLAG_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_HVC_FLAG_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_HVC_FLAG_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_013_016.DET_HVC_FLAG_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_013_016.DET_MH_CYCLE_COUNTER_013_016   = 0;
   data_ptr.FLR_DETECTION_013_016.DET_MH_CRC16_013_016           = 0;
   data_ptr.FLR_DETECTION_013_016.DET_MH_SCAN_INDEX_4LSB_013_016 = 0;

   // FLR_DETECTION_017_020_decoded_msg_t
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_017 = af_target_report_ptr[16].ran;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_018 = af_target_report_ptr[17].ran;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_019 = af_target_report_ptr[18].ran;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_020 = af_target_report_ptr[19].ran;

   data_ptr.FLR_DETECTION_017_020.DET_AZIMUTH_017 = af_target_report_ptr[16].theta;
   data_ptr.FLR_DETECTION_017_020.DET_AZIMUTH_018 = af_target_report_ptr[17].theta;
   data_ptr.FLR_DETECTION_017_020.DET_AZIMUTH_019 = af_target_report_ptr[18].theta;
   data_ptr.FLR_DETECTION_017_020.DET_AZIMUTH_020 = af_target_report_ptr[19].theta;

   data_ptr.FLR_DETECTION_017_020.DET_BI_STATIC_FLAG_017 = af_target_report_ptr[16].f_bistatic;
   data_ptr.FLR_DETECTION_017_020.DET_BI_STATIC_FLAG_018 = af_target_report_ptr[17].f_bistatic;
   data_ptr.FLR_DETECTION_017_020.DET_BI_STATIC_FLAG_019 = af_target_report_ptr[18].f_bistatic;
   data_ptr.FLR_DETECTION_017_020.DET_BI_STATIC_FLAG_020 = af_target_report_ptr[19].f_bistatic;

   data_ptr.FLR_DETECTION_017_020.DET_CONFD_AZIMUTH_017 = af_target_report_ptr[16].az_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_AZIMUTH_018 = af_target_report_ptr[17].az_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_AZIMUTH_019 = af_target_report_ptr[18].az_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_AZIMUTH_020 = af_target_report_ptr[19].az_conf;

   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_017 = af_target_report_ptr[16].phi;
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_018 = af_target_report_ptr[17].phi;
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_019 = af_target_report_ptr[18].phi;
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_020 = af_target_report_ptr[19].phi;

   data_ptr.FLR_DETECTION_017_020.DET_CONFD_ELEVATION_017 = af_target_report_ptr[16].el_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_ELEVATION_018 = af_target_report_ptr[17].el_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_ELEVATION_019 = af_target_report_ptr[18].el_conf;
   data_ptr.FLR_DETECTION_017_020.DET_CONFD_ELEVATION_020 = af_target_report_ptr[19].el_conf;

   data_ptr.FLR_DETECTION_017_020.DET_EXISTENCE_PROB_017 = TOI_DS_Stream_Ptr->existence_prob[16];
   data_ptr.FLR_DETECTION_017_020.DET_EXISTENCE_PROB_018 = TOI_DS_Stream_Ptr->existence_prob[17];
   data_ptr.FLR_DETECTION_017_020.DET_EXISTENCE_PROB_019 = TOI_DS_Stream_Ptr->existence_prob[18];
   data_ptr.FLR_DETECTION_017_020.DET_EXISTENCE_PROB_020 = TOI_DS_Stream_Ptr->existence_prob[19];

   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_ERR_017 = TOI_DS_Stream_Ptr->std_phi[16];
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_ERR_018 = TOI_DS_Stream_Ptr->std_phi[17];
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_ERR_019 = TOI_DS_Stream_Ptr->std_phi[18];
   data_ptr.FLR_DETECTION_017_020.DET_ELEVATION_ERR_020 = TOI_DS_Stream_Ptr->std_phi[19];

   data_ptr.FLR_DETECTION_017_020.DET_IDM_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_IDM_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_IDM_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_IDM_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_017_020.DET_MTD_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_MTD_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_MTD_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_MTD_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_017_020.DET_PROB_1STAZHYPO_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_PROB_1STAZHYPO_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_PROB_1STAZHYPO_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_PROB_1STAZHYPO_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_017_020.DET_RANGE_ERR_017 = TOI_DS_Stream_Ptr->std_ran[16];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_ERR_018 = TOI_DS_Stream_Ptr->std_ran[17];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_ERR_019 = TOI_DS_Stream_Ptr->std_ran[18];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_ERR_020 = TOI_DS_Stream_Ptr->std_ran[19];

   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_017 = af_target_report_ptr[16].vel;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_018 = af_target_report_ptr[17].vel;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_019 = af_target_report_ptr[18].vel;
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_020 = af_target_report_ptr[19].vel;

   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_017 = TOI_DS_Stream_Ptr->std_vel[16];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_018 = TOI_DS_Stream_Ptr->std_vel[17];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_019 = TOI_DS_Stream_Ptr->std_vel[18];
   data_ptr.FLR_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_020 = TOI_DS_Stream_Ptr->std_vel[19];

   data_ptr.FLR_DETECTION_017_020.DET_RCS_017 = af_target_report_ptr[16].rcs;
   data_ptr.FLR_DETECTION_017_020.DET_RCS_018 = af_target_report_ptr[17].rcs;
   data_ptr.FLR_DETECTION_017_020.DET_RCS_019 = af_target_report_ptr[18].rcs;
   data_ptr.FLR_DETECTION_017_020.DET_RCS_020 = af_target_report_ptr[19].rcs;

   data_ptr.FLR_DETECTION_017_020.DET_SNR_017 = af_target_report_ptr[16].snr;
   data_ptr.FLR_DETECTION_017_020.DET_SNR_018 = af_target_report_ptr[17].snr;
   data_ptr.FLR_DETECTION_017_020.DET_SNR_019 = af_target_report_ptr[18].snr;
   data_ptr.FLR_DETECTION_017_020.DET_SNR_020 = af_target_report_ptr[19].snr;

   data_ptr.FLR_DETECTION_017_020.DET_SUPER_RES_TARGET_017 = af_target_report_ptr[16].f_superres_target;
   data_ptr.FLR_DETECTION_017_020.DET_SUPER_RES_TARGET_018 = af_target_report_ptr[17].f_superres_target;
   data_ptr.FLR_DETECTION_017_020.DET_SUPER_RES_TARGET_019 = af_target_report_ptr[18].f_superres_target;
   data_ptr.FLR_DETECTION_017_020.DET_SUPER_RES_TARGET_020 = af_target_report_ptr[19].f_superres_target;

   data_ptr.FLR_DETECTION_017_020.DET_BELOW_RAIN_THOLD_017 = 0;
   data_ptr.FLR_DETECTION_017_020.DET_BELOW_RAIN_THOLD_018 = 0;
   data_ptr.FLR_DETECTION_017_020.DET_BELOW_RAIN_THOLD_019 = 0;
   data_ptr.FLR_DETECTION_017_020.DET_BELOW_RAIN_THOLD_020 = 0;

   data_ptr.FLR_DETECTION_017_020.DET_HVC_FLAG_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_HVC_FLAG_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_HVC_FLAG_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_017_020.DET_HVC_FLAG_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_017_020.DET_MH_CYCLE_COUNTER_017_020   = 0;
   data_ptr.FLR_DETECTION_017_020.DET_MH_CRC16_017_020           = 0;
   data_ptr.FLR_DETECTION_017_020.DET_MH_SCAN_INDEX_4LSB_017_020 = 0;

   // FLR_DETECTION_021_024_decoded_msg_t

   data_ptr.FLR_DETECTION_021_024.DET_RANGE_021 = af_target_report_ptr[20].ran;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_022 = af_target_report_ptr[21].ran;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_023 = af_target_report_ptr[22].ran;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_024 = af_target_report_ptr[23].ran;

   data_ptr.FLR_DETECTION_021_024.DET_AZIMUTH_021 = af_target_report_ptr[20].theta;
   data_ptr.FLR_DETECTION_021_024.DET_AZIMUTH_022 = af_target_report_ptr[21].theta;
   data_ptr.FLR_DETECTION_021_024.DET_AZIMUTH_023 = af_target_report_ptr[22].theta;
   data_ptr.FLR_DETECTION_021_024.DET_AZIMUTH_024 = af_target_report_ptr[23].theta;

   data_ptr.FLR_DETECTION_021_024.DET_BI_STATIC_FLAG_021 = af_target_report_ptr[20].f_bistatic;
   data_ptr.FLR_DETECTION_021_024.DET_BI_STATIC_FLAG_022 = af_target_report_ptr[21].f_bistatic;
   data_ptr.FLR_DETECTION_021_024.DET_BI_STATIC_FLAG_023 = af_target_report_ptr[22].f_bistatic;
   data_ptr.FLR_DETECTION_021_024.DET_BI_STATIC_FLAG_024 = af_target_report_ptr[23].f_bistatic;

   data_ptr.FLR_DETECTION_021_024.DET_CONFD_AZIMUTH_021 = af_target_report_ptr[20].az_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_AZIMUTH_022 = af_target_report_ptr[21].az_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_AZIMUTH_023 = af_target_report_ptr[22].az_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_AZIMUTH_024 = af_target_report_ptr[23].az_conf;

   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_021 = af_target_report_ptr[20].phi;
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_022 = af_target_report_ptr[21].phi;
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_023 = af_target_report_ptr[22].phi;
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_024 = af_target_report_ptr[23].phi;

   data_ptr.FLR_DETECTION_021_024.DET_CONFD_ELEVATION_021 = af_target_report_ptr[20].el_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_ELEVATION_022 = af_target_report_ptr[21].el_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_ELEVATION_023 = af_target_report_ptr[22].el_conf;
   data_ptr.FLR_DETECTION_021_024.DET_CONFD_ELEVATION_024 = af_target_report_ptr[23].el_conf;

   data_ptr.FLR_DETECTION_021_024.DET_EXISTENCE_PROB_021 = TOI_DS_Stream_Ptr->existence_prob[20];
   data_ptr.FLR_DETECTION_021_024.DET_EXISTENCE_PROB_022 = TOI_DS_Stream_Ptr->existence_prob[21];
   data_ptr.FLR_DETECTION_021_024.DET_EXISTENCE_PROB_023 = TOI_DS_Stream_Ptr->existence_prob[22];
   data_ptr.FLR_DETECTION_021_024.DET_EXISTENCE_PROB_024 = TOI_DS_Stream_Ptr->existence_prob[23];

   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_ERR_021 = TOI_DS_Stream_Ptr->std_phi[20];
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_ERR_022 = TOI_DS_Stream_Ptr->std_phi[21];
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_ERR_023 = TOI_DS_Stream_Ptr->std_phi[22];
   data_ptr.FLR_DETECTION_021_024.DET_ELEVATION_ERR_024 = TOI_DS_Stream_Ptr->std_phi[23];

   data_ptr.FLR_DETECTION_021_024.DET_IDM_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_IDM_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_IDM_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_IDM_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_021_024.DET_MTD_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_MTD_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_MTD_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_MTD_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_021_024.DET_PROB_1STAZHYPO_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_PROB_1STAZHYPO_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_PROB_1STAZHYPO_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_PROB_1STAZHYPO_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_021_024.DET_RANGE_ERR_021 = TOI_DS_Stream_Ptr->std_ran[20];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_ERR_022 = TOI_DS_Stream_Ptr->std_ran[21];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_ERR_023 = TOI_DS_Stream_Ptr->std_ran[22];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_ERR_024 = TOI_DS_Stream_Ptr->std_ran[23];

   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_021 = af_target_report_ptr[20].vel;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_022 = af_target_report_ptr[21].vel;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_023 = af_target_report_ptr[22].vel;
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_024 = af_target_report_ptr[23].vel;

   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_021 = TOI_DS_Stream_Ptr->std_vel[20];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_022 = TOI_DS_Stream_Ptr->std_vel[21];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_023 = TOI_DS_Stream_Ptr->std_vel[22];
   data_ptr.FLR_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_024 = TOI_DS_Stream_Ptr->std_vel[23];

   data_ptr.FLR_DETECTION_021_024.DET_RCS_021 = af_target_report_ptr[20].rcs;
   data_ptr.FLR_DETECTION_021_024.DET_RCS_022 = af_target_report_ptr[21].rcs;
   data_ptr.FLR_DETECTION_021_024.DET_RCS_023 = af_target_report_ptr[22].rcs;
   data_ptr.FLR_DETECTION_021_024.DET_RCS_024 = af_target_report_ptr[23].rcs;

   data_ptr.FLR_DETECTION_021_024.DET_SNR_021 = af_target_report_ptr[20].snr;
   data_ptr.FLR_DETECTION_021_024.DET_SNR_022 = af_target_report_ptr[21].snr;
   data_ptr.FLR_DETECTION_021_024.DET_SNR_023 = af_target_report_ptr[22].snr;
   data_ptr.FLR_DETECTION_021_024.DET_SNR_024 = af_target_report_ptr[23].snr;

   data_ptr.FLR_DETECTION_021_024.DET_SUPER_RES_TARGET_021 = af_target_report_ptr[20].f_superres_target;
   data_ptr.FLR_DETECTION_021_024.DET_SUPER_RES_TARGET_022 = af_target_report_ptr[21].f_superres_target;
   data_ptr.FLR_DETECTION_021_024.DET_SUPER_RES_TARGET_023 = af_target_report_ptr[22].f_superres_target;
   data_ptr.FLR_DETECTION_021_024.DET_SUPER_RES_TARGET_024 = af_target_report_ptr[23].f_superres_target;

   data_ptr.FLR_DETECTION_021_024.DET_BELOW_RAIN_THOLD_021 = 0;
   data_ptr.FLR_DETECTION_021_024.DET_BELOW_RAIN_THOLD_022 = 0;
   data_ptr.FLR_DETECTION_021_024.DET_BELOW_RAIN_THOLD_023 = 0;
   data_ptr.FLR_DETECTION_021_024.DET_BELOW_RAIN_THOLD_024 = 0;

   data_ptr.FLR_DETECTION_021_024.DET_HVC_FLAG_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_HVC_FLAG_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_HVC_FLAG_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_021_024.DET_HVC_FLAG_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_021_024.DET_MH_CYCLE_COUNTER_021_024   = 0;
   data_ptr.FLR_DETECTION_021_024.DET_MH_CRC16_021_024           = 0;
   data_ptr.FLR_DETECTION_021_024.DET_MH_SCAN_INDEX_4LSB_021_024 = 0;

   // FLR_DETECTION_025_028_decoded_msg_t
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_025 = af_target_report_ptr[24].ran;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_026 = af_target_report_ptr[25].ran;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_027 = af_target_report_ptr[26].ran;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_028 = af_target_report_ptr[27].ran;

   data_ptr.FLR_DETECTION_025_028.DET_AZIMUTH_025 = af_target_report_ptr[24].theta;
   data_ptr.FLR_DETECTION_025_028.DET_AZIMUTH_026 = af_target_report_ptr[25].theta;
   data_ptr.FLR_DETECTION_025_028.DET_AZIMUTH_027 = af_target_report_ptr[26].theta;
   data_ptr.FLR_DETECTION_025_028.DET_AZIMUTH_028 = af_target_report_ptr[27].theta;

   data_ptr.FLR_DETECTION_025_028.DET_BI_STATIC_FLAG_025 = af_target_report_ptr[24].f_bistatic;
   data_ptr.FLR_DETECTION_025_028.DET_BI_STATIC_FLAG_026 = af_target_report_ptr[25].f_bistatic;
   data_ptr.FLR_DETECTION_025_028.DET_BI_STATIC_FLAG_027 = af_target_report_ptr[26].f_bistatic;
   data_ptr.FLR_DETECTION_025_028.DET_BI_STATIC_FLAG_028 = af_target_report_ptr[27].f_bistatic;

   data_ptr.FLR_DETECTION_025_028.DET_CONFD_AZIMUTH_025 = af_target_report_ptr[24].az_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_AZIMUTH_026 = af_target_report_ptr[25].az_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_AZIMUTH_027 = af_target_report_ptr[26].az_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_AZIMUTH_028 = af_target_report_ptr[27].az_conf;

   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_025 = af_target_report_ptr[24].phi;
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_026 = af_target_report_ptr[25].phi;
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_027 = af_target_report_ptr[26].phi;
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_028 = af_target_report_ptr[27].phi;

   data_ptr.FLR_DETECTION_025_028.DET_CONFD_ELEVATION_025 = af_target_report_ptr[24].el_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_ELEVATION_026 = af_target_report_ptr[25].el_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_ELEVATION_027 = af_target_report_ptr[26].el_conf;
   data_ptr.FLR_DETECTION_025_028.DET_CONFD_ELEVATION_028 = af_target_report_ptr[27].el_conf;

   data_ptr.FLR_DETECTION_025_028.DET_EXISTENCE_PROB_025 = TOI_DS_Stream_Ptr->existence_prob[24];
   data_ptr.FLR_DETECTION_025_028.DET_EXISTENCE_PROB_026 = TOI_DS_Stream_Ptr->existence_prob[25];
   data_ptr.FLR_DETECTION_025_028.DET_EXISTENCE_PROB_027 = TOI_DS_Stream_Ptr->existence_prob[26];
   data_ptr.FLR_DETECTION_025_028.DET_EXISTENCE_PROB_028 = TOI_DS_Stream_Ptr->existence_prob[27];

   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_ERR_025 = TOI_DS_Stream_Ptr->std_phi[24];
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_ERR_026 = TOI_DS_Stream_Ptr->std_phi[25];
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_ERR_027 = TOI_DS_Stream_Ptr->std_phi[26];
   data_ptr.FLR_DETECTION_025_028.DET_ELEVATION_ERR_028 = TOI_DS_Stream_Ptr->std_phi[27];

   data_ptr.FLR_DETECTION_025_028.DET_IDM_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_IDM_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_IDM_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_IDM_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_025_028.DET_MTD_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_MTD_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_MTD_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_MTD_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_025_028.DET_PROB_1STAZHYPO_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_PROB_1STAZHYPO_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_PROB_1STAZHYPO_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_PROB_1STAZHYPO_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_025_028.DET_RANGE_ERR_025 = TOI_DS_Stream_Ptr->std_ran[24];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_ERR_026 = TOI_DS_Stream_Ptr->std_ran[25];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_ERR_027 = TOI_DS_Stream_Ptr->std_ran[26];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_ERR_028 = TOI_DS_Stream_Ptr->std_ran[27];

   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_025 = af_target_report_ptr[24].vel;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_026 = af_target_report_ptr[25].vel;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_027 = af_target_report_ptr[26].vel;
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_028 = af_target_report_ptr[27].vel;

   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_025 = TOI_DS_Stream_Ptr->std_vel[24];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_026 = TOI_DS_Stream_Ptr->std_vel[25];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_027 = TOI_DS_Stream_Ptr->std_vel[26];
   data_ptr.FLR_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_028 = TOI_DS_Stream_Ptr->std_vel[27];

   data_ptr.FLR_DETECTION_025_028.DET_RCS_025 = af_target_report_ptr[24].rcs;
   data_ptr.FLR_DETECTION_025_028.DET_RCS_026 = af_target_report_ptr[25].rcs;
   data_ptr.FLR_DETECTION_025_028.DET_RCS_027 = af_target_report_ptr[26].rcs;
   data_ptr.FLR_DETECTION_025_028.DET_RCS_028 = af_target_report_ptr[27].rcs;

   data_ptr.FLR_DETECTION_025_028.DET_SNR_025 = af_target_report_ptr[24].snr;
   data_ptr.FLR_DETECTION_025_028.DET_SNR_026 = af_target_report_ptr[25].snr;
   data_ptr.FLR_DETECTION_025_028.DET_SNR_027 = af_target_report_ptr[26].snr;
   data_ptr.FLR_DETECTION_025_028.DET_SNR_028 = af_target_report_ptr[27].snr;

   data_ptr.FLR_DETECTION_025_028.DET_SUPER_RES_TARGET_025 = af_target_report_ptr[24].f_superres_target;
   data_ptr.FLR_DETECTION_025_028.DET_SUPER_RES_TARGET_026 = af_target_report_ptr[25].f_superres_target;
   data_ptr.FLR_DETECTION_025_028.DET_SUPER_RES_TARGET_027 = af_target_report_ptr[26].f_superres_target;
   data_ptr.FLR_DETECTION_025_028.DET_SUPER_RES_TARGET_028 = af_target_report_ptr[27].f_superres_target;

   data_ptr.FLR_DETECTION_025_028.DET_BELOW_RAIN_THOLD_025 = 0;
   data_ptr.FLR_DETECTION_025_028.DET_BELOW_RAIN_THOLD_026 = 0;
   data_ptr.FLR_DETECTION_025_028.DET_BELOW_RAIN_THOLD_027 = 0;
   data_ptr.FLR_DETECTION_025_028.DET_BELOW_RAIN_THOLD_028 = 0;

   data_ptr.FLR_DETECTION_025_028.DET_HVC_FLAG_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_HVC_FLAG_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_HVC_FLAG_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_025_028.DET_HVC_FLAG_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_025_028.DET_MH_CYCLE_COUNTER_025_028   = 0;
   data_ptr.FLR_DETECTION_025_028.DET_MH_CRC16_025_028           = 0;
   data_ptr.FLR_DETECTION_025_028.DET_MH_SCAN_INDEX_4LSB_025_028 = 0;

   // FLR_DETECTION_029_032_decoded_msg_t
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_029 = af_target_report_ptr[28].ran;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_030 = af_target_report_ptr[29].ran;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_031 = af_target_report_ptr[30].ran;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_032 = af_target_report_ptr[31].ran;

   data_ptr.FLR_DETECTION_029_032.DET_AZIMUTH_029 = af_target_report_ptr[28].theta;
   data_ptr.FLR_DETECTION_029_032.DET_AZIMUTH_030 = af_target_report_ptr[29].theta;
   data_ptr.FLR_DETECTION_029_032.DET_AZIMUTH_031 = af_target_report_ptr[30].theta;
   data_ptr.FLR_DETECTION_029_032.DET_AZIMUTH_032 = af_target_report_ptr[31].theta;

   data_ptr.FLR_DETECTION_029_032.DET_BI_STATIC_FLAG_029 = af_target_report_ptr[28].f_bistatic;
   data_ptr.FLR_DETECTION_029_032.DET_BI_STATIC_FLAG_030 = af_target_report_ptr[29].f_bistatic;
   data_ptr.FLR_DETECTION_029_032.DET_BI_STATIC_FLAG_031 = af_target_report_ptr[30].f_bistatic;
   data_ptr.FLR_DETECTION_029_032.DET_BI_STATIC_FLAG_032 = af_target_report_ptr[31].f_bistatic;

   data_ptr.FLR_DETECTION_029_032.DET_CONFD_AZIMUTH_029 = af_target_report_ptr[28].az_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_AZIMUTH_030 = af_target_report_ptr[29].az_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_AZIMUTH_031 = af_target_report_ptr[30].az_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_AZIMUTH_032 = af_target_report_ptr[31].az_conf;

   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_029 = af_target_report_ptr[28].phi;
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_030 = af_target_report_ptr[29].phi;
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_031 = af_target_report_ptr[30].phi;
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_032 = af_target_report_ptr[31].phi;

   data_ptr.FLR_DETECTION_029_032.DET_CONFD_ELEVATION_029 = af_target_report_ptr[28].el_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_ELEVATION_030 = af_target_report_ptr[29].el_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_ELEVATION_031 = af_target_report_ptr[30].el_conf;
   data_ptr.FLR_DETECTION_029_032.DET_CONFD_ELEVATION_032 = af_target_report_ptr[31].el_conf;

   data_ptr.FLR_DETECTION_029_032.DET_EXISTENCE_PROB_029 = TOI_DS_Stream_Ptr->existence_prob[28];
   data_ptr.FLR_DETECTION_029_032.DET_EXISTENCE_PROB_030 = TOI_DS_Stream_Ptr->existence_prob[29];
   data_ptr.FLR_DETECTION_029_032.DET_EXISTENCE_PROB_031 = TOI_DS_Stream_Ptr->existence_prob[30];
   data_ptr.FLR_DETECTION_029_032.DET_EXISTENCE_PROB_032 = TOI_DS_Stream_Ptr->existence_prob[31];

   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_ERR_029 = TOI_DS_Stream_Ptr->std_phi[28];
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_ERR_030 = TOI_DS_Stream_Ptr->std_phi[29];
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_ERR_031 = TOI_DS_Stream_Ptr->std_phi[30];
   data_ptr.FLR_DETECTION_029_032.DET_ELEVATION_ERR_032 = TOI_DS_Stream_Ptr->std_phi[31];

   data_ptr.FLR_DETECTION_029_032.DET_IDM_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_IDM_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_IDM_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_IDM_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_029_032.DET_MTD_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_MTD_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_MTD_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_MTD_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_029_032.DET_PROB_1STAZHYPO_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_PROB_1STAZHYPO_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_PROB_1STAZHYPO_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_PROB_1STAZHYPO_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_029_032.DET_RANGE_ERR_029 = TOI_DS_Stream_Ptr->std_ran[28];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_ERR_030 = TOI_DS_Stream_Ptr->std_ran[29];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_ERR_031 = TOI_DS_Stream_Ptr->std_ran[30];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_ERR_032 = TOI_DS_Stream_Ptr->std_ran[31];

   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_029 = af_target_report_ptr[28].vel;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_030 = af_target_report_ptr[29].vel;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_031 = af_target_report_ptr[30].vel;
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_032 = af_target_report_ptr[31].vel;

   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_029 = TOI_DS_Stream_Ptr->std_vel[28];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_030 = TOI_DS_Stream_Ptr->std_vel[29];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_031 = TOI_DS_Stream_Ptr->std_vel[30];
   data_ptr.FLR_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_032 = TOI_DS_Stream_Ptr->std_vel[31];

   data_ptr.FLR_DETECTION_029_032.DET_RCS_029 = af_target_report_ptr[28].rcs;
   data_ptr.FLR_DETECTION_029_032.DET_RCS_030 = af_target_report_ptr[29].rcs;
   data_ptr.FLR_DETECTION_029_032.DET_RCS_031 = af_target_report_ptr[30].rcs;
   data_ptr.FLR_DETECTION_029_032.DET_RCS_032 = af_target_report_ptr[31].rcs;

   data_ptr.FLR_DETECTION_029_032.DET_SNR_029 = af_target_report_ptr[28].snr;
   data_ptr.FLR_DETECTION_029_032.DET_SNR_030 = af_target_report_ptr[29].snr;
   data_ptr.FLR_DETECTION_029_032.DET_SNR_031 = af_target_report_ptr[30].snr;
   data_ptr.FLR_DETECTION_029_032.DET_SNR_032 = af_target_report_ptr[31].snr;

   data_ptr.FLR_DETECTION_029_032.DET_SUPER_RES_TARGET_029 = af_target_report_ptr[28].f_superres_target;
   data_ptr.FLR_DETECTION_029_032.DET_SUPER_RES_TARGET_030 = af_target_report_ptr[29].f_superres_target;
   data_ptr.FLR_DETECTION_029_032.DET_SUPER_RES_TARGET_031 = af_target_report_ptr[30].f_superres_target;
   data_ptr.FLR_DETECTION_029_032.DET_SUPER_RES_TARGET_032 = af_target_report_ptr[31].f_superres_target;

   data_ptr.FLR_DETECTION_029_032.DET_BELOW_RAIN_THOLD_029 = 0;
   data_ptr.FLR_DETECTION_029_032.DET_BELOW_RAIN_THOLD_030 = 0;
   data_ptr.FLR_DETECTION_029_032.DET_BELOW_RAIN_THOLD_031 = 0;
   data_ptr.FLR_DETECTION_029_032.DET_BELOW_RAIN_THOLD_032 = 0;

   data_ptr.FLR_DETECTION_029_032.DET_HVC_FLAG_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_HVC_FLAG_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_HVC_FLAG_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_029_032.DET_HVC_FLAG_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_029_032.DET_MH_CYCLE_COUNTER_029_032   = 0;
   data_ptr.FLR_DETECTION_029_032.DET_MH_CRC16_029_032           = 0;
   data_ptr.FLR_DETECTION_029_032.DET_MH_SCAN_INDEX_4LSB_029_032 = 0;

   // FLR_DETECTION_033_036_decoded_msg_t
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_033 = af_target_report_ptr[32].ran;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_034 = af_target_report_ptr[33].ran;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_035 = af_target_report_ptr[34].ran;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_036 = af_target_report_ptr[35].ran;

   data_ptr.FLR_DETECTION_033_036.DET_AZIMUTH_033 = af_target_report_ptr[32].theta;
   data_ptr.FLR_DETECTION_033_036.DET_AZIMUTH_034 = af_target_report_ptr[33].theta;
   data_ptr.FLR_DETECTION_033_036.DET_AZIMUTH_035 = af_target_report_ptr[34].theta;
   data_ptr.FLR_DETECTION_033_036.DET_AZIMUTH_036 = af_target_report_ptr[35].theta;

   data_ptr.FLR_DETECTION_033_036.DET_BI_STATIC_FLAG_033 = af_target_report_ptr[32].f_bistatic;
   data_ptr.FLR_DETECTION_033_036.DET_BI_STATIC_FLAG_034 = af_target_report_ptr[33].f_bistatic;
   data_ptr.FLR_DETECTION_033_036.DET_BI_STATIC_FLAG_035 = af_target_report_ptr[34].f_bistatic;
   data_ptr.FLR_DETECTION_033_036.DET_BI_STATIC_FLAG_036 = af_target_report_ptr[35].f_bistatic;

   data_ptr.FLR_DETECTION_033_036.DET_CONFD_AZIMUTH_033 = af_target_report_ptr[32].az_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_AZIMUTH_034 = af_target_report_ptr[33].az_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_AZIMUTH_035 = af_target_report_ptr[34].az_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_AZIMUTH_036 = af_target_report_ptr[35].az_conf;

   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_033 = af_target_report_ptr[32].phi;
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_034 = af_target_report_ptr[33].phi;
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_035 = af_target_report_ptr[34].phi;
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_036 = af_target_report_ptr[35].phi;

   data_ptr.FLR_DETECTION_033_036.DET_CONFD_ELEVATION_033 = af_target_report_ptr[32].el_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_ELEVATION_034 = af_target_report_ptr[33].el_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_ELEVATION_035 = af_target_report_ptr[34].el_conf;
   data_ptr.FLR_DETECTION_033_036.DET_CONFD_ELEVATION_036 = af_target_report_ptr[35].el_conf;

   data_ptr.FLR_DETECTION_033_036.DET_EXISTENCE_PROB_033 = TOI_DS_Stream_Ptr->existence_prob[32];
   data_ptr.FLR_DETECTION_033_036.DET_EXISTENCE_PROB_034 = TOI_DS_Stream_Ptr->existence_prob[33];
   data_ptr.FLR_DETECTION_033_036.DET_EXISTENCE_PROB_035 = TOI_DS_Stream_Ptr->existence_prob[34];
   data_ptr.FLR_DETECTION_033_036.DET_EXISTENCE_PROB_036 = TOI_DS_Stream_Ptr->existence_prob[35];

   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_ERR_033 = TOI_DS_Stream_Ptr->std_phi[32];
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_ERR_034 = TOI_DS_Stream_Ptr->std_phi[33];
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_ERR_035 = TOI_DS_Stream_Ptr->std_phi[34];
   data_ptr.FLR_DETECTION_033_036.DET_ELEVATION_ERR_036 = TOI_DS_Stream_Ptr->std_phi[35];

   data_ptr.FLR_DETECTION_033_036.DET_IDM_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_IDM_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_IDM_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_IDM_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_033_036.DET_MTD_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_MTD_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_MTD_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_MTD_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_033_036.DET_PROB_1STAZHYPO_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_PROB_1STAZHYPO_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_PROB_1STAZHYPO_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_PROB_1STAZHYPO_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_033_036.DET_RANGE_ERR_033 = TOI_DS_Stream_Ptr->std_ran[32];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_ERR_034 = TOI_DS_Stream_Ptr->std_ran[33];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_ERR_035 = TOI_DS_Stream_Ptr->std_ran[34];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_ERR_036 = TOI_DS_Stream_Ptr->std_ran[35];

   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_033 = af_target_report_ptr[32].vel;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_034 = af_target_report_ptr[33].vel;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_035 = af_target_report_ptr[34].vel;
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_036 = af_target_report_ptr[35].vel;

   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_033 = TOI_DS_Stream_Ptr->std_vel[32];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_034 = TOI_DS_Stream_Ptr->std_vel[33];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_035 = TOI_DS_Stream_Ptr->std_vel[34];
   data_ptr.FLR_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_036 = TOI_DS_Stream_Ptr->std_vel[35];

   data_ptr.FLR_DETECTION_033_036.DET_RCS_033 = af_target_report_ptr[32].rcs;
   data_ptr.FLR_DETECTION_033_036.DET_RCS_034 = af_target_report_ptr[33].rcs;
   data_ptr.FLR_DETECTION_033_036.DET_RCS_035 = af_target_report_ptr[34].rcs;
   data_ptr.FLR_DETECTION_033_036.DET_RCS_036 = af_target_report_ptr[35].rcs;

   data_ptr.FLR_DETECTION_033_036.DET_SNR_033 = af_target_report_ptr[32].snr;
   data_ptr.FLR_DETECTION_033_036.DET_SNR_034 = af_target_report_ptr[33].snr;
   data_ptr.FLR_DETECTION_033_036.DET_SNR_035 = af_target_report_ptr[34].snr;
   data_ptr.FLR_DETECTION_033_036.DET_SNR_036 = af_target_report_ptr[35].snr;

   data_ptr.FLR_DETECTION_033_036.DET_SUPER_RES_TARGET_033 = af_target_report_ptr[32].f_superres_target;
   data_ptr.FLR_DETECTION_033_036.DET_SUPER_RES_TARGET_034 = af_target_report_ptr[33].f_superres_target;
   data_ptr.FLR_DETECTION_033_036.DET_SUPER_RES_TARGET_035 = af_target_report_ptr[34].f_superres_target;
   data_ptr.FLR_DETECTION_033_036.DET_SUPER_RES_TARGET_036 = af_target_report_ptr[35].f_superres_target;

   data_ptr.FLR_DETECTION_033_036.DET_BELOW_RAIN_THOLD_033 = 0;
   data_ptr.FLR_DETECTION_033_036.DET_BELOW_RAIN_THOLD_034 = 0;
   data_ptr.FLR_DETECTION_033_036.DET_BELOW_RAIN_THOLD_035 = 0;
   data_ptr.FLR_DETECTION_033_036.DET_BELOW_RAIN_THOLD_036 = 0;

   data_ptr.FLR_DETECTION_033_036.DET_HVC_FLAG_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_HVC_FLAG_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_HVC_FLAG_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_033_036.DET_HVC_FLAG_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_033_036.DET_MH_CYCLE_COUNTER_033_036   = 0;
   data_ptr.FLR_DETECTION_033_036.DET_MH_CRC16_033_036           = 0;
   data_ptr.FLR_DETECTION_033_036.DET_MH_SCAN_INDEX_4LSB_033_036 = 0;

   // FLR_DETECTION_037_040_decoded_msg_t
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_037 = af_target_report_ptr[36].ran;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_038 = af_target_report_ptr[37].ran;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_039 = af_target_report_ptr[38].ran;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_040 = af_target_report_ptr[39].ran;

   data_ptr.FLR_DETECTION_037_040.DET_AZIMUTH_037 = af_target_report_ptr[36].theta;
   data_ptr.FLR_DETECTION_037_040.DET_AZIMUTH_038 = af_target_report_ptr[37].theta;
   data_ptr.FLR_DETECTION_037_040.DET_AZIMUTH_039 = af_target_report_ptr[38].theta;
   data_ptr.FLR_DETECTION_037_040.DET_AZIMUTH_040 = af_target_report_ptr[39].theta;

   data_ptr.FLR_DETECTION_037_040.DET_BI_STATIC_FLAG_037 = af_target_report_ptr[36].f_bistatic;
   data_ptr.FLR_DETECTION_037_040.DET_BI_STATIC_FLAG_038 = af_target_report_ptr[37].f_bistatic;
   data_ptr.FLR_DETECTION_037_040.DET_BI_STATIC_FLAG_039 = af_target_report_ptr[38].f_bistatic;
   data_ptr.FLR_DETECTION_037_040.DET_BI_STATIC_FLAG_040 = af_target_report_ptr[39].f_bistatic;

   data_ptr.FLR_DETECTION_037_040.DET_CONFD_AZIMUTH_037 = af_target_report_ptr[36].az_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_AZIMUTH_038 = af_target_report_ptr[37].az_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_AZIMUTH_039 = af_target_report_ptr[38].az_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_AZIMUTH_040 = af_target_report_ptr[39].az_conf;

   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_037 = af_target_report_ptr[36].phi;
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_038 = af_target_report_ptr[37].phi;
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_039 = af_target_report_ptr[38].phi;
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_040 = af_target_report_ptr[39].phi;

   data_ptr.FLR_DETECTION_037_040.DET_CONFD_ELEVATION_037 = af_target_report_ptr[36].el_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_ELEVATION_038 = af_target_report_ptr[37].el_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_ELEVATION_039 = af_target_report_ptr[38].el_conf;
   data_ptr.FLR_DETECTION_037_040.DET_CONFD_ELEVATION_040 = af_target_report_ptr[39].el_conf;

   data_ptr.FLR_DETECTION_037_040.DET_EXISTENCE_PROB_037 = TOI_DS_Stream_Ptr->existence_prob[36];
   data_ptr.FLR_DETECTION_037_040.DET_EXISTENCE_PROB_038 = TOI_DS_Stream_Ptr->existence_prob[37];
   data_ptr.FLR_DETECTION_037_040.DET_EXISTENCE_PROB_039 = TOI_DS_Stream_Ptr->existence_prob[38];
   data_ptr.FLR_DETECTION_037_040.DET_EXISTENCE_PROB_040 = TOI_DS_Stream_Ptr->existence_prob[39];

   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_ERR_037 = TOI_DS_Stream_Ptr->std_phi[36];
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_ERR_038 = TOI_DS_Stream_Ptr->std_phi[37];
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_ERR_039 = TOI_DS_Stream_Ptr->std_phi[38];
   data_ptr.FLR_DETECTION_037_040.DET_ELEVATION_ERR_040 = TOI_DS_Stream_Ptr->std_phi[39];

   data_ptr.FLR_DETECTION_037_040.DET_IDM_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_IDM_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_IDM_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_IDM_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_037_040.DET_MTD_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_MTD_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_MTD_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_MTD_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_037_040.DET_PROB_1STAZHYPO_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_PROB_1STAZHYPO_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_PROB_1STAZHYPO_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_PROB_1STAZHYPO_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_037_040.DET_RANGE_ERR_037 = TOI_DS_Stream_Ptr->std_ran[36];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_ERR_038 = TOI_DS_Stream_Ptr->std_ran[37];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_ERR_039 = TOI_DS_Stream_Ptr->std_ran[38];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_ERR_040 = TOI_DS_Stream_Ptr->std_ran[39];

   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_037 = af_target_report_ptr[36].vel;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_038 = af_target_report_ptr[37].vel;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_039 = af_target_report_ptr[38].vel;
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_040 = af_target_report_ptr[39].vel;

   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_037 = TOI_DS_Stream_Ptr->std_vel[36];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_038 = TOI_DS_Stream_Ptr->std_vel[37];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_039 = TOI_DS_Stream_Ptr->std_vel[38];
   data_ptr.FLR_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_040 = TOI_DS_Stream_Ptr->std_vel[39];

   data_ptr.FLR_DETECTION_037_040.DET_RCS_037 = af_target_report_ptr[36].rcs;
   data_ptr.FLR_DETECTION_037_040.DET_RCS_038 = af_target_report_ptr[37].rcs;
   data_ptr.FLR_DETECTION_037_040.DET_RCS_039 = af_target_report_ptr[38].rcs;
   data_ptr.FLR_DETECTION_037_040.DET_RCS_040 = af_target_report_ptr[39].rcs;

   data_ptr.FLR_DETECTION_037_040.DET_SNR_037 = af_target_report_ptr[36].snr;
   data_ptr.FLR_DETECTION_037_040.DET_SNR_038 = af_target_report_ptr[37].snr;
   data_ptr.FLR_DETECTION_037_040.DET_SNR_039 = af_target_report_ptr[38].snr;
   data_ptr.FLR_DETECTION_037_040.DET_SNR_040 = af_target_report_ptr[39].snr;

   data_ptr.FLR_DETECTION_037_040.DET_SUPER_RES_TARGET_037 = af_target_report_ptr[36].f_superres_target;
   data_ptr.FLR_DETECTION_037_040.DET_SUPER_RES_TARGET_038 = af_target_report_ptr[37].f_superres_target;
   data_ptr.FLR_DETECTION_037_040.DET_SUPER_RES_TARGET_039 = af_target_report_ptr[38].f_superres_target;
   data_ptr.FLR_DETECTION_037_040.DET_SUPER_RES_TARGET_040 = af_target_report_ptr[39].f_superres_target;

   data_ptr.FLR_DETECTION_037_040.DET_BELOW_RAIN_THOLD_037 = 0;
   data_ptr.FLR_DETECTION_037_040.DET_BELOW_RAIN_THOLD_038 = 0;
   data_ptr.FLR_DETECTION_037_040.DET_BELOW_RAIN_THOLD_039 = 0;
   data_ptr.FLR_DETECTION_037_040.DET_BELOW_RAIN_THOLD_040 = 0;

   data_ptr.FLR_DETECTION_037_040.DET_HVC_FLAG_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_HVC_FLAG_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_HVC_FLAG_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_037_040.DET_HVC_FLAG_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_037_040.DET_MH_CYCLE_COUNTER_037_040   = 0;
   data_ptr.FLR_DETECTION_037_040.DET_MH_CRC16_037_040           = 0;
   data_ptr.FLR_DETECTION_037_040.DET_MH_SCAN_INDEX_4LSB_037_040 = 0;

   // FLR_DETECTION_041_044_decoded_msg_t

   data_ptr.FLR_DETECTION_041_044.DET_RANGE_041 = af_target_report_ptr[40].ran;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_042 = af_target_report_ptr[41].ran;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_043 = af_target_report_ptr[42].ran;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_044 = af_target_report_ptr[43].ran;

   data_ptr.FLR_DETECTION_041_044.DET_AZIMUTH_041 = af_target_report_ptr[40].theta;
   data_ptr.FLR_DETECTION_041_044.DET_AZIMUTH_042 = af_target_report_ptr[41].theta;
   data_ptr.FLR_DETECTION_041_044.DET_AZIMUTH_043 = af_target_report_ptr[42].theta;
   data_ptr.FLR_DETECTION_041_044.DET_AZIMUTH_044 = af_target_report_ptr[43].theta;

   data_ptr.FLR_DETECTION_041_044.DET_BI_STATIC_FLAG_041 = af_target_report_ptr[40].f_bistatic;
   data_ptr.FLR_DETECTION_041_044.DET_BI_STATIC_FLAG_042 = af_target_report_ptr[41].f_bistatic;
   data_ptr.FLR_DETECTION_041_044.DET_BI_STATIC_FLAG_043 = af_target_report_ptr[42].f_bistatic;
   data_ptr.FLR_DETECTION_041_044.DET_BI_STATIC_FLAG_044 = af_target_report_ptr[43].f_bistatic;

   data_ptr.FLR_DETECTION_041_044.DET_CONFD_AZIMUTH_041 = af_target_report_ptr[40].az_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_AZIMUTH_042 = af_target_report_ptr[41].az_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_AZIMUTH_043 = af_target_report_ptr[42].az_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_AZIMUTH_044 = af_target_report_ptr[43].az_conf;

   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_041 = af_target_report_ptr[40].phi;
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_042 = af_target_report_ptr[41].phi;
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_043 = af_target_report_ptr[42].phi;
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_044 = af_target_report_ptr[43].phi;

   data_ptr.FLR_DETECTION_041_044.DET_CONFD_ELEVATION_041 = af_target_report_ptr[40].el_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_ELEVATION_042 = af_target_report_ptr[41].el_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_ELEVATION_043 = af_target_report_ptr[42].el_conf;
   data_ptr.FLR_DETECTION_041_044.DET_CONFD_ELEVATION_044 = af_target_report_ptr[43].el_conf;

   data_ptr.FLR_DETECTION_041_044.DET_EXISTENCE_PROB_041 = TOI_DS_Stream_Ptr->existence_prob[40];
   data_ptr.FLR_DETECTION_041_044.DET_EXISTENCE_PROB_042 = TOI_DS_Stream_Ptr->existence_prob[41];
   data_ptr.FLR_DETECTION_041_044.DET_EXISTENCE_PROB_043 = TOI_DS_Stream_Ptr->existence_prob[42];
   data_ptr.FLR_DETECTION_041_044.DET_EXISTENCE_PROB_044 = TOI_DS_Stream_Ptr->existence_prob[43];

   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_ERR_041 = TOI_DS_Stream_Ptr->std_phi[40];
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_ERR_042 = TOI_DS_Stream_Ptr->std_phi[41];
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_ERR_043 = TOI_DS_Stream_Ptr->std_phi[42];
   data_ptr.FLR_DETECTION_041_044.DET_ELEVATION_ERR_044 = TOI_DS_Stream_Ptr->std_phi[43];

   data_ptr.FLR_DETECTION_041_044.DET_IDM_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_IDM_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_IDM_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_IDM_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_041_044.DET_MTD_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_MTD_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_MTD_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_MTD_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_041_044.DET_PROB_1STAZHYPO_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_PROB_1STAZHYPO_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_PROB_1STAZHYPO_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_PROB_1STAZHYPO_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_041_044.DET_RANGE_ERR_041 = TOI_DS_Stream_Ptr->std_ran[40];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_ERR_042 = TOI_DS_Stream_Ptr->std_ran[41];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_ERR_043 = TOI_DS_Stream_Ptr->std_ran[42];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_ERR_044 = TOI_DS_Stream_Ptr->std_ran[43];

   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_041 = af_target_report_ptr[40].vel;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_042 = af_target_report_ptr[41].vel;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_043 = af_target_report_ptr[42].vel;
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_044 = af_target_report_ptr[43].vel;

   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_041 = TOI_DS_Stream_Ptr->std_vel[40];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_042 = TOI_DS_Stream_Ptr->std_vel[41];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_043 = TOI_DS_Stream_Ptr->std_vel[42];
   data_ptr.FLR_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_044 = TOI_DS_Stream_Ptr->std_vel[43];

   data_ptr.FLR_DETECTION_041_044.DET_RCS_041 = af_target_report_ptr[40].rcs;
   data_ptr.FLR_DETECTION_041_044.DET_RCS_042 = af_target_report_ptr[41].rcs;
   data_ptr.FLR_DETECTION_041_044.DET_RCS_043 = af_target_report_ptr[42].rcs;
   data_ptr.FLR_DETECTION_041_044.DET_RCS_044 = af_target_report_ptr[43].rcs;

   data_ptr.FLR_DETECTION_041_044.DET_SNR_041 = af_target_report_ptr[40].snr;
   data_ptr.FLR_DETECTION_041_044.DET_SNR_042 = af_target_report_ptr[41].snr;
   data_ptr.FLR_DETECTION_041_044.DET_SNR_043 = af_target_report_ptr[42].snr;
   data_ptr.FLR_DETECTION_041_044.DET_SNR_044 = af_target_report_ptr[43].snr;

   data_ptr.FLR_DETECTION_041_044.DET_SUPER_RES_TARGET_041 = af_target_report_ptr[40].f_superres_target;
   data_ptr.FLR_DETECTION_041_044.DET_SUPER_RES_TARGET_042 = af_target_report_ptr[41].f_superres_target;
   data_ptr.FLR_DETECTION_041_044.DET_SUPER_RES_TARGET_043 = af_target_report_ptr[42].f_superres_target;
   data_ptr.FLR_DETECTION_041_044.DET_SUPER_RES_TARGET_044 = af_target_report_ptr[43].f_superres_target;

   data_ptr.FLR_DETECTION_041_044.DET_BELOW_RAIN_THOLD_041 = 0;
   data_ptr.FLR_DETECTION_041_044.DET_BELOW_RAIN_THOLD_042 = 0;
   data_ptr.FLR_DETECTION_041_044.DET_BELOW_RAIN_THOLD_043 = 0;
   data_ptr.FLR_DETECTION_041_044.DET_BELOW_RAIN_THOLD_044 = 0;

   data_ptr.FLR_DETECTION_041_044.DET_HVC_FLAG_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_HVC_FLAG_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_HVC_FLAG_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_041_044.DET_HVC_FLAG_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_041_044.DET_MH_CYCLE_COUNTER_041_044   = 0;
   data_ptr.FLR_DETECTION_041_044.DET_MH_CRC16_041_044           = 0;
   data_ptr.FLR_DETECTION_041_044.DET_MH_SCAN_INDEX_4LSB_041_044 = 0;

   // FLR_DETECTION_045_048_decoded_msg_t

   data_ptr.FLR_DETECTION_045_048.DET_RANGE_045 = af_target_report_ptr[44].ran;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_046 = af_target_report_ptr[45].ran;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_047 = af_target_report_ptr[46].ran;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_048 = af_target_report_ptr[47].ran;

   data_ptr.FLR_DETECTION_045_048.DET_AZIMUTH_045 = af_target_report_ptr[44].theta;
   data_ptr.FLR_DETECTION_045_048.DET_AZIMUTH_046 = af_target_report_ptr[45].theta;
   data_ptr.FLR_DETECTION_045_048.DET_AZIMUTH_047 = af_target_report_ptr[46].theta;
   data_ptr.FLR_DETECTION_045_048.DET_AZIMUTH_048 = af_target_report_ptr[47].theta;

   data_ptr.FLR_DETECTION_045_048.DET_BI_STATIC_FLAG_045 = af_target_report_ptr[44].f_bistatic;
   data_ptr.FLR_DETECTION_045_048.DET_BI_STATIC_FLAG_046 = af_target_report_ptr[45].f_bistatic;
   data_ptr.FLR_DETECTION_045_048.DET_BI_STATIC_FLAG_047 = af_target_report_ptr[46].f_bistatic;
   data_ptr.FLR_DETECTION_045_048.DET_BI_STATIC_FLAG_048 = af_target_report_ptr[47].f_bistatic;

   data_ptr.FLR_DETECTION_045_048.DET_CONFD_AZIMUTH_045 = af_target_report_ptr[44].az_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_AZIMUTH_046 = af_target_report_ptr[45].az_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_AZIMUTH_047 = af_target_report_ptr[46].az_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_AZIMUTH_048 = af_target_report_ptr[47].az_conf;

   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_045 = af_target_report_ptr[44].phi;
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_046 = af_target_report_ptr[45].phi;
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_047 = af_target_report_ptr[46].phi;
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_048 = af_target_report_ptr[47].phi;

   data_ptr.FLR_DETECTION_045_048.DET_CONFD_ELEVATION_045 = af_target_report_ptr[44].el_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_ELEVATION_046 = af_target_report_ptr[45].el_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_ELEVATION_047 = af_target_report_ptr[46].el_conf;
   data_ptr.FLR_DETECTION_045_048.DET_CONFD_ELEVATION_048 = af_target_report_ptr[47].el_conf;

   data_ptr.FLR_DETECTION_045_048.DET_EXISTENCE_PROB_045 = TOI_DS_Stream_Ptr->existence_prob[44];
   data_ptr.FLR_DETECTION_045_048.DET_EXISTENCE_PROB_046 = TOI_DS_Stream_Ptr->existence_prob[45];
   data_ptr.FLR_DETECTION_045_048.DET_EXISTENCE_PROB_047 = TOI_DS_Stream_Ptr->existence_prob[46];
   data_ptr.FLR_DETECTION_045_048.DET_EXISTENCE_PROB_048 = TOI_DS_Stream_Ptr->existence_prob[47];

   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_ERR_045 = TOI_DS_Stream_Ptr->std_phi[44];
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_ERR_046 = TOI_DS_Stream_Ptr->std_phi[45];
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_ERR_047 = TOI_DS_Stream_Ptr->std_phi[46];
   data_ptr.FLR_DETECTION_045_048.DET_ELEVATION_ERR_048 = TOI_DS_Stream_Ptr->std_phi[47];

   data_ptr.FLR_DETECTION_045_048.DET_IDM_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_IDM_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_IDM_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_IDM_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_045_048.DET_MTD_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_MTD_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_MTD_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_MTD_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_045_048.DET_PROB_1STAZHYPO_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_PROB_1STAZHYPO_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_PROB_1STAZHYPO_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_PROB_1STAZHYPO_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_045_048.DET_RANGE_ERR_045 = TOI_DS_Stream_Ptr->std_ran[44];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_ERR_046 = TOI_DS_Stream_Ptr->std_ran[45];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_ERR_047 = TOI_DS_Stream_Ptr->std_ran[46];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_ERR_048 = TOI_DS_Stream_Ptr->std_ran[47];

   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_045 = af_target_report_ptr[44].vel;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_046 = af_target_report_ptr[45].vel;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_047 = af_target_report_ptr[46].vel;
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_048 = af_target_report_ptr[47].vel;

   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_045 = TOI_DS_Stream_Ptr->std_vel[44];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_046 = TOI_DS_Stream_Ptr->std_vel[45];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_047 = TOI_DS_Stream_Ptr->std_vel[46];
   data_ptr.FLR_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_048 = TOI_DS_Stream_Ptr->std_vel[47];

   data_ptr.FLR_DETECTION_045_048.DET_RCS_045 = af_target_report_ptr[44].rcs;
   data_ptr.FLR_DETECTION_045_048.DET_RCS_046 = af_target_report_ptr[45].rcs;
   data_ptr.FLR_DETECTION_045_048.DET_RCS_047 = af_target_report_ptr[46].rcs;
   data_ptr.FLR_DETECTION_045_048.DET_RCS_048 = af_target_report_ptr[47].rcs;

   data_ptr.FLR_DETECTION_045_048.DET_SNR_045 = af_target_report_ptr[44].snr;
   data_ptr.FLR_DETECTION_045_048.DET_SNR_046 = af_target_report_ptr[45].snr;
   data_ptr.FLR_DETECTION_045_048.DET_SNR_047 = af_target_report_ptr[46].snr;
   data_ptr.FLR_DETECTION_045_048.DET_SNR_048 = af_target_report_ptr[47].snr;

   data_ptr.FLR_DETECTION_045_048.DET_SUPER_RES_TARGET_045 = af_target_report_ptr[44].f_superres_target;
   data_ptr.FLR_DETECTION_045_048.DET_SUPER_RES_TARGET_046 = af_target_report_ptr[45].f_superres_target;
   data_ptr.FLR_DETECTION_045_048.DET_SUPER_RES_TARGET_047 = af_target_report_ptr[46].f_superres_target;
   data_ptr.FLR_DETECTION_045_048.DET_SUPER_RES_TARGET_048 = af_target_report_ptr[47].f_superres_target;

   data_ptr.FLR_DETECTION_045_048.DET_BELOW_RAIN_THOLD_045 = 0;
   data_ptr.FLR_DETECTION_045_048.DET_BELOW_RAIN_THOLD_046 = 0;
   data_ptr.FLR_DETECTION_045_048.DET_BELOW_RAIN_THOLD_047 = 0;
   data_ptr.FLR_DETECTION_045_048.DET_BELOW_RAIN_THOLD_048 = 0;

   data_ptr.FLR_DETECTION_045_048.DET_HVC_FLAG_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_HVC_FLAG_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_HVC_FLAG_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_045_048.DET_HVC_FLAG_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_045_048.DET_MH_CYCLE_COUNTER_045_048   = 0;
   data_ptr.FLR_DETECTION_045_048.DET_MH_CRC16_045_048           = 0;
   data_ptr.FLR_DETECTION_045_048.DET_MH_SCAN_INDEX_4LSB_045_048 = 0;
   // FLR_DETECTION_049_052_decoded_msg_t

   data_ptr.FLR_DETECTION_049_052.DET_RANGE_049 = af_target_report_ptr[48].ran;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_050 = af_target_report_ptr[49].ran;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_051 = af_target_report_ptr[50].ran;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_052 = af_target_report_ptr[51].ran;

   data_ptr.FLR_DETECTION_049_052.DET_AZIMUTH_049 = af_target_report_ptr[48].theta;
   data_ptr.FLR_DETECTION_049_052.DET_AZIMUTH_050 = af_target_report_ptr[49].theta;
   data_ptr.FLR_DETECTION_049_052.DET_AZIMUTH_051 = af_target_report_ptr[50].theta;
   data_ptr.FLR_DETECTION_049_052.DET_AZIMUTH_052 = af_target_report_ptr[51].theta;

   data_ptr.FLR_DETECTION_049_052.DET_BI_STATIC_FLAG_049 = af_target_report_ptr[48].f_bistatic;
   data_ptr.FLR_DETECTION_049_052.DET_BI_STATIC_FLAG_050 = af_target_report_ptr[49].f_bistatic;
   data_ptr.FLR_DETECTION_049_052.DET_BI_STATIC_FLAG_051 = af_target_report_ptr[50].f_bistatic;
   data_ptr.FLR_DETECTION_049_052.DET_BI_STATIC_FLAG_052 = af_target_report_ptr[51].f_bistatic;

   data_ptr.FLR_DETECTION_049_052.DET_CONFD_AZIMUTH_049 = af_target_report_ptr[48].az_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_AZIMUTH_050 = af_target_report_ptr[49].az_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_AZIMUTH_051 = af_target_report_ptr[50].az_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_AZIMUTH_052 = af_target_report_ptr[51].az_conf;

   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_049 = af_target_report_ptr[48].phi;
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_050 = af_target_report_ptr[49].phi;
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_051 = af_target_report_ptr[50].phi;
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_052 = af_target_report_ptr[51].phi;

   data_ptr.FLR_DETECTION_049_052.DET_CONFD_ELEVATION_049 = af_target_report_ptr[48].el_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_ELEVATION_050 = af_target_report_ptr[49].el_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_ELEVATION_051 = af_target_report_ptr[50].el_conf;
   data_ptr.FLR_DETECTION_049_052.DET_CONFD_ELEVATION_052 = af_target_report_ptr[51].el_conf;

   data_ptr.FLR_DETECTION_049_052.DET_EXISTENCE_PROB_049 = TOI_DS_Stream_Ptr->existence_prob[48];
   data_ptr.FLR_DETECTION_049_052.DET_EXISTENCE_PROB_050 = TOI_DS_Stream_Ptr->existence_prob[49];
   data_ptr.FLR_DETECTION_049_052.DET_EXISTENCE_PROB_051 = TOI_DS_Stream_Ptr->existence_prob[50];
   data_ptr.FLR_DETECTION_049_052.DET_EXISTENCE_PROB_052 = TOI_DS_Stream_Ptr->existence_prob[51];

   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_ERR_049 = TOI_DS_Stream_Ptr->std_phi[48];
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_ERR_050 = TOI_DS_Stream_Ptr->std_phi[49];
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_ERR_051 = TOI_DS_Stream_Ptr->std_phi[50];
   data_ptr.FLR_DETECTION_049_052.DET_ELEVATION_ERR_052 = TOI_DS_Stream_Ptr->std_phi[51];

   data_ptr.FLR_DETECTION_049_052.DET_IDM_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_IDM_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_IDM_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_IDM_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_049_052.DET_MTD_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_MTD_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_MTD_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_MTD_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_049_052.DET_PROB_1STAZHYPO_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_PROB_1STAZHYPO_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_PROB_1STAZHYPO_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_PROB_1STAZHYPO_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_049_052.DET_RANGE_ERR_049 = TOI_DS_Stream_Ptr->std_ran[48];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_ERR_050 = TOI_DS_Stream_Ptr->std_ran[49];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_ERR_051 = TOI_DS_Stream_Ptr->std_ran[50];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_ERR_052 = TOI_DS_Stream_Ptr->std_ran[51];

   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_049 = af_target_report_ptr[48].vel;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_050 = af_target_report_ptr[49].vel;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_051 = af_target_report_ptr[50].vel;
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_052 = af_target_report_ptr[51].vel;

   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_049 = TOI_DS_Stream_Ptr->std_vel[48];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_050 = TOI_DS_Stream_Ptr->std_vel[49];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_051 = TOI_DS_Stream_Ptr->std_vel[50];
   data_ptr.FLR_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_052 = TOI_DS_Stream_Ptr->std_vel[51];

   data_ptr.FLR_DETECTION_049_052.DET_RCS_049 = af_target_report_ptr[48].rcs;
   data_ptr.FLR_DETECTION_049_052.DET_RCS_050 = af_target_report_ptr[49].rcs;
   data_ptr.FLR_DETECTION_049_052.DET_RCS_051 = af_target_report_ptr[50].rcs;
   data_ptr.FLR_DETECTION_049_052.DET_RCS_052 = af_target_report_ptr[51].rcs;

   data_ptr.FLR_DETECTION_049_052.DET_SNR_049 = af_target_report_ptr[48].snr;
   data_ptr.FLR_DETECTION_049_052.DET_SNR_050 = af_target_report_ptr[49].snr;
   data_ptr.FLR_DETECTION_049_052.DET_SNR_051 = af_target_report_ptr[50].snr;
   data_ptr.FLR_DETECTION_049_052.DET_SNR_052 = af_target_report_ptr[51].snr;

   data_ptr.FLR_DETECTION_049_052.DET_SUPER_RES_TARGET_049 = af_target_report_ptr[48].f_superres_target;
   data_ptr.FLR_DETECTION_049_052.DET_SUPER_RES_TARGET_050 = af_target_report_ptr[49].f_superres_target;
   data_ptr.FLR_DETECTION_049_052.DET_SUPER_RES_TARGET_051 = af_target_report_ptr[50].f_superres_target;
   data_ptr.FLR_DETECTION_049_052.DET_SUPER_RES_TARGET_052 = af_target_report_ptr[51].f_superres_target;

   data_ptr.FLR_DETECTION_049_052.DET_BELOW_RAIN_THOLD_049 = 0;
   data_ptr.FLR_DETECTION_049_052.DET_BELOW_RAIN_THOLD_050 = 0;
   data_ptr.FLR_DETECTION_049_052.DET_BELOW_RAIN_THOLD_051 = 0;
   data_ptr.FLR_DETECTION_049_052.DET_BELOW_RAIN_THOLD_052 = 0;

   data_ptr.FLR_DETECTION_049_052.DET_HVC_FLAG_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_HVC_FLAG_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_HVC_FLAG_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_049_052.DET_HVC_FLAG_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_049_052.DET_MH_CYCLE_COUNTER_049_052   = 0;
   data_ptr.FLR_DETECTION_049_052.DET_MH_CRC16_049_052           = 0;
   data_ptr.FLR_DETECTION_049_052.DET_MH_SCAN_INDEX_4LSB_049_052 = 0;

   // FLR_DETECTION_053_056_decoded_msg_t

   data_ptr.FLR_DETECTION_053_056.DET_RANGE_053 = af_target_report_ptr[52].ran;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_054 = af_target_report_ptr[53].ran;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_055 = af_target_report_ptr[54].ran;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_056 = af_target_report_ptr[55].ran;

   data_ptr.FLR_DETECTION_053_056.DET_AZIMUTH_053 = af_target_report_ptr[52].theta;
   data_ptr.FLR_DETECTION_053_056.DET_AZIMUTH_054 = af_target_report_ptr[53].theta;
   data_ptr.FLR_DETECTION_053_056.DET_AZIMUTH_055 = af_target_report_ptr[54].theta;
   data_ptr.FLR_DETECTION_053_056.DET_AZIMUTH_056 = af_target_report_ptr[55].theta;

   data_ptr.FLR_DETECTION_053_056.DET_BI_STATIC_FLAG_053 = af_target_report_ptr[52].f_bistatic;
   data_ptr.FLR_DETECTION_053_056.DET_BI_STATIC_FLAG_054 = af_target_report_ptr[53].f_bistatic;
   data_ptr.FLR_DETECTION_053_056.DET_BI_STATIC_FLAG_055 = af_target_report_ptr[54].f_bistatic;
   data_ptr.FLR_DETECTION_053_056.DET_BI_STATIC_FLAG_056 = af_target_report_ptr[55].f_bistatic;

   data_ptr.FLR_DETECTION_053_056.DET_CONFD_AZIMUTH_053 = af_target_report_ptr[52].az_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_AZIMUTH_054 = af_target_report_ptr[53].az_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_AZIMUTH_055 = af_target_report_ptr[54].az_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_AZIMUTH_056 = af_target_report_ptr[55].az_conf;

   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_053 = af_target_report_ptr[52].phi;
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_054 = af_target_report_ptr[53].phi;
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_055 = af_target_report_ptr[54].phi;
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_056 = af_target_report_ptr[55].phi;

   data_ptr.FLR_DETECTION_053_056.DET_CONFD_ELEVATION_053 = af_target_report_ptr[52].el_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_ELEVATION_054 = af_target_report_ptr[53].el_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_ELEVATION_055 = af_target_report_ptr[54].el_conf;
   data_ptr.FLR_DETECTION_053_056.DET_CONFD_ELEVATION_056 = af_target_report_ptr[55].el_conf;

   data_ptr.FLR_DETECTION_053_056.DET_EXISTENCE_PROB_053 = TOI_DS_Stream_Ptr->existence_prob[52];
   data_ptr.FLR_DETECTION_053_056.DET_EXISTENCE_PROB_054 = TOI_DS_Stream_Ptr->existence_prob[53];
   data_ptr.FLR_DETECTION_053_056.DET_EXISTENCE_PROB_055 = TOI_DS_Stream_Ptr->existence_prob[54];
   data_ptr.FLR_DETECTION_053_056.DET_EXISTENCE_PROB_056 = TOI_DS_Stream_Ptr->existence_prob[55];

   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_ERR_053 = TOI_DS_Stream_Ptr->std_phi[52];
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_ERR_054 = TOI_DS_Stream_Ptr->std_phi[53];
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_ERR_055 = TOI_DS_Stream_Ptr->std_phi[54];
   data_ptr.FLR_DETECTION_053_056.DET_ELEVATION_ERR_056 = TOI_DS_Stream_Ptr->std_phi[55];

   data_ptr.FLR_DETECTION_053_056.DET_IDM_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_IDM_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_IDM_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_IDM_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_053_056.DET_MTD_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_MTD_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_MTD_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_MTD_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_053_056.DET_PROB_1STAZHYPO_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_PROB_1STAZHYPO_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_PROB_1STAZHYPO_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_PROB_1STAZHYPO_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_053_056.DET_RANGE_ERR_053 = TOI_DS_Stream_Ptr->std_ran[52];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_ERR_054 = TOI_DS_Stream_Ptr->std_ran[53];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_ERR_055 = TOI_DS_Stream_Ptr->std_ran[54];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_ERR_056 = TOI_DS_Stream_Ptr->std_ran[55];

   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_053 = af_target_report_ptr[52].vel;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_054 = af_target_report_ptr[53].vel;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_055 = af_target_report_ptr[54].vel;
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_056 = af_target_report_ptr[55].vel;

   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_053 = TOI_DS_Stream_Ptr->std_vel[52];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_054 = TOI_DS_Stream_Ptr->std_vel[53];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_055 = TOI_DS_Stream_Ptr->std_vel[54];
   data_ptr.FLR_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_056 = TOI_DS_Stream_Ptr->std_vel[55];

   data_ptr.FLR_DETECTION_053_056.DET_RCS_053 = af_target_report_ptr[52].rcs;
   data_ptr.FLR_DETECTION_053_056.DET_RCS_054 = af_target_report_ptr[53].rcs;
   data_ptr.FLR_DETECTION_053_056.DET_RCS_055 = af_target_report_ptr[54].rcs;
   data_ptr.FLR_DETECTION_053_056.DET_RCS_056 = af_target_report_ptr[55].rcs;

   data_ptr.FLR_DETECTION_053_056.DET_SNR_053 = af_target_report_ptr[52].snr;
   data_ptr.FLR_DETECTION_053_056.DET_SNR_054 = af_target_report_ptr[53].snr;
   data_ptr.FLR_DETECTION_053_056.DET_SNR_055 = af_target_report_ptr[54].snr;
   data_ptr.FLR_DETECTION_053_056.DET_SNR_056 = af_target_report_ptr[55].snr;

   data_ptr.FLR_DETECTION_053_056.DET_SUPER_RES_TARGET_053 = af_target_report_ptr[52].f_superres_target;
   data_ptr.FLR_DETECTION_053_056.DET_SUPER_RES_TARGET_054 = af_target_report_ptr[53].f_superres_target;
   data_ptr.FLR_DETECTION_053_056.DET_SUPER_RES_TARGET_055 = af_target_report_ptr[54].f_superres_target;
   data_ptr.FLR_DETECTION_053_056.DET_SUPER_RES_TARGET_056 = af_target_report_ptr[55].f_superres_target;

   data_ptr.FLR_DETECTION_053_056.DET_BELOW_RAIN_THOLD_053 = 0;
   data_ptr.FLR_DETECTION_053_056.DET_BELOW_RAIN_THOLD_054 = 0;
   data_ptr.FLR_DETECTION_053_056.DET_BELOW_RAIN_THOLD_055 = 0;
   data_ptr.FLR_DETECTION_053_056.DET_BELOW_RAIN_THOLD_056 = 0;

   data_ptr.FLR_DETECTION_053_056.DET_HVC_FLAG_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_HVC_FLAG_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_HVC_FLAG_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_053_056.DET_HVC_FLAG_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_053_056.DET_MH_CYCLE_COUNTER_053_056   = 0;
   data_ptr.FLR_DETECTION_053_056.DET_MH_CRC16_053_056           = 0;
   data_ptr.FLR_DETECTION_053_056.DET_MH_SCAN_INDEX_4LSB_053_056 = 0;

   // FLR_DETECTION_057_060_decoded_msg_t

   data_ptr.FLR_DETECTION_057_060.DET_RANGE_057 = af_target_report_ptr[56].ran;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_058 = af_target_report_ptr[57].ran;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_059 = af_target_report_ptr[58].ran;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_060 = af_target_report_ptr[59].ran;

   data_ptr.FLR_DETECTION_057_060.DET_AZIMUTH_057 = af_target_report_ptr[56].theta;
   data_ptr.FLR_DETECTION_057_060.DET_AZIMUTH_058 = af_target_report_ptr[57].theta;
   data_ptr.FLR_DETECTION_057_060.DET_AZIMUTH_059 = af_target_report_ptr[58].theta;
   data_ptr.FLR_DETECTION_057_060.DET_AZIMUTH_060 = af_target_report_ptr[59].theta;

   data_ptr.FLR_DETECTION_057_060.DET_BI_STATIC_FLAG_057 = af_target_report_ptr[56].f_bistatic;
   data_ptr.FLR_DETECTION_057_060.DET_BI_STATIC_FLAG_058 = af_target_report_ptr[57].f_bistatic;
   data_ptr.FLR_DETECTION_057_060.DET_BI_STATIC_FLAG_059 = af_target_report_ptr[58].f_bistatic;
   data_ptr.FLR_DETECTION_057_060.DET_BI_STATIC_FLAG_060 = af_target_report_ptr[59].f_bistatic;

   data_ptr.FLR_DETECTION_057_060.DET_CONFD_AZIMUTH_057 = af_target_report_ptr[56].az_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_AZIMUTH_058 = af_target_report_ptr[57].az_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_AZIMUTH_059 = af_target_report_ptr[58].az_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_AZIMUTH_060 = af_target_report_ptr[59].az_conf;

   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_057 = af_target_report_ptr[56].phi;
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_058 = af_target_report_ptr[57].phi;
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_059 = af_target_report_ptr[58].phi;
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_060 = af_target_report_ptr[59].phi;

   data_ptr.FLR_DETECTION_057_060.DET_CONFD_ELEVATION_057 = af_target_report_ptr[56].el_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_ELEVATION_058 = af_target_report_ptr[57].el_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_ELEVATION_059 = af_target_report_ptr[58].el_conf;
   data_ptr.FLR_DETECTION_057_060.DET_CONFD_ELEVATION_060 = af_target_report_ptr[59].el_conf;

   data_ptr.FLR_DETECTION_057_060.DET_EXISTENCE_PROB_057 = TOI_DS_Stream_Ptr->existence_prob[56];
   data_ptr.FLR_DETECTION_057_060.DET_EXISTENCE_PROB_058 = TOI_DS_Stream_Ptr->existence_prob[57];
   data_ptr.FLR_DETECTION_057_060.DET_EXISTENCE_PROB_059 = TOI_DS_Stream_Ptr->existence_prob[58];
   data_ptr.FLR_DETECTION_057_060.DET_EXISTENCE_PROB_060 = TOI_DS_Stream_Ptr->existence_prob[59];

   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_ERR_057 = TOI_DS_Stream_Ptr->std_phi[56];
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_ERR_058 = TOI_DS_Stream_Ptr->std_phi[57];
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_ERR_059 = TOI_DS_Stream_Ptr->std_phi[58];
   data_ptr.FLR_DETECTION_057_060.DET_ELEVATION_ERR_060 = TOI_DS_Stream_Ptr->std_phi[59];

   data_ptr.FLR_DETECTION_057_060.DET_IDM_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_IDM_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_IDM_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_IDM_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_057_060.DET_MTD_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_MTD_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_MTD_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_MTD_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_057_060.DET_PROB_1STAZHYPO_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_PROB_1STAZHYPO_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_PROB_1STAZHYPO_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_PROB_1STAZHYPO_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_057_060.DET_RANGE_ERR_057 = TOI_DS_Stream_Ptr->std_ran[56];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_ERR_058 = TOI_DS_Stream_Ptr->std_ran[57];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_ERR_059 = TOI_DS_Stream_Ptr->std_ran[58];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_ERR_060 = TOI_DS_Stream_Ptr->std_ran[59];

   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_057 = af_target_report_ptr[56].vel;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_058 = af_target_report_ptr[57].vel;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_059 = af_target_report_ptr[58].vel;
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_060 = af_target_report_ptr[59].vel;

   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_057 = TOI_DS_Stream_Ptr->std_vel[56];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_058 = TOI_DS_Stream_Ptr->std_vel[57];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_059 = TOI_DS_Stream_Ptr->std_vel[58];
   data_ptr.FLR_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_060 = TOI_DS_Stream_Ptr->std_vel[59];

   data_ptr.FLR_DETECTION_057_060.DET_RCS_057 = af_target_report_ptr[56].rcs;
   data_ptr.FLR_DETECTION_057_060.DET_RCS_058 = af_target_report_ptr[57].rcs;
   data_ptr.FLR_DETECTION_057_060.DET_RCS_059 = af_target_report_ptr[58].rcs;
   data_ptr.FLR_DETECTION_057_060.DET_RCS_060 = af_target_report_ptr[59].rcs;

   data_ptr.FLR_DETECTION_057_060.DET_SNR_057 = af_target_report_ptr[56].snr;
   data_ptr.FLR_DETECTION_057_060.DET_SNR_058 = af_target_report_ptr[57].snr;
   data_ptr.FLR_DETECTION_057_060.DET_SNR_059 = af_target_report_ptr[58].snr;
   data_ptr.FLR_DETECTION_057_060.DET_SNR_060 = af_target_report_ptr[59].snr;

   data_ptr.FLR_DETECTION_057_060.DET_SUPER_RES_TARGET_057 = af_target_report_ptr[56].f_superres_target;
   data_ptr.FLR_DETECTION_057_060.DET_SUPER_RES_TARGET_058 = af_target_report_ptr[57].f_superres_target;
   data_ptr.FLR_DETECTION_057_060.DET_SUPER_RES_TARGET_059 = af_target_report_ptr[58].f_superres_target;
   data_ptr.FLR_DETECTION_057_060.DET_SUPER_RES_TARGET_060 = af_target_report_ptr[59].f_superres_target;

   data_ptr.FLR_DETECTION_057_060.DET_BELOW_RAIN_THOLD_057 = 0;
   data_ptr.FLR_DETECTION_057_060.DET_BELOW_RAIN_THOLD_058 = 0;
   data_ptr.FLR_DETECTION_057_060.DET_BELOW_RAIN_THOLD_059 = 0;
   data_ptr.FLR_DETECTION_057_060.DET_BELOW_RAIN_THOLD_060 = 0;

   data_ptr.FLR_DETECTION_057_060.DET_HVC_FLAG_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_HVC_FLAG_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_HVC_FLAG_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_057_060.DET_HVC_FLAG_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_057_060.DET_MH_CYCLE_COUNTER_057_060   = 0;
   data_ptr.FLR_DETECTION_057_060.DET_MH_CRC16_057_060           = 0;
   data_ptr.FLR_DETECTION_057_060.DET_MH_SCAN_INDEX_4LSB_057_060 = 0;

   // FLR_DETECTION_061_064_decoded_msg_t

   data_ptr.FLR_DETECTION_061_064.DET_RANGE_061 = af_target_report_ptr[60].ran;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_062 = af_target_report_ptr[61].ran;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_063 = af_target_report_ptr[62].ran;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_064 = af_target_report_ptr[63].ran;

   data_ptr.FLR_DETECTION_061_064.DET_AZIMUTH_061 = af_target_report_ptr[60].theta;
   data_ptr.FLR_DETECTION_061_064.DET_AZIMUTH_062 = af_target_report_ptr[61].theta;
   data_ptr.FLR_DETECTION_061_064.DET_AZIMUTH_063 = af_target_report_ptr[62].theta;
   data_ptr.FLR_DETECTION_061_064.DET_AZIMUTH_064 = af_target_report_ptr[63].theta;

   data_ptr.FLR_DETECTION_061_064.DET_BI_STATIC_FLAG_061 = af_target_report_ptr[60].f_bistatic;
   data_ptr.FLR_DETECTION_061_064.DET_BI_STATIC_FLAG_062 = af_target_report_ptr[61].f_bistatic;
   data_ptr.FLR_DETECTION_061_064.DET_BI_STATIC_FLAG_063 = af_target_report_ptr[62].f_bistatic;
   data_ptr.FLR_DETECTION_061_064.DET_BI_STATIC_FLAG_064 = af_target_report_ptr[63].f_bistatic;

   data_ptr.FLR_DETECTION_061_064.DET_CONFD_AZIMUTH_061 = af_target_report_ptr[60].az_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_AZIMUTH_062 = af_target_report_ptr[61].az_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_AZIMUTH_063 = af_target_report_ptr[62].az_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_AZIMUTH_064 = af_target_report_ptr[63].az_conf;

   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_061 = af_target_report_ptr[60].phi;
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_062 = af_target_report_ptr[61].phi;
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_063 = af_target_report_ptr[62].phi;
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_064 = af_target_report_ptr[63].phi;

   data_ptr.FLR_DETECTION_061_064.DET_CONFD_ELEVATION_061 = af_target_report_ptr[60].el_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_ELEVATION_062 = af_target_report_ptr[61].el_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_ELEVATION_063 = af_target_report_ptr[62].el_conf;
   data_ptr.FLR_DETECTION_061_064.DET_CONFD_ELEVATION_064 = af_target_report_ptr[63].el_conf;

   data_ptr.FLR_DETECTION_061_064.DET_EXISTENCE_PROB_061 = TOI_DS_Stream_Ptr->existence_prob[60];
   data_ptr.FLR_DETECTION_061_064.DET_EXISTENCE_PROB_062 = TOI_DS_Stream_Ptr->existence_prob[61];
   data_ptr.FLR_DETECTION_061_064.DET_EXISTENCE_PROB_063 = TOI_DS_Stream_Ptr->existence_prob[62];
   data_ptr.FLR_DETECTION_061_064.DET_EXISTENCE_PROB_064 = TOI_DS_Stream_Ptr->existence_prob[63];

   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_ERR_061 = TOI_DS_Stream_Ptr->std_phi[60];
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_ERR_062 = TOI_DS_Stream_Ptr->std_phi[61];
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_ERR_063 = TOI_DS_Stream_Ptr->std_phi[62];
   data_ptr.FLR_DETECTION_061_064.DET_ELEVATION_ERR_064 = TOI_DS_Stream_Ptr->std_phi[63];

   data_ptr.FLR_DETECTION_061_064.DET_IDM_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_IDM_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_IDM_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_IDM_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_061_064.DET_MTD_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_MTD_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_MTD_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_MTD_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_061_064.DET_PROB_1STAZHYPO_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_PROB_1STAZHYPO_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_PROB_1STAZHYPO_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_PROB_1STAZHYPO_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_061_064.DET_RANGE_ERR_061 = TOI_DS_Stream_Ptr->std_ran[60];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_ERR_062 = TOI_DS_Stream_Ptr->std_ran[61];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_ERR_063 = TOI_DS_Stream_Ptr->std_ran[62];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_ERR_064 = TOI_DS_Stream_Ptr->std_ran[63];

   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_061 = af_target_report_ptr[60].vel;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_062 = af_target_report_ptr[61].vel;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_063 = af_target_report_ptr[62].vel;
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_064 = af_target_report_ptr[63].vel;

   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_061 = TOI_DS_Stream_Ptr->std_vel[60];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_062 = TOI_DS_Stream_Ptr->std_vel[61];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_063 = TOI_DS_Stream_Ptr->std_vel[62];
   data_ptr.FLR_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_064 = TOI_DS_Stream_Ptr->std_vel[63];

   data_ptr.FLR_DETECTION_061_064.DET_RCS_061 = af_target_report_ptr[60].rcs;
   data_ptr.FLR_DETECTION_061_064.DET_RCS_062 = af_target_report_ptr[61].rcs;
   data_ptr.FLR_DETECTION_061_064.DET_RCS_063 = af_target_report_ptr[62].rcs;
   data_ptr.FLR_DETECTION_061_064.DET_RCS_064 = af_target_report_ptr[63].rcs;

   data_ptr.FLR_DETECTION_061_064.DET_SNR_061 = af_target_report_ptr[60].snr;
   data_ptr.FLR_DETECTION_061_064.DET_SNR_062 = af_target_report_ptr[61].snr;
   data_ptr.FLR_DETECTION_061_064.DET_SNR_063 = af_target_report_ptr[62].snr;
   data_ptr.FLR_DETECTION_061_064.DET_SNR_064 = af_target_report_ptr[63].snr;

   data_ptr.FLR_DETECTION_061_064.DET_SUPER_RES_TARGET_061 = af_target_report_ptr[60].f_superres_target;
   data_ptr.FLR_DETECTION_061_064.DET_SUPER_RES_TARGET_062 = af_target_report_ptr[61].f_superres_target;
   data_ptr.FLR_DETECTION_061_064.DET_SUPER_RES_TARGET_063 = af_target_report_ptr[62].f_superres_target;
   data_ptr.FLR_DETECTION_061_064.DET_SUPER_RES_TARGET_064 = af_target_report_ptr[63].f_superres_target;

   data_ptr.FLR_DETECTION_061_064.DET_BELOW_RAIN_THOLD_061 = 0;
   data_ptr.FLR_DETECTION_061_064.DET_BELOW_RAIN_THOLD_062 = 0;
   data_ptr.FLR_DETECTION_061_064.DET_BELOW_RAIN_THOLD_063 = 0;
   data_ptr.FLR_DETECTION_061_064.DET_BELOW_RAIN_THOLD_064 = 0;

   data_ptr.FLR_DETECTION_061_064.DET_HVC_FLAG_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_HVC_FLAG_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_HVC_FLAG_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_061_064.DET_HVC_FLAG_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_061_064.DET_MH_CYCLE_COUNTER_061_064   = 0;
   data_ptr.FLR_DETECTION_061_064.DET_MH_CRC16_061_064           = 0;
   data_ptr.FLR_DETECTION_061_064.DET_MH_SCAN_INDEX_4LSB_061_064 = 0;

   // FLR_DETECTION_065_068_decoded_msg_t

   data_ptr.FLR_DETECTION_065_068.DET_RANGE_065 = af_target_report_ptr[64].ran;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_066 = af_target_report_ptr[65].ran;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_067 = af_target_report_ptr[66].ran;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_068 = af_target_report_ptr[67].ran;

   data_ptr.FLR_DETECTION_065_068.DET_AZIMUTH_065 = af_target_report_ptr[64].theta;
   data_ptr.FLR_DETECTION_065_068.DET_AZIMUTH_066 = af_target_report_ptr[65].theta;
   data_ptr.FLR_DETECTION_065_068.DET_AZIMUTH_067 = af_target_report_ptr[66].theta;
   data_ptr.FLR_DETECTION_065_068.DET_AZIMUTH_068 = af_target_report_ptr[67].theta;

   data_ptr.FLR_DETECTION_065_068.DET_BI_STATIC_FLAG_065 = af_target_report_ptr[64].f_bistatic;
   data_ptr.FLR_DETECTION_065_068.DET_BI_STATIC_FLAG_066 = af_target_report_ptr[65].f_bistatic;
   data_ptr.FLR_DETECTION_065_068.DET_BI_STATIC_FLAG_067 = af_target_report_ptr[66].f_bistatic;
   data_ptr.FLR_DETECTION_065_068.DET_BI_STATIC_FLAG_068 = af_target_report_ptr[67].f_bistatic;

   data_ptr.FLR_DETECTION_065_068.DET_CONFD_AZIMUTH_065 = af_target_report_ptr[64].az_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_AZIMUTH_066 = af_target_report_ptr[65].az_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_AZIMUTH_067 = af_target_report_ptr[66].az_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_AZIMUTH_068 = af_target_report_ptr[67].az_conf;

   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_065 = af_target_report_ptr[64].phi;
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_066 = af_target_report_ptr[65].phi;
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_067 = af_target_report_ptr[66].phi;
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_068 = af_target_report_ptr[67].phi;

   data_ptr.FLR_DETECTION_065_068.DET_CONFD_ELEVATION_065 = af_target_report_ptr[64].el_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_ELEVATION_066 = af_target_report_ptr[65].el_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_ELEVATION_067 = af_target_report_ptr[66].el_conf;
   data_ptr.FLR_DETECTION_065_068.DET_CONFD_ELEVATION_068 = af_target_report_ptr[67].el_conf;

   data_ptr.FLR_DETECTION_065_068.DET_EXISTENCE_PROB_065 = TOI_DS_Stream_Ptr->existence_prob[64];
   data_ptr.FLR_DETECTION_065_068.DET_EXISTENCE_PROB_066 = TOI_DS_Stream_Ptr->existence_prob[65];
   data_ptr.FLR_DETECTION_065_068.DET_EXISTENCE_PROB_067 = TOI_DS_Stream_Ptr->existence_prob[66];
   data_ptr.FLR_DETECTION_065_068.DET_EXISTENCE_PROB_068 = TOI_DS_Stream_Ptr->existence_prob[67];

   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_ERR_065 = TOI_DS_Stream_Ptr->std_phi[64];
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_ERR_066 = TOI_DS_Stream_Ptr->std_phi[65];
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_ERR_067 = TOI_DS_Stream_Ptr->std_phi[66];
   data_ptr.FLR_DETECTION_065_068.DET_ELEVATION_ERR_068 = TOI_DS_Stream_Ptr->std_phi[67];

   data_ptr.FLR_DETECTION_065_068.DET_IDM_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_IDM_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_IDM_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_IDM_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_065_068.DET_MTD_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_MTD_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_MTD_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_MTD_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_065_068.DET_PROB_1STAZHYPO_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_PROB_1STAZHYPO_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_PROB_1STAZHYPO_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_PROB_1STAZHYPO_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_065_068.DET_RANGE_ERR_065 = TOI_DS_Stream_Ptr->std_ran[64];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_ERR_066 = TOI_DS_Stream_Ptr->std_ran[65];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_ERR_067 = TOI_DS_Stream_Ptr->std_ran[66];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_ERR_068 = TOI_DS_Stream_Ptr->std_ran[67];

   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_065 = af_target_report_ptr[64].vel;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_066 = af_target_report_ptr[65].vel;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_067 = af_target_report_ptr[66].vel;
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_068 = af_target_report_ptr[67].vel;

   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_065 = TOI_DS_Stream_Ptr->std_vel[64];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_066 = TOI_DS_Stream_Ptr->std_vel[65];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_067 = TOI_DS_Stream_Ptr->std_vel[66];
   data_ptr.FLR_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_068 = TOI_DS_Stream_Ptr->std_vel[67];

   data_ptr.FLR_DETECTION_065_068.DET_RCS_065 = af_target_report_ptr[64].rcs;
   data_ptr.FLR_DETECTION_065_068.DET_RCS_066 = af_target_report_ptr[65].rcs;
   data_ptr.FLR_DETECTION_065_068.DET_RCS_067 = af_target_report_ptr[66].rcs;
   data_ptr.FLR_DETECTION_065_068.DET_RCS_068 = af_target_report_ptr[67].rcs;

   data_ptr.FLR_DETECTION_065_068.DET_SNR_065 = af_target_report_ptr[64].snr;
   data_ptr.FLR_DETECTION_065_068.DET_SNR_066 = af_target_report_ptr[65].snr;
   data_ptr.FLR_DETECTION_065_068.DET_SNR_067 = af_target_report_ptr[66].snr;
   data_ptr.FLR_DETECTION_065_068.DET_SNR_068 = af_target_report_ptr[67].snr;

   data_ptr.FLR_DETECTION_065_068.DET_SUPER_RES_TARGET_065 = af_target_report_ptr[64].f_superres_target;
   data_ptr.FLR_DETECTION_065_068.DET_SUPER_RES_TARGET_066 = af_target_report_ptr[65].f_superres_target;
   data_ptr.FLR_DETECTION_065_068.DET_SUPER_RES_TARGET_067 = af_target_report_ptr[66].f_superres_target;
   data_ptr.FLR_DETECTION_065_068.DET_SUPER_RES_TARGET_068 = af_target_report_ptr[67].f_superres_target;

   data_ptr.FLR_DETECTION_065_068.DET_BELOW_RAIN_THOLD_065 = 0;
   data_ptr.FLR_DETECTION_065_068.DET_BELOW_RAIN_THOLD_066 = 0;
   data_ptr.FLR_DETECTION_065_068.DET_BELOW_RAIN_THOLD_067 = 0;
   data_ptr.FLR_DETECTION_065_068.DET_BELOW_RAIN_THOLD_068 = 0;

   data_ptr.FLR_DETECTION_065_068.DET_HVC_FLAG_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_HVC_FLAG_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_HVC_FLAG_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_065_068.DET_HVC_FLAG_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_065_068.DET_MH_CYCLE_COUNTER_065_068   = 0;
   data_ptr.FLR_DETECTION_065_068.DET_MH_CRC16_065_068           = 0;
   data_ptr.FLR_DETECTION_065_068.DET_MH_SCAN_INDEX_4LSB_065_068 = 0;

   // FLR_DETECTION_069_072_decoded_msg_t

   data_ptr.FLR_DETECTION_069_072.DET_RANGE_069 = af_target_report_ptr[68].ran;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_070 = af_target_report_ptr[69].ran;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_071 = af_target_report_ptr[70].ran;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_072 = af_target_report_ptr[71].ran;

   data_ptr.FLR_DETECTION_069_072.DET_AZIMUTH_069 = af_target_report_ptr[68].theta;
   data_ptr.FLR_DETECTION_069_072.DET_AZIMUTH_070 = af_target_report_ptr[69].theta;
   data_ptr.FLR_DETECTION_069_072.DET_AZIMUTH_071 = af_target_report_ptr[70].theta;
   data_ptr.FLR_DETECTION_069_072.DET_AZIMUTH_072 = af_target_report_ptr[71].theta;

   data_ptr.FLR_DETECTION_069_072.DET_BI_STATIC_FLAG_069 = af_target_report_ptr[68].f_bistatic;
   data_ptr.FLR_DETECTION_069_072.DET_BI_STATIC_FLAG_070 = af_target_report_ptr[69].f_bistatic;
   data_ptr.FLR_DETECTION_069_072.DET_BI_STATIC_FLAG_071 = af_target_report_ptr[70].f_bistatic;
   data_ptr.FLR_DETECTION_069_072.DET_BI_STATIC_FLAG_072 = af_target_report_ptr[71].f_bistatic;

   data_ptr.FLR_DETECTION_069_072.DET_CONFD_AZIMUTH_069 = af_target_report_ptr[68].az_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_AZIMUTH_070 = af_target_report_ptr[69].az_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_AZIMUTH_071 = af_target_report_ptr[70].az_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_AZIMUTH_072 = af_target_report_ptr[71].az_conf;

   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_069 = af_target_report_ptr[68].phi;
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_070 = af_target_report_ptr[69].phi;
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_071 = af_target_report_ptr[70].phi;
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_072 = af_target_report_ptr[71].phi;

   data_ptr.FLR_DETECTION_069_072.DET_CONFD_ELEVATION_069 = af_target_report_ptr[68].el_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_ELEVATION_070 = af_target_report_ptr[69].el_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_ELEVATION_071 = af_target_report_ptr[70].el_conf;
   data_ptr.FLR_DETECTION_069_072.DET_CONFD_ELEVATION_072 = af_target_report_ptr[71].el_conf;

   data_ptr.FLR_DETECTION_069_072.DET_EXISTENCE_PROB_069 = TOI_DS_Stream_Ptr->existence_prob[68];
   data_ptr.FLR_DETECTION_069_072.DET_EXISTENCE_PROB_070 = TOI_DS_Stream_Ptr->existence_prob[69];
   data_ptr.FLR_DETECTION_069_072.DET_EXISTENCE_PROB_071 = TOI_DS_Stream_Ptr->existence_prob[70];
   data_ptr.FLR_DETECTION_069_072.DET_EXISTENCE_PROB_072 = TOI_DS_Stream_Ptr->existence_prob[71];

   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_ERR_069 = TOI_DS_Stream_Ptr->std_phi[68];
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_ERR_070 = TOI_DS_Stream_Ptr->std_phi[69];
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_ERR_071 = TOI_DS_Stream_Ptr->std_phi[70];
   data_ptr.FLR_DETECTION_069_072.DET_ELEVATION_ERR_072 = TOI_DS_Stream_Ptr->std_phi[71];

   data_ptr.FLR_DETECTION_069_072.DET_IDM_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_IDM_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_IDM_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_IDM_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_069_072.DET_MTD_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_MTD_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_MTD_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_MTD_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_069_072.DET_PROB_1STAZHYPO_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_PROB_1STAZHYPO_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_PROB_1STAZHYPO_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_PROB_1STAZHYPO_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_069_072.DET_RANGE_ERR_069 = TOI_DS_Stream_Ptr->std_ran[68];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_ERR_070 = TOI_DS_Stream_Ptr->std_ran[69];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_ERR_071 = TOI_DS_Stream_Ptr->std_ran[70];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_ERR_072 = TOI_DS_Stream_Ptr->std_ran[71];

   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_069 = af_target_report_ptr[68].vel;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_070 = af_target_report_ptr[69].vel;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_071 = af_target_report_ptr[70].vel;
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_072 = af_target_report_ptr[71].vel;

   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_069 = TOI_DS_Stream_Ptr->std_vel[68];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_070 = TOI_DS_Stream_Ptr->std_vel[69];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_071 = TOI_DS_Stream_Ptr->std_vel[70];
   data_ptr.FLR_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_072 = TOI_DS_Stream_Ptr->std_vel[71];

   data_ptr.FLR_DETECTION_069_072.DET_RCS_069 = af_target_report_ptr[68].rcs;
   data_ptr.FLR_DETECTION_069_072.DET_RCS_070 = af_target_report_ptr[69].rcs;
   data_ptr.FLR_DETECTION_069_072.DET_RCS_071 = af_target_report_ptr[70].rcs;
   data_ptr.FLR_DETECTION_069_072.DET_RCS_072 = af_target_report_ptr[71].rcs;

   data_ptr.FLR_DETECTION_069_072.DET_SNR_069 = af_target_report_ptr[68].snr;
   data_ptr.FLR_DETECTION_069_072.DET_SNR_070 = af_target_report_ptr[69].snr;
   data_ptr.FLR_DETECTION_069_072.DET_SNR_071 = af_target_report_ptr[70].snr;
   data_ptr.FLR_DETECTION_069_072.DET_SNR_072 = af_target_report_ptr[71].snr;

   data_ptr.FLR_DETECTION_069_072.DET_SUPER_RES_TARGET_069 = af_target_report_ptr[68].f_superres_target;
   data_ptr.FLR_DETECTION_069_072.DET_SUPER_RES_TARGET_070 = af_target_report_ptr[69].f_superres_target;
   data_ptr.FLR_DETECTION_069_072.DET_SUPER_RES_TARGET_071 = af_target_report_ptr[70].f_superres_target;
   data_ptr.FLR_DETECTION_069_072.DET_SUPER_RES_TARGET_072 = af_target_report_ptr[71].f_superres_target;

   data_ptr.FLR_DETECTION_069_072.DET_BELOW_RAIN_THOLD_069 = 0;
   data_ptr.FLR_DETECTION_069_072.DET_BELOW_RAIN_THOLD_070 = 0;
   data_ptr.FLR_DETECTION_069_072.DET_BELOW_RAIN_THOLD_071 = 0;
   data_ptr.FLR_DETECTION_069_072.DET_BELOW_RAIN_THOLD_072 = 0;

   data_ptr.FLR_DETECTION_069_072.DET_HVC_FLAG_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_HVC_FLAG_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_HVC_FLAG_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_069_072.DET_HVC_FLAG_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_069_072.DET_MH_CYCLE_COUNTER_069_072   = 0;
   data_ptr.FLR_DETECTION_069_072.DET_MH_CRC16_069_072           = 0;
   data_ptr.FLR_DETECTION_069_072.DET_MH_SCAN_INDEX_4LSB_069_072 = 0;

   // FLR_DETECTION_073_076_decoded_msg_t

   data_ptr.FLR_DETECTION_073_076.DET_RANGE_073 = af_target_report_ptr[72].ran;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_074 = af_target_report_ptr[73].ran;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_075 = af_target_report_ptr[74].ran;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_076 = af_target_report_ptr[75].ran;

   data_ptr.FLR_DETECTION_073_076.DET_AZIMUTH_073 = af_target_report_ptr[72].theta;
   data_ptr.FLR_DETECTION_073_076.DET_AZIMUTH_074 = af_target_report_ptr[73].theta;
   data_ptr.FLR_DETECTION_073_076.DET_AZIMUTH_075 = af_target_report_ptr[74].theta;
   data_ptr.FLR_DETECTION_073_076.DET_AZIMUTH_076 = af_target_report_ptr[75].theta;

   data_ptr.FLR_DETECTION_073_076.DET_BI_STATIC_FLAG_073 = af_target_report_ptr[72].f_bistatic;
   data_ptr.FLR_DETECTION_073_076.DET_BI_STATIC_FLAG_074 = af_target_report_ptr[73].f_bistatic;
   data_ptr.FLR_DETECTION_073_076.DET_BI_STATIC_FLAG_075 = af_target_report_ptr[74].f_bistatic;
   data_ptr.FLR_DETECTION_073_076.DET_BI_STATIC_FLAG_076 = af_target_report_ptr[75].f_bistatic;

   data_ptr.FLR_DETECTION_073_076.DET_CONFD_AZIMUTH_073 = af_target_report_ptr[72].az_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_AZIMUTH_074 = af_target_report_ptr[73].az_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_AZIMUTH_075 = af_target_report_ptr[74].az_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_AZIMUTH_076 = af_target_report_ptr[75].az_conf;

   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_073 = af_target_report_ptr[72].phi;
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_074 = af_target_report_ptr[73].phi;
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_075 = af_target_report_ptr[74].phi;
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_076 = af_target_report_ptr[75].phi;

   data_ptr.FLR_DETECTION_073_076.DET_CONFD_ELEVATION_073 = af_target_report_ptr[72].el_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_ELEVATION_074 = af_target_report_ptr[73].el_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_ELEVATION_075 = af_target_report_ptr[74].el_conf;
   data_ptr.FLR_DETECTION_073_076.DET_CONFD_ELEVATION_076 = af_target_report_ptr[75].el_conf;

   data_ptr.FLR_DETECTION_073_076.DET_EXISTENCE_PROB_073 = TOI_DS_Stream_Ptr->existence_prob[72];
   data_ptr.FLR_DETECTION_073_076.DET_EXISTENCE_PROB_074 = TOI_DS_Stream_Ptr->existence_prob[73];
   data_ptr.FLR_DETECTION_073_076.DET_EXISTENCE_PROB_075 = TOI_DS_Stream_Ptr->existence_prob[74];
   data_ptr.FLR_DETECTION_073_076.DET_EXISTENCE_PROB_076 = TOI_DS_Stream_Ptr->existence_prob[75];

   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_ERR_073 = TOI_DS_Stream_Ptr->std_phi[72];
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_ERR_074 = TOI_DS_Stream_Ptr->std_phi[73];
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_ERR_075 = TOI_DS_Stream_Ptr->std_phi[74];
   data_ptr.FLR_DETECTION_073_076.DET_ELEVATION_ERR_076 = TOI_DS_Stream_Ptr->std_phi[75];

   data_ptr.FLR_DETECTION_073_076.DET_IDM_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_IDM_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_IDM_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_IDM_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_073_076.DET_MTD_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_MTD_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_MTD_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_MTD_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_073_076.DET_PROB_1STAZHYPO_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_PROB_1STAZHYPO_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_PROB_1STAZHYPO_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_PROB_1STAZHYPO_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_073_076.DET_RANGE_ERR_073 = TOI_DS_Stream_Ptr->std_ran[72];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_ERR_074 = TOI_DS_Stream_Ptr->std_ran[73];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_ERR_075 = TOI_DS_Stream_Ptr->std_ran[74];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_ERR_076 = TOI_DS_Stream_Ptr->std_ran[75];

   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_073 = af_target_report_ptr[72].vel;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_074 = af_target_report_ptr[73].vel;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_075 = af_target_report_ptr[74].vel;
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_076 = af_target_report_ptr[75].vel;

   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_073 = TOI_DS_Stream_Ptr->std_vel[72];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_074 = TOI_DS_Stream_Ptr->std_vel[73];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_075 = TOI_DS_Stream_Ptr->std_vel[74];
   data_ptr.FLR_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_076 = TOI_DS_Stream_Ptr->std_vel[75];

   data_ptr.FLR_DETECTION_073_076.DET_RCS_073 = af_target_report_ptr[72].rcs;
   data_ptr.FLR_DETECTION_073_076.DET_RCS_074 = af_target_report_ptr[73].rcs;
   data_ptr.FLR_DETECTION_073_076.DET_RCS_075 = af_target_report_ptr[74].rcs;
   data_ptr.FLR_DETECTION_073_076.DET_RCS_076 = af_target_report_ptr[75].rcs;

   data_ptr.FLR_DETECTION_073_076.DET_SNR_073 = af_target_report_ptr[72].snr;
   data_ptr.FLR_DETECTION_073_076.DET_SNR_074 = af_target_report_ptr[73].snr;
   data_ptr.FLR_DETECTION_073_076.DET_SNR_075 = af_target_report_ptr[74].snr;
   data_ptr.FLR_DETECTION_073_076.DET_SNR_076 = af_target_report_ptr[75].snr;

   data_ptr.FLR_DETECTION_073_076.DET_SUPER_RES_TARGET_073 = af_target_report_ptr[72].f_superres_target;
   data_ptr.FLR_DETECTION_073_076.DET_SUPER_RES_TARGET_074 = af_target_report_ptr[73].f_superres_target;
   data_ptr.FLR_DETECTION_073_076.DET_SUPER_RES_TARGET_075 = af_target_report_ptr[74].f_superres_target;
   data_ptr.FLR_DETECTION_073_076.DET_SUPER_RES_TARGET_076 = af_target_report_ptr[75].f_superres_target;

   data_ptr.FLR_DETECTION_073_076.DET_BELOW_RAIN_THOLD_073 = 0;
   data_ptr.FLR_DETECTION_073_076.DET_BELOW_RAIN_THOLD_074 = 0;
   data_ptr.FLR_DETECTION_073_076.DET_BELOW_RAIN_THOLD_075 = 0;
   data_ptr.FLR_DETECTION_073_076.DET_BELOW_RAIN_THOLD_076 = 0;

   data_ptr.FLR_DETECTION_073_076.DET_HVC_FLAG_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_HVC_FLAG_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_HVC_FLAG_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_073_076.DET_HVC_FLAG_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_073_076.DET_MH_CYCLE_COUNTER_073_076   = 0;
   data_ptr.FLR_DETECTION_073_076.DET_MH_CRC16_073_076           = 0;
   data_ptr.FLR_DETECTION_073_076.DET_MH_SCAN_INDEX_4LSB_073_076 = 0;

   // FLR_DETECTION_077_080_decoded_msg_t

   data_ptr.FLR_DETECTION_077_080.DET_RANGE_077 = af_target_report_ptr[76].ran;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_078 = af_target_report_ptr[77].ran;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_079 = af_target_report_ptr[78].ran;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_080 = af_target_report_ptr[79].ran;

   data_ptr.FLR_DETECTION_077_080.DET_AZIMUTH_077 = af_target_report_ptr[76].theta;
   data_ptr.FLR_DETECTION_077_080.DET_AZIMUTH_078 = af_target_report_ptr[77].theta;
   data_ptr.FLR_DETECTION_077_080.DET_AZIMUTH_079 = af_target_report_ptr[78].theta;
   data_ptr.FLR_DETECTION_077_080.DET_AZIMUTH_080 = af_target_report_ptr[79].theta;

   data_ptr.FLR_DETECTION_077_080.DET_BI_STATIC_FLAG_077 = af_target_report_ptr[76].f_bistatic;
   data_ptr.FLR_DETECTION_077_080.DET_BI_STATIC_FLAG_078 = af_target_report_ptr[77].f_bistatic;
   data_ptr.FLR_DETECTION_077_080.DET_BI_STATIC_FLAG_079 = af_target_report_ptr[78].f_bistatic;
   data_ptr.FLR_DETECTION_077_080.DET_BI_STATIC_FLAG_080 = af_target_report_ptr[79].f_bistatic;

   data_ptr.FLR_DETECTION_077_080.DET_CONFD_AZIMUTH_077 = af_target_report_ptr[76].az_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_AZIMUTH_078 = af_target_report_ptr[77].az_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_AZIMUTH_079 = af_target_report_ptr[78].az_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_AZIMUTH_080 = af_target_report_ptr[79].az_conf;

   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_077 = af_target_report_ptr[76].phi;
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_078 = af_target_report_ptr[77].phi;
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_079 = af_target_report_ptr[78].phi;
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_080 = af_target_report_ptr[79].phi;

   data_ptr.FLR_DETECTION_077_080.DET_CONFD_ELEVATION_077 = af_target_report_ptr[76].el_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_ELEVATION_078 = af_target_report_ptr[77].el_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_ELEVATION_079 = af_target_report_ptr[78].el_conf;
   data_ptr.FLR_DETECTION_077_080.DET_CONFD_ELEVATION_080 = af_target_report_ptr[79].el_conf;

   data_ptr.FLR_DETECTION_077_080.DET_EXISTENCE_PROB_077 = TOI_DS_Stream_Ptr->existence_prob[76];
   data_ptr.FLR_DETECTION_077_080.DET_EXISTENCE_PROB_078 = TOI_DS_Stream_Ptr->existence_prob[77];
   data_ptr.FLR_DETECTION_077_080.DET_EXISTENCE_PROB_079 = TOI_DS_Stream_Ptr->existence_prob[78];
   data_ptr.FLR_DETECTION_077_080.DET_EXISTENCE_PROB_080 = TOI_DS_Stream_Ptr->existence_prob[79];

   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_ERR_077 = TOI_DS_Stream_Ptr->std_phi[76];
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_ERR_078 = TOI_DS_Stream_Ptr->std_phi[77];
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_ERR_079 = TOI_DS_Stream_Ptr->std_phi[78];
   data_ptr.FLR_DETECTION_077_080.DET_ELEVATION_ERR_080 = TOI_DS_Stream_Ptr->std_phi[79];

   data_ptr.FLR_DETECTION_077_080.DET_IDM_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_IDM_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_IDM_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_IDM_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_077_080.DET_MTD_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_MTD_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_MTD_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_MTD_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_077_080.DET_PROB_1STAZHYPO_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_PROB_1STAZHYPO_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_PROB_1STAZHYPO_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_PROB_1STAZHYPO_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_077_080.DET_RANGE_ERR_077 = TOI_DS_Stream_Ptr->std_ran[76];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_ERR_078 = TOI_DS_Stream_Ptr->std_ran[77];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_ERR_079 = TOI_DS_Stream_Ptr->std_ran[78];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_ERR_080 = TOI_DS_Stream_Ptr->std_ran[79];

   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_077 = af_target_report_ptr[76].vel;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_078 = af_target_report_ptr[77].vel;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_079 = af_target_report_ptr[78].vel;
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_080 = af_target_report_ptr[79].vel;

   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_077 = TOI_DS_Stream_Ptr->std_vel[76];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_078 = TOI_DS_Stream_Ptr->std_vel[77];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_079 = TOI_DS_Stream_Ptr->std_vel[78];
   data_ptr.FLR_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_080 = TOI_DS_Stream_Ptr->std_vel[79];

   data_ptr.FLR_DETECTION_077_080.DET_RCS_077 = af_target_report_ptr[76].rcs;
   data_ptr.FLR_DETECTION_077_080.DET_RCS_078 = af_target_report_ptr[77].rcs;
   data_ptr.FLR_DETECTION_077_080.DET_RCS_079 = af_target_report_ptr[78].rcs;
   data_ptr.FLR_DETECTION_077_080.DET_RCS_080 = af_target_report_ptr[79].rcs;

   data_ptr.FLR_DETECTION_077_080.DET_SNR_077 = af_target_report_ptr[76].snr;
   data_ptr.FLR_DETECTION_077_080.DET_SNR_078 = af_target_report_ptr[77].snr;
   data_ptr.FLR_DETECTION_077_080.DET_SNR_079 = af_target_report_ptr[78].snr;
   data_ptr.FLR_DETECTION_077_080.DET_SNR_080 = af_target_report_ptr[79].snr;

   data_ptr.FLR_DETECTION_077_080.DET_SUPER_RES_TARGET_077 = af_target_report_ptr[76].f_superres_target;
   data_ptr.FLR_DETECTION_077_080.DET_SUPER_RES_TARGET_078 = af_target_report_ptr[77].f_superres_target;
   data_ptr.FLR_DETECTION_077_080.DET_SUPER_RES_TARGET_079 = af_target_report_ptr[78].f_superres_target;
   data_ptr.FLR_DETECTION_077_080.DET_SUPER_RES_TARGET_080 = af_target_report_ptr[79].f_superres_target;

   data_ptr.FLR_DETECTION_077_080.DET_BELOW_RAIN_THOLD_077 = 0;
   data_ptr.FLR_DETECTION_077_080.DET_BELOW_RAIN_THOLD_078 = 0;
   data_ptr.FLR_DETECTION_077_080.DET_BELOW_RAIN_THOLD_079 = 0;
   data_ptr.FLR_DETECTION_077_080.DET_BELOW_RAIN_THOLD_080 = 0;

   data_ptr.FLR_DETECTION_077_080.DET_HVC_FLAG_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_HVC_FLAG_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_HVC_FLAG_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_077_080.DET_HVC_FLAG_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_077_080.DET_MH_CYCLE_COUNTER_077_080   = 0;
   data_ptr.FLR_DETECTION_077_080.DET_MH_CRC16_077_080           = 0;
   data_ptr.FLR_DETECTION_077_080.DET_MH_SCAN_INDEX_4LSB_077_080 = 0;

   // FLR_DETECTION_081_084_decoded_msg_t

   data_ptr.FLR_DETECTION_081_084.DET_RANGE_081 = af_target_report_ptr[80].ran;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_082 = af_target_report_ptr[81].ran;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_083 = af_target_report_ptr[82].ran;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_084 = af_target_report_ptr[83].ran;

   data_ptr.FLR_DETECTION_081_084.DET_AZIMUTH_081 = af_target_report_ptr[80].theta;
   data_ptr.FLR_DETECTION_081_084.DET_AZIMUTH_082 = af_target_report_ptr[81].theta;
   data_ptr.FLR_DETECTION_081_084.DET_AZIMUTH_083 = af_target_report_ptr[82].theta;
   data_ptr.FLR_DETECTION_081_084.DET_AZIMUTH_084 = af_target_report_ptr[83].theta;

   data_ptr.FLR_DETECTION_081_084.DET_BI_STATIC_FLAG_081 = af_target_report_ptr[80].f_bistatic;
   data_ptr.FLR_DETECTION_081_084.DET_BI_STATIC_FLAG_082 = af_target_report_ptr[81].f_bistatic;
   data_ptr.FLR_DETECTION_081_084.DET_BI_STATIC_FLAG_083 = af_target_report_ptr[82].f_bistatic;
   data_ptr.FLR_DETECTION_081_084.DET_BI_STATIC_FLAG_084 = af_target_report_ptr[83].f_bistatic;

   data_ptr.FLR_DETECTION_081_084.DET_CONFD_AZIMUTH_081 = af_target_report_ptr[80].az_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_AZIMUTH_082 = af_target_report_ptr[81].az_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_AZIMUTH_083 = af_target_report_ptr[82].az_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_AZIMUTH_084 = af_target_report_ptr[83].az_conf;

   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_081 = af_target_report_ptr[80].phi;
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_082 = af_target_report_ptr[81].phi;
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_083 = af_target_report_ptr[82].phi;
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_084 = af_target_report_ptr[83].phi;

   data_ptr.FLR_DETECTION_081_084.DET_CONFD_ELEVATION_081 = af_target_report_ptr[80].el_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_ELEVATION_082 = af_target_report_ptr[81].el_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_ELEVATION_083 = af_target_report_ptr[82].el_conf;
   data_ptr.FLR_DETECTION_081_084.DET_CONFD_ELEVATION_084 = af_target_report_ptr[83].el_conf;

   data_ptr.FLR_DETECTION_081_084.DET_EXISTENCE_PROB_081 = TOI_DS_Stream_Ptr->existence_prob[80];
   data_ptr.FLR_DETECTION_081_084.DET_EXISTENCE_PROB_082 = TOI_DS_Stream_Ptr->existence_prob[81];
   data_ptr.FLR_DETECTION_081_084.DET_EXISTENCE_PROB_083 = TOI_DS_Stream_Ptr->existence_prob[82];
   data_ptr.FLR_DETECTION_081_084.DET_EXISTENCE_PROB_084 = TOI_DS_Stream_Ptr->existence_prob[83];

   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_ERR_081 = TOI_DS_Stream_Ptr->std_phi[80];
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_ERR_082 = TOI_DS_Stream_Ptr->std_phi[81];
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_ERR_083 = TOI_DS_Stream_Ptr->std_phi[82];
   data_ptr.FLR_DETECTION_081_084.DET_ELEVATION_ERR_084 = TOI_DS_Stream_Ptr->std_phi[83];

   data_ptr.FLR_DETECTION_081_084.DET_IDM_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_IDM_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_IDM_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_IDM_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_081_084.DET_MTD_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_MTD_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_MTD_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_MTD_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_081_084.DET_PROB_1STAZHYPO_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_PROB_1STAZHYPO_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_PROB_1STAZHYPO_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_PROB_1STAZHYPO_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_081_084.DET_RANGE_ERR_081 = TOI_DS_Stream_Ptr->std_ran[80];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_ERR_082 = TOI_DS_Stream_Ptr->std_ran[81];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_ERR_083 = TOI_DS_Stream_Ptr->std_ran[82];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_ERR_084 = TOI_DS_Stream_Ptr->std_ran[83];

   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_081 = af_target_report_ptr[80].vel;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_082 = af_target_report_ptr[81].vel;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_083 = af_target_report_ptr[82].vel;
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_084 = af_target_report_ptr[83].vel;

   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_081 = TOI_DS_Stream_Ptr->std_vel[80];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_082 = TOI_DS_Stream_Ptr->std_vel[81];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_083 = TOI_DS_Stream_Ptr->std_vel[82];
   data_ptr.FLR_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_084 = TOI_DS_Stream_Ptr->std_vel[83];

   data_ptr.FLR_DETECTION_081_084.DET_RCS_081 = af_target_report_ptr[80].rcs;
   data_ptr.FLR_DETECTION_081_084.DET_RCS_082 = af_target_report_ptr[81].rcs;
   data_ptr.FLR_DETECTION_081_084.DET_RCS_083 = af_target_report_ptr[82].rcs;
   data_ptr.FLR_DETECTION_081_084.DET_RCS_084 = af_target_report_ptr[83].rcs;

   data_ptr.FLR_DETECTION_081_084.DET_SNR_081 = af_target_report_ptr[80].snr;
   data_ptr.FLR_DETECTION_081_084.DET_SNR_082 = af_target_report_ptr[81].snr;
   data_ptr.FLR_DETECTION_081_084.DET_SNR_083 = af_target_report_ptr[82].snr;
   data_ptr.FLR_DETECTION_081_084.DET_SNR_084 = af_target_report_ptr[83].snr;

   data_ptr.FLR_DETECTION_081_084.DET_SUPER_RES_TARGET_081 = af_target_report_ptr[80].f_superres_target;
   data_ptr.FLR_DETECTION_081_084.DET_SUPER_RES_TARGET_082 = af_target_report_ptr[81].f_superres_target;
   data_ptr.FLR_DETECTION_081_084.DET_SUPER_RES_TARGET_083 = af_target_report_ptr[82].f_superres_target;
   data_ptr.FLR_DETECTION_081_084.DET_SUPER_RES_TARGET_084 = af_target_report_ptr[83].f_superres_target;

   data_ptr.FLR_DETECTION_081_084.DET_BELOW_RAIN_THOLD_081 = 0;
   data_ptr.FLR_DETECTION_081_084.DET_BELOW_RAIN_THOLD_082 = 0;
   data_ptr.FLR_DETECTION_081_084.DET_BELOW_RAIN_THOLD_083 = 0;
   data_ptr.FLR_DETECTION_081_084.DET_BELOW_RAIN_THOLD_084 = 0;

   data_ptr.FLR_DETECTION_081_084.DET_HVC_FLAG_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_HVC_FLAG_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_HVC_FLAG_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_081_084.DET_HVC_FLAG_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_081_084.DET_MH_CYCLE_COUNTER_081_084   = 0;
   data_ptr.FLR_DETECTION_081_084.DET_MH_CRC16_081_084           = 0;
   data_ptr.FLR_DETECTION_081_084.DET_MH_SCAN_INDEX_4LSB_081_084 = 0;

   // FLR_DETECTION_085_088_decoded_msg_t

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.FLR_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.FLR_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.FLR_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.FLR_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.FLR_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // FLR_DETECTION_089_092_decoded_msg_t

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.FLR_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.FLR_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.FLR_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.FLR_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.FLR_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.FLR_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.FLR_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.FLR_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.FLR_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.FLR_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.FLR_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.FLR_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.FLR_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.FLR_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.FLR_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // FLR_DETECTION_093_096_decoded_msg_t

   data_ptr.FLR_DETECTION_093_096.DET_RANGE_093 = af_target_report_ptr[92].ran;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_094 = af_target_report_ptr[93].ran;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_095 = af_target_report_ptr[94].ran;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_096 = af_target_report_ptr[95].ran;

   data_ptr.FLR_DETECTION_093_096.DET_AZIMUTH_093 = af_target_report_ptr[92].theta;
   data_ptr.FLR_DETECTION_093_096.DET_AZIMUTH_094 = af_target_report_ptr[93].theta;
   data_ptr.FLR_DETECTION_093_096.DET_AZIMUTH_095 = af_target_report_ptr[94].theta;
   data_ptr.FLR_DETECTION_093_096.DET_AZIMUTH_096 = af_target_report_ptr[95].theta;

   data_ptr.FLR_DETECTION_093_096.DET_BI_STATIC_FLAG_093 = af_target_report_ptr[92].f_bistatic;
   data_ptr.FLR_DETECTION_093_096.DET_BI_STATIC_FLAG_094 = af_target_report_ptr[93].f_bistatic;
   data_ptr.FLR_DETECTION_093_096.DET_BI_STATIC_FLAG_095 = af_target_report_ptr[94].f_bistatic;
   data_ptr.FLR_DETECTION_093_096.DET_BI_STATIC_FLAG_096 = af_target_report_ptr[95].f_bistatic;

   data_ptr.FLR_DETECTION_093_096.DET_CONFD_AZIMUTH_093 = af_target_report_ptr[92].az_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_AZIMUTH_094 = af_target_report_ptr[93].az_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_AZIMUTH_095 = af_target_report_ptr[94].az_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_AZIMUTH_096 = af_target_report_ptr[95].az_conf;

   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_093 = af_target_report_ptr[92].phi;
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_094 = af_target_report_ptr[93].phi;
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_095 = af_target_report_ptr[94].phi;
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_096 = af_target_report_ptr[95].phi;

   data_ptr.FLR_DETECTION_093_096.DET_CONFD_ELEVATION_093 = af_target_report_ptr[92].el_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_ELEVATION_094 = af_target_report_ptr[93].el_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_ELEVATION_095 = af_target_report_ptr[94].el_conf;
   data_ptr.FLR_DETECTION_093_096.DET_CONFD_ELEVATION_096 = af_target_report_ptr[95].el_conf;

   data_ptr.FLR_DETECTION_093_096.DET_EXISTENCE_PROB_093 = TOI_DS_Stream_Ptr->existence_prob[92];
   data_ptr.FLR_DETECTION_093_096.DET_EXISTENCE_PROB_094 = TOI_DS_Stream_Ptr->existence_prob[93];
   data_ptr.FLR_DETECTION_093_096.DET_EXISTENCE_PROB_095 = TOI_DS_Stream_Ptr->existence_prob[94];
   data_ptr.FLR_DETECTION_093_096.DET_EXISTENCE_PROB_096 = TOI_DS_Stream_Ptr->existence_prob[95];

   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_ERR_093 = TOI_DS_Stream_Ptr->std_phi[92];
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_ERR_094 = TOI_DS_Stream_Ptr->std_phi[93];
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_ERR_095 = TOI_DS_Stream_Ptr->std_phi[94];
   data_ptr.FLR_DETECTION_093_096.DET_ELEVATION_ERR_096 = TOI_DS_Stream_Ptr->std_phi[95];

   data_ptr.FLR_DETECTION_093_096.DET_IDM_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_IDM_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_IDM_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_IDM_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_093_096.DET_MTD_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_MTD_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_MTD_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_MTD_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_093_096.DET_PROB_1STAZHYPO_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_PROB_1STAZHYPO_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_PROB_1STAZHYPO_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_PROB_1STAZHYPO_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_093_096.DET_RANGE_ERR_093 = TOI_DS_Stream_Ptr->std_ran[92];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_ERR_094 = TOI_DS_Stream_Ptr->std_ran[93];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_ERR_095 = TOI_DS_Stream_Ptr->std_ran[94];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_ERR_096 = TOI_DS_Stream_Ptr->std_ran[95];

   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_093 = af_target_report_ptr[92].vel;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_094 = af_target_report_ptr[93].vel;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_095 = af_target_report_ptr[94].vel;
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_096 = af_target_report_ptr[95].vel;

   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_093 = TOI_DS_Stream_Ptr->std_vel[92];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_094 = TOI_DS_Stream_Ptr->std_vel[93];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_095 = TOI_DS_Stream_Ptr->std_vel[94];
   data_ptr.FLR_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_096 = TOI_DS_Stream_Ptr->std_vel[95];

   data_ptr.FLR_DETECTION_093_096.DET_RCS_093 = af_target_report_ptr[92].rcs;
   data_ptr.FLR_DETECTION_093_096.DET_RCS_094 = af_target_report_ptr[93].rcs;
   data_ptr.FLR_DETECTION_093_096.DET_RCS_095 = af_target_report_ptr[94].rcs;
   data_ptr.FLR_DETECTION_093_096.DET_RCS_096 = af_target_report_ptr[95].rcs;

   data_ptr.FLR_DETECTION_093_096.DET_SNR_093 = af_target_report_ptr[92].snr;
   data_ptr.FLR_DETECTION_093_096.DET_SNR_094 = af_target_report_ptr[93].snr;
   data_ptr.FLR_DETECTION_093_096.DET_SNR_095 = af_target_report_ptr[94].snr;
   data_ptr.FLR_DETECTION_093_096.DET_SNR_096 = af_target_report_ptr[95].snr;

   data_ptr.FLR_DETECTION_093_096.DET_SUPER_RES_TARGET_093 = af_target_report_ptr[92].f_superres_target;
   data_ptr.FLR_DETECTION_093_096.DET_SUPER_RES_TARGET_094 = af_target_report_ptr[93].f_superres_target;
   data_ptr.FLR_DETECTION_093_096.DET_SUPER_RES_TARGET_095 = af_target_report_ptr[94].f_superres_target;
   data_ptr.FLR_DETECTION_093_096.DET_SUPER_RES_TARGET_096 = af_target_report_ptr[95].f_superres_target;

   data_ptr.FLR_DETECTION_093_096.DET_BELOW_RAIN_THOLD_093 = 0;
   data_ptr.FLR_DETECTION_093_096.DET_BELOW_RAIN_THOLD_094 = 0;
   data_ptr.FLR_DETECTION_093_096.DET_BELOW_RAIN_THOLD_095 = 0;
   data_ptr.FLR_DETECTION_093_096.DET_BELOW_RAIN_THOLD_096 = 0;

   data_ptr.FLR_DETECTION_093_096.DET_HVC_FLAG_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_HVC_FLAG_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_HVC_FLAG_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_093_096.DET_HVC_FLAG_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_093_096.DET_MH_CYCLE_COUNTER_093_096   = 0;
   data_ptr.FLR_DETECTION_093_096.DET_MH_CRC16_093_096           = 0;
   data_ptr.FLR_DETECTION_093_096.DET_MH_SCAN_INDEX_4LSB_093_096 = 0;

   // FLR_DETECTION_097_100_decoded_msg_t

   data_ptr.FLR_DETECTION_097_100.DET_RANGE_097 = af_target_report_ptr[96].ran;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_098 = af_target_report_ptr[97].ran;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_099 = af_target_report_ptr[98].ran;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_100 = af_target_report_ptr[99].ran;

   data_ptr.FLR_DETECTION_097_100.DET_AZIMUTH_097 = af_target_report_ptr[96].theta;
   data_ptr.FLR_DETECTION_097_100.DET_AZIMUTH_098 = af_target_report_ptr[97].theta;
   data_ptr.FLR_DETECTION_097_100.DET_AZIMUTH_099 = af_target_report_ptr[98].theta;
   data_ptr.FLR_DETECTION_097_100.DET_AZIMUTH_100 = af_target_report_ptr[99].theta;

   data_ptr.FLR_DETECTION_097_100.DET_BI_STATIC_FLAG_097 = af_target_report_ptr[96].f_bistatic;
   data_ptr.FLR_DETECTION_097_100.DET_BI_STATIC_FLAG_098 = af_target_report_ptr[97].f_bistatic;
   data_ptr.FLR_DETECTION_097_100.DET_BI_STATIC_FLAG_099 = af_target_report_ptr[98].f_bistatic;
   data_ptr.FLR_DETECTION_097_100.DET_BI_STATIC_FLAG_100 = af_target_report_ptr[99].f_bistatic;

   data_ptr.FLR_DETECTION_097_100.DET_CONFD_AZIMUTH_097 = af_target_report_ptr[96].az_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_AZIMUTH_098 = af_target_report_ptr[97].az_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_AZIMUTH_099 = af_target_report_ptr[98].az_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_AZIMUTH_100 = af_target_report_ptr[99].az_conf;

   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_097 = af_target_report_ptr[96].phi;
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_098 = af_target_report_ptr[97].phi;
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_099 = af_target_report_ptr[98].phi;
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_100 = af_target_report_ptr[99].phi;

   data_ptr.FLR_DETECTION_097_100.DET_CONFD_ELEVATION_097 = af_target_report_ptr[96].el_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_ELEVATION_098 = af_target_report_ptr[97].el_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_ELEVATION_099 = af_target_report_ptr[98].el_conf;
   data_ptr.FLR_DETECTION_097_100.DET_CONFD_ELEVATION_100 = af_target_report_ptr[99].el_conf;

   data_ptr.FLR_DETECTION_097_100.DET_EXISTENCE_PROB_097 = TOI_DS_Stream_Ptr->existence_prob[96];
   data_ptr.FLR_DETECTION_097_100.DET_EXISTENCE_PROB_098 = TOI_DS_Stream_Ptr->existence_prob[97];
   data_ptr.FLR_DETECTION_097_100.DET_EXISTENCE_PROB_099 = TOI_DS_Stream_Ptr->existence_prob[98];
   data_ptr.FLR_DETECTION_097_100.DET_EXISTENCE_PROB_100 = TOI_DS_Stream_Ptr->existence_prob[99];

   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_ERR_097 = TOI_DS_Stream_Ptr->std_phi[96];
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_ERR_098 = TOI_DS_Stream_Ptr->std_phi[97];
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_ERR_099 = TOI_DS_Stream_Ptr->std_phi[98];
   data_ptr.FLR_DETECTION_097_100.DET_ELEVATION_ERR_100 = TOI_DS_Stream_Ptr->std_phi[99];

   data_ptr.FLR_DETECTION_097_100.DET_IDM_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_IDM_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_IDM_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_IDM_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_097_100.DET_MTD_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_MTD_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_MTD_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_MTD_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_097_100.DET_PROB_1STAZHYPO_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_PROB_1STAZHYPO_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_PROB_1STAZHYPO_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_PROB_1STAZHYPO_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_097_100.DET_RANGE_ERR_097 = TOI_DS_Stream_Ptr->std_ran[96];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_ERR_098 = TOI_DS_Stream_Ptr->std_ran[97];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_ERR_099 = TOI_DS_Stream_Ptr->std_ran[98];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_ERR_100 = TOI_DS_Stream_Ptr->std_ran[99];

   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_097 = af_target_report_ptr[96].vel;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_098 = af_target_report_ptr[97].vel;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_099 = af_target_report_ptr[98].vel;
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_100 = af_target_report_ptr[99].vel;

   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_097 = TOI_DS_Stream_Ptr->std_vel[96];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_098 = TOI_DS_Stream_Ptr->std_vel[97];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_099 = TOI_DS_Stream_Ptr->std_vel[98];
   data_ptr.FLR_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_100 = TOI_DS_Stream_Ptr->std_vel[99];

   data_ptr.FLR_DETECTION_097_100.DET_RCS_097 = af_target_report_ptr[96].rcs;
   data_ptr.FLR_DETECTION_097_100.DET_RCS_098 = af_target_report_ptr[97].rcs;
   data_ptr.FLR_DETECTION_097_100.DET_RCS_099 = af_target_report_ptr[98].rcs;
   data_ptr.FLR_DETECTION_097_100.DET_RCS_100 = af_target_report_ptr[99].rcs;

   data_ptr.FLR_DETECTION_097_100.DET_SNR_097 = af_target_report_ptr[96].snr;
   data_ptr.FLR_DETECTION_097_100.DET_SNR_098 = af_target_report_ptr[97].snr;
   data_ptr.FLR_DETECTION_097_100.DET_SNR_099 = af_target_report_ptr[98].snr;
   data_ptr.FLR_DETECTION_097_100.DET_SNR_100 = af_target_report_ptr[99].snr;

   data_ptr.FLR_DETECTION_097_100.DET_SUPER_RES_TARGET_097 = af_target_report_ptr[96].f_superres_target;
   data_ptr.FLR_DETECTION_097_100.DET_SUPER_RES_TARGET_098 = af_target_report_ptr[97].f_superres_target;
   data_ptr.FLR_DETECTION_097_100.DET_SUPER_RES_TARGET_099 = af_target_report_ptr[98].f_superres_target;
   data_ptr.FLR_DETECTION_097_100.DET_SUPER_RES_TARGET_100 = af_target_report_ptr[99].f_superres_target;

   data_ptr.FLR_DETECTION_097_100.DET_BELOW_RAIN_THOLD_097 = 0;
   data_ptr.FLR_DETECTION_097_100.DET_BELOW_RAIN_THOLD_098 = 0;
   data_ptr.FLR_DETECTION_097_100.DET_BELOW_RAIN_THOLD_099 = 0;
   data_ptr.FLR_DETECTION_097_100.DET_BELOW_RAIN_THOLD_100 = 0;

   data_ptr.FLR_DETECTION_097_100.DET_HVC_FLAG_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_HVC_FLAG_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_HVC_FLAG_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_097_100.DET_HVC_FLAG_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_097_100.DET_MH_CYCLE_COUNTER_097_100   = 0;
   data_ptr.FLR_DETECTION_097_100.DET_MH_CRC16_097_100           = 0;
   data_ptr.FLR_DETECTION_097_100.DET_MH_SCAN_INDEX_4LSB_097_100 = 0;

   // FLR_DETECTION_101_104_decoded_msg_t

   data_ptr.FLR_DETECTION_101_104.DET_RANGE_101 = af_target_report_ptr[100].ran;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_102 = af_target_report_ptr[101].ran;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_103 = af_target_report_ptr[102].ran;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_104 = af_target_report_ptr[103].ran;

   data_ptr.FLR_DETECTION_101_104.DET_AZIMUTH_101 = af_target_report_ptr[100].theta;
   data_ptr.FLR_DETECTION_101_104.DET_AZIMUTH_102 = af_target_report_ptr[101].theta;
   data_ptr.FLR_DETECTION_101_104.DET_AZIMUTH_103 = af_target_report_ptr[102].theta;
   data_ptr.FLR_DETECTION_101_104.DET_AZIMUTH_104 = af_target_report_ptr[103].theta;

   data_ptr.FLR_DETECTION_101_104.DET_BI_STATIC_FLAG_101 = af_target_report_ptr[100].f_bistatic;
   data_ptr.FLR_DETECTION_101_104.DET_BI_STATIC_FLAG_102 = af_target_report_ptr[101].f_bistatic;
   data_ptr.FLR_DETECTION_101_104.DET_BI_STATIC_FLAG_103 = af_target_report_ptr[102].f_bistatic;
   data_ptr.FLR_DETECTION_101_104.DET_BI_STATIC_FLAG_104 = af_target_report_ptr[103].f_bistatic;

   data_ptr.FLR_DETECTION_101_104.DET_CONFD_AZIMUTH_101 = af_target_report_ptr[100].az_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_AZIMUTH_102 = af_target_report_ptr[101].az_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_AZIMUTH_103 = af_target_report_ptr[102].az_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_AZIMUTH_104 = af_target_report_ptr[103].az_conf;

   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_101 = af_target_report_ptr[100].phi;
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_102 = af_target_report_ptr[101].phi;
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_103 = af_target_report_ptr[102].phi;
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_104 = af_target_report_ptr[103].phi;

   data_ptr.FLR_DETECTION_101_104.DET_CONFD_ELEVATION_101 = af_target_report_ptr[100].el_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_ELEVATION_102 = af_target_report_ptr[101].el_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_ELEVATION_103 = af_target_report_ptr[102].el_conf;
   data_ptr.FLR_DETECTION_101_104.DET_CONFD_ELEVATION_104 = af_target_report_ptr[103].el_conf;

   data_ptr.FLR_DETECTION_101_104.DET_EXISTENCE_PROB_101 = TOI_DS_Stream_Ptr->existence_prob[100];
   data_ptr.FLR_DETECTION_101_104.DET_EXISTENCE_PROB_102 = TOI_DS_Stream_Ptr->existence_prob[101];
   data_ptr.FLR_DETECTION_101_104.DET_EXISTENCE_PROB_103 = TOI_DS_Stream_Ptr->existence_prob[102];
   data_ptr.FLR_DETECTION_101_104.DET_EXISTENCE_PROB_104 = TOI_DS_Stream_Ptr->existence_prob[103];

   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_ERR_101 = TOI_DS_Stream_Ptr->std_phi[100];
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_ERR_102 = TOI_DS_Stream_Ptr->std_phi[101];
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_ERR_103 = TOI_DS_Stream_Ptr->std_phi[102];
   data_ptr.FLR_DETECTION_101_104.DET_ELEVATION_ERR_104 = TOI_DS_Stream_Ptr->std_phi[103];

   data_ptr.FLR_DETECTION_101_104.DET_IDM_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_IDM_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_IDM_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_IDM_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_101_104.DET_MTD_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_MTD_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_MTD_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_MTD_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_101_104.DET_PROB_1STAZHYPO_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_PROB_1STAZHYPO_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_PROB_1STAZHYPO_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_PROB_1STAZHYPO_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_101_104.DET_RANGE_ERR_101 = TOI_DS_Stream_Ptr->std_ran[100];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_ERR_102 = TOI_DS_Stream_Ptr->std_ran[101];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_ERR_103 = TOI_DS_Stream_Ptr->std_ran[102];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_ERR_104 = TOI_DS_Stream_Ptr->std_ran[103];

   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_101 = af_target_report_ptr[100].vel;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_102 = af_target_report_ptr[101].vel;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_103 = af_target_report_ptr[102].vel;
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_104 = af_target_report_ptr[103].vel;

   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_101 = TOI_DS_Stream_Ptr->std_vel[100];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_102 = TOI_DS_Stream_Ptr->std_vel[101];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_103 = TOI_DS_Stream_Ptr->std_vel[102];
   data_ptr.FLR_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_104 = TOI_DS_Stream_Ptr->std_vel[103];

   data_ptr.FLR_DETECTION_101_104.DET_RCS_101 = af_target_report_ptr[100].rcs;
   data_ptr.FLR_DETECTION_101_104.DET_RCS_102 = af_target_report_ptr[101].rcs;
   data_ptr.FLR_DETECTION_101_104.DET_RCS_103 = af_target_report_ptr[102].rcs;
   data_ptr.FLR_DETECTION_101_104.DET_RCS_104 = af_target_report_ptr[103].rcs;

   data_ptr.FLR_DETECTION_101_104.DET_SNR_101 = af_target_report_ptr[100].snr;
   data_ptr.FLR_DETECTION_101_104.DET_SNR_102 = af_target_report_ptr[101].snr;
   data_ptr.FLR_DETECTION_101_104.DET_SNR_103 = af_target_report_ptr[102].snr;
   data_ptr.FLR_DETECTION_101_104.DET_SNR_104 = af_target_report_ptr[103].snr;

   data_ptr.FLR_DETECTION_101_104.DET_SUPER_RES_TARGET_101 = af_target_report_ptr[100].f_superres_target;
   data_ptr.FLR_DETECTION_101_104.DET_SUPER_RES_TARGET_102 = af_target_report_ptr[101].f_superres_target;
   data_ptr.FLR_DETECTION_101_104.DET_SUPER_RES_TARGET_103 = af_target_report_ptr[102].f_superres_target;
   data_ptr.FLR_DETECTION_101_104.DET_SUPER_RES_TARGET_104 = af_target_report_ptr[103].f_superres_target;

   data_ptr.FLR_DETECTION_101_104.DET_BELOW_RAIN_THOLD_101 = 0;
   data_ptr.FLR_DETECTION_101_104.DET_BELOW_RAIN_THOLD_102 = 0;
   data_ptr.FLR_DETECTION_101_104.DET_BELOW_RAIN_THOLD_103 = 0;
   data_ptr.FLR_DETECTION_101_104.DET_BELOW_RAIN_THOLD_104 = 0;

   data_ptr.FLR_DETECTION_101_104.DET_HVC_FLAG_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_HVC_FLAG_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_HVC_FLAG_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_101_104.DET_HVC_FLAG_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_101_104.DET_MH_CYCLE_COUNTER_101_104   = 0;
   data_ptr.FLR_DETECTION_101_104.DET_MH_CRC16_101_104           = 0;
   data_ptr.FLR_DETECTION_101_104.DET_MH_SCAN_INDEX_4LSB_101_104 = 0;

   // FLR_DETECTION_105_108_decoded_msg_t
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_105 = af_target_report_ptr[104].ran;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_106 = af_target_report_ptr[105].ran;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_107 = af_target_report_ptr[106].ran;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_108 = af_target_report_ptr[107].ran;

   data_ptr.FLR_DETECTION_105_108.DET_AZIMUTH_105 = af_target_report_ptr[104].theta;
   data_ptr.FLR_DETECTION_105_108.DET_AZIMUTH_106 = af_target_report_ptr[105].theta;
   data_ptr.FLR_DETECTION_105_108.DET_AZIMUTH_107 = af_target_report_ptr[106].theta;
   data_ptr.FLR_DETECTION_105_108.DET_AZIMUTH_108 = af_target_report_ptr[107].theta;

   data_ptr.FLR_DETECTION_105_108.DET_BI_STATIC_FLAG_105 = af_target_report_ptr[104].f_bistatic;
   data_ptr.FLR_DETECTION_105_108.DET_BI_STATIC_FLAG_106 = af_target_report_ptr[105].f_bistatic;
   data_ptr.FLR_DETECTION_105_108.DET_BI_STATIC_FLAG_107 = af_target_report_ptr[106].f_bistatic;
   data_ptr.FLR_DETECTION_105_108.DET_BI_STATIC_FLAG_108 = af_target_report_ptr[107].f_bistatic;

   data_ptr.FLR_DETECTION_105_108.DET_CONFD_AZIMUTH_105 = af_target_report_ptr[104].az_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_AZIMUTH_106 = af_target_report_ptr[105].az_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_AZIMUTH_107 = af_target_report_ptr[106].az_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_AZIMUTH_108 = af_target_report_ptr[107].az_conf;

   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_105 = af_target_report_ptr[104].phi;
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_106 = af_target_report_ptr[105].phi;
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_107 = af_target_report_ptr[106].phi;
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_108 = af_target_report_ptr[107].phi;

   data_ptr.FLR_DETECTION_105_108.DET_CONFD_ELEVATION_105 = af_target_report_ptr[104].el_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_ELEVATION_106 = af_target_report_ptr[105].el_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_ELEVATION_107 = af_target_report_ptr[106].el_conf;
   data_ptr.FLR_DETECTION_105_108.DET_CONFD_ELEVATION_108 = af_target_report_ptr[107].el_conf;

   data_ptr.FLR_DETECTION_105_108.DET_EXISTENCE_PROB_105 = TOI_DS_Stream_Ptr->existence_prob[104];
   data_ptr.FLR_DETECTION_105_108.DET_EXISTENCE_PROB_106 = TOI_DS_Stream_Ptr->existence_prob[105];
   data_ptr.FLR_DETECTION_105_108.DET_EXISTENCE_PROB_107 = TOI_DS_Stream_Ptr->existence_prob[106];
   data_ptr.FLR_DETECTION_105_108.DET_EXISTENCE_PROB_108 = TOI_DS_Stream_Ptr->existence_prob[107];

   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_ERR_105 = TOI_DS_Stream_Ptr->std_phi[104];
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_ERR_106 = TOI_DS_Stream_Ptr->std_phi[105];
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_ERR_107 = TOI_DS_Stream_Ptr->std_phi[106];
   data_ptr.FLR_DETECTION_105_108.DET_ELEVATION_ERR_108 = TOI_DS_Stream_Ptr->std_phi[107];

   data_ptr.FLR_DETECTION_105_108.DET_IDM_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_IDM_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_IDM_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_IDM_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_105_108.DET_MTD_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_MTD_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_MTD_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_MTD_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_105_108.DET_PROB_1STAZHYPO_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_PROB_1STAZHYPO_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_PROB_1STAZHYPO_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_PROB_1STAZHYPO_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_105_108.DET_RANGE_ERR_105 = TOI_DS_Stream_Ptr->std_ran[104];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_ERR_106 = TOI_DS_Stream_Ptr->std_ran[105];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_ERR_107 = TOI_DS_Stream_Ptr->std_ran[106];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_ERR_108 = TOI_DS_Stream_Ptr->std_ran[107];

   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_105 = af_target_report_ptr[104].vel;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_106 = af_target_report_ptr[105].vel;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_107 = af_target_report_ptr[106].vel;
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_108 = af_target_report_ptr[107].vel;

   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_105 = TOI_DS_Stream_Ptr->std_vel[104];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_106 = TOI_DS_Stream_Ptr->std_vel[105];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_107 = TOI_DS_Stream_Ptr->std_vel[106];
   data_ptr.FLR_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_108 = TOI_DS_Stream_Ptr->std_vel[107];

   data_ptr.FLR_DETECTION_105_108.DET_RCS_105 = af_target_report_ptr[104].rcs;
   data_ptr.FLR_DETECTION_105_108.DET_RCS_106 = af_target_report_ptr[105].rcs;
   data_ptr.FLR_DETECTION_105_108.DET_RCS_107 = af_target_report_ptr[106].rcs;
   data_ptr.FLR_DETECTION_105_108.DET_RCS_108 = af_target_report_ptr[107].rcs;

   data_ptr.FLR_DETECTION_105_108.DET_SNR_105 = af_target_report_ptr[104].snr;
   data_ptr.FLR_DETECTION_105_108.DET_SNR_106 = af_target_report_ptr[105].snr;
   data_ptr.FLR_DETECTION_105_108.DET_SNR_107 = af_target_report_ptr[106].snr;
   data_ptr.FLR_DETECTION_105_108.DET_SNR_108 = af_target_report_ptr[107].snr;

   data_ptr.FLR_DETECTION_105_108.DET_SUPER_RES_TARGET_105 = af_target_report_ptr[104].f_superres_target;
   data_ptr.FLR_DETECTION_105_108.DET_SUPER_RES_TARGET_106 = af_target_report_ptr[105].f_superres_target;
   data_ptr.FLR_DETECTION_105_108.DET_SUPER_RES_TARGET_107 = af_target_report_ptr[106].f_superres_target;
   data_ptr.FLR_DETECTION_105_108.DET_SUPER_RES_TARGET_108 = af_target_report_ptr[107].f_superres_target;

   data_ptr.FLR_DETECTION_105_108.DET_BELOW_RAIN_THOLD_105 = 0;
   data_ptr.FLR_DETECTION_105_108.DET_BELOW_RAIN_THOLD_106 = 0;
   data_ptr.FLR_DETECTION_105_108.DET_BELOW_RAIN_THOLD_107 = 0;
   data_ptr.FLR_DETECTION_105_108.DET_BELOW_RAIN_THOLD_108 = 0;

   data_ptr.FLR_DETECTION_105_108.DET_HVC_FLAG_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_HVC_FLAG_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_HVC_FLAG_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_105_108.DET_HVC_FLAG_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_105_108.DET_MH_CYCLE_COUNTER_105_108   = 0;
   data_ptr.FLR_DETECTION_105_108.DET_MH_CRC16_105_108           = 0;
   data_ptr.FLR_DETECTION_105_108.DET_MH_SCAN_INDEX_4LSB_105_108 = 0;

   // FLR_DETECTION_109_112_decoded_msg_t
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_109 = af_target_report_ptr[108].ran;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_110 = af_target_report_ptr[109].ran;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_111 = af_target_report_ptr[110].ran;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_112 = af_target_report_ptr[111].ran;

   data_ptr.FLR_DETECTION_109_112.DET_AZIMUTH_109 = af_target_report_ptr[108].theta;
   data_ptr.FLR_DETECTION_109_112.DET_AZIMUTH_110 = af_target_report_ptr[109].theta;
   data_ptr.FLR_DETECTION_109_112.DET_AZIMUTH_111 = af_target_report_ptr[110].theta;
   data_ptr.FLR_DETECTION_109_112.DET_AZIMUTH_112 = af_target_report_ptr[111].theta;

   data_ptr.FLR_DETECTION_109_112.DET_BI_STATIC_FLAG_109 = af_target_report_ptr[108].f_bistatic;
   data_ptr.FLR_DETECTION_109_112.DET_BI_STATIC_FLAG_110 = af_target_report_ptr[109].f_bistatic;
   data_ptr.FLR_DETECTION_109_112.DET_BI_STATIC_FLAG_111 = af_target_report_ptr[110].f_bistatic;
   data_ptr.FLR_DETECTION_109_112.DET_BI_STATIC_FLAG_112 = af_target_report_ptr[111].f_bistatic;

   data_ptr.FLR_DETECTION_109_112.DET_CONFD_AZIMUTH_109 = af_target_report_ptr[108].az_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_AZIMUTH_110 = af_target_report_ptr[109].az_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_AZIMUTH_111 = af_target_report_ptr[110].az_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_AZIMUTH_112 = af_target_report_ptr[111].az_conf;

   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_109 = af_target_report_ptr[108].phi;
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_110 = af_target_report_ptr[109].phi;
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_111 = af_target_report_ptr[110].phi;
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_112 = af_target_report_ptr[111].phi;

   data_ptr.FLR_DETECTION_109_112.DET_CONFD_ELEVATION_109 = af_target_report_ptr[108].el_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_ELEVATION_110 = af_target_report_ptr[109].el_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_ELEVATION_111 = af_target_report_ptr[110].el_conf;
   data_ptr.FLR_DETECTION_109_112.DET_CONFD_ELEVATION_112 = af_target_report_ptr[111].el_conf;

   data_ptr.FLR_DETECTION_109_112.DET_EXISTENCE_PROB_109 = TOI_DS_Stream_Ptr->existence_prob[108];
   data_ptr.FLR_DETECTION_109_112.DET_EXISTENCE_PROB_110 = TOI_DS_Stream_Ptr->existence_prob[109];
   data_ptr.FLR_DETECTION_109_112.DET_EXISTENCE_PROB_111 = TOI_DS_Stream_Ptr->existence_prob[110];
   data_ptr.FLR_DETECTION_109_112.DET_EXISTENCE_PROB_112 = TOI_DS_Stream_Ptr->existence_prob[111];

   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_ERR_109 = TOI_DS_Stream_Ptr->std_phi[108];
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_ERR_110 = TOI_DS_Stream_Ptr->std_phi[109];
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_ERR_111 = TOI_DS_Stream_Ptr->std_phi[110];
   data_ptr.FLR_DETECTION_109_112.DET_ELEVATION_ERR_112 = TOI_DS_Stream_Ptr->std_phi[111];

   data_ptr.FLR_DETECTION_109_112.DET_IDM_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_IDM_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_IDM_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_IDM_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_109_112.DET_MTD_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_MTD_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_MTD_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_MTD_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_109_112.DET_PROB_1STAZHYPO_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_PROB_1STAZHYPO_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_PROB_1STAZHYPO_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_PROB_1STAZHYPO_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_109_112.DET_RANGE_ERR_109 = TOI_DS_Stream_Ptr->std_ran[108];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_ERR_110 = TOI_DS_Stream_Ptr->std_ran[109];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_ERR_111 = TOI_DS_Stream_Ptr->std_ran[110];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_ERR_112 = TOI_DS_Stream_Ptr->std_ran[111];

   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_109 = af_target_report_ptr[108].vel;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_110 = af_target_report_ptr[109].vel;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_111 = af_target_report_ptr[110].vel;
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_112 = af_target_report_ptr[111].vel;

   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_109 = TOI_DS_Stream_Ptr->std_vel[108];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_110 = TOI_DS_Stream_Ptr->std_vel[109];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_111 = TOI_DS_Stream_Ptr->std_vel[110];
   data_ptr.FLR_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_112 = TOI_DS_Stream_Ptr->std_vel[111];

   data_ptr.FLR_DETECTION_109_112.DET_RCS_109 = af_target_report_ptr[108].rcs;
   data_ptr.FLR_DETECTION_109_112.DET_RCS_110 = af_target_report_ptr[109].rcs;
   data_ptr.FLR_DETECTION_109_112.DET_RCS_111 = af_target_report_ptr[110].rcs;
   data_ptr.FLR_DETECTION_109_112.DET_RCS_112 = af_target_report_ptr[111].rcs;

   data_ptr.FLR_DETECTION_109_112.DET_SNR_109 = af_target_report_ptr[108].snr;
   data_ptr.FLR_DETECTION_109_112.DET_SNR_110 = af_target_report_ptr[109].snr;
   data_ptr.FLR_DETECTION_109_112.DET_SNR_111 = af_target_report_ptr[110].snr;
   data_ptr.FLR_DETECTION_109_112.DET_SNR_112 = af_target_report_ptr[111].snr;

   data_ptr.FLR_DETECTION_109_112.DET_SUPER_RES_TARGET_109 = af_target_report_ptr[108].f_superres_target;
   data_ptr.FLR_DETECTION_109_112.DET_SUPER_RES_TARGET_110 = af_target_report_ptr[109].f_superres_target;
   data_ptr.FLR_DETECTION_109_112.DET_SUPER_RES_TARGET_111 = af_target_report_ptr[110].f_superres_target;
   data_ptr.FLR_DETECTION_109_112.DET_SUPER_RES_TARGET_112 = af_target_report_ptr[111].f_superres_target;

   data_ptr.FLR_DETECTION_109_112.DET_BELOW_RAIN_THOLD_109 = 0;
   data_ptr.FLR_DETECTION_109_112.DET_BELOW_RAIN_THOLD_110 = 0;
   data_ptr.FLR_DETECTION_109_112.DET_BELOW_RAIN_THOLD_111 = 0;
   data_ptr.FLR_DETECTION_109_112.DET_BELOW_RAIN_THOLD_112 = 0;

   data_ptr.FLR_DETECTION_109_112.DET_HVC_FLAG_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_HVC_FLAG_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_HVC_FLAG_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_109_112.DET_HVC_FLAG_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_109_112.DET_MH_CYCLE_COUNTER_109_112   = 0;
   data_ptr.FLR_DETECTION_109_112.DET_MH_CRC16_109_112           = 0;
   data_ptr.FLR_DETECTION_109_112.DET_MH_SCAN_INDEX_4LSB_109_112 = 0;

   // FLR_DETECTION_113_116_decoded_msg_t
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_113 = af_target_report_ptr[112].ran;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_114 = af_target_report_ptr[113].ran;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_115 = af_target_report_ptr[114].ran;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_116 = af_target_report_ptr[115].ran;

   data_ptr.FLR_DETECTION_113_116.DET_AZIMUTH_113 = af_target_report_ptr[112].theta;
   data_ptr.FLR_DETECTION_113_116.DET_AZIMUTH_114 = af_target_report_ptr[113].theta;
   data_ptr.FLR_DETECTION_113_116.DET_AZIMUTH_115 = af_target_report_ptr[114].theta;
   data_ptr.FLR_DETECTION_113_116.DET_AZIMUTH_116 = af_target_report_ptr[115].theta;

   data_ptr.FLR_DETECTION_113_116.DET_BI_STATIC_FLAG_113 = af_target_report_ptr[112].f_bistatic;
   data_ptr.FLR_DETECTION_113_116.DET_BI_STATIC_FLAG_114 = af_target_report_ptr[113].f_bistatic;
   data_ptr.FLR_DETECTION_113_116.DET_BI_STATIC_FLAG_115 = af_target_report_ptr[114].f_bistatic;
   data_ptr.FLR_DETECTION_113_116.DET_BI_STATIC_FLAG_116 = af_target_report_ptr[115].f_bistatic;

   data_ptr.FLR_DETECTION_113_116.DET_CONFD_AZIMUTH_113 = af_target_report_ptr[112].az_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_AZIMUTH_114 = af_target_report_ptr[113].az_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_AZIMUTH_115 = af_target_report_ptr[114].az_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_AZIMUTH_116 = af_target_report_ptr[115].az_conf;

   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_113 = af_target_report_ptr[112].phi;
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_114 = af_target_report_ptr[113].phi;
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_115 = af_target_report_ptr[114].phi;
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_116 = af_target_report_ptr[115].phi;

   data_ptr.FLR_DETECTION_113_116.DET_CONFD_ELEVATION_113 = af_target_report_ptr[112].el_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_ELEVATION_114 = af_target_report_ptr[113].el_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_ELEVATION_115 = af_target_report_ptr[114].el_conf;
   data_ptr.FLR_DETECTION_113_116.DET_CONFD_ELEVATION_116 = af_target_report_ptr[115].el_conf;

   data_ptr.FLR_DETECTION_113_116.DET_EXISTENCE_PROB_113 = TOI_DS_Stream_Ptr->existence_prob[112];
   data_ptr.FLR_DETECTION_113_116.DET_EXISTENCE_PROB_114 = TOI_DS_Stream_Ptr->existence_prob[113];
   data_ptr.FLR_DETECTION_113_116.DET_EXISTENCE_PROB_115 = TOI_DS_Stream_Ptr->existence_prob[114];
   data_ptr.FLR_DETECTION_113_116.DET_EXISTENCE_PROB_116 = TOI_DS_Stream_Ptr->existence_prob[115];

   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_ERR_113 = TOI_DS_Stream_Ptr->std_phi[112];
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_ERR_114 = TOI_DS_Stream_Ptr->std_phi[113];
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_ERR_115 = TOI_DS_Stream_Ptr->std_phi[114];
   data_ptr.FLR_DETECTION_113_116.DET_ELEVATION_ERR_116 = TOI_DS_Stream_Ptr->std_phi[115];

   data_ptr.FLR_DETECTION_113_116.DET_IDM_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_IDM_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_IDM_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_IDM_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_113_116.DET_MTD_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_MTD_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_MTD_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_MTD_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_113_116.DET_PROB_1STAZHYPO_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_PROB_1STAZHYPO_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_PROB_1STAZHYPO_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_PROB_1STAZHYPO_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_113_116.DET_RANGE_ERR_113 = TOI_DS_Stream_Ptr->std_ran[112];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_ERR_114 = TOI_DS_Stream_Ptr->std_ran[113];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_ERR_115 = TOI_DS_Stream_Ptr->std_ran[114];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_ERR_116 = TOI_DS_Stream_Ptr->std_ran[115];

   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_113 = af_target_report_ptr[112].vel;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_114 = af_target_report_ptr[113].vel;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_115 = af_target_report_ptr[114].vel;
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_116 = af_target_report_ptr[115].vel;

   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_113 = TOI_DS_Stream_Ptr->std_vel[112];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_114 = TOI_DS_Stream_Ptr->std_vel[113];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_115 = TOI_DS_Stream_Ptr->std_vel[114];
   data_ptr.FLR_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_116 = TOI_DS_Stream_Ptr->std_vel[115];

   data_ptr.FLR_DETECTION_113_116.DET_RCS_113 = af_target_report_ptr[112].rcs;
   data_ptr.FLR_DETECTION_113_116.DET_RCS_114 = af_target_report_ptr[113].rcs;
   data_ptr.FLR_DETECTION_113_116.DET_RCS_115 = af_target_report_ptr[114].rcs;
   data_ptr.FLR_DETECTION_113_116.DET_RCS_116 = af_target_report_ptr[115].rcs;

   data_ptr.FLR_DETECTION_113_116.DET_SNR_113 = af_target_report_ptr[112].snr;
   data_ptr.FLR_DETECTION_113_116.DET_SNR_114 = af_target_report_ptr[113].snr;
   data_ptr.FLR_DETECTION_113_116.DET_SNR_115 = af_target_report_ptr[114].snr;
   data_ptr.FLR_DETECTION_113_116.DET_SNR_116 = af_target_report_ptr[115].snr;

   data_ptr.FLR_DETECTION_113_116.DET_SUPER_RES_TARGET_113 = af_target_report_ptr[112].f_superres_target;
   data_ptr.FLR_DETECTION_113_116.DET_SUPER_RES_TARGET_114 = af_target_report_ptr[113].f_superres_target;
   data_ptr.FLR_DETECTION_113_116.DET_SUPER_RES_TARGET_115 = af_target_report_ptr[114].f_superres_target;
   data_ptr.FLR_DETECTION_113_116.DET_SUPER_RES_TARGET_116 = af_target_report_ptr[115].f_superres_target;

   data_ptr.FLR_DETECTION_113_116.DET_BELOW_RAIN_THOLD_113 = 0;
   data_ptr.FLR_DETECTION_113_116.DET_BELOW_RAIN_THOLD_114 = 0;
   data_ptr.FLR_DETECTION_113_116.DET_BELOW_RAIN_THOLD_115 = 0;
   data_ptr.FLR_DETECTION_113_116.DET_BELOW_RAIN_THOLD_116 = 0;

   data_ptr.FLR_DETECTION_113_116.DET_HVC_FLAG_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_HVC_FLAG_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_HVC_FLAG_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_113_116.DET_HVC_FLAG_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_113_116.DET_MH_CYCLE_COUNTER_113_116   = 0;
   data_ptr.FLR_DETECTION_113_116.DET_MH_CRC16_113_116           = 0;
   data_ptr.FLR_DETECTION_113_116.DET_MH_SCAN_INDEX_4LSB_113_116 = 0;

   // FLR_DETECTION_117_120_decoded_msg_t
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_117 = af_target_report_ptr[116].ran;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_118 = af_target_report_ptr[117].ran;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_119 = af_target_report_ptr[118].ran;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_120 = af_target_report_ptr[119].ran;

   data_ptr.FLR_DETECTION_117_120.DET_AZIMUTH_117 = af_target_report_ptr[116].theta;
   data_ptr.FLR_DETECTION_117_120.DET_AZIMUTH_118 = af_target_report_ptr[117].theta;
   data_ptr.FLR_DETECTION_117_120.DET_AZIMUTH_119 = af_target_report_ptr[118].theta;
   data_ptr.FLR_DETECTION_117_120.DET_AZIMUTH_120 = af_target_report_ptr[119].theta;

   data_ptr.FLR_DETECTION_117_120.DET_BI_STATIC_FLAG_117 = af_target_report_ptr[116].f_bistatic;
   data_ptr.FLR_DETECTION_117_120.DET_BI_STATIC_FLAG_118 = af_target_report_ptr[117].f_bistatic;
   data_ptr.FLR_DETECTION_117_120.DET_BI_STATIC_FLAG_119 = af_target_report_ptr[118].f_bistatic;
   data_ptr.FLR_DETECTION_117_120.DET_BI_STATIC_FLAG_120 = af_target_report_ptr[119].f_bistatic;

   data_ptr.FLR_DETECTION_117_120.DET_CONFD_AZIMUTH_117 = af_target_report_ptr[116].az_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_AZIMUTH_118 = af_target_report_ptr[117].az_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_AZIMUTH_119 = af_target_report_ptr[118].az_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_AZIMUTH_120 = af_target_report_ptr[119].az_conf;

   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_117 = af_target_report_ptr[116].phi;
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_118 = af_target_report_ptr[117].phi;
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_119 = af_target_report_ptr[118].phi;
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_120 = af_target_report_ptr[119].phi;

   data_ptr.FLR_DETECTION_117_120.DET_CONFD_ELEVATION_117 = af_target_report_ptr[116].el_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_ELEVATION_118 = af_target_report_ptr[117].el_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_ELEVATION_119 = af_target_report_ptr[118].el_conf;
   data_ptr.FLR_DETECTION_117_120.DET_CONFD_ELEVATION_120 = af_target_report_ptr[119].el_conf;

   data_ptr.FLR_DETECTION_117_120.DET_EXISTENCE_PROB_117 = TOI_DS_Stream_Ptr->existence_prob[116];
   data_ptr.FLR_DETECTION_117_120.DET_EXISTENCE_PROB_118 = TOI_DS_Stream_Ptr->existence_prob[117];
   data_ptr.FLR_DETECTION_117_120.DET_EXISTENCE_PROB_119 = TOI_DS_Stream_Ptr->existence_prob[118];
   data_ptr.FLR_DETECTION_117_120.DET_EXISTENCE_PROB_120 = TOI_DS_Stream_Ptr->existence_prob[119];

   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_ERR_117 = TOI_DS_Stream_Ptr->std_phi[116];
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_ERR_118 = TOI_DS_Stream_Ptr->std_phi[117];
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_ERR_119 = TOI_DS_Stream_Ptr->std_phi[118];
   data_ptr.FLR_DETECTION_117_120.DET_ELEVATION_ERR_120 = TOI_DS_Stream_Ptr->std_phi[119];

   data_ptr.FLR_DETECTION_117_120.DET_IDM_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_IDM_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_IDM_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_IDM_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_117_120.DET_MTD_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_MTD_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_MTD_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_MTD_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_117_120.DET_PROB_1STAZHYPO_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_PROB_1STAZHYPO_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_PROB_1STAZHYPO_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_PROB_1STAZHYPO_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_117_120.DET_RANGE_ERR_117 = TOI_DS_Stream_Ptr->std_ran[116];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_ERR_118 = TOI_DS_Stream_Ptr->std_ran[117];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_ERR_119 = TOI_DS_Stream_Ptr->std_ran[118];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_ERR_120 = TOI_DS_Stream_Ptr->std_ran[119];

   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_117 = af_target_report_ptr[116].vel;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_118 = af_target_report_ptr[117].vel;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_119 = af_target_report_ptr[118].vel;
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_120 = af_target_report_ptr[119].vel;

   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_117 = TOI_DS_Stream_Ptr->std_vel[116];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_118 = TOI_DS_Stream_Ptr->std_vel[117];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_119 = TOI_DS_Stream_Ptr->std_vel[118];
   data_ptr.FLR_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_120 = TOI_DS_Stream_Ptr->std_vel[119];

   data_ptr.FLR_DETECTION_117_120.DET_RCS_117 = af_target_report_ptr[116].rcs;
   data_ptr.FLR_DETECTION_117_120.DET_RCS_118 = af_target_report_ptr[117].rcs;
   data_ptr.FLR_DETECTION_117_120.DET_RCS_119 = af_target_report_ptr[118].rcs;
   data_ptr.FLR_DETECTION_117_120.DET_RCS_120 = af_target_report_ptr[119].rcs;

   data_ptr.FLR_DETECTION_117_120.DET_SNR_117 = af_target_report_ptr[116].snr;
   data_ptr.FLR_DETECTION_117_120.DET_SNR_118 = af_target_report_ptr[117].snr;
   data_ptr.FLR_DETECTION_117_120.DET_SNR_119 = af_target_report_ptr[118].snr;
   data_ptr.FLR_DETECTION_117_120.DET_SNR_120 = af_target_report_ptr[119].snr;

   data_ptr.FLR_DETECTION_117_120.DET_SUPER_RES_TARGET_117 = af_target_report_ptr[116].f_superres_target;
   data_ptr.FLR_DETECTION_117_120.DET_SUPER_RES_TARGET_118 = af_target_report_ptr[117].f_superres_target;
   data_ptr.FLR_DETECTION_117_120.DET_SUPER_RES_TARGET_119 = af_target_report_ptr[118].f_superres_target;
   data_ptr.FLR_DETECTION_117_120.DET_SUPER_RES_TARGET_120 = af_target_report_ptr[119].f_superres_target;

   data_ptr.FLR_DETECTION_117_120.DET_BELOW_RAIN_THOLD_117 = 0;
   data_ptr.FLR_DETECTION_117_120.DET_BELOW_RAIN_THOLD_118 = 0;
   data_ptr.FLR_DETECTION_117_120.DET_BELOW_RAIN_THOLD_119 = 0;
   data_ptr.FLR_DETECTION_117_120.DET_BELOW_RAIN_THOLD_120 = 0;

   data_ptr.FLR_DETECTION_117_120.DET_HVC_FLAG_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_HVC_FLAG_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_HVC_FLAG_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_117_120.DET_HVC_FLAG_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_117_120.DET_MH_CYCLE_COUNTER_117_120   = 0;
   data_ptr.FLR_DETECTION_117_120.DET_MH_CRC16_117_120           = 0;
   data_ptr.FLR_DETECTION_117_120.DET_MH_SCAN_INDEX_4LSB_117_120 = 0;

   // FLR_DETECTION_121_124_decoded_msg_t
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_121 = af_target_report_ptr[120].ran;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_122 = af_target_report_ptr[121].ran;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_123 = af_target_report_ptr[122].ran;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_124 = af_target_report_ptr[123].ran;

   data_ptr.FLR_DETECTION_121_124.DET_AZIMUTH_121 = af_target_report_ptr[120].theta;
   data_ptr.FLR_DETECTION_121_124.DET_AZIMUTH_122 = af_target_report_ptr[121].theta;
   data_ptr.FLR_DETECTION_121_124.DET_AZIMUTH_123 = af_target_report_ptr[122].theta;
   data_ptr.FLR_DETECTION_121_124.DET_AZIMUTH_124 = af_target_report_ptr[123].theta;

   data_ptr.FLR_DETECTION_121_124.DET_BI_STATIC_FLAG_121 = af_target_report_ptr[120].f_bistatic;
   data_ptr.FLR_DETECTION_121_124.DET_BI_STATIC_FLAG_122 = af_target_report_ptr[121].f_bistatic;
   data_ptr.FLR_DETECTION_121_124.DET_BI_STATIC_FLAG_123 = af_target_report_ptr[122].f_bistatic;
   data_ptr.FLR_DETECTION_121_124.DET_BI_STATIC_FLAG_124 = af_target_report_ptr[123].f_bistatic;

   data_ptr.FLR_DETECTION_121_124.DET_CONFD_AZIMUTH_121 = af_target_report_ptr[120].az_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_AZIMUTH_122 = af_target_report_ptr[121].az_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_AZIMUTH_123 = af_target_report_ptr[122].az_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_AZIMUTH_124 = af_target_report_ptr[123].az_conf;

   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_121 = af_target_report_ptr[120].phi;
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_122 = af_target_report_ptr[121].phi;
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_123 = af_target_report_ptr[122].phi;
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_124 = af_target_report_ptr[123].phi;

   data_ptr.FLR_DETECTION_121_124.DET_CONFD_ELEVATION_121 = af_target_report_ptr[120].el_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_ELEVATION_122 = af_target_report_ptr[121].el_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_ELEVATION_123 = af_target_report_ptr[122].el_conf;
   data_ptr.FLR_DETECTION_121_124.DET_CONFD_ELEVATION_124 = af_target_report_ptr[123].el_conf;

   data_ptr.FLR_DETECTION_121_124.DET_EXISTENCE_PROB_121 = TOI_DS_Stream_Ptr->existence_prob[120];
   data_ptr.FLR_DETECTION_121_124.DET_EXISTENCE_PROB_122 = TOI_DS_Stream_Ptr->existence_prob[121];
   data_ptr.FLR_DETECTION_121_124.DET_EXISTENCE_PROB_123 = TOI_DS_Stream_Ptr->existence_prob[122];
   data_ptr.FLR_DETECTION_121_124.DET_EXISTENCE_PROB_124 = TOI_DS_Stream_Ptr->existence_prob[123];

   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_ERR_121 = TOI_DS_Stream_Ptr->std_phi[120];
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_ERR_122 = TOI_DS_Stream_Ptr->std_phi[121];
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_ERR_123 = TOI_DS_Stream_Ptr->std_phi[122];
   data_ptr.FLR_DETECTION_121_124.DET_ELEVATION_ERR_124 = TOI_DS_Stream_Ptr->std_phi[123];

   data_ptr.FLR_DETECTION_121_124.DET_IDM_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_IDM_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_IDM_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_IDM_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_121_124.DET_MTD_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_MTD_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_MTD_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_MTD_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_121_124.DET_PROB_1STAZHYPO_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_PROB_1STAZHYPO_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_PROB_1STAZHYPO_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_PROB_1STAZHYPO_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_121_124.DET_RANGE_ERR_121 = TOI_DS_Stream_Ptr->std_ran[120];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_ERR_122 = TOI_DS_Stream_Ptr->std_ran[121];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_ERR_123 = TOI_DS_Stream_Ptr->std_ran[122];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_ERR_124 = TOI_DS_Stream_Ptr->std_ran[123];

   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_121 = af_target_report_ptr[120].vel;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_122 = af_target_report_ptr[121].vel;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_123 = af_target_report_ptr[122].vel;
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_124 = af_target_report_ptr[123].vel;

   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_121 = TOI_DS_Stream_Ptr->std_vel[120];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_122 = TOI_DS_Stream_Ptr->std_vel[121];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_123 = TOI_DS_Stream_Ptr->std_vel[122];
   data_ptr.FLR_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_124 = TOI_DS_Stream_Ptr->std_vel[123];

   data_ptr.FLR_DETECTION_121_124.DET_RCS_121 = af_target_report_ptr[120].rcs;
   data_ptr.FLR_DETECTION_121_124.DET_RCS_122 = af_target_report_ptr[121].rcs;
   data_ptr.FLR_DETECTION_121_124.DET_RCS_123 = af_target_report_ptr[122].rcs;
   data_ptr.FLR_DETECTION_121_124.DET_RCS_124 = af_target_report_ptr[123].rcs;

   data_ptr.FLR_DETECTION_121_124.DET_SNR_121 = af_target_report_ptr[120].snr;
   data_ptr.FLR_DETECTION_121_124.DET_SNR_122 = af_target_report_ptr[121].snr;
   data_ptr.FLR_DETECTION_121_124.DET_SNR_123 = af_target_report_ptr[122].snr;
   data_ptr.FLR_DETECTION_121_124.DET_SNR_124 = af_target_report_ptr[123].snr;

   data_ptr.FLR_DETECTION_121_124.DET_SUPER_RES_TARGET_121 = af_target_report_ptr[120].f_superres_target;
   data_ptr.FLR_DETECTION_121_124.DET_SUPER_RES_TARGET_122 = af_target_report_ptr[121].f_superres_target;
   data_ptr.FLR_DETECTION_121_124.DET_SUPER_RES_TARGET_123 = af_target_report_ptr[122].f_superres_target;
   data_ptr.FLR_DETECTION_121_124.DET_SUPER_RES_TARGET_124 = af_target_report_ptr[123].f_superres_target;

   data_ptr.FLR_DETECTION_121_124.DET_BELOW_RAIN_THOLD_121 = 0;
   data_ptr.FLR_DETECTION_121_124.DET_BELOW_RAIN_THOLD_122 = 0;
   data_ptr.FLR_DETECTION_121_124.DET_BELOW_RAIN_THOLD_123 = 0;
   data_ptr.FLR_DETECTION_121_124.DET_BELOW_RAIN_THOLD_124 = 0;

   data_ptr.FLR_DETECTION_121_124.DET_HVC_FLAG_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_HVC_FLAG_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_HVC_FLAG_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_DETECTION_121_124.DET_HVC_FLAG_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.FLR_DETECTION_121_124.DET_MH_CYCLE_COUNTER_121_124   = 0;
   data_ptr.FLR_DETECTION_121_124.DET_MH_CRC16_121_124           = 0;
   data_ptr.FLR_DETECTION_121_124.DET_MH_SCAN_INDEX_4LSB_121_124 = 0;

   // FLR_DETECTION_125_128_decoded_msg_t
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_125 = af_target_report_ptr[125].ran; // af_target_report_ptr->af_ds_data.ran[124];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_126 = af_target_report_ptr[126].ran; // af_target_report_ptr->af_ds_data.ran[125];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_127 = af_target_report_ptr[127].ran; // af_target_report_ptr->af_ds_data.ran[126];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_128 = af_target_report_ptr[128].ran; // af_target_report_ptr->af_ds_data.ran[127];

   data_ptr.FLR_DETECTION_125_128_.DET_AZIMUTH_125 = 0; // af_target_report_ptr->af_ds_data.theta[124];
   data_ptr.FLR_DETECTION_125_128_.DET_AZIMUTH_126 = 0; // af_target_report_ptr->af_ds_data.theta[125];
   data_ptr.FLR_DETECTION_125_128_.DET_AZIMUTH_127 = 0; // af_target_report_ptr->af_ds_data.theta[126];
   data_ptr.FLR_DETECTION_125_128_.DET_AZIMUTH_128 = 0; // af_target_report_ptr->af_ds_data.theta[127];

   data_ptr.FLR_DETECTION_125_128_.DET_BI_STATIC_FLAG_125 = 0; // af_target_report_ptr->af_ds_data.f_bistatic[124];
   data_ptr.FLR_DETECTION_125_128_.DET_BI_STATIC_FLAG_126 = 0; // af_target_report_ptr->af_ds_data.f_bistatic[125];
   data_ptr.FLR_DETECTION_125_128_.DET_BI_STATIC_FLAG_127 = 0; // af_target_report_ptr->af_ds_data.f_bistatic[126];
   data_ptr.FLR_DETECTION_125_128_.DET_BI_STATIC_FLAG_128 = 0; // af_target_report_ptr->af_ds_data.f_bistatic[127];

   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_AZIMUTH_125 = 0; // af_target_report_ptr->af_ds_data.az_conf[124];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_AZIMUTH_126 = 0; // af_target_report_ptr->af_ds_data.az_conf[125];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_AZIMUTH_127 = 0; // af_target_report_ptr->af_ds_data.az_conf[126];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_AZIMUTH_128 = 0; // af_target_report_ptr->af_ds_data.az_conf[127];

   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_125 = 0; // af_target_report_ptr->af_ds_data.phi[125];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_126 = 0; // af_target_report_ptr->af_ds_data.phi[126];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_127 = 0; // af_target_report_ptr->af_ds_data.phi[127];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_128 = 0; // af_target_report_ptr->af_ds_data.phi[128];

   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_ELEVATION_125 = 0; // af_target_report_ptr->af_ds_data.el_conf[125];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_ELEVATION_126 = 0; // af_target_report_ptr->af_ds_data.el_conf[126];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_ELEVATION_127 = 0; // af_target_report_ptr->af_ds_data.el_conf[127];
   data_ptr.FLR_DETECTION_125_128_.DET_CONFD_ELEVATION_128 = 0; // af_target_report_ptr->af_ds_data.el_conf[128];

   data_ptr.FLR_DETECTION_125_128_.DET_EXISTENCE_PROB_125 = 0; // TOI_Stream_Ptr->toi_data.existence_prob[124];
   data_ptr.FLR_DETECTION_125_128_.DET_EXISTENCE_PROB_126 = 0; // TOI_Stream_Ptr->toi_data.existence_prob[125];
   data_ptr.FLR_DETECTION_125_128_.DET_EXISTENCE_PROB_127 = 0; // TOI_Stream_Ptr->toi_data.existence_prob[126];
   data_ptr.FLR_DETECTION_125_128_.DET_EXISTENCE_PROB_128 = 0; // TOI_Stream_Ptr->toi_data.existence_prob[127];

   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_ERR_125 = 0; // TOI_Stream_Ptr->toi_data.std_phi[124];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_ERR_126 = 0; // TOI_Stream_Ptr->toi_data.std_phi[125];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_ERR_127 = 0; // TOI_Stream_Ptr->toi_data.std_phi[126];
   data_ptr.FLR_DETECTION_125_128_.DET_ELEVATION_ERR_128 = 0; // TOI_Stream_Ptr->toi_data.std_phi[127];

   data_ptr.FLR_DETECTION_125_128_.DET_IDM_125 = 0; // af_target_report_ptr->af_ds_data.f_idm[124];
   data_ptr.FLR_DETECTION_125_128_.DET_IDM_126 = 0; // af_target_report_ptr->af_ds_data.f_idm[125];
   data_ptr.FLR_DETECTION_125_128_.DET_IDM_127 = 0; // af_target_report_ptr->af_ds_data.f_idm[126];
   data_ptr.FLR_DETECTION_125_128_.DET_IDM_128 = 0; // af_target_report_ptr->af_ds_data.f_idm[127];

   data_ptr.FLR_DETECTION_125_128_.DET_MTD_125 = 0; // af_target_report_ptr->af_ds_data.f_mtd[124];
   data_ptr.FLR_DETECTION_125_128_.DET_MTD_126 = 0; // af_target_report_ptr->af_ds_data.f_mtd[125];
   data_ptr.FLR_DETECTION_125_128_.DET_MTD_127 = 0; // af_target_report_ptr->af_ds_data.f_mtd[126];
   data_ptr.FLR_DETECTION_125_128_.DET_MTD_128 = 0; // af_target_report_ptr->af_ds_data.f_mtd[127];

   data_ptr.FLR_DETECTION_125_128_.DET_PROB_1STAZHYPO_125 = 0; // af_target_report_ptr->af_ds_data.f_prob_1stazhypo[124];
   data_ptr.FLR_DETECTION_125_128_.DET_PROB_1STAZHYPO_126 = 0; // af_target_report_ptr->af_ds_data.f_prob_1stazhypo[125];
   data_ptr.FLR_DETECTION_125_128_.DET_PROB_1STAZHYPO_127 = 0; // af_target_report_ptr->af_ds_data.f_prob_1stazhypo[126];
   data_ptr.FLR_DETECTION_125_128_.DET_PROB_1STAZHYPO_128 = 0; // af_target_report_ptr->af_ds_data.f_prob_1stazhypo[127];

   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_ERR_125 = 0; // TOI_Stream_Ptr->toi_data.std_ran[124];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_ERR_126 = 0; // TOI_Stream_Ptr->toi_data.std_ran[125];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_ERR_127 = 0; // TOI_Stream_Ptr->toi_data.std_ran[126];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_ERR_128 = 0; // TOI_Stream_Ptr->toi_data.std_ran[127];

   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_125 = 0; // af_target_report_ptr->af_ds_data.vel[124];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_126 = 0; // af_target_report_ptr->af_ds_data.vel[125];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_127 = 0; // af_target_report_ptr->af_ds_data.vel[126];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_128 = 0; // af_target_report_ptr->af_ds_data.vel[127];

   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_ERR_125 = 0; // TOI_Stream_Ptr->toi_data.std_vel[124];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_ERR_126 = 0; // TOI_Stream_Ptr->toi_data.std_vel[125];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_ERR_127 = 0; // TOI_Stream_Ptr->toi_data.std_vel[126];
   data_ptr.FLR_DETECTION_125_128_.DET_RANGE_VELOCITY_ERR_128 = 0; // TOI_Stream_Ptr->toi_data.std_vel[127];

   data_ptr.FLR_DETECTION_125_128_.DET_RCS_125 = 0; // af_target_report_ptr->af_ds_data.rcs[124];
   data_ptr.FLR_DETECTION_125_128_.DET_RCS_126 = 0; // af_target_report_ptr->af_ds_data.rcs[125];
   data_ptr.FLR_DETECTION_125_128_.DET_RCS_127 = 0; // af_target_report_ptr->af_ds_data.rcs[126];
   data_ptr.FLR_DETECTION_125_128_.DET_RCS_128 = 0; // af_target_report_ptr->af_ds_data.rcs[127];

   data_ptr.FLR_DETECTION_125_128_.DET_SNR_125 = 0; // af_target_report_ptr->af_ds_data.snr[124];
   data_ptr.FLR_DETECTION_125_128_.DET_SNR_126 = 0; // af_target_report_ptr->af_ds_data.snr[125];
   data_ptr.FLR_DETECTION_125_128_.DET_SNR_127 = 0; // af_target_report_ptr->af_ds_data.snr[126];
   data_ptr.FLR_DETECTION_125_128_.DET_SNR_128 = 0; // af_target_report_ptr->af_ds_data.snr[127];

   data_ptr.FLR_DETECTION_125_128_.DET_SUPER_RES_TARGET_125 = 0; // af_target_report_ptr->af_ds_data.f_superres_target[124];
   data_ptr.FLR_DETECTION_125_128_.DET_SUPER_RES_TARGET_126 = 0; // af_target_report_ptr->af_ds_data.f_superres_target[125];
   data_ptr.FLR_DETECTION_125_128_.DET_SUPER_RES_TARGET_127 = 0; // af_target_report_ptr->af_ds_data.f_superres_target[126];
   data_ptr.FLR_DETECTION_125_128_.DET_SUPER_RES_TARGET_128 = 0; // af_target_report_ptr->af_ds_data.f_superres_target[127];

   data_ptr.FLR_DETECTION_125_128_.DET_BELOW_RAIN_THOLD_125 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_BELOW_RAIN_THOLD_126 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_BELOW_RAIN_THOLD_127 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_BELOW_RAIN_THOLD_128 = 0;

   data_ptr.FLR_DETECTION_125_128_.DET_HVC_FLAG_125 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_HVC_FLAG_126 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_HVC_FLAG_127 = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_HVC_FLAG_128 = 0;

   data_ptr.FLR_DETECTION_125_128_.DET_MH_CYCLE_COUNTER_125_128   = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_MH_CRC16_125_128           = 0;
   data_ptr.FLR_DETECTION_125_128_.DET_MH_SCAN_INDEX_4LSB_125_128 = 0;
}

void populate_FLR_VCAN_object_data(void)
{
   uint8_t temp_sig;
   SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr = Get_Sil_Radar_Input_Symbol_Ptr();

   memset(&vcan_data_ptr, 0, sizeof(Sensor_decoded_types_VCAN_t));

   vcan_data_ptr.BSD1.BlindSpotDetectionState          = RL_bsis_alert_level;
   vcan_data_ptr.BSD1.BlindSpotCollisionWarningLevel   = RL_BlindSpotDetectionState;
   vcan_data_ptr.BSD1.BlindSpotWarnigRelevantObjDetect = RL_BlindSpotWarnigRelevantObjDetect;
   vcan_data_ptr.BSD1.BendOffPrbablityofMstImportatObj = RL_BendOffPrbablityofMstImportatObj;

   temp_sig = ipc_d2m->payload.Mois_IPC_Output.mois_cust_output.mois_alert_level;
   if (temp_sig > 0U)
   {
      vcan_data_ptr.MOIS.ObjectDetectionState = COLLISION_WARNING_ACTIVE;
   }
   else
   {
      vcan_data_ptr.MOIS.ObjectDetectionState = SYSTEM_READY_ACTIVATED;
   }

   vcan_data_ptr.MOIS.CollisionWarningLevel = ipc_d2m->payload.Mois_IPC_Output.mois_cust_output.mois_alert_level;

   temp_sig = ipc_d2m->payload.Mois_IPC_Output.mois_cust_output.mois_number_of_relevant_objects;
   switch (temp_sig)
   {
      case NO_RELEVANT_OBJECT_MONITORED:
      {
         vcan_data_ptr.MOIS.WarningRelevantObjectDetected = NO_RELEVANT_OBJECT_MONITORED;
         break;
      }
      case SINGLE_RELEVANT_OBJECT_MONITORED:
      {
         vcan_data_ptr.MOIS.WarningRelevantObjectDetected = SINGLE_RELEVANT_OBJECT_MONITORED;
         break;
      }
      default:
      {
         vcan_data_ptr.MOIS.WarningRelevantObjectDetected = MULTIPLE_RELEVANT_OBJECT_MONITORED;
         break;
      }
   }

   vcan_data_ptr.prop_ADAS_MOIS_BSIS_info.BlindSpotCollisionWarningLevel = 0;
   vcan_data_ptr.prop_ADAS_MOIS_BSIS_info.BlindSpotDetectionState        = 0;
   vcan_data_ptr.prop_ADAS_MOIS_BSIS_info.MOIS_CollisionWarningLevel     = 0;
   vcan_data_ptr.prop_ADAS_MOIS_BSIS_info.MovingObjectDetectionState     = 0;
}

void populate_Front_object_data(void)
{
   SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr = Get_Sil_Radar_Input_Symbol_Ptr();

   memset(&data_ptr, 0, sizeof(Sensor_decoded_types_t));

   // SRR_FL_HEADER_001_decoded_msg_t
   data_ptr.SRR_FL_HEADER_001.HED_ALIGN_HOR_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal;
   data_ptr.SRR_FL_HEADER_001.HED_ALIGN_VER_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal;
   data_ptr.SRR_FL_HEADER_001.HED_Auth_CRC32 = 0; // need to be check
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_FL_HEADER_001.HED_DATA_QUALIFIER = (ipc_d2m->payload.toi_ds_stream_data.toi_op_data.data_qualifier) - 1U;
#else
   data_ptr.SRR_FL_HEADER_001.HED_DATA_QUALIFIER          = ipc_d2m->payload.toi_stream_data.toi_op_data.data_qualifier;
#endif
   data_ptr.SRR_FL_HEADER_001.HED_DET_BI_STATIC_COUNT = CAN_SIG_NOT_IMPLEMENTED;
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_FL_HEADER_001.HED_DET_NUM_OF_1PASS = ipc_d2m->payload.downselection_data.det_list_property.num_fp_detections;
   data_ptr.SRR_FL_HEADER_001.HED_DET_NUM_OF_2PASS = ipc_d2m->payload.downselection_data.det_list_property.num_sp_detections;
   data_ptr.SRR_FL_HEADER_001.HED_NUM_OF_VALID_DETECTIONS = ipc_d2m->payload.downselection_data.num_af_ds_det;
   data_ptr.SRR_FL_HEADER_001.HED_SENSOR_TIME_STAMP_NS    = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.SRR_FL_HEADER_001.HED_SENSOR_TIME_STAMP_SEC   = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#else
   data_ptr.SRR_FL_HEADER_001.HED_DET_NUM_OF_1PASS        = ipc_d2m->payload.det_data.det_list_property.num_fp_detections;
   data_ptr.SRR_FL_HEADER_001.HED_DET_NUM_OF_2PASS        = ipc_d2m->payload.det_data.det_list_property.num_sp_detections;
   data_ptr.SRR_FL_HEADER_001.HED_NUM_OF_VALID_DETECTIONS = ipc_d2m->payload.det_data.num_af_ds_det;
   data_ptr.SRR_FL_HEADER_001.HED_SENSOR_TIME_STAMP_NS    = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.SRR_FL_HEADER_001.HED_SENSOR_TIME_STAMP_SEC   = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#endif
   data_ptr.SRR_FL_HEADER_001.HED_FOV_HOR_MIN           = FXP2FLP_Fnc(k_fov_hor_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_FL_HEADER_001.HED_FOV_HOR_MAX           = FXP2FLP_Fnc(k_fov_hor_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_FL_HEADER_001.HED_FOV_VER_MIN           = FXP2FLP_Fnc(k_fov_ver_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_FL_HEADER_001.HED_FOV_VER_MAX           = FXP2FLP_Fnc(k_fov_ver_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_FL_HEADER_001.HED_LOOK_ID               = ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   data_ptr.SRR_FL_HEADER_001.HED_SCAN_INDEX            = Get_Current_Scan_Index();
   data_ptr.SRR_FL_HEADER_001.HED_MAX_NUM_OF_DETECTIONS = static_cast<uint8_t>(MAX_FLR_DETECTIONS);
   data_ptr.SRR_FL_HEADER_001.HED_MH_CRC16              = 0;
   data_ptr.SRR_FL_HEADER_001.HED_MH_CYCLE_COUNTER      = 0;

   data_ptr.SRR_FL_HEADER_001.HED_NUM_OF_RESTBINS_USED = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_HEADER_001.HED_OPERATION_MODE       = 0x02; // 0x02 for Operational Mode
   data_ptr.SRR_FL_HEADER_001.HED_PROCESSED_RANGE      = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_HEADER_001.HED_R_WRAPPING           = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_HEADER_001.HED_Rain_Level           = 0;
   data_ptr.SRR_FL_HEADER_001.HED_LOOK_INDEX           = ipc_d2m->payload.rdd_stream_data.look_data.look_index;

   data_ptr.SRR_FL_HEADER_001.HED_TRIGGER_TIME             = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_HEADER_001.HED_SLOPE_CORR_EXECUTIONFLAG = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_HEADER_001.HED_TIME_SYNC_VALIDITY_FLAG  = 0; // need to check
   data_ptr.SRR_FL_HEADER_001.HED_TIME_SYNC_SRC_MASTER     = 0; // need to check

   Radar_Look_T hdr_look_type;
   hdr_look_type = (Radar_Look_T)ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   if (hdr_look_type < RADAR_LOOK_D)
   {
      data_ptr.SRR_FL_HEADER_001.HED_DET_RANGE_MAX       = k_detection_range_max_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_FL_HEADER_001.HED_DET_RANGE_MIN       = k_detection_range_min_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_FL_HEADER_001.HED_DET_SPEED_RANGE_MAX = k_detection_range_rate_max_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_FL_HEADER_001.HED_DET_SPEED_RANGE_MIN = k_detection_range_rate_min_smc[(uint8_t)hdr_look_type];
   }
   else
   {
      data_ptr.SRR_FL_HEADER_001.HED_DET_RANGE_MAX       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.SRR_FL_HEADER_001.HED_DET_RANGE_MIN       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.SRR_FL_HEADER_001.HED_DET_SPEED_RANGE_MAX = Init_Fixed_Point(0, s7p8_T);
      data_ptr.SRR_FL_HEADER_001.HED_DET_SPEED_RANGE_MIN = Init_Fixed_Point(0, s7p8_T);
   }

   // SRR_FL_STATUS_001
   data_ptr.SRR_FL_STATUS_001.STS_MH_001_CYCLE_COUNTER     = 0;
   data_ptr.SRR_FL_STATUS_001.STS_MH_001_CRC16             = 0;
   data_ptr.SRR_FL_STATUS_001.STS_USC_CAL_VER_MAJOR        = Get_USC_Cal_Major();
   data_ptr.SRR_FL_STATUS_001.STS_USC_CAL_VER_MINOR        = Get_USC_Cal_Minor();
   data_ptr.SRR_FL_STATUS_001.STS_USC_SECTION_COMPTBLITY   = Get_USC_Cal_Major();
   data_ptr.SRR_FL_STATUS_001.STS_SMC_CAL_VER_MAJOR        = Get_SMC_Cal_Major();
   data_ptr.SRR_FL_STATUS_001.STS_SMC_CAL_VER_MINOR        = Get_SMC_Cal_Minor();
   data_ptr.SRR_FL_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = Get_SMC_Cal_Major();
   data_ptr.SRR_FL_STATUS_001.STS_SMC_PLATFROM_VERSION     = Get_SMC_Cal_Platform();
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_POSITION          = Get_Radar_Position();
   data_ptr.SRR_FL_STATUS_001.STS_HARDWARE_VERSION         = status_stream_ptr->app_version_Info.board_type;
   data_ptr.SRR_FL_STATUS_001.STS_PCAN_PROTOCOL_VER_MAJOR  = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.SRR_FL_STATUS_001.STS_PCAN_PROTOCOL_VER_MINOR  = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.SRR_FL_STATUS_001.STS_PLATFORM_VARIANT         = Get_SMC_Cal_Platform();
   data_ptr.SRR_FL_STATUS_001.STS_SERIAL_NUM_JULIAN_DAY    = k_Julian_Production_Date_USC;
   data_ptr.SRR_FL_STATUS_001.STS_SERIAL_NUM_JULIAN_YEAR   = k_Julian_Year_USC;
   data_ptr.SRR_FL_STATUS_001.STS_SERIAL_NUMBER_SEQUENCE   = k_Mfg_Sequence_Number_USC;
   data_ptr.SRR_FL_STATUS_001.STS_SW_VERSION_FIELD1        = status_stream_ptr->app_version_Info.appl_variant;
   data_ptr.SRR_FL_STATUS_001.STS_SW_VERSION_FIELD2        = status_stream_ptr->app_version_Info.major_release_revision;
   data_ptr.SRR_FL_STATUS_001.STS_SW_VERSION_FIELD3        = status_stream_ptr->app_version_Info.minor_release_revision;
   data_ptr.SRR_FL_STATUS_001.STS_SW_VERSION_FIELD4        = status_stream_ptr->app_version_Info.patch_release_revision;
   data_ptr.SRR_FL_STATUS_001.STS_PBL_VERSION_FIELD1       = status_stream_ptr->pbl_version_maj;
   data_ptr.SRR_FL_STATUS_001.STS_PBL_VERSION_FIELD2       = status_stream_ptr->pbl_version_min;
   data_ptr.SRR_FL_STATUS_001.STS_PBL_VERSION_FIELD3       = status_stream_ptr->pbl_version_patch;
   data_ptr.SRR_FL_STATUS_001.STS_PBL_VERSION_FIELD4       = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_ORNT_YAW    = *k_sensor_mount_ornt_yaw_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_POLARITY          = 0;
   data_ptr.SRR_FL_STATUS_001.STS_DIST_FRNT_BMPR_TO_RR_AXL = 0;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_ORNT_PITCH  = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_ORNT_ROLL   = *k_sensor_mount_ornt_roll_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_POS_X       = *k_sensor_mount_pos_x_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_POS_Y       = *k_sensor_mount_pos_y_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_MOUNT_POS_Z       = *k_sensor_mount_pos_z_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_SENSOR_HEIGHT            = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.SRR_FL_STATUS_001.STS_DET_DBC_BASE_VER_MAJOR   = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.SRR_FL_STATUS_001.STS_DET_DBC_BASE_VER_MINOR   = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.SRR_FL_STATUS_001.STS_TIME_SINCE_POWER_ON      = 0;
   data_ptr.SRR_FL_STATUS_001.STS_AF_TIME_PEAK             = 0;
   data_ptr.SRR_FL_STATUS_001.STS_AF_TIME_INST             = 0;
   data_ptr.SRR_FL_STATUS_001.STS_MAIN_CORE_TIME_INST      = 0;
   data_ptr.SRR_FL_STATUS_001.STS_MAIN_CORE_TIME_PEAK      = 0;
   data_ptr.SRR_FL_STATUS_001.STS_RDD_CORE_TIME_INST       = 0;
   data_ptr.SRR_FL_STATUS_001.STS_RDD_CORE_TIME_PEAK       = 0;
   data_ptr.SRR_FL_STATUS_001.STS_SP_CORE_TIME_INST        = 0;
   data_ptr.SRR_FL_STATUS_001.STS_SP_CORE_TIME_PEAK        = 0;
   data_ptr.SRR_FL_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = 0;

   // SRR_FL_STATUS_002
   data_ptr.SRR_FL_STATUS_002.STS_MH_002_CYCLE_COUNTER   = 0;
   data_ptr.SRR_FL_STATUS_002.STS_MH_002_CRC16           = 0;
   data_ptr.SRR_FL_STATUS_002.STS_VEHICLE_SUPPLY_VOLTAGE = 0; // need to check
   data_ptr.SRR_FL_STATUS_002.STS_YAW_RATE_BIAS          = ipc_m2d->payload.veh_data.vse_output.yaw_rate_bias;
   data_ptr.SRR_FL_STATUS_002.STS_STEERING_ANGLE         = ipc_m2d->payload.veh_data.vse_output.comp_steering_angle_deg;

   if (!(ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_OUT) &&
       (ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_BASE))
   {
      data_ptr.SRR_FL_STATUS_002.STS_NO_TSYN_ERROR = 1;
   }
   else
   {
      data_ptr.SRR_FL_STATUS_002.STS_NO_TSYN_ERROR = 0;
   }

   data_ptr.SRR_FL_STATUS_002.STS_BRR_STATUS         = 0; // need to be checked
   data_ptr.SRR_FL_STATUS_002.STS_XCVR_OPERATIONAL   = 0; // need to be checked
   data_ptr.SRR_FL_STATUS_002.STS_MMIC_RE_INIT_COUNT = 0;
   data_ptr.SRR_FL_STATUS_002.STS_POINT_OF_TRIGGER   = CAN_SIG_NOT_IMPLEMENTED;
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_FL_STATUS_002.STS_SCAN_TYPE = ipc_d2m->payload.downselection_data.det_list_property.look_type;
#else
   data_ptr.SRR_FL_STATUS_002.STS_SCAN_TYPE               = ipc_d2m->payload.det_data.det_list_property.look_type;
#endif
   data_ptr.SRR_FL_STATUS_002.STS_Gear_Position             = 0;
   data_ptr.SRR_FL_STATUS_002.STS_CAN_NM_State              = 0;
   data_ptr.SRR_FL_STATUS_002.STS_MMIC_TEMP_TX1_2           = 0; // status_stream_ptr->mmic_temp_rx1;// need to checked
   data_ptr.SRR_FL_STATUS_002.STS_MMIC_TEMP_TX3_4           = 0; // status_stream_ptr->mmic_temp_tx1;// need to checked
   data_ptr.SRR_FL_STATUS_002.STS_MCU_TEMP                  = 0;
   data_ptr.SRR_FL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_4_to_7 = 0;
   data_ptr.SRR_FL_STATUS_002.STS_AF_CORE_THROUGHPUT        = 0;
   data_ptr.SRR_FL_STATUS_002.STS_Vehicle_Speed_Calc_QF     = 0;
   data_ptr.SRR_FL_STATUS_002.STS_RDD_CORE_THROUGHPUT       = 0;
   data_ptr.SRR_FL_STATUS_002.STS_Yaw_Rate_Calc_QF          = 0;
   data_ptr.SRR_FL_STATUS_002.STS_MMIC_TEMP_RX              = 0; // need to checked
   data_ptr.SRR_FL_STATUS_002.STS_TIME_SYNC_OFFSET          = 0;
   data_ptr.SRR_FL_STATUS_002.STS_MMIC_TEMP_TX0             = 0;
   data_ptr.SRR_FL_STATUS_002.STS_STEERING_ANGLE_SIGN       = 0; // ipc_m2d->payload.veh_data.veh_params.veh_steering_sign_status;
   data_ptr.SRR_FL_STATUS_002.STS_VEH_SPEED_DIRECTION = 0; //(ipc_m2d->payload.veh_data.veh_params.lros_drive_reverse) ? 1 : 0;
   data_ptr.SRR_FL_STATUS_002.STS_VEHICLE_SPEED_CALC  = 0; // ipc_m2d->payload.veh_data.veh_params.veh_speed;
   data_ptr.SRR_FL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_0_to_3    = 0;
   data_ptr.SRR_FL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_8_to_11   = 0;
   data_ptr.SRR_FL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_11_to_15  = 0;
   data_ptr.SRR_FL_STATUS_002.STS_Project_ACTV_FLT_BYTE_0_to_3 = 0;
   data_ptr.SRR_FL_STATUS_002.STS_Project_ACTV_FLT_BYTE_4_to_5 = 0;
   data_ptr.SRR_FL_STATUS_002.STS_Last_CAN_Det_Inst_Latency    = 0;
   data_ptr.SRR_FL_STATUS_002.STS_First_CAN_Det_Inst_Latency   = 0;
   data_ptr.SRR_FL_STATUS_002.STS_RAIN_COUNT                   = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_STATUS_002.STS_INTRFC_VERSION_ID_MAJOR      = 0;
   data_ptr.SRR_FL_STATUS_002.STS_INTRFC_VERSION_ID_MINOR      = 0;
   data_ptr.SRR_FL_STATUS_002.STS_INTRFC_VERSION_ID_PATCH      = 0;

   // SRR_FL_ALIGNMENT_STATUS_001
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.AL_STS_001_MH_CRC16      = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.AL_STS_001_CYCLE_COUNTER = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AAAzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AACurrentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AACurrentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AAElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentAutoStatus = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentError = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentModeIn =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AlignmentModeOut =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AutoAlignmentFailRootCause = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AzimuthErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_az;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AzimuthErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_az;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_AzimuthUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_CalDisplay = 1;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_CalTime    = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_CoordinateSystemInput =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.detection_coordinate_system;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_ElevationErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_el;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_ElevationErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_el;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_ElevationUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_HostSpdCompensationFactorQF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_HostSpeedCompensationFactor =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitAlignmentResultElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitAlignmentResultAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitAlignResultAzimuthUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_ElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitAlignRsltElevationUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitAlignRsltHostSpdCompFac =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_StartAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   uint8_t Complete_Percent_Az =
      (uint8_t)ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_az;
   uint8_t Complete_Percent_El =
      (uint8_t)ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_el;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_ProgressPercent = (uint8_t)((Complete_Percent_Az + Complete_Percent_El) / 2U);
   data_ptr.SRR_FL_ALIGNMENT_STATUS_001.STS_InitLastSuccessfulAlignMode = 0;

   // SRR_FL_ALIGNMENT_STATUS_002
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_AlignmentServiceStatus = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_ImpactByInterference   = 0; // TODO: check what to be filled
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_AlignmentStaticStatus  = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_Measured_Range =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_range;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_MeasuredRangeStd =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_range;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_MeasuredRangeRate =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_r_dot;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_MeasuredRangeRateStd =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_MeasuredRawAmplitude =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_rcs;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_MeasuredAmpSTD =
      0; // ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_AlignmentShortTrackStatus = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_VehicleCondition          = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_DistanceAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_since_start;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_AverageNumberOfDetections = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_DistanceEffective =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el >
            (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf) ?
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el) :
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf);
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_DurationAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_since_start;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_AverageSpeed =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.avg_spd_since_start;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.STS_DurationEffective =
      (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el >
       ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf) ?
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el) :
         (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf);
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.AL_STS_002_MH_CRC16      = 0;
   data_ptr.SRR_FL_ALIGNMENT_STATUS_002.AL_STS_002_CYCLE_COUNTER = 0;

   // FLR_CAPABILITY
   data_ptr.FLR_CAPABILITY.CAP_FreeSightCheckActive  = ipc_d2m->payload.radar_capability_data.fsc.run_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageStatus        = ipc_d2m->payload.radar_capability_data.blockage.blockage_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageActive        = ipc_d2m->payload.radar_capability_data.blockage.blockage_active;
   data_ptr.FLR_CAPABILITY.CAP_BlockageSensitivity   = ipc_d2m->payload.radar_capability_data.sensitivity_level;
   data_ptr.FLR_CAPABILITY.CAP_DampingStatus         = ipc_d2m->payload.radar_capability_data.dm.dm_status;
   data_ptr.FLR_CAPABILITY.CAP_FreeSightCheckStatus  = ipc_d2m->payload.radar_capability_data.fsc.fault_status;
   data_ptr.FLR_CAPABILITY.CAP_BlockageValue         = ipc_d2m->payload.radar_capability_data.blockage.blockage.value;
   data_ptr.FLR_CAPABILITY.CAP_DampingActive         = ipc_d2m->payload.radar_capability_data.dm.dm_active;
   data_ptr.FLR_CAPABILITY.CAP_BlockageProbability   = ipc_d2m->payload.radar_capability_data.blockage.blockage.probability;
   data_ptr.FLR_CAPABILITY.CAP_RangeEstimationActive = ipc_d2m->payload.radar_capability_data.re.re_active;
   data_ptr.FLR_CAPABILITY.CAP_SLBlockageFilterValue = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_CAPABILITY.CAP_SLBlockageFlag        = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.FLR_CAPABILITY.CAP_DampingCurrent        = ipc_d2m->payload.radar_capability_data.dm.damping.current_dB;
   data_ptr.FLR_CAPABILITY.CAP_DampingStandardDeviation =
      Float2Fix(ipc_d2m->payload.radar_capability_data.dm.damping.std_dB, u8p0_T);
   data_ptr.FLR_CAPABILITY.CAP_SLLMonitoringStatus   = ipc_d2m->payload.radar_capability_data.pbd.status;
   data_ptr.FLR_CAPABILITY.CAP_SLLMonitoringActive   = ipc_d2m->payload.radar_capability_data.pbd.pbd_active;
   data_ptr.FLR_CAPABILITY.CAP_RangeEstimationStatus = ipc_d2m->payload.radar_capability_data.re.re_status;
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetectionRangeCar_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangeMotorbike_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[0], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[1], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_MaxDetRangePedestrian_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[2], u16p0_T);
   data_ptr.FLR_CAPABILITY.CAP_AngleAzimuthRangeStart =
      Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_begin_rad[0], s15p0_T);
   data_ptr.FLR_CAPABILITY.CAP_AngleAzimuthRangeEnd = Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_end_rad[0], s15p0_T);
   data_ptr.FLR_CAPABILITY.CAP_SideLobeLevelBeamformer = ipc_d2m->payload.radar_capability_data.pbd.az_sector[0].side_lobe_level;
   data_ptr.FLR_CAPABILITY.CAP_MH_CRC16                = 0;
   data_ptr.FLR_CAPABILITY.CAP_CYCLE_COUNTER           = 0;

   // SRR_FL_DETECTION_001_004_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_001 = af_target_report_ptr[0].ran;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_002 = af_target_report_ptr[1].ran;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_003 = af_target_report_ptr[2].ran;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_004 = af_target_report_ptr[3].ran;

   data_ptr.SRR_FL_DETECTION_001_004.DET_AZIMUTH_001 = af_target_report_ptr[0].theta;
   data_ptr.SRR_FL_DETECTION_001_004.DET_AZIMUTH_002 = af_target_report_ptr[1].theta;
   data_ptr.SRR_FL_DETECTION_001_004.DET_AZIMUTH_003 = af_target_report_ptr[2].theta;
   data_ptr.SRR_FL_DETECTION_001_004.DET_AZIMUTH_004 = af_target_report_ptr[3].theta;

   data_ptr.SRR_FL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_001 = 0;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_002 = 0;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_003 = 0;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_004 = 0;

   data_ptr.SRR_FL_DETECTION_001_004.DET_BI_STATIC_FLAG_004 = af_target_report_ptr[3].f_bistatic;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BI_STATIC_FLAG_003 = af_target_report_ptr[2].f_bistatic;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BI_STATIC_FLAG_002 = af_target_report_ptr[1].f_bistatic;
   data_ptr.SRR_FL_DETECTION_001_004.DET_BI_STATIC_FLAG_001 = af_target_report_ptr[0].f_bistatic;

   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_AZIMUTH_001 = af_target_report_ptr[0].az_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_AZIMUTH_002 = af_target_report_ptr[1].az_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_AZIMUTH_003 = af_target_report_ptr[2].az_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_AZIMUTH_004 = af_target_report_ptr[3].az_conf;

   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_001 = af_target_report_ptr[0].phi;
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_002 = af_target_report_ptr[1].phi;
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_003 = af_target_report_ptr[2].phi;
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_004 = af_target_report_ptr[3].phi;

   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_ELEVATION_001 = af_target_report_ptr[0].el_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_ELEVATION_002 = af_target_report_ptr[1].el_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_ELEVATION_003 = af_target_report_ptr[2].el_conf;
   data_ptr.SRR_FL_DETECTION_001_004.DET_CONFD_ELEVATION_004 = af_target_report_ptr[3].el_conf;

   data_ptr.SRR_FL_DETECTION_001_004.DET_EXISTENCE_PROB_001 = TOI_DS_Stream_Ptr->existence_prob[0];
   data_ptr.SRR_FL_DETECTION_001_004.DET_EXISTENCE_PROB_002 = TOI_DS_Stream_Ptr->existence_prob[1];
   data_ptr.SRR_FL_DETECTION_001_004.DET_EXISTENCE_PROB_003 = TOI_DS_Stream_Ptr->existence_prob[2];
   data_ptr.SRR_FL_DETECTION_001_004.DET_EXISTENCE_PROB_004 = TOI_DS_Stream_Ptr->existence_prob[3];

   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_ERR_001 = TOI_DS_Stream_Ptr->std_phi[0];
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_ERR_002 = TOI_DS_Stream_Ptr->std_phi[1];
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_ERR_003 = TOI_DS_Stream_Ptr->std_phi[2];
   data_ptr.SRR_FL_DETECTION_001_004.DET_ELEVATION_ERR_004 = TOI_DS_Stream_Ptr->std_phi[3];

   data_ptr.SRR_FL_DETECTION_001_004.DET_HVC_FLAG_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_HVC_FLAG_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_HVC_FLAG_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_HVC_FLAG_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_001_004.DET_IDM_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_IDM_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_IDM_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_IDM_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_001_004.DET_MH_CYCLE_COUNTER_001_004   = 0;
   data_ptr.SRR_FL_DETECTION_001_004.DET_MH_CRC16_001_004           = 0;
   data_ptr.SRR_FL_DETECTION_001_004.DET_MH_SCAN_INDEX_4LSB_001_004 = 0;

   data_ptr.SRR_FL_DETECTION_001_004.DET_MTD_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_MTD_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_MTD_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_MTD_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_001_004.DET_PROB_1STAZHYPO_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_PROB_1STAZHYPO_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_PROB_1STAZHYPO_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_001_004.DET_PROB_1STAZHYPO_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_ERR_001 = TOI_DS_Stream_Ptr->std_ran[0];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_ERR_002 = TOI_DS_Stream_Ptr->std_ran[1];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_ERR_003 = TOI_DS_Stream_Ptr->std_ran[2];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_ERR_004 = TOI_DS_Stream_Ptr->std_ran[3];

   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_001 = af_target_report_ptr[0].vel;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_002 = af_target_report_ptr[1].vel;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_003 = af_target_report_ptr[2].vel;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_004 = af_target_report_ptr[3].vel;

   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_001 = TOI_DS_Stream_Ptr->std_vel[0];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_002 = TOI_DS_Stream_Ptr->std_vel[1];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_003 = TOI_DS_Stream_Ptr->std_vel[2];
   data_ptr.SRR_FL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_004 = TOI_DS_Stream_Ptr->std_vel[3];

   data_ptr.SRR_FL_DETECTION_001_004.DET_RCS_001 = af_target_report_ptr[0].rcs;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RCS_002 = af_target_report_ptr[1].rcs;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RCS_003 = af_target_report_ptr[2].rcs;
   data_ptr.SRR_FL_DETECTION_001_004.DET_RCS_004 = af_target_report_ptr[3].rcs;

   data_ptr.SRR_FL_DETECTION_001_004.DET_SNR_001 = af_target_report_ptr[0].snr;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SNR_002 = af_target_report_ptr[1].snr;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SNR_003 = af_target_report_ptr[2].snr;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SNR_004 = af_target_report_ptr[3].snr;

   data_ptr.SRR_FL_DETECTION_001_004.DET_SUPER_RES_TARGET_001 = af_target_report_ptr[0].f_superres_target;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SUPER_RES_TARGET_002 = af_target_report_ptr[1].f_superres_target;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SUPER_RES_TARGET_003 = af_target_report_ptr[2].f_superres_target;
   data_ptr.SRR_FL_DETECTION_001_004.DET_SUPER_RES_TARGET_004 = af_target_report_ptr[3].f_superres_target;

   // SRR_FL_DETECTION_005_008_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_005 = af_target_report_ptr[4].ran;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_006 = af_target_report_ptr[5].ran;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_007 = af_target_report_ptr[6].ran;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_008 = af_target_report_ptr[7].ran;

   data_ptr.SRR_FL_DETECTION_005_008.DET_AZIMUTH_005 = af_target_report_ptr[4].theta;
   data_ptr.SRR_FL_DETECTION_005_008.DET_AZIMUTH_006 = af_target_report_ptr[5].theta;
   data_ptr.SRR_FL_DETECTION_005_008.DET_AZIMUTH_007 = af_target_report_ptr[6].theta;
   data_ptr.SRR_FL_DETECTION_005_008.DET_AZIMUTH_008 = af_target_report_ptr[7].theta;

   data_ptr.SRR_FL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_005 = 0;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_006 = 0;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_007 = 0;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_008 = 0;

   data_ptr.SRR_FL_DETECTION_005_008.DET_BI_STATIC_FLAG_005 = af_target_report_ptr[4].f_bistatic;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BI_STATIC_FLAG_006 = af_target_report_ptr[5].f_bistatic;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BI_STATIC_FLAG_007 = af_target_report_ptr[6].f_bistatic;
   data_ptr.SRR_FL_DETECTION_005_008.DET_BI_STATIC_FLAG_008 = af_target_report_ptr[7].f_bistatic;

   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_AZIMUTH_005 = af_target_report_ptr[4].az_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_AZIMUTH_006 = af_target_report_ptr[5].az_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_AZIMUTH_007 = af_target_report_ptr[6].az_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_AZIMUTH_008 = af_target_report_ptr[7].az_conf;

   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_005 = af_target_report_ptr[4].phi;
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_006 = af_target_report_ptr[5].phi;
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_007 = af_target_report_ptr[6].phi;
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_008 = af_target_report_ptr[7].phi;

   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_ELEVATION_005 = af_target_report_ptr[4].el_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_ELEVATION_006 = af_target_report_ptr[5].el_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_ELEVATION_007 = af_target_report_ptr[6].el_conf;
   data_ptr.SRR_FL_DETECTION_005_008.DET_CONFD_ELEVATION_008 = af_target_report_ptr[7].el_conf;

   data_ptr.SRR_FL_DETECTION_005_008.DET_EXISTENCE_PROB_005 = TOI_DS_Stream_Ptr->existence_prob[4];
   data_ptr.SRR_FL_DETECTION_005_008.DET_EXISTENCE_PROB_006 = TOI_DS_Stream_Ptr->existence_prob[5];
   data_ptr.SRR_FL_DETECTION_005_008.DET_EXISTENCE_PROB_007 = TOI_DS_Stream_Ptr->existence_prob[6];
   data_ptr.SRR_FL_DETECTION_005_008.DET_EXISTENCE_PROB_008 = TOI_DS_Stream_Ptr->existence_prob[7];

   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_ERR_005 = TOI_DS_Stream_Ptr->std_phi[4];
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_ERR_006 = TOI_DS_Stream_Ptr->std_phi[5];
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_ERR_007 = TOI_DS_Stream_Ptr->std_phi[6];
   data_ptr.SRR_FL_DETECTION_005_008.DET_ELEVATION_ERR_008 = TOI_DS_Stream_Ptr->std_phi[7];

   data_ptr.SRR_FL_DETECTION_005_008.DET_HVC_FLAG_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_HVC_FLAG_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_HVC_FLAG_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_HVC_FLAG_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_005_008.DET_IDM_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_IDM_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_IDM_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_IDM_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_005_008.DET_MH_CYCLE_COUNTER_005_008   = 0;
   data_ptr.SRR_FL_DETECTION_005_008.DET_MH_CRC16_005_008           = 0;
   data_ptr.SRR_FL_DETECTION_005_008.DET_MH_SCAN_INDEX_4LSB_005_008 = 0;

   data_ptr.SRR_FL_DETECTION_005_008.DET_MTD_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_MTD_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_MTD_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_MTD_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_005_008.DET_PROB_1STAZHYPO_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_PROB_1STAZHYPO_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_PROB_1STAZHYPO_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_005_008.DET_PROB_1STAZHYPO_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_ERR_005 = TOI_DS_Stream_Ptr->std_ran[4];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_ERR_006 = TOI_DS_Stream_Ptr->std_ran[5];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_ERR_007 = TOI_DS_Stream_Ptr->std_ran[6];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_ERR_008 = TOI_DS_Stream_Ptr->std_ran[7];

   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_005 = af_target_report_ptr[4].vel;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_006 = af_target_report_ptr[5].vel;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_007 = af_target_report_ptr[6].vel;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_008 = af_target_report_ptr[7].vel;

   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_005 = TOI_DS_Stream_Ptr->std_vel[4];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_006 = TOI_DS_Stream_Ptr->std_vel[5];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_007 = TOI_DS_Stream_Ptr->std_vel[6];
   data_ptr.SRR_FL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_008 = TOI_DS_Stream_Ptr->std_vel[7];

   data_ptr.SRR_FL_DETECTION_005_008.DET_RCS_005 = af_target_report_ptr[4].rcs;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RCS_006 = af_target_report_ptr[5].rcs;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RCS_007 = af_target_report_ptr[6].rcs;
   data_ptr.SRR_FL_DETECTION_005_008.DET_RCS_008 = af_target_report_ptr[7].rcs;

   data_ptr.SRR_FL_DETECTION_005_008.DET_SNR_005 = af_target_report_ptr[4].snr;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SNR_006 = af_target_report_ptr[5].snr;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SNR_007 = af_target_report_ptr[6].snr;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SNR_008 = af_target_report_ptr[7].snr;

   data_ptr.SRR_FL_DETECTION_005_008.DET_SUPER_RES_TARGET_005 = af_target_report_ptr[4].f_superres_target;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SUPER_RES_TARGET_006 = af_target_report_ptr[5].f_superres_target;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SUPER_RES_TARGET_007 = af_target_report_ptr[6].f_superres_target;
   data_ptr.SRR_FL_DETECTION_005_008.DET_SUPER_RES_TARGET_008 = af_target_report_ptr[7].f_superres_target;

   // SRR_FL_DETECTION_009_012_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_009 = af_target_report_ptr[8].ran;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_010 = af_target_report_ptr[9].ran;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_011 = af_target_report_ptr[10].ran;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_012 = af_target_report_ptr[11].ran;

   data_ptr.SRR_FL_DETECTION_009_012.DET_AZIMUTH_009 = af_target_report_ptr[8].theta;
   data_ptr.SRR_FL_DETECTION_009_012.DET_AZIMUTH_010 = af_target_report_ptr[9].theta;
   data_ptr.SRR_FL_DETECTION_009_012.DET_AZIMUTH_011 = af_target_report_ptr[10].theta;
   data_ptr.SRR_FL_DETECTION_009_012.DET_AZIMUTH_012 = af_target_report_ptr[11].theta;

   data_ptr.SRR_FL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_009 = 0;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_010 = 0;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_011 = 0;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_012 = 0;

   data_ptr.SRR_FL_DETECTION_009_012.DET_BI_STATIC_FLAG_009 = af_target_report_ptr[8].f_bistatic;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BI_STATIC_FLAG_010 = af_target_report_ptr[9].f_bistatic;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BI_STATIC_FLAG_011 = af_target_report_ptr[10].f_bistatic;
   data_ptr.SRR_FL_DETECTION_009_012.DET_BI_STATIC_FLAG_012 = af_target_report_ptr[11].f_bistatic;

   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_AZIMUTH_009 = af_target_report_ptr[8].az_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_AZIMUTH_010 = af_target_report_ptr[9].az_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_AZIMUTH_011 = af_target_report_ptr[10].az_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_AZIMUTH_012 = af_target_report_ptr[11].az_conf;

   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_009 = af_target_report_ptr[8].phi;
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_010 = af_target_report_ptr[9].phi;
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_011 = af_target_report_ptr[10].phi;
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_012 = af_target_report_ptr[11].phi;

   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_ELEVATION_009 = af_target_report_ptr[8].el_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_ELEVATION_010 = af_target_report_ptr[9].el_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_ELEVATION_011 = af_target_report_ptr[10].el_conf;
   data_ptr.SRR_FL_DETECTION_009_012.DET_CONFD_ELEVATION_012 = af_target_report_ptr[11].el_conf;

   data_ptr.SRR_FL_DETECTION_009_012.DET_EXISTENCE_PROB_009 = TOI_DS_Stream_Ptr->existence_prob[8];
   data_ptr.SRR_FL_DETECTION_009_012.DET_EXISTENCE_PROB_010 = TOI_DS_Stream_Ptr->existence_prob[9];
   data_ptr.SRR_FL_DETECTION_009_012.DET_EXISTENCE_PROB_011 = TOI_DS_Stream_Ptr->existence_prob[10];
   data_ptr.SRR_FL_DETECTION_009_012.DET_EXISTENCE_PROB_012 = TOI_DS_Stream_Ptr->existence_prob[11];

   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_ERR_009 = TOI_DS_Stream_Ptr->std_phi[8];
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_ERR_010 = TOI_DS_Stream_Ptr->std_phi[9];
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_ERR_011 = TOI_DS_Stream_Ptr->std_phi[10];
   data_ptr.SRR_FL_DETECTION_009_012.DET_ELEVATION_ERR_012 = TOI_DS_Stream_Ptr->std_phi[11];

   data_ptr.SRR_FL_DETECTION_009_012.DET_HVC_FLAG_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_HVC_FLAG_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_HVC_FLAG_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_HVC_FLAG_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_009_012.DET_IDM_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_IDM_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_IDM_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_IDM_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_009_012.DET_MH_CYCLE_COUNTER_009_012   = 0;
   data_ptr.SRR_FL_DETECTION_009_012.DET_MH_CRC16_009_012           = 0;
   data_ptr.SRR_FL_DETECTION_009_012.DET_MH_SCAN_INDEX_4LSB_009_012 = 0;

   data_ptr.SRR_FL_DETECTION_009_012.DET_MTD_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_MTD_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_MTD_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_MTD_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_009_012.DET_PROB_1STAZHYPO_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_PROB_1STAZHYPO_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_PROB_1STAZHYPO_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_009_012.DET_PROB_1STAZHYPO_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_ERR_009 = TOI_DS_Stream_Ptr->std_ran[8];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_ERR_010 = TOI_DS_Stream_Ptr->std_ran[9];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_ERR_011 = TOI_DS_Stream_Ptr->std_ran[10];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_ERR_012 = TOI_DS_Stream_Ptr->std_ran[11];

   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_009 = af_target_report_ptr[8].vel;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_010 = af_target_report_ptr[9].vel;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_011 = af_target_report_ptr[10].vel;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_012 = af_target_report_ptr[11].vel;

   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_009 = TOI_DS_Stream_Ptr->std_vel[8];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_010 = TOI_DS_Stream_Ptr->std_vel[9];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_011 = TOI_DS_Stream_Ptr->std_vel[10];
   data_ptr.SRR_FL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_012 = TOI_DS_Stream_Ptr->std_vel[11];

   data_ptr.SRR_FL_DETECTION_009_012.DET_RCS_009 = af_target_report_ptr[8].rcs;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RCS_010 = af_target_report_ptr[9].rcs;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RCS_011 = af_target_report_ptr[10].rcs;
   data_ptr.SRR_FL_DETECTION_009_012.DET_RCS_012 = af_target_report_ptr[11].rcs;

   data_ptr.SRR_FL_DETECTION_009_012.DET_SNR_009 = af_target_report_ptr[8].snr;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SNR_010 = af_target_report_ptr[9].snr;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SNR_011 = af_target_report_ptr[10].snr;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SNR_012 = af_target_report_ptr[11].snr;

   data_ptr.SRR_FL_DETECTION_009_012.DET_SUPER_RES_TARGET_009 = af_target_report_ptr[8].f_superres_target;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SUPER_RES_TARGET_010 = af_target_report_ptr[9].f_superres_target;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SUPER_RES_TARGET_011 = af_target_report_ptr[10].f_superres_target;
   data_ptr.SRR_FL_DETECTION_009_012.DET_SUPER_RES_TARGET_012 = af_target_report_ptr[11].f_superres_target;

   // SRR_FL_DETECTION_013_016_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_013 = af_target_report_ptr[12].ran;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_014 = af_target_report_ptr[13].ran;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_015 = af_target_report_ptr[14].ran;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_016 = af_target_report_ptr[15].ran;

   data_ptr.SRR_FL_DETECTION_013_016.DET_AZIMUTH_013 = af_target_report_ptr[12].theta;
   data_ptr.SRR_FL_DETECTION_013_016.DET_AZIMUTH_014 = af_target_report_ptr[13].theta;
   data_ptr.SRR_FL_DETECTION_013_016.DET_AZIMUTH_015 = af_target_report_ptr[14].theta;
   data_ptr.SRR_FL_DETECTION_013_016.DET_AZIMUTH_016 = af_target_report_ptr[15].theta;

   data_ptr.SRR_FL_DETECTION_013_016.DET_BI_STATIC_FLAG_013 = af_target_report_ptr[12].f_bistatic;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BI_STATIC_FLAG_014 = af_target_report_ptr[13].f_bistatic;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BI_STATIC_FLAG_015 = af_target_report_ptr[14].f_bistatic;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BI_STATIC_FLAG_016 = af_target_report_ptr[15].f_bistatic;

   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_AZIMUTH_013 = af_target_report_ptr[12].az_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_AZIMUTH_014 = af_target_report_ptr[13].az_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_AZIMUTH_015 = af_target_report_ptr[14].az_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_AZIMUTH_016 = af_target_report_ptr[15].az_conf;

   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_013 = af_target_report_ptr[12].phi;
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_014 = af_target_report_ptr[13].phi;
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_015 = af_target_report_ptr[14].phi;
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_016 = af_target_report_ptr[15].phi;

   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_ELEVATION_013 = af_target_report_ptr[12].el_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_ELEVATION_014 = af_target_report_ptr[13].el_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_ELEVATION_015 = af_target_report_ptr[14].el_conf;
   data_ptr.SRR_FL_DETECTION_013_016.DET_CONFD_ELEVATION_016 = af_target_report_ptr[15].el_conf;

   data_ptr.SRR_FL_DETECTION_013_016.DET_EXISTENCE_PROB_013 = TOI_DS_Stream_Ptr->existence_prob[12];
   data_ptr.SRR_FL_DETECTION_013_016.DET_EXISTENCE_PROB_014 = TOI_DS_Stream_Ptr->existence_prob[13];
   data_ptr.SRR_FL_DETECTION_013_016.DET_EXISTENCE_PROB_015 = TOI_DS_Stream_Ptr->existence_prob[14];
   data_ptr.SRR_FL_DETECTION_013_016.DET_EXISTENCE_PROB_016 = TOI_DS_Stream_Ptr->existence_prob[15];

   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_ERR_013 = TOI_DS_Stream_Ptr->std_phi[12];
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_ERR_014 = TOI_DS_Stream_Ptr->std_phi[13];
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_ERR_015 = TOI_DS_Stream_Ptr->std_phi[14];
   data_ptr.SRR_FL_DETECTION_013_016.DET_ELEVATION_ERR_016 = TOI_DS_Stream_Ptr->std_phi[15];

   data_ptr.SRR_FL_DETECTION_013_016.DET_IDM_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_IDM_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_IDM_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_IDM_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_013_016.DET_MTD_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_MTD_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_MTD_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_MTD_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_013_016.DET_PROB_1STAZHYPO_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_PROB_1STAZHYPO_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_PROB_1STAZHYPO_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_PROB_1STAZHYPO_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_ERR_013 = TOI_DS_Stream_Ptr->std_ran[12];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_ERR_014 = TOI_DS_Stream_Ptr->std_ran[13];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_ERR_015 = TOI_DS_Stream_Ptr->std_ran[14];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_ERR_016 = TOI_DS_Stream_Ptr->std_ran[15];

   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_013 = af_target_report_ptr[12].vel;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_014 = af_target_report_ptr[13].vel;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_015 = af_target_report_ptr[14].vel;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_016 = af_target_report_ptr[15].vel;

   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_013 = TOI_DS_Stream_Ptr->std_vel[12];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_014 = TOI_DS_Stream_Ptr->std_vel[13];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_015 = TOI_DS_Stream_Ptr->std_vel[14];
   data_ptr.SRR_FL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_016 = TOI_DS_Stream_Ptr->std_vel[15];

   data_ptr.SRR_FL_DETECTION_013_016.DET_RCS_013 = af_target_report_ptr[12].rcs;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RCS_014 = af_target_report_ptr[13].rcs;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RCS_015 = af_target_report_ptr[14].rcs;
   data_ptr.SRR_FL_DETECTION_013_016.DET_RCS_016 = af_target_report_ptr[15].rcs;

   data_ptr.SRR_FL_DETECTION_013_016.DET_SNR_013 = af_target_report_ptr[12].snr;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SNR_014 = af_target_report_ptr[13].snr;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SNR_015 = af_target_report_ptr[14].snr;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SNR_016 = af_target_report_ptr[15].snr;

   data_ptr.SRR_FL_DETECTION_013_016.DET_SUPER_RES_TARGET_013 = af_target_report_ptr[12].f_superres_target;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SUPER_RES_TARGET_014 = af_target_report_ptr[13].f_superres_target;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SUPER_RES_TARGET_015 = af_target_report_ptr[14].f_superres_target;
   data_ptr.SRR_FL_DETECTION_013_016.DET_SUPER_RES_TARGET_016 = af_target_report_ptr[15].f_superres_target;

   data_ptr.SRR_FL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_013 = 0;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_014 = 0;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_015 = 0;
   data_ptr.SRR_FL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_016 = 0;

   data_ptr.SRR_FL_DETECTION_013_016.DET_HVC_FLAG_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_HVC_FLAG_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_HVC_FLAG_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_013_016.DET_HVC_FLAG_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_013_016.DET_MH_CYCLE_COUNTER_013_016   = 0;
   data_ptr.SRR_FL_DETECTION_013_016.DET_MH_CRC16_013_016           = 0;
   data_ptr.SRR_FL_DETECTION_013_016.DET_MH_SCAN_INDEX_4LSB_013_016 = 0;

   // SRR_FL_DETECTION_017_020_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_017 = af_target_report_ptr[16].ran;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_018 = af_target_report_ptr[17].ran;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_019 = af_target_report_ptr[18].ran;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_020 = af_target_report_ptr[19].ran;

   data_ptr.SRR_FL_DETECTION_017_020.DET_AZIMUTH_017 = af_target_report_ptr[16].theta;
   data_ptr.SRR_FL_DETECTION_017_020.DET_AZIMUTH_018 = af_target_report_ptr[17].theta;
   data_ptr.SRR_FL_DETECTION_017_020.DET_AZIMUTH_019 = af_target_report_ptr[18].theta;
   data_ptr.SRR_FL_DETECTION_017_020.DET_AZIMUTH_020 = af_target_report_ptr[19].theta;

   data_ptr.SRR_FL_DETECTION_017_020.DET_BI_STATIC_FLAG_017 = af_target_report_ptr[16].f_bistatic;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BI_STATIC_FLAG_018 = af_target_report_ptr[17].f_bistatic;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BI_STATIC_FLAG_019 = af_target_report_ptr[18].f_bistatic;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BI_STATIC_FLAG_020 = af_target_report_ptr[19].f_bistatic;

   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_AZIMUTH_017 = af_target_report_ptr[16].az_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_AZIMUTH_018 = af_target_report_ptr[17].az_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_AZIMUTH_019 = af_target_report_ptr[18].az_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_AZIMUTH_020 = af_target_report_ptr[19].az_conf;

   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_017 = af_target_report_ptr[16].phi;
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_018 = af_target_report_ptr[17].phi;
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_019 = af_target_report_ptr[18].phi;
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_020 = af_target_report_ptr[19].phi;

   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_ELEVATION_017 = af_target_report_ptr[16].el_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_ELEVATION_018 = af_target_report_ptr[17].el_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_ELEVATION_019 = af_target_report_ptr[18].el_conf;
   data_ptr.SRR_FL_DETECTION_017_020.DET_CONFD_ELEVATION_020 = af_target_report_ptr[19].el_conf;

   data_ptr.SRR_FL_DETECTION_017_020.DET_EXISTENCE_PROB_017 = TOI_DS_Stream_Ptr->existence_prob[16];
   data_ptr.SRR_FL_DETECTION_017_020.DET_EXISTENCE_PROB_018 = TOI_DS_Stream_Ptr->existence_prob[17];
   data_ptr.SRR_FL_DETECTION_017_020.DET_EXISTENCE_PROB_019 = TOI_DS_Stream_Ptr->existence_prob[18];
   data_ptr.SRR_FL_DETECTION_017_020.DET_EXISTENCE_PROB_020 = TOI_DS_Stream_Ptr->existence_prob[19];

   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_ERR_017 = TOI_DS_Stream_Ptr->std_phi[16];
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_ERR_018 = TOI_DS_Stream_Ptr->std_phi[17];
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_ERR_019 = TOI_DS_Stream_Ptr->std_phi[18];
   data_ptr.SRR_FL_DETECTION_017_020.DET_ELEVATION_ERR_020 = TOI_DS_Stream_Ptr->std_phi[19];

   data_ptr.SRR_FL_DETECTION_017_020.DET_IDM_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_IDM_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_IDM_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_IDM_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_017_020.DET_MTD_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_MTD_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_MTD_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_MTD_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_017_020.DET_PROB_1STAZHYPO_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_PROB_1STAZHYPO_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_PROB_1STAZHYPO_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_PROB_1STAZHYPO_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_ERR_017 = TOI_DS_Stream_Ptr->std_ran[16];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_ERR_018 = TOI_DS_Stream_Ptr->std_ran[17];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_ERR_019 = TOI_DS_Stream_Ptr->std_ran[18];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_ERR_020 = TOI_DS_Stream_Ptr->std_ran[19];

   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_017 = af_target_report_ptr[16].vel;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_018 = af_target_report_ptr[17].vel;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_019 = af_target_report_ptr[18].vel;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_020 = af_target_report_ptr[19].vel;

   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_017 = TOI_DS_Stream_Ptr->std_vel[16];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_018 = TOI_DS_Stream_Ptr->std_vel[17];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_019 = TOI_DS_Stream_Ptr->std_vel[18];
   data_ptr.SRR_FL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_020 = TOI_DS_Stream_Ptr->std_vel[19];

   data_ptr.SRR_FL_DETECTION_017_020.DET_RCS_017 = af_target_report_ptr[16].rcs;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RCS_018 = af_target_report_ptr[17].rcs;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RCS_019 = af_target_report_ptr[18].rcs;
   data_ptr.SRR_FL_DETECTION_017_020.DET_RCS_020 = af_target_report_ptr[19].rcs;

   data_ptr.SRR_FL_DETECTION_017_020.DET_SNR_017 = af_target_report_ptr[16].snr;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SNR_018 = af_target_report_ptr[17].snr;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SNR_019 = af_target_report_ptr[18].snr;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SNR_020 = af_target_report_ptr[19].snr;

   data_ptr.SRR_FL_DETECTION_017_020.DET_SUPER_RES_TARGET_017 = af_target_report_ptr[16].f_superres_target;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SUPER_RES_TARGET_018 = af_target_report_ptr[17].f_superres_target;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SUPER_RES_TARGET_019 = af_target_report_ptr[18].f_superres_target;
   data_ptr.SRR_FL_DETECTION_017_020.DET_SUPER_RES_TARGET_020 = af_target_report_ptr[19].f_superres_target;

   data_ptr.SRR_FL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_017 = 0;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_018 = 0;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_019 = 0;
   data_ptr.SRR_FL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_020 = 0;

   data_ptr.SRR_FL_DETECTION_017_020.DET_HVC_FLAG_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_HVC_FLAG_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_HVC_FLAG_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_017_020.DET_HVC_FLAG_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_017_020.DET_MH_CYCLE_COUNTER_017_020   = 0;
   data_ptr.SRR_FL_DETECTION_017_020.DET_MH_CRC16_017_020           = 0;
   data_ptr.SRR_FL_DETECTION_017_020.DET_MH_SCAN_INDEX_4LSB_017_020 = 0;

   // SRR_FL_DETECTION_021_024_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_021 = af_target_report_ptr[20].ran;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_022 = af_target_report_ptr[21].ran;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_023 = af_target_report_ptr[22].ran;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_024 = af_target_report_ptr[23].ran;

   data_ptr.SRR_FL_DETECTION_021_024.DET_AZIMUTH_021 = af_target_report_ptr[20].theta;
   data_ptr.SRR_FL_DETECTION_021_024.DET_AZIMUTH_022 = af_target_report_ptr[21].theta;
   data_ptr.SRR_FL_DETECTION_021_024.DET_AZIMUTH_023 = af_target_report_ptr[22].theta;
   data_ptr.SRR_FL_DETECTION_021_024.DET_AZIMUTH_024 = af_target_report_ptr[23].theta;

   data_ptr.SRR_FL_DETECTION_021_024.DET_BI_STATIC_FLAG_021 = af_target_report_ptr[20].f_bistatic;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BI_STATIC_FLAG_022 = af_target_report_ptr[21].f_bistatic;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BI_STATIC_FLAG_023 = af_target_report_ptr[22].f_bistatic;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BI_STATIC_FLAG_024 = af_target_report_ptr[23].f_bistatic;

   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_AZIMUTH_021 = af_target_report_ptr[20].az_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_AZIMUTH_022 = af_target_report_ptr[21].az_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_AZIMUTH_023 = af_target_report_ptr[22].az_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_AZIMUTH_024 = af_target_report_ptr[23].az_conf;

   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_021 = af_target_report_ptr[20].phi;
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_022 = af_target_report_ptr[21].phi;
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_023 = af_target_report_ptr[22].phi;
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_024 = af_target_report_ptr[23].phi;

   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_ELEVATION_021 = af_target_report_ptr[20].el_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_ELEVATION_022 = af_target_report_ptr[21].el_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_ELEVATION_023 = af_target_report_ptr[22].el_conf;
   data_ptr.SRR_FL_DETECTION_021_024.DET_CONFD_ELEVATION_024 = af_target_report_ptr[23].el_conf;

   data_ptr.SRR_FL_DETECTION_021_024.DET_EXISTENCE_PROB_021 = TOI_DS_Stream_Ptr->existence_prob[20];
   data_ptr.SRR_FL_DETECTION_021_024.DET_EXISTENCE_PROB_022 = TOI_DS_Stream_Ptr->existence_prob[21];
   data_ptr.SRR_FL_DETECTION_021_024.DET_EXISTENCE_PROB_023 = TOI_DS_Stream_Ptr->existence_prob[22];
   data_ptr.SRR_FL_DETECTION_021_024.DET_EXISTENCE_PROB_024 = TOI_DS_Stream_Ptr->existence_prob[23];

   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_ERR_021 = TOI_DS_Stream_Ptr->std_phi[20];
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_ERR_022 = TOI_DS_Stream_Ptr->std_phi[21];
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_ERR_023 = TOI_DS_Stream_Ptr->std_phi[22];
   data_ptr.SRR_FL_DETECTION_021_024.DET_ELEVATION_ERR_024 = TOI_DS_Stream_Ptr->std_phi[23];

   data_ptr.SRR_FL_DETECTION_021_024.DET_IDM_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_IDM_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_IDM_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_IDM_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_021_024.DET_MTD_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_MTD_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_MTD_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_MTD_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_021_024.DET_PROB_1STAZHYPO_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_PROB_1STAZHYPO_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_PROB_1STAZHYPO_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_PROB_1STAZHYPO_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_ERR_021 = TOI_DS_Stream_Ptr->std_ran[20];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_ERR_022 = TOI_DS_Stream_Ptr->std_ran[21];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_ERR_023 = TOI_DS_Stream_Ptr->std_ran[22];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_ERR_024 = TOI_DS_Stream_Ptr->std_ran[23];

   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_021 = af_target_report_ptr[20].vel;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_022 = af_target_report_ptr[21].vel;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_023 = af_target_report_ptr[22].vel;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_024 = af_target_report_ptr[23].vel;

   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_021 = TOI_DS_Stream_Ptr->std_vel[20];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_022 = TOI_DS_Stream_Ptr->std_vel[21];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_023 = TOI_DS_Stream_Ptr->std_vel[22];
   data_ptr.SRR_FL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_024 = TOI_DS_Stream_Ptr->std_vel[23];

   data_ptr.SRR_FL_DETECTION_021_024.DET_RCS_021 = af_target_report_ptr[20].rcs;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RCS_022 = af_target_report_ptr[21].rcs;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RCS_023 = af_target_report_ptr[22].rcs;
   data_ptr.SRR_FL_DETECTION_021_024.DET_RCS_024 = af_target_report_ptr[23].rcs;

   data_ptr.SRR_FL_DETECTION_021_024.DET_SNR_021 = af_target_report_ptr[20].snr;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SNR_022 = af_target_report_ptr[21].snr;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SNR_023 = af_target_report_ptr[22].snr;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SNR_024 = af_target_report_ptr[23].snr;

   data_ptr.SRR_FL_DETECTION_021_024.DET_SUPER_RES_TARGET_021 = af_target_report_ptr[20].f_superres_target;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SUPER_RES_TARGET_022 = af_target_report_ptr[21].f_superres_target;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SUPER_RES_TARGET_023 = af_target_report_ptr[22].f_superres_target;
   data_ptr.SRR_FL_DETECTION_021_024.DET_SUPER_RES_TARGET_024 = af_target_report_ptr[23].f_superres_target;

   data_ptr.SRR_FL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_021 = 0;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_022 = 0;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_023 = 0;
   data_ptr.SRR_FL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_024 = 0;

   data_ptr.SRR_FL_DETECTION_021_024.DET_HVC_FLAG_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_HVC_FLAG_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_HVC_FLAG_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_021_024.DET_HVC_FLAG_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_021_024.DET_MH_CYCLE_COUNTER_021_024   = 0;
   data_ptr.SRR_FL_DETECTION_021_024.DET_MH_CRC16_021_024           = 0;
   data_ptr.SRR_FL_DETECTION_021_024.DET_MH_SCAN_INDEX_4LSB_021_024 = 0;

   // SRR_FL_DETECTION_025_028_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_025 = af_target_report_ptr[24].ran;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_026 = af_target_report_ptr[25].ran;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_027 = af_target_report_ptr[26].ran;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_028 = af_target_report_ptr[27].ran;

   data_ptr.SRR_FL_DETECTION_025_028.DET_AZIMUTH_025 = af_target_report_ptr[24].theta;
   data_ptr.SRR_FL_DETECTION_025_028.DET_AZIMUTH_026 = af_target_report_ptr[25].theta;
   data_ptr.SRR_FL_DETECTION_025_028.DET_AZIMUTH_027 = af_target_report_ptr[26].theta;
   data_ptr.SRR_FL_DETECTION_025_028.DET_AZIMUTH_028 = af_target_report_ptr[27].theta;

   data_ptr.SRR_FL_DETECTION_025_028.DET_BI_STATIC_FLAG_025 = af_target_report_ptr[24].f_bistatic;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BI_STATIC_FLAG_026 = af_target_report_ptr[25].f_bistatic;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BI_STATIC_FLAG_027 = af_target_report_ptr[26].f_bistatic;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BI_STATIC_FLAG_028 = af_target_report_ptr[27].f_bistatic;

   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_AZIMUTH_025 = af_target_report_ptr[24].az_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_AZIMUTH_026 = af_target_report_ptr[25].az_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_AZIMUTH_027 = af_target_report_ptr[26].az_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_AZIMUTH_028 = af_target_report_ptr[27].az_conf;

   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_025 = af_target_report_ptr[24].phi;
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_026 = af_target_report_ptr[25].phi;
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_027 = af_target_report_ptr[26].phi;
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_028 = af_target_report_ptr[27].phi;

   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_ELEVATION_025 = af_target_report_ptr[24].el_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_ELEVATION_026 = af_target_report_ptr[25].el_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_ELEVATION_027 = af_target_report_ptr[26].el_conf;
   data_ptr.SRR_FL_DETECTION_025_028.DET_CONFD_ELEVATION_028 = af_target_report_ptr[27].el_conf;

   data_ptr.SRR_FL_DETECTION_025_028.DET_EXISTENCE_PROB_025 = TOI_DS_Stream_Ptr->existence_prob[24];
   data_ptr.SRR_FL_DETECTION_025_028.DET_EXISTENCE_PROB_026 = TOI_DS_Stream_Ptr->existence_prob[25];
   data_ptr.SRR_FL_DETECTION_025_028.DET_EXISTENCE_PROB_027 = TOI_DS_Stream_Ptr->existence_prob[26];
   data_ptr.SRR_FL_DETECTION_025_028.DET_EXISTENCE_PROB_028 = TOI_DS_Stream_Ptr->existence_prob[27];

   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_ERR_025 = TOI_DS_Stream_Ptr->std_phi[24];
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_ERR_026 = TOI_DS_Stream_Ptr->std_phi[25];
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_ERR_027 = TOI_DS_Stream_Ptr->std_phi[26];
   data_ptr.SRR_FL_DETECTION_025_028.DET_ELEVATION_ERR_028 = TOI_DS_Stream_Ptr->std_phi[27];

   data_ptr.SRR_FL_DETECTION_025_028.DET_IDM_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_IDM_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_IDM_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_IDM_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_025_028.DET_MTD_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_MTD_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_MTD_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_MTD_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_025_028.DET_PROB_1STAZHYPO_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_PROB_1STAZHYPO_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_PROB_1STAZHYPO_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_PROB_1STAZHYPO_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_ERR_025 = TOI_DS_Stream_Ptr->std_ran[24];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_ERR_026 = TOI_DS_Stream_Ptr->std_ran[25];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_ERR_027 = TOI_DS_Stream_Ptr->std_ran[26];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_ERR_028 = TOI_DS_Stream_Ptr->std_ran[27];

   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_025 = af_target_report_ptr[24].vel;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_026 = af_target_report_ptr[25].vel;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_027 = af_target_report_ptr[26].vel;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_028 = af_target_report_ptr[27].vel;

   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_025 = TOI_DS_Stream_Ptr->std_vel[24];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_026 = TOI_DS_Stream_Ptr->std_vel[25];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_027 = TOI_DS_Stream_Ptr->std_vel[26];
   data_ptr.SRR_FL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_028 = TOI_DS_Stream_Ptr->std_vel[27];

   data_ptr.SRR_FL_DETECTION_025_028.DET_RCS_025 = af_target_report_ptr[24].rcs;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RCS_026 = af_target_report_ptr[25].rcs;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RCS_027 = af_target_report_ptr[26].rcs;
   data_ptr.SRR_FL_DETECTION_025_028.DET_RCS_028 = af_target_report_ptr[27].rcs;

   data_ptr.SRR_FL_DETECTION_025_028.DET_SNR_025 = af_target_report_ptr[24].snr;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SNR_026 = af_target_report_ptr[25].snr;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SNR_027 = af_target_report_ptr[26].snr;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SNR_028 = af_target_report_ptr[27].snr;

   data_ptr.SRR_FL_DETECTION_025_028.DET_SUPER_RES_TARGET_025 = af_target_report_ptr[24].f_superres_target;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SUPER_RES_TARGET_026 = af_target_report_ptr[25].f_superres_target;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SUPER_RES_TARGET_027 = af_target_report_ptr[26].f_superres_target;
   data_ptr.SRR_FL_DETECTION_025_028.DET_SUPER_RES_TARGET_028 = af_target_report_ptr[27].f_superres_target;

   data_ptr.SRR_FL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_025 = 0;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_026 = 0;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_027 = 0;
   data_ptr.SRR_FL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_028 = 0;

   data_ptr.SRR_FL_DETECTION_025_028.DET_HVC_FLAG_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_HVC_FLAG_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_HVC_FLAG_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_025_028.DET_HVC_FLAG_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_025_028.DET_MH_CYCLE_COUNTER_025_028   = 0;
   data_ptr.SRR_FL_DETECTION_025_028.DET_MH_CRC16_025_028           = 0;
   data_ptr.SRR_FL_DETECTION_025_028.DET_MH_SCAN_INDEX_4LSB_025_028 = 0;

   // SRR_FL_DETECTION_029_032_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_029 = af_target_report_ptr[28].ran;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_030 = af_target_report_ptr[29].ran;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_031 = af_target_report_ptr[30].ran;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_032 = af_target_report_ptr[31].ran;

   data_ptr.SRR_FL_DETECTION_029_032.DET_AZIMUTH_029 = af_target_report_ptr[28].theta;
   data_ptr.SRR_FL_DETECTION_029_032.DET_AZIMUTH_030 = af_target_report_ptr[29].theta;
   data_ptr.SRR_FL_DETECTION_029_032.DET_AZIMUTH_031 = af_target_report_ptr[30].theta;
   data_ptr.SRR_FL_DETECTION_029_032.DET_AZIMUTH_032 = af_target_report_ptr[31].theta;

   data_ptr.SRR_FL_DETECTION_029_032.DET_BI_STATIC_FLAG_029 = af_target_report_ptr[28].f_bistatic;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BI_STATIC_FLAG_030 = af_target_report_ptr[29].f_bistatic;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BI_STATIC_FLAG_031 = af_target_report_ptr[30].f_bistatic;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BI_STATIC_FLAG_032 = af_target_report_ptr[31].f_bistatic;

   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_AZIMUTH_029 = af_target_report_ptr[28].az_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_AZIMUTH_030 = af_target_report_ptr[29].az_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_AZIMUTH_031 = af_target_report_ptr[30].az_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_AZIMUTH_032 = af_target_report_ptr[31].az_conf;

   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_029 = af_target_report_ptr[28].phi;
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_030 = af_target_report_ptr[29].phi;
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_031 = af_target_report_ptr[30].phi;
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_032 = af_target_report_ptr[31].phi;

   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_ELEVATION_029 = af_target_report_ptr[28].el_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_ELEVATION_030 = af_target_report_ptr[29].el_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_ELEVATION_031 = af_target_report_ptr[30].el_conf;
   data_ptr.SRR_FL_DETECTION_029_032.DET_CONFD_ELEVATION_032 = af_target_report_ptr[31].el_conf;

   data_ptr.SRR_FL_DETECTION_029_032.DET_EXISTENCE_PROB_029 = TOI_DS_Stream_Ptr->existence_prob[28];
   data_ptr.SRR_FL_DETECTION_029_032.DET_EXISTENCE_PROB_030 = TOI_DS_Stream_Ptr->existence_prob[29];
   data_ptr.SRR_FL_DETECTION_029_032.DET_EXISTENCE_PROB_031 = TOI_DS_Stream_Ptr->existence_prob[30];
   data_ptr.SRR_FL_DETECTION_029_032.DET_EXISTENCE_PROB_032 = TOI_DS_Stream_Ptr->existence_prob[31];

   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_ERR_029 = TOI_DS_Stream_Ptr->std_phi[28];
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_ERR_030 = TOI_DS_Stream_Ptr->std_phi[29];
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_ERR_031 = TOI_DS_Stream_Ptr->std_phi[30];
   data_ptr.SRR_FL_DETECTION_029_032.DET_ELEVATION_ERR_032 = TOI_DS_Stream_Ptr->std_phi[31];

   data_ptr.SRR_FL_DETECTION_029_032.DET_IDM_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_IDM_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_IDM_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_IDM_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_029_032.DET_MTD_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_MTD_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_MTD_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_MTD_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_029_032.DET_PROB_1STAZHYPO_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_PROB_1STAZHYPO_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_PROB_1STAZHYPO_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_PROB_1STAZHYPO_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_ERR_029 = TOI_DS_Stream_Ptr->std_ran[28];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_ERR_030 = TOI_DS_Stream_Ptr->std_ran[29];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_ERR_031 = TOI_DS_Stream_Ptr->std_ran[30];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_ERR_032 = TOI_DS_Stream_Ptr->std_ran[31];

   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_029 = af_target_report_ptr[28].vel;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_030 = af_target_report_ptr[29].vel;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_031 = af_target_report_ptr[30].vel;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_032 = af_target_report_ptr[31].vel;

   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_029 = TOI_DS_Stream_Ptr->std_vel[28];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_030 = TOI_DS_Stream_Ptr->std_vel[29];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_031 = TOI_DS_Stream_Ptr->std_vel[30];
   data_ptr.SRR_FL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_032 = TOI_DS_Stream_Ptr->std_vel[31];

   data_ptr.SRR_FL_DETECTION_029_032.DET_RCS_029 = af_target_report_ptr[28].rcs;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RCS_030 = af_target_report_ptr[29].rcs;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RCS_031 = af_target_report_ptr[30].rcs;
   data_ptr.SRR_FL_DETECTION_029_032.DET_RCS_032 = af_target_report_ptr[31].rcs;

   data_ptr.SRR_FL_DETECTION_029_032.DET_SNR_029 = af_target_report_ptr[28].snr;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SNR_030 = af_target_report_ptr[29].snr;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SNR_031 = af_target_report_ptr[30].snr;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SNR_032 = af_target_report_ptr[31].snr;

   data_ptr.SRR_FL_DETECTION_029_032.DET_SUPER_RES_TARGET_029 = af_target_report_ptr[28].f_superres_target;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SUPER_RES_TARGET_030 = af_target_report_ptr[29].f_superres_target;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SUPER_RES_TARGET_031 = af_target_report_ptr[30].f_superres_target;
   data_ptr.SRR_FL_DETECTION_029_032.DET_SUPER_RES_TARGET_032 = af_target_report_ptr[31].f_superres_target;

   data_ptr.SRR_FL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_029 = 0;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_030 = 0;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_031 = 0;
   data_ptr.SRR_FL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_032 = 0;

   data_ptr.SRR_FL_DETECTION_029_032.DET_HVC_FLAG_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_HVC_FLAG_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_HVC_FLAG_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_029_032.DET_HVC_FLAG_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_029_032.DET_MH_CYCLE_COUNTER_029_032   = 0;
   data_ptr.SRR_FL_DETECTION_029_032.DET_MH_CRC16_029_032           = 0;
   data_ptr.SRR_FL_DETECTION_029_032.DET_MH_SCAN_INDEX_4LSB_029_032 = 0;

   // SRR_FL_DETECTION_033_036_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_033 = af_target_report_ptr[32].ran;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_034 = af_target_report_ptr[33].ran;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_035 = af_target_report_ptr[34].ran;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_036 = af_target_report_ptr[35].ran;

   data_ptr.SRR_FL_DETECTION_033_036.DET_AZIMUTH_033 = af_target_report_ptr[32].theta;
   data_ptr.SRR_FL_DETECTION_033_036.DET_AZIMUTH_034 = af_target_report_ptr[33].theta;
   data_ptr.SRR_FL_DETECTION_033_036.DET_AZIMUTH_035 = af_target_report_ptr[34].theta;
   data_ptr.SRR_FL_DETECTION_033_036.DET_AZIMUTH_036 = af_target_report_ptr[35].theta;

   data_ptr.SRR_FL_DETECTION_033_036.DET_BI_STATIC_FLAG_033 = af_target_report_ptr[32].f_bistatic;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BI_STATIC_FLAG_034 = af_target_report_ptr[33].f_bistatic;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BI_STATIC_FLAG_035 = af_target_report_ptr[34].f_bistatic;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BI_STATIC_FLAG_036 = af_target_report_ptr[35].f_bistatic;

   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_AZIMUTH_033 = af_target_report_ptr[32].az_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_AZIMUTH_034 = af_target_report_ptr[33].az_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_AZIMUTH_035 = af_target_report_ptr[34].az_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_AZIMUTH_036 = af_target_report_ptr[35].az_conf;

   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_033 = af_target_report_ptr[32].phi;
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_034 = af_target_report_ptr[33].phi;
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_035 = af_target_report_ptr[34].phi;
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_036 = af_target_report_ptr[35].phi;

   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_ELEVATION_033 = af_target_report_ptr[32].el_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_ELEVATION_034 = af_target_report_ptr[33].el_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_ELEVATION_035 = af_target_report_ptr[34].el_conf;
   data_ptr.SRR_FL_DETECTION_033_036.DET_CONFD_ELEVATION_036 = af_target_report_ptr[35].el_conf;

   data_ptr.SRR_FL_DETECTION_033_036.DET_EXISTENCE_PROB_033 = TOI_DS_Stream_Ptr->existence_prob[32];
   data_ptr.SRR_FL_DETECTION_033_036.DET_EXISTENCE_PROB_034 = TOI_DS_Stream_Ptr->existence_prob[33];
   data_ptr.SRR_FL_DETECTION_033_036.DET_EXISTENCE_PROB_035 = TOI_DS_Stream_Ptr->existence_prob[34];
   data_ptr.SRR_FL_DETECTION_033_036.DET_EXISTENCE_PROB_036 = TOI_DS_Stream_Ptr->existence_prob[35];

   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_ERR_033 = TOI_DS_Stream_Ptr->std_phi[32];
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_ERR_034 = TOI_DS_Stream_Ptr->std_phi[33];
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_ERR_035 = TOI_DS_Stream_Ptr->std_phi[34];
   data_ptr.SRR_FL_DETECTION_033_036.DET_ELEVATION_ERR_036 = TOI_DS_Stream_Ptr->std_phi[35];

   data_ptr.SRR_FL_DETECTION_033_036.DET_IDM_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_IDM_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_IDM_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_IDM_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_033_036.DET_MTD_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_MTD_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_MTD_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_MTD_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_033_036.DET_PROB_1STAZHYPO_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_PROB_1STAZHYPO_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_PROB_1STAZHYPO_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_PROB_1STAZHYPO_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_ERR_033 = TOI_DS_Stream_Ptr->std_ran[32];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_ERR_034 = TOI_DS_Stream_Ptr->std_ran[33];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_ERR_035 = TOI_DS_Stream_Ptr->std_ran[34];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_ERR_036 = TOI_DS_Stream_Ptr->std_ran[35];

   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_033 = af_target_report_ptr[32].vel;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_034 = af_target_report_ptr[33].vel;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_035 = af_target_report_ptr[34].vel;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_036 = af_target_report_ptr[35].vel;

   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_033 = TOI_DS_Stream_Ptr->std_vel[32];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_034 = TOI_DS_Stream_Ptr->std_vel[33];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_035 = TOI_DS_Stream_Ptr->std_vel[34];
   data_ptr.SRR_FL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_036 = TOI_DS_Stream_Ptr->std_vel[35];

   data_ptr.SRR_FL_DETECTION_033_036.DET_RCS_033 = af_target_report_ptr[32].rcs;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RCS_034 = af_target_report_ptr[33].rcs;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RCS_035 = af_target_report_ptr[34].rcs;
   data_ptr.SRR_FL_DETECTION_033_036.DET_RCS_036 = af_target_report_ptr[35].rcs;

   data_ptr.SRR_FL_DETECTION_033_036.DET_SNR_033 = af_target_report_ptr[32].snr;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SNR_034 = af_target_report_ptr[33].snr;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SNR_035 = af_target_report_ptr[34].snr;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SNR_036 = af_target_report_ptr[35].snr;

   data_ptr.SRR_FL_DETECTION_033_036.DET_SUPER_RES_TARGET_033 = af_target_report_ptr[32].f_superres_target;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SUPER_RES_TARGET_034 = af_target_report_ptr[33].f_superres_target;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SUPER_RES_TARGET_035 = af_target_report_ptr[34].f_superres_target;
   data_ptr.SRR_FL_DETECTION_033_036.DET_SUPER_RES_TARGET_036 = af_target_report_ptr[35].f_superres_target;

   data_ptr.SRR_FL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_033 = 0;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_034 = 0;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_035 = 0;
   data_ptr.SRR_FL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_036 = 0;

   data_ptr.SRR_FL_DETECTION_033_036.DET_HVC_FLAG_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_HVC_FLAG_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_HVC_FLAG_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_033_036.DET_HVC_FLAG_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_033_036.DET_MH_CYCLE_COUNTER_033_036   = 0;
   data_ptr.SRR_FL_DETECTION_033_036.DET_MH_CRC16_033_036           = 0;
   data_ptr.SRR_FL_DETECTION_033_036.DET_MH_SCAN_INDEX_4LSB_033_036 = 0;

   // SRR_FL_DETECTION_037_040_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_037 = af_target_report_ptr[36].ran;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_038 = af_target_report_ptr[37].ran;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_039 = af_target_report_ptr[38].ran;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_040 = af_target_report_ptr[39].ran;

   data_ptr.SRR_FL_DETECTION_037_040.DET_AZIMUTH_037 = af_target_report_ptr[36].theta;
   data_ptr.SRR_FL_DETECTION_037_040.DET_AZIMUTH_038 = af_target_report_ptr[37].theta;
   data_ptr.SRR_FL_DETECTION_037_040.DET_AZIMUTH_039 = af_target_report_ptr[38].theta;
   data_ptr.SRR_FL_DETECTION_037_040.DET_AZIMUTH_040 = af_target_report_ptr[39].theta;

   data_ptr.SRR_FL_DETECTION_037_040.DET_BI_STATIC_FLAG_037 = af_target_report_ptr[36].f_bistatic;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BI_STATIC_FLAG_038 = af_target_report_ptr[37].f_bistatic;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BI_STATIC_FLAG_039 = af_target_report_ptr[38].f_bistatic;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BI_STATIC_FLAG_040 = af_target_report_ptr[39].f_bistatic;

   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_AZIMUTH_037 = af_target_report_ptr[36].az_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_AZIMUTH_038 = af_target_report_ptr[37].az_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_AZIMUTH_039 = af_target_report_ptr[38].az_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_AZIMUTH_040 = af_target_report_ptr[39].az_conf;

   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_037 = af_target_report_ptr[36].phi;
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_038 = af_target_report_ptr[37].phi;
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_039 = af_target_report_ptr[38].phi;
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_040 = af_target_report_ptr[39].phi;

   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_ELEVATION_037 = af_target_report_ptr[36].el_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_ELEVATION_038 = af_target_report_ptr[37].el_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_ELEVATION_039 = af_target_report_ptr[38].el_conf;
   data_ptr.SRR_FL_DETECTION_037_040.DET_CONFD_ELEVATION_040 = af_target_report_ptr[39].el_conf;

   data_ptr.SRR_FL_DETECTION_037_040.DET_EXISTENCE_PROB_037 = TOI_DS_Stream_Ptr->existence_prob[36];
   data_ptr.SRR_FL_DETECTION_037_040.DET_EXISTENCE_PROB_038 = TOI_DS_Stream_Ptr->existence_prob[37];
   data_ptr.SRR_FL_DETECTION_037_040.DET_EXISTENCE_PROB_039 = TOI_DS_Stream_Ptr->existence_prob[38];
   data_ptr.SRR_FL_DETECTION_037_040.DET_EXISTENCE_PROB_040 = TOI_DS_Stream_Ptr->existence_prob[39];

   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_ERR_037 = TOI_DS_Stream_Ptr->std_phi[36];
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_ERR_038 = TOI_DS_Stream_Ptr->std_phi[37];
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_ERR_039 = TOI_DS_Stream_Ptr->std_phi[38];
   data_ptr.SRR_FL_DETECTION_037_040.DET_ELEVATION_ERR_040 = TOI_DS_Stream_Ptr->std_phi[39];

   data_ptr.SRR_FL_DETECTION_037_040.DET_IDM_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_IDM_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_IDM_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_IDM_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_037_040.DET_MTD_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_MTD_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_MTD_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_MTD_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_037_040.DET_PROB_1STAZHYPO_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_PROB_1STAZHYPO_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_PROB_1STAZHYPO_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_PROB_1STAZHYPO_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_ERR_037 = TOI_DS_Stream_Ptr->std_ran[36];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_ERR_038 = TOI_DS_Stream_Ptr->std_ran[37];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_ERR_039 = TOI_DS_Stream_Ptr->std_ran[38];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_ERR_040 = TOI_DS_Stream_Ptr->std_ran[39];

   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_037 = af_target_report_ptr[36].vel;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_038 = af_target_report_ptr[37].vel;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_039 = af_target_report_ptr[38].vel;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_040 = af_target_report_ptr[39].vel;

   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_037 = TOI_DS_Stream_Ptr->std_vel[36];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_038 = TOI_DS_Stream_Ptr->std_vel[37];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_039 = TOI_DS_Stream_Ptr->std_vel[38];
   data_ptr.SRR_FL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_040 = TOI_DS_Stream_Ptr->std_vel[39];

   data_ptr.SRR_FL_DETECTION_037_040.DET_RCS_037 = af_target_report_ptr[36].rcs;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RCS_038 = af_target_report_ptr[37].rcs;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RCS_039 = af_target_report_ptr[38].rcs;
   data_ptr.SRR_FL_DETECTION_037_040.DET_RCS_040 = af_target_report_ptr[39].rcs;

   data_ptr.SRR_FL_DETECTION_037_040.DET_SNR_037 = af_target_report_ptr[36].snr;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SNR_038 = af_target_report_ptr[37].snr;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SNR_039 = af_target_report_ptr[38].snr;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SNR_040 = af_target_report_ptr[39].snr;

   data_ptr.SRR_FL_DETECTION_037_040.DET_SUPER_RES_TARGET_037 = af_target_report_ptr[36].f_superres_target;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SUPER_RES_TARGET_038 = af_target_report_ptr[37].f_superres_target;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SUPER_RES_TARGET_039 = af_target_report_ptr[38].f_superres_target;
   data_ptr.SRR_FL_DETECTION_037_040.DET_SUPER_RES_TARGET_040 = af_target_report_ptr[39].f_superres_target;

   data_ptr.SRR_FL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_037 = 0;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_038 = 0;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_039 = 0;
   data_ptr.SRR_FL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_040 = 0;

   data_ptr.SRR_FL_DETECTION_037_040.DET_HVC_FLAG_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_HVC_FLAG_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_HVC_FLAG_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_037_040.DET_HVC_FLAG_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_037_040.DET_MH_CYCLE_COUNTER_037_040   = 0;
   data_ptr.SRR_FL_DETECTION_037_040.DET_MH_CRC16_037_040           = 0;
   data_ptr.SRR_FL_DETECTION_037_040.DET_MH_SCAN_INDEX_4LSB_037_040 = 0;

   // SRR_FL_DETECTION_041_044_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_041 = af_target_report_ptr[40].ran;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_042 = af_target_report_ptr[41].ran;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_043 = af_target_report_ptr[42].ran;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_044 = af_target_report_ptr[43].ran;

   data_ptr.SRR_FL_DETECTION_041_044.DET_AZIMUTH_041 = af_target_report_ptr[40].theta;
   data_ptr.SRR_FL_DETECTION_041_044.DET_AZIMUTH_042 = af_target_report_ptr[41].theta;
   data_ptr.SRR_FL_DETECTION_041_044.DET_AZIMUTH_043 = af_target_report_ptr[42].theta;
   data_ptr.SRR_FL_DETECTION_041_044.DET_AZIMUTH_044 = af_target_report_ptr[43].theta;

   data_ptr.SRR_FL_DETECTION_041_044.DET_BI_STATIC_FLAG_041 = af_target_report_ptr[40].f_bistatic;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BI_STATIC_FLAG_042 = af_target_report_ptr[41].f_bistatic;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BI_STATIC_FLAG_043 = af_target_report_ptr[42].f_bistatic;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BI_STATIC_FLAG_044 = af_target_report_ptr[43].f_bistatic;

   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_AZIMUTH_041 = af_target_report_ptr[40].az_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_AZIMUTH_042 = af_target_report_ptr[41].az_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_AZIMUTH_043 = af_target_report_ptr[42].az_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_AZIMUTH_044 = af_target_report_ptr[43].az_conf;

   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_041 = af_target_report_ptr[40].phi;
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_042 = af_target_report_ptr[41].phi;
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_043 = af_target_report_ptr[42].phi;
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_044 = af_target_report_ptr[43].phi;

   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_ELEVATION_041 = af_target_report_ptr[40].el_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_ELEVATION_042 = af_target_report_ptr[41].el_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_ELEVATION_043 = af_target_report_ptr[42].el_conf;
   data_ptr.SRR_FL_DETECTION_041_044.DET_CONFD_ELEVATION_044 = af_target_report_ptr[43].el_conf;

   data_ptr.SRR_FL_DETECTION_041_044.DET_EXISTENCE_PROB_041 = TOI_DS_Stream_Ptr->existence_prob[40];
   data_ptr.SRR_FL_DETECTION_041_044.DET_EXISTENCE_PROB_042 = TOI_DS_Stream_Ptr->existence_prob[41];
   data_ptr.SRR_FL_DETECTION_041_044.DET_EXISTENCE_PROB_043 = TOI_DS_Stream_Ptr->existence_prob[42];
   data_ptr.SRR_FL_DETECTION_041_044.DET_EXISTENCE_PROB_044 = TOI_DS_Stream_Ptr->existence_prob[43];

   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_ERR_041 = TOI_DS_Stream_Ptr->std_phi[40];
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_ERR_042 = TOI_DS_Stream_Ptr->std_phi[41];
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_ERR_043 = TOI_DS_Stream_Ptr->std_phi[42];
   data_ptr.SRR_FL_DETECTION_041_044.DET_ELEVATION_ERR_044 = TOI_DS_Stream_Ptr->std_phi[43];

   data_ptr.SRR_FL_DETECTION_041_044.DET_IDM_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_IDM_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_IDM_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_IDM_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_041_044.DET_MTD_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_MTD_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_MTD_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_MTD_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_041_044.DET_PROB_1STAZHYPO_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_PROB_1STAZHYPO_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_PROB_1STAZHYPO_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_PROB_1STAZHYPO_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_ERR_041 = TOI_DS_Stream_Ptr->std_ran[40];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_ERR_042 = TOI_DS_Stream_Ptr->std_ran[41];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_ERR_043 = TOI_DS_Stream_Ptr->std_ran[42];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_ERR_044 = TOI_DS_Stream_Ptr->std_ran[43];

   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_041 = af_target_report_ptr[40].vel;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_042 = af_target_report_ptr[41].vel;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_043 = af_target_report_ptr[42].vel;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_044 = af_target_report_ptr[43].vel;

   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_041 = TOI_DS_Stream_Ptr->std_vel[40];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_042 = TOI_DS_Stream_Ptr->std_vel[41];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_043 = TOI_DS_Stream_Ptr->std_vel[42];
   data_ptr.SRR_FL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_044 = TOI_DS_Stream_Ptr->std_vel[43];

   data_ptr.SRR_FL_DETECTION_041_044.DET_RCS_041 = af_target_report_ptr[40].rcs;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RCS_042 = af_target_report_ptr[41].rcs;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RCS_043 = af_target_report_ptr[42].rcs;
   data_ptr.SRR_FL_DETECTION_041_044.DET_RCS_044 = af_target_report_ptr[43].rcs;

   data_ptr.SRR_FL_DETECTION_041_044.DET_SNR_041 = af_target_report_ptr[40].snr;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SNR_042 = af_target_report_ptr[41].snr;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SNR_043 = af_target_report_ptr[42].snr;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SNR_044 = af_target_report_ptr[43].snr;

   data_ptr.SRR_FL_DETECTION_041_044.DET_SUPER_RES_TARGET_041 = af_target_report_ptr[40].f_superres_target;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SUPER_RES_TARGET_042 = af_target_report_ptr[41].f_superres_target;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SUPER_RES_TARGET_043 = af_target_report_ptr[42].f_superres_target;
   data_ptr.SRR_FL_DETECTION_041_044.DET_SUPER_RES_TARGET_044 = af_target_report_ptr[43].f_superres_target;

   data_ptr.SRR_FL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_041 = 0;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_042 = 0;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_043 = 0;
   data_ptr.SRR_FL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_044 = 0;

   data_ptr.SRR_FL_DETECTION_041_044.DET_HVC_FLAG_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_HVC_FLAG_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_HVC_FLAG_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_041_044.DET_HVC_FLAG_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_041_044.DET_MH_CYCLE_COUNTER_041_044   = 0;
   data_ptr.SRR_FL_DETECTION_041_044.DET_MH_CRC16_041_044           = 0;
   data_ptr.SRR_FL_DETECTION_041_044.DET_MH_SCAN_INDEX_4LSB_041_044 = 0;

   // SRR_FL_DETECTION_045_048_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_045 = af_target_report_ptr[44].ran;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_046 = af_target_report_ptr[45].ran;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_047 = af_target_report_ptr[46].ran;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_048 = af_target_report_ptr[47].ran;

   data_ptr.SRR_FL_DETECTION_045_048.DET_AZIMUTH_045 = af_target_report_ptr[44].theta;
   data_ptr.SRR_FL_DETECTION_045_048.DET_AZIMUTH_046 = af_target_report_ptr[45].theta;
   data_ptr.SRR_FL_DETECTION_045_048.DET_AZIMUTH_047 = af_target_report_ptr[46].theta;
   data_ptr.SRR_FL_DETECTION_045_048.DET_AZIMUTH_048 = af_target_report_ptr[47].theta;

   data_ptr.SRR_FL_DETECTION_045_048.DET_BI_STATIC_FLAG_045 = af_target_report_ptr[44].f_bistatic;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BI_STATIC_FLAG_046 = af_target_report_ptr[45].f_bistatic;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BI_STATIC_FLAG_047 = af_target_report_ptr[46].f_bistatic;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BI_STATIC_FLAG_048 = af_target_report_ptr[47].f_bistatic;

   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_AZIMUTH_045 = af_target_report_ptr[44].az_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_AZIMUTH_046 = af_target_report_ptr[45].az_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_AZIMUTH_047 = af_target_report_ptr[46].az_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_AZIMUTH_048 = af_target_report_ptr[47].az_conf;

   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_045 = af_target_report_ptr[44].phi;
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_046 = af_target_report_ptr[45].phi;
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_047 = af_target_report_ptr[46].phi;
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_048 = af_target_report_ptr[47].phi;

   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_ELEVATION_045 = af_target_report_ptr[44].el_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_ELEVATION_046 = af_target_report_ptr[45].el_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_ELEVATION_047 = af_target_report_ptr[46].el_conf;
   data_ptr.SRR_FL_DETECTION_045_048.DET_CONFD_ELEVATION_048 = af_target_report_ptr[47].el_conf;

   data_ptr.SRR_FL_DETECTION_045_048.DET_EXISTENCE_PROB_045 = TOI_DS_Stream_Ptr->existence_prob[44];
   data_ptr.SRR_FL_DETECTION_045_048.DET_EXISTENCE_PROB_046 = TOI_DS_Stream_Ptr->existence_prob[45];
   data_ptr.SRR_FL_DETECTION_045_048.DET_EXISTENCE_PROB_047 = TOI_DS_Stream_Ptr->existence_prob[46];
   data_ptr.SRR_FL_DETECTION_045_048.DET_EXISTENCE_PROB_048 = TOI_DS_Stream_Ptr->existence_prob[47];

   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_ERR_045 = TOI_DS_Stream_Ptr->std_phi[44];
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_ERR_046 = TOI_DS_Stream_Ptr->std_phi[45];
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_ERR_047 = TOI_DS_Stream_Ptr->std_phi[46];
   data_ptr.SRR_FL_DETECTION_045_048.DET_ELEVATION_ERR_048 = TOI_DS_Stream_Ptr->std_phi[47];

   data_ptr.SRR_FL_DETECTION_045_048.DET_IDM_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_IDM_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_IDM_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_IDM_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_045_048.DET_MTD_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_MTD_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_MTD_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_MTD_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_045_048.DET_PROB_1STAZHYPO_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_PROB_1STAZHYPO_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_PROB_1STAZHYPO_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_PROB_1STAZHYPO_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_ERR_045 = TOI_DS_Stream_Ptr->std_ran[44];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_ERR_046 = TOI_DS_Stream_Ptr->std_ran[45];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_ERR_047 = TOI_DS_Stream_Ptr->std_ran[46];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_ERR_048 = TOI_DS_Stream_Ptr->std_ran[47];

   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_045 = af_target_report_ptr[44].vel;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_046 = af_target_report_ptr[45].vel;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_047 = af_target_report_ptr[46].vel;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_048 = af_target_report_ptr[47].vel;

   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_045 = TOI_DS_Stream_Ptr->std_vel[44];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_046 = TOI_DS_Stream_Ptr->std_vel[45];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_047 = TOI_DS_Stream_Ptr->std_vel[46];
   data_ptr.SRR_FL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_048 = TOI_DS_Stream_Ptr->std_vel[47];

   data_ptr.SRR_FL_DETECTION_045_048.DET_RCS_045 = af_target_report_ptr[44].rcs;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RCS_046 = af_target_report_ptr[45].rcs;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RCS_047 = af_target_report_ptr[46].rcs;
   data_ptr.SRR_FL_DETECTION_045_048.DET_RCS_048 = af_target_report_ptr[47].rcs;

   data_ptr.SRR_FL_DETECTION_045_048.DET_SNR_045 = af_target_report_ptr[44].snr;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SNR_046 = af_target_report_ptr[45].snr;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SNR_047 = af_target_report_ptr[46].snr;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SNR_048 = af_target_report_ptr[47].snr;

   data_ptr.SRR_FL_DETECTION_045_048.DET_SUPER_RES_TARGET_045 = af_target_report_ptr[44].f_superres_target;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SUPER_RES_TARGET_046 = af_target_report_ptr[45].f_superres_target;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SUPER_RES_TARGET_047 = af_target_report_ptr[46].f_superres_target;
   data_ptr.SRR_FL_DETECTION_045_048.DET_SUPER_RES_TARGET_048 = af_target_report_ptr[47].f_superres_target;

   data_ptr.SRR_FL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_045 = 0;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_046 = 0;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_047 = 0;
   data_ptr.SRR_FL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_048 = 0;

   data_ptr.SRR_FL_DETECTION_045_048.DET_HVC_FLAG_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_HVC_FLAG_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_HVC_FLAG_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_045_048.DET_HVC_FLAG_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_045_048.DET_MH_CYCLE_COUNTER_045_048   = 0;
   data_ptr.SRR_FL_DETECTION_045_048.DET_MH_CRC16_045_048           = 0;
   data_ptr.SRR_FL_DETECTION_045_048.DET_MH_SCAN_INDEX_4LSB_045_048 = 0;
   // SRR_FL_DETECTION_049_052_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_049 = af_target_report_ptr[48].ran;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_050 = af_target_report_ptr[49].ran;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_051 = af_target_report_ptr[50].ran;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_052 = af_target_report_ptr[51].ran;

   data_ptr.SRR_FL_DETECTION_049_052.DET_AZIMUTH_049 = af_target_report_ptr[48].theta;
   data_ptr.SRR_FL_DETECTION_049_052.DET_AZIMUTH_050 = af_target_report_ptr[49].theta;
   data_ptr.SRR_FL_DETECTION_049_052.DET_AZIMUTH_051 = af_target_report_ptr[50].theta;
   data_ptr.SRR_FL_DETECTION_049_052.DET_AZIMUTH_052 = af_target_report_ptr[51].theta;

   data_ptr.SRR_FL_DETECTION_049_052.DET_BI_STATIC_FLAG_049 = af_target_report_ptr[48].f_bistatic;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BI_STATIC_FLAG_050 = af_target_report_ptr[49].f_bistatic;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BI_STATIC_FLAG_051 = af_target_report_ptr[50].f_bistatic;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BI_STATIC_FLAG_052 = af_target_report_ptr[51].f_bistatic;

   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_AZIMUTH_049 = af_target_report_ptr[48].az_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_AZIMUTH_050 = af_target_report_ptr[49].az_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_AZIMUTH_051 = af_target_report_ptr[50].az_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_AZIMUTH_052 = af_target_report_ptr[51].az_conf;

   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_049 = af_target_report_ptr[48].phi;
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_050 = af_target_report_ptr[49].phi;
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_051 = af_target_report_ptr[50].phi;
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_052 = af_target_report_ptr[51].phi;

   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_ELEVATION_049 = af_target_report_ptr[48].el_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_ELEVATION_050 = af_target_report_ptr[49].el_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_ELEVATION_051 = af_target_report_ptr[50].el_conf;
   data_ptr.SRR_FL_DETECTION_049_052.DET_CONFD_ELEVATION_052 = af_target_report_ptr[51].el_conf;

   data_ptr.SRR_FL_DETECTION_049_052.DET_EXISTENCE_PROB_049 = TOI_DS_Stream_Ptr->existence_prob[48];
   data_ptr.SRR_FL_DETECTION_049_052.DET_EXISTENCE_PROB_050 = TOI_DS_Stream_Ptr->existence_prob[49];
   data_ptr.SRR_FL_DETECTION_049_052.DET_EXISTENCE_PROB_051 = TOI_DS_Stream_Ptr->existence_prob[50];
   data_ptr.SRR_FL_DETECTION_049_052.DET_EXISTENCE_PROB_052 = TOI_DS_Stream_Ptr->existence_prob[51];

   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_ERR_049 = TOI_DS_Stream_Ptr->std_phi[48];
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_ERR_050 = TOI_DS_Stream_Ptr->std_phi[49];
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_ERR_051 = TOI_DS_Stream_Ptr->std_phi[50];
   data_ptr.SRR_FL_DETECTION_049_052.DET_ELEVATION_ERR_052 = TOI_DS_Stream_Ptr->std_phi[51];

   data_ptr.SRR_FL_DETECTION_049_052.DET_IDM_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_IDM_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_IDM_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_IDM_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_049_052.DET_MTD_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_MTD_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_MTD_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_MTD_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_049_052.DET_PROB_1STAZHYPO_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_PROB_1STAZHYPO_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_PROB_1STAZHYPO_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_PROB_1STAZHYPO_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_ERR_049 = TOI_DS_Stream_Ptr->std_ran[48];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_ERR_050 = TOI_DS_Stream_Ptr->std_ran[49];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_ERR_051 = TOI_DS_Stream_Ptr->std_ran[50];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_ERR_052 = TOI_DS_Stream_Ptr->std_ran[51];

   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_049 = af_target_report_ptr[48].vel;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_050 = af_target_report_ptr[49].vel;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_051 = af_target_report_ptr[50].vel;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_052 = af_target_report_ptr[51].vel;

   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_049 = TOI_DS_Stream_Ptr->std_vel[48];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_050 = TOI_DS_Stream_Ptr->std_vel[49];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_051 = TOI_DS_Stream_Ptr->std_vel[50];
   data_ptr.SRR_FL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_052 = TOI_DS_Stream_Ptr->std_vel[51];

   data_ptr.SRR_FL_DETECTION_049_052.DET_RCS_049 = af_target_report_ptr[48].rcs;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RCS_050 = af_target_report_ptr[49].rcs;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RCS_051 = af_target_report_ptr[50].rcs;
   data_ptr.SRR_FL_DETECTION_049_052.DET_RCS_052 = af_target_report_ptr[51].rcs;

   data_ptr.SRR_FL_DETECTION_049_052.DET_SNR_049 = af_target_report_ptr[48].snr;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SNR_050 = af_target_report_ptr[49].snr;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SNR_051 = af_target_report_ptr[50].snr;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SNR_052 = af_target_report_ptr[51].snr;

   data_ptr.SRR_FL_DETECTION_049_052.DET_SUPER_RES_TARGET_049 = af_target_report_ptr[48].f_superres_target;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SUPER_RES_TARGET_050 = af_target_report_ptr[49].f_superres_target;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SUPER_RES_TARGET_051 = af_target_report_ptr[50].f_superres_target;
   data_ptr.SRR_FL_DETECTION_049_052.DET_SUPER_RES_TARGET_052 = af_target_report_ptr[51].f_superres_target;

   data_ptr.SRR_FL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_049 = 0;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_050 = 0;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_051 = 0;
   data_ptr.SRR_FL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_052 = 0;

   data_ptr.SRR_FL_DETECTION_049_052.DET_HVC_FLAG_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_HVC_FLAG_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_HVC_FLAG_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_049_052.DET_HVC_FLAG_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_049_052.DET_MH_CYCLE_COUNTER_049_052   = 0;
   data_ptr.SRR_FL_DETECTION_049_052.DET_MH_CRC16_049_052           = 0;
   data_ptr.SRR_FL_DETECTION_049_052.DET_MH_SCAN_INDEX_4LSB_049_052 = 0;

   // SRR_FL_DETECTION_053_056_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_053 = af_target_report_ptr[52].ran;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_054 = af_target_report_ptr[53].ran;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_055 = af_target_report_ptr[54].ran;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_056 = af_target_report_ptr[55].ran;

   data_ptr.SRR_FL_DETECTION_053_056.DET_AZIMUTH_053 = af_target_report_ptr[52].theta;
   data_ptr.SRR_FL_DETECTION_053_056.DET_AZIMUTH_054 = af_target_report_ptr[53].theta;
   data_ptr.SRR_FL_DETECTION_053_056.DET_AZIMUTH_055 = af_target_report_ptr[54].theta;
   data_ptr.SRR_FL_DETECTION_053_056.DET_AZIMUTH_056 = af_target_report_ptr[55].theta;

   data_ptr.SRR_FL_DETECTION_053_056.DET_BI_STATIC_FLAG_053 = af_target_report_ptr[52].f_bistatic;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BI_STATIC_FLAG_054 = af_target_report_ptr[53].f_bistatic;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BI_STATIC_FLAG_055 = af_target_report_ptr[54].f_bistatic;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BI_STATIC_FLAG_056 = af_target_report_ptr[55].f_bistatic;

   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_AZIMUTH_053 = af_target_report_ptr[52].az_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_AZIMUTH_054 = af_target_report_ptr[53].az_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_AZIMUTH_055 = af_target_report_ptr[54].az_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_AZIMUTH_056 = af_target_report_ptr[55].az_conf;

   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_053 = af_target_report_ptr[52].phi;
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_054 = af_target_report_ptr[53].phi;
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_055 = af_target_report_ptr[54].phi;
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_056 = af_target_report_ptr[55].phi;

   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_ELEVATION_053 = af_target_report_ptr[52].el_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_ELEVATION_054 = af_target_report_ptr[53].el_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_ELEVATION_055 = af_target_report_ptr[54].el_conf;
   data_ptr.SRR_FL_DETECTION_053_056.DET_CONFD_ELEVATION_056 = af_target_report_ptr[55].el_conf;

   data_ptr.SRR_FL_DETECTION_053_056.DET_EXISTENCE_PROB_053 = TOI_DS_Stream_Ptr->existence_prob[52];
   data_ptr.SRR_FL_DETECTION_053_056.DET_EXISTENCE_PROB_054 = TOI_DS_Stream_Ptr->existence_prob[53];
   data_ptr.SRR_FL_DETECTION_053_056.DET_EXISTENCE_PROB_055 = TOI_DS_Stream_Ptr->existence_prob[54];
   data_ptr.SRR_FL_DETECTION_053_056.DET_EXISTENCE_PROB_056 = TOI_DS_Stream_Ptr->existence_prob[55];

   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_ERR_053 = TOI_DS_Stream_Ptr->std_phi[52];
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_ERR_054 = TOI_DS_Stream_Ptr->std_phi[53];
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_ERR_055 = TOI_DS_Stream_Ptr->std_phi[54];
   data_ptr.SRR_FL_DETECTION_053_056.DET_ELEVATION_ERR_056 = TOI_DS_Stream_Ptr->std_phi[55];

   data_ptr.SRR_FL_DETECTION_053_056.DET_IDM_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_IDM_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_IDM_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_IDM_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_053_056.DET_MTD_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_MTD_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_MTD_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_MTD_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_053_056.DET_PROB_1STAZHYPO_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_PROB_1STAZHYPO_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_PROB_1STAZHYPO_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_PROB_1STAZHYPO_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_ERR_053 = TOI_DS_Stream_Ptr->std_ran[52];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_ERR_054 = TOI_DS_Stream_Ptr->std_ran[53];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_ERR_055 = TOI_DS_Stream_Ptr->std_ran[54];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_ERR_056 = TOI_DS_Stream_Ptr->std_ran[55];

   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_053 = af_target_report_ptr[52].vel;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_054 = af_target_report_ptr[53].vel;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_055 = af_target_report_ptr[54].vel;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_056 = af_target_report_ptr[55].vel;

   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_053 = TOI_DS_Stream_Ptr->std_vel[52];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_054 = TOI_DS_Stream_Ptr->std_vel[53];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_055 = TOI_DS_Stream_Ptr->std_vel[54];
   data_ptr.SRR_FL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_056 = TOI_DS_Stream_Ptr->std_vel[55];

   data_ptr.SRR_FL_DETECTION_053_056.DET_RCS_053 = af_target_report_ptr[52].rcs;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RCS_054 = af_target_report_ptr[53].rcs;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RCS_055 = af_target_report_ptr[54].rcs;
   data_ptr.SRR_FL_DETECTION_053_056.DET_RCS_056 = af_target_report_ptr[55].rcs;

   data_ptr.SRR_FL_DETECTION_053_056.DET_SNR_053 = af_target_report_ptr[52].snr;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SNR_054 = af_target_report_ptr[53].snr;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SNR_055 = af_target_report_ptr[54].snr;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SNR_056 = af_target_report_ptr[55].snr;

   data_ptr.SRR_FL_DETECTION_053_056.DET_SUPER_RES_TARGET_053 = af_target_report_ptr[52].f_superres_target;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SUPER_RES_TARGET_054 = af_target_report_ptr[53].f_superres_target;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SUPER_RES_TARGET_055 = af_target_report_ptr[54].f_superres_target;
   data_ptr.SRR_FL_DETECTION_053_056.DET_SUPER_RES_TARGET_056 = af_target_report_ptr[55].f_superres_target;

   data_ptr.SRR_FL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_053 = 0;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_054 = 0;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_055 = 0;
   data_ptr.SRR_FL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_056 = 0;

   data_ptr.SRR_FL_DETECTION_053_056.DET_HVC_FLAG_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_HVC_FLAG_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_HVC_FLAG_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_053_056.DET_HVC_FLAG_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_053_056.DET_MH_CYCLE_COUNTER_053_056   = 0;
   data_ptr.SRR_FL_DETECTION_053_056.DET_MH_CRC16_053_056           = 0;
   data_ptr.SRR_FL_DETECTION_053_056.DET_MH_SCAN_INDEX_4LSB_053_056 = 0;

   // SRR_FL_DETECTION_057_060_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_057 = af_target_report_ptr[56].ran;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_058 = af_target_report_ptr[57].ran;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_059 = af_target_report_ptr[58].ran;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_060 = af_target_report_ptr[59].ran;

   data_ptr.SRR_FL_DETECTION_057_060.DET_AZIMUTH_057 = af_target_report_ptr[56].theta;
   data_ptr.SRR_FL_DETECTION_057_060.DET_AZIMUTH_058 = af_target_report_ptr[57].theta;
   data_ptr.SRR_FL_DETECTION_057_060.DET_AZIMUTH_059 = af_target_report_ptr[58].theta;
   data_ptr.SRR_FL_DETECTION_057_060.DET_AZIMUTH_060 = af_target_report_ptr[59].theta;

   data_ptr.SRR_FL_DETECTION_057_060.DET_BI_STATIC_FLAG_057 = af_target_report_ptr[56].f_bistatic;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BI_STATIC_FLAG_058 = af_target_report_ptr[57].f_bistatic;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BI_STATIC_FLAG_059 = af_target_report_ptr[58].f_bistatic;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BI_STATIC_FLAG_060 = af_target_report_ptr[59].f_bistatic;

   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_AZIMUTH_057 = af_target_report_ptr[56].az_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_AZIMUTH_058 = af_target_report_ptr[57].az_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_AZIMUTH_059 = af_target_report_ptr[58].az_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_AZIMUTH_060 = af_target_report_ptr[59].az_conf;

   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_057 = af_target_report_ptr[56].phi;
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_058 = af_target_report_ptr[57].phi;
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_059 = af_target_report_ptr[58].phi;
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_060 = af_target_report_ptr[59].phi;

   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_ELEVATION_057 = af_target_report_ptr[56].el_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_ELEVATION_058 = af_target_report_ptr[57].el_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_ELEVATION_059 = af_target_report_ptr[58].el_conf;
   data_ptr.SRR_FL_DETECTION_057_060.DET_CONFD_ELEVATION_060 = af_target_report_ptr[59].el_conf;

   data_ptr.SRR_FL_DETECTION_057_060.DET_EXISTENCE_PROB_057 = TOI_DS_Stream_Ptr->existence_prob[56];
   data_ptr.SRR_FL_DETECTION_057_060.DET_EXISTENCE_PROB_058 = TOI_DS_Stream_Ptr->existence_prob[57];
   data_ptr.SRR_FL_DETECTION_057_060.DET_EXISTENCE_PROB_059 = TOI_DS_Stream_Ptr->existence_prob[58];
   data_ptr.SRR_FL_DETECTION_057_060.DET_EXISTENCE_PROB_060 = TOI_DS_Stream_Ptr->existence_prob[59];

   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_ERR_057 = TOI_DS_Stream_Ptr->std_phi[56];
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_ERR_058 = TOI_DS_Stream_Ptr->std_phi[57];
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_ERR_059 = TOI_DS_Stream_Ptr->std_phi[58];
   data_ptr.SRR_FL_DETECTION_057_060.DET_ELEVATION_ERR_060 = TOI_DS_Stream_Ptr->std_phi[59];

   data_ptr.SRR_FL_DETECTION_057_060.DET_IDM_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_IDM_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_IDM_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_IDM_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_057_060.DET_MTD_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_MTD_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_MTD_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_MTD_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_057_060.DET_PROB_1STAZHYPO_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_PROB_1STAZHYPO_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_PROB_1STAZHYPO_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_PROB_1STAZHYPO_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_ERR_057 = TOI_DS_Stream_Ptr->std_ran[56];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_ERR_058 = TOI_DS_Stream_Ptr->std_ran[57];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_ERR_059 = TOI_DS_Stream_Ptr->std_ran[58];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_ERR_060 = TOI_DS_Stream_Ptr->std_ran[59];

   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_057 = af_target_report_ptr[56].vel;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_058 = af_target_report_ptr[57].vel;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_059 = af_target_report_ptr[58].vel;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_060 = af_target_report_ptr[59].vel;

   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_057 = TOI_DS_Stream_Ptr->std_vel[56];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_058 = TOI_DS_Stream_Ptr->std_vel[57];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_059 = TOI_DS_Stream_Ptr->std_vel[58];
   data_ptr.SRR_FL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_060 = TOI_DS_Stream_Ptr->std_vel[59];

   data_ptr.SRR_FL_DETECTION_057_060.DET_RCS_057 = af_target_report_ptr[56].rcs;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RCS_058 = af_target_report_ptr[57].rcs;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RCS_059 = af_target_report_ptr[58].rcs;
   data_ptr.SRR_FL_DETECTION_057_060.DET_RCS_060 = af_target_report_ptr[59].rcs;

   data_ptr.SRR_FL_DETECTION_057_060.DET_SNR_057 = af_target_report_ptr[56].snr;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SNR_058 = af_target_report_ptr[57].snr;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SNR_059 = af_target_report_ptr[58].snr;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SNR_060 = af_target_report_ptr[59].snr;

   data_ptr.SRR_FL_DETECTION_057_060.DET_SUPER_RES_TARGET_057 = af_target_report_ptr[56].f_superres_target;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SUPER_RES_TARGET_058 = af_target_report_ptr[57].f_superres_target;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SUPER_RES_TARGET_059 = af_target_report_ptr[58].f_superres_target;
   data_ptr.SRR_FL_DETECTION_057_060.DET_SUPER_RES_TARGET_060 = af_target_report_ptr[59].f_superres_target;

   data_ptr.SRR_FL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_057 = 0;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_058 = 0;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_059 = 0;
   data_ptr.SRR_FL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_060 = 0;

   data_ptr.SRR_FL_DETECTION_057_060.DET_HVC_FLAG_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_HVC_FLAG_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_HVC_FLAG_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_057_060.DET_HVC_FLAG_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_057_060.DET_MH_CYCLE_COUNTER_057_060   = 0;
   data_ptr.SRR_FL_DETECTION_057_060.DET_MH_CRC16_057_060           = 0;
   data_ptr.SRR_FL_DETECTION_057_060.DET_MH_SCAN_INDEX_4LSB_057_060 = 0;

   // SRR_FL_DETECTION_061_064_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_061 = af_target_report_ptr[60].ran;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_062 = af_target_report_ptr[61].ran;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_063 = af_target_report_ptr[62].ran;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_064 = af_target_report_ptr[63].ran;

   data_ptr.SRR_FL_DETECTION_061_064.DET_AZIMUTH_061 = af_target_report_ptr[60].theta;
   data_ptr.SRR_FL_DETECTION_061_064.DET_AZIMUTH_062 = af_target_report_ptr[61].theta;
   data_ptr.SRR_FL_DETECTION_061_064.DET_AZIMUTH_063 = af_target_report_ptr[62].theta;
   data_ptr.SRR_FL_DETECTION_061_064.DET_AZIMUTH_064 = af_target_report_ptr[63].theta;

   data_ptr.SRR_FL_DETECTION_061_064.DET_BI_STATIC_FLAG_061 = af_target_report_ptr[60].f_bistatic;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BI_STATIC_FLAG_062 = af_target_report_ptr[61].f_bistatic;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BI_STATIC_FLAG_063 = af_target_report_ptr[62].f_bistatic;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BI_STATIC_FLAG_064 = af_target_report_ptr[63].f_bistatic;

   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_AZIMUTH_061 = af_target_report_ptr[60].az_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_AZIMUTH_062 = af_target_report_ptr[61].az_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_AZIMUTH_063 = af_target_report_ptr[62].az_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_AZIMUTH_064 = af_target_report_ptr[63].az_conf;

   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_061 = af_target_report_ptr[60].phi;
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_062 = af_target_report_ptr[61].phi;
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_063 = af_target_report_ptr[62].phi;
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_064 = af_target_report_ptr[63].phi;

   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_ELEVATION_061 = af_target_report_ptr[60].el_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_ELEVATION_062 = af_target_report_ptr[61].el_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_ELEVATION_063 = af_target_report_ptr[62].el_conf;
   data_ptr.SRR_FL_DETECTION_061_064.DET_CONFD_ELEVATION_064 = af_target_report_ptr[63].el_conf;

   data_ptr.SRR_FL_DETECTION_061_064.DET_EXISTENCE_PROB_061 = TOI_DS_Stream_Ptr->existence_prob[60];
   data_ptr.SRR_FL_DETECTION_061_064.DET_EXISTENCE_PROB_062 = TOI_DS_Stream_Ptr->existence_prob[61];
   data_ptr.SRR_FL_DETECTION_061_064.DET_EXISTENCE_PROB_063 = TOI_DS_Stream_Ptr->existence_prob[62];
   data_ptr.SRR_FL_DETECTION_061_064.DET_EXISTENCE_PROB_064 = TOI_DS_Stream_Ptr->existence_prob[63];

   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_ERR_061 = TOI_DS_Stream_Ptr->std_phi[60];
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_ERR_062 = TOI_DS_Stream_Ptr->std_phi[61];
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_ERR_063 = TOI_DS_Stream_Ptr->std_phi[62];
   data_ptr.SRR_FL_DETECTION_061_064.DET_ELEVATION_ERR_064 = TOI_DS_Stream_Ptr->std_phi[63];

   data_ptr.SRR_FL_DETECTION_061_064.DET_IDM_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_IDM_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_IDM_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_IDM_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_061_064.DET_MTD_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_MTD_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_MTD_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_MTD_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_061_064.DET_PROB_1STAZHYPO_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_PROB_1STAZHYPO_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_PROB_1STAZHYPO_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_PROB_1STAZHYPO_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_ERR_061 = TOI_DS_Stream_Ptr->std_ran[60];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_ERR_062 = TOI_DS_Stream_Ptr->std_ran[61];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_ERR_063 = TOI_DS_Stream_Ptr->std_ran[62];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_ERR_064 = TOI_DS_Stream_Ptr->std_ran[63];

   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_061 = af_target_report_ptr[60].vel;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_062 = af_target_report_ptr[61].vel;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_063 = af_target_report_ptr[62].vel;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_064 = af_target_report_ptr[63].vel;

   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_061 = TOI_DS_Stream_Ptr->std_vel[60];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_062 = TOI_DS_Stream_Ptr->std_vel[61];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_063 = TOI_DS_Stream_Ptr->std_vel[62];
   data_ptr.SRR_FL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_064 = TOI_DS_Stream_Ptr->std_vel[63];

   data_ptr.SRR_FL_DETECTION_061_064.DET_RCS_061 = af_target_report_ptr[60].rcs;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RCS_062 = af_target_report_ptr[61].rcs;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RCS_063 = af_target_report_ptr[62].rcs;
   data_ptr.SRR_FL_DETECTION_061_064.DET_RCS_064 = af_target_report_ptr[63].rcs;

   data_ptr.SRR_FL_DETECTION_061_064.DET_SNR_061 = af_target_report_ptr[60].snr;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SNR_062 = af_target_report_ptr[61].snr;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SNR_063 = af_target_report_ptr[62].snr;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SNR_064 = af_target_report_ptr[63].snr;

   data_ptr.SRR_FL_DETECTION_061_064.DET_SUPER_RES_TARGET_061 = af_target_report_ptr[60].f_superres_target;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SUPER_RES_TARGET_062 = af_target_report_ptr[61].f_superres_target;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SUPER_RES_TARGET_063 = af_target_report_ptr[62].f_superres_target;
   data_ptr.SRR_FL_DETECTION_061_064.DET_SUPER_RES_TARGET_064 = af_target_report_ptr[63].f_superres_target;

   data_ptr.SRR_FL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_061 = 0;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_062 = 0;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_063 = 0;
   data_ptr.SRR_FL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_064 = 0;

   data_ptr.SRR_FL_DETECTION_061_064.DET_HVC_FLAG_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_HVC_FLAG_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_HVC_FLAG_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_061_064.DET_HVC_FLAG_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_061_064.DET_MH_CYCLE_COUNTER_061_064   = 0;
   data_ptr.SRR_FL_DETECTION_061_064.DET_MH_CRC16_061_064           = 0;
   data_ptr.SRR_FL_DETECTION_061_064.DET_MH_SCAN_INDEX_4LSB_061_064 = 0;

   // SRR_FL_DETECTION_065_068_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_065 = af_target_report_ptr[64].ran;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_066 = af_target_report_ptr[65].ran;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_067 = af_target_report_ptr[66].ran;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_068 = af_target_report_ptr[67].ran;

   data_ptr.SRR_FL_DETECTION_065_068.DET_AZIMUTH_065 = af_target_report_ptr[64].theta;
   data_ptr.SRR_FL_DETECTION_065_068.DET_AZIMUTH_066 = af_target_report_ptr[65].theta;
   data_ptr.SRR_FL_DETECTION_065_068.DET_AZIMUTH_067 = af_target_report_ptr[66].theta;
   data_ptr.SRR_FL_DETECTION_065_068.DET_AZIMUTH_068 = af_target_report_ptr[67].theta;

   data_ptr.SRR_FL_DETECTION_065_068.DET_BI_STATIC_FLAG_065 = af_target_report_ptr[64].f_bistatic;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BI_STATIC_FLAG_066 = af_target_report_ptr[65].f_bistatic;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BI_STATIC_FLAG_067 = af_target_report_ptr[66].f_bistatic;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BI_STATIC_FLAG_068 = af_target_report_ptr[67].f_bistatic;

   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_AZIMUTH_065 = af_target_report_ptr[64].az_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_AZIMUTH_066 = af_target_report_ptr[65].az_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_AZIMUTH_067 = af_target_report_ptr[66].az_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_AZIMUTH_068 = af_target_report_ptr[67].az_conf;

   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_065 = af_target_report_ptr[64].phi;
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_066 = af_target_report_ptr[65].phi;
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_067 = af_target_report_ptr[66].phi;
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_068 = af_target_report_ptr[67].phi;

   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_ELEVATION_065 = af_target_report_ptr[64].el_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_ELEVATION_066 = af_target_report_ptr[65].el_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_ELEVATION_067 = af_target_report_ptr[66].el_conf;
   data_ptr.SRR_FL_DETECTION_065_068.DET_CONFD_ELEVATION_068 = af_target_report_ptr[67].el_conf;

   data_ptr.SRR_FL_DETECTION_065_068.DET_EXISTENCE_PROB_065 = TOI_DS_Stream_Ptr->existence_prob[64];
   data_ptr.SRR_FL_DETECTION_065_068.DET_EXISTENCE_PROB_066 = TOI_DS_Stream_Ptr->existence_prob[65];
   data_ptr.SRR_FL_DETECTION_065_068.DET_EXISTENCE_PROB_067 = TOI_DS_Stream_Ptr->existence_prob[66];
   data_ptr.SRR_FL_DETECTION_065_068.DET_EXISTENCE_PROB_068 = TOI_DS_Stream_Ptr->existence_prob[67];

   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_ERR_065 = TOI_DS_Stream_Ptr->std_phi[64];
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_ERR_066 = TOI_DS_Stream_Ptr->std_phi[65];
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_ERR_067 = TOI_DS_Stream_Ptr->std_phi[66];
   data_ptr.SRR_FL_DETECTION_065_068.DET_ELEVATION_ERR_068 = TOI_DS_Stream_Ptr->std_phi[67];

   data_ptr.SRR_FL_DETECTION_065_068.DET_IDM_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_IDM_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_IDM_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_IDM_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_065_068.DET_MTD_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_MTD_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_MTD_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_MTD_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_065_068.DET_PROB_1STAZHYPO_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_PROB_1STAZHYPO_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_PROB_1STAZHYPO_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_PROB_1STAZHYPO_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_ERR_065 = TOI_DS_Stream_Ptr->std_ran[64];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_ERR_066 = TOI_DS_Stream_Ptr->std_ran[65];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_ERR_067 = TOI_DS_Stream_Ptr->std_ran[66];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_ERR_068 = TOI_DS_Stream_Ptr->std_ran[67];

   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_065 = af_target_report_ptr[64].vel;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_066 = af_target_report_ptr[65].vel;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_067 = af_target_report_ptr[66].vel;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_068 = af_target_report_ptr[67].vel;

   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_065 = TOI_DS_Stream_Ptr->std_vel[64];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_066 = TOI_DS_Stream_Ptr->std_vel[65];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_067 = TOI_DS_Stream_Ptr->std_vel[66];
   data_ptr.SRR_FL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_068 = TOI_DS_Stream_Ptr->std_vel[67];

   data_ptr.SRR_FL_DETECTION_065_068.DET_RCS_065 = af_target_report_ptr[64].rcs;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RCS_066 = af_target_report_ptr[65].rcs;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RCS_067 = af_target_report_ptr[66].rcs;
   data_ptr.SRR_FL_DETECTION_065_068.DET_RCS_068 = af_target_report_ptr[67].rcs;

   data_ptr.SRR_FL_DETECTION_065_068.DET_SNR_065 = af_target_report_ptr[64].snr;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SNR_066 = af_target_report_ptr[65].snr;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SNR_067 = af_target_report_ptr[66].snr;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SNR_068 = af_target_report_ptr[67].snr;

   data_ptr.SRR_FL_DETECTION_065_068.DET_SUPER_RES_TARGET_065 = af_target_report_ptr[64].f_superres_target;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SUPER_RES_TARGET_066 = af_target_report_ptr[65].f_superres_target;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SUPER_RES_TARGET_067 = af_target_report_ptr[66].f_superres_target;
   data_ptr.SRR_FL_DETECTION_065_068.DET_SUPER_RES_TARGET_068 = af_target_report_ptr[67].f_superres_target;

   data_ptr.SRR_FL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_065 = 0;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_066 = 0;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_067 = 0;
   data_ptr.SRR_FL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_068 = 0;

   data_ptr.SRR_FL_DETECTION_065_068.DET_HVC_FLAG_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_HVC_FLAG_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_HVC_FLAG_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_065_068.DET_HVC_FLAG_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_065_068.DET_MH_CYCLE_COUNTER_065_068   = 0;
   data_ptr.SRR_FL_DETECTION_065_068.DET_MH_CRC16_065_068           = 0;
   data_ptr.SRR_FL_DETECTION_065_068.DET_MH_SCAN_INDEX_4LSB_065_068 = 0;

   // SRR_FL_DETECTION_069_072_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_069 = af_target_report_ptr[68].ran;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_070 = af_target_report_ptr[69].ran;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_071 = af_target_report_ptr[70].ran;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_072 = af_target_report_ptr[71].ran;

   data_ptr.SRR_FL_DETECTION_069_072.DET_AZIMUTH_069 = af_target_report_ptr[68].theta;
   data_ptr.SRR_FL_DETECTION_069_072.DET_AZIMUTH_070 = af_target_report_ptr[69].theta;
   data_ptr.SRR_FL_DETECTION_069_072.DET_AZIMUTH_071 = af_target_report_ptr[70].theta;
   data_ptr.SRR_FL_DETECTION_069_072.DET_AZIMUTH_072 = af_target_report_ptr[71].theta;

   data_ptr.SRR_FL_DETECTION_069_072.DET_BI_STATIC_FLAG_069 = af_target_report_ptr[68].f_bistatic;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BI_STATIC_FLAG_070 = af_target_report_ptr[69].f_bistatic;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BI_STATIC_FLAG_071 = af_target_report_ptr[70].f_bistatic;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BI_STATIC_FLAG_072 = af_target_report_ptr[71].f_bistatic;

   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_AZIMUTH_069 = af_target_report_ptr[68].az_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_AZIMUTH_070 = af_target_report_ptr[69].az_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_AZIMUTH_071 = af_target_report_ptr[70].az_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_AZIMUTH_072 = af_target_report_ptr[71].az_conf;

   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_069 = af_target_report_ptr[68].phi;
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_070 = af_target_report_ptr[69].phi;
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_071 = af_target_report_ptr[70].phi;
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_072 = af_target_report_ptr[71].phi;

   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_ELEVATION_069 = af_target_report_ptr[68].el_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_ELEVATION_070 = af_target_report_ptr[69].el_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_ELEVATION_071 = af_target_report_ptr[70].el_conf;
   data_ptr.SRR_FL_DETECTION_069_072.DET_CONFD_ELEVATION_072 = af_target_report_ptr[71].el_conf;

   data_ptr.SRR_FL_DETECTION_069_072.DET_EXISTENCE_PROB_069 = TOI_DS_Stream_Ptr->existence_prob[68];
   data_ptr.SRR_FL_DETECTION_069_072.DET_EXISTENCE_PROB_070 = TOI_DS_Stream_Ptr->existence_prob[69];
   data_ptr.SRR_FL_DETECTION_069_072.DET_EXISTENCE_PROB_071 = TOI_DS_Stream_Ptr->existence_prob[70];
   data_ptr.SRR_FL_DETECTION_069_072.DET_EXISTENCE_PROB_072 = TOI_DS_Stream_Ptr->existence_prob[71];

   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_ERR_069 = TOI_DS_Stream_Ptr->std_phi[68];
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_ERR_070 = TOI_DS_Stream_Ptr->std_phi[69];
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_ERR_071 = TOI_DS_Stream_Ptr->std_phi[70];
   data_ptr.SRR_FL_DETECTION_069_072.DET_ELEVATION_ERR_072 = TOI_DS_Stream_Ptr->std_phi[71];

   data_ptr.SRR_FL_DETECTION_069_072.DET_IDM_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_IDM_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_IDM_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_IDM_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_069_072.DET_MTD_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_MTD_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_MTD_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_MTD_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_069_072.DET_PROB_1STAZHYPO_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_PROB_1STAZHYPO_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_PROB_1STAZHYPO_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_PROB_1STAZHYPO_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_ERR_069 = TOI_DS_Stream_Ptr->std_ran[68];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_ERR_070 = TOI_DS_Stream_Ptr->std_ran[69];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_ERR_071 = TOI_DS_Stream_Ptr->std_ran[70];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_ERR_072 = TOI_DS_Stream_Ptr->std_ran[71];

   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_069 = af_target_report_ptr[68].vel;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_070 = af_target_report_ptr[69].vel;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_071 = af_target_report_ptr[70].vel;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_072 = af_target_report_ptr[71].vel;

   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_069 = TOI_DS_Stream_Ptr->std_vel[68];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_070 = TOI_DS_Stream_Ptr->std_vel[69];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_071 = TOI_DS_Stream_Ptr->std_vel[70];
   data_ptr.SRR_FL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_072 = TOI_DS_Stream_Ptr->std_vel[71];

   data_ptr.SRR_FL_DETECTION_069_072.DET_RCS_069 = af_target_report_ptr[68].rcs;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RCS_070 = af_target_report_ptr[69].rcs;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RCS_071 = af_target_report_ptr[70].rcs;
   data_ptr.SRR_FL_DETECTION_069_072.DET_RCS_072 = af_target_report_ptr[71].rcs;

   data_ptr.SRR_FL_DETECTION_069_072.DET_SNR_069 = af_target_report_ptr[68].snr;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SNR_070 = af_target_report_ptr[69].snr;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SNR_071 = af_target_report_ptr[70].snr;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SNR_072 = af_target_report_ptr[71].snr;

   data_ptr.SRR_FL_DETECTION_069_072.DET_SUPER_RES_TARGET_069 = af_target_report_ptr[68].f_superres_target;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SUPER_RES_TARGET_070 = af_target_report_ptr[69].f_superres_target;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SUPER_RES_TARGET_071 = af_target_report_ptr[70].f_superres_target;
   data_ptr.SRR_FL_DETECTION_069_072.DET_SUPER_RES_TARGET_072 = af_target_report_ptr[71].f_superres_target;

   data_ptr.SRR_FL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_069 = 0;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_070 = 0;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_071 = 0;
   data_ptr.SRR_FL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_072 = 0;

   data_ptr.SRR_FL_DETECTION_069_072.DET_HVC_FLAG_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_HVC_FLAG_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_HVC_FLAG_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_069_072.DET_HVC_FLAG_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_069_072.DET_MH_CYCLE_COUNTER_069_072   = 0;
   data_ptr.SRR_FL_DETECTION_069_072.DET_MH_CRC16_069_072           = 0;
   data_ptr.SRR_FL_DETECTION_069_072.DET_MH_SCAN_INDEX_4LSB_069_072 = 0;

   // SRR_FL_DETECTION_073_076_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_073 = af_target_report_ptr[72].ran;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_074 = af_target_report_ptr[73].ran;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_075 = af_target_report_ptr[74].ran;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_076 = af_target_report_ptr[75].ran;

   data_ptr.SRR_FL_DETECTION_073_076.DET_AZIMUTH_073 = af_target_report_ptr[72].theta;
   data_ptr.SRR_FL_DETECTION_073_076.DET_AZIMUTH_074 = af_target_report_ptr[73].theta;
   data_ptr.SRR_FL_DETECTION_073_076.DET_AZIMUTH_075 = af_target_report_ptr[74].theta;
   data_ptr.SRR_FL_DETECTION_073_076.DET_AZIMUTH_076 = af_target_report_ptr[75].theta;

   data_ptr.SRR_FL_DETECTION_073_076.DET_BI_STATIC_FLAG_073 = af_target_report_ptr[72].f_bistatic;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BI_STATIC_FLAG_074 = af_target_report_ptr[73].f_bistatic;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BI_STATIC_FLAG_075 = af_target_report_ptr[74].f_bistatic;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BI_STATIC_FLAG_076 = af_target_report_ptr[75].f_bistatic;

   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_AZIMUTH_073 = af_target_report_ptr[72].az_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_AZIMUTH_074 = af_target_report_ptr[73].az_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_AZIMUTH_075 = af_target_report_ptr[74].az_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_AZIMUTH_076 = af_target_report_ptr[75].az_conf;

   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_073 = af_target_report_ptr[72].phi;
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_074 = af_target_report_ptr[73].phi;
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_075 = af_target_report_ptr[74].phi;
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_076 = af_target_report_ptr[75].phi;

   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_ELEVATION_073 = af_target_report_ptr[72].el_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_ELEVATION_074 = af_target_report_ptr[73].el_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_ELEVATION_075 = af_target_report_ptr[74].el_conf;
   data_ptr.SRR_FL_DETECTION_073_076.DET_CONFD_ELEVATION_076 = af_target_report_ptr[75].el_conf;

   data_ptr.SRR_FL_DETECTION_073_076.DET_EXISTENCE_PROB_073 = TOI_DS_Stream_Ptr->existence_prob[72];
   data_ptr.SRR_FL_DETECTION_073_076.DET_EXISTENCE_PROB_074 = TOI_DS_Stream_Ptr->existence_prob[73];
   data_ptr.SRR_FL_DETECTION_073_076.DET_EXISTENCE_PROB_075 = TOI_DS_Stream_Ptr->existence_prob[74];
   data_ptr.SRR_FL_DETECTION_073_076.DET_EXISTENCE_PROB_076 = TOI_DS_Stream_Ptr->existence_prob[75];

   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_ERR_073 = TOI_DS_Stream_Ptr->std_phi[72];
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_ERR_074 = TOI_DS_Stream_Ptr->std_phi[73];
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_ERR_075 = TOI_DS_Stream_Ptr->std_phi[74];
   data_ptr.SRR_FL_DETECTION_073_076.DET_ELEVATION_ERR_076 = TOI_DS_Stream_Ptr->std_phi[75];

   data_ptr.SRR_FL_DETECTION_073_076.DET_IDM_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_IDM_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_IDM_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_IDM_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_073_076.DET_MTD_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_MTD_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_MTD_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_MTD_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_073_076.DET_PROB_1STAZHYPO_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_PROB_1STAZHYPO_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_PROB_1STAZHYPO_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_PROB_1STAZHYPO_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_ERR_073 = TOI_DS_Stream_Ptr->std_ran[72];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_ERR_074 = TOI_DS_Stream_Ptr->std_ran[73];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_ERR_075 = TOI_DS_Stream_Ptr->std_ran[74];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_ERR_076 = TOI_DS_Stream_Ptr->std_ran[75];

   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_073 = af_target_report_ptr[72].vel;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_074 = af_target_report_ptr[73].vel;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_075 = af_target_report_ptr[74].vel;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_076 = af_target_report_ptr[75].vel;

   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_073 = TOI_DS_Stream_Ptr->std_vel[72];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_074 = TOI_DS_Stream_Ptr->std_vel[73];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_075 = TOI_DS_Stream_Ptr->std_vel[74];
   data_ptr.SRR_FL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_076 = TOI_DS_Stream_Ptr->std_vel[75];

   data_ptr.SRR_FL_DETECTION_073_076.DET_RCS_073 = af_target_report_ptr[72].rcs;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RCS_074 = af_target_report_ptr[73].rcs;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RCS_075 = af_target_report_ptr[74].rcs;
   data_ptr.SRR_FL_DETECTION_073_076.DET_RCS_076 = af_target_report_ptr[75].rcs;

   data_ptr.SRR_FL_DETECTION_073_076.DET_SNR_073 = af_target_report_ptr[72].snr;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SNR_074 = af_target_report_ptr[73].snr;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SNR_075 = af_target_report_ptr[74].snr;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SNR_076 = af_target_report_ptr[75].snr;

   data_ptr.SRR_FL_DETECTION_073_076.DET_SUPER_RES_TARGET_073 = af_target_report_ptr[72].f_superres_target;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SUPER_RES_TARGET_074 = af_target_report_ptr[73].f_superres_target;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SUPER_RES_TARGET_075 = af_target_report_ptr[74].f_superres_target;
   data_ptr.SRR_FL_DETECTION_073_076.DET_SUPER_RES_TARGET_076 = af_target_report_ptr[75].f_superres_target;

   data_ptr.SRR_FL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_073 = 0;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_074 = 0;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_075 = 0;
   data_ptr.SRR_FL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_076 = 0;

   data_ptr.SRR_FL_DETECTION_073_076.DET_HVC_FLAG_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_HVC_FLAG_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_HVC_FLAG_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_073_076.DET_HVC_FLAG_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_073_076.DET_MH_CYCLE_COUNTER_073_076   = 0;
   data_ptr.SRR_FL_DETECTION_073_076.DET_MH_CRC16_073_076           = 0;
   data_ptr.SRR_FL_DETECTION_073_076.DET_MH_SCAN_INDEX_4LSB_073_076 = 0;

   // SRR_FL_DETECTION_077_080_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_077 = af_target_report_ptr[76].ran;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_078 = af_target_report_ptr[77].ran;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_079 = af_target_report_ptr[78].ran;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_080 = af_target_report_ptr[79].ran;

   data_ptr.SRR_FL_DETECTION_077_080.DET_AZIMUTH_077 = af_target_report_ptr[76].theta;
   data_ptr.SRR_FL_DETECTION_077_080.DET_AZIMUTH_078 = af_target_report_ptr[77].theta;
   data_ptr.SRR_FL_DETECTION_077_080.DET_AZIMUTH_079 = af_target_report_ptr[78].theta;
   data_ptr.SRR_FL_DETECTION_077_080.DET_AZIMUTH_080 = af_target_report_ptr[79].theta;

   data_ptr.SRR_FL_DETECTION_077_080.DET_BI_STATIC_FLAG_077 = af_target_report_ptr[76].f_bistatic;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BI_STATIC_FLAG_078 = af_target_report_ptr[77].f_bistatic;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BI_STATIC_FLAG_079 = af_target_report_ptr[78].f_bistatic;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BI_STATIC_FLAG_080 = af_target_report_ptr[79].f_bistatic;

   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_AZIMUTH_077 = af_target_report_ptr[76].az_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_AZIMUTH_078 = af_target_report_ptr[77].az_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_AZIMUTH_079 = af_target_report_ptr[78].az_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_AZIMUTH_080 = af_target_report_ptr[79].az_conf;

   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_077 = af_target_report_ptr[76].phi;
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_078 = af_target_report_ptr[77].phi;
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_079 = af_target_report_ptr[78].phi;
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_080 = af_target_report_ptr[79].phi;

   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_ELEVATION_077 = af_target_report_ptr[76].el_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_ELEVATION_078 = af_target_report_ptr[77].el_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_ELEVATION_079 = af_target_report_ptr[78].el_conf;
   data_ptr.SRR_FL_DETECTION_077_080.DET_CONFD_ELEVATION_080 = af_target_report_ptr[79].el_conf;

   data_ptr.SRR_FL_DETECTION_077_080.DET_EXISTENCE_PROB_077 = TOI_DS_Stream_Ptr->existence_prob[76];
   data_ptr.SRR_FL_DETECTION_077_080.DET_EXISTENCE_PROB_078 = TOI_DS_Stream_Ptr->existence_prob[77];
   data_ptr.SRR_FL_DETECTION_077_080.DET_EXISTENCE_PROB_079 = TOI_DS_Stream_Ptr->existence_prob[78];
   data_ptr.SRR_FL_DETECTION_077_080.DET_EXISTENCE_PROB_080 = TOI_DS_Stream_Ptr->existence_prob[79];

   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_ERR_077 = TOI_DS_Stream_Ptr->std_phi[76];
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_ERR_078 = TOI_DS_Stream_Ptr->std_phi[77];
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_ERR_079 = TOI_DS_Stream_Ptr->std_phi[78];
   data_ptr.SRR_FL_DETECTION_077_080.DET_ELEVATION_ERR_080 = TOI_DS_Stream_Ptr->std_phi[79];

   data_ptr.SRR_FL_DETECTION_077_080.DET_IDM_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_IDM_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_IDM_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_IDM_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_077_080.DET_MTD_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_MTD_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_MTD_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_MTD_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_077_080.DET_PROB_1STAZHYPO_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_PROB_1STAZHYPO_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_PROB_1STAZHYPO_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_PROB_1STAZHYPO_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_ERR_077 = TOI_DS_Stream_Ptr->std_ran[76];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_ERR_078 = TOI_DS_Stream_Ptr->std_ran[77];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_ERR_079 = TOI_DS_Stream_Ptr->std_ran[78];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_ERR_080 = TOI_DS_Stream_Ptr->std_ran[79];

   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_077 = af_target_report_ptr[76].vel;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_078 = af_target_report_ptr[77].vel;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_079 = af_target_report_ptr[78].vel;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_080 = af_target_report_ptr[79].vel;

   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_077 = TOI_DS_Stream_Ptr->std_vel[76];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_078 = TOI_DS_Stream_Ptr->std_vel[77];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_079 = TOI_DS_Stream_Ptr->std_vel[78];
   data_ptr.SRR_FL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_080 = TOI_DS_Stream_Ptr->std_vel[79];

   data_ptr.SRR_FL_DETECTION_077_080.DET_RCS_077 = af_target_report_ptr[76].rcs;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RCS_078 = af_target_report_ptr[77].rcs;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RCS_079 = af_target_report_ptr[78].rcs;
   data_ptr.SRR_FL_DETECTION_077_080.DET_RCS_080 = af_target_report_ptr[79].rcs;

   data_ptr.SRR_FL_DETECTION_077_080.DET_SNR_077 = af_target_report_ptr[76].snr;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SNR_078 = af_target_report_ptr[77].snr;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SNR_079 = af_target_report_ptr[78].snr;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SNR_080 = af_target_report_ptr[79].snr;

   data_ptr.SRR_FL_DETECTION_077_080.DET_SUPER_RES_TARGET_077 = af_target_report_ptr[76].f_superres_target;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SUPER_RES_TARGET_078 = af_target_report_ptr[77].f_superres_target;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SUPER_RES_TARGET_079 = af_target_report_ptr[78].f_superres_target;
   data_ptr.SRR_FL_DETECTION_077_080.DET_SUPER_RES_TARGET_080 = af_target_report_ptr[79].f_superres_target;

   data_ptr.SRR_FL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_077 = 0;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_078 = 0;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_079 = 0;
   data_ptr.SRR_FL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_080 = 0;

   data_ptr.SRR_FL_DETECTION_077_080.DET_HVC_FLAG_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_HVC_FLAG_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_HVC_FLAG_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_077_080.DET_HVC_FLAG_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_077_080.DET_MH_CYCLE_COUNTER_077_080   = 0;
   data_ptr.SRR_FL_DETECTION_077_080.DET_MH_CRC16_077_080           = 0;
   data_ptr.SRR_FL_DETECTION_077_080.DET_MH_SCAN_INDEX_4LSB_077_080 = 0;

   // SRR_FL_DETECTION_081_084_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_081 = af_target_report_ptr[80].ran;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_082 = af_target_report_ptr[81].ran;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_083 = af_target_report_ptr[82].ran;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_084 = af_target_report_ptr[83].ran;

   data_ptr.SRR_FL_DETECTION_081_084.DET_AZIMUTH_081 = af_target_report_ptr[80].theta;
   data_ptr.SRR_FL_DETECTION_081_084.DET_AZIMUTH_082 = af_target_report_ptr[81].theta;
   data_ptr.SRR_FL_DETECTION_081_084.DET_AZIMUTH_083 = af_target_report_ptr[82].theta;
   data_ptr.SRR_FL_DETECTION_081_084.DET_AZIMUTH_084 = af_target_report_ptr[83].theta;

   data_ptr.SRR_FL_DETECTION_081_084.DET_BI_STATIC_FLAG_081 = af_target_report_ptr[80].f_bistatic;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BI_STATIC_FLAG_082 = af_target_report_ptr[81].f_bistatic;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BI_STATIC_FLAG_083 = af_target_report_ptr[82].f_bistatic;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BI_STATIC_FLAG_084 = af_target_report_ptr[83].f_bistatic;

   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_AZIMUTH_081 = af_target_report_ptr[80].az_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_AZIMUTH_082 = af_target_report_ptr[81].az_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_AZIMUTH_083 = af_target_report_ptr[82].az_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_AZIMUTH_084 = af_target_report_ptr[83].az_conf;

   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_081 = af_target_report_ptr[80].phi;
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_082 = af_target_report_ptr[81].phi;
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_083 = af_target_report_ptr[82].phi;
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_084 = af_target_report_ptr[83].phi;

   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_ELEVATION_081 = af_target_report_ptr[80].el_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_ELEVATION_082 = af_target_report_ptr[81].el_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_ELEVATION_083 = af_target_report_ptr[82].el_conf;
   data_ptr.SRR_FL_DETECTION_081_084.DET_CONFD_ELEVATION_084 = af_target_report_ptr[83].el_conf;

   data_ptr.SRR_FL_DETECTION_081_084.DET_EXISTENCE_PROB_081 = TOI_DS_Stream_Ptr->existence_prob[80];
   data_ptr.SRR_FL_DETECTION_081_084.DET_EXISTENCE_PROB_082 = TOI_DS_Stream_Ptr->existence_prob[81];
   data_ptr.SRR_FL_DETECTION_081_084.DET_EXISTENCE_PROB_083 = TOI_DS_Stream_Ptr->existence_prob[82];
   data_ptr.SRR_FL_DETECTION_081_084.DET_EXISTENCE_PROB_084 = TOI_DS_Stream_Ptr->existence_prob[83];

   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_ERR_081 = TOI_DS_Stream_Ptr->std_phi[80];
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_ERR_082 = TOI_DS_Stream_Ptr->std_phi[81];
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_ERR_083 = TOI_DS_Stream_Ptr->std_phi[82];
   data_ptr.SRR_FL_DETECTION_081_084.DET_ELEVATION_ERR_084 = TOI_DS_Stream_Ptr->std_phi[83];

   data_ptr.SRR_FL_DETECTION_081_084.DET_IDM_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_IDM_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_IDM_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_IDM_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_081_084.DET_MTD_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_MTD_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_MTD_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_MTD_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_081_084.DET_PROB_1STAZHYPO_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_PROB_1STAZHYPO_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_PROB_1STAZHYPO_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_PROB_1STAZHYPO_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_ERR_081 = TOI_DS_Stream_Ptr->std_ran[80];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_ERR_082 = TOI_DS_Stream_Ptr->std_ran[81];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_ERR_083 = TOI_DS_Stream_Ptr->std_ran[82];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_ERR_084 = TOI_DS_Stream_Ptr->std_ran[83];

   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_081 = af_target_report_ptr[80].vel;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_082 = af_target_report_ptr[81].vel;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_083 = af_target_report_ptr[82].vel;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_084 = af_target_report_ptr[83].vel;

   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_081 = TOI_DS_Stream_Ptr->std_vel[80];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_082 = TOI_DS_Stream_Ptr->std_vel[81];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_083 = TOI_DS_Stream_Ptr->std_vel[82];
   data_ptr.SRR_FL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_084 = TOI_DS_Stream_Ptr->std_vel[83];

   data_ptr.SRR_FL_DETECTION_081_084.DET_RCS_081 = af_target_report_ptr[80].rcs;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RCS_082 = af_target_report_ptr[81].rcs;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RCS_083 = af_target_report_ptr[82].rcs;
   data_ptr.SRR_FL_DETECTION_081_084.DET_RCS_084 = af_target_report_ptr[83].rcs;

   data_ptr.SRR_FL_DETECTION_081_084.DET_SNR_081 = af_target_report_ptr[80].snr;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SNR_082 = af_target_report_ptr[81].snr;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SNR_083 = af_target_report_ptr[82].snr;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SNR_084 = af_target_report_ptr[83].snr;

   data_ptr.SRR_FL_DETECTION_081_084.DET_SUPER_RES_TARGET_081 = af_target_report_ptr[80].f_superres_target;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SUPER_RES_TARGET_082 = af_target_report_ptr[81].f_superres_target;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SUPER_RES_TARGET_083 = af_target_report_ptr[82].f_superres_target;
   data_ptr.SRR_FL_DETECTION_081_084.DET_SUPER_RES_TARGET_084 = af_target_report_ptr[83].f_superres_target;

   data_ptr.SRR_FL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_081 = 0;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_082 = 0;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_083 = 0;
   data_ptr.SRR_FL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_084 = 0;

   data_ptr.SRR_FL_DETECTION_081_084.DET_HVC_FLAG_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_HVC_FLAG_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_HVC_FLAG_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_081_084.DET_HVC_FLAG_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_081_084.DET_MH_CYCLE_COUNTER_081_084   = 0;
   data_ptr.SRR_FL_DETECTION_081_084.DET_MH_CRC16_081_084           = 0;
   data_ptr.SRR_FL_DETECTION_081_084.DET_MH_SCAN_INDEX_4LSB_081_084 = 0;

   // SRR_FL_DETECTION_085_088_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // SRR_FL_DETECTION_089_092_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.SRR_FL_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.SRR_FL_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.SRR_FL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.SRR_FL_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.SRR_FL_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.SRR_FL_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // SRR_FL_DETECTION_093_096_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_093 = af_target_report_ptr[92].ran;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_094 = af_target_report_ptr[93].ran;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_095 = af_target_report_ptr[94].ran;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_096 = af_target_report_ptr[95].ran;

   data_ptr.SRR_FL_DETECTION_093_096.DET_AZIMUTH_093 = af_target_report_ptr[92].theta;
   data_ptr.SRR_FL_DETECTION_093_096.DET_AZIMUTH_094 = af_target_report_ptr[93].theta;
   data_ptr.SRR_FL_DETECTION_093_096.DET_AZIMUTH_095 = af_target_report_ptr[94].theta;
   data_ptr.SRR_FL_DETECTION_093_096.DET_AZIMUTH_096 = af_target_report_ptr[95].theta;

   data_ptr.SRR_FL_DETECTION_093_096.DET_BI_STATIC_FLAG_093 = af_target_report_ptr[92].f_bistatic;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BI_STATIC_FLAG_094 = af_target_report_ptr[93].f_bistatic;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BI_STATIC_FLAG_095 = af_target_report_ptr[94].f_bistatic;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BI_STATIC_FLAG_096 = af_target_report_ptr[95].f_bistatic;

   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_AZIMUTH_093 = af_target_report_ptr[92].az_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_AZIMUTH_094 = af_target_report_ptr[93].az_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_AZIMUTH_095 = af_target_report_ptr[94].az_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_AZIMUTH_096 = af_target_report_ptr[95].az_conf;

   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_093 = af_target_report_ptr[92].phi;
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_094 = af_target_report_ptr[93].phi;
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_095 = af_target_report_ptr[94].phi;
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_096 = af_target_report_ptr[95].phi;

   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_ELEVATION_093 = af_target_report_ptr[92].el_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_ELEVATION_094 = af_target_report_ptr[93].el_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_ELEVATION_095 = af_target_report_ptr[94].el_conf;
   data_ptr.SRR_FL_DETECTION_093_096.DET_CONFD_ELEVATION_096 = af_target_report_ptr[95].el_conf;

   data_ptr.SRR_FL_DETECTION_093_096.DET_EXISTENCE_PROB_093 = TOI_DS_Stream_Ptr->existence_prob[92];
   data_ptr.SRR_FL_DETECTION_093_096.DET_EXISTENCE_PROB_094 = TOI_DS_Stream_Ptr->existence_prob[93];
   data_ptr.SRR_FL_DETECTION_093_096.DET_EXISTENCE_PROB_095 = TOI_DS_Stream_Ptr->existence_prob[94];
   data_ptr.SRR_FL_DETECTION_093_096.DET_EXISTENCE_PROB_096 = TOI_DS_Stream_Ptr->existence_prob[95];

   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_ERR_093 = TOI_DS_Stream_Ptr->std_phi[92];
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_ERR_094 = TOI_DS_Stream_Ptr->std_phi[93];
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_ERR_095 = TOI_DS_Stream_Ptr->std_phi[94];
   data_ptr.SRR_FL_DETECTION_093_096.DET_ELEVATION_ERR_096 = TOI_DS_Stream_Ptr->std_phi[95];

   data_ptr.SRR_FL_DETECTION_093_096.DET_IDM_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_IDM_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_IDM_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_IDM_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_093_096.DET_MTD_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_MTD_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_MTD_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_MTD_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_093_096.DET_PROB_1STAZHYPO_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_PROB_1STAZHYPO_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_PROB_1STAZHYPO_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_PROB_1STAZHYPO_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_ERR_093 = TOI_DS_Stream_Ptr->std_ran[92];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_ERR_094 = TOI_DS_Stream_Ptr->std_ran[93];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_ERR_095 = TOI_DS_Stream_Ptr->std_ran[94];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_ERR_096 = TOI_DS_Stream_Ptr->std_ran[95];

   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_093 = af_target_report_ptr[92].vel;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_094 = af_target_report_ptr[93].vel;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_095 = af_target_report_ptr[94].vel;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_096 = af_target_report_ptr[95].vel;

   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_093 = TOI_DS_Stream_Ptr->std_vel[92];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_094 = TOI_DS_Stream_Ptr->std_vel[93];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_095 = TOI_DS_Stream_Ptr->std_vel[94];
   data_ptr.SRR_FL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_096 = TOI_DS_Stream_Ptr->std_vel[95];

   data_ptr.SRR_FL_DETECTION_093_096.DET_RCS_093 = af_target_report_ptr[92].rcs;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RCS_094 = af_target_report_ptr[93].rcs;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RCS_095 = af_target_report_ptr[94].rcs;
   data_ptr.SRR_FL_DETECTION_093_096.DET_RCS_096 = af_target_report_ptr[95].rcs;

   data_ptr.SRR_FL_DETECTION_093_096.DET_SNR_093 = af_target_report_ptr[92].snr;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SNR_094 = af_target_report_ptr[93].snr;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SNR_095 = af_target_report_ptr[94].snr;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SNR_096 = af_target_report_ptr[95].snr;

   data_ptr.SRR_FL_DETECTION_093_096.DET_SUPER_RES_TARGET_093 = af_target_report_ptr[92].f_superres_target;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SUPER_RES_TARGET_094 = af_target_report_ptr[93].f_superres_target;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SUPER_RES_TARGET_095 = af_target_report_ptr[94].f_superres_target;
   data_ptr.SRR_FL_DETECTION_093_096.DET_SUPER_RES_TARGET_096 = af_target_report_ptr[95].f_superres_target;

   data_ptr.SRR_FL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_093 = 0;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_094 = 0;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_095 = 0;
   data_ptr.SRR_FL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_096 = 0;

   data_ptr.SRR_FL_DETECTION_093_096.DET_HVC_FLAG_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_HVC_FLAG_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_HVC_FLAG_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_093_096.DET_HVC_FLAG_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_093_096.DET_MH_CYCLE_COUNTER_093_096   = 0;
   data_ptr.SRR_FL_DETECTION_093_096.DET_MH_CRC16_093_096           = 0;
   data_ptr.SRR_FL_DETECTION_093_096.DET_MH_SCAN_INDEX_4LSB_093_096 = 0;

   // SRR_FL_DETECTION_097_100_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_097 = af_target_report_ptr[96].ran;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_098 = af_target_report_ptr[97].ran;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_099 = af_target_report_ptr[98].ran;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_100 = af_target_report_ptr[99].ran;

   data_ptr.SRR_FL_DETECTION_097_100.DET_AZIMUTH_097 = af_target_report_ptr[96].theta;
   data_ptr.SRR_FL_DETECTION_097_100.DET_AZIMUTH_098 = af_target_report_ptr[97].theta;
   data_ptr.SRR_FL_DETECTION_097_100.DET_AZIMUTH_099 = af_target_report_ptr[98].theta;
   data_ptr.SRR_FL_DETECTION_097_100.DET_AZIMUTH_100 = af_target_report_ptr[99].theta;

   data_ptr.SRR_FL_DETECTION_097_100.DET_BI_STATIC_FLAG_097 = af_target_report_ptr[96].f_bistatic;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BI_STATIC_FLAG_098 = af_target_report_ptr[97].f_bistatic;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BI_STATIC_FLAG_099 = af_target_report_ptr[98].f_bistatic;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BI_STATIC_FLAG_100 = af_target_report_ptr[99].f_bistatic;

   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_AZIMUTH_097 = af_target_report_ptr[96].az_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_AZIMUTH_098 = af_target_report_ptr[97].az_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_AZIMUTH_099 = af_target_report_ptr[98].az_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_AZIMUTH_100 = af_target_report_ptr[99].az_conf;

   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_097 = af_target_report_ptr[96].phi;
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_098 = af_target_report_ptr[97].phi;
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_099 = af_target_report_ptr[98].phi;
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_100 = af_target_report_ptr[99].phi;

   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_ELEVATION_097 = af_target_report_ptr[96].el_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_ELEVATION_098 = af_target_report_ptr[97].el_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_ELEVATION_099 = af_target_report_ptr[98].el_conf;
   data_ptr.SRR_FL_DETECTION_097_100.DET_CONFD_ELEVATION_100 = af_target_report_ptr[99].el_conf;

   data_ptr.SRR_FL_DETECTION_097_100.DET_EXISTENCE_PROB_097 = TOI_DS_Stream_Ptr->existence_prob[96];
   data_ptr.SRR_FL_DETECTION_097_100.DET_EXISTENCE_PROB_098 = TOI_DS_Stream_Ptr->existence_prob[97];
   data_ptr.SRR_FL_DETECTION_097_100.DET_EXISTENCE_PROB_099 = TOI_DS_Stream_Ptr->existence_prob[98];
   data_ptr.SRR_FL_DETECTION_097_100.DET_EXISTENCE_PROB_100 = TOI_DS_Stream_Ptr->existence_prob[99];

   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_ERR_097 = TOI_DS_Stream_Ptr->std_phi[96];
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_ERR_098 = TOI_DS_Stream_Ptr->std_phi[97];
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_ERR_099 = TOI_DS_Stream_Ptr->std_phi[98];
   data_ptr.SRR_FL_DETECTION_097_100.DET_ELEVATION_ERR_100 = TOI_DS_Stream_Ptr->std_phi[99];

   data_ptr.SRR_FL_DETECTION_097_100.DET_IDM_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_IDM_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_IDM_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_IDM_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_097_100.DET_MTD_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_MTD_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_MTD_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_MTD_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_097_100.DET_PROB_1STAZHYPO_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_PROB_1STAZHYPO_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_PROB_1STAZHYPO_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_PROB_1STAZHYPO_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_ERR_097 = TOI_DS_Stream_Ptr->std_ran[96];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_ERR_098 = TOI_DS_Stream_Ptr->std_ran[97];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_ERR_099 = TOI_DS_Stream_Ptr->std_ran[98];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_ERR_100 = TOI_DS_Stream_Ptr->std_ran[99];

   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_097 = af_target_report_ptr[96].vel;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_098 = af_target_report_ptr[97].vel;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_099 = af_target_report_ptr[98].vel;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_100 = af_target_report_ptr[99].vel;

   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_097 = TOI_DS_Stream_Ptr->std_vel[96];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_098 = TOI_DS_Stream_Ptr->std_vel[97];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_099 = TOI_DS_Stream_Ptr->std_vel[98];
   data_ptr.SRR_FL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_100 = TOI_DS_Stream_Ptr->std_vel[99];

   data_ptr.SRR_FL_DETECTION_097_100.DET_RCS_097 = af_target_report_ptr[96].rcs;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RCS_098 = af_target_report_ptr[97].rcs;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RCS_099 = af_target_report_ptr[98].rcs;
   data_ptr.SRR_FL_DETECTION_097_100.DET_RCS_100 = af_target_report_ptr[99].rcs;

   data_ptr.SRR_FL_DETECTION_097_100.DET_SNR_097 = af_target_report_ptr[96].snr;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SNR_098 = af_target_report_ptr[97].snr;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SNR_099 = af_target_report_ptr[98].snr;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SNR_100 = af_target_report_ptr[99].snr;

   data_ptr.SRR_FL_DETECTION_097_100.DET_SUPER_RES_TARGET_097 = af_target_report_ptr[96].f_superres_target;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SUPER_RES_TARGET_098 = af_target_report_ptr[97].f_superres_target;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SUPER_RES_TARGET_099 = af_target_report_ptr[98].f_superres_target;
   data_ptr.SRR_FL_DETECTION_097_100.DET_SUPER_RES_TARGET_100 = af_target_report_ptr[99].f_superres_target;

   data_ptr.SRR_FL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_097 = 0;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_098 = 0;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_099 = 0;
   data_ptr.SRR_FL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_100 = 0;

   data_ptr.SRR_FL_DETECTION_097_100.DET_HVC_FLAG_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_HVC_FLAG_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_HVC_FLAG_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_097_100.DET_HVC_FLAG_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_097_100.DET_MH_CYCLE_COUNTER_097_100   = 0;
   data_ptr.SRR_FL_DETECTION_097_100.DET_MH_CRC16_097_100           = 0;
   data_ptr.SRR_FL_DETECTION_097_100.DET_MH_SCAN_INDEX_4LSB_097_100 = 0;

   // SRR_FL_DETECTION_101_104_decoded_msg_t

   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_101 = af_target_report_ptr[100].ran;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_102 = af_target_report_ptr[101].ran;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_103 = af_target_report_ptr[102].ran;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_104 = af_target_report_ptr[103].ran;

   data_ptr.SRR_FL_DETECTION_101_104.DET_AZIMUTH_101 = af_target_report_ptr[100].theta;
   data_ptr.SRR_FL_DETECTION_101_104.DET_AZIMUTH_102 = af_target_report_ptr[101].theta;
   data_ptr.SRR_FL_DETECTION_101_104.DET_AZIMUTH_103 = af_target_report_ptr[102].theta;
   data_ptr.SRR_FL_DETECTION_101_104.DET_AZIMUTH_104 = af_target_report_ptr[103].theta;

   data_ptr.SRR_FL_DETECTION_101_104.DET_BI_STATIC_FLAG_101 = af_target_report_ptr[100].f_bistatic;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BI_STATIC_FLAG_102 = af_target_report_ptr[101].f_bistatic;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BI_STATIC_FLAG_103 = af_target_report_ptr[102].f_bistatic;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BI_STATIC_FLAG_104 = af_target_report_ptr[103].f_bistatic;

   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_AZIMUTH_101 = af_target_report_ptr[100].az_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_AZIMUTH_102 = af_target_report_ptr[101].az_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_AZIMUTH_103 = af_target_report_ptr[102].az_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_AZIMUTH_104 = af_target_report_ptr[103].az_conf;

   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_101 = af_target_report_ptr[100].phi;
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_102 = af_target_report_ptr[101].phi;
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_103 = af_target_report_ptr[102].phi;
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_104 = af_target_report_ptr[103].phi;

   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_ELEVATION_101 = af_target_report_ptr[100].el_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_ELEVATION_102 = af_target_report_ptr[101].el_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_ELEVATION_103 = af_target_report_ptr[102].el_conf;
   data_ptr.SRR_FL_DETECTION_101_104.DET_CONFD_ELEVATION_104 = af_target_report_ptr[103].el_conf;

   data_ptr.SRR_FL_DETECTION_101_104.DET_EXISTENCE_PROB_101 = TOI_DS_Stream_Ptr->existence_prob[100];
   data_ptr.SRR_FL_DETECTION_101_104.DET_EXISTENCE_PROB_102 = TOI_DS_Stream_Ptr->existence_prob[101];
   data_ptr.SRR_FL_DETECTION_101_104.DET_EXISTENCE_PROB_103 = TOI_DS_Stream_Ptr->existence_prob[102];
   data_ptr.SRR_FL_DETECTION_101_104.DET_EXISTENCE_PROB_104 = TOI_DS_Stream_Ptr->existence_prob[103];

   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_ERR_101 = TOI_DS_Stream_Ptr->std_phi[100];
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_ERR_102 = TOI_DS_Stream_Ptr->std_phi[101];
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_ERR_103 = TOI_DS_Stream_Ptr->std_phi[102];
   data_ptr.SRR_FL_DETECTION_101_104.DET_ELEVATION_ERR_104 = TOI_DS_Stream_Ptr->std_phi[103];

   data_ptr.SRR_FL_DETECTION_101_104.DET_IDM_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_IDM_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_IDM_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_IDM_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_101_104.DET_MTD_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_MTD_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_MTD_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_MTD_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_101_104.DET_PROB_1STAZHYPO_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_PROB_1STAZHYPO_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_PROB_1STAZHYPO_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_PROB_1STAZHYPO_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_ERR_101 = TOI_DS_Stream_Ptr->std_ran[100];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_ERR_102 = TOI_DS_Stream_Ptr->std_ran[101];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_ERR_103 = TOI_DS_Stream_Ptr->std_ran[102];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_ERR_104 = TOI_DS_Stream_Ptr->std_ran[103];

   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_101 = af_target_report_ptr[100].vel;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_102 = af_target_report_ptr[101].vel;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_103 = af_target_report_ptr[102].vel;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_104 = af_target_report_ptr[103].vel;

   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_101 = TOI_DS_Stream_Ptr->std_vel[100];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_102 = TOI_DS_Stream_Ptr->std_vel[101];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_103 = TOI_DS_Stream_Ptr->std_vel[102];
   data_ptr.SRR_FL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_104 = TOI_DS_Stream_Ptr->std_vel[103];

   data_ptr.SRR_FL_DETECTION_101_104.DET_RCS_101 = af_target_report_ptr[100].rcs;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RCS_102 = af_target_report_ptr[101].rcs;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RCS_103 = af_target_report_ptr[102].rcs;
   data_ptr.SRR_FL_DETECTION_101_104.DET_RCS_104 = af_target_report_ptr[103].rcs;

   data_ptr.SRR_FL_DETECTION_101_104.DET_SNR_101 = af_target_report_ptr[100].snr;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SNR_102 = af_target_report_ptr[101].snr;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SNR_103 = af_target_report_ptr[102].snr;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SNR_104 = af_target_report_ptr[103].snr;

   data_ptr.SRR_FL_DETECTION_101_104.DET_SUPER_RES_TARGET_101 = af_target_report_ptr[100].f_superres_target;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SUPER_RES_TARGET_102 = af_target_report_ptr[101].f_superres_target;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SUPER_RES_TARGET_103 = af_target_report_ptr[102].f_superres_target;
   data_ptr.SRR_FL_DETECTION_101_104.DET_SUPER_RES_TARGET_104 = af_target_report_ptr[103].f_superres_target;

   data_ptr.SRR_FL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_101 = 0;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_102 = 0;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_103 = 0;
   data_ptr.SRR_FL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_104 = 0;

   data_ptr.SRR_FL_DETECTION_101_104.DET_HVC_FLAG_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_HVC_FLAG_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_HVC_FLAG_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_101_104.DET_HVC_FLAG_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_101_104.DET_MH_CYCLE_COUNTER_101_104   = 0;
   data_ptr.SRR_FL_DETECTION_101_104.DET_MH_CRC16_101_104           = 0;
   data_ptr.SRR_FL_DETECTION_101_104.DET_MH_SCAN_INDEX_4LSB_101_104 = 0;

   // SRR_FL_DETECTION_105_108_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_105 = af_target_report_ptr[104].ran;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_106 = af_target_report_ptr[105].ran;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_107 = af_target_report_ptr[106].ran;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_108 = af_target_report_ptr[107].ran;

   data_ptr.SRR_FL_DETECTION_105_108.DET_AZIMUTH_105 = af_target_report_ptr[104].theta;
   data_ptr.SRR_FL_DETECTION_105_108.DET_AZIMUTH_106 = af_target_report_ptr[105].theta;
   data_ptr.SRR_FL_DETECTION_105_108.DET_AZIMUTH_107 = af_target_report_ptr[106].theta;
   data_ptr.SRR_FL_DETECTION_105_108.DET_AZIMUTH_108 = af_target_report_ptr[107].theta;

   data_ptr.SRR_FL_DETECTION_105_108.DET_BI_STATIC_FLAG_105 = af_target_report_ptr[104].f_bistatic;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BI_STATIC_FLAG_106 = af_target_report_ptr[105].f_bistatic;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BI_STATIC_FLAG_107 = af_target_report_ptr[106].f_bistatic;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BI_STATIC_FLAG_108 = af_target_report_ptr[107].f_bistatic;

   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_AZIMUTH_105 = af_target_report_ptr[104].az_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_AZIMUTH_106 = af_target_report_ptr[105].az_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_AZIMUTH_107 = af_target_report_ptr[106].az_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_AZIMUTH_108 = af_target_report_ptr[107].az_conf;

   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_105 = af_target_report_ptr[104].phi;
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_106 = af_target_report_ptr[105].phi;
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_107 = af_target_report_ptr[106].phi;
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_108 = af_target_report_ptr[107].phi;

   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_ELEVATION_105 = af_target_report_ptr[104].el_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_ELEVATION_106 = af_target_report_ptr[105].el_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_ELEVATION_107 = af_target_report_ptr[106].el_conf;
   data_ptr.SRR_FL_DETECTION_105_108.DET_CONFD_ELEVATION_108 = af_target_report_ptr[107].el_conf;

   data_ptr.SRR_FL_DETECTION_105_108.DET_EXISTENCE_PROB_105 = TOI_DS_Stream_Ptr->existence_prob[104];
   data_ptr.SRR_FL_DETECTION_105_108.DET_EXISTENCE_PROB_106 = TOI_DS_Stream_Ptr->existence_prob[105];
   data_ptr.SRR_FL_DETECTION_105_108.DET_EXISTENCE_PROB_107 = TOI_DS_Stream_Ptr->existence_prob[106];
   data_ptr.SRR_FL_DETECTION_105_108.DET_EXISTENCE_PROB_108 = TOI_DS_Stream_Ptr->existence_prob[107];

   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_ERR_105 = TOI_DS_Stream_Ptr->std_phi[104];
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_ERR_106 = TOI_DS_Stream_Ptr->std_phi[105];
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_ERR_107 = TOI_DS_Stream_Ptr->std_phi[106];
   data_ptr.SRR_FL_DETECTION_105_108.DET_ELEVATION_ERR_108 = TOI_DS_Stream_Ptr->std_phi[107];

   data_ptr.SRR_FL_DETECTION_105_108.DET_IDM_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_IDM_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_IDM_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_IDM_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_105_108.DET_MTD_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_MTD_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_MTD_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_MTD_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_105_108.DET_PROB_1STAZHYPO_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_PROB_1STAZHYPO_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_PROB_1STAZHYPO_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_PROB_1STAZHYPO_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_ERR_105 = TOI_DS_Stream_Ptr->std_ran[104];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_ERR_106 = TOI_DS_Stream_Ptr->std_ran[105];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_ERR_107 = TOI_DS_Stream_Ptr->std_ran[106];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_ERR_108 = TOI_DS_Stream_Ptr->std_ran[107];

   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_105 = af_target_report_ptr[104].vel;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_106 = af_target_report_ptr[105].vel;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_107 = af_target_report_ptr[106].vel;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_108 = af_target_report_ptr[107].vel;

   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_105 = TOI_DS_Stream_Ptr->std_vel[104];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_106 = TOI_DS_Stream_Ptr->std_vel[105];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_107 = TOI_DS_Stream_Ptr->std_vel[106];
   data_ptr.SRR_FL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_108 = TOI_DS_Stream_Ptr->std_vel[107];

   data_ptr.SRR_FL_DETECTION_105_108.DET_RCS_105 = af_target_report_ptr[104].rcs;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RCS_106 = af_target_report_ptr[105].rcs;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RCS_107 = af_target_report_ptr[106].rcs;
   data_ptr.SRR_FL_DETECTION_105_108.DET_RCS_108 = af_target_report_ptr[107].rcs;

   data_ptr.SRR_FL_DETECTION_105_108.DET_SNR_105 = af_target_report_ptr[104].snr;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SNR_106 = af_target_report_ptr[105].snr;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SNR_107 = af_target_report_ptr[106].snr;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SNR_108 = af_target_report_ptr[107].snr;

   data_ptr.SRR_FL_DETECTION_105_108.DET_SUPER_RES_TARGET_105 = af_target_report_ptr[104].f_superres_target;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SUPER_RES_TARGET_106 = af_target_report_ptr[105].f_superres_target;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SUPER_RES_TARGET_107 = af_target_report_ptr[106].f_superres_target;
   data_ptr.SRR_FL_DETECTION_105_108.DET_SUPER_RES_TARGET_108 = af_target_report_ptr[107].f_superres_target;

   data_ptr.SRR_FL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_105 = 0;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_106 = 0;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_107 = 0;
   data_ptr.SRR_FL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_108 = 0;

   data_ptr.SRR_FL_DETECTION_105_108.DET_HVC_FLAG_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_HVC_FLAG_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_HVC_FLAG_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_105_108.DET_HVC_FLAG_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_105_108.DET_MH_CYCLE_COUNTER_105_108   = 0;
   data_ptr.SRR_FL_DETECTION_105_108.DET_MH_CRC16_105_108           = 0;
   data_ptr.SRR_FL_DETECTION_105_108.DET_MH_SCAN_INDEX_4LSB_105_108 = 0;

   // SRR_FL_DETECTION_109_112_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_109 = af_target_report_ptr[108].ran;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_110 = af_target_report_ptr[109].ran;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_111 = af_target_report_ptr[110].ran;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_112 = af_target_report_ptr[111].ran;

   data_ptr.SRR_FL_DETECTION_109_112.DET_AZIMUTH_109 = af_target_report_ptr[108].theta;
   data_ptr.SRR_FL_DETECTION_109_112.DET_AZIMUTH_110 = af_target_report_ptr[109].theta;
   data_ptr.SRR_FL_DETECTION_109_112.DET_AZIMUTH_111 = af_target_report_ptr[110].theta;
   data_ptr.SRR_FL_DETECTION_109_112.DET_AZIMUTH_112 = af_target_report_ptr[111].theta;

   data_ptr.SRR_FL_DETECTION_109_112.DET_BI_STATIC_FLAG_109 = af_target_report_ptr[108].f_bistatic;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BI_STATIC_FLAG_110 = af_target_report_ptr[109].f_bistatic;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BI_STATIC_FLAG_111 = af_target_report_ptr[110].f_bistatic;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BI_STATIC_FLAG_112 = af_target_report_ptr[111].f_bistatic;

   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_AZIMUTH_109 = af_target_report_ptr[108].az_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_AZIMUTH_110 = af_target_report_ptr[109].az_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_AZIMUTH_111 = af_target_report_ptr[110].az_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_AZIMUTH_112 = af_target_report_ptr[111].az_conf;

   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_109 = af_target_report_ptr[108].phi;
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_110 = af_target_report_ptr[109].phi;
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_111 = af_target_report_ptr[110].phi;
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_112 = af_target_report_ptr[111].phi;

   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_ELEVATION_109 = af_target_report_ptr[108].el_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_ELEVATION_110 = af_target_report_ptr[109].el_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_ELEVATION_111 = af_target_report_ptr[110].el_conf;
   data_ptr.SRR_FL_DETECTION_109_112.DET_CONFD_ELEVATION_112 = af_target_report_ptr[111].el_conf;

   data_ptr.SRR_FL_DETECTION_109_112.DET_EXISTENCE_PROB_109 = TOI_DS_Stream_Ptr->existence_prob[108];
   data_ptr.SRR_FL_DETECTION_109_112.DET_EXISTENCE_PROB_110 = TOI_DS_Stream_Ptr->existence_prob[109];
   data_ptr.SRR_FL_DETECTION_109_112.DET_EXISTENCE_PROB_111 = TOI_DS_Stream_Ptr->existence_prob[110];
   data_ptr.SRR_FL_DETECTION_109_112.DET_EXISTENCE_PROB_112 = TOI_DS_Stream_Ptr->existence_prob[111];

   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_ERR_109 = TOI_DS_Stream_Ptr->std_phi[108];
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_ERR_110 = TOI_DS_Stream_Ptr->std_phi[109];
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_ERR_111 = TOI_DS_Stream_Ptr->std_phi[110];
   data_ptr.SRR_FL_DETECTION_109_112.DET_ELEVATION_ERR_112 = TOI_DS_Stream_Ptr->std_phi[111];

   data_ptr.SRR_FL_DETECTION_109_112.DET_IDM_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_IDM_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_IDM_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_IDM_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_109_112.DET_MTD_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_MTD_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_MTD_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_MTD_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_109_112.DET_PROB_1STAZHYPO_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_PROB_1STAZHYPO_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_PROB_1STAZHYPO_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_PROB_1STAZHYPO_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_ERR_109 = TOI_DS_Stream_Ptr->std_ran[108];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_ERR_110 = TOI_DS_Stream_Ptr->std_ran[109];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_ERR_111 = TOI_DS_Stream_Ptr->std_ran[110];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_ERR_112 = TOI_DS_Stream_Ptr->std_ran[111];

   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_109 = af_target_report_ptr[108].vel;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_110 = af_target_report_ptr[109].vel;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_111 = af_target_report_ptr[110].vel;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_112 = af_target_report_ptr[111].vel;

   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_109 = TOI_DS_Stream_Ptr->std_vel[108];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_110 = TOI_DS_Stream_Ptr->std_vel[109];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_111 = TOI_DS_Stream_Ptr->std_vel[110];
   data_ptr.SRR_FL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_112 = TOI_DS_Stream_Ptr->std_vel[111];

   data_ptr.SRR_FL_DETECTION_109_112.DET_RCS_109 = af_target_report_ptr[108].rcs;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RCS_110 = af_target_report_ptr[109].rcs;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RCS_111 = af_target_report_ptr[110].rcs;
   data_ptr.SRR_FL_DETECTION_109_112.DET_RCS_112 = af_target_report_ptr[111].rcs;

   data_ptr.SRR_FL_DETECTION_109_112.DET_SNR_109 = af_target_report_ptr[108].snr;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SNR_110 = af_target_report_ptr[109].snr;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SNR_111 = af_target_report_ptr[110].snr;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SNR_112 = af_target_report_ptr[111].snr;

   data_ptr.SRR_FL_DETECTION_109_112.DET_SUPER_RES_TARGET_109 = af_target_report_ptr[108].f_superres_target;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SUPER_RES_TARGET_110 = af_target_report_ptr[109].f_superres_target;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SUPER_RES_TARGET_111 = af_target_report_ptr[110].f_superres_target;
   data_ptr.SRR_FL_DETECTION_109_112.DET_SUPER_RES_TARGET_112 = af_target_report_ptr[111].f_superres_target;

   data_ptr.SRR_FL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_109 = 0;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_110 = 0;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_111 = 0;
   data_ptr.SRR_FL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_112 = 0;

   data_ptr.SRR_FL_DETECTION_109_112.DET_HVC_FLAG_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_HVC_FLAG_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_HVC_FLAG_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_109_112.DET_HVC_FLAG_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_109_112.DET_MH_CYCLE_COUNTER_109_112   = 0;
   data_ptr.SRR_FL_DETECTION_109_112.DET_MH_CRC16_109_112           = 0;
   data_ptr.SRR_FL_DETECTION_109_112.DET_MH_SCAN_INDEX_4LSB_109_112 = 0;

   // SRR_FL_DETECTION_113_116_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_113 = af_target_report_ptr[112].ran;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_114 = af_target_report_ptr[113].ran;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_115 = af_target_report_ptr[114].ran;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_116 = af_target_report_ptr[115].ran;

   data_ptr.SRR_FL_DETECTION_113_116.DET_AZIMUTH_113 = af_target_report_ptr[112].theta;
   data_ptr.SRR_FL_DETECTION_113_116.DET_AZIMUTH_114 = af_target_report_ptr[113].theta;
   data_ptr.SRR_FL_DETECTION_113_116.DET_AZIMUTH_115 = af_target_report_ptr[114].theta;
   data_ptr.SRR_FL_DETECTION_113_116.DET_AZIMUTH_116 = af_target_report_ptr[115].theta;

   data_ptr.SRR_FL_DETECTION_113_116.DET_BI_STATIC_FLAG_113 = af_target_report_ptr[112].f_bistatic;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BI_STATIC_FLAG_114 = af_target_report_ptr[113].f_bistatic;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BI_STATIC_FLAG_115 = af_target_report_ptr[114].f_bistatic;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BI_STATIC_FLAG_116 = af_target_report_ptr[115].f_bistatic;

   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_AZIMUTH_113 = af_target_report_ptr[112].az_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_AZIMUTH_114 = af_target_report_ptr[113].az_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_AZIMUTH_115 = af_target_report_ptr[114].az_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_AZIMUTH_116 = af_target_report_ptr[115].az_conf;

   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_113 = af_target_report_ptr[112].phi;
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_114 = af_target_report_ptr[113].phi;
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_115 = af_target_report_ptr[114].phi;
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_116 = af_target_report_ptr[115].phi;

   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_ELEVATION_113 = af_target_report_ptr[112].el_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_ELEVATION_114 = af_target_report_ptr[113].el_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_ELEVATION_115 = af_target_report_ptr[114].el_conf;
   data_ptr.SRR_FL_DETECTION_113_116.DET_CONFD_ELEVATION_116 = af_target_report_ptr[115].el_conf;

   data_ptr.SRR_FL_DETECTION_113_116.DET_EXISTENCE_PROB_113 = TOI_DS_Stream_Ptr->existence_prob[112];
   data_ptr.SRR_FL_DETECTION_113_116.DET_EXISTENCE_PROB_114 = TOI_DS_Stream_Ptr->existence_prob[113];
   data_ptr.SRR_FL_DETECTION_113_116.DET_EXISTENCE_PROB_115 = TOI_DS_Stream_Ptr->existence_prob[114];
   data_ptr.SRR_FL_DETECTION_113_116.DET_EXISTENCE_PROB_116 = TOI_DS_Stream_Ptr->existence_prob[115];

   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_ERR_113 = TOI_DS_Stream_Ptr->std_phi[112];
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_ERR_114 = TOI_DS_Stream_Ptr->std_phi[113];
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_ERR_115 = TOI_DS_Stream_Ptr->std_phi[114];
   data_ptr.SRR_FL_DETECTION_113_116.DET_ELEVATION_ERR_116 = TOI_DS_Stream_Ptr->std_phi[115];

   data_ptr.SRR_FL_DETECTION_113_116.DET_IDM_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_IDM_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_IDM_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_IDM_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_113_116.DET_MTD_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_MTD_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_MTD_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_MTD_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_113_116.DET_PROB_1STAZHYPO_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_PROB_1STAZHYPO_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_PROB_1STAZHYPO_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_PROB_1STAZHYPO_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_ERR_113 = TOI_DS_Stream_Ptr->std_ran[112];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_ERR_114 = TOI_DS_Stream_Ptr->std_ran[113];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_ERR_115 = TOI_DS_Stream_Ptr->std_ran[114];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_ERR_116 = TOI_DS_Stream_Ptr->std_ran[115];

   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_113 = af_target_report_ptr[112].vel;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_114 = af_target_report_ptr[113].vel;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_115 = af_target_report_ptr[114].vel;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_116 = af_target_report_ptr[115].vel;

   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_113 = TOI_DS_Stream_Ptr->std_vel[112];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_114 = TOI_DS_Stream_Ptr->std_vel[113];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_115 = TOI_DS_Stream_Ptr->std_vel[114];
   data_ptr.SRR_FL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_116 = TOI_DS_Stream_Ptr->std_vel[115];

   data_ptr.SRR_FL_DETECTION_113_116.DET_RCS_113 = af_target_report_ptr[112].rcs;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RCS_114 = af_target_report_ptr[113].rcs;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RCS_115 = af_target_report_ptr[114].rcs;
   data_ptr.SRR_FL_DETECTION_113_116.DET_RCS_116 = af_target_report_ptr[115].rcs;

   data_ptr.SRR_FL_DETECTION_113_116.DET_SNR_113 = af_target_report_ptr[112].snr;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SNR_114 = af_target_report_ptr[113].snr;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SNR_115 = af_target_report_ptr[114].snr;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SNR_116 = af_target_report_ptr[115].snr;

   data_ptr.SRR_FL_DETECTION_113_116.DET_SUPER_RES_TARGET_113 = af_target_report_ptr[112].f_superres_target;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SUPER_RES_TARGET_114 = af_target_report_ptr[113].f_superres_target;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SUPER_RES_TARGET_115 = af_target_report_ptr[114].f_superres_target;
   data_ptr.SRR_FL_DETECTION_113_116.DET_SUPER_RES_TARGET_116 = af_target_report_ptr[115].f_superres_target;

   data_ptr.SRR_FL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_113 = 0;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_114 = 0;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_115 = 0;
   data_ptr.SRR_FL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_116 = 0;

   data_ptr.SRR_FL_DETECTION_113_116.DET_HVC_FLAG_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_HVC_FLAG_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_HVC_FLAG_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_113_116.DET_HVC_FLAG_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_113_116.DET_MH_CYCLE_COUNTER_113_116   = 0;
   data_ptr.SRR_FL_DETECTION_113_116.DET_MH_CRC16_113_116           = 0;
   data_ptr.SRR_FL_DETECTION_113_116.DET_MH_SCAN_INDEX_4LSB_113_116 = 0;

   // SRR_FL_DETECTION_117_120_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_117 = af_target_report_ptr[116].ran;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_118 = af_target_report_ptr[117].ran;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_119 = af_target_report_ptr[118].ran;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_120 = af_target_report_ptr[119].ran;

   data_ptr.SRR_FL_DETECTION_117_120.DET_AZIMUTH_117 = af_target_report_ptr[116].theta;
   data_ptr.SRR_FL_DETECTION_117_120.DET_AZIMUTH_118 = af_target_report_ptr[117].theta;
   data_ptr.SRR_FL_DETECTION_117_120.DET_AZIMUTH_119 = af_target_report_ptr[118].theta;
   data_ptr.SRR_FL_DETECTION_117_120.DET_AZIMUTH_120 = af_target_report_ptr[119].theta;

   data_ptr.SRR_FL_DETECTION_117_120.DET_BI_STATIC_FLAG_117 = af_target_report_ptr[116].f_bistatic;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BI_STATIC_FLAG_118 = af_target_report_ptr[117].f_bistatic;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BI_STATIC_FLAG_119 = af_target_report_ptr[118].f_bistatic;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BI_STATIC_FLAG_120 = af_target_report_ptr[119].f_bistatic;

   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_AZIMUTH_117 = af_target_report_ptr[116].az_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_AZIMUTH_118 = af_target_report_ptr[117].az_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_AZIMUTH_119 = af_target_report_ptr[118].az_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_AZIMUTH_120 = af_target_report_ptr[119].az_conf;

   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_117 = af_target_report_ptr[116].phi;
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_118 = af_target_report_ptr[117].phi;
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_119 = af_target_report_ptr[118].phi;
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_120 = af_target_report_ptr[119].phi;

   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_ELEVATION_117 = af_target_report_ptr[116].el_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_ELEVATION_118 = af_target_report_ptr[117].el_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_ELEVATION_119 = af_target_report_ptr[118].el_conf;
   data_ptr.SRR_FL_DETECTION_117_120.DET_CONFD_ELEVATION_120 = af_target_report_ptr[119].el_conf;

   data_ptr.SRR_FL_DETECTION_117_120.DET_EXISTENCE_PROB_117 = TOI_DS_Stream_Ptr->existence_prob[116];
   data_ptr.SRR_FL_DETECTION_117_120.DET_EXISTENCE_PROB_118 = TOI_DS_Stream_Ptr->existence_prob[117];
   data_ptr.SRR_FL_DETECTION_117_120.DET_EXISTENCE_PROB_119 = TOI_DS_Stream_Ptr->existence_prob[118];
   data_ptr.SRR_FL_DETECTION_117_120.DET_EXISTENCE_PROB_120 = TOI_DS_Stream_Ptr->existence_prob[119];

   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_ERR_117 = TOI_DS_Stream_Ptr->std_phi[116];
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_ERR_118 = TOI_DS_Stream_Ptr->std_phi[117];
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_ERR_119 = TOI_DS_Stream_Ptr->std_phi[118];
   data_ptr.SRR_FL_DETECTION_117_120.DET_ELEVATION_ERR_120 = TOI_DS_Stream_Ptr->std_phi[119];

   data_ptr.SRR_FL_DETECTION_117_120.DET_IDM_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_IDM_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_IDM_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_IDM_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_117_120.DET_MTD_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_MTD_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_MTD_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_MTD_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_117_120.DET_PROB_1STAZHYPO_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_PROB_1STAZHYPO_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_PROB_1STAZHYPO_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_PROB_1STAZHYPO_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_ERR_117 = TOI_DS_Stream_Ptr->std_ran[116];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_ERR_118 = TOI_DS_Stream_Ptr->std_ran[117];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_ERR_119 = TOI_DS_Stream_Ptr->std_ran[118];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_ERR_120 = TOI_DS_Stream_Ptr->std_ran[119];

   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_117 = af_target_report_ptr[116].vel;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_118 = af_target_report_ptr[117].vel;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_119 = af_target_report_ptr[118].vel;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_120 = af_target_report_ptr[119].vel;

   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_117 = TOI_DS_Stream_Ptr->std_vel[116];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_118 = TOI_DS_Stream_Ptr->std_vel[117];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_119 = TOI_DS_Stream_Ptr->std_vel[118];
   data_ptr.SRR_FL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_120 = TOI_DS_Stream_Ptr->std_vel[119];

   data_ptr.SRR_FL_DETECTION_117_120.DET_RCS_117 = af_target_report_ptr[116].rcs;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RCS_118 = af_target_report_ptr[117].rcs;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RCS_119 = af_target_report_ptr[118].rcs;
   data_ptr.SRR_FL_DETECTION_117_120.DET_RCS_120 = af_target_report_ptr[119].rcs;

   data_ptr.SRR_FL_DETECTION_117_120.DET_SNR_117 = af_target_report_ptr[116].snr;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SNR_118 = af_target_report_ptr[117].snr;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SNR_119 = af_target_report_ptr[118].snr;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SNR_120 = af_target_report_ptr[119].snr;

   data_ptr.SRR_FL_DETECTION_117_120.DET_SUPER_RES_TARGET_117 = af_target_report_ptr[116].f_superres_target;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SUPER_RES_TARGET_118 = af_target_report_ptr[117].f_superres_target;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SUPER_RES_TARGET_119 = af_target_report_ptr[118].f_superres_target;
   data_ptr.SRR_FL_DETECTION_117_120.DET_SUPER_RES_TARGET_120 = af_target_report_ptr[119].f_superres_target;

   data_ptr.SRR_FL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_117 = 0;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_118 = 0;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_119 = 0;
   data_ptr.SRR_FL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_120 = 0;

   data_ptr.SRR_FL_DETECTION_117_120.DET_HVC_FLAG_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_HVC_FLAG_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_HVC_FLAG_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_117_120.DET_HVC_FLAG_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_117_120.DET_MH_CYCLE_COUNTER_117_120   = 0;
   data_ptr.SRR_FL_DETECTION_117_120.DET_MH_CRC16_117_120           = 0;
   data_ptr.SRR_FL_DETECTION_117_120.DET_MH_SCAN_INDEX_4LSB_117_120 = 0;

   // SRR_FL_DETECTION_121_124_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_121 = af_target_report_ptr[120].ran;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_122 = af_target_report_ptr[121].ran;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_123 = af_target_report_ptr[122].ran;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_124 = af_target_report_ptr[123].ran;

   data_ptr.SRR_FL_DETECTION_121_124.DET_AZIMUTH_121 = af_target_report_ptr[120].theta;
   data_ptr.SRR_FL_DETECTION_121_124.DET_AZIMUTH_122 = af_target_report_ptr[121].theta;
   data_ptr.SRR_FL_DETECTION_121_124.DET_AZIMUTH_123 = af_target_report_ptr[122].theta;
   data_ptr.SRR_FL_DETECTION_121_124.DET_AZIMUTH_124 = af_target_report_ptr[123].theta;

   data_ptr.SRR_FL_DETECTION_121_124.DET_BI_STATIC_FLAG_121 = af_target_report_ptr[120].f_bistatic;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BI_STATIC_FLAG_122 = af_target_report_ptr[121].f_bistatic;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BI_STATIC_FLAG_123 = af_target_report_ptr[122].f_bistatic;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BI_STATIC_FLAG_124 = af_target_report_ptr[123].f_bistatic;

   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_AZIMUTH_121 = af_target_report_ptr[120].az_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_AZIMUTH_122 = af_target_report_ptr[121].az_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_AZIMUTH_123 = af_target_report_ptr[122].az_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_AZIMUTH_124 = af_target_report_ptr[123].az_conf;

   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_121 = af_target_report_ptr[120].phi;
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_122 = af_target_report_ptr[121].phi;
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_123 = af_target_report_ptr[122].phi;
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_124 = af_target_report_ptr[123].phi;

   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_ELEVATION_121 = af_target_report_ptr[120].el_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_ELEVATION_122 = af_target_report_ptr[121].el_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_ELEVATION_123 = af_target_report_ptr[122].el_conf;
   data_ptr.SRR_FL_DETECTION_121_124.DET_CONFD_ELEVATION_124 = af_target_report_ptr[123].el_conf;

   data_ptr.SRR_FL_DETECTION_121_124.DET_EXISTENCE_PROB_121 = TOI_DS_Stream_Ptr->existence_prob[120];
   data_ptr.SRR_FL_DETECTION_121_124.DET_EXISTENCE_PROB_122 = TOI_DS_Stream_Ptr->existence_prob[121];
   data_ptr.SRR_FL_DETECTION_121_124.DET_EXISTENCE_PROB_123 = TOI_DS_Stream_Ptr->existence_prob[122];
   data_ptr.SRR_FL_DETECTION_121_124.DET_EXISTENCE_PROB_124 = TOI_DS_Stream_Ptr->existence_prob[123];

   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_ERR_121 = TOI_DS_Stream_Ptr->std_phi[120];
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_ERR_122 = TOI_DS_Stream_Ptr->std_phi[121];
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_ERR_123 = TOI_DS_Stream_Ptr->std_phi[122];
   data_ptr.SRR_FL_DETECTION_121_124.DET_ELEVATION_ERR_124 = TOI_DS_Stream_Ptr->std_phi[123];

   data_ptr.SRR_FL_DETECTION_121_124.DET_IDM_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_IDM_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_IDM_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_IDM_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_121_124.DET_MTD_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_MTD_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_MTD_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_MTD_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_121_124.DET_PROB_1STAZHYPO_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_PROB_1STAZHYPO_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_PROB_1STAZHYPO_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_PROB_1STAZHYPO_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_ERR_121 = TOI_DS_Stream_Ptr->std_ran[120];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_ERR_122 = TOI_DS_Stream_Ptr->std_ran[121];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_ERR_123 = TOI_DS_Stream_Ptr->std_ran[122];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_ERR_124 = TOI_DS_Stream_Ptr->std_ran[123];

   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_121 = af_target_report_ptr[120].vel;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_122 = af_target_report_ptr[121].vel;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_123 = af_target_report_ptr[122].vel;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_124 = af_target_report_ptr[123].vel;

   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_121 = TOI_DS_Stream_Ptr->std_vel[120];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_122 = TOI_DS_Stream_Ptr->std_vel[121];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_123 = TOI_DS_Stream_Ptr->std_vel[122];
   data_ptr.SRR_FL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_124 = TOI_DS_Stream_Ptr->std_vel[123];

   data_ptr.SRR_FL_DETECTION_121_124.DET_RCS_121 = af_target_report_ptr[120].rcs;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RCS_122 = af_target_report_ptr[121].rcs;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RCS_123 = af_target_report_ptr[122].rcs;
   data_ptr.SRR_FL_DETECTION_121_124.DET_RCS_124 = af_target_report_ptr[123].rcs;

   data_ptr.SRR_FL_DETECTION_121_124.DET_SNR_121 = af_target_report_ptr[120].snr;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SNR_122 = af_target_report_ptr[121].snr;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SNR_123 = af_target_report_ptr[122].snr;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SNR_124 = af_target_report_ptr[123].snr;

   data_ptr.SRR_FL_DETECTION_121_124.DET_SUPER_RES_TARGET_121 = af_target_report_ptr[120].f_superres_target;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SUPER_RES_TARGET_122 = af_target_report_ptr[121].f_superres_target;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SUPER_RES_TARGET_123 = af_target_report_ptr[122].f_superres_target;
   data_ptr.SRR_FL_DETECTION_121_124.DET_SUPER_RES_TARGET_124 = af_target_report_ptr[123].f_superres_target;

   data_ptr.SRR_FL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_121 = 0;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_122 = 0;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_123 = 0;
   data_ptr.SRR_FL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_124 = 0;

   data_ptr.SRR_FL_DETECTION_121_124.DET_HVC_FLAG_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_HVC_FLAG_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_HVC_FLAG_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_121_124.DET_HVC_FLAG_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_121_124.DET_MH_CYCLE_COUNTER_121_124   = 0;
   data_ptr.SRR_FL_DETECTION_121_124.DET_MH_CRC16_121_124           = 0;
   data_ptr.SRR_FL_DETECTION_121_124.DET_MH_SCAN_INDEX_4LSB_121_124 = 0;

   // SRR_FL_DETECTION_125_128_decoded_msg_t
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_125 = af_target_report_ptr[124].ran;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_126 = af_target_report_ptr[125].ran;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_127 = af_target_report_ptr[126].ran;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_128 = af_target_report_ptr[127].ran;

   data_ptr.SRR_FL_DETECTION_125_128.DET_AZIMUTH_125 = af_target_report_ptr[124].theta;
   data_ptr.SRR_FL_DETECTION_125_128.DET_AZIMUTH_126 = af_target_report_ptr[125].theta;
   data_ptr.SRR_FL_DETECTION_125_128.DET_AZIMUTH_127 = af_target_report_ptr[126].theta;
   data_ptr.SRR_FL_DETECTION_125_128.DET_AZIMUTH_128 = af_target_report_ptr[127].theta;

   data_ptr.SRR_FL_DETECTION_125_128.DET_BI_STATIC_FLAG_125 = af_target_report_ptr[124].f_bistatic;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BI_STATIC_FLAG_126 = af_target_report_ptr[125].f_bistatic;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BI_STATIC_FLAG_127 = af_target_report_ptr[126].f_bistatic;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BI_STATIC_FLAG_128 = af_target_report_ptr[127].f_bistatic;

   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_AZIMUTH_125 = af_target_report_ptr[124].az_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_AZIMUTH_126 = af_target_report_ptr[125].az_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_AZIMUTH_127 = af_target_report_ptr[126].az_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_AZIMUTH_128 = af_target_report_ptr[127].az_conf;

   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_125 = af_target_report_ptr[124].phi;
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_126 = af_target_report_ptr[125].phi;
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_127 = af_target_report_ptr[126].phi;
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_128 = af_target_report_ptr[127].phi;

   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_ELEVATION_125 = af_target_report_ptr[124].el_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_ELEVATION_126 = af_target_report_ptr[125].el_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_ELEVATION_127 = af_target_report_ptr[126].el_conf;
   data_ptr.SRR_FL_DETECTION_125_128.DET_CONFD_ELEVATION_128 = af_target_report_ptr[127].el_conf;

   data_ptr.SRR_FL_DETECTION_125_128.DET_EXISTENCE_PROB_125 = TOI_DS_Stream_Ptr->existence_prob[124];
   data_ptr.SRR_FL_DETECTION_125_128.DET_EXISTENCE_PROB_126 = TOI_DS_Stream_Ptr->existence_prob[125];
   data_ptr.SRR_FL_DETECTION_125_128.DET_EXISTENCE_PROB_127 = TOI_DS_Stream_Ptr->existence_prob[126];
   data_ptr.SRR_FL_DETECTION_125_128.DET_EXISTENCE_PROB_128 = TOI_DS_Stream_Ptr->existence_prob[127];

   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_ERR_125 = TOI_DS_Stream_Ptr->std_phi[124];
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_ERR_126 = TOI_DS_Stream_Ptr->std_phi[125];
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_ERR_127 = TOI_DS_Stream_Ptr->std_phi[126];
   data_ptr.SRR_FL_DETECTION_125_128.DET_ELEVATION_ERR_128 = TOI_DS_Stream_Ptr->std_phi[127];

   data_ptr.SRR_FL_DETECTION_125_128.DET_IDM_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_IDM_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_IDM_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_IDM_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_125_128.DET_MTD_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_MTD_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_MTD_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_MTD_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_125_128.DET_PROB_1STAZHYPO_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_PROB_1STAZHYPO_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_PROB_1STAZHYPO_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_PROB_1STAZHYPO_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_ERR_125 = TOI_DS_Stream_Ptr->std_ran[124];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_ERR_126 = TOI_DS_Stream_Ptr->std_ran[125];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_ERR_127 = TOI_DS_Stream_Ptr->std_ran[126];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_ERR_128 = TOI_DS_Stream_Ptr->std_ran[127];

   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_125 = af_target_report_ptr[124].vel;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_126 = af_target_report_ptr[125].vel;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_127 = af_target_report_ptr[126].vel;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_128 = af_target_report_ptr[127].vel;

   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_125 = TOI_DS_Stream_Ptr->std_vel[124];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_126 = TOI_DS_Stream_Ptr->std_vel[125];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_127 = TOI_DS_Stream_Ptr->std_vel[126];
   data_ptr.SRR_FL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_128 = TOI_DS_Stream_Ptr->std_vel[127];

   data_ptr.SRR_FL_DETECTION_125_128.DET_RCS_125 = af_target_report_ptr[124].rcs;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RCS_126 = af_target_report_ptr[125].rcs;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RCS_127 = af_target_report_ptr[126].rcs;
   data_ptr.SRR_FL_DETECTION_125_128.DET_RCS_128 = af_target_report_ptr[127].rcs;

   data_ptr.SRR_FL_DETECTION_125_128.DET_SNR_125 = af_target_report_ptr[124].snr;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SNR_126 = af_target_report_ptr[125].snr;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SNR_127 = af_target_report_ptr[126].snr;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SNR_128 = af_target_report_ptr[127].snr;

   data_ptr.SRR_FL_DETECTION_125_128.DET_SUPER_RES_TARGET_125 = af_target_report_ptr[124].f_superres_target;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SUPER_RES_TARGET_126 = af_target_report_ptr[125].f_superres_target;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SUPER_RES_TARGET_127 = af_target_report_ptr[126].f_superres_target;
   data_ptr.SRR_FL_DETECTION_125_128.DET_SUPER_RES_TARGET_128 = af_target_report_ptr[127].f_superres_target;

   data_ptr.SRR_FL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_125 = 0;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_126 = 0;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_127 = 0;
   data_ptr.SRR_FL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_128 = 0;

   data_ptr.SRR_FL_DETECTION_125_128.DET_HVC_FLAG_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_HVC_FLAG_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_HVC_FLAG_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_FL_DETECTION_125_128.DET_HVC_FLAG_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_FL_DETECTION_125_128.DET_MH_CYCLE_COUNTER_125_128   = 0;
   data_ptr.SRR_FL_DETECTION_125_128.DET_MH_CRC16_125_128           = 0;
   data_ptr.SRR_FL_DETECTION_125_128.DET_MH_SCAN_INDEX_4LSB_125_128 = 0;
}

void populate_Rear_object_data(void)
{
   uint8_t temp_sig;
   SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr = Get_Sil_Radar_Input_Symbol_Ptr();

   memset(&data_ptr, 0, sizeof(Sensor_decoded_types_t));

   // SRR_RL_HEADER_001_decoded_msg_t
   data_ptr.SRR_RL_HEADER_001.HED_ALIGN_HOR_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal;
   data_ptr.SRR_RL_HEADER_001.HED_ALIGN_VER_REF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal;
   data_ptr.SRR_RL_HEADER_001.HED_Auth_CRC32 = 0; // need to be check
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_RL_HEADER_001.HED_DATA_QUALIFIER = (ipc_d2m->payload.toi_ds_stream_data.toi_op_data.data_qualifier) - 1U;
#else
   data_ptr.SRR_RL_HEADER_001.HED_DATA_QUALIFIER          = ipc_d2m->payload.toi_stream_data.toi_op_data.data_qualifier;
#endif
   data_ptr.SRR_RL_HEADER_001.HED_DET_BI_STATIC_COUNT = CAN_SIG_NOT_IMPLEMENTED;

#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_RL_HEADER_001.HED_DET_NUM_OF_1PASS = ipc_d2m->payload.downselection_data.det_list_property.num_fp_detections;
   data_ptr.SRR_RL_HEADER_001.HED_DET_NUM_OF_2PASS = ipc_d2m->payload.downselection_data.det_list_property.num_sp_detections;
   data_ptr.SRR_RL_HEADER_001.HED_NUM_OF_VALID_DETECTIONS = ipc_d2m->payload.downselection_data.num_af_ds_det;
   data_ptr.SRR_RL_HEADER_001.HED_SENSOR_TIME_STAMP_NS    = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.SRR_RL_HEADER_001.HED_SENSOR_TIME_STAMP_SEC   = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#else
   data_ptr.SRR_RL_HEADER_001.HED_DET_NUM_OF_1PASS        = ipc_d2m->payload.det_data.det_list_property.num_fp_detections;
   data_ptr.SRR_RL_HEADER_001.HED_DET_NUM_OF_2PASS        = ipc_d2m->payload.det_data.det_list_property.num_sp_detections;
   data_ptr.SRR_RL_HEADER_001.HED_NUM_OF_VALID_DETECTIONS = ipc_d2m->payload.det_data.num_af_ds_det;
   data_ptr.SRR_RL_HEADER_001.HED_SENSOR_TIME_STAMP_NS    = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_nanosec;
   data_ptr.SRR_RL_HEADER_001.HED_SENSOR_TIME_STAMP_SEC   = ipc_d2m->payload.rdd_stream_data.look_data.start_dwell_sec;
#endif

   data_ptr.SRR_RL_HEADER_001.HED_FOV_HOR_MIN           = FXP2FLP_Fnc(k_fov_hor_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_RL_HEADER_001.HED_FOV_HOR_MAX           = FXP2FLP_Fnc(k_fov_hor_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_RL_HEADER_001.HED_FOV_VER_MIN           = FXP2FLP_Fnc(k_fov_ver_begin_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_RL_HEADER_001.HED_FOV_VER_MAX           = FXP2FLP_Fnc(k_fov_ver_end_smc, BPP_s2p13_T, SIGNED_s2p13_T);
   data_ptr.SRR_RL_HEADER_001.HED_LOOK_ID               = ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   data_ptr.SRR_RL_HEADER_001.HED_SCAN_INDEX            = Get_Current_Scan_Index();
   data_ptr.SRR_RL_HEADER_001.HED_MAX_NUM_OF_DETECTIONS = static_cast<uint8_t>(MAX_FLR_DETECTIONS);
   data_ptr.SRR_RL_HEADER_001.HED_MH_CRC16              = 0;
   data_ptr.SRR_RL_HEADER_001.HED_MH_CYCLE_COUNTER      = 0;

   data_ptr.SRR_RL_HEADER_001.HED_NUM_OF_RESTBINS_USED = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_HEADER_001.HED_OPERATION_MODE       = 0x02; // 0x02 for Operational Mode
   data_ptr.SRR_RL_HEADER_001.HED_PROCESSED_RANGE      = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_HEADER_001.HED_R_WRAPPING           = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_HEADER_001.HED_Rain_Level           = 0;
   data_ptr.SRR_RL_HEADER_001.HED_LOOK_INDEX           = ipc_d2m->payload.rdd_stream_data.look_data.look_index;

   data_ptr.SRR_RL_HEADER_001.HED_TRIGGER_TIME             = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_HEADER_001.HED_SLOPE_CORR_EXECUTIONFLAG = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_HEADER_001.HED_TIME_SYNC_VALIDITY_FLAG  = 0; // need to check
   data_ptr.SRR_RL_HEADER_001.HED_TIME_SYNC_SRC_MASTER     = 0; // need to check

   Radar_Look_T hdr_look_type;
   hdr_look_type = (Radar_Look_T)ipc_d2m->payload.rdd_stream_data.look_data.look_id;
   if (hdr_look_type < RADAR_LOOK_D)
   {
      data_ptr.SRR_RL_HEADER_001.HED_DET_RANGE_MAX       = k_detection_range_max_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_RL_HEADER_001.HED_DET_RANGE_MIN       = k_detection_range_min_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_RL_HEADER_001.HED_DET_SPEED_RANGE_MAX = k_detection_range_rate_max_smc[(uint8_t)hdr_look_type];
      data_ptr.SRR_RL_HEADER_001.HED_DET_SPEED_RANGE_MIN = k_detection_range_rate_min_smc[(uint8_t)hdr_look_type];
   }
   else
   {
      data_ptr.SRR_RL_HEADER_001.HED_DET_RANGE_MAX       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.SRR_RL_HEADER_001.HED_DET_RANGE_MIN       = Init_Fixed_Point(0, u9p7_T);
      data_ptr.SRR_RL_HEADER_001.HED_DET_SPEED_RANGE_MAX = Init_Fixed_Point(0, s7p8_T);
      data_ptr.SRR_RL_HEADER_001.HED_DET_SPEED_RANGE_MIN = Init_Fixed_Point(0, s7p8_T);
   }

   // SRR_RL_STATUS_001
   data_ptr.SRR_RL_STATUS_001.STS_MH_001_CYCLE_COUNTER     = 0;
   data_ptr.SRR_RL_STATUS_001.STS_MH_001_CRC16             = 0;
   data_ptr.SRR_RL_STATUS_001.STS_USC_CAL_VER_MAJOR        = Get_USC_Cal_Major();
   data_ptr.SRR_RL_STATUS_001.STS_USC_CAL_VER_MINOR        = Get_USC_Cal_Minor();
   data_ptr.SRR_RL_STATUS_001.STS_USC_SECTION_COMPTBLITY   = Get_USC_Cal_Major();
   data_ptr.SRR_RL_STATUS_001.STS_SMC_CAL_VER_MAJOR        = Get_SMC_Cal_Major();
   data_ptr.SRR_RL_STATUS_001.STS_SMC_CAL_VER_MINOR        = Get_SMC_Cal_Minor();
   data_ptr.SRR_RL_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = Get_SMC_Cal_Major();
   data_ptr.SRR_RL_STATUS_001.STS_SMC_PLATFROM_VERSION     = Get_SMC_Cal_Platform();
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_POSITION          = Get_Radar_Position();
   data_ptr.SRR_RL_STATUS_001.STS_HARDWARE_VERSION         = status_stream_ptr->app_version_Info.board_type;
   data_ptr.SRR_RL_STATUS_001.STS_PCAN_PROTOCOL_VER_MAJOR  = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.SRR_RL_STATUS_001.STS_PCAN_PROTOCOL_VER_MINOR  = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.SRR_RL_STATUS_001.STS_PLATFORM_VARIANT         = Get_SMC_Cal_Platform();
   data_ptr.SRR_RL_STATUS_001.STS_SERIAL_NUM_JULIAN_DAY    = k_Julian_Production_Date_USC;
   data_ptr.SRR_RL_STATUS_001.STS_SERIAL_NUM_JULIAN_YEAR   = k_Julian_Year_USC;
   data_ptr.SRR_RL_STATUS_001.STS_SERIAL_NUMBER_SEQUENCE   = k_Mfg_Sequence_Number_USC;
   data_ptr.SRR_RL_STATUS_001.STS_SW_VERSION_FIELD1        = status_stream_ptr->app_version_Info.appl_variant;
   data_ptr.SRR_RL_STATUS_001.STS_SW_VERSION_FIELD2        = status_stream_ptr->app_version_Info.major_release_revision;
   data_ptr.SRR_RL_STATUS_001.STS_SW_VERSION_FIELD3        = status_stream_ptr->app_version_Info.minor_release_revision;
   data_ptr.SRR_RL_STATUS_001.STS_SW_VERSION_FIELD4        = status_stream_ptr->app_version_Info.patch_release_revision;
   data_ptr.SRR_RL_STATUS_001.STS_PBL_VERSION_FIELD1       = status_stream_ptr->pbl_version_maj;
   data_ptr.SRR_RL_STATUS_001.STS_PBL_VERSION_FIELD2       = status_stream_ptr->pbl_version_min;
   data_ptr.SRR_RL_STATUS_001.STS_PBL_VERSION_FIELD3       = status_stream_ptr->pbl_version_patch;
   data_ptr.SRR_RL_STATUS_001.STS_PBL_VERSION_FIELD4       = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_ORNT_YAW    = *k_sensor_mount_ornt_yaw_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_POLARITY          = 0;
   data_ptr.SRR_RL_STATUS_001.STS_DIST_FRNT_BMPR_TO_RR_AXL = 0;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_ORNT_PITCH  = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_ORNT_ROLL   = *k_sensor_mount_ornt_roll_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_POS_X       = *k_sensor_mount_pos_x_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_POS_Y       = *k_sensor_mount_pos_y_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_MOUNT_POS_Z       = *k_sensor_mount_pos_z_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_SENSOR_HEIGHT            = *k_sensor_mount_ornt_pitch_list_smc;
   data_ptr.SRR_RL_STATUS_001.STS_DET_DBC_BASE_VER_MAJOR   = DET_DBC_BASE_VERSION_MAJOR;
   data_ptr.SRR_RL_STATUS_001.STS_DET_DBC_BASE_VER_MINOR   = DET_DBC_BASE_VERSION_MINOR;
   data_ptr.SRR_RL_STATUS_001.STS_TIME_SINCE_POWER_ON      = 0;
   data_ptr.SRR_RL_STATUS_001.STS_AF_TIME_PEAK             = 0;
   data_ptr.SRR_RL_STATUS_001.STS_AF_TIME_INST             = 0;
   data_ptr.SRR_RL_STATUS_001.STS_MAIN_CORE_TIME_INST      = 0;
   data_ptr.SRR_RL_STATUS_001.STS_MAIN_CORE_TIME_PEAK      = 0;
   data_ptr.SRR_RL_STATUS_001.STS_RDD_CORE_TIME_INST       = 0;
   data_ptr.SRR_RL_STATUS_001.STS_RDD_CORE_TIME_PEAK       = 0;
   data_ptr.SRR_RL_STATUS_001.STS_SP_CORE_TIME_INST        = 0;
   data_ptr.SRR_RL_STATUS_001.STS_SP_CORE_TIME_PEAK        = 0;
   data_ptr.SRR_RL_STATUS_001.STS_SMC_SECTION_COMPTBLITY   = 0;

   // SRR_RL_STATUS_002
   data_ptr.SRR_RL_STATUS_002.STS_MH_002_CYCLE_COUNTER   = 0;
   data_ptr.SRR_RL_STATUS_002.STS_MH_002_CRC16           = 0;
   data_ptr.SRR_RL_STATUS_002.STS_VEHICLE_SUPPLY_VOLTAGE = 0; // need to check
   data_ptr.SRR_RL_STATUS_002.STS_YAW_RATE_BIAS          = ipc_m2d->payload.veh_data.vse_output.yaw_rate_bias;
   data_ptr.SRR_RL_STATUS_002.STS_STEERING_ANGLE         = ipc_m2d->payload.veh_data.vse_output.comp_steering_angle_deg;

   if (!(ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_OUT) &&
       (ipc_d2m->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload.end_dwell_status & TS_GLOBAL_TIME_BASE))
   {
      data_ptr.SRR_RL_STATUS_002.STS_NO_TSYN_ERROR = 1;
   }
   else
   {
      data_ptr.SRR_RL_STATUS_002.STS_NO_TSYN_ERROR = 0;
   }

   data_ptr.SRR_RL_STATUS_002.STS_BRR_STATUS         = 0; // need to be checked
   data_ptr.SRR_RL_STATUS_002.STS_XCVR_OPERATIONAL   = 0; // need to be checked
   data_ptr.SRR_RL_STATUS_002.STS_MMIC_RE_INIT_COUNT = 0;
   data_ptr.SRR_RL_STATUS_002.STS_POINT_OF_TRIGGER   = CAN_SIG_NOT_IMPLEMENTED;
#if (DOWNSELECTION_ENABLE == 1U)
   data_ptr.SRR_RL_STATUS_002.STS_SCAN_TYPE = ipc_d2m->payload.downselection_data.det_list_property.look_type;
#else
   data_ptr.SRR_RL_STATUS_002.STS_SCAN_TYPE               = ipc_d2m->payload.det_data.det_list_property.look_type;
#endif
   data_ptr.SRR_RL_STATUS_002.STS_Gear_Position             = 0;
   data_ptr.SRR_RL_STATUS_002.STS_CAN_NM_State              = 0;
   data_ptr.SRR_RL_STATUS_002.STS_MMIC_TEMP_TX1_2           = 0; // status_stream_ptr->mmic_temp_rx1;// need to checked
   data_ptr.SRR_RL_STATUS_002.STS_MMIC_TEMP_TX3_4           = 0; // status_stream_ptr->mmic_temp_tx1;// need to checked
   data_ptr.SRR_RL_STATUS_002.STS_MCU_TEMP                  = 0;
   data_ptr.SRR_RL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_4_to_7 = 0;
   data_ptr.SRR_RL_STATUS_002.STS_AF_CORE_THROUGHPUT        = 0;
   data_ptr.SRR_RL_STATUS_002.STS_Vehicle_Speed_Calc_QF     = 0;
   data_ptr.SRR_RL_STATUS_002.STS_RDD_CORE_THROUGHPUT       = 0;
   data_ptr.SRR_RL_STATUS_002.STS_Yaw_Rate_Calc_QF          = 0;
   data_ptr.SRR_RL_STATUS_002.STS_MMIC_TEMP_RX              = 0; // need to checked
   data_ptr.SRR_RL_STATUS_002.STS_TIME_SYNC_OFFSET          = 0;
   data_ptr.SRR_RL_STATUS_002.STS_MMIC_TEMP_TX0             = 0;
   data_ptr.SRR_RL_STATUS_002.STS_STEERING_ANGLE_SIGN       = 0; // ipc_m2d->payload.veh_data.vse_output.veh_steering_sign_status;
   data_ptr.SRR_RL_STATUS_002.STS_VEH_SPEED_DIRECTION = 0; //(ipc_m2d->payload.veh_data.vse_output.lros_drive_reverse) ? 1 : 0;
   data_ptr.SRR_RL_STATUS_002.STS_VEHICLE_SPEED_CALC  = 0; // ipc_m2d->payload.veh_data.vse_output.veh_speed;
   data_ptr.SRR_RL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_0_to_3    = 0;
   data_ptr.SRR_RL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_8_to_11   = 0;
   data_ptr.SRR_RL_STATUS_002.STS_CORE_ACTV_FLT_BYTE_11_to_15  = 0;
   data_ptr.SRR_RL_STATUS_002.STS_Project_ACTV_FLT_BYTE_0_to_3 = 0;
   data_ptr.SRR_RL_STATUS_002.STS_Project_ACTV_FLT_BYTE_4_to_5 = 0;
   data_ptr.SRR_RL_STATUS_002.STS_Last_CAN_Det_Inst_Latency    = 0;
   data_ptr.SRR_RL_STATUS_002.STS_First_CAN_Det_Inst_Latency   = 0;
   data_ptr.SRR_RL_STATUS_002.STS_RAIN_COUNT                   = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_STATUS_002.STS_INTRFC_VERSION_ID_MAJOR      = 0;
   data_ptr.SRR_RL_STATUS_002.STS_INTRFC_VERSION_ID_MINOR      = 0;
   data_ptr.SRR_RL_STATUS_002.STS_INTRFC_VERSION_ID_PATCH      = 0;

   // SRR_RL_ALIGNMENT_STATUS_001
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.AL_STS_001_MH_CRC16      = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.AL_STS_001_CYCLE_COUNTER = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AAAzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AACurrentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AACurrentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AAElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentAutoStatus = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentError = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentModeIn =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AlignmentModeOut =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AutoAlignmentFailRootCause = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AzimuthErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_az;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AzimuthErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_az;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AzimuthStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_az;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_AzimuthUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_CalDisplay = 1;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_CalTime    = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_CoordinateSystemInput =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.detection_coordinate_system;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_ElevationErrorNegative =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_neg_error_bound_el;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_ElevationErrorPositive =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_pos_error_bound_el;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_ElevationUpdates =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_HostSpdCompensationFactorQF =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_HostSpeedCompensationFactor =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitAlignmentResultElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitAlignmentResultAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitAlignResultAzimuthUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_ElevationStd =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.estimated_standard_deviation_el;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitAlignRsltElevationUpdate =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_elevation_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitAlignRsltHostSpdCompFac =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_StartAzimuth =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_initial;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_StartElevation =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_initial;
   uint8_t Complete_Percent_Az =
      (uint8_t)ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_az;
   uint8_t Complete_Percent_El =
      (uint8_t)ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_complete_percent_el;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_ProgressPercent = (uint8_t)((Complete_Percent_Az + Complete_Percent_El) / 2U);
   data_ptr.SRR_RL_ALIGNMENT_STATUS_001.STS_InitLastSuccessfulAlignMode = 0;

   // SRR_RL_ALIGNMENT_STATUS_002
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_AlignmentServiceStatus = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_ImpactByInterference   = 0; // TODO: check what to be filled
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_AlignmentStaticStatus  = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_Measured_Range         = 0;
   //   ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_range;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_MeasuredRangeStd = 0;
   //    ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_range;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_MeasuredRangeRate = 0;
   //   ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_r_dot;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_MeasuredRangeRateStd = 0;
   //    ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_MeasuredRawAmplitude = 0;
   //    ipc_d2m->payload.alignment_stream_data.static_align_internal.meas_plate_rcs;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_MeasuredAmpSTD = 0;
   //    ipc_d2m->payload.alignment_stream_data.static_align_stream_output.std_r_dot;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_AlignmentShortTrackStatus = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_VehicleCondition          = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_DistanceAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_since_start;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_AverageNumberOfDetections = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_DistanceEffective =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el >
            ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf ?
         ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_el :
         ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_distance_running_az_scf;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_DurationAbsolute =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_since_start;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_AverageSpeed =
      ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.avg_spd_since_start;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.STS_DurationEffective =
      ((ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el >
        ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf) ?
          (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_el) :
          (ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.total_time_running_az_scf));
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.AL_STS_002_MH_CRC16      = 0;
   data_ptr.SRR_RL_ALIGNMENT_STATUS_002.AL_STS_002_CYCLE_COUNTER = 0;

   // SRR_RL_CAPABILITY
   data_ptr.SRR_RL_CAPABILITY.CAP_FreeSightCheckActive  = ipc_d2m->payload.radar_capability_data.fsc.run_status;
   data_ptr.SRR_RL_CAPABILITY.CAP_BlockageStatus        = ipc_d2m->payload.radar_capability_data.blockage.blockage_status;
   data_ptr.SRR_RL_CAPABILITY.CAP_BlockageActive        = ipc_d2m->payload.radar_capability_data.blockage.blockage_active;
   data_ptr.SRR_RL_CAPABILITY.CAP_BlockageSensitivity   = ipc_d2m->payload.radar_capability_data.sensitivity_level;
   data_ptr.SRR_RL_CAPABILITY.CAP_DampingStatus         = ipc_d2m->payload.radar_capability_data.dm.dm_status;
   data_ptr.SRR_RL_CAPABILITY.CAP_FreeSightCheckStatus  = ipc_d2m->payload.radar_capability_data.fsc.fault_status;
   data_ptr.SRR_RL_CAPABILITY.CAP_BlockageValue         = ipc_d2m->payload.radar_capability_data.blockage.blockage.value;
   data_ptr.SRR_RL_CAPABILITY.CAP_DampingActive         = ipc_d2m->payload.radar_capability_data.dm.dm_active;
   data_ptr.SRR_RL_CAPABILITY.CAP_BlockageProbability   = ipc_d2m->payload.radar_capability_data.blockage.blockage.probability;
   data_ptr.SRR_RL_CAPABILITY.CAP_RangeEstimationActive = ipc_d2m->payload.radar_capability_data.re.re_active;
   data_ptr.SRR_RL_CAPABILITY.CAP_SLBlockageFilterValue = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_CAPABILITY.CAP_SLBlockageFlag        = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_CAPABILITY.CAP_DampingCurrent        = ipc_d2m->payload.radar_capability_data.dm.damping.current_dB;
   data_ptr.SRR_RL_CAPABILITY.CAP_DampingStandardDeviation =
      Float2Fix(ipc_d2m->payload.radar_capability_data.dm.damping.std_dB, u8p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_SLLMonitoringStatus   = ipc_d2m->payload.radar_capability_data.pbd.status;
   data_ptr.SRR_RL_CAPABILITY.CAP_SLLMonitoringActive   = ipc_d2m->payload.radar_capability_data.pbd.pbd_active;
   data_ptr.SRR_RL_CAPABILITY.CAP_RangeEstimationStatus = ipc_d2m->payload.radar_capability_data.re.re_status;
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetectionRangeCar_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[0], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetectionRangeCar_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[1], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetectionRangeCar_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_car[2], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangeMotorbike_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[0], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangeMotorbike_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[1], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangeMotorbike_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_motorbike[2], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangePedestrian_0 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[0], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangePedestrian_1 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[1], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_MaxDetRangePedestrian_2 =
      Float2Fix(ipc_d2m->payload.radar_capability_data.re.max_det_range_pedestrian[2], u16p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_AngleAzimuthRangeStart =
      Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_begin_rad[0], s15p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_AngleAzimuthRangeEnd =
      Float2Fix(ipc_d2m->payload.radar_capability_data.az_fov_end_rad[0], s15p0_T);
   data_ptr.SRR_RL_CAPABILITY.CAP_SideLobeLevelBeamformer =
      ipc_d2m->payload.radar_capability_data.pbd.az_sector[0].side_lobe_level;
   data_ptr.SRR_RL_CAPABILITY.CAP_MH_CRC16      = 0;
   data_ptr.SRR_RL_CAPABILITY.CAP_CYCLE_COUNTER = 0;

   // SRR_RL_DETECTION_001_004_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_001 = af_target_report_ptr[0].ran;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_002 = af_target_report_ptr[1].ran;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_003 = af_target_report_ptr[2].ran;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_004 = af_target_report_ptr[3].ran;

   data_ptr.SRR_RL_DETECTION_001_004.DET_AZIMUTH_001 = af_target_report_ptr[0].theta;
   data_ptr.SRR_RL_DETECTION_001_004.DET_AZIMUTH_002 = af_target_report_ptr[1].theta;
   data_ptr.SRR_RL_DETECTION_001_004.DET_AZIMUTH_003 = af_target_report_ptr[2].theta;
   data_ptr.SRR_RL_DETECTION_001_004.DET_AZIMUTH_004 = af_target_report_ptr[3].theta;

   data_ptr.SRR_RL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_001 = 0;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_002 = 0;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_003 = 0;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BELOW_RAIN_THOLD_004 = 0;

   data_ptr.SRR_RL_DETECTION_001_004.DET_BI_STATIC_FLAG_004 = af_target_report_ptr[3].f_bistatic;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BI_STATIC_FLAG_003 = af_target_report_ptr[2].f_bistatic;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BI_STATIC_FLAG_002 = af_target_report_ptr[1].f_bistatic;
   data_ptr.SRR_RL_DETECTION_001_004.DET_BI_STATIC_FLAG_001 = af_target_report_ptr[0].f_bistatic;

   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_AZIMUTH_001 = af_target_report_ptr[0].az_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_AZIMUTH_002 = af_target_report_ptr[1].az_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_AZIMUTH_003 = af_target_report_ptr[2].az_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_AZIMUTH_004 = af_target_report_ptr[3].az_conf;

   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_001 = af_target_report_ptr[0].phi;
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_002 = af_target_report_ptr[1].phi;
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_003 = af_target_report_ptr[2].phi;
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_004 = af_target_report_ptr[3].phi;

   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_ELEVATION_001 = af_target_report_ptr[0].el_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_ELEVATION_002 = af_target_report_ptr[1].el_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_ELEVATION_003 = af_target_report_ptr[2].el_conf;
   data_ptr.SRR_RL_DETECTION_001_004.DET_CONFD_ELEVATION_004 = af_target_report_ptr[3].el_conf;

   data_ptr.SRR_RL_DETECTION_001_004.DET_EXISTENCE_PROB_001 = TOI_DS_Stream_Ptr->existence_prob[0];
   data_ptr.SRR_RL_DETECTION_001_004.DET_EXISTENCE_PROB_002 = TOI_DS_Stream_Ptr->existence_prob[1];
   data_ptr.SRR_RL_DETECTION_001_004.DET_EXISTENCE_PROB_003 = TOI_DS_Stream_Ptr->existence_prob[2];
   data_ptr.SRR_RL_DETECTION_001_004.DET_EXISTENCE_PROB_004 = TOI_DS_Stream_Ptr->existence_prob[3];

   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_ERR_001 = TOI_DS_Stream_Ptr->std_phi[0];
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_ERR_002 = TOI_DS_Stream_Ptr->std_phi[1];
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_ERR_003 = TOI_DS_Stream_Ptr->std_phi[2];
   data_ptr.SRR_RL_DETECTION_001_004.DET_ELEVATION_ERR_004 = TOI_DS_Stream_Ptr->std_phi[3];

   data_ptr.SRR_RL_DETECTION_001_004.DET_HVC_FLAG_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_HVC_FLAG_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_HVC_FLAG_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_HVC_FLAG_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_001_004.DET_IDM_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_IDM_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_IDM_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_IDM_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_001_004.DET_MH_CYCLE_COUNTER_001_004   = 0;
   data_ptr.SRR_RL_DETECTION_001_004.DET_MH_CRC16_001_004           = 0;
   data_ptr.SRR_RL_DETECTION_001_004.DET_MH_SCAN_INDEX_4LSB_001_004 = 0;

   data_ptr.SRR_RL_DETECTION_001_004.DET_MTD_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_MTD_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_MTD_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_MTD_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_001_004.DET_PROB_1STAZHYPO_001 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_PROB_1STAZHYPO_002 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_PROB_1STAZHYPO_003 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_001_004.DET_PROB_1STAZHYPO_004 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_ERR_001 = TOI_DS_Stream_Ptr->std_ran[0];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_ERR_002 = TOI_DS_Stream_Ptr->std_ran[1];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_ERR_003 = TOI_DS_Stream_Ptr->std_ran[2];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_ERR_004 = TOI_DS_Stream_Ptr->std_ran[3];

   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_001 = af_target_report_ptr[0].vel;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_002 = af_target_report_ptr[1].vel;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_003 = af_target_report_ptr[2].vel;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_004 = af_target_report_ptr[3].vel;

   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_001 = TOI_DS_Stream_Ptr->std_vel[0];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_002 = TOI_DS_Stream_Ptr->std_vel[1];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_003 = TOI_DS_Stream_Ptr->std_vel[2];
   data_ptr.SRR_RL_DETECTION_001_004.DET_RANGE_VELOCITY_ERR_004 = TOI_DS_Stream_Ptr->std_vel[3];

   data_ptr.SRR_RL_DETECTION_001_004.DET_RCS_001 = af_target_report_ptr[0].rcs;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RCS_002 = af_target_report_ptr[1].rcs;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RCS_003 = af_target_report_ptr[2].rcs;
   data_ptr.SRR_RL_DETECTION_001_004.DET_RCS_004 = af_target_report_ptr[3].rcs;

   data_ptr.SRR_RL_DETECTION_001_004.DET_SNR_001 = af_target_report_ptr[0].snr;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SNR_002 = af_target_report_ptr[1].snr;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SNR_003 = af_target_report_ptr[2].snr;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SNR_004 = af_target_report_ptr[3].snr;

   data_ptr.SRR_RL_DETECTION_001_004.DET_SUPER_RES_TARGET_001 = af_target_report_ptr[0].f_superres_target;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SUPER_RES_TARGET_002 = af_target_report_ptr[1].f_superres_target;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SUPER_RES_TARGET_003 = af_target_report_ptr[2].f_superres_target;
   data_ptr.SRR_RL_DETECTION_001_004.DET_SUPER_RES_TARGET_004 = af_target_report_ptr[3].f_superres_target;

   // SRR_RL_DETECTION_005_008_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_005 = af_target_report_ptr[4].ran;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_006 = af_target_report_ptr[5].ran;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_007 = af_target_report_ptr[6].ran;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_008 = af_target_report_ptr[7].ran;

   data_ptr.SRR_RL_DETECTION_005_008.DET_AZIMUTH_005 = af_target_report_ptr[4].theta;
   data_ptr.SRR_RL_DETECTION_005_008.DET_AZIMUTH_006 = af_target_report_ptr[5].theta;
   data_ptr.SRR_RL_DETECTION_005_008.DET_AZIMUTH_007 = af_target_report_ptr[6].theta;
   data_ptr.SRR_RL_DETECTION_005_008.DET_AZIMUTH_008 = af_target_report_ptr[7].theta;

   data_ptr.SRR_RL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_005 = 0;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_006 = 0;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_007 = 0;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BELOW_RAIN_THOLD_008 = 0;

   data_ptr.SRR_RL_DETECTION_005_008.DET_BI_STATIC_FLAG_005 = af_target_report_ptr[4].f_bistatic;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BI_STATIC_FLAG_006 = af_target_report_ptr[5].f_bistatic;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BI_STATIC_FLAG_007 = af_target_report_ptr[6].f_bistatic;
   data_ptr.SRR_RL_DETECTION_005_008.DET_BI_STATIC_FLAG_008 = af_target_report_ptr[7].f_bistatic;

   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_AZIMUTH_005 = af_target_report_ptr[4].az_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_AZIMUTH_006 = af_target_report_ptr[5].az_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_AZIMUTH_007 = af_target_report_ptr[6].az_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_AZIMUTH_008 = af_target_report_ptr[7].az_conf;

   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_005 = af_target_report_ptr[4].phi;
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_006 = af_target_report_ptr[5].phi;
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_007 = af_target_report_ptr[6].phi;
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_008 = af_target_report_ptr[7].phi;

   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_ELEVATION_005 = af_target_report_ptr[4].el_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_ELEVATION_006 = af_target_report_ptr[5].el_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_ELEVATION_007 = af_target_report_ptr[6].el_conf;
   data_ptr.SRR_RL_DETECTION_005_008.DET_CONFD_ELEVATION_008 = af_target_report_ptr[7].el_conf;

   data_ptr.SRR_RL_DETECTION_005_008.DET_EXISTENCE_PROB_005 = TOI_DS_Stream_Ptr->existence_prob[4];
   data_ptr.SRR_RL_DETECTION_005_008.DET_EXISTENCE_PROB_006 = TOI_DS_Stream_Ptr->existence_prob[5];
   data_ptr.SRR_RL_DETECTION_005_008.DET_EXISTENCE_PROB_007 = TOI_DS_Stream_Ptr->existence_prob[6];
   data_ptr.SRR_RL_DETECTION_005_008.DET_EXISTENCE_PROB_008 = TOI_DS_Stream_Ptr->existence_prob[7];

   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_ERR_005 = TOI_DS_Stream_Ptr->std_phi[4];
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_ERR_006 = TOI_DS_Stream_Ptr->std_phi[5];
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_ERR_007 = TOI_DS_Stream_Ptr->std_phi[6];
   data_ptr.SRR_RL_DETECTION_005_008.DET_ELEVATION_ERR_008 = TOI_DS_Stream_Ptr->std_phi[7];

   data_ptr.SRR_RL_DETECTION_005_008.DET_HVC_FLAG_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_HVC_FLAG_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_HVC_FLAG_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_HVC_FLAG_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_005_008.DET_IDM_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_IDM_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_IDM_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_IDM_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_005_008.DET_MH_CYCLE_COUNTER_005_008   = 0;
   data_ptr.SRR_RL_DETECTION_005_008.DET_MH_CRC16_005_008           = 0;
   data_ptr.SRR_RL_DETECTION_005_008.DET_MH_SCAN_INDEX_4LSB_005_008 = 0;

   data_ptr.SRR_RL_DETECTION_005_008.DET_MTD_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_MTD_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_MTD_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_MTD_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_005_008.DET_PROB_1STAZHYPO_005 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_PROB_1STAZHYPO_006 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_PROB_1STAZHYPO_007 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_005_008.DET_PROB_1STAZHYPO_008 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_ERR_005 = TOI_DS_Stream_Ptr->std_ran[4];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_ERR_006 = TOI_DS_Stream_Ptr->std_ran[5];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_ERR_007 = TOI_DS_Stream_Ptr->std_ran[6];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_ERR_008 = TOI_DS_Stream_Ptr->std_ran[7];

   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_005 = af_target_report_ptr[4].vel;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_006 = af_target_report_ptr[5].vel;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_007 = af_target_report_ptr[6].vel;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_008 = af_target_report_ptr[7].vel;

   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_005 = TOI_DS_Stream_Ptr->std_vel[4];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_006 = TOI_DS_Stream_Ptr->std_vel[5];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_007 = TOI_DS_Stream_Ptr->std_vel[6];
   data_ptr.SRR_RL_DETECTION_005_008.DET_RANGE_VELOCITY_ERR_008 = TOI_DS_Stream_Ptr->std_vel[7];

   data_ptr.SRR_RL_DETECTION_005_008.DET_RCS_005 = af_target_report_ptr[4].rcs;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RCS_006 = af_target_report_ptr[5].rcs;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RCS_007 = af_target_report_ptr[6].rcs;
   data_ptr.SRR_RL_DETECTION_005_008.DET_RCS_008 = af_target_report_ptr[7].rcs;

   data_ptr.SRR_RL_DETECTION_005_008.DET_SNR_005 = af_target_report_ptr[4].snr;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SNR_006 = af_target_report_ptr[5].snr;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SNR_007 = af_target_report_ptr[6].snr;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SNR_008 = af_target_report_ptr[7].snr;

   data_ptr.SRR_RL_DETECTION_005_008.DET_SUPER_RES_TARGET_005 = af_target_report_ptr[4].f_superres_target;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SUPER_RES_TARGET_006 = af_target_report_ptr[5].f_superres_target;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SUPER_RES_TARGET_007 = af_target_report_ptr[6].f_superres_target;
   data_ptr.SRR_RL_DETECTION_005_008.DET_SUPER_RES_TARGET_008 = af_target_report_ptr[7].f_superres_target;

   // SRR_RL_DETECTION_009_012_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_009 = af_target_report_ptr[8].ran;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_010 = af_target_report_ptr[9].ran;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_011 = af_target_report_ptr[10].ran;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_012 = af_target_report_ptr[11].ran;

   data_ptr.SRR_RL_DETECTION_009_012.DET_AZIMUTH_009 = af_target_report_ptr[8].theta;
   data_ptr.SRR_RL_DETECTION_009_012.DET_AZIMUTH_010 = af_target_report_ptr[9].theta;
   data_ptr.SRR_RL_DETECTION_009_012.DET_AZIMUTH_011 = af_target_report_ptr[10].theta;
   data_ptr.SRR_RL_DETECTION_009_012.DET_AZIMUTH_012 = af_target_report_ptr[11].theta;

   data_ptr.SRR_RL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_009 = 0;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_010 = 0;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_011 = 0;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BELOW_RAIN_THOLD_012 = 0;

   data_ptr.SRR_RL_DETECTION_009_012.DET_BI_STATIC_FLAG_009 = af_target_report_ptr[8].f_bistatic;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BI_STATIC_FLAG_010 = af_target_report_ptr[9].f_bistatic;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BI_STATIC_FLAG_011 = af_target_report_ptr[10].f_bistatic;
   data_ptr.SRR_RL_DETECTION_009_012.DET_BI_STATIC_FLAG_012 = af_target_report_ptr[11].f_bistatic;

   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_AZIMUTH_009 = af_target_report_ptr[8].az_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_AZIMUTH_010 = af_target_report_ptr[9].az_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_AZIMUTH_011 = af_target_report_ptr[10].az_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_AZIMUTH_012 = af_target_report_ptr[11].az_conf;

   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_009 = af_target_report_ptr[8].phi;
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_010 = af_target_report_ptr[9].phi;
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_011 = af_target_report_ptr[10].phi;
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_012 = af_target_report_ptr[11].phi;

   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_ELEVATION_009 = af_target_report_ptr[8].el_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_ELEVATION_010 = af_target_report_ptr[9].el_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_ELEVATION_011 = af_target_report_ptr[10].el_conf;
   data_ptr.SRR_RL_DETECTION_009_012.DET_CONFD_ELEVATION_012 = af_target_report_ptr[11].el_conf;

   data_ptr.SRR_RL_DETECTION_009_012.DET_EXISTENCE_PROB_009 = TOI_DS_Stream_Ptr->existence_prob[8];
   data_ptr.SRR_RL_DETECTION_009_012.DET_EXISTENCE_PROB_010 = TOI_DS_Stream_Ptr->existence_prob[9];
   data_ptr.SRR_RL_DETECTION_009_012.DET_EXISTENCE_PROB_011 = TOI_DS_Stream_Ptr->existence_prob[10];
   data_ptr.SRR_RL_DETECTION_009_012.DET_EXISTENCE_PROB_012 = TOI_DS_Stream_Ptr->existence_prob[11];

   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_ERR_009 = TOI_DS_Stream_Ptr->std_phi[8];
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_ERR_010 = TOI_DS_Stream_Ptr->std_phi[9];
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_ERR_011 = TOI_DS_Stream_Ptr->std_phi[10];
   data_ptr.SRR_RL_DETECTION_009_012.DET_ELEVATION_ERR_012 = TOI_DS_Stream_Ptr->std_phi[11];

   data_ptr.SRR_RL_DETECTION_009_012.DET_HVC_FLAG_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_HVC_FLAG_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_HVC_FLAG_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_HVC_FLAG_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_009_012.DET_IDM_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_IDM_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_IDM_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_IDM_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_009_012.DET_MH_CYCLE_COUNTER_009_012   = 0;
   data_ptr.SRR_RL_DETECTION_009_012.DET_MH_CRC16_009_012           = 0;
   data_ptr.SRR_RL_DETECTION_009_012.DET_MH_SCAN_INDEX_4LSB_009_012 = 0;

   data_ptr.SRR_RL_DETECTION_009_012.DET_MTD_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_MTD_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_MTD_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_MTD_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_009_012.DET_PROB_1STAZHYPO_009 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_PROB_1STAZHYPO_010 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_PROB_1STAZHYPO_011 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_009_012.DET_PROB_1STAZHYPO_012 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_ERR_009 = TOI_DS_Stream_Ptr->std_ran[8];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_ERR_010 = TOI_DS_Stream_Ptr->std_ran[9];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_ERR_011 = TOI_DS_Stream_Ptr->std_ran[10];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_ERR_012 = TOI_DS_Stream_Ptr->std_ran[11];

   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_009 = af_target_report_ptr[8].vel;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_010 = af_target_report_ptr[9].vel;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_011 = af_target_report_ptr[10].vel;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_012 = af_target_report_ptr[11].vel;

   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_009 = TOI_DS_Stream_Ptr->std_vel[8];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_010 = TOI_DS_Stream_Ptr->std_vel[9];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_011 = TOI_DS_Stream_Ptr->std_vel[10];
   data_ptr.SRR_RL_DETECTION_009_012.DET_RANGE_VELOCITY_ERR_012 = TOI_DS_Stream_Ptr->std_vel[11];

   data_ptr.SRR_RL_DETECTION_009_012.DET_RCS_009 = af_target_report_ptr[8].rcs;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RCS_010 = af_target_report_ptr[9].rcs;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RCS_011 = af_target_report_ptr[10].rcs;
   data_ptr.SRR_RL_DETECTION_009_012.DET_RCS_012 = af_target_report_ptr[11].rcs;

   data_ptr.SRR_RL_DETECTION_009_012.DET_SNR_009 = af_target_report_ptr[8].snr;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SNR_010 = af_target_report_ptr[9].snr;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SNR_011 = af_target_report_ptr[10].snr;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SNR_012 = af_target_report_ptr[11].snr;

   data_ptr.SRR_RL_DETECTION_009_012.DET_SUPER_RES_TARGET_009 = af_target_report_ptr[8].f_superres_target;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SUPER_RES_TARGET_010 = af_target_report_ptr[9].f_superres_target;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SUPER_RES_TARGET_011 = af_target_report_ptr[10].f_superres_target;
   data_ptr.SRR_RL_DETECTION_009_012.DET_SUPER_RES_TARGET_012 = af_target_report_ptr[11].f_superres_target;

   // SRR_RL_DETECTION_013_016_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_013 = af_target_report_ptr[12].ran;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_014 = af_target_report_ptr[13].ran;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_015 = af_target_report_ptr[14].ran;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_016 = af_target_report_ptr[15].ran;

   data_ptr.SRR_RL_DETECTION_013_016.DET_AZIMUTH_013 = af_target_report_ptr[12].theta;
   data_ptr.SRR_RL_DETECTION_013_016.DET_AZIMUTH_014 = af_target_report_ptr[13].theta;
   data_ptr.SRR_RL_DETECTION_013_016.DET_AZIMUTH_015 = af_target_report_ptr[14].theta;
   data_ptr.SRR_RL_DETECTION_013_016.DET_AZIMUTH_016 = af_target_report_ptr[15].theta;

   data_ptr.SRR_RL_DETECTION_013_016.DET_BI_STATIC_FLAG_013 = af_target_report_ptr[12].f_bistatic;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BI_STATIC_FLAG_014 = af_target_report_ptr[13].f_bistatic;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BI_STATIC_FLAG_015 = af_target_report_ptr[14].f_bistatic;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BI_STATIC_FLAG_016 = af_target_report_ptr[15].f_bistatic;

   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_AZIMUTH_013 = af_target_report_ptr[12].az_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_AZIMUTH_014 = af_target_report_ptr[13].az_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_AZIMUTH_015 = af_target_report_ptr[14].az_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_AZIMUTH_016 = af_target_report_ptr[15].az_conf;

   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_013 = af_target_report_ptr[12].phi;
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_014 = af_target_report_ptr[13].phi;
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_015 = af_target_report_ptr[14].phi;
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_016 = af_target_report_ptr[15].phi;

   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_ELEVATION_013 = af_target_report_ptr[12].el_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_ELEVATION_014 = af_target_report_ptr[13].el_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_ELEVATION_015 = af_target_report_ptr[14].el_conf;
   data_ptr.SRR_RL_DETECTION_013_016.DET_CONFD_ELEVATION_016 = af_target_report_ptr[15].el_conf;

   data_ptr.SRR_RL_DETECTION_013_016.DET_EXISTENCE_PROB_013 = TOI_DS_Stream_Ptr->existence_prob[12];
   data_ptr.SRR_RL_DETECTION_013_016.DET_EXISTENCE_PROB_014 = TOI_DS_Stream_Ptr->existence_prob[13];
   data_ptr.SRR_RL_DETECTION_013_016.DET_EXISTENCE_PROB_015 = TOI_DS_Stream_Ptr->existence_prob[14];
   data_ptr.SRR_RL_DETECTION_013_016.DET_EXISTENCE_PROB_016 = TOI_DS_Stream_Ptr->existence_prob[15];

   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_ERR_013 = TOI_DS_Stream_Ptr->std_phi[12];
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_ERR_014 = TOI_DS_Stream_Ptr->std_phi[13];
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_ERR_015 = TOI_DS_Stream_Ptr->std_phi[14];
   data_ptr.SRR_RL_DETECTION_013_016.DET_ELEVATION_ERR_016 = TOI_DS_Stream_Ptr->std_phi[15];

   data_ptr.SRR_RL_DETECTION_013_016.DET_IDM_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_IDM_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_IDM_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_IDM_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_013_016.DET_MTD_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_MTD_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_MTD_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_MTD_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_013_016.DET_PROB_1STAZHYPO_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_PROB_1STAZHYPO_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_PROB_1STAZHYPO_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_PROB_1STAZHYPO_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_ERR_013 = TOI_DS_Stream_Ptr->std_ran[12];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_ERR_014 = TOI_DS_Stream_Ptr->std_ran[13];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_ERR_015 = TOI_DS_Stream_Ptr->std_ran[14];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_ERR_016 = TOI_DS_Stream_Ptr->std_ran[15];

   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_013 = af_target_report_ptr[12].vel;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_014 = af_target_report_ptr[13].vel;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_015 = af_target_report_ptr[14].vel;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_016 = af_target_report_ptr[15].vel;

   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_013 = TOI_DS_Stream_Ptr->std_vel[12];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_014 = TOI_DS_Stream_Ptr->std_vel[13];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_015 = TOI_DS_Stream_Ptr->std_vel[14];
   data_ptr.SRR_RL_DETECTION_013_016.DET_RANGE_VELOCITY_ERR_016 = TOI_DS_Stream_Ptr->std_vel[15];

   data_ptr.SRR_RL_DETECTION_013_016.DET_RCS_013 = af_target_report_ptr[12].rcs;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RCS_014 = af_target_report_ptr[13].rcs;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RCS_015 = af_target_report_ptr[14].rcs;
   data_ptr.SRR_RL_DETECTION_013_016.DET_RCS_016 = af_target_report_ptr[15].rcs;

   data_ptr.SRR_RL_DETECTION_013_016.DET_SNR_013 = af_target_report_ptr[12].snr;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SNR_014 = af_target_report_ptr[13].snr;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SNR_015 = af_target_report_ptr[14].snr;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SNR_016 = af_target_report_ptr[15].snr;

   data_ptr.SRR_RL_DETECTION_013_016.DET_SUPER_RES_TARGET_013 = af_target_report_ptr[12].f_superres_target;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SUPER_RES_TARGET_014 = af_target_report_ptr[13].f_superres_target;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SUPER_RES_TARGET_015 = af_target_report_ptr[14].f_superres_target;
   data_ptr.SRR_RL_DETECTION_013_016.DET_SUPER_RES_TARGET_016 = af_target_report_ptr[15].f_superres_target;

   data_ptr.SRR_RL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_013 = 0;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_014 = 0;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_015 = 0;
   data_ptr.SRR_RL_DETECTION_013_016.DET_BELOW_RAIN_THOLD_016 = 0;

   data_ptr.SRR_RL_DETECTION_013_016.DET_HVC_FLAG_013 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_HVC_FLAG_014 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_HVC_FLAG_015 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_013_016.DET_HVC_FLAG_016 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_013_016.DET_MH_CYCLE_COUNTER_013_016   = 0;
   data_ptr.SRR_RL_DETECTION_013_016.DET_MH_CRC16_013_016           = 0;
   data_ptr.SRR_RL_DETECTION_013_016.DET_MH_SCAN_INDEX_4LSB_013_016 = 0;

   // SRR_RL_DETECTION_017_020_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_017 = af_target_report_ptr[16].ran;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_018 = af_target_report_ptr[17].ran;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_019 = af_target_report_ptr[18].ran;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_020 = af_target_report_ptr[19].ran;

   data_ptr.SRR_RL_DETECTION_017_020.DET_AZIMUTH_017 = af_target_report_ptr[16].theta;
   data_ptr.SRR_RL_DETECTION_017_020.DET_AZIMUTH_018 = af_target_report_ptr[17].theta;
   data_ptr.SRR_RL_DETECTION_017_020.DET_AZIMUTH_019 = af_target_report_ptr[18].theta;
   data_ptr.SRR_RL_DETECTION_017_020.DET_AZIMUTH_020 = af_target_report_ptr[19].theta;

   data_ptr.SRR_RL_DETECTION_017_020.DET_BI_STATIC_FLAG_017 = af_target_report_ptr[16].f_bistatic;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BI_STATIC_FLAG_018 = af_target_report_ptr[17].f_bistatic;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BI_STATIC_FLAG_019 = af_target_report_ptr[18].f_bistatic;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BI_STATIC_FLAG_020 = af_target_report_ptr[19].f_bistatic;

   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_AZIMUTH_017 = af_target_report_ptr[16].az_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_AZIMUTH_018 = af_target_report_ptr[17].az_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_AZIMUTH_019 = af_target_report_ptr[18].az_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_AZIMUTH_020 = af_target_report_ptr[19].az_conf;

   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_017 = af_target_report_ptr[16].phi;
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_018 = af_target_report_ptr[17].phi;
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_019 = af_target_report_ptr[18].phi;
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_020 = af_target_report_ptr[19].phi;

   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_ELEVATION_017 = af_target_report_ptr[16].el_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_ELEVATION_018 = af_target_report_ptr[17].el_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_ELEVATION_019 = af_target_report_ptr[18].el_conf;
   data_ptr.SRR_RL_DETECTION_017_020.DET_CONFD_ELEVATION_020 = af_target_report_ptr[19].el_conf;

   data_ptr.SRR_RL_DETECTION_017_020.DET_EXISTENCE_PROB_017 = TOI_DS_Stream_Ptr->existence_prob[16];
   data_ptr.SRR_RL_DETECTION_017_020.DET_EXISTENCE_PROB_018 = TOI_DS_Stream_Ptr->existence_prob[17];
   data_ptr.SRR_RL_DETECTION_017_020.DET_EXISTENCE_PROB_019 = TOI_DS_Stream_Ptr->existence_prob[18];
   data_ptr.SRR_RL_DETECTION_017_020.DET_EXISTENCE_PROB_020 = TOI_DS_Stream_Ptr->existence_prob[19];

   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_ERR_017 = TOI_DS_Stream_Ptr->std_phi[16];
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_ERR_018 = TOI_DS_Stream_Ptr->std_phi[17];
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_ERR_019 = TOI_DS_Stream_Ptr->std_phi[18];
   data_ptr.SRR_RL_DETECTION_017_020.DET_ELEVATION_ERR_020 = TOI_DS_Stream_Ptr->std_phi[19];

   data_ptr.SRR_RL_DETECTION_017_020.DET_IDM_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_IDM_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_IDM_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_IDM_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_017_020.DET_MTD_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_MTD_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_MTD_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_MTD_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_017_020.DET_PROB_1STAZHYPO_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_PROB_1STAZHYPO_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_PROB_1STAZHYPO_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_PROB_1STAZHYPO_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_ERR_017 = TOI_DS_Stream_Ptr->std_ran[16];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_ERR_018 = TOI_DS_Stream_Ptr->std_ran[17];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_ERR_019 = TOI_DS_Stream_Ptr->std_ran[18];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_ERR_020 = TOI_DS_Stream_Ptr->std_ran[19];

   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_017 = af_target_report_ptr[16].vel;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_018 = af_target_report_ptr[17].vel;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_019 = af_target_report_ptr[18].vel;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_020 = af_target_report_ptr[19].vel;

   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_017 = TOI_DS_Stream_Ptr->std_vel[16];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_018 = TOI_DS_Stream_Ptr->std_vel[17];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_019 = TOI_DS_Stream_Ptr->std_vel[18];
   data_ptr.SRR_RL_DETECTION_017_020.DET_RANGE_VELOCITY_ERR_020 = TOI_DS_Stream_Ptr->std_vel[19];

   data_ptr.SRR_RL_DETECTION_017_020.DET_RCS_017 = af_target_report_ptr[16].rcs;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RCS_018 = af_target_report_ptr[17].rcs;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RCS_019 = af_target_report_ptr[18].rcs;
   data_ptr.SRR_RL_DETECTION_017_020.DET_RCS_020 = af_target_report_ptr[19].rcs;

   data_ptr.SRR_RL_DETECTION_017_020.DET_SNR_017 = af_target_report_ptr[16].snr;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SNR_018 = af_target_report_ptr[17].snr;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SNR_019 = af_target_report_ptr[18].snr;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SNR_020 = af_target_report_ptr[19].snr;

   data_ptr.SRR_RL_DETECTION_017_020.DET_SUPER_RES_TARGET_017 = af_target_report_ptr[16].f_superres_target;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SUPER_RES_TARGET_018 = af_target_report_ptr[17].f_superres_target;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SUPER_RES_TARGET_019 = af_target_report_ptr[18].f_superres_target;
   data_ptr.SRR_RL_DETECTION_017_020.DET_SUPER_RES_TARGET_020 = af_target_report_ptr[19].f_superres_target;

   data_ptr.SRR_RL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_017 = 0;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_018 = 0;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_019 = 0;
   data_ptr.SRR_RL_DETECTION_017_020.DET_BELOW_RAIN_THOLD_020 = 0;

   data_ptr.SRR_RL_DETECTION_017_020.DET_HVC_FLAG_017 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_HVC_FLAG_018 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_HVC_FLAG_019 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_017_020.DET_HVC_FLAG_020 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_017_020.DET_MH_CYCLE_COUNTER_017_020   = 0;
   data_ptr.SRR_RL_DETECTION_017_020.DET_MH_CRC16_017_020           = 0;
   data_ptr.SRR_RL_DETECTION_017_020.DET_MH_SCAN_INDEX_4LSB_017_020 = 0;

   // SRR_RL_DETECTION_021_024_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_021 = af_target_report_ptr[20].ran;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_022 = af_target_report_ptr[21].ran;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_023 = af_target_report_ptr[22].ran;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_024 = af_target_report_ptr[23].ran;

   data_ptr.SRR_RL_DETECTION_021_024.DET_AZIMUTH_021 = af_target_report_ptr[20].theta;
   data_ptr.SRR_RL_DETECTION_021_024.DET_AZIMUTH_022 = af_target_report_ptr[21].theta;
   data_ptr.SRR_RL_DETECTION_021_024.DET_AZIMUTH_023 = af_target_report_ptr[22].theta;
   data_ptr.SRR_RL_DETECTION_021_024.DET_AZIMUTH_024 = af_target_report_ptr[23].theta;

   data_ptr.SRR_RL_DETECTION_021_024.DET_BI_STATIC_FLAG_021 = af_target_report_ptr[20].f_bistatic;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BI_STATIC_FLAG_022 = af_target_report_ptr[21].f_bistatic;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BI_STATIC_FLAG_023 = af_target_report_ptr[22].f_bistatic;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BI_STATIC_FLAG_024 = af_target_report_ptr[23].f_bistatic;

   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_AZIMUTH_021 = af_target_report_ptr[20].az_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_AZIMUTH_022 = af_target_report_ptr[21].az_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_AZIMUTH_023 = af_target_report_ptr[22].az_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_AZIMUTH_024 = af_target_report_ptr[23].az_conf;

   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_021 = af_target_report_ptr[20].phi;
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_022 = af_target_report_ptr[21].phi;
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_023 = af_target_report_ptr[22].phi;
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_024 = af_target_report_ptr[23].phi;

   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_ELEVATION_021 = af_target_report_ptr[20].el_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_ELEVATION_022 = af_target_report_ptr[21].el_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_ELEVATION_023 = af_target_report_ptr[22].el_conf;
   data_ptr.SRR_RL_DETECTION_021_024.DET_CONFD_ELEVATION_024 = af_target_report_ptr[23].el_conf;

   data_ptr.SRR_RL_DETECTION_021_024.DET_EXISTENCE_PROB_021 = TOI_DS_Stream_Ptr->existence_prob[20];
   data_ptr.SRR_RL_DETECTION_021_024.DET_EXISTENCE_PROB_022 = TOI_DS_Stream_Ptr->existence_prob[21];
   data_ptr.SRR_RL_DETECTION_021_024.DET_EXISTENCE_PROB_023 = TOI_DS_Stream_Ptr->existence_prob[22];
   data_ptr.SRR_RL_DETECTION_021_024.DET_EXISTENCE_PROB_024 = TOI_DS_Stream_Ptr->existence_prob[23];

   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_ERR_021 = TOI_DS_Stream_Ptr->std_phi[20];
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_ERR_022 = TOI_DS_Stream_Ptr->std_phi[21];
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_ERR_023 = TOI_DS_Stream_Ptr->std_phi[22];
   data_ptr.SRR_RL_DETECTION_021_024.DET_ELEVATION_ERR_024 = TOI_DS_Stream_Ptr->std_phi[23];

   data_ptr.SRR_RL_DETECTION_021_024.DET_IDM_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_IDM_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_IDM_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_IDM_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_021_024.DET_MTD_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_MTD_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_MTD_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_MTD_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_021_024.DET_PROB_1STAZHYPO_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_PROB_1STAZHYPO_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_PROB_1STAZHYPO_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_PROB_1STAZHYPO_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_ERR_021 = TOI_DS_Stream_Ptr->std_ran[20];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_ERR_022 = TOI_DS_Stream_Ptr->std_ran[21];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_ERR_023 = TOI_DS_Stream_Ptr->std_ran[22];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_ERR_024 = TOI_DS_Stream_Ptr->std_ran[23];

   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_021 = af_target_report_ptr[20].vel;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_022 = af_target_report_ptr[21].vel;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_023 = af_target_report_ptr[22].vel;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_024 = af_target_report_ptr[23].vel;

   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_021 = TOI_DS_Stream_Ptr->std_vel[20];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_022 = TOI_DS_Stream_Ptr->std_vel[21];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_023 = TOI_DS_Stream_Ptr->std_vel[22];
   data_ptr.SRR_RL_DETECTION_021_024.DET_RANGE_VELOCITY_ERR_024 = TOI_DS_Stream_Ptr->std_vel[23];

   data_ptr.SRR_RL_DETECTION_021_024.DET_RCS_021 = af_target_report_ptr[20].rcs;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RCS_022 = af_target_report_ptr[21].rcs;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RCS_023 = af_target_report_ptr[22].rcs;
   data_ptr.SRR_RL_DETECTION_021_024.DET_RCS_024 = af_target_report_ptr[23].rcs;

   data_ptr.SRR_RL_DETECTION_021_024.DET_SNR_021 = af_target_report_ptr[20].snr;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SNR_022 = af_target_report_ptr[21].snr;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SNR_023 = af_target_report_ptr[22].snr;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SNR_024 = af_target_report_ptr[23].snr;

   data_ptr.SRR_RL_DETECTION_021_024.DET_SUPER_RES_TARGET_021 = af_target_report_ptr[20].f_superres_target;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SUPER_RES_TARGET_022 = af_target_report_ptr[21].f_superres_target;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SUPER_RES_TARGET_023 = af_target_report_ptr[22].f_superres_target;
   data_ptr.SRR_RL_DETECTION_021_024.DET_SUPER_RES_TARGET_024 = af_target_report_ptr[23].f_superres_target;

   data_ptr.SRR_RL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_021 = 0;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_022 = 0;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_023 = 0;
   data_ptr.SRR_RL_DETECTION_021_024.DET_BELOW_RAIN_THOLD_024 = 0;

   data_ptr.SRR_RL_DETECTION_021_024.DET_HVC_FLAG_021 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_HVC_FLAG_022 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_HVC_FLAG_023 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_021_024.DET_HVC_FLAG_024 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_021_024.DET_MH_CYCLE_COUNTER_021_024   = 0;
   data_ptr.SRR_RL_DETECTION_021_024.DET_MH_CRC16_021_024           = 0;
   data_ptr.SRR_RL_DETECTION_021_024.DET_MH_SCAN_INDEX_4LSB_021_024 = 0;

   // SRR_RL_DETECTION_025_028_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_025 = af_target_report_ptr[24].ran;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_026 = af_target_report_ptr[25].ran;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_027 = af_target_report_ptr[26].ran;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_028 = af_target_report_ptr[27].ran;

   data_ptr.SRR_RL_DETECTION_025_028.DET_AZIMUTH_025 = af_target_report_ptr[24].theta;
   data_ptr.SRR_RL_DETECTION_025_028.DET_AZIMUTH_026 = af_target_report_ptr[25].theta;
   data_ptr.SRR_RL_DETECTION_025_028.DET_AZIMUTH_027 = af_target_report_ptr[26].theta;
   data_ptr.SRR_RL_DETECTION_025_028.DET_AZIMUTH_028 = af_target_report_ptr[27].theta;

   data_ptr.SRR_RL_DETECTION_025_028.DET_BI_STATIC_FLAG_025 = af_target_report_ptr[24].f_bistatic;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BI_STATIC_FLAG_026 = af_target_report_ptr[25].f_bistatic;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BI_STATIC_FLAG_027 = af_target_report_ptr[26].f_bistatic;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BI_STATIC_FLAG_028 = af_target_report_ptr[27].f_bistatic;

   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_AZIMUTH_025 = af_target_report_ptr[24].az_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_AZIMUTH_026 = af_target_report_ptr[25].az_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_AZIMUTH_027 = af_target_report_ptr[26].az_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_AZIMUTH_028 = af_target_report_ptr[27].az_conf;

   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_025 = af_target_report_ptr[24].phi;
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_026 = af_target_report_ptr[25].phi;
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_027 = af_target_report_ptr[26].phi;
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_028 = af_target_report_ptr[27].phi;

   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_ELEVATION_025 = af_target_report_ptr[24].el_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_ELEVATION_026 = af_target_report_ptr[25].el_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_ELEVATION_027 = af_target_report_ptr[26].el_conf;
   data_ptr.SRR_RL_DETECTION_025_028.DET_CONFD_ELEVATION_028 = af_target_report_ptr[27].el_conf;

   data_ptr.SRR_RL_DETECTION_025_028.DET_EXISTENCE_PROB_025 = TOI_DS_Stream_Ptr->existence_prob[24];
   data_ptr.SRR_RL_DETECTION_025_028.DET_EXISTENCE_PROB_026 = TOI_DS_Stream_Ptr->existence_prob[25];
   data_ptr.SRR_RL_DETECTION_025_028.DET_EXISTENCE_PROB_027 = TOI_DS_Stream_Ptr->existence_prob[26];
   data_ptr.SRR_RL_DETECTION_025_028.DET_EXISTENCE_PROB_028 = TOI_DS_Stream_Ptr->existence_prob[27];

   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_ERR_025 = TOI_DS_Stream_Ptr->std_phi[24];
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_ERR_026 = TOI_DS_Stream_Ptr->std_phi[25];
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_ERR_027 = TOI_DS_Stream_Ptr->std_phi[26];
   data_ptr.SRR_RL_DETECTION_025_028.DET_ELEVATION_ERR_028 = TOI_DS_Stream_Ptr->std_phi[27];

   data_ptr.SRR_RL_DETECTION_025_028.DET_IDM_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_IDM_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_IDM_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_IDM_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_025_028.DET_MTD_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_MTD_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_MTD_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_MTD_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_025_028.DET_PROB_1STAZHYPO_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_PROB_1STAZHYPO_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_PROB_1STAZHYPO_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_PROB_1STAZHYPO_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_ERR_025 = TOI_DS_Stream_Ptr->std_ran[24];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_ERR_026 = TOI_DS_Stream_Ptr->std_ran[25];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_ERR_027 = TOI_DS_Stream_Ptr->std_ran[26];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_ERR_028 = TOI_DS_Stream_Ptr->std_ran[27];

   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_025 = af_target_report_ptr[24].vel;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_026 = af_target_report_ptr[25].vel;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_027 = af_target_report_ptr[26].vel;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_028 = af_target_report_ptr[27].vel;

   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_025 = TOI_DS_Stream_Ptr->std_vel[24];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_026 = TOI_DS_Stream_Ptr->std_vel[25];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_027 = TOI_DS_Stream_Ptr->std_vel[26];
   data_ptr.SRR_RL_DETECTION_025_028.DET_RANGE_VELOCITY_ERR_028 = TOI_DS_Stream_Ptr->std_vel[27];

   data_ptr.SRR_RL_DETECTION_025_028.DET_RCS_025 = af_target_report_ptr[24].rcs;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RCS_026 = af_target_report_ptr[25].rcs;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RCS_027 = af_target_report_ptr[26].rcs;
   data_ptr.SRR_RL_DETECTION_025_028.DET_RCS_028 = af_target_report_ptr[27].rcs;

   data_ptr.SRR_RL_DETECTION_025_028.DET_SNR_025 = af_target_report_ptr[24].snr;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SNR_026 = af_target_report_ptr[25].snr;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SNR_027 = af_target_report_ptr[26].snr;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SNR_028 = af_target_report_ptr[27].snr;

   data_ptr.SRR_RL_DETECTION_025_028.DET_SUPER_RES_TARGET_025 = af_target_report_ptr[24].f_superres_target;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SUPER_RES_TARGET_026 = af_target_report_ptr[25].f_superres_target;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SUPER_RES_TARGET_027 = af_target_report_ptr[26].f_superres_target;
   data_ptr.SRR_RL_DETECTION_025_028.DET_SUPER_RES_TARGET_028 = af_target_report_ptr[27].f_superres_target;

   data_ptr.SRR_RL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_025 = 0;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_026 = 0;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_027 = 0;
   data_ptr.SRR_RL_DETECTION_025_028.DET_BELOW_RAIN_THOLD_028 = 0;

   data_ptr.SRR_RL_DETECTION_025_028.DET_HVC_FLAG_025 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_HVC_FLAG_026 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_HVC_FLAG_027 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_025_028.DET_HVC_FLAG_028 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_025_028.DET_MH_CYCLE_COUNTER_025_028   = 0;
   data_ptr.SRR_RL_DETECTION_025_028.DET_MH_CRC16_025_028           = 0;
   data_ptr.SRR_RL_DETECTION_025_028.DET_MH_SCAN_INDEX_4LSB_025_028 = 0;

   // SRR_RL_DETECTION_029_032_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_029 = af_target_report_ptr[28].ran;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_030 = af_target_report_ptr[29].ran;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_031 = af_target_report_ptr[30].ran;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_032 = af_target_report_ptr[31].ran;

   data_ptr.SRR_RL_DETECTION_029_032.DET_AZIMUTH_029 = af_target_report_ptr[28].theta;
   data_ptr.SRR_RL_DETECTION_029_032.DET_AZIMUTH_030 = af_target_report_ptr[29].theta;
   data_ptr.SRR_RL_DETECTION_029_032.DET_AZIMUTH_031 = af_target_report_ptr[30].theta;
   data_ptr.SRR_RL_DETECTION_029_032.DET_AZIMUTH_032 = af_target_report_ptr[31].theta;

   data_ptr.SRR_RL_DETECTION_029_032.DET_BI_STATIC_FLAG_029 = af_target_report_ptr[28].f_bistatic;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BI_STATIC_FLAG_030 = af_target_report_ptr[29].f_bistatic;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BI_STATIC_FLAG_031 = af_target_report_ptr[30].f_bistatic;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BI_STATIC_FLAG_032 = af_target_report_ptr[31].f_bistatic;

   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_AZIMUTH_029 = af_target_report_ptr[28].az_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_AZIMUTH_030 = af_target_report_ptr[29].az_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_AZIMUTH_031 = af_target_report_ptr[30].az_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_AZIMUTH_032 = af_target_report_ptr[31].az_conf;

   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_029 = af_target_report_ptr[28].phi;
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_030 = af_target_report_ptr[29].phi;
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_031 = af_target_report_ptr[30].phi;
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_032 = af_target_report_ptr[31].phi;

   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_ELEVATION_029 = af_target_report_ptr[28].el_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_ELEVATION_030 = af_target_report_ptr[29].el_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_ELEVATION_031 = af_target_report_ptr[30].el_conf;
   data_ptr.SRR_RL_DETECTION_029_032.DET_CONFD_ELEVATION_032 = af_target_report_ptr[31].el_conf;

   data_ptr.SRR_RL_DETECTION_029_032.DET_EXISTENCE_PROB_029 = TOI_DS_Stream_Ptr->existence_prob[28];
   data_ptr.SRR_RL_DETECTION_029_032.DET_EXISTENCE_PROB_030 = TOI_DS_Stream_Ptr->existence_prob[29];
   data_ptr.SRR_RL_DETECTION_029_032.DET_EXISTENCE_PROB_031 = TOI_DS_Stream_Ptr->existence_prob[30];
   data_ptr.SRR_RL_DETECTION_029_032.DET_EXISTENCE_PROB_032 = TOI_DS_Stream_Ptr->existence_prob[31];

   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_ERR_029 = TOI_DS_Stream_Ptr->std_phi[28];
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_ERR_030 = TOI_DS_Stream_Ptr->std_phi[29];
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_ERR_031 = TOI_DS_Stream_Ptr->std_phi[30];
   data_ptr.SRR_RL_DETECTION_029_032.DET_ELEVATION_ERR_032 = TOI_DS_Stream_Ptr->std_phi[31];

   data_ptr.SRR_RL_DETECTION_029_032.DET_IDM_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_IDM_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_IDM_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_IDM_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_029_032.DET_MTD_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_MTD_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_MTD_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_MTD_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_029_032.DET_PROB_1STAZHYPO_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_PROB_1STAZHYPO_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_PROB_1STAZHYPO_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_PROB_1STAZHYPO_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_ERR_029 = TOI_DS_Stream_Ptr->std_ran[28];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_ERR_030 = TOI_DS_Stream_Ptr->std_ran[29];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_ERR_031 = TOI_DS_Stream_Ptr->std_ran[30];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_ERR_032 = TOI_DS_Stream_Ptr->std_ran[31];

   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_029 = af_target_report_ptr[28].vel;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_030 = af_target_report_ptr[29].vel;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_031 = af_target_report_ptr[30].vel;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_032 = af_target_report_ptr[31].vel;

   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_029 = TOI_DS_Stream_Ptr->std_vel[28];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_030 = TOI_DS_Stream_Ptr->std_vel[29];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_031 = TOI_DS_Stream_Ptr->std_vel[30];
   data_ptr.SRR_RL_DETECTION_029_032.DET_RANGE_VELOCITY_ERR_032 = TOI_DS_Stream_Ptr->std_vel[31];

   data_ptr.SRR_RL_DETECTION_029_032.DET_RCS_029 = af_target_report_ptr[28].rcs;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RCS_030 = af_target_report_ptr[29].rcs;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RCS_031 = af_target_report_ptr[30].rcs;
   data_ptr.SRR_RL_DETECTION_029_032.DET_RCS_032 = af_target_report_ptr[31].rcs;

   data_ptr.SRR_RL_DETECTION_029_032.DET_SNR_029 = af_target_report_ptr[28].snr;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SNR_030 = af_target_report_ptr[29].snr;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SNR_031 = af_target_report_ptr[30].snr;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SNR_032 = af_target_report_ptr[31].snr;

   data_ptr.SRR_RL_DETECTION_029_032.DET_SUPER_RES_TARGET_029 = af_target_report_ptr[28].f_superres_target;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SUPER_RES_TARGET_030 = af_target_report_ptr[29].f_superres_target;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SUPER_RES_TARGET_031 = af_target_report_ptr[30].f_superres_target;
   data_ptr.SRR_RL_DETECTION_029_032.DET_SUPER_RES_TARGET_032 = af_target_report_ptr[31].f_superres_target;

   data_ptr.SRR_RL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_029 = 0;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_030 = 0;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_031 = 0;
   data_ptr.SRR_RL_DETECTION_029_032.DET_BELOW_RAIN_THOLD_032 = 0;

   data_ptr.SRR_RL_DETECTION_029_032.DET_HVC_FLAG_029 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_HVC_FLAG_030 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_HVC_FLAG_031 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_029_032.DET_HVC_FLAG_032 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_029_032.DET_MH_CYCLE_COUNTER_029_032   = 0;
   data_ptr.SRR_RL_DETECTION_029_032.DET_MH_CRC16_029_032           = 0;
   data_ptr.SRR_RL_DETECTION_029_032.DET_MH_SCAN_INDEX_4LSB_029_032 = 0;

   // SRR_RL_DETECTION_033_036_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_033 = af_target_report_ptr[32].ran;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_034 = af_target_report_ptr[33].ran;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_035 = af_target_report_ptr[34].ran;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_036 = af_target_report_ptr[35].ran;

   data_ptr.SRR_RL_DETECTION_033_036.DET_AZIMUTH_033 = af_target_report_ptr[32].theta;
   data_ptr.SRR_RL_DETECTION_033_036.DET_AZIMUTH_034 = af_target_report_ptr[33].theta;
   data_ptr.SRR_RL_DETECTION_033_036.DET_AZIMUTH_035 = af_target_report_ptr[34].theta;
   data_ptr.SRR_RL_DETECTION_033_036.DET_AZIMUTH_036 = af_target_report_ptr[35].theta;

   data_ptr.SRR_RL_DETECTION_033_036.DET_BI_STATIC_FLAG_033 = af_target_report_ptr[32].f_bistatic;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BI_STATIC_FLAG_034 = af_target_report_ptr[33].f_bistatic;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BI_STATIC_FLAG_035 = af_target_report_ptr[34].f_bistatic;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BI_STATIC_FLAG_036 = af_target_report_ptr[35].f_bistatic;

   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_AZIMUTH_033 = af_target_report_ptr[32].az_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_AZIMUTH_034 = af_target_report_ptr[33].az_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_AZIMUTH_035 = af_target_report_ptr[34].az_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_AZIMUTH_036 = af_target_report_ptr[35].az_conf;

   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_033 = af_target_report_ptr[32].phi;
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_034 = af_target_report_ptr[33].phi;
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_035 = af_target_report_ptr[34].phi;
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_036 = af_target_report_ptr[35].phi;

   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_ELEVATION_033 = af_target_report_ptr[32].el_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_ELEVATION_034 = af_target_report_ptr[33].el_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_ELEVATION_035 = af_target_report_ptr[34].el_conf;
   data_ptr.SRR_RL_DETECTION_033_036.DET_CONFD_ELEVATION_036 = af_target_report_ptr[35].el_conf;

   data_ptr.SRR_RL_DETECTION_033_036.DET_EXISTENCE_PROB_033 = TOI_DS_Stream_Ptr->existence_prob[32];
   data_ptr.SRR_RL_DETECTION_033_036.DET_EXISTENCE_PROB_034 = TOI_DS_Stream_Ptr->existence_prob[33];
   data_ptr.SRR_RL_DETECTION_033_036.DET_EXISTENCE_PROB_035 = TOI_DS_Stream_Ptr->existence_prob[34];
   data_ptr.SRR_RL_DETECTION_033_036.DET_EXISTENCE_PROB_036 = TOI_DS_Stream_Ptr->existence_prob[35];

   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_ERR_033 = TOI_DS_Stream_Ptr->std_phi[32];
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_ERR_034 = TOI_DS_Stream_Ptr->std_phi[33];
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_ERR_035 = TOI_DS_Stream_Ptr->std_phi[34];
   data_ptr.SRR_RL_DETECTION_033_036.DET_ELEVATION_ERR_036 = TOI_DS_Stream_Ptr->std_phi[35];

   data_ptr.SRR_RL_DETECTION_033_036.DET_IDM_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_IDM_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_IDM_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_IDM_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_033_036.DET_MTD_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_MTD_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_MTD_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_MTD_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_033_036.DET_PROB_1STAZHYPO_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_PROB_1STAZHYPO_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_PROB_1STAZHYPO_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_PROB_1STAZHYPO_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_ERR_033 = TOI_DS_Stream_Ptr->std_ran[32];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_ERR_034 = TOI_DS_Stream_Ptr->std_ran[33];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_ERR_035 = TOI_DS_Stream_Ptr->std_ran[34];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_ERR_036 = TOI_DS_Stream_Ptr->std_ran[35];

   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_033 = af_target_report_ptr[32].vel;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_034 = af_target_report_ptr[33].vel;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_035 = af_target_report_ptr[34].vel;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_036 = af_target_report_ptr[35].vel;

   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_033 = TOI_DS_Stream_Ptr->std_vel[32];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_034 = TOI_DS_Stream_Ptr->std_vel[33];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_035 = TOI_DS_Stream_Ptr->std_vel[34];
   data_ptr.SRR_RL_DETECTION_033_036.DET_RANGE_VELOCITY_ERR_036 = TOI_DS_Stream_Ptr->std_vel[35];

   data_ptr.SRR_RL_DETECTION_033_036.DET_RCS_033 = af_target_report_ptr[32].rcs;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RCS_034 = af_target_report_ptr[33].rcs;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RCS_035 = af_target_report_ptr[34].rcs;
   data_ptr.SRR_RL_DETECTION_033_036.DET_RCS_036 = af_target_report_ptr[35].rcs;

   data_ptr.SRR_RL_DETECTION_033_036.DET_SNR_033 = af_target_report_ptr[32].snr;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SNR_034 = af_target_report_ptr[33].snr;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SNR_035 = af_target_report_ptr[34].snr;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SNR_036 = af_target_report_ptr[35].snr;

   data_ptr.SRR_RL_DETECTION_033_036.DET_SUPER_RES_TARGET_033 = af_target_report_ptr[32].f_superres_target;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SUPER_RES_TARGET_034 = af_target_report_ptr[33].f_superres_target;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SUPER_RES_TARGET_035 = af_target_report_ptr[34].f_superres_target;
   data_ptr.SRR_RL_DETECTION_033_036.DET_SUPER_RES_TARGET_036 = af_target_report_ptr[35].f_superres_target;

   data_ptr.SRR_RL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_033 = 0;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_034 = 0;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_035 = 0;
   data_ptr.SRR_RL_DETECTION_033_036.DET_BELOW_RAIN_THOLD_036 = 0;

   data_ptr.SRR_RL_DETECTION_033_036.DET_HVC_FLAG_033 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_HVC_FLAG_034 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_HVC_FLAG_035 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_033_036.DET_HVC_FLAG_036 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_033_036.DET_MH_CYCLE_COUNTER_033_036   = 0;
   data_ptr.SRR_RL_DETECTION_033_036.DET_MH_CRC16_033_036           = 0;
   data_ptr.SRR_RL_DETECTION_033_036.DET_MH_SCAN_INDEX_4LSB_033_036 = 0;

   // SRR_RL_DETECTION_037_040_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_037 = af_target_report_ptr[36].ran;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_038 = af_target_report_ptr[37].ran;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_039 = af_target_report_ptr[38].ran;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_040 = af_target_report_ptr[39].ran;

   data_ptr.SRR_RL_DETECTION_037_040.DET_AZIMUTH_037 = af_target_report_ptr[36].theta;
   data_ptr.SRR_RL_DETECTION_037_040.DET_AZIMUTH_038 = af_target_report_ptr[37].theta;
   data_ptr.SRR_RL_DETECTION_037_040.DET_AZIMUTH_039 = af_target_report_ptr[38].theta;
   data_ptr.SRR_RL_DETECTION_037_040.DET_AZIMUTH_040 = af_target_report_ptr[39].theta;

   data_ptr.SRR_RL_DETECTION_037_040.DET_BI_STATIC_FLAG_037 = af_target_report_ptr[36].f_bistatic;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BI_STATIC_FLAG_038 = af_target_report_ptr[37].f_bistatic;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BI_STATIC_FLAG_039 = af_target_report_ptr[38].f_bistatic;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BI_STATIC_FLAG_040 = af_target_report_ptr[39].f_bistatic;

   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_AZIMUTH_037 = af_target_report_ptr[36].az_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_AZIMUTH_038 = af_target_report_ptr[37].az_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_AZIMUTH_039 = af_target_report_ptr[38].az_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_AZIMUTH_040 = af_target_report_ptr[39].az_conf;

   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_037 = af_target_report_ptr[36].phi;
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_038 = af_target_report_ptr[37].phi;
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_039 = af_target_report_ptr[38].phi;
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_040 = af_target_report_ptr[39].phi;

   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_ELEVATION_037 = af_target_report_ptr[36].el_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_ELEVATION_038 = af_target_report_ptr[37].el_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_ELEVATION_039 = af_target_report_ptr[38].el_conf;
   data_ptr.SRR_RL_DETECTION_037_040.DET_CONFD_ELEVATION_040 = af_target_report_ptr[39].el_conf;

   data_ptr.SRR_RL_DETECTION_037_040.DET_EXISTENCE_PROB_037 = TOI_DS_Stream_Ptr->existence_prob[36];
   data_ptr.SRR_RL_DETECTION_037_040.DET_EXISTENCE_PROB_038 = TOI_DS_Stream_Ptr->existence_prob[37];
   data_ptr.SRR_RL_DETECTION_037_040.DET_EXISTENCE_PROB_039 = TOI_DS_Stream_Ptr->existence_prob[38];
   data_ptr.SRR_RL_DETECTION_037_040.DET_EXISTENCE_PROB_040 = TOI_DS_Stream_Ptr->existence_prob[39];

   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_ERR_037 = TOI_DS_Stream_Ptr->std_phi[36];
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_ERR_038 = TOI_DS_Stream_Ptr->std_phi[37];
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_ERR_039 = TOI_DS_Stream_Ptr->std_phi[38];
   data_ptr.SRR_RL_DETECTION_037_040.DET_ELEVATION_ERR_040 = TOI_DS_Stream_Ptr->std_phi[39];

   data_ptr.SRR_RL_DETECTION_037_040.DET_IDM_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_IDM_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_IDM_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_IDM_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_037_040.DET_MTD_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_MTD_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_MTD_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_MTD_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_037_040.DET_PROB_1STAZHYPO_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_PROB_1STAZHYPO_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_PROB_1STAZHYPO_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_PROB_1STAZHYPO_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_ERR_037 = TOI_DS_Stream_Ptr->std_ran[36];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_ERR_038 = TOI_DS_Stream_Ptr->std_ran[37];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_ERR_039 = TOI_DS_Stream_Ptr->std_ran[38];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_ERR_040 = TOI_DS_Stream_Ptr->std_ran[39];

   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_037 = af_target_report_ptr[36].vel;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_038 = af_target_report_ptr[37].vel;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_039 = af_target_report_ptr[38].vel;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_040 = af_target_report_ptr[39].vel;

   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_037 = TOI_DS_Stream_Ptr->std_vel[36];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_038 = TOI_DS_Stream_Ptr->std_vel[37];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_039 = TOI_DS_Stream_Ptr->std_vel[38];
   data_ptr.SRR_RL_DETECTION_037_040.DET_RANGE_VELOCITY_ERR_040 = TOI_DS_Stream_Ptr->std_vel[39];

   data_ptr.SRR_RL_DETECTION_037_040.DET_RCS_037 = af_target_report_ptr[36].rcs;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RCS_038 = af_target_report_ptr[37].rcs;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RCS_039 = af_target_report_ptr[38].rcs;
   data_ptr.SRR_RL_DETECTION_037_040.DET_RCS_040 = af_target_report_ptr[39].rcs;

   data_ptr.SRR_RL_DETECTION_037_040.DET_SNR_037 = af_target_report_ptr[36].snr;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SNR_038 = af_target_report_ptr[37].snr;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SNR_039 = af_target_report_ptr[38].snr;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SNR_040 = af_target_report_ptr[39].snr;

   data_ptr.SRR_RL_DETECTION_037_040.DET_SUPER_RES_TARGET_037 = af_target_report_ptr[36].f_superres_target;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SUPER_RES_TARGET_038 = af_target_report_ptr[37].f_superres_target;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SUPER_RES_TARGET_039 = af_target_report_ptr[38].f_superres_target;
   data_ptr.SRR_RL_DETECTION_037_040.DET_SUPER_RES_TARGET_040 = af_target_report_ptr[39].f_superres_target;

   data_ptr.SRR_RL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_037 = 0;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_038 = 0;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_039 = 0;
   data_ptr.SRR_RL_DETECTION_037_040.DET_BELOW_RAIN_THOLD_040 = 0;

   data_ptr.SRR_RL_DETECTION_037_040.DET_HVC_FLAG_037 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_HVC_FLAG_038 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_HVC_FLAG_039 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_037_040.DET_HVC_FLAG_040 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_037_040.DET_MH_CYCLE_COUNTER_037_040   = 0;
   data_ptr.SRR_RL_DETECTION_037_040.DET_MH_CRC16_037_040           = 0;
   data_ptr.SRR_RL_DETECTION_037_040.DET_MH_SCAN_INDEX_4LSB_037_040 = 0;

   // SRR_RL_DETECTION_041_044_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_041 = af_target_report_ptr[40].ran;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_042 = af_target_report_ptr[41].ran;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_043 = af_target_report_ptr[42].ran;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_044 = af_target_report_ptr[43].ran;

   data_ptr.SRR_RL_DETECTION_041_044.DET_AZIMUTH_041 = af_target_report_ptr[40].theta;
   data_ptr.SRR_RL_DETECTION_041_044.DET_AZIMUTH_042 = af_target_report_ptr[41].theta;
   data_ptr.SRR_RL_DETECTION_041_044.DET_AZIMUTH_043 = af_target_report_ptr[42].theta;
   data_ptr.SRR_RL_DETECTION_041_044.DET_AZIMUTH_044 = af_target_report_ptr[43].theta;

   data_ptr.SRR_RL_DETECTION_041_044.DET_BI_STATIC_FLAG_041 = af_target_report_ptr[40].f_bistatic;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BI_STATIC_FLAG_042 = af_target_report_ptr[41].f_bistatic;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BI_STATIC_FLAG_043 = af_target_report_ptr[42].f_bistatic;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BI_STATIC_FLAG_044 = af_target_report_ptr[43].f_bistatic;

   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_AZIMUTH_041 = af_target_report_ptr[40].az_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_AZIMUTH_042 = af_target_report_ptr[41].az_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_AZIMUTH_043 = af_target_report_ptr[42].az_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_AZIMUTH_044 = af_target_report_ptr[43].az_conf;

   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_041 = af_target_report_ptr[40].phi;
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_042 = af_target_report_ptr[41].phi;
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_043 = af_target_report_ptr[42].phi;
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_044 = af_target_report_ptr[43].phi;

   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_ELEVATION_041 = af_target_report_ptr[40].el_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_ELEVATION_042 = af_target_report_ptr[41].el_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_ELEVATION_043 = af_target_report_ptr[42].el_conf;
   data_ptr.SRR_RL_DETECTION_041_044.DET_CONFD_ELEVATION_044 = af_target_report_ptr[43].el_conf;

   data_ptr.SRR_RL_DETECTION_041_044.DET_EXISTENCE_PROB_041 = TOI_DS_Stream_Ptr->existence_prob[40];
   data_ptr.SRR_RL_DETECTION_041_044.DET_EXISTENCE_PROB_042 = TOI_DS_Stream_Ptr->existence_prob[41];
   data_ptr.SRR_RL_DETECTION_041_044.DET_EXISTENCE_PROB_043 = TOI_DS_Stream_Ptr->existence_prob[42];
   data_ptr.SRR_RL_DETECTION_041_044.DET_EXISTENCE_PROB_044 = TOI_DS_Stream_Ptr->existence_prob[43];

   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_ERR_041 = TOI_DS_Stream_Ptr->std_phi[40];
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_ERR_042 = TOI_DS_Stream_Ptr->std_phi[41];
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_ERR_043 = TOI_DS_Stream_Ptr->std_phi[42];
   data_ptr.SRR_RL_DETECTION_041_044.DET_ELEVATION_ERR_044 = TOI_DS_Stream_Ptr->std_phi[43];

   data_ptr.SRR_RL_DETECTION_041_044.DET_IDM_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_IDM_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_IDM_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_IDM_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_041_044.DET_MTD_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_MTD_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_MTD_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_MTD_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_041_044.DET_PROB_1STAZHYPO_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_PROB_1STAZHYPO_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_PROB_1STAZHYPO_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_PROB_1STAZHYPO_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_ERR_041 = TOI_DS_Stream_Ptr->std_ran[40];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_ERR_042 = TOI_DS_Stream_Ptr->std_ran[41];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_ERR_043 = TOI_DS_Stream_Ptr->std_ran[42];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_ERR_044 = TOI_DS_Stream_Ptr->std_ran[43];

   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_041 = af_target_report_ptr[40].vel;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_042 = af_target_report_ptr[41].vel;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_043 = af_target_report_ptr[42].vel;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_044 = af_target_report_ptr[43].vel;

   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_041 = TOI_DS_Stream_Ptr->std_vel[40];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_042 = TOI_DS_Stream_Ptr->std_vel[41];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_043 = TOI_DS_Stream_Ptr->std_vel[42];
   data_ptr.SRR_RL_DETECTION_041_044.DET_RANGE_VELOCITY_ERR_044 = TOI_DS_Stream_Ptr->std_vel[43];

   data_ptr.SRR_RL_DETECTION_041_044.DET_RCS_041 = af_target_report_ptr[40].rcs;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RCS_042 = af_target_report_ptr[41].rcs;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RCS_043 = af_target_report_ptr[42].rcs;
   data_ptr.SRR_RL_DETECTION_041_044.DET_RCS_044 = af_target_report_ptr[43].rcs;

   data_ptr.SRR_RL_DETECTION_041_044.DET_SNR_041 = af_target_report_ptr[40].snr;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SNR_042 = af_target_report_ptr[41].snr;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SNR_043 = af_target_report_ptr[42].snr;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SNR_044 = af_target_report_ptr[43].snr;

   data_ptr.SRR_RL_DETECTION_041_044.DET_SUPER_RES_TARGET_041 = af_target_report_ptr[40].f_superres_target;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SUPER_RES_TARGET_042 = af_target_report_ptr[41].f_superres_target;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SUPER_RES_TARGET_043 = af_target_report_ptr[42].f_superres_target;
   data_ptr.SRR_RL_DETECTION_041_044.DET_SUPER_RES_TARGET_044 = af_target_report_ptr[43].f_superres_target;

   data_ptr.SRR_RL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_041 = 0;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_042 = 0;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_043 = 0;
   data_ptr.SRR_RL_DETECTION_041_044.DET_BELOW_RAIN_THOLD_044 = 0;

   data_ptr.SRR_RL_DETECTION_041_044.DET_HVC_FLAG_041 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_HVC_FLAG_042 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_HVC_FLAG_043 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_041_044.DET_HVC_FLAG_044 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_041_044.DET_MH_CYCLE_COUNTER_041_044   = 0;
   data_ptr.SRR_RL_DETECTION_041_044.DET_MH_CRC16_041_044           = 0;
   data_ptr.SRR_RL_DETECTION_041_044.DET_MH_SCAN_INDEX_4LSB_041_044 = 0;

   // SRR_RL_DETECTION_045_048_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_045 = af_target_report_ptr[44].ran;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_046 = af_target_report_ptr[45].ran;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_047 = af_target_report_ptr[46].ran;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_048 = af_target_report_ptr[47].ran;

   data_ptr.SRR_RL_DETECTION_045_048.DET_AZIMUTH_045 = af_target_report_ptr[44].theta;
   data_ptr.SRR_RL_DETECTION_045_048.DET_AZIMUTH_046 = af_target_report_ptr[45].theta;
   data_ptr.SRR_RL_DETECTION_045_048.DET_AZIMUTH_047 = af_target_report_ptr[46].theta;
   data_ptr.SRR_RL_DETECTION_045_048.DET_AZIMUTH_048 = af_target_report_ptr[47].theta;

   data_ptr.SRR_RL_DETECTION_045_048.DET_BI_STATIC_FLAG_045 = af_target_report_ptr[44].f_bistatic;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BI_STATIC_FLAG_046 = af_target_report_ptr[45].f_bistatic;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BI_STATIC_FLAG_047 = af_target_report_ptr[46].f_bistatic;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BI_STATIC_FLAG_048 = af_target_report_ptr[47].f_bistatic;

   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_AZIMUTH_045 = af_target_report_ptr[44].az_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_AZIMUTH_046 = af_target_report_ptr[45].az_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_AZIMUTH_047 = af_target_report_ptr[46].az_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_AZIMUTH_048 = af_target_report_ptr[47].az_conf;

   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_045 = af_target_report_ptr[44].phi;
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_046 = af_target_report_ptr[45].phi;
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_047 = af_target_report_ptr[46].phi;
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_048 = af_target_report_ptr[47].phi;

   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_ELEVATION_045 = af_target_report_ptr[44].el_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_ELEVATION_046 = af_target_report_ptr[45].el_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_ELEVATION_047 = af_target_report_ptr[46].el_conf;
   data_ptr.SRR_RL_DETECTION_045_048.DET_CONFD_ELEVATION_048 = af_target_report_ptr[47].el_conf;

   data_ptr.SRR_RL_DETECTION_045_048.DET_EXISTENCE_PROB_045 = TOI_DS_Stream_Ptr->existence_prob[44];
   data_ptr.SRR_RL_DETECTION_045_048.DET_EXISTENCE_PROB_046 = TOI_DS_Stream_Ptr->existence_prob[45];
   data_ptr.SRR_RL_DETECTION_045_048.DET_EXISTENCE_PROB_047 = TOI_DS_Stream_Ptr->existence_prob[46];
   data_ptr.SRR_RL_DETECTION_045_048.DET_EXISTENCE_PROB_048 = TOI_DS_Stream_Ptr->existence_prob[47];

   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_ERR_045 = TOI_DS_Stream_Ptr->std_phi[44];
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_ERR_046 = TOI_DS_Stream_Ptr->std_phi[45];
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_ERR_047 = TOI_DS_Stream_Ptr->std_phi[46];
   data_ptr.SRR_RL_DETECTION_045_048.DET_ELEVATION_ERR_048 = TOI_DS_Stream_Ptr->std_phi[47];

   data_ptr.SRR_RL_DETECTION_045_048.DET_IDM_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_IDM_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_IDM_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_IDM_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_045_048.DET_MTD_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_MTD_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_MTD_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_MTD_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_045_048.DET_PROB_1STAZHYPO_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_PROB_1STAZHYPO_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_PROB_1STAZHYPO_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_PROB_1STAZHYPO_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_ERR_045 = TOI_DS_Stream_Ptr->std_ran[44];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_ERR_046 = TOI_DS_Stream_Ptr->std_ran[45];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_ERR_047 = TOI_DS_Stream_Ptr->std_ran[46];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_ERR_048 = TOI_DS_Stream_Ptr->std_ran[47];

   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_045 = af_target_report_ptr[44].vel;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_046 = af_target_report_ptr[45].vel;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_047 = af_target_report_ptr[46].vel;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_048 = af_target_report_ptr[47].vel;

   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_045 = TOI_DS_Stream_Ptr->std_vel[44];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_046 = TOI_DS_Stream_Ptr->std_vel[45];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_047 = TOI_DS_Stream_Ptr->std_vel[46];
   data_ptr.SRR_RL_DETECTION_045_048.DET_RANGE_VELOCITY_ERR_048 = TOI_DS_Stream_Ptr->std_vel[47];

   data_ptr.SRR_RL_DETECTION_045_048.DET_RCS_045 = af_target_report_ptr[44].rcs;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RCS_046 = af_target_report_ptr[45].rcs;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RCS_047 = af_target_report_ptr[46].rcs;
   data_ptr.SRR_RL_DETECTION_045_048.DET_RCS_048 = af_target_report_ptr[47].rcs;

   data_ptr.SRR_RL_DETECTION_045_048.DET_SNR_045 = af_target_report_ptr[44].snr;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SNR_046 = af_target_report_ptr[45].snr;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SNR_047 = af_target_report_ptr[46].snr;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SNR_048 = af_target_report_ptr[47].snr;

   data_ptr.SRR_RL_DETECTION_045_048.DET_SUPER_RES_TARGET_045 = af_target_report_ptr[44].f_superres_target;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SUPER_RES_TARGET_046 = af_target_report_ptr[45].f_superres_target;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SUPER_RES_TARGET_047 = af_target_report_ptr[46].f_superres_target;
   data_ptr.SRR_RL_DETECTION_045_048.DET_SUPER_RES_TARGET_048 = af_target_report_ptr[47].f_superres_target;

   data_ptr.SRR_RL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_045 = 0;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_046 = 0;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_047 = 0;
   data_ptr.SRR_RL_DETECTION_045_048.DET_BELOW_RAIN_THOLD_048 = 0;

   data_ptr.SRR_RL_DETECTION_045_048.DET_HVC_FLAG_045 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_HVC_FLAG_046 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_HVC_FLAG_047 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_045_048.DET_HVC_FLAG_048 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_045_048.DET_MH_CYCLE_COUNTER_045_048   = 0;
   data_ptr.SRR_RL_DETECTION_045_048.DET_MH_CRC16_045_048           = 0;
   data_ptr.SRR_RL_DETECTION_045_048.DET_MH_SCAN_INDEX_4LSB_045_048 = 0;
   // SRR_RL_DETECTION_049_052_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_049 = af_target_report_ptr[48].ran;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_050 = af_target_report_ptr[49].ran;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_051 = af_target_report_ptr[50].ran;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_052 = af_target_report_ptr[51].ran;

   data_ptr.SRR_RL_DETECTION_049_052.DET_AZIMUTH_049 = af_target_report_ptr[48].theta;
   data_ptr.SRR_RL_DETECTION_049_052.DET_AZIMUTH_050 = af_target_report_ptr[49].theta;
   data_ptr.SRR_RL_DETECTION_049_052.DET_AZIMUTH_051 = af_target_report_ptr[50].theta;
   data_ptr.SRR_RL_DETECTION_049_052.DET_AZIMUTH_052 = af_target_report_ptr[51].theta;

   data_ptr.SRR_RL_DETECTION_049_052.DET_BI_STATIC_FLAG_049 = af_target_report_ptr[48].f_bistatic;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BI_STATIC_FLAG_050 = af_target_report_ptr[49].f_bistatic;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BI_STATIC_FLAG_051 = af_target_report_ptr[50].f_bistatic;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BI_STATIC_FLAG_052 = af_target_report_ptr[51].f_bistatic;

   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_AZIMUTH_049 = af_target_report_ptr[48].az_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_AZIMUTH_050 = af_target_report_ptr[49].az_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_AZIMUTH_051 = af_target_report_ptr[50].az_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_AZIMUTH_052 = af_target_report_ptr[51].az_conf;

   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_049 = af_target_report_ptr[48].phi;
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_050 = af_target_report_ptr[49].phi;
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_051 = af_target_report_ptr[50].phi;
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_052 = af_target_report_ptr[51].phi;

   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_ELEVATION_049 = af_target_report_ptr[48].el_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_ELEVATION_050 = af_target_report_ptr[49].el_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_ELEVATION_051 = af_target_report_ptr[50].el_conf;
   data_ptr.SRR_RL_DETECTION_049_052.DET_CONFD_ELEVATION_052 = af_target_report_ptr[51].el_conf;

   data_ptr.SRR_RL_DETECTION_049_052.DET_EXISTENCE_PROB_049 = TOI_DS_Stream_Ptr->existence_prob[48];
   data_ptr.SRR_RL_DETECTION_049_052.DET_EXISTENCE_PROB_050 = TOI_DS_Stream_Ptr->existence_prob[49];
   data_ptr.SRR_RL_DETECTION_049_052.DET_EXISTENCE_PROB_051 = TOI_DS_Stream_Ptr->existence_prob[50];
   data_ptr.SRR_RL_DETECTION_049_052.DET_EXISTENCE_PROB_052 = TOI_DS_Stream_Ptr->existence_prob[51];

   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_ERR_049 = TOI_DS_Stream_Ptr->std_phi[48];
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_ERR_050 = TOI_DS_Stream_Ptr->std_phi[49];
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_ERR_051 = TOI_DS_Stream_Ptr->std_phi[50];
   data_ptr.SRR_RL_DETECTION_049_052.DET_ELEVATION_ERR_052 = TOI_DS_Stream_Ptr->std_phi[51];

   data_ptr.SRR_RL_DETECTION_049_052.DET_IDM_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_IDM_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_IDM_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_IDM_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_049_052.DET_MTD_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_MTD_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_MTD_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_MTD_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_049_052.DET_PROB_1STAZHYPO_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_PROB_1STAZHYPO_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_PROB_1STAZHYPO_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_PROB_1STAZHYPO_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_ERR_049 = TOI_DS_Stream_Ptr->std_ran[48];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_ERR_050 = TOI_DS_Stream_Ptr->std_ran[49];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_ERR_051 = TOI_DS_Stream_Ptr->std_ran[50];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_ERR_052 = TOI_DS_Stream_Ptr->std_ran[51];

   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_049 = af_target_report_ptr[48].vel;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_050 = af_target_report_ptr[49].vel;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_051 = af_target_report_ptr[50].vel;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_052 = af_target_report_ptr[51].vel;

   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_049 = TOI_DS_Stream_Ptr->std_vel[48];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_050 = TOI_DS_Stream_Ptr->std_vel[49];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_051 = TOI_DS_Stream_Ptr->std_vel[50];
   data_ptr.SRR_RL_DETECTION_049_052.DET_RANGE_VELOCITY_ERR_052 = TOI_DS_Stream_Ptr->std_vel[51];

   data_ptr.SRR_RL_DETECTION_049_052.DET_RCS_049 = af_target_report_ptr[48].rcs;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RCS_050 = af_target_report_ptr[49].rcs;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RCS_051 = af_target_report_ptr[50].rcs;
   data_ptr.SRR_RL_DETECTION_049_052.DET_RCS_052 = af_target_report_ptr[51].rcs;

   data_ptr.SRR_RL_DETECTION_049_052.DET_SNR_049 = af_target_report_ptr[48].snr;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SNR_050 = af_target_report_ptr[49].snr;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SNR_051 = af_target_report_ptr[50].snr;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SNR_052 = af_target_report_ptr[51].snr;

   data_ptr.SRR_RL_DETECTION_049_052.DET_SUPER_RES_TARGET_049 = af_target_report_ptr[48].f_superres_target;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SUPER_RES_TARGET_050 = af_target_report_ptr[49].f_superres_target;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SUPER_RES_TARGET_051 = af_target_report_ptr[50].f_superres_target;
   data_ptr.SRR_RL_DETECTION_049_052.DET_SUPER_RES_TARGET_052 = af_target_report_ptr[51].f_superres_target;

   data_ptr.SRR_RL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_049 = 0;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_050 = 0;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_051 = 0;
   data_ptr.SRR_RL_DETECTION_049_052.DET_BELOW_RAIN_THOLD_052 = 0;

   data_ptr.SRR_RL_DETECTION_049_052.DET_HVC_FLAG_049 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_HVC_FLAG_050 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_HVC_FLAG_051 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_049_052.DET_HVC_FLAG_052 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_049_052.DET_MH_CYCLE_COUNTER_049_052   = 0;
   data_ptr.SRR_RL_DETECTION_049_052.DET_MH_CRC16_049_052           = 0;
   data_ptr.SRR_RL_DETECTION_049_052.DET_MH_SCAN_INDEX_4LSB_049_052 = 0;

   // SRR_RL_DETECTION_053_056_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_053 = af_target_report_ptr[52].ran;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_054 = af_target_report_ptr[53].ran;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_055 = af_target_report_ptr[54].ran;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_056 = af_target_report_ptr[55].ran;

   data_ptr.SRR_RL_DETECTION_053_056.DET_AZIMUTH_053 = af_target_report_ptr[52].theta;
   data_ptr.SRR_RL_DETECTION_053_056.DET_AZIMUTH_054 = af_target_report_ptr[53].theta;
   data_ptr.SRR_RL_DETECTION_053_056.DET_AZIMUTH_055 = af_target_report_ptr[54].theta;
   data_ptr.SRR_RL_DETECTION_053_056.DET_AZIMUTH_056 = af_target_report_ptr[55].theta;

   data_ptr.SRR_RL_DETECTION_053_056.DET_BI_STATIC_FLAG_053 = af_target_report_ptr[52].f_bistatic;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BI_STATIC_FLAG_054 = af_target_report_ptr[53].f_bistatic;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BI_STATIC_FLAG_055 = af_target_report_ptr[54].f_bistatic;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BI_STATIC_FLAG_056 = af_target_report_ptr[55].f_bistatic;

   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_AZIMUTH_053 = af_target_report_ptr[52].az_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_AZIMUTH_054 = af_target_report_ptr[53].az_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_AZIMUTH_055 = af_target_report_ptr[54].az_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_AZIMUTH_056 = af_target_report_ptr[55].az_conf;

   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_053 = af_target_report_ptr[52].phi;
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_054 = af_target_report_ptr[53].phi;
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_055 = af_target_report_ptr[54].phi;
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_056 = af_target_report_ptr[55].phi;

   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_ELEVATION_053 = af_target_report_ptr[52].el_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_ELEVATION_054 = af_target_report_ptr[53].el_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_ELEVATION_055 = af_target_report_ptr[54].el_conf;
   data_ptr.SRR_RL_DETECTION_053_056.DET_CONFD_ELEVATION_056 = af_target_report_ptr[55].el_conf;

   data_ptr.SRR_RL_DETECTION_053_056.DET_EXISTENCE_PROB_053 = TOI_DS_Stream_Ptr->existence_prob[52];
   data_ptr.SRR_RL_DETECTION_053_056.DET_EXISTENCE_PROB_054 = TOI_DS_Stream_Ptr->existence_prob[53];
   data_ptr.SRR_RL_DETECTION_053_056.DET_EXISTENCE_PROB_055 = TOI_DS_Stream_Ptr->existence_prob[54];
   data_ptr.SRR_RL_DETECTION_053_056.DET_EXISTENCE_PROB_056 = TOI_DS_Stream_Ptr->existence_prob[55];

   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_ERR_053 = TOI_DS_Stream_Ptr->std_phi[52];
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_ERR_054 = TOI_DS_Stream_Ptr->std_phi[53];
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_ERR_055 = TOI_DS_Stream_Ptr->std_phi[54];
   data_ptr.SRR_RL_DETECTION_053_056.DET_ELEVATION_ERR_056 = TOI_DS_Stream_Ptr->std_phi[55];

   data_ptr.SRR_RL_DETECTION_053_056.DET_IDM_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_IDM_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_IDM_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_IDM_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_053_056.DET_MTD_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_MTD_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_MTD_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_MTD_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_053_056.DET_PROB_1STAZHYPO_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_PROB_1STAZHYPO_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_PROB_1STAZHYPO_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_PROB_1STAZHYPO_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_ERR_053 = TOI_DS_Stream_Ptr->std_ran[52];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_ERR_054 = TOI_DS_Stream_Ptr->std_ran[53];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_ERR_055 = TOI_DS_Stream_Ptr->std_ran[54];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_ERR_056 = TOI_DS_Stream_Ptr->std_ran[55];

   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_053 = af_target_report_ptr[52].vel;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_054 = af_target_report_ptr[53].vel;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_055 = af_target_report_ptr[54].vel;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_056 = af_target_report_ptr[55].vel;

   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_053 = TOI_DS_Stream_Ptr->std_vel[52];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_054 = TOI_DS_Stream_Ptr->std_vel[53];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_055 = TOI_DS_Stream_Ptr->std_vel[54];
   data_ptr.SRR_RL_DETECTION_053_056.DET_RANGE_VELOCITY_ERR_056 = TOI_DS_Stream_Ptr->std_vel[55];

   data_ptr.SRR_RL_DETECTION_053_056.DET_RCS_053 = af_target_report_ptr[52].rcs;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RCS_054 = af_target_report_ptr[53].rcs;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RCS_055 = af_target_report_ptr[54].rcs;
   data_ptr.SRR_RL_DETECTION_053_056.DET_RCS_056 = af_target_report_ptr[55].rcs;

   data_ptr.SRR_RL_DETECTION_053_056.DET_SNR_053 = af_target_report_ptr[52].snr;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SNR_054 = af_target_report_ptr[53].snr;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SNR_055 = af_target_report_ptr[54].snr;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SNR_056 = af_target_report_ptr[55].snr;

   data_ptr.SRR_RL_DETECTION_053_056.DET_SUPER_RES_TARGET_053 = af_target_report_ptr[52].f_superres_target;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SUPER_RES_TARGET_054 = af_target_report_ptr[53].f_superres_target;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SUPER_RES_TARGET_055 = af_target_report_ptr[54].f_superres_target;
   data_ptr.SRR_RL_DETECTION_053_056.DET_SUPER_RES_TARGET_056 = af_target_report_ptr[55].f_superres_target;

   data_ptr.SRR_RL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_053 = 0;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_054 = 0;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_055 = 0;
   data_ptr.SRR_RL_DETECTION_053_056.DET_BELOW_RAIN_THOLD_056 = 0;

   data_ptr.SRR_RL_DETECTION_053_056.DET_HVC_FLAG_053 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_HVC_FLAG_054 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_HVC_FLAG_055 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_053_056.DET_HVC_FLAG_056 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_053_056.DET_MH_CYCLE_COUNTER_053_056   = 0;
   data_ptr.SRR_RL_DETECTION_053_056.DET_MH_CRC16_053_056           = 0;
   data_ptr.SRR_RL_DETECTION_053_056.DET_MH_SCAN_INDEX_4LSB_053_056 = 0;

   // SRR_RL_DETECTION_057_060_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_057 = af_target_report_ptr[56].ran;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_058 = af_target_report_ptr[57].ran;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_059 = af_target_report_ptr[58].ran;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_060 = af_target_report_ptr[59].ran;

   data_ptr.SRR_RL_DETECTION_057_060.DET_AZIMUTH_057 = af_target_report_ptr[56].theta;
   data_ptr.SRR_RL_DETECTION_057_060.DET_AZIMUTH_058 = af_target_report_ptr[57].theta;
   data_ptr.SRR_RL_DETECTION_057_060.DET_AZIMUTH_059 = af_target_report_ptr[58].theta;
   data_ptr.SRR_RL_DETECTION_057_060.DET_AZIMUTH_060 = af_target_report_ptr[59].theta;

   data_ptr.SRR_RL_DETECTION_057_060.DET_BI_STATIC_FLAG_057 = af_target_report_ptr[56].f_bistatic;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BI_STATIC_FLAG_058 = af_target_report_ptr[57].f_bistatic;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BI_STATIC_FLAG_059 = af_target_report_ptr[58].f_bistatic;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BI_STATIC_FLAG_060 = af_target_report_ptr[59].f_bistatic;

   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_AZIMUTH_057 = af_target_report_ptr[56].az_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_AZIMUTH_058 = af_target_report_ptr[57].az_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_AZIMUTH_059 = af_target_report_ptr[58].az_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_AZIMUTH_060 = af_target_report_ptr[59].az_conf;

   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_057 = af_target_report_ptr[56].phi;
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_058 = af_target_report_ptr[57].phi;
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_059 = af_target_report_ptr[58].phi;
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_060 = af_target_report_ptr[59].phi;

   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_ELEVATION_057 = af_target_report_ptr[56].el_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_ELEVATION_058 = af_target_report_ptr[57].el_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_ELEVATION_059 = af_target_report_ptr[58].el_conf;
   data_ptr.SRR_RL_DETECTION_057_060.DET_CONFD_ELEVATION_060 = af_target_report_ptr[59].el_conf;

   data_ptr.SRR_RL_DETECTION_057_060.DET_EXISTENCE_PROB_057 = TOI_DS_Stream_Ptr->existence_prob[56];
   data_ptr.SRR_RL_DETECTION_057_060.DET_EXISTENCE_PROB_058 = TOI_DS_Stream_Ptr->existence_prob[57];
   data_ptr.SRR_RL_DETECTION_057_060.DET_EXISTENCE_PROB_059 = TOI_DS_Stream_Ptr->existence_prob[58];
   data_ptr.SRR_RL_DETECTION_057_060.DET_EXISTENCE_PROB_060 = TOI_DS_Stream_Ptr->existence_prob[59];

   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_ERR_057 = TOI_DS_Stream_Ptr->std_phi[56];
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_ERR_058 = TOI_DS_Stream_Ptr->std_phi[57];
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_ERR_059 = TOI_DS_Stream_Ptr->std_phi[58];
   data_ptr.SRR_RL_DETECTION_057_060.DET_ELEVATION_ERR_060 = TOI_DS_Stream_Ptr->std_phi[59];

   data_ptr.SRR_RL_DETECTION_057_060.DET_IDM_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_IDM_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_IDM_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_IDM_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_057_060.DET_MTD_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_MTD_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_MTD_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_MTD_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_057_060.DET_PROB_1STAZHYPO_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_PROB_1STAZHYPO_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_PROB_1STAZHYPO_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_PROB_1STAZHYPO_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_ERR_057 = TOI_DS_Stream_Ptr->std_ran[56];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_ERR_058 = TOI_DS_Stream_Ptr->std_ran[57];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_ERR_059 = TOI_DS_Stream_Ptr->std_ran[58];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_ERR_060 = TOI_DS_Stream_Ptr->std_ran[59];

   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_057 = af_target_report_ptr[56].vel;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_058 = af_target_report_ptr[57].vel;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_059 = af_target_report_ptr[58].vel;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_060 = af_target_report_ptr[59].vel;

   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_057 = TOI_DS_Stream_Ptr->std_vel[56];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_058 = TOI_DS_Stream_Ptr->std_vel[57];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_059 = TOI_DS_Stream_Ptr->std_vel[58];
   data_ptr.SRR_RL_DETECTION_057_060.DET_RANGE_VELOCITY_ERR_060 = TOI_DS_Stream_Ptr->std_vel[59];

   data_ptr.SRR_RL_DETECTION_057_060.DET_RCS_057 = af_target_report_ptr[56].rcs;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RCS_058 = af_target_report_ptr[57].rcs;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RCS_059 = af_target_report_ptr[58].rcs;
   data_ptr.SRR_RL_DETECTION_057_060.DET_RCS_060 = af_target_report_ptr[59].rcs;

   data_ptr.SRR_RL_DETECTION_057_060.DET_SNR_057 = af_target_report_ptr[56].snr;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SNR_058 = af_target_report_ptr[57].snr;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SNR_059 = af_target_report_ptr[58].snr;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SNR_060 = af_target_report_ptr[59].snr;

   data_ptr.SRR_RL_DETECTION_057_060.DET_SUPER_RES_TARGET_057 = af_target_report_ptr[56].f_superres_target;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SUPER_RES_TARGET_058 = af_target_report_ptr[57].f_superres_target;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SUPER_RES_TARGET_059 = af_target_report_ptr[58].f_superres_target;
   data_ptr.SRR_RL_DETECTION_057_060.DET_SUPER_RES_TARGET_060 = af_target_report_ptr[59].f_superres_target;

   data_ptr.SRR_RL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_057 = 0;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_058 = 0;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_059 = 0;
   data_ptr.SRR_RL_DETECTION_057_060.DET_BELOW_RAIN_THOLD_060 = 0;

   data_ptr.SRR_RL_DETECTION_057_060.DET_HVC_FLAG_057 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_HVC_FLAG_058 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_HVC_FLAG_059 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_057_060.DET_HVC_FLAG_060 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_057_060.DET_MH_CYCLE_COUNTER_057_060   = 0;
   data_ptr.SRR_RL_DETECTION_057_060.DET_MH_CRC16_057_060           = 0;
   data_ptr.SRR_RL_DETECTION_057_060.DET_MH_SCAN_INDEX_4LSB_057_060 = 0;

   // SRR_RL_DETECTION_061_064_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_061 = af_target_report_ptr[60].ran;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_062 = af_target_report_ptr[61].ran;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_063 = af_target_report_ptr[62].ran;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_064 = af_target_report_ptr[63].ran;

   data_ptr.SRR_RL_DETECTION_061_064.DET_AZIMUTH_061 = af_target_report_ptr[60].theta;
   data_ptr.SRR_RL_DETECTION_061_064.DET_AZIMUTH_062 = af_target_report_ptr[61].theta;
   data_ptr.SRR_RL_DETECTION_061_064.DET_AZIMUTH_063 = af_target_report_ptr[62].theta;
   data_ptr.SRR_RL_DETECTION_061_064.DET_AZIMUTH_064 = af_target_report_ptr[63].theta;

   data_ptr.SRR_RL_DETECTION_061_064.DET_BI_STATIC_FLAG_061 = af_target_report_ptr[60].f_bistatic;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BI_STATIC_FLAG_062 = af_target_report_ptr[61].f_bistatic;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BI_STATIC_FLAG_063 = af_target_report_ptr[62].f_bistatic;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BI_STATIC_FLAG_064 = af_target_report_ptr[63].f_bistatic;

   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_AZIMUTH_061 = af_target_report_ptr[60].az_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_AZIMUTH_062 = af_target_report_ptr[61].az_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_AZIMUTH_063 = af_target_report_ptr[62].az_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_AZIMUTH_064 = af_target_report_ptr[63].az_conf;

   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_061 = af_target_report_ptr[60].phi;
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_062 = af_target_report_ptr[61].phi;
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_063 = af_target_report_ptr[62].phi;
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_064 = af_target_report_ptr[63].phi;

   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_ELEVATION_061 = af_target_report_ptr[60].el_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_ELEVATION_062 = af_target_report_ptr[61].el_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_ELEVATION_063 = af_target_report_ptr[62].el_conf;
   data_ptr.SRR_RL_DETECTION_061_064.DET_CONFD_ELEVATION_064 = af_target_report_ptr[63].el_conf;

   data_ptr.SRR_RL_DETECTION_061_064.DET_EXISTENCE_PROB_061 = TOI_DS_Stream_Ptr->existence_prob[60];
   data_ptr.SRR_RL_DETECTION_061_064.DET_EXISTENCE_PROB_062 = TOI_DS_Stream_Ptr->existence_prob[61];
   data_ptr.SRR_RL_DETECTION_061_064.DET_EXISTENCE_PROB_063 = TOI_DS_Stream_Ptr->existence_prob[62];
   data_ptr.SRR_RL_DETECTION_061_064.DET_EXISTENCE_PROB_064 = TOI_DS_Stream_Ptr->existence_prob[63];

   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_ERR_061 = TOI_DS_Stream_Ptr->std_phi[60];
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_ERR_062 = TOI_DS_Stream_Ptr->std_phi[61];
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_ERR_063 = TOI_DS_Stream_Ptr->std_phi[62];
   data_ptr.SRR_RL_DETECTION_061_064.DET_ELEVATION_ERR_064 = TOI_DS_Stream_Ptr->std_phi[63];

   data_ptr.SRR_RL_DETECTION_061_064.DET_IDM_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_IDM_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_IDM_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_IDM_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_061_064.DET_MTD_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_MTD_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_MTD_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_MTD_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_061_064.DET_PROB_1STAZHYPO_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_PROB_1STAZHYPO_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_PROB_1STAZHYPO_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_PROB_1STAZHYPO_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_ERR_061 = TOI_DS_Stream_Ptr->std_ran[60];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_ERR_062 = TOI_DS_Stream_Ptr->std_ran[61];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_ERR_063 = TOI_DS_Stream_Ptr->std_ran[62];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_ERR_064 = TOI_DS_Stream_Ptr->std_ran[63];

   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_061 = af_target_report_ptr[60].vel;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_062 = af_target_report_ptr[61].vel;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_063 = af_target_report_ptr[62].vel;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_064 = af_target_report_ptr[63].vel;

   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_061 = TOI_DS_Stream_Ptr->std_vel[60];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_062 = TOI_DS_Stream_Ptr->std_vel[61];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_063 = TOI_DS_Stream_Ptr->std_vel[62];
   data_ptr.SRR_RL_DETECTION_061_064.DET_RANGE_VELOCITY_ERR_064 = TOI_DS_Stream_Ptr->std_vel[63];

   data_ptr.SRR_RL_DETECTION_061_064.DET_RCS_061 = af_target_report_ptr[60].rcs;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RCS_062 = af_target_report_ptr[61].rcs;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RCS_063 = af_target_report_ptr[62].rcs;
   data_ptr.SRR_RL_DETECTION_061_064.DET_RCS_064 = af_target_report_ptr[63].rcs;

   data_ptr.SRR_RL_DETECTION_061_064.DET_SNR_061 = af_target_report_ptr[60].snr;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SNR_062 = af_target_report_ptr[61].snr;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SNR_063 = af_target_report_ptr[62].snr;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SNR_064 = af_target_report_ptr[63].snr;

   data_ptr.SRR_RL_DETECTION_061_064.DET_SUPER_RES_TARGET_061 = af_target_report_ptr[60].f_superres_target;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SUPER_RES_TARGET_062 = af_target_report_ptr[61].f_superres_target;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SUPER_RES_TARGET_063 = af_target_report_ptr[62].f_superres_target;
   data_ptr.SRR_RL_DETECTION_061_064.DET_SUPER_RES_TARGET_064 = af_target_report_ptr[63].f_superres_target;

   data_ptr.SRR_RL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_061 = 0;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_062 = 0;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_063 = 0;
   data_ptr.SRR_RL_DETECTION_061_064.DET_BELOW_RAIN_THOLD_064 = 0;

   data_ptr.SRR_RL_DETECTION_061_064.DET_HVC_FLAG_061 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_HVC_FLAG_062 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_HVC_FLAG_063 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_061_064.DET_HVC_FLAG_064 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_061_064.DET_MH_CYCLE_COUNTER_061_064   = 0;
   data_ptr.SRR_RL_DETECTION_061_064.DET_MH_CRC16_061_064           = 0;
   data_ptr.SRR_RL_DETECTION_061_064.DET_MH_SCAN_INDEX_4LSB_061_064 = 0;

   // SRR_RL_DETECTION_065_068_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_065 = af_target_report_ptr[64].ran;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_066 = af_target_report_ptr[65].ran;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_067 = af_target_report_ptr[66].ran;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_068 = af_target_report_ptr[67].ran;

   data_ptr.SRR_RL_DETECTION_065_068.DET_AZIMUTH_065 = af_target_report_ptr[64].theta;
   data_ptr.SRR_RL_DETECTION_065_068.DET_AZIMUTH_066 = af_target_report_ptr[65].theta;
   data_ptr.SRR_RL_DETECTION_065_068.DET_AZIMUTH_067 = af_target_report_ptr[66].theta;
   data_ptr.SRR_RL_DETECTION_065_068.DET_AZIMUTH_068 = af_target_report_ptr[67].theta;

   data_ptr.SRR_RL_DETECTION_065_068.DET_BI_STATIC_FLAG_065 = af_target_report_ptr[64].f_bistatic;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BI_STATIC_FLAG_066 = af_target_report_ptr[65].f_bistatic;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BI_STATIC_FLAG_067 = af_target_report_ptr[66].f_bistatic;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BI_STATIC_FLAG_068 = af_target_report_ptr[67].f_bistatic;

   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_AZIMUTH_065 = af_target_report_ptr[64].az_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_AZIMUTH_066 = af_target_report_ptr[65].az_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_AZIMUTH_067 = af_target_report_ptr[66].az_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_AZIMUTH_068 = af_target_report_ptr[67].az_conf;

   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_065 = af_target_report_ptr[64].phi;
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_066 = af_target_report_ptr[65].phi;
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_067 = af_target_report_ptr[66].phi;
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_068 = af_target_report_ptr[67].phi;

   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_ELEVATION_065 = af_target_report_ptr[64].el_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_ELEVATION_066 = af_target_report_ptr[65].el_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_ELEVATION_067 = af_target_report_ptr[66].el_conf;
   data_ptr.SRR_RL_DETECTION_065_068.DET_CONFD_ELEVATION_068 = af_target_report_ptr[67].el_conf;

   data_ptr.SRR_RL_DETECTION_065_068.DET_EXISTENCE_PROB_065 = TOI_DS_Stream_Ptr->existence_prob[64];
   data_ptr.SRR_RL_DETECTION_065_068.DET_EXISTENCE_PROB_066 = TOI_DS_Stream_Ptr->existence_prob[65];
   data_ptr.SRR_RL_DETECTION_065_068.DET_EXISTENCE_PROB_067 = TOI_DS_Stream_Ptr->existence_prob[66];
   data_ptr.SRR_RL_DETECTION_065_068.DET_EXISTENCE_PROB_068 = TOI_DS_Stream_Ptr->existence_prob[67];

   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_ERR_065 = TOI_DS_Stream_Ptr->std_phi[64];
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_ERR_066 = TOI_DS_Stream_Ptr->std_phi[65];
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_ERR_067 = TOI_DS_Stream_Ptr->std_phi[66];
   data_ptr.SRR_RL_DETECTION_065_068.DET_ELEVATION_ERR_068 = TOI_DS_Stream_Ptr->std_phi[67];

   data_ptr.SRR_RL_DETECTION_065_068.DET_IDM_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_IDM_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_IDM_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_IDM_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_065_068.DET_MTD_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_MTD_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_MTD_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_MTD_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_065_068.DET_PROB_1STAZHYPO_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_PROB_1STAZHYPO_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_PROB_1STAZHYPO_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_PROB_1STAZHYPO_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_ERR_065 = TOI_DS_Stream_Ptr->std_ran[64];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_ERR_066 = TOI_DS_Stream_Ptr->std_ran[65];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_ERR_067 = TOI_DS_Stream_Ptr->std_ran[66];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_ERR_068 = TOI_DS_Stream_Ptr->std_ran[67];

   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_065 = af_target_report_ptr[64].vel;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_066 = af_target_report_ptr[65].vel;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_067 = af_target_report_ptr[66].vel;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_068 = af_target_report_ptr[67].vel;

   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_065 = TOI_DS_Stream_Ptr->std_vel[64];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_066 = TOI_DS_Stream_Ptr->std_vel[65];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_067 = TOI_DS_Stream_Ptr->std_vel[66];
   data_ptr.SRR_RL_DETECTION_065_068.DET_RANGE_VELOCITY_ERR_068 = TOI_DS_Stream_Ptr->std_vel[67];

   data_ptr.SRR_RL_DETECTION_065_068.DET_RCS_065 = af_target_report_ptr[64].rcs;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RCS_066 = af_target_report_ptr[65].rcs;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RCS_067 = af_target_report_ptr[66].rcs;
   data_ptr.SRR_RL_DETECTION_065_068.DET_RCS_068 = af_target_report_ptr[67].rcs;

   data_ptr.SRR_RL_DETECTION_065_068.DET_SNR_065 = af_target_report_ptr[64].snr;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SNR_066 = af_target_report_ptr[65].snr;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SNR_067 = af_target_report_ptr[66].snr;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SNR_068 = af_target_report_ptr[67].snr;

   data_ptr.SRR_RL_DETECTION_065_068.DET_SUPER_RES_TARGET_065 = af_target_report_ptr[64].f_superres_target;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SUPER_RES_TARGET_066 = af_target_report_ptr[65].f_superres_target;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SUPER_RES_TARGET_067 = af_target_report_ptr[66].f_superres_target;
   data_ptr.SRR_RL_DETECTION_065_068.DET_SUPER_RES_TARGET_068 = af_target_report_ptr[67].f_superres_target;

   data_ptr.SRR_RL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_065 = 0;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_066 = 0;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_067 = 0;
   data_ptr.SRR_RL_DETECTION_065_068.DET_BELOW_RAIN_THOLD_068 = 0;

   data_ptr.SRR_RL_DETECTION_065_068.DET_HVC_FLAG_065 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_HVC_FLAG_066 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_HVC_FLAG_067 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_065_068.DET_HVC_FLAG_068 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_065_068.DET_MH_CYCLE_COUNTER_065_068   = 0;
   data_ptr.SRR_RL_DETECTION_065_068.DET_MH_CRC16_065_068           = 0;
   data_ptr.SRR_RL_DETECTION_065_068.DET_MH_SCAN_INDEX_4LSB_065_068 = 0;

   // SRR_RL_DETECTION_069_072_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_069 = af_target_report_ptr[68].ran;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_070 = af_target_report_ptr[69].ran;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_071 = af_target_report_ptr[70].ran;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_072 = af_target_report_ptr[71].ran;

   data_ptr.SRR_RL_DETECTION_069_072.DET_AZIMUTH_069 = af_target_report_ptr[68].theta;
   data_ptr.SRR_RL_DETECTION_069_072.DET_AZIMUTH_070 = af_target_report_ptr[69].theta;
   data_ptr.SRR_RL_DETECTION_069_072.DET_AZIMUTH_071 = af_target_report_ptr[70].theta;
   data_ptr.SRR_RL_DETECTION_069_072.DET_AZIMUTH_072 = af_target_report_ptr[71].theta;

   data_ptr.SRR_RL_DETECTION_069_072.DET_BI_STATIC_FLAG_069 = af_target_report_ptr[68].f_bistatic;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BI_STATIC_FLAG_070 = af_target_report_ptr[69].f_bistatic;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BI_STATIC_FLAG_071 = af_target_report_ptr[70].f_bistatic;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BI_STATIC_FLAG_072 = af_target_report_ptr[71].f_bistatic;

   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_AZIMUTH_069 = af_target_report_ptr[68].az_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_AZIMUTH_070 = af_target_report_ptr[69].az_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_AZIMUTH_071 = af_target_report_ptr[70].az_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_AZIMUTH_072 = af_target_report_ptr[71].az_conf;

   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_069 = af_target_report_ptr[68].phi;
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_070 = af_target_report_ptr[69].phi;
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_071 = af_target_report_ptr[70].phi;
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_072 = af_target_report_ptr[71].phi;

   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_ELEVATION_069 = af_target_report_ptr[68].el_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_ELEVATION_070 = af_target_report_ptr[69].el_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_ELEVATION_071 = af_target_report_ptr[70].el_conf;
   data_ptr.SRR_RL_DETECTION_069_072.DET_CONFD_ELEVATION_072 = af_target_report_ptr[71].el_conf;

   data_ptr.SRR_RL_DETECTION_069_072.DET_EXISTENCE_PROB_069 = TOI_DS_Stream_Ptr->existence_prob[68];
   data_ptr.SRR_RL_DETECTION_069_072.DET_EXISTENCE_PROB_070 = TOI_DS_Stream_Ptr->existence_prob[69];
   data_ptr.SRR_RL_DETECTION_069_072.DET_EXISTENCE_PROB_071 = TOI_DS_Stream_Ptr->existence_prob[70];
   data_ptr.SRR_RL_DETECTION_069_072.DET_EXISTENCE_PROB_072 = TOI_DS_Stream_Ptr->existence_prob[71];

   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_ERR_069 = TOI_DS_Stream_Ptr->std_phi[68];
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_ERR_070 = TOI_DS_Stream_Ptr->std_phi[69];
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_ERR_071 = TOI_DS_Stream_Ptr->std_phi[70];
   data_ptr.SRR_RL_DETECTION_069_072.DET_ELEVATION_ERR_072 = TOI_DS_Stream_Ptr->std_phi[71];

   data_ptr.SRR_RL_DETECTION_069_072.DET_IDM_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_IDM_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_IDM_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_IDM_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_069_072.DET_MTD_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_MTD_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_MTD_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_MTD_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_069_072.DET_PROB_1STAZHYPO_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_PROB_1STAZHYPO_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_PROB_1STAZHYPO_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_PROB_1STAZHYPO_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_ERR_069 = TOI_DS_Stream_Ptr->std_ran[68];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_ERR_070 = TOI_DS_Stream_Ptr->std_ran[69];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_ERR_071 = TOI_DS_Stream_Ptr->std_ran[70];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_ERR_072 = TOI_DS_Stream_Ptr->std_ran[71];

   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_069 = af_target_report_ptr[68].vel;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_070 = af_target_report_ptr[69].vel;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_071 = af_target_report_ptr[70].vel;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_072 = af_target_report_ptr[71].vel;

   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_069 = TOI_DS_Stream_Ptr->std_vel[68];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_070 = TOI_DS_Stream_Ptr->std_vel[69];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_071 = TOI_DS_Stream_Ptr->std_vel[70];
   data_ptr.SRR_RL_DETECTION_069_072.DET_RANGE_VELOCITY_ERR_072 = TOI_DS_Stream_Ptr->std_vel[71];

   data_ptr.SRR_RL_DETECTION_069_072.DET_RCS_069 = af_target_report_ptr[68].rcs;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RCS_070 = af_target_report_ptr[69].rcs;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RCS_071 = af_target_report_ptr[70].rcs;
   data_ptr.SRR_RL_DETECTION_069_072.DET_RCS_072 = af_target_report_ptr[71].rcs;

   data_ptr.SRR_RL_DETECTION_069_072.DET_SNR_069 = af_target_report_ptr[68].snr;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SNR_070 = af_target_report_ptr[69].snr;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SNR_071 = af_target_report_ptr[70].snr;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SNR_072 = af_target_report_ptr[71].snr;

   data_ptr.SRR_RL_DETECTION_069_072.DET_SUPER_RES_TARGET_069 = af_target_report_ptr[68].f_superres_target;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SUPER_RES_TARGET_070 = af_target_report_ptr[69].f_superres_target;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SUPER_RES_TARGET_071 = af_target_report_ptr[70].f_superres_target;
   data_ptr.SRR_RL_DETECTION_069_072.DET_SUPER_RES_TARGET_072 = af_target_report_ptr[71].f_superres_target;

   data_ptr.SRR_RL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_069 = 0;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_070 = 0;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_071 = 0;
   data_ptr.SRR_RL_DETECTION_069_072.DET_BELOW_RAIN_THOLD_072 = 0;

   data_ptr.SRR_RL_DETECTION_069_072.DET_HVC_FLAG_069 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_HVC_FLAG_070 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_HVC_FLAG_071 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_069_072.DET_HVC_FLAG_072 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_069_072.DET_MH_CYCLE_COUNTER_069_072   = 0;
   data_ptr.SRR_RL_DETECTION_069_072.DET_MH_CRC16_069_072           = 0;
   data_ptr.SRR_RL_DETECTION_069_072.DET_MH_SCAN_INDEX_4LSB_069_072 = 0;

   // SRR_RL_DETECTION_073_076_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_073 = af_target_report_ptr[72].ran;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_074 = af_target_report_ptr[73].ran;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_075 = af_target_report_ptr[74].ran;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_076 = af_target_report_ptr[75].ran;

   data_ptr.SRR_RL_DETECTION_073_076.DET_AZIMUTH_073 = af_target_report_ptr[72].theta;
   data_ptr.SRR_RL_DETECTION_073_076.DET_AZIMUTH_074 = af_target_report_ptr[73].theta;
   data_ptr.SRR_RL_DETECTION_073_076.DET_AZIMUTH_075 = af_target_report_ptr[74].theta;
   data_ptr.SRR_RL_DETECTION_073_076.DET_AZIMUTH_076 = af_target_report_ptr[75].theta;

   data_ptr.SRR_RL_DETECTION_073_076.DET_BI_STATIC_FLAG_073 = af_target_report_ptr[72].f_bistatic;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BI_STATIC_FLAG_074 = af_target_report_ptr[73].f_bistatic;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BI_STATIC_FLAG_075 = af_target_report_ptr[74].f_bistatic;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BI_STATIC_FLAG_076 = af_target_report_ptr[75].f_bistatic;

   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_AZIMUTH_073 = af_target_report_ptr[72].az_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_AZIMUTH_074 = af_target_report_ptr[73].az_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_AZIMUTH_075 = af_target_report_ptr[74].az_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_AZIMUTH_076 = af_target_report_ptr[75].az_conf;

   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_073 = af_target_report_ptr[72].phi;
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_074 = af_target_report_ptr[73].phi;
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_075 = af_target_report_ptr[74].phi;
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_076 = af_target_report_ptr[75].phi;

   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_ELEVATION_073 = af_target_report_ptr[72].el_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_ELEVATION_074 = af_target_report_ptr[73].el_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_ELEVATION_075 = af_target_report_ptr[74].el_conf;
   data_ptr.SRR_RL_DETECTION_073_076.DET_CONFD_ELEVATION_076 = af_target_report_ptr[75].el_conf;

   data_ptr.SRR_RL_DETECTION_073_076.DET_EXISTENCE_PROB_073 = TOI_DS_Stream_Ptr->existence_prob[72];
   data_ptr.SRR_RL_DETECTION_073_076.DET_EXISTENCE_PROB_074 = TOI_DS_Stream_Ptr->existence_prob[73];
   data_ptr.SRR_RL_DETECTION_073_076.DET_EXISTENCE_PROB_075 = TOI_DS_Stream_Ptr->existence_prob[74];
   data_ptr.SRR_RL_DETECTION_073_076.DET_EXISTENCE_PROB_076 = TOI_DS_Stream_Ptr->existence_prob[75];

   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_ERR_073 = TOI_DS_Stream_Ptr->std_phi[72];
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_ERR_074 = TOI_DS_Stream_Ptr->std_phi[73];
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_ERR_075 = TOI_DS_Stream_Ptr->std_phi[74];
   data_ptr.SRR_RL_DETECTION_073_076.DET_ELEVATION_ERR_076 = TOI_DS_Stream_Ptr->std_phi[75];

   data_ptr.SRR_RL_DETECTION_073_076.DET_IDM_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_IDM_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_IDM_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_IDM_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_073_076.DET_MTD_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_MTD_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_MTD_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_MTD_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_073_076.DET_PROB_1STAZHYPO_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_PROB_1STAZHYPO_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_PROB_1STAZHYPO_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_PROB_1STAZHYPO_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_ERR_073 = TOI_DS_Stream_Ptr->std_ran[72];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_ERR_074 = TOI_DS_Stream_Ptr->std_ran[73];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_ERR_075 = TOI_DS_Stream_Ptr->std_ran[74];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_ERR_076 = TOI_DS_Stream_Ptr->std_ran[75];

   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_073 = af_target_report_ptr[72].vel;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_074 = af_target_report_ptr[73].vel;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_075 = af_target_report_ptr[74].vel;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_076 = af_target_report_ptr[75].vel;

   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_073 = TOI_DS_Stream_Ptr->std_vel[72];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_074 = TOI_DS_Stream_Ptr->std_vel[73];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_075 = TOI_DS_Stream_Ptr->std_vel[74];
   data_ptr.SRR_RL_DETECTION_073_076.DET_RANGE_VELOCITY_ERR_076 = TOI_DS_Stream_Ptr->std_vel[75];

   data_ptr.SRR_RL_DETECTION_073_076.DET_RCS_073 = af_target_report_ptr[72].rcs;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RCS_074 = af_target_report_ptr[73].rcs;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RCS_075 = af_target_report_ptr[74].rcs;
   data_ptr.SRR_RL_DETECTION_073_076.DET_RCS_076 = af_target_report_ptr[75].rcs;

   data_ptr.SRR_RL_DETECTION_073_076.DET_SNR_073 = af_target_report_ptr[72].snr;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SNR_074 = af_target_report_ptr[73].snr;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SNR_075 = af_target_report_ptr[74].snr;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SNR_076 = af_target_report_ptr[75].snr;

   data_ptr.SRR_RL_DETECTION_073_076.DET_SUPER_RES_TARGET_073 = af_target_report_ptr[72].f_superres_target;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SUPER_RES_TARGET_074 = af_target_report_ptr[73].f_superres_target;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SUPER_RES_TARGET_075 = af_target_report_ptr[74].f_superres_target;
   data_ptr.SRR_RL_DETECTION_073_076.DET_SUPER_RES_TARGET_076 = af_target_report_ptr[75].f_superres_target;

   data_ptr.SRR_RL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_073 = 0;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_074 = 0;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_075 = 0;
   data_ptr.SRR_RL_DETECTION_073_076.DET_BELOW_RAIN_THOLD_076 = 0;

   data_ptr.SRR_RL_DETECTION_073_076.DET_HVC_FLAG_073 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_HVC_FLAG_074 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_HVC_FLAG_075 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_073_076.DET_HVC_FLAG_076 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_073_076.DET_MH_CYCLE_COUNTER_073_076   = 0;
   data_ptr.SRR_RL_DETECTION_073_076.DET_MH_CRC16_073_076           = 0;
   data_ptr.SRR_RL_DETECTION_073_076.DET_MH_SCAN_INDEX_4LSB_073_076 = 0;

   // SRR_RL_DETECTION_077_080_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_077 = af_target_report_ptr[76].ran;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_078 = af_target_report_ptr[77].ran;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_079 = af_target_report_ptr[78].ran;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_080 = af_target_report_ptr[79].ran;

   data_ptr.SRR_RL_DETECTION_077_080.DET_AZIMUTH_077 = af_target_report_ptr[76].theta;
   data_ptr.SRR_RL_DETECTION_077_080.DET_AZIMUTH_078 = af_target_report_ptr[77].theta;
   data_ptr.SRR_RL_DETECTION_077_080.DET_AZIMUTH_079 = af_target_report_ptr[78].theta;
   data_ptr.SRR_RL_DETECTION_077_080.DET_AZIMUTH_080 = af_target_report_ptr[79].theta;

   data_ptr.SRR_RL_DETECTION_077_080.DET_BI_STATIC_FLAG_077 = af_target_report_ptr[76].f_bistatic;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BI_STATIC_FLAG_078 = af_target_report_ptr[77].f_bistatic;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BI_STATIC_FLAG_079 = af_target_report_ptr[78].f_bistatic;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BI_STATIC_FLAG_080 = af_target_report_ptr[79].f_bistatic;

   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_AZIMUTH_077 = af_target_report_ptr[76].az_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_AZIMUTH_078 = af_target_report_ptr[77].az_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_AZIMUTH_079 = af_target_report_ptr[78].az_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_AZIMUTH_080 = af_target_report_ptr[79].az_conf;

   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_077 = af_target_report_ptr[76].phi;
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_078 = af_target_report_ptr[77].phi;
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_079 = af_target_report_ptr[78].phi;
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_080 = af_target_report_ptr[79].phi;

   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_ELEVATION_077 = af_target_report_ptr[76].el_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_ELEVATION_078 = af_target_report_ptr[77].el_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_ELEVATION_079 = af_target_report_ptr[78].el_conf;
   data_ptr.SRR_RL_DETECTION_077_080.DET_CONFD_ELEVATION_080 = af_target_report_ptr[79].el_conf;

   data_ptr.SRR_RL_DETECTION_077_080.DET_EXISTENCE_PROB_077 = TOI_DS_Stream_Ptr->existence_prob[76];
   data_ptr.SRR_RL_DETECTION_077_080.DET_EXISTENCE_PROB_078 = TOI_DS_Stream_Ptr->existence_prob[77];
   data_ptr.SRR_RL_DETECTION_077_080.DET_EXISTENCE_PROB_079 = TOI_DS_Stream_Ptr->existence_prob[78];
   data_ptr.SRR_RL_DETECTION_077_080.DET_EXISTENCE_PROB_080 = TOI_DS_Stream_Ptr->existence_prob[79];

   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_ERR_077 = TOI_DS_Stream_Ptr->std_phi[76];
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_ERR_078 = TOI_DS_Stream_Ptr->std_phi[77];
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_ERR_079 = TOI_DS_Stream_Ptr->std_phi[78];
   data_ptr.SRR_RL_DETECTION_077_080.DET_ELEVATION_ERR_080 = TOI_DS_Stream_Ptr->std_phi[79];

   data_ptr.SRR_RL_DETECTION_077_080.DET_IDM_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_IDM_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_IDM_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_IDM_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_077_080.DET_MTD_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_MTD_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_MTD_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_MTD_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_077_080.DET_PROB_1STAZHYPO_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_PROB_1STAZHYPO_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_PROB_1STAZHYPO_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_PROB_1STAZHYPO_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_ERR_077 = TOI_DS_Stream_Ptr->std_ran[76];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_ERR_078 = TOI_DS_Stream_Ptr->std_ran[77];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_ERR_079 = TOI_DS_Stream_Ptr->std_ran[78];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_ERR_080 = TOI_DS_Stream_Ptr->std_ran[79];

   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_077 = af_target_report_ptr[76].vel;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_078 = af_target_report_ptr[77].vel;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_079 = af_target_report_ptr[78].vel;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_080 = af_target_report_ptr[79].vel;

   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_077 = TOI_DS_Stream_Ptr->std_vel[76];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_078 = TOI_DS_Stream_Ptr->std_vel[77];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_079 = TOI_DS_Stream_Ptr->std_vel[78];
   data_ptr.SRR_RL_DETECTION_077_080.DET_RANGE_VELOCITY_ERR_080 = TOI_DS_Stream_Ptr->std_vel[79];

   data_ptr.SRR_RL_DETECTION_077_080.DET_RCS_077 = af_target_report_ptr[76].rcs;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RCS_078 = af_target_report_ptr[77].rcs;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RCS_079 = af_target_report_ptr[78].rcs;
   data_ptr.SRR_RL_DETECTION_077_080.DET_RCS_080 = af_target_report_ptr[79].rcs;

   data_ptr.SRR_RL_DETECTION_077_080.DET_SNR_077 = af_target_report_ptr[76].snr;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SNR_078 = af_target_report_ptr[77].snr;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SNR_079 = af_target_report_ptr[78].snr;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SNR_080 = af_target_report_ptr[79].snr;

   data_ptr.SRR_RL_DETECTION_077_080.DET_SUPER_RES_TARGET_077 = af_target_report_ptr[76].f_superres_target;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SUPER_RES_TARGET_078 = af_target_report_ptr[77].f_superres_target;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SUPER_RES_TARGET_079 = af_target_report_ptr[78].f_superres_target;
   data_ptr.SRR_RL_DETECTION_077_080.DET_SUPER_RES_TARGET_080 = af_target_report_ptr[79].f_superres_target;

   data_ptr.SRR_RL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_077 = 0;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_078 = 0;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_079 = 0;
   data_ptr.SRR_RL_DETECTION_077_080.DET_BELOW_RAIN_THOLD_080 = 0;

   data_ptr.SRR_RL_DETECTION_077_080.DET_HVC_FLAG_077 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_HVC_FLAG_078 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_HVC_FLAG_079 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_077_080.DET_HVC_FLAG_080 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_077_080.DET_MH_CYCLE_COUNTER_077_080   = 0;
   data_ptr.SRR_RL_DETECTION_077_080.DET_MH_CRC16_077_080           = 0;
   data_ptr.SRR_RL_DETECTION_077_080.DET_MH_SCAN_INDEX_4LSB_077_080 = 0;

   // SRR_RL_DETECTION_081_084_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_081 = af_target_report_ptr[80].ran;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_082 = af_target_report_ptr[81].ran;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_083 = af_target_report_ptr[82].ran;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_084 = af_target_report_ptr[83].ran;

   data_ptr.SRR_RL_DETECTION_081_084.DET_AZIMUTH_081 = af_target_report_ptr[80].theta;
   data_ptr.SRR_RL_DETECTION_081_084.DET_AZIMUTH_082 = af_target_report_ptr[81].theta;
   data_ptr.SRR_RL_DETECTION_081_084.DET_AZIMUTH_083 = af_target_report_ptr[82].theta;
   data_ptr.SRR_RL_DETECTION_081_084.DET_AZIMUTH_084 = af_target_report_ptr[83].theta;

   data_ptr.SRR_RL_DETECTION_081_084.DET_BI_STATIC_FLAG_081 = af_target_report_ptr[80].f_bistatic;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BI_STATIC_FLAG_082 = af_target_report_ptr[81].f_bistatic;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BI_STATIC_FLAG_083 = af_target_report_ptr[82].f_bistatic;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BI_STATIC_FLAG_084 = af_target_report_ptr[83].f_bistatic;

   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_AZIMUTH_081 = af_target_report_ptr[80].az_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_AZIMUTH_082 = af_target_report_ptr[81].az_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_AZIMUTH_083 = af_target_report_ptr[82].az_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_AZIMUTH_084 = af_target_report_ptr[83].az_conf;

   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_081 = af_target_report_ptr[80].phi;
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_082 = af_target_report_ptr[81].phi;
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_083 = af_target_report_ptr[82].phi;
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_084 = af_target_report_ptr[83].phi;

   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_ELEVATION_081 = af_target_report_ptr[80].el_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_ELEVATION_082 = af_target_report_ptr[81].el_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_ELEVATION_083 = af_target_report_ptr[82].el_conf;
   data_ptr.SRR_RL_DETECTION_081_084.DET_CONFD_ELEVATION_084 = af_target_report_ptr[83].el_conf;

   data_ptr.SRR_RL_DETECTION_081_084.DET_EXISTENCE_PROB_081 = TOI_DS_Stream_Ptr->existence_prob[80];
   data_ptr.SRR_RL_DETECTION_081_084.DET_EXISTENCE_PROB_082 = TOI_DS_Stream_Ptr->existence_prob[81];
   data_ptr.SRR_RL_DETECTION_081_084.DET_EXISTENCE_PROB_083 = TOI_DS_Stream_Ptr->existence_prob[82];
   data_ptr.SRR_RL_DETECTION_081_084.DET_EXISTENCE_PROB_084 = TOI_DS_Stream_Ptr->existence_prob[83];

   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_ERR_081 = TOI_DS_Stream_Ptr->std_phi[80];
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_ERR_082 = TOI_DS_Stream_Ptr->std_phi[81];
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_ERR_083 = TOI_DS_Stream_Ptr->std_phi[82];
   data_ptr.SRR_RL_DETECTION_081_084.DET_ELEVATION_ERR_084 = TOI_DS_Stream_Ptr->std_phi[83];

   data_ptr.SRR_RL_DETECTION_081_084.DET_IDM_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_IDM_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_IDM_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_IDM_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_081_084.DET_MTD_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_MTD_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_MTD_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_MTD_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_081_084.DET_PROB_1STAZHYPO_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_PROB_1STAZHYPO_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_PROB_1STAZHYPO_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_PROB_1STAZHYPO_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_ERR_081 = TOI_DS_Stream_Ptr->std_ran[80];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_ERR_082 = TOI_DS_Stream_Ptr->std_ran[81];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_ERR_083 = TOI_DS_Stream_Ptr->std_ran[82];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_ERR_084 = TOI_DS_Stream_Ptr->std_ran[83];

   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_081 = af_target_report_ptr[80].vel;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_082 = af_target_report_ptr[81].vel;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_083 = af_target_report_ptr[82].vel;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_084 = af_target_report_ptr[83].vel;

   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_081 = TOI_DS_Stream_Ptr->std_vel[80];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_082 = TOI_DS_Stream_Ptr->std_vel[81];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_083 = TOI_DS_Stream_Ptr->std_vel[82];
   data_ptr.SRR_RL_DETECTION_081_084.DET_RANGE_VELOCITY_ERR_084 = TOI_DS_Stream_Ptr->std_vel[83];

   data_ptr.SRR_RL_DETECTION_081_084.DET_RCS_081 = af_target_report_ptr[80].rcs;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RCS_082 = af_target_report_ptr[81].rcs;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RCS_083 = af_target_report_ptr[82].rcs;
   data_ptr.SRR_RL_DETECTION_081_084.DET_RCS_084 = af_target_report_ptr[83].rcs;

   data_ptr.SRR_RL_DETECTION_081_084.DET_SNR_081 = af_target_report_ptr[80].snr;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SNR_082 = af_target_report_ptr[81].snr;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SNR_083 = af_target_report_ptr[82].snr;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SNR_084 = af_target_report_ptr[83].snr;

   data_ptr.SRR_RL_DETECTION_081_084.DET_SUPER_RES_TARGET_081 = af_target_report_ptr[80].f_superres_target;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SUPER_RES_TARGET_082 = af_target_report_ptr[81].f_superres_target;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SUPER_RES_TARGET_083 = af_target_report_ptr[82].f_superres_target;
   data_ptr.SRR_RL_DETECTION_081_084.DET_SUPER_RES_TARGET_084 = af_target_report_ptr[83].f_superres_target;

   data_ptr.SRR_RL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_081 = 0;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_082 = 0;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_083 = 0;
   data_ptr.SRR_RL_DETECTION_081_084.DET_BELOW_RAIN_THOLD_084 = 0;

   data_ptr.SRR_RL_DETECTION_081_084.DET_HVC_FLAG_081 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_HVC_FLAG_082 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_HVC_FLAG_083 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_081_084.DET_HVC_FLAG_084 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_081_084.DET_MH_CYCLE_COUNTER_081_084   = 0;
   data_ptr.SRR_RL_DETECTION_081_084.DET_MH_CRC16_081_084           = 0;
   data_ptr.SRR_RL_DETECTION_081_084.DET_MH_SCAN_INDEX_4LSB_081_084 = 0;

   // SRR_RL_DETECTION_085_088_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // SRR_RL_DETECTION_089_092_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_085 = af_target_report_ptr[84].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_086 = af_target_report_ptr[85].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_087 = af_target_report_ptr[86].ran;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_088 = af_target_report_ptr[87].ran;

   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_085 = af_target_report_ptr[84].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_086 = af_target_report_ptr[85].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_087 = af_target_report_ptr[86].theta;
   data_ptr.SRR_RL_DETECTION_085_088.DET_AZIMUTH_088 = af_target_report_ptr[87].theta;

   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_085 = af_target_report_ptr[84].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_086 = af_target_report_ptr[85].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_087 = af_target_report_ptr[86].f_bistatic;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BI_STATIC_FLAG_088 = af_target_report_ptr[87].f_bistatic;

   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_085 = af_target_report_ptr[84].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_086 = af_target_report_ptr[85].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_087 = af_target_report_ptr[86].az_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_AZIMUTH_088 = af_target_report_ptr[87].az_conf;

   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_085 = af_target_report_ptr[84].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_086 = af_target_report_ptr[85].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_087 = af_target_report_ptr[86].phi;
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_088 = af_target_report_ptr[87].phi;

   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_085 = af_target_report_ptr[84].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_086 = af_target_report_ptr[85].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_087 = af_target_report_ptr[86].el_conf;
   data_ptr.SRR_RL_DETECTION_085_088.DET_CONFD_ELEVATION_088 = af_target_report_ptr[87].el_conf;

   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_085 = TOI_DS_Stream_Ptr->existence_prob[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_086 = TOI_DS_Stream_Ptr->existence_prob[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_087 = TOI_DS_Stream_Ptr->existence_prob[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_EXISTENCE_PROB_088 = TOI_DS_Stream_Ptr->existence_prob[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_085 = TOI_DS_Stream_Ptr->std_phi[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_086 = TOI_DS_Stream_Ptr->std_phi[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_087 = TOI_DS_Stream_Ptr->std_phi[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_ELEVATION_ERR_088 = TOI_DS_Stream_Ptr->std_phi[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_IDM_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MTD_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_PROB_1STAZHYPO_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_085 = TOI_DS_Stream_Ptr->std_ran[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_086 = TOI_DS_Stream_Ptr->std_ran[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_087 = TOI_DS_Stream_Ptr->std_ran[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_ERR_088 = TOI_DS_Stream_Ptr->std_ran[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_085 = af_target_report_ptr[84].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_086 = af_target_report_ptr[85].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_087 = af_target_report_ptr[86].vel;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_088 = af_target_report_ptr[87].vel;

   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_085 = TOI_DS_Stream_Ptr->std_vel[84];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_086 = TOI_DS_Stream_Ptr->std_vel[85];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_087 = TOI_DS_Stream_Ptr->std_vel[86];
   data_ptr.SRR_RL_DETECTION_085_088.DET_RANGE_VELOCITY_ERR_088 = TOI_DS_Stream_Ptr->std_vel[87];

   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_085 = af_target_report_ptr[84].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_086 = af_target_report_ptr[85].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_087 = af_target_report_ptr[86].rcs;
   data_ptr.SRR_RL_DETECTION_085_088.DET_RCS_088 = af_target_report_ptr[87].rcs;

   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_085 = af_target_report_ptr[84].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_086 = af_target_report_ptr[85].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_087 = af_target_report_ptr[86].snr;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SNR_088 = af_target_report_ptr[87].snr;

   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_085 = af_target_report_ptr[84].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_086 = af_target_report_ptr[85].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_087 = af_target_report_ptr[86].f_superres_target;
   data_ptr.SRR_RL_DETECTION_085_088.DET_SUPER_RES_TARGET_088 = af_target_report_ptr[87].f_superres_target;

   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_085 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_086 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_087 = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_BELOW_RAIN_THOLD_088 = 0;

   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_085 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_086 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_087 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_085_088.DET_HVC_FLAG_088 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_CYCLE_COUNTER_085_088   = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_CRC16_085_088           = 0;
   data_ptr.SRR_RL_DETECTION_085_088.DET_MH_SCAN_INDEX_4LSB_085_088 = 0;

   // SRR_RL_DETECTION_093_096_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_093 = af_target_report_ptr[92].ran;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_094 = af_target_report_ptr[93].ran;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_095 = af_target_report_ptr[94].ran;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_096 = af_target_report_ptr[95].ran;

   data_ptr.SRR_RL_DETECTION_093_096.DET_AZIMUTH_093 = af_target_report_ptr[92].theta;
   data_ptr.SRR_RL_DETECTION_093_096.DET_AZIMUTH_094 = af_target_report_ptr[93].theta;
   data_ptr.SRR_RL_DETECTION_093_096.DET_AZIMUTH_095 = af_target_report_ptr[94].theta;
   data_ptr.SRR_RL_DETECTION_093_096.DET_AZIMUTH_096 = af_target_report_ptr[95].theta;

   data_ptr.SRR_RL_DETECTION_093_096.DET_BI_STATIC_FLAG_093 = af_target_report_ptr[92].f_bistatic;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BI_STATIC_FLAG_094 = af_target_report_ptr[93].f_bistatic;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BI_STATIC_FLAG_095 = af_target_report_ptr[94].f_bistatic;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BI_STATIC_FLAG_096 = af_target_report_ptr[95].f_bistatic;

   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_AZIMUTH_093 = af_target_report_ptr[92].az_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_AZIMUTH_094 = af_target_report_ptr[93].az_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_AZIMUTH_095 = af_target_report_ptr[94].az_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_AZIMUTH_096 = af_target_report_ptr[95].az_conf;

   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_093 = af_target_report_ptr[92].phi;
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_094 = af_target_report_ptr[93].phi;
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_095 = af_target_report_ptr[94].phi;
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_096 = af_target_report_ptr[95].phi;

   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_ELEVATION_093 = af_target_report_ptr[92].el_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_ELEVATION_094 = af_target_report_ptr[93].el_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_ELEVATION_095 = af_target_report_ptr[94].el_conf;
   data_ptr.SRR_RL_DETECTION_093_096.DET_CONFD_ELEVATION_096 = af_target_report_ptr[95].el_conf;

   data_ptr.SRR_RL_DETECTION_093_096.DET_EXISTENCE_PROB_093 = TOI_DS_Stream_Ptr->existence_prob[92];
   data_ptr.SRR_RL_DETECTION_093_096.DET_EXISTENCE_PROB_094 = TOI_DS_Stream_Ptr->existence_prob[93];
   data_ptr.SRR_RL_DETECTION_093_096.DET_EXISTENCE_PROB_095 = TOI_DS_Stream_Ptr->existence_prob[94];
   data_ptr.SRR_RL_DETECTION_093_096.DET_EXISTENCE_PROB_096 = TOI_DS_Stream_Ptr->existence_prob[95];

   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_ERR_093 = TOI_DS_Stream_Ptr->std_phi[92];
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_ERR_094 = TOI_DS_Stream_Ptr->std_phi[93];
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_ERR_095 = TOI_DS_Stream_Ptr->std_phi[94];
   data_ptr.SRR_RL_DETECTION_093_096.DET_ELEVATION_ERR_096 = TOI_DS_Stream_Ptr->std_phi[95];

   data_ptr.SRR_RL_DETECTION_093_096.DET_IDM_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_IDM_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_IDM_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_IDM_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_093_096.DET_MTD_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_MTD_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_MTD_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_MTD_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_093_096.DET_PROB_1STAZHYPO_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_PROB_1STAZHYPO_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_PROB_1STAZHYPO_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_PROB_1STAZHYPO_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_ERR_093 = TOI_DS_Stream_Ptr->std_ran[92];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_ERR_094 = TOI_DS_Stream_Ptr->std_ran[93];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_ERR_095 = TOI_DS_Stream_Ptr->std_ran[94];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_ERR_096 = TOI_DS_Stream_Ptr->std_ran[95];

   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_093 = af_target_report_ptr[92].vel;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_094 = af_target_report_ptr[93].vel;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_095 = af_target_report_ptr[94].vel;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_096 = af_target_report_ptr[95].vel;

   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_093 = TOI_DS_Stream_Ptr->std_vel[92];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_094 = TOI_DS_Stream_Ptr->std_vel[93];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_095 = TOI_DS_Stream_Ptr->std_vel[94];
   data_ptr.SRR_RL_DETECTION_093_096.DET_RANGE_VELOCITY_ERR_096 = TOI_DS_Stream_Ptr->std_vel[95];

   data_ptr.SRR_RL_DETECTION_093_096.DET_RCS_093 = af_target_report_ptr[92].rcs;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RCS_094 = af_target_report_ptr[93].rcs;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RCS_095 = af_target_report_ptr[94].rcs;
   data_ptr.SRR_RL_DETECTION_093_096.DET_RCS_096 = af_target_report_ptr[95].rcs;

   data_ptr.SRR_RL_DETECTION_093_096.DET_SNR_093 = af_target_report_ptr[92].snr;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SNR_094 = af_target_report_ptr[93].snr;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SNR_095 = af_target_report_ptr[94].snr;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SNR_096 = af_target_report_ptr[95].snr;

   data_ptr.SRR_RL_DETECTION_093_096.DET_SUPER_RES_TARGET_093 = af_target_report_ptr[92].f_superres_target;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SUPER_RES_TARGET_094 = af_target_report_ptr[93].f_superres_target;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SUPER_RES_TARGET_095 = af_target_report_ptr[94].f_superres_target;
   data_ptr.SRR_RL_DETECTION_093_096.DET_SUPER_RES_TARGET_096 = af_target_report_ptr[95].f_superres_target;

   data_ptr.SRR_RL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_093 = 0;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_094 = 0;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_095 = 0;
   data_ptr.SRR_RL_DETECTION_093_096.DET_BELOW_RAIN_THOLD_096 = 0;

   data_ptr.SRR_RL_DETECTION_093_096.DET_HVC_FLAG_093 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_HVC_FLAG_094 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_HVC_FLAG_095 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_093_096.DET_HVC_FLAG_096 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_093_096.DET_MH_CYCLE_COUNTER_093_096   = 0;
   data_ptr.SRR_RL_DETECTION_093_096.DET_MH_CRC16_093_096           = 0;
   data_ptr.SRR_RL_DETECTION_093_096.DET_MH_SCAN_INDEX_4LSB_093_096 = 0;

   // SRR_RL_DETECTION_097_100_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_097 = af_target_report_ptr[96].ran;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_098 = af_target_report_ptr[97].ran;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_099 = af_target_report_ptr[98].ran;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_100 = af_target_report_ptr[99].ran;

   data_ptr.SRR_RL_DETECTION_097_100.DET_AZIMUTH_097 = af_target_report_ptr[96].theta;
   data_ptr.SRR_RL_DETECTION_097_100.DET_AZIMUTH_098 = af_target_report_ptr[97].theta;
   data_ptr.SRR_RL_DETECTION_097_100.DET_AZIMUTH_099 = af_target_report_ptr[98].theta;
   data_ptr.SRR_RL_DETECTION_097_100.DET_AZIMUTH_100 = af_target_report_ptr[99].theta;

   data_ptr.SRR_RL_DETECTION_097_100.DET_BI_STATIC_FLAG_097 = af_target_report_ptr[96].f_bistatic;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BI_STATIC_FLAG_098 = af_target_report_ptr[97].f_bistatic;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BI_STATIC_FLAG_099 = af_target_report_ptr[98].f_bistatic;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BI_STATIC_FLAG_100 = af_target_report_ptr[99].f_bistatic;

   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_AZIMUTH_097 = af_target_report_ptr[96].az_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_AZIMUTH_098 = af_target_report_ptr[97].az_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_AZIMUTH_099 = af_target_report_ptr[98].az_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_AZIMUTH_100 = af_target_report_ptr[99].az_conf;

   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_097 = af_target_report_ptr[96].phi;
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_098 = af_target_report_ptr[97].phi;
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_099 = af_target_report_ptr[98].phi;
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_100 = af_target_report_ptr[99].phi;

   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_ELEVATION_097 = af_target_report_ptr[96].el_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_ELEVATION_098 = af_target_report_ptr[97].el_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_ELEVATION_099 = af_target_report_ptr[98].el_conf;
   data_ptr.SRR_RL_DETECTION_097_100.DET_CONFD_ELEVATION_100 = af_target_report_ptr[99].el_conf;

   data_ptr.SRR_RL_DETECTION_097_100.DET_EXISTENCE_PROB_097 = TOI_DS_Stream_Ptr->existence_prob[96];
   data_ptr.SRR_RL_DETECTION_097_100.DET_EXISTENCE_PROB_098 = TOI_DS_Stream_Ptr->existence_prob[97];
   data_ptr.SRR_RL_DETECTION_097_100.DET_EXISTENCE_PROB_099 = TOI_DS_Stream_Ptr->existence_prob[98];
   data_ptr.SRR_RL_DETECTION_097_100.DET_EXISTENCE_PROB_100 = TOI_DS_Stream_Ptr->existence_prob[99];

   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_ERR_097 = TOI_DS_Stream_Ptr->std_phi[96];
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_ERR_098 = TOI_DS_Stream_Ptr->std_phi[97];
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_ERR_099 = TOI_DS_Stream_Ptr->std_phi[98];
   data_ptr.SRR_RL_DETECTION_097_100.DET_ELEVATION_ERR_100 = TOI_DS_Stream_Ptr->std_phi[99];

   data_ptr.SRR_RL_DETECTION_097_100.DET_IDM_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_IDM_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_IDM_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_IDM_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_097_100.DET_MTD_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_MTD_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_MTD_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_MTD_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_097_100.DET_PROB_1STAZHYPO_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_PROB_1STAZHYPO_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_PROB_1STAZHYPO_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_PROB_1STAZHYPO_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_ERR_097 = TOI_DS_Stream_Ptr->std_ran[96];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_ERR_098 = TOI_DS_Stream_Ptr->std_ran[97];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_ERR_099 = TOI_DS_Stream_Ptr->std_ran[98];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_ERR_100 = TOI_DS_Stream_Ptr->std_ran[99];

   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_097 = af_target_report_ptr[96].vel;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_098 = af_target_report_ptr[97].vel;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_099 = af_target_report_ptr[98].vel;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_100 = af_target_report_ptr[99].vel;

   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_097 = TOI_DS_Stream_Ptr->std_vel[96];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_098 = TOI_DS_Stream_Ptr->std_vel[97];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_099 = TOI_DS_Stream_Ptr->std_vel[98];
   data_ptr.SRR_RL_DETECTION_097_100.DET_RANGE_VELOCITY_ERR_100 = TOI_DS_Stream_Ptr->std_vel[99];

   data_ptr.SRR_RL_DETECTION_097_100.DET_RCS_097 = af_target_report_ptr[96].rcs;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RCS_098 = af_target_report_ptr[97].rcs;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RCS_099 = af_target_report_ptr[98].rcs;
   data_ptr.SRR_RL_DETECTION_097_100.DET_RCS_100 = af_target_report_ptr[99].rcs;

   data_ptr.SRR_RL_DETECTION_097_100.DET_SNR_097 = af_target_report_ptr[96].snr;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SNR_098 = af_target_report_ptr[97].snr;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SNR_099 = af_target_report_ptr[98].snr;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SNR_100 = af_target_report_ptr[99].snr;

   data_ptr.SRR_RL_DETECTION_097_100.DET_SUPER_RES_TARGET_097 = af_target_report_ptr[96].f_superres_target;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SUPER_RES_TARGET_098 = af_target_report_ptr[97].f_superres_target;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SUPER_RES_TARGET_099 = af_target_report_ptr[98].f_superres_target;
   data_ptr.SRR_RL_DETECTION_097_100.DET_SUPER_RES_TARGET_100 = af_target_report_ptr[99].f_superres_target;

   data_ptr.SRR_RL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_097 = 0;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_098 = 0;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_099 = 0;
   data_ptr.SRR_RL_DETECTION_097_100.DET_BELOW_RAIN_THOLD_100 = 0;

   data_ptr.SRR_RL_DETECTION_097_100.DET_HVC_FLAG_097 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_HVC_FLAG_098 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_HVC_FLAG_099 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_097_100.DET_HVC_FLAG_100 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_097_100.DET_MH_CYCLE_COUNTER_097_100   = 0;
   data_ptr.SRR_RL_DETECTION_097_100.DET_MH_CRC16_097_100           = 0;
   data_ptr.SRR_RL_DETECTION_097_100.DET_MH_SCAN_INDEX_4LSB_097_100 = 0;

   // SRR_RL_DETECTION_101_104_decoded_msg_t

   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_101 = af_target_report_ptr[100].ran;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_102 = af_target_report_ptr[101].ran;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_103 = af_target_report_ptr[102].ran;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_104 = af_target_report_ptr[103].ran;

   data_ptr.SRR_RL_DETECTION_101_104.DET_AZIMUTH_101 = af_target_report_ptr[100].theta;
   data_ptr.SRR_RL_DETECTION_101_104.DET_AZIMUTH_102 = af_target_report_ptr[101].theta;
   data_ptr.SRR_RL_DETECTION_101_104.DET_AZIMUTH_103 = af_target_report_ptr[102].theta;
   data_ptr.SRR_RL_DETECTION_101_104.DET_AZIMUTH_104 = af_target_report_ptr[103].theta;

   data_ptr.SRR_RL_DETECTION_101_104.DET_BI_STATIC_FLAG_101 = af_target_report_ptr[100].f_bistatic;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BI_STATIC_FLAG_102 = af_target_report_ptr[101].f_bistatic;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BI_STATIC_FLAG_103 = af_target_report_ptr[102].f_bistatic;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BI_STATIC_FLAG_104 = af_target_report_ptr[103].f_bistatic;

   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_AZIMUTH_101 = af_target_report_ptr[100].az_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_AZIMUTH_102 = af_target_report_ptr[101].az_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_AZIMUTH_103 = af_target_report_ptr[102].az_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_AZIMUTH_104 = af_target_report_ptr[103].az_conf;

   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_101 = af_target_report_ptr[100].phi;
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_102 = af_target_report_ptr[101].phi;
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_103 = af_target_report_ptr[102].phi;
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_104 = af_target_report_ptr[103].phi;

   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_ELEVATION_101 = af_target_report_ptr[100].el_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_ELEVATION_102 = af_target_report_ptr[101].el_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_ELEVATION_103 = af_target_report_ptr[102].el_conf;
   data_ptr.SRR_RL_DETECTION_101_104.DET_CONFD_ELEVATION_104 = af_target_report_ptr[103].el_conf;

   data_ptr.SRR_RL_DETECTION_101_104.DET_EXISTENCE_PROB_101 = TOI_DS_Stream_Ptr->existence_prob[100];
   data_ptr.SRR_RL_DETECTION_101_104.DET_EXISTENCE_PROB_102 = TOI_DS_Stream_Ptr->existence_prob[101];
   data_ptr.SRR_RL_DETECTION_101_104.DET_EXISTENCE_PROB_103 = TOI_DS_Stream_Ptr->existence_prob[102];
   data_ptr.SRR_RL_DETECTION_101_104.DET_EXISTENCE_PROB_104 = TOI_DS_Stream_Ptr->existence_prob[103];

   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_ERR_101 = TOI_DS_Stream_Ptr->std_phi[100];
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_ERR_102 = TOI_DS_Stream_Ptr->std_phi[101];
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_ERR_103 = TOI_DS_Stream_Ptr->std_phi[102];
   data_ptr.SRR_RL_DETECTION_101_104.DET_ELEVATION_ERR_104 = TOI_DS_Stream_Ptr->std_phi[103];

   data_ptr.SRR_RL_DETECTION_101_104.DET_IDM_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_IDM_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_IDM_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_IDM_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_101_104.DET_MTD_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_MTD_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_MTD_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_MTD_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_101_104.DET_PROB_1STAZHYPO_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_PROB_1STAZHYPO_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_PROB_1STAZHYPO_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_PROB_1STAZHYPO_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_ERR_101 = TOI_DS_Stream_Ptr->std_ran[100];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_ERR_102 = TOI_DS_Stream_Ptr->std_ran[101];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_ERR_103 = TOI_DS_Stream_Ptr->std_ran[102];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_ERR_104 = TOI_DS_Stream_Ptr->std_ran[103];

   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_101 = af_target_report_ptr[100].vel;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_102 = af_target_report_ptr[101].vel;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_103 = af_target_report_ptr[102].vel;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_104 = af_target_report_ptr[103].vel;

   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_101 = TOI_DS_Stream_Ptr->std_vel[100];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_102 = TOI_DS_Stream_Ptr->std_vel[101];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_103 = TOI_DS_Stream_Ptr->std_vel[102];
   data_ptr.SRR_RL_DETECTION_101_104.DET_RANGE_VELOCITY_ERR_104 = TOI_DS_Stream_Ptr->std_vel[103];

   data_ptr.SRR_RL_DETECTION_101_104.DET_RCS_101 = af_target_report_ptr[100].rcs;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RCS_102 = af_target_report_ptr[101].rcs;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RCS_103 = af_target_report_ptr[102].rcs;
   data_ptr.SRR_RL_DETECTION_101_104.DET_RCS_104 = af_target_report_ptr[103].rcs;

   data_ptr.SRR_RL_DETECTION_101_104.DET_SNR_101 = af_target_report_ptr[100].snr;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SNR_102 = af_target_report_ptr[101].snr;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SNR_103 = af_target_report_ptr[102].snr;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SNR_104 = af_target_report_ptr[103].snr;

   data_ptr.SRR_RL_DETECTION_101_104.DET_SUPER_RES_TARGET_101 = af_target_report_ptr[100].f_superres_target;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SUPER_RES_TARGET_102 = af_target_report_ptr[101].f_superres_target;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SUPER_RES_TARGET_103 = af_target_report_ptr[102].f_superres_target;
   data_ptr.SRR_RL_DETECTION_101_104.DET_SUPER_RES_TARGET_104 = af_target_report_ptr[103].f_superres_target;

   data_ptr.SRR_RL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_101 = 0;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_102 = 0;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_103 = 0;
   data_ptr.SRR_RL_DETECTION_101_104.DET_BELOW_RAIN_THOLD_104 = 0;

   data_ptr.SRR_RL_DETECTION_101_104.DET_HVC_FLAG_101 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_HVC_FLAG_102 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_HVC_FLAG_103 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_101_104.DET_HVC_FLAG_104 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_101_104.DET_MH_CYCLE_COUNTER_101_104   = 0;
   data_ptr.SRR_RL_DETECTION_101_104.DET_MH_CRC16_101_104           = 0;
   data_ptr.SRR_RL_DETECTION_101_104.DET_MH_SCAN_INDEX_4LSB_101_104 = 0;

   // SRR_RL_DETECTION_105_108_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_105 = af_target_report_ptr[104].ran;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_106 = af_target_report_ptr[105].ran;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_107 = af_target_report_ptr[106].ran;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_108 = af_target_report_ptr[107].ran;

   data_ptr.SRR_RL_DETECTION_105_108.DET_AZIMUTH_105 = af_target_report_ptr[104].theta;
   data_ptr.SRR_RL_DETECTION_105_108.DET_AZIMUTH_106 = af_target_report_ptr[105].theta;
   data_ptr.SRR_RL_DETECTION_105_108.DET_AZIMUTH_107 = af_target_report_ptr[106].theta;
   data_ptr.SRR_RL_DETECTION_105_108.DET_AZIMUTH_108 = af_target_report_ptr[107].theta;

   data_ptr.SRR_RL_DETECTION_105_108.DET_BI_STATIC_FLAG_105 = af_target_report_ptr[104].f_bistatic;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BI_STATIC_FLAG_106 = af_target_report_ptr[105].f_bistatic;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BI_STATIC_FLAG_107 = af_target_report_ptr[106].f_bistatic;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BI_STATIC_FLAG_108 = af_target_report_ptr[107].f_bistatic;

   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_AZIMUTH_105 = af_target_report_ptr[104].az_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_AZIMUTH_106 = af_target_report_ptr[105].az_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_AZIMUTH_107 = af_target_report_ptr[106].az_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_AZIMUTH_108 = af_target_report_ptr[107].az_conf;

   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_105 = af_target_report_ptr[104].phi;
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_106 = af_target_report_ptr[105].phi;
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_107 = af_target_report_ptr[106].phi;
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_108 = af_target_report_ptr[107].phi;

   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_ELEVATION_105 = af_target_report_ptr[104].el_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_ELEVATION_106 = af_target_report_ptr[105].el_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_ELEVATION_107 = af_target_report_ptr[106].el_conf;
   data_ptr.SRR_RL_DETECTION_105_108.DET_CONFD_ELEVATION_108 = af_target_report_ptr[107].el_conf;

   data_ptr.SRR_RL_DETECTION_105_108.DET_EXISTENCE_PROB_105 = TOI_DS_Stream_Ptr->existence_prob[104];
   data_ptr.SRR_RL_DETECTION_105_108.DET_EXISTENCE_PROB_106 = TOI_DS_Stream_Ptr->existence_prob[105];
   data_ptr.SRR_RL_DETECTION_105_108.DET_EXISTENCE_PROB_107 = TOI_DS_Stream_Ptr->existence_prob[106];
   data_ptr.SRR_RL_DETECTION_105_108.DET_EXISTENCE_PROB_108 = TOI_DS_Stream_Ptr->existence_prob[107];

   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_ERR_105 = TOI_DS_Stream_Ptr->std_phi[104];
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_ERR_106 = TOI_DS_Stream_Ptr->std_phi[105];
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_ERR_107 = TOI_DS_Stream_Ptr->std_phi[106];
   data_ptr.SRR_RL_DETECTION_105_108.DET_ELEVATION_ERR_108 = TOI_DS_Stream_Ptr->std_phi[107];

   data_ptr.SRR_RL_DETECTION_105_108.DET_IDM_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_IDM_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_IDM_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_IDM_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_105_108.DET_MTD_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_MTD_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_MTD_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_MTD_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_105_108.DET_PROB_1STAZHYPO_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_PROB_1STAZHYPO_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_PROB_1STAZHYPO_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_PROB_1STAZHYPO_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_ERR_105 = TOI_DS_Stream_Ptr->std_ran[104];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_ERR_106 = TOI_DS_Stream_Ptr->std_ran[105];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_ERR_107 = TOI_DS_Stream_Ptr->std_ran[106];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_ERR_108 = TOI_DS_Stream_Ptr->std_ran[107];

   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_105 = af_target_report_ptr[104].vel;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_106 = af_target_report_ptr[105].vel;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_107 = af_target_report_ptr[106].vel;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_108 = af_target_report_ptr[107].vel;

   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_105 = TOI_DS_Stream_Ptr->std_vel[104];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_106 = TOI_DS_Stream_Ptr->std_vel[105];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_107 = TOI_DS_Stream_Ptr->std_vel[106];
   data_ptr.SRR_RL_DETECTION_105_108.DET_RANGE_VELOCITY_ERR_108 = TOI_DS_Stream_Ptr->std_vel[107];

   data_ptr.SRR_RL_DETECTION_105_108.DET_RCS_105 = af_target_report_ptr[104].rcs;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RCS_106 = af_target_report_ptr[105].rcs;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RCS_107 = af_target_report_ptr[106].rcs;
   data_ptr.SRR_RL_DETECTION_105_108.DET_RCS_108 = af_target_report_ptr[107].rcs;

   data_ptr.SRR_RL_DETECTION_105_108.DET_SNR_105 = af_target_report_ptr[104].snr;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SNR_106 = af_target_report_ptr[105].snr;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SNR_107 = af_target_report_ptr[106].snr;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SNR_108 = af_target_report_ptr[107].snr;

   data_ptr.SRR_RL_DETECTION_105_108.DET_SUPER_RES_TARGET_105 = af_target_report_ptr[104].f_superres_target;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SUPER_RES_TARGET_106 = af_target_report_ptr[105].f_superres_target;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SUPER_RES_TARGET_107 = af_target_report_ptr[106].f_superres_target;
   data_ptr.SRR_RL_DETECTION_105_108.DET_SUPER_RES_TARGET_108 = af_target_report_ptr[107].f_superres_target;

   data_ptr.SRR_RL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_105 = 0;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_106 = 0;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_107 = 0;
   data_ptr.SRR_RL_DETECTION_105_108.DET_BELOW_RAIN_THOLD_108 = 0;

   data_ptr.SRR_RL_DETECTION_105_108.DET_HVC_FLAG_105 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_HVC_FLAG_106 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_HVC_FLAG_107 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_105_108.DET_HVC_FLAG_108 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_105_108.DET_MH_CYCLE_COUNTER_105_108   = 0;
   data_ptr.SRR_RL_DETECTION_105_108.DET_MH_CRC16_105_108           = 0;
   data_ptr.SRR_RL_DETECTION_105_108.DET_MH_SCAN_INDEX_4LSB_105_108 = 0;

   // SRR_RL_DETECTION_109_112_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_109 = af_target_report_ptr[108].ran;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_110 = af_target_report_ptr[109].ran;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_111 = af_target_report_ptr[110].ran;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_112 = af_target_report_ptr[111].ran;

   data_ptr.SRR_RL_DETECTION_109_112.DET_AZIMUTH_109 = af_target_report_ptr[108].theta;
   data_ptr.SRR_RL_DETECTION_109_112.DET_AZIMUTH_110 = af_target_report_ptr[109].theta;
   data_ptr.SRR_RL_DETECTION_109_112.DET_AZIMUTH_111 = af_target_report_ptr[110].theta;
   data_ptr.SRR_RL_DETECTION_109_112.DET_AZIMUTH_112 = af_target_report_ptr[111].theta;

   data_ptr.SRR_RL_DETECTION_109_112.DET_BI_STATIC_FLAG_109 = af_target_report_ptr[108].f_bistatic;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BI_STATIC_FLAG_110 = af_target_report_ptr[109].f_bistatic;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BI_STATIC_FLAG_111 = af_target_report_ptr[110].f_bistatic;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BI_STATIC_FLAG_112 = af_target_report_ptr[111].f_bistatic;

   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_AZIMUTH_109 = af_target_report_ptr[108].az_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_AZIMUTH_110 = af_target_report_ptr[109].az_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_AZIMUTH_111 = af_target_report_ptr[110].az_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_AZIMUTH_112 = af_target_report_ptr[111].az_conf;

   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_109 = af_target_report_ptr[108].phi;
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_110 = af_target_report_ptr[109].phi;
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_111 = af_target_report_ptr[110].phi;
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_112 = af_target_report_ptr[111].phi;

   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_ELEVATION_109 = af_target_report_ptr[108].el_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_ELEVATION_110 = af_target_report_ptr[109].el_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_ELEVATION_111 = af_target_report_ptr[110].el_conf;
   data_ptr.SRR_RL_DETECTION_109_112.DET_CONFD_ELEVATION_112 = af_target_report_ptr[111].el_conf;

   data_ptr.SRR_RL_DETECTION_109_112.DET_EXISTENCE_PROB_109 = TOI_DS_Stream_Ptr->existence_prob[108];
   data_ptr.SRR_RL_DETECTION_109_112.DET_EXISTENCE_PROB_110 = TOI_DS_Stream_Ptr->existence_prob[109];
   data_ptr.SRR_RL_DETECTION_109_112.DET_EXISTENCE_PROB_111 = TOI_DS_Stream_Ptr->existence_prob[110];
   data_ptr.SRR_RL_DETECTION_109_112.DET_EXISTENCE_PROB_112 = TOI_DS_Stream_Ptr->existence_prob[111];

   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_ERR_109 = TOI_DS_Stream_Ptr->std_phi[108];
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_ERR_110 = TOI_DS_Stream_Ptr->std_phi[109];
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_ERR_111 = TOI_DS_Stream_Ptr->std_phi[110];
   data_ptr.SRR_RL_DETECTION_109_112.DET_ELEVATION_ERR_112 = TOI_DS_Stream_Ptr->std_phi[111];

   data_ptr.SRR_RL_DETECTION_109_112.DET_IDM_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_IDM_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_IDM_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_IDM_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_109_112.DET_MTD_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_MTD_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_MTD_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_MTD_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_109_112.DET_PROB_1STAZHYPO_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_PROB_1STAZHYPO_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_PROB_1STAZHYPO_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_PROB_1STAZHYPO_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_ERR_109 = TOI_DS_Stream_Ptr->std_ran[108];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_ERR_110 = TOI_DS_Stream_Ptr->std_ran[109];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_ERR_111 = TOI_DS_Stream_Ptr->std_ran[110];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_ERR_112 = TOI_DS_Stream_Ptr->std_ran[111];

   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_109 = af_target_report_ptr[108].vel;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_110 = af_target_report_ptr[109].vel;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_111 = af_target_report_ptr[110].vel;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_112 = af_target_report_ptr[111].vel;

   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_109 = TOI_DS_Stream_Ptr->std_vel[108];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_110 = TOI_DS_Stream_Ptr->std_vel[109];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_111 = TOI_DS_Stream_Ptr->std_vel[110];
   data_ptr.SRR_RL_DETECTION_109_112.DET_RANGE_VELOCITY_ERR_112 = TOI_DS_Stream_Ptr->std_vel[111];

   data_ptr.SRR_RL_DETECTION_109_112.DET_RCS_109 = af_target_report_ptr[108].rcs;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RCS_110 = af_target_report_ptr[109].rcs;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RCS_111 = af_target_report_ptr[110].rcs;
   data_ptr.SRR_RL_DETECTION_109_112.DET_RCS_112 = af_target_report_ptr[111].rcs;

   data_ptr.SRR_RL_DETECTION_109_112.DET_SNR_109 = af_target_report_ptr[108].snr;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SNR_110 = af_target_report_ptr[109].snr;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SNR_111 = af_target_report_ptr[110].snr;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SNR_112 = af_target_report_ptr[111].snr;

   data_ptr.SRR_RL_DETECTION_109_112.DET_SUPER_RES_TARGET_109 = af_target_report_ptr[108].f_superres_target;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SUPER_RES_TARGET_110 = af_target_report_ptr[109].f_superres_target;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SUPER_RES_TARGET_111 = af_target_report_ptr[110].f_superres_target;
   data_ptr.SRR_RL_DETECTION_109_112.DET_SUPER_RES_TARGET_112 = af_target_report_ptr[111].f_superres_target;

   data_ptr.SRR_RL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_109 = 0;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_110 = 0;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_111 = 0;
   data_ptr.SRR_RL_DETECTION_109_112.DET_BELOW_RAIN_THOLD_112 = 0;

   data_ptr.SRR_RL_DETECTION_109_112.DET_HVC_FLAG_109 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_HVC_FLAG_110 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_HVC_FLAG_111 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_109_112.DET_HVC_FLAG_112 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_109_112.DET_MH_CYCLE_COUNTER_109_112   = 0;
   data_ptr.SRR_RL_DETECTION_109_112.DET_MH_CRC16_109_112           = 0;
   data_ptr.SRR_RL_DETECTION_109_112.DET_MH_SCAN_INDEX_4LSB_109_112 = 0;

   // SRR_RL_DETECTION_113_116_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_113 = af_target_report_ptr[112].ran;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_114 = af_target_report_ptr[113].ran;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_115 = af_target_report_ptr[114].ran;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_116 = af_target_report_ptr[115].ran;

   data_ptr.SRR_RL_DETECTION_113_116.DET_AZIMUTH_113 = af_target_report_ptr[112].theta;
   data_ptr.SRR_RL_DETECTION_113_116.DET_AZIMUTH_114 = af_target_report_ptr[113].theta;
   data_ptr.SRR_RL_DETECTION_113_116.DET_AZIMUTH_115 = af_target_report_ptr[114].theta;
   data_ptr.SRR_RL_DETECTION_113_116.DET_AZIMUTH_116 = af_target_report_ptr[115].theta;

   data_ptr.SRR_RL_DETECTION_113_116.DET_BI_STATIC_FLAG_113 = af_target_report_ptr[112].f_bistatic;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BI_STATIC_FLAG_114 = af_target_report_ptr[113].f_bistatic;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BI_STATIC_FLAG_115 = af_target_report_ptr[114].f_bistatic;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BI_STATIC_FLAG_116 = af_target_report_ptr[115].f_bistatic;

   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_AZIMUTH_113 = af_target_report_ptr[112].az_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_AZIMUTH_114 = af_target_report_ptr[113].az_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_AZIMUTH_115 = af_target_report_ptr[114].az_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_AZIMUTH_116 = af_target_report_ptr[115].az_conf;

   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_113 = af_target_report_ptr[112].phi;
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_114 = af_target_report_ptr[113].phi;
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_115 = af_target_report_ptr[114].phi;
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_116 = af_target_report_ptr[115].phi;

   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_ELEVATION_113 = af_target_report_ptr[112].el_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_ELEVATION_114 = af_target_report_ptr[113].el_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_ELEVATION_115 = af_target_report_ptr[114].el_conf;
   data_ptr.SRR_RL_DETECTION_113_116.DET_CONFD_ELEVATION_116 = af_target_report_ptr[115].el_conf;

   data_ptr.SRR_RL_DETECTION_113_116.DET_EXISTENCE_PROB_113 = TOI_DS_Stream_Ptr->existence_prob[112];
   data_ptr.SRR_RL_DETECTION_113_116.DET_EXISTENCE_PROB_114 = TOI_DS_Stream_Ptr->existence_prob[113];
   data_ptr.SRR_RL_DETECTION_113_116.DET_EXISTENCE_PROB_115 = TOI_DS_Stream_Ptr->existence_prob[114];
   data_ptr.SRR_RL_DETECTION_113_116.DET_EXISTENCE_PROB_116 = TOI_DS_Stream_Ptr->existence_prob[115];

   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_ERR_113 = TOI_DS_Stream_Ptr->std_phi[112];
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_ERR_114 = TOI_DS_Stream_Ptr->std_phi[113];
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_ERR_115 = TOI_DS_Stream_Ptr->std_phi[114];
   data_ptr.SRR_RL_DETECTION_113_116.DET_ELEVATION_ERR_116 = TOI_DS_Stream_Ptr->std_phi[115];

   data_ptr.SRR_RL_DETECTION_113_116.DET_IDM_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_IDM_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_IDM_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_IDM_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_113_116.DET_MTD_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_MTD_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_MTD_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_MTD_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_113_116.DET_PROB_1STAZHYPO_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_PROB_1STAZHYPO_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_PROB_1STAZHYPO_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_PROB_1STAZHYPO_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_ERR_113 = TOI_DS_Stream_Ptr->std_ran[112];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_ERR_114 = TOI_DS_Stream_Ptr->std_ran[113];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_ERR_115 = TOI_DS_Stream_Ptr->std_ran[114];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_ERR_116 = TOI_DS_Stream_Ptr->std_ran[115];

   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_113 = af_target_report_ptr[112].vel;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_114 = af_target_report_ptr[113].vel;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_115 = af_target_report_ptr[114].vel;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_116 = af_target_report_ptr[115].vel;

   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_113 = TOI_DS_Stream_Ptr->std_vel[112];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_114 = TOI_DS_Stream_Ptr->std_vel[113];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_115 = TOI_DS_Stream_Ptr->std_vel[114];
   data_ptr.SRR_RL_DETECTION_113_116.DET_RANGE_VELOCITY_ERR_116 = TOI_DS_Stream_Ptr->std_vel[115];

   data_ptr.SRR_RL_DETECTION_113_116.DET_RCS_113 = af_target_report_ptr[112].rcs;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RCS_114 = af_target_report_ptr[113].rcs;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RCS_115 = af_target_report_ptr[114].rcs;
   data_ptr.SRR_RL_DETECTION_113_116.DET_RCS_116 = af_target_report_ptr[115].rcs;

   data_ptr.SRR_RL_DETECTION_113_116.DET_SNR_113 = af_target_report_ptr[112].snr;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SNR_114 = af_target_report_ptr[113].snr;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SNR_115 = af_target_report_ptr[114].snr;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SNR_116 = af_target_report_ptr[115].snr;

   data_ptr.SRR_RL_DETECTION_113_116.DET_SUPER_RES_TARGET_113 = af_target_report_ptr[112].f_superres_target;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SUPER_RES_TARGET_114 = af_target_report_ptr[113].f_superres_target;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SUPER_RES_TARGET_115 = af_target_report_ptr[114].f_superres_target;
   data_ptr.SRR_RL_DETECTION_113_116.DET_SUPER_RES_TARGET_116 = af_target_report_ptr[115].f_superres_target;

   data_ptr.SRR_RL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_113 = 0;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_114 = 0;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_115 = 0;
   data_ptr.SRR_RL_DETECTION_113_116.DET_BELOW_RAIN_THOLD_116 = 0;

   data_ptr.SRR_RL_DETECTION_113_116.DET_HVC_FLAG_113 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_HVC_FLAG_114 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_HVC_FLAG_115 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_113_116.DET_HVC_FLAG_116 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_113_116.DET_MH_CYCLE_COUNTER_113_116   = 0;
   data_ptr.SRR_RL_DETECTION_113_116.DET_MH_CRC16_113_116           = 0;
   data_ptr.SRR_RL_DETECTION_113_116.DET_MH_SCAN_INDEX_4LSB_113_116 = 0;

   // SRR_RL_DETECTION_117_120_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_117 = af_target_report_ptr[116].ran;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_118 = af_target_report_ptr[117].ran;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_119 = af_target_report_ptr[118].ran;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_120 = af_target_report_ptr[119].ran;

   data_ptr.SRR_RL_DETECTION_117_120.DET_AZIMUTH_117 = af_target_report_ptr[116].theta;
   data_ptr.SRR_RL_DETECTION_117_120.DET_AZIMUTH_118 = af_target_report_ptr[117].theta;
   data_ptr.SRR_RL_DETECTION_117_120.DET_AZIMUTH_119 = af_target_report_ptr[118].theta;
   data_ptr.SRR_RL_DETECTION_117_120.DET_AZIMUTH_120 = af_target_report_ptr[119].theta;

   data_ptr.SRR_RL_DETECTION_117_120.DET_BI_STATIC_FLAG_117 = af_target_report_ptr[116].f_bistatic;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BI_STATIC_FLAG_118 = af_target_report_ptr[117].f_bistatic;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BI_STATIC_FLAG_119 = af_target_report_ptr[118].f_bistatic;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BI_STATIC_FLAG_120 = af_target_report_ptr[119].f_bistatic;

   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_AZIMUTH_117 = af_target_report_ptr[116].az_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_AZIMUTH_118 = af_target_report_ptr[117].az_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_AZIMUTH_119 = af_target_report_ptr[118].az_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_AZIMUTH_120 = af_target_report_ptr[119].az_conf;

   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_117 = af_target_report_ptr[116].phi;
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_118 = af_target_report_ptr[117].phi;
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_119 = af_target_report_ptr[118].phi;
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_120 = af_target_report_ptr[119].phi;

   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_ELEVATION_117 = af_target_report_ptr[116].el_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_ELEVATION_118 = af_target_report_ptr[117].el_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_ELEVATION_119 = af_target_report_ptr[118].el_conf;
   data_ptr.SRR_RL_DETECTION_117_120.DET_CONFD_ELEVATION_120 = af_target_report_ptr[119].el_conf;

   data_ptr.SRR_RL_DETECTION_117_120.DET_EXISTENCE_PROB_117 = TOI_DS_Stream_Ptr->existence_prob[116];
   data_ptr.SRR_RL_DETECTION_117_120.DET_EXISTENCE_PROB_118 = TOI_DS_Stream_Ptr->existence_prob[117];
   data_ptr.SRR_RL_DETECTION_117_120.DET_EXISTENCE_PROB_119 = TOI_DS_Stream_Ptr->existence_prob[118];
   data_ptr.SRR_RL_DETECTION_117_120.DET_EXISTENCE_PROB_120 = TOI_DS_Stream_Ptr->existence_prob[119];

   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_ERR_117 = TOI_DS_Stream_Ptr->std_phi[116];
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_ERR_118 = TOI_DS_Stream_Ptr->std_phi[117];
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_ERR_119 = TOI_DS_Stream_Ptr->std_phi[118];
   data_ptr.SRR_RL_DETECTION_117_120.DET_ELEVATION_ERR_120 = TOI_DS_Stream_Ptr->std_phi[119];

   data_ptr.SRR_RL_DETECTION_117_120.DET_IDM_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_IDM_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_IDM_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_IDM_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_117_120.DET_MTD_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_MTD_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_MTD_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_MTD_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_117_120.DET_PROB_1STAZHYPO_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_PROB_1STAZHYPO_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_PROB_1STAZHYPO_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_PROB_1STAZHYPO_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_ERR_117 = TOI_DS_Stream_Ptr->std_ran[116];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_ERR_118 = TOI_DS_Stream_Ptr->std_ran[117];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_ERR_119 = TOI_DS_Stream_Ptr->std_ran[118];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_ERR_120 = TOI_DS_Stream_Ptr->std_ran[119];

   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_117 = af_target_report_ptr[116].vel;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_118 = af_target_report_ptr[117].vel;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_119 = af_target_report_ptr[118].vel;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_120 = af_target_report_ptr[119].vel;

   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_117 = TOI_DS_Stream_Ptr->std_vel[116];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_118 = TOI_DS_Stream_Ptr->std_vel[117];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_119 = TOI_DS_Stream_Ptr->std_vel[118];
   data_ptr.SRR_RL_DETECTION_117_120.DET_RANGE_VELOCITY_ERR_120 = TOI_DS_Stream_Ptr->std_vel[119];

   data_ptr.SRR_RL_DETECTION_117_120.DET_RCS_117 = af_target_report_ptr[116].rcs;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RCS_118 = af_target_report_ptr[117].rcs;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RCS_119 = af_target_report_ptr[118].rcs;
   data_ptr.SRR_RL_DETECTION_117_120.DET_RCS_120 = af_target_report_ptr[119].rcs;

   data_ptr.SRR_RL_DETECTION_117_120.DET_SNR_117 = af_target_report_ptr[116].snr;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SNR_118 = af_target_report_ptr[117].snr;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SNR_119 = af_target_report_ptr[118].snr;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SNR_120 = af_target_report_ptr[119].snr;

   data_ptr.SRR_RL_DETECTION_117_120.DET_SUPER_RES_TARGET_117 = af_target_report_ptr[116].f_superres_target;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SUPER_RES_TARGET_118 = af_target_report_ptr[117].f_superres_target;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SUPER_RES_TARGET_119 = af_target_report_ptr[118].f_superres_target;
   data_ptr.SRR_RL_DETECTION_117_120.DET_SUPER_RES_TARGET_120 = af_target_report_ptr[119].f_superres_target;

   data_ptr.SRR_RL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_117 = 0;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_118 = 0;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_119 = 0;
   data_ptr.SRR_RL_DETECTION_117_120.DET_BELOW_RAIN_THOLD_120 = 0;

   data_ptr.SRR_RL_DETECTION_117_120.DET_HVC_FLAG_117 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_HVC_FLAG_118 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_HVC_FLAG_119 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_117_120.DET_HVC_FLAG_120 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_117_120.DET_MH_CYCLE_COUNTER_117_120   = 0;
   data_ptr.SRR_RL_DETECTION_117_120.DET_MH_CRC16_117_120           = 0;
   data_ptr.SRR_RL_DETECTION_117_120.DET_MH_SCAN_INDEX_4LSB_117_120 = 0;

   // SRR_RL_DETECTION_121_124_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_121 = af_target_report_ptr[120].ran;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_122 = af_target_report_ptr[121].ran;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_123 = af_target_report_ptr[122].ran;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_124 = af_target_report_ptr[123].ran;

   data_ptr.SRR_RL_DETECTION_121_124.DET_AZIMUTH_121 = af_target_report_ptr[120].theta;
   data_ptr.SRR_RL_DETECTION_121_124.DET_AZIMUTH_122 = af_target_report_ptr[121].theta;
   data_ptr.SRR_RL_DETECTION_121_124.DET_AZIMUTH_123 = af_target_report_ptr[122].theta;
   data_ptr.SRR_RL_DETECTION_121_124.DET_AZIMUTH_124 = af_target_report_ptr[123].theta;

   data_ptr.SRR_RL_DETECTION_121_124.DET_BI_STATIC_FLAG_121 = af_target_report_ptr[120].f_bistatic;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BI_STATIC_FLAG_122 = af_target_report_ptr[121].f_bistatic;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BI_STATIC_FLAG_123 = af_target_report_ptr[122].f_bistatic;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BI_STATIC_FLAG_124 = af_target_report_ptr[123].f_bistatic;

   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_AZIMUTH_121 = af_target_report_ptr[120].az_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_AZIMUTH_122 = af_target_report_ptr[121].az_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_AZIMUTH_123 = af_target_report_ptr[122].az_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_AZIMUTH_124 = af_target_report_ptr[123].az_conf;

   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_121 = af_target_report_ptr[120].phi;
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_122 = af_target_report_ptr[121].phi;
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_123 = af_target_report_ptr[122].phi;
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_124 = af_target_report_ptr[123].phi;

   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_ELEVATION_121 = af_target_report_ptr[120].el_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_ELEVATION_122 = af_target_report_ptr[121].el_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_ELEVATION_123 = af_target_report_ptr[122].el_conf;
   data_ptr.SRR_RL_DETECTION_121_124.DET_CONFD_ELEVATION_124 = af_target_report_ptr[123].el_conf;

   data_ptr.SRR_RL_DETECTION_121_124.DET_EXISTENCE_PROB_121 = TOI_DS_Stream_Ptr->existence_prob[120];
   data_ptr.SRR_RL_DETECTION_121_124.DET_EXISTENCE_PROB_122 = TOI_DS_Stream_Ptr->existence_prob[121];
   data_ptr.SRR_RL_DETECTION_121_124.DET_EXISTENCE_PROB_123 = TOI_DS_Stream_Ptr->existence_prob[122];
   data_ptr.SRR_RL_DETECTION_121_124.DET_EXISTENCE_PROB_124 = TOI_DS_Stream_Ptr->existence_prob[123];

   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_ERR_121 = TOI_DS_Stream_Ptr->std_phi[120];
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_ERR_122 = TOI_DS_Stream_Ptr->std_phi[121];
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_ERR_123 = TOI_DS_Stream_Ptr->std_phi[122];
   data_ptr.SRR_RL_DETECTION_121_124.DET_ELEVATION_ERR_124 = TOI_DS_Stream_Ptr->std_phi[123];

   data_ptr.SRR_RL_DETECTION_121_124.DET_IDM_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_IDM_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_IDM_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_IDM_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_121_124.DET_MTD_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_MTD_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_MTD_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_MTD_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_121_124.DET_PROB_1STAZHYPO_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_PROB_1STAZHYPO_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_PROB_1STAZHYPO_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_PROB_1STAZHYPO_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_ERR_121 = TOI_DS_Stream_Ptr->std_ran[120];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_ERR_122 = TOI_DS_Stream_Ptr->std_ran[121];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_ERR_123 = TOI_DS_Stream_Ptr->std_ran[122];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_ERR_124 = TOI_DS_Stream_Ptr->std_ran[123];

   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_121 = af_target_report_ptr[120].vel;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_122 = af_target_report_ptr[121].vel;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_123 = af_target_report_ptr[122].vel;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_124 = af_target_report_ptr[123].vel;

   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_121 = TOI_DS_Stream_Ptr->std_vel[120];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_122 = TOI_DS_Stream_Ptr->std_vel[121];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_123 = TOI_DS_Stream_Ptr->std_vel[122];
   data_ptr.SRR_RL_DETECTION_121_124.DET_RANGE_VELOCITY_ERR_124 = TOI_DS_Stream_Ptr->std_vel[123];

   data_ptr.SRR_RL_DETECTION_121_124.DET_RCS_121 = af_target_report_ptr[120].rcs;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RCS_122 = af_target_report_ptr[121].rcs;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RCS_123 = af_target_report_ptr[122].rcs;
   data_ptr.SRR_RL_DETECTION_121_124.DET_RCS_124 = af_target_report_ptr[123].rcs;

   data_ptr.SRR_RL_DETECTION_121_124.DET_SNR_121 = af_target_report_ptr[120].snr;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SNR_122 = af_target_report_ptr[121].snr;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SNR_123 = af_target_report_ptr[122].snr;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SNR_124 = af_target_report_ptr[123].snr;

   data_ptr.SRR_RL_DETECTION_121_124.DET_SUPER_RES_TARGET_121 = af_target_report_ptr[120].f_superres_target;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SUPER_RES_TARGET_122 = af_target_report_ptr[121].f_superres_target;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SUPER_RES_TARGET_123 = af_target_report_ptr[122].f_superres_target;
   data_ptr.SRR_RL_DETECTION_121_124.DET_SUPER_RES_TARGET_124 = af_target_report_ptr[123].f_superres_target;

   data_ptr.SRR_RL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_121 = 0;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_122 = 0;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_123 = 0;
   data_ptr.SRR_RL_DETECTION_121_124.DET_BELOW_RAIN_THOLD_124 = 0;

   data_ptr.SRR_RL_DETECTION_121_124.DET_HVC_FLAG_121 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_HVC_FLAG_122 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_HVC_FLAG_123 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_121_124.DET_HVC_FLAG_124 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_121_124.DET_MH_CYCLE_COUNTER_121_124   = 0;
   data_ptr.SRR_RL_DETECTION_121_124.DET_MH_CRC16_121_124           = 0;
   data_ptr.SRR_RL_DETECTION_121_124.DET_MH_SCAN_INDEX_4LSB_121_124 = 0;

   // SRR_RL_DETECTION_125_128_decoded_msg_t
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_125 = af_target_report_ptr[124].ran;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_126 = af_target_report_ptr[125].ran;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_127 = af_target_report_ptr[126].ran;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_128 = af_target_report_ptr[127].ran;

   data_ptr.SRR_RL_DETECTION_125_128.DET_AZIMUTH_125 = af_target_report_ptr[124].theta;
   data_ptr.SRR_RL_DETECTION_125_128.DET_AZIMUTH_126 = af_target_report_ptr[125].theta;
   data_ptr.SRR_RL_DETECTION_125_128.DET_AZIMUTH_127 = af_target_report_ptr[126].theta;
   data_ptr.SRR_RL_DETECTION_125_128.DET_AZIMUTH_128 = af_target_report_ptr[127].theta;

   data_ptr.SRR_RL_DETECTION_125_128.DET_BI_STATIC_FLAG_125 = af_target_report_ptr[124].f_bistatic;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BI_STATIC_FLAG_126 = af_target_report_ptr[125].f_bistatic;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BI_STATIC_FLAG_127 = af_target_report_ptr[126].f_bistatic;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BI_STATIC_FLAG_128 = af_target_report_ptr[127].f_bistatic;

   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_AZIMUTH_125 = af_target_report_ptr[124].az_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_AZIMUTH_126 = af_target_report_ptr[125].az_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_AZIMUTH_127 = af_target_report_ptr[126].az_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_AZIMUTH_128 = af_target_report_ptr[127].az_conf;

   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_125 = af_target_report_ptr[124].phi;
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_126 = af_target_report_ptr[125].phi;
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_127 = af_target_report_ptr[126].phi;
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_128 = af_target_report_ptr[127].phi;

   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_ELEVATION_125 = af_target_report_ptr[124].el_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_ELEVATION_126 = af_target_report_ptr[125].el_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_ELEVATION_127 = af_target_report_ptr[126].el_conf;
   data_ptr.SRR_RL_DETECTION_125_128.DET_CONFD_ELEVATION_128 = af_target_report_ptr[127].el_conf;

   data_ptr.SRR_RL_DETECTION_125_128.DET_EXISTENCE_PROB_125 = TOI_DS_Stream_Ptr->existence_prob[124];
   data_ptr.SRR_RL_DETECTION_125_128.DET_EXISTENCE_PROB_126 = TOI_DS_Stream_Ptr->existence_prob[125];
   data_ptr.SRR_RL_DETECTION_125_128.DET_EXISTENCE_PROB_127 = TOI_DS_Stream_Ptr->existence_prob[126];
   data_ptr.SRR_RL_DETECTION_125_128.DET_EXISTENCE_PROB_128 = TOI_DS_Stream_Ptr->existence_prob[127];

   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_ERR_125 = TOI_DS_Stream_Ptr->std_phi[124];
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_ERR_126 = TOI_DS_Stream_Ptr->std_phi[125];
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_ERR_127 = TOI_DS_Stream_Ptr->std_phi[126];
   data_ptr.SRR_RL_DETECTION_125_128.DET_ELEVATION_ERR_128 = TOI_DS_Stream_Ptr->std_phi[127];

   data_ptr.SRR_RL_DETECTION_125_128.DET_IDM_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_IDM_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_IDM_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_IDM_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_125_128.DET_MTD_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_MTD_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_MTD_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_MTD_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_125_128.DET_PROB_1STAZHYPO_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_PROB_1STAZHYPO_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_PROB_1STAZHYPO_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_PROB_1STAZHYPO_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_ERR_125 = TOI_DS_Stream_Ptr->std_ran[124];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_ERR_126 = TOI_DS_Stream_Ptr->std_ran[125];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_ERR_127 = TOI_DS_Stream_Ptr->std_ran[126];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_ERR_128 = TOI_DS_Stream_Ptr->std_ran[127];

   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_125 = af_target_report_ptr[124].vel;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_126 = af_target_report_ptr[125].vel;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_127 = af_target_report_ptr[126].vel;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_128 = af_target_report_ptr[127].vel;

   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_125 = TOI_DS_Stream_Ptr->std_vel[124];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_126 = TOI_DS_Stream_Ptr->std_vel[125];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_127 = TOI_DS_Stream_Ptr->std_vel[126];
   data_ptr.SRR_RL_DETECTION_125_128.DET_RANGE_VELOCITY_ERR_128 = TOI_DS_Stream_Ptr->std_vel[127];

   data_ptr.SRR_RL_DETECTION_125_128.DET_RCS_125 = af_target_report_ptr[124].rcs;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RCS_126 = af_target_report_ptr[125].rcs;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RCS_127 = af_target_report_ptr[126].rcs;
   data_ptr.SRR_RL_DETECTION_125_128.DET_RCS_128 = af_target_report_ptr[127].rcs;

   data_ptr.SRR_RL_DETECTION_125_128.DET_SNR_125 = af_target_report_ptr[124].snr;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SNR_126 = af_target_report_ptr[125].snr;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SNR_127 = af_target_report_ptr[126].snr;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SNR_128 = af_target_report_ptr[127].snr;

   data_ptr.SRR_RL_DETECTION_125_128.DET_SUPER_RES_TARGET_125 = af_target_report_ptr[124].f_superres_target;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SUPER_RES_TARGET_126 = af_target_report_ptr[125].f_superres_target;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SUPER_RES_TARGET_127 = af_target_report_ptr[126].f_superres_target;
   data_ptr.SRR_RL_DETECTION_125_128.DET_SUPER_RES_TARGET_128 = af_target_report_ptr[127].f_superres_target;

   data_ptr.SRR_RL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_125 = 0;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_126 = 0;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_127 = 0;
   data_ptr.SRR_RL_DETECTION_125_128.DET_BELOW_RAIN_THOLD_128 = 0;

   data_ptr.SRR_RL_DETECTION_125_128.DET_HVC_FLAG_125 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_HVC_FLAG_126 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_HVC_FLAG_127 = CAN_SIG_NOT_IMPLEMENTED;
   data_ptr.SRR_RL_DETECTION_125_128.DET_HVC_FLAG_128 = CAN_SIG_NOT_IMPLEMENTED;

   data_ptr.SRR_RL_DETECTION_125_128.DET_MH_CYCLE_COUNTER_125_128   = 0;
   data_ptr.SRR_RL_DETECTION_125_128.DET_MH_CRC16_125_128           = 0;
   data_ptr.SRR_RL_DETECTION_125_128.DET_MH_SCAN_INDEX_4LSB_125_128 = 0;

   temp_sig = ipc_d2m->payload.Bsis_IPC_Output.bsis_instance.core_output.bsis_alert_level[0];
   if (temp_sig > 0U)
   {
      data_ptr.SRR_RL_BSD1_B0.BlindSpotDetectionState             = COLLISION_WARNING_ACTIVE;
      data_ptr.SRR_RL_prop_ADAS_BSIS_info.BlindSpotDetectionState = COLLISION_WARNING_ACTIVE;
   }
   else
   {
      data_ptr.SRR_RL_BSD1_B0.BlindSpotDetectionState             = SYSTEM_READY_ACTIVATED;
      data_ptr.SRR_RL_prop_ADAS_BSIS_info.BlindSpotDetectionState = SYSTEM_READY_ACTIVATED;
   }

   RL_BlindSpotDetectionState = data_ptr.SRR_RL_BSD1_B0.BlindSpotDetectionState;

   data_ptr.SRR_RL_BSD1_B0.BlindSpotCollisionWarningLevel =
      ipc_d2m->payload.Bsis_IPC_Output.bsis_instance.core_output.bsis_alert_level[0];

   RL_BlindSpotDetectionState = data_ptr.SRR_RL_prop_ADAS_BSIS_info.BlindSpotDetectionState;

   data_ptr.SRR_RL_prop_ADAS_BSIS_info.BlindSpotCollisionWarningLevel =
      ipc_d2m->payload.Bsis_IPC_Output.bsis_instance.core_output.bsis_alert_level[0];
}

void encode_FLR_messages(void)
{
   encode_message_FLR_CAPABILITY(&e_ptr.FLR_CAPABILITY, &data_ptr.FLR_CAPABILITY);
   encode_message_FLR_ALIGNMENT_STATUS_001(&e_ptr.FLR_ALIGNMENT_STATUS_001, &data_ptr.FLR_ALIGNMENT_STATUS_001);
   encode_message_FLR_ALIGNMENT_STATUS_002(&e_ptr.FLR_ALIGNMENT_STATUS_002, &data_ptr.FLR_ALIGNMENT_STATUS_002);
   encode_message_FLR_DETECTION_001_004(&e_ptr.FLR_DETECTION_001_004, &data_ptr.FLR_DETECTION_001_004);
   encode_message_FLR_STATUS_001(&e_ptr.FLR_STATUS_001, &data_ptr.FLR_STATUS_001);
   encode_message_FLR_STATUS_002(&e_ptr.FLR_STATUS_002, &data_ptr.FLR_STATUS_002);
   encode_message_FLR_HEADER_001(&e_ptr.FLR_HEADER_001, &data_ptr.FLR_HEADER_001);
   encode_message_FLR_XCP_CTO_REQ(&e_ptr.FLR_XCP_CTO_REQ, &data_ptr.FLR_XCP_CTO_REQ);
   encode_message_FLR_XCP_CTO_RESP(&e_ptr.FLR_XCP_CTO_RESP, &data_ptr.FLR_XCP_CTO_RESP);
   encode_message_FLR_XCP_DAQ_RESP(&e_ptr.FLR_XCP_DAQ_RESP, &data_ptr.FLR_XCP_DAQ_RESP);
   encode_message_FLR_DETECTION_005_008(&e_ptr.FLR_DETECTION_005_008, &data_ptr.FLR_DETECTION_005_008);
   encode_message_FLR_DETECTION_009_012(&e_ptr.FLR_DETECTION_009_012, &data_ptr.FLR_DETECTION_009_012);
   encode_message_FLR_DETECTION_013_016(&e_ptr.FLR_DETECTION_013_016, &data_ptr.FLR_DETECTION_013_016);
   encode_message_FLR_DETECTION_017_020(&e_ptr.FLR_DETECTION_017_020, &data_ptr.FLR_DETECTION_017_020);
   encode_message_FLR_DETECTION_021_024(&e_ptr.FLR_DETECTION_021_024, &data_ptr.FLR_DETECTION_021_024);
   encode_message_FLR_DETECTION_025_028(&e_ptr.FLR_DETECTION_025_028, &data_ptr.FLR_DETECTION_025_028);
   encode_message_FLR_DETECTION_029_032(&e_ptr.FLR_DETECTION_029_032, &data_ptr.FLR_DETECTION_029_032);
   encode_message_FLR_DETECTION_033_036(&e_ptr.FLR_DETECTION_033_036, &data_ptr.FLR_DETECTION_033_036);
   encode_message_FLR_DETECTION_037_040(&e_ptr.FLR_DETECTION_037_040, &data_ptr.FLR_DETECTION_037_040);
   encode_message_FLR_DETECTION_041_044(&e_ptr.FLR_DETECTION_041_044, &data_ptr.FLR_DETECTION_041_044);
   encode_message_FLR_DETECTION_045_048(&e_ptr.FLR_DETECTION_045_048, &data_ptr.FLR_DETECTION_045_048);
   encode_message_FLR_DETECTION_049_052(&e_ptr.FLR_DETECTION_049_052, &data_ptr.FLR_DETECTION_049_052);
   encode_message_FLR_DETECTION_053_056(&e_ptr.FLR_DETECTION_053_056, &data_ptr.FLR_DETECTION_053_056);
   encode_message_FLR_DETECTION_057_060(&e_ptr.FLR_DETECTION_057_060, &data_ptr.FLR_DETECTION_057_060);
   encode_message_FLR_DETECTION_061_064(&e_ptr.FLR_DETECTION_061_064, &data_ptr.FLR_DETECTION_061_064);
   encode_message_FLR_DETECTION_065_068(&e_ptr.FLR_DETECTION_065_068, &data_ptr.FLR_DETECTION_065_068);
   encode_message_FLR_DETECTION_069_072(&e_ptr.FLR_DETECTION_069_072, &data_ptr.FLR_DETECTION_069_072);
   encode_message_FLR_DETECTION_073_076(&e_ptr.FLR_DETECTION_073_076, &data_ptr.FLR_DETECTION_073_076);
   encode_message_FLR_DETECTION_077_080(&e_ptr.FLR_DETECTION_077_080, &data_ptr.FLR_DETECTION_077_080);
   encode_message_FLR_DETECTION_081_084(&e_ptr.FLR_DETECTION_081_084, &data_ptr.FLR_DETECTION_081_084);
   encode_message_FLR_DETECTION_085_088(&e_ptr.FLR_DETECTION_085_088, &data_ptr.FLR_DETECTION_085_088);
   encode_message_FLR_DETECTION_089_092(&e_ptr.FLR_DETECTION_089_092, &data_ptr.FLR_DETECTION_089_092);
   encode_message_FLR_DETECTION_093_096(&e_ptr.FLR_DETECTION_093_096, &data_ptr.FLR_DETECTION_093_096);
   encode_message_FLR_DETECTION_097_100(&e_ptr.FLR_DETECTION_097_100, &data_ptr.FLR_DETECTION_097_100);
   encode_message_FLR_DETECTION_101_104(&e_ptr.FLR_DETECTION_101_104, &data_ptr.FLR_DETECTION_101_104);
   encode_message_FLR_DETECTION_105_108(&e_ptr.FLR_DETECTION_105_108, &data_ptr.FLR_DETECTION_105_108);
   encode_message_FLR_DETECTION_109_112(&e_ptr.FLR_DETECTION_109_112, &data_ptr.FLR_DETECTION_109_112);
   encode_message_FLR_DETECTION_113_116(&e_ptr.FLR_DETECTION_113_116, &data_ptr.FLR_DETECTION_113_116);
   encode_message_FLR_DETECTION_117_120(&e_ptr.FLR_DETECTION_117_120, &data_ptr.FLR_DETECTION_117_120);
   encode_message_FLR_DETECTION_121_124(&e_ptr.FLR_DETECTION_121_124, &data_ptr.FLR_DETECTION_121_124);
   encode_message_FLR_DETECTION_125_128_(&e_ptr.FLR_DETECTION_125_128_, &data_ptr.FLR_DETECTION_125_128_);
}

void encode_FLR_VCAN_messages(void)
{
   encode_message_BSD1_VCAN(&vcan_e_ptr.BSD1, &vcan_data_ptr.BSD1);
   encode_message_MOIS(&vcan_e_ptr.MOIS, &vcan_data_ptr.MOIS);
   encode_message_prop_ADAS_MOIS_BSIS_info(&vcan_e_ptr.prop_ADAS_MOIS_BSIS_info, &vcan_data_ptr.prop_ADAS_MOIS_BSIS_info);
}

void encode_Front_messages(void)
{
   encode_message_SRR_FL_ALIGNMENT_STATUS_002(&e_ptr.SRR_FL_ALIGNMENT_STATUS_002, &data_ptr.SRR_FL_ALIGNMENT_STATUS_002);
   encode_message_SRR_FL_ALIGNMENT_STATUS_001(&e_ptr.SRR_FL_ALIGNMENT_STATUS_001, &data_ptr.SRR_FL_ALIGNMENT_STATUS_001);
   encode_message_SRR_FL_CAPABILITY(&e_ptr.SRR_FL_CAPABILITY, &data_ptr.SRR_FL_CAPABILITY);
   encode_message_SRR_FL_DETECTION_001_004(&e_ptr.SRR_FL_DETECTION_001_004, &data_ptr.SRR_FL_DETECTION_001_004);
   encode_message_SRR_FL_DETECTION_005_008(&e_ptr.SRR_FL_DETECTION_005_008, &data_ptr.SRR_FL_DETECTION_005_008);
   encode_message_SRR_FL_DETECTION_009_012(&e_ptr.SRR_FL_DETECTION_009_012, &data_ptr.SRR_FL_DETECTION_009_012);
   encode_message_SRR_FL_DETECTION_013_016(&e_ptr.SRR_FL_DETECTION_013_016, &data_ptr.SRR_FL_DETECTION_013_016);
   encode_message_SRR_FL_DETECTION_017_020(&e_ptr.SRR_FL_DETECTION_017_020, &data_ptr.SRR_FL_DETECTION_017_020);
   encode_message_SRR_FL_DETECTION_021_024(&e_ptr.SRR_FL_DETECTION_021_024, &data_ptr.SRR_FL_DETECTION_021_024);
   encode_message_SRR_FL_DETECTION_025_028(&e_ptr.SRR_FL_DETECTION_025_028, &data_ptr.SRR_FL_DETECTION_025_028);
   encode_message_SRR_FL_DETECTION_029_032(&e_ptr.SRR_FL_DETECTION_029_032, &data_ptr.SRR_FL_DETECTION_029_032);
   encode_message_SRR_FL_DETECTION_033_036(&e_ptr.SRR_FL_DETECTION_033_036, &data_ptr.SRR_FL_DETECTION_033_036);
   encode_message_SRR_FL_DETECTION_037_040(&e_ptr.SRR_FL_DETECTION_037_040, &data_ptr.SRR_FL_DETECTION_037_040);
   encode_message_SRR_FL_DETECTION_041_044(&e_ptr.SRR_FL_DETECTION_041_044, &data_ptr.SRR_FL_DETECTION_041_044);
   encode_message_SRR_FL_DETECTION_045_048(&e_ptr.SRR_FL_DETECTION_045_048, &data_ptr.SRR_FL_DETECTION_045_048);
   encode_message_SRR_FL_DETECTION_049_052(&e_ptr.SRR_FL_DETECTION_049_052, &data_ptr.SRR_FL_DETECTION_049_052);
   encode_message_SRR_FL_DETECTION_053_056(&e_ptr.SRR_FL_DETECTION_053_056, &data_ptr.SRR_FL_DETECTION_053_056);
   encode_message_SRR_FL_DETECTION_057_060(&e_ptr.SRR_FL_DETECTION_057_060, &data_ptr.SRR_FL_DETECTION_057_060);
   encode_message_SRR_FL_DETECTION_061_064(&e_ptr.SRR_FL_DETECTION_061_064, &data_ptr.SRR_FL_DETECTION_061_064);
   encode_message_SRR_FL_DETECTION_065_068(&e_ptr.SRR_FL_DETECTION_065_068, &data_ptr.SRR_FL_DETECTION_065_068);
   encode_message_SRR_FL_DETECTION_069_072(&e_ptr.SRR_FL_DETECTION_069_072, &data_ptr.SRR_FL_DETECTION_069_072);
   encode_message_SRR_FL_DETECTION_073_076(&e_ptr.SRR_FL_DETECTION_073_076, &data_ptr.SRR_FL_DETECTION_073_076);
   encode_message_SRR_FL_DETECTION_077_080(&e_ptr.SRR_FL_DETECTION_077_080, &data_ptr.SRR_FL_DETECTION_077_080);
   encode_message_SRR_FL_DETECTION_081_084(&e_ptr.SRR_FL_DETECTION_081_084, &data_ptr.SRR_FL_DETECTION_081_084);
   encode_message_SRR_FL_DETECTION_085_088(&e_ptr.SRR_FL_DETECTION_085_088, &data_ptr.SRR_FL_DETECTION_085_088);
   encode_message_SRR_FL_DETECTION_089_092(&e_ptr.SRR_FL_DETECTION_089_092, &data_ptr.SRR_FL_DETECTION_089_092);
   encode_message_SRR_FL_DETECTION_093_096(&e_ptr.SRR_FL_DETECTION_093_096, &data_ptr.SRR_FL_DETECTION_093_096);
   encode_message_SRR_FL_DETECTION_097_100(&e_ptr.SRR_FL_DETECTION_097_100, &data_ptr.SRR_FL_DETECTION_097_100);
   encode_message_SRR_FL_DETECTION_101_104(&e_ptr.SRR_FL_DETECTION_101_104, &data_ptr.SRR_FL_DETECTION_101_104);
   encode_message_SRR_FL_DETECTION_105_108(&e_ptr.SRR_FL_DETECTION_105_108, &data_ptr.SRR_FL_DETECTION_105_108);
   encode_message_SRR_FL_DETECTION_109_112(&e_ptr.SRR_FL_DETECTION_109_112, &data_ptr.SRR_FL_DETECTION_109_112);
   encode_message_SRR_FL_DETECTION_113_116(&e_ptr.SRR_FL_DETECTION_113_116, &data_ptr.SRR_FL_DETECTION_113_116);
   encode_message_SRR_FL_DETECTION_117_120(&e_ptr.SRR_FL_DETECTION_117_120, &data_ptr.SRR_FL_DETECTION_117_120);
   encode_message_SRR_FL_DETECTION_121_124(&e_ptr.SRR_FL_DETECTION_121_124, &data_ptr.SRR_FL_DETECTION_121_124);
   encode_message_SRR_FL_DETECTION_125_128(&e_ptr.SRR_FL_DETECTION_125_128, &data_ptr.SRR_FL_DETECTION_125_128);
   encode_message_SRR_FL_HEADER_001(&e_ptr.SRR_FL_HEADER_001, &data_ptr.SRR_FL_HEADER_001);
   encode_message_SRR_FL_STATUS_001(&e_ptr.SRR_FL_STATUS_001, &data_ptr.SRR_FL_STATUS_001);
   encode_message_SRR_FL_STATUS_002(&e_ptr.SRR_FL_STATUS_002, &data_ptr.SRR_FL_STATUS_002);
   encode_message_SRR_FL_XCP_CTO_REQ(&e_ptr.SRR_FL_XCP_CTO_REQ, &data_ptr.SRR_FL_XCP_CTO_REQ);
   encode_message_SRR_FL_XCP_CTO_RESP(&e_ptr.SRR_FL_XCP_CTO_RESP, &data_ptr.SRR_FL_XCP_CTO_RESP);
   encode_message_SRR_FL_XCP_DAQ_RESP(&e_ptr.SRR_FL_XCP_DAQ_RESP, &data_ptr.SRR_FL_XCP_DAQ_RESP);
}

void encode_Rear_messages(void)
{
   encode_message_SRR_RL_ALIGNMENT_STATUS_002(&e_ptr.SRR_RL_ALIGNMENT_STATUS_002, &data_ptr.SRR_RL_ALIGNMENT_STATUS_002);
   encode_message_SRR_RL_ALIGNMENT_STATUS_001(&e_ptr.SRR_RL_ALIGNMENT_STATUS_001, &data_ptr.SRR_RL_ALIGNMENT_STATUS_001);
   encode_message_SRR_RL_CAPABILITY(&e_ptr.SRR_RL_CAPABILITY, &data_ptr.SRR_RL_CAPABILITY);
   encode_message_SRR_RL_DETECTION_001_004(&e_ptr.SRR_RL_DETECTION_001_004, &data_ptr.SRR_RL_DETECTION_001_004);
   encode_message_SRR_RL_DETECTION_005_008(&e_ptr.SRR_RL_DETECTION_005_008, &data_ptr.SRR_RL_DETECTION_005_008);
   encode_message_SRR_RL_DETECTION_009_012(&e_ptr.SRR_RL_DETECTION_009_012, &data_ptr.SRR_RL_DETECTION_009_012);
   encode_message_SRR_RL_DETECTION_013_016(&e_ptr.SRR_RL_DETECTION_013_016, &data_ptr.SRR_RL_DETECTION_013_016);
   encode_message_SRR_RL_DETECTION_017_020(&e_ptr.SRR_RL_DETECTION_017_020, &data_ptr.SRR_RL_DETECTION_017_020);
   encode_message_SRR_RL_DETECTION_021_024(&e_ptr.SRR_RL_DETECTION_021_024, &data_ptr.SRR_RL_DETECTION_021_024);
   encode_message_SRR_RL_DETECTION_025_028(&e_ptr.SRR_RL_DETECTION_025_028, &data_ptr.SRR_RL_DETECTION_025_028);
   encode_message_SRR_RL_DETECTION_029_032(&e_ptr.SRR_RL_DETECTION_029_032, &data_ptr.SRR_RL_DETECTION_029_032);
   encode_message_SRR_RL_DETECTION_033_036(&e_ptr.SRR_RL_DETECTION_033_036, &data_ptr.SRR_RL_DETECTION_033_036);
   encode_message_SRR_RL_DETECTION_037_040(&e_ptr.SRR_RL_DETECTION_037_040, &data_ptr.SRR_RL_DETECTION_037_040);
   encode_message_SRR_RL_DETECTION_041_044(&e_ptr.SRR_RL_DETECTION_041_044, &data_ptr.SRR_RL_DETECTION_041_044);
   encode_message_SRR_RL_DETECTION_045_048(&e_ptr.SRR_RL_DETECTION_045_048, &data_ptr.SRR_RL_DETECTION_045_048);
   encode_message_SRR_RL_DETECTION_049_052(&e_ptr.SRR_RL_DETECTION_049_052, &data_ptr.SRR_RL_DETECTION_049_052);
   encode_message_SRR_RL_DETECTION_053_056(&e_ptr.SRR_RL_DETECTION_053_056, &data_ptr.SRR_RL_DETECTION_053_056);
   encode_message_SRR_RL_DETECTION_057_060(&e_ptr.SRR_RL_DETECTION_057_060, &data_ptr.SRR_RL_DETECTION_057_060);
   encode_message_SRR_RL_DETECTION_061_064(&e_ptr.SRR_RL_DETECTION_061_064, &data_ptr.SRR_RL_DETECTION_061_064);
   encode_message_SRR_RL_DETECTION_065_068(&e_ptr.SRR_RL_DETECTION_065_068, &data_ptr.SRR_RL_DETECTION_065_068);
   encode_message_SRR_RL_DETECTION_069_072(&e_ptr.SRR_RL_DETECTION_069_072, &data_ptr.SRR_RL_DETECTION_069_072);
   encode_message_SRR_RL_DETECTION_073_076(&e_ptr.SRR_RL_DETECTION_073_076, &data_ptr.SRR_RL_DETECTION_073_076);
   encode_message_SRR_RL_DETECTION_077_080(&e_ptr.SRR_RL_DETECTION_077_080, &data_ptr.SRR_RL_DETECTION_077_080);
   encode_message_SRR_RL_DETECTION_081_084(&e_ptr.SRR_RL_DETECTION_081_084, &data_ptr.SRR_RL_DETECTION_081_084);
   encode_message_SRR_RL_DETECTION_085_088(&e_ptr.SRR_RL_DETECTION_085_088, &data_ptr.SRR_RL_DETECTION_085_088);
   encode_message_SRR_RL_DETECTION_089_092(&e_ptr.SRR_RL_DETECTION_089_092, &data_ptr.SRR_RL_DETECTION_089_092);
   encode_message_SRR_RL_DETECTION_093_096(&e_ptr.SRR_RL_DETECTION_093_096, &data_ptr.SRR_RL_DETECTION_093_096);
   encode_message_SRR_RL_DETECTION_097_100(&e_ptr.SRR_RL_DETECTION_097_100, &data_ptr.SRR_RL_DETECTION_097_100);
   encode_message_SRR_RL_DETECTION_101_104(&e_ptr.SRR_RL_DETECTION_101_104, &data_ptr.SRR_RL_DETECTION_101_104);
   encode_message_SRR_RL_DETECTION_105_108(&e_ptr.SRR_RL_DETECTION_105_108, &data_ptr.SRR_RL_DETECTION_105_108);
   encode_message_SRR_RL_DETECTION_109_112(&e_ptr.SRR_RL_DETECTION_109_112, &data_ptr.SRR_RL_DETECTION_109_112);
   encode_message_SRR_RL_DETECTION_113_116(&e_ptr.SRR_RL_DETECTION_113_116, &data_ptr.SRR_RL_DETECTION_113_116);
   encode_message_SRR_RL_DETECTION_117_120(&e_ptr.SRR_RL_DETECTION_117_120, &data_ptr.SRR_RL_DETECTION_117_120);
   encode_message_SRR_RL_DETECTION_121_124(&e_ptr.SRR_RL_DETECTION_121_124, &data_ptr.SRR_RL_DETECTION_121_124);
   encode_message_SRR_RL_DETECTION_125_128(&e_ptr.SRR_RL_DETECTION_125_128, &data_ptr.SRR_RL_DETECTION_125_128);
   encode_message_SRR_RL_HEADER_001(&e_ptr.SRR_RL_HEADER_001, &data_ptr.SRR_RL_HEADER_001);
   encode_message_SRR_RL_STATUS_001(&e_ptr.SRR_RL_STATUS_001, &data_ptr.SRR_RL_STATUS_001);
   encode_message_SRR_RL_STATUS_002(&e_ptr.SRR_RL_STATUS_002, &data_ptr.SRR_RL_STATUS_002);
   encode_message_SRR_RL_XCP_CTO_REQ(&e_ptr.SRR_RL_XCP_CTO_REQ, &data_ptr.SRR_RL_XCP_CTO_REQ);
   encode_message_SRR_RL_XCP_CTO_RESP(&e_ptr.SRR_RL_XCP_CTO_RESP, &data_ptr.SRR_RL_XCP_CTO_RESP);
   encode_message_SRR_RL_XCP_DAQ_RESP(&e_ptr.SRR_RL_XCP_DAQ_RESP, &data_ptr.SRR_RL_XCP_DAQ_RESP);
   encode_message_SRR_RL_BSD1_B0(&e_ptr.SRR_RL_BSD1_B0, &data_ptr.SRR_RL_BSD1_B0);
}

void add_FLR_DETECTION_001_004(FLR_DETECTION_001_004_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_001_004, 64, buffer);
}

void add_FLR_DETECTION_005_008(FLR_DETECTION_005_008_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_005_008, 64, buffer);
}

void add_FLR_DETECTION_009_012(FLR_DETECTION_009_012_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_009_012, 64, buffer);
}

void add_FLR_DETECTION_013_016(FLR_DETECTION_013_016_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_013_016, 64, buffer);
}

void add_FLR_DETECTION_017_020(FLR_DETECTION_017_020_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_017_020, 64, buffer);
}

void add_FLR_DETECTION_021_024(FLR_DETECTION_021_024_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_021_024, 64, buffer);
}

void add_FLR_DETECTION_025_028(FLR_DETECTION_025_028_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_025_028, 64, buffer);
}

void add_FLR_DETECTION_029_032(FLR_DETECTION_029_032_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_029_032, 64, buffer);
}

void add_FLR_DETECTION_033_036(FLR_DETECTION_033_036_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_033_036, 64, buffer);
}

void add_FLR_DETECTION_037_040(FLR_DETECTION_037_040_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_037_040, 64, buffer);
}

void add_FLR_DETECTION_041_044(FLR_DETECTION_041_044_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_041_044, 64, buffer);
}

void add_FLR_DETECTION_045_048(FLR_DETECTION_045_048_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_045_048, 64, buffer);
}

void add_FLR_DETECTION_049_052(FLR_DETECTION_049_052_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_049_052, 64, buffer);
}

void add_FLR_DETECTION_053_056(FLR_DETECTION_053_056_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_053_056, 64, buffer);
}

void add_FLR_DETECTION_057_060(FLR_DETECTION_057_060_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_057_060, 64, buffer);
}

void add_FLR_DETECTION_061_064(FLR_DETECTION_061_064_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_061_064, 64, buffer);
}

void add_FLR_DETECTION_065_068(FLR_DETECTION_065_068_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_065_068, 64, buffer);
}

void add_FLR_DETECTION_069_072(FLR_DETECTION_069_072_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_069_072, 64, buffer);
}

void add_FLR_DETECTION_073_076(FLR_DETECTION_073_076_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_073_076, 64, buffer);
}

void add_FLR_DETECTION_077_080(FLR_DETECTION_077_080_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_077_080, 64, buffer);
}

void add_FLR_DETECTION_081_084(FLR_DETECTION_081_084_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_081_084, 64, buffer);
}

void add_FLR_DETECTION_085_088(FLR_DETECTION_085_088_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_085_088, 64, buffer);
}

void add_FLR_DETECTION_089_092(FLR_DETECTION_089_092_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_089_092, 64, buffer);
}

void add_FLR_DETECTION_093_096(FLR_DETECTION_093_096_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_093_096, 64, buffer);
}

void add_FLR_DETECTION_097_100(FLR_DETECTION_097_100_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_097_100, 64, buffer);
}

void add_FLR_DETECTION_101_104(FLR_DETECTION_101_104_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_101_104, 64, buffer);
}

void add_FLR_DETECTION_105_108(FLR_DETECTION_105_108_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_105_108, 64, buffer);
}

void add_FLR_DETECTION_109_112(FLR_DETECTION_109_112_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_109_112, 64, buffer);
}

void add_FLR_DETECTION_113_116(FLR_DETECTION_113_116_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_113_116, 64, buffer);
}

void add_FLR_DETECTION_117_120(FLR_DETECTION_117_120_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_117_120, 64, buffer);
}

void add_FLR_DETECTION_121_124(FLR_DETECTION_121_124_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_121_124, 64, buffer);
}

void add_FLR_DETECTION_125_128(FLR_DETECTION_125_128__encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_DETECTION_125_128, 64, buffer);
}

void add_FCM_IFV_SWVersion(FCM_IFV_SWVersion_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FCM_IFV_SWVersion, 64, buffer);
}

void add_FLR_DIAG_REQ_PHYS_OTA(FLR_DIAG_REQ_PHYS_OTA_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, 0x18DAD0F4, 64, buffer);
}

void add_FLR_DIAG_RESP_PHYS_OTA(FLR_DIAG_RESP_PHYS_OTA_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, 0x18DAF4D0, 64, buffer);
}

void add_FLR_HEADER_001(FLR_HEADER_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_HEADER_001, 64, buffer);
}

void add_FLR_STATUS_001(FLR_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_STATUS_001, 64, buffer);
}

void add_FLR_STATUS_002(FLR_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_STATUS_002, 64, buffer);
}

void add_FLR_XCP_CTO_REQ(FLR_XCP_CTO_REQ_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_XCP_CTO_REQ, 64, buffer);
}

void add_FLR_XCP_CTO_RESP(FLR_XCP_CTO_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_XCP_CTO_RESP, 64, buffer);
}

void add_FLR_XCP_DAQ_RESP(FLR_XCP_DAQ_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_XCP_DAQ_RESP, 64, buffer);
}

void add_FLR_CAPABILITY(FLR_CAPABILITY_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_CAPABILITY, 64, buffer);
}

void add_FLR_ALIGNMENT_STATUS_001(FLR_ALIGNMENT_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_ALIGNMENT_STATUS_001, 64, buffer);
}

void add_FLR_ALIGNMENT_STATUS_002(FLR_ALIGNMENT_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLR, FLR_ALIGNMENT_STATUS_002, 64, buffer);
}

// FLR_VCAN SENSOR
void add_BSD1(BSD1_VCAN_encoded_msg_t *vcan_e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, vcan_e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLRVcan, BSD1, 64, buffer);
}

void add_MOIS(MOIS_encoded_msg_t *vcan_e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, vcan_e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLRVcan, MOIS, 64, buffer);
}

void add_prop_ADAS_MOIS_BSIS_info(prop_ADAS_MOIS_BSIS_info_encoded_msg_t *vcan_e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, vcan_e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FLRVcan, prop_ADAS_MOIS_BSIS_info, 64, buffer);
}

// FL SENSOR
void add_SRR_FL_ALIGNMENT_STATUS_002(SRR_FL_ALIGNMENT_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_ALIGNMENT_STATUS_002, 64, buffer);
}

void add_SRR_FL_ALIGNMENT_STATUS_001(SRR_FL_ALIGNMENT_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_ALIGNMENT_STATUS_001, 64, buffer);
}

void add_SRR_FL_CAPABILITY(SRR_FL_CAPABILITY_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_CAPABILITY, 64, buffer);
}

// Detection signals
void add_SRR_FL_DETECTION_001_004(SRR_FL_DETECTION_001_004_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_001_004 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_001_004);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_001_004, 64, buffer);
}

void add_SRR_FL_DETECTION_005_008(SRR_FL_DETECTION_005_008_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_005_008 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_005_008);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_005_008, 64, buffer);
}

void add_SRR_FL_DETECTION_009_012(SRR_FL_DETECTION_009_012_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_009_012 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_009_012);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_009_012, 64, buffer);
}

void add_SRR_FL_DETECTION_013_016(SRR_FL_DETECTION_013_016_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_013_016 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_013_016);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_013_016, 64, buffer);
}

void add_SRR_FL_DETECTION_017_020(SRR_FL_DETECTION_017_020_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_017_020 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_017_020);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_017_020, 64, buffer);
}

void add_SRR_FL_DETECTION_021_024(SRR_FL_DETECTION_021_024_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_021_024 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_021_024);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_021_024, 64, buffer);
}

void add_SRR_FL_DETECTION_025_028(SRR_FL_DETECTION_025_028_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_025_028 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_025_028);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_025_028, 64, buffer);
}

void add_SRR_FL_DETECTION_029_032(SRR_FL_DETECTION_029_032_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_029_032 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_029_032);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_029_032, 64, buffer);
}

void add_SRR_FL_DETECTION_033_036(SRR_FL_DETECTION_033_036_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_033_036 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_033_036);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_033_036, 64, buffer);
}

void add_SRR_FL_DETECTION_037_040(SRR_FL_DETECTION_037_040_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_037_040 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_037_040);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_037_040, 64, buffer);
}

void add_SRR_FL_DETECTION_041_044(SRR_FL_DETECTION_041_044_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_041_044 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_041_044);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_041_044, 64, buffer);
}

void add_SRR_FL_DETECTION_045_048(SRR_FL_DETECTION_045_048_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_045_048 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_045_048);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_045_048, 64, buffer);
}

void add_SRR_FL_DETECTION_049_052(SRR_FL_DETECTION_049_052_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_049_052 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_049_052);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_049_052, 64, buffer);
}

void add_SRR_FL_DETECTION_053_056(SRR_FL_DETECTION_053_056_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_053_056 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_053_056);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_053_056, 64, buffer);
}

void add_SRR_FL_DETECTION_057_060(SRR_FL_DETECTION_057_060_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_057_060 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_057_060);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_057_060, 64, buffer);
}

void add_SRR_FL_DETECTION_061_064(SRR_FL_DETECTION_061_064_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_061_064 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_061_064);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_061_064, 64, buffer);
}

void add_SRR_FL_DETECTION_065_068(SRR_FL_DETECTION_065_068_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_065_068 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_065_068);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_065_068, 64, buffer);
}

void add_SRR_FL_DETECTION_069_072(SRR_FL_DETECTION_069_072_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_069_072 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_069_072);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_069_072, 64, buffer);
}

void add_SRR_FL_DETECTION_073_076(SRR_FL_DETECTION_073_076_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_073_076 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_073_076);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_073_076, 64, buffer);
}

void add_SRR_FL_DETECTION_077_080(SRR_FL_DETECTION_077_080_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_077_080 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_077_080);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_077_080, 64, buffer);
}

void add_SRR_FL_DETECTION_081_084(SRR_FL_DETECTION_081_084_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_081_084 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_081_084);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_081_084, 64, buffer);
}

void add_SRR_FL_DETECTION_085_088(SRR_FL_DETECTION_085_088_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_085_088 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_085_088);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_085_088, 64, buffer);
}

void add_SRR_FL_DETECTION_089_092(SRR_FL_DETECTION_089_092_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_089_092 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_089_092);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_089_092, 64, buffer);
}

void add_SRR_FL_DETECTION_093_096(SRR_FL_DETECTION_093_096_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_093_096 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_093_096);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_093_096, 64, buffer);
}

void add_SRR_FL_DETECTION_097_100(SRR_FL_DETECTION_097_100_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_097_100 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_097_100);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_097_100, 64, buffer);
}

void add_SRR_FL_DETECTION_101_104(SRR_FL_DETECTION_101_104_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_101_104 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_101_104);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_101_104, 64, buffer);
}

void add_SRR_FL_DETECTION_105_108(SRR_FL_DETECTION_105_108_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_105_108 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_105_108);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_105_108, 64, buffer);
}

void add_SRR_FL_DETECTION_109_112(SRR_FL_DETECTION_109_112_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_109_112 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_109_112);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_109_112, 64, buffer);
}

void add_SRR_FL_DETECTION_113_116(SRR_FL_DETECTION_113_116_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_113_116 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_113_116);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_113_116, 64, buffer);
}

void add_SRR_FL_DETECTION_117_120(SRR_FL_DETECTION_117_120_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_117_120 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_117_120);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_117_120, 64, buffer);
}

void add_SRR_FL_DETECTION_121_124(SRR_FL_DETECTION_121_124_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_121_124 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_121_124);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_121_124, 64, buffer);
}

void add_SRR_FL_DETECTION_125_128(SRR_FL_DETECTION_125_128_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_FL_DETECTION_125_128 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_FL_DETECTION_125_128);

   Fill_CAN_buffer(can_channel_FL, SRR_FL_DETECTION_125_128, 64, buffer);
}

void add_SRR_FL_STATUS_001(SRR_FL_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_STATUS_001, 64, buffer);
}

void add_SRR_FL_STATUS_002(SRR_FL_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_STATUS_002, 64, buffer);
}

void add_SRR_FL_XCP_CTO_REQ(SRR_FL_XCP_CTO_REQ_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_XCP_CTO_REQ, 64, buffer);
}

void add_SRR_FL_XCP_CTO_RESP(SRR_FL_XCP_CTO_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_XCP_CTO_RESP, 64, buffer);
}

void add_SRR_FL_XCP_DAQ_RESP(SRR_FL_XCP_DAQ_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_XCP_DAQ_RESP, 64, buffer);
}

void add_SRR_FL_HEADER_001(SRR_FL_HEADER_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_FL, SRR_FL_HEADER_001, 64, buffer);
}

// REAR SENSOR
//  Alignment and capability signals
void add_SRR_RL_ALIGNMENT_STATUS_002(SRR_RL_ALIGNMENT_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_ALIGNMENT_STATUS_002, 64, buffer);
}

void add_SRR_RL_ALIGNMENT_STATUS_001(SRR_RL_ALIGNMENT_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_ALIGNMENT_STATUS_001, 64, buffer);
}

void add_SRR_RL_CAPABILITY(SRR_RL_CAPABILITY_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_CAPABILITY, 64, buffer);
}

// Detection signals
void add_SRR_RL_DETECTION_001_004(SRR_RL_DETECTION_001_004_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_001_004 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_001_004);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_001_004, 64, buffer);
}

void add_SRR_RL_DETECTION_005_008(SRR_RL_DETECTION_005_008_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_005_008 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_005_008);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_005_008, 64, buffer);
}

void add_SRR_RL_DETECTION_009_012(SRR_RL_DETECTION_009_012_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_009_012 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_009_012);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_009_012, 64, buffer);
}

void add_SRR_RL_DETECTION_013_016(SRR_RL_DETECTION_013_016_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_013_016 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_013_016);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_013_016, 64, buffer);
}

void add_SRR_RL_DETECTION_017_020(SRR_RL_DETECTION_017_020_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_017_020 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_017_020);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_017_020, 64, buffer);
}

void add_SRR_RL_DETECTION_021_024(SRR_RL_DETECTION_021_024_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_021_024 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_021_024);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_021_024, 64, buffer);
}

void add_SRR_RL_DETECTION_025_028(SRR_RL_DETECTION_025_028_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_025_028 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_025_028);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_025_028, 64, buffer);
}

void add_SRR_RL_DETECTION_029_032(SRR_RL_DETECTION_029_032_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_029_032 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_029_032);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_029_032, 64, buffer);
}

void add_SRR_RL_DETECTION_033_036(SRR_RL_DETECTION_033_036_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_033_036 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_033_036);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_033_036, 64, buffer);
}

void add_SRR_RL_DETECTION_037_040(SRR_RL_DETECTION_037_040_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_037_040 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_037_040);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_037_040, 64, buffer);
}

void add_SRR_RL_DETECTION_041_044(SRR_RL_DETECTION_041_044_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_041_044 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_041_044);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_041_044, 64, buffer);
}

void add_SRR_RL_DETECTION_045_048(SRR_RL_DETECTION_045_048_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_045_048 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_045_048);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_045_048, 64, buffer);
}

void add_SRR_RL_DETECTION_049_052(SRR_RL_DETECTION_049_052_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_049_052 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_049_052);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_049_052, 64, buffer);
}

void add_SRR_RL_DETECTION_053_056(SRR_RL_DETECTION_053_056_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_053_056 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_053_056);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_053_056, 64, buffer);
}

void add_SRR_RL_DETECTION_057_060(SRR_RL_DETECTION_057_060_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_057_060 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_057_060);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_057_060, 64, buffer);
}

void add_SRR_RL_DETECTION_061_064(SRR_RL_DETECTION_061_064_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_061_064 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_061_064);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_061_064, 64, buffer);
}

void add_SRR_RL_DETECTION_065_068(SRR_RL_DETECTION_065_068_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_065_068 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_065_068);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_065_068, 64, buffer);
}

void add_SRR_RL_DETECTION_069_072(SRR_RL_DETECTION_069_072_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_069_072 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_069_072);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_069_072, 64, buffer);
}

void add_SRR_RL_DETECTION_073_076(SRR_RL_DETECTION_073_076_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_073_076 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_073_076);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_073_076, 64, buffer);
}

void add_SRR_RL_DETECTION_077_080(SRR_RL_DETECTION_077_080_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_077_080 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_077_080);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_077_080, 64, buffer);
}

void add_SRR_RL_DETECTION_081_084(SRR_RL_DETECTION_081_084_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_081_084 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_081_084);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_081_084, 64, buffer);
}

void add_SRR_RL_DETECTION_085_088(SRR_RL_DETECTION_085_088_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_085_088 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_085_088);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_085_088, 64, buffer);
}

void add_SRR_RL_DETECTION_089_092(SRR_RL_DETECTION_089_092_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_089_092 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_089_092);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_089_092, 64, buffer);
}

void add_SRR_RL_DETECTION_093_096(SRR_RL_DETECTION_093_096_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_093_096 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_093_096);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_093_096, 64, buffer);
}

void add_SRR_RL_DETECTION_097_100(SRR_RL_DETECTION_097_100_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));

   // static uint8_t alive_SRR_RL_DETECTION_097_100 = 0;
   // CAN_Det_Patch(buffer, &alive_SRR_RL_DETECTION_097_100);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_097_100, 64, buffer);
}

void add_SRR_RL_DETECTION_101_104(SRR_RL_DETECTION_101_104_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_101_104 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_101_104);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_101_104, 64, buffer);
}

void add_SRR_RL_DETECTION_105_108(SRR_RL_DETECTION_105_108_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_105_108 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_105_108);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_105_108, 64, buffer);
}

void add_SRR_RL_DETECTION_109_112(SRR_RL_DETECTION_109_112_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_109_112 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_109_112);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_109_112, 64, buffer);
}

void add_SRR_RL_DETECTION_113_116(SRR_RL_DETECTION_113_116_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_113_116 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_113_116);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_113_116, 64, buffer);
}

void add_SRR_RL_DETECTION_117_120(SRR_RL_DETECTION_117_120_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_117_120 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_117_120);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_117_120, 64, buffer);
}

void add_SRR_RL_DETECTION_121_124(SRR_RL_DETECTION_121_124_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_121_124 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_121_124);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_121_124, 64, buffer);
}

void add_SRR_RL_DETECTION_125_128(SRR_RL_DETECTION_125_128_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   // static uint8_t alive_add_SRR_RL_DETECTION_125_128 = 0;
   // CAN_Det_Patch(buffer, &alive_add_SRR_RL_DETECTION_125_128);

   Fill_CAN_buffer(can_channel_RL, SRR_RL_DETECTION_125_128, 64, buffer);
}

void add_SRR_RL_HEADER_001(SRR_RL_HEADER_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_HEADER_001, 64, buffer);
}

void add_SRR_RL_STATUS_001(SRR_RL_STATUS_001_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_STATUS_001, 64, buffer);
}

void add_SRR_RL_STATUS_002(SRR_RL_STATUS_002_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_STATUS_002, 64, buffer);
}

void add_SRR_RL_XCP_CTO_REQ(SRR_RL_XCP_CTO_REQ_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_XCP_CTO_REQ, 64, buffer);
}

void add_SRR_RL_XCP_CTO_RESP(SRR_RL_XCP_CTO_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_XCP_CTO_RESP, 64, buffer);
}

void add_SRR_RL_XCP_DAQ_RESP(SRR_RL_XCP_DAQ_RESP_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_XCP_DAQ_RESP, 64, buffer);
}

void add_SRR_RL_BSD1_B0(SRR_RL_BSD1_B0_encoded_msg_t *e_ptr)
{
   memset(buffer, 0, sizeof(buffer));
   memcpy(buffer, e_ptr, sizeof(buffer));
   Fill_CAN_buffer(can_channel_RL, SRR_RL_BSD1_B0, 64, buffer);
}

void populate_FLR_can_signals(void)
{
   add_FLR_DETECTION_001_004(&e_ptr.FLR_DETECTION_001_004);
   add_FLR_DETECTION_005_008(&e_ptr.FLR_DETECTION_005_008);
   add_FLR_DETECTION_009_012(&e_ptr.FLR_DETECTION_009_012);
   add_FLR_DETECTION_013_016(&e_ptr.FLR_DETECTION_013_016);
   add_FLR_DETECTION_017_020(&e_ptr.FLR_DETECTION_017_020);
   add_FLR_DETECTION_021_024(&e_ptr.FLR_DETECTION_021_024);
   add_FLR_DETECTION_025_028(&e_ptr.FLR_DETECTION_025_028);
   add_FLR_DETECTION_029_032(&e_ptr.FLR_DETECTION_029_032);
   add_FLR_DETECTION_033_036(&e_ptr.FLR_DETECTION_033_036);
   add_FLR_DETECTION_037_040(&e_ptr.FLR_DETECTION_037_040);
   add_FLR_DETECTION_041_044(&e_ptr.FLR_DETECTION_041_044);
   add_FLR_DETECTION_045_048(&e_ptr.FLR_DETECTION_045_048);
   add_FLR_DETECTION_049_052(&e_ptr.FLR_DETECTION_049_052);
   add_FLR_DETECTION_053_056(&e_ptr.FLR_DETECTION_053_056);
   add_FLR_DETECTION_057_060(&e_ptr.FLR_DETECTION_057_060);
   add_FLR_DETECTION_061_064(&e_ptr.FLR_DETECTION_061_064);
   add_FLR_DETECTION_065_068(&e_ptr.FLR_DETECTION_065_068);
   add_FLR_DETECTION_069_072(&e_ptr.FLR_DETECTION_069_072);
   add_FLR_DETECTION_073_076(&e_ptr.FLR_DETECTION_073_076);
   add_FLR_DETECTION_077_080(&e_ptr.FLR_DETECTION_077_080);
   add_FLR_DETECTION_081_084(&e_ptr.FLR_DETECTION_081_084);
   add_FLR_DETECTION_085_088(&e_ptr.FLR_DETECTION_085_088);
   add_FLR_DETECTION_089_092(&e_ptr.FLR_DETECTION_089_092);
   add_FLR_DETECTION_093_096(&e_ptr.FLR_DETECTION_093_096);
   add_FLR_DETECTION_097_100(&e_ptr.FLR_DETECTION_097_100);
   add_FLR_DETECTION_101_104(&e_ptr.FLR_DETECTION_101_104);
   add_FLR_DETECTION_105_108(&e_ptr.FLR_DETECTION_105_108);
   add_FLR_DETECTION_109_112(&e_ptr.FLR_DETECTION_109_112);
   add_FLR_DETECTION_113_116(&e_ptr.FLR_DETECTION_113_116);
   add_FLR_DETECTION_117_120(&e_ptr.FLR_DETECTION_117_120);
   add_FLR_DETECTION_121_124(&e_ptr.FLR_DETECTION_121_124);
   add_FLR_DETECTION_125_128(&e_ptr.FLR_DETECTION_125_128_);
   add_FLR_DIAG_REQ_PHYS_OTA(&e_ptr.FLR_DIAG_REQ_PHYS_OTA);
   add_FLR_DIAG_RESP_PHYS_OTA(&e_ptr.FLR_DIAG_RESP_PHYS_OTA);
   add_FLR_HEADER_001(&e_ptr.FLR_HEADER_001);
   add_FLR_STATUS_001(&e_ptr.FLR_STATUS_001);
   add_FLR_STATUS_002(&e_ptr.FLR_STATUS_002);
   add_FLR_XCP_CTO_REQ(&e_ptr.FLR_XCP_CTO_REQ);
   add_FLR_XCP_CTO_RESP(&e_ptr.FLR_XCP_CTO_RESP);
   add_FLR_XCP_DAQ_RESP(&e_ptr.FLR_XCP_DAQ_RESP);
   add_FCM_IFV_SWVersion(&e_ptr.FCM_IFV_SWVersion);
   add_FLR_CAPABILITY(&e_ptr.FLR_CAPABILITY);
   add_FLR_ALIGNMENT_STATUS_001(&e_ptr.FLR_ALIGNMENT_STATUS_001);
   add_FLR_ALIGNMENT_STATUS_002(&e_ptr.FLR_ALIGNMENT_STATUS_002);
}

void populate_FLR_VCAN_can_signals(void)
{
   add_BSD1(&vcan_e_ptr.BSD1);
   add_MOIS(&vcan_e_ptr.MOIS);
   add_prop_ADAS_MOIS_BSIS_info(&vcan_e_ptr.prop_ADAS_MOIS_BSIS_info);
}

void populate_Front_can_signals()
{
   // Add alignment and capability signals
   add_SRR_FL_ALIGNMENT_STATUS_002(&e_ptr.SRR_FL_ALIGNMENT_STATUS_002);
   add_SRR_FL_ALIGNMENT_STATUS_001(&e_ptr.SRR_FL_ALIGNMENT_STATUS_001);
   add_SRR_FL_CAPABILITY(&e_ptr.SRR_FL_CAPABILITY);

   // Detection signals
   add_SRR_FL_DETECTION_001_004(&e_ptr.SRR_FL_DETECTION_001_004);
   add_SRR_FL_DETECTION_005_008(&e_ptr.SRR_FL_DETECTION_005_008);
   add_SRR_FL_DETECTION_009_012(&e_ptr.SRR_FL_DETECTION_009_012);
   add_SRR_FL_DETECTION_013_016(&e_ptr.SRR_FL_DETECTION_013_016);
   add_SRR_FL_DETECTION_017_020(&e_ptr.SRR_FL_DETECTION_017_020);
   add_SRR_FL_DETECTION_021_024(&e_ptr.SRR_FL_DETECTION_021_024);
   add_SRR_FL_DETECTION_025_028(&e_ptr.SRR_FL_DETECTION_025_028);
   add_SRR_FL_DETECTION_029_032(&e_ptr.SRR_FL_DETECTION_029_032);
   add_SRR_FL_DETECTION_033_036(&e_ptr.SRR_FL_DETECTION_033_036);
   add_SRR_FL_DETECTION_037_040(&e_ptr.SRR_FL_DETECTION_037_040);
   add_SRR_FL_DETECTION_041_044(&e_ptr.SRR_FL_DETECTION_041_044);
   add_SRR_FL_DETECTION_045_048(&e_ptr.SRR_FL_DETECTION_045_048);
   add_SRR_FL_DETECTION_049_052(&e_ptr.SRR_FL_DETECTION_049_052);
   add_SRR_FL_DETECTION_053_056(&e_ptr.SRR_FL_DETECTION_053_056);
   add_SRR_FL_DETECTION_057_060(&e_ptr.SRR_FL_DETECTION_057_060);
   add_SRR_FL_DETECTION_061_064(&e_ptr.SRR_FL_DETECTION_061_064);
   add_SRR_FL_DETECTION_065_068(&e_ptr.SRR_FL_DETECTION_065_068);
   add_SRR_FL_DETECTION_069_072(&e_ptr.SRR_FL_DETECTION_069_072);
   add_SRR_FL_DETECTION_073_076(&e_ptr.SRR_FL_DETECTION_073_076);
   add_SRR_FL_DETECTION_077_080(&e_ptr.SRR_FL_DETECTION_077_080);
   add_SRR_FL_DETECTION_081_084(&e_ptr.SRR_FL_DETECTION_081_084);
   add_SRR_FL_DETECTION_085_088(&e_ptr.SRR_FL_DETECTION_085_088);
   add_SRR_FL_DETECTION_089_092(&e_ptr.SRR_FL_DETECTION_089_092);
   add_SRR_FL_DETECTION_093_096(&e_ptr.SRR_FL_DETECTION_093_096);
   add_SRR_FL_DETECTION_097_100(&e_ptr.SRR_FL_DETECTION_097_100);
   add_SRR_FL_DETECTION_101_104(&e_ptr.SRR_FL_DETECTION_101_104);
   add_SRR_FL_DETECTION_105_108(&e_ptr.SRR_FL_DETECTION_105_108);
   add_SRR_FL_DETECTION_109_112(&e_ptr.SRR_FL_DETECTION_109_112);
   add_SRR_FL_DETECTION_113_116(&e_ptr.SRR_FL_DETECTION_113_116);
   add_SRR_FL_DETECTION_117_120(&e_ptr.SRR_FL_DETECTION_117_120);
   add_SRR_FL_DETECTION_121_124(&e_ptr.SRR_FL_DETECTION_121_124);
   add_SRR_FL_DETECTION_125_128(&e_ptr.SRR_FL_DETECTION_125_128);

   add_SRR_FL_HEADER_001(&e_ptr.SRR_FL_HEADER_001);

   add_SRR_FL_STATUS_001(&e_ptr.SRR_FL_STATUS_001);
   add_SRR_FL_STATUS_002(&e_ptr.SRR_FL_STATUS_002);
   add_SRR_FL_XCP_CTO_REQ(&e_ptr.SRR_FL_XCP_CTO_REQ);
   add_SRR_FL_XCP_CTO_RESP(&e_ptr.SRR_FL_XCP_CTO_RESP);
   add_SRR_FL_XCP_DAQ_RESP(&e_ptr.SRR_FL_XCP_DAQ_RESP);
}

void populate_Rear_can_signals()
{
   add_SRR_RL_ALIGNMENT_STATUS_002(&e_ptr.SRR_RL_ALIGNMENT_STATUS_002);
   add_SRR_RL_ALIGNMENT_STATUS_001(&e_ptr.SRR_RL_ALIGNMENT_STATUS_001);
   add_SRR_RL_CAPABILITY(&e_ptr.SRR_RL_CAPABILITY);
   add_SRR_RL_DETECTION_001_004(&e_ptr.SRR_RL_DETECTION_001_004);
   add_SRR_RL_DETECTION_005_008(&e_ptr.SRR_RL_DETECTION_005_008);
   add_SRR_RL_DETECTION_009_012(&e_ptr.SRR_RL_DETECTION_009_012);
   add_SRR_RL_DETECTION_013_016(&e_ptr.SRR_RL_DETECTION_013_016);
   add_SRR_RL_DETECTION_017_020(&e_ptr.SRR_RL_DETECTION_017_020);
   add_SRR_RL_DETECTION_021_024(&e_ptr.SRR_RL_DETECTION_021_024);
   add_SRR_RL_DETECTION_025_028(&e_ptr.SRR_RL_DETECTION_025_028);
   add_SRR_RL_DETECTION_029_032(&e_ptr.SRR_RL_DETECTION_029_032);
   add_SRR_RL_DETECTION_033_036(&e_ptr.SRR_RL_DETECTION_033_036);
   add_SRR_RL_DETECTION_037_040(&e_ptr.SRR_RL_DETECTION_037_040);
   add_SRR_RL_DETECTION_041_044(&e_ptr.SRR_RL_DETECTION_041_044);
   add_SRR_RL_DETECTION_045_048(&e_ptr.SRR_RL_DETECTION_045_048);
   add_SRR_RL_DETECTION_049_052(&e_ptr.SRR_RL_DETECTION_049_052);
   add_SRR_RL_DETECTION_053_056(&e_ptr.SRR_RL_DETECTION_053_056);
   add_SRR_RL_DETECTION_057_060(&e_ptr.SRR_RL_DETECTION_057_060);
   add_SRR_RL_DETECTION_061_064(&e_ptr.SRR_RL_DETECTION_061_064);
   add_SRR_RL_DETECTION_065_068(&e_ptr.SRR_RL_DETECTION_065_068);
   add_SRR_RL_DETECTION_069_072(&e_ptr.SRR_RL_DETECTION_069_072);
   add_SRR_RL_DETECTION_073_076(&e_ptr.SRR_RL_DETECTION_073_076);
   add_SRR_RL_DETECTION_077_080(&e_ptr.SRR_RL_DETECTION_077_080);
   add_SRR_RL_DETECTION_081_084(&e_ptr.SRR_RL_DETECTION_081_084);
   add_SRR_RL_DETECTION_085_088(&e_ptr.SRR_RL_DETECTION_085_088);
   add_SRR_RL_DETECTION_089_092(&e_ptr.SRR_RL_DETECTION_089_092);
   add_SRR_RL_DETECTION_093_096(&e_ptr.SRR_RL_DETECTION_093_096);
   add_SRR_RL_DETECTION_097_100(&e_ptr.SRR_RL_DETECTION_097_100);
   add_SRR_RL_DETECTION_101_104(&e_ptr.SRR_RL_DETECTION_101_104);
   add_SRR_RL_DETECTION_105_108(&e_ptr.SRR_RL_DETECTION_105_108);
   add_SRR_RL_DETECTION_109_112(&e_ptr.SRR_RL_DETECTION_109_112);
   add_SRR_RL_DETECTION_113_116(&e_ptr.SRR_RL_DETECTION_113_116);
   add_SRR_RL_DETECTION_117_120(&e_ptr.SRR_RL_DETECTION_117_120);
   add_SRR_RL_DETECTION_121_124(&e_ptr.SRR_RL_DETECTION_121_124);
   add_SRR_RL_DETECTION_125_128(&e_ptr.SRR_RL_DETECTION_125_128);
   add_SRR_RL_HEADER_001(&e_ptr.SRR_RL_HEADER_001);
   add_SRR_RL_STATUS_001(&e_ptr.SRR_RL_STATUS_001);
   add_SRR_RL_STATUS_002(&e_ptr.SRR_RL_STATUS_002);
   add_SRR_RL_XCP_CTO_REQ(&e_ptr.SRR_RL_XCP_CTO_REQ);
   add_SRR_RL_XCP_CTO_RESP(&e_ptr.SRR_RL_XCP_CTO_RESP);
   add_SRR_RL_XCP_DAQ_RESP(&e_ptr.SRR_RL_XCP_DAQ_RESP);
   add_SRR_RL_BSD1_B0(&e_ptr.SRR_RL_BSD1_B0);
}

void Populate_FLR_Messages(void)
{
   populate_FLR_object_data();
   encode_FLR_messages();
   populate_FLR_can_signals();
}

void Populate_FLR_VCAN_Messages(void)
{
   populate_FLR_VCAN_object_data();
   encode_FLR_VCAN_messages();
   populate_FLR_VCAN_can_signals();
}

void Populate_Front_Left_Messages(void)
{
   populate_Front_object_data();
   encode_Front_messages();
   populate_Front_can_signals();
}
void Populate_Rear_Left_Messages(void)
{
   populate_Rear_object_data();
   encode_Rear_messages();
   populate_Rear_can_signals();
}
