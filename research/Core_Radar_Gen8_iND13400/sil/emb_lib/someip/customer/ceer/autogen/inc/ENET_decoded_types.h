#include "fixmac.h"
typedef bool boolean_t;
typedef uint16_t sint16_t;
typedef uint32_t sint32_t;
typedef uint8_t sint8_t;

namespace ENET_decoded
{

typedef struct Dimension
{
   float32_t DET_AZIMUTH;
   float32_t DET_AZIMUTH_ERR;
   float32_t DET_BI_STATIC_FLAG;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_CONFD_AZIMUTH;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_CONFD_ELEVATION; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_ELEVATION;
   float32_t DET_ELEVATION_ERR;
   float32_t DET_EXISTENCE_PROB;
   float32_t DET_HVC_FLAG;       /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_OUTSIDE_SECTOR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_POINT_TARGET_PROB;
   float32_t DET_RANGE;
   float32_t DET_RANGE_ERR;
   float32_t DET_RANGE_VELOCITY;
   float32_t DET_RANGE_VELOCITY_ERR;
   float32_t DET_RCS;
   float32_t DET_SNR;
   float32_t DET_SUPER_RES_TARGET; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DET_VALID_FLAG;       /*Factor = 0.000000 offset = 0.000000 */
} Dimension_T;

typedef struct HED_INTERFACE_VERSION
{
   float32_t HED_INTRFC_VERSION_ID_MAJOR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_INTRFC_VERSION_ID_MINOR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_INTRFC_VERSION_ID_PATCH; /*Factor = 0.000000 offset = 0.000000 */
} HED_INTERFACE_VERSION_T;

typedef struct HED_DETECTION_INFO
{
   float32_t HED_DET_BI_STATIC_COUNT;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_DET_NUM_OF_1PASS;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_DET_NUM_OF_2PASS;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_MAX_NUM_OF_DETECTIONS;    /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_NUM_OF_RESTBINS_USED;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_OPERATION_MODE;           /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_PROCESSED_RANGE;          /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_SLOPE_CORR_EXECUTIONFLAG; /*Factor = 0.000000 offset = 0.000000 */
} HED_DETECTION_INFO_T;

typedef struct HED_TIMESTAMP
{
   float32_t HED_SENSOR_TIME_STAMP_NS;    /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_SENSOR_TIME_STAMP_SEC;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_TIME_SYNC_SRC_MASTER;    /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_TIME_SYNC_VALIDITY_FLAG; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_TRIGGER_TIME;            /*Factor = 0.000000 offset = 0.000000 */
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
   float32_t HED_ALIGN_HOR_QF; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_ALIGN_HOR_REF;
   float32_t HED_ALIGN_VER_QF; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_ALIGN_VER_REF;
} HED_ALIGNMENT_T;

typedef struct HED_RADAR_STATE
{
   float32_t HED_DATA_QUALIFIER;          /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_LOOK_ID;                 /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_LOOK_INDEX;              /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_NUM_OF_VALID_DETECTIONS; /*Factor = 0.000000 offset = 0.000000 */
   float32_t HED_SCAN_INDEX;              /*Factor = 0.000000 offset = 0.000000 */
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
   float32_t CRC;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t COUNTER; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DATA_ID; /*Factor = 0.000000 offset = 0.000000 */
   float32_t LENGTH;  /*Factor = 0.000000 offset = 0.000000 */
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
   float32_t Element[3];
} CAP_MaxDetRangePedestrian_T;

typedef struct CAP_MaxDetRangeMotorbike
{
   float32_t Element[3];
} CAP_MaxDetRangeMotorbike_T;

typedef struct CAP_MaxDetectionRangeCar
{
   float32_t Element[3];
} CAP_MaxDetectionRangeCar_T;

typedef struct STS_EtoE_HDR
{
   float32_t CRC;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t COUNTER; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DATA_ID; /*Factor = 0.000000 offset = 0.000000 */
   float32_t LENGTH;  /*Factor = 0.000000 offset = 0.000000 */
} STS_EtoE_HDR_T;

typedef struct STS_VEHICLE
{
   float32_t STS_STEERING_ANGLE;
   float32_t STS_STEERING_ANGLE_SIGN; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_VEH_SPEED_DIRECTION; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_VEHICLE_SPEED_CALC;
   float32_t STS_VEHICLE_SUPPLY_VOLTAGE; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_YAW_RATE_BIAS;
} STS_VEHICLE_T;

typedef struct STS_RADAR_PROFILE
{
   float32_t STS_AF_CORE_THROUGHPUT;
   float32_t STS_MMIC_RE_INIT_COUNT; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_RDD_CORE_THROUGHPUT;
   float32_t STS_SCAN_TYPE;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_XCVR_OPERATIONAL; /*Factor = 0.000000 offset = 0.000000 */
} STS_RADAR_PROFILE_T;

typedef struct STS_FAULTS
{
   float32_t STS_CORE_ACTIVE_FAULTS; /*Factor = 0.000000 offset = 0.000000 */
} STS_FAULTS_T;

typedef struct STS_TEMPERATURE
{
   float32_t STS_MCU_TEMP;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_MMIC_TEMP_RX;    /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_MMIC_TEMP_TX0;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_MMIC_TEMP_TX1_2; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_MMIC_TEMP_TX3_4; /*Factor = 0.000000 offset = 0.000000 */
} STS_TEMPERATURE_T;

typedef struct STS_SENSOR_PERF
{
   float32_t STS_BRR_STATUS; /*Factor = 0.000000 offset = 0.000000 */
} STS_SENSOR_PERF_T;

typedef struct STS_TIMESYNC_STATUS
{
   float32_t STS_NO_TSYN_ERROR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_POINT_OF_TRIGGER;
   float32_t STS_TIME_SYNC_OFFSET; /*Factor = 0.000000 offset = 0.000000 */
} STS_TIMESYNC_STATUS_T;

typedef struct STS_CAPAB_SLL_MONITOR
{
   float32_t CAP_SideLobeLevelBeamformer; /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_SLLMonitoringActive;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_SLLMonitoringStatus;     /*Factor = 0.000000 offset = 0.000000 */
} STS_CAPAB_SLL_MONITOR_T;

typedef struct STS_CAPAB_RANGE_DET
{
   float32_t CAP_AngleAzimuthRangeEnd;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_AngleAzimuthRangeStart; /*Factor = 0.000000 offset = 0.000000 */
   CAP_MaxDetectionRangeCar_T CAP_MaxDetectionRangeCar;
   CAP_MaxDetRangeMotorbike_T CAP_MaxDetRangeMotorbike;
   CAP_MaxDetRangePedestrian_T CAP_MaxDetRangePedestrian;
   float32_t CAP_RangeEstimationActive; /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_RangeEstimationStatus; /*Factor = 0.000000 offset = 0.000000 */
} STS_CAPAB_RANGE_DET_T;

typedef struct STS_CAPAB_DAMPING
{
   float32_t CAP_DampingActive;            /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_DampingCurrent;           /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_DampingStandardDeviation; /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_DampingStatus;            /*Factor = 0.000000 offset = 0.000000 */
} STS_CAPAB_DAMPING_T;

typedef struct STS_CAPAB_RDR_PERF
{
   float32_t CAP_BlockageActive;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_BlockageProbability;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_BlockageSensitivity;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_BlockageStatus;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_BlockageValue;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_FreeSightCheckActive;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_FreeSightCheckStatus;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_SLBlockageFilterValue; /*Factor = 0.000000 offset = 0.000000 */
   float32_t CAP_SLBlockageFlag;        /*Factor = 0.000000 offset = 0.000000 */
} STS_CAPAB_RDR_PERF_T;

typedef struct STS_ALIGN_SHORT_TRACK
{
   float32_t STS_AlignmentShortTrackStatus; /*Factor = 0.000000 offset = 0.000000 */
} STS_ALIGN_SHORT_TRACK_T;

typedef struct STS_ALIGNMENT_SERVICE
{
   float32_t STS_AlignmentServiceStatus; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AverageNumberOfDetections;
   float32_t STS_AverageSpeed;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_DistanceAbsolute;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_DistanceEffective; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_DurationAbsolute;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_DurationEffective; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_VehicleCondition;  /*Factor = 0.000000 offset = 0.000000 */
} STS_ALIGNMENT_SERVICE_T;

typedef struct STS_ALIGNMENT_STATIC
{
   float32_t STS_AlignmentStaticStatus; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ImpactByInterference;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_Measured_Range;
   float32_t STS_MeasuredRangeRate;
   float32_t STS_MeasuredRangeRateStd;
   float32_t STS_MeasuredRangeStd;
   float32_t STS_MeasuredRCS;
   float32_t STS_MeasuredRCSStd;
} STS_ALIGNMENT_STATIC_T;

typedef struct STS_ALIGNMENT_AUTO
{
   float32_t STS_AAAzimuthStd;                /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AACurrentAzimuth;            /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AACurrentElevation;          /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AAElevationStd;              /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AlignmentAutoStatus;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AutoAlignmentFailRootCause;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AzimuthErrorNegative;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AzimuthErrorPositive;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AzimuthUpdates;              /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ElevationErrorNegative;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ElevationErrorPositive;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ElevationUpdates;            /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_HostSpdCompensationFactorQF; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_HostSpeedCompensationFactor; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_RollErrorPositive;           /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_StartAzimuth;                /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_StartElevation;              /*Factor = 0.000000 offset = 0.000000 */
} STS_ALIGNMENT_AUTO_T;

typedef struct STS_ALIGNMENT_HANDLER
{
   float32_t STS_AlignmentAzimuth;
   float32_t STS_AlignmentElevation;
   float32_t STS_AlignmentError;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AlignmentModeIn;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AlignmentModeOut; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_AzimuthStd;
   float32_t STS_CalDisplay; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_CalTime;
   float32_t STS_CoordinateSystemInput; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ElevationStd;
   float32_t STS_InitAlignmentResultAzimuth;
   float32_t STS_InitAlignmentResultElevation;
   float32_t STS_InitAlignResultAzimuthUpdate; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_InitAlignRsltElevationUpdate; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_InitAlignRsltHostSpdCompFac;
   float32_t STS_InitLastSuccessfulAlignMode; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_ProgressPercent;
   float32_t STS_RadarTypeInput; /*Factor = 0.000000 offset = 0.000000 */
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
   float32_t CRC;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t COUNTER; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DATA_ID; /*Factor = 0.000000 offset = 0.000000 */
   float32_t LENGTH;  /*Factor = 0.000000 offset = 0.000000 */
} INFO_EtoE_HDR_T;

typedef struct INFO_HW_CAN_VERSION
{
   float32_t STS_DET_DBC_BASE_VER_MAJOR;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_DET_DBC_BASE_VER_MINOR;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_HARDWARE_VERSION;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PCAN_PROTOCOL_VER_MAJOR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PCAN_PROTOCOL_VER_MINOR; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PLATFORM_VARIANT;        /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SERIAL_NUM_JULIAN_DAY;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SERIAL_NUM_JULIAN_YEAR;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SERIAL_NUMBER_SEQUENCE;  /*Factor = 0.000000 offset = 0.000000 */
} INFO_HW_CAN_VERSION_T;

typedef struct INFO_SW_VERSION
{
   float32_t STS_PBL_VERSION_FIELD1; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PBL_VERSION_FIELD2; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PBL_VERSION_FIELD3; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_PBL_VERSION_FIELD4; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SW_VERSION_FIELD1;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SW_VERSION_FIELD2;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SW_VERSION_FIELD3;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SW_VERSION_FIELD4;  /*Factor = 0.000000 offset = 0.000000 */
} INFO_SW_VERSION_T;

typedef struct INFO_MOUNTING_POS
{
   float32_t STS_SENSOR_HEIGHT;
   float32_t STS_SENSOR_MOUNT_LOCATION; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SENSOR_MOUNT_ORNT_PITCH;
   float32_t STS_SENSOR_MOUNT_ORNT_ROLL;
   float32_t STS_SENSOR_MOUNT_ORNT_YAW;
   float32_t STS_SENSOR_MOUNT_POS_X;
   float32_t STS_SENSOR_MOUNT_POS_Y;
   float32_t STS_SENSOR_MOUNT_POS_Z;
   float32_t STS_SENSOR_POSITION; /*Factor = 0.000000 offset = 0.000000 */
} INFO_MOUNTING_POS_T;

typedef struct INFO_CALIBRATION_VERSION
{
   float32_t STS_SMC_CAL_VER_MAJOR;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SMC_CAL_VER_MINOR;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SMC_PLATFROM_VERSION;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_SMC_SECTION_COMPTBLITY; /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_USC_CAL_VER_MAJOR;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_USC_CAL_VER_MINOR;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t STS_USC_SECTION_COMPTBLITY; /*Factor = 0.000000 offset = 0.000000 */
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
   float32_t CRC;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t COUNTER; /*Factor = 0.000000 offset = 0.000000 */
   float32_t DATA_ID; /*Factor = 0.000000 offset = 0.000000 */
   float32_t LENGTH;  /*Factor = 0.000000 offset = 0.000000 */
} SSTS_EtoE_HDR_T;

typedef struct System_Status_Absolute_Time
{
   float32_t SSTS_VEH_AbsoluteTime_Day;    /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_AbsoluteTime_Hour;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_AbsoluteTime_Minute; /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_AbsoluteTime_Month;  /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_AbsoluteTime_Second; /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_AbsoluteTime_Year;   /*Factor = 0.000000 offset = 0.000000 */
} System_Status_Absolute_Time_T;

typedef struct System_Status_Vehicle_State
{
   float32_t SSTS_DRIVE_DIR;          /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_DRIVE_REVERSE;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_GEAR_POSITION;      /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_IGN_STATUS;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_LROS_DRIVE_DIR;     /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_LROS_DRIVE_REVERSE; /*Factor = 0.000000 offset = 0.000000 */
} System_Status_Vehicle_State_T;

typedef struct System_Status_Vehicle
{
   float32_t SSTS_STEERING_ANGLE;
   float32_t SSTS_STEERING_ANGLE_SIGN;   /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_ODOMETER;          /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_POWER_MODE_STATUS; /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEH_SPD_COMP_FACTOR;
   float32_t SSTS_VEH_SYSTEM_VOLTAGE;
   float32_t SSTS_VEHICLE_SPEED_CALC;
   float32_t SSTS_VEHICLE_SPEED_CALC_QF; /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_VEHICLE_STATE;         /*Factor = 0.000000 offset = 0.000000 */
   float32_t SSTS_YAW_RATE_BIAS;
   float32_t SSTS_YAW_RATE_CALC;
   float32_t SSTS_YAW_RATE_CALC_QF; /*Factor = 0.000000 offset = 0.000000 */
} System_Status_Vehicle_T;

typedef struct VEHICLE_STATUS_RECORD
{
   System_Status_Vehicle_T System_Status_Vehicle;
   System_Status_Vehicle_State_T System_Status_Vehicle_State;
   float32_t System_Status_ADAS_Version; /*Factor = 0.000000 offset = 0.000000 */
   System_Status_Absolute_Time_T System_Status_Absolute_Time;
   SSTS_EtoE_HDR_T SSTS_EtoE_HDR;
} VEHICLE_STATUS_RECORD_T;

/*********************************************************/
} // namespace ENET_decoded

typedef struct ENET_Decoded_Types
{
   ENET_decoded::DETECTIONS_RECORD_T DETECTIONS_RECORD;
   ENET_decoded::VEHICLE_STATUS_RECORD_T VEHICLE_STATUS_RECORD;
   ENET_decoded::RADAR_STATUS_RECORD_T RADAR_STATUS_RECORD;
   ENET_decoded::RADAR_SW_INFO_RECORD_T RADAR_SW_INFO_RECORD;
} ENET_Decoded_Types_T;
