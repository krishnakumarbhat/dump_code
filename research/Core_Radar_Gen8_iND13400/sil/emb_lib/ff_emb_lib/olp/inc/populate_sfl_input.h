#ifndef POPULATE_SFl_INPUT_H
#define POPULATE_SFl_INPUT_H

/* reuse header patch */
#ifndef uint32_T
typedef unsigned int uint32_T;
#endif
#ifndef uint16_T
typedef unsigned short uint16_T;
#endif
#ifndef uint8_T
typedef unsigned char uint8_T;
#endif
#ifndef int8_T
typedef signed char int8_T;
#endif
#ifndef int32_T
typedef int int32_T;
#endif

typedef struct SFL_F360_Output_Tag
{
   uint32_T unique_id;
   uint16_T trkID;
   uint8_T reducedID;
   uint8_T trk_fltr_type;
   float vcs_xposn;
   float vcs_yposn;
   float vcs_xvel;
   float vcs_yvel;
   float vcs_xaccel;
   float vcs_yaccel;
   float vcs_heading;
   float vcs_pointing;
   float speed;
   float curvature;
   float tang_accel;
   float existence_probability;
   float state_variance[6];
   float supplemental_state_covariance[3];
   float confidenceLevel;
   float time_since_measurement;
   float time_since_cluster_created;
   float time_since_track_updated;
   float time_since_stage_start;
   float len1;
   float len2;
   float wid1;
   float wid2;
   float accuracy_length;
   float accuracy_width;
   float probability_pedestrian;
   float probability_car;
   float probability_motorcycle;
   float probability_bicycle;
   float probability_truck;
   float probability_undet;
   uint16_T ndets;
   uint16_T num_reduced_dets;
   uint8_T status;
   uint8_T reference_point;
   uint8_T reducedStatus;
   int8_T init_scheme;
   uint8_T object_class;
   uint8_T f_crossing;
   uint8_T f_moving;
   uint8_T f_moveable;
   uint8_T f_oncoming;
   uint8_T f_vehicular_trk;
   uint8_T f_onguardrail;
   uint8_T f_fast_moving;
   uint8_T underdrivable_status;
   uint8_T current_msmt_type;
} SFL_F360_Output_T;

typedef struct SFL_Vehicle_Output_Tag
{
   int32_T vehicle_index;
   float global_time_sync_s;
   float timestamp_s;
   float align_angle_az_rad[1];
   float align_angle_el_rad[1];
   float speed_correction_factor;
   float world_x;
   float world_y;
   float heading;
   float delta_pointing;
   float delta_position_x;
   float delta_position_y;
   float speed;
   float acceleration;
   float curvature_rear;
   float vcs_speed;
   float vcs_lat_acceleration;
   float vcs_long_acceleration;
   float vcs_sideslip;
   float rear_cornering_compliance;
   float raw_speed;
   float steering_angle_rad;
   float raw_yaw_rate_rad;
   float dist_rear_axle_to_vcs_m;
   uint8_T prndl;
   uint8_T f_reverse_gear;
   uint8_T f_trailer_present;
} SFL_Vehicle_Output_T;

typedef struct
{
   SFL_F360_Output_T tracker_out[64];
   SFL_Vehicle_Output_T vehicle_out;
} SFL_IPC_T;

SFL_IPC_T *Get_SFL_Input_Ptr();
void Populate_SFL_Input();

#endif
