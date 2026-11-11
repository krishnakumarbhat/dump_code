/*===========================================================================*/
/**
 * @file can_rx_msgs.c
 *
 * Processes received CAN messages and manages vehicle status signals.
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
 * This module processes CAN received messages and extracts vehicle status signals
 * from the AUTOSAR Rte interface. It provides signal conversion and access functions
 * for vehicle parameters including speed, steering angle, gear position, and system status.
 *
 * @section ABBR ABBREVIATIONS:
 *   - CAN: Controller Area Network
 *   - RTE: AUTOSAR Runtime Environment
 *   - VCAN: Vehicle CAN signals
 *   - ADAS: Advanced Driver Assistance Systems
 *   - QF: Quality Factor
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Gen8 Radar Platform CAN Message Specification
 *
 *   - Requirements Document(s):
 *     - DND-3402: Update for RX CAN messages Gen8 RdrPlatform
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
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "math.h"
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_Appl_Communication.h"
#include "Rte_Type.h"
#include "can_rx_msgs.h"
#include "can_signals.h"
#include "dsp_setup.h"
#include "emb_tracker_project_parameters.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "radar_sw_config.h"
#include "sensor_position.h"
#include "smc_cal.h"
#include "vse_stream.h"
/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define REVERSE_SW_INFO_EN    (1U)
#define TRAN_CRR_GEAR_NEUTRAL (0)

#define TRANS_CRR_GEAR_MT_CW_DIS_MIN (1)
#define TRANS_CRR_GEAR_MT_CW_DIS_MAX (8)

#define TRANS_CRR_GEAR_MT_CW_EN_MIN (2)
#define TRANS_CRR_GEAR_MT_CW_EN_MAX (15)

#define TRANS_CRR_GEAR_AT_PARK (126)
#define TRANS_CRR_GEAR_CRAWLER (1)

#define TRANS_CRR_GEAR_AT_6S_DRIVE_MIN (1)
#define TRANS_CRR_GEAR_AT_6S_DRIVE_MAX (14)

#define TRANS_CRR_GEAR_AT_9S_12S_DRIVE_MIN (2)
#define TRANS_CRR_GEAR_AT_9S_12S_DRIVE_MAX (16)

#define TRANS_CRR_GEAR_AT_REV_1 (-1)
#define TRANS_CRR_GEAR_AT_REV_2 (-2)

#define PARK_BRAKE_SWITCH_ENGAGED  (1)
#define PARK_BRAKE_SWITCH_RELEASED (0)
#define PARK_BRAKE_SWITCH_ERR      (2)
#define TRANS_CRR_GEAR_ERR         (129)

#define KMPH_TO_MPS(x)           ((x)*0.2778F) // x * 1000/3600
#define IS_IN_RANGE(x, min, max) (((x) >= (min)) && ((x) <= (max)))
#define DEGREES_TO_RADIANS(x)    ((x)*0.017453292519F) // x * pi / 180
#define RADIANS_TO_DEGREES(x)    ((x)*57.2957795131F)  // x * 180 / pi
/* Vehicle Status */
#define GET_VEHICLE_STATUS_FROM_CAN Rte_Read_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL
#define RX_TIMEOUT_DEBOUNCE_COUNT   5
#define RAD_TO_DEG_F32              (57.2957795F)
/* Runnable execution period for Populate_Veh_Data_On_Ipc processing (10 ms). */
#define COMM_RX_PERIOD_SEC (0.010F)
/* Time unit conversion from seconds to nanoseconds. */
#define NANOSECONDS_PER_SECOND (1000000000U)

#define MAX_DETECTION_MSG_SRR_L1 16U
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

typedef Std_ReturnType (*Read_Can_Fusion_Detection_Msg_Func_Ptr)(void *data);
typedef struct Rte_Read_Can_Msg_Function_Array_Tag
{
   uint32_t size;
   Read_Can_Fusion_Detection_Msg_Func_Ptr const *read_functions;
} Rte_Read_Can_Msg_Function_Array_T;
volatile uint8_t Customer_Radar_Position                                    = Init;
volatile uint8_t Vcan_CCVS1_message_timeout_fault_pass                      = 0;
volatile uint8_t Vcan_CCVS1_message_timeout_fault_fail                      = 0;
volatile uint8_t Vcan_ETC2_00_message_timeout_fault_pass                    = 0;
volatile uint8_t Vcan_ETC2_00_message_timeout_fault_fail                    = 0;
volatile uint8_t Vcan_VDC2_message_timeout_fault_pass                       = 0;
volatile uint8_t Vcan_VDC2_message_timeout_fault_fail                       = 0;
volatile uint8_t Vcan_ETC2_03_message_timeout_fault_pass                    = 0;
volatile uint8_t Vcan_ETC2_03_message_timeout_fault_fail                    = 0;
volatile uint8_t Pcan_GW_CCVS1_message_timeout_fault_pass                   = 0;
volatile uint8_t Pcan_GW_CCVS1_message_timeout_fault_fail                   = 0;
volatile uint8_t Pcan_GW_ETC2_message_timeout_fault_pass                    = 0;
volatile uint8_t Pcan_GW_ETC2_message_timeout_fault_fail                    = 0;
volatile uint8_t Pcan_GW_VDC2_message_timeout_fault_pass                    = 0;
volatile uint8_t Pcan_GW_VDC2_message_timeout_fault_fail                    = 0;
volatile uint8_t Pcan_GW_ETC2_03_message_timeout_fault_pass                 = 0;
volatile uint8_t Pcan_GW_ETC2_03_message_timeout_fault_fail                 = 0;
volatile uint8_t Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass = 0;
volatile uint8_t Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail = 0;
volatile uint8_t Vcan_CLS_Tx_16_message_timeout_fault_pass                  = 0;
volatile uint8_t Vcan_CLS_Tx_16_message_timeout_fault_fail                  = 0;
volatile uint8_t Vcan_CLS_Tx_4_message_timeout_fault_pass                   = 0;
volatile uint8_t Vcan_CLS_Tx_4_message_timeout_fault_fail                   = 0;
volatile uint8_t Vcan_OEL_message_timeout_fault_pass                        = 0;
volatile uint8_t Vcan_OEL_message_timeout_fault_fail                        = 0;
volatile uint8_t Vcan_TD_message_timeout_fault_pass                         = 0;
volatile uint8_t Vcan_TD_message_timeout_fault_fail                         = 0;
volatile uint8_t Vcan_VD_message_timeout_fault_pass                         = 0;
volatile uint8_t Vcan_VD_message_timeout_fault_fail                         = 0;
volatile uint8_t Vcan_SAS_message_timeout_fault_pass                        = 0;
volatile uint8_t Vcan_SAS_message_timeout_fault_fail                        = 0;
volatile uint8_t Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass = 0;
volatile uint8_t Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail = 0;
volatile uint8_t Pcan_CLS_Tx_16_message_timeout_fault_pass                  = 0;
volatile uint8_t Pcan_CLS_Tx_16_message_timeout_fault_fail                  = 0;
volatile uint8_t Pcan_CLS_Tx_4_message_timeout_fault_pass                   = 0;
volatile uint8_t Pcan_CLS_Tx_4_message_timeout_fault_fail                   = 0;
volatile uint8_t Pcan_OEL_message_timeout_fault_pass                        = 0;
volatile uint8_t Pcan_OEL_message_timeout_fault_fail                        = 0;
volatile uint8_t Pcan_GW_TD_message_timeout_fault_pass                      = 0;
volatile uint8_t Pcan_GW_TD_message_timeout_fault_fail                      = 0;
volatile uint8_t Pcan_GW_VD_message_timeout_fault_pass                      = 0;
volatile uint8_t Pcan_GW_VD_message_timeout_fault_fail                      = 0;
volatile uint8_t Pcan_GW_SAS_message_timeout_fault_pass                     = 0;
volatile uint8_t Pcan_GW_SAS_message_timeout_fault_fail                     = 0;
volatile uint8_t Pcan_RadarHeader_message_timeout_fault_pass                = 0;
volatile uint8_t Pcan_RadarHeader_message_timeout_fault_fail                = 0;
volatile uint8_t Pcan_RadarCapability_message_timeout_fault_pass            = 0;
volatile uint8_t Pcan_RadarCapability_message_timeout_fault_fail            = 0;
volatile uint8_t Pcan_RadarStatus_message_timeout_fault_pass                = 0;
volatile uint8_t Pcan_RadarStatus_message_timeout_fault_fail                = 0;
volatile uint8_t Pcan_RadarStatus2_message_timeout_fault_pass               = 0;
volatile uint8_t Pcan_RadarStatus2_message_timeout_fault_fail               = 0;
volatile uint8_t Pcan_AlignmentStatus1_message_timeout_fault_pass           = 0;
volatile uint8_t Pcan_AlignmentStatus1_message_timeout_fault_fail           = 0;
volatile uint8_t Vcan_ADAS_FN_message_timeout_fault                         = CODED_FALSE;

#ifdef VEH_AL_CAN_STANDALONE
   #if defined(FEATURE_ENABLE)
L1_Feature_Degradation_Params_T L1_Feature_Degradation_Params;
L1_Feature_Degradation_Flags_T L1_BSIS_Feature_Degradation_Flags;
uint8_t L1_BSIS_Feat_Degrade_Flag = CODED_FALSE;
   #endif
#endif

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
extern uint8_t Get_Customer_Radar_Position(void);
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#pragma clang optimize off
#ifdef VEH_AL_CAN_STANDALONE
static bool Steering_Whl_Angle_Initialized   = false;
static float32_t Prev_Steering_Whl_Angle_Deg = 0.0F;
static I_SG_Fusion_RadarHeader_ALPCAN Radar_Header_Message;
static I_SG_Fusion_RadarStatus_ALPCAN Radar_Status1_Message;
static I_SG_Fusion_AlignmentStatus1_ALPCAN Radar_Align1_Message;
static Vcan_Vehicle_Status_Signal_T Vcan_Vehicle_Status_Signal;
static VehicleStandstillState_T Vehicle_Standstill_State;
static Delta_Vehicle_Status_msg_T Delta_Vehicle_Status_msg;
const static Read_Can_Fusion_Detection_Msg_Func_Ptr Rte_Read_Can_Msg_Functionss_Sensor_0[] = {
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_001_004_AL_Vdp_SG_Fusion_Detections_001_004_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_005_008_AL_Vdp_SG_Fusion_Detections_005_008_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_009_012_AL_Vdp_SG_Fusion_Detections_009_012_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_013_016_AL_Vdp_SG_Fusion_Detections_013_016_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_017_020_AL_Vdp_SG_Fusion_Detections_017_020_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_021_024_AL_Vdp_SG_Fusion_Detections_021_024_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_025_028_AL_Vdp_SG_Fusion_Detections_025_028_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_029_032_AL_Vdp_SG_Fusion_Detections_029_032_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_033_036_AL_Vdp_SG_Fusion_Detections_033_036_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_037_040_AL_Vdp_SG_Fusion_Detections_037_040_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_041_044_AL_Vdp_SG_Fusion_Detections_041_044_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_045_048_AL_Vdp_SG_Fusion_Detections_045_048_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_049_052_AL_Vdp_SG_Fusion_Detections_049_052_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_053_056_AL_Vdp_SG_Fusion_Detections_053_056_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_057_060_AL_Vdp_SG_Fusion_Detections_057_060_AL,
   (Read_Can_Fusion_Detection_Msg_Func_Ptr)Rte_Read_Rp_SG_Fusion_Detections_061_064_AL_Vdp_SG_Fusion_Detections_061_064_AL,
};

const static Rte_Read_Can_Msg_Function_Array_T Rte_Read_Can_Msg_From_Sensors = {
   .size           = sizeof(Rte_Read_Can_Msg_Functionss_Sensor_0) / sizeof(Rte_Read_Can_Msg_Functionss_Sensor_0[0U]),
   .read_functions = Rte_Read_Can_Msg_Functionss_Sensor_0,
};
#else
static VCAN_Rx_Signals_T VCAN_Rx_Signals;
#endif
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
#ifdef VEH_AL_CAN_STANDALONE
void Populate_Veh_Data_On_Ipc(void);
static void Process_Sensor_Fusion_Header_Status_Align_Data(void);
static void Process_Sensor_Fusion_Detections(void);
static Gear_Box_Position_T Calculate_Trans_Gear_Position(Vcan_Vehicle_Status_Signal_T *signals);
#else
static void Process_Vehicle_Status(void);
#endif
#ifdef VEH_AL_CAN_STANDALONE

/**
 * @brief Calculates the gear position based on the transmission type and current gear.
 * @param sig Pointer to the vehicle status signal structure containing transmission information.
 * @return Gear_Box_Position_T The calculated gear position.
 */
static Gear_Box_Position_T Calculate_Trans_Gear_Position(Vcan_Vehicle_Status_Signal_T *sig)
{
   Gear_Box_Position_T gear_position = GEAR_BOX_POSITION_INVALID;

   if (PARK_BRAKE_SWITCH_ENGAGED == sig->parking_brake_switch)
   {
      gear_position = GEAR_BOX_POSITION_PARK;
   }
   else if (PARK_BRAKE_SWITCH_RELEASED == sig->parking_brake_switch)
   {
      if (sig->transmission_type_info == TRANSMISSION_TYPE_MT_VARIANT)
      {
         if (CRAWLER_DISABLED == sig->crawler_confi_status_info)
         {
            if (REVERSE_SW_INFO_EN == sig->reverse_switch_info)
            {
               gear_position = GEAR_BOX_POSITION_REVERSE;
            }
            else
            {
               if (TRAN_CRR_GEAR_NEUTRAL == sig->trans_current_gear)
               {
                  gear_position = GEAR_BOX_POSITION_NEUTRAL;
               }
               else if ((TRANS_CRR_GEAR_MT_CW_DIS_MIN <= sig->trans_current_gear) &&
                        (TRANS_CRR_GEAR_MT_CW_DIS_MAX >= sig->trans_current_gear))
               {
                  gear_position = GEAR_BOX_POSITION_DRIVE;
               }
               else
               {
                  gear_position = GEAR_BOX_POSITION_INVALID;
               }
            }
         }
         else if (CRAWLER_ENABLED == sig->crawler_confi_status_info)
         {
            if (REVERSE_SW_INFO_EN == sig->reverse_switch_info)
            {
               gear_position = GEAR_BOX_POSITION_REVERSE;
            }
            else
            {
               if (TRAN_CRR_GEAR_NEUTRAL == sig->trans_current_gear)
               {
                  gear_position = GEAR_BOX_POSITION_NEUTRAL;
               }
               else if (TRANS_CRR_GEAR_CRAWLER == sig->trans_current_gear)
               {
                  gear_position = GEAR_BOX_POSITION_LOW;
               }
               else if ((TRANS_CRR_GEAR_MT_CW_EN_MIN <= sig->trans_current_gear) &&
                        (TRANS_CRR_GEAR_MT_CW_EN_MAX >= sig->trans_current_gear))
               {
                  gear_position = GEAR_BOX_POSITION_DRIVE;
               }
               else
               {
                  gear_position = GEAR_BOX_POSITION_INVALID;
               }
            }
         }
         else
         {
            gear_position = GEAR_BOX_POSITION_INVALID;
         }
      }
      else if ((TRANSMISSION_TYPE_AT_VARIANT == sig->transmission_type_info) ||
               (TRANSMISSION_TYPE_6S_AMT_VARIANT == sig->transmission_type_info))
      {
         if ((TRANS_CRR_GEAR_AT_REV_1 == sig->trans_current_gear) || (TRANS_CRR_GEAR_AT_REV_2 == sig->trans_current_gear))
         {
            gear_position = GEAR_BOX_POSITION_REVERSE;
         }
         else if (TRAN_CRR_GEAR_NEUTRAL == sig->trans_current_gear)
         {
            gear_position = GEAR_BOX_POSITION_NEUTRAL;
         }
         else if ((TRANS_CRR_GEAR_AT_6S_DRIVE_MIN <= sig->trans_current_gear) &&
                  (TRANS_CRR_GEAR_AT_6S_DRIVE_MAX >= sig->trans_current_gear))
         {
            gear_position = GEAR_BOX_POSITION_DRIVE;
         }
         else if (TRANS_CRR_GEAR_AT_PARK == sig->trans_current_gear)
         {
            gear_position = GEAR_BOX_POSITION_PARK;
         }
         else
         {
            gear_position = GEAR_BOX_POSITION_INVALID;
         }
      }
      else if ((TRANSMISSION_TYPE_9S_AMT_VARIANT == sig->transmission_type_info) ||
               (TRANSMISSION_TYPE_12S_AMT_VARIANT == sig->transmission_type_info))
      {
         if ((TRANS_CRR_GEAR_AT_REV_1 == sig->trans_current_gear) || (TRANS_CRR_GEAR_AT_REV_2 == sig->trans_current_gear))
         {
            gear_position = GEAR_BOX_POSITION_REVERSE;
         }
         else if (TRAN_CRR_GEAR_NEUTRAL == sig->trans_current_gear)
         {
            gear_position = GEAR_BOX_POSITION_NEUTRAL;
         }
         else if (TRANS_CRR_GEAR_CRAWLER == sig->trans_current_gear)
         {
            gear_position = GEAR_BOX_POSITION_LOW;
         }
         else if ((TRANS_CRR_GEAR_AT_9S_12S_DRIVE_MIN <= sig->trans_current_gear) &&
                  (TRANS_CRR_GEAR_AT_9S_12S_DRIVE_MAX >= sig->trans_current_gear))
         {
            gear_position = GEAR_BOX_POSITION_DRIVE;
         }
         else if (TRANS_CRR_GEAR_AT_PARK == sig->trans_current_gear)
         {
            gear_position = GEAR_BOX_POSITION_PARK;
         }
         else
         {
            gear_position = GEAR_BOX_POSITION_INVALID;
         }
      }
      else
      {
         gear_position = GEAR_BOX_POSITION_INVALID;
      }
   }
   else if ((TRANS_CRR_GEAR_ERR == sig->trans_current_gear) || (PARK_BRAKE_SWITCH_ERR == sig->parking_brake_switch))
   {
      gear_position = GEAR_BOX_POSITION_ERROR;
   }
   else
   {
      gear_position = GEAR_BOX_POSITION_INVALID;
   }
   return gear_position;
}

uint8_t UpdateVehicleStandstill(VehicleStandstillState_T *state, float32_t vehicle_speed)
{
   float32_t abs_speed = fabsf(vehicle_speed);

   if (state->standstill == 0U)
   {
      if (abs_speed <= STANDSTILL_ENTER_MPS)
      {
         state->on_counter_ms += UPDATE_VEHICLE_STANDSTILL_PERIOD_MS;

         if (state->on_counter_ms >= STANDSTILL_ON_TIME_MS)
         {
            state->standstill    = 1U;
            state->on_counter_ms = 0U;
         }
      }
      else
      {
         state->on_counter_ms = 0U;
      }

      state->off_counter_ms = 0U;
   }
   else
   {
      if (abs_speed >= STANDSTILL_EXIT_MPS)
      {
         state->off_counter_ms += UPDATE_VEHICLE_STANDSTILL_PERIOD_MS;

         if (state->off_counter_ms >= STANDSTILL_OFF_TIME_MS)
         {
            state->standstill     = 0U;
            state->off_counter_ms = 0U;
         }
      }
      else
      {
         state->off_counter_ms = 0U;
      }

      state->on_counter_ms = 0U;
   }

   return state->standstill;
}
/**
 * @brief populates the IPC vse stream based on last received vehicle can signals values
 * @param void
 * @return void
 */
void Populate_Veh_Data_On_Ipc(void)
{
   M2D_Msg_T *const m2d_msg   = (M2D_Msg_T *const)Get_MSS_IPC_M2D_Msg_Buffer();
   D2M_Msg_T *const p_ipc_d2m = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   static uint8_t write_idx               = 0U;
   Veh_Raw_Data_T *const veh_raw          = &m2d_msg->payload.veh_data.veh_raw_data[write_idx];
   Veh_Raw_Misc_T *const veh_misc         = &m2d_msg->payload.veh_data.veh_raw_misc;
   Veh_Params_T *const veh_params         = &m2d_msg->payload.veh_data.veh_params;
   Last_Key_Cycle_T *const last_key_cycle = &m2d_msg->payload.veh_data.last_key_cycle;
   // volatile M2D_One_Time_Msg_T *const m2d_one_time_msg = Get_IPC_M2D_Onetime_Msg_Buffer();
   // const float32_t steering_gear_ratio_deg             = m2d_one_time_msg->calib_data.vehicle_calib_data.k_steering_gear_ratio;
   //  const float32_t steering_divisor =
   //     ((steering_gear_ratio_deg >= -1.0e-5F) && (steering_gear_ratio_deg <= 1.0e-5F)) ? 1.0F : steering_gear_ratio_deg;
   veh_raw->system_time_secs       = Vcan_Vehicle_Status_Signal.rx_seconds;
   veh_raw->system_time_nanosecs   = Vcan_Vehicle_Status_Signal.rx_nanoseconds;
   veh_raw->ego_yaw_rate           = (-1.0F) * Vcan_Vehicle_Status_Signal.yaw_rate;
   veh_misc->vehicle_standstill    = UpdateVehicleStandstill(&Vehicle_Standstill_State, veh_raw->ego_vehicle_speed);
   veh_raw->ego_lateral_accel      = (-1.0F) * Vcan_Vehicle_Status_Signal.lateral_acceleration;
   veh_raw->ego_longitudinal_accel = Vcan_Vehicle_Status_Signal.longitudinal_acceleration;
   veh_misc->ego_vehicle_speed_qf =
      3; // valid value (3) is used since the signals are not available from the Vcan_Vehicle_Status_Signal
   veh_misc->ego_yaw_rate_qf =
      3; // valid value (3) is used since the signals are not available from the Vcan_Vehicle_Status_Signal
   veh_misc->ego_lateral_accel_qf =
      3; // valid value (3) is used since the signals are not available from the Vcan_Vehicle_Status_Signal
   veh_misc->ego_longitudinal_accel_qf =
      3; // valid value (3) is used since the signals are not available from the Vcan_Vehicle_Status_Signal
   veh_misc->steering_whl_angle_qf =
      3; // valid value (3) is used since the signals are not available from the Vcan_Vehicle_Status_Signal

   // veh_raw->steering_whl_angle =
   //    DEGREES_TO_RADIANS(((-1.0F) * RADIANS_TO_DEGREES(Vcan_Vehicle_Status_Signal.steer_wheel_angle)) / steering_divisor);
   veh_raw->steering_whl_angle = (-1.0F) * (Vcan_Vehicle_Status_Signal.steer_wheel_angle);
   veh_raw->ego_vehicle_speed  = KMPH_TO_MPS(Vcan_Vehicle_Status_Signal.wheel_base_vehicle_speed);
   veh_misc->gear_pos          = Calculate_Trans_Gear_Position(&Vcan_Vehicle_Status_Signal);
   veh_misc->turn_signal       = Vcan_Vehicle_Status_Signal.turn_signal_switch;

   #if defined(FEATURE_ENABLE)
   if (CODED_TRUE == Vcan_ADAS_FN_message_timeout_fault)
   {
      m2d_msg->payload.feature_input.mois_fn_enable_disable_sts = 1;
   }
   else
   {
      m2d_msg->payload.feature_input.mois_fn_enable_disable_sts =
         Vcan_Vehicle_Status_Signal
            .mois_fn_switch_sts; /*code changes made as requested by feature function team for vehicle testing as a temp fix.*/
   }
   m2d_msg->payload.feature_input.bsis_fn_enable_disable_sts =
      1; // Vcan_Vehicle_Status_Signal.bsis_fn_switch_sts; /*TODO: make changes such that we are using the activ fault table to
         // enable /disable the feature function status
   m2d_msg->payload.feature_input.ignition_sts = 1; // Vcan_Vehicle_Status_Signal.ignition;
   #endif

   /* Need to take these values from the DRA stream if it is available */
   /* Otherwise, keep the previous values (or defaults if DRA hasn't been available once yet) */
   static float32_t speed_comp        = 1.0F;
   static uint8_t speed_comp_qf       = 3U;
   static const uint8_t scf_qf_map[3] = {0U, 2U, 3U};
   if (p_ipc_d2m != NULL && p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode != 0U)
   {
      speed_comp           = p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated;
      const uint8_t scf_qf = p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf;
      if (scf_qf <= 2U)
      {
         speed_comp_qf = scf_qf_map[scf_qf];
      }
      else
      {
         /* Invalid QF: keep previous valid value */
      }
   }
   veh_misc->vehspeedcompfac_ka    = speed_comp;
   veh_misc->vehspeedcompfac_ka_qf = speed_comp_qf;

   const float32_t steering_whl_angle_deg = (veh_raw->steering_whl_angle * RAD_TO_DEG_F32);
   if (!Steering_Whl_Angle_Initialized)
   {
      veh_raw->steering_whl_speed_deg_per_s = 0.0F;
      Steering_Whl_Angle_Initialized        = true;
   }
   else
   {
      veh_raw->steering_whl_speed_deg_per_s = (steering_whl_angle_deg - Prev_Steering_Whl_Angle_Deg) / COMM_RX_PERIOD_SEC;
   }
   Prev_Steering_Whl_Angle_Deg                = steering_whl_angle_deg;
   m2d_msg->payload.veh_data.latest_raw_index = write_idx;
   write_idx                                  = (uint8_t)((write_idx + 1U) % VSE_STREAM_RAW_INSTANCES);
   if (k_gxcp_delay_smc == 1u)
   {
      veh_params->k_cog_x                           = 1.9654f;
      veh_params->k_cog_y                           = -0.015188f;
      veh_params->k_understeer_coefficient          = 0.007f;
      veh_params->k_front_track_width               = 1.98f;
      veh_params->k_steering_ratio_rack_pinion_type = 0.0F;
   }
   else if (k_gxcp_delay_smc == 2u)
   {
      veh_params->k_cog_x                           = 1.09f;
      veh_params->k_cog_y                           = 0.0f;
      veh_params->k_understeer_coefficient          = 0.007f;
      veh_params->k_front_track_width               = 2.08f;
      veh_params->k_steering_ratio_rack_pinion_type = 0.0F;
   }
   else
   {
      // No operation
   }
   veh_params->k_wheel_base                = k_wheelbase_smc;
   veh_params->k_dist_rear_axle_to_vcs     = k_distance_front_bumper_to_rear_axle_smc;
   veh_params->k_steering_gear_ratio       = k_steering_gear_ratio_smc;
   veh_params->k_rear_cornering_compliance = k_rear_cornering_complicane_smc;
   veh_params->k_vehicle_length            = k_vehicle_length_smc;
   veh_params->k_vehicle_width             = k_vehicle_width_smc;

   uint8_t sts_radar_pos                      = Get_Radar_Position();
   uint8_t smc_index                          = sts_radar_pos - (uint8_t)BIT_1;
   veh_params->k_long_dist_radar_to_rear_axle = k_sensor_mount_pos_x_list_smc[smc_index];
   veh_params->k_lat_dist_radar_to_rear_axle  = k_sensor_mount_pos_y_list_smc[smc_index];

   last_key_cycle->nvm_f_last_rem_swa_bias                    = 0u;
   last_key_cycle->nvm_last_rem_stop_yaw_bias_secondary_radps = 0.0F;
   last_key_cycle->nvm_last_rem_stop_yaw_bias_primary_radps   = 0.0F;
   last_key_cycle->nvm_last_rem_speed_comp                    = 0.0F;
   last_key_cycle->nvm_last_rem_swa_bias_deg                  = 0.0F;
}

/**
 * @brief populate received vehicle can status message on global variable
 * SRR_L1/SRR_L2 receive vehicle signals via the PCAN gateway (GW_*_ALPCAN ports).
 * SRR_FC receives vehicle signals directly on VCAN (ALVCAN ports).
 * @param void
 * @return void
 */
void Populate_Comm_Veh_Data_On_Ipc(void)
{
   Vcan_Vehicle_Status_Signal_T *const signal = &Vcan_Vehicle_Status_Signal;
   GLOB_TS_STRUCT_TYPE vcan_data_rx_time;
   CaptureGlobalTimestamp(TS_NO_BUFF, &vcan_data_rx_time);
   signal->rx_seconds     = vcan_data_rx_time.ts_secs;
   signal->rx_nanoseconds = vcan_data_rx_time.ts_nanosecs;

   uint8_t radar_pos                                          = Get_Radar_Position();
   I_SG_GW_CCVS1_ALPCAN pcan_msg_ccvs1                        = {0};
   I_SG_GW_ETC2_03_ALPCAN pcan_msg_etc2_03                    = {0};
   I_SG_GW_CLS_Tx_16_ALPCAN pcan_msg_cls_tx_16                = {0};
   I_SG_GW_ETC2_ALPCAN pcan_msg_etc2_00                       = {0};
   I_SG_GW_VD_ALPCAN pcan_msg_vd                              = {0};
   I_SG_GW_VDC2_ALPCAN pcan_msg_vdc2                          = {0};
   I_SG_GW_TD_ALPCAN pcan_msg_td                              = {0};
   I_SG_GW_OEL_ALPCAN pcan_msg_oel                            = {0};
   I_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN pcan_msg_adas_fn = {0};
   I_SG_GW_SAS_ALPCAN pcan_msg_sas                            = {0};
   I_SG_GW_CLS_Tx_4_ALPCAN pcan_msg_cls_tx_4                  = {0};
   I_SG_GW_VI_ALPCAN pcan_msg_vi                              = {0};
   I_SG_CCVS1_ALVCAN vcan_msg_ccvs1                           = {0};
   I_SG_CLS_Tx_16_ALVCAN vcan_msg_cls_tx_16                   = {0};
   I_SG_ETC2_03_ALVCAN vcan_msg_etc2_03                       = {0};
   I_SG_ETC2_00_ALVCAN vcan_msg_etc2_00                       = {0};
   I_SG_VD_ALVCAN vcan_msg_vd                                 = {0};
   I_SG_VDC2_ALVCAN vcan_msg_vdc2                             = {0};
   I_SG_TD_ALVCAN vcan_msg_td                                 = {0};
   I_SG_OEL_ALVCAN vcan_msg_oel                               = {0};
   I_SG_ADAS_FN_Enable_disable_sts_ALVCAN vcan_msg_adas_fn    = {0};
   I_SG_SAS_ALVCAN vcan_msg_sas                               = {0};
   I_SG_CLS_Tx_4_ALVCAN vcan_msg_cls_tx_4                     = {0};
   I_SG_VI_ALVCAN vcan_msg_vi                                 = {0};

   /* CCVS1 — speed, parking brake, brake switch */
   if ((radar_pos == SRR_L1) || (radar_pos == SRR_L2))
   {
      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CCVS1_ALPCAN_Vdp_SG_GW_CCVS1_ALPCAN(&pcan_msg_ccvs1);
      signal->wheel_base_vehicle_speed = CAN_RX_SIGNAL_CORRECTION(pcan_msg_ccvs1.WheelBasedVehicleSpeed, WheelBasedVehicleSpeed);
      signal->parking_brake_switch     = CAN_RX_SIGNAL_CORRECTION(pcan_msg_ccvs1.ParkingBrakeSwitch, ParkingBrakeSwitch);
      signal->brake_switch             = CAN_RX_SIGNAL_CORRECTION(pcan_msg_ccvs1.BrakeSwitch, BrakeSwitch);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_16_ALPCAN_Vdp_SG_GW_CLS_Tx_16_ALPCAN(&pcan_msg_cls_tx_16);
      signal->crawler_confi_status_info =
         CAN_RX_SIGNAL_CORRECTION(pcan_msg_cls_tx_16.Crawler_confi_status_info, Crawler_confi_status_info);
      signal->transmission_type_info = CAN_RX_SIGNAL_CORRECTION(pcan_msg_cls_tx_16.Transmission_type_info, Transmission_type_info);

      if ((signal->transmission_type_info == TRANSMISSION_TYPE_AT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_6S_AMT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_9S_AMT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_12S_AMT_VARIANT))
      {
         (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_03_ALPCAN_Vdp_SG_GW_ETC2_03_ALPCAN(&pcan_msg_etc2_03);
         signal->trans_current_gear = CAN_RX_SIGNAL_CORRECTION(pcan_msg_etc2_03.TransCurrentGear_03, TransCurrentGear_03);
      }
      else if (signal->transmission_type_info == TRANSMISSION_TYPE_MT_VARIANT)
      {
         (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_ALPCAN_Vdp_SG_GW_ETC2_ALPCAN(&pcan_msg_etc2_00);
         signal->trans_current_gear = CAN_RX_SIGNAL_CORRECTION(pcan_msg_etc2_00.TransCurrentGear_00, TransCurrentGear_00);
      }

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VD_ALPCAN_Vdp_SG_GW_VD_ALPCAN(&pcan_msg_vd);
      signal->total_vehicle_distance = CAN_RX_SIGNAL_CORRECTION(pcan_msg_vd.TotalVehicleDistance, Total_vehicle_distance);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VDC2_ALPCAN_Vdp_SG_GW_VDC2_ALPCAN(&pcan_msg_vdc2);
      signal->yaw_rate             = CAN_RX_SIGNAL_CORRECTION(pcan_msg_vdc2.YawRate, YawRate);
      signal->lateral_acceleration = CAN_RX_SIGNAL_CORRECTION(pcan_msg_vdc2.LateralAcceleration, LateralAcceleration);
      signal->longitudinal_acceleration =
         CAN_RX_SIGNAL_CORRECTION(pcan_msg_vdc2.LongitudinalAcceleration, LongitudinalAcceleration);
      signal->steer_wheel_angle = CAN_RX_SIGNAL_CORRECTION(pcan_msg_vdc2.SteerWheelAngle, SteerWheelAngle);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_TD_ALPCAN_Vdp_SG_GW_TD_ALPCAN(&pcan_msg_td);
      signal->seconds             = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Seconds, Seconds);
      signal->minutes             = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Minutes, Minutes);
      signal->hours               = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Hours, Hours);
      signal->month               = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Month, Month);
      signal->day                 = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Day, Day);
      signal->year                = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.Year, Year);
      signal->local_minute_offset = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.LocalMinuteOffset, LocalMinuteOffset);
      signal->local_hour_offset   = CAN_RX_SIGNAL_CORRECTION(pcan_msg_td.LocalHourOffset, LocalHourOffset);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_OEL_ALPCAN_Vdp_SG_GW_OEL_ALPCAN(&pcan_msg_oel);
      signal->turn_signal_switch   = CAN_RX_SIGNAL_CORRECTION(pcan_msg_oel.TurnSignalSwitch, TurnSignalSwitch);
      signal->hazard_light_switch  = CAN_RX_SIGNAL_CORRECTION(pcan_msg_oel.HazardLightSwitch, HazardLightSwitch);
      signal->high_low_beam_switch = CAN_RX_SIGNAL_CORRECTION(pcan_msg_oel.HighLowBeamSwitch, HighLowBeamSwitch);

      (void)
         Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_Vdp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN(
            &pcan_msg_adas_fn);
      signal->mois_fn_switch_sts         = CAN_RX_SIGNAL_CORRECTION(pcan_msg_adas_fn.MOIS_Fn_Switch_sts, MOIS_Fn_Switch_sts);
      signal->mois_fn_enable_disable_sts = signal->mois_fn_switch_sts;
      signal->message_alive_counter      = CAN_RX_SIGNAL_CORRECTION(pcan_msg_adas_fn.MessageAliveCounter, MessageAliveCounter);
      signal->message_crc                = CAN_RX_SIGNAL_CORRECTION(pcan_msg_adas_fn.MessageCRC, MessageCRC);
      signal->bsis_fn_switch_sts         = CAN_RX_SIGNAL_CORRECTION(pcan_msg_adas_fn.BSIS_fn_Switch_Sts, BSIS_Fn_Switch_Sts);
      signal->bsis_fn_enable_disable_sts = signal->bsis_fn_switch_sts;

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_SAS_ALPCAN_Vdp_SG_GW_SAS_ALPCAN(&pcan_msg_sas);
      signal->steering_wheel_angle = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerWheelAngle, SteeringWheelAngle);
      signal->steering_wheel_angle_range_counter =
         CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerWheelAngleRangeCounter, SteeringWheelAngleRangeCounter);
      signal->steering_wheel_angle_range_counter_type =
         CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerWheelAngleRangeCounterType, SteeringWheelAngleRangeCounterTy);
      signal->steering_wheel_angle_range = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerWheelAngleRange, SteeringWheelAngleRange);
      signal->active_mode                = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerAngleSensorActiveMode, ActiveMode);
      signal->calibrated                 = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.SteerAngleSensorCalibrated, Calibrated);
      signal->message_counter            = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.MessageCounter, MessageCounter);
      signal->message_checksum_          = CAN_RX_SIGNAL_CORRECTION(pcan_msg_sas.MessageChecksum, MessageChecksum);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_4_ALPCAN_Vdp_SG_GW_CLS_Tx_4_ALPCAN(&pcan_msg_cls_tx_4);
      signal->reverse_switch_info = CAN_RX_SIGNAL_CORRECTION(pcan_msg_cls_tx_4.ReverseSwitchInfo, ReverseSwitchInfo);
      signal->ignition            = CAN_RX_SIGNAL_CORRECTION(pcan_msg_cls_tx_4.Ignition, Ignition);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VI_ALPCAN_Vdp_SG_GW_VI_ALPCAN(&pcan_msg_vi);
      signal->vehicle_identification = CAN_RX_SIGNAL_CORRECTION(pcan_msg_vi.VehicleIdentification, VehicleIdentification);
   }
   else
   {
      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CCVS1_ALVCAN_Vdp_SG_CCVS1_ALVCAN(&vcan_msg_ccvs1);
      signal->wheel_base_vehicle_speed = CAN_RX_SIGNAL_CORRECTION(vcan_msg_ccvs1.WheelBasedVehicleSpeed, WheelBasedVehicleSpeed);
      signal->parking_brake_switch     = CAN_RX_SIGNAL_CORRECTION(vcan_msg_ccvs1.ParkingBrakeSwitch, ParkingBrakeSwitch);
      signal->brake_switch             = CAN_RX_SIGNAL_CORRECTION(vcan_msg_ccvs1.BrakeSwitch, BrakeSwitch);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_16_ALVCAN_Vdp_SG_CLS_Tx_16_ALVCAN(&vcan_msg_cls_tx_16);
      signal->crawler_confi_status_info =
         CAN_RX_SIGNAL_CORRECTION(vcan_msg_cls_tx_16.Crawler_confi_status_info, Crawler_confi_status_info);
      signal->transmission_type_info = CAN_RX_SIGNAL_CORRECTION(vcan_msg_cls_tx_16.Transmission_type_info, Transmission_type_info);

      if ((signal->transmission_type_info == TRANSMISSION_TYPE_AT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_6S_AMT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_9S_AMT_VARIANT) ||
          (signal->transmission_type_info == TRANSMISSION_TYPE_12S_AMT_VARIANT))
      {
         /* ETC2_03 — transmission current gear */
         (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_03_ALVCAN_Vdp_SG_ETC2_03_ALVCAN(&vcan_msg_etc2_03);
         signal->trans_current_gear = CAN_RX_SIGNAL_CORRECTION(vcan_msg_etc2_03.TransCurrentGear_03, TransCurrentGear_03);
      }
      else if (signal->transmission_type_info == TRANSMISSION_TYPE_MT_VARIANT)
      {
         /* ETC2_00 — transmission current gear */
         (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_00_ALVCAN_Vdp_SG_ETC2_00_ALVCAN(&vcan_msg_etc2_00);
         signal->trans_current_gear = CAN_RX_SIGNAL_CORRECTION(vcan_msg_etc2_00.TransCurrentGear_00, TransCurrentGear_00);
      }

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VD_ALVCAN_Vdp_SG_VD_ALVCAN(&vcan_msg_vd);
      signal->total_vehicle_distance = CAN_RX_SIGNAL_CORRECTION(vcan_msg_vd.Total_vehicle_distance, Total_vehicle_distance);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VDC2_ALVCAN_Vdp_SG_VDC2_ALVCAN(&vcan_msg_vdc2);
      signal->yaw_rate             = CAN_RX_SIGNAL_CORRECTION(vcan_msg_vdc2.YawRate, YawRate);
      signal->lateral_acceleration = CAN_RX_SIGNAL_CORRECTION(vcan_msg_vdc2.LateralAcceleration, LateralAcceleration);
      signal->longitudinal_acceleration =
         CAN_RX_SIGNAL_CORRECTION(vcan_msg_vdc2.LongitudinalAcceleration, LongitudinalAcceleration);
      signal->steer_wheel_angle = CAN_RX_SIGNAL_CORRECTION(vcan_msg_vdc2.SteerWheelAngle, SteerWheelAngle);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_TD_ALVCAN_Vdp_SG_TD_ALVCAN(&vcan_msg_td);
      signal->seconds             = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Seconds, Seconds);
      signal->minutes             = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Minutes, Minutes);
      signal->hours               = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Hours, Hours);
      signal->month               = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Month, Month);
      signal->day                 = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Day, Day);
      signal->year                = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.Year, Year);
      signal->local_minute_offset = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.LocalMinuteOffset, LocalMinuteOffset);
      signal->local_hour_offset   = CAN_RX_SIGNAL_CORRECTION(vcan_msg_td.LocalHourOffset, LocalHourOffset);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_OEL_ALVCAN_Vdp_SG_OEL_ALVCAN(&vcan_msg_oel);
      signal->turn_signal_switch   = CAN_RX_SIGNAL_CORRECTION(vcan_msg_oel.TurnSignalSwitch, TurnSignalSwitch);
      signal->hazard_light_switch  = CAN_RX_SIGNAL_CORRECTION(vcan_msg_oel.HazardLightSwitch, HazardLightSwitch);
      signal->high_low_beam_switch = CAN_RX_SIGNAL_CORRECTION(vcan_msg_oel.HighLowBeamSwitch, HighLowBeamSwitch);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ADAS_FN_Enable_disable_sts_ALVCAN_Vdp_SG_ADAS_FN_Enable_disable_sts_ALVCAN(
         &vcan_msg_adas_fn);
      signal->mois_fn_switch_sts         = CAN_RX_SIGNAL_CORRECTION(vcan_msg_adas_fn.MOIS_Fn_Switch_sts, MOIS_Fn_Switch_sts);
      signal->mois_fn_enable_disable_sts = signal->mois_fn_switch_sts;
      signal->message_alive_counter      = CAN_RX_SIGNAL_CORRECTION(vcan_msg_adas_fn.MessageAliveCounter, MessageAliveCounter);
      signal->message_crc                = CAN_RX_SIGNAL_CORRECTION(vcan_msg_adas_fn.MessageCRC, MessageCRC);
      signal->bsis_fn_switch_sts         = CAN_RX_SIGNAL_CORRECTION(vcan_msg_adas_fn.BSIS_Fn_Switch_Sts, BSIS_Fn_Switch_Sts);
      signal->bsis_fn_enable_disable_sts = signal->bsis_fn_switch_sts;

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_SAS_ALVCAN_Vdp_SG_SAS_ALVCAN(&vcan_msg_sas);
      signal->steering_wheel_angle = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.SteeringWheelAngle, SteeringWheelAngle);
      signal->steering_wheel_angle_range_counter =
         CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.SteeringWheelAngleRangeCounter, SteeringWheelAngleRangeCounter);
      signal->steering_wheel_angle_range_counter_type =
         CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.SteeringWheelAngleRangeCounterType, SteeringWheelAngleRangeCounterTy);
      signal->steering_wheel_angle_range = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.SteeringWheelAngleRange, SteeringWheelAngleRange);
      signal->active_mode                = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.ActiveMode, ActiveMode);
      signal->calibrated                 = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.Calibrated, Calibrated);
      signal->message_counter            = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.MessageCounter, MessageCounter);
      signal->message_checksum_          = CAN_RX_SIGNAL_CORRECTION(vcan_msg_sas.MessageChecksum, MessageChecksum);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_4_ALVCAN_Vdp_SG_CLS_Tx_4_ALVCAN(&vcan_msg_cls_tx_4);
      signal->reverse_switch_info = CAN_RX_SIGNAL_CORRECTION(vcan_msg_cls_tx_4.ReverseSwitchInfo, ReverseSwitchInfo);
      signal->ignition            = CAN_RX_SIGNAL_CORRECTION(vcan_msg_cls_tx_4.Ignition, Ignition);

      (void)Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VI_ALVCAN_Vdp_SG_VI_ALVCAN(&vcan_msg_vi);
      signal->vehicle_identification = CAN_RX_SIGNAL_CORRECTION(vcan_msg_vi.VehicleIdentification, VehicleIdentification);
   }
}

   /**
    * @brief L1 feature degradation flag handling for partner sensor.
    * @param void
    * @return void
    * PRS requirements to be considered for testing
    * 1) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106822
    * 2) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106824
    * 3) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106844
    * 4) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106846
    * 5) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-106849
    * 6) https://polarion.asux.aptiv.com/polarion/#/project/ASHOKLEYLAND_ADAS/workitem?id=PAA-118163
    */
   #if defined(FEATURE_ENABLE)
static void L1_BSIS_Feature_Degradation_Check(L1_Feature_Degradation_Params_T L1_Feature_Degradation_Params)
{
   uint8_t partner_sensor_blockage_cond1 =
      (DRA_BLOCKAGE_STATUS_OK == L1_Feature_Degradation_Params.l1_sensor_blocked_sts) &&
      ((DRA_BLOCKAGE_VALUE_NOT_BLOCKED != L1_Feature_Degradation_Params.l1_sensor_block_value) &&
       (DRA_BLOCKAGE_VALUE_SLIGHTLY_BLOCKED != L1_Feature_Degradation_Params.l1_sensor_block_value));
   uint8_t partner_sensor_blockage_cond2 =
      (DRA_BLOCKAGE_STATUS_FAULTY == L1_Feature_Degradation_Params.l1_sensor_blocked_sts) ||
      (0x4U == L1_Feature_Degradation_Params.l1_sensor_blocked_sts); // in software 255 is invalid(DRA_BLOCKAGE_STATUS_INVALID)
   uint8_t partner_sensor_blocked = partner_sensor_blockage_cond1 || partner_sensor_blockage_cond2;
   uint8_t parter_sensor_no_blockage =
      ((DRA_BLOCKAGE_STATUS_OK == L1_Feature_Degradation_Params.l1_sensor_blocked_sts) &&
       ((DRA_BLOCKAGE_VALUE_NOT_BLOCKED == L1_Feature_Degradation_Params.l1_sensor_block_value) ||
        (DRA_BLOCKAGE_VALUE_SLIGHTLY_BLOCKED == L1_Feature_Degradation_Params.l1_sensor_block_value)));

   uint8_t align_no_calib_flt = (((L1_Feature_Degradation_Params.l1_fault_table_11_15 >> 8) & 0xFF) & 0x2);

   if (Cx1_SYNCED_AT_LEAST_ONCE == L1_Feature_Degradation_Params.l1_time_sync_validity_flag)
   {
      L1_BSIS_Feature_Degradation_Flags.l1_time_sync_validity_degraded_flag = CODED_FALSE;
   }
   else if ((Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR == L1_Feature_Degradation_Params.l1_time_sync_validity_flag) ||
            (Cx0_OUT_OF_SYNC == L1_Feature_Degradation_Params.l1_time_sync_validity_flag))
   {
      L1_BSIS_Feature_Degradation_Flags.l1_time_sync_validity_degraded_flag = CODED_TRUE;
   }

   if (Cx2_Operational == L1_Feature_Degradation_Params.l1_op_mode)
   {
      L1_BSIS_Feature_Degradation_Flags.l1_op_mode_degraded_flag = CODED_FALSE;
   }
   else if ((Cx0_Init_MCU == L1_Feature_Degradation_Params.l1_op_mode) ||
            (Cx1_Radar_Not_Configured == L1_Feature_Degradation_Params.l1_op_mode) ||
            (Cx3_OpMode_Faulty == L1_Feature_Degradation_Params.l1_op_mode))
   {
      L1_BSIS_Feature_Degradation_Flags.l1_op_mode_degraded_flag = CODED_TRUE;
   }

   if (parter_sensor_no_blockage)
   {
      L1_BSIS_Feature_Degradation_Flags.l1_sensor_blockage_degraded_flag = CODED_FALSE;
   }
   else if (partner_sensor_blocked)
   {
      L1_BSIS_Feature_Degradation_Flags.l1_sensor_blockage_degraded_flag = CODED_TRUE;
   }

   if ((false == (uint8_t)align_no_calib_flt) && ((Cx1_AAstatus_Active == L1_Feature_Degradation_Params.l1_alignment_auto_sts) ||
                                                  (Cx2_AAstatus_Paused == L1_Feature_Degradation_Params.l1_alignment_auto_sts)))
   {
      L1_BSIS_Feature_Degradation_Flags.l1_align_no_calib_auto_sts_degraded_flag = CODED_FALSE;
   }
   else if ((true == (uint8_t)align_no_calib_flt) ||
            ((Cx0_AAstatus_Off == L1_Feature_Degradation_Params.l1_alignment_auto_sts) ||
             (Cx3_AAstatus_Failed == L1_Feature_Degradation_Params.l1_alignment_auto_sts)))
   {
      L1_BSIS_Feature_Degradation_Flags.l1_align_no_calib_auto_sts_degraded_flag = CODED_TRUE;
   }

   L1_BSIS_Feat_Degrade_Flag = ((CODED_TRUE == L1_BSIS_Feature_Degradation_Flags.l1_time_sync_validity_degraded_flag) ||
                                (CODED_TRUE == L1_BSIS_Feature_Degradation_Flags.l1_op_mode_degraded_flag) ||
                                (CODED_TRUE == L1_BSIS_Feature_Degradation_Flags.l1_sensor_blockage_degraded_flag) ||
                                (CODED_TRUE == L1_BSIS_Feature_Degradation_Flags.l1_align_no_calib_auto_sts_degraded_flag)) ?
                                  CODED_TRUE :
                                  CODED_FALSE;
}

/**
 * @param void
 * @return L1 degradation flag status for the partner sensor.
 */
uint8_t Get_L1_BSIS_Degradation_Flag_Sts(void)
{
   return L1_BSIS_Feat_Degrade_Flag;
}
   #endif

/**
 * @brief populate the sensor fusion header, status, and alignment data for partner sensor over IPC structure.
 * @param void
 * @return void
 */
static void Process_Sensor_Fusion_Header_Status_Align_Data(void)
{
   M2D_Msg_T *const m2d_msg                    = (M2D_Msg_T *const)Get_MSS_IPC_M2D_Msg_Buffer();
   Partner_Sensor_Stream_T *const partner_data = &m2d_msg->payload.partners_data;
   I_SG_Fusion_RadarCapability_ALPCAN Radar_Capability_Message;
   I_SG_Fusion_RadarStatus2_ALPCAN Radar_Status2_Message;
   Rte_Read_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN(&Radar_Status2_Message);
   Rte_Read_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN(&Radar_Capability_Message);
   Rte_Read_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN(&Radar_Header_Message);
   Rte_Read_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN(&Radar_Status1_Message);
   Rte_Read_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN(&Radar_Align1_Message);
   sint16 signed_value = 0;

   #if defined(FEATURE_ENABLE)
   L1_Feature_Degradation_Params.l1_time_sync_validity_flag =
      CAN_RX_SIGNAL_CORRECTION(Radar_Header_Message.HED_TIME_SYNC_VALIDITY_FLAG_Rx, HED_TIME_SYNC_VALIDITY_FLAG_Rx);
   L1_Feature_Degradation_Params.l1_op_mode =
      CAN_RX_SIGNAL_CORRECTION(Radar_Header_Message.HED_OPERATION_MODE_Rx, HED_OPERATION_MODE_Rx);
   L1_Feature_Degradation_Params.l1_sensor_blocked_sts =
      CAN_RX_SIGNAL_CORRECTION(Radar_Capability_Message.CAP_BlockageStatus_Rx, CAP_BlockageStatus_Rx);
   L1_Feature_Degradation_Params.l1_sensor_block_value =
      CAN_RX_SIGNAL_CORRECTION(Radar_Capability_Message.CAP_BlockageValue_Rx, CAP_BlockageValue_Rx);
   L1_Feature_Degradation_Params.l1_alignment_auto_sts =
      CAN_RX_SIGNAL_CORRECTION(Radar_Align1_Message.STS_AlignmentAutoStatus_Rx, STS_AlignmentAutoStatus_Rx);
   L1_Feature_Degradation_Params.l1_fault_table_11_15 =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status2_Message.STS_CORE_ACTV_FLT_BYTE_11_to_15_Rx, STS_CORE_ACTV_FLT_BYTE_11_to_15_Rx);

   L1_BSIS_Feature_Degradation_Check(L1_Feature_Degradation_Params);
   #endif

   partner_data->partner_sensor_det_data.num_af_det = MIN(Radar_Header_Message.HED_NUM_OF_VALID_DETECTIONS_Rx, MAX_TARGET_REPORTS);
   partner_data->partner_det_list_property_data[0].look_index           = Radar_Header_Message.HED_LOOK_INDEX_Rx;
   partner_data->partner_det_list_property_data[0].look_type            = Radar_Header_Message.HED_LOOK_ID_Rx;
   partner_data->partner_det_list_property_data[0].radar_position       = Radar_Status1_Message.STS_SENSOR_POSITION_Rx;
   partner_data->partner_det_list_property_data[0].ts_mid_dwell_nanosec = Radar_Header_Message.HED_SENSOR_TIME_STAMP_NS_Rx;
   partner_data->partner_det_list_property_data[0].ts_mid_dwell_sec     = Radar_Header_Message.HED_SENSOR_TIME_STAMP_SEC_Rx;
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_pos_x =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_POS_X_Rx, STS_SENSOR_MOUNT_POS_X);
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_pos_y =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_POS_Y_Rx, STS_SENSOR_MOUNT_POS_Y);
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_pos_z =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_POS_Z_Rx, STS_SENSOR_MOUNT_POS_Z);
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_ORNT_YAW_Rx, STS_SENSOR_MOUNT_ORNT_YAW);
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_ORNT_PITCH_Rx, STS_SENSOR_MOUNT_ORNT_PITCH);
   partner_data->partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll =
      CAN_RX_SIGNAL_CORRECTION(Radar_Status1_Message.STS_SENSOR_MOUNT_ORNT_ROLL_Rx, STS_SENSOR_MOUNT_ORNT_ROLL);

   /* Direct sint16 typecast wont work as signal length is 15.
   The below lines will mmic the uint to sint typecast for 15bits */
   if (Radar_Align1_Message.STS_AACurrentAzimuth_Rx < 16384)
   {
      signed_value = Radar_Align1_Message.STS_AACurrentAzimuth_Rx;
   }
   else
   {
      signed_value = Radar_Align1_Message.STS_AACurrentAzimuth_Rx - 32768;
   }
   partner_data->partner_sensor_alignment_info[0].vacs_boresight_az_estimated =
      CAN_RX_SIGNAL_CORRECTION(signed_value, STS_AACurrentAzimuth);

   /* The below lines will mmic the uint to sint typecast for 11bits */
   if (Radar_Align1_Message.STS_AACurrentElevation_Rx < 1024)
   {
      signed_value = Radar_Align1_Message.STS_AACurrentElevation_Rx;
   }
   else
   {
      signed_value = Radar_Align1_Message.STS_AACurrentElevation_Rx - 2048;
   }
   partner_data->partner_sensor_alignment_info[0].vacs_boresight_el_estimated =
      CAN_RX_SIGNAL_CORRECTION(signed_value, STS_AACurrentElevation);

   partner_data->partner_sensor_alignment_info[0].alignment_mode =
      CAN_RX_SIGNAL_CORRECTION(Radar_Align1_Message.STS_AlignmentModeOut_Rx, STS_AlignmentModeOut);
   partner_data->partner_sensor_alignment_info[0].alignment_error_status_combined =
      (CAN_RX_SIGNAL_CORRECTION(Radar_Align1_Message.STS_AlignmentAutoStatus_Rx, STS_AlignmentAutoStatus) == 1) ? 0 : 1;

   if (partner_data->partner_det_list_property_data[0].radar_position != 0U)
   {
      partner_data->partner_sensor_diag_data[0].status_recvd_flag = 1U;
   }
   Delta_Vehicle_Status_msg.af_core_throughput = Radar_Status2_Message.STS_AF_CORE_THROUGHPUT_Rx;
   Delta_Vehicle_Status_msg.blockage_value     = Radar_Capability_Message.CAP_BlockageValue_Rx;
   Delta_Vehicle_Status_msg.hed_operation_mode = Radar_Header_Message.HED_OPERATION_MODE_Rx;
   Delta_Vehicle_Status_msg.hed_data_qualifier = Radar_Header_Message.HED_DATA_QUALIFIER_Rx;
   Delta_Vehicle_Status_msg.Blockage_status    = Radar_Capability_Message.CAP_BlockageStatus_Rx;

   partner_data->partner_sensor_blockage_info[0].blockage_value  = Delta_Vehicle_Status_msg.blockage_value;
   partner_data->partner_sensor_blockage_info[0].blockage_status = Delta_Vehicle_Status_msg.Blockage_status;
   partner_data->partner_sensor_diag_data[0].data_qualifier      = Delta_Vehicle_Status_msg.hed_data_qualifier;
   partner_data->partner_sensor_diag_data[0].operation_mode      = Delta_Vehicle_Status_msg.hed_operation_mode;
}

/**
 * @brief populate the sensor fusion detection data for partner sensor over IPC structure.
 * @param void
 * @return void
 */
static void Process_Sensor_Fusion_Detections(void)
{
   M2D_Msg_T *const m2d_msg                    = (M2D_Msg_T *const)Get_MSS_IPC_M2D_Msg_Buffer();
   Partner_Sensor_Stream_T *const partner_data = &m2d_msg->payload.partners_data;
   const uint32_t signal_per_msg               = 4U;
   // const uint32_t max_detections_messages      = MIN(Rte_Read_Can_Msg_From_Sensors.size, MAX_TARGET_REPORTS / signal_per_msg);
   const uint32_t max_detections_messages = MAX_DETECTION_MSG_SRR_L1;
   uint32_t det_msg_success_count         = 0U;

   for (uint8_t msg_idx = 0U; msg_idx < max_detections_messages; msg_idx++)
   {
      I_SG_Fusion_Detections_001_004_AL fusion_msg            = {0};
      Read_Can_Fusion_Detection_Msg_Func_Ptr rte_read_can_msg = Rte_Read_Can_Msg_From_Sensors.read_functions[msg_idx];
      if (NULL != rte_read_can_msg)
      {
         Std_ReturnType result = rte_read_can_msg(&fusion_msg);
         if (E_OK == result)
         {
            det_msg_success_count++;

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].ran =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_001_Rx, DET_RANGE);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].ran =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_002_Rx, DET_RANGE);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].ran =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_003_Rx, DET_RANGE);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].ran =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_004_Rx, DET_RANGE);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].snr =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SNR_001_Rx, DET_SNR);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].snr =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SNR_002_Rx, DET_SNR);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].snr =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SNR_003_Rx, DET_SNR);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].snr =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SNR_004_Rx, DET_SNR);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].vel =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_VELOCITY_001_Rx, DET_RANGE_VELOCITY);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].vel =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_VELOCITY_002_Rx, DET_RANGE_VELOCITY);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].vel =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_VELOCITY_003_Rx, DET_RANGE_VELOCITY);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].vel =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RANGE_VELOCITY_004_Rx, DET_RANGE_VELOCITY);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].theta =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_AZIMUTH_001_Rx, DET_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].theta =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_AZIMUTH_002_Rx, DET_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].theta =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_AZIMUTH_003_Rx, DET_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].theta =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_AZIMUTH_004_Rx, DET_AZIMUTH);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].phi =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_ELEVATION_001_Rx, DET_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].phi =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_ELEVATION_002_Rx, DET_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].phi =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_ELEVATION_003_Rx, DET_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].phi =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_ELEVATION_004_Rx, DET_ELEVATION);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].rcs =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RCS_001_Rx, DET_RCS);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].rcs =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RCS_002_Rx, DET_RCS);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].rcs =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RCS_003_Rx, DET_RCS);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].rcs =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_RCS_004_Rx, DET_RCS);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].az_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_AZIMUTH_001_Rx, DET_CONFD_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].az_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_AZIMUTH_002_Rx, DET_CONFD_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].az_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_AZIMUTH_003_Rx, DET_CONFD_AZIMUTH);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].az_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_AZIMUTH_004_Rx, DET_CONFD_AZIMUTH);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].el_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_ELEVATION_001_Rx, DET_CONFD_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].el_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_ELEVATION_002_Rx, DET_CONFD_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].el_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_ELEVATION_003_Rx, DET_CONFD_ELEVATION);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].el_conf =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_CONFD_ELEVATION_004_Rx, DET_CONFD_ELEVATION);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].f_superres_target =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SUPER_RES_TARGET_001_Rx, DET_SUPER_RES_TARGET);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].f_superres_target =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SUPER_RES_TARGET_002_Rx, DET_SUPER_RES_TARGET);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].f_superres_target =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SUPER_RES_TARGET_003_Rx, DET_SUPER_RES_TARGET);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].f_superres_target =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_SUPER_RES_TARGET_004_Rx, DET_SUPER_RES_TARGET);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].f_bistatic =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_BI_STATIC_FLAG_001_Rx, DET_BI_STATIC_FLAG);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].f_bistatic =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_BI_STATIC_FLAG_002_Rx, DET_BI_STATIC_FLAG);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].f_bistatic =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_BI_STATIC_FLAG_003_Rx, DET_BI_STATIC_FLAG);
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].f_bistatic =
               CAN_RX_SIGNAL_CORRECTION(fusion_msg.DET_BI_STATIC_FLAG_004_Rx, DET_BI_STATIC_FLAG);

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].f_ci_det = 0U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].f_ci_det = 0U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].f_ci_det = 0U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].f_ci_det = 0U;

            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 0U].sensor_id = 2U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 1U].sensor_id = 2U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 2U].sensor_id = 2U;
            partner_data->partner_sensor_det_data.ps_dets[msg_idx * signal_per_msg + 3U].sensor_id = 2U;
         }
         else
         {
            /* do nothing */
            /* keep values from last detection message */
         }
      }
      else
      {
         /* do nothing */
         /* RTE not available for reading message*/
      }
   }

   /* Only set flag if we received all expected detection messages */
   partner_data->partner_sensor_diag_data[0].det_recvd_flag = (det_msg_success_count == max_detections_messages) ? 1U : 0U;
}
#else
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
/**
 * @brief Processes received CAN messages and updates vehicle status signals.
 * This function reads the vehicle status from the CAN message using the RTE interface,
 * @param void
 * @return void
 */
static void Process_Vehicle_Status(void)
{
   // Std_ReturnType ret_vehStatus;
   I_SG_VehicleStatus_AL Vehicle_Status;
   Std_ReturnType result = GET_VEHICLE_STATUS_FROM_CAN(&Vehicle_Status);
   if (E_OK == result)
   {
      VCAN_Rx_Signals.SSTS_CAN_PCAN_MAJOR_ADAS     = Vehicle_Status.SSTS_CAN_PCAN_MAJOR_ADAS;
      VCAN_Rx_Signals.SSTS_CAN_PCAN_MINOR_ADAS     = Vehicle_Status.SSTS_CAN_PCAN_MINOR_ADAS;
      VCAN_Rx_Signals.SSTS_DRIVE_DIR               = Vehicle_Status.SSTS_DRIVE_DIR;
      VCAN_Rx_Signals.SSTS_DRIVE_REVERSE           = Vehicle_Status.SSTS_DRIVE_REVERSE;
      VCAN_Rx_Signals.SSTS_GEAR_POSITION           = Vehicle_Status.SSTS_GEAR_POSITION;
      VCAN_Rx_Signals.SSTS_IGN_STATUS              = Vehicle_Status.SSTS_IGN_STATUS;
      VCAN_Rx_Signals.SSTS_MH_VS_CRC16             = Vehicle_Status.SSTS_MH_VS_CRC16;
      VCAN_Rx_Signals.SSTS_MH_VS_CYCLE_COUNTER     = Vehicle_Status.SSTS_MH_VS_CYCLE_COUNTER;
      VCAN_Rx_Signals.SSTS_STEERING_ANGLE          = Vehicle_Status.SSTS_STEERING_ANGLE;
      VCAN_Rx_Signals.SSTS_STEERING_ANGLE_SIGN     = Vehicle_Status.SSTS_STEERING_ANGLE_SIGN;
      VCAN_Rx_Signals.SSTS_SW_VERSION_ADAS         = Vehicle_Status.SSTS_SW_VERSION_ADAS;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Day    = Vehicle_Status.SSTS_VEH_AbsoluteTime_Day;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Hour   = Vehicle_Status.SSTS_VEH_AbsoluteTime_Hour;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Minute = Vehicle_Status.SSTS_VEH_AbsoluteTime_Minute;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Month  = Vehicle_Status.SSTS_VEH_AbsoluteTime_Month;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Second = Vehicle_Status.SSTS_VEH_AbsoluteTime_Second;
      VCAN_Rx_Signals.SSTS_VEH_AbsoluteTime_Year   = Vehicle_Status.SSTS_VEH_AbsoluteTime_Year;
      VCAN_Rx_Signals.SSTS_VEH_ODOMETER            = Vehicle_Status.SSTS_VEH_ODOMETER;
      VCAN_Rx_Signals.SSTS_VEH_POWER_MODE_STATUS   = Vehicle_Status.SSTS_VEH_POWER_MODE_STATUS;
      VCAN_Rx_Signals.SSTS_VEH_SPD_COMP_FACTOR     = Vehicle_Status.SSTS_VEH_SPD_COMP_FACTOR;
      VCAN_Rx_Signals.SSTS_VEH_SYSTEM_VOLTAGE      = Vehicle_Status.SSTS_VEH_SYSTEM_VOLTAGE;
      VCAN_Rx_Signals.SSTS_VEHICLE_SPEED_CALC      = Vehicle_Status.SSTS_VEHICLE_SPEED_CALC;
      VCAN_Rx_Signals.SSTS_VEHICLE_SPEED_CALC_QF   = Vehicle_Status.SSTS_VEHICLE_SPEED_CALC_QF;
      VCAN_Rx_Signals.SSTS_VEHICLE_STATE           = Vehicle_Status.SSTS_VEHICLE_STATE;
      VCAN_Rx_Signals.SSTS_YAW_RATE_BIAS           = Vehicle_Status.SSTS_YAW_RATE_BIAS;
      VCAN_Rx_Signals.SSTS_YAW_RATE_CALC           = Vehicle_Status.SSTS_YAW_RATE_CALC;
      VCAN_Rx_Signals.SSTS_YAW_RATE_CALC_QF        = Vehicle_Status.SSTS_YAW_RATE_CALC_QF;
   }
   else
   {
      /* keep last received signal values */
      /* do nothing */
   }
}
#endif
/* VCAN timeout faults for safety critical Messages */

/**
 * @brief Callback for reception of CCVS1 message.
 *
 * This function is called when the CCVS1 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CCVS1_message_timeout_fault_pass++;
      Vcan_CCVS1_message_timeout_fault_fail = 0;
      if (Vcan_CCVS1_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of CCVS1 message.
 *
 * This function is called when the CCVS1 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CCVS1_message_timeout_fault_fail++;
      Vcan_CCVS1_message_timeout_fault_pass = 0;
      if (Vcan_CCVS1_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for VCAN message timeout of ETC2_00.
 *
 * This function is called when the VCAN message ETC2_00 times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ETC2_00_message_timeout_fault_pass++;
      Vcan_ETC2_00_message_timeout_fault_fail = 0;
      if (Vcan_ETC2_00_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of ETC2_00 message.
 *
 * This function is called when the ETC2_00 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ETC2_00_message_timeout_fault_fail++;
      Vcan_ETC2_00_message_timeout_fault_pass = 0;
      if (Vcan_ETC2_00_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of VDC2 message.
 *
 * This function is called when the VDC2 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_VDC2_message_timeout_fault_pass++;
      Vcan_VDC2_message_timeout_fault_fail = 0;
      if (Vcan_VDC2_message_timeout_fault_pass >= 10)
      {
         Rte_Write_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of VDC2 message.
 *
 * This function is called when the VDC2 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_VDC2_message_timeout_fault_fail++;
      Vcan_VDC2_message_timeout_fault_pass = 0;
      if (Vcan_VDC2_message_timeout_fault_fail >= 10)
      {
         Rte_Write_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of ETC2_03 message.
 *
 * This function is called when the ETC2_03 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ETC2_03_message_timeout_fault_pass++;
      Vcan_ETC2_03_message_timeout_fault_fail = 0;
      if (Vcan_ETC2_03_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of ETC2_03 message.
 *
 * This function is called when the ETC2_03 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ETC2_03_message_timeout_fault_fail++;
      Vcan_ETC2_03_message_timeout_fault_pass = 0;
      if (Vcan_ETC2_03_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/* VCAN timeout faults for safety critical Messages for SRR_L1,L2 using Pcan */
/**
 * @brief Callback for reception of GW_CCVS1 message.
 *
 * This function is called when the GW_CCVS1 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_CCVS1_message_timeout_fault_pass++;
      Pcan_GW_CCVS1_message_timeout_fault_fail = 0;
      if (Pcan_GW_CCVS1_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_CCVS1 message.
 *
 * This function is called when the GW_CCVS1 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_CCVS1_message_timeout_fault_fail++;
      Pcan_GW_CCVS1_message_timeout_fault_pass = 0;
      if (Pcan_GW_CCVS1_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_ETC2 message.
 *
 * This function is called when the GW_ETC2 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_ETC2_message_timeout_fault_pass++;
      Pcan_GW_ETC2_message_timeout_fault_fail = 0;
      if (Pcan_GW_ETC2_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_ETC2 message.
 *
 * This function is called when the GW_ETC2 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_ETC2_message_timeout_fault_fail++;
      Pcan_GW_ETC2_message_timeout_fault_pass = 0;
      if (Pcan_GW_ETC2_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_VDC2 message.
 *
 * This function is called when the GW_VDC2 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_VDC2_message_timeout_fault_pass++;
      Pcan_GW_VDC2_message_timeout_fault_fail = 0;
      if (Pcan_GW_VDC2_message_timeout_fault_pass >= 10)
      {
         Rte_Write_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_VDC2 message.
 *
 * This function is called when the GW_VDC2 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx(void)
{
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_VDC2_message_timeout_fault_fail++;
      Pcan_GW_VDC2_message_timeout_fault_pass = 0;
      if (Pcan_GW_VDC2_message_timeout_fault_fail >= 10)
      {
         Rte_Write_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_ETC2_03 message.
 *
 * This function is called when the GW_ETC2_03 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_ETC2_03_message_timeout_fault_pass++;
      Pcan_GW_ETC2_03_message_timeout_fault_fail = 0;
      if (Pcan_GW_ETC2_03_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_ETC2_03 message.
 *
 * This function is called when the GW_ETC2_03 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_ETC2_03_message_timeout_fault_fail++;
      Pcan_GW_ETC2_03_message_timeout_fault_pass = 0;
      if (Pcan_GW_ETC2_03_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/* VCAN timeout faults for Non-safety critical Messages */
/**
 * @brief Callback for reception of ADAS_FN_Enable_disable_sts message.
 *
 * This function is called when the ADAS_FN_Enable_disable_sts message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass++;
      Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail = 0;
      if (Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
         Vcan_ADAS_FN_message_timeout_fault = CODED_FALSE;
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of ADAS_FN_Enable_disable_sts message.
 *
 * This function is called when the ADAS_FN_Enable_disable_sts message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE)
ComTimeoutNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail++;
      Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass = 0;
      if (Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
         Vcan_ADAS_FN_message_timeout_fault = CODED_TRUE;
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of CLS_Tx_16 message.
 *
 * This function is called when the CLS_Tx_16 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CLS_Tx_16_message_timeout_fault_pass++;
      Vcan_CLS_Tx_16_message_timeout_fault_fail = 0;
      if (Vcan_CLS_Tx_16_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of CLS_Tx_16 message.
 *
 * This function is called when the CLS_Tx_16 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CLS_Tx_16_message_timeout_fault_fail++;
      Vcan_CLS_Tx_16_message_timeout_fault_pass = 0;
      if (Vcan_CLS_Tx_16_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of CLS_Tx_4 message.
 *
 * This function is called when the CLS_Tx_4 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CLS_Tx_4_message_timeout_fault_pass++;
      Vcan_CLS_Tx_4_message_timeout_fault_fail = 0;
      if (Vcan_CLS_Tx_4_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of CLS_Tx_4 message.
 *
 * This function is called when the CLS_Tx_4 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_CLS_Tx_4_message_timeout_fault_fail++;
      Vcan_CLS_Tx_4_message_timeout_fault_pass = 0;
      if (Vcan_CLS_Tx_4_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of OEL message.
 *
 * This function is called when the OEL message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_OEL_message_timeout_fault_pass++;
      Vcan_OEL_message_timeout_fault_fail = 0;
      if (Vcan_OEL_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of OEL message.
 *
 * This function is called when the OEL message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_OEL_message_timeout_fault_fail++;
      Vcan_OEL_message_timeout_fault_pass = 0;
      if (Vcan_OEL_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of TD message.
 *
 * This function is called when the TD message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_TD_message_timeout_fault_pass++;
      Vcan_TD_message_timeout_fault_fail = 0;
      if (Vcan_TD_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of TD message.
 *
 * This function is called when the TD message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_TD_message_timeout_fault_fail++;
      Vcan_TD_message_timeout_fault_pass = 0;
      if (Vcan_TD_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of VD message.
 *
 * This function is called when the VD message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_VD_message_timeout_fault_pass++;
      Vcan_VD_message_timeout_fault_fail = 0;
      if (Vcan_VD_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of VD message.
 *
 * This function is called when the VD message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_VD_message_timeout_fault_fail++;
      Vcan_VD_message_timeout_fault_pass = 0;
      if (Vcan_VD_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of SAS message.
 *
 * This function is called when the SAS message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_SAS_message_timeout_fault_pass++;
      Vcan_SAS_message_timeout_fault_fail = 0;
      if (Vcan_SAS_message_timeout_fault_pass >= 10)
      {
         Rte_Write_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of SAS message.
 *
 * This function is called when the SAS message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_FC)
   {
      Vcan_SAS_message_timeout_fault_fail++;
      Vcan_SAS_message_timeout_fault_pass = 0;
      if (Vcan_SAS_message_timeout_fault_fail >= 10)
      {
         Rte_Write_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of GW_VD message.
 *
 * This function is called when the GW_VD message is received on the bus.
 * No parameters.
 */

/* VCAN timeout faults for Non-safety critical Messages for SRR_L1,L2 using Pcan */

/**
 * @brief Callback for reception of GW_ADAS_FN_Enable_disable_sts message.
 *
 * This function is called when the GW_ADAS_FN_Enable_disable_sts message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE)
ComNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass++;
      Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail = 0;
      if (Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_ADAS_FN_Enable_disable_sts message.
 *
 * This function is called when the GW_ADAS_FN_Enable_disable_sts message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE)
ComTimeoutNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail++;
      Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass = 0;
      if (Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_CLS_Tx_16 message.
 *
 * This function is called when the GW_CLS_Tx_16 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_CLS_Tx_16_message_timeout_fault_pass++;
      Pcan_CLS_Tx_16_message_timeout_fault_fail = 0;
      if (Pcan_CLS_Tx_16_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_CLS_Tx_16 message.
 *
 * This function is called when the GW_CLS_Tx_16 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_CLS_Tx_16_message_timeout_fault_fail++;
      Pcan_CLS_Tx_16_message_timeout_fault_pass = 0;
      if (Pcan_CLS_Tx_16_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of GW_CLS_Tx_4 message.
 *
 * This function is called when the GW_CLS_Tx_4 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_CLS_Tx_4_message_timeout_fault_pass++;
      Pcan_CLS_Tx_4_message_timeout_fault_fail = 0;
      if (Pcan_CLS_Tx_4_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_CLS_Tx_4 message.
 *
 * This function is called when the GW_CLS_Tx_4 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_CLS_Tx_4_message_timeout_fault_fail++;
      Pcan_CLS_Tx_4_message_timeout_fault_pass = 0;
      if (Pcan_CLS_Tx_4_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_OEL message.
 *
 * This function is called when the GW_OEL message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_OEL_message_timeout_fault_pass++;
      Pcan_OEL_message_timeout_fault_fail = 0;
      if (Pcan_OEL_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
      else
      {
         /* do nothing */
      }
   }
}
/**
 * @brief Callback for timeout of GW_OEL message.
 *
 * This function is called when the GW_OEL message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_OEL_message_timeout_fault_fail++;
      Pcan_OEL_message_timeout_fault_pass = 0;
      if (Pcan_OEL_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_TD message.
 *
 * This function is called when the GW_TD message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_TD_message_timeout_fault_pass++;
      Pcan_GW_TD_message_timeout_fault_fail = 0;
      if (Pcan_GW_TD_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_TD message.
 *
 * This function is called when the GW_TD message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_TD_message_timeout_fault_fail++;
      Pcan_GW_TD_message_timeout_fault_pass = 0;
      if (Pcan_GW_TD_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_VD_message_timeout_fault_pass++;
      Pcan_GW_VD_message_timeout_fault_fail = 0;
      if (Pcan_GW_VD_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_VD message.
 *
 * This function is called when the GW_VD message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_VD_message_timeout_fault_fail++;
      Pcan_GW_VD_message_timeout_fault_pass = 0;
      if (Pcan_GW_VD_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of GW_SAS message.
 *
 * This function is called when the GW_SAS message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_SAS_message_timeout_fault_pass++;
      Pcan_GW_SAS_message_timeout_fault_fail = 0;
      if (Pcan_GW_SAS_message_timeout_fault_pass >= 3)
      {
         Rte_Write_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of GW_SAS message.
 *
 * This function is called when the GW_SAS message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if ((Customer_Radar_Position == SRR_L1) || (Customer_Radar_Position == SRR_L2))
   {
      Pcan_GW_SAS_message_timeout_fault_fail++;
      Pcan_GW_SAS_message_timeout_fault_pass = 0;
      if (Pcan_GW_SAS_message_timeout_fault_fail >= 3)
      {
         Rte_Write_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/*PCAN Timeout faults*/

/**
 * @brief Callback for reception of Fusion_RadarHeader message.
 *
 * This function is called when the Fusion_RadarHeader message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarHeader_message_timeout_fault_pass++;
      Pcan_RadarHeader_message_timeout_fault_fail = 0;
      if (Pcan_RadarHeader_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of Fusion_RadarHeader message.
 *
 * This function is called when the Fusion_RadarHeader message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarHeader_message_timeout_fault_fail++;
      Pcan_RadarHeader_message_timeout_fault_pass = 0;
      if (Pcan_RadarHeader_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of Fusion_RadarCCapability message.
 *
 * This function is called when the Fusion_RadarCapability message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarCapability_message_timeout_fault_pass++;
      Pcan_RadarCapability_message_timeout_fault_fail = 0;
      if (Pcan_RadarCapability_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for timeout of Fusion_RadarCapability message.
 *
 * This function is called when the Fusion_RadarCapability message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarCapability_message_timeout_fault_fail++;
      Pcan_RadarCapability_message_timeout_fault_pass = 0;
      if (Pcan_RadarCapability_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of Fusion_RadarStatus message.
 *
 * This function is called when the Fusion_RadarStatus message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarStatus_message_timeout_fault_pass++;
      Pcan_RadarStatus_message_timeout_fault_fail = 0;
      if (Pcan_RadarStatus_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of Fusion_RadarStatus message.
 *
 * This function is called when the Fusion_RadarStatus message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarStatus_message_timeout_fault_fail++;
      Pcan_RadarStatus_message_timeout_fault_pass = 0;
      if (Pcan_RadarStatus_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for reception of Fusion_RadarStatus2 message.
 *
 * This function is called when the Fusion_RadarStatus2 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarStatus2_message_timeout_fault_pass++;
      Pcan_RadarStatus2_message_timeout_fault_fail = 0;
      if (Pcan_RadarStatus2_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for timeout of Fusion_RadarStatus2 message.
 *
 * This function is called when the Fusion_RadarStatus2 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_RadarStatus2_message_timeout_fault_fail++;
      Pcan_RadarStatus2_message_timeout_fault_pass = 0;
      if (Pcan_RadarStatus2_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/**
 * @brief Callback for reception of Fusion_AlignmentStatus1 message.
 *
 * This function is called when the Fusion_AlignmentStatus1 message is received on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE) ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_AlignmentStatus1_message_timeout_fault_pass++;
      Pcan_AlignmentStatus1_message_timeout_fault_fail = 0;
      if (Pcan_AlignmentStatus1_message_timeout_fault_pass >= 5)
      {
         Rte_Write_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_TRUE);
      }
   }
   else
   {
      /* do nothing */
   }
}
/**
 * @brief Callback for timeout of Fusion_AlignmentStatus1 message.
 *
 * This function is called when the Fusion_AlignmentStatus1 message times out on the bus.
 * No parameters.
 */
FUNC(void, COM_APPL_CODE)
ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx(void)
{
   Customer_Radar_Position = Get_Customer_Radar_Position();
   if (Customer_Radar_Position == SRR_L2)
   {
      Pcan_AlignmentStatus1_message_timeout_fault_fail++;
      Pcan_AlignmentStatus1_message_timeout_fault_pass = 0;
      if (Pcan_AlignmentStatus1_message_timeout_fault_fail >= 5)
      {
         Rte_Write_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(CODED_FALSE);
      }
   }
   else
   {
      /* do nothing */
   }
}

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*****************************************************************************
 *. Name: Process_Received_CAN_Msgs
 *.
 *.
 *. Parameters: void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 ******************************************************************************/
void Process_Received_CAN_Msgs(void)
{
#ifdef VEH_AL_CAN_STANDALONE
   M2D_Msg_T *const m2d_msg    = (M2D_Msg_T *const)Get_MSS_IPC_M2D_Msg_Buffer();
   uint8_t hil_mode_enabled    = m2d_msg->payload.hil_ipc_info.hil_mode_enabled;
   uint8_t radar_pos           = Get_Radar_Position();
   uint8_t hil_src_fusion_data = m2d_msg->payload.hil_ipc_info.hil_src_fusion_data;

   if (((SRR_L2 == radar_pos) && ((CODED_TRUE != hil_mode_enabled) ||
                                  ((CODED_TRUE == hil_mode_enabled) && (HIL_EXECUTE_AUTOSAR_CAN_DATA == hil_src_fusion_data)))))
   {
      Process_Sensor_Fusion_Detections();
      Process_Sensor_Fusion_Header_Status_Align_Data();
   }
#else
   Process_Vehicle_Status();
#endif
}
#ifdef VEH_AL_CAN_STANDALONE
/**
 * @brief return  pointer to last recieved vehicle status signals
 * @param void
 * @return Vcan_Vehicle_Status_Signal_T*
 */
const Vcan_Vehicle_Status_Signal_T *Get_Vehicle_Status_Signals(void)
{
   return &Vcan_Vehicle_Status_Signal;
}
/*===========================================================================*\
 * FUNCTION: Get_VCAN_Rx_Signals
 *===========================================================================
 * RETURN VALUE:
 *    VCAN_Rx_Signals
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns Rx vehicle speed.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#else
VCAN_Rx_Signals_T *Get_VCAN_Rx_Signals(void)
{
   return (VCAN_Rx_Signals_T *)&VCAN_Rx_Signals;
}
#endif

/*===========================================================================*\
 * FUNCTION: FXP2FLP_Fnc
 *===========================================================================
 * RETURN TYPE:
 *    float32_t
 *
 * PARAMETERS:
 *    value
 *    bpp_num
 *    signed_flag
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns Rx system absolute time signals.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
float32 FXP2FLP_Fnc(int32_t value, int32_t bpp_num, bool signed_flag)
{
   float32 result = 0.0f;
   if ((bpp_num > 31) || (bpp_num < -31))
   {
      // result = FXP2FLP_Fnc_Ext(value,bpp_num,signed_flag);
   }
   else if (bpp_num >= 0)
   {
      if (signed_flag)
      {
         result = ((value) / (float32)(1ul << (bpp_num)));
      }
      else
      {
         result = (((uint32)value) / (float32)(1ul << (bpp_num)));
      }
   }
   else
   {
      if (signed_flag)
      {
         result = ((value) * (float32)(1ul << (-1 * (bpp_num))));
      }
      else
      {
         result = (((uint32_t)value) * (float32)(1ul << (-1 * (bpp_num))));
      }
   }
   return result;
}
