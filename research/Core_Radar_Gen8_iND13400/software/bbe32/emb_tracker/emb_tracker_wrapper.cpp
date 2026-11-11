/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_wrapper.cpp
 * Purpose: Embedded tracker wrapper implementation
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */
/*==========================================================================*/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* Standard C/C++ header includes */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>

/* Wrapper includes */
#include "emb_tracker_internal.h"
#include "emb_tracker_stream_interface.h"
#include "emb_tracker_wrapper.h"

/* Stub tracker input functions include */
#if EMB_TRACKER_STUBBED
   #include "emb_tracker_stubs.h"
#endif

/* Tracker and state manager includes */
#include "State_Manager.h"
#include "f360_input_diagnostics.h"
#include "f360_output_diagnostics.h"
#include "f360_safety_control_logic.h"
#include "f360_tracker.h"

/* Other f360 includes */
#include "f360_coordinate_system.h"
#include "f360_core_info.h"
#include "f360_detection_props_list.h"
#include "f360_host.h"
#include "f360_host_calib.h"
#include "f360_host_raw.h"
#include "f360_radar_sensor.h"
#include "f360_reference_point.h"

/* OCG includes */
#ifndef DISABLE_OCG
   #include "ocg_occupancy_grid.h"
   #include "ocg_occupancy_grid_types.h"
#endif

/* SG includes */
#ifndef DISABLE_SG
   #include "sg_stationary_geometries.h"
#endif

/* Timing function includes */
#ifndef PC_RESIM_TRACKER
   #include "get_r52_time_from_bbe32.h"
   #include "ipc_dsp.h"
#else
   #define US_PER_S  (1000000ULL)
   #define NS_PER_US (1000ULL)
#endif

/* Needed for matching the namespace in the tracker algo */
using namespace f360_variant_A;

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
/* Macro to help with sign flipping */
#ifndef NEG_FLOAT
   #define NEG_FLOAT (-1.0f)
#endif

/* Macro for microsec to sec conversion */
#ifndef MICRO_SEC_TO_SEC
   #define MICRO_SEC_TO_SEC (1.0e-6f)
#endif

/* Macro for timestamp workaround when middle dwell time is 0 */
#define TIMESTAMP_WORKAROUND (30000U) /* 30 ms */

/* Throw error if downselection is not enabled */
/* Note: Functions below will throw error if downselection_data stream is not present, even if this check passes */
#if !defined(DOWNSELECTION_ENABLE) || (DOWNSELECTION_ENABLE != 1U)
   #error "Tracker requires DOWNSELECTION_ENABLE to be 1!"
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* Tracker and state manager structs */
static F360_Tracker f360_tracker{};                                                    /*Object for managing the tracker state*/
static Input_Diagnostics input_diagnostics{};                                          /*Object for managing input diagnostics*/
static Output_Diagnostics output_diagnostics{};                                        /*Object for managing output diagnostics*/
static SafetyControlLogic safety_control_logic(input_diagnostics, output_diagnostics); /*Object for managing safety control logic*/

/* Host data buffer and pointers */
static constexpr uint8_t host_buffer_length = HOST_BUFFER_DELAY_CYCLES + 1U; /* Length of the host data buffer */
static F360_Host_T host_buffer[host_buffer_length]{};                        /*Buffer for storing host data*/
static F360_Host_T *host_buffer_write_ptr = &host_buffer[0]; /*Pointer to the current write position in the host buffer*/
F360_Host_T *host_buffer_read_ptr         = &host_buffer[0]; /*Pointer to the current read position in the host buffer*/

/* Raw detection list struct */
#ifdef PC_RESIM_TRACKER
static F360_Detection_List_T f360_det_list_instance{};
#endif
F360_Detection_List_T *f360_det_list = nullptr;

/* Pointer to mempool used for det props list internal to tracker algo */
#ifdef PC_RESIM_TRACKER
static F360_Detection_Props_List_T f360_det_props_list_instance{};
#endif
static F360_Detection_Props_List_T *f360_det_props_list = nullptr;

/* Other f360 structs */
F360_Core_Info_T core_info{};
F360_Host_Raw_T host_raw{};
static F360_Host_Calib_T host_calib{};
F360_Radar_Sensor_T sensors[MAX_NUMBER_OF_SENSORS]{};
static float32_t vacs_boresight_az_estimated[MAX_NUMBER_OF_SENSORS]{};
static float32_t vacs_boresight_el_estimated[MAX_NUMBER_OF_SENSORS]{};

/* Compile-time flag for enabling main sensor data buffering. */
#define MAIN_SENSOR_BUFFERING_ENABLED (MAIN_SENSOR_BUFFER_DELAY_CYCLES > 0U)

/* Structure of just the cycle-to-cycle variable sensor data to reduce buffer memory usage */
typedef struct Variable_Sensor_Data_Tag
{
   uint64_t timestamp_us;
   uint32_t number_of_valid_detections;
   uint16_t overall_rain_level;
   uint16_t look_index;
   F360_Det_Look_ID_T look_id;
} Variable_Sensor_Data_T;

/* Main sensor buffer entry definition */
#if MAIN_SENSOR_BUFFERING_ENABLED
typedef struct Main_Sensor_Buffer_Entry_Tag
{
   Variable_Sensor_Data_T variable_sensor_data;
   F360_Detection_T raw_det_data[NUMBER_OF_MAIN_DETECTIONS_EMB];
} Main_Sensor_Buffer_Entry_T;

/* Main sensor buffer and pointers */
static constexpr uint8_t main_sensor_buffer_length = MAIN_SENSOR_BUFFER_DELAY_CYCLES + 1U;
static Main_Sensor_Buffer_Entry_T main_sensor_buffer[main_sensor_buffer_length]{};
static Main_Sensor_Buffer_Entry_T *main_sensor_buffer_write_ptr = &main_sensor_buffer[0];
static Main_Sensor_Buffer_Entry_T *main_sensor_buffer_read_ptr  = &main_sensor_buffer[0];
#endif

/* OCG structs */
#ifndef DISABLE_OCG
static ocg::Occupancy_Grid ocg_grid{};
   #ifdef PC_RESIM_TRACKER
static ocg::OCG_Inputs_T ocg_inputs_instance{};
static ocg::OCG_Outputs_T ocg_outputs_instance{};
   #endif
static ocg::OCG_Inputs_T *ocg_inputs   = nullptr;
static ocg::OCG_Outputs_T *ocg_outputs = nullptr;
#endif

/* OCG helper variables */
static uint8_t front_center_sensor_index = 0;
static bool runtime_enable_ocg           = false;
static bool ocg_initialized              = false;

/* SG structs */
#ifndef DISABLE_SG
static sg::Stationary_Geometries sg_tracker{}; /* SG to be properly integrated, calibrated, and tested still */
   #ifdef PC_RESIM_TRACKER
static sg::SG_Output_T sg_output_instance{};
   #endif
static sg::SG_Output_T *sg_output = nullptr;
#endif

/* Tracker output streams' pointers to IPC */
static Sync_Info_Log_T *sync_info_log                               = nullptr;
static Vehicle_Info_Log_T *vehicle_info_log                         = nullptr;
static Tracker_Info_Log_T *tracker_info_log                         = nullptr;
static Timing_Info_Log_T *timing_info_log                           = nullptr;
static Host_Calibs_Log_T *host_calibs_log                           = nullptr;
static F360_Host_Props_Log_T *host_props_log                        = nullptr;
static F360_Static_Env_Poly_Log_T *static_env_poly_log              = nullptr;
static Functional_Safety_Faults_Log_T *functional_safety_faults_log = nullptr;
static F360_Object_Log_Output_T *object_list_log                    = nullptr;
static F360_Detection_Log_Output_T *processed_detection_log         = nullptr;
static F360_Sensor_Calib_Log_Output_T *sensor_calib_log             = nullptr;
static Trailer_Detector_Log_T *trailer_detector_log                 = nullptr;
static CV_Trailer_Log_T *cv_trailer_log                             = nullptr;

/* Tracker internal streams' pointers to IPC */
#if ENABLE_INTERNAL_TRACKER_STREAMS
static F360_Internal_Trailer_Detector_T *internal_trailer_detector_log              = nullptr;
static F360_Internal_Object_Log_Output_T *internal_object_log                       = nullptr;
static F360_Internal_Cluster_Log_Output_T *internal_cluster_log                     = nullptr;
static F360_Internal_Detection_History_Log_Output_T *internal_detection_hist_log    = nullptr;
static F360_Internal_Reflection_Buffer_Log_Output_T *internal_reflection_buffer_log = nullptr;
static F360_Internal_CWD_Log_Output_T *internal_cwd_log                             = nullptr;
#endif

/* Flags for controlling whether the tracker execution is skipped due to certain input failures */
static bool core_info_valid           = false;
static bool first_main_scan_received  = false;
static bool first_valid_host_received = false;

/* For changing the max number of sensors populated in loops for special cases like AL 1 SW */
static uint8_t max_sensors_to_update = MAX_NUMBER_OF_SENSORS;
/* For disabling the main sensor buffering for special cases like AL 1 SW */
static bool main_sensor_buffering_active = true;

/* For disabling the host data buffering for special cases like AL 1 SW */
static bool host_data_buffering_active = true;
/* For changing the detection caps for special cases like AL 1 SW */
static uint16_t sensor_det_caps[MAX_NUMBER_OF_SENSORS] = {0};

/* For checking if sensor data is stale */
static uint16_t sensors_prev_scan_index[MAX_NUMBER_OF_SENSORS] = {0};

/* For tracking which sensors have been initialized */
static bool sensors_initialized[MAX_NUMBER_OF_SENSORS] = {false};

#if defined(PC_RESIM_TRACKER) && defined(_DEBUG)
/* For xtrk logging */
static bool enable_xtrk_logging = false;
#endif

/* ========================================================================== */
/*                      Local Function Declarations                          */
/* ========================================================================== */
/* Static init functions */

static void Init_Host_Calibs(M2D_Msg_T *p_ipc_m2d);
static void Init_Sensors(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d);

#if !PC_RESIM_TRACKER
static Memory_Pool_Return_T Emb_Tracker_Mempool_Init(Mem_Pool_T *mem_pool);
#endif

/* Static update functions */
static void Update_Core_Info(D2M_Msg_T *p_ipc_d2m);
static void Update_Sensors(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d);
static void Update_Sensor_Motion(void);
static void Update_DS_Dets(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d);
static void Update_Host_From_R52_VSE_Output(const Vse_Output_T *p_vse_output);
static F360_Host_T *Get_Previous_Host_Buffer_Entry(F360_Host_T *entry_ptr);

/* Static run functions */
#ifndef DISABLE_OCG
static void Run_OCG(void);
#elif !defined(DISABLE_SG)
static void Run_SG(void);
#endif

#ifdef PC_RESIM_TRACKER
uint64_t Get_Time_For_RESIM(D2M_Msg_T *p_ipc_d2m);
#endif

/* Wrapper for calling tracker output logging functions */
static void Populate_Tracker_Logs(void);

/* ========================================================================== */
/*                   Inline Helper Function Definitions                       */
/* ========================================================================== */
/*
 * Function:    Get_State_Manager
 * Returns:     State_Manager&
 * Parameters:  None
 * Globals:     safety_control_logic, f360_tracker
 * Abstract:    Returns a reference to the static state manager instance.
 * Reentrant:   NO
 */
static State_Manager &Get_State_Manager()
{
   /* Emb_Tracker_Mem_Init with Set_Det_Props_List_Ptr MUST be called before the first call to this each cycle! */
   static State_Manager state_manager(safety_control_logic, f360_tracker);
   return state_manager;
}

/*
 * Function:    Get_Next_Host_Buffer_Entry
 * Returns:     F360_Host_T*
 * Parameters:  F360_Host_T *entry_ptr - pointer to the current host buffer entry
 * Globals:     host_buffer, host_buffer_length
 * Abstract:    Returns the next host buffer entry pointer with wrap-around handling.
 * Reentrant:   NO
 */
static F360_Host_T *Get_Next_Host_Buffer_Entry(F360_Host_T *entry_ptr)
{
   return (entry_ptr == &host_buffer[host_buffer_length - 1U]) ? &host_buffer[0] : (entry_ptr + 1);
}

/*
 * Function:    Get_Previous_Host_Buffer_Entry
 * Returns:     F360_Host_T*
 * Parameters:  F360_Host_T *entry_ptr - pointer to the current host buffer entry
 * Globals:     host_buffer, host_buffer_length
 * Abstract:    Returns the previous host buffer entry pointer with wrap-around handling.
 * Reentrant:   NO
 */
static F360_Host_T *Get_Previous_Host_Buffer_Entry(F360_Host_T *entry_ptr)
{
   return (entry_ptr == &host_buffer[0]) ? &host_buffer[host_buffer_length - 1U] : (entry_ptr - 1);
}

#if MAIN_SENSOR_BUFFERING_ENABLED
/*
 * Function:    Get_Next_Main_Sensor_Buffer_Entry
 * Returns:     Main_Sensor_Buffer_Entry_T*
 * Parameters:  Main_Sensor_Buffer_Entry_T *entry_ptr - pointer to the current main sensor buffer entry
 * Globals:     main_sensor_buffer, main_sensor_buffer_length
 * Abstract:    Returns the next main sensor buffer entry pointer with wrap-around handling.
 * Reentrant:   NO
 */
static Main_Sensor_Buffer_Entry_T *Get_Next_Main_Sensor_Buffer_Entry(Main_Sensor_Buffer_Entry_T *entry_ptr)
{
   return (entry_ptr == &main_sensor_buffer[main_sensor_buffer_length - 1U]) ? &main_sensor_buffer[0] : (entry_ptr + 1);
}
#endif

/*
 * Function:    Load_Variable_Data_To_Sensor
 * Returns:     void
 * Parameters:  F360_Radar_Sensor_T *sensor - pointer to the sensor to update
 *              const Variable_Sensor_Data_T *var - pointer to the (possibly buffered) variable sensor data
 * Globals:     None
 * Abstract:    Copies the cycle-varying sensor fields from var into sensor.
 * Reentrant:   NO
 */
static void Load_Variable_Data_To_Sensor(F360_Radar_Sensor_T *sensor, const Variable_Sensor_Data_T *var)
{
   sensor->timestamp_us               = var->timestamp_us;
   sensor->number_of_valid_detections = var->number_of_valid_detections;
   sensor->overall_rain_level         = var->overall_rain_level;
   sensor->look_index                 = var->look_index;
   sensor->look_id                    = var->look_id;
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*
 * Function:    Init_Emb_Tracker
 * Returns:     void
 * Parameters:  volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time - Pointer to one-time IPC message structure containing static data
 *              such as host vehicle calibrations and radar position
 *              M2D_Msg_T *p_ipc_m2d - Pointer to IPC message structure for communicating with other modules
 * Globals:     max_sensors_to_update, main_sensor_buffering_active, sensor_det_caps, host_buffer, host_buffer_write_ptr,
 *              host_buffer_read_ptr, host_calib, sensors, ocg_initialized, sg_tracker
 * Abstract:    Initializes the embedded tracker including state manager, buffers, calibrations, sensors, etc.
 * Reentrant:   NO
 */
void Init_Emb_Tracker(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d)
{
   /* Memset some variables in case of re-initialization */
   memset(&core_info, 0, sizeof(core_info));
   memset(&sensors, 0, sizeof(sensors));
   memset(vacs_boresight_az_estimated, 0, sizeof(vacs_boresight_az_estimated));
   memset(vacs_boresight_el_estimated, 0, sizeof(vacs_boresight_el_estimated));
   memset(sensors_prev_scan_index, 0, sizeof(sensors_prev_scan_index));
   memset(sensors_initialized, 0, sizeof(sensors_initialized));

   /* Initialize the state manager and tracker using SAE coordinate system */
   Get_State_Manager().Initialize(F360_Coordinate_System_T::F360_COORD_SYS_SAE);

   /* Initialize host buffering state */
   host_buffer_write_ptr = &host_buffer[0];
   host_buffer_read_ptr  = &host_buffer[0];
   memset(host_buffer, 0, sizeof(F360_Host_T) * host_buffer_length);

#if MAIN_SENSOR_BUFFERING_ENABLED
   /* Initialize main sensor buffering state */
   main_sensor_buffer_write_ptr = &main_sensor_buffer[0];
   main_sensor_buffer_read_ptr  = &main_sensor_buffer[0];
   memset(main_sensor_buffer, 0, sizeof(Main_Sensor_Buffer_Entry_T) * main_sensor_buffer_length);
#endif

   /* Initialize sensors */
#if EMB_TRACKER_STUBBED
   Populate_Ipc_Data_For_Init_Stub_Sensors(p_ipc_m2d_one_time, p_ipc_m2d);
#endif

   /* Initialize host vehicle calibrations */
   Init_Host_Calibs(p_ipc_m2d);

   /* Special case considerations */
   /* Defaults for this build from emb_tracker_project_parameters.h */
   max_sensors_to_update        = MAX_NUMBER_OF_SENSORS;
   main_sensor_buffering_active = true;
   host_data_buffering_active   = true;
   sensor_det_caps[0]           = NUMBER_OF_MAIN_DETECTIONS_EMB;
   for (uint8_t sensor_index = 1U; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      sensor_det_caps[sensor_index] = NUMBER_OF_PARTNER_DETECTIONS_EMB;
   }
   /* Special case for AL Front Center (position 5) */
#if defined(AL_TRACKER)
   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      max_sensors_to_update        = 1U;
      main_sensor_buffering_active = false;
      host_data_buffering_active   = false;
      sensor_det_caps[0]           = NUMBER_OF_MAIN_DETECTIONS_EMB;
      sensor_det_caps[1]           = 0U;
      sensors[1].is_valid          = false;
   }
   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      max_sensors_to_update        = 2U;
      main_sensor_buffering_active = true;
      host_data_buffering_active   = true;
      sensor_det_caps[0]           = NUMBER_OF_MAIN_DETECTIONS_EMB / 2;
      sensor_det_caps[1]           = NUMBER_OF_PARTNER_DETECTIONS_EMB / 2;
   }
#elif !EMB_TRACKER_STUBBED
   (void)p_ipc_m2d_one_time;
#endif

#ifndef DISABLE_OCG
   ocg_initialized = false;
#else
   (void)ocg_initialized;
#endif

#ifndef DISABLE_SG
   /* Initialize SG */
   static const sg::SG_Internals_Dump_T sg_internals{};
   sg_tracker.initialize(sg_internals);
#endif
}

/*
 * Function:    Init_Host_Calibs
 * Returns:     void
 * Parameters:  M2D_Msg_T *p_ipc_m2d - Pointer to IPC message structure for communicating with other modules
 * Globals:     host_calib, host_buffer, host_buffer_length
 * Abstract:    Initializes host calibration values and seeds the host buffer with the host type.
 * Reentrant:   NO
 */
static void Init_Host_Calibs(M2D_Msg_T *p_ipc_m2d)
{
   /* Get pointer to vehicle params from VSE stream */
   volatile Veh_Params_T *vehicle_params_ptr = &p_ipc_m2d->payload.veh_data.veh_params;

   /* Set vehicle specific calibration values */
   host_calib.dist_rear_axle_to_vcs_m                    = vehicle_params_ptr->k_dist_rear_axle_to_vcs;
   host_calib.rear_cornering_compliance                  = vehicle_params_ptr->k_rear_cornering_compliance;
   host_calib.steer_gear_ratio                           = vehicle_params_ptr->k_steering_gear_ratio;
   host_calib.wheelbase_m                                = vehicle_params_ptr->k_wheel_base;
   host_calib.understeer_coefficient                     = vehicle_params_ptr->k_understeer_coefficient;
   host_calib.vehicle_width_m                            = vehicle_params_ptr->k_vehicle_width;
   host_calib.vehicle_length_m                           = vehicle_params_ptr->k_vehicle_length;
   host_calib.cog_x                                      = vehicle_params_ptr->k_cog_x;
   host_calib.cog_y                                      = vehicle_params_ptr->k_cog_y;
   host_calib.front_wheel_radius_m                       = 0;
   host_calib.front_track_width_m                        = vehicle_params_ptr->k_front_track_width;
   host_calib.raw_host_signal_latency_ms                 = 0;
   host_calib.f_enable_internal_reflections_func         = 0;
   host_calib.f_enable_internal_reflections_func_trailer = 0;

   /* Copy host type to host_calib and every element of host data buffer */
   host_calib.host_type = HOST_TYPE;
   for (uint8_t host_buffer_index = 0U; host_buffer_index < host_buffer_length; host_buffer_index++)
   {
      host_buffer[host_buffer_index].host_type = HOST_TYPE;
   }
}

/*
 * Function:    Init_Sensors
 * Returns:     void
 * Parameters:  M2D_Msg_T *p_ipc_m2d - Pointer to IPC message structure for communicating with other modules
 *              volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time - Pointer to one-time IPC message structure containing static data
 *              such as host vehicle calibrations and radar position
 * Globals:     sensors, front_center_sensor_index, runtime_enable_ocg, sensors_initialized
 * Abstract:    Initializes sensor calibration, mounting, and look-specific data from IPC inputs.
 *              Main sensor: initialization on first call.
 *              Partner sensors: initialization deferred until CAN data is valid.
 * Reentrant:   NO
 */
static void Init_Sensors(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d)
{
   for (uint8_t sensor_index = 0; sensor_index < max_sensors_to_update; sensor_index++)
   {
      /* Skip if sensor already initialized */
      if (sensors_initialized[sensor_index])
      {
         continue;
      }

      /* Get pointer to the sensor calib data (for all sensors) on IPC */
      volatile Sensor_Calib_Data_T *sensor_calib_data_ptr = &p_ipc_m2d_one_time->calib_data.sensor_calib_data;

      /* Get radar position and parameter pointers */
      uint8_t radar_position;
      uint8_t partner_sensor_index;
      volatile Sensor_Mount_Data_T *sensor_mount_data_ptr;
      if (sensor_index == 0)
      {
         radar_position        = p_ipc_m2d_one_time->radar_position;
         sensor_mount_data_ptr = &p_ipc_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data;
      }
      else
      {
         partner_sensor_index = sensor_index - 1U;

         /* Wait to initialize partner sensors until CAN data is valid */
         if (p_ipc_m2d->payload.partners_data.partner_sensor_diag_data[partner_sensor_index].status_recvd_flag != 1U)
         {
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_UNKNOWN;
            continue;
         }

         radar_position = p_ipc_m2d->payload.partners_data.partner_det_list_property_data[partner_sensor_index].radar_position;
         sensor_mount_data_ptr = reinterpret_cast<volatile Sensor_Mount_Data_T *>(
            &p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[partner_sensor_index]);
      }

      /* Set sensor ID */
      sensors[sensor_index].id = sensor_index + 1;

      /* Mounting params */
      sensors[sensor_index].mounting_position.vcs_position.longitudinal =
         sensor_mount_data_ptr->k_sensor_mount_pos_x - host_calib.dist_rear_axle_to_vcs_m;
      sensors[sensor_index].mounting_position.vcs_position.lateral = NEG_FLOAT * sensor_mount_data_ptr->k_sensor_mount_pos_y;
      sensors[sensor_index].mounting_position.vcs_position.height  = sensor_mount_data_ptr->k_sensor_mount_pos_z;
      sensors[sensor_index].mounting_position.vcs_boresight_azimuth_angle =
         NEG_FLOAT * sensor_mount_data_ptr->k_sensor_mount_ornt_yaw;
      sensors[sensor_index].mounting_position.vcs_boresight_elevation_angle = sensor_mount_data_ptr->k_sensor_mount_ornt_pitch;

      /* Set polarity based on roll value after ISO->SAE conversion */
      sensors[sensor_index].polarity = ((F360_PI - sensor_mount_data_ptr->k_sensor_mount_ornt_roll) < 0.1F) ? 1 : -1;

      /* Default DRA values */
      vacs_boresight_az_estimated[sensor_index] = sensors[sensor_index].mounting_position.vcs_boresight_azimuth_angle;
      vacs_boresight_el_estimated[sensor_index] = sensors[sensor_index].mounting_position.vcs_boresight_elevation_angle;

      /* Set mounting_location based on radar_position */
      switch (radar_position)
      {
         case RADAR_POSITION_REAR_LEFT:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_LEFT_REAR;
            break;
         case RADAR_POSITION_REAR_RIGHT:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_RIGHT_REAR;
            break;
         case RADAR_POSITION_FRONT_RIGHT:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_RIGHT_FORWARD;
            break;
         case RADAR_POSITION_FRONT_LEFT:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_LEFT_FORWARD;
            break;
         case RADAR_POSITION_FRONT_CENTER:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_CENTER_FORWARD;
            if (!runtime_enable_ocg)
            {
               front_center_sensor_index = sensor_index;
               runtime_enable_ocg        = true;
            }
            break;
         default:
            sensors[sensor_index].mounting_location = F360_MOUNTING_LOCATION_UNKNOWN;
            break;
      }

      /* Set sensor type based on platform variant */
      switch (K_PLATFORM_VARIANT)
      {
         case 82:
            sensors[sensor_index].sensor_type = F360_SENSOR_TYPE_FLR8_PLT_RADAR;
            break;
         case 83:
            sensors[sensor_index].sensor_type = F360_SENSOR_TYPE_SRR8_PLUS_PLT_RADAR;
            break;
         default:
            sensors[sensor_index].sensor_type = F360_SENSOR_TYPE_UNKNOWN;
            break;
      }

      /* Set look specific values from SMC */
      for (uint8_t look_id = 0; look_id < (uint8_t)F360_DET_NUM_LOOK_ID; look_id++)
      {
         /* Range limits */
         sensors[sensor_index].range_limits[look_id] = sensor_calib_data_ptr->k_detection_range_max[look_id];

         /* FOVs */
         sensors[sensor_index].fov_min_az_rad[look_id] = sensor_calib_data_ptr->k_fov_hor_begin;
         sensors[sensor_index].fov_max_az_rad[look_id] = sensor_calib_data_ptr->k_fov_hor_end;
         sensors[sensor_index].fov_min_el_rad[look_id] = sensor_calib_data_ptr->k_fov_ver_begin;
         sensors[sensor_index].fov_max_el_rad[look_id] = sensor_calib_data_ptr->k_fov_ver_end;

         /* For dealiasing purposes */
         sensors[sensor_index].min_aliaised_range_rate[look_id] = sensor_calib_data_ptr->k_rdotmin;
         sensors[sensor_index].v_wrapping[look_id]              = sensor_calib_data_ptr->k_vwrapping[look_id];
         sensors[sensor_index].r_wrapping[look_id]              = sensor_calib_data_ptr->k_rwrapping[look_id];
      }

      /* Only applicable on some projects with trailers. Default, disabled values for now */
      sensors[sensor_index].internal_reflections.min_host_vel          = 0.0f;
      sensors[sensor_index].internal_reflections.occurrence_lowerlimit = 0.0f;
      sensors[sensor_index].internal_reflections.occurrence_threshold  = 0.0f;
      sensors[sensor_index].internal_reflections.rcs_tolerance         = 0.0f;
      sensors[sensor_index].internal_reflections.azimuth_tolerance     = 0.0f;
      sensors[sensor_index].internal_reflections.range_tolerance       = 0.0f;
      sensors[sensor_index].internal_reflections.max_abs_range_rate    = 0.0f;
      sensors[sensor_index].internal_reflections.rcs_max               = 0.0f;
      sensors[sensor_index].internal_reflections.range_max             = 0.0f;
      sensors[sensor_index].internal_reflections.age_threshold         = 0;
      sensors[sensor_index].internal_reflections.f_enable              = false;

      /* Bools for enabling sensor in tracker */
      sensors[sensor_index].is_valid                = true;
      sensors[sensor_index].f_sensor_fault_detected = false;

      /* Mark the sensor as initialized */
      sensors_initialized[sensor_index] = true;
   }
}

/*
 * Function:    Emb_Tracker_Mem_Init
 * Returns:     Memory_Pool_Return_T
 * Parameters:  Mem_Pool_T *mem_pool - pointer to the memory pool for tracker allocations
 *              D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message structure
 * Globals:     sync_info_log, vehicle_info_log, tracker_info_log, timing_info_log, host_calibs_log, host_props_log,
 *              static_env_poly_log, functional_safety_faults_log, object_list_log, processed_detection_log,
 *              sensor_calib_log, trailer_detector_log, cv_trailer_log
 * Abstract:    Initializes tracker stream pointers and allocates scratch state from the memory pool.
 * Reentrant:   NO
 */
Memory_Pool_Return_T Emb_Tracker_Mem_Init(Mem_Pool_T *mem_pool, D2M_Msg_T *p_ipc_d2m)
{
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;

   /* Set pointers to IPC for tracker streams */
   sync_info_log                = &p_ipc_d2m->payload.sync_info_stream;
   vehicle_info_log             = &p_ipc_d2m->payload.vehicle_info_stream;
   tracker_info_log             = &p_ipc_d2m->payload.tracker_info_stream;
   timing_info_log              = &p_ipc_d2m->payload.timing_info_stream;
   host_calibs_log              = &p_ipc_d2m->payload.host_calibs_stream;
   host_props_log               = &p_ipc_d2m->payload.host_props_stream;
   static_env_poly_log          = &p_ipc_d2m->payload.static_env_poly_stream;
   functional_safety_faults_log = &p_ipc_d2m->payload.functional_safety_faults_stream;
   object_list_log              = reinterpret_cast<F360_Object_Log_Output_T *>(&p_ipc_d2m->payload.object_list_stream);
   processed_detection_log      = reinterpret_cast<F360_Detection_Log_Output_T *>(&p_ipc_d2m->payload.processed_detection_stream);
   sensor_calib_log             = reinterpret_cast<F360_Sensor_Calib_Log_Output_T *>(&p_ipc_d2m->payload.sensor_calib_stream);
   trailer_detector_log         = &p_ipc_d2m->payload.trailer_detector_stream;
   cv_trailer_log               = &p_ipc_d2m->payload.cv_trailer_stream;

#if ENABLE_INTERNAL_TRACKER_STREAMS
   /* Set pointers to IPC for tracker internal streams */
   internal_trailer_detector_log = &p_ipc_d2m->payload.internal_trailer_detector_stream;
   internal_object_log  = reinterpret_cast<F360_Internal_Object_Log_Output_T *>(&p_ipc_d2m->payload.internal_object_stream);
   internal_cluster_log = reinterpret_cast<F360_Internal_Cluster_Log_Output_T *>(&p_ipc_d2m->payload.internal_cluster_stream);
   internal_detection_hist_log =
      reinterpret_cast<F360_Internal_Detection_History_Log_Output_T *>(&p_ipc_d2m->payload.internal_detection_hist_stream);
   internal_reflection_buffer_log =
      reinterpret_cast<F360_Internal_Reflection_Buffer_Log_Output_T *>(&p_ipc_d2m->payload.internal_reflection_buffer_stream);
   internal_cwd_log = reinterpret_cast<F360_Internal_CWD_Log_Output_T *>(&p_ipc_d2m->payload.internal_cwd_stream);
#endif

#ifdef PC_RESIM_TRACKER
   f360_det_list       = &f360_det_list_instance;
   f360_det_props_list = &f360_det_props_list_instance;
   #ifndef DISABLE_OCG
   ocg_inputs  = &ocg_inputs_instance;
   ocg_outputs = &ocg_outputs_instance;
   #endif
   #ifndef DISABLE_SG
   sg_output = &sg_output_instance;
   #endif
#else
   retVal = Emb_Tracker_Mempool_Init(mem_pool);
#endif

   /* Memset tracker streams on IPC */
   memset(sync_info_log, 0, sizeof(*sync_info_log));
   memset(vehicle_info_log, 0, sizeof(*vehicle_info_log));
   memset(tracker_info_log, 0, sizeof(*tracker_info_log));
   memset(timing_info_log, 0, sizeof(*timing_info_log));
   memset(host_calibs_log, 0, sizeof(*host_calibs_log));
   memset(host_props_log, 0, sizeof(*host_props_log));
   memset(static_env_poly_log, 0, sizeof(*static_env_poly_log));
   memset(functional_safety_faults_log, 0, sizeof(*functional_safety_faults_log));
   memset(object_list_log, 0, sizeof(*object_list_log));
   memset(processed_detection_log, 0, sizeof(*processed_detection_log));
   memset(sensor_calib_log, 0, sizeof(*sensor_calib_log));
   memset(trailer_detector_log, 0, sizeof(*trailer_detector_log));
   memset(cv_trailer_log, 0, sizeof(*cv_trailer_log));

#if ENABLE_INTERNAL_TRACKER_STREAMS
   /* Memset tracker internal streams on IPC */
   memset(internal_trailer_detector_log, 0, sizeof(*internal_trailer_detector_log));
   memset(internal_object_log, 0, sizeof(*internal_object_log));
   memset(internal_cluster_log, 0, sizeof(*internal_cluster_log));
   memset(internal_detection_hist_log, 0, sizeof(*internal_detection_hist_log));
   memset(internal_reflection_buffer_log, 0, sizeof(*internal_reflection_buffer_log));
   memset(internal_cwd_log, 0, sizeof(*internal_cwd_log));
#endif

   if (retVal == MEM_POOL_SUCCESS)
   {
      /* Memset scratch variables on mempool */
      memset(f360_det_list, 0, sizeof(*f360_det_list));

#ifndef DISABLE_OCG
      memset(ocg_inputs, 0, sizeof(*ocg_inputs));
      memset(ocg_outputs, 0, sizeof(*ocg_outputs));
#endif
#ifndef DISABLE_SG
      memset(sg_output, 0, sizeof(*sg_output));
#endif
   }

#if MAIN_SENSOR_BUFFERING_ENABLED
   /* Memset the write entry of the main sensor buffer */
   memset(main_sensor_buffer_write_ptr, 0, sizeof(*main_sensor_buffer_write_ptr));
#endif

   /* Pass the pointer for det props list to the tracker algo */
   /* Memsetting this is unnecessary in wrapper as the algo manually resets this class every cycle */
   f360_tracker.Set_Det_Props_List_Ptr(f360_det_props_list);

   return retVal;
}

/*
 * Function:    Emb_Tracker_Mempool_Init
 * Returns:     Memory_Pool_Return_T
 * Parameters:  Mem_Pool_T *mem_pool - pointer to the memory pool for tracker allocations
 * Globals:     f360_det_list, ocg_inputs, ocg_outputs, sg_output
 * Abstract:    Allocates scratch objects for non-RESIM builds.
 * Reentrant:   NO
 */
#if !PC_RESIM_TRACKER
static Memory_Pool_Return_T Emb_Tracker_Mempool_Init(Mem_Pool_T *mem_pool)
{
   /* Allocate space on mempool for scratch variables */
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;

   /* Raw detection list */
   retVal = Mem_Pool_Alloc(mem_pool, sizeof(*f360_det_list), (void **)&f360_det_list);

   /* OCG inputs and outputs */
   #ifndef DISABLE_OCG
   if (retVal == MEM_POOL_SUCCESS)
   {
      retVal = Mem_Pool_Alloc(mem_pool, sizeof(*ocg_inputs), (void **)&ocg_inputs);
   }
   if (retVal == MEM_POOL_SUCCESS)
   {
      retVal = Mem_Pool_Alloc(mem_pool, sizeof(*ocg_outputs), (void **)&ocg_outputs);
   }
   #endif

   /* SG outputs */
   #ifndef DISABLE_SG
   if (retVal == MEM_POOL_SUCCESS)
   {
      retVal = Mem_Pool_Alloc(mem_pool, sizeof(*sg_output), (void **)&sg_output);
   }
   #endif

   /* Detection props and object tracks internal to the tracker */
   if (retVal == MEM_POOL_SUCCESS)
   {
      retVal = Mem_Pool_Alloc(mem_pool, sizeof(*f360_det_props_list), (void **)&f360_det_props_list);
   }

   return retVal;
}
#endif

/*
 * Function:    Run_Emb_Tracker
 * Returns:     void
 * Parameters:  D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message structure
 *              M2D_Msg_T *p_ipc_m2d - pointer to IPC M2D message structure
 *              volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time - Pointer to one-time IPC message structure containing static data
 *              such as host vehicle calibrations and radar position
 * Globals:     main_sensor_buffer, main_sensor_buffer_length
 * Abstract:    Runs one tracker cycle by updating inputs, executing modules, and publishing outputs.
 * Reentrant:   NO
 */
void Run_Emb_Tracker(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d, volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time)
{
   /* Update inputs to tracker and other modules */
   Update_Core_Info(p_ipc_d2m);

#if EMB_TRACKER_STUBBED
   /* Stub path must populate host and detection streams before Update_Sensors reads them this cycle. */
   Populate_Ipc_Data_For_Init_Stub_Sensors(p_ipc_m2d_one_time, p_ipc_m2d);
   Populate_Ipc_Data_For_Stub_Host(p_ipc_d2m, p_ipc_m2d);
   Populate_Ipc_Data_For_Stub_Dets();
#endif

   /* Initialize sensors if not done on previous cycle due to CAN partner sensor data unavailability */
   Init_Sensors(p_ipc_m2d_one_time, p_ipc_m2d);

   /* Update sensor and detection cycle-to-cycle inputs */
   Update_Sensors(p_ipc_d2m, p_ipc_m2d);
   Update_DS_Dets(p_ipc_d2m, p_ipc_m2d);

   static bool first_host_timestamp_received  = false;
   static uint64_t previous_host_timestamp_us = 0U;
   bool host_data_fresh                       = false;
   /* PAA 104111 : Host data freshness check. Consider host data stale if the timestamp does not advance between consecutive
    * tracker cycles. A timestamp of 0 is treated as a special bench-test case and is always considered fresh.*/
   if (p_ipc_m2d->payload.veh_data.vse_output_valid == CODED_TRUE)
   {
      const uint64_t host_timestamp_us = ((uint64_t)p_ipc_m2d->payload.veh_data.vse_output.timestamp_secs * US_PER_S) +
                                         ((uint64_t)p_ipc_m2d->payload.veh_data.vse_output.timestamp_nanosecs / NS_PER_US);
      if (!first_host_timestamp_received)
      {
         host_data_fresh               = true;
         first_host_timestamp_received = true;
      }
      else
      {
         host_data_fresh = (host_timestamp_us >= previous_host_timestamp_us);
      }

      previous_host_timestamp_us = host_timestamp_us;
   }

   /* Consume processed VSE output from R52 IPC module. */
   if (p_ipc_m2d->payload.veh_data.vse_output_valid == CODED_TRUE && host_data_fresh)
   {
      Update_Host_From_R52_VSE_Output(&p_ipc_m2d->payload.veh_data.vse_output);
      first_valid_host_received = true;
   }
   else
   {
      if (host_data_buffering_active)
      {
         memcpy(host_buffer_write_ptr, Get_Previous_Host_Buffer_Entry(host_buffer_write_ptr), sizeof(*host_buffer_write_ptr));
      }
   }
   Update_Sensor_Motion();

   const bool rot_execution_allowed = first_main_scan_received && core_info_valid && first_valid_host_received;
/* Run OCG, SG, or neither and then run the tracker via state_manager */
#ifndef DISABLE_OCG
   Run_OCG();
   if (ocg_outputs != nullptr && rot_execution_allowed)
   {
      Get_State_Manager().execute(core_info, *host_buffer_read_ptr, *ocg_outputs, sensors, *f360_det_list, *tracker_info_log,
                                  *object_list_log);
   }
#elif !defined(DISABLE_SG)
   Run_SG();
   if (sg_output != nullptr && rot_execution_allowed)
   {
      Get_State_Manager().execute(core_info, *host_buffer_read_ptr, sg_output, sensors, *f360_det_list, *tracker_info_log,
                                  *object_list_log);
   }
#else
   if (rot_execution_allowed)
   {
      Get_State_Manager().execute(core_info, *host_buffer_read_ptr, sensors, *f360_det_list, *tracker_info_log, *object_list_log);
   }
#endif

   if (host_data_buffering_active)
   {
      /* Update host buffer pointers */
      host_buffer_write_ptr = Get_Next_Host_Buffer_Entry(host_buffer_write_ptr);
      if (core_info.cnt_loops > HOST_BUFFER_DELAY_CYCLES)
      {
         host_buffer_read_ptr = Get_Next_Host_Buffer_Entry(host_buffer_read_ptr);
      }
   }
#if MAIN_SENSOR_BUFFERING_ENABLED
   if (main_sensor_buffering_active)
   {
      /* Update main sensor buffer pointers */
      main_sensor_buffer_write_ptr = Get_Next_Main_Sensor_Buffer_Entry(main_sensor_buffer_write_ptr);
      if (core_info.cnt_loops > MAIN_SENSOR_BUFFER_DELAY_CYCLES)
      {
         main_sensor_buffer_read_ptr = Get_Next_Main_Sensor_Buffer_Entry(main_sensor_buffer_read_ptr);
      }
   }
#endif

#if defined(_DEBUG) && defined(PC_RESIM_TRACKER)
   if (enable_xtrk_logging)
   {
      f360_tracker.Write_Debug_Info(&host_calib, &host_raw, host_buffer_read_ptr, f360_det_list, sensors, ocg_outputs, nullptr);
   }
#endif
   /* Call logging functions for streams on IPC */
   Populate_Tracker_Logs();

   if (!rot_execution_allowed)
   {
      f360_tracker.Log_Objects(*object_list_log, sensors, *f360_det_list, *host_buffer_read_ptr);
   }
   /* PAA-104141 : Functional safety gate: invalidate all tracker objects when overall fault is present so downstream functions do
    * not use unsafe object data.*/
   if (p_ipc_d2m->payload.functional_safety_faults_stream.scl_output_faults.overall_fault_status !=
       SafetyControlLogic::FAULT_NOT_PRESENT_STATUS)
   {
      for (uint8_t obj_idx = 0U; obj_idx < NUMBER_OF_OBJECTS_EMB; obj_idx++)
      {
         p_ipc_d2m->payload.object_list_stream.object[obj_idx].reducedID = 0U;
      }
   }

   /* Populate scan index from AF for use as streamRefIndex of tracker streams */
   p_ipc_d2m->payload.emb_tracker_status.scan_index = p_ipc_d2m->payload.downselection_data.stream_hdr.scan_index;
}
/*
 * Function:    Update_Core_Info
 * Returns:     void
 * Parameters:  D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message structure
 * Globals:     core_info
 * Abstract:    Updates core timing and loop counters for tracker processing. When HIL mode is enabled, the current time is
 *              derived from the downselection detection timestamp instead of the R52/BBE32 tick synchronization.
 * Reentrant:   NO
 */
static void Update_Core_Info(D2M_Msg_T *p_ipc_d2m)
{
   /* Get an estimate for the current time on R52 or use the RESIM replacement function */
   uint64_t current_time_us;
#ifndef PC_RESIM_TRACKER
   if (CODED_TRUE == Get_IPC_M2D_Buffer()->payload.hil_ipc_info.hil_mode_enabled)
   {
      current_time_us = Get_HIL_R52_Time_From_BBE32(p_ipc_d2m);
   }
   else
   {
      current_time_us = Get_R52_Time_From_BBE32();
   }
#else
   current_time_us = Get_Time_For_RESIM(p_ipc_d2m);
#endif

   /* For first cycle, prev_time_us = time_us to prevent large jump */
   core_info.cnt_loops++;
   if (core_info.cnt_loops == 1U)
   {
      core_info.time_us        = current_time_us;
      core_info.prev_time_us   = current_time_us;
      core_info.elapsed_time_s = 0.0F;
      core_info_valid          = true;
   }
   else
   {
      core_info.prev_time_us = core_info.time_us;
      core_info.time_us      = current_time_us;

      if (core_info.time_us <= core_info.prev_time_us)
      {
         core_info.elapsed_time_s = 0.0F;
         core_info_valid          = false;
      }
      else
      {
         core_info.elapsed_time_s = (core_info.time_us - core_info.prev_time_us) * MICRO_SEC_TO_SEC;
         core_info_valid          = true;
      }
   }
}

/*
 * Function:    Update_Sensors
 * Returns:     void
 * Parameters:  D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message structure
 *              M2D_Msg_T *p_ipc_m2d - pointer to IPC M2D message structure
 * Globals:     sensors, main_sensor_buffer, main_sensor_buffer_length
 * Abstract:    Updates per-sensor variable data from D2M and M2D inputs, applying the timestamp workaround when middle-dwell
 *              timing is unavailable and retaining the last valid dynamic-alignment estimate during temporary dropouts.
 *              Calls Init_Partner_Sensors_Deferred() to complete partner sensor initialization when CAN data becomes valid.
 * Reentrant:   NO
 */
static void Update_Sensors(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d)
{
   /* Populate the main sensor variable data through a single path. When buffering is active, populate directly into the
      buffer write slot for use in a future cycle; otherwise populate a local staging object for immediate use this cycle. */
   Variable_Sensor_Data_T main_sensor_staging{};
   Variable_Sensor_Data_T *main_sensor_variable_data_ptr = &main_sensor_staging;
   static Variable_Sensor_Data_T previous_main_sensor_variable_data{};
   static bool first_partner_scan_received[MAX_NUMBER_OF_SENSORS]{};

#if MAIN_SENSOR_BUFFERING_ENABLED
   if (main_sensor_buffering_active)
   {
      /* Populate main sensor data to write pointer of buffer for use in future cycle */
      main_sensor_variable_data_ptr = &main_sensor_buffer_write_ptr->variable_sensor_data;
   }
#endif

   uint64_t ms_incoming_timestamp_us = 0U;
   /* Middle dwell sensor timestamp */
   if (p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec != 0 ||
       p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns != 0)
   {
      ms_incoming_timestamp_us =
         static_cast<uint64_t>(p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec) * US_PER_S +
         (p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns / NS_PER_US);
   }
   else
   {
      ms_incoming_timestamp_us = core_info.time_us - TIMESTAMP_WORKAROUND;
   }

   uint16_t ms_incoming_look_index = p_ipc_d2m->payload.downselection_data.det_list_property.lookindex;
   F360_Det_Look_ID_T ms_incoming_look_id =
      (F360_Det_Look_ID_T)(p_ipc_d2m->payload.downselection_data.det_list_property.look_type);
   bool ms_scan_available = false;

   /* The first scan is accepted once valid sensor data is received. For subsequent scans, a new scan is detected when the look
    * index differs from that of the previously processed scan.*/
   if (!first_main_scan_received)
   {
      first_main_scan_received = true;
      ms_scan_available        = true;
   }
   else
   {
      ms_scan_available = (ms_incoming_look_index != previous_main_sensor_variable_data.look_index);
   }

   /* Dynamic alignment inputs.
    * Keep the last valid estimate on temporary alignment dropouts. */
   if (p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode != 0U)
   {
      if (p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf == 2U)
      {
         vacs_boresight_az_estimated[0] =
            p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated;
      }
      if (p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf == 2U)
      {
         vacs_boresight_el_estimated[0] =
            p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated;
      }
   }

   sensors[0].vacs_boresight_az_estimated = vacs_boresight_az_estimated[0];
   sensors[0].vacs_boresight_el_estimated = vacs_boresight_el_estimated[0];

   /* New scan received */
   if (ms_scan_available)
   {
      /* Number of DS detections available OR max detections tracker will accept from this sensor */
      main_sensor_variable_data_ptr->number_of_valid_detections =
         std::min<int32_t>(p_ipc_d2m->payload.downselection_data.num_af_ds_det, sensor_det_caps[0]);

      /* Rain level */
      main_sensor_variable_data_ptr->overall_rain_level =
         0U; /* 0 until can be populated (no existing signal on input streams as of now) */

      /* Record the previous look index to check if the sensor data is stale */
      sensors_prev_scan_index[0] = sensors[0].look_index;

      /* Look index and type */
      main_sensor_variable_data_ptr->look_index = ms_incoming_look_index;
      main_sensor_variable_data_ptr->look_id    = ms_incoming_look_id;

      /* Cache the most recently received valid scan. */
      previous_main_sensor_variable_data = *main_sensor_variable_data_ptr;
   }
   else
   {
      *main_sensor_variable_data_ptr                            = previous_main_sensor_variable_data;
      main_sensor_variable_data_ptr->number_of_valid_detections = 0U;
   }

   main_sensor_variable_data_ptr->timestamp_us = ms_incoming_timestamp_us;

   /* Populate the appropriate (possibly delayed) variable data into the live sensor for use by the tracker this cycle */
#if MAIN_SENSOR_BUFFERING_ENABLED
   if (main_sensor_buffering_active)
   {
      /* Load main sensor data from read pointer of buffer for use in tracker this cycle */
      Load_Variable_Data_To_Sensor(&sensors[0], &main_sensor_buffer_read_ptr->variable_sensor_data);
   }
   else
#endif
   {
      Load_Variable_Data_To_Sensor(&sensors[0], main_sensor_variable_data_ptr);
   }

   /* Populate partner sensor data */
   for (uint8_t sensor_index = 1; sensor_index < max_sensors_to_update; sensor_index++)
   {
      const uint8_t partner_sensor_index                     = sensor_index - 1U;
      F360_Radar_Sensor_T *partner_sensor_ptr                = &sensors[sensor_index];
      const Partner_Sensor_Stream_T *partner_source_data_ptr = &p_ipc_m2d->payload.partners_data;

      /* Skip data update if critical CAN data not received or stale (per-cycle validity check) */
      if (partner_source_data_ptr->partner_sensor_diag_data[partner_sensor_index].status_recvd_flag != 1U ||
          partner_source_data_ptr->partner_sensor_diag_data[partner_sensor_index].det_recvd_flag != 1U)
      {
         /* Mark detection count as zero when data invalid - tracker will skip this sensor for this cycle */
         partner_sensor_ptr->number_of_valid_detections = 0;
         continue;
      }

      uint16_t incoming_look_index = partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].look_index;

      bool partner_scan_available = false;
      if (!first_partner_scan_received[sensor_index])
      {
         first_partner_scan_received[sensor_index] = true;
         partner_scan_available                    = true;
      }
      else
      {
         partner_scan_available = (incoming_look_index != partner_sensor_ptr->look_index);
      }

      /*Disable fusion activities as per HIL user request*/
      partner_sensor_ptr->is_valid = (p_ipc_m2d->payload.hil_ipc_info.hil_request_disable_fusion != CODED_TRUE);

      /* Dynamic alignment inputs.
       * Keep the last valid estimate on temporary alignment dropouts. */
      if (partner_source_data_ptr->partner_sensor_alignment_info[partner_sensor_index].alignment_mode != 0U &&
          partner_source_data_ptr->partner_sensor_alignment_info[partner_sensor_index].alignment_error_status_combined == 0U)
      {
         vacs_boresight_az_estimated[sensor_index] =
            partner_source_data_ptr->partner_sensor_alignment_info[partner_sensor_index].vacs_boresight_az_estimated;
         vacs_boresight_el_estimated[sensor_index] =
            partner_source_data_ptr->partner_sensor_alignment_info[partner_sensor_index].vacs_boresight_el_estimated;
      }

      partner_sensor_ptr->vacs_boresight_az_estimated = vacs_boresight_az_estimated[sensor_index];
      partner_sensor_ptr->vacs_boresight_el_estimated = vacs_boresight_el_estimated[sensor_index];

      /* Middle dwell sensor timestamp */
      if (partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].ts_mid_dwell_sec != 0 ||
          partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].ts_mid_dwell_nanosec != 0)
      {
         partner_sensor_ptr->timestamp_us =
            static_cast<uint64_t>(partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].ts_mid_dwell_sec) *
               US_PER_S +
            (partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].ts_mid_dwell_nanosec / NS_PER_US);
      }
      else
      {
         partner_sensor_ptr->timestamp_us = core_info.time_us - TIMESTAMP_WORKAROUND;
      }

      if (partner_scan_available)
      {
         /* Number of DS detections available OR max detections tracker will accept from this sensor */
         partner_sensor_ptr->number_of_valid_detections =
            std::min<int32_t>(partner_source_data_ptr->partner_sensor_det_data.num_af_det, sensor_det_caps[sensor_index]);

         /* Rain level */
         partner_sensor_ptr->overall_rain_level = 0; /* 0 until can be populated (no existing signal on input streams as of now) */

         /* Record the previous look index to check if the sensor data is stale */
         sensors_prev_scan_index[sensor_index] = partner_sensor_ptr->look_index;

         /* Look index and type */
         partner_sensor_ptr->look_index = partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].look_index;
         partner_sensor_ptr->look_id =
            (F360_Det_Look_ID_T)partner_source_data_ptr->partner_det_list_property_data[partner_sensor_index].look_type;
      }
      else
      {
         /* No new data available. Partner sensor signals will be unchanged from previous cycle. Keep
          * number_of_valid_detections as zero. */
         partner_sensor_ptr->number_of_valid_detections = 0U;
      }
   }

   /* Verify Timestamp difference between detection lists shall be  < 25 ms */
   // if (max_sensors_to_update > 1)
   // {
   //    uint64_t min_timestamp_us = UINT64_MAX;
   //    uint64_t max_timestamp_us = 0U;
   //    for (uint8_t sensor_index = 0U; sensor_index < max_sensors_to_update; sensor_index++)
   //    {
   //       min_timestamp_us = std::min(min_timestamp_us, sensors[sensor_index].timestamp_us);
   //       max_timestamp_us = std::max(max_timestamp_us, sensors[sensor_index].timestamp_us);
   //    }
   // }
}

/*
 * Function:    Update_Sensor_Motion
 * Returns:     void
 * Parameters:  None
 * Globals:     host_calib, host_buffer_read_ptr, sensors, max_sensors_to_update
 * Abstract:    Updates each sensor's VCS velocity components from host motion and mounting position.
 * Reentrant:   NO
 */
static void Update_Sensor_Motion(void)
{
   /* This function comes direct from the algorithm team and will be moved inside the algorithm in the future */

   float32_t xsens = 0.0f;
   float32_t ysens = 0.0f;
   float32_t rear_sideslip;
   float32_t cb = 0.0f;
   float32_t sb = 0.0f;

   rear_sideslip = -(host_calib.rear_cornering_compliance) *
                   (host_buffer_read_ptr->curvature_rear * host_buffer_read_ptr->speed * host_buffer_read_ptr->speed);
   cb = cosf(rear_sideslip);
   sb = sinf(rear_sideslip);

   for (uint8_t sensor_index = 0; sensor_index < max_sensors_to_update; sensor_index++)
   {
      /* Sensor position relative to center of rear axle (in VCS-aligned coordinates) */
      xsens = host_buffer_read_ptr->dist_rear_axle_to_vcs_m + sensors[sensor_index].mounting_position.vcs_position.longitudinal;
      ysens = sensors[sensor_index].mounting_position.vcs_position.lateral;

      /* VCS components of OTG velocity of sensor */
      sensors[sensor_index].vcs_velocity.longitudinal =
         (host_buffer_read_ptr->speed * cb) - (host_buffer_read_ptr->yaw_rate_rad * ysens);
      sensors[sensor_index].vcs_velocity.lateral =
         (host_buffer_read_ptr->speed * sb) + (host_buffer_read_ptr->yaw_rate_rad * xsens);
   }
}

/*
 * Function:    Update_Host_From_R52_VSE_Output
 * Returns:     void
 * Parameters:  const Vse_Output_T *p_vse_output - pointer to processed host output from R52
 * Globals:     host_buffer_write_ptr
 * Abstract:    Copies R52-processed VSE host output into tracker host buffer write entry.
 * Reentrant:   NO
 */
static void Update_Host_From_R52_VSE_Output(const Vse_Output_T *p_vse_output)
{
   const float abs_speed = hypotf(p_vse_output->vcs_long_velocity, p_vse_output->vcs_lat_velocity);

   host_buffer_write_ptr->vehicle_index               = p_vse_output->veh_index;
   host_buffer_write_ptr->speed                       = p_vse_output->signed_filt_veh_speed_over_ground;
   host_buffer_write_ptr->vcs_speed                   = (0.0F > p_vse_output->vcs_long_velocity) ? (-1.0F * abs_speed) : abs_speed;
   host_buffer_write_ptr->acceleration                = p_vse_output->vcs_long_accel;
   host_buffer_write_ptr->vcs_lat_acceleration        = p_vse_output->vcs_lat_accel;
   host_buffer_write_ptr->vcs_long_acceleration       = p_vse_output->vcs_long_accel;
   host_buffer_write_ptr->yaw_rate_rad                = p_vse_output->comp_yaw_rate_filtered;
   host_buffer_write_ptr->vcs_sideslip                = p_vse_output->vcs_sideslip;
   host_buffer_write_ptr->curvature_rear              = p_vse_output->curvature_rear_axle;
   host_buffer_write_ptr->dist_rear_axle_to_vcs_m     = host_calib.dist_rear_axle_to_vcs_m;
   host_buffer_write_ptr->vehicle_length              = host_calib.vehicle_length_m;
   host_buffer_write_ptr->vehicle_width               = host_calib.vehicle_width_m;
   host_buffer_write_ptr->rear_cornering_compliance   = host_calib.rear_cornering_compliance;
   host_buffer_write_ptr->speed_correction_factor     = p_vse_output->speed_compensation_factor;
   host_buffer_write_ptr->host_type                   = HOST_TYPE;
   host_buffer_write_ptr->f_trailer_presence_hardware = false; // TODO: Need to populate from VSE stream when available
   host_buffer_write_ptr->speed_qf                    = p_vse_output->filt_veh_speed_over_ground_qf;
   host_buffer_write_ptr->yaw_rate_qf                 = p_vse_output->comp_yaw_rate_qf;
   host_buffer_write_ptr->lat_accel_qf                = p_vse_output->vcs_lat_accel_qf;
   host_buffer_write_ptr->long_accel_qf               = p_vse_output->vcs_long_accel_qf;

   /* Populate one value of host_raw for logging purposes */
   host_raw.timestamp_us =
      (static_cast<uint64_t>(p_vse_output->timestamp_secs) * US_PER_S) + (p_vse_output->timestamp_nanosecs / NS_PER_US);
}

/*
 * Function:    Update_DS_Dets
 * Returns:     void
 * Parameters:  D2M_Msg_T *p_ipc_d2m - pointer to IPC D2M message
 *              M2D_Msg_T *p_ipc_m2d - pointer to IPC M2D message
 * Globals:     main_sensor_buffer, main_sensor_buffer_length
 * Abstract:    Copies downselection detections into f360_det_list, skipping stale sensor data and applying buffering when enabled.
 * Reentrant:   NO
 */
static void Update_DS_Dets(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d)
{
   uint32_t f360_det_list_index = 0;

   bool main_sensor_data_valid = true;

   const uint8_t skip_tolerance      = 5;
   const int32_t rollover_adjustment = (int32_t)skip_tolerance - (int32_t)UINT16_MAX;

   /* Check main sensor scan index is stale or skipped too many values */
   int32_t main_index_diff = (int32_t)sensors[0].look_index - (int32_t)sensors_prev_scan_index[0];
   if ((main_index_diff <= 0 && main_index_diff >= rollover_adjustment) || (main_index_diff > skip_tolerance))
   {
      main_sensor_data_valid = false;
   }

   if (main_sensor_data_valid)
   {
      uint32_t main_sensor_num_dets = sensors[0].number_of_valid_detections;

#if MAIN_SENSOR_BUFFERING_ENABLED
      if (main_sensor_buffering_active)
      {
         main_sensor_num_dets = main_sensor_buffer_write_ptr->variable_sensor_data.number_of_valid_detections;
      }
#endif

      F360_Detection_T *main_sensor_raw_det_ptr = nullptr;

      for (uint32_t det_index = 0; det_index < main_sensor_num_dets; det_index++)
      {
         /* Populate main sensor detections directly when no delay buffering is configured */
         main_sensor_raw_det_ptr = &f360_det_list->detections[det_index];
#if MAIN_SENSOR_BUFFERING_ENABLED
         if (main_sensor_buffering_active)
         {
            /* Populate main sensor detections to write pointer of buffer */
            main_sensor_raw_det_ptr = &main_sensor_buffer_write_ptr->raw_det_data[det_index];
         }
#endif

         /* Get rdd_idx for this detection to index into RDD stream as needed */
         int16_t rdd_index = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].rdd_idx;

         (void)rdd_index; /* Currently unused, but will be needed to index into RDD stream for additional inputs in the future */

         main_sensor_raw_det_ptr->range            = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].ran;
         main_sensor_raw_det_ptr->range_rate       = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].vel;
         main_sensor_raw_det_ptr->azimuth          = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].theta;
         main_sensor_raw_det_ptr->elevation        = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].phi;
         main_sensor_raw_det_ptr->snr              = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].snr;
         main_sensor_raw_det_ptr->rcs              = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].rcs;
         main_sensor_raw_det_ptr->prob_1stazhypo   = 1;
         main_sensor_raw_det_ptr->sensor_id        = 1;
         main_sensor_raw_det_ptr->det_id           = det_index + 1;
         main_sensor_raw_det_ptr->confid_azimuth   = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].az_conf;
         main_sensor_raw_det_ptr->confid_elevation = p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].el_conf;
         main_sensor_raw_det_ptr->f_super_res =
            static_cast<bool>(p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].f_superres_target);
         main_sensor_raw_det_ptr->f_host_veh_clutter =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         main_sensor_raw_det_ptr->f_nd_target =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         main_sensor_raw_det_ptr->f_bistatic =
            static_cast<bool>(p_ipc_d2m->payload.downselection_data.af_ds_dets[det_index].f_bistatic);
         main_sensor_raw_det_ptr->f_ci_det = false; /* false - CI detections are no longer supported */
         main_sensor_raw_det_ptr->f_idm_det =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         main_sensor_raw_det_ptr->f_below_rain_thold =
            false; /* false until can be populated (no existing signal on input streams as of now) */
      }

      f360_det_list_index = main_sensor_num_dets;
#if MAIN_SENSOR_BUFFERING_ENABLED
      if (main_sensor_buffering_active)
      {
         /* Load main sensor detections from read pointer of buffer */
         f360_det_list_index = 0;
         for (uint32_t det_index = 0; det_index < main_sensor_buffer_read_ptr->variable_sensor_data.number_of_valid_detections;
              det_index++)
         {
            f360_det_list->detections[f360_det_list_index] = main_sensor_buffer_read_ptr->raw_det_data[det_index];
            f360_det_list_index++;
         }
      }
#endif
   }
   /* Loop for each partner sensor and populate detection data */
   for (uint8_t sensor_index = 1; sensor_index < max_sensors_to_update; sensor_index++)
   {
      /* Skip the partner sensor's detections if the scan index is stale or skipped too many values */
      int32_t partner_index_diff = (int32_t)sensors[sensor_index].look_index - (int32_t)sensors_prev_scan_index[sensor_index];
      if ((partner_index_diff <= 0 && partner_index_diff >= rollover_adjustment) || (partner_index_diff > skip_tolerance))
      {
         continue;
      }
      /* Populate partner sensor detections to f360_det_list */
      const Partner_Sensor_Stream_T *partner_source_data_ptr = &p_ipc_m2d->payload.partners_data;
      for (uint32_t det_index = 0; det_index < sensors[sensor_index].number_of_valid_detections; det_index++)
      {
         F360_Detection_T *f360_det_list_raw_index_ptr = &f360_det_list->detections[f360_det_list_index];

         f360_det_list_raw_index_ptr->range          = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].ran;
         f360_det_list_raw_index_ptr->range_rate     = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].vel;
         f360_det_list_raw_index_ptr->azimuth        = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].theta;
         f360_det_list_raw_index_ptr->elevation      = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].phi;
         f360_det_list_raw_index_ptr->snr            = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].snr;
         f360_det_list_raw_index_ptr->rcs            = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].rcs;
         f360_det_list_raw_index_ptr->prob_1stazhypo = 1;
         f360_det_list_raw_index_ptr->sensor_id = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].sensor_id;
         f360_det_list_raw_index_ptr->det_id    = det_index + 1;
         f360_det_list_raw_index_ptr->confid_azimuth = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].az_conf;
         f360_det_list_raw_index_ptr->confid_elevation =
            partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].el_conf;
         f360_det_list_raw_index_ptr->f_super_res =
            static_cast<bool>(partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].f_superres_target);
         f360_det_list_raw_index_ptr->f_host_veh_clutter =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         f360_det_list_raw_index_ptr->f_nd_target =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         f360_det_list_raw_index_ptr->f_bistatic =
            static_cast<bool>(partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].f_bistatic);
         f360_det_list_raw_index_ptr->f_ci_det = partner_source_data_ptr->partner_sensor_det_data.ps_dets[det_index].f_ci_det;
         f360_det_list_raw_index_ptr->f_idm_det =
            false; /* false until can be populated (no existing signal on input streams as of now) */
         f360_det_list_raw_index_ptr->f_below_rain_thold =
            false; /* false until can be populated (no existing signal on input streams as of now) */

         f360_det_list_index++;
      }
   }

   f360_det_list->number_of_valid_detections = f360_det_list_index;
}

/*
 * Function:    Run_OCG
 * Returns:     void
 * Parameters:  void
 * Globals:     ocg_inputs, ocg_grid, ocg_initialized, runtime_enable_ocg, sensors, front_center_sensor_index,
 *              f360_det_list, host_buffer_read_ptr, core_info
 * Abstract:    Performs deferred OCG initialization on first cycle where runtime_enable_ocg becomes true.
 *              Returns early if OCG not enabled. Otherwise, prepares front-center sensor inputs and runs OCG.
 * Reentrant:   NO
 */
#ifndef DISABLE_OCG
static void Run_OCG(void)
{
   /* Return early if OCG not enabled */
   if (!runtime_enable_ocg)
   {
      return;
   }

   /* Initialize OCG on first cycle where runtime_enable_ocg becomes true */
   if (!ocg_initialized)
   {
      ocg_inputs->host.dist_rear_axle_to_vcs_m = host_calib.dist_rear_axle_to_vcs_m;
      ocg_inputs->sensor.vcs_position_x        = sensors[front_center_sensor_index].mounting_position.vcs_position.longitudinal;
      ocg_inputs->sensor.vcs_position_y        = sensors[front_center_sensor_index].mounting_position.vcs_position.lateral;
      ocg_inputs->sensor.vcs_position_z        = sensors[front_center_sensor_index].mounting_position.vcs_position.height;
      ocg_inputs->sensor.polarity              = sensors[front_center_sensor_index].polarity;
      ocg_grid.initialize(*ocg_inputs);
      ocg_initialized = true;
   }

   /* Update variable sensor data for OCG execution */
   ocg_inputs->sensor.timestamp_us = sensors[front_center_sensor_index].timestamp_us;
   ocg_inputs->sensor.v_wrapping   = sensors[front_center_sensor_index].v_wrapping[sensors[front_center_sensor_index].look_id];
   ocg_inputs->sensor.vacs_boresight_az_estimated = sensors[front_center_sensor_index].vacs_boresight_az_estimated;
   ocg_inputs->sensor.vacs_boresight_el_estimated = sensors[front_center_sensor_index].vacs_boresight_el_estimated;

   /* Update detections' data for OCG execution */
   uint16_t ocg_det_index = 0;
   for (uint16_t det_index = 0; det_index < f360_det_list->number_of_valid_detections; det_index++)
   {
      if (f360_det_list->detections[det_index].sensor_id == front_center_sensor_index + 1)
      {
         ocg_inputs->detection_list.detections[ocg_det_index].range          = f360_det_list->detections[det_index].range;
         ocg_inputs->detection_list.detections[ocg_det_index].range_rate     = f360_det_list->detections[det_index].range_rate;
         ocg_inputs->detection_list.detections[ocg_det_index].azimuth        = f360_det_list->detections[det_index].azimuth;
         ocg_inputs->detection_list.detections[ocg_det_index].elevation      = f360_det_list->detections[det_index].elevation;
         ocg_inputs->detection_list.detections[ocg_det_index].rcs            = f360_det_list->detections[det_index].rcs;
         ocg_inputs->detection_list.detections[ocg_det_index].confid_azimuth = f360_det_list->detections[det_index].confid_azimuth;
         ocg_inputs->detection_list.detections[ocg_det_index].confid_elevation =
            f360_det_list->detections[det_index].confid_elevation;
         ocg_inputs->detection_list.detections[ocg_det_index].f_super_res = f360_det_list->detections[det_index].f_super_res;
         ocg_det_index++;
      }
   }
   ocg_inputs->detection_list.number_of_valid_detections = sensors[front_center_sensor_index].number_of_valid_detections;

   /* Update host data for OCG execution */
   ocg_inputs->host.speed          = host_buffer_read_ptr->speed;
   ocg_inputs->host.curvature_rear = host_buffer_read_ptr->curvature_rear;
   ocg_inputs->host.vcs_speed      = host_buffer_read_ptr->vcs_speed;
   ocg_inputs->host.yaw_rate_rad   = host_buffer_read_ptr->yaw_rate_rad;
   ocg_inputs->host.vcs_sideslip   = host_buffer_read_ptr->vcs_sideslip;

   /* Run OCG and get output */
   ocg_grid.step(static_cast<double>(core_info.time_us), *ocg_inputs);
   ocg_grid.get_output(*ocg_outputs);
}

/*
 * Function:    Run_SG
 * Returns:     void
 * Parameters:  void
 * Globals:     sg_tracker, processed_detection_log, f360_det_list, sensors, rspp_host, sg_output, core_info
 * Abstract:    Prepares inputs and runs SG.
 * Reentrant:   NO
 */
#elif !defined(DISABLE_SG)
static void Run_SG(void)
{
   sg_tracker.step(core_info.time_us, *processed_detection_log, *f360_det_list,
                   reinterpret_cast<const rspp_variant_A::F360_Radar_Sensor_T(&)[rspp_variant_A::MAX_NUMBER_OF_SENSORS]>(sensors),
                   rspp_host);
   sg_tracker.get_output(*sg_output);
}
#endif

/*
 * Function:    Populate_Tracker_Logs
 * Returns:     void
 * Parameters:  void
 * Globals:     f360_tracker
 * Abstract:    Populates all tracker IPC logs from the current sensor and host state.
 * Reentrant:   NO
 */
static void Populate_Tracker_Logs(void)
{
   /* Call logging functions for tracker streams */
   f360_tracker.Log_Sync_Info(*sync_info_log, *host_buffer_read_ptr, sensors);
   f360_tracker.Log_Vehicle_Info(*vehicle_info_log, *host_buffer_read_ptr, host_raw, sensors);
   f360_tracker.Log_Tracker_Info(tracker_info_log);
   f360_tracker.Log_Timing_Info(timing_info_log);
   f360_tracker.Log_Host_Calibs(*host_calibs_log, host_calib);
   f360_tracker.Log_F360_Host_Props(*host_props_log);
   f360_tracker.Log_Static_Env_Polys(static_env_poly_log);
   Get_State_Manager().Log_Functional_Safety_Faults(*functional_safety_faults_log);
   /* Note: Log_Objects not called because state_manager already calls it */
   /*f360_tracker.Log_Objects(*object_list_log);*/
   f360_tracker.Log_Detections(*processed_detection_log, *f360_det_list, *host_buffer_read_ptr);
   f360_tracker.Log_Sensor_Calibs(*sensor_calib_log, sensors);
   f360_tracker.Log_Trailer_Detector(trailer_detector_log);
   f360_tracker.Log_CV_Trailer_Output(cv_trailer_log);

#if ENABLE_INTERNAL_TRACKER_STREAMS
   /* Call logging functions for internal tracker streams */
   f360_tracker.Log_Internal_Trailer_Detector(*internal_trailer_detector_log);
   f360_tracker.Log_Internal_Objects(*internal_object_log);
   f360_tracker.Log_Internal_Clusters(*internal_cluster_log);
   f360_tracker.Log_Internal_Detection_History(*internal_detection_hist_log);
   f360_tracker.Log_Internal_Reflection_Buffer(*internal_reflection_buffer_log);
   f360_tracker.Log_Internal_CWD(*internal_cwd_log);
#endif
}

/*
 * Function:    Map_Ref_Point_To_Len_Wid_Segments
 * Returns:     void
 * Parameters:  uint8_t reference_point - object reference point value
 *              float32_t length - object length
 *              float32_t width - object width
 *              Len_Wid_Segments *segments - output segment values
 * Globals:     None
 * Abstract:    Splits object length and width into segments based on the reference point.
 * Reentrant:   NO
 */
void Map_Ref_Point_To_Len_Wid_Segments(uint8_t reference_point, float32_t length, float32_t width, Len_Wid_Segments *segments)
{
   switch (reference_point)
   {
      case F360_REFERENCE_POINT_FRONT_LEFT:
         segments->len1 = length;
         segments->len2 = 0.0f;
         segments->wid1 = 0.0f;
         segments->wid2 = width;
         break;
      case F360_REFERENCE_POINT_FRONT:
         segments->len1 = length;
         segments->len2 = 0.0f;
         segments->wid1 = width * 0.5f;
         segments->wid2 = width * 0.5f;
         break;
      case F360_REFERENCE_POINT_FRONT_RIGHT:
         segments->len1 = length;
         segments->len2 = 0.0f;
         segments->wid1 = width;
         segments->wid2 = 0.0f;
         break;
      case F360_REFERENCE_POINT_RIGHT:
         segments->len1 = length * 0.5f;
         segments->len2 = length * 0.5f;
         segments->wid1 = width;
         segments->wid2 = 0.0f;
         break;
      case F360_REFERENCE_POINT_REAR_RIGHT:
         segments->len1 = 0.0f;
         segments->len2 = length;
         segments->wid1 = width;
         segments->wid2 = 0.0f;
         break;
      case F360_REFERENCE_POINT_REAR:
         segments->len1 = 0.0f;
         segments->len2 = length;
         segments->wid1 = width * 0.5f;
         segments->wid2 = width * 0.5f;
         break;
      case F360_REFERENCE_POINT_REAR_LEFT:
         segments->len1 = 0.0f;
         segments->len2 = length;
         segments->wid1 = 0.0f;
         segments->wid2 = width;
         break;
      case F360_REFERENCE_POINT_LEFT:
         segments->len1 = length * 0.5f;
         segments->len2 = length * 0.5f;
         segments->wid1 = 0.0f;
         segments->wid2 = width;
         break;
      default:
         segments->len1 = length * 0.5f;
         segments->len2 = length * 0.5f;
         segments->wid1 = width * 0.5f;
         segments->wid2 = width * 0.5f;
         break;
   }
}

#if defined(PC_RESIM_TRACKER)
/*
 * Function:    Get_Time_For_RESIM
 * Returns:     uint64_t
 * Parameters:  D2M_Msg_T *p_ipc_d2m - pointer to the IPC D2M message
 * Globals:     TIMESTAMP_WORKAROUND
 * Abstract:    Returns the downselection detection timestamp in microseconds for RESIM, with the tracker timestamp workaround
 *              applied so PC wall time does not influence tracker timing.
 * Reentrant:   NO
 */
uint64_t Get_Time_For_RESIM(D2M_Msg_T *p_ipc_d2m)
{
   /* Use only the detection timestamp. PC wall time depends on host performance and can drift from the detection timeline. */
   static uint64_t timestamp_us = 0;
   #if 1
   /* Down-selection stream detection timestamp */
   timestamp_us =
      static_cast<uint64_t>(p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_sec) * US_PER_S +
      (p_ipc_d2m->payload.downselection_data.det_list_property.detection_timestamp_ns / NS_PER_US) + TIMESTAMP_WORKAROUND;
   #else
   /* Timestamp which increments by 50ms every call */
   /* Note: If used, this will likely drift over time and end up setting the timestamp divergence fault in the tracker. */
   timestamp_us += 50000U;
   #endif

   return timestamp_us;
}

   #if defined(_DEBUG)
/*
 * Function:    Open_F360_Tracker_Xtrk_File
 * Returns:     void
 * Parameters:  const char *xtrk_filename - pointer to the Xtrk file name
 * Globals:     enable_xtrk_logging
 * Abstract:    Opens the Xtrk file for logging.
 * Reentrant:   NO
 */
void Open_F360_Tracker_Xtrk_File(const char *xtrk_filename)
{
   if (xtrk_filename && *xtrk_filename)
   {
      f360_tracker.Open_Debug_Info(xtrk_filename);
      enable_xtrk_logging = true;
   }
}

/*
 * Function:    Close_F360_Tracker_Xtrk_File
 * Returns:     void
 * Parameters:  None
 * Globals:     enable_xtrk_logging
 * Abstract:    Closes the Xtrk file for logging.
 * Reentrant:   NO
 */
void Close_F360_Tracker_Xtrk_File()
{
   if (enable_xtrk_logging)
   {
      f360_tracker.Close_Debug_Info();
      enable_xtrk_logging = false;
   }
}
   #endif
#endif
