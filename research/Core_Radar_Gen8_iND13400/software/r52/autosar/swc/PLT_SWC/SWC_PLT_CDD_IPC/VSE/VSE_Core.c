/******************************************************************************
 * File:        VSE_Core.c
 *
 * Description:
 *    Wrapper implementation for Vehicle State Estimator (VSE) integration.
 *    This module initializes the VSE model, updates model inputs from vehicle
 *    and tracker data, executes the VSE algorithm, and provides processed
 *    vehicle state outputs for downstream consumers.
 *
 * Copyright:
 *    Copyright (c) Aptiv. All rights reserved.
 *
 * Notes:
 *    - Maintains static instances of VSE model, inputs, outputs, and working
 *      memory.
 *    - Supports initialization, input population, model execution, and
 *      output retrieval.
 *
 ******************************************************************************/
#include "VSE_Core.h"
#include "VSE_Master_Model_WL_L2P.h"
#include "VSE_Master_Model_WL_L2P_types.h"
#include "sensor_position.h"
#include "smc_cal.h"

#include <string.h>

static RT_MODEL_VSE_Master_Model_WL_L2P_T g_vse_model;
static DW_VSE_Master_Model_WL_L2P_T g_vse_dwork;

static VnetInVehicleStateEstimator g_vse_in_vehicle_state;
static Tracker_VSE g_vse_in_tracker;
static Vehicle_Parameters g_vse_in_vehicle_parameters;
static uint64_T g_vse_in_system_time_us;
static LAST_KEY_CYCLE g_vse_in_last_key_cycle;
static Tracker_VSE_Trailer_Signals g_vse_in_trailer_signals;
static AptivCfg g_vse_in_aptiv_cfg;

static VSE_OUT g_vse_out;
static VSE_RESIM_T g_vse_out_resim;
static VSE_OUT_Trailer g_vse_out_trailer;

static bool vse_initialized = false;

#define NS_TO_US_DIVISOR   (1000U)
#define S_TO_US_MULTIPLIER (1000000ULL)
#define RAD_TO_DEG         (57.2957795F)

static void VSE_Initialization(void);
static void VSE_Populate_Input(const volatile Vse_Stream_T *p_vse_stream);
static void VSE_Populate_Output(volatile Vse_Output_T *vse_output);

/*
 * Function:    VSE_Initialization
 * Returns:     void
 * Parameters:  None
 * Abstract:    Initializes all VSE model data structures, clears internal
 *              state variables, associates the model work area, and invokes
 *              the VSE model initialization routine.
 * Reentrant:   NO
 */
static void VSE_Initialization(void)
{
   (void)memset(&g_vse_model, 0, sizeof(g_vse_model));
   (void)memset(&g_vse_dwork, 0, sizeof(g_vse_dwork));
   (void)memset(&g_vse_in_vehicle_state, 0, sizeof(g_vse_in_vehicle_state));
   (void)memset(&g_vse_in_tracker, 0, sizeof(g_vse_in_tracker));
   (void)memset(&g_vse_in_vehicle_parameters, 0, sizeof(g_vse_in_vehicle_parameters));
   (void)memset(&g_vse_in_last_key_cycle, 0, sizeof(g_vse_in_last_key_cycle));
   (void)memset(&g_vse_in_trailer_signals, 0, sizeof(g_vse_in_trailer_signals));
   (void)memset(&g_vse_in_aptiv_cfg, 0, sizeof(g_vse_in_aptiv_cfg));
   (void)memset(&g_vse_out, 0, sizeof(g_vse_out));
   (void)memset(&g_vse_out_resim, 0, sizeof(g_vse_out_resim));
   (void)memset(&g_vse_out_trailer, 0, sizeof(g_vse_out_trailer));

   g_vse_model.dwork = &g_vse_dwork;
   VSE_Master_Model_WL_L2P_initialize(&g_vse_model);
}
/*
 * Function:    VSE_Populate_Output
 * Returns:     void
 * Parameters:  Vse_Output_T *vse_output
 *             *   - pointer to VSE primary output*structure

 ** Abstract:    Executes one VSE mo*el step using the currently stored*input
 *              data and cop*es the generated outputs to the ca*ler-provided
 *              outpu* structures when valid pointers ar* supplied
 * Reentrant:   NO
 */
static void VSE_Populate_Output(volatile Vse_Output_T *vse_output)
{
   if (vse_output)
   {
      vse_output->timestamp_secs = (uint32_t)(g_vse_out.timestamp_us / S_TO_US_MULTIPLIER);

      vse_output->timestamp_nanosecs                = (uint32_t)((g_vse_out.timestamp_us % S_TO_US_MULTIPLIER) * NS_TO_US_DIVISOR);
      vse_output->veh_index                         = g_vse_out.veh_index;
      vse_output->signed_filt_veh_speed_over_ground = g_vse_out.signed_filt_veh_speed_over_ground;
      vse_output->vcs_long_velocity                 = g_vse_out.vcs_long_velocity;
      vse_output->vcs_lat_velocity                  = g_vse_out.vcs_lat_velocity;
      vse_output->vcs_lat_accel                     = g_vse_out.VCS_Lat_Accel;
      vse_output->vcs_long_accel                    = g_vse_out.VCS_Long_Accel;
      vse_output->comp_yaw_rate_filtered            = g_vse_out.comp_yaw_rate_filtered;
      vse_output->vcs_sideslip                      = g_vse_out.vcs_sideslip;
      vse_output->sideslip_rear_axle                = g_vse_out.sideslip_rear_axle;
      vse_output->curvature_rear_axle               = g_vse_out.curvature_rear_axle;
      vse_output->speed_compensation_factor         = g_vse_out.speed_compensation_factor;
      vse_output->filt_veh_speed_over_ground_qf     = g_vse_out.filt_veh_speed_over_ground_qf;
      vse_output->comp_yaw_rate_qf                  = g_vse_out.comp_yaw_rate_qf;
      vse_output->vcs_lat_accel_qf                  = g_vse_out.VCS_Lat_Accel_QF;
      vse_output->vcs_long_accel_qf                 = g_vse_out.VCS_Long_Accel_QF;
      vse_output->yaw_rate_bias_qf                  = g_vse_out.yaw_rate_bias_qf;
      vse_output->yaw_rate_bias                     = g_vse_out.yaw_rate_bias;
      vse_output->reverse_status                    = g_vse_out.reverse_status;
      vse_output->vse_major_version                 = g_vse_out.vse_major_version;
      vse_output->vse_minor_version                 = g_vse_out.vse_minor_version;
      vse_output->vse_field_version                 = g_vse_out.vse_field_version;
      vse_output->vse_calibration_version           = g_vse_out.vse_calibration_version;
      vse_output->comp_steering_angle_deg           = g_vse_out.comp_steering_angle_deg;
      vse_output->raw_speed_mps                     = g_vse_out.raw_speed_mps;
      vse_output->raw_yaw_rate_rps                  = g_vse_out.raw_yaw_rate_rps;
   }
}
/*
 * Function:    VSE_Populate_Input
 * Returns:     void
 * Parameters:  volatile Vse_Stream_T *p_vse_streamr,
 *              Vse_Stream_T *p_vse_stream Abstract:    Populates VSE vehicle parameters from IPC M2D message buffer.
 * Reentrant:   NO
 */
static void VSE_Populate_Input(const volatile Vse_Stream_T *p_vse_stream)
{
   if (NULL == p_vse_stream)
   {
      return;
   }

   const volatile Veh_Raw_Data_T *veh_raw          = &p_vse_stream->veh_raw_data[p_vse_stream->latest_raw_index];
   const volatile Veh_Raw_Misc_T *veh_misc         = &p_vse_stream->veh_raw_misc;
   const volatile Veh_Params_T *veh_params         = &p_vse_stream->veh_params;
   const volatile Last_Key_Cycle_T *last_key_cycle = &p_vse_stream->last_key_cycle;
   if (k_gxcp_delay_smc == 1u)
   {
      g_vse_in_vehicle_parameters.k_front_wheel_radius_static_loaded = 0.4856f;
      g_vse_in_trailer_signals.VsTracker_TrailerPresence             = 0u;
   }
   else if (k_gxcp_delay_smc == 2u)
   {
      g_vse_in_vehicle_parameters.k_front_wheel_radius_static_loaded = 0.485f;
      g_vse_in_trailer_signals.VsTracker_TrailerPresence             = 1u;
   }
   else
   {
      // No operation
   }
   g_vse_in_vehicle_parameters.k_wheel_base = veh_params->k_wheel_base;

   g_vse_in_vehicle_parameters.k_dist_rear_axle_to_vcs = veh_params->k_dist_rear_axle_to_vcs;

   g_vse_in_vehicle_parameters.k_long_dist_radar_to_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;

   g_vse_in_vehicle_parameters.k_lat_dist_radar_to_rear_axle = veh_params->k_lat_dist_radar_to_rear_axle;

   g_vse_in_vehicle_parameters.k_steering_gear_ratio = veh_params->k_steering_gear_ratio;

   g_vse_in_vehicle_parameters.k_understeer_coefficient = veh_params->k_understeer_coefficient;

   g_vse_in_vehicle_parameters.k_rear_cornering_compliance = veh_params->k_rear_cornering_compliance;

   g_vse_in_vehicle_parameters.k_vehicle_width = veh_params->k_vehicle_width;

   g_vse_in_vehicle_parameters.k_cog_x = veh_params->k_cog_x;

   g_vse_in_vehicle_parameters.k_cog_y = veh_params->k_cog_y;

   g_vse_in_vehicle_parameters.k_front_track_width = veh_params->k_front_track_width;

   uint8_t sts_radar_pos = Get_Radar_Position();
   if (sts_radar_pos == RADAR_POS_FRONT_RIGHT)
   {
      g_vse_in_vehicle_parameters.front_right_sensor_lat_distance_from_rear_axle  = veh_params->k_lat_dist_radar_to_rear_axle;
      g_vse_in_vehicle_parameters.front_right_sensor_long_distance_from_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;
   }
   else if (sts_radar_pos == RADAR_POS_REAR_LEFT)
   {
      g_vse_in_vehicle_parameters.rear_left_sensor_lat_distance_from_rear_axle  = veh_params->k_lat_dist_radar_to_rear_axle;
      g_vse_in_vehicle_parameters.rear_left_sensor_long_distance_from_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;
   }
   else if (sts_radar_pos == RADAR_POS_REAR_RIGHT)
   {
      g_vse_in_vehicle_parameters.rear_right_sensor_lat_distance_from_rear_axle  = veh_params->k_lat_dist_radar_to_rear_axle;
      g_vse_in_vehicle_parameters.rear_right_sensor_long_distance_from_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;
   }
   else if (sts_radar_pos == RADAR_POS_FRONT_LEFT)
   {
      g_vse_in_vehicle_parameters.front_left_sensor_lat_distance_from_rear_axle  = veh_params->k_lat_dist_radar_to_rear_axle;
      g_vse_in_vehicle_parameters.front_left_sensor_long_distance_from_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;
   }
   else if (sts_radar_pos == RADAR_POS_FRONT_CENTER)
   {
      g_vse_in_vehicle_parameters.front_bumper_sensor_long_distance_from_rear_axle = veh_params->k_long_dist_radar_to_rear_axle;
      g_vse_in_vehicle_parameters.front_bumper_sensor_lat_distance_from_rear_axle  = veh_params->k_lat_dist_radar_to_rear_axle;
   }

   g_vse_in_tracker.VehSpeedCompFac_KA_1    = veh_misc->vehspeedcompfac_ka;
   g_vse_in_tracker.VehSpeedCompFac_KA_QF_1 = veh_misc->vehspeedcompfac_ka_qf;
   g_vse_in_tracker.VehSpeedCompFac_KA_2    = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_QF_2 = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_3    = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_QF_3 = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_4    = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_QF_4 = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_5    = 0U;
   g_vse_in_tracker.VehSpeedCompFac_KA_QF_5 = 0U;

   g_vse_in_system_time_us =
      ((uint64_t)veh_raw->system_time_secs * S_TO_US_MULTIPLIER) + ((uint64_t)veh_raw->system_time_nanosecs / NS_TO_US_DIVISOR);

   g_vse_in_vehicle_state.ego_vehicle_speed                = veh_raw->ego_vehicle_speed;
   g_vse_in_vehicle_state.ego_vehicle_speed_qf             = veh_misc->ego_vehicle_speed_qf;
   g_vse_in_vehicle_state.ground_speed_gvpm                = 0u;
   g_vse_in_vehicle_state.ground_speed_qf_gvpm             = 0u;
   g_vse_in_vehicle_state.ego_yaw_rate                     = veh_raw->ego_yaw_rate;
   g_vse_in_vehicle_state.ego_yaw_rate_qf                  = veh_misc->ego_yaw_rate_qf;
   g_vse_in_vehicle_state.yaw_rate_gvpm                    = 0u;
   g_vse_in_vehicle_state.yaw_rate_qf_gvpm                 = 0u;
   g_vse_in_vehicle_state.steering_whl_angle               = (veh_raw->steering_whl_angle * RAD_TO_DEG);
   g_vse_in_vehicle_state.steering_whl_angle_qf            = veh_misc->steering_whl_angle_qf;
   g_vse_in_vehicle_state.ego_lateral_accel                = veh_raw->ego_lateral_accel;
   g_vse_in_vehicle_state.ego_lateral_accel_qf             = veh_misc->ego_lateral_accel_qf;
   g_vse_in_vehicle_state.lateral_acceleration_gvpm        = 0u;
   g_vse_in_vehicle_state.lateral_acceleration_qf_gvpm     = 0u;
   g_vse_in_vehicle_state.ego_longitudinal_accel           = veh_raw->ego_longitudinal_accel;
   g_vse_in_vehicle_state.ego_longitudinal_accel_qf        = veh_misc->ego_longitudinal_accel_qf;
   g_vse_in_vehicle_state.longitudinal_acceleration_gvpm   = 0u;
   g_vse_in_vehicle_state.logitudinal_acceleration_qf_gvpm = 0u;
   g_vse_in_vehicle_state.gear_box_pos                     = veh_misc->gear_pos;
   g_vse_in_vehicle_state.vehicle_standstill               = veh_misc->vehicle_standstill;
   g_vse_in_vehicle_state.rr_wheel_pulse_counter_qf        = 0u;
   g_vse_in_vehicle_state.rl_wheel_pulse_counter_qf        = 0u;
   g_vse_in_vehicle_state.fr_wheel_pulse_counter_qf        = 0u;
   g_vse_in_vehicle_state.fl_wheel_pulse_counter_qf        = 0u;

   g_vse_in_vehicle_state.LongAcceleration_BSM_SNA = 0u;
   g_vse_in_vehicle_state.VehicleSpeedVSOSig_SNA   = 0u;

   g_vse_in_vehicle_state.VsVCAN_Trailer_ITBM_Power = 0.0F;
   g_vse_in_vehicle_state.VsVCAN_Nm_Trailer_AxleTrq = 0.0F;

   g_vse_in_vehicle_state.rear_rwa_speed_measured_rad_per_s_validity = 3u;
   g_vse_in_vehicle_state.rear_rwa_measured_rad_validity             = 0u;
   g_vse_in_vehicle_state.rwa_speed_measured_rad_per_s_validity      = 0u;
   g_vse_in_vehicle_state.rwa_measured_rad_validity                  = 0u;

   g_vse_in_vehicle_state.rear_rwa_speed_measured_rad_per_s = 3.0F;
   g_vse_in_vehicle_state.rear_rwa_measured_rad             = 0.0F;
   g_vse_in_vehicle_state.rwa_speed_measured_rad_per_s      = 0.0F;
   g_vse_in_vehicle_state.rwa_measured_rad                  = 0.0F;

   g_vse_in_vehicle_state.pitch_rate    = 0.0F;
   g_vse_in_vehicle_state.pitch_rate_qf = 0u;

   g_vse_in_vehicle_state.steering_whl_speed_deg_per_s = veh_raw->steering_whl_speed_deg_per_s;

   g_vse_in_vehicle_state.vertical_acceleration    = 0.0F;
   g_vse_in_vehicle_state.vertical_acceleration_qf = 0u;

   g_vse_in_vehicle_state.roll_rate    = 0.0F;
   g_vse_in_vehicle_state.roll_rate_qf = 0u;

   g_vse_in_vehicle_state.fl_wheel_rot_speed_rpm = 0.0F;
   g_vse_in_vehicle_state.fr_wheel_rot_speed_rpm = 0.0F;

   g_vse_in_vehicle_state.fl_wheel_speed    = 0.0F;
   g_vse_in_vehicle_state.fl_wheel_speed_qf = 0u;

   g_vse_in_vehicle_state.fr_wheel_speed    = 0.0F;
   g_vse_in_vehicle_state.fr_wheel_speed_qf = 0u;

   g_vse_in_vehicle_state.tire_pressure_front_left_psi  = 0.0F;
   g_vse_in_vehicle_state.tire_pressure_front_right_psi = 0.0F;

   g_vse_in_vehicle_state.fl_wheel_spin = 0u;
   g_vse_in_vehicle_state.fr_wheel_spin = 0u;
   g_vse_in_vehicle_state.rl_wheel_spin = 0u;
   g_vse_in_vehicle_state.rr_wheel_spin = 0u;

   g_vse_in_vehicle_state.fl_wheel_pulse_counter = 0u;
   g_vse_in_vehicle_state.fr_wheel_pulse_counter = 0u;
   g_vse_in_vehicle_state.rl_wheel_pulse_counter = 0u;
   g_vse_in_vehicle_state.rr_wheel_pulse_counter = 0u;

   g_vse_in_vehicle_state.asr_active = 0u;
   g_vse_in_vehicle_state.abs_active = 0u;

   g_vse_in_vehicle_state.brake_padel_press = 0u;

   g_vse_in_vehicle_state.total_axle_torque_static = 0.0F;
   g_vse_in_vehicle_state.engine_rpm               = 1.0F;
   g_vse_in_vehicle_state.brk_trq                  = 0.0F;
   g_vse_in_vehicle_state.trq_amp_trans            = 1.0F;

   g_vse_in_vehicle_state.trailer_sts            = 0u;
   g_vse_in_vehicle_state.trailer_connection_sts = 0u;
   g_vse_in_vehicle_state.veh_ignition_sts       = 0u;
   g_vse_in_vehicle_state.bsd_drv_setting        = 0u;

   g_vse_in_last_key_cycle.nvm_last_rem_swa_bias_deg                  = last_key_cycle->nvm_last_rem_swa_bias_deg;
   g_vse_in_last_key_cycle.nvm_f_last_rem_swa_bias                    = last_key_cycle->nvm_f_last_rem_swa_bias;
   g_vse_in_last_key_cycle.nvm_last_rem_speed_comp                    = last_key_cycle->nvm_last_rem_speed_comp;
   g_vse_in_last_key_cycle.nvm_last_rem_stop_yaw_bias_primary_radps   = last_key_cycle->nvm_last_rem_stop_yaw_bias_primary_radps;
   g_vse_in_last_key_cycle.nvm_last_rem_stop_yaw_bias_secondary_radps = last_key_cycle->nvm_last_rem_stop_yaw_bias_secondary_radps;

   ;
   g_vse_in_trailer_signals.VsTracker_TrailerPresenceConfLvl  = 1u;
   g_vse_in_trailer_signals.VsTracker_m_TrailerLength         = 1u;
   g_vse_in_trailer_signals.VsTracker_TrailerLengthConfLvl    = 0u;
   g_vse_in_trailer_signals.VsTracker_m_TrailerWidth          = 1u;
   g_vse_in_trailer_signals.VsTracker_TrailerWidthConfLvl     = 0u;
   g_vse_in_trailer_signals.VsTracker_rps_TrailerAngleRate    = 1.0F;
   g_vse_in_trailer_signals.VsTracker_rad_TrailerAngle        = 1.0F;
   g_vse_in_trailer_signals.VsTracker_m_TrailerHVGap          = 0.0F;
   g_vse_in_trailer_signals.VsTracker_TrailerAngleConfLvl     = 0u;
   g_vse_in_trailer_signals.VsTracker_TrailerAngleRateConfLvl = 0u;
   g_vse_in_trailer_signals.VsTracker_ms_RadarDetectTimer     = 0u;
   g_vse_in_trailer_signals.VsTracker_ms_StationaryTimer      = 0u;
   g_vse_in_trailer_signals.VsTracker_RadarDetectSts          = 0u;

   g_vse_in_aptiv_cfg.CsPROXI_CANNode63_TTM               = 0u;
   g_vse_in_aptiv_cfg.CsPROXI_SteeringSystemInputType     = 0u;
   g_vse_in_aptiv_cfg.CsPROXI_CANNode95_ITBM              = 0u;
   g_vse_in_aptiv_cfg.CsPROXI_SteeringRatioRackPinionType = veh_params->k_steering_ratio_rack_pinion_type;
}

/*
 * Function:    Run_VSE
 * Returns:     void
 * Parameters:  const D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message
 *              volatile M2D_Msg_T *p_ipc_m2d - pointer to IPC M2D message
 *              const Vehicle_Parameters *p_vehicle_parameters - pointer to VSE vehicle parameters
 * Abstract:    Executes VSE and writes processed host output to M2D payload for tracker.
 * Reentrant:   NO
 */
void Run_VSE(volatile M2D_Msg_T *p_ipc_m2d)
{
   if (NULL == p_ipc_m2d)
   {
      return;
   }
   /* Default to invalid */
   p_ipc_m2d->payload.veh_data.vse_output_valid = CODED_FALSE;
   /* VSE Implementation */
   if (!vse_initialized)
   {
      VSE_Initialization();

      vse_initialized = true;
   }
   VSE_Populate_Input(&p_ipc_m2d->payload.veh_data);

   VSE_Master_Model_WL_L2P_step(&g_vse_model, &g_vse_in_vehicle_state, &g_vse_in_tracker, &g_vse_in_vehicle_parameters,
                                g_vse_in_system_time_us, &g_vse_in_last_key_cycle, &g_vse_in_trailer_signals, &g_vse_in_aptiv_cfg,
                                &g_vse_out, &g_vse_out_resim, &g_vse_out_trailer);

   VSE_Populate_Output(&p_ipc_m2d->payload.veh_data.vse_output);

   p_ipc_m2d->payload.veh_data.vse_output_valid = CODED_TRUE;
}
