#ifndef CAN_RX_MSGS_H
#define CAN_RX_MSGS_H
/*===========================================================================*/
/**
 * @file can_rx_msgs.h
 *
 * CAN receive message definitions and signal processing for VCAN communication.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This header file defines the CAN receive message structure and provides
 * functions for processing received CAN messages and accessing vehicle
 * status signals from the VCAN message bus.
 *
 * @section ABBR ABBREVIATIONS:
 *   - CAN: Controller Area Network
 *   - VCAN: Vehicle CAN
 *   - ADAS: Advanced Driver Assistance Systems
 *   - FXP: Fixed Point
 *   - FLP: Floating Point
 *   - QF: Quality Factor
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Core_Radar_Gen8_iND13400 CAN Signal Definitions
 *
 *   - Requirements Document(s):
 *     - DND-3402: Update for RX can msgs dbcv2.0 Gen8 RdrPlatform
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - AUTOSAR C Language Coding Guidelines
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup CAN_RX_MSGS CAN Receive Message Processing API
 * @ingroup SWC_PLT_Appl_Communication
 * @{
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_Type.h"
#include "can_signals.h"
#include "fixmac.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
#define Init   0
#define SRR_FC 5U
#define SRR_L1 4U
#define SRR_L2 1U

/* Vehicle standstill hysteresis thresholds and debounce timers */
#define STANDSTILL_ENTER_MPS (0.02778f) /* 0.1 km/h */
#define STANDSTILL_EXIT_MPS  (0.13889f) /* 0.5 km/h */

#define STANDSTILL_ON_TIME_MS  (500U)
#define STANDSTILL_OFF_TIME_MS (200U)

#define UPDATE_VEHICLE_STANDSTILL_PERIOD_MS (10U)
/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
#if defined(FEATURE_ENABLE)
typedef struct L1_Feature_Degradation_Params_Tag
{
   uint8_t l1_time_sync_validity_flag;
   uint8_t l1_op_mode;
   uint8_t l1_sensor_blocked_sts;
   uint8_t l1_sensor_block_value;
   uint8_t l1_alignment_auto_sts;
   uint32_t l1_fault_table_11_15;
} L1_Feature_Degradation_Params_T;

typedef struct L1_Feature_Degradation_Flags_Tag
{
   uint8_t l1_time_sync_validity_degraded_flag;
   uint8_t l1_op_mode_degraded_flag;
   uint8_t l1_sensor_blockage_degraded_flag;
   uint8_t l1_align_no_calib_auto_sts_degraded_flag;
} L1_Feature_Degradation_Flags_T;
#endif

typedef enum Gear_Box_Position_Tag
{
   GEAR_BOX_POSITION_PARK,
   GEAR_BOX_POSITION_REVERSE,
   GEAR_BOX_POSITION_NEUTRAL,
   GEAR_BOX_POSITION_DRIVE,
   GEAR_BOX_POSITION_LOW,
   GEAR_BOX_POSITION_RESERVED2,
   GEAR_BOX_POSITION_RESERVED3,
   GEAR_BOX_POSITION_RESERVED4,
   GEAR_BOX_POSITION_RESERVED5,
   GEAR_BOX_POSITION_RESERVED6,
   GEAR_BOX_POSITION_RESERVED7,
   GEAR_BOX_POSITION_RESERVED8,
   GEAR_BOX_POSITION_RESERVED9,
   GEAR_BOX_POSITION_RESERVED10,
   GEAR_BOX_POSITION_ERROR,
   GEAR_BOX_POSITION_INVALID,
} Gear_Box_Position_T;

typedef enum Transmission_Type_Tag
{
   TRANSMISSION_TYPE_MT_VARIANT,
   TRANSMISSION_TYPE_AT_VARIANT,
   TRANSMISSION_TYPE_6S_AMT_VARIANT,
   TRANSMISSION_TYPE_9S_AMT_VARIANT,
   TRANSMISSION_TYPE_12S_AMT_VARIANT,
   TRANSMISSION_TYPE_RESERVED_1,
   TRANSMISSION_TYPE_RESERVED_2,
   TRANSMISSION_TYPE_NOT_DEFINED,
} Transmission_Type_T;

typedef enum Crawler_Type_Tag
{
   CRAWLER_DISABLED,
   CRAWLER_ENABLED,
} Crawler_Type_T;

typedef struct Delta_Vehicle_Status_msg
{
   uint8_t af_core_throughput;
   uint8_t blockage_value;
   uint8_t hed_operation_mode;
   uint8_t hed_data_qualifier;
   uint8_t Blockage_status;
} Delta_Vehicle_Status_msg_T;

typedef struct VCAN_Rx_Signals_Tag
{
   uint8_t SSTS_CAN_PCAN_MAJOR_ADAS;
   uint8_t SSTS_CAN_PCAN_MINOR_ADAS;
   uint8_t SSTS_DRIVE_DIR;
   bool SSTS_DRIVE_REVERSE;
   uint8_t SSTS_GEAR_POSITION;
   uint8_t SSTS_IGN_STATUS;
   uint8_t SSTS_LROS_DRIVE_DIR;
   bool SSTS_LROS_DRIVE_REVERSE;
   uint16_t SSTS_MH_VS_CRC16;
   uint8_t SSTS_MH_VS_CYCLE_COUNTER;
   uint8_t SSTS_STEERING_ANGLE;
   bool SSTS_STEERING_ANGLE_SIGN;
   uint32_t SSTS_SW_VERSION_ADAS;
   uint8_t SSTS_VEH_AbsoluteTime_Day;
   uint8_t SSTS_VEH_AbsoluteTime_Hour;
   uint8_t SSTS_VEH_AbsoluteTime_Minute;
   uint8_t SSTS_VEH_AbsoluteTime_Month;
   uint8_t SSTS_VEH_AbsoluteTime_Second;
   uint8_t SSTS_VEH_AbsoluteTime_Year;
   uint32_t SSTS_VEH_ODOMETER;
   uint8_t SSTS_VEH_POWER_MODE_STATUS;
   sint8 SSTS_VEH_SPD_COMP_FACTOR;
   uint16_t SSTS_VEH_SYSTEM_VOLTAGE;
   uint16_t SSTS_VEHICLE_SPEED_CALC;
   uint8_t SSTS_VEHICLE_SPEED_CALC_QF;
   uint8_t SSTS_VEHICLE_STATE;
   uint8_t SSTS_YAW_RATE_BIAS;
   uint16_t SSTS_YAW_RATE_CALC;
   uint8_t SSTS_YAW_RATE_CALC_QF;
} VCAN_Rx_Signals_T;

typedef struct Vcan_Vehicle_Status_Signal_Tag
{
   float32_t wheel_base_vehicle_speed;
   float32_t total_vehicle_distance;
   float32_t brake_pedal_pos;
   float32_t front_axle_speed;
   float32_t relative_speed_front_axle_left_wheel;
   float32_t relative_speed_front_axle_right_wheel;
   float32_t relative_speed_rear_axle_1_left_wheel;
   float32_t relative_speed_rear_axle_1_right_wheel;
   float32_t xbr_acceleration_limit;
   float32_t front_axle_left_wheel_speed;
   float32_t front_axle_right_wheel_speed;
   float32_t rear_axle_left_wheel_speed;
   float32_t rear_axle_right_wheel_speed;
   float32_t steer_wheel_angle;
   float32_t yaw_rate;
   float32_t lateral_acceleration;
   float32_t longitudinal_acceleration;
   float32_t steering_wheel_angle;
   float32_t steering_wheel_angle_range;
   float32_t transmission_output_shaft_speed;
   uint32_t rx_nanoseconds;
   uint32_t rx_seconds;
   uint8_t seconds;
   uint8_t minutes;
   uint8_t hours;
   uint8_t month;
   uint8_t day;
   uint8_t year;
   uint8_t local_minute_offset;
   uint8_t local_hour_offset;
   uint8_t parking_brake_switch;
   uint8_t brake_switch;
   int16_t trans_current_gear;
   uint8_t engine_operating_mode;
   uint8_t aebs_readiness_state;
   uint8_t antilock_braking_active;
   uint8_t asr_off_road_switch;
   uint8_t abs_fully_operational;
   uint8_t abs_ebs_amber_warning_signal;
   uint8_t atc_asr_information_signal;
   uint8_t foundation_brake_use;
   uint8_t xbr_system_state;
   uint8_t xbr_active_ctrl_mode;
   uint8_t emergency_braking_active;
   uint8_t turn_signal_switch;
   uint8_t hazard_light_switch;
   uint8_t high_low_beam_switch;
   uint8_t mois_fn_enable_disable_sts;
   uint8_t bsis_fn_enable_disable_sts;
   uint8_t ddaw_fn_enable_disable_sts;
   uint8_t aebs_fn_enable_disable_sts;
   uint8_t ldws_fn_enable_disable_sts;
   uint8_t ddaw_warning_suppression;
   uint8_t message_alive_counter;
   uint8_t message_crc;
   uint8_t steering_wheel_angle_range_counter;
   uint8_t steering_wheel_angle_range_counter_type;
   uint8_t active_mode;
   uint8_t calibrated;
   uint8_t message_counter;
   uint8_t message_checksum_;
   uint8_t transmission_mode_1_indicator;
   uint8_t reverse_switch_info;
   uint8_t ignition;
   uint8_t crawler_confi_status_info;
   uint8_t transmission_type_info;
   uint8_t transmission_driveline_engaged;
   uint8_t transmission_shift_in_process;
   uint8_t vehicle_identification;
   uint8_t moving_object_detection_state;
   uint8_t blind_spot_detection_state;
   uint8_t blind_spot_collision_warning_level;
   uint8_t rdn_moving_object_detection_state;
   uint8_t rdn_blind_spot_detection_state;
   uint8_t rdn_mois_collision_warning_level;
   uint8_t rdn_blind_spot_collision_warning_level;
   uint8_t bsis_fn_switch_sts;
   uint8_t mois_fn_switch_sts;
   uint8_t Blind_Spot_Collision_Warning_Level;
} Vcan_Vehicle_Status_Signal_T;
typedef struct
{
   uint8_t standstill;
   uint16_t on_counter_ms;
   uint16_t off_counter_ms;
} VehicleStandstillState_T;
/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
void Process_Received_CAN_Msgs(void);
float32_t FXP2FLP_Fnc(int32_t value, int32_t bpp_num, bool signed_flag);
uint8_t UpdateVehicleStandstill(VehicleStandstillState_T *state, float32_t vehicle_speed);
#ifdef VEH_AL_CAN_STANDALONE
const Vcan_Vehicle_Status_Signal_T *Get_Vehicle_Status_Signals(void);
uint8_t Get_L1_BSIS_Degradation_Flag_Sts(void);
const Delta_Vehicle_Status_msg_T *Get_Delta_Vehicle_Status_Msg(void);
void Populate_Comm_Veh_Data_On_Ipc(void);
#else
VCAN_Rx_Signals_T *Get_VCAN_Rx_Signals(void);
#endif

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

/*===========================================================================
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *    Date      userid  (Description on following lines: SCR #, etc.)
 * -----------  ------  ------------------------------------------------
 * 03-Mar-2025  xj0l28  DND-3402 Update for RX can msgs dbcv2.0 Gen8 RdrPlatform
 * 01-Mar-2025  xj0l28  DND-3402: New file checkin
 * ============================================================================ */
#endif /* CAN_RX_MSGS_H */
