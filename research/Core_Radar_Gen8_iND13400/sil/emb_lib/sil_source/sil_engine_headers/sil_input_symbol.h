#ifndef RADAR_SIL_INPUT_SYMBOL_H
#define RADAR_SIL_INPUT_SYMBOL_H
/*===========================================================================*
 * FILE: sil_input_symbol.h
 *===========================================================================
 * Copyright 2024 APTIV Technologies, Inc., All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for Data Structures for RADAR Software In Loop(SIL) Simulation.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
 *===========================================================================*/
#define SIL_DEBUG_INPUT_TYPE_STRUCTURE_VERSION (24)

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "RR_ADAS_SYMBOL_Enum.h"
#include "dvl_message.h"
#include "reuse.h"
#include <stdint.h>

/*===========================================================================*
 * Typedef's or Structure Declarations
 *===========================================================================*/
#define NUMBER_OF_FUSION_OBJECTS       (6)
#define MAX_NUM_RESIM_OUTPUT           (40)
#define MAX_RADAR_SOURCE               (11)
#define METER_TO_MM                    (1000)
#define OFFSET_ANGLE_RESOLTION         (0.1f)
#define NUMBER_OF_DETECTIONS_PER_RADAR (500)
#define MAX_PCAN_MESSAGE               (500)
#define TRACKER_NUMBER_OF_OBJECTS      (64)
#define BSIS_FBK_NUMBER_OF_SIDES       (2U)
#ifdef _WIN64
   #define SIL_INPUT_MAX_PATH_SIZE 260
#elif defined(__GNUC__)
   #define SIL_INPUT_MAX_PATH_SIZE 4096
#endif

/* RADAR SIL Input Symbol Data Structure - Newly Added Interface */

/* APTIV Detections structure definition for SIL Data Injection needed for Series Production Flexray Only SIL  */
#pragma pack(push, save_pack)
#pragma pack(push, 2)
enum SIL_Customer_T
{
   /*====RADAR===PROJECT======*/
   enCUST_INVALID_CUSTOMER = 0x0,
   enCUST_PLATFORM_GEN7    = 0x81,
   enCUST_RNA_GEN7         = 0x5A,
   enCUST_PLATFORM_GEN8    = 0x82,
};

typedef struct Detections_Input_Tag
{
   float32_t elevation_raw;
   float32_t azimuth_raw;    /* [rad] */
   float32_t range_rate_raw; /* [m/s] */
   float32_t range;          /* [m]*/
   float32_t amplitude;      /* [dB] */
                             // uint8_t valid_level; /* Read Value from FLexray signal */
   float32_t detection_snr;
   // uint8 Mixer_Bias;
   float32_t std_elevation_angle;
   float32_t std_azimuth_angle;
   float32_t std_r_dot;
   float32_t std_range;
   //  float32_t  ambiguity_id;
   // float32_t   classification;
   float32_t std_rcs;
   float32_t multi_target_probability;
   float32_t existence_probability;
   uint8_t azimuth_confidence;
   uint8_t elevation_confidence;
   uint8_t valid_level;
   uint8_t host_veh_clutter:1;
   uint8_t super_res_target:1;
   uint8_t nd_target:1;
   uint8_t bistatic:1;
   uint8_t K_Unused8_1:4;
} Detections_Input_T;

/* Additional Data needed along with APTIV Detections for SIL Data Injection needed for Series Production Flexray Only SIL  */
typedef struct Detection_Header_Tag
{
   float32_t AutoAlignAzimuth;
   float32_t AutoAlignElevation;
   float32_t timestamp;
   uint32_t Count;
   uint32_t ScanIndex;
   uint8_t AutoAlignAzimuthQF;
   uint8_t AutoAlignElevationQF;
   uint8_t timestamp_consistency;
   uint8_t LookID;
   uint8_t LookType;
   uint8_t K_Unused8_1;
   uint16_t K_Unused16_1;
   uint8_t alignment_mode;
   uint8_t blockage_value;
   uint8_t blockage_status;
} Detection_Header_T;

/*APTIV Detections for SIL Data Injection needed for Series Production Flexray Only SIL  */
typedef struct Detection_Data_Input_Tag
{
   Detection_Header_T dets_info;
   Detections_Input_T dets_input[NUMBER_OF_DETECTIONS_PER_RADAR];
} Detection_Data_Input_T;

typedef enum
{
   DEBUG_TRACK_STATUS_INVALID = (0), /**< 0*/
   DEBUG_TRACK_STATUS_NEW     = (1), /**< 1*/
   DEBUG_TRACK_STATUS_MATURE  = (2), /**< 2*/
   DEBUG_TRACK_STATUS_COASTED = (3)  /**< 3*/

} DEBUG_TRAC_STATUS_T;

typedef enum DEBUG_OBJECT_CLASS_Tag
{
   DEBUG_OBJECT_CLASS_UNKNOWN    = (0), /**< 0*/
   DEBUG_OBJECT_CLASS_PEDESTRIAN = (1), /**< 1*/
   DEBUG_OBJECT_CLASS_2WHEEL     = (2), /**< 2*/
   DEBUG_OBJECT_CLASS_CAR        = (3), /**< 3*/
   DEBUG_OBJECT_CLASS_TRUCK      = (4)  /**< 4*/
} DEBUG_OBJECT_CLASS_T;
typedef struct DEBUG_OBJECT_CLASS_PROBABILITY_Tag
{
   float32_t probability_unknown;    //!< probability that the object class is unknown
   float32_t probability_pedestrian; //!< probability that the object is a pedestrian
   float32_t probability_2wheel;     //!< probability that the object is a 2wheel
   float32_t probability_car;        //!< probability that the object is a car
   float32_t probability_truck;      //!< probability that the object is a truck
} DEBUG_OBJECT_CLASS_PROBABILITY_T;

typedef enum DEBUG_REFERENCE_POSITION_Tag
{
   DEBUG_REFERENCE_POSITION_FRONT_LEFT  = (0), /**< 0*/
   DEBUG_REFERENCE_POSITION_FRONT       = (1), /**< 1*/
   DEBUG_REFERENCE_POSITION_FRONT_RIGHT = (2), /**< 2*/
   DEBUG_REFERENCE_POSITION_RIGHT       = (3), /**< 3*/
   DEBUG_REFERENCE_POSITION_REAR_RIGHT  = (4), /**< 4*/
   DEBUG_REFERENCE_POSITION_REAR        = (5), /**< 5*/
   DEBUG_REFERENCE_POSITION_REAR_LEFT   = (6), /**< 6*/
   DEBUG_REFERENCE_POSITION_LEFT        = (7), /**< 7*/
   DEBUG_REFERENCE_POSITION_INVALID     = (8)  /**< 8*/
} DEBUG_REFERENCE_POSITION_T;

/*APTIV Track Structure for SIL Data Injection of Artificial Created Tracks For FF testing in SIL  */
typedef struct TrackObject_Tag
{
   uint8_t id;                        // unique id number
   DEBUG_TRAC_STATUS_T status;        // values are INVALID, NEW, MATURE, and COASTED
   uint8_t age;                       // Start from 1 ; number of scans this object has existed
   uint32_t stage_age;                // age
   float32_t vcs_long_posn;           //[m] longitudinal position of object in vcs coordinates
   float32_t vcs_long_vel;            //[m/s] longitudinal velocity of object in vcs coordinates
   float32_t vcs_long_accel;          // [m/s^2] longitudinal acceleration of object in vcs coordinates
   float32_t vcs_lat_posn;            //[m] lateral position of object in vcs coordinates
   float32_t vcs_lat_vel;             //[m/s] lateral velocity of object in vcs coordinates
   float32_t vcs_lat_accel;           //[m/s^2] lateral acceleration of object in vcs coordinates
   float32_t vcs_long_vel_rel;        //[m/s] relative longitudinal velocity of object in vcs coordinates
   float32_t vcs_lat_vel_rel;         //[m/s] relative lateral velocity of object in vcs coordinates
   float32_t speed;                   //[m/s^2] speed of the object in vcs coordinates
   float32_t tangential_accel;        //[m/s^2] tangential acceleration of the object in vcs coordinates
   float32_t heading;                 //[rad] heading of the object in vcs coordinates
   float32_t heading_rate;            // Yaw rate of the target in the VCS
   float32_t length;                  //[m] length of the target vehicle
   float32_t width;                   //[m] width of the target vehicle
   DEBUG_OBJECT_CLASS_T object_class; // classification of the object based on target size
} TrackObject_T;

/*EGO Vehicle Data Inputs Needed for SIL Data Injection Mode in SIL  */
typedef struct Vehicle_Data_Input_Tag
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
} Vehicle_Data_Input_T;

typedef struct RADAR_BSIS_Input_Tag
{
   uint8_t bsis_index[BSIS_FBK_NUMBER_OF_SIDES];
   uint8_t bsis_id[BSIS_FBK_NUMBER_OF_SIDES];
   uint8_t bsis_alert_level[BSIS_FBK_NUMBER_OF_SIDES];
   uint16_t K_Unused16_1;
   float32_t bsis_ttc[BSIS_FBK_NUMBER_OF_SIDES];
} RADAR_Bsis_Input_T;

/* ALIGNMENT ALGORITHM To Execute */
typedef enum ALIGN_ALGO_TAG
{
   AUTO_ALIGNMENT        = 0, // Execute Auto Alignment in SIL
   SHORT_TRACK_ALIGNMENT = 1, // Execute SHORT TRACK Alignment in SIL
   KD_ALIGNMENT          = 2, // Execute KD Alignment in SIL
   EOL_ALIGNMENT         = 3  // Execute END OF LINE Auto Alignment in SIL   -->
} ALIGN_ALGO_T;

/* Autocalibration  Source */
typedef enum AUTO_CAL_SOURCE_TAG
{
   XML_FIXED = 0, // use Auto Alignment values as constant provided in XML option - USE_ALIGNMENT_VALUES_USE_FROM_XML
   UDP_LOG   = 1, // use Auto Alignment values saved from vehicle testing from UDP stream
   SIL_START_FROM_UDP =
      2, // use Auto Alignment values provided from Auto alignment running in SIL using the value from the Log as a starting value
   SIL_START_FROM_XML = 3 // use Auto Alignment values provided from Auto alignment running in SIL using the value from the XML as
                          // a starting value -->
} AUTO_CAL_SOURCE_T;

/* Autocalibration Values from XML File */
typedef struct ALIGNMENT_VALUES_TAG
{
   float32_t AZM_ALIGNMENT_REAR_LEFT;
   float32_t AZM_ALIGNMENT_REAR_RIGHT;
   float32_t AZM_ALIGNMENT_FRONT_LEFT;
   float32_t AZM_ALIGNMENT_FRONT_RIGHT;
   float32_t AZM_ALIGNMENT_BPILLAR_LEFT;
   float32_t AZM_ALIGNMENT_BPILLAR_RIGHT;
   float32_t AZM_ALIGNMENT_FRONT_CENTER;
   float32_t AZM_ALIGNMENT_REAR_CENTER;
   float32_t AZM_ALIGNMENT_POS1;
   float32_t AZM_ALIGNMENT_POS2;
   float32_t AZM_ALIGNMENT_POS3;

   float32_t ELV_ALIGNMENT_REAR_LEFT;
   float32_t ELV_ALIGNMENT_REAR_RIGHT;
   float32_t ELV_ALIGNMENT_FRONT_LEFT;
   float32_t ELV_ALIGNMENT_FRONT_RIGHT;
   float32_t ELV_ALIGNMENT_BPILLAR_LEFT;
   float32_t ELV_ALIGNMENT_BPILLAR_RIGHT;
   float32_t ELV_ALIGNMENT_FRONT_CENTER;
   float32_t ELV_ALIGNMENT_REAR_CENTER;
   float32_t ELV_ALIGNMENT_POS1;
   float32_t ELV_ALIGNMENT_POS2;
   float32_t ELV_ALIGNMENT_POS3;
} ALIGNMENT_VALUES_T;

/* KD / EOL Values from XML File */
typedef struct KD_EOL_VALUES_TAG
{
   float32_t Activated;
   float32_t Range;
   float32_t Angle;
} KD_EOL_VALUES_T;

/* KD / EOL Values for all Radar */
typedef struct KD_EOL_VALUES_POS_TAG
{
   KD_EOL_VALUES_T Azm_Value_REAR_LEFT;
   KD_EOL_VALUES_T Azm_Value_REAR_RIGHT;
   KD_EOL_VALUES_T Azm_Value_FRONT_LEFT;
   KD_EOL_VALUES_T Azm_Value_FRONT_RIGHT;
   KD_EOL_VALUES_T Azm_Value_BPILLAR_LEFT;
   KD_EOL_VALUES_T Azm_Value_BPILLAR_RIGHT;
   KD_EOL_VALUES_T Azm_Value_FRONT_CENTER;
   KD_EOL_VALUES_T Azm_Value_REAR_CENTER;
   KD_EOL_VALUES_T Azm_Value_POS1;
   KD_EOL_VALUES_T Azm_Value_POS2;
   KD_EOL_VALUES_T Azm_Value_POS3;

   KD_EOL_VALUES_T Elv_Value_REAR_LEFT;
   KD_EOL_VALUES_T Elv_Value_REAR_RIGHT;
   KD_EOL_VALUES_T Elv_Value_FRONT_LEFT;
   KD_EOL_VALUES_T Elv_Value_FRONT_RIGHT;
   KD_EOL_VALUES_T Elv_Value_BPILLAR_LEFT;
   KD_EOL_VALUES_T Elv_Value_BPILLAR_RIGHT;
   KD_EOL_VALUES_T Elv_Value_FRONT_CENTER;
   KD_EOL_VALUES_T Elv_Value_REAR_CENTER;
   KD_EOL_VALUES_T Elv_Value_POS1;
   KD_EOL_VALUES_T Elv_Value_POS2;
   KD_EOL_VALUES_T Elv_Value_POS3;
} KD_EOL_VALUES_POS_T;

typedef enum SIL_INJECTION_MODE_TAG
{
   UDP        = 0, /* SIL Input is UDP Frames - SIL / Decoder using API- SIL_RADAR_UDP_Frame_process*/
   DETECTIONS = 1, /* - SIL Input is Decoded data from Flexray Frames - SIL using API- SIL_RADAR_DATA_Frame_process */
   TRACKS = 2, /* SIL Input is object and vehicle data from virtual environment - SIL using API- SIL_RADAR_DATA_Frame_process */
   TRACKS_UDP = 3
} SIL_INJECTION_MODE_T;

/* Mounting Parameters from XML File is chosen */
typedef struct MOUNTING_VALUES_XML_TAG
{
   float32_t azimuth_polarity;
   float32_t boresight_angle;
   float32_t vcs_lat_position;
   float32_t vcs_lon_position;
   float32_t vcs_z_position;

} MOUNTING_VALUES_XML_T;
/* Source to use for the above mounting parameters */
typedef enum MOUNTING_POSITION_SOURCE_TAG
{
   MOUNT_UDP = 0,
   MOUNT_XML = 1
} MOUNTING_POSITION_SOURCE_T;

typedef struct UDPRecord_Hdr_TAG
{
   /*!
    *  Application Layer Info
    */
   uint16_t versionInfo;   /*  Version of this header specification [set to UDP_RECORD_VERSIONINFO] */
   uint16_t sourceTxCnt;   /*  Incremented on every transmission from this source.  */
   uint32_t sourceTxTime;  /*  Timestamp (ms) when packet queued for transmit. */
   uint8_t Platform;       /*  Constant identifying sending application [0:63], see udp_sources.h.  */
   uint8_t Radar_Position; /*  (Set to zero) */
   uint8_t reservedSrc2;   /*  (Set to zero) */
   uint8_t reservedSrc3;   /*  (Set to zero) */

   /*!
    *  Process Layer Info
    */
   uint32_t streamRefIndex; /*  Stream-specific index used for data retrieval (e.g. Look Index for radar) */
   uint16_t streamDataLen;  /*  Stream data payload size (bytes).  Size for each stream must be constant. */
   uint8_t streamTxCnt;     /*  Increments on each transmission of associated stream number. */
   uint8_t streamNumber;    /*  Stream number [0:31]. One source may transmit multiple, asynchronous streams.  */
   uint8_t streamVersion;   /*  Stream data structure format/version (how to interpret data). */
   uint8_t streamChunks;    /*!< A Stream may be transmitted from the process layer as M equal-size
                      chunks that can be reconstructed on the receive side.
                      Set to 0 if transmission is not part of a series of chunks (normal mode).
                      Set to M (>=2) to indicate stream is sent as a series of M chunks.
                      NOTE: streamTxCnt must increment for each chunk while streamRefIndex
                      would be the same for each chunk of a series. */
   uint8_t streamChunkIdx;  /*!< Zero when streamChunks is zero. Otherwise, represents this chunk's
                      position in the reconstruction queue [0:(streamChunks-1)]. */
   uint8_t customerId;      /*  (Set to zero)    */
} UDPRecord_Hdr;

typedef struct UDP_CUST_FRAME_HDR_TAG
{
   uint32_t packetnumber; /* UDP packet number, increments with each single UDP packet */
   uint32_t utc_time;     /* Latest UTC time available on Flexray at the middle of the radar dwell */
   uint32_t timestamp;    /* Time signal based upon an internal clock that is synchronized to the Flexray Signal SC_Masterzeit */
   uint8_t sensorid;      /* Radar Position */
   uint8_t sensorstatus;  /* 0 - Sensor working, 1- Sensor blind, 2 - Error */
   uint8_t detectioncnt;  /* Number of detections in current scan */
   uint8_t spare[5];      /* Reserved for future use */
} UDP_CUST_FRAME_HDR_T;

typedef struct UDP_Hdr_Info_TAG
{
   UDPRecord_Hdr Frame_Hdr;
   UDP_CUST_FRAME_HDR_T Cust_Hdr;
} UDP_Hdr_Info_T;

typedef struct CODING_Config_Param_TAG
{
   uint8_t mounting_position_signal_availability;
   uint8_t trailer_signal_availability;
   uint8_t camera_signal_availability;
   uint8_t ldw_system_signal_availability;
   uint8_t rear_axle_steering_signal_availability;
} CODING_Config_Param_T;

typedef enum SIL_RESIM_USER
{
   USER_DEVELOPER = 1,
   USER_ASATE     = 2
} SIL_RESIM_USER_T;

typedef struct Resim_Output_Control_Tag
{
   char *resim_out_suppress[MAX_NUM_RESIM_OUTPUT];
   char suppress_count;
} Resim_Output_Control_T;

/* Fusion Tracker Data - To be filled from the Opposite Radar Position */
typedef struct Tracker_Fusion_Object_Tag
{
   float32_t speed;     //!< [m/s] speed of the object in vcs coordinates
   float32_t heading;   //!< [rad] heading of the object in vcs coordinates
   float32_t pos_lat;   //!< [m] longitudinal position of the center of the vehicle in vcs coordinates
   float32_t pos_long;  //!< [m] lateral position of the center of the vehicle in vcs coordinates
   uint8_t valid;       //!< flag indicating a valid object
   float32_t timestamp; //!< timestamp of the detection info
} Tracker_Fusion_Object_T;

typedef enum SIL_UDP_LOG_Status_Tag
{
   OWN_CUSTOMER_LOG   = 1,
   INTER_CUSTOMER_LOG = 2
} SIL_UDP_LOG_Status_T;

typedef struct PCAN_DBC_Version_Tag
{
   uint16_t PCAN_Major_Version;
   uint16_t PCAN_Minor_Version;
} PCAN_DBC_Version_T;

typedef struct PCAN_RX_Tag
{
   dvlMessageUnion dvl_payload[MAX_PCAN_MESSAGE];
   int32_t msg_count;
   uint16_t PCAN_Counter;
} PCAN_RX_T;

typedef struct MAT_MF4_Header_Info
{
   char mf4_fileName[SIL_INPUT_MAX_PATH_SIZE];
   unsigned char MF4_Major_Version;
   unsigned char MF4_Minor_Version;
   unsigned char MF4_Release_Version;
   unsigned long long MF4_fileSize;
   unsigned long long network_timeStamp[MAX_RADAR_SOURCE];
} MAT_MF4_Header_Info_T;

typedef struct SIL_Data_Input_Hdr_Tag
{
   uint32_t sym_Size;     // size of the SIL_Data_Input structure
   uint32_t sym_Counter;  // Counter to protect over symbol interface
   uint16_t sym_Checksum; // checksum to be calculated over entire structure leaving header part
   uint16_t sym_version;  // smbol interface version number
} SIL_Data_Input_Hdr_T;
typedef struct SIL_Data_Input_TAG
{
   /* header added to protect the symbol data*/
   SIL_Data_Input_Hdr_T sil_data_input_hdr;
   /* SIL DATA Injection Mode - Detections , Tracks and EGO vehicle data
   Used for Feature function Testing using Artificially Created Tracks in VTD/ Carmaker
   Used in Series Production SIL where there is NO UDP and Detections and vehicle data are availiable from Flexray / Debug Frames
 */
   SIL_INJECTION_MODE_T SIL_Mode;

   /* Sensor Position - REAR_LEFT = 0x01, REAR_RIGHT = 0x02, FRONT_RIGHT = 0x03, FRONT_LEFT = 0x04, FRONT_CENTRE = 0x06 */
   uint8_t Radar_Position;

   /* Vehicle Data Input */
   Vehicle_Data_Input_T vehicle_inputs[MAX_RADAR_SOURCE];

   /*Ashley_alert Rear_Left*/
   RADAR_Bsis_Input_T BSIS_In[MAX_RADAR_SOURCE];

   uint8_t BlindSpotDetectionState[MAX_RADAR_SOURCE];

   uint8_t BendOffPrbablityofMstImportatObj[MAX_RADAR_SOURCE];

   uint8_t BlindSpotWarnigRelevantObjDetect[MAX_RADAR_SOURCE];

   /* Detections REAR_LEFT Sensor */
   Detection_Data_Input_T detection_rl_radar;

   /* Detections REAR_RIGHT Sensor */
   Detection_Data_Input_T detection_rr_radar;

   /* Detections FRONT_LEFT Sensor */
   Detection_Data_Input_T detection_fl_radar;

   /* Detections FRONT_RIGHT Sensor */
   Detection_Data_Input_T detection_fr_radar;

   /* Detections FRONT_CENTRE Sensor */
   Detection_Data_Input_T detection_fc_radar;
   /* Detections BP_LEFT Sensor */
   Detection_Data_Input_T detection_bl_radar;

   /* Detections BP_RIGHT Sensor */
   Detection_Data_Input_T detection_br_radar;

   /* Detections REAR_CENTRE Sensor */
   Detection_Data_Input_T detection_rc_radar;

   /* Detections POS1 Sensor */
   Detection_Data_Input_T detection_pos1_radar;

   /* Detections POS2 Sensor */
   Detection_Data_Input_T detection_pos2_radar;

   /* Detections POS3 Sensor */
   Detection_Data_Input_T detection_pos3_radar;

   /* Tracker in REAR_LEFT - REAR_LEFT combined REAR_RIGHT FOV */
   TrackObject_T object_rl[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in REAR_RIGHT - REAR_LEFT combined REAR_RIGHT FOV */
   TrackObject_T object_rr[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in FL FRONT_LEFT FOV */
   TrackObject_T object_fl[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in FR FRONT_RIGHT FOV */
   TrackObject_T object_fr[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in FC FRONT_CENTRE FOV */
   TrackObject_T object_fc[TRACKER_NUMBER_OF_OBJECTS];
   /* Tracker in BP FRONT_LEFT FOV */
   TrackObject_T object_bl[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in BP FRONT_RIGHT FOV */
   TrackObject_T object_br[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in RC REAR_CENTRE FOV */
   TrackObject_T object_rc[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in POS1 FOV */
   TrackObject_T object_pos1[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in POS2 FOV */
   TrackObject_T object_pos2[TRACKER_NUMBER_OF_OBJECTS];

   /* Tracker in POS3 FOV */
   TrackObject_T object_pos3[TRACKER_NUMBER_OF_OBJECTS];

   /* ALIGNMENT ALGORITHM To Execute */
   ALIGN_ALGO_T Align_Algo_to_Run;

   /* Autocalibration  Source */
   AUTO_CAL_SOURCE_T Auto_Calib_Source;

   /* Autocalibration Values from XML File */
   ALIGNMENT_VALUES_T Align_values;

   /* KD / EOL Input Values from XML */
   KD_EOL_VALUES_POS_T EOL_Values;

   /* Update UDP Header Info for individual Stream here */
   UDP_Hdr_Info_T UDP_Hdr_Info[MAX_RADAR_LOGGING_SOURCE];

   /*Coding Parameters for the ReSim to use signals passed via the Data Process API*/
   CODING_Config_Param_T coding_parameters;

   /* User for ReSim */
   SIL_RESIM_USER_T sil_user;

   /* Mounting Source from XML Cofiguration */
   MOUNTING_POSITION_SOURCE_T Mounting_Source;

   /* Mounting Values from XML Cofiguration for REAR LEFT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_RL;

   /* Mounting Values from XML Cofiguration for REAR RIGHT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_RR;

   /* Mounting Values from XML Cofiguration for FRONT LEFT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_FL;

   /* Mounting Values from XML Cofiguration for FRONT RIGHT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_FR;

   /* Mounting Values from XML Cofiguration for FRONT CENTRE Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_FC;

   /* Mounting Values from XML Cofiguration for BP RIGHT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_BR;

   /* Mounting Values from XML Cofiguration for BP LEFT Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_BL;

   /* Mounting Values from XML Cofiguration for REAR CENTRE Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_RC;

   /* Mounting Values from XML Cofiguration for POS1 Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_POS1;

   /* Mounting Values from XML Cofiguration for POS2 Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_POS2;

   /* Mounting Values from XML Cofiguration for POS3 Radar */
   MOUNTING_VALUES_XML_T Mounting_Values_POS3;

   /* Control for ReSim outputs */
   Resim_Output_Control_T Resim_Output_Suppress_Switch;

   /* Fusion Tracker Data - Rear Left */
   Tracker_Fusion_Object_T Fusion_Track_Rl[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - Rear Right */
   Tracker_Fusion_Object_T Fusion_Track_Rr[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - Front Left */
   Tracker_Fusion_Object_T Fusion_Track_Fl[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - Front Right */
   Tracker_Fusion_Object_T Fusion_Track_Fr[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - Front Centre */
   Tracker_Fusion_Object_T Fusion_Track_Fc[NUMBER_OF_FUSION_OBJECTS];
   /* Fusion Tracker Data - BP Left */
   Tracker_Fusion_Object_T Fusion_Track_Bl[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - BP Right */
   Tracker_Fusion_Object_T Fusion_Track_Br[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - Right Centre */
   Tracker_Fusion_Object_T Fusion_Track_Rc[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - POS1 */
   Tracker_Fusion_Object_T Fusion_Track_POS1[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - POS2 */
   Tracker_Fusion_Object_T Fusion_Track_POS2[NUMBER_OF_FUSION_OBJECTS];

   /* Fusion Tracker Data - POS3 */
   Tracker_Fusion_Object_T Fusion_Track_POS3[NUMBER_OF_FUSION_OBJECTS];

   /* Logging Stream Version from UDP - To be filled with the stream versions on Log */
   uint8_t Stream_Versions[MAX_RADAR_LOGGING_SOURCE];

   /* Inter Customer or Self log Mode - This has to be updated accordingly to support Intercustomer and Normal Log Replay */
   SIL_UDP_LOG_Status_T UDP_Log_Status;

   char Embedded_Lib_Config[SIL_INPUT_MAX_PATH_SIZE];

   PCAN_DBC_Version_T dbc_version_in;

   ///* PCAN_ Data for Rear left sensor*/
   PCAN_RX_T RL_PCAN_Data;

   ///* PCAN_ Data for Rear right sensor*/
   PCAN_RX_T RR_PCAN_Data;

   ///* PCAN_ Data for front right sensor*/
   PCAN_RX_T FR_PCAN_Data;

   ///* PCAN_ Data for front left sensor*/
   PCAN_RX_T FL_PCAN_Data;

   ///* PCAN_ Data for front centre sensor*/
   PCAN_RX_T FC_PCAN_Data;

   ///* PCAN_ Data for BP right sensor*/
   PCAN_RX_T BR_PCAN_Data;

   ///* PCAN_ Data for BP left sensor*/
   PCAN_RX_T BL_PCAN_Data;

   /* PCAN_ Data for rear center sensor*/
   PCAN_RX_T RC_PCAN_Data;

   /* PCAN_ Data for POS1 sensor*/
   PCAN_RX_T POS1_PCAN_Data;

   /* PCAN_ Data for POS2 sensor*/
   PCAN_RX_T POS2_PCAN_Data;

   /* PCAN_ Data for POS3 sensor*/
   PCAN_RX_T POS3_PCAN_Data;
   /* MF4 Information for .MAT File*/
   MAT_MF4_Header_Info_T MF4_Information;
   // Flag to indicate whether or not to read & update the file paths in emb lib.
   char f_readFilePath; // to be set to 1 for reading file name when there is a change in the file names & set to 0 to indicate not
                        // to read.

   // input file path from RADAR_DEBUG
   char fPath_Debug[SIL_INPUT_MAX_PATH_SIZE];

   // input file path from BN_CALIFR
   char fPath_BN_CALIFR[SIL_INPUT_MAX_PATH_SIZE];
   // input file path from BN_CALIFRSIDE
   char fPath_BN_CALIFRSide[SIL_INPUT_MAX_PATH_SIZE];

   // input file path from BN_IUKETH
   char fPath_BN_IUKETH[SIL_INPUT_MAX_PATH_SIZE];

   // input of Next file path from RADAR_DEBUG
   char fPath_Debug_Next[SIL_INPUT_MAX_PATH_SIZE];

   // input of Next file path from BN_CALIFR
   char fPath_BN_CALIFR_Next[SIL_INPUT_MAX_PATH_SIZE];
   // input of Next file path from BN_CALIFRSIDE
   char fPath_BN_CALIFRSide_Next[SIL_INPUT_MAX_PATH_SIZE];

   // input of Next file path from BN_IUKETH
   char fPath_BN_IUKETH_Next[SIL_INPUT_MAX_PATH_SIZE];

} SIL_RADAR_Input_Symbol_T;

#pragma pack(pop, save_pack)

#endif
