#include "fixmac.h"

typedef bool boolean_t;
typedef uint16_t sint16_t;
typedef uint32_t sint32_t;
typedef uint8_t sint8_t;

namespace ENET_encoded
{
typedef struct Dimension
{
   float32_t DET_AZIMUTH;
   float32_t DET_AZIMUTH_ERR;
   boolean_t DET_BI_STATIC_FLAG;
   uint8_t DET_CONFD_AZIMUTH;
   uint8_t DET_CONFD_ELEVATION;
   float32_t DET_ELEVATION;
   float32_t DET_ELEVATION_ERR;
   float32_t DET_EXISTENCE_PROB;
   boolean_t DET_HVC_FLAG;
   boolean_t DET_OUTSIDE_SECTOR;
   float32_t DET_POINT_TARGET_PROB;
   float32_t DET_RANGE;
   float32_t DET_RANGE_ERR;
   float32_t DET_RANGE_VELOCITY;
   float32_t DET_RANGE_VELOCITY_ERR;
   float32_t DET_RCS;
   float32_t DET_SNR;
   uint8_t DET_SUPER_RES_TARGET;
   boolean_t DET_VALID_FLAG;
} Dimension_T;

typedef struct HED_INTERFACE_VERSION
{
   uint8_t HED_INTRFC_VERSION_ID_MAJOR;
   uint8_t HED_INTRFC_VERSION_ID_MINOR;
   uint8_t HED_INTRFC_VERSION_ID_PATCH;
} HED_INTERFACE_VERSION_T;

typedef struct HED_DETECTION_INFO
{
   uint8_t HED_DET_BI_STATIC_COUNT;
   uint16_t HED_DET_NUM_OF_1PASS;
   uint16_t HED_DET_NUM_OF_2PASS;
   uint16_t HED_MAX_NUM_OF_DETECTIONS;
   uint16_t HED_NUM_OF_RESTBINS_USED;
   uint8_t HED_OPERATION_MODE;
   uint16_t HED_PROCESSED_RANGE;
   uint8_t HED_SLOPE_CORR_EXECUTIONFLAG;
} HED_DETECTION_INFO_T;

typedef struct HED_TIMESTAMP
{
   uint32_t HED_SENSOR_TIME_STAMP_NS;
   uint32_t HED_SENSOR_TIME_STAMP_SEC;
   boolean_t HED_TIME_SYNC_SRC_MASTER;
   boolean_t HED_TIME_SYNC_VALIDITY_FLAG;
   uint32_t HED_TRIGGER_TIME;
} HED_TIMESTAMP_T;

typedef struct HED_TIMING_PROFILES
{
   float32_t HED_AF_TIME_INST;
   float32_t HED_AF_TIME_PEAK;
   float32_t HED_MAIN_CORE_TIME_INST;
   float32_t HED_MAIN_CORE_TIME_PEAK;
   float32_t HED_RDD_CORE_TIME_INST;
   float32_t HED_RDD_CORE_TIME_PEAK;
   float32_t HED_SP_CORE_TIME_INST;
   float32_t HED_SP_CORE_TIME_PEAK;
} HED_TIMING_PROFILES_T;

typedef struct HED_ALIGNMENT
{
   uint8_t HED_ALIGN_HOR_QF;
   float32_t HED_ALIGN_HOR_REF;
   uint8_t HED_ALIGN_VER_QF;
   float32_t HED_ALIGN_VER_REF;
} HED_ALIGNMENT_T;

typedef struct HED_RADAR_STATE
{
   uint8_t HED_DATA_QUALIFIER;
   uint8_t HED_LOOK_ID;
   uint16_t HED_LOOK_INDEX;
   uint16_t HED_NUM_OF_VALID_DETECTIONS;
   uint16_t HED_SCAN_INDEX;
} HED_RADAR_STATE_T;

typedef struct HED_SENSOR_COVERAGE
{
   float32_t HED_DET_RANGE_MAX;
   float32_t HED_DET_RANGE_MIN;
   float32_t HED_DET_SPEED_RANGE_MAX;
   float32_t HED_DET_SPEED_RANGE_MIN;
   float32_t HED_FOV_HOR_MAX;
   float32_t HED_FOV_HOR_MIN;
   float32_t HED_FOV_VER_MAX;
   float32_t HED_FOV_VER_MIN;
} HED_SENSOR_COVERAGE_T;

typedef struct DETECTIONS_ARRAY
{
   Dimension_T Dimension[700];
} DETECTIONS_ARRAY_T;

typedef struct DET_EtoE_HDR
{
   uint64_t CRC;
   uint32_t COUNTER;
   uint32_t DATA_ID;
   uint32_t LENGTH;
} DET_EtoE_HDR_T;

typedef struct DET_HEADER_STRUCT
{
   HED_SENSOR_COVERAGE_T HED_SENSOR_COVERAGE;
   HED_RADAR_STATE_T HED_RADAR_STATE;
   HED_ALIGNMENT_T HED_ALIGNMENT;
   HED_TIMING_PROFILES_T HED_TIMING_PROFILES;
   HED_TIMESTAMP_T HED_TIMESTAMP;
   HED_DETECTION_INFO_T HED_DETECTION_INFO;
   HED_INTERFACE_VERSION_T HED_INTERFACE_VERSION;
} DET_HEADER_STRUCT_T;

typedef struct DETECTIONS_RECORD
{
   DET_HEADER_STRUCT_T DET_HEADER_STRUCT;
   DET_EtoE_HDR_T DET_EtoE_HDR;
   DETECTIONS_ARRAY_T DETECTIONS_ARRAY;
} DETECTIONS_RECORD_T;

/*********************************************************/
typedef struct CAP_MaxDetRangePedestrian
{
   uint64_t Element[3]; // added by me
} CAP_MaxDetRangePedestrian_T;

typedef struct CAP_MaxDetRangeMotorbike
{
   uint64_t Element[3]; // added by me
} CAP_MaxDetRangeMotorbike_T;

typedef struct CAP_MaxDetectionRangeCar
{
   uint64_t Element[3]; // added by me
} CAP_MaxDetectionRangeCar_T;

typedef struct STS_EtoE_HDR
{
   uint64_t CRC;
   uint32_t COUNTER;
   uint32_t DATA_ID;
   uint32_t LENGTH;
} STS_EtoE_HDR_T;

typedef struct STS_VEHICLE
{
   float32_t STS_STEERING_ANGLE;
   boolean_t STS_STEERING_ANGLE_SIGN;
   boolean_t STS_VEH_SPEED_DIRECTION;
   float32_t STS_VEHICLE_SPEED_CALC;
   uint8_t STS_VEHICLE_SUPPLY_VOLTAGE;
   float32_t STS_YAW_RATE_BIAS;
} STS_VEHICLE_T;

typedef struct STS_RADAR_PROFILE
{
   float32_t STS_AF_CORE_THROUGHPUT;
   uint8_t STS_MMIC_RE_INIT_COUNT;
   float32_t STS_RDD_CORE_THROUGHPUT;
   boolean_t STS_SCAN_TYPE;
   boolean_t STS_XCVR_OPERATIONAL;
} STS_RADAR_PROFILE_T;

typedef struct STS_FAULTS
{
   uint32_t STS_CORE_ACTIVE_FAULTS;
} STS_FAULTS_T;

typedef struct STS_TEMPERATURE
{
   sint16_t STS_MCU_TEMP;
   sint16_t STS_MMIC_TEMP_RX;
   sint16_t STS_MMIC_TEMP_TX0;
   sint16_t STS_MMIC_TEMP_TX1_2;
   sint16_t STS_MMIC_TEMP_TX3_4;
} STS_TEMPERATURE_T;

typedef struct STS_SENSOR_PERF
{
   uint8_t STS_BRR_STATUS;
} STS_SENSOR_PERF_T;

typedef struct STS_TIMESYNC_STATUS
{
   boolean_t STS_NO_TSYN_ERROR;
   float32_t STS_POINT_OF_TRIGGER;
   sint16_t STS_TIME_SYNC_OFFSET;
} STS_TIMESYNC_STATUS_T;

typedef struct STS_CAPAB_SLL_MONITOR
{
   uint8_t CAP_SideLobeLevelBeamformer;
   boolean_t CAP_SLLMonitoringActive;
   uint8_t CAP_SLLMonitoringStatus;
} STS_CAPAB_SLL_MONITOR_T;

typedef struct STS_CAPAB_RANGE_DET
{
   sint16_t CAP_AngleAzimuthRangeEnd;
   sint16_t CAP_AngleAzimuthRangeStart;
   CAP_MaxDetectionRangeCar_T CAP_MaxDetectionRangeCar;
   CAP_MaxDetRangeMotorbike_T CAP_MaxDetRangeMotorbike;
   CAP_MaxDetRangePedestrian_T CAP_MaxDetRangePedestrian;
   boolean_t CAP_RangeEstimationActive;
   uint8_t CAP_RangeEstimationStatus;
} STS_CAPAB_RANGE_DET_T;

typedef struct STS_CAPAB_DAMPING
{
   boolean_t CAP_DampingActive;
   uint16_t CAP_DampingCurrent;
   uint8_t CAP_DampingStandardDeviation;
   uint8_t CAP_DampingStatus;
} STS_CAPAB_DAMPING_T;

typedef struct STS_CAPAB_RDR_PERF
{
   boolean_t CAP_BlockageActive;
   uint8_t CAP_BlockageProbability;
   uint8_t CAP_BlockageSensitivity;
   uint8_t CAP_BlockageStatus;
   uint8_t CAP_BlockageValue;
   uint8_t CAP_FreeSightCheckActive;
   uint8_t CAP_FreeSightCheckStatus;
   uint8_t CAP_SLBlockageFilterValue;
   boolean_t CAP_SLBlockageFlag;
} STS_CAPAB_RDR_PERF_T;

typedef struct STS_ALIGN_SHORT_TRACK
{
   uint8_t STS_AlignmentShortTrackStatus;
} STS_ALIGN_SHORT_TRACK_T;

typedef struct STS_ALIGNMENT_SERVICE
{
   uint8_t STS_AlignmentServiceStatus;
   float32_t STS_AverageNumberOfDetections;
   sint16_t STS_AverageSpeed;
   uint32_t STS_DistanceAbsolute;
   uint32_t STS_DistanceEffective;
   uint32_t STS_DurationAbsolute;
   uint32_t STS_DurationEffective;
   uint8_t STS_VehicleCondition;
} STS_ALIGNMENT_SERVICE_T;

typedef struct STS_ALIGNMENT_STATIC
{
   uint8_t STS_AlignmentStaticStatus;
   boolean_t STS_ImpactByInterference;
   float32_t STS_Measured_Range;
   float32_t STS_MeasuredRangeRate;
   float32_t STS_MeasuredRangeRateStd;
   float32_t STS_MeasuredRangeStd;
   float32_t STS_MeasuredRCS;
   float32_t STS_MeasuredRCSStd;
} STS_ALIGNMENT_STATIC_T;

typedef struct STS_ALIGNMENT_AUTO
{
   uint8_t STS_AAAzimuthStd;
   sint32_t STS_AACurrentAzimuth;
   sint16_t STS_AACurrentElevation;
   uint8_t STS_AAElevationStd;
   uint8_t STS_AlignmentAutoStatus;
   uint8_t STS_AutoAlignmentFailRootCause;
   sint16_t STS_AzimuthErrorNegative;
   uint16_t STS_AzimuthErrorPositive;
   uint32_t STS_AzimuthUpdates;
   sint8_t STS_ElevationErrorNegative;
   uint8_t STS_ElevationErrorPositive;
   uint32_t STS_ElevationUpdates;
   uint8_t STS_HostSpdCompensationFactorQF;
   uint8_t STS_HostSpeedCompensationFactor;
   sint16_t STS_RollErrorPositive;
   sint16_t STS_StartAzimuth;
   sint16_t STS_StartElevation;
} STS_ALIGNMENT_AUTO_T;

typedef struct STS_ALIGNMENT_HANDLER
{
   float32_t STS_AlignmentAzimuth;
   float32_t STS_AlignmentElevation;
   uint8_t STS_AlignmentError;
   uint8_t STS_AlignmentModeIn;
   uint8_t STS_AlignmentModeOut;
   float32_t STS_AzimuthStd;
   boolean_t STS_CalDisplay;
   float32_t STS_CalTime;
   uint8_t STS_CoordinateSystemInput;
   float32_t STS_ElevationStd;
   float32_t STS_InitAlignmentResultAzimuth;
   float32_t STS_InitAlignmentResultElevation;
   uint32_t STS_InitAlignResultAzimuthUpdate;
   uint32_t STS_InitAlignRsltElevationUpdate;
   float32_t STS_InitAlignRsltHostSpdCompFac;
   uint8_t STS_InitLastSuccessfulAlignMode;
   float32_t STS_ProgressPercent;
   uint8_t STS_RadarTypeInput;
} STS_ALIGNMENT_HANDLER_T;

typedef struct RADAR_STATUS_RECORD
{
   STS_ALIGNMENT_HANDLER_T STS_ALIGNMENT_HANDLER;
   STS_ALIGNMENT_AUTO_T STS_ALIGNMENT_AUTO;
   STS_ALIGNMENT_STATIC_T STS_ALIGNMENT_STATIC;
   STS_ALIGNMENT_SERVICE_T STS_ALIGNMENT_SERVICE;
   STS_ALIGN_SHORT_TRACK_T STS_ALIGN_SHORT_TRACK;
   STS_CAPAB_RDR_PERF_T STS_CAPAB_RDR_PERF;
   STS_CAPAB_DAMPING_T STS_CAPAB_DAMPING;
   STS_CAPAB_RANGE_DET_T STS_CAPAB_RANGE_DET;
   STS_CAPAB_SLL_MONITOR_T STS_CAPAB_SLL_MONITOR;
   STS_TIMESYNC_STATUS_T STS_TIMESYNC_STATUS;
   STS_SENSOR_PERF_T STS_SENSOR_PERF;
   STS_TEMPERATURE_T STS_TEMPERATURE;
   STS_FAULTS_T STS_FAULTS;
   STS_RADAR_PROFILE_T STS_RADAR_PROFILE;
   STS_VEHICLE_T STS_VEHICLE;
   STS_EtoE_HDR_T STS_EtoE_HDR;
} RADAR_STATUS_RECORD_T;

/*********************************************************/
typedef struct INFO_EtoE_HDR
{
   uint64_t CRC;
   uint32_t COUNTER;
   uint32_t DATA_ID;
   uint32_t LENGTH;
} INFO_EtoE_HDR_T;

typedef struct INFO_HW_CAN_VERSION
{
   uint8_t STS_DET_DBC_BASE_VER_MAJOR;
   uint8_t STS_DET_DBC_BASE_VER_MINOR;
   uint8_t STS_HARDWARE_VERSION;
   uint8_t STS_PCAN_PROTOCOL_VER_MAJOR;
   uint8_t STS_PCAN_PROTOCOL_VER_MINOR;
   uint8_t STS_PLATFORM_VARIANT;
   uint16_t STS_SERIAL_NUM_JULIAN_DAY;
   uint8_t STS_SERIAL_NUM_JULIAN_YEAR;
   uint16_t STS_SERIAL_NUMBER_SEQUENCE;
} INFO_HW_CAN_VERSION_T;

typedef struct INFO_SW_VERSION
{
   uint8_t STS_PBL_VERSION_FIELD1;
   uint8_t STS_PBL_VERSION_FIELD2;
   uint8_t STS_PBL_VERSION_FIELD3;
   uint8_t STS_PBL_VERSION_FIELD4;
   uint8_t STS_SW_VERSION_FIELD1;
   uint8_t STS_SW_VERSION_FIELD2;
   uint8_t STS_SW_VERSION_FIELD3;
   uint8_t STS_SW_VERSION_FIELD4;
} INFO_SW_VERSION_T;

typedef struct INFO_MOUNTING_POS
{
   float32_t STS_SENSOR_HEIGHT;
   uint8_t STS_SENSOR_MOUNT_LOCATION;
   float32_t STS_SENSOR_MOUNT_ORNT_PITCH;
   float32_t STS_SENSOR_MOUNT_ORNT_ROLL;
   float32_t STS_SENSOR_MOUNT_ORNT_YAW;
   float32_t STS_SENSOR_MOUNT_POS_X;
   float32_t STS_SENSOR_MOUNT_POS_Y;
   float32_t STS_SENSOR_MOUNT_POS_Z;
   uint8_t STS_SENSOR_POSITION;
} INFO_MOUNTING_POS_T;

typedef struct INFO_CALIBRATION_VERSION
{
   uint16_t STS_SMC_CAL_VER_MAJOR;
   uint16_t STS_SMC_CAL_VER_MINOR;
   uint8_t STS_SMC_PLATFROM_VERSION;
   uint16_t STS_SMC_SECTION_COMPTBLITY;
   uint16_t STS_USC_CAL_VER_MAJOR;
   uint16_t STS_USC_CAL_VER_MINOR;
   uint16_t STS_USC_SECTION_COMPTBLITY;
} INFO_CALIBRATION_VERSION_T;

typedef struct RADAR_SW_INFO_RECORD
{
   INFO_CALIBRATION_VERSION_T INFO_CALIBRATION_VERSION;
   INFO_MOUNTING_POS_T INFO_MOUNTING_POS;
   INFO_SW_VERSION_T INFO_SW_VERSION;
   INFO_HW_CAN_VERSION_T INFO_HW_CAN_VERSION;
   INFO_EtoE_HDR_T INFO_EtoE_HDR;
} RADAR_SW_INFO_RECORD_T;

/*********************************************************/
typedef struct SSTS_EtoE_HDR
{
   uint64_t CRC;
   uint32_t COUNTER;
   uint32_t DATA_ID;
   uint32_t LENGTH;
} SSTS_EtoE_HDR_T;

typedef struct System_Status_Absolute_Time
{
   uint8_t SSTS_VEH_AbsoluteTime_Day;
   uint8_t SSTS_VEH_AbsoluteTime_Hour;
   uint8_t SSTS_VEH_AbsoluteTime_Minute;
   uint8_t SSTS_VEH_AbsoluteTime_Month;
   uint8_t SSTS_VEH_AbsoluteTime_Second;
   uint8_t SSTS_VEH_AbsoluteTime_Year;
} System_Status_Absolute_Time_T;

typedef struct System_Status_Vehicle_State
{
   uint8_t SSTS_DRIVE_DIR;
   boolean_t SSTS_DRIVE_REVERSE;
   uint8_t SSTS_GEAR_POSITION;
   uint8_t SSTS_IGN_STATUS;
   uint8_t SSTS_LROS_DRIVE_DIR;
   boolean_t SSTS_LROS_DRIVE_REVERSE;
} System_Status_Vehicle_State_T;

typedef struct System_Status_Vehicle
{
   float32_t SSTS_STEERING_ANGLE;
   boolean_t SSTS_STEERING_ANGLE_SIGN;
   uint32_t SSTS_VEH_ODOMETER;
   uint8_t SSTS_VEH_POWER_MODE_STATUS;
   float32_t SSTS_VEH_SPD_COMP_FACTOR;
   float32_t SSTS_VEH_SYSTEM_VOLTAGE;
   float32_t SSTS_VEHICLE_SPEED_CALC;
   uint8_t SSTS_VEHICLE_SPEED_CALC_QF;
   uint8_t SSTS_VEHICLE_STATE;
   float32_t SSTS_YAW_RATE_BIAS;
   float32_t SSTS_YAW_RATE_CALC;
   uint8_t SSTS_YAW_RATE_CALC_QF;
} System_Status_Vehicle_T;

typedef struct VEHICLE_STATUS_RECORD
{
   System_Status_Vehicle_T System_Status_Vehicle;
   System_Status_Vehicle_State_T System_Status_Vehicle_State;
   // System_Status_ADAS_Version_t System_Status_ADAS_Version; //removed manually
   float32_t System_Status_ADAS_Version; // added to remove error due to enum unavailablity
   System_Status_Absolute_Time_T System_Status_Absolute_Time;
   SSTS_EtoE_HDR_T SSTS_EtoE_HDR;
} VEHICLE_STATUS_RECORD_T;

/*********************************************************/
} // namespace ENET_encoded

typedef struct ENET_Encoded_Types
{
   ENET_encoded::DETECTIONS_RECORD_T DETECTIONS_RECORD;
   ENET_encoded::VEHICLE_STATUS_RECORD_T VEHICLE_STATUS_RECORD;
   ENET_encoded::RADAR_STATUS_RECORD_T RADAR_STATUS_RECORD;
   ENET_encoded::RADAR_SW_INFO_RECORD_T RADAR_SW_INFO_RECORD;
} ENET_Encoded_Types_T;
