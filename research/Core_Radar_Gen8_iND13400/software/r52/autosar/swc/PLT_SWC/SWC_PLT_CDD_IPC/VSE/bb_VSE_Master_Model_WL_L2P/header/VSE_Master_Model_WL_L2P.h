/*
 * File: VSE_Master_Model_WL_L2P.h
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

#ifndef RTW_HEADER_VSE_Master_Model_WL_L2P_h_
   #define RTW_HEADER_VSE_Master_Model_WL_L2P_h_
   #include <math.h>
   #include <string.h>
   #ifndef VSE_Master_Model_WL_L2P_COMMON_INCLUDES_
      #define VSE_Master_Model_WL_L2P_COMMON_INCLUDES_
      #include "rtwtypes.h"
   #endif /* VSE_Master_Model_WL_L2P_COMMON_INCLUDES_ */

   #include "VSE_Master_Model_WL_L2P_types.h"

   /* Child system includes */
   #include "ABS_TCS_Algorithm.h"
   #include "Acceleration_VCS.h"
   #include "DetermineReverseStatus.h"
   #include "DtrmnVehStationary.h"
   #include "GradeEstimation.h"
   #include "HeadingAngleandLatLongDisplacement.h"
   #include "PitchRateCompensation.h"
   #include "RollRateCompensation.h"
   #include "SelectHostLongAccel.h"
   #include "Signal_Arbitration_Common.h"
   #include "Signal_Rationality_Check_Common.h"
   #include "SpeedCompensation.h"
   #include "SpeedCompensationArbitration.h"
   #include "Speed_Arbitration_and_IMU_Fusion.h"
   #include "SteeringWheelAngleBiasEstimation.h"
   #include "TrailerDetection.h"
   #include "VehicleCurvatureAndSideslipEstimation_Simulink.h"
   #include "VehicleMassEstimator_2018b.h"
   #include "Wheel_Counts_To_Linear_Speed.h"
   #include "YawRateCompensation.h"
   #include "YawRateEstimationUsingSteeringWheelAngle.h"
   #include "Yaw_Rate_Rationality_Check.h"

   /* Macros for accessing real-time model data structure */
   #ifndef rtmGetRootDWork
      #define rtmGetRootDWork(rtm) ((rtm)->dwork)
   #endif

   #ifndef rtmSetRootDWork
      #define rtmSetRootDWork(rtm, val) ((rtm)->dwork = (val))
   #endif

/* Block signals and states (default storage) for system '<S5>/Chart' */
typedef struct
{
   struct
   {
      uint_T is_c4_JerkEstimator:2;        /* '<S5>/Chart' */
      uint_T is_active_c4_JerkEstimator:1; /* '<S5>/Chart' */
   } bitsForTID0;
} DW_Chart_VSE_Master_Model_WL_L2P_T;

/* Block signals and states (default storage) for system '<S8>/Initialization_Trigger' */
typedef struct
{
   struct
   {
      uint_T is_c5_Initialization_Trigger:2;        /* '<S8>/Initialization_Trigger' */
      uint_T is_active_c5_Initialization_Trigger:1; /* '<S8>/Initialization_Trigger' */
   } bitsForTID0;
} DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T;

/* Block signals and states (default storage) for system '<S181>/MATLAB Function' */
typedef struct
{
   real32_T matured_time;   /* '<S181>/MATLAB Function' */
   real32_T dematured_time; /* '<S181>/MATLAB Function' */
   struct
   {
      uint_T prev_final_fault_flag:1; /* '<S181>/MATLAB Function' */
   } bitsForTID0;
} DW_MATLABFunction_VSE_Master_Model_WL_L2P_T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_ds; /* '<S35>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_o;  /* '<S34>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_l;  /* '<S33>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_ak; /* '<S31>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_ie; /* '<S30>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_i;  /* '<S29>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_d;  /* '<S28>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_j;  /* '<S27>/Initialization_Trigger' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_a;                  /* '<S211>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_h;                  /* '<S208>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_d;                  /* '<S205>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_k;                  /* '<S202>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_e;                  /* '<S199>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_o;                  /* '<S196>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_f;                  /* '<S193>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_b;                  /* '<S190>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_i;                  /* '<S187>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_c;                  /* '<S184>/MATLAB Function' */
   DW_MATLABFunction_VSE_Master_Model_WL_L2P_T sf_MATLABFunction_l;                  /* '<S181>/MATLAB Function' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_n;  /* '<S13>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_h;  /* '<S12>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_a;  /* '<S11>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_e;  /* '<S10>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger_g;  /* '<S9>/Initialization_Trigger' */
   DW_Initialization_Trigger_VSE_Master_Model_WL_L2P_T sf_Initialization_Trigger;    /* '<S8>/Initialization_Trigger' */
   DW_Chart_VSE_Master_Model_WL_L2P_T sf_Chart_fq;                                   /* '<S7>/Chart' */
   DW_Chart_VSE_Master_Model_WL_L2P_T sf_Chart_f;                                    /* '<S6>/Chart' */
   DW_Chart_VSE_Master_Model_WL_L2P_T sf_Chart;                                      /* '<S5>/Chart' */
   MdlrefDW_ABS_TCS_Algorithm_T Model6_InstanceData;                                 /* '<S36>/Model6' */
   MdlrefDW_Acceleration_VCS_T Model4_InstanceData;                                  /* '<S1>/Model4' */
   MdlrefDW_DetermineReverseStatus_T DetermineReverseStatus_InstanceData;            /* '<S1>/DetermineReverseStatus' */
   MdlrefDW_DtrmnVehStationary_T DtrmnVehStationary_InstanceData;                    /* '<S1>/DtrmnVehStationary' */
   MdlrefDW_GradeEstimation_T Model3_InstanceData_c;                                 /* '<S1>/Model3' */
   MdlrefDW_HeadingAngleandLatLongDisplacement_T
      HeadingAngleAndLatLongDisplacement_InstanceData;                    /* '<S1>/HeadingAngleAndLatLongDisplacement' */
   MdlrefDW_PitchRateCompensation_T PitchRateCompensation_InstanceData;   /* '<S1>/PitchRateCompensation' */
   MdlrefDW_RollRateCompensation_T RollRateCompensation_InstanceData;     /* '<S1>/RollRateCompensation' */
   MdlrefDW_SelectHostLongAccel_T SelectHostLongAccel_InstanceData;       /* '<S1>/SelectHostLongAccel' */
   MdlrefDW_Signal_Arbitration_Common_T RawSpeedArbitration_InstanceData; /* '<S1>/RawSpeedArbitration' */
   MdlrefDW_Signal_Arbitration_Common_T
      RawLateralAccelerationArbitration_InstanceData;                             /* '<S1>/RawLateralAccelerationArbitration' */
   MdlrefDW_Signal_Arbitration_Common_T RawSteeringAngleArbitration_InstanceData; /* '<S1>/RawSteeringAngleArbitration' */
   MdlrefDW_Signal_Arbitration_Common_T Model1_InstanceData;                      /* '<S1>/Model1' */
   MdlrefDW_Signal_Arbitration_Common_T
      RawLongitudinalAccelerationArbitration_InstanceData; /* '<S1>/RawLongitudinalAccelerationArbitration' */
   MdlrefDW_Signal_Arbitration_Common_T CompensatedYawRateArbitration_InstanceData; /* '<S1>/CompensatedYawRateArbitration' */
   MdlrefDW_Signal_Rationality_Check_Common_T SpeedRationalityCheck_InstanceData;   /* '<S1>/SpeedRationalityCheck' */
   MdlrefDW_Signal_Rationality_Check_Common_T
      SteeringAngleRationalityCheck_InstanceData;                                     /* '<S1>/SteeringAngleRationalityCheck' */
   MdlrefDW_Signal_Rationality_Check_Common_T LatAccelRationalityCheck_InstanceData;  /* '<S1>/LatAccelRationalityCheck' */
   MdlrefDW_Signal_Rationality_Check_Common_T LongAccelRationalityCheck_InstanceData; /* '<S1>/LongAccelRationalityCheck' */
   MdlrefDW_SpeedCompensation_T SpeedCompensation_InstanceData;                       /* '<S1>/SpeedCompensation' */
   MdlrefDW_Speed_Arbitration_and_IMU_Fusion_T Model5_InstanceData_k;                 /* '<S36>/Model5' */
   MdlrefDW_SteeringWheelAngleBiasEstimation_T
      SteeringWheelAngleBiasEstimation_InstanceData; /* '<S1>/Steering Wheel Angle Bias Estimation' */
   MdlrefDW_VehicleCurvatureAndSideslipEstimation_Simulink_T
      VehicleCurvatureAndSideslipEstimation_InstanceData;                     /* '<S1>/VehicleCurvatureAndSideslipEstimation' */
   MdlrefDW_VehicleMassEstimator_2018b_T Model6_InstanceData_o;               /* '<S1>/Model6' */
   MdlrefDW_Wheel_Counts_To_Linear_Speed_T Model3_InstanceData;               /* '<S36>/Model3' */
   MdlrefDW_YawRateCompensation_T YawRateCompensation_Primary_InstanceData;   /* '<S1>/YawRateCompensation_Primary' */
   MdlrefDW_YawRateCompensation_T YawRateCompensation_Secondary_InstanceData; /* '<S1>/YawRateCompensation_Secondary' */
   MdlrefDW_YawRateEstimationUsingSteeringWheelAngle_T
      YawRateEstimationUsingSteeringWheelAngle_InstanceData;  /* '<S1>/YawRateEstimationUsingSteeringWheelAngle' */
   MdlrefDW_Yaw_Rate_Rationality_Check_T Model2_InstanceData; /* '<S1>/Model2' */
   real_T diff_num[8];                                        /* '<S97>/FindDifferentiatorCoeff' */
   real_T diff_denom[8];                                      /* '<S97>/FindDifferentiatorCoeff' */
   real_T filter_discrete_num[5];                             /* '<S89>/FindFilterCoeff' */
   real_T filter_discrete_denom[5];                           /* '<S89>/FindFilterCoeff' */
   real_T diff_num_k[8];                                      /* '<S88>/FindDifferentiatorCoeff' */
   real_T diff_denom_d[8];                                    /* '<S88>/FindDifferentiatorCoeff' */
   real_T filter_discrete_num_j[5];                           /* '<S80>/FindFilterCoeff' */
   real_T filter_discrete_denom_g[5];                         /* '<S80>/FindFilterCoeff' */
   real_T diff_num_p[8];                                      /* '<S79>/FindDifferentiatorCoeff' */
   real_T diff_denom_m[8];                                    /* '<S79>/FindDifferentiatorCoeff' */
   real_T LowPassFilter_states[4];                            /* '<S81>/LowPass Filter' */
   real_T LowPassFilter_states_d[4];                          /* '<S90>/LowPass Filter' */
   real_T Differentiator_states[7];                           /* '<S100>/Differentiator' */
   real_T Differentiator_states_p[7];                         /* '<S82>/Differentiator' */
   real_T Differentiator_states_k[7];                         /* '<S91>/Differentiator' */
   real32_T diff_num_d[4];                                    /* '<S299>/MATLAB Function' */
   real32_T diff_denom_p[4];                                  /* '<S299>/MATLAB Function' */
   real32_T diff_num_e[4];                                    /* '<S287>/MATLAB Function' */
   real32_T diff_denom_dh[4];                                 /* '<S287>/MATLAB Function' */
   real32_T diff_num_n[4];                                    /* '<S275>/MATLAB Function' */
   real32_T diff_denom_o[4];                                  /* '<S275>/MATLAB Function' */
   real32_T diff_num_a[4];                                    /* '<S262>/MATLAB Function' */
   real32_T diff_denom_g[4];                                  /* '<S262>/MATLAB Function' */
   real32_T diff_num_h[4];                                    /* '<S250>/MATLAB Function' */
   real32_T diff_denom_b[4];                                  /* '<S250>/MATLAB Function' */
   real32_T diff_num_f[4];                                    /* '<S238>/MATLAB Function' */
   real32_T diff_denom_gf[4];                                 /* '<S238>/MATLAB Function' */
   real32_T diff_num_es[4];                                   /* '<S226>/MATLAB Function' */
   real32_T diff_denom_oi[4];                                 /* '<S226>/MATLAB Function' */
   real32_T diff_num_kn[4];                                   /* '<S214>/MATLAB Function' */
   real32_T diff_denom_e[4];                                  /* '<S214>/MATLAB Function' */
   real32_T diff_num_b[4];                                    /* '<S166>/MATLAB Function' */
   real32_T diff_denom_e0[4];                                 /* '<S166>/MATLAB Function' */
   real32_T diff_num_el[4];                                   /* '<S154>/MATLAB Function' */
   real32_T diff_denom_l[4];                                  /* '<S154>/MATLAB Function' */
   real32_T diff_num_g[4];                                    /* '<S142>/MATLAB Function' */
   real32_T diff_denom_gd[4];                                 /* '<S142>/MATLAB Function' */
   real32_T diff_num_gb[4];                                   /* '<S130>/MATLAB Function' */
   real32_T diff_denom_ez[4];                                 /* '<S130>/MATLAB Function' */
   real32_T diff_num_knm[4];                                  /* '<S118>/MATLAB Function' */
   real32_T diff_denom_k[4];                                  /* '<S118>/MATLAB Function' */
   real32_T diff_num_m[4];                                    /* '<S106>/MATLAB Function' */
   real32_T diff_denom_kv[4];                                 /* '<S106>/MATLAB Function' */
   real32_T DiscreteFilter_states[3];                         /* '<S27>/Discrete Filter' */
   real32_T DiscreteFilter_states_e[3];                       /* '<S28>/Discrete Filter' */
   real32_T DiscreteFilter_states_o[3];                       /* '<S29>/Discrete Filter' */
   real32_T DiscreteFilter_states_p[3];                       /* '<S8>/Discrete Filter' */
   real32_T DiscreteFilter_states_o1[3];                      /* '<S9>/Discrete Filter' */
   real32_T DiscreteFilter_states_ej[3];                      /* '<S30>/Discrete Filter' */
   real32_T DiscreteFilter_states_k[3];                       /* '<S31>/Discrete Filter' */
   real32_T DiscreteFilter_states_g[3];                       /* '<S34>/Discrete Filter' */
   real32_T DiscreteFilter_states_l[3];                       /* '<S35>/Discrete Filter' */
   real32_T DiscreteFilter_states_or[3];                      /* '<S10>/Discrete Filter' */
   real32_T DiscreteFilter_states_c[3];                       /* '<S11>/Discrete Filter' */
   real32_T DiscreteFilter_states_n[3];                       /* '<S12>/Discrete Filter' */
   real32_T DiscreteFilter_states_gy[3];                      /* '<S13>/Discrete Filter' */
   real32_T DiscreteFilter_states_ou[3];                      /* '<S33>/Discrete Filter' */
   real32_T selected_signal;                                  /* '<S1>/RawSpeedArbitration' */
   real32_T selected_signal_a;                                /* '<S1>/RawLateralAccelerationArbitration' */
   real32_T selected_signal_b;                                /* '<S1>/RawSteeringAngleArbitration' */
   real32_T SWA_Bias_deg_Conv_Out;                            /* '<S1>/Steering Wheel Angle Bias Estimation' */
   real32_T CompSteeringAngle_deg_SAE;                        /* '<S1>/Steering Wheel Angle Bias Estimation' */
   real32_T selected_signal_ag;                               /* '<S1>/Model1' */
   real32_T selected_signal_d;                                /* '<S1>/RawLongitudinalAccelerationArbitration' */
   real32_T selected_signal_bf;                               /* '<S1>/CompensatedYawRateArbitration' */
   real32_T Yaw_Rate_Compensated_Filtered;                    /* '<S14>/Merge' */
   real32_T imu_signal_bias;                                  /* '<S1>/RollRateCompensation' */
   real32_T imu_signal_bias_m;                                /* '<S1>/PitchRateCompensation' */
   real32_T Timer;                                            /* '<S1>/Model6' */
   real32_T Delay_DSTATE;                                     /* '<S46>/Delay' */
   real32_T Delay_DSTATE_b;                                   /* '<S47>/Delay' */
   real32_T Delay_DSTATE_d;                                   /* '<S48>/Delay' */
   real32_T Delay_DSTATE_k;                                   /* '<S49>/Delay' */
   real32_T Delay_DSTATE_c;                                   /* '<S45>/Delay' */
   real32_T UnitDelay1_DSTATE;                                /* '<S1>/Unit Delay1' */
   real32_T Delay_DSTATE_i;                                   /* '<S50>/Delay' */
   real32_T Delay_DSTATE_j;                                   /* '<S51>/Delay' */
   real32_T Delay_DSTATE_f;                                   /* '<S40>/Delay' */
   real32_T Delay_DSTATE_l;                                   /* '<S41>/Delay' */
   real32_T Delay_DSTATE_o;                                   /* '<S52>/Delay' */
   real32_T Delay_DSTATE_lm;                                  /* '<S53>/Delay' */
   real32_T UnitDelay_DSTATE;                                 /* '<S36>/Unit Delay' */
   real32_T UnitDelay1_DSTATE_k;                              /* '<S36>/Unit Delay1' */
   real32_T Delay_DSTATE_ji;                                  /* '<S44>/Delay' */
   real32_T Delay_DSTATE_jv;                                  /* '<S43>/Delay' */
   real32_T Delay_DSTATE_do;                                  /* '<S42>/Delay' */
   struct
   {
      uint_T is_c3_VSE_Master_Model_WL_L2P:2;        /* '<S32>/Chart' */
      uint_T is_active_c3_VSE_Master_Model_WL_L2P:1; /* '<S32>/Chart' */
      uint_T f_initialize_vse:1;                     /* '<S32>/Chart' */
   } bitsForTID0;

   selected_signal_number_T selected_signal_number;                 /* '<S1>/RawSpeedArbitration' */
   selected_signal_number_T selected_signal_number_e;               /* '<S1>/RawLateralAccelerationArbitration' */
   selected_signal_number_T selected_signal_number_m;               /* '<S1>/RawSteeringAngleArbitration' */
   selected_signal_number_T selected_signal_number_p;               /* '<S1>/Model1' */
   selected_signal_number_T selected_signal_number_g;               /* '<S1>/RawLongitudinalAccelerationArbitration' */
   selected_signal_number_T selected_signal_number_k;               /* '<S1>/CompensatedYawRateArbitration' */
   enum_quality_factor_T selected_signal_qf;                        /* '<S1>/RawSpeedArbitration' */
   enum_quality_factor_T selected_signal_qf_g;                      /* '<S1>/RawLateralAccelerationArbitration' */
   enum_quality_factor_T selected_signal_qf_i;                      /* '<S1>/RawSteeringAngleArbitration' */
   enum_quality_factor_T CompSteeringAngle_QF;                      /* '<S1>/Steering Wheel Angle Bias Estimation' */
   enum_quality_factor_T selected_signal_qf_h;                      /* '<S1>/Model1' */
   enum_quality_factor_T selected_signal_qf_iq;                     /* '<S1>/RawLongitudinalAccelerationArbitration' */
   enum_quality_factor_T selected_signal_qf_k;                      /* '<S1>/CompensatedYawRateArbitration' */
   enum_quality_factor_T Yaw_Rate_Compensated_QF;                   /* '<S14>/Merge' */
   enum_quality_factor_T VeVSE_mps_WhlOdoVehSpeedOverGroundQF;      /* '<S36>/Model6' */
   enum_quality_factor_T VeVSE_WhlOdoVehAccelQF;                    /* '<S36>/Model6' */
   enum_quality_factor_T VeVSE_mps_WhlOdoVehSpeedOverGroundQF_h;    /* '<S36>/Model5' */
   enum_quality_factor_T VeVSE_WhlOdoVehAccelQF_m;                  /* '<S36>/Model5' */
   enum_quality_factor_T VsVSE_EstimatedGradeQF;                    /* '<S1>/Model3' */
   enum_accuracy_level_wheelodo_T VeVSE_WhlOdoVehLongSpdAccLvl;     /* '<S36>/Model6' */
   enum_accuracy_level_wheelodo_T VeVSE_WhlOdoVehLongAccelAccLvl;   /* '<S36>/Model6' */
   enum_accuracy_level_wheelodo_T VeVSE_WhlOdoVehLongSpdAccLvl_c;   /* '<S36>/Model5' */
   enum_accuracy_level_wheelodo_T VeVSE_WhlOdoVehLongAccelAccLvl_n; /* '<S36>/Model5' */
   enum_accuracy_level_T VsVSE_EstimatedGradeAccuracy;              /* '<S1>/Model3' */
   enum_Presence_Status Trailer_Detection;                          /* '<S1>/Model' */
   enum_quality_factor_T UnitDelay_DSTATE_c;                        /* '<S1>/Unit Delay' */
   boolean_T f_SWA_Bias_deg_Conv_out;                               /* '<S1>/Steering Wheel Angle Bias Estimation' */
   boolean_T f_SWA_Bias_deg_Conv_internal;                          /* '<S1>/Steering Wheel Angle Bias Estimation' */
   boolean_T VsVSE_b_ASRStatus;                                     /* '<S36>/Model6' */
   boolean_T f_stop_imu_signal_bias_converged;                      /* '<S1>/RollRateCompensation' */
   boolean_T f_stop_imu_signal_bias_converged_j;                    /* '<S1>/PitchRateCompensation' */
   boolean_T Model2;                                                /* '<S1>/Model2' */
   boolean_T f_yaw_rate_stop_bias_converged_atleast_once;           /* '<S14>/Merge' */
   boolean_T f_initialize;                                          /* '<S35>/Initialization_Trigger' */
   boolean_T f_initialize_j;                                        /* '<S34>/Initialization_Trigger' */
   boolean_T f_initialize_i;                                        /* '<S33>/Initialization_Trigger' */
   boolean_T f_initialize_iv;                                       /* '<S31>/Initialization_Trigger' */
   boolean_T f_initialize_ia;                                       /* '<S30>/Initialization_Trigger' */
   boolean_T f_initialize_k;                                        /* '<S29>/Initialization_Trigger' */
   boolean_T f_initialize_g;                                        /* '<S28>/Initialization_Trigger' */
   boolean_T f_initialize_gm;                                       /* '<S27>/Initialization_Trigger' */
   boolean_T f_initialize_k1;                                       /* '<S13>/Initialization_Trigger' */
   boolean_T f_initialize_m;                                        /* '<S12>/Initialization_Trigger' */
   boolean_T f_initialize_io;                                       /* '<S11>/Initialization_Trigger' */
   boolean_T f_initialize_mm;                                       /* '<S10>/Initialization_Trigger' */
   boolean_T f_initialize_p;                                        /* '<S9>/Initialization_Trigger' */
   boolean_T f_initialize_b;                                        /* '<S8>/Initialization_Trigger' */
   boolean_T f_initialize_JerkEstimation;                           /* '<S7>/Chart' */
   boolean_T f_initialize_JerkEstimation_l;                         /* '<S6>/Chart' */
   boolean_T f_initialize_JerkEstimation_h;                         /* '<S5>/Chart' */
   boolean_T UnitDelay2_DSTATE;                                     /* '<S1>/Unit Delay2' */
} DW_VSE_Master_Model_WL_L2P_T;

/* Invariant block signals (default storage) */
typedef struct
{
   const enum_quality_factor_T DataTypeConversion4; /* '<S1>/Data Type Conversion4' */
} ConstB_VSE_Master_Model_WL_L2P_T;

/* Constant parameters (default storage) */
typedef struct
{
   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant13'
    *   '<S1>/Constant15'
    *   '<S1>/Constant2'
    *   '<S1>/Constant26'
    *   '<S1>/Constant28'
    *   '<S1>/Constant32'
    *   '<S1>/Constant35'
    *   '<S1>/Constant5'
    *   '<S1>/Unit Delay1'
    *   '<S4>/Constant'
    *   '<S4>/Constant1'
    *   '<S4>/Constant10'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S15>/Constant'
    *   '<S15>/Constant1'
    *   '<S16>/Constant'
    *   '<S16>/Constant1'
    *   '<S17>/Constant1'
    *   '<S18>/Constant1'
    *   '<S19>/Constant1'
    *   '<S20>/Constant1'
    *   '<S21>/Constant1'
    *   '<S22>/Constant1'
    *   '<S23>/Constant1'
    *   '<S24>/Constant1'
    *   '<S25>/Constant1'
    *   '<S36>/Unit Delay'
    *   '<S36>/Unit Delay1'
    *   '<S40>/Delay'
    *   '<S41>/Delay'
    *   '<S42>/Delay'
    *   '<S43>/Delay'
    *   '<S44>/Delay'
    *   '<S45>/Delay'
    *   '<S46>/Delay'
    *   '<S47>/Delay'
    *   '<S48>/Delay'
    *   '<S49>/Delay'
    *   '<S50>/Delay'
    *   '<S51>/Delay'
    *   '<S52>/Delay'
    *   '<S53>/Delay'
    *   '<S56>/k_rws_angle_not_activated_rad'
    *   '<S57>/k_rws_angle_speed_not_activated_rps'
    *   '<S58>/k_rws_angle_not_activated_rad'
    *   '<S63>/k_rws_angle_speed_not_activated_rps'
    *   '<S106>/diff_num'
    *   '<S106>/diff_den'
    *   '<S118>/diff_num'
    *   '<S118>/diff_den'
    *   '<S130>/diff_num'
    *   '<S130>/diff_den'
    *   '<S142>/diff_num'
    *   '<S142>/diff_den'
    *   '<S154>/diff_num'
    *   '<S154>/diff_den'
    *   '<S166>/diff_num'
    *   '<S166>/diff_den'
    *   '<S214>/diff_num'
    *   '<S214>/diff_den'
    *   '<S216>/Constant'
    *   '<S226>/diff_num'
    *   '<S226>/diff_den'
    *   '<S228>/Constant'
    *   '<S238>/diff_num'
    *   '<S238>/diff_den'
    *   '<S240>/Constant'
    *   '<S250>/diff_num'
    *   '<S250>/diff_den'
    *   '<S262>/diff_num'
    *   '<S262>/diff_den'
    *   '<S275>/diff_num'
    *   '<S275>/diff_den'
    *   '<S287>/diff_num'
    *   '<S287>/diff_den'
    *   '<S299>/diff_num'
    *   '<S299>/diff_den'
    */
   real32_T pooled11;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant29'
    *   '<S1>/default_gps_comp_factor'
    *   '<S26>/Constant1'
    */
   real32_T pooled18;

   /* Pooled Parameter (Expression: SystemExecutionTime)
    * Referenced by:
    *   '<S1>/Constant43'
    *   '<S1>/Constant44'
    */
   real32_T pooled29;

   /* Computed Parameter: VsVCAN_nu_CountsPerRevol_Value
    * Referenced by: '<S1>/VsVCAN_nu_CountsPerRevol'
    */
   real32_T VsVCAN_nu_CountsPerRevol_Value;

   /* Computed Parameter: Constant40_Value
    * Referenced by: '<S1>/Constant40'
    */
   real32_T Constant40_Value;

   /* Expression: k_speed_acceptable_abs_diff_mps
    * Referenced by: '<S1>/Constant'
    */
   real32_T Constant_Value;

   /* Computed Parameter: Constant1_Value
    * Referenced by: '<S1>/Constant1'
    */
   real32_T Constant1_Value;

   /* Expression: k_yawrate_acceptable_abs_diff_IfStandstillBiasIsNotLearned_rps
    * Referenced by: '<S1>/Constant36'
    */
   real32_T Constant36_Value;

   /* Computed Parameter: Constant34_Value
    * Referenced by: '<S1>/Constant34'
    */
   real32_T Constant34_Value;

   /* Expression: k_yawrate_acceptable_abs_diff_rps
    * Referenced by: '<S1>/Constant20'
    */
   real32_T Constant20_Value;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant25'
    *   '<S1>/Constant27'
    *   '<S1>/Constant31'
    */
   real32_T pooled30;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant14'
    *   '<S1>/Constant22'
    */
   real32_T pooled31;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant11'
    *   '<S1>/Constant21'
    *   '<S1>/Constant23'
    *   '<S1>/Constant30'
    *   '<S1>/Constant33'
    *   '<S1>/Constant4'
    *   '<S1>/Constant41'
    *   '<S1>/Constant42'
    *   '<S1>/default_f_use_gps_comp_factor'
    *   '<S1>/Unit Delay2'
    *   '<S4>/Constant4'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    *   '<S14>/Merge'
    */
   boolean_T pooled35;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Unit Delay'
    *   '<S4>/Constant2'
    *   '<S4>/Constant3'
    *   '<S4>/Constant6'
    *   '<S59>/validity_default'
    *   '<S60>/validity_default'
    *   '<S61>/validity_default'
    *   '<S62>/validity_default'
    *   '<S105>/Constant3'
    *   '<S117>/Constant3'
    *   '<S129>/Constant3'
    *   '<S141>/Constant3'
    *   '<S153>/Constant3'
    *   '<S165>/Constant3'
    *   '<S213>/Constant3'
    *   '<S225>/Constant3'
    *   '<S237>/Constant3'
    *   '<S249>/Constant3'
    *   '<S261>/Constant3'
    *   '<S274>/Constant3'
    *   '<S286>/Constant3'
    *   '<S298>/Constant3'
    *   '<S64>/Constant'
    *   '<S65>/Constant'
    *   '<S66>/Constant'
    *   '<S67>/Constant'
    *   '<S68>/Constant'
    *   '<S69>/Constant'
    *   '<S70>/Constant'
    *   '<S71>/Constant'
    *   '<S72>/Constant'
    *   '<S73>/Constant'
    *   '<S74>/Constant'
    *   '<S75>/Constant'
    *   '<S76>/Constant'
    *   '<S77>/Constant'
    */
   enum_quality_factor_T pooled36;

   /* Pooled Parameter (Mixed Expressions)
    * Referenced by:
    *   '<S1>/Constant12'
    *   '<S105>/Constant'
    *   '<S117>/Constant'
    *   '<S129>/Constant'
    *   '<S141>/Constant'
    *   '<S153>/Constant'
    *   '<S165>/Constant'
    *   '<S180>/Constant'
    *   '<S183>/Constant'
    *   '<S186>/Constant'
    *   '<S189>/Constant'
    *   '<S192>/Constant'
    *   '<S195>/Constant'
    *   '<S198>/Constant'
    *   '<S201>/Constant'
    *   '<S204>/Constant'
    *   '<S207>/Constant'
    *   '<S210>/Constant'
    *   '<S213>/Constant'
    *   '<S225>/Constant'
    *   '<S237>/Constant'
    *   '<S249>/Constant'
    *   '<S261>/Constant'
    *   '<S274>/Constant'
    *   '<S286>/Constant'
    *   '<S298>/Constant'
    *   '<S110>/Constant'
    *   '<S122>/Constant'
    *   '<S134>/Constant'
    *   '<S146>/Constant'
    *   '<S158>/Constant'
    *   '<S170>/Constant'
    *   '<S218>/Constant'
    *   '<S230>/Constant'
    *   '<S242>/Constant'
    *   '<S254>/Constant'
    *   '<S266>/Constant'
    *   '<S279>/Constant'
    *   '<S291>/Constant'
    *   '<S303>/Constant'
    */
   enum_quality_factor_T pooled37;
} ConstP_VSE_Master_Model_WL_L2P_T;

/* Real-time Model Data Structure */
struct tag_RTM_VSE_Master_Model_WL_L2P_T
{
   DW_VSE_Master_Model_WL_L2P_T *dwork;
};

extern const ConstB_VSE_Master_Model_WL_L2P_T VSE_Master_Model_WL_L2P_ConstB; /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_VSE_Master_Model_WL_L2P_T VSE_Master_Model_WL_L2P_ConstP;

/* Model entry point functions */
extern void VSE_Master_Model_WL_L2P_initialize(RT_MODEL_VSE_Master_Model_WL_L2P_T *const VSE_Master_Model_WL_L2P_M);
extern void VSE_Master_Model_WL_L2P_step(
   RT_MODEL_VSE_Master_Model_WL_L2P_T *const VSE_Master_Model_WL_L2P_M,
   VnetInVehicleStateEstimator *VSE_Master_Model_WL_L2P_U_VnetInVehicleStateEstimator_b,
   Tracker_VSE *VSE_Master_Model_WL_L2P_U_Tracker_VSE_m, Vehicle_Parameters *VSE_Master_Model_WL_L2P_U_Vehicle_Parameters_j,
   uint64_T VSE_Master_Model_WL_L2P_U_System_Time_Micro_Sec, LAST_KEY_CYCLE *VSE_Master_Model_WL_L2P_U_LAST_KEY_CYCLE_k,
   Tracker_VSE_Trailer_Signals *VSE_Master_Model_WL_L2P_U_Tracker_VSE_Trailer_Signals_a,
   AptivCfg *VSE_Master_Model_WL_L2P_U_AptivCfg_p, VSE_OUT *VSE_Master_Model_WL_L2P_Y_VSE_Output,
   VSE_RESIM_T *VSE_Master_Model_WL_L2P_Y_VSE_Resim_Output, VSE_OUT_Trailer *VSE_Master_Model_WL_L2P_Y_VSE_Output_Trailer);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Constant7' : Unused code path elimination
 * Block '<S4>/Constant8' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Unused code path elimination
 * Block '<S99>/Abs' : Unused code path elimination
 * Block '<S103>/Compare' : Unused code path elimination
 * Block '<S103>/Constant' : Unused code path elimination
 * Block '<S99>/Constant' : Unused code path elimination
 * Block '<S99>/Data Type Conversion' : Unused code path elimination
 * Block '<S99>/LowPass Filter' : Unused code path elimination
 * Block '<S99>/Switch' : Unused code path elimination
 * Block '<S1>/Gain10' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain6' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain7' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain8' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain9' : Eliminated nontunable gain of 1
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VSE_Master_Model_WL_L2P'
 * '<S1>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model'
 * '<S2>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/CheckRationalityCheckApplicability'
 * '<S3>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Degrees to Radians'
 * '<S4>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper'
 * '<S5>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3'
 * '<S6>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4'
 * '<S7>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5'
 * '<S8>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary'
 * '<S9>'   : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary'
 * '<S10>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary'
 * '<S11>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary'
 * '<S12>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck'
 * '<S13>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck'
 * '<S14>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SelectCompensatedYawRateSignals'
 * '<S15>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompSpeed_Fault_Based_On_QF'
 * '<S16>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompYawRate_Fault_Based_On_QF'
 * '<S17>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLatAccel_Fault_Based_On_QF'
 * '<S18>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLongAccel_Fault_Based_On_QF'
 * '<S19>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawSpeed_Fault_Based_On_QF'
 * '<S20>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawYawRate_Fault_Based_On_QF'
 * '<S21>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_RawSteering_Fault_Based_On_QF'
 * '<S22>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLatAccel_Fault_Based_On_QF'
 * '<S23>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLongAccel_Fault_Based_On_QF'
 * '<S24>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawSpeed_Fault_Based_On_QF'
 * '<S25>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawYawRate_Fault_Based_On_QF'
 * '<S26>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Signed_Speed_Calculation'
 * '<S27>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary'
 * '<S28>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary'
 * '<S29>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary'
 * '<S30>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary'
 * '<S31>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary'
 * '<S32>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VehicleIndexCalculation'
 * '<S33>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck'
 * '<S34>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary'
 * '<S35>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary'
 * '<S36>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/wheel_odometry'
 * '<S37>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/CheckRationalityCheckApplicability/Compare To Constant'
 * '<S38>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Compare To Constant'
 * '<S39>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Compare To Constant1'
 * '<S40>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based'
 * '<S41>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based1'
 * '<S42>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based10'
 * '<S43>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based11'
 * '<S44>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based12'
 * '<S45>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based13'
 * '<S46>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based2'
 * '<S47>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based3'
 * '<S48>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based4'
 * '<S49>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based5'
 * '<S50>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based6'
 * '<S51>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based7'
 * '<S52>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based8'
 * '<S53>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based9'
 * '<S54>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/MATLAB Function'
 * '<S55>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/MATLAB Function1'
 * '<S56>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rear_rwa_arbitration'
 * '<S57>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rear_rwa_speed_arbitration'
 * '<S58>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_arbitration'
 * '<S59>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_arbitration1'
 * '<S60>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_arbitration2'
 * '<S61>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_arbitration3'
 * '<S62>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_arbitration4'
 * '<S63>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/rwa_speed_arbitration'
 * '<S64>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based/Compare To Constant'
 * '<S65>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based1/Compare To Constant'
 * '<S66>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based10/Compare To Constant'
 * '<S67>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based11/Compare To Constant'
 * '<S68>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based12/Compare To Constant'
 * '<S69>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based13/Compare To Constant'
 * '<S70>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based2/Compare To Constant'
 * '<S71>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based3/Compare To Constant'
 * '<S72>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based4/Compare To Constant'
 * '<S73>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based5/Compare To Constant'
 * '<S74>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based6/Compare To Constant'
 * '<S75>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based7/Compare To Constant'
 * '<S76>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based8/Compare To Constant'
 * '<S77>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/InputWrapper/Hold_Last_Value_Condition_Based9/Compare To Constant'
 * '<S78>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Chart'
 * '<S79>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Differentiator Generator'
 * '<S80>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Filter Generator'
 * '<S81>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Lateral Acceleration Filter'
 * '<S82>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Lateral Jerk Estimator'
 * '<S83>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Differentiator Generator/FindDifferentiatorCoeff'
 * '<S84>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Filter Generator/FindFilterCoeff'
 * '<S85>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Lateral Acceleration Filter/Compare To Constant'
 * '<S86>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator3/Lateral Jerk Estimator/Compare To Constant'
 * '<S87>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Chart'
 * '<S88>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Differentiator Generator'
 * '<S89>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Filter Generator'
 * '<S90>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Lateral Acceleration Filter'
 * '<S91>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Lateral Jerk Estimator'
 * '<S92>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Differentiator Generator/FindDifferentiatorCoeff'
 * '<S93>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Filter Generator/FindFilterCoeff'
 * '<S94>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Lateral Acceleration Filter/Compare To Constant'
 * '<S95>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator4/Lateral Jerk Estimator/Compare To Constant'
 * '<S96>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Chart'
 * '<S97>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Differentiator Generator'
 * '<S98>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Filter Generator'
 * '<S99>'  : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Lateral Acceleration Filter'
 * '<S100>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Lateral Jerk Estimator'
 * '<S101>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Differentiator Generator/FindDifferentiatorCoeff'
 * '<S102>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Filter Generator/FindFilterCoeff'
 * '<S103>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Lateral Acceleration Filter/Compare To Constant'
 * '<S104>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Jerk_Estimator5/Lateral Jerk Estimator/Compare To Constant'
 * '<S105>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor'
 * '<S106>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/Initialization'
 * '<S107>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/Initialization_Trigger'
 * '<S108>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/SignalRangeCheck'
 * '<S109>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/SignalRateCheck'
 * '<S110>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/Compare
 * To Constant'
 * '<S111>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem'
 * '<S112>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem1'
 * '<S113>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem2'
 * '<S114>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem3'
 * '<S115>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem4'
 * '<S116>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Primary/Initialization/MATLAB
 * Function'
 * '<S117>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor'
 * '<S118>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/Initialization'
 * '<S119>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/Initialization_Trigger'
 * '<S120>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/SignalRangeCheck'
 * '<S121>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/SignalRateCheck'
 * '<S122>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/Compare
 * To Constant'
 * '<S123>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem'
 * '<S124>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S125>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem2'
 * '<S126>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S127>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem4'
 * '<S128>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LateralAcceleration_PlausibilityCheck_Secondary/Initialization/MATLAB
 * Function'
 * '<S129>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor'
 * '<S130>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/Initialization'
 * '<S131>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/Initialization_Trigger'
 * '<S132>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/SignalRangeCheck'
 * '<S133>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/SignalRateCheck'
 * '<S134>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/Compare To
 * Constant'
 * '<S135>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If
 * Action Subsystem'
 * '<S136>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S137>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If
 * Action Subsystem2'
 * '<S138>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S139>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/DecideQualityFactor/If
 * Action Subsystem4'
 * '<S140>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Primary/Initialization/MATLAB
 * Function'
 * '<S141>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor'
 * '<S142>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/Initialization'
 * '<S143>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/Initialization_Trigger'
 * '<S144>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/SignalRangeCheck'
 * '<S145>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/SignalRateCheck'
 * '<S146>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/Compare To
 * Constant'
 * '<S147>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem'
 * '<S148>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem1'
 * '<S149>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem2'
 * '<S150>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem3'
 * '<S151>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/DecideQualityFactor/If
 * Action Subsystem4'
 * '<S152>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/LongitudinalAcceleration_PlausibilityCheck_Secondary/Initialization/MATLAB
 * Function'
 * '<S153>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor'
 * '<S154>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/Initialization'
 * '<S155>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/Initialization_Trigger'
 * '<S156>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/SignalRangeCheck'
 * '<S157>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/SignalRateCheck'
 * '<S158>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/Compare To Constant'
 * '<S159>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem'
 * '<S160>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem1'
 * '<S161>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem2'
 * '<S162>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem3'
 * '<S163>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem4'
 * '<S164>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/PitchRate_PlausibilityCheck/Initialization/MATLAB Function'
 * '<S165>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor'
 * '<S166>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/Initialization'
 * '<S167>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/Initialization_Trigger'
 * '<S168>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/SignalRangeCheck'
 * '<S169>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/SignalRateCheck'
 * '<S170>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/Compare To Constant'
 * '<S171>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem'
 * '<S172>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem1'
 * '<S173>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem2'
 * '<S174>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem3'
 * '<S175>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/DecideQualityFactor/If Action Subsystem4'
 * '<S176>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/RollRate_PlausibilityCheck/Initialization/MATLAB Function'
 * '<S177>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SelectCompensatedYawRateSignals/Compare To Constant'
 * '<S178>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SelectCompensatedYawRateSignals/If Action Subsystem'
 * '<S179>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SelectCompensatedYawRateSignals/If Action Subsystem1'
 * '<S180>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompSpeed_Fault_Based_On_QF/Compare To Constant'
 * '<S181>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S182>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S183>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompYawRate_Fault_Based_On_QF/Compare To Constant'
 * '<S184>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S185>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_CompYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S186>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLatAccel_Fault_Based_On_QF/Compare To Constant'
 * '<S187>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLatAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S188>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLatAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S189>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLongAccel_Fault_Based_On_QF/Compare To Constant'
 * '<S190>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLongAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S191>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawLongAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S192>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawSpeed_Fault_Based_On_QF/Compare To Constant'
 * '<S193>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S194>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S195>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawYawRate_Fault_Based_On_QF/Compare To Constant'
 * '<S196>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S197>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_PrimaryRawYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB Function'
 * '<S198>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_RawSteering_Fault_Based_On_QF/Compare To Constant'
 * '<S199>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_RawSteering_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S200>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_RawSteering_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S201>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLatAccel_Fault_Based_On_QF/Compare To Constant'
 * '<S202>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLatAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S203>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLatAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S204>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLongAccel_Fault_Based_On_QF/Compare To Constant'
 * '<S205>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLongAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S206>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawLongAccel_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S207>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawSpeed_Fault_Based_On_QF/Compare To Constant'
 * '<S208>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S209>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawSpeed_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB Function'
 * '<S210>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawYawRate_Fault_Based_On_QF/Compare To Constant'
 * '<S211>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block'
 * '<S212>' :
 * 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Set_SecondaryRawYawRate_Fault_Based_On_QF/Maturation_DeMaturation_Block/MATLAB
 * Function'
 * '<S213>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor'
 * '<S214>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/Initialization'
 * '<S215>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/Initialization_Trigger'
 * '<S216>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/SignalRangeCheck'
 * '<S217>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/SignalRateCheck'
 * '<S218>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/Compare To Constant'
 * '<S219>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem'
 * '<S220>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem1'
 * '<S221>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem2'
 * '<S222>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem3'
 * '<S223>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem4'
 * '<S224>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Primary/Initialization/MATLAB Function'
 * '<S225>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor'
 * '<S226>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/Initialization'
 * '<S227>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/Initialization_Trigger'
 * '<S228>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/SignalRangeCheck'
 * '<S229>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/SignalRateCheck'
 * '<S230>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/Compare To Constant'
 * '<S231>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/If Action Subsystem'
 * '<S232>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/If Action Subsystem1'
 * '<S233>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/If Action Subsystem2'
 * '<S234>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/If Action Subsystem3'
 * '<S235>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/DecideQualityFactor/If Action Subsystem4'
 * '<S236>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Secondary/Initialization/MATLAB Function'
 * '<S237>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor'
 * '<S238>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/Initialization'
 * '<S239>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/Initialization_Trigger'
 * '<S240>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/SignalRangeCheck'
 * '<S241>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/SignalRateCheck'
 * '<S242>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/Compare To Constant'
 * '<S243>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/If Action Subsystem'
 * '<S244>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/If Action Subsystem1'
 * '<S245>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/If Action Subsystem2'
 * '<S246>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/If Action Subsystem3'
 * '<S247>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/DecideQualityFactor/If Action Subsystem4'
 * '<S248>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/Speed_PlausibilityCheck_Tertiary/Initialization/MATLAB Function'
 * '<S249>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor'
 * '<S250>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/Initialization'
 * '<S251>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/Initialization_Trigger'
 * '<S252>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/SignalRangeCheck'
 * '<S253>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/SignalRateCheck'
 * '<S254>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/Compare To
 * Constant'
 * '<S255>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem'
 * '<S256>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem1'
 * '<S257>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem2'
 * '<S258>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem3'
 * '<S259>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/DecideQualityFactor/If Action
 * Subsystem4'
 * '<S260>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Primary/Initialization/MATLAB Function'
 * '<S261>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor'
 * '<S262>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/Initialization'
 * '<S263>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/Initialization_Trigger'
 * '<S264>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/SignalRangeCheck'
 * '<S265>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/SignalRateCheck'
 * '<S266>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/Compare To
 * Constant'
 * '<S267>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem'
 * '<S268>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem1'
 * '<S269>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem2'
 * '<S270>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem3'
 * '<S271>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem4'
 * '<S272>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/SteeringWhlAngle_PlausibilityCheck_Secondary/Initialization/MATLAB
 * Function'
 * '<S273>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VehicleIndexCalculation/Chart'
 * '<S274>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor'
 * '<S275>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/Initialization'
 * '<S276>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/Initialization_Trigger'
 * '<S277>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/SignalRangeCheck'
 * '<S278>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/SignalRateCheck'
 * '<S279>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/Compare To
 * Constant'
 * '<S280>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/If Action
 * Subsystem'
 * '<S281>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/If Action
 * Subsystem1'
 * '<S282>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/If Action
 * Subsystem2'
 * '<S283>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/If Action
 * Subsystem3'
 * '<S284>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/DecideQualityFactor/If Action
 * Subsystem4'
 * '<S285>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/VerticalAcceleration_PlausibilityCheck/Initialization/MATLAB Function'
 * '<S286>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor'
 * '<S287>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/Initialization'
 * '<S288>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/Initialization_Trigger'
 * '<S289>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/SignalRangeCheck'
 * '<S290>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/SignalRateCheck'
 * '<S291>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/Compare To Constant'
 * '<S292>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem'
 * '<S293>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem1'
 * '<S294>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem2'
 * '<S295>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem3'
 * '<S296>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/DecideQualityFactor/If Action Subsystem4'
 * '<S297>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Primary/Initialization/MATLAB Function'
 * '<S298>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor'
 * '<S299>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/Initialization'
 * '<S300>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/Initialization_Trigger'
 * '<S301>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/SignalRangeCheck'
 * '<S302>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/SignalRateCheck'
 * '<S303>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/Compare To
 * Constant'
 * '<S304>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem'
 * '<S305>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem1'
 * '<S306>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem2'
 * '<S307>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem3'
 * '<S308>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/DecideQualityFactor/If Action
 * Subsystem4'
 * '<S309>' : 'VSE_Master_Model_WL_L2P/VSE_Master_Model/YawRate_PlausibilityCheck_Secondary/Initialization/MATLAB Function'
 */
#endif /* RTW_HEADER_VSE_Master_Model_WL_L2P_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
