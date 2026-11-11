/*
 * File: VSE_Master_Model_WL_L2P.c
 *
 * Code generated for Simulink model 'VSE_Master_Model_WL_L2P'.
 *
 * Model version                  : 1.1208
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:08:25 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Safety precaution
 *    4. Execution efficiency
 *    5. MISRA C:2012 guidelines
 *    6. Traceability
 *    7. Debugging
 * Validation result: Not run
 */

#include "VSE_Master_Model_WL_L2P.h"
#include "VSE_Master_Model_WL_L2P_private.h"

/* Named constants for Chart: '<S5>/Chart' */
#define VSE_Master_Model_WL_L2P_IN_Initialize ((uint8_T)1U)
#define VSE_Master_Model_WL_L2P_IN_Running    ((uint8_T)2U)

/* Named constants for Chart: '<S8>/Initialization_Trigger' */
#define VSE_Master_Model_WL_L2P_IN_Initialize_d ((uint8_T)1U)
#define VSE_Master_Model_WL_L2P_IN_Running_o    ((uint8_T)2U)

/* Named constants for Chart: '<S32>/Chart' */
#define VSE_Master_Model_WL_L2P_IN_Initialize_g ((uint8_T)1U)
#define VSE_Master_Model_WL_L2P_IN_Running_f    ((uint8_T)2U)

/*
 * Output and update for atomic system:
 *    '<S5>/Chart'
 *    '<S6>/Chart'
 *    '<S7>/Chart'
 */
void VSE_Master_Model_WL_L2P_Chart(boolean_T *rty_f_initialize_JerkEstimation, DW_Chart_VSE_Master_Model_WL_L2P_T *localDW)
{
   /* Chart: '<S5>/Chart' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c4_JerkEstimator) == 0U)
   {
      localDW->bitsForTID0.is_active_c4_JerkEstimator = 1;
      localDW->bitsForTID0.is_c4_JerkEstimator        = VSE_Master_Model_WL_L2P_IN_Initialize;
      *rty_f_initialize_JerkEstimation                = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c4_JerkEstimator) == VSE_Master_Model_WL_L2P_IN_Initialize)
   {
      if (*rty_f_initialize_JerkEstimation)
      {
         localDW->bitsForTID0.is_c4_JerkEstimator = VSE_Master_Model_WL_L2P_IN_Running;
         *rty_f_initialize_JerkEstimation         = false;
      }
   }
   else
   {
      *rty_f_initialize_JerkEstimation = false;
   }

   /* End of Chart: '<S5>/Chart' */
}

/*
 * Output and update for enable system:
 *    '<S5>/Differentiator Generator'
 *    '<S6>/Differentiator Generator'
 *    '<S7>/Differentiator Generator'
 */
void VSE_Master_Model_WL_L2P_DifferentiatorGenerator(boolean_T rtu_Enable, real_T rty_Differentiator_Num[8],
                                                     real_T rty_Differentiator_Den[8])
{
   static const real_T tmp[8] = {2.7763343084463628E-5,   0.00013881671542231814,  0.00024987008776017263,
                                 0.00013881671542231814,  -0.00013881671542231814, -0.00024987008776017263,
                                 -0.00013881671542231814, -2.7763343084463628E-5};

   static const real_T tmp_0[8] = {1.0,
                                   -4.4174748855531005,
                                   6.8371489541927639,
                                   -2.5591716874759509,
                                   -4.7218966575350478,
                                   6.4186206346111945,
                                   -3.1152434123881272,
                                   0.5580348226874462};

   /* Outputs for Enabled SubSystem: '<S5>/Differentiator Generator' incorporates:
    *  EnablePort: '<S79>/Enable'
    */
   if (rtu_Enable)
   {
      /* MATLAB Function: '<S79>/FindDifferentiatorCoeff' */
      memcpy(&rty_Differentiator_Num[0], &tmp[0], (sizeof(real_T)) << 3U);
      memcpy(&rty_Differentiator_Den[0], &tmp_0[0], (sizeof(real_T)) << 3U);
   }

   /* End of Outputs for SubSystem: '<S5>/Differentiator Generator' */
}

/*
 * Output and update for enable system:
 *    '<S5>/Filter Generator'
 *    '<S6>/Filter Generator'
 *    '<S7>/Filter Generator'
 */
void VSE_Master_Model_WL_L2P_FilterGenerator(boolean_T rtu_Enable, real_T rty_Filter_Num[5], real_T rty_Filter_Den[5])
{
   static const real_T tmp[5] = {0.0097355705758097114, -0.032135368264455524, 0.045449987251035384, -0.032135368264455511,
                                 0.0097355705758096975};

   static const real_T tmp_0[5] = {1.0, -3.5729428344521863, 4.8079147193565426, -2.8863252161892525, 0.65200372315863975};

   int32_T i;

   /* Outputs for Enabled SubSystem: '<S5>/Filter Generator' incorporates:
    *  EnablePort: '<S80>/Enable'
    */
   if (rtu_Enable)
   {
      /* MATLAB Function: '<S80>/FindFilterCoeff' */
      for (i = 0; i < 5; i++)
      {
         rty_Filter_Num[i] = tmp[i];
         rty_Filter_Den[i] = tmp_0[i];
      }

      /* End of MATLAB Function: '<S80>/FindFilterCoeff' */
   }

   /* End of Outputs for SubSystem: '<S5>/Filter Generator' */
}

/*
 * Output and update for enable system:
 *    '<S8>/Initialization'
 *    '<S9>/Initialization'
 *    '<S10>/Initialization'
 *    '<S11>/Initialization'
 *    '<S12>/Initialization'
 *    '<S13>/Initialization'
 *    '<S27>/Initialization'
 *    '<S28>/Initialization'
 *    '<S29>/Initialization'
 *    '<S30>/Initialization'
 *    ...
 */
void VSE_Master_Model_WL_L2P_Initialization(boolean_T rtu_Enable, real32_T rty_diff_num[4], real32_T rty_diff_den[4])
{
   /* Outputs for Enabled SubSystem: '<S8>/Initialization' incorporates:
    *  EnablePort: '<S106>/Enable'
    */
   if (rtu_Enable)
   {
      /* MATLAB Function: '<S106>/MATLAB Function' */
      rty_diff_num[0] = 0.724336267F;
      rty_diff_den[0] = 1.0F;
      rty_diff_num[1] = 0.724336267F;
      rty_diff_den[1] = -0.822694957F;
      rty_diff_num[2] = -0.724336267F;
      rty_diff_den[2] = -0.98551327F;
      rty_diff_num[3] = -0.724336267F;
      rty_diff_den[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S8>/Initialization' */
}

/*
 * Output and update for atomic system:
 *    '<S8>/Initialization_Trigger'
 *    '<S9>/Initialization_Trigger'
 *    '<S10>/Initialization_Trigger'
 *    '<S11>/Initialization_Trigger'
 *    '<S12>/Initialization_Trigger'
 *    '<S13>/Initialization_Trigger'
 *    '<S27>/Initialization_Trigger'
 *    '<S28>/Initialization_Trigger'
 *    '<S29>/Initialization_Trigger'
 *    '<S30>/Initialization_Trigger'
 *    ...
 */
void VSE_Master_Model_WL_L2P_Initialization_Trigger(boolean_T *rty_f_initialize,
                                                    DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T *localDW)
{
   /* Chart: '<S8>/Initialization_Trigger' */
   if (((uint32_T)localDW->bitsForTID0.is_active_c5_Initialization_Trigger) == 0U)
   {
      localDW->bitsForTID0.is_active_c5_Initialization_Trigger = 1;
      localDW->bitsForTID0.is_c5_Initialization_Trigger        = VSE_Master_Model_WL_L2P_IN_Initialize_d;
      *rty_f_initialize                                        = true;
   }
   else if (((uint32_T)localDW->bitsForTID0.is_c5_Initialization_Trigger) == VSE_Master_Model_WL_L2P_IN_Initialize_d)
   {
      if (*rty_f_initialize)
      {
         localDW->bitsForTID0.is_c5_Initialization_Trigger = VSE_Master_Model_WL_L2P_IN_Running_o;
         *rty_f_initialize                                 = false;
      }
   }
   else
   {
      *rty_f_initialize = false;
   }

   /* End of Chart: '<S8>/Initialization_Trigger' */
}

/*
 * Output and update for action system:
 *    '<S14>/If Action Subsystem1'
 *    '<S14>/If Action Subsystem'
 */
void VSE_Master_Model_WL_L2P_IfActionSubsystem1(
   real32_T rtu_In1, real32_T rtu_In1_j, real32_T rtu_In1_f, real32_T rtu_In1_fr, real32_T rtu_In1_c, enum_road_type_T rtu_In1_a,
   boolean_T rtu_In1_k, boolean_T rtu_In1_b, boolean_T rtu_In1_fe, boolean_T rtu_In1_e, boolean_T rtu_In1_i, real32_T rtu_In1_jz,
   boolean_T rtu_In1_bp, boolean_T rtu_In1_kf, real32_T rtu_In1_ir, boolean_T rtu_In1_n, real32_T rtu_In1_na,
   enum_quality_factor_T rtu_In1_d, boolean_T rtu_In1_o, real32_T rtu_In1_km, enum_quality_factor_T rtu_In1_g,
   enum_quality_factor_T rtu_In1_jf, boolean_T rtu_In1_fy, boolean_T rtu_In1_ik, real32_T rtu_In1_m, real32_T rtu_In1_ef,
   real32_T *rty_Out1, real32_T *rty_Out1_j, real32_T *rty_Out1_f, enum_quality_factor_T *rty_Out1_fr,
   enum_quality_factor_T *rty_Out1_c, boolean_T *rty_Out1_a, boolean_T *rty_Out1_k, real32_T *rty_Out1_b, real32_T *rty_Out1_fe,
   real32_T *rty_Out1_e, real32_T *rty_Out1_i, real32_T *rty_Out1_jz, real32_T *rty_Out1_bp, enum_road_type_T *rty_Out1_kf,
   boolean_T *rty_Out1_ir, boolean_T *rty_Out1_n, boolean_T *rty_Out1_na, boolean_T *rty_Out1_d, boolean_T *rty_Out1_o,
   boolean_T *rty_Out1_km, boolean_T *rty_Out1_g, real32_T *rty_Out1_jf, boolean_T *rty_Out1_fy, real32_T *rty_Out1_ik,
   enum_quality_factor_T *rty_Out1_m, boolean_T *rty_Out1_ef)
{
   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1 = rtu_In1;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_e = rtu_In1_j;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_i = rtu_In1_f;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_jz = rtu_In1_fr;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_bp = rtu_In1_c;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_kf = rtu_In1_a;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_ir = rtu_In1_k;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_n = rtu_In1_b;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_na = rtu_In1_fe;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_d = rtu_In1_e;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_o = rtu_In1_i;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_j = rtu_In1_jz;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_km = rtu_In1_bp;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_g = rtu_In1_kf;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_jf = rtu_In1_ir;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_fy = rtu_In1_n;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_ik = rtu_In1_na;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_m = rtu_In1_d;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_ef = rtu_In1_o;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_f = rtu_In1_km;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_fr = rtu_In1_g;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_c = rtu_In1_jf;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_a = rtu_In1_fy;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_k = rtu_In1_ik;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_b = rtu_In1_m;

   /* SignalConversion: '<S179>/BusConversion_InsertedFor_Out1_at_inport_0' */
   *rty_Out1_fe = rtu_In1_ef;
}

/*
 * Output and update for atomic system:
 *    '<S181>/MATLAB Function'
 *    '<S184>/MATLAB Function'
 *    '<S187>/MATLAB Function'
 *    '<S190>/MATLAB Function'
 *    '<S193>/MATLAB Function'
 *    '<S196>/MATLAB Function'
 *    '<S199>/MATLAB Function'
 *    '<S202>/MATLAB Function'
 *    '<S205>/MATLAB Function'
 *    '<S208>/MATLAB Function'
 *    '<S211>/MATLAB Function'
 */
void VSE_Master_Model_WL_L2P_MATLABFunction(boolean_T rtu_fault_flag, real32_T rtu_fault_maturation_time_seconds,
                                            real32_T rtu_fault_dematuration_time_seconds, boolean_T *rty_final_fault,
                                            DW_MATLABFunction_VSE_Master_Model_WL_L2P_T *localDW)
{
   boolean_T tmp;
   boolean_T tmp_0;
   tmp = !localDW->bitsForTID0.prev_final_fault_flag;
   if (rtu_fault_flag && tmp)
   {
      localDW->matured_time += 0.01F;
   }
   else
   {
      if (!rtu_fault_flag)
      {
         localDW->matured_time = 0.0F;
      }
   }

   tmp_0 = !rtu_fault_flag;
   if (tmp_0 && (localDW->bitsForTID0.prev_final_fault_flag))
   {
      localDW->dematured_time += 0.01F;
   }
   else
   {
      if (!localDW->bitsForTID0.prev_final_fault_flag)
      {
         localDW->dematured_time = 0.0F;
      }
   }

   *rty_final_fault = (((rtu_fault_flag && tmp) && (localDW->matured_time >= rtu_fault_maturation_time_seconds)) ||
                       ((tmp_0 || (localDW->bitsForTID0.prev_final_fault_flag)) &&
                        (((rtu_fault_flag || tmp) || (localDW->dematured_time < rtu_fault_dematuration_time_seconds)) &&
                         ((tmp_0 && (localDW->bitsForTID0.prev_final_fault_flag)) || rtu_fault_flag))));
   localDW->bitsForTID0.prev_final_fault_flag = *rty_final_fault;
}

/* Model step function */
void VSE_Master_Model_WL_L2P_step(RT_MODEL_VSE_Master_Model_WL_L2P_T *const VSE_Master_Model_WL_L2P_M,
                                  VnetInVehicleStateEstimator *VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b,
                                  Tracker_VSE *VSE_Master_Model_WL_L2P_U_Tracker_VSE_m,
                                  Vehicle_Parameters *VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j,
                                  uint64_T VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec,
                                  LAST_KEY_CYCLE *VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k,
                                  Tracker_VSE_Trailer_Signals *VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a,
                                  AptivCfg *VSE_Master_Model_WL_L2P_U_AptivCfg_p, VSE_OUT *VSE_Master_Model_WL_L2P_Y_VSE_Output,
                                  VSE_RESIM_T *VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output,
                                  VSE_OUT_Trailer *VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer)
{
   DW_VSE_Master_Model_WL_L2P_T *VSE_Master_Model_WL_L2P_DW = ((DW_VSE_Master_Model_WL_L2P_T *)VSE_Master_Model_WL_L2P_M->dwork);

   /* local block i/o variables */
   real32_T rtb_VsTracker_VehSpdCompFac;
   real32_T rtb_SpeedCompensation_o1;
   real32_T rtb_fl_wheel_speed;
   real32_T rtb_fr_wheel_speed;
   real32_T rtb_yawRate;
   real32_T rtb_YawRateEstimationUsingSteeringWheelAngle_o3;
   real32_T rtb_Yaw_Rate_Compensated_Unfiltered;
   real32_T rtb_Yaw_Rate_Compensated_Filtered;
   real32_T rtb_Yaw_Rate_Raw_Bias;
   real32_T rtb_Stop_Yaw_Bias_NVM_Write;
   real32_T rtb_yaw_rate_bias1;
   real32_T rtb_f_yaw_stop_bias_converged;
   real32_T rtb_yaw_rate_bias_fast_bias1;
   real32_T rtb_yaw_rate_bias_fast_bias2;
   real32_T rtb_comp_yaw_rate_diff_filt;
   real32_T rtb_yaw_rate_bias_diff;
   real32_T rtb_ignition_time;
   real32_T rtb_Yaw_Rate_Compensated_Unfiltered_m;
   real32_T rtb_Yaw_Rate_Compensated_Filtered_p;
   real32_T rtb_Yaw_Rate_Raw_Bias_m;
   real32_T rtb_Stop_Yaw_Bias_NVM_Write_l;
   real32_T rtb_yaw_rate_bias1_g;
   real32_T rtb_f_yaw_stop_bias_converged_a;
   real32_T rtb_yaw_rate_bias_fast_bias1_h;
   real32_T rtb_yaw_rate_bias_fast_bias2_p;
   real32_T rtb_comp_yaw_rate_diff_filt_n;
   real32_T rtb_yaw_rate_bias_diff_l;
   real32_T rtb_ignition_time_f;
   real32_T rtb_Gain1;
   real32_T rtb_VsVSE_mps_WhlOdoVehSpeedOverGround;
   real32_T rtb_VsVSE_mps2_WhlOdoVehLongAccel;
   real32_T rtb_VsVSE_mps_LastEstimWhlSpd;
   real32_T rtb_VsVCAN_nu_CountsPerRevol;
   real32_T rtb_combined_whl_tck_bsd_lin_spd;
   real32_T rtb_combined_whl_tck_bsd_lin_spd_g;
   real32_T rtb_combined_whl_tck_bsd_lin_spd_j;
   real32_T rtb_combined_whl_tck_bsd_lin_spd_jz;
   real32_T rtb_VsVSE_mps2_WhlOdoVehLongAccel_p;
   real32_T rtb_curvature_rear_axle;
   real32_T rtb_VCS_long_velocity;
   real32_T rtb_sensor_long_velocity;
   real32_T rtb_VCS_sideslip;
   real32_T rtb_sensor_sideslip;
   real32_T rtb_sideslip_rear_axle;
   real32_T rtb_VCS_lat_velocity;
   real32_T rtb_sensor_lat_velocity;
   real32_T rtb_CurvKalmanFilterC0;
   real32_T rtb_CurvKalmanFilterC1;
   real32_T rtb_front_left_sensor_long;
   real32_T rtb_front_left_sensor_lat;
   real32_T rtb_front_right_sensor_long;
   real32_T rtb_front_right_sensor_lat;
   real32_T rtb_rear_left_sensor_long;
   real32_T rtb_rear_left_sensor_lat;
   real32_T rtb_rear_right_sensor_long;
   real32_T rtb_rear_right_sensor_lat;
   real32_T rtb_front_bumper_sensor_long;
   real32_T rtb_front_bumper_sensor_lat;
   real32_T rtb_Model4_o1;
   real32_T rtb_Model4_o2;
   real32_T rtb_VsVSE_pct_EstimatedGrade;
   real32_T rtb_RollRateCompensation_o2;
   real32_T rtb_RollRateCompensation_o3;
   real32_T rtb_PitchRateCompensation_o2;
   real32_T rtb_PitchRateCompensation_o3;
   real32_T rtb_HeadingAngleAndLatLongDisplacement_o1;
   real32_T rtb_HeadingAngleAndLatLongDisplacement_o2;
   real32_T rtb_HeadingAngleAndLatLongDisplacement_o3;
   real32_T rtb_Host_Long_Accel_mpss;
   real32_T rtb_Road_Grade_Accel;
   real32_T rtb_IMULongAccelFilt_mpss;
   real32_T rtb_HostLongAccelFilt_mpss;
   real32_T rtb_trailer_length;
   real32_T rtb_trailer_width;
   real32_T rtb_Model_o8;
   real32_T rtb_Model_o9;
   real32_T rtb_Model6_o1;
   real32_T rtb_total_count;
   real32_T rtb_CountAccel;
   real32_T rtb_brake_count;
   real32_T rtb_EstMass_Acc;
   real32_T rtb_EstMass_Brk;
   real32_T rtb_percentage_conv;
   real32_T rtb_EstimatedMass;
   enum_road_type_T rtb_road_type;
   enum_road_type_T rtb_road_type_b;
   uint8_T rtb_fl_wheel_spin;
   uint8_T rtb_fr_wheel_spin;
   uint8_T rtb_rl_wheel_spin;
   uint8_T rtb_rr_wheel_spin;
   uint8_T rtb_fl_wheel_pulse_counter;
   uint8_T rtb_fr_wheel_pulse_counter;
   uint8_T rtb_rl_wheel_pulse_counter;
   uint8_T rtb_rr_wheel_pulse_counter;
   uint8_T rtb_Cast;
   uint8_T rtb_VsVSE_u8_ABSStatusUnderBraking;
   uint8_T rtb_brake_padel_press;
   uint8_T rtb_Road_Grade_Accel_QF;
   uint8_T rtb_Trailer_Detection_ConfLvl;
   uint8_T rtb_trailer_length_ConfLvl;
   uint8_T rtb_trailer_width_ConfLvl;
   enum_quality_factor_T rtb_Merge;
   enum_quality_factor_T rtb_Merge_b;
   enum_quality_factor_T rtb_Merge_a;
   enum_quality_factor_T rtb_VeTracker_VehSpdCompFac_QF;
   enum_quality_factor_T rtb_SpeedCompensation_o2;
   enum_quality_factor_T rtb_Merge_l;
   enum_quality_factor_T rtb_Merge_a5;
   enum_quality_factor_T rtb_Merge_d;
   enum_quality_factor_T rtb_Merge_p;
   enum_quality_factor_T rtb_qf;
   enum_quality_factor_T rtb_YawRateEstimationUsingSteeringWheelAngle_o4;
   enum_quality_factor_T rtb_Merge_e;
   enum_quality_factor_T rtb_Merge_i;
   enum_quality_factor_T rtb_ego_longitudinal_accel_qf;
   enum_quality_factor_T rtb_Merge_iw;
   enum_quality_factor_T rtb_Merge_o;
   enum_quality_factor_T rtb_Yaw_Rate_Bias_QF;
   enum_quality_factor_T rtb_Yaw_Rate_Compensated_QF;
   enum_quality_factor_T rtb_Yaw_Rate_Bias_QF_l;
   enum_quality_factor_T rtb_Yaw_Rate_Compensated_QF_e;
   enum_quality_factor_T rtb_Model4_o3;
   enum_quality_factor_T rtb_Model4_o4;
   enum_quality_factor_T rtb_RollRateCompensation_o4;
   enum_quality_factor_T rtb_PitchRateCompensation_o4;
   enum_quality_factor_T rtb_HeadingAngleAndLatLongDisplacement_o4;
   boolean_T rtb_DetermineReverseStatus;
   boolean_T rtb_f_stationary;
   boolean_T rtb_f_Yaw_Rate_Bias_Converged;
   boolean_T rtb_f_stop_bias_converged;
   boolean_T rtb_f_yaw_rate_bias_shift;
   boolean_T rtb_f_Yaw_Rate_Bias_Converged_a;
   boolean_T rtb_f_stop_bias_converged_h;
   boolean_T rtb_f_yaw_rate_steady;
   boolean_T rtb_f_input_invalid_persistent;
   boolean_T rtb_f_execution_period_error_persistent;
   boolean_T rtb_f_bias_was_accurate;
   boolean_T rtb_f_yaw_stop_bias_converged_d;
   boolean_T rtb_f_yaw_stop_bias_converged_h;
   boolean_T rtb_f_Yaw_Rate_Bias_Converged_j;
   boolean_T rtb_f_stop_bias_converged_n;
   boolean_T rtb_f_yaw_rate_bias_shift_j;
   boolean_T rtb_f_Yaw_Rate_Bias_Converged_ak;
   boolean_T rtb_f_stop_bias_converged_k;
   boolean_T rtb_f_yaw_rate_steady_k;
   boolean_T rtb_f_input_invalid_persistent_g;
   boolean_T rtb_f_execution_period_error_persistent_g;
   boolean_T rtb_f_bias_was_accurate_p;
   boolean_T rtb_f_yaw_stop_bias_converged_g;
   boolean_T rtb_f_yaw_stop_bias_converged_i;
   boolean_T rtb_zero_whl_cnt;
   boolean_T rtb_SpeedRationalityCheck;
   boolean_T rtb_SteeringAngleRationalityCheck;
   boolean_T rtb_LatAccelRationalityCheck;
   boolean_T rtb_LongAccelRationalityCheck;
   boolean_T rtb_Model_o7;
   boolean_T rtb_Model6_o2;
   boolean_T rtb_VsVSE_b_ResetFlag;
   boolean_T rtb_final_fault_h;
   boolean_T rtb_final_fault_f;
   real32_T denAccum;
   real32_T denAccum_0;
   real32_T denAccum_1;
   real32_T denAccum_2;
   real32_T denAccum_3;
   real32_T denAccum_4;
   real32_T denAccum_5;
   real32_T denAccum_6;
   real32_T denAccum_7;
   real32_T denAccum_8;
   real32_T denAccum_9;
   real_T denAccum_a;
   real_T denAccum_b;
   real_T denAccum_c;
   int32_T j;
   int32_T denIdx;
   real_T denAccum_d;
   real_T denAccum_e;
   boolean_T rtb_LogicalOperator;
   boolean_T rtb_LogicalOperator_jn;
   real32_T rtb_DataTypeConversion_p;
   boolean_T rtb_LogicalOperator_m;
   enum_quality_factor_T rtb_Merge_mz;
   enum_quality_factor_T rtb_Cast4;
   real32_T rtb_DataTypeConversion_lk;
   real32_T rtb_correc_stop_yaw_bias_nvm_read_g;
   boolean_T rtb_LogicalOperator_hj;
   real_T rtb_Abs;
   real_T rtb_Switch;
   real_T rtb_filter_discrete_num[5];
   real_T rtb_filter_discrete_denom[5];
   uint8_T rtb_gear_box_pos;
   enum_quality_factor_T rtb_Merge_mg;
   enum_quality_factor_T rtb_Merge_lr;
   real32_T rtb_Switch1;
   real32_T rtb_Switch1_d;
   enum_quality_factor_T rtb_Switch1_n5;
   real32_T rtb_Product;
   uint8_T rtb_Cast6;
   real32_T rtb_DataTypeConversion_a;
   real32_T rtb_fl_wheel_rot_speed_rpm;
   real32_T rtb_fr_wheel_rot_speed_rpm;
   real32_T rtb_VsVCAN_Trailer_ITBM_Power;
   real32_T yaw_rate_bias1;
   real32_T yaw_rate_bias2;
   real32_T yaw_rate_bias_fast_bias1;
   real32_T yaw_rate_bias_fast_bias2;
   real32_T comp_yaw_rate_diff_filt;
   real32_T yaw_rate_bias_diff;
   boolean_T f_stop_bias_converged;
   boolean_T f_yaw_rate_steady;
   boolean_T f_input_invalid_persistent;
   boolean_T f_execution_period_error_persistent;
   boolean_T f_bias_was_accurate;
   real32_T ignition_time;
   boolean_T f_yaw_stop_bias_converged;
   enum_road_type_T road_type;
   boolean_T f_Yaw_Rate_Bias_Converged_c;
   uint32_T qY;
   enum_quality_factor_T tmp;
   enum_quality_factor_T tmp_0;

   /* RelationalOperator: '<S70>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S291>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_yaw_rate_qf;

   /* Switch: '<S46>/Switch' incorporates:
    *  Constant: '<S70>/Constant'
    *  Delay: '<S46>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S70>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_yaw_rate;
   }

   /* End of Switch: '<S46>/Switch' */

   /* RelationalOperator: '<S71>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S303>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp_0 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->yaw_rate_qf_gvpm;

   /* Switch: '<S47>/Switch' incorporates:
    *  Constant: '<S71>/Constant'
    *  Delay: '<S47>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S71>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->yaw_rate_gvpm;
   }

   /* End of Switch: '<S47>/Switch' */

   /* Logic: '<S289>/Logical Operator' incorporates:
    *  Constant: '<S289>/Constant'
    *  Constant: '<S289>/Constant1'
    *  Delay: '<S46>/Delay'
    *  RelationalOperator: '<S289>/Equal'
    *  RelationalOperator: '<S289>/Equal1'
    */
   rtb_LogicalOperator =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE >= -1.74532926F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE <= 1.74532926F));

   /* RelationalOperator: '<S72>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S218>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_vehicle_speed_qf;

   /* Switch: '<S48>/Switch' incorporates:
    *  Abs: '<S4>/Abs'
    *  Constant: '<S72>/Constant'
    *  Delay: '<S48>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S72>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d =
         fabsf(VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_vehicle_speed);
   }

   /* End of Switch: '<S48>/Switch' */

   /* Logic: '<S216>/Logical Operator' incorporates:
    *  Constant: '<S216>/Constant'
    *  Constant: '<S216>/Constant1'
    *  Delay: '<S48>/Delay'
    *  RelationalOperator: '<S216>/Equal'
    *  RelationalOperator: '<S216>/Equal1'
    */
   rtb_LogicalOperator_jn =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d >= 0.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d <= 150.0F));

   /* Chart: '<S32>/Chart' */
   if (((uint32_T)VSE_Master_Model_WL_L2P_DW->bitsForTID0.is_active_c3_VSE_Master_Model_WL_L2P) == 0U)
   {
      VSE_Master_Model_WL_L2P_DW->bitsForTID0.is_active_c3_VSE_Master_Model_WL_L2P = 1;
      VSE_Master_Model_WL_L2P_DW->bitsForTID0.is_c3_VSE_Master_Model_WL_L2P        = VSE_Master_Model_WL_L2P_IN_Initialize_g;
      VSE_Master_Model_WL_L2P_DW->bitsForTID0.f_initialize_vse                     = true;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index                              = 0U;
   }
   else if (((uint32_T)VSE_Master_Model_WL_L2P_DW->bitsForTID0.is_c3_VSE_Master_Model_WL_L2P) ==
            VSE_Master_Model_WL_L2P_IN_Initialize_g)
   {
      if (VSE_Master_Model_WL_L2P_DW->bitsForTID0.f_initialize_vse)
      {
         VSE_Master_Model_WL_L2P_DW->bitsForTID0.is_c3_VSE_Master_Model_WL_L2P = VSE_Master_Model_WL_L2P_IN_Running_f;
         VSE_Master_Model_WL_L2P_DW->bitsForTID0.f_initialize_vse              = false;
         qY = VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index + /*MW:OvSatOk*/ 1U;
         if (qY < VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index)
         {
            qY = MAX_uint32_T;
         }

         VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index = qY;
      }
   }
   else
   {
      VSE_Master_Model_WL_L2P_DW->bitsForTID0.f_initialize_vse = false;
      qY = VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index + /*MW:OvSatOk*/ 1U;
      if (qY < VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index)
      {
         qY = MAX_uint32_T;
      }

      VSE_Master_Model_WL_L2P_Y_VSE_Output->veh_index = qY;
   }

   /* End of Chart: '<S32>/Chart' */

   /* Chart: '<S27>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_gm,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_j);

   /* Outputs for Enabled SubSystem: '<S27>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_gm, VSE_Master_Model_WL_L2P_DW->diff_num_kn,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_e);

   /* End of Outputs for SubSystem: '<S27>/Initialization' */

   /* DiscreteFilter: '<S27>/Discrete Filter' incorporates:
    *  Delay: '<S48>/Delay'
    */
   denAccum = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_e[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[0])) -
               (VSE_Master_Model_WL_L2P_DW->diff_denom_e[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[1])) -
              (VSE_Master_Model_WL_L2P_DW->diff_denom_e[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_kn[0] * denAccum) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_kn[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_kn[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_kn[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[2]);

   /* Logic: '<S217>/Logical Operator' incorporates:
    *  Constant: '<S217>/Constant1'
    *  Constant: '<S217>/Constant2'
    *  DiscreteFilter: '<S27>/Discrete Filter'
    *  RelationalOperator: '<S217>/Equal'
    *  RelationalOperator: '<S217>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -1.0E+6F) && (rtb_DataTypeConversion_a <= 1.0E+6F));

   /* If: '<S213>/If' incorporates:
    *  Constant: '<S213>/Constant'
    *  Constant: '<S213>/Constant1'
    *  Constant: '<S213>/Constant2'
    *  Constant: '<S213>/Constant3'
    *  Constant: '<S218>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S219>/In1'
    *  Inport: '<S220>/In1'
    *  Inport: '<S221>/In1'
    *  Inport: '<S222>/In1'
    *  Inport: '<S223>/In1'
    *  RelationalOperator: '<S218>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S213>/If Action Subsystem' incorporates:
       *  ActionPort: '<S219>/Action Port'
       */
      rtb_Merge = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_vehicle_speed_qf;

      /* End of Outputs for SubSystem: '<S213>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_jn && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S213>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S220>/Action Port'
       */
      rtb_Merge = ACCURATED;

      /* End of Outputs for SubSystem: '<S213>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_jn) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S213>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S221>/Action Port'
       */
      rtb_Merge = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S213>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_jn && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S213>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S222>/Action Port'
       */
      rtb_Merge = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S213>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S213>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S223>/Action Port'
       */
      rtb_Merge = UNDEFINED;

      /* End of Outputs for SubSystem: '<S213>/If Action Subsystem4' */
   }

   /* End of If: '<S213>/If' */

   /* RelationalOperator: '<S73>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S230>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ground_speed_qf_gvpm;

   /* Switch: '<S49>/Switch' incorporates:
    *  Abs: '<S4>/Abs1'
    *  Constant: '<S73>/Constant'
    *  Delay: '<S49>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S73>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k =
         fabsf(VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ground_speed_gvpm);
   }

   /* End of Switch: '<S49>/Switch' */

   /* Logic: '<S228>/Logical Operator' incorporates:
    *  Constant: '<S228>/Constant'
    *  Constant: '<S228>/Constant1'
    *  Delay: '<S49>/Delay'
    *  RelationalOperator: '<S228>/Equal'
    *  RelationalOperator: '<S228>/Equal1'
    */
   rtb_LogicalOperator_jn =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k >= 0.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k <= 150.0F));

   /* Chart: '<S28>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_g,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_d);

   /* Outputs for Enabled SubSystem: '<S28>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_g, VSE_Master_Model_WL_L2P_DW->diff_num_es,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_oi);

   /* End of Outputs for SubSystem: '<S28>/Initialization' */

   /* DiscreteFilter: '<S28>/Discrete Filter' incorporates:
    *  Delay: '<S49>/Delay'
    */
   denAccum_0 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_oi[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_oi[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_oi[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_es[0] * denAccum_0) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_es[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_es[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_es[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[2]);

   /* Logic: '<S229>/Logical Operator' incorporates:
    *  Constant: '<S229>/Constant1'
    *  Constant: '<S229>/Constant2'
    *  DiscreteFilter: '<S28>/Discrete Filter'
    *  RelationalOperator: '<S229>/Equal'
    *  RelationalOperator: '<S229>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -1.0E+6F) && (rtb_DataTypeConversion_a <= 1.0E+6F));

   /* If: '<S225>/If' incorporates:
    *  Constant: '<S225>/Constant'
    *  Constant: '<S225>/Constant1'
    *  Constant: '<S225>/Constant2'
    *  Constant: '<S225>/Constant3'
    *  Constant: '<S230>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S231>/In1'
    *  Inport: '<S232>/In1'
    *  Inport: '<S233>/In1'
    *  Inport: '<S234>/In1'
    *  Inport: '<S235>/In1'
    *  RelationalOperator: '<S230>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem' incorporates:
       *  ActionPort: '<S231>/Action Port'
       */
      rtb_Merge_b = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ground_speed_qf_gvpm;

      /* End of Outputs for SubSystem: '<S225>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_jn && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S232>/Action Port'
       */
      rtb_Merge_b = ACCURATED;

      /* End of Outputs for SubSystem: '<S225>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_jn) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S233>/Action Port'
       */
      rtb_Merge_b = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S225>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_jn && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S234>/Action Port'
       */
      rtb_Merge_b = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S225>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S235>/Action Port'
       */
      rtb_Merge_b = UNDEFINED;

      /* End of Outputs for SubSystem: '<S225>/If Action Subsystem4' */
   }

   /* End of If: '<S225>/If' */

   /* Chart: '<S29>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_k,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_i);

   /* Outputs for Enabled SubSystem: '<S29>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_k, VSE_Master_Model_WL_L2P_DW->diff_num_f,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_gf);

   /* End of Outputs for SubSystem: '<S29>/Initialization' */

   /* DiscreteFilter: '<S29>/Discrete Filter' incorporates:
    *  Delay: '<S45>/Delay'
    */
   denAccum_1 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_c -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_gf[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_gf[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_gf[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[2]);

   /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem4' incorporates:
    *  ActionPort: '<S247>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem3' incorporates:
    *  ActionPort: '<S246>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem2' incorporates:
    *  ActionPort: '<S245>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem1' incorporates:
    *  ActionPort: '<S244>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem' incorporates:
    *  ActionPort: '<S243>/Action Port'
    */
   /* If: '<S237>/If' incorporates:
    *  Constant: '<S4>/Constant6'
    *  Inport: '<S243>/In1'
    *  Inport: '<S244>/In1'
    *  Inport: '<S245>/In1'
    *  Inport: '<S246>/In1'
    *  Inport: '<S247>/In1'
    */
   rtb_Merge_a = UNDEFINED;

   /* End of Outputs for SubSystem: '<S237>/If Action Subsystem' */
   /* End of Outputs for SubSystem: '<S237>/If Action Subsystem1' */
   /* End of Outputs for SubSystem: '<S237>/If Action Subsystem2' */
   /* End of Outputs for SubSystem: '<S237>/If Action Subsystem3' */
   /* End of Outputs for SubSystem: '<S237>/If Action Subsystem4' */

   /* ModelReference: '<S1>/RawSpeedArbitration' incorporates:
    *  Delay: '<S45>/Delay'
    *  Delay: '<S48>/Delay'
    *  Delay: '<S49>/Delay'
    */
   Signal_Arbitration_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k,
                             &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_c, &rtb_Merge, &rtb_Merge_b, &rtb_Merge_a,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number,
                             &(VSE_Master_Model_WL_L2P_DW->RawSpeedArbitration_InstanceData.rtdw));

   /* ModelReference: '<S1>/Model5' incorporates:
    *  Inport: '<Root>/Tracker_VSE'
    */
   SpeedCompensationArbitration(&VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_1,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_QF_1,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_2,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_QF_2,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_3,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_QF_3,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_4,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_QF_4,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_5,
                                &VSE_Master_Model_WL_L2P_U_Tracker_VSE_m->VehSpeedCompFac_KA_QF_5, &rtb_VsTracker_VehSpdCompFac,
                                &rtb_VeTracker_VehSpdCompFac_QF);

   /* ModelReference: '<S1>/SpeedCompensation' incorporates:
    *  Constant: '<S1>/default_f_use_gps_comp_factor'
    *  Constant: '<S1>/default_gps_comp_factor'
    *  Inport: '<Root>/LAST_KEY_CYCLE'
    */
   SpeedCompensation(&VSE_Master_Model_WL_L2P_DW->selected_signal, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf,
                     &rtb_VsTracker_VehSpdCompFac, &rtb_VeTracker_VehSpdCompFac_QF,
                     &VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_speed_comp,
                     &VSE_Master_Model_WL_L2P_ConstP.pooled18, &VSE_Master_Model_WL_L2P_ConstP.pooled35, &rtb_SpeedCompensation_o1,
                     &rtb_SpeedCompensation_o2, &(VSE_Master_Model_WL_L2P_DW->SpeedCompensation_InstanceData.rtdw));

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fl_wheel_spin = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_spin;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fr_wheel_spin = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_spin;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_rl_wheel_spin = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rl_wheel_spin;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_rr_wheel_spin = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rr_wheel_spin;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fl_wheel_pulse_counter = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_pulse_counter;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fr_wheel_pulse_counter = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_pulse_counter;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_rl_wheel_pulse_counter = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rl_wheel_pulse_counter;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_rr_wheel_pulse_counter = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rr_wheel_pulse_counter;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_gear_box_pos = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->gear_box_pos;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_pulse_counter_qf;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Cast4 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_pulse_counter_qf;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Merge_mg = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rl_wheel_pulse_counter_qf;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Merge_lr = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rr_wheel_pulse_counter_qf;

   /* ModelReference: '<S1>/DetermineReverseStatus' */
   DetermineReverseStatus(&rtb_fl_wheel_spin, &rtb_fr_wheel_spin, &rtb_rl_wheel_spin, &rtb_rr_wheel_spin,
                          &rtb_fl_wheel_pulse_counter, &rtb_fr_wheel_pulse_counter, &rtb_rl_wheel_pulse_counter,
                          &rtb_rr_wheel_pulse_counter, &rtb_gear_box_pos, &rtb_Merge_mz, &rtb_Cast4, &rtb_Merge_mg, &rtb_Merge_lr,
                          &rtb_DetermineReverseStatus, &(VSE_Master_Model_WL_L2P_DW->DetermineReverseStatus_InstanceData.rtdw));

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fl_wheel_speed = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_speed;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fr_wheel_speed = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_speed;

   /* RelationalOperator: '<S74>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S110>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_lateral_accel_qf;

   /* Switch: '<S50>/Switch' incorporates:
    *  Constant: '<S74>/Constant'
    *  Delay: '<S50>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S74>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_lateral_accel;
   }

   /* End of Switch: '<S50>/Switch' */

   /* Logic: '<S108>/Logical Operator' incorporates:
    *  Constant: '<S108>/Constant'
    *  Constant: '<S108>/Constant1'
    *  Delay: '<S50>/Delay'
    *  RelationalOperator: '<S108>/Equal'
    *  RelationalOperator: '<S108>/Equal1'
    */
   rtb_LogicalOperator_jn =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i >= -15.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i <= 15.0F));

   /* Chart: '<S8>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_b,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger);

   /* Outputs for Enabled SubSystem: '<S8>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_b, VSE_Master_Model_WL_L2P_DW->diff_num_m,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_kv);

   /* End of Outputs for SubSystem: '<S8>/Initialization' */

   /* DiscreteFilter: '<S8>/Discrete Filter' incorporates:
    *  Delay: '<S50>/Delay'
    */
   denAccum_2 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_kv[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_kv[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_kv[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_m[0] * denAccum_2) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_m[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_m[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_m[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[2]);

   /* Logic: '<S109>/Logical Operator' incorporates:
    *  Constant: '<S109>/Constant1'
    *  Constant: '<S109>/Constant2'
    *  DiscreteFilter: '<S8>/Discrete Filter'
    *  RelationalOperator: '<S109>/Equal'
    *  RelationalOperator: '<S109>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -50.0F) && (rtb_DataTypeConversion_a <= 50.0F));

   /* If: '<S105>/If' incorporates:
    *  Constant: '<S105>/Constant'
    *  Constant: '<S105>/Constant1'
    *  Constant: '<S105>/Constant2'
    *  Constant: '<S105>/Constant3'
    *  Constant: '<S110>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S111>/In1'
    *  Inport: '<S112>/In1'
    *  Inport: '<S113>/In1'
    *  Inport: '<S114>/In1'
    *  Inport: '<S115>/In1'
    *  RelationalOperator: '<S110>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem' incorporates:
       *  ActionPort: '<S111>/Action Port'
       */
      rtb_Merge_l = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_lateral_accel_qf;

      /* End of Outputs for SubSystem: '<S105>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_jn && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S112>/Action Port'
       */
      rtb_Merge_l = ACCURATED;

      /* End of Outputs for SubSystem: '<S105>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_jn) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S113>/Action Port'
       */
      rtb_Merge_l = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S105>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_jn && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S114>/Action Port'
       */
      rtb_Merge_l = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S105>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S105>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S115>/Action Port'
       */
      rtb_Merge_l = UNDEFINED;

      /* End of Outputs for SubSystem: '<S105>/If Action Subsystem4' */
   }

   /* End of If: '<S105>/If' */

   /* RelationalOperator: '<S75>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S122>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->lateral_acceleration_qf_gvpm;

   /* Switch: '<S51>/Switch' incorporates:
    *  Constant: '<S75>/Constant'
    *  Delay: '<S51>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S75>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->lateral_acceleration_gvpm;
   }

   /* End of Switch: '<S51>/Switch' */

   /* Logic: '<S120>/Logical Operator' incorporates:
    *  Constant: '<S120>/Constant'
    *  Constant: '<S120>/Constant1'
    *  Delay: '<S51>/Delay'
    *  RelationalOperator: '<S120>/Equal'
    *  RelationalOperator: '<S120>/Equal1'
    */
   rtb_LogicalOperator_jn =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j >= -15.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j <= 15.0F));

   /* Chart: '<S9>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_p,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_g);

   /* Outputs for Enabled SubSystem: '<S9>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_p, VSE_Master_Model_WL_L2P_DW->diff_num_knm,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_k);

   /* End of Outputs for SubSystem: '<S9>/Initialization' */

   /* DiscreteFilter: '<S9>/Discrete Filter' incorporates:
    *  Delay: '<S51>/Delay'
    */
   denAccum_3 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_k[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_k[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_k[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_knm[0] * denAccum_3) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_knm[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_knm[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_knm[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[2]);

   /* Logic: '<S121>/Logical Operator' incorporates:
    *  Constant: '<S121>/Constant1'
    *  Constant: '<S121>/Constant2'
    *  DiscreteFilter: '<S9>/Discrete Filter'
    *  RelationalOperator: '<S121>/Equal'
    *  RelationalOperator: '<S121>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -50.0F) && (rtb_DataTypeConversion_a <= 50.0F));

   /* If: '<S117>/If' incorporates:
    *  Constant: '<S117>/Constant'
    *  Constant: '<S117>/Constant1'
    *  Constant: '<S117>/Constant2'
    *  Constant: '<S117>/Constant3'
    *  Constant: '<S122>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S123>/In1'
    *  Inport: '<S124>/In1'
    *  Inport: '<S125>/In1'
    *  Inport: '<S126>/In1'
    *  Inport: '<S127>/In1'
    *  RelationalOperator: '<S122>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem' incorporates:
       *  ActionPort: '<S123>/Action Port'
       */
      rtb_Merge_a5 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->lateral_acceleration_qf_gvpm;

      /* End of Outputs for SubSystem: '<S117>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_jn && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S124>/Action Port'
       */
      rtb_Merge_a5 = ACCURATED;

      /* End of Outputs for SubSystem: '<S117>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_jn) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S125>/Action Port'
       */
      rtb_Merge_a5 = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S117>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_jn && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S126>/Action Port'
       */
      rtb_Merge_a5 = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S117>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S127>/Action Port'
       */
      rtb_Merge_a5 = UNDEFINED;

      /* End of Outputs for SubSystem: '<S117>/If Action Subsystem4' */
   }

   /* End of If: '<S117>/If' */

   /* ModelReference: '<S1>/RawLateralAccelerationArbitration' incorporates:
    *  Delay: '<S50>/Delay'
    *  Delay: '<S51>/Delay'
    */
   Signal_Arbitration_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j,
                             &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j, &rtb_Merge_l, &rtb_Merge_a5, &rtb_Merge_a5,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_a, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number_e,
                             &(VSE_Master_Model_WL_L2P_DW->RawLateralAccelerationArbitration_InstanceData.rtdw));

   /* RelationalOperator: '<S64>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S254>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->steering_whl_angle_qf;

   /* Switch: '<S40>/Switch' incorporates:
    *  Constant: '<S64>/Constant'
    *  Delay: '<S40>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S64>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->steering_whl_angle;
   }

   /* End of Switch: '<S40>/Switch' */

   /* Logic: '<S252>/Logical Operator' incorporates:
    *  Constant: '<S252>/Constant'
    *  Constant: '<S252>/Constant1'
    *  Delay: '<S40>/Delay'
    *  RelationalOperator: '<S252>/Equal'
    *  RelationalOperator: '<S252>/Equal1'
    */
   rtb_LogicalOperator_jn =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f >= -720.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f <= 720.0F));

   /* Chart: '<S30>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_ia,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_ie);

   /* Outputs for Enabled SubSystem: '<S30>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_ia, VSE_Master_Model_WL_L2P_DW->diff_num_h,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_b);

   /* End of Outputs for SubSystem: '<S30>/Initialization' */

   /* DiscreteFilter: '<S30>/Discrete Filter' incorporates:
    *  Delay: '<S40>/Delay'
    */
   denAccum_4 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_b[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_b[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_b[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_h[0] * denAccum_4) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_h[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_h[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_h[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[2]);

   /* Logic: '<S253>/Logical Operator' incorporates:
    *  Constant: '<S253>/Constant1'
    *  Constant: '<S253>/Constant2'
    *  DiscreteFilter: '<S30>/Discrete Filter'
    *  RelationalOperator: '<S253>/Equal'
    *  RelationalOperator: '<S253>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -2000.0F) && (rtb_DataTypeConversion_a <= 2000.0F));

   /* If: '<S249>/If' incorporates:
    *  Constant: '<S249>/Constant'
    *  Constant: '<S249>/Constant1'
    *  Constant: '<S249>/Constant2'
    *  Constant: '<S249>/Constant3'
    *  Constant: '<S254>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S255>/In1'
    *  Inport: '<S256>/In1'
    *  Inport: '<S257>/In1'
    *  Inport: '<S258>/In1'
    *  Inport: '<S259>/In1'
    *  RelationalOperator: '<S254>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_Merge_mz) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S249>/If Action Subsystem' incorporates:
       *  ActionPort: '<S255>/Action Port'
       */
      rtb_Merge_d = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->steering_whl_angle_qf;

      /* End of Outputs for SubSystem: '<S249>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_jn && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S249>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S256>/Action Port'
       */
      rtb_Merge_d = ACCURATED;

      /* End of Outputs for SubSystem: '<S249>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_jn) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S249>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S257>/Action Port'
       */
      rtb_Merge_d = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S249>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_jn && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S249>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S258>/Action Port'
       */
      rtb_Merge_d = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S249>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S249>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S259>/Action Port'
       */
      rtb_Merge_d = UNDEFINED;

      /* End of Outputs for SubSystem: '<S249>/If Action Subsystem4' */
   }

   /* End of If: '<S249>/If' */

   /* Chart: '<S31>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_iv,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_ak);

   /* Outputs for Enabled SubSystem: '<S31>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_iv, VSE_Master_Model_WL_L2P_DW->diff_num_a,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_g);

   /* End of Outputs for SubSystem: '<S31>/Initialization' */

   /* DiscreteFilter: '<S31>/Discrete Filter' incorporates:
    *  Delay: '<S41>/Delay'
    */
   denAccum_5 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_l -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_g[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_g[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_g[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[2]);

   /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem4' incorporates:
    *  ActionPort: '<S271>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem3' incorporates:
    *  ActionPort: '<S270>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem2' incorporates:
    *  ActionPort: '<S269>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem1' incorporates:
    *  ActionPort: '<S268>/Action Port'
    */
   /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem' incorporates:
    *  ActionPort: '<S267>/Action Port'
    */
   /* If: '<S261>/If' incorporates:
    *  Constant: '<S4>/Constant2'
    *  Inport: '<S267>/In1'
    *  Inport: '<S268>/In1'
    *  Inport: '<S269>/In1'
    *  Inport: '<S270>/In1'
    *  Inport: '<S271>/In1'
    */
   rtb_Merge_p = UNDEFINED;

   /* End of Outputs for SubSystem: '<S261>/If Action Subsystem' */
   /* End of Outputs for SubSystem: '<S261>/If Action Subsystem1' */
   /* End of Outputs for SubSystem: '<S261>/If Action Subsystem2' */
   /* End of Outputs for SubSystem: '<S261>/If Action Subsystem3' */
   /* End of Outputs for SubSystem: '<S261>/If Action Subsystem4' */

   /* ModelReference: '<S1>/RawSteeringAngleArbitration' incorporates:
    *  Delay: '<S40>/Delay'
    *  Delay: '<S41>/Delay'
    */
   Signal_Arbitration_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_l,
                             &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_l, &rtb_Merge_d, &rtb_Merge_p, &rtb_Merge_p,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_b, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_i,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number_m,
                             &(VSE_Master_Model_WL_L2P_DW->RawSteeringAngleArbitration_InstanceData.rtdw));

   /* UnitDelay: '<S1>/Unit Delay2' */
   rtb_final_fault_f = VSE_Master_Model_WL_L2P_DW->UnitDelay2_DSTATE;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_DataTypeConversion_p = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->tire_pressure_front_right_psi;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_DataTypeConversion_lk = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->tire_pressure_front_left_psi;

   /* ModelReference: '<S1>/Steering Wheel Angle Bias Estimation' incorporates:
    *  Constant: '<S4>/Constant1'
    *  Constant: '<S4>/Constant3'
    *  Inport: '<Root>/LAST_KEY_CYCLE'
    *  Inport: '<Root>/Vehicle_Parameters'
    *  UnitDelay: '<S1>/Unit Delay'
    *  UnitDelay: '<S1>/Unit Delay1'
    */
   SteeringWheelAngleBiasEstimation(
      &rtb_SpeedCompensation_o1, &VSE_Master_Model_WL_L2P_DW->UnitDelay1_DSTATE, &VSE_Master_Model_WL_L2P_DW->selected_signal_a,
      &VSE_Master_Model_WL_L2P_DW->selected_signal_b, &rtb_SpeedCompensation_o2, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf,
      &VSE_Master_Model_WL_L2P_DW->UnitDelay_DSTATE_c, &rtb_final_fault_f, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g,
      &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_i, &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_DataTypeConversion_p,
      &rtb_DataTypeConversion_lk, &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_front_track_width,
      &VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_swa_bias_deg,
      &VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_f_last_rem_swa_bias, &VSE_Master_Model_WL_L2P_ConstP.pooled11,
      &VSE_Master_Model_WL_L2P_ConstP.pooled36, &VSE_Master_Model_WL_L2P_DW->f_SWA_Bias_deg_Conv_out,
      &VSE_Master_Model_WL_L2P_DW->SWA_Bias_deg_Conv_Out, &VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_deg_SAE,
      &VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_QF, &VSE_Master_Model_WL_L2P_DW->f_SWA_Bias_deg_Conv_internal,
      &(VSE_Master_Model_WL_L2P_DW->SteeringWheelAngleBiasEstimation_InstanceData.rtdw));

   /* RelationalOperator: '<S39>/Compare' incorporates:
    *  Constant: '<S39>/Constant'
    *  Inport: '<Root>/AptivCfg'
    */
   rtb_LogicalOperator_jn = (((int32_T)VSE_Master_Model_WL_L2P_U_AptivCfg_p->CsPROXI_SteeringSystemInputType) == 1);

   /* Switch: '<S58>/Switch1' incorporates:
    *  Constant: '<S56>/k_rws_angle_not_activated_rad'
    *  Constant: '<S58>/k_rws_angle_not_activated_rad'
    *  Constant: '<S59>/validity_default'
    *  Constant: '<S60>/validity_default'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    *  Switch: '<S56>/Switch1'
    *  Switch: '<S59>/Switch1'
    *  Switch: '<S60>/Switch1'
    */
   if (rtb_LogicalOperator_jn)
   {
      rtb_Switch1    = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rwa_measured_rad;
      rtb_Cast4      = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rwa_measured_rad_validity;
      rtb_Switch1_d  = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rear_rwa_measured_rad;
      rtb_Switch1_n5 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rear_rwa_measured_rad_validity;
   }
   else
   {
      rtb_Switch1    = 0.0F;
      rtb_Cast4      = UNDEFINED;
      rtb_Switch1_d  = 0.0F;
      rtb_Switch1_n5 = UNDEFINED;
   }

   /* End of Switch: '<S58>/Switch1' */

   /* ModelReference: '<S1>/YawRateEstimationUsingSteeringWheelAngle' incorporates:
    *  Inport: '<Root>/Vehicle_Parameters'
    */
   YawRateEstimationUsingSteeringWheelAngle(
      &rtb_SpeedCompensation_o1, &rtb_DetermineReverseStatus, &VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_deg_SAE,
      &VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_QF, &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_wheel_base,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_steering_gear_ratio,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_understeer_coefficient, &rtb_Switch1, &rtb_Cast4, &rtb_Switch1_d,
      &rtb_Switch1_n5, &rtb_LogicalOperator_jn, &rtb_yawRate, &rtb_qf, &rtb_YawRateEstimationUsingSteeringWheelAngle_o3,
      &rtb_YawRateEstimationUsingSteeringWheelAngle_o4,
      &(VSE_Master_Model_WL_L2P_DW->YawRateEstimationUsingSteeringWheelAngle_InstanceData.rtdw));

   /* Chart: '<S34>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_j,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_o);

   /* Outputs for Enabled SubSystem: '<S34>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_j, VSE_Master_Model_WL_L2P_DW->diff_num_e,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_dh);

   /* End of Outputs for SubSystem: '<S34>/Initialization' */

   /* DiscreteFilter: '<S34>/Discrete Filter' incorporates:
    *  Delay: '<S46>/Delay'
    */
   rtb_DataTypeConversion_p =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE -
        (VSE_Master_Model_WL_L2P_DW->diff_denom_dh[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[0])) -
       (VSE_Master_Model_WL_L2P_DW->diff_denom_dh[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[1])) -
      (VSE_Master_Model_WL_L2P_DW->diff_denom_dh[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_e[0] * rtb_DataTypeConversion_p) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_e[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_e[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_e[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[2]);

   /* Logic: '<S290>/Logical Operator' incorporates:
    *  Constant: '<S290>/Constant1'
    *  Constant: '<S290>/Constant2'
    *  DiscreteFilter: '<S34>/Discrete Filter'
    *  RelationalOperator: '<S290>/Equal'
    *  RelationalOperator: '<S290>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -3.0543263F) && (rtb_DataTypeConversion_a <= 3.0543263F));

   /* If: '<S286>/If' incorporates:
    *  Constant: '<S286>/Constant'
    *  Constant: '<S286>/Constant1'
    *  Constant: '<S286>/Constant2'
    *  Constant: '<S286>/Constant3'
    *  Constant: '<S291>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S292>/In1'
    *  Inport: '<S293>/In1'
    *  Inport: '<S294>/In1'
    *  Inport: '<S295>/In1'
    *  Inport: '<S296>/In1'
    *  RelationalOperator: '<S291>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S286>/If Action Subsystem' incorporates:
       *  ActionPort: '<S292>/Action Port'
       */
      rtb_Merge_e = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_yaw_rate_qf;

      /* End of Outputs for SubSystem: '<S286>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S286>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S293>/Action Port'
       */
      rtb_Merge_e = ACCURATED;

      /* End of Outputs for SubSystem: '<S286>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S286>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S294>/Action Port'
       */
      rtb_Merge_e = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S286>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S286>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S295>/Action Port'
       */
      rtb_Merge_e = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S286>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S286>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S296>/Action Port'
       */
      rtb_Merge_e = UNDEFINED;

      /* End of Outputs for SubSystem: '<S286>/If Action Subsystem4' */
   }

   /* End of If: '<S286>/If' */

   /* Logic: '<S301>/Logical Operator' incorporates:
    *  Constant: '<S301>/Constant'
    *  Constant: '<S301>/Constant1'
    *  Delay: '<S47>/Delay'
    *  RelationalOperator: '<S301>/Equal'
    *  RelationalOperator: '<S301>/Equal1'
    */
   rtb_LogicalOperator = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b >= -1.74532926F) &&
                          (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b <= 1.74532926F));

   /* Chart: '<S35>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_ds);

   /* Outputs for Enabled SubSystem: '<S35>/Initialization' incorporates:
    *  EnablePort: '<S299>/Enable'
    */
   if (VSE_Master_Model_WL_L2P_DW->f_initialize)
   {
      /* MATLAB Function: '<S299>/MATLAB Function' */
      VSE_Master_Model_WL_L2P_DW->diff_num_d[0]   = 0.724336267F;
      VSE_Master_Model_WL_L2P_DW->diff_denom_p[0] = 1.0F;
      VSE_Master_Model_WL_L2P_DW->diff_num_d[1]   = 0.724336267F;
      VSE_Master_Model_WL_L2P_DW->diff_denom_p[1] = -0.822694957F;
      VSE_Master_Model_WL_L2P_DW->diff_num_d[2]   = -0.724336267F;
      VSE_Master_Model_WL_L2P_DW->diff_denom_p[2] = -0.98551327F;
      VSE_Master_Model_WL_L2P_DW->diff_num_d[3]   = -0.724336267F;
      VSE_Master_Model_WL_L2P_DW->diff_denom_p[3] = 0.837181628F;
   }

   /* End of Outputs for SubSystem: '<S35>/Initialization' */

   /* DiscreteFilter: '<S35>/Discrete Filter' incorporates:
    *  Delay: '<S47>/Delay'
    */
   rtb_DataTypeConversion_lk =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b -
        (VSE_Master_Model_WL_L2P_DW->diff_denom_p[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[0])) -
       (VSE_Master_Model_WL_L2P_DW->diff_denom_p[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[1])) -
      (VSE_Master_Model_WL_L2P_DW->diff_denom_p[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_d[0] * rtb_DataTypeConversion_lk) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_d[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_d[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_d[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[2]);

   /* Logic: '<S302>/Logical Operator' incorporates:
    *  Constant: '<S302>/Constant1'
    *  Constant: '<S302>/Constant2'
    *  DiscreteFilter: '<S35>/Discrete Filter'
    *  RelationalOperator: '<S302>/Equal'
    *  RelationalOperator: '<S302>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -3.0543263F) && (rtb_DataTypeConversion_a <= 3.0543263F));

   /* If: '<S298>/If' incorporates:
    *  Constant: '<S298>/Constant'
    *  Constant: '<S298>/Constant1'
    *  Constant: '<S298>/Constant2'
    *  Constant: '<S298>/Constant3'
    *  Constant: '<S303>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S304>/In1'
    *  Inport: '<S305>/In1'
    *  Inport: '<S306>/In1'
    *  Inport: '<S307>/In1'
    *  Inport: '<S308>/In1'
    *  RelationalOperator: '<S303>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S298>/If Action Subsystem' incorporates:
       *  ActionPort: '<S304>/Action Port'
       */
      rtb_Merge_i = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->yaw_rate_qf_gvpm;

      /* End of Outputs for SubSystem: '<S298>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S298>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S305>/Action Port'
       */
      rtb_Merge_i = ACCURATED;

      /* End of Outputs for SubSystem: '<S298>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S298>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S306>/Action Port'
       */
      rtb_Merge_i = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S298>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S298>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S307>/Action Port'
       */
      rtb_Merge_i = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S298>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S298>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S308>/Action Port'
       */
      rtb_Merge_i = UNDEFINED;

      /* End of Outputs for SubSystem: '<S298>/If Action Subsystem4' */
   }

   /* End of If: '<S298>/If' */

   /* Logic: '<S14>/AND' incorporates:
    *  Constant: '<S177>/Constant'
    *  DataTypeConversion: '<S14>/Cast To Single2'
    *  DataTypeConversion: '<S14>/Cast To Single3'
    *  RelationalOperator: '<S14>/Equal'
    *  RelationalOperator: '<S177>/Compare'
    */
   rtb_final_fault_f = ((rtb_Merge_e == rtb_Merge_i) && (((int32_T)rtb_Merge_i) != 0));

   /* DataTypeConversion: '<S14>/Cast To Single4' */
   rtb_gear_box_pos = rtb_final_fault_f ? 1U : 0U;

   /* ModelReference: '<S1>/Model1' incorporates:
    *  Delay: '<S46>/Delay'
    *  Delay: '<S47>/Delay'
    */
   Signal_Arbitration_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b,
                             &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b, &rtb_Merge_e, &rtb_Merge_i, &rtb_Merge_i,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_ag, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_h,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number_p,
                             &(VSE_Master_Model_WL_L2P_DW->Model1_InstanceData.rtdw));

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_ego_longitudinal_accel_qf = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_longitudinal_accel_qf;

   /* Switch: '<S52>/Switch' incorporates:
    *  Constant: '<S76>/Constant'
    *  Delay: '<S52>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S76>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)rtb_ego_longitudinal_accel_qf) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->ego_longitudinal_accel;
   }

   /* End of Switch: '<S52>/Switch' */

   /* Logic: '<S132>/Logical Operator' incorporates:
    *  Constant: '<S132>/Constant'
    *  Constant: '<S132>/Constant1'
    *  Delay: '<S52>/Delay'
    *  RelationalOperator: '<S132>/Equal'
    *  RelationalOperator: '<S132>/Equal1'
    */
   rtb_LogicalOperator =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o >= -15.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o <= 15.0F));

   /* Chart: '<S10>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_mm,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_e);

   /* Outputs for Enabled SubSystem: '<S10>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_mm, VSE_Master_Model_WL_L2P_DW->diff_num_gb,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_ez);

   /* End of Outputs for SubSystem: '<S10>/Initialization' */

   /* DiscreteFilter: '<S10>/Discrete Filter' incorporates:
    *  Delay: '<S52>/Delay'
    */
   denAccum_6 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_ez[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_ez[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_ez[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_gb[0] * denAccum_6) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_gb[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_gb[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_gb[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[2]);

   /* Logic: '<S133>/Logical Operator' incorporates:
    *  Constant: '<S133>/Constant1'
    *  Constant: '<S133>/Constant2'
    *  DiscreteFilter: '<S10>/Discrete Filter'
    *  RelationalOperator: '<S133>/Equal'
    *  RelationalOperator: '<S133>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -50.0F) && (rtb_DataTypeConversion_a <= 50.0F));

   /* If: '<S129>/If' incorporates:
    *  Constant: '<S129>/Constant'
    *  Constant: '<S129>/Constant1'
    *  Constant: '<S129>/Constant2'
    *  Constant: '<S129>/Constant3'
    *  Constant: '<S134>/Constant'
    *  Inport: '<S135>/In1'
    *  Inport: '<S136>/In1'
    *  Inport: '<S137>/In1'
    *  Inport: '<S138>/In1'
    *  Inport: '<S139>/In1'
    *  RelationalOperator: '<S134>/Compare'
    *  RelationalOperator: '<S76>/Compare'
    */
   if (((uint32_T)rtb_ego_longitudinal_accel_qf) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem' incorporates:
       *  ActionPort: '<S135>/Action Port'
       */
      rtb_Merge_iw = rtb_ego_longitudinal_accel_qf;

      /* End of Outputs for SubSystem: '<S129>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S136>/Action Port'
       */
      rtb_Merge_iw = ACCURATED;

      /* End of Outputs for SubSystem: '<S129>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S137>/Action Port'
       */
      rtb_Merge_iw = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S129>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S138>/Action Port'
       */
      rtb_Merge_iw = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S129>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S139>/Action Port'
       */
      rtb_Merge_iw = UNDEFINED;

      /* End of Outputs for SubSystem: '<S129>/If Action Subsystem4' */
   }

   /* End of If: '<S129>/If' */

   /* RelationalOperator: '<S77>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S146>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp_0 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->logitudinal_acceleration_qf_gvpm;

   /* Switch: '<S53>/Switch' incorporates:
    *  Constant: '<S77>/Constant'
    *  Delay: '<S53>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S77>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->longitudinal_acceleration_gvpm;
   }

   /* End of Switch: '<S53>/Switch' */

   /* Logic: '<S144>/Logical Operator' incorporates:
    *  Constant: '<S144>/Constant'
    *  Constant: '<S144>/Constant1'
    *  Delay: '<S53>/Delay'
    *  RelationalOperator: '<S144>/Equal'
    *  RelationalOperator: '<S144>/Equal1'
    */
   rtb_LogicalOperator =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm >= -15.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm <= 15.0F));

   /* Chart: '<S11>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_io,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_a);

   /* Outputs for Enabled SubSystem: '<S11>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_io, VSE_Master_Model_WL_L2P_DW->diff_num_g,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_gd);

   /* End of Outputs for SubSystem: '<S11>/Initialization' */

   /* DiscreteFilter: '<S11>/Discrete Filter' incorporates:
    *  Delay: '<S53>/Delay'
    */
   denAccum_7 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_gd[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_gd[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_gd[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_g[0] * denAccum_7) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_g[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_g[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_g[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[2]);

   /* Logic: '<S145>/Logical Operator' incorporates:
    *  Constant: '<S145>/Constant1'
    *  Constant: '<S145>/Constant2'
    *  DiscreteFilter: '<S11>/Discrete Filter'
    *  RelationalOperator: '<S145>/Equal'
    *  RelationalOperator: '<S145>/Equal1'
    */
   rtb_LogicalOperator_m = ((rtb_DataTypeConversion_a >= -50.0F) && (rtb_DataTypeConversion_a <= 50.0F));

   /* If: '<S141>/If' incorporates:
    *  Constant: '<S141>/Constant'
    *  Constant: '<S141>/Constant1'
    *  Constant: '<S141>/Constant2'
    *  Constant: '<S141>/Constant3'
    *  Constant: '<S146>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S147>/In1'
    *  Inport: '<S148>/In1'
    *  Inport: '<S149>/In1'
    *  Inport: '<S150>/In1'
    *  Inport: '<S151>/In1'
    *  RelationalOperator: '<S146>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
       *  ActionPort: '<S147>/Action Port'
       */
      rtb_Merge_o = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->logitudinal_acceleration_qf_gvpm;

      /* End of Outputs for SubSystem: '<S141>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S148>/Action Port'
       */
      rtb_Merge_o = ACCURATED;

      /* End of Outputs for SubSystem: '<S141>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator) && rtb_LogicalOperator_m)
   {
      /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S149>/Action Port'
       */
      rtb_Merge_o = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S141>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator && (!rtb_LogicalOperator_m))
   {
      /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S150>/Action Port'
       */
      rtb_Merge_o = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S141>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S151>/Action Port'
       */
      rtb_Merge_o = UNDEFINED;

      /* End of Outputs for SubSystem: '<S141>/If Action Subsystem4' */
   }

   /* End of If: '<S141>/If' */

   /* ModelReference: '<S1>/RawLongitudinalAccelerationArbitration' incorporates:
    *  Delay: '<S52>/Delay'
    *  Delay: '<S53>/Delay'
    */
   Signal_Arbitration_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm,
                             &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm, &rtb_Merge_iw, &rtb_Merge_o, &rtb_Merge_o,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_d, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_iq,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number_g,
                             &(VSE_Master_Model_WL_L2P_DW->RawLongitudinalAccelerationArbitration_InstanceData.rtdw));

   /* Switch: '<S4>/Switch' incorporates:
    *  Constant: '<S38>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S38>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   rtb_final_fault_f = (((int32_T)VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->vehicle_standstill) != 1);

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Merge_lr = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_speed_qf;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Merge_mg = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_speed_qf;

   /* ModelReference: '<S1>/DtrmnVehStationary' */
   DtrmnVehStationary(&VSE_Master_Model_WL_L2P_DW->selected_signal_ag, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_h,
                      &VSE_Master_Model_WL_L2P_DW->selected_signal_a, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g,
                      &VSE_Master_Model_WL_L2P_DW->selected_signal_d, &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_iq,
                      &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_final_fault_f,
                      &rtb_Merge_lr, &rtb_Merge_mg, &rtb_Merge_lr, &rtb_Merge_mg, &rtb_f_stationary,
                      &(VSE_Master_Model_WL_L2P_DW->DtrmnVehStationary_InstanceData.rtdw));

   /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
    *  Inport: '<Root>/LAST_KEY_CYCLE'
    */
   if ((VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_primary_radps > 0.0610865243F) ||
       (VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_primary_radps < -0.0610865243F))
   {
      rtb_correc_stop_yaw_bias_nvm_read_g = 0.0F;
   }
   else
   {
      rtb_correc_stop_yaw_bias_nvm_read_g = VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_primary_radps;
   }

   /* End of MATLAB Function: '<S4>/MATLAB Function' */

   /* ModelReference: '<S1>/YawRateCompensation_Primary' incorporates:
    *  Delay: '<S46>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    */
   YawRateCompensation(
      &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE, &rtb_Merge_e, &rtb_yawRate, &rtb_qf, &rtb_SpeedCompensation_o1,
      &rtb_SpeedCompensation_o2, &rtb_f_stationary, &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec,
      &rtb_correc_stop_yaw_bias_nvm_read_g, &rtb_Yaw_Rate_Compensated_Unfiltered, &rtb_Yaw_Rate_Compensated_Filtered,
      &rtb_Yaw_Rate_Raw_Bias, &rtb_Yaw_Rate_Bias_QF, &rtb_Yaw_Rate_Compensated_QF, &rtb_Stop_Yaw_Bias_NVM_Write,
      &rtb_f_Yaw_Rate_Bias_Converged, &rtb_f_stop_bias_converged, &rtb_yaw_rate_bias1, &rtb_f_yaw_stop_bias_converged,
      &rtb_yaw_rate_bias_fast_bias1, &rtb_yaw_rate_bias_fast_bias2, &rtb_comp_yaw_rate_diff_filt, &rtb_yaw_rate_bias_diff,
      &rtb_road_type, &rtb_f_yaw_rate_bias_shift, &rtb_f_Yaw_Rate_Bias_Converged_a, &rtb_f_stop_bias_converged_h,
      &rtb_f_yaw_rate_steady, &rtb_f_input_invalid_persistent, &rtb_f_execution_period_error_persistent, &rtb_f_bias_was_accurate,
      &rtb_ignition_time, &rtb_f_yaw_stop_bias_converged_d, &rtb_f_yaw_stop_bias_converged_h,
      &(VSE_Master_Model_WL_L2P_DW->YawRateCompensation_Primary_InstanceData.rtdw));

   /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
    *  Inport: '<Root>/LAST_KEY_CYCLE'
    */
   if ((VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_secondary_radps > 0.0610865243F) ||
       (VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_secondary_radps < -0.0610865243F))
   {
      rtb_correc_stop_yaw_bias_nvm_read_g = 0.0F;
   }
   else
   {
      rtb_correc_stop_yaw_bias_nvm_read_g = VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k->nvm_last_rem_stop_yaw_bias_secondary_radps;
   }

   /* End of MATLAB Function: '<S4>/MATLAB Function1' */

   /* ModelReference: '<S1>/YawRateCompensation_Secondary' incorporates:
    *  Delay: '<S47>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    */
   YawRateCompensation(
      &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b, &rtb_Merge_i, &rtb_yawRate, &rtb_qf, &rtb_SpeedCompensation_o1,
      &rtb_SpeedCompensation_o2, &rtb_f_stationary, &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec,
      &rtb_correc_stop_yaw_bias_nvm_read_g, &rtb_Yaw_Rate_Compensated_Unfiltered_m, &rtb_Yaw_Rate_Compensated_Filtered_p,
      &rtb_Yaw_Rate_Raw_Bias_m, &rtb_Yaw_Rate_Bias_QF_l, &rtb_Yaw_Rate_Compensated_QF_e, &rtb_Stop_Yaw_Bias_NVM_Write_l,
      &rtb_f_Yaw_Rate_Bias_Converged_j, &rtb_f_stop_bias_converged_n, &rtb_yaw_rate_bias1_g, &rtb_f_yaw_stop_bias_converged_a,
      &rtb_yaw_rate_bias_fast_bias1_h, &rtb_yaw_rate_bias_fast_bias2_p, &rtb_comp_yaw_rate_diff_filt_n, &rtb_yaw_rate_bias_diff_l,
      &rtb_road_type_b, &rtb_f_yaw_rate_bias_shift_j, &rtb_f_Yaw_Rate_Bias_Converged_ak, &rtb_f_stop_bias_converged_k,
      &rtb_f_yaw_rate_steady_k, &rtb_f_input_invalid_persistent_g, &rtb_f_execution_period_error_persistent_g,
      &rtb_f_bias_was_accurate_p, &rtb_ignition_time_f, &rtb_f_yaw_stop_bias_converged_g, &rtb_f_yaw_stop_bias_converged_i,
      &(VSE_Master_Model_WL_L2P_DW->YawRateCompensation_Secondary_InstanceData.rtdw));

   /* ModelReference: '<S1>/CompensatedYawRateArbitration' */
   Signal_Arbitration_Common(&rtb_Yaw_Rate_Compensated_Unfiltered, &rtb_Yaw_Rate_Compensated_Unfiltered_m,
                             &rtb_Yaw_Rate_Compensated_Unfiltered_m, &rtb_Yaw_Rate_Compensated_QF, &rtb_Yaw_Rate_Compensated_QF_e,
                             &rtb_Yaw_Rate_Compensated_QF_e, &VSE_Master_Model_WL_L2P_DW->selected_signal_bf,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_qf_k,
                             &VSE_Master_Model_WL_L2P_DW->selected_signal_number_k,
                             &(VSE_Master_Model_WL_L2P_DW->CompensatedYawRateArbitration_InstanceData.rtdw));

   /* If: '<S14>/If1' incorporates:
    *  DataTypeConversion: '<S14>/Cast To Single'
    *  DataTypeConversion: '<S14>/Cast To Single1'
    */
   if (((((int32_T)rtb_gear_box_pos) == 1) && (((int32_T)VSE_Master_Model_WL_L2P_DW->selected_signal_number_k) == 2)) ||
       ((((int32_T)rtb_gear_box_pos) == 0) && (((int32_T)VSE_Master_Model_WL_L2P_DW->selected_signal_number_p) == 2)))
   {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S179>/Action Port'
       */
      /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
       *  BusCreator: '<S1>/Bus Creator'
       *  Delay: '<S47>/Delay'
       *  Outport: '<Root>/VSE_Output'
       */
      VSE_Master_Model_WL_L2P_IfActionSubsystem1(
         rtb_Yaw_Rate_Compensated_Unfiltered_m, rtb_yaw_rate_bias_fast_bias1_h, rtb_yaw_rate_bias_fast_bias2_p,
         rtb_comp_yaw_rate_diff_filt_n, rtb_yaw_rate_bias_diff_l, rtb_road_type_b, rtb_f_yaw_rate_bias_shift_j,
         rtb_f_Yaw_Rate_Bias_Converged_ak, rtb_f_stop_bias_converged_k, rtb_f_yaw_rate_steady_k, rtb_f_input_invalid_persistent_g,
         rtb_Yaw_Rate_Compensated_Filtered_p, rtb_f_execution_period_error_persistent_g, rtb_f_bias_was_accurate_p,
         rtb_ignition_time_f, rtb_f_yaw_stop_bias_converged_g, VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b, rtb_Merge_i,
         rtb_f_yaw_stop_bias_converged_i, rtb_Yaw_Rate_Raw_Bias_m, rtb_Yaw_Rate_Bias_QF_l, rtb_Yaw_Rate_Compensated_QF_e,
         rtb_f_Yaw_Rate_Bias_Converged_j, rtb_f_stop_bias_converged_n, rtb_yaw_rate_bias1_g, rtb_f_yaw_stop_bias_converged_a,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_yaw_rate_unfiltered,
         &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered, &VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_bias,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_bias_qf, &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF,
         &f_Yaw_Rate_Bias_Converged_c, &VSE_Master_Model_WL_L2P_DW->UnitDelay2_DSTATE, &yaw_rate_bias1, &yaw_rate_bias2,
         &yaw_rate_bias_fast_bias1, &yaw_rate_bias_fast_bias2, &comp_yaw_rate_diff_filt, &yaw_rate_bias_diff, &road_type,
         &rtb_LogicalOperator, &rtb_LogicalOperator_m, &f_stop_bias_converged, &f_yaw_rate_steady, &f_input_invalid_persistent,
         &f_execution_period_error_persistent, &f_bias_was_accurate, &ignition_time, &f_yaw_stop_bias_converged,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_yaw_rate_rps, &VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_yaw_rate_qf,
         &VSE_Master_Model_WL_L2P_DW->f_yaw_rate_stop_bias_converged_atleast_once);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
       *  ActionPort: '<S178>/Action Port'
       */
      /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
       *  BusCreator: '<S1>/Bus Creator'
       *  Delay: '<S46>/Delay'
       *  Outport: '<Root>/VSE_Output'
       */
      VSE_Master_Model_WL_L2P_IfActionSubsystem1(
         rtb_Yaw_Rate_Compensated_Unfiltered, rtb_yaw_rate_bias_fast_bias1, rtb_yaw_rate_bias_fast_bias2,
         rtb_comp_yaw_rate_diff_filt, rtb_yaw_rate_bias_diff, rtb_road_type, rtb_f_yaw_rate_bias_shift,
         rtb_f_Yaw_Rate_Bias_Converged_a, rtb_f_stop_bias_converged_h, rtb_f_yaw_rate_steady, rtb_f_input_invalid_persistent,
         rtb_Yaw_Rate_Compensated_Filtered, rtb_f_execution_period_error_persistent, rtb_f_bias_was_accurate, rtb_ignition_time,
         rtb_f_yaw_stop_bias_converged_d, VSE_Master_Model_WL_L2P_DW->Delay_DSTATE, rtb_Merge_e, rtb_f_yaw_stop_bias_converged_h,
         rtb_Yaw_Rate_Raw_Bias, rtb_Yaw_Rate_Bias_QF, rtb_Yaw_Rate_Compensated_QF, rtb_f_Yaw_Rate_Bias_Converged,
         rtb_f_stop_bias_converged, rtb_yaw_rate_bias1, rtb_f_yaw_stop_bias_converged,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_yaw_rate_unfiltered,
         &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered, &VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_bias,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_bias_qf, &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF,
         &f_Yaw_Rate_Bias_Converged_c, &VSE_Master_Model_WL_L2P_DW->UnitDelay2_DSTATE, &yaw_rate_bias1, &yaw_rate_bias2,
         &yaw_rate_bias_fast_bias1, &yaw_rate_bias_fast_bias2, &comp_yaw_rate_diff_filt, &yaw_rate_bias_diff, &road_type,
         &rtb_LogicalOperator, &rtb_LogicalOperator_m, &f_stop_bias_converged, &f_yaw_rate_steady, &f_input_invalid_persistent,
         &f_execution_period_error_persistent, &f_bias_was_accurate, &ignition_time, &f_yaw_stop_bias_converged,
         &VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_yaw_rate_rps, &VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_yaw_rate_qf,
         &VSE_Master_Model_WL_L2P_DW->f_yaw_rate_stop_bias_converged_atleast_once);

      /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
   }

   /* End of If: '<S14>/If1' */

   /* DataTypeConversion: '<S1>/Cast' */
   rtb_Cast = rtb_DetermineReverseStatus ? 1U : 0U;

   /* Gain: '<S3>/Gain1' */
   rtb_Gain1 = 0.0174532924F * rtb_YawRateEstimationUsingSteeringWheelAngle_o3;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_final_fault_f = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->abs_active;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_final_fault_h = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->asr_active;

   /* ModelReference: '<S36>/Model6' incorporates:
    *  Constant: '<S1>/Constant12'
    *  Constant: '<S1>/Constant13'
    *  Constant: '<S1>/Constant44'
    *  Delay: '<S52>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    *  Inport: '<Root>/Vehicle_Parameters'
    */
   ABS_TCS_Algorithm(
      &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_fl_wheel_spin, &rtb_fr_wheel_spin,
      &rtb_rl_wheel_spin, &rtb_rr_wheel_spin, &VSE_Master_Model_WL_L2P_ConstP.pooled37, &VSE_Master_Model_WL_L2P_ConstP.pooled37,
      &VSE_Master_Model_WL_L2P_ConstP.pooled37, &VSE_Master_Model_WL_L2P_ConstP.pooled37, &rtb_Gain1,
      &VSE_Master_Model_WL_L2P_ConstP.pooled11, &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_front_track_width,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_front_track_width, &rtb_final_fault_f, &rtb_final_fault_h,
      &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o, &rtb_ego_longitudinal_accel_qf, &rtb_Cast,
      &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered, &VSE_Master_Model_WL_L2P_ConstP.pooled29,
      &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec, &rtb_VsVSE_mps_WhlOdoVehSpeedOverGround,
      &rtb_VsVSE_mps2_WhlOdoVehLongAccel, &rtb_VsVSE_u8_ABSStatusUnderBraking, &VSE_Master_Model_WL_L2P_DW->VsVSE_b_ASRStatus,
      &VSE_Master_Model_WL_L2P_DW->VeVSE_mps_WhlOdoVehSpeedOverGroundQF, &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehAccelQF,
      &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehLongSpdAccLvl, &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehLongAccelAccLvl,
      &(VSE_Master_Model_WL_L2P_DW->Model6_InstanceData.rtdw));

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_brake_padel_press = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->brake_padel_press;

   /* UnitDelay: '<S36>/Unit Delay' */
   rtb_VsVSE_mps_LastEstimWhlSpd = VSE_Master_Model_WL_L2P_DW->UnitDelay_DSTATE;

   /* UnitDelay: '<S36>/Unit Delay1' */
   rtb_VsVCAN_nu_CountsPerRevol = VSE_Master_Model_WL_L2P_DW->UnitDelay1_DSTATE_k;

   /* ModelReference: '<S36>/Model3' incorporates:
    *  Constant: '<S1>/VsVCAN_nu_CountsPerRevol'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    *  Inport: '<Root>/Vehicle_Parameters'
    */
   Wheel_Counts_To_Linear_Speed(
      &rtb_fl_wheel_pulse_counter, &rtb_fr_wheel_pulse_counter, &rtb_rl_wheel_pulse_counter, &rtb_rr_wheel_pulse_counter,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_front_wheel_radius_static_loaded,
      &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec, &VSE_Master_Model_WL_L2P_ConstP.VsVCAN_nu_CountsPerRevol_Value,
      &rtb_VsVSE_mps_LastEstimWhlSpd, &rtb_VsVCAN_nu_CountsPerRevol, &rtb_combined_whl_tck_bsd_lin_spd,
      &rtb_combined_whl_tck_bsd_lin_spd_g, &rtb_combined_whl_tck_bsd_lin_spd_j, &rtb_combined_whl_tck_bsd_lin_spd_jz,
      &rtb_zero_whl_cnt, &(VSE_Master_Model_WL_L2P_DW->Model3_InstanceData.rtdw));

   /* ModelReference: '<S36>/Model5' incorporates:
    *  Delay: '<S52>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    *  UnitDelay: '<S36>/Unit Delay'
    *  UnitDelay: '<S36>/Unit Delay1'
    */
   Speed_Arbitration_and_IMU_Fusion(
      &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o, &rtb_VsVSE_mps_WhlOdoVehSpeedOverGround,
      &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehAccelQF, &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehAccelQF, &rtb_fl_wheel_spin,
      &rtb_fr_wheel_spin, &rtb_rl_wheel_spin, &rtb_rr_wheel_spin, &rtb_fl_wheel_speed, &rtb_fr_wheel_speed, &rtb_fl_wheel_speed,
      &rtb_fr_wheel_speed, &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec, &rtb_brake_padel_press,
      &rtb_combined_whl_tck_bsd_lin_spd, &rtb_combined_whl_tck_bsd_lin_spd_g, &rtb_combined_whl_tck_bsd_lin_spd_j,
      &rtb_combined_whl_tck_bsd_lin_spd_jz, &rtb_zero_whl_cnt, &rtb_VsVSE_u8_ABSStatusUnderBraking, &rtb_Cast,
      &VSE_Master_Model_WL_L2P_DW->UnitDelay_DSTATE, &rtb_VsVSE_mps2_WhlOdoVehLongAccel_p,
      &VSE_Master_Model_WL_L2P_DW->VeVSE_mps_WhlOdoVehSpeedOverGroundQF_h, &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehAccelQF_m,
      &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehLongSpdAccLvl_c, &VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehLongAccelAccLvl_n,
      &VSE_Master_Model_WL_L2P_DW->UnitDelay1_DSTATE_k, &(VSE_Master_Model_WL_L2P_DW->Model5_InstanceData_k.rtdw));

   /* Chart: '<S33>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_i,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_l);

   /* ModelReference: '<S1>/VehicleCurvatureAndSideslipEstimation' incorporates:
    *  Constant: '<S1>/Constant4'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    *  Inport: '<Root>/Vehicle_Parameters'
    */
   VehicleCurvatureAndSideslipEstimation_Simulink(
      &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec, &rtb_SpeedCompensation_o1,
      &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_dist_rear_axle_to_vcs,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_vehicle_width, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_rear_cornering_compliance, &rtb_DetermineReverseStatus,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_left_sensor_long_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_left_sensor_lat_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_right_sensor_long_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_right_sensor_lat_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->rear_left_sensor_long_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->rear_left_sensor_lat_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->rear_right_sensor_long_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->rear_right_sensor_lat_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_bumper_sensor_long_distance_from_rear_axle,
      &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->front_bumper_sensor_lat_distance_from_rear_axle, &rtb_curvature_rear_axle,
      &rtb_VCS_long_velocity, &rtb_sensor_long_velocity, &rtb_VCS_sideslip, &rtb_sensor_sideslip, &rtb_sideslip_rear_axle,
      &rtb_VCS_lat_velocity, &rtb_sensor_lat_velocity, &rtb_CurvKalmanFilterC0, &rtb_CurvKalmanFilterC1,
      &rtb_front_left_sensor_long, &rtb_front_left_sensor_lat, &rtb_front_right_sensor_long, &rtb_front_right_sensor_lat,
      &rtb_rear_left_sensor_long, &rtb_rear_left_sensor_lat, &rtb_rear_right_sensor_long, &rtb_rear_right_sensor_lat,
      &rtb_front_bumper_sensor_long, &rtb_front_bumper_sensor_lat,
      &(VSE_Master_Model_WL_L2P_DW->VehicleCurvatureAndSideslipEstimation_InstanceData.rtdw));

   /* ModelReference: '<S1>/Model4' */
   Acceleration_VCS(&rtb_VCS_lat_velocity, &rtb_VCS_long_velocity, &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered,
                    &rtb_SpeedCompensation_o2, &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF, &rtb_Model4_o1,
                    &rtb_Model4_o2, &rtb_Model4_o3, &rtb_Model4_o4, &(VSE_Master_Model_WL_L2P_DW->Model4_InstanceData.rtdw));

   /* Chart: '<S5>/Chart' */
   VSE_Master_Model_WL_L2P_Chart(&VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_h,
                                 &VSE_Master_Model_WL_L2P_DW->sf_Chart);

   /* Outputs for Enabled SubSystem: '<S5>/Differentiator Generator' */
   VSE_Master_Model_WL_L2P_DifferentiatorGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_h,
                                                   VSE_Master_Model_WL_L2P_DW->diff_num_p,
                                                   VSE_Master_Model_WL_L2P_DW->diff_denom_m);

   /* End of Outputs for SubSystem: '<S5>/Differentiator Generator' */

   /* Chart: '<S6>/Chart' */
   VSE_Master_Model_WL_L2P_Chart(&VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_l,
                                 &VSE_Master_Model_WL_L2P_DW->sf_Chart_f);

   /* Outputs for Enabled SubSystem: '<S6>/Differentiator Generator' */
   VSE_Master_Model_WL_L2P_DifferentiatorGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_l,
                                                   VSE_Master_Model_WL_L2P_DW->diff_num_k,
                                                   VSE_Master_Model_WL_L2P_DW->diff_denom_d);

   /* End of Outputs for SubSystem: '<S6>/Differentiator Generator' */

   /* Chart: '<S7>/Chart' */
   VSE_Master_Model_WL_L2P_Chart(&VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation,
                                 &VSE_Master_Model_WL_L2P_DW->sf_Chart_fq);

   /* Outputs for Enabled SubSystem: '<S7>/Differentiator Generator' */
   VSE_Master_Model_WL_L2P_DifferentiatorGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation,
                                                   VSE_Master_Model_WL_L2P_DW->diff_num, VSE_Master_Model_WL_L2P_DW->diff_denom);

   /* End of Outputs for SubSystem: '<S7>/Differentiator Generator' */

   /* Outputs for Enabled SubSystem: '<S7>/Filter Generator' */
   VSE_Master_Model_WL_L2P_FilterGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation, rtb_filter_discrete_num,
                                           rtb_filter_discrete_denom);

   /* End of Outputs for SubSystem: '<S7>/Filter Generator' */

   /* Outputs for Enabled SubSystem: '<S6>/Filter Generator' */
   VSE_Master_Model_WL_L2P_FilterGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_l,
                                           VSE_Master_Model_WL_L2P_DW->filter_discrete_num,
                                           VSE_Master_Model_WL_L2P_DW->filter_discrete_denom);

   /* End of Outputs for SubSystem: '<S6>/Filter Generator' */

   /* Outputs for Enabled SubSystem: '<S5>/Filter Generator' */
   VSE_Master_Model_WL_L2P_FilterGenerator(VSE_Master_Model_WL_L2P_DW->f_initialize_JerkEstimation_h,
                                           VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j,
                                           VSE_Master_Model_WL_L2P_DW->filter_discrete_denom_g);

   /* End of Outputs for SubSystem: '<S5>/Filter Generator' */

   /* Outputs for Enabled SubSystem: '<S33>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_i, VSE_Master_Model_WL_L2P_DW->diff_num_n,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_o);

   /* End of Outputs for SubSystem: '<S33>/Initialization' */

   /* ModelReference: '<S1>/Model3' incorporates:
    *  Constant: '<S1>/Constant40'
    *  Constant: '<S1>/Constant41'
    *  Constant: '<S1>/Constant42'
    *  Constant: '<S1>/Constant43'
    *  Delay: '<S52>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    */
   GradeEstimation(&rtb_SpeedCompensation_o1, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o,
                   &VSE_Master_Model_WL_L2P_ConstP.Constant40_Value, &VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec,
                   &VSE_Master_Model_WL_L2P_ConstP.pooled35, &rtb_VCS_sideslip, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
                   &rtb_Merge_iw, &VSE_Master_Model_WL_L2P_ConstP.pooled29, &rtb_VsVSE_pct_EstimatedGrade,
                   &VSE_Master_Model_WL_L2P_DW->VsVSE_EstimatedGradeQF, &VSE_Master_Model_WL_L2P_DW->VsVSE_EstimatedGradeAccuracy,
                   &(VSE_Master_Model_WL_L2P_DW->Model3_InstanceData_c.rtdw));

   /* Chart: '<S13>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_k1,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_n);

   /* Outputs for Enabled SubSystem: '<S13>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_k1, VSE_Master_Model_WL_L2P_DW->diff_num_b,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_e0);

   /* End of Outputs for SubSystem: '<S13>/Initialization' */

   /* Chart: '<S12>/Initialization_Trigger' */
   VSE_Master_Model_WL_L2P_Initialization_Trigger(&VSE_Master_Model_WL_L2P_DW->f_initialize_m,
                                                  &VSE_Master_Model_WL_L2P_DW->sf_Initialization_Trigger_h);

   /* Outputs for Enabled SubSystem: '<S12>/Initialization' */
   VSE_Master_Model_WL_L2P_Initialization(VSE_Master_Model_WL_L2P_DW->f_initialize_m, VSE_Master_Model_WL_L2P_DW->diff_num_el,
                                          VSE_Master_Model_WL_L2P_DW->diff_denom_l);

   /* End of Outputs for SubSystem: '<S12>/Initialization' */

   /* RelationalOperator: '<S68>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S158>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp_0 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->pitch_rate_qf;

   /* Switch: '<S44>/Switch' incorporates:
    *  Constant: '<S68>/Constant'
    *  Delay: '<S44>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S68>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->pitch_rate;
   }

   /* End of Switch: '<S44>/Switch' */

   /* DiscreteFilter: '<S12>/Discrete Filter' incorporates:
    *  Delay: '<S44>/Delay'
    */
   rtb_correc_stop_yaw_bias_nvm_read_g =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji -
        (VSE_Master_Model_WL_L2P_DW->diff_denom_l[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[0])) -
       (VSE_Master_Model_WL_L2P_DW->diff_denom_l[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[1])) -
      (VSE_Master_Model_WL_L2P_DW->diff_denom_l[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_el[0] * rtb_correc_stop_yaw_bias_nvm_read_g) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_el[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_el[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_el[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[2]);

   /* Logic: '<S157>/Logical Operator' incorporates:
    *  Constant: '<S157>/Constant1'
    *  Constant: '<S157>/Constant2'
    *  DiscreteFilter: '<S12>/Discrete Filter'
    *  RelationalOperator: '<S157>/Equal'
    *  RelationalOperator: '<S157>/Equal1'
    */
   f_Yaw_Rate_Bias_Converged_c = ((rtb_DataTypeConversion_a >= -1.74532926F) && (rtb_DataTypeConversion_a <= 1.74532926F));

   /* Logic: '<S156>/Logical Operator' incorporates:
    *  Constant: '<S156>/Constant'
    *  Constant: '<S156>/Constant1'
    *  Delay: '<S44>/Delay'
    *  RelationalOperator: '<S156>/Equal'
    *  RelationalOperator: '<S156>/Equal1'
    */
   rtb_LogicalOperator_hj = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji >= -1.74532926F) &&
                             (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji <= 1.74532926F));

   /* If: '<S153>/If' incorporates:
    *  Constant: '<S153>/Constant'
    *  Constant: '<S153>/Constant1'
    *  Constant: '<S153>/Constant2'
    *  Constant: '<S153>/Constant3'
    *  Constant: '<S158>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S159>/In1'
    *  Inport: '<S160>/In1'
    *  Inport: '<S161>/In1'
    *  Inport: '<S162>/In1'
    *  Inport: '<S163>/In1'
    *  RelationalOperator: '<S158>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem' incorporates:
       *  ActionPort: '<S159>/Action Port'
       */
      rtb_Merge_lr = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->pitch_rate_qf;

      /* End of Outputs for SubSystem: '<S153>/If Action Subsystem' */
   }
   else if (rtb_LogicalOperator_hj && f_Yaw_Rate_Bias_Converged_c)
   {
      /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S160>/Action Port'
       */
      rtb_Merge_lr = ACCURATED;

      /* End of Outputs for SubSystem: '<S153>/If Action Subsystem1' */
   }
   else if ((!rtb_LogicalOperator_hj) && f_Yaw_Rate_Bias_Converged_c)
   {
      /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S161>/Action Port'
       */
      rtb_Merge_lr = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S153>/If Action Subsystem2' */
   }
   else if (rtb_LogicalOperator_hj && (!f_Yaw_Rate_Bias_Converged_c))
   {
      /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      rtb_Merge_lr = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S153>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S153>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S163>/Action Port'
       */
      rtb_Merge_lr = UNDEFINED;

      /* End of Outputs for SubSystem: '<S153>/If Action Subsystem4' */
   }

   /* End of If: '<S153>/If' */

   /* RelationalOperator: '<S67>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S170>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp_0 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->roll_rate_qf;

   /* Switch: '<S43>/Switch' incorporates:
    *  Constant: '<S67>/Constant'
    *  Delay: '<S43>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S67>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->roll_rate;
   }

   /* End of Switch: '<S43>/Switch' */

   /* Logic: '<S168>/Logical Operator' incorporates:
    *  Constant: '<S168>/Constant'
    *  Constant: '<S168>/Constant1'
    *  Delay: '<S43>/Delay'
    *  RelationalOperator: '<S168>/Equal'
    *  RelationalOperator: '<S168>/Equal1'
    */
   f_Yaw_Rate_Bias_Converged_c = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv >= -1.74532926F) &&
                                  (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv <= 1.74532926F));

   /* DiscreteFilter: '<S13>/Discrete Filter' incorporates:
    *  Delay: '<S43>/Delay'
    */
   denAccum_8 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_e0[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_e0[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_e0[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_b[0] * denAccum_8) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_b[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_b[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_b[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[2]);

   /* Logic: '<S169>/Logical Operator' incorporates:
    *  Constant: '<S169>/Constant1'
    *  Constant: '<S169>/Constant2'
    *  DiscreteFilter: '<S13>/Discrete Filter'
    *  RelationalOperator: '<S169>/Equal'
    *  RelationalOperator: '<S169>/Equal1'
    */
   rtb_LogicalOperator_hj = ((rtb_DataTypeConversion_a >= -1.74532926F) && (rtb_DataTypeConversion_a <= 1.74532926F));

   /* If: '<S165>/If' incorporates:
    *  Constant: '<S165>/Constant'
    *  Constant: '<S165>/Constant1'
    *  Constant: '<S165>/Constant2'
    *  Constant: '<S165>/Constant3'
    *  Constant: '<S170>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S171>/In1'
    *  Inport: '<S172>/In1'
    *  Inport: '<S173>/In1'
    *  Inport: '<S174>/In1'
    *  Inport: '<S175>/In1'
    *  RelationalOperator: '<S170>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp_0) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
      rtb_Merge_mg = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->roll_rate_qf;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem' */
   }
   else if (f_Yaw_Rate_Bias_Converged_c && rtb_LogicalOperator_hj)
   {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S172>/Action Port'
       */
      rtb_Merge_mg = ACCURATED;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem1' */
   }
   else if ((!f_Yaw_Rate_Bias_Converged_c) && rtb_LogicalOperator_hj)
   {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S173>/Action Port'
       */
      rtb_Merge_mg = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem2' */
   }
   else if (f_Yaw_Rate_Bias_Converged_c && (!rtb_LogicalOperator_hj))
   {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S174>/Action Port'
       */
      rtb_Merge_mg = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      rtb_Merge_mg = UNDEFINED;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem4' */
   }

   /* End of If: '<S165>/If' */

   /* ModelReference: '<S1>/RollRateCompensation' incorporates:
    *  Delay: '<S43>/Delay'
    */
   RollRateCompensation(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv, &rtb_Merge_mg, &rtb_f_stationary,
                        &VSE_Master_Model_WL_L2P_DW->imu_signal_bias, &rtb_RollRateCompensation_o2, &rtb_RollRateCompensation_o3,
                        &rtb_RollRateCompensation_o4, &VSE_Master_Model_WL_L2P_DW->f_stop_imu_signal_bias_converged,
                        &(VSE_Master_Model_WL_L2P_DW->RollRateCompensation_InstanceData.rtdw));

   /* ModelReference: '<S1>/PitchRateCompensation' incorporates:
    *  Delay: '<S44>/Delay'
    */
   PitchRateCompensation(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji, &rtb_Merge_lr, &rtb_f_stationary,
                         &VSE_Master_Model_WL_L2P_DW->imu_signal_bias_m, &rtb_PitchRateCompensation_o2,
                         &rtb_PitchRateCompensation_o3, &rtb_PitchRateCompensation_o4,
                         &VSE_Master_Model_WL_L2P_DW->f_stop_imu_signal_bias_converged_j,
                         &(VSE_Master_Model_WL_L2P_DW->PitchRateCompensation_InstanceData.rtdw));

   /* RelationalOperator: '<S37>/Compare' incorporates:
    *  Constant: '<S37>/Constant'
    */
   f_Yaw_Rate_Bias_Converged_c = (VSE_Master_Model_WL_L2P_DW->selected_signal > 2.78F);

   /* ModelReference: '<S1>/SpeedRationalityCheck' incorporates:
    *  Constant: '<S1>/Constant'
    *  Constant: '<S1>/Constant1'
    *  Constant: '<S1>/Constant11'
    *  Constant: '<S1>/Constant15'
    *  Delay: '<S48>/Delay'
    *  Delay: '<S49>/Delay'
    */
   Signal_Rationality_Check_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_d, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k,
                                   &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_k, &rtb_Merge, &rtb_Merge_b, &rtb_Merge_b,
                                   &VSE_Master_Model_WL_L2P_ConstP.Constant_Value, &VSE_Master_Model_WL_L2P_ConstP.Constant1_Value,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled11, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
                                   &f_Yaw_Rate_Bias_Converged_c, &rtb_SpeedRationalityCheck,
                                   &(VSE_Master_Model_WL_L2P_DW->SpeedRationalityCheck_InstanceData.rtdw));

   /* ModelReference: '<S1>/Model2' incorporates:
    *  Constant: '<S1>/Constant20'
    *  Constant: '<S1>/Constant33'
    *  Constant: '<S1>/Constant34'
    *  Constant: '<S1>/Constant35'
    *  Constant: '<S1>/Constant36'
    *  Delay: '<S46>/Delay'
    *  Delay: '<S47>/Delay'
    */
   Yaw_Rate_Rationality_Check(&rtb_f_stop_bias_converged, &rtb_f_stop_bias_converged_n, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE,
                              &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_b,
                              &rtb_Merge_e, &rtb_Merge_i, &rtb_Merge_i, &VSE_Master_Model_WL_L2P_ConstP.Constant36_Value,
                              &VSE_Master_Model_WL_L2P_ConstP.Constant34_Value, &VSE_Master_Model_WL_L2P_ConstP.pooled11,
                              &VSE_Master_Model_WL_L2P_ConstP.pooled35, &f_Yaw_Rate_Bias_Converged_c,
                              &rtb_Yaw_Rate_Compensated_Filtered, &rtb_Yaw_Rate_Compensated_Filtered_p,
                              &rtb_Yaw_Rate_Compensated_Filtered_p, &rtb_Yaw_Rate_Compensated_QF, &rtb_Yaw_Rate_Compensated_QF_e,
                              &rtb_Yaw_Rate_Compensated_QF_e, &VSE_Master_Model_WL_L2P_ConstP.Constant20_Value,
                              &VSE_Master_Model_WL_L2P_DW->Model2, &(VSE_Master_Model_WL_L2P_DW->Model2_InstanceData.rtdw));

   /* ModelReference: '<S1>/SteeringAngleRationalityCheck' incorporates:
    *  Constant: '<S1>/Constant29'
    *  Constant: '<S1>/Constant30'
    *  Constant: '<S1>/Constant31'
    *  Constant: '<S1>/Constant32'
    *  Delay: '<S40>/Delay'
    *  Delay: '<S41>/Delay'
    */
   Signal_Rationality_Check_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_f, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_l,
                                   &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_l, &rtb_Merge_d, &rtb_Merge_p, &rtb_Merge_p,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled18, &VSE_Master_Model_WL_L2P_ConstP.pooled30,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled11, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
                                   &f_Yaw_Rate_Bias_Converged_c, &rtb_SteeringAngleRationalityCheck,
                                   &(VSE_Master_Model_WL_L2P_DW->SteeringAngleRationalityCheck_InstanceData.rtdw));

   /* ModelReference: '<S1>/LatAccelRationalityCheck' incorporates:
    *  Constant: '<S1>/Constant14'
    *  Constant: '<S1>/Constant21'
    *  Constant: '<S1>/Constant25'
    *  Constant: '<S1>/Constant26'
    *  Delay: '<S50>/Delay'
    *  Delay: '<S51>/Delay'
    */
   Signal_Rationality_Check_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_i, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j,
                                   &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_j, &rtb_Merge_l, &rtb_Merge_a5, &rtb_Merge_a5,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled31, &VSE_Master_Model_WL_L2P_ConstP.pooled30,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled11, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
                                   &f_Yaw_Rate_Bias_Converged_c, &rtb_LatAccelRationalityCheck,
                                   &(VSE_Master_Model_WL_L2P_DW->LatAccelRationalityCheck_InstanceData.rtdw));

   /* ModelReference: '<S1>/LongAccelRationalityCheck' incorporates:
    *  Constant: '<S1>/Constant22'
    *  Constant: '<S1>/Constant23'
    *  Constant: '<S1>/Constant27'
    *  Constant: '<S1>/Constant28'
    *  Delay: '<S52>/Delay'
    *  Delay: '<S53>/Delay'
    */
   Signal_Rationality_Check_Common(&VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm,
                                   &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_lm, &rtb_Merge_iw, &rtb_Merge_o, &rtb_Merge_o,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled31, &VSE_Master_Model_WL_L2P_ConstP.pooled30,
                                   &VSE_Master_Model_WL_L2P_ConstP.pooled11, &VSE_Master_Model_WL_L2P_ConstP.pooled35,
                                   &f_Yaw_Rate_Bias_Converged_c, &rtb_LongAccelRationalityCheck,
                                   &(VSE_Master_Model_WL_L2P_DW->LongAccelRationalityCheck_InstanceData.rtdw));

   /* ModelReference: '<S1>/HeadingAngleAndLatLongDisplacement' incorporates:
    *  Inport: '<Root>/System_Time_Micro_Sec'
    */
   HeadingAngleandLatLongDisplacement(&rtb_VCS_lat_velocity, &rtb_VCS_long_velocity,
                                      &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered,
                                      &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF, &rtb_VCS_sideslip,
                                      &VSE_Master_Model_WL_L2P_DW->f_yaw_rate_stop_bias_converged_atleast_once,
                                      &rtb_HeadingAngleAndLatLongDisplacement_o1, &rtb_HeadingAngleAndLatLongDisplacement_o2,
                                      &rtb_HeadingAngleAndLatLongDisplacement_o3, &rtb_HeadingAngleAndLatLongDisplacement_o4,
                                      &(VSE_Master_Model_WL_L2P_DW->HeadingAngleAndLatLongDisplacement_InstanceData.rtdw));

   /* Switch: '<S26>/Switch' incorporates:
    *  Constant: '<S26>/Constant'
    *  Constant: '<S26>/Constant1'
    */
   if (rtb_DetermineReverseStatus)
   {
      denAccum_9 = -1.0F;
   }
   else
   {
      denAccum_9 = 1.0F;
   }

   /* End of Switch: '<S26>/Switch' */

   /* Product: '<S26>/Product' */
   rtb_Product = rtb_SpeedCompensation_o1 * denAccum_9;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   f_Yaw_Rate_Bias_Converged_c = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->VehicleSpeedVSOSig_SNA;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_LogicalOperator_hj = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->LongAcceleration_BSM_SNA;

   /* DataTypeConversion: '<S1>/Cast5' */
   rtb_gear_box_pos = (uint8_T)rtb_SpeedCompensation_o2;

   /* DataTypeConversion: '<S1>/Cast6' incorporates:
    *  RelationalOperator: '<S76>/Compare'
    */
   rtb_Cast6 = (uint8_T)rtb_ego_longitudinal_accel_qf;

   /* ModelReference: '<S1>/SelectHostLongAccel' incorporates:
    *  Delay: '<S52>/Delay'
    */
   SelectHostLongAccel(&f_Yaw_Rate_Bias_Converged_c, &VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_o, &rtb_LogicalOperator_hj,
                       &rtb_Product, &rtb_gear_box_pos, &rtb_Cast6, &rtb_Host_Long_Accel_mpss, &rtb_Road_Grade_Accel,
                       &rtb_IMULongAccelFilt_mpss, &rtb_HostLongAccelFilt_mpss, &rtb_Road_Grade_Accel_QF,
                       &(VSE_Master_Model_WL_L2P_DW->SelectHostLongAccel_InstanceData.rtdw));

   /* RelationalOperator: '<S66>/Compare' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S279>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   tmp = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->vertical_acceleration_qf;

   /* Switch: '<S42>/Switch' incorporates:
    *  Constant: '<S66>/Constant'
    *  Delay: '<S42>/Delay'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  RelationalOperator: '<S66>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp) != UNDEFINED)
   {
      VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->vertical_acceleration;
   }

   /* End of Switch: '<S42>/Switch' */

   /* Logic: '<S277>/Logical Operator' incorporates:
    *  Constant: '<S277>/Constant'
    *  Constant: '<S277>/Constant1'
    *  Delay: '<S42>/Delay'
    *  RelationalOperator: '<S277>/Equal'
    *  RelationalOperator: '<S277>/Equal1'
    */
   f_Yaw_Rate_Bias_Converged_c =
      ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do >= -15.0F) && (VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do <= 15.0F));

   /* DiscreteFilter: '<S33>/Discrete Filter' incorporates:
    *  Delay: '<S42>/Delay'
    */
   denAccum_9 = ((VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do -
                  (VSE_Master_Model_WL_L2P_DW->diff_denom_o[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[0])) -
                 (VSE_Master_Model_WL_L2P_DW->diff_denom_o[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[1])) -
                (VSE_Master_Model_WL_L2P_DW->diff_denom_o[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[2]);
   rtb_DataTypeConversion_a =
      (((VSE_Master_Model_WL_L2P_DW->diff_num_n[0] * denAccum_9) +
        (VSE_Master_Model_WL_L2P_DW->diff_num_n[1] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[0])) +
       (VSE_Master_Model_WL_L2P_DW->diff_num_n[2] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[1])) +
      (VSE_Master_Model_WL_L2P_DW->diff_num_n[3] * VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[2]);

   /* Logic: '<S278>/Logical Operator' incorporates:
    *  Constant: '<S278>/Constant1'
    *  Constant: '<S278>/Constant2'
    *  DiscreteFilter: '<S33>/Discrete Filter'
    *  RelationalOperator: '<S278>/Equal'
    *  RelationalOperator: '<S278>/Equal1'
    */
   rtb_LogicalOperator_hj = ((rtb_DataTypeConversion_a >= -50.0F) && (rtb_DataTypeConversion_a <= 50.0F));

   /* If: '<S274>/If' incorporates:
    *  Constant: '<S274>/Constant'
    *  Constant: '<S274>/Constant1'
    *  Constant: '<S274>/Constant2'
    *  Constant: '<S274>/Constant3'
    *  Constant: '<S279>/Constant'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Inport: '<S280>/In1'
    *  Inport: '<S281>/In1'
    *  Inport: '<S282>/In1'
    *  Inport: '<S283>/In1'
    *  Inport: '<S284>/In1'
    *  RelationalOperator: '<S279>/Compare'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    */
   if (((uint32_T)tmp) != ACCURATED)
   {
      /* Outputs for IfAction SubSystem: '<S274>/If Action Subsystem' incorporates:
       *  ActionPort: '<S280>/Action Port'
       */
      rtb_Merge_mz = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->vertical_acceleration_qf;

      /* End of Outputs for SubSystem: '<S274>/If Action Subsystem' */
   }
   else if (f_Yaw_Rate_Bias_Converged_c && rtb_LogicalOperator_hj)
   {
      /* Outputs for IfAction SubSystem: '<S274>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S281>/Action Port'
       */
      rtb_Merge_mz = ACCURATED;

      /* End of Outputs for SubSystem: '<S274>/If Action Subsystem1' */
   }
   else if ((!f_Yaw_Rate_Bias_Converged_c) && rtb_LogicalOperator_hj)
   {
      /* Outputs for IfAction SubSystem: '<S274>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S282>/Action Port'
       */
      rtb_Merge_mz = TEMP_UNDEFINED;

      /* End of Outputs for SubSystem: '<S274>/If Action Subsystem2' */
   }
   else if (f_Yaw_Rate_Bias_Converged_c && (!rtb_LogicalOperator_hj))
   {
      /* Outputs for IfAction SubSystem: '<S274>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S283>/Action Port'
       */
      rtb_Merge_mz = NOT_ACCURATED;

      /* End of Outputs for SubSystem: '<S274>/If Action Subsystem3' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S274>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S284>/Action Port'
       */
      rtb_Merge_mz = UNDEFINED;

      /* End of Outputs for SubSystem: '<S274>/If Action Subsystem4' */
   }

   /* End of If: '<S274>/If' */

   /* DiscreteTransferFcn: '<S81>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S5>/Data Type Conversion'
    */
   denAccum_a =
      (((((real_T)VSE_Master_Model_WL_L2P_DW->selected_signal_a) -
         (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom_g[1] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[0])) -
        (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom_g[2] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[1])) -
       (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom_g[3] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[2])) -
      (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom_g[4] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[3]);
   rtb_Abs = ((((VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j[0] * denAccum_a) +
                (VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j[1] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[0])) +
               (VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j[2] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[1])) +
              (VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j[3] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[2])) +
             (VSE_Master_Model_WL_L2P_DW->filter_discrete_num_j[4] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[3]);

   /* Switch: '<S81>/Switch' incorporates:
    *  Abs: '<S81>/Abs'
    *  Constant: '<S81>/Constant'
    *  Constant: '<S85>/Constant'
    *  DiscreteTransferFcn: '<S81>/LowPass Filter'
    *  RelationalOperator: '<S85>/Compare'
    */
   if (fabs(rtb_Abs) <= 1.0E-10)
   {
      rtb_Abs = 0.0;
   }

   /* End of Switch: '<S81>/Switch' */

   /* DiscreteTransferFcn: '<S90>/LowPass Filter' incorporates:
    *  DataTypeConversion: '<S6>/Data Type Conversion'
    */
   denAccum_b =
      (((((real_T)VSE_Master_Model_WL_L2P_DW->selected_signal_d) -
         (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom[1] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[0])) -
        (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom[2] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[1])) -
       (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom[3] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[2])) -
      (VSE_Master_Model_WL_L2P_DW->filter_discrete_denom[4] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[3]);
   rtb_Switch = ((((VSE_Master_Model_WL_L2P_DW->filter_discrete_num[0] * denAccum_b) +
                   (VSE_Master_Model_WL_L2P_DW->filter_discrete_num[1] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[0])) +
                  (VSE_Master_Model_WL_L2P_DW->filter_discrete_num[2] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[1])) +
                 (VSE_Master_Model_WL_L2P_DW->filter_discrete_num[3] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[2])) +
                (VSE_Master_Model_WL_L2P_DW->filter_discrete_num[4] * VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[3]);

   /* Switch: '<S90>/Switch' incorporates:
    *  Abs: '<S90>/Abs'
    *  Constant: '<S90>/Constant'
    *  Constant: '<S94>/Constant'
    *  DiscreteTransferFcn: '<S90>/LowPass Filter'
    *  RelationalOperator: '<S94>/Compare'
    */
   if (fabs(rtb_Switch) <= 1.0E-10)
   {
      rtb_Switch = 0.0;
   }

   /* End of Switch: '<S90>/Switch' */

   /* DataTypeConversion: '<S90>/Data Type Conversion' */
   rtb_DataTypeConversion_a = (real32_T)rtb_Switch;

   /* DiscreteTransferFcn: '<S100>/Differentiator' incorporates:
    *  DataTypeConversion: '<S7>/Data Type Conversion'
    *  Delay: '<S42>/Delay'
    */
   denAccum_c = (real_T)VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      denAccum_c -= VSE_Master_Model_WL_L2P_DW->diff_denom[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states[j];
      denIdx++;
   }

   rtb_Switch = VSE_Master_Model_WL_L2P_DW->diff_num[0] * denAccum_c;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      rtb_Switch += VSE_Master_Model_WL_L2P_DW->diff_num[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states[j];
      denIdx++;
   }

   /* Switch: '<S100>/Switch' incorporates:
    *  Abs: '<S100>/Abs'
    *  Constant: '<S100>/Constant'
    *  Constant: '<S104>/Constant'
    *  DiscreteTransferFcn: '<S100>/Differentiator'
    *  RelationalOperator: '<S104>/Compare'
    */
   if (fabs(rtb_Switch) <= 1.0E-10)
   {
      rtb_Switch = 0.0;
   }

   /* End of Switch: '<S100>/Switch' */

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  DataTypeConversion: '<S100>/Data Type Conversion'
    *  Outport: '<Root>/VSE_Output'
    */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vert_jerk = (real32_T)rtb_Switch;

   /* DiscreteTransferFcn: '<S82>/Differentiator' incorporates:
    *  DataTypeConversion: '<S5>/Data Type Conversion'
    */
   denAccum_d = (real_T)VSE_Master_Model_WL_L2P_DW->selected_signal_a;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      denAccum_d -= VSE_Master_Model_WL_L2P_DW->diff_denom_m[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states_p[j];
      denIdx++;
   }

   rtb_Switch = VSE_Master_Model_WL_L2P_DW->diff_num_p[0] * denAccum_d;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      rtb_Switch += VSE_Master_Model_WL_L2P_DW->diff_num_p[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states_p[j];
      denIdx++;
   }

   /* Switch: '<S82>/Switch' incorporates:
    *  Abs: '<S82>/Abs'
    *  Constant: '<S82>/Constant'
    *  Constant: '<S86>/Constant'
    *  DiscreteTransferFcn: '<S82>/Differentiator'
    *  RelationalOperator: '<S86>/Compare'
    */
   if (fabs(rtb_Switch) <= 1.0E-10)
   {
      rtb_Switch = 0.0;
   }

   /* End of Switch: '<S82>/Switch' */

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  DataTypeConversion: '<S82>/Data Type Conversion'
    *  Outport: '<Root>/VSE_Output'
    */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->lateral_jerk = (real32_T)rtb_Switch;

   /* DiscreteTransferFcn: '<S91>/Differentiator' incorporates:
    *  DataTypeConversion: '<S6>/Data Type Conversion'
    */
   denAccum_e = (real_T)VSE_Master_Model_WL_L2P_DW->selected_signal_d;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      denAccum_e -= VSE_Master_Model_WL_L2P_DW->diff_denom_d[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states_k[j];
      denIdx++;
   }

   rtb_Switch = VSE_Master_Model_WL_L2P_DW->diff_num_k[0] * denAccum_e;
   denIdx     = 1;
   for (j = 0; j < 7; j++)
   {
      rtb_Switch += VSE_Master_Model_WL_L2P_DW->diff_num_k[denIdx] * VSE_Master_Model_WL_L2P_DW->Differentiator_states_k[j];
      denIdx++;
   }

   /* Switch: '<S91>/Switch' incorporates:
    *  Abs: '<S91>/Abs'
    *  Constant: '<S91>/Constant'
    *  Constant: '<S95>/Constant'
    *  DiscreteTransferFcn: '<S91>/Differentiator'
    *  RelationalOperator: '<S95>/Compare'
    */
   if (fabs(rtb_Switch) <= 1.0E-10)
   {
      rtb_Switch = 0.0;
   }

   /* End of Switch: '<S91>/Switch' */

   /* Gain: '<S1>/Gain' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->grade_angle_deg = 0.57F * rtb_VsVSE_pct_EstimatedGrade;

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  Constant: '<S192>/Constant'
    *  Constant: '<S19>/Constant'
    *  Constant: '<S19>/Constant1'
    *  MATLAB Function: '<S193>/MATLAB Function'
    *  Outport: '<Root>/VSE_Output'
    *  RelationalOperator: '<S192>/Compare'
    */
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_primary_rawspeed_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_f);

   /* MATLAB Function: '<S208>/MATLAB Function' incorporates:
    *  Constant: '<S207>/Constant'
    *  Constant: '<S24>/Constant'
    *  Constant: '<S24>/Constant1'
    *  RelationalOperator: '<S207>/Compare'
    */
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_b) != ACCURATED, 0.15F, 0.0F, &rtb_final_fault_f,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_h);

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  Constant: '<S195>/Constant'
    *  Constant: '<S20>/Constant'
    *  Constant: '<S20>/Constant1'
    *  MATLAB Function: '<S196>/MATLAB Function'
    *  Outport: '<Root>/VSE_Output'
    *  RelationalOperator: '<S195>/Compare'
    */
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_e) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_primary_rawyawrate_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_o);

   /* MATLAB Function: '<S211>/MATLAB Function' incorporates:
    *  Constant: '<S210>/Constant'
    *  Constant: '<S25>/Constant'
    *  Constant: '<S25>/Constant1'
    *  RelationalOperator: '<S210>/Compare'
    */
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_i) != ACCURATED, 0.15F, 0.0F, &rtb_final_fault_h,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_a);

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  Constant: '<S15>/Constant'
    *  Constant: '<S15>/Constant1'
    *  Constant: '<S16>/Constant'
    *  Constant: '<S16>/Constant1'
    *  Constant: '<S17>/Constant'
    *  Constant: '<S17>/Constant1'
    *  Constant: '<S180>/Constant'
    *  Constant: '<S183>/Constant'
    *  Constant: '<S186>/Constant'
    *  Constant: '<S189>/Constant'
    *  Constant: '<S18>/Constant'
    *  Constant: '<S18>/Constant1'
    *  Constant: '<S198>/Constant'
    *  Constant: '<S201>/Constant'
    *  Constant: '<S204>/Constant'
    *  Constant: '<S21>/Constant'
    *  Constant: '<S21>/Constant1'
    *  Constant: '<S22>/Constant'
    *  Constant: '<S22>/Constant1'
    *  Constant: '<S23>/Constant'
    *  Constant: '<S23>/Constant1'
    *  MATLAB Function: '<S181>/MATLAB Function'
    *  MATLAB Function: '<S184>/MATLAB Function'
    *  MATLAB Function: '<S187>/MATLAB Function'
    *  MATLAB Function: '<S190>/MATLAB Function'
    *  MATLAB Function: '<S199>/MATLAB Function'
    *  MATLAB Function: '<S202>/MATLAB Function'
    *  MATLAB Function: '<S205>/MATLAB Function'
    *  Outport: '<Root>/VSE_Output'
    *  RelationalOperator: '<S180>/Compare'
    *  RelationalOperator: '<S183>/Compare'
    *  RelationalOperator: '<S186>/Compare'
    *  RelationalOperator: '<S189>/Compare'
    *  RelationalOperator: '<S198>/Compare'
    *  RelationalOperator: '<S201>/Compare'
    *  RelationalOperator: '<S204>/Compare'
    */
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_l) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_primary_rawlataccel_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_i);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_a5) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_secondary_rawlataccel_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_k);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_iw) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_primary_rawlongaccel_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_b);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_o) != ACCURATED, 0.15F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_secondary_rawlongaccel_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_d);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_Merge_d) != ACCURATED, 0.1F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_rawsteeringangle_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_e);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)rtb_SpeedCompensation_o2) != ACCURATED, 0.0F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_compspeed_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_l);
   VSE_Master_Model_WL_L2P_MATLABFunction(((uint32_T)VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF) != ACCURATED, 0.0F, 0.0F,
                                          &VSE_Master_Model_WL_L2P_Y_VSE_Output->f_compyawrate_plausibility_fault,
                                          &VSE_Master_Model_WL_L2P_DW->sf_MATLABFunction_c);

   /* Switch: '<S63>/Switch1' incorporates:
    *  Switch: '<S57>/Switch1'
    *  Switch: '<S61>/Switch1'
    *  Switch: '<S62>/Switch1'
    */
   if (rtb_LogicalOperator_jn)
   {
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Inport: '<Root>/VnetInVehicleStateEstimator'
       *  Outport: '<Root>/VSE_Output'
       *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
       */
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_speed_measured_rad_per_s =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rwa_speed_measured_rad_per_s;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_speed_measured_rad_per_s_validity =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rwa_speed_measured_rad_per_s_validity;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_speed_measured_rad_per_s =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rear_rwa_speed_measured_rad_per_s;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_speed_measured_rad_per_s_validity =
         VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->rear_rwa_speed_measured_rad_per_s_validity;
   }
   else
   {
      /* BusCreator: '<S1>/Bus Creator' incorporates:
       *  Constant: '<S57>/k_rws_angle_speed_not_activated_rps'
       *  Constant: '<S61>/validity_default'
       *  Constant: '<S62>/validity_default'
       *  Constant: '<S63>/k_rws_angle_speed_not_activated_rps'
       *  Outport: '<Root>/VSE_Output'
       */
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_speed_measured_rad_per_s               = 0.0F;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_speed_measured_rad_per_s_validity      = UNDEFINED;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_speed_measured_rad_per_s          = 0.0F;
      VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_speed_measured_rad_per_s_validity = UNDEFINED;
   }

   /* End of Switch: '<S63>/Switch1' */

   /* Gain: '<S1>/Gain2' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_left_sensor_lat_velocity_ULVC = -rtb_front_left_sensor_lat;

   /* Gain: '<S1>/Gain1' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_right_sensor_lat_velocity_ULVC = -rtb_front_right_sensor_lat;

   /* Gain: '<S1>/Gain3' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_left_sensor_lat_velocity_ULVC = -rtb_rear_left_sensor_lat;

   /* Gain: '<S1>/Gain4' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_right_sensor_lat_velocity_ULVC = -rtb_rear_right_sensor_lat;

   /* Gain: '<S1>/Gain5' */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_bumper_sensor_lat_velocity_ULVC = -rtb_front_bumper_sensor_lat;

   /* BusCreator: '<S1>/Bus Creator' incorporates:
    *  Constant: '<S1>/Constant10'
    *  Constant: '<S1>/Constant2'
    *  Constant: '<S1>/Constant5'
    *  Constant: '<S1>/Constant6'
    *  Constant: '<S1>/Constant7'
    *  Constant: '<S1>/Constant8'
    *  Constant: '<S1>/Constant9'
    *  DataTypeConversion: '<S1>/Cast4'
    *  DataTypeConversion: '<S81>/Data Type Conversion'
    *  DataTypeConversion: '<S91>/Data Type Conversion'
    *  Delay: '<S42>/Delay'
    *  Delay: '<S43>/Delay'
    *  Delay: '<S44>/Delay'
    *  Inport: '<Root>/System_Time_Micro_Sec'
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    *  Outport: '<Root>/VSE_Output'
    *  SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0'
    *  UnitDelay: '<S36>/Unit Delay'
    */
   VSE_Master_Model_WL_L2P_Y_VSE_Output->timestamp_us                      = VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_speed_mps                     = VSE_Master_Model_WL_L2P_DW->selected_signal;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_speed_qf                      = VSE_Master_Model_WL_L2P_DW->selected_signal_qf;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->speed_compensation_factor         = rtb_VsTracker_VehSpdCompFac;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->speed_compensation_factor_qf      = rtb_VeTracker_VehSpdCompFac_QF;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->filt_veh_speed_over_ground        = rtb_SpeedCompensation_o1;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->filt_veh_speed_over_ground_qf     = rtb_SpeedCompensation_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->signed_filt_veh_speed_over_ground = rtb_Product;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->wheel_odo_speed_over_ground       = VSE_Master_Model_WL_L2P_DW->UnitDelay_DSTATE;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->wheel_odo_speed_over_ground_qf =
      VSE_Master_Model_WL_L2P_DW->VeVSE_mps_WhlOdoVehSpeedOverGroundQF_h;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_lat_accel           = VSE_Master_Model_WL_L2P_DW->selected_signal_a;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_lat_accel_qf        = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_long_accel          = VSE_Master_Model_WL_L2P_DW->selected_signal_d;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_long_accel_qf       = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_iq;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_vert_accel          = VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_vert_accel_qf       = rtb_Merge_mz;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->VCS_Lat_Accel           = rtb_Model4_o1;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->VCS_Long_Accel          = rtb_Model4_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->VCS_Lat_Accel_QF        = rtb_Model4_o3;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->VCS_Long_Accel_QF       = rtb_Model4_o4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_lat_accel          = (real32_T)rtb_Abs;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_lat_accel_qf       = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_long_accel         = rtb_DataTypeConversion_a;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_long_accel_qf      = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_iq;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->wheel_odo_long_accel    = rtb_VsVSE_mps2_WhlOdoVehLongAccel_p;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->wheel_odo_long_accel_qf = VSE_Master_Model_WL_L2P_DW->VeVSE_WhlOdoVehAccelQF_m;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_vert_accel         = VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_do;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_vert_accel_qf      = rtb_Merge_mz;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vert_jerk_qf            = rtb_Merge_mz;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->lateral_jerk_qf         = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_g;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->longitudinal_jerk       = (real32_T)rtb_Switch;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->longitudinal_jerk_qf    = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_iq;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->bank_angle_deg          = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->bank_angle_qf           = VSE_Master_Model_WL_L2P_ConstB.DataTypeConversion4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->grade_angle_qf          = VSE_Master_Model_WL_L2P_DW->VsVSE_EstimatedGradeQF;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_yaw_stop_bias_converged =
      VSE_Master_Model_WL_L2P_DW->f_yaw_rate_stop_bias_converged_atleast_once;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_roll_rate_rps             = VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_jv;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_roll_rate_qf              = rtb_Merge_mg;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_pitch_rate_rps            = VSE_Master_Model_WL_L2P_DW->Delay_DSTATE_ji;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_pitch_rate_qf             = rtb_Merge_lr;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_steering_angle_deg        = VSE_Master_Model_WL_L2P_DW->selected_signal_b;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->raw_steering_angle_qf         = VSE_Master_Model_WL_L2P_DW->selected_signal_qf_i;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_steering_angle_deg       = VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_deg_SAE;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_steering_angle_qf        = VSE_Master_Model_WL_L2P_DW->CompSteeringAngle_QF;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->swa_bias_deg_converged_to_nvm = VSE_Master_Model_WL_L2P_DW->SWA_Bias_deg_Conv_Out;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_swa_bias_converged_to_nvm   = VSE_Master_Model_WL_L2P_DW->f_SWA_Bias_deg_Conv_out;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_swa_bias_converged_internal = VSE_Master_Model_WL_L2P_DW->f_SWA_Bias_deg_Conv_internal;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->road_wheel_angle_deg          = rtb_YawRateEstimationUsingSteeringWheelAngle_o3;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->road_wheel_angle_qf           = rtb_YawRateEstimationUsingSteeringWheelAngle_o4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->steering_angle_rate_filt_degpsec =
      VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->steering_whl_speed_deg_per_s;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_sa                       = rtb_yawRate;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->yaw_rate_sa_qf                    = rtb_qf;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->stop_yaw_bias_nvm_write_primary   = rtb_Stop_Yaw_Bias_NVM_Write;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->stop_yaw_bias_nvm_write_secondary = rtb_Stop_Yaw_Bias_NVM_Write_l;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_yaw_rate_filtered     = VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_yaw_rate_qf           = VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->roll_rate_bias             = VSE_Master_Model_WL_L2P_DW->imu_signal_bias;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_roll_rate_unfiltered  = rtb_RollRateCompensation_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_roll_rate_filtered    = rtb_RollRateCompensation_o3;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_roll_rate_qf          = rtb_RollRateCompensation_o4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->pitch_rate_bias            = VSE_Master_Model_WL_L2P_DW->imu_signal_bias_m;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_pitch_rate_unfiltered = rtb_PitchRateCompensation_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_pitch_rate_filtered   = rtb_PitchRateCompensation_o3;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->comp_pitch_rate_qf         = rtb_PitchRateCompensation_o4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->curvature_rear_axle        = rtb_curvature_rear_axle;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->sideslip_rear_axle         = rtb_sideslip_rear_axle;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vcs_sideslip               = rtb_VCS_sideslip;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vcs_long_velocity          = rtb_VCS_long_velocity;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vcs_lat_velocity           = rtb_VCS_lat_velocity;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->sensor_sideslip            = rtb_sensor_sideslip;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->sensor_long_velocity       = rtb_sensor_long_velocity;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->sensor_lat_velocity        = rtb_sensor_lat_velocity;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->cog_long_vel               = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->cog_lat_vel                = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->cog_long_accel             = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->cog_lat_accel              = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->stationary = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->vehicle_standstill;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_stationary_vse                          = rtb_f_stationary;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->reverse_status                            = rtb_Cast;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->motion_direction                          = 0U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_speed_rationality_check_passed          = rtb_SpeedRationalityCheck;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_yawrate_rationality_check_passed        = VSE_Master_Model_WL_L2P_DW->Model2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_steering_rationality_check_passed       = rtb_SteeringAngleRationalityCheck;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_lataccel_rationality_check_passed       = rtb_LatAccelRationalityCheck;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_longaccel_rationality_check_passed      = rtb_LongAccelRationalityCheck;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_secondary_rawspeed_plausibility_fault   = rtb_final_fault_f;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->f_secondary_rawyawrate_plausibility_fault = rtb_final_fault_h;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_measured_rad                          = rtb_Switch1;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rwa_measured_rad_validity                 = rtb_Cast4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_measured_rad                     = rtb_Switch1_d;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_rwa_measured_rad_validity            = rtb_Switch1_n5;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Lat_Delta_ULVC                            = rtb_HeadingAngleAndLatLongDisplacement_o1;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Long_Delta_ULVC                           = rtb_HeadingAngleAndLatLongDisplacement_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Heading_Delta_ULVC                        = rtb_HeadingAngleAndLatLongDisplacement_o3;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Heading_Delta_ULVC_QF                     = rtb_HeadingAngleAndLatLongDisplacement_o4;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_left_sensor_long_velocity_ULVC      = rtb_front_left_sensor_long;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_right_sensor_long_velocity_ULVC     = rtb_front_right_sensor_long;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_left_sensor_long_velocity_ULVC       = rtb_rear_left_sensor_long;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->rear_right_sensor_long_velocity_ULVC      = rtb_rear_right_sensor_long;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->front_bumper_sensor_long_velocity_ULVC    = rtb_front_bumper_sensor_long;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Road_Grade_Accel                          = rtb_Road_Grade_Accel;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->Road_Grade_Accel_QF     = (enum_quality_factor_T)rtb_Road_Grade_Accel_QF;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vse_major_version       = 60U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vse_minor_version       = 0U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vse_field_version       = 0U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output->vse_calibration_version = 0U;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Switch1 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->VsVCAN_Nm_Trailer_AxleTrq;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Switch1_d = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->brk_trq;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Product = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->trq_amp_trans;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fr_wheel_rot_speed_rpm = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fr_wheel_rot_speed_rpm;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_fl_wheel_rot_speed_rpm = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->fl_wheel_rot_speed_rpm;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_VsVCAN_Trailer_ITBM_Power = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->VsVCAN_Trailer_ITBM_Power;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_gear_box_pos = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->trailer_connection_sts;

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_Cast6 = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->trailer_sts;

   /* ModelReference: '<S1>/Model' incorporates:
    *  Inport: '<Root>/AptivCfg'
    *  Inport: '<Root>/Tracker_VSE_Trailer_Signals'
    */
   TrailerDetection(&rtb_gear_box_pos, &rtb_Cast6, &VSE_Master_Model_WL_L2P_U_AptivCfg_p->CsPROXI_CANNode63_TTM,
                    &VSE_Master_Model_WL_L2P_U_AptivCfg_p->CsPROXI_CANNode95_ITBM,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerPresence,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerPresenceConfLvl,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerLengthConfLvl,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerWidthConfLvl,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_m_TrailerLength,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_m_TrailerWidth,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_RadarDetectSts,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_ms_RadarDetectTimer,
                    &VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_ms_StationaryTimer,
                    &VSE_Master_Model_WL_L2P_DW->Trailer_Detection, &rtb_Trailer_Detection_ConfLvl, &rtb_trailer_length,
                    &rtb_trailer_length_ConfLvl, &rtb_trailer_width, &rtb_trailer_width_ConfLvl, &rtb_Model_o7, &rtb_Model_o8,
                    &rtb_Model_o9);

   /* SignalConversion: '<Root>/BusConversion_InsertedFor_VnetInVehicleStateEstimator_at_outport_0' incorporates:
    *  Inport: '<Root>/VnetInVehicleStateEstimator'
    */
   rtb_gear_box_pos = VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b->veh_ignition_sts;

   /* ModelReference: '<S1>/Model6' incorporates:
    *  Inport: '<Root>/AptivCfg'
    *  Inport: '<Root>/Tracker_VSE_Trailer_Signals'
    *  Inport: '<Root>/Vehicle_Parameters'
    */
   VehicleMassEstimator_2018b(
      &rtb_Switch1, &rtb_SpeedCompensation_o1, &VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j->k_front_wheel_radius_static_loaded,
      &rtb_Switch1_d, &rtb_DataTypeConversion_a, &VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered, &rtb_Product,
      &rtb_fr_wheel_rot_speed_rpm, &rtb_fl_wheel_rot_speed_rpm, &rtb_VsVCAN_Trailer_ITBM_Power,
      &VSE_Master_Model_WL_L2P_DW->Trailer_Detection, &rtb_gear_box_pos,
      &VSE_Master_Model_WL_L2P_U_AptivCfg_p->CsPROXI_CANNode95_ITBM, &rtb_f_stationary, &rtb_brake_padel_press, &rtb_Model6_o1,
      &rtb_Model6_o2, &VSE_Master_Model_WL_L2P_DW->Timer, &rtb_total_count, &rtb_CountAccel, &rtb_brake_count, &rtb_EstMass_Acc,
      &rtb_EstMass_Brk, &rtb_percentage_conv, &rtb_VsVSE_b_ResetFlag, &rtb_EstimatedMass,
      &(VSE_Master_Model_WL_L2P_DW->Model6_InstanceData_o.rtdw));

   /* BusCreator: '<S1>/Bus Creator1' incorporates:
    *  Outport: '<Root>/VSE_Resim_Output'
    */
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->yaw_rate_bias1                      = yaw_rate_bias1;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->yaw_rate_bias2                      = yaw_rate_bias2;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->yaw_rate_bias_fast_bias1            = yaw_rate_bias_fast_bias1;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->yaw_rate_bias_fast_bias2            = yaw_rate_bias_fast_bias2;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->comp_yaw_rate_diff_filt             = comp_yaw_rate_diff_filt;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->yaw_rate_bias_diff                  = yaw_rate_bias_diff;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->road_type                           = road_type;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_yaw_rate_bias_shift               = rtb_LogicalOperator;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_Yaw_Rate_Bias_Converged           = rtb_LogicalOperator_m;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_stop_bias_converged               = f_stop_bias_converged;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_yaw_rate_steady                   = f_yaw_rate_steady;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_input_invalid_persistent          = f_input_invalid_persistent;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_execution_period_error_persistent = f_execution_period_error_persistent;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_bias_was_accurate                 = f_bias_was_accurate;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->ignition_time                       = ignition_time;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_yaw_stop_bias_converged           = f_yaw_stop_bias_converged;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->CurvKalmanFilterC0                  = rtb_CurvKalmanFilterC0;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->CurvKalmanFilterC1                  = rtb_CurvKalmanFilterC1;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_stop_rollrate_bias_converged =
      VSE_Master_Model_WL_L2P_DW->f_stop_imu_signal_bias_converged;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->f_stop_pitchrate_bias_converged =
      VSE_Master_Model_WL_L2P_DW->f_stop_imu_signal_bias_converged_j;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_TrlrTotalCount      = rtb_total_count;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_TrlrCountAccel      = rtb_CountAccel;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_TrlrCountBrake      = rtb_brake_count;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_TrlrRunningAvgAccel = rtb_EstMass_Acc;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_TrlrRunningAvgBrake = rtb_EstMass_Brk;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_EstMassRunningAvg   = rtb_EstimatedMass;
   VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output->VsVSE_b_ResetFlag         = rtb_VsVSE_b_ResetFlag;

   /* BusCreator: '<S1>/Bus Creator2' incorporates:
    *  Inport: '<Root>/Tracker_VSE_Trailer_Signals'
    *  Outport: '<Root>/VSE_Output_Trailer'
    */
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_Kg_TrlrMass     = rtb_Model6_o1;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_Kg_HostVehMass  = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_m_TrlrLen       = rtb_trailer_length;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_m_TrlrWidth     = rtb_trailer_width;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_Kgm2_HostVehIzz = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_Kgm2_TrlrIzz    = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_N_HitchFx       = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_N_HitchFy       = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_Nm_HitchMz      = 0.0F;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_rad_HitchAng =
      VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_rad_TrailerAngle;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_rps_HitchAngSpd =
      VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_rps_TrailerAngleRate;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_m_TrlrHostVehGap =
      VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_m_TrailerHVGap;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_TrlrDetectSts        = VSE_Master_Model_WL_L2P_DW->Trailer_Detection;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_TrlrDetectStsConfLvl = rtb_Trailer_Detection_ConfLvl;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_b_TrlrMassConv       = rtb_Model6_o2;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_b_HostVehMassConv    = false;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_TrlrLenConfLvl       = rtb_trailer_length_ConfLvl;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_TrlrWidthConfLvl     = rtb_trailer_width_ConfLvl;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_b_HostVehIzzConv     = false;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_b_TrlrIzzConv        = false;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_HitchFxConfLvl       = 3U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_HitchFyConfLvl       = 3U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_HitchMzConfLvl       = 3U;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_HitchAngConfLvl =
      VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerAngleConfLvl;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_HitchAngSpdConfLvl =
      VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a->VsTracker_TrailerAngleRateConfLvl;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VeVSE_b_RadarDetectionSts   = rtb_Model_o7;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_s_RadarDetectionTimer = rtb_Model_o8;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_s_StationaryTimer     = rtb_Model_o9;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_s_TrlrMassCalcTimer   = VSE_Master_Model_WL_L2P_DW->Timer;
   VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer->VsVSE_TrlrMassConvPercent   = rtb_percentage_conv;

   /* Update for DiscreteFilter: '<S27>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states[0] = denAccum;

   /* Update for DiscreteFilter: '<S28>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_e[0] = denAccum_0;

   /* Update for DiscreteFilter: '<S29>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o[0] = denAccum_1;

   /* Update for UnitDelay: '<S1>/Unit Delay1' */
   VSE_Master_Model_WL_L2P_DW->UnitDelay1_DSTATE = VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_Filtered;

   /* Update for DiscreteFilter: '<S8>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_p[0] = denAccum_2;

   /* Update for DiscreteFilter: '<S9>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_o1[0] = denAccum_3;

   /* Update for DiscreteFilter: '<S30>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ej[0] = denAccum_4;

   /* Update for DiscreteFilter: '<S31>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_k[0] = denAccum_5;

   /* Update for UnitDelay: '<S1>/Unit Delay' */
   VSE_Master_Model_WL_L2P_DW->UnitDelay_DSTATE_c = VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF;

   /* Update for DiscreteFilter: '<S34>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_g[0] = rtb_DataTypeConversion_p;

   /* Update for DiscreteFilter: '<S35>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_l[0] = rtb_DataTypeConversion_lk;

   /* Update for DiscreteFilter: '<S10>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_or[0] = denAccum_6;

   /* Update for DiscreteFilter: '<S11>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_c[0] = denAccum_7;

   /* Update for DiscreteFilter: '<S12>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_n[0] = rtb_correc_stop_yaw_bias_nvm_read_g;

   /* Update for DiscreteFilter: '<S13>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_gy[0] = denAccum_8;

   /* Update for DiscreteFilter: '<S33>/Discrete Filter' */
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[2] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[1];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[1] = VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[0];
   VSE_Master_Model_WL_L2P_DW->DiscreteFilter_states_ou[0] = denAccum_9;

   /* Update for DiscreteTransferFcn: '<S81>/LowPass Filter' */
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[3] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[2];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[2] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[1];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[1] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[0];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states[0] = denAccum_a;

   /* Update for DiscreteTransferFcn: '<S90>/LowPass Filter' */
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[3] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[2];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[2] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[1];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[1] = VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[0];
   VSE_Master_Model_WL_L2P_DW->LowPassFilter_states_d[0] = denAccum_b;
   for (j = 0; j < 6; j++)
   {
      /* Update for DiscreteTransferFcn: '<S100>/Differentiator' */
      VSE_Master_Model_WL_L2P_DW->Differentiator_states[6 - j] = VSE_Master_Model_WL_L2P_DW->Differentiator_states[5 - j];

      /* Update for DiscreteTransferFcn: '<S82>/Differentiator' */
      VSE_Master_Model_WL_L2P_DW->Differentiator_states_p[6 - j] = VSE_Master_Model_WL_L2P_DW->Differentiator_states_p[5 - j];

      /* Update for DiscreteTransferFcn: '<S91>/Differentiator' */
      VSE_Master_Model_WL_L2P_DW->Differentiator_states_k[6 - j] = VSE_Master_Model_WL_L2P_DW->Differentiator_states_k[5 - j];
   }

   /* Update for DiscreteTransferFcn: '<S100>/Differentiator' */
   VSE_Master_Model_WL_L2P_DW->Differentiator_states[0] = denAccum_c;

   /* Update for DiscreteTransferFcn: '<S82>/Differentiator' */
   VSE_Master_Model_WL_L2P_DW->Differentiator_states_p[0] = denAccum_d;

   /* Update for DiscreteTransferFcn: '<S91>/Differentiator' */
   VSE_Master_Model_WL_L2P_DW->Differentiator_states_k[0] = denAccum_e;
}

/* Model initialize function */
void VSE_Master_Model_WL_L2P_initialize(RT_MODEL_VSE_Master_Model_WL_L2P_T *const VSE_Master_Model_WL_L2P_M)
{
   DW_VSE_Master_Model_WL_L2P_T *VSE_Master_Model_WL_L2P_DW = ((DW_VSE_Master_Model_WL_L2P_T *)VSE_Master_Model_WL_L2P_M->dwork);

   /* Registration code */

   /* states (dwork) */
   {
      VSE_Master_Model_WL_L2P_DW->selected_signal_number   = PRIMARY;
      VSE_Master_Model_WL_L2P_DW->selected_signal_number_e = PRIMARY;
      VSE_Master_Model_WL_L2P_DW->selected_signal_number_m = PRIMARY;
      VSE_Master_Model_WL_L2P_DW->selected_signal_number_p = PRIMARY;
      VSE_Master_Model_WL_L2P_DW->selected_signal_number_g = PRIMARY;
      VSE_Master_Model_WL_L2P_DW->selected_signal_number_k = PRIMARY;
   }

   {
      /* local block i/o variables */
      real32_T rtb_VsVSE_mps_WhlOdoVehSpeedOverGround;
      real32_T rtb_VsVSE_mps2_WhlOdoVehLongAccel;

      /* Start for ModelReference: '<S36>/Model6' incorporates:
       *  Constant: '<S1>/Constant12'
       *  Constant: '<S1>/Constant13'
       *  Constant: '<S1>/Constant44'
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  Inport: '<Root>/Vehicle_Parameters'
       */
      ABS_TCS_Algorithm_Start(&(VSE_Master_Model_WL_L2P_DW->Model6_InstanceData.rtdw));

      /* Start for ModelReference: '<S36>/Model5' incorporates:
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  UnitDelay: '<S36>/Unit Delay'
       *  UnitDelay: '<S36>/Unit Delay1'
       */
      Speed_Arbitration_and_IMU_Fusion_Start(&(VSE_Master_Model_WL_L2P_DW->Model5_InstanceData_k.rtdw));

      /* Start for ModelReference: '<S1>/Model3' incorporates:
       *  Constant: '<S1>/Constant40'
       *  Constant: '<S1>/Constant41'
       *  Constant: '<S1>/Constant42'
       *  Constant: '<S1>/Constant43'
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       */
      GradeEstimation_Start(&(VSE_Master_Model_WL_L2P_DW->Model3_InstanceData_c.rtdw));

      /* SystemInitialize for ModelReference: '<S1>/RawSpeedArbitration' incorporates:
       *  Delay: '<S45>/Delay'
       *  Delay: '<S48>/Delay'
       *  Delay: '<S49>/Delay'
       */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number);

      /* SystemInitialize for ModelReference: '<S1>/SpeedCompensation' incorporates:
       *  Constant: '<S1>/default_f_use_gps_comp_factor'
       *  Constant: '<S1>/default_gps_comp_factor'
       *  Inport: '<Root>/LAST_KEY_CYCLE'
       */
      SpeedCompensation_Init(&(VSE_Master_Model_WL_L2P_DW->SpeedCompensation_InstanceData.rtdw));

      /* SystemInitialize for ModelReference: '<S1>/RawLateralAccelerationArbitration' incorporates:
       *  Delay: '<S50>/Delay'
       *  Delay: '<S51>/Delay'
       */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number_e);

      /* SystemInitialize for ModelReference: '<S1>/RawSteeringAngleArbitration' incorporates:
       *  Delay: '<S40>/Delay'
       *  Delay: '<S41>/Delay'
       */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number_m);

      /* SystemInitialize for ModelReference: '<S1>/Model1' incorporates:
       *  Delay: '<S46>/Delay'
       *  Delay: '<S47>/Delay'
       */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number_p);

      /* SystemInitialize for ModelReference: '<S1>/RawLongitudinalAccelerationArbitration' incorporates:
       *  Delay: '<S52>/Delay'
       *  Delay: '<S53>/Delay'
       */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number_g);

      /* SystemInitialize for ModelReference: '<S1>/CompensatedYawRateArbitration' */
      Signal_Arbitration_Common_Init(&VSE_Master_Model_WL_L2P_DW->selected_signal_number_k);

      /* SystemInitialize for Merge: '<S14>/Merge' */
      VSE_Master_Model_WL_L2P_DW->Yaw_Rate_Compensated_QF = UNDEFINED;

      /* SystemInitialize for ModelReference: '<S36>/Model6' incorporates:
       *  Constant: '<S1>/Constant12'
       *  Constant: '<S1>/Constant13'
       *  Constant: '<S1>/Constant44'
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  Inport: '<Root>/Vehicle_Parameters'
       */
      ABS_TCS_Algorithm_Init(&rtb_VsVSE_mps_WhlOdoVehSpeedOverGround, &rtb_VsVSE_mps2_WhlOdoVehLongAccel,
                             &(VSE_Master_Model_WL_L2P_DW->Model6_InstanceData.rtdw));

      /* SystemInitialize for ModelReference: '<S36>/Model3' incorporates:
       *  Constant: '<S1>/VsVCAN_nu_CountsPerRevol'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  Inport: '<Root>/Vehicle_Parameters'
       */
      Wheel_Counts_To_Linear_Speed_Init(&(VSE_Master_Model_WL_L2P_DW->Model3_InstanceData.rtdw));

      /* SystemInitialize for ModelReference: '<S36>/Model5' incorporates:
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  UnitDelay: '<S36>/Unit Delay'
       *  UnitDelay: '<S36>/Unit Delay1'
       */
      Speed_Arbitration_and_IMU_Fusion_Init(&(VSE_Master_Model_WL_L2P_DW->Model5_InstanceData_k.rtdw));

      /* SystemInitialize for ModelReference: '<S1>/VehicleCurvatureAndSideslipEstimation' incorporates:
       *  Constant: '<S1>/Constant4'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       *  Inport: '<Root>/Vehicle_Parameters'
       */
      VehicleCurvatureAndSideslipEstimation_Simulink_Init(
         &(VSE_Master_Model_WL_L2P_DW->VehicleCurvatureAndSideslipEstimation_InstanceData.rtdw));

      /* SystemInitialize for ModelReference: '<S1>/Model3' incorporates:
       *  Constant: '<S1>/Constant40'
       *  Constant: '<S1>/Constant41'
       *  Constant: '<S1>/Constant42'
       *  Constant: '<S1>/Constant43'
       *  Delay: '<S52>/Delay'
       *  Inport: '<Root>/System_Time_Micro_Sec'
       */
      GradeEstimation_Init(&(VSE_Master_Model_WL_L2P_DW->Model3_InstanceData_c.rtdw));
   }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
