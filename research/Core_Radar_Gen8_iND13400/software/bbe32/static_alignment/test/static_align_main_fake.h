#ifndef STATIC_ALIGN_MAIN_FAKE_H
#define STATIC_ALIGN_MAIN_FAKE_H

#include "fff.h"
#include "ipc_data.h"

#ifndef SRA_NUMBER_OF_DETECTIONS
   #define SRA_NUMBER_OF_DETECTIONS (64U)
#endif

#ifndef typedef_sfa_mounting_loc_T
   #define typedef_sfa_mounting_loc_T
typedef unsigned char sfa_mounting_loc_T;
#endif /* typedef_sfa_mounting_loc_T */

#ifndef sfa_mounting_loc_T_constants
   #define sfa_mounting_loc_T_constants

   /* enum sfa_mounting_loc_T */
   #define SFA_ALIGN_MOUNTING_LEFT_FORWARD ((sfa_mounting_loc_T)0U)
   #define SFA_ALIGN_MOUNTING_LEFT_REAR    ((sfa_mounting_loc_T)24U)
   #define c_SFA_ALIGN_MOUNTING_CENTER_FOR ((sfa_mounting_loc_T)1U)
   #define SFA_ALIGN_MOUNTING_CENTER_REAR  ((sfa_mounting_loc_T)25U)
   #define c_SFA_ALIGN_MOUNTING_RIGHT_FORW ((sfa_mounting_loc_T)2U)
   #define SFA_ALIGN_MOUNTING_RIGHT_REAR   ((sfa_mounting_loc_T)26U)

#endif /* sfa_mounting_loc_T_constants */

enum SFA_Status_Tag
{
   SFA_INCOMPLETE                    = 255, /* Default value */
   SFA_PASS                          = 1,
   SFA_FAIL_SENSOR_FACING_UPWARDS    = 2,
   SFA_FAIL_SENSOR_FACING_DOWNWARDS  = 3,
   SFA_FAIL_SENSOR_FACING_RIGHT      = 4,
   SFA_FAIL_SENSOR_FACING_LEFT       = 5,
   SFA_FAIL_TARGET_SIGNAL_TOO_WEAK   = 6,
   SFA_FAIL_TARGET_SIGNAL_TOO_STRONG = 7,
   SFA_FAIL_TARGET_NOT_STATIC        = 8,
   SFA_FAIL_TARGET_TOO_FAR           = 9,
   SFA_FAIL_TARGET_TOO_CLOSE         = 10,
   SFA_FAIL_TARGET_NOT_FOUND         = 11,
   SFA_FAIL_INVALID_INPUT            = 12,
   SFA_FAIL_INVALID_VEHICLE_SIGN     = 13,
   SFA_FAIL_MULTIPATH_TARGET         = 14,
   SFA_FAIL_INTERFERENCE             = 15
};

typedef enum SFA_Interference_Tag
{
   SFA_INACTIVE         = 0, /* Default value */
   SFA_NO_DEGRADATION   = 1,
   SFA_DEGRADATION_LOW  = 2,
   SFA_DEGRADATION_MED  = 3,
   SFA_DEGRADATION_HIGH = 4
} SFA_Interference_T;

typedef enum SFA_Quality_Factor_Tag
{
   SFA_QF_INIT    = (0),
   SFA_QF_REDUCED = (1),
   SFA_QF_OK      = (2),
} SFA_Quality_Factor_T;

typedef struct
{
   float min_angle;
   float max_angle;
} struct0_T;
typedef struct
{
   float elevation_deg;
   float range;
   float r_dot;
   float azimuth_deg;
   float amplitude;
   float snr;
   bool f_super_res;
   bool f_valid_level;
} DETECTIONS_FA_T;

typedef struct
{
   unsigned int total_num_dets;
   float meas_plate_az;
   float meas_plate_rcs;
   float meas_plate_el;
   float meas_plate_range;
   float meas_plate_r_dot;
   uint32_t invalid_scan_counter;
   uint32_t valid_scan_counter;
   float sel_det_azimuth_sum;
   float sel_det_amplitude_sum;
   float sel_det_elevation_sum;
   float sel_det_range_sum;
   float sel_det_r_dot_sum;
   uint8_t sel_det_id;
   uint8_t qualified_det_id[SRA_NUMBER_OF_DETECTIONS];
   uint8_t num_qualified_dets;
   uint8_t num_selected_dets;
   float sigma_azimuth;
   float sigma_amplitude;
   float sigma_elevation;
   float sigma_range;
   float sigma_r_dot;
   uint32_t snr_min_counter;
   uint32_t r_dot_counter;
   uint32_t multipath_counter;
   uint32_t range_min_counter;
   uint32_t range_max_counter;
   uint32_t total_scan_counter;
   bool f_plate_detection_found;
   float processed_horz_angle_min;
   float processed_horz_angle_max;
   float processed_vert_angle_min;
   float processed_vert_angle_max;
} INTERNAL_FA_T;

typedef struct
{
   short k_nof_detections;
   float k_range_threshold;
   uint32_t k_min_number_of_updates;
   uint32_t k_max_number_of_updates;
   float k_r_dot_threshold;
   float k_az_max_threshold;
   float k_az_min_threshold;
   float k_horiz_misalign_lim;
   float k_vert_misalign_lim;
   float k_min_vert_misalign_angle;
   float k_max_vert_misalign_angle;
   struct0_T k_horz_angle_min_lim;
   struct0_T k_horz_angle_max_lim;
   struct0_T k_vert_angle_min_lim;
   struct0_T k_vert_angle_max_lim;
   float k_horz_angle_min_default;
   float k_horz_angle_max_default;
   float k_vert_angle_min_default;
   float k_vert_angle_max_default;
   float k_plate_angle_az_range_deg_srr;
   float k_plate_angle_az_range_deg_flr;
   float k_veh_speed_threshold;
   float k_angle_std_dev_min_for_OK;
   float k_veh_yawrate_threshold;
   float k_max_range_offset;
   float k_min_snr_threshold;
} CALS_FA_T;

typedef struct
{
   float plate_distance;
   float plate_angle_deg_scs;
   float yaw;
   float pitch;
   float polarity;
   float veh_speed;
   float veh_yawrate_deg;
   sfa_mounting_loc_T mount_loc;
   float plate_lat_position;
   float horz_angle_min;
   float horz_angle_max;
   float vert_angle_min;
   float vert_angle_max;
   SFA_Interference_T Interference_Detection_Level;
} INPUT_FA_T;

typedef struct
{
   SFA_Status_Tag status_of_plate;
   float vert_misalign_ang;
   float horiz_misalign_ang;
   SFA_Status_Tag status_vert_misalign_ang;
   SFA_Status_Tag status_horiz_misalign_ang;
   float std_azimuth;
   float std_amplitude;
   float std_elevation;
   float std_range;
   float std_r_dot;
   float complete_percentage;
   SFA_Quality_Factor_T qf_az;
   SFA_Quality_Factor_T qf_el;
} OUTPUT_FA_T;
typedef struct Static_Alignment_Logging_Tag
{
   float vacs_boresight_az_nominal; // [rad] yaw of the radar

   // float vacs_boresight_az_measurement; // [rad] boresight angle measurement at each execution - raw measurement after adding
   // yaw and polarity

   float vacs_boresight_az_estimated; // [rad] estimated boresight angle over multiple executions - smoothed value after adding yaw
                                      // and polarity
   float vacs_boresight_az_std;       // [-] estimated error standard deviation

   float vacs_boresight_el_nominal; // [rad] pitch of the radar

   // float vacs_boresight_el_measurement; // [rad] boresight angle measurement at each execution

   float vacs_boresight_el_estimated; // [rad] estimated boresight angle el over multiple executions - smoothed value after adding
                                      // pitch and polarity
   float vacs_boresight_el_std;       // [-] estimated error standard devaition

   float std_amplitude;
   float std_range;
   float std_r_dot;

   float radar_to_plate_distance; // m
   float plate_angle_scs;         // expected plate azimuth angle in radians - known position
   float vehicle_speed;
   float vehicle_yawrate;       // vehicle yawrate in radians
   float vacs_boresight_az_min; // minimum allowed azimuth misalignment input- compensated with yaw
   float vacs_boresight_az_max; // maximum allowed azimuth misalignment - compensated with yaw
   float vacs_boresight_el_min; // minimum allowed elevation misalignment input- compensated with pitch
   float vacs_boresight_el_max; // maximum allowed elevation misalignment input- compensated with pitch
   uint32_t valid_scan_counter;
   uint32_t invalid_scan_counter;
   uint8_t detection_used; // [-]    detection idx used for  estimation
   int8_t vcs_polarity;    // polarity of the radar
   uint8_t mount_loc;
   uint8_t status_of_plate;
   uint8_t alignment_mode; // 0: off, 1: static, 2: Dynamic,
   uint8_t version_major;  // algorithm version information
   uint8_t version_minor;  // algorithm version information
   uint8_t version_patch;  // algorithm version information
} Static_Alignment_Logging_T;
#ifdef __cplusplus
extern "C"
{
#endif

   DECLARE_FAKE_VALUE_FUNC(M2D_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
   DECLARE_FAKE_VALUE_FUNC(M2D_One_Time_Msg_T *, Get_IPC_M2D_One_Time_Buffer);

#ifdef __cplusplus
}
#endif

#define FFF_FAKE_BUFFER_FUNCTION(FAKE)                                                                                            \
   FAKE(Get_IPC_M2D_Onetime_Msg_Buffer)                                                                                           \
   FAKE(Get_IPC_D2M_Sp_Post_Proc_Buffer)                                                                                          \
   FAKE(Get_IPC_M2D_One_Time_Buffer)

#endif /* STATIC_ALIGN_MAIN_FAKE_H */
