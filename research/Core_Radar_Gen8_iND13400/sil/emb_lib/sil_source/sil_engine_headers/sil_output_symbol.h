#ifndef SIL_OUTPUT_SYMBOL
#define SIL_OUTPUT_SYMBOL

#define RADAR_DEBUG_TYPE_STRUCTURE_VERSION (3)
#define NUMBER_OF_OBJECTS                  (48)
#define NUMBER_OF_GUARDRAILS               (2)
#define LCDA_NUMBER_OF_OBJECT_L            (4)
#define BSIS_FBK_NUMBER_OF_SIDES           (2U)

#include "sil_input_symbol.h"

#pragma pack(push, 2)

#ifndef _DEBUG_GUARDRAIL_OUTPUT_T_
   #define _DEBUG_GUARDRAIL_OUTPUT_T_
typedef struct DEBUG_GUARDRAIL_OUTPUT
{
   uint8_t f_active:1;            //!< flag indicating that this guardrail is enabled
   uint8_t f_guardrail_present:1; //!< flag indicating that a guardrail exists near the sensor
   float lateral_position;        //!< [m] guardrail lateralPosition
   DEBUG_TRAC_STATUS_T status;    //!< available values are INVALID, NEW, MATURE, and COASTED

} DEBUG_GUARDRAIL_OUTPUT_T;
#endif

/* Tracker */
typedef struct RADAR_TRACKER_OUTPUT_Tag
{
   uint8_t f_updated:1;   /**< flag indicating the tracker output has been updated */
   uint8_t major_version; /**< major version of the tracker */
   uint8_t minor_version; /**< minor version of the tracker */
   float32_t
      max_measured_range_current_look; /**< [m] maximum measured range current look. In case detection saturation is detected the
                                        * measured maximum range is shown, the sensors range coverage (all looks) otherwise. */
#ifndef TRACKER_SUPPRESS_ID
   int8_t
      id[NUMBER_OF_OBJECTS]; /**< For compatibility with older features: id=index+1. the id field will be removed, do not use. */
#endif
   uint8_t distinct_id[NUMBER_OF_OBJECTS]; /**< Distinctive id of this object. A distinctive id is not connected in any way to the
                                              index of an object.*/
   DEBUG_TRAC_STATUS_T status[NUMBER_OF_OBJECTS];      /**< available values are INVALID, NEW, MATURE, and COASTED */
   uint8_t age[NUMBER_OF_OBJECTS];                     /**< number of scans this object has existed */
   uint8_t stage_age[NUMBER_OF_OBJECTS];               /**< number of consecutive scans this object has had the same status */
   float32_t existence_probability[NUMBER_OF_OBJECTS]; /**< existence probability of object */
   float32_t eclipse_value[NUMBER_OF_OBJECTS];         /**< eclipse value of object */
   float32_t priority_value[NUMBER_OF_OBJECTS];        /**< priority value of object = lower value indicates higher priority */
   int8_t
      priority_number[NUMBER_OF_OBJECTS]; /**< one-based index of rank of this object (1 is highest) according to priority value */
   float32_t vcs_long_posn[NUMBER_OF_OBJECTS];           /**< [m] longitudinal position of object in vcs coordinates */
   float32_t vcs_long_vel[NUMBER_OF_OBJECTS];            /**< [m/s] longitudinal velocity of object in vcs coordinates */
   float32_t vcs_long_accel[NUMBER_OF_OBJECTS];          /**< [m/s^2] longitudinal acceleration of object in vcs coordinates */
   float32_t vcs_lat_posn[NUMBER_OF_OBJECTS];            /**< [m] lateral position of object in vcs coordinates */
   float32_t vcs_lat_vel[NUMBER_OF_OBJECTS];             /**< [m/s] lateral velocity of object in vcs coordinates */
   float32_t vcs_lat_accel[NUMBER_OF_OBJECTS];           /**< [m/s^2] lateral acceleration of object in vcs coordinates */
   float32_t vcs_long_vel_rel[NUMBER_OF_OBJECTS];        /**< [m/s] relative longitudinal velocity of object in vcs coordinates */
   float32_t vcs_lat_vel_rel[NUMBER_OF_OBJECTS];         /**< [m/s] relative lateral velocity of object in vcs coordinates */
   uint8_t f_stationary[NUMBER_OF_OBJECTS];              /**< flag indicating object is currently stationary */
   uint8_t f_moveable[NUMBER_OF_OBJECTS];                /**< flag indicating object was non-stationary before */
   float32_t speed[NUMBER_OF_OBJECTS];                   /**< [m/s^2] speed of the object in vcs coordinates */
   float32_t tangential_accel[NUMBER_OF_OBJECTS];        /**< [m/s^2] tangential acceleration of the object in vcs coordinates */
   float32_t heading[NUMBER_OF_OBJECTS];                 /**< [rad] heading of the object in vcs coordinates */
   float32_t heading_rate[NUMBER_OF_OBJECTS];            /**< [rad] heading of the object in vcs coordinates */
   float32_t object_distance[NUMBER_OF_OBJECTS];         /**< minimum distance from border of host vehicle to border of object */
   float32_t length[NUMBER_OF_OBJECTS];                  /**< [m] length of the target vehicle */
   float32_t width[NUMBER_OF_OBJECTS];                   /**< [m] width of the target vehicle */
   DEBUG_OBJECT_CLASS_T object_class[NUMBER_OF_OBJECTS]; /**< classification of the object based on target size */
   DEBUG_OBJECT_CLASS_PROBABILITY_T
   object_class_probability[NUMBER_OF_OBJECTS]; /**< probability that the object is of a specific class */
   DEBUG_REFERENCE_POSITION_T
   ref_position[NUMBER_OF_OBJECTS];               /**< enumeration indicating where the reference point is on the target vehicle */
   float32_t ref_long_posn[NUMBER_OF_OBJECTS];    /**< [m] longitudinal position of reference point in vcs coordinates */
   float32_t ref_long_vel[NUMBER_OF_OBJECTS];     /**< [m/s] longitudinal velocity of reference point in vcs coordinates */
   float32_t ref_long_accel[NUMBER_OF_OBJECTS];   /**< [m/s^2] longitudinal acceleration of reference point in vcs coordinates */
   float32_t ref_lat_posn[NUMBER_OF_OBJECTS];     /**< [m] lateral position of reference point in vcs coordinates */
   float32_t ref_lat_vel[NUMBER_OF_OBJECTS];      /**< [m/s] lateral velocity of reference point in vcs coordinates */
   float32_t ref_lat_accel[NUMBER_OF_OBJECTS];    /**< [m/s^2] lateral acceleration of reference point in vcs coordinates */
   uint8_t f_ref_updated[NUMBER_OF_OBJECTS];      /**< flag indicating if reference point has been updated */
   float32_t curvi_long_posn[NUMBER_OF_OBJECTS];  /**< [m] longitudinal position of object in curvi coordinates */
   float32_t curvi_long_vel[NUMBER_OF_OBJECTS];   /**< [m/s] longitudinal velocity of object in curvi coordinates */
   float32_t curvi_long_accel[NUMBER_OF_OBJECTS]; /**< [m/s^2] longitudinal acceleration of object in curvi coordinates */
   float32_t curvi_lat_posn[NUMBER_OF_OBJECTS];   /**< [m] lateral position of object in curvi coordinates */
   float32_t curvi_lat_vel[NUMBER_OF_OBJECTS];    /**< [m/s] lateral velocity of object in curvi coordinates */
   float32_t curvi_lat_accel[NUMBER_OF_OBJECTS];  /**< [m/s^2] lateral acceleration of object in curvi coordinates */
   float32_t curvi_long_vel_rel[NUMBER_OF_OBJECTS]; /**< [m/s] relative longitudinal velocity of object in curvi coordinates */
   float32_t curvi_lat_vel_rel[NUMBER_OF_OBJECTS];  /**< [m/s] relative lateral velocity of object in curvi coordinates */
   float32_t curvi_heading[NUMBER_OF_OBJECTS];      /**< [rad] heading of the object in curvi coordinates */
   uint8_t f_just_merged[NUMBER_OF_OBJECTS];        /**< this object has been merged in current cycle */
   int8_t f_just_merged_with[NUMBER_OF_OBJECTS]; /**< id of object this object was merged with. -1 if object has not been merged in
                                                  * current cycle or if the object it has been merged with has been created in the
                                                  * current cycle. In this case the merged object never has been reported and the
                                                  * ID does not matter for features. It still may be of interest to know that a
                                                  * merge took place, therefore f_just_merged will be TRUE. */
   uint8_t f_just_redivided[NUMBER_OF_OBJECTS];  /**< This object has been intentionally redivided */
   uint8_t
      f_behind_guardrail[NUMBER_OF_OBJECTS];          /**< This object is located behind a guardrail.
                                                       * The structure TRACKER_STATUS_T has a member f_tracking_behind_guardrails_enabled
                                                       * that indicates if the tracker is set up to produce objects that have this flag
                                                       * set. \sa TRACKER_STATUS_T::f_tracking_behind_guardrails_enabled */
   uint8_t f_intersects_guardrail[NUMBER_OF_OBJECTS]; /**< Flag indicating that this object intersects with a detected guardrail.
                                                         \sa f_behind_guardrail*/
   float32_t obstruction_probability[NUMBER_OF_OBJECTS];           /**< probability that object is behind obstruction */
   float32_t rangeRegionObstructed_probability[NUMBER_OF_OBJECTS]; /**< probability that object is due to detections that are in
                                                                      spectrally cluttered regions */
   float32_t filtered_amplitude[NUMBER_OF_OBJECTS];                /**< [dBsm] current filtered amplitude (max of tracklets) */
   uint8_t f_reflection[NUMBER_OF_OBJECTS];                        /**< This object is probably a reflection */
   DEBUG_GUARDRAIL_OUTPUT_T
   guardrails[NUMBER_OF_GUARDRAILS]; /**< Guardrail data to be used by functions. Index0:left, index 1: right */
} RADAR_Tracker_Output_T;

/* CED */
typedef struct RADAR_Ced_Output_Tag
{
   /**Alert indicator for left side*/
   uint8_t CED_alert_left;

   /**Id of object with highest severity on left side*/
   uint8_t CED_id_left;

   /**Alert indicator for left side*/
   uint8_t CED_alert_right;

   /**Id of object with highest severity on right side*/
   uint8_t CED_id_right;

   /**Alert indicator for left side - front coming traffic.*/
   uint8_t CED_front_alert_left;

   /**Id of object with highest severity on left side - front coming traffic.*/
   uint8_t CED_front_id_left;

   /**Alert indicator for left side - front coming traffic.*/
   uint8_t CED_front_alert_right;

   /**Id of object with highest severity on right side - front coming traffic.*/
   uint8_t CED_front_id_right;

   /**TTC for most severe object on left side in [s]*/
   float32_t CED_ttc_left;

   /**TTC for most severe object on right side in [s]*/
   float32_t CED_ttc_right;

   /**TTC for most severe object on left side in [s] - front coming traffic.*/
   float32_t CED_front_ttc_left;

   /**TTC for most severe object on right side in [s] - front coming traffic.*/
   float32_t CED_front_ttc_right;

} RADAR_Ced_Output_T;

/* LCDA */
typedef struct RADAR_LCDA_CORE_OUTPUT_RNA_Tag
{
   uint8_t f_lcda_enabled;  // Flag indicating that LCMA is enabled
   uint8_t f_bsw_enabled;   // Flag indicating that the BLIS alert functionality is enabled
   uint8_t bsw_alert_left;  // Flag indicating that there is an active BLIS alert for the left side
   int32_t bsw_id_left;     // ID of the object responsible for the BLIS alert on the left side (-1 for none)
   uint8_t bsw_alert_right; // Flag indicating that there is an active BLIS alert for the right side
   int32_t bsw_id_right;    // ID of the object responsible for the BLIS alert on the right side (-1 for none)

   uint8_t f_cvw_enabled;   // Flag indicating that the CVW alert functionality is enabled
   uint8_t cvw_alert_left;  // Flag indicating that there is an active CVW alert for the left side
   int32_t cvw_id_left;     // ID of the object responsible for the CVW alert on the left side (-1 for none)
   float32_t cvw_ttc_left;  // TTC (time to conflict) of the object given by cvw_id_left
   uint8_t cvw_alert_right; // Flag indicating that there is an active CVW alert for the right side
   int32_t cvw_id_right;    // ID of the object responsible for the CVW alert on the right side (-1 for none)
   float32_t cvw_ttc_right; // TTC (time to conflict) of the object given by cvw_id_right
} RADAR_Lcda_Core_Output_Rna_T;

/*LCDA Customer*/
typedef struct LKA_Object_Logging_RNA_Tag
{
   int32_t lka_tracker_id;
   int32_t lka_obj_id;
   uint8_t lka_object_class;
   uint8_t lka_change_status;
   uint8_t lka_alert_condition;
   uint8_t lka_motion_class;
   float32_t lka_ttc;
   float32_t lka_vcs_vel_lat;
   float32_t lka_vcs_pos_lat;
   float32_t lka_vcs_vel_long;
   float32_t lka_vcs_pos_long;
   float32_t lka_curvi_vel_lat;
   float32_t lka_curvi_pos_lat;
   float32_t lka_curvi_vel_long;
   float32_t lka_curvi_pos_long;
} LKA_Object_Logging_RNA_T;

typedef struct RADAR_LCDA_CUST_SPEC_OUTPUT_LOGGING_RNA_Tag
{
   LKA_Object_Logging_RNA_T LKA_Object_Left[LCDA_NUMBER_OF_OBJECT_L];
   LKA_Object_Logging_RNA_T LKA_Object_Right[LCDA_NUMBER_OF_OBJECT_L];
} RADAR_Lcda_Cust_Spec_Output_Logging_Rna_T;

/* CTA */
typedef struct RADAR_CTA_Output_Tag
{
   uint8_t f_cta_enabled; // Flag indicating that CTA is enabled

   /*
      The folloing date is used for debugging and application (warning, alert)
      ID, TTC, Intersection and radial_distance are used for debugging output in FlexRay in Audi SRR3
   */
   uint8_t f_cta_alert_left;           // Flag indicating that there is an active CTA alert for the left side
   uint8_t f_cta_warn_left;            // Flag indicating that there is a warning on the left side (but no alert)
   uint8_t f_cta_prefill_req_left;     // Flag indicating that there is a prefill request on the left side
   uint8_t f_cta_braking_req_left;     // Flag indicating that there is a braking request on the left side
   uint8_t f_cta_hold_supp_left;       // Flag indicating that there is are conditions for hold request, CTA just support, it, not
                                       // request directly
   int32_t cta_id_left;                // ID of the object responsible for the CTA alert on the left side (-1 for none)
   float32_t cta_ttc_left;             // TTC (time to conflict) of the object given by CTA_id_left
   float32_t cta_intersectionX_left;   // intersection of target trajectory with host x-axis
   float32_t cta_intersectionY_left;   // intersection of target trajectory with host y-axis
   float32_t cta_radialDistance_left;  // radial distance of target from center of rear bumper
   float32_t cta_objPoseX_left;        // x coordinate of target position
   float32_t cta_objPoseY_left;        // x coordinate of target position
   float32_t cta_objVelocityX_left;    // target velocity (longitudinal to host)
   float32_t cta_objVelocityY_left;    // target velocity (lateral to host)
   uint8_t f_cta_alert_right;          // Flag indicating that there is an active CTA alert for the right side
   uint8_t f_cta_warn_right;           // Flag indicating that there is a warning on the right side (but no alert)
   uint8_t f_cta_prefill_req_right;    // Flag indicating that there is a prefill request on the right side
   uint8_t f_cta_braking_req_right;    // Flag indicating that there is a braking request on the right side
   uint8_t f_cta_hold_supp_right;      // Flag indicating that there is are conditions for hold request, CTA just support, it, not
                                       // request directly
   int32_t cta_id_right;               // ID of the object responsible for the CTA alert on the right side (-1 for none)
   float32_t cta_ttc_right;            // TTC (time to conflict) of the object given by CTA_id_right
   float32_t cta_intersectionX_right;  // intersection of target trajectory with host x-axis
   float32_t cta_intersectionY_right;  // intersection of target trajectory with host y-axis
   float32_t cta_radialDistance_right; // radial distance of target from center of rear bumper
   float32_t cta_objPoseX_right;       // x coordinate of target position
   float32_t cta_objPoseY_right;       // x coordinate of target position
   float32_t cta_objVelocityX_right;   // target velocity (longitudinal to host)
   float32_t cta_objVelocityY_right;   // target velocity (lateral to host)
   uint8_t RCTA_Kritikalitaetslevel_rechts;
   uint8_t RCTA_Kritikalitaetslevel_links;
} RADAR_Cta_Output_T;

typedef struct RADAR_BSIS_Output_Tag
{
   uint8_t bsis_index[BSIS_FBK_NUMBER_OF_SIDES];
   uint8_t bsis_id[BSIS_FBK_NUMBER_OF_SIDES];
   uint8_t bsis_alert_level[BSIS_FBK_NUMBER_OF_SIDES];
   uint16_t K_Unused16_1;
   float32_t bsis_ttc[BSIS_FBK_NUMBER_OF_SIDES];
} RADAR_Bsis_Output_T;
typedef struct Detections_Data_Tag
{
   float elevation_raw;
   float azimuth_raw;    /* [rad] */
   float range_rate_raw; /* [m/s] */
   float range;          /* [m]*/
   float amplitude;      /* [dB] */
   uint32_t valid_level; /* Read Value from FLexray signal */
   float detection_snr;
   uint8_t Mixer_Bias;
   uint8_t host_veh_clutter:1;
   uint8_t azimuth_confidence:2;
   uint8_t elevation_confidence;
   uint8_t super_res_target;
   uint8_t bistatic;
} Detections_Data_T;

typedef struct Detection_Info_Tag
{
   uint8_t AutoAlignQF; /* Read Value from FLexray signal */
   uint8_t timestamp_consistency;
   uint8_t LookID;     /* Read Value from FLexray signal */
   uint8_t LookType;   /* Read Value from FLexray signal */
   uint32_t Count;     /* Read Value from FLexray signal */
   uint32_t ScanIndex; /* Read Value from FLexray signal */
   float32_t AutoAlignAzimuth;
   float32_t AutoAlignElevation;
   float timestamp; /* Read Value from FLexray signal */
   uint8_t alignment_mode;
   uint8_t blockage_value;
   uint8_t blockage_status;
} Detection_Info_T;

typedef struct RADAR_DETECTION_OUT_Tag
{
   Detection_Info_T dets_info;
   Detections_Data_T dets_input[NUMBER_OF_DETECTIONS_PER_RADAR];
} RADAR_Detection_Out_T;

typedef struct RADAR_MOUNTING_OUT_Tag
{
   float32_t sensor_azimuth_polarity;
   float32_t sensor_boresight_angle;
   float32_t sensor_vcs_lat_posn;
   float32_t sensor_vcs_long_posn;
   float32_t veh_width;
   float32_t veh_length;
   float32_t vcs_offset_lat;
   float32_t vcs_offset_long;
   float32_t rear_axle_position;
   float32_t sensor_vcs_z_posn;
} RADAR_Mounting_Out_T;

/* Fusion Tracker Data - To be filled from the Opposite Radar Position */
typedef struct Tracker_Fusion_Data_Tag
{
   float speed;         //!< [m/s] speed of the object in vcs coordinates
   float heading;       //!< [rad] heading of the object in vcs coordinates
   float pos_lat;       //!< [m] longitudinal position of the center of the vehicle in vcs coordinates
   float pos_long;      //!< [m] lateral position of the center of the vehicle in vcs coordinates
   unsigned char valid; //!< flag indicating a valid object
   float timestamp;     //!< timestamp of the detection info
} Tracker_Fusion_Data_T;
typedef struct Vehicle_Data_Output_Tag
{
   float32_t abs_speed;
   float32_t yawrate;
   float32_t steering_angle;
   float32_t rear_axle_steering_angle;
   float32_t rear_axle_position;
   float32_t lane_width_external;
   float32_t lane_center_offset_external;
   float32_t host_vehicle_length;
   float32_t host_vehicle_width;
   float32_t host_vehicle_height;
   float32_t curve_radius;
   float32_t vcs_long_acc;
   float32_t vcs_lat_acc;
   float32_t bb_center_to_rear_x;
   float32_t bb_center_to_rear_y;
   float32_t bb_center_to_rear_z;
   uint32_t vehicle_data_buff_timestamp;
   uint8_t prndl;
   uint8_t turn_signal;
   uint8_t f_reverse_gear;
   uint8_t f_trailer_present;
   uint8_t f_traffic_side;
   uint8_t K_Unused8_1;
   uint16_t K_Unused16_1;
} Vehicle_Data_Output_T;

typedef struct SIL_RADAR_Output_Symbol
{
   /* Tracker debug output */
   RADAR_Tracker_Output_T Tracker_Out;

   /* CED Feature Warnings */
   RADAR_Ced_Output_T CED_Out;

   RADAR_Lcda_Cust_Spec_Output_Logging_Rna_T LCDA_Cust_Out;

   /* LCDA Feature Warnings */
   RADAR_Lcda_Core_Output_Rna_T LCDA_Out;

   /* CTA Feature Warnings */
   RADAR_Cta_Output_T CTA_Out;

   /* BSIS Feature Warnings */
   RADAR_Bsis_Output_T BSIS_Out;

   uint8_t BlindSpotDetectionState;

   uint8_t BendOffPrbabltyofMstImportatObj;

   uint8_t BlindSpotWarnigRelevantObjDetect;

   /* Vehicle output data */
   Vehicle_Data_Output_T Vehicle_Info_Out;
   /* Detection from Self Radar for Fusion */
   RADAR_Detection_Out_T Detection_Out;

   /* Mounting Data for Self Radar */
   RADAR_Mounting_Out_T Mounting_Out;

   /* Tracker fusion Data*/
   Tracker_Fusion_Data_T Tracker_Fusion_Data[NUMBER_OF_FUSION_OBJECTS];
} SIL_RADAR_Output_Symbol_T;

#pragma pack(pop)

#endif // SIL_OUTPUT_SYMBOL
