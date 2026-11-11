/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_Radar_Alignment_Handler.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Radar_Alignment_Handler
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Radar_Alignment_Handler>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dt_AlignAuto_Error
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_AlignHandler_Error
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_Align_Status
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_Align_Veh_Cond
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_AlignmentModeIn_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_Appl_ShutdownReqStatus
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_DRA_Detection_Coordinate_System
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * EcuM_StateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Radar_Alignment_Handler.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SWC_PLT_CDD_XCP.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "sra_types.h"
#include <math.h>
#include <string.h>

#define AA_ANGLE_CHG_INDEX     4000U
#define AA_ANGLE_CHG_THRESHOLD (1 * Deg2Radians)

static uint8_t AutoAlignment_Trigger      = (uint8_t)FALSE; /*To indicata Auto Alignment 1st trigger after Succesfull Alignment*/
static uint8_t AutoAlignmentRunningStatus = (uint8_t)FALSE;

/* Dynamic Service Alignment Variables from Algo that does not require conversion */
static uint8_t Complete_Percent_Az;
static uint8_t Complete_Percent_El;

static uint32_t N_Updates_Azimuth_Prev   = 0U;
static uint32_t N_Updates_Elevation_Prev = 0U;
static uint32_t N_Updates_roll_Prev      = 0U;
static uint32_t Align_Look_Index_Prev    = 0U; /* Previous alignment_index for stall detection */
static uint32_t n_updates_az_el          = 0U;

Dt_Alignment_IPC_Data alignment_ipc_data;
Dt_Alignment_M2D_Data alignment_m2d_data;

Dt_Write_Alignment_NvM_Data_T Alignment_NVM_Data;

Dt_Align_Mode_T Alignment_Type = ALIGN_MODE_AUTO;
Dt_Alignment_Handler AlignmentHandler;
Dt_AlignmentService AlignmentService = {
   0U, 0U, 0U, 0U, 0U, 0.0F, ALIGNMENT_OFF, ALIGN_VEH_NO_ISSSUE}; /* Initialize VehicleCondition with ALIGN_VEH_NO_ISSSUE*/
Dt_AlignmentShortTrack AlignmentShortTrack;
Dt_AlignmentAuto AlignmentAuto;
Dt_AlignmentStatic AlignmentStatic;
AlignmentDynamic_T AlignmentDynamic;
Dt_Alignment_Faults_T Alignment_Faults;
AlignmentAutoCals_T alignment_auto_cals;
AlignmentInitialCals_T alignment_initial_cals;
Sensor_Align_Mounting_Parameters_T Align_Mounting_Parameters;
static D2M_Msg_T *p_align_d2m;

#ifdef ALIGN_STUB_SIMULATE_DET
volatile static uint8_t Align_Oper_Mode_Test = 3;
volatile uint8_t Align_Angle_Chg_Test        = CODED_FALSE;
#endif

static void Alignment_Handler(void);
static void Process_Alignment_Cmd(void);
static void Read_Xcp_Cmd(void);
static void Auto_Alignment_Handler(void);
static void Process_Auto_Alignment_Mode_Data(bool *init_nvm_write_flag);
static void Dynamic_ShortTrack_Alignment_Handler(void);
static void Dynamic_Service_Alignment_Handler(Dt_Align_Status *target_alignment_status);
static uint32_t Calculate_Detection_Count(void);
static void Chk_AutoAlignment_Nvm(bool *init_nvm_write);
static void Check_And_Update_NVM_Angles(void);
static void Compute_Autoalign_Faults(void);
static void Static_Alignment_Handler(void);
static void Process_Manual_Xcp_Cmd(void);
static void Update_Alignment_Faults(void);
static void Initialize_alignment(void);
static void Update_Dynamic_Alignment_Config_Params(void);
static void Update_Static_Alignment_Config_Params(void);
static void Reset_NVM_On_Alignment_Req(void);
static void Update_Auto_Alignment_Start_Value(void);
static void Process_Service_Alignment_Data(Dt_Align_Status *target_alignment_status);
static void Process_Static_Alignment_Data(void);
static bool Check_InitialDyn_Alignment_Status(void);
static void Calculate_Initial_Align_Time(void);
static void Process_ShortTrack_Alignment_Status(bool st_align_success);
static void Manual_Alignment_Handler(void);
static void Read_Dyn_Alignment_Data(void);
static void Update_Alignment_NVM_Data(void);
static void Update_Current_Dyn_Alignment_Data(void);
static void Update_Successful_Dyn_Alignment_Data(void);
static void Update_XCP_Alignment_Data(void);
static void Auto_Alignment_Error_Check(void);
static void Check_Sensor_Orientation_Errors(void);
static void Check_System_Input_Errors(void);
static void Dyn_Alignment_Error_Check(void);
static bool Check_Dyn_Sensor_Orientation_Errors(void);
static void Check_Dyn_System_Errors(void);
static void Service_Alignment_Error_Check(uint8_t max_distance_crossed, uint8_t max_duration_crossed);
static uint8_t Check_Max_Distance_Crossed(void);
static uint8_t Check_Max_Duration_Crossed(void);
static bool Is_Service_Alignment_Paused(void);
static void Set_Calibration_Fault_Status(void);
static bool Check_No_Initial_Calibration_Error(void);
static bool Check_NVM_Data_Corruption(void);
static bool Check_NVM_Misalignment_Range(float32_t aacurrentazimuth_nvm, float32_t aacurrentelevation_nvm);
static bool Check_NVM_Roll_Range(void);
static bool Check_NVM_Update_Counts(void);
static bool Check_NVM_Alignment_Mode(void);
static void Check_And_Fix_Host_Speed_Factor(void);
static void Check_Vehicle_Speed_And_Yaw(void);
static void Check_Vehicle_Quality_And_Reverse(void);
static void Vehicle_Input_Data_Status(void);
static Dt_Align_Status Validate_Alignment_NVM_Data(void);
static void Update_Alignment_Output(Dt_Align_Mode_T Alig_Type);
static void initialize_alignment_cals(void);
static void Send_OperationMode_To_BBE32(void);
static void Initial_Align_Sys_Err_check(void);
static void Initialize_Auto_Alignment_From_NVM(void);
static void Handle_Auto_Alignment_Precondition(void);
static void Handle_ShortTrack_Alignment(void);
static void Handle_Service_Alignment(void);
static void Handle_Static_Alignment(void);
static Dt_Align_Status Check_Alignment_Faults_And_Get_State(Dt_Align_Status current_state);
static void Update_Initial_Alignment_Value(void);
static uint8_t Alignment_OOR_Hyst_Check(float32_t misalignment_az, float32_t misalignment_el, uint8_t out_of_range_error);
static void Save_Unsuccesfull_Alignment_Data(void);
#if ((ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON))
void Test_Alignment_Faults(Dt_Alignment_Faults_T *Alignment_Faults);
#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
extern volatile int Alignment_Test_Stub;
extern volatile uint8_t Alignment_Write_Test_Result;

static int32_t Alignment_NVM_Stub_Prev = -1;

void Test_Alignment_NVM_Record_Write(Dt_Write_Alignment_NvM_Data_T *alignment_nvm_data);
void Test_Alignment_Main_RTE_Writes(Dt_AlignmentAuto *alignment_auto, Dt_AlignmentService *alignment_service,
                                    Dt_AlignmentShortTrack *alignment_shorttrack, Dt_AlignmentStatic *alignment_static,
                                    Dt_Alignment_Handler *alignment_handler, Dt_Alignment_M2D_Data *alignment_m2d);
void Test_Alignment_XCP_RTE_Writes(Dt_Auto_Alignment_Result_T *xcp_auto_alignment_data,
                                   Dt_Initial_Alignment_Result_T *xcp_initial_align_res,
                                   Dt_Initial_Alignment_Performance_Result_T *xcp_align_perf_res);
void Test_Alignment_IPC_AutoAlignment_Write(Dt_Alignment_NVM_T *ipc_autoalignment_nvm);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_AlignAuto_Error: Enumeration of integer in interval [0...255] with enumerators
 *   AH_AA_ROOTCAUSE_INVALID_INPUT (0U)
 *   AH_AA_ROOTCAUSE_SENSOR_FACING_UPWARDS (1U)
 *   AH_AA_ROOTCAUSE_SENSOR_FACING_DOWNWARDS (2U)
 *   AH_AA_ROOTCAUSE_SENSOR_FACING_RIGHT (3U)
 *   AH_AA_ROOTCAUSE_SENSOR_FACING_LEFT (4U)
 *   AH_AA_ROOTCAUSE_VELOCITY_TOO_LOW (5U)
 *   AH_AA_ROOTCAUSE_YAW_RATE_TOO_HIGH (6U)
 *   AH_AA_ROOTCAUSE_VEHICLE_IN_REVERSE (7U)
 *   AH_AA_ROOTCAUSE_INVALID_VEHICLE_SIGNAL (8U)
 *   AH_AA_ROOTCAUSE_TARGETS_TOO_LOW (9U)
 *   AH_AA_ROOTCAUSE_QUALITY_TOO_LOW (10U)
 *   AH_AA_ROOTCAUSE_BLOCKAGE (11U)
 *   AH_AA_ROOTCAUSE_OPERATION_MODE_FAULTY (12U)
 *   AH_AA_ROOTCAUSE_DATA_QUALIFIER_INVALID (13U)
 *   AH_AA_ROOTCAUSE_SUDDEN_JUMP_DETECTION (14U)
 *   AH_AA_ROOTCAUSE_CRITICAL_MISALIGNMENT (15U)
 *   AH_AA_ROOTCAUSE_CORRUPTED_NVM (16U)
 *   AH_AA_ROOTCAUSE_INACCURATE_MISALIGNMENT_VALUE (17U)
 *   AH_AA_ROOTCAUSE_INITIAL_ALIGNMENT_NOT_DONE (18U)
 *   AH_AA_ROOTCAUSE_ALIGNMENT_QF_NOT_OK (19U)
 *   AH_AA_ROOTCAUSE_TRAILER_CONNECTED (20U)
 *   AH_AA_ROOTCAUSE_NONE (255U)
 * Dt_AlignHandler_Error: Enumeration of integer in interval [0...255] with enumerators
 *   AH_ALIGNERR_NO_ERROR (0U)
 *   AH_ALIGNERR_SENSOR_FACING_UPWARDS (1U)
 *   AH_ALIGNERR_SENSOR_FACING_DOWNWARDS (2U)
 *   AH_ALIGNERR_SENSOR_FACING_RIGHT (3U)
 *   AH_ALIGNERR_SENSOR_FACING_LEFT (4U)
 *   AH_ALIGNERR_NUMBER_OF_TARGETS_TOO_LOW_SERVICE (5U)
 *   AH_ALIGNERR_QUALITY_OF_TARGET_TOO_LOW_SERVICE (6U)
 *   AH_ALIGNERR_TARGET_SIGNAL_TOO_WEAK (7U)
 *   AH_ALIGNERR_TARGET_SIGNAL_TOO_STRONG (8U)
 *   AH_ALIGNERR_TARGET_NOT_STATIC (9U)
 *   AH_ALIGNERR_TARGET_DISTANCE_TOO_HIGH_STATIC (10U)
 *   AH_ALIGNERR_TARGET_DISTANCE_TOO_LOW_STATIC (11U)
 *   AH_ALIGNERR_TARGET_NOT_FOUND_STATIC (12U)
 *   AH_ALIGNERR_INTERFERENCE_STATIC (13U)
 *   AH_ALIGNERR_INVALID_INPUT (14U)
 *   AH_ALIGNERR_INVALID_VEHICLE_SIGNAL (15U)
 *   AH_ALIGNERR_BLOCKAGE (16U)
 *   AH_ALIGNERR_MAX_DISTANCE_CROSSED_SERVICE (17U)
 *   AH_ALIGNERR_MAX_DURATION_CROSSED_SERVICE (18U)
 *   AH_ALIGNERR_OPERATION_MODE_FAULTY (19U)
 *   AH_ALIGNERR_DATA_QUALIFIER_INVALID (20U)
 *   AH_ALIGNERR_AUTO_ALIGNMENT_ANGLE_CHG (21U)
 *   AH_ALIGNERR_INVALID (255U)
 * Dt_Align_Mode_T: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGN_MODE_OFF (0U)
 *   ALIGN_MODE_AUTO (1U)
 *   ALIGN_MODE_SHORT_TRACK (2U)
 *   ALIGN_MODE_SERVICE (3U)
 *   ALIGN_MODE_STATIC (4U)
 *   ALIGN_MODE_MANUAL (5U)
 * Dt_Align_Status: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGNMENT_OFF (0U)
 *   ALIGNMENT_RUNNING (1U)
 *   ALIGNMENT_PAUSED (2U)
 *   ALIGNMENT_FAILED (3U)
 *   ALIGNMENT_SUCCESSFUL (4U)
 * Dt_Align_Veh_Cond: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGN_VEH_VEL_LOW (0U)
 *   ALIGN_VEH_VEL_HIGH (1U)
 *   ALIGN_VEH_YAW_HIGH (2U)
 *   ALIGN_VEH_VEL_QF_INSUFFICIENT (3U)
 *   ALIGN_VEH_YAW_QF_INSUFFICIENT (4U)
 *   ALIGN_VEH_VEL_REVERSE (5U)
 *   ALIGN_VEH_NO_ISSSUE (6U)
 * Dt_AlignmentModeIn_T: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   AUTOALIGNMENT (1U)
 *   SHORT_TRACK_ALIGNMENT (2U)
 *   SERVICE_ALIGNMEMT (3U)
 *   STATIC_ALIGNMENT (4U)
 * Dt_Appl_ShutdownReqStatus: Enumeration of integer in interval [0...255] with enumerators
 *   ACCEPTED (0U)
 *   PENDING (1U)
 *   REJECTED (2U)
 * Dt_DRA_Detection_Coordinate_System: Enumeration of integer in interval [0...255] with enumerators
 *   DRA_DET_COORD_SYS_UNDEFINED_ALIGN (0U)
 *   DRA_DET_COORD_SYS_SAE_ALIGN (1U)
 *   DRA_DET_COORD_SYS_ISO_ALIGN (2U)
 * Dt_Nv_Caller_ID: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID (0U)
 *   CDD_FAIL_SAFE (1U)
 *   CDD_ESM (2U)
 *   APPL_DIAG (3U)
 *   CDD_ALIGNMENT (4U)
 *   DYNAMIC_ALIGNMENT (5U)
 *   RFE_R1R2_FAULT (6U)
 *   CDD_FAILSAFE_ECC (7U)
 *   CDD_SENSORPOS (8U)
 * Dt_SystemOperationMode: Enumeration of integer in interval [0...255] with enumerators
 *   INIT_MCU (1U)
 *   RADAR_NOT_CONFIGURED (2U)
 *   OPERATIONAL (3U)
 *   FAULTY (4U)
 *   SHUTDOWN_INITIATED (5U)
 *   SHUTDOWN_COMPLETED (6U)
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 *   ECUM_STATE_SLEEP (80U)
 *   ECUM_STATE_OFF (128U)
 *   ECUM_STATE_RESET (144U)
 * Rte_DT_Dt_Alignment_Initial_NVM_T_2: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGN_MODE_OFF (0U)
 *   ALIGN_MODE_AUTO (1U)
 *   ALIGN_MODE_SHORT_TRACK (2U)
 *   ALIGN_MODE_SERVICE (3U)
 *   ALIGN_MODE_STATIC (4U)
 *   ALIGN_MODE_MANUAL (5U)
 * Rte_DT_Dt_Alignment_NVM_T_4: Enumeration of integer in interval [0...255] with enumerators
 *   ALIGN_MODE_OFF (0U)
 *   ALIGN_MODE_AUTO (1U)
 *   ALIGN_MODE_SHORT_TRACK (2U)
 *   ALIGN_MODE_SERVICE (3U)
 *   ALIGN_MODE_STATIC (4U)
 *   ALIGN_MODE_MANUAL (5U)
 * Rte_DT_Dt_Auto_Alignment_Result_T_12: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   ACTIVE (1U)
 *   PAUSED (2U)
 *   FAILED (3U)
 * Rte_DT_Dt_Auto_Alignment_Result_T_13: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID_INPUT (0U)
 *   SENSOR_FACING_UPWARDS (1U)
 *   SENSOR_FACING_DOWNWARDS (2U)
 *   SENSOR_FACING_RIGHT (3U)
 *   SENSOR_FACING_LEFT (4U)
 *   VELOCITY_TOO_LOW (5U)
 *   YAW_RATE_TOO_HIGH (6U)
 *   VEHICLE_IN_RESERVE (7U)
 *   INVALID_VEHICLE_SIGNAL (8U)
 *   TARGETS_TOO_LOW (9U)
 *   QUALITY_TOO_LOW (10U)
 *   ALIGNMENT_BLOCKAGE (11U)
 *   NONE (255U)
 *
 * Array Types:
 * ============
 * Rte_DT_Dt_DRA_Core_Log_Data_22: Array with 24 element(s) of type uint32
 * Rte_DT_Dt_DRA_Core_Log_Data_23: Array with 24 element(s) of type uint32
 * Rte_DT_Dt_DRA_Core_Log_Data_42: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Dynamic_Alignment_Data_30: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Dynamic_Alignment_Data_6: Array with 4 element(s) of type float32
 *
 * Record Types:
 * =============
 * DID_StaticAlignment_NonConfig_Param_T: Record with elements
 *   AlignmentStatic_NumberOfScans of type uint16
 *   AlignmentStatic_RangeOffset_Threshold of type uint16
 *   RangeRateUpper_Threshold of type uint16
 *   RCS_Min of type sint16
 *   RCS_Max of type uint16
 *   Velocity_Max of type uint16
 *   Yaw_Max of type sint16
 *   FlatPlateWidth_Lower_Limit of type uint16
 *   FlatPlateWidth_Upper_Limit of type uint16
 *   FlatPlateHeight_Lower_Limit of type uint16
 *   FlatPlateHeight_Upper_Limit of type uint16
 *   FlatPlateRCS_Lower_Limit of type sint16
 *   FlatPlateRCS_Upper_Limit of type sint16
 *   FlatPlateRange_Lower_Limit of type uint16
 *   FlatPlateRange_Upper_Limit of type uint16
 *   FlatPlateAzimuth_Lower_Limit of type sint16
 *   FlatPlateAzimuth_Upper_Limit of type uint16
 *   FlatPlateElevation_Lower_Limit of type sint16
 *   FlatPlateElevation_Upper_Limit of type uint16
 *   FlatPlateRangeRate_Lower_Limit of type sint16
 *   FlatPlateRangeRate_Upper_Limit of type uint16
 * Dt_AlignmentAuto: Record with elements
 *   StartAzimuth of type float32
 *   StartElevation of type float32
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AAAzimuthStd of type float32
 *   AAElevationStd of type float32
 *   AARollStd of type float32
 *   Az_Err_positive of type float32
 *   Az_Err_negative of type float32
 *   El_Err_positive of type float32
 *   El_Err_negative of type float32
 *   RollError_positive of type float32
 *   RollError_negative of type float32
 *   HostScf of type float32
 *   AzimuthNumUpdates of type uint32
 *   ElevationNumUpdates of type uint32
 *   AutoAlignmentFailRootCause of type Dt_AlignAuto_Error
 *   AlignAutoStatus of type Dt_Align_Status
 *   HostScf_QF of type uint8
 *   StartRoll of type float32
 *   AACurrentRoll of type float32
 *   RollUpdates of type uint32
 * Dt_AlignmentDyn_Initial_NVM_T: Record with elements
 *   InitialAlignmentResultAzimuthUpdates of type uint32
 *   InitialAlignmentResultElevationUpdates of type uint32
 *   InitialAlignmentResultHostSCF of type float32
 * Dt_AlignmentService: Record with elements
 *   DistanceAbsolute of type uint32
 *   DistanceEffective of type uint32
 *   AvgNumOfDet of type uint32
 *   DurationAbsolute of type uint32
 *   DurationEffective of type uint32
 *   AverageSpeed of type float32
 *   AlignmentServiceSt of type Dt_Align_Status
 *   VehicleCondition of type Dt_Align_Veh_Cond
 * Dt_AlignmentShortTrack: Record with elements
 *   AlignShortTrackSt of type Dt_Align_Status
 * Dt_AlignmentStatic: Record with elements
 *   MeasuredAzimuth of type float32
 *   MeasuredElevation of type float32
 *   Measured_Az_Std of type float32
 *   Measured_El_Std of type float32
 *   MeasuredRange of type float32
 *   MeasuredRangeStd of type float32
 *   MeasuredRangeRate of type float32
 *   MeasuredRangeRateStd of type float32
 *   MeasuredAmplitude of type float32
 *   MeasuredAmpStd of type float32
 *   AlignmentStaticStatus of type Dt_Align_Status
 *   StatusOfPlate of type uint8
 *   StatusOfAzimuth of type uint8
 *   StatusOfElevation of type uint8
 *   ImpactByInterference of type boolean
 * Dt_Alignment_AutoCyclic_NVM_T: Record with elements
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 * Dt_Alignment_Auto_NVM_T: Record with elements
 *   AzimuthUpdates of type uint32
 *   ElevationUpdates of type uint32
 *   HostScf of type float32
 * Dt_Alignment_Faults_T: Record with elements
 *   No_Initial_Calibration_error of type uint8
 *   Static_Calibration_error of type uint8
 *   Service_Calibration_error of type uint8
 *   ShortTrack_Calibration_error of type uint8
 *   Autoalign_outof_range_error of type uint8
 *   Autoalignment_algo_error of type uint8
 *   Autoalignment_critical_misalignment_error of type uint8
 *   Autoalignment_sudden_jump_detection_error of type uint8
 * Dt_Alignment_Handler: Record with elements
 *   InitialAlignmentResultAz of type float32
 *   InitialAlignmentResultEl of type float32
 *   InitialAlignmentResultHostSCF of type float32
 *   InitialAlignmentResultAzUpdates of type uint32
 *   InitialAlignmentResultElUpdates of type uint32
 *   AlignmentAzimuth of type float32
 *   AlignmentElevation of type float32
 *   AzimuthStd of type float32
 *   ElevationStd of type float32
 *   calTime of type float32
 *   CalDisplay of type uint8
 *   ProgressPercent of type uint8
 *   AlignmentError of type Dt_AlignHandler_Error
 *   ElevationQuality of type uint8
 *   AzimuthQuality of type uint8
 *   Alignment_modeIn of type Dt_Align_Mode_T
 *   AlignmentModeOut of type Dt_Align_Mode_T
 *   InitialLastSuccessAlignmentMode of type Dt_Align_Mode_T
 *   Radar_Type_Input of type uint8
 *   CoordinateSystem_Input of type Dt_DRA_Detection_Coordinate_System
 *   InitialAlignmentResultRoll of type float32
 *   InitialAlignmentResultRollUpdates of type uint32
 *   AlignmentRoll of type float32
 *   RollStd of type float32
 * Dt_Alignment_IPC_Data: Record with elements
 *   dra_core_log_data of type Dt_DRA_Core_Log_Data
 *   sra_core_log_data of type Dt_SRA_Core_Log_Data
 *   alignment_static of type Dt_Alignment_Static
 *   veh_info of type Dt_Veh_Info
 *   alignment_stream of type Dt_Alignment_Stream
 *   alignment_mode of type uint8
 *   interference_detected of type uint8
 *   blockage_active of type boolean
 *   operation_mode_status of type uint8
 *   data_qualifier of type uint8
 *   look_index of type uint32
 * Dt_Alignment_Initial_NVM_T: Record with elements
 *   InitialAlignmentResultAzimuth of type float32
 *   InitialAlignmentResultElevation of type float32
 *   InitialLastSuccessfulAlignmentMode of type Rte_DT_Dt_Alignment_Initial_NVM_T_2
 * Dt_Alignment_M2D_Data: Record with elements
 *   static_alignment_data of type Dt_Static_Alignment_Data
 *   dynamic_alignment_data of type Dt_Dynamic_Alignment_Data
 * Dt_Alignment_NVM_T: Record with elements
 *   Alignment_Initial_NVM_Data of type Dt_Alignment_Initial_NVM_T
 *   AlignmentDyn_Initial_NVM_Data of type Dt_AlignmentDyn_Initial_NVM_T
 *   Alignment_AutoCyclic_NVM_Data of type Dt_Alignment_AutoCyclic_NVM_T
 *   Alignment_Auto_NVM_data of type Dt_Alignment_Auto_NVM_T
 *   AlignmentModeOut of type Rte_DT_Dt_Alignment_NVM_T_4
 * Dt_Alignment_Static: Record with elements
 *   StatusOfPlate of type uint8
 *   StatusOfAzimuth of type uint8
 *   StatusOfElevation of type uint8
 * Dt_Alignment_Stream: Record with elements
 *   horiz_misalign_ang of type float32
 *   vert_misalign_ang of type float32
 *   std_azimuth of type float32
 *   std_elevation of type float32
 *   meas_plate_range of type float32
 *   meas_plate_r_dot of type float32
 *   meas_plate_rcs of type float32
 *   std_range of type float32
 *   std_r_dot of type float32
 *   complete_percentage of type float32
 *   status_of_plate of type uint8
 *   status_horiz_misalign_ang of type uint8
 *   status_vert_misalign_ang of type uint8
 * Dt_Auto_Alignment_Result_T: Record with elements
 *   StartAzimuth of type float32
 *   StartElevation of type float32
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AAAzimuthStd of type float32
 *   AAElevationStd of type float32
 *   AzimuthError_positiveRead of type float32
 *   AzimuthError_negativeRead of type float32
 *   ElevationError_positive_Read of type float32
 *   ElevationError_negative_Read of type float32
 *   RollError_positive_Read of type float32
 *   RollError_negative of type float32
 *   AlignmentAutoStatus of type Rte_DT_Dt_Auto_Alignment_Result_T_12
 *   AutoAlignmentFailRootCause of type Rte_DT_Dt_Auto_Alignment_Result_T_13
 *   StartRoll of type float32
 *   AACurrentRoll of type float32
 *   AARollStd of type float32
 * Dt_Auto_Alignment_Status_Information: Record with elements
 *   AlignmentModeOut of type uint8
 *   AlignmentAutoStatus of type uint8
 *   AutoAlignmentFailRootCause of type uint8
 *   StartAzimuth of type sint32
 *   StartElevation of type sint32
 *   StartRoll of type sint32
 *   AACurrentAzimuth of type sint32
 *   AACurrentElevation of type sint32
 *   AACurrentRoll of type sint32
 *   AAAzimuthStd of type sint32
 *   AAElevationStd of type sint32
 *   AARollStd of type sint32
 *   InitialLastSuccessfulAlignmentMode of type uint8
 *   InitialAlignmentResultAzimuth of type sint32
 *   InitialAlignmentResultElevation of type sint32
 *   InitialAlignmentResultRoll of type sint32
 *   AzimuthError_positive of type sint32
 *   ElevationError_positive of type sint32
 *   RollError_positive of type sint32
 *   AzimuthError_negative of type sint32
 *   ElevationError_negative of type sint32
 *   RollError_negative of type sint32
 *   HostSpeedCompensationFactor of type sint32
 *   HostSpeedCompensationFactor_QF of type uint8
 *   AzimuthUpdates of type uint32
 *   ElevationUpdates of type uint32
 *   RollUpdates of type uint32
 * Dt_DRA_Core_Log_Data: Record with elements
 *   vacs_boresight_az_estimated of type float32
 *   vacs_boresight_el_estimated of type float32
 *   estimated_standard_deviation_az of type float32
 *   estimated_standard_deviation_el of type float32
 *   alignment_complete_percent_az of type float32
 *   alignment_complete_percent_el of type float32
 *   total_time_since_start of type float32
 *   total_time_running_az_scf of type float32
 *   total_time_running_el of type float32
 *   total_distance_since_start of type float32
 *   total_distance_running_az_scf of type float32
 *   total_distance_running_el of type float32
 *   avg_spd_since_start of type float32
 *   avg_spd_running_az_scf of type float32
 *   avg_spd_running_el of type float32
 *   estimated_pos_error_bound_az of type float32
 *   estimated_pos_error_bound_el of type float32
 *   estimated_neg_error_bound_az of type float32
 *   estimated_neg_error_bound_el of type float32
 *   speed_compensation_factor_estimated of type float32
 *   n_updates_azimuth of type uint32
 *   n_updates_elevation of type uint32
 *   detection_used_az of type Rte_DT_Dt_DRA_Core_Log_Data_22
 *   detection_used_el of type Rte_DT_Dt_DRA_Core_Log_Data_23
 *   alignment_mode of type uint8
 *   error_status_detection_input of type uint8
 *   azimuth_estimation_qf of type uint8
 *   elevation_estimation_qf of type uint8
 *   error_status_az_est_out_of_bounds of type uint8
 *   error_status_el_est_out_of_bounds of type uint8
 *   error_status_initialization of type uint8
 *   error_status_excessive_blockage of type uint8
 *   error_status_vehicle_input of type uint8
 *   detection_coordinate_system of type uint8
 *   error_status_scf_out_of_bounds of type uint8
 *   error_status_combined of type uint8
 *   error_status_interference of type uint8
 *   scf_estimation_qf of type uint8
 *   n_updates_roll of type uint32
 *   vacs_boresight_roll_initial of type float32
 *   vacs_boresight_roll_kf_internal of type float32
 *   vacs_boresight_roll_estimated of type float32
 *   el_roll_kf_covariance of type Rte_DT_Dt_DRA_Core_Log_Data_42
 *   alignment_index of type uint32
 *   vacs_boresight_az_kf_internal of type float32
 *   vacs_boresight_el_kf_internal of type float32
 *   estimated_standard_deviation_rl of type float32
 *   estimated_pos_error_bound_rl of type float32
 *   estimated_neg_error_bound_rl of type float32
 *   num_cycles_since_well_converged of type uint32
 *   flag_well_converged_az_el of type uint8
 *   interference_detected of type uint8
 *   blockage_active of type boolean
 *   coordinate_system of type uint8
 *   error_status_sudden_state_change of type uint8
 *   error_status_parking_accident of type uint8
 *   vacs_boresight_az_nominal of type float32
 *   vacs_boresight_el_nominal of type float32
 *   error_status_trailer_detected of type uint8
 * Dt_Dynamic_Alignment_Data: Record with elements
 *   initial_vacs_boresight_az_estimated of type float32
 *   initial_vacs_boresight_el_estimated of type float32
 *   initial_speed_compensation_factor of type float32
 *   max_abs_misalignment_az of type float32
 *   short_track_target_height of type float32
 *   short_track_target_range_rate of type float32
 *   az_scf_kf_covariance of type Rte_DT_Dt_Dynamic_Alignment_Data_6
 *   el_kf_covariance of type float32
 *   iso_sensor_x_posn of type float32
 *   iso_sensor_y_posn of type float32
 *   iso_sensor_z_posn of type float32
 *   iso_sensor_yaw of type float32
 *   iso_sensor_pitch of type float32
 *   iso_sensor_roll of type float32
 *   distance_rear_axle_to_front_bumper of type float32
 *   max_abs_misalignment_el_sky of type float32
 *   max_abs_misalignment_el_ground of type float32
 *   aacurrent_azimuth of type float32
 *   aacurrent_elevation of type float32
 *   initial_num_updates_az of type uint32
 *   initial_num_updates_el of type float32
 *   mount_loc of type uint8
 *   short_track_exit_condition of type uint8
 *   f_data_valid of type uint8
 *   initial_align_quality_factor_el of type uint8
 *   initial_align_quality_factor_az of type uint8
 *   align_cmd of type uint8
 *   auto_align_status of type uint8
 *   initial_vacs_boresight_rl_estimated of type float32
 *   initial_num_updates_rl of type uint8
 *   el_roll_kf_covariance of type Rte_DT_Dt_Dynamic_Alignment_Data_30
 *   Align_RadarOperation_Mode of type uint8
 *   coordinate_system_input of type uint8
 * Dt_Initial_Alignment_Performance_Result_T: Record with elements
 *   MeasuredRange of type float32
 *   MeasuredRangeStd of type float32
 *   MeasuredRangeRate of type float32
 *   MeasuredRangeRateStd of type float32
 *   MeasuredAmp of type float32
 *   MeasuredAmpStd of type float32
 *   DistanceAbsolute of type uint32
 *   DistanceEffective of type uint32
 *   AverageNumberOfDetections of type float32
 *   DurationAbsolute of type uint32
 *   DurationEffective of type uint32
 *   AverageSpeed of type float32
 *   VehicleCondition of type uint8
 * Dt_Initial_Alignment_Result_T: Record with elements
 *   AlignmentAzimuth of type float32
 *   AlignmentElevation of type float32
 *   AzimuthStd of type float32
 *   ElevationStd of type float32
 *   CalTime of type float32
 *   AlignmentStaticStatus of type uint8
 *   AlignmentServiceStatus of type uint8
 *   AlignmentShortTrackStatus of type uint8
 *   ProgressPercent of type uint8
 *   AlignmentError of type uint8
 *   AlignmentRoll of type float32
 *   RollStd of type float32
 * Dt_Manual_Alignment_Execution_Data: Record with elements
 *   AlignmentModeIn of type Dt_Align_Mode_T
 *   InitialLastSuccessfulAlignmentMode of type Dt_Align_Mode_T
 *   IntialMisalignmentAngleAzimuth of type sint32
 *   IntialMisalignmentAngleElevation of type sint32
 * Dt_Manual_Alignment_Execution_Data_CRC: Record with elements
 *   Manual_Alignment_Execution_Data of type Dt_Manual_Alignment_Execution_Data
 *   Data_CRC of type uint32
 * Dt_SRA_Core_Log_Data: Record with elements
 *   vacs_boresight_az_nominal of type float32
 *   vacs_boresight_az_estimated of type float32
 *   vacs_boresight_el_nominal of type float32
 *   vacs_boresight_el_estimated of type float32
 *   estimated_standard_deviation_az of type float32
 *   estimated_standard_deviation_el of type float32
 *   target_mean_azimuth of type float32
 *   target_mean_elevation of type float32
 *   target_mean_range of type float32
 *   target_mean_r_dot of type float32
 *   target_mean_raw_amp of type float32
 *   target_mean_snr of type float32
 *   target_std_dev_azimuth of type float32
 *   target_std_dev_elevation of type float32
 *   target_std_dev_range of type float32
 *   target_std_dev_r_dot of type float32
 *   target_std_dev_raw_amp of type float32
 *   target_std_dev_snr of type float32
 *   complete_percentage of type float32
 *   n_updates_az_el of type uint32
 *   AlgoStatus of type uint8
 *   ErrorAzimuthEstimate of type uint8
 *   ErrorElevationEstimate of type uint8
 *   ErrorStatusInterference of type uint8
 *   ErrorStatusIntialisation of type uint8
 *   ErrorStatusDetection of type uint8
 *   ErrorStatusVehical of type uint8
 *   f_interference_detected of type uint8
 *   az_qf of type uint8
 *   el_qf of type uint8
 *   alignment_mode of type uint8
 * Dt_Service_Alignment_Engineering_Non_Configuration_Parameters: Record with elements
 *   AlignService_Abs_Dist_Th of type uint16
 *   AlignService_Eff_Dist_Th of type uint16
 *   AlignService_Abs_Duration_Th of type uint16
 *   AlignService_Eff_Duration_Th of type uint16
 *   AlignService_Vel_Min of type uint16
 *   AlignService_Vel_Max of type uint16
 *   AlignService_Yawrate_Max of type uint16
 * Dt_Service_Alignment_Result_Parameters: Record with elements
 *   AlignmentModeOut of type uint8
 *   AlignmentServiceStatus of type uint8
 *   AlignmentError of type uint8
 *   AlignmentAzimuth of type sint32
 *   AlignmentElevation of type sint32
 *   AlignmentRoll of type sint32
 *   AzimuthStd of type sint32
 *   ElevationStd of type sint32
 *   RollStd of type sint32
 *   CalTime of type sint32
 *   ProgressPercent of type uint8
 *   CalDisplay of type uint8
 *   InitialAlignmentResultAzimuthUpdates of type uint32
 *   InitialAlignmentResultElevationUpdates of type uint32
 *   InitialAlignmentResultRollUpdates of type uint32
 *   InitialAlignmentResultHostSpeedCompensationFactor of type sint32
 *   VehicleCondition of type uint8
 *   AverageNumberOfDetections of type uint32
 *   AverageSpeed of type uint32
 *   DistanceAbsolute of type uint32
 *   DistanceEffective of type uint32
 *   DurationAbsolute of type uint32
 *   DurationEffective of type uint32
 *   InitialLastSuccessfulAlignmentMode of type uint8
 *   InitialAlignmentResultAzimuth of type sint32
 *   InitialAlignmentResultElevation of type sint32
 *   InitialAlignmentResultRoll of type sint32
 * Dt_Static_Alignment_Data: Record with elements
 *   yaw of type float32
 *   pitch of type float32
 *   plate_angle_deg_scs of type float32
 *   plate_distance of type float32
 *   polarity of type float32
 *   horz_angle_min of type float32
 *   horz_angle_max of type float32
 *   vert_angle_min of type float32
 *   vert_angle_max of type float32
 *   plate_lat_position of type float32
 *   mount_loc of type uint8
 *   align_cmd of type uint8
 *   max_abs_misalignment_az of type float32
 *   max_abs_misalignment_el_sky of type float32
 *   max_abs_misalignment_el_ground of type float32
 *   target_height_over_ground of type float32
 *   k_num_valid_scan_needed of type uint16
 *   k_max_number_of_scans_allowed of type uint16
 *   target_range_rate of type float32
 *   target_type_select of type uint8
 *   f_data_valid of type uint8
 * Dt_Static_Alignment_Engineering_Parameters: Record with elements
 *   AlignmentStatic_AzimuthUpper_Threshold of type uint16
 *   AlignmentStatic_AzimuthLower_Threshold of type sint16
 *   AlignmentStatic_ElevationUpper_Threshold of type uint16
 *   AlignmentStatic_ElevationLower_Threshold of type sint16
 *   AlignmentStatic_TargetAzimuth of type sint16
 *   AlignmentStatic_TargetElevation of type sint16
 *   AlignmentStatic_TargetDistance of type uint16
 * Dt_Static_Alignment_Engineering_Write_Configuration_Parameters: Record with elements
 *   AlignmentStatic_TargetAzimuth of type sint16
 *   AlignmentStatic_TargetElevation of type sint16
 *   AlignmentStatic_TargetDistance of type uint16
 * Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC: Record with elements
 *   Static_alignment_write_Params of type Dt_Static_Alignment_Engineering_Write_Configuration_Parameters
 *   Data_CRC of type uint32
 * Dt_Veh_Info: Record with elements
 *   veh_speed of type float32
 *   veh_yaw of type float32
 *   veh_speed_qf of type uint8
 *   veh_yaw_qf of type uint8
 *   lros_drive_reverse of type uint8
 * Dt_Write_Alignment_NvM_Data_T: Record with elements
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AACurrentRoll of type float32
 *   InitialAlignmentResultAzimuth of type float32
 *   InitialAlignmentResultElevation of type float32
 *   InitialAlignmentResultRoll of type float32
 *   InitialLastSuccessfulAlignmentMode of type float32
 *   ElevationUpdates of type float32
 *   AzimuthUpdates of type float32
 *   RollUpdates of type float32
 *   InitialAlignmentResultElevationUpdates of type float32
 *   InitialAlignmentResultHostSpeedCompensationFactor of type float32
 *   HostSpeedCompensationFactor of type float32
 *   InitialAlignmentResultAzimuthUpdates of type float32
 *   InitialAlignmentResultRollUpdates of type float32
 *   AlignmentModeOut of type uint8
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Dt_Alignment_NVM_T *Rte_CData_Appl_AutoAlignment_DefaultValue(void)
 *
 *********************************************************************************************************************/

#define SWC_PLT_Radar_Alignment_Handler_START_SEC_CODE
#include "SWC_PLT_Radar_Alignment_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Alignment_Fault_Injection_read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <read> of PortPrototype <CS_Alignment_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Alignment_Fault_Injection_read(uint8 Injection_control)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Alignment_Fault_Injection_read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE)
CS_Alignment_Fault_Injection_read(uint8 Injection_control) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Alignment_Fault_Injection_read
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Alignment_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data(Dt_Write_Alignment_NvM_Data_T *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Alignment_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE) RE_Alignment_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Alignment_Init
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Alignment_Main_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data(Dt_Alignment_IPC_Data *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data(Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_Type_Alignment_Type(Dt_AlignmentModeIn_T *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM(Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_IPC_SWC_AutoAlignment_Input_De_AutoAlignment(Dt_Alignment_NVM_T *data)
 *   Std_ReturnType
 *Rte_Read_Rp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC(Dt_Manual_Alignment_Execution_Data_CRC
 **data) Std_ReturnType Rte_Read_Rp_OperationMode_Type_De_OperationMode_System(Dt_SystemOperationMode *data) Std_ReturnType
 *Rte_Read_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC
 **data) Std_ReturnType Rte_Read_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Align_Write_Nvm_Record_Alignment_Record(const Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Write_Pp_AlignmentAuto_De_AlignmentAuto(const Dt_AlignmentAuto *data)
 *   Std_ReturnType Rte_Write_Pp_AlignmentService_De_AlignmentService(const Dt_AlignmentService *data)
 *   Std_ReturnType Rte_Write_Pp_AlignmentShortTrack_De_AlignmentShortTrack(const Dt_AlignmentShortTrack *data)
 *   Std_ReturnType Rte_Write_Pp_AlignmentStatic_De_AlignmentStatic(const Dt_AlignmentStatic *data)
 *   Std_ReturnType Rte_Write_Pp_Alignment_Faults_De_Alignment_Faults(const Dt_Alignment_Faults_T *data)
 *   Std_ReturnType Rte_Write_Pp_Alignment_Handler_De_Alignment_Handler(const Dt_Alignment_Handler *data)
 *   Std_ReturnType Rte_Write_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data(const Dt_Alignment_M2D_Data *data)
 *   Std_ReturnType Rte_Write_Pp_Auto_Alignment_Data_Auto_Alignment_Data(const Dt_Auto_Alignment_Result_T *data)
 *   Std_ReturnType Rte_Write_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information(const
 *Dt_Auto_Alignment_Status_Information *data) Std_ReturnType Rte_Write_Pp_IPC_SWC_AutoAlignment_Output_De_AutoAlignment(const
 *Dt_Alignment_NVM_T *data) Std_ReturnType Rte_Write_Pp_Initial_Alignment_Result_Initial_Alignment_Result(const
 *Dt_Initial_Alignment_Result_T *data) Std_ReturnType
 *Rte_Write_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(const
 *Dt_Manual_Alignment_Execution_Data_CRC *data) Std_ReturnType
 *Rte_Write_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters(const
 *Dt_Service_Alignment_Engineering_Non_Configuration_Parameters *data) Std_ReturnType
 *Rte_Write_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters(const
 *Dt_Service_Alignment_Result_Parameters *data) Std_ReturnType
 *Rte_Write_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T(const DID_StaticAlignment_NonConfig_Param_T
 **data) Std_ReturnType Rte_Write_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters(const
 *Dt_Static_Alignment_Engineering_Parameters *data) Std_ReturnType
 *Rte_Write_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform(const Dt_Initial_Alignment_Performance_Result_T *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Get_Platform_Elapsed_ustime_read(uint32 *inst_us_time, uint64 start_time)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Get_PlatfromTime_us_read(uint64 *instant_ustime)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Rp_Trigger_Write_to_NvM_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID
 *dt_Nv_Caller_Id) Synchronous Server Invocation. Timeout: None Std_ReturnType
 *Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Ecu_Shutdown_Request_Ecu_Shutdown_Request(EcuM_StateType ShutdownTarget, Dt_Appl_ShutdownReqStatus
 **ReqStatus) Synchronous Server Invocation. Timeout: None Returned Application Errors: RTE_E_Ecu_Shutdown_Request_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Alignment_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Radar_Alignment_Handler_CODE)
RE_Alignment_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Alignment_Main_50ms
    *********************************************************************************************************************/

   static uint8_t alignment_initialized_flag = CODED_FALSE;

   if (alignment_initialized_flag == CODED_FALSE)
   {
      M2D_One_Time_Msg_T volatile *m2d_one_time_init_ptr = Get_IPC_M2D_Onetime_Msg_Buffer();
      if (NULL_PTR != m2d_one_time_init_ptr)
      {
         if (m2d_one_time_init_ptr->calib_data.data_availability_status == CODED_TRUE)
         {
            Initialize_alignment(); /* Re-initialize alignment when M2D one time message with valid data is received for the first
                                       time. This is to ensure that the alignment module has the latest sensor mounting parameters
                                       and alignment type before processing the alignment */
            alignment_initialized_flag = CODED_TRUE;
         }
      }
   }

#if (K_PLATFORM_VARIANT == 82) /*Flr8 sensor type check*/
   AlignmentHandler.Radar_Type_Input = (DRA_Radar_Type_T)DRA_RADAR_TYPE_FLR8;
#elif (K_PLATFORM_VARIANT == 83) /*Srr8p sensor type check*/
   AlignmentHandler.Radar_Type_Input                                   = (DRA_Radar_Type_T)DRA_RADAR_TYPE_SRR8P;
#else
   #error "Unknown sensor type"
#endif

   p_align_d2m = (D2M_Msg_T *)Get_IPC_D2M_Sp_Post_Proc_Buffer();

   (void)Rte_Read_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data(&alignment_ipc_data);

   /*Dynamic Structure Will be updated with Live data from Algo every Driving Cycle*/
   /*Intention was to Use to Dynamic Structre if Alignment Handler is disabled*/
   Update_Current_Dyn_Alignment_Data();
   Send_OperationMode_To_BBE32(); /* Update the operation Mode */
   if (alignment_initialized_flag == CODED_TRUE)
   {
      Alignment_Handler();
   }

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   if (Alignment_Test_Stub != Alignment_NVM_Stub_Prev)
   {
      Alignment_NVM_Stub_Prev = Alignment_Test_Stub;
      if ((Alignment_Test_Stub == 3) || (Alignment_Test_Stub == 4))
      {
         /* Trigger actual NVM write path once when NVM stub selection changes. */
         Update_Alignment_NVM_Data();
      }
      else if (Alignment_Test_Stub == 6)
      {
         /* Trigger XCP alignment write path once when stub 6 is selected. */
         Update_XCP_Alignment_Data();
      }
   }

   Test_Alignment_Main_RTE_Writes(&AlignmentAuto, &AlignmentService, &AlignmentShortTrack, &AlignmentStatic, &AlignmentHandler,
                                  &alignment_m2d_data);
#endif

   /* Write AlignmentAuto data */
   Rte_Write_Pp_AlignmentAuto_De_AlignmentAuto(&AlignmentAuto);
   /* Write AlignmentService data */
   Rte_Write_Pp_AlignmentService_De_AlignmentService(&AlignmentService);
   /* Write AlignmentShortTrack data */
   Rte_Write_Pp_AlignmentShortTrack_De_AlignmentShortTrack(&AlignmentShortTrack);
   /* Write AlignmentStatic data */
   Rte_Write_Pp_AlignmentStatic_De_AlignmentStatic(&AlignmentStatic);
   /* Write AlignmentHandler data */
   Rte_Write_Pp_Alignment_Handler_De_Alignment_Handler(&AlignmentHandler);

   (void)Rte_Write_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data(&alignment_m2d_data);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Radar_Alignment_Handler_STOP_SEC_CODE
#include "SWC_PLT_Radar_Alignment_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
   Function name        : get_alignment_m2d_data.dynamic_alignment_data.
   Function Description : This function Get daynamic alignment config data
   Input Parameters     : Nil
   Return               : &alignment_m2d_data.dynamic_alignment_data.
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/

Dt_Dynamic_Alignment_Data *Get_Dynamic_Alignment_M2D(void)
{
   return &alignment_m2d_data.dynamic_alignment_data;
}

/******************************************************************************
   Function name        : Get_alignment_m2d_data.static_alignment_data.
   Function Description : This function Get static alignment config data
   Input Parameters     : Nil
   Return               : &alignment_m2d_data.static_alignment_data.
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/

Dt_Static_Alignment_Data *Get_Static_Alignment_M2D(void)
{
   return &alignment_m2d_data.static_alignment_data;
}

/******************************************************************************
   Function name        : Get_AlignmentHandler
   Function Description : This function Get alignment alignment data
   Input Parameters     : Nil
   Return               : &Alignment_Handler_T
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
Dt_Alignment_Handler *Get_AlignmentHandler(void)
{
   return &AlignmentHandler;
}

/******************************************************************************
   Function name        : Get_AlignmentService
   Function Description : This function alignment service data
   Input Parameters     : Nil
   Return               : &AlignmentService_T
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
Dt_AlignmentService *Get_AlignmentService(void)
{
   return &AlignmentService;
}

/******************************************************************************
   Function name        : Get_AlignmentShortTrack
   Function Description : This function alignment shorttrack data
   Input Parameters     : Nil
   Return               : &AlignmentShortTrack_T
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
Dt_AlignmentShortTrack *Get_AlignmentShortTrack(void)
{
   return &AlignmentShortTrack;
}

/******************************************************************************
   Function name        : Get_AlignmentAuto
   Function Description : This function auto alignment data
   Input Parameters     : Nil
   Return               : &AlignmentAuto
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
Dt_AlignmentAuto *Get_AlignmentAuto(void)
{
   return &AlignmentAuto;
}

/******************************************************************************
   Function name        : Get_AlignmentStatic
   Function Description : This function Get static alignment data
   Input Parameters     : Nil
   Return               : &AlignmentStatic
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
Dt_AlignmentStatic *Get_AlignmentStatic(void)
{
   return &AlignmentStatic;
}

/******************************************************************************
   Function name        : Initialize_alignment
   Function Description : This function to initialize required parameters for alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Initialize_alignment(void)
{
   Update_Dynamic_Alignment_Config_Params();
   Update_Static_Alignment_Config_Params();
}

/******************************************************************************
   Function name        : initialize_alignment_cals
   Function Description : This function to initialize required cals parameters for alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void initialize_alignment_cals(void)
{
   alignment_auto_cals.nvm_cycle_time                  = k_align_auto_nvm_cycle_time_smc;
   alignment_auto_cals.azimuth_threshold               = k_align_auto_azimuth_threshold_smc; /* radians*/
   alignment_auto_cals.elevation_threshold             = k_align_auto_elevation_threshold_smc;
   alignment_auto_cals.critical_misalignment_threshold = 0.1186F; /* This value should be updated from smc once available */

   alignment_initial_cals.absolute_distance_threshold  = (uint16_t)k_align_service_absolute_distance_threshold_smc;  /* m*/
   alignment_initial_cals.effective_distance_threshold = (uint16_t)k_align_service_effective_distance_threshold_smc; /* m*/
   alignment_initial_cals.absolute_duration_threshold  = (uint16_t)k_align_service_absolute_duration_threshold_smc;  /* sec*/
   alignment_initial_cals.effective_duration_threshold = (uint16_t)k_align_service_effective_duration_threshold_smc; /* sec*/
   alignment_initial_cals.velocity_min                 = (uint16_t)k_align_service_velocity_min_smc;                 /*m/sec*/
   alignment_initial_cals.velocity_max                 = (uint16_t)k_align_service_velocity_max_smc;                 /*190m/sec*/
   alignment_initial_cals.yawrate_max                  = k_align_service_yaw_rate_max_smc;                           /*rad/s*/
   /*Replace hardcoded value with SMC when k_Config_AlignmentShortTrack_Submode_Switch_SMC parameter is available*/
   alignment_initial_cals.short_track_submode = 0U; /*Default to Standard Short Track */
}

/******************************************************************************
   Function name        : Update_Dynamic_Alignment_Config_Params
   Function Description : This function updates the mounting data to M2D buffer
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Dynamic_Alignment_Config_Params(void)
{
   /*Read the Dynamic Alignment PIM from NvM Module init*/
   (void)Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data(&Alignment_NVM_Data);

/*Stub code for NVM corruption check*/
#ifdef ALIGNMENT_NVM_FAIL_TEST
   memset(&Alignment_NVM_Data, 0xff, sizeof(Dt_Write_Alignment_NvM_Data_T));
#endif
   AlignmentAuto.AlignAutoStatus = Validate_Alignment_NVM_Data();
   if (AlignmentAuto.AlignAutoStatus == ALIGNMENT_FAILED)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_CORRUPTED_NVM;
   }

   Calib_Data_T volatile *calib_data_ptr = &Get_IPC_M2D_Onetime_Msg_Buffer()->calib_data;
   /* send mounting information to DSS core */
   /* mount_loc to be updated from one time buffer, once brought up parameter in the one time buffer*/
   alignment_m2d_data.dynamic_alignment_data.mount_loc = k_sensor_mount_location_smc;
   Align_Mounting_Parameters.iso_sensor_yaw   = calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw;
   Align_Mounting_Parameters.iso_sensor_pitch = calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch;
   Align_Mounting_Parameters.iso_sensor_roll  = calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll;

   /*Alignment thresholds to be passed thru M2D, since different thresholds required for Auto and Service Alignments*/
   alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_az        = k_max_abs_misalignment_az_smc;
   alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_sky    = k_max_abs_misalignment_el_smc;
   alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_ground = k_max_abs_misalignment_el_smc;

   alignment_m2d_data.dynamic_alignment_data.short_track_target_height     = 0.8F;
   alignment_m2d_data.dynamic_alignment_data.short_track_target_range_rate = -11.0F;
   alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[0]       = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[1]       = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[2]       = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[3]       = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[0]      = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[1]      = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[2]      = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[3]      = 0.0F;
   alignment_m2d_data.dynamic_alignment_data.short_track_exit_condition    = DRA_SHORT_TRACK_EXIT_AUTO;

   /* send the stored NvM data to DSS core */
   alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated =
      (Align_Mounting_Parameters.iso_sensor_yaw * -1.0F);
   alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated =
      (Align_Mounting_Parameters.iso_sensor_pitch * -1.0F);
   alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated =
      0.0F; /*Update with proper value once roll signal is ready */
   Initialize_Auto_Alignment_From_NVM();
   AlignmentHandler.InitialAlignmentResultHostSCF = Alignment_NVM_Data.InitialAlignmentResultHostSpeedCompensationFactor;

   AlignmentAuto.HostScf = ((Alignment_NVM_Data.HostSpeedCompensationFactor < HOST_SPEED_COMP_FACTOR_MIN) ||
                            (Alignment_NVM_Data.HostSpeedCompensationFactor > HOST_SPEED_COMP_FACTOR_MAX)) ?
                              1.0F :
                              Alignment_NVM_Data.HostSpeedCompensationFactor;

   /*Auto Alignment to be Started on next Cycle irrespective of Last Run Alignment*/
   AlignmentHandler.Alignment_modeIn = ALIGN_MODE_AUTO;

   /* send the stored NvM data to DSS core */
   alignment_m2d_data.dynamic_alignment_data.initial_speed_compensation_factor = AlignmentAuto.HostScf;
   alignment_m2d_data.dynamic_alignment_data.initial_num_updates_az            = AlignmentAuto.AzimuthNumUpdates;
   alignment_m2d_data.dynamic_alignment_data.initial_num_updates_el            = AlignmentAuto.ElevationNumUpdates;
#ifdef FLR8
   alignment_m2d_data.dynamic_alignment_data.initial_num_updates_rl = AlignmentAuto.RollUpdates;
#endif
   alignment_m2d_data.dynamic_alignment_data.f_data_valid = 1U;
   /* Initialize smc parameters */
   initialize_alignment_cals();
   /* Check Outof range only if NVM is not corrupted */
   if (AlignmentAuto.AlignAutoStatus != ALIGNMENT_FAILED)
   {
      Auto_Align_OOR_Fault_Check();
   }
}

/******************************************************************************
   Function name        : Update_Static_Alignment_Config_Params
   Function Description : This function updates the static alignment data to M2D buffer
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Static_Alignment_Config_Params(void)
{
   uint8_t sensor_posn                   = Get_Radar_Position() - 1U;
   Calib_Data_T volatile *calib_data_ptr = &Get_IPC_M2D_Onetime_Msg_Buffer()->calib_data;

   if (sensor_posn < MAX_RADAR_SENSOR_POS)
   {
      /* static alignment init */
      alignment_m2d_data.static_alignment_data.plate_distance      = k_align_static_target_distance_smc;
      alignment_m2d_data.static_alignment_data.plate_angle_deg_scs = k_align_static_plate_angle_deg_scs_smc;
      alignment_m2d_data.static_alignment_data.yaw                 = k_align_static_target_azimuth_smc;
      alignment_m2d_data.static_alignment_data.pitch               = k_align_static_target_elevation_smc;

      alignment_m2d_data.static_alignment_data.plate_lat_position = k_align_static_plate_lat_position_smc;
      alignment_m2d_data.static_alignment_data.horz_angle_min     = k_align_static_azimuth_lower_threshold_smc;
      alignment_m2d_data.static_alignment_data.horz_angle_max     = k_align_static_azimuth_upper_threshold_smc;
      alignment_m2d_data.static_alignment_data.vert_angle_min     = k_align_static_elevation_lower_threshold_smc;
      alignment_m2d_data.static_alignment_data.vert_angle_max     = k_align_static_elevation_upper_threshold_smc;
      alignment_m2d_data.static_alignment_data.mount_loc          = k_sensor_mount_location_smc;
      alignment_m2d_data.static_alignment_data.f_data_valid       = 1U;

      alignment_m2d_data.static_alignment_data.max_abs_misalignment_az = k_align_static_azimuth_upper_threshold_smc * Deg2Radians;
      alignment_m2d_data.static_alignment_data.max_abs_misalignment_el_sky =
         k_align_static_elevation_upper_threshold_smc * Deg2Radians;
      alignment_m2d_data.static_alignment_data.max_abs_misalignment_el_ground =
         k_align_static_elevation_upper_threshold_smc * Deg2Radians;
      alignment_m2d_data.static_alignment_data.target_height_over_ground =
         calib_data_ptr->sensor_calib_data.sensor_mount_data
            .k_sensor_mount_pos_z; /*Assuming Flat plate height same as Radar Height*/
      alignment_m2d_data.static_alignment_data.k_num_valid_scan_needed       = SRA_NUM_VALID_SCANS_TO_PASS;
      alignment_m2d_data.static_alignment_data.k_max_number_of_scans_allowed = 40U;
   }
}

/******************************************************************************
   Function name        : Send_OperationMode_To_BBE32
   Function Description : This function fetch the operation mode of radar
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Send_OperationMode_To_BBE32(void)
{
   Dt_SystemOperationMode operation_mode;

   /*Read the Radar operation mode status*/
   (void)Rte_Read_Rp_OperationMode_Type_De_OperationMode_System(&operation_mode);

#ifndef ALIGN_STUB_SIMULATE_DET
   alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode =
      OPERATIONAL; /*operation_mode. TODO : Operation mode check removed for R6.0 Release*/
#else
   alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode = Align_Oper_Mode_Test;
#endif
}

/******************************************************************************
   Function name        : Alignment_Handler
   Function Description : This function to handle/monitor Alignment cyclicly
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Alignment_Handler(void)
{
   /* Read XCP command*/
   Read_Xcp_Cmd();

   /*Check the Alighnment requests over XCP*/
   Process_Alignment_Cmd();

   switch (Alignment_Type)
   {
      case ALIGN_MODE_OFF:
         alignment_m2d_data.static_alignment_data.align_cmd  = (uint8_t)SRA_ALGO_MODE_OFF;
         alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_OFF; /*AutoAlignment Stop*/
         AlignmentHandler.CalDisplay                         = (uint8_t)FALSE;             /*Indicates Alignment is INACTIVE*/
         break;

      case ALIGN_MODE_AUTO:
         alignment_m2d_data.static_alignment_data.align_cmd = (uint8_t)SRA_ALGO_MODE_OFF;
         /*WI-322574 - The product shall only switch to Auto Alignment if an initial Alignment was successfully performed*/
         Handle_Auto_Alignment_Precondition();
         break;

      case ALIGN_MODE_SHORT_TRACK:
         Handle_ShortTrack_Alignment();
         break;

      case ALIGN_MODE_SERVICE:
         Handle_Service_Alignment();
         break;

      case ALIGN_MODE_STATIC:
         Handle_Static_Alignment();
         break;

      case ALIGN_MODE_MANUAL:
         alignment_m2d_data.static_alignment_data.align_cmd  = (uint8_t)SRA_ALGO_MODE_OFF; /*Stop Static alignment*/
         alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_OFF; /*AutoAlignment Stop*/
         Manual_Alignment_Handler();
         break;

      default:
      {
         Alignment_Type = ALIGN_MODE_OFF;
      }
      break;
   }

   /*Update the Faults to Platform Fault table*/
   Update_Alignment_Faults();
   Update_Alignment_Output(Alignment_Type);
}

/******************************************************************************
   Function name        : Process_Alignment_Cmd
   Function Description :
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Process_Alignment_Cmd(void)
{
   static Dt_Align_Mode_T alignment_modereq_prev = ALIGN_MODE_AUTO;

   if (AlignmentHandler.Alignment_modeIn <= ALIGN_MODE_MANUAL)
   {
      if (alignment_modereq_prev != AlignmentHandler.Alignment_modeIn)
      {
         alignment_modereq_prev = AlignmentHandler.Alignment_modeIn;
         Alignment_Type         = AlignmentHandler.Alignment_modeIn;
         /*AutoAlignment Stop. The Requested Alignment mode will be triggered by Align Handler.*/
         alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_OFF;
         AutoAlignment_Trigger                               = (uint8_t)FALSE;
         AlignmentHandler.AlignmentError                     = AH_ALIGNERR_NO_ERROR;
         AlignmentAuto.AutoAlignmentFailRootCause            = AH_AA_ROOTCAUSE_NONE;
         AlignmentHandler.calTime                            = 0.0F;
         Reset_NVM_On_Alignment_Req();
         AlignmentAuto.AlignAutoStatus         = ALIGNMENT_OFF;
         AlignmentService.AlignmentServiceSt   = ALIGNMENT_OFF;
         AlignmentShortTrack.AlignShortTrackSt = ALIGNMENT_OFF;
         AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_OFF;
         AutoAlignmentRunningStatus            = false;
      }
   }
   AlignmentHandler.AlignmentModeOut   = Alignment_Type;
   Alignment_NVM_Data.AlignmentModeOut = Alignment_Type;

   /* Add check for XCP connected */
   if (CODED_TRUE == Xcp_Connect_Status())
   {
      Update_XCP_Alignment_Data();
   }
}

/******************************************************************************
   Function name        : Read_Xcp_Cmd
   Function Description :
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Read_Xcp_Cmd(void)
{
   uint8_t alignment_mode_in_xcp             = 0; /*No XCP Cmd*/
   static uint8_t alignment_mode_in_xcp_prev = ALIGN_MODE_OFF;
   (void)Rte_Read_Rp_Alignment_Type_Alignment_Type(&alignment_mode_in_xcp);
   if ((alignment_mode_in_xcp <= ALIGN_MODE_MANUAL) && (alignment_mode_in_xcp_prev != alignment_mode_in_xcp))
   {
      AlignmentHandler.Alignment_modeIn = (Dt_Align_Mode_T)alignment_mode_in_xcp;
   }
   alignment_mode_in_xcp_prev = alignment_mode_in_xcp;
}

/******************************************************************************
   Function name        : Reset_NVM_On_Alignment_Req
   Function Description : This function is to Fail the Auto Mode when a key cycle is performed without Succesfull alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Reset_NVM_On_Alignment_Req(void)
{
   /*To Fail the Auto Mode when a key cycle is performed without Succesfull alignment*/
   /*Check provided if Auto Triggered by User*/
   if (ALIGN_MODE_AUTO != Alignment_Type)
   {
      AlignmentHandler.InitialLastSuccessAlignmentMode = ALIGN_MODE_OFF;
      AlignmentHandler.InitialAlignmentResultAz        = 0.0F;
      AlignmentHandler.InitialAlignmentResultEl        = 0.0F;
      AlignmentHandler.InitialAlignmentResultAzUpdates = 0U;
      AlignmentHandler.InitialAlignmentResultElUpdates = 0U;
      AlignmentAuto.AACurrentAzimuth                   = 0.0F;
      AlignmentAuto.AACurrentElevation                 = 0.0F;
#ifdef FLR8
      AlignmentHandler.InitialAlignmentResultRoll        = 0.0F;
      AlignmentHandler.InitialAlignmentResultRollUpdates = 0U;
      AlignmentAuto.AACurrentRoll                        = 0.0F;
#endif
      Update_Alignment_NVM_Data();
   }
}
/******************************************************************************
   Function name        : Update_Initial_Alignment_Value
   Function Description : This function to update the initial values
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Initial_Alignment_Value(void)
{
   alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated =
      Align_Mounting_Parameters.iso_sensor_yaw * -1.0F;
   alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated =
      Align_Mounting_Parameters.iso_sensor_pitch * -1.0F;
   alignment_m2d_data.dynamic_alignment_data.initial_num_updates_az = 0;
   alignment_m2d_data.dynamic_alignment_data.initial_num_updates_el = 0;
}
/******************************************************************************
   Function name        : Auto_Alignment_Error_Check
   Function Description : Checks for auto alignment errors and sets appropriate root cause
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_Error_Status_*, alignment_m2d_data, AlignmentAuto
   SDD Requirements IDs : WI-322574
*******************************************************************************/
static void Auto_Alignment_Error_Check(void)
{
   /* Check sensor orientation errors first */
   Check_Sensor_Orientation_Errors();

   /* If no orientation error found, check system and input errors */
   if (AlignmentAuto.AutoAlignmentFailRootCause == AH_AA_ROOTCAUSE_NONE)
   {
      Check_System_Input_Errors();
   }
}

/******************************************************************************
   Function name        : Check_Sensor_Orientation_Errors
   Function Description : Checks sensor orientation errors (elevation and azimuth bounds)
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, AlignmentAuto
   SDD Requirements IDs : WI-322574
*******************************************************************************/
static void Check_Sensor_Orientation_Errors(void)
{
   if (alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds == (uint8_t)DRA_EL_SENSOR_STATUS_FACING_SKY)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_SENSOR_FACING_UPWARDS;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds == (uint8_t)DRA_EL_SENSOR_STATUS_FACING_DOWN)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_SENSOR_FACING_DOWNWARDS;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds == (uint8_t)DRA_AZ_SENSOR_STATUS_CLOCKWISE)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_SENSOR_FACING_RIGHT;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds ==
            (uint8_t)DRA_AZ_SENSOR_STATUS_COUNTER_CLOCKWISE)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_SENSOR_FACING_LEFT;
   }
   else
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_NONE;
   }
}

/******************************************************************************
   Function name        : Check_System_Input_Errors
   Function Description : Checks system and input errors (vehicle, blockage, initialization, operation mode, data qualifier)
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_Error_Status_*, alignment_m2d_data, AlignmentAuto
   SDD Requirements IDs : WI-322574
*******************************************************************************/
static void Check_System_Input_Errors(void)
{
   if (alignment_ipc_data.dra_core_log_data.error_status_vehicle_input == (uint8_t)TRUE) /* vehicle signale corrupted*/
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INVALID_VEHICLE_SIGNAL;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_excessive_blockage == (uint8_t)TRUE) /* targrt too low*/
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_BLOCKAGE;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_initialization == (uint8_t)TRUE)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INVALID_INPUT;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_detection_input == (uint8_t)TRUE)
   {
      /* DRA_FAULTY - Enum Starts from 0 and Enum in modemanager for OperationalMode Starts with 1, so "-1" is added to match the
       * comparison */
      if ((alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode) == (uint8_t)FAULTY)
      {
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_OPERATION_MODE_FAULTY;
      }
      else if (alignment_ipc_data.data_qualifier == (uint8_t)DATA_QUALIFIER_INVALID)
      {
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_DATA_QUALIFIER_INVALID;
      }
      else
      {
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_QUALITY_TOO_LOW;
      }
   }
   else if (((alignment_ipc_data.dra_core_log_data.error_status_sudden_state_change == (uint8_t)TRUE) ||
             (alignment_ipc_data.dra_core_log_data.error_status_parking_accident == (uint8_t)TRUE)) == TRUE)
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_SUDDEN_JUMP_DETECTION;
   }
   else
   {
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_NONE;
   }
}

/******************************************************************************
   Function name        : Initial_Align_Sys_Err_check;
   Function Description : Checks and updates initial alignment errors
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Initial_Align_Sys_Err_check(void)
{
   if ((alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode) == (uint8_t)FAULTY)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_OPERATION_MODE_FAULTY;
   }
   else if (alignment_ipc_data.data_qualifier == (uint8_t)DATA_QUALIFIER_INVALID)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_DATA_QUALIFIER_INVALID;
   }
   else
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_NO_ERROR;
   }
}

/*******************************************************************************
   Function name        : Check_Alignment_Faults_And_Get_State
   Function Description : Common function to check alignment faults and determine state
   Input Parameters     : current_state - Current alignment state
   Return               : Dt_Align_Status - New alignment state
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static Dt_Align_Status Check_Alignment_Faults_And_Get_State(Dt_Align_Status current_state)
{
   Dt_Align_Status new_state              = current_state;
   uint32_t current_look_index            = 0u;
   static uint8_t detection_input_err_cnt = 0;
   current_look_index                     = alignment_ipc_data.look_index;

   // Check if look_index is not incrementing (alignment is paused/stalled)
   bool look_index_freezed = (Align_Look_Index_Prev == current_look_index);

   bool detection_input_err_detected =
      ((alignment_ipc_data.dra_core_log_data.error_status_detection_input == (uint8_t)TRUE) &&
       (alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode != (uint8_t)FAULTY) &&
       (alignment_ipc_data.data_qualifier != (uint8_t)DATA_QUALIFIER_INVALID) && (!look_index_freezed));

   /*Since peration mode is read within R52, it could be cleared before error_status_detection_input is cleared
   So ensure 1 cycle for BB32 process Operation mode*/
   if (detection_input_err_detected)
   {
      detection_input_err_cnt++;
   }
   else
   {
      detection_input_err_cnt = 0;
   }

   if ((detection_input_err_cnt >= DETECTION_INPUT_ERR_TRANSITION_BUFFER) ||
       (alignment_ipc_data.dra_core_log_data.error_status_detection_input == (uint8_t) false))
   {
      if (alignment_ipc_data.dra_core_log_data.error_status_vehicle_input == (uint8_t)TRUE)
      {
         new_state                       = ALIGNMENT_PAUSED;
         AlignmentHandler.AlignmentError = AH_ALIGNERR_INVALID_VEHICLE_SIGNAL;
      }
      else
      {
         Dyn_Alignment_Error_Check();
         new_state                                = ALIGNMENT_FAILED;
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INITIAL_ALIGNMENT_NOT_DONE;
         Alignment_Type                           = ALIGN_MODE_OFF;
         /* Save NVM Data even the alignment fails */
         Save_Unsuccesfull_Alignment_Data();
      }
   }
   // Pause for operation mode or data qualifier faults (recoverable)
   else if ((alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode == (uint8_t)FAULTY) ||
            (alignment_ipc_data.data_qualifier == (uint8_t)DATA_QUALIFIER_INVALID) || (look_index_freezed))
   {
      Initial_Align_Sys_Err_check();
      new_state = ALIGNMENT_PAUSED;
   }
   else
   {
      /*Do Nothing*/
   }
   return new_state;
}

/******************************************************************************
   Function name        : Chk_AutoAlignment_Angle_Chg
   Function Description : To check AA output angle deviation of >1 deg from actual value
   Input Parameters     : NA
   Return               : uint8_t
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static uint8_t Chk_AutoAlignment_Angle_Chg(void)
{
   float32_t az_angle_chg   = 0.0f;
   float32_t el_angle_chg   = 0.0f;
   uint8_t aa_out_angle_chg = CODED_FALSE;

#ifdef ALIGN_STUB_SIMULATE_DET

   if (Align_Angle_Chg_Test == CODED_TRUE)
   {
      alignment_ipc_data.dra_core_log_data.vacs_boresight_az_kf_internal =
         alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated + AA_ANGLE_CHG_THRESHOLD + 1.0F;
   }
#endif

   /*Check for deviation after 4000 scans*/
   if (alignment_ipc_data.dra_core_log_data.alignment_index > AA_ANGLE_CHG_INDEX)
   {
      az_angle_chg = fabs(alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated -
                          alignment_ipc_data.dra_core_log_data.vacs_boresight_az_kf_internal);
      el_angle_chg = fabs(alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated -
                          alignment_ipc_data.dra_core_log_data.vacs_boresight_el_kf_internal);

      if ((az_angle_chg > AA_ANGLE_CHG_THRESHOLD) || (el_angle_chg > AA_ANGLE_CHG_THRESHOLD))
      {
         aa_out_angle_chg = CODED_TRUE;
      }
   }
   return aa_out_angle_chg;
}
/******************************************************************************
   Function name        : Auto_Alignment_Handler
   Function Description :
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Auto_Alignment_Handler(void)
{
   static bool init_nvm_write_flag = false;

   if (!AutoAlignmentRunningStatus)
   {
      Update_Auto_Alignment_Start_Value();
      /*WI-323037 - The product shall provide information about the initial Auto Alignment angles used to start Auto Alignmnet*/
      AlignmentAuto.StartAzimuth   = alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated;
      AlignmentAuto.StartElevation = alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated;
#ifdef FLR8
      AlignmentAuto.StartRoll = alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated;
#endif
      AutoAlignmentRunningStatus = true;
      init_nvm_write_flag        = true;
   }

   alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_AUTO; /*Trigger AutoAlignment*/
   if ((uint8_t)DRA_ALGO_MODE_AUTO == (uint8_t)alignment_ipc_data.dra_core_log_data.alignment_mode)
   {
      Process_Auto_Alignment_Mode_Data(&init_nvm_write_flag);
   }
}

/******************************************************************************
   Function name        : Update_Auto_Alignment_Start_Value
   Function Description : This function updates Azimuth and Elevation data to m2d buffer if AutoAlignment_Trigger is triggered
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Auto_Alignment_Start_Value(void)
{
   if (AutoAlignment_Trigger)
   {
      /*WI-323038 - The product shall utilize the misalignment angles of a successfully performed initial Alignment
      as starting values the next time AutoAlignment is active.*/
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated =
         (Align_Mounting_Parameters.iso_sensor_yaw * -1) + (AlignmentHandler.InitialAlignmentResultAz * Deg2Radians);
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated =
         (Align_Mounting_Parameters.iso_sensor_pitch * -1) + (AlignmentHandler.InitialAlignmentResultEl * Deg2Radians);
#ifdef FLR8
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated =
         (AlignmentHandler.InitialAlignmentResultRoll * Deg2Radians);
#endif
      AutoAlignment_Trigger = (uint8_t)FALSE;
      /* Carry forward successful dynamic alignment state into Auto start values. */
      alignment_m2d_data.dynamic_alignment_data.initial_speed_compensation_factor = AlignmentHandler.InitialAlignmentResultHostSCF;
      alignment_m2d_data.dynamic_alignment_data.initial_num_updates_az = AlignmentHandler.InitialAlignmentResultAzUpdates;
      alignment_m2d_data.dynamic_alignment_data.initial_num_updates_el = AlignmentHandler.InitialAlignmentResultElUpdates;
   }
   else
   {
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated = AlignmentAuto.AACurrentAzimuth;
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated = AlignmentAuto.AACurrentElevation;
#ifdef FLR8
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated = AlignmentAuto.AACurrentRoll;
#endif
   }
}

/******************************************************************************
   Function name        : Chk_AutoAlignment_Nvm
   Function Description :
   Input Parameters     : *init_nvm_write
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/

static void Chk_AutoAlignment_Nvm(bool *init_nvm_write)
{
   static uint32_t nvm_UpdateAngleCounter = 0U;

   /* Update NVM for the first instance after Auto Alignment Starts and at every alignment_auto_cals.nvm_cycle_time secs */
   nvm_UpdateAngleCounter++;

   if ((*init_nvm_write))
   {
      Update_Alignment_NVM_Data();
      *init_nvm_write        = false;
      nvm_UpdateAngleCounter = 0U;
   }
   /*Update NVM at every alignment_auto_cals.nvm_cycle_time secs*/
   /* sec to ms conversion, 1sec = (50ms*20) */
   else if (nvm_UpdateAngleCounter >= (uint32_t)(alignment_auto_cals.nvm_cycle_time * (uint32_t)SEC_TO_50mSEC))
   {
      Check_And_Update_NVM_Angles();
      nvm_UpdateAngleCounter = 0U;
   }
   else
   {
      /* Do Nothing */
   }
}

/******************************************************************************
   Function name        : Alignment_OOR_Hyst_Check
   Function Description : Do Hysteresis check before setting error to avoid toggling
   Input Parameters     : float32_t misalignment_az,float32_t misalignment_el
   Return               : out_of_range_error
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static uint8_t Alignment_OOR_Hyst_Check(float32_t misalignment_az, float32_t misalignment_el, uint8_t out_of_range_error)
{
   float32_t oor_az_low_tld = alignment_auto_cals.azimuth_threshold - 0.01F;
   float32_t oor_el_low_tld = alignment_auto_cals.elevation_threshold - 0.01F;

   if (out_of_range_error == CODED_TRUE)
   {
      if ((misalignment_az < oor_az_low_tld) && (misalignment_el < oor_el_low_tld))
      {
         out_of_range_error = CODED_FALSE;
      }
   }
   else
   {
      out_of_range_error = CODED_FALSE;
      if ((misalignment_az > alignment_auto_cals.azimuth_threshold) || (misalignment_el > alignment_auto_cals.elevation_threshold))
      {
         out_of_range_error = CODED_TRUE;
      }
   }
   return out_of_range_error;
}

/******************************************************************************
   Function name        : Compute_Autoalign_Faults
   Function Description :
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Compute_Autoalign_Faults(void)
{
   bool critical_misalignment_error_status = false;
   float32_t misalignment_az               = 0.0F;
   float32_t misalignment_el               = 0.0F;

   /*check if the Azimuth and elevation angle are with in the range*/
   /*Note:since Roll is not implemented yet it is not checked, once is implemented it should also be checked*/
   misalignment_az = (float32_t)(fabs(alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated -
                                      alignment_ipc_data.dra_core_log_data.vacs_boresight_az_nominal));
   misalignment_el = (float32_t)(fabs(alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated -
                                      alignment_ipc_data.dra_core_log_data.vacs_boresight_el_nominal));
   /*Check with hysteresis for out-of-range error and set or clear Out of range error*/
   Alignment_Faults.Autoalign_outof_range_error =
      Alignment_OOR_Hyst_Check(misalignment_az, misalignment_el, Alignment_Faults.Autoalign_outof_range_error);
   /* Check whether misalignment values above critical misalignment threshold, update fault based on the value.*/
   critical_misalignment_error_status = ((misalignment_az > (alignment_auto_cals.critical_misalignment_threshold)) ||
                                         (misalignment_el > (alignment_auto_cals.critical_misalignment_threshold)));
   /*Critical Misalignment once Set should not be cleared*/
   if (critical_misalignment_error_status)
   {
      Alignment_Faults.Autoalignment_critical_misalignment_error = CODED_TRUE;
   }
   /*Set or Clear sudden jump detection error*/
   Alignment_Faults.Autoalignment_sudden_jump_detection_error =
      (uint8_t)(((alignment_ipc_data.dra_core_log_data.error_status_sudden_state_change == (uint8_t)TRUE) ||
                 (alignment_ipc_data.dra_core_log_data.error_status_parking_accident == (uint8_t)TRUE))) ?
         CODED_TRUE :
         CODED_FALSE;
}
/******************************************************************************
   Function name        : Dyn_Alignment_Error_Check
   Function Description :
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Dyn_Alignment_Error_Check(void)
{
   /* Check sensor orientation errors first */
   if (!Check_Dyn_Sensor_Orientation_Errors())
   {
      /* If no orientation error, check system errors */
      Check_Dyn_System_Errors();
   }
}

/******************************************************************************
   Function name        : Service_Alignment_Error_Check
   Function Description : Checks and updates service alignment errors
   Input Parameters     : max_distance_crossed, max_duration_crossed
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Service_Alignment_Error_Check(uint8_t max_distance_crossed, uint8_t max_duration_crossed)
{
   if (max_distance_crossed == (uint8_t)TRUE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_MAX_DISTANCE_CROSSED_SERVICE;
   }
   else if (max_duration_crossed == (uint8_t)TRUE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_MAX_DURATION_CROSSED_SERVICE;
   }
   else
   {
      /*Do nothing*/
   }
}

/******************************************************************************
   Function name        : Calculate_Initial_Align_Time
   Function Description : This function calculates the time spent for Iniitial alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Calculate_Initial_Align_Time(void)
{
   static uint32_t initial_align_time_ms = 0U;

   initial_align_time_ms++;
   if (initial_align_time_ms >= (uint32_t)SEC_TO_50mSEC)
   {
      AlignmentHandler.calTime++;
      initial_align_time_ms = 0;
   }
}

/******************************************************************************
   Function name        : Dynamic_ShortTrack_Alignment_Handler
   Function Description : This function Handling the Automatic Initial Alignment - Short Track
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Dynamic_ShortTrack_Alignment_Handler(void)
{
   /*WI-322583 Once the alignment mode switched to an initial method CalDisplay shall be set until the next ignition cycle.*/
   AlignmentHandler.CalDisplay = (uint8_t)TRUE;
   bool st_align_success       = false;

   Calculate_Initial_Align_Time();
   Read_Dyn_Alignment_Data();
   st_align_success = Check_InitialDyn_Alignment_Status();

   /* Process alignment status and update state */
   Process_ShortTrack_Alignment_Status(st_align_success);

   /* Update previous values for pause detection */
   N_Updates_Azimuth_Prev   = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
   N_Updates_Elevation_Prev = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
   N_Updates_roll_Prev      = alignment_ipc_data.dra_core_log_data.n_updates_roll;

   Align_Look_Index_Prev = alignment_ipc_data.look_index; // store previous look_index
}

/******************************************************************************
   Function name        : Check_Vehicle_Speed_And_Yaw
   Function Description : Checks vehicle speed and yaw rate conditions
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, alignment_initial_cals, AlignmentService
   SDD Requirements IDs :
*******************************************************************************/
static void Check_Vehicle_Speed_And_Yaw(void)
{
   if (alignment_ipc_data.veh_info.veh_speed < (float32_t)alignment_initial_cals.velocity_min)
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_VEL_LOW;
   }
   else if (alignment_ipc_data.veh_info.veh_speed > (float32_t)alignment_initial_cals.velocity_max)
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_VEL_HIGH;
   }
   else if (alignment_ipc_data.veh_info.veh_yaw > alignment_initial_cals.yawrate_max)
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_YAW_HIGH;
   }
   else
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_NO_ISSSUE;
   }
}

/******************************************************************************
   Function name        : Check_Vehicle_Quality_And_Reverse
   Function Description : Checks vehicle quality factors and reverse condition
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, AlignmentService
   SDD Requirements IDs :
*******************************************************************************/
static void Check_Vehicle_Quality_And_Reverse(void)
{
   if (alignment_ipc_data.veh_info.veh_speed_qf == VEH_SPEED_QF_VALUE)
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_VEL_QF_INSUFFICIENT;
   }
   else if (alignment_ipc_data.veh_info.veh_yaw_qf == VEH_YAW_QF_VALUE)
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_YAW_QF_INSUFFICIENT;
   }
   else if (alignment_ipc_data.veh_info.lros_drive_reverse ==
            LROS_DRIVE_REVERSE_VALUE) /*0-Noreverse,1-Reverse reverse - to be checked */
   {
      AlignmentService.VehicleCondition = ALIGN_VEH_VEL_REVERSE;
   }
   else
   {
      /*Do nothing - condition already set to ALIGN_VEH_NO_ISSSUE*/
   }
}

/******************************************************************************
   Function name        : Vehicle_Input_Data_Status
   Function Description : This function evaluate vehicle input data for service alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Vehicle_Input_Data_Status(void)
{
   /* Check vehicle speed and yaw values first */
   Check_Vehicle_Speed_And_Yaw();

   /* If no speed/yaw issue, check quality factors and reverse */
   if (AlignmentService.VehicleCondition == ALIGN_VEH_NO_ISSSUE)
   {
      Check_Vehicle_Quality_And_Reverse();
   }
}
/******************************************************************************
   Function name        : Dynamic_Service_Alignment_Handler
   Function Description : This function Handling the dynamic service Alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Dynamic_Service_Alignment_Handler(Dt_Align_Status *target_alignment_status)
{
   Calculate_Initial_Align_Time();
   Read_Dyn_Alignment_Data();

   /*WI-322583 Once the alignment mode switched to an initial method CalDisplay shall be set until the next ignition cycle.*/
   AlignmentHandler.CalDisplay = (uint8_t) true;

   /*Update Service structure. Clarification pending for the correct parameters from D2M structure*/
   AlignmentService.DistanceAbsolute  = (uint32_t)alignment_ipc_data.dra_core_log_data.total_distance_since_start;
   AlignmentService.DistanceEffective = (uint32_t)((alignment_ipc_data.dra_core_log_data.total_distance_running_el >
                                                    alignment_ipc_data.dra_core_log_data.total_distance_running_az_scf) ?
                                                      (alignment_ipc_data.dra_core_log_data.total_distance_running_el) :
                                                      (alignment_ipc_data.dra_core_log_data.total_distance_running_az_scf));

   AlignmentService.DurationAbsolute =
      (uint32_t)(alignment_ipc_data.dra_core_log_data.total_time_since_start * SECONDS_TO_MILLISECONDS);
   AlignmentService.DurationEffective = (uint32_t)(((alignment_ipc_data.dra_core_log_data.total_time_running_el >
                                                     alignment_ipc_data.dra_core_log_data.total_time_running_az_scf) ?
                                                       (alignment_ipc_data.dra_core_log_data.total_time_running_el) :
                                                       (alignment_ipc_data.dra_core_log_data.total_time_running_az_scf)) *
                                                   SECONDS_TO_MILLISECONDS);
   AlignmentService.AverageSpeed      = (float32_t)alignment_ipc_data.dra_core_log_data.avg_spd_since_start;

   AlignmentService.AvgNumOfDet = Calculate_Detection_Count();

   Vehicle_Input_Data_Status();
   Process_Service_Alignment_Data(target_alignment_status);
}
/******************************************************************************
   Function name        : Process_Service_Alignment_Data
   Function Description : This function updates status of Service Alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Process_Service_Alignment_Data(Dt_Align_Status *target_alignment_status)
{
   uint8_t max_distance_crossed  = Check_Max_Distance_Crossed();
   uint8_t max_duration_crossed  = Check_Max_Duration_Crossed();
   uint8_t service_align_success = (uint8_t)Check_InitialDyn_Alignment_Status();
   if (service_align_success == 1U)
   {
      /*Set the Initial Successful data- Service*/
      Update_Successful_Dyn_Alignment_Data();

      *target_alignment_status        = ALIGNMENT_SUCCESSFUL;
      Alignment_Type                  = ALIGN_MODE_AUTO;
      AlignmentHandler.AlignmentError = AH_ALIGNERR_NO_ERROR;
      AutoAlignment_Trigger           = (uint8_t)TRUE; /*To indicata Auto Alignment 1st trigger after Succesfull Alignment*/
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)TRUE)
   {
      *target_alignment_status = Check_Alignment_Faults_And_Get_State(*target_alignment_status);
   }
   else if ((max_distance_crossed == 1U) || (max_duration_crossed == 1U))
   {
      Service_Alignment_Error_Check(max_distance_crossed, max_duration_crossed);
      *target_alignment_status                 = ALIGNMENT_FAILED;
      Alignment_Type                           = ALIGN_MODE_OFF;
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INITIAL_ALIGNMENT_NOT_DONE;
      /* Save NVM Data even the alignment fails */
      Save_Unsuccesfull_Alignment_Data();
   }
   /*Pause State can be determined if azimuth, elevations and roll counts are not updated*/
   else
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_NO_ERROR;
      *target_alignment_status        = Is_Service_Alignment_Paused() ? (uint8_t)ALIGNMENT_PAUSED : (uint8_t)ALIGNMENT_RUNNING;
   }
   N_Updates_Azimuth_Prev   = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
   N_Updates_Elevation_Prev = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
   N_Updates_roll_Prev      = alignment_ipc_data.dra_core_log_data.n_updates_roll;

   Align_Look_Index_Prev = alignment_ipc_data.look_index; // store previous look_index
}

/******************************************************************************
   Function name        : Process_Auto_Alignment_Mode_Data
   Function Description : Processes auto alignment mode data and updates alignment status
   Input Parameters     : init_nvm_write_flag - pointer to NVM write flag
   Return               : void
   Global Data used     : alignment_ipc_data, AlignmentAuto, AlignmentHandler, Alignment_Error_Status_*, N_Updates_*_Prev
   SDD Requirements IDs :
*******************************************************************************/
static void Process_Auto_Alignment_Mode_Data(bool *init_nvm_write_flag)
{
   Read_Dyn_Alignment_Data();

   Compute_Autoalign_Faults();

   Chk_AutoAlignment_Nvm(init_nvm_write_flag);

   if (alignment_ipc_data.dra_core_log_data.error_status_initialization == (uint8_t)TRUE)
   {
      AlignmentAuto.AlignAutoStatus            = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError          = AH_ALIGNERR_INVALID_INPUT;
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INVALID_INPUT;
      Alignment_Type                           = ALIGN_MODE_OFF;
   }
   /*Pause State can be determined if azimuth and elevations counts are not updated*/
   else if ((N_Updates_Azimuth_Prev == alignment_ipc_data.dra_core_log_data.n_updates_azimuth) &&
            (N_Updates_Elevation_Prev == alignment_ipc_data.dra_core_log_data.n_updates_elevation) &&
            (N_Updates_roll_Prev == alignment_ipc_data.dra_core_log_data.n_updates_roll))
   {
      AlignmentAuto.AlignAutoStatus = ALIGNMENT_PAUSED;
      Auto_Alignment_Error_Check();
   }
   else
   {
      AlignmentAuto.AlignAutoStatus            = ALIGNMENT_RUNNING;
      AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_NONE;
      if (Alignment_Faults.Autoalignment_critical_misalignment_error == CODED_TRUE)
      {
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_CRITICAL_MISALIGNMENT;
      }
      else if (alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)TRUE)
      {
         Auto_Alignment_Error_Check();
      }
#ifndef AL_ALIGNMENT_BUILD
      /* Pause State when azimuth or elevations quality factor not ok */
      else if (((uint8_t)alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf < (uint8_t)DRA_QF_OK) ||
               ((uint8_t)alignment_ipc_data.dra_core_log_data.elevation_estimation_qf < (uint8_t)DRA_QF_OK))
#else
      /* Pause State when azimuth quality factor not ok  for AL build*/
      else if (((uint8_t)alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf < (uint8_t)DRA_QF_OK))
#endif
      {
         AlignmentAuto.AlignAutoStatus            = ALIGNMENT_PAUSED;
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_ALIGNMENT_QF_NOT_OK;
      }
      else if (Chk_AutoAlignment_Angle_Chg() == CODED_TRUE)
      {
         AlignmentAuto.AlignAutoStatus            = ALIGNMENT_FAILED;
         AlignmentAuto.AutoAlignmentFailRootCause = AH_AA_ROOTCAUSE_INACCURATE_MISALIGNMENT_VALUE;
      }
      else
      {
         /* No failure - initialized/running state is used */
      }
   }
   N_Updates_Azimuth_Prev   = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
   N_Updates_Elevation_Prev = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
   N_Updates_roll_Prev      = alignment_ipc_data.dra_core_log_data.n_updates_roll;
}

/******************************************************************************
   Function name        : Check_And_Update_NVM_Angles
   Function Description : Checks if alignment angles have changed beyond threshold and updates NVM
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_NVM_Data, AlignmentAuto, Alignment_Faults
   SDD Requirements IDs :
*******************************************************************************/
static void Check_And_Update_NVM_Angles(void)
{
   float32_t misaligned_azimuth_angle   = 0.00F;
   float32_t misaligned_elevation_angle = 0.00F;
   float32_t misaligned_roll            = 0.00F;
   float32_t mismatch_scf               = 0.00F;
   uint32_t mismatch_n_updates          = 0U;

   /* Calculate the misalignment for azimuth and elevation angles */
   misaligned_azimuth_angle   = Rad2Degree * (fabs(Alignment_NVM_Data.AACurrentAzimuth - AlignmentAuto.AACurrentAzimuth));
   misaligned_elevation_angle = Rad2Degree * (fabs(Alignment_NVM_Data.AACurrentElevation - AlignmentAuto.AACurrentElevation));
#ifdef FLR8
   misaligned_roll = Rad2Degree * (fabs(Alignment_NVM_Data.AACurrentRoll - AlignmentAuto.AACurrentRoll));
#endif
   mismatch_scf       = (fabs(Alignment_NVM_Data.HostSpeedCompensationFactor - AlignmentAuto.HostScf)); /*scf mismatch calc*/
   mismatch_n_updates = (fabs(Alignment_NVM_Data.AzimuthUpdates - AlignmentAuto.AzimuthNumUpdates));    /*n updates mismatch calc*/

   if ((misaligned_azimuth_angle > NVM_UPDATE_DEGREE_THRESHOLD) || (misaligned_elevation_angle > NVM_UPDATE_DEGREE_THRESHOLD) ||
       (misaligned_roll > NVM_UPDATE_DEGREE_THRESHOLD) || (mismatch_scf > 0.001F) || (mismatch_n_updates > 5000U))
   {
      Update_Alignment_NVM_Data();
   }
}

/******************************************************************************
   Function name        : Check_Dyn_Sensor_Orientation_Errors
   Function Description : Checks dynamic alignment sensor orientation errors (elevation and azimuth)
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, AlignmentHandler
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_Dyn_Sensor_Orientation_Errors(void)
{
   bool has_error = false;

   if (alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds == (uint8_t)DRA_EL_SENSOR_STATUS_FACING_SKY)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_UPWARDS;
      has_error                       = true;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds == (uint8_t)DRA_EL_SENSOR_STATUS_FACING_DOWN)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_DOWNWARDS;
      has_error                       = true;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds == (uint8_t)DRA_AZ_SENSOR_STATUS_CLOCKWISE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_RIGHT;
      has_error                       = true;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds ==
            (uint8_t)DRA_AZ_SENSOR_STATUS_COUNTER_CLOCKWISE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_LEFT;
      has_error                       = true;
   }
   else
   {
      /* No sensor orientation error */
   }

   return has_error;
}

/******************************************************************************
   Function name        : Check_Dyn_System_Errors
   Function Description : Checks dynamic alignment system errors (blockage, detection, initialization, vehicle)
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_Error_Status_*, Alignment_Type, AlignmentHandler
   SDD Requirements IDs :
*******************************************************************************/
static void Check_Dyn_System_Errors(void)
{
   if (alignment_ipc_data.dra_core_log_data.error_status_excessive_blockage == (uint8_t)TRUE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_BLOCKAGE;
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_detection_input == (uint8_t)TRUE)
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_QUALITY_OF_TARGET_TOO_LOW_SERVICE;
   }
   else if ((alignment_ipc_data.dra_core_log_data.error_status_initialization == (uint8_t)TRUE) ||
            (alignment_ipc_data.dra_core_log_data.error_status_scf_out_of_bounds == (uint8_t)TRUE))
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_INVALID_INPUT;
   }
   else
   {
      /*Do nothing*/
   }
}

/******************************************************************************
   Function name        : Process_ShortTrack_Alignment_Status
   Function Description : Processes short track alignment status and updates state based on success/error/running conditions
   Input Parameters     : st_align_success - boolean indicating if alignment was successful
   Return               : void
   Global Data used     : N_Updates_*_Prev, alignment_ipc_data, AlignmentShortTrack,
AlignmentHandler SDD Requirements IDs :
*******************************************************************************/
static void Process_ShortTrack_Alignment_Status(bool st_align_success)
{
   bool st_alignment_paused = false;

   if (st_align_success)
   {
      /*Update Initial Successfull data - ShortTrack*/
      Update_Successful_Dyn_Alignment_Data();

      AlignmentShortTrack.AlignShortTrackSt = ALIGNMENT_SUCCESSFUL;
      Alignment_Type                        = ALIGN_MODE_AUTO;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_NO_ERROR;
      AutoAlignment_Trigger                 = (uint8_t)TRUE; /*To indicata Auto Alignment is trigger after Succesfull Alignment*/
   }
   else if (alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)TRUE)
   {
      AlignmentShortTrack.AlignShortTrackSt = Check_Alignment_Faults_And_Get_State(AlignmentShortTrack.AlignShortTrackSt);
   }
   /*Algo Updates n_updates_xx whenever Alignment is running. Pause state can be detected by checking no change in
    * "n_updates_xxx"*/
   else
   {
      AlignmentHandler.AlignmentError = AH_ALIGNERR_NO_ERROR;
      st_alignment_paused             = ((N_Updates_Azimuth_Prev == alignment_ipc_data.dra_core_log_data.n_updates_azimuth) &&
                             ((N_Updates_Elevation_Prev == alignment_ipc_data.dra_core_log_data.n_updates_elevation) &&
                              (N_Updates_roll_Prev == alignment_ipc_data.dra_core_log_data.n_updates_roll)));

      AlignmentShortTrack.AlignShortTrackSt = (st_alignment_paused) ? (uint8_t)ALIGNMENT_PAUSED : (uint8_t)ALIGNMENT_RUNNING;
   }
}

/******************************************************************************
   Function name        : Check_Max_Distance_Crossed
   Function Description : Checks if absolute or effective distance threshold has been crossed
   Input Parameters     : void
   Return               : uint8_t - TRUE if threshold crossed, FALSE otherwise
   Global Data used     : AlignmentService, alignment_initial_cals
   SDD Requirements IDs :
*******************************************************************************/
static uint8_t Check_Max_Distance_Crossed(void)
{
   return ((AlignmentService.DistanceAbsolute > (float32_t)(alignment_initial_cals.absolute_distance_threshold)) ||
           (AlignmentService.DistanceEffective > (float32_t)(alignment_initial_cals.effective_distance_threshold)));
}

/******************************************************************************
   Function name        : Check_Max_Duration_Crossed
   Function Description : Checks if absolute or effective duration threshold has been crossed
   Input Parameters     : void
   Return               : uint8_t - TRUE if threshold crossed, FALSE otherwise
   Global Data used     : AlignmentService, alignment_initial_cals
   SDD Requirements IDs :
*******************************************************************************/
static uint8_t Check_Max_Duration_Crossed(void)
{
   return ((AlignmentService.DurationAbsolute >
            (float32_t)(alignment_initial_cals.absolute_duration_threshold * SECONDS_TO_MILLISECONDS)) ||
           (AlignmentService.DurationEffective >
            (float32_t)(alignment_initial_cals.effective_duration_threshold * SECONDS_TO_MILLISECONDS)));
}

/******************************************************************************
   Function name        : Is_Service_Alignment_Paused
   Function Description : Checks if service alignment is paused by comparing update counts
   Input Parameters     : void
   Return               : bool - TRUE if paused (no updates), FALSE if running
   Global Data used     : N_Updates_*_Prev, alignment_ipc_data
   SDD Requirements IDs :
*******************************************************************************/
static bool Is_Service_Alignment_Paused(void)
{
   return ((N_Updates_Azimuth_Prev == alignment_ipc_data.dra_core_log_data.n_updates_azimuth) &&
           (N_Updates_Elevation_Prev == alignment_ipc_data.dra_core_log_data.n_updates_elevation) &&
           (N_Updates_roll_Prev == alignment_ipc_data.dra_core_log_data.n_updates_roll));
}

/******************************************************************************
   Function name        : Check_InitialDyn_Alignment_Status
   Function Description : This function checks the success criteria for Initial dynamic alignment
   Input Parameters     : void
   Return               : uint8_t
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_InitialDyn_Alignment_Status(void)
{
   bool ret = false;

/* For AL build only Az progress percentage  and az quality factor considered */
#ifndef AL_ALIGNMENT_BUILD
   if ((alignment_initial_cals.short_track_submode == 1U) && (Alignment_Type == ALIGN_MODE_SHORT_TRACK))
   {
      /* Short Track Guardrail mode (Fast Service): This mode only requires azimuth alignment completion since guardrails provide
       * primarily azimuth references*/
      ret =
         ((alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)FALSE) &&
          (alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf == (uint8_t)DRA_QF_OK) &&
          (alignment_ipc_data.dra_core_log_data.scf_estimation_qf == (uint8_t)DRA_QF_OK) && (Complete_Percent_Az == PERCENTAGE));
   }
   else
   {
      /* Other alignment modes: This covers Short Track Standard mode, normal Service mode, and other alignment methods that use
      targets providing both azimuth and elevation information*/
      ret = ((alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)FALSE) &&
             (alignment_ipc_data.dra_core_log_data.elevation_estimation_qf == (uint8_t)DRA_QF_OK) &&
             (alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf == (uint8_t)DRA_QF_OK) &&
             (alignment_ipc_data.dra_core_log_data.scf_estimation_qf == (uint8_t)DRA_QF_OK) &&
             (Complete_Percent_Az == PERCENTAGE) && (Complete_Percent_El == PERCENTAGE));
   }
#else
   ret = ((alignment_ipc_data.dra_core_log_data.error_status_combined == (uint8_t)FALSE) &&
          (alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf == (uint8_t)DRA_QF_OK) &&
          (alignment_ipc_data.dra_core_log_data.scf_estimation_qf == (uint8_t)DRA_QF_OK) && (Complete_Percent_Az == PERCENTAGE));
#endif
   return ret;
}
/******************************************************************************
   Function name        : Calculate_Detection_Count
   Function Description : This function counts number of detections used for Caliberating Alignment
   Input Parameters     : void
   Return               : uint32_t
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static uint32_t Calculate_Detection_Count(void)
{
   uint32_t detection_used_az[DRA_BITFIELD_LEN];
   uint32_t detection_used_el[DRA_BITFIELD_LEN];
   uint32_t count_az_det = 0;
   uint32_t count_el_det = 0;

   /*Detections are stored in detection_used_az and detection_used_el in binary bitwise encoded
   To get no_of_detections no of 1's in detection_used_az and detection_used_el to be counted*/
   (void)memcpy(detection_used_az, alignment_ipc_data.dra_core_log_data.detection_used_az,
                sizeof(alignment_ipc_data.dra_core_log_data.detection_used_az));
   (void)memcpy(detection_used_el, alignment_ipc_data.dra_core_log_data.detection_used_el,
                sizeof(alignment_ipc_data.dra_core_log_data.detection_used_el));

   for (uint8_t i = 0U; i < DRA_BITFIELD_LEN; i++)
   {
      for (uint8_t no_of_bits = 0; no_of_bits < (uint8_t)32U; no_of_bits++)
      {
         count_az_det += (uint32_t)(detection_used_az[i] & (uint32_t)0x01);
         count_el_det += (uint32_t)(detection_used_el[i] & (uint32_t)0x01);
         detection_used_az[i] >>= 1;
         detection_used_el[i] >>= 1;
      }
   }

   return (uint32_t)((count_az_det > count_el_det) ? (count_az_det) : (count_el_det));
}
/******************************************************************************
   Function name        : Static_Alignment_Handler
   Function Description : This function reads the status for EOL Calibration from DSS and takes action base on that
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Static_Alignment_Handler(void)
{
   SRA_Core_Log_Data_T *p_sra_core_data = &p_align_d2m->payload.alignment_stream_data.sra_core_data;
   Calculate_Initial_Align_Time();
   AlignmentHandler.CalDisplay                    = (uint8_t)TRUE; /*Indicates Alignment is ACTIVE*/
   AlignmentHandler.InitialAlignmentResultHostSCF = 1.0F;          /* Initial Alignment Result Host Speed Compensation Factor */

   AlignmentStatic.MeasuredAzimuth =
      (p_sra_core_data->vacs_boresight_az_estimated - p_sra_core_data->vacs_boresight_az_nominal) * Rad2Degree;
   AlignmentStatic.MeasuredElevation =
      (p_sra_core_data->vacs_boresight_el_estimated - p_sra_core_data->vacs_boresight_el_nominal) * Rad2Degree;
   AlignmentStatic.Measured_Az_Std      = p_sra_core_data->estimated_standard_deviation_az * Rad2Degree;
   AlignmentStatic.Measured_El_Std      = p_sra_core_data->estimated_standard_deviation_el * Rad2Degree;
   AlignmentStatic.MeasuredRange        = alignment_ipc_data.sra_core_log_data.target_mean_range * METER_TO_MILLIMETER;
   AlignmentStatic.MeasuredRangeRate    = alignment_ipc_data.sra_core_log_data.target_mean_r_dot * METER_TO_MILLIMETER;
   AlignmentStatic.MeasuredAmplitude    = alignment_ipc_data.sra_core_log_data.target_mean_raw_amp;
   AlignmentStatic.MeasuredRangeStd     = alignment_ipc_data.sra_core_log_data.target_std_dev_range * METER_TO_MILLIMETER;
   AlignmentStatic.MeasuredRangeRateStd = alignment_ipc_data.sra_core_log_data.target_std_dev_r_dot * METER_TO_MILLIMETER;
   AlignmentStatic.MeasuredAmpStd       = alignment_ipc_data.sra_core_log_data.target_std_dev_raw_amp;
   AlignmentStatic.ImpactByInterference = alignment_ipc_data.sra_core_log_data.f_interference_detected;

   AlignmentHandler.ProgressPercent = (uint8_t)alignment_ipc_data.sra_core_log_data.complete_percentage;
   AlignmentHandler.AlignmentModeOut =
      ALIGN_MODE_STATIC; /*sfa_d2m_alignment_stream_data->static_align_stream_output.alignment_mode;*/

   AlignmentHandler.AlignmentAzimuth   = AlignmentStatic.MeasuredAzimuth;
   AlignmentHandler.AlignmentElevation = AlignmentStatic.MeasuredElevation;
   AlignmentHandler.AzimuthStd         = AlignmentStatic.Measured_Az_Std;
   AlignmentHandler.ElevationStd       = AlignmentStatic.Measured_El_Std;

   Process_Static_Alignment_Data();
}

/******************************************************************************
   Function name        : Process_Static_Alignment_Data
   Function Description : This function updates status of static Alignment
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Process_Static_Alignment_Data(void)
{
   if (alignment_ipc_data.sra_core_log_data.ErrorStatusIntialisation)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_INVALID_INPUT;
   }
   else if (alignment_ipc_data.sra_core_log_data.ErrorStatusInterference)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_INTERFERENCE_STATIC;
   }
   else if (alignment_ipc_data.sra_core_log_data.ErrorStatusDetection)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_SIGNAL_TOO_STRONG; /*detection_input error*/
   }
   else if (alignment_ipc_data.sra_core_log_data.ErrorStatusVehical)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_PAUSED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_INVALID_VEHICLE_SIGNAL;
   }
   else if (alignment_ipc_data.sra_core_log_data.ErrorAzimuthEstimate != 0U)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      if (alignment_ipc_data.sra_core_log_data.ErrorAzimuthEstimate == 1U)
      {
         AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_RIGHT;
      }
      else if (alignment_ipc_data.sra_core_log_data.ErrorAzimuthEstimate == 2U)
      {
         AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_LEFT;
      }
   }
   else if (alignment_ipc_data.sra_core_log_data.ErrorElevationEstimate != 0U)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      if (alignment_ipc_data.sra_core_log_data.ErrorElevationEstimate == 1U)
      {
         AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_UPWARDS;
      }
      else if (alignment_ipc_data.sra_core_log_data.ErrorElevationEstimate == 2U)
      {
         AlignmentHandler.AlignmentError = AH_ALIGNERR_SENSOR_FACING_DOWNWARDS;
      }
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_FAIL_TARGET_SIGNAL_TOO_WEAK)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_SIGNAL_TOO_WEAK;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_FAIL_TARGET_NOT_STATIC)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_NOT_STATIC;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_FAIL_TARGET_TOO_FAR)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_DISTANCE_TOO_HIGH_STATIC;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_FAIL_TARGET_TOO_CLOSE)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_DISTANCE_TOO_LOW_STATIC;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_FAIL_TARGET_NOT_FOUND)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_FAILED;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_TARGET_NOT_FOUND_STATIC;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_PASS_TARGET_FOUND)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_SUCCESSFUL;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_PASS_MULTIPATH_TARGET)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_SUCCESSFUL;
   }
   else if (alignment_ipc_data.sra_core_log_data.AlgoStatus == SRA_PASS_INTERFERENCE)
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_SUCCESSFUL;
   }

   if (AlignmentStatic.AlignmentStaticStatus == ALIGNMENT_SUCCESSFUL)
   {
      /*Set the Initial Successful data- Static*/
      AlignmentHandler.InitialAlignmentResultAz        = AlignmentHandler.AlignmentAzimuth;
      AlignmentHandler.InitialAlignmentResultEl        = AlignmentHandler.AlignmentElevation;
      AlignmentHandler.InitialLastSuccessAlignmentMode = Alignment_Type;

      Update_Alignment_NVM_Data();
      Alignment_Type                  = ALIGN_MODE_AUTO;
      AlignmentHandler.AlignmentError = AH_ALIGNERR_NO_ERROR;
      AutoAlignment_Trigger           = (uint8_t)TRUE; /*To indicata Auto Alignment is triggered after Succesfull Alignment*/
   }
   else if (AlignmentStatic.AlignmentStaticStatus == ALIGNMENT_FAILED)
   {
      Alignment_Type = ALIGN_MODE_OFF;
      /* Update NVM Data even the alignment fails */
      AlignmentHandler.InitialAlignmentResultAz = AlignmentStatic.MeasuredAzimuth;
      AlignmentHandler.InitialAlignmentResultEl = AlignmentStatic.MeasuredElevation;
      Update_Alignment_NVM_Data();
   }
   else if (n_updates_az_el == alignment_ipc_data.sra_core_log_data.n_updates_az_el)
   {
      /*If there is no update in azimuth and elevation data from algo, it means alignment is paused.*/
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_PAUSED;
   }
   else
   {
      AlignmentStatic.AlignmentStaticStatus = ALIGNMENT_RUNNING;
      AlignmentHandler.AlignmentError       = AH_ALIGNERR_NO_ERROR;
   }

   n_updates_az_el = alignment_ipc_data.sra_core_log_data.n_updates_az_el;
}

/******************************************************************************
   Function name        : Manual_Alignment_Handler
   Function Description : This function updates Alignment NVM parameters as User Request
   Input Parameters     :
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Manual_Alignment_Handler(void)
{
   Process_Manual_Xcp_Cmd();
}
/******************************************************************************
   Function name        : Process_Manual_Xcp_Cmd
   Function Description : This function Process XCP Manual Alignment
   Input Parameters     :
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Process_Manual_Xcp_Cmd(void)
{
   int32_t nvm_new_data                             = (int32_t)0;
   uint8_t flag_Status                              = 0U;
   Dt_Write_Alignment_NvM_Data_T Xcp_Alignment_Data = {0};

   (void)Rte_Read_Rp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(&flag_Status);

   if (flag_Status == CODED_TRUE)
   {
      (void)Rte_Read_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM(&Xcp_Alignment_Data);
      Xcp_Alignment_Data.AlignmentModeOut = Alignment_NVM_Data.AlignmentModeOut;
      nvm_new_data =
         (int32_t)memcmp((void *)&Xcp_Alignment_Data, (void *)&Alignment_NVM_Data, sizeof(Dt_Write_Alignment_NvM_Data_T));

      if (nvm_new_data != FALSE)
      {
         /* Use XCP-provided values directly for all alignment fields.
          * Previously, dynamic sensor readings (e.g. iso_sensor_yaw * -1.0F) were used here,
          * which overwrote the user-specified XCP values with live sensor data before NVM write.
          * This caused F1 31 read-back to return sensor readings instead of the values written
          * via F1 30, making XCP manual alignment ineffective. */
         if ((Xcp_Alignment_Data.InitialLastSuccessfulAlignmentMode >= (float32_t)ALIGN_MODE_OFF) &&
             (Xcp_Alignment_Data.InitialLastSuccessfulAlignmentMode <= (float32_t)ALIGN_MODE_MANUAL))
         {
            AlignmentHandler.InitialLastSuccessAlignmentMode =
               (Dt_Align_Mode_T)Xcp_Alignment_Data.InitialLastSuccessfulAlignmentMode;
         }

         AlignmentHandler.InitialAlignmentResultAz = Xcp_Alignment_Data.InitialAlignmentResultAzimuth;
         AlignmentHandler.InitialAlignmentResultEl = Xcp_Alignment_Data.InitialAlignmentResultElevation;
#ifdef FLR8
         if (Xcp_Alignment_Data.InitialAlignmentResultRoll < (2)) /* Roll initial value to be less than 2 deg */
         {
            AlignmentHandler.InitialAlignmentResultRoll = Xcp_Alignment_Data.InitialAlignmentResultRoll;
         }
#endif
         AlignmentAuto.AACurrentAzimuth =
            (Align_Mounting_Parameters.iso_sensor_yaw * -1.0F) +
            (AlignmentHandler.InitialAlignmentResultAz * Deg2Radians); /* offset of +/- 6 to SMC value */
         AlignmentAuto.AACurrentElevation =
            (Align_Mounting_Parameters.iso_sensor_pitch * -1.0F) +
            (AlignmentHandler.InitialAlignmentResultEl * Deg2Radians); /* offset of +/- 6 to SMC value */
#ifdef FLR8
         AlignmentAuto.AACurrentRoll = (AlignmentHandler.InitialAlignmentResultRoll * Deg2Radians);
#endif
         AlignmentAuto.AzimuthNumUpdates   = (uint32_t)Xcp_Alignment_Data.AzimuthUpdates;
         AlignmentAuto.ElevationNumUpdates = (uint32_t)Xcp_Alignment_Data.ElevationUpdates;
#ifdef FLR8
         AlignmentAuto.RollUpdates = (uint32_t)Xcp_Alignment_Data.RollUpdates;
#endif
         AlignmentHandler.InitialAlignmentResultAzUpdates = (uint32_t)Xcp_Alignment_Data.InitialAlignmentResultAzimuthUpdates;
         AlignmentHandler.InitialAlignmentResultElUpdates = (uint32_t)Xcp_Alignment_Data.InitialAlignmentResultElevationUpdates;
#ifdef FLR8
         AlignmentHandler.InitialAlignmentResultRollUpdates = (uint32_t)Xcp_Alignment_Data.InitialAlignmentResultRollUpdates;
#endif
         AlignmentHandler.InitialAlignmentResultHostSCF =
            ((Xcp_Alignment_Data.InitialAlignmentResultHostSpeedCompensationFactor < HOST_SPEED_COMP_FACTOR_MIN) ||
             (Xcp_Alignment_Data.InitialAlignmentResultHostSpeedCompensationFactor > HOST_SPEED_COMP_FACTOR_MAX)) ?
               1.0F :
               Xcp_Alignment_Data.InitialAlignmentResultHostSpeedCompensationFactor;
         AlignmentAuto.HostScf = ((Xcp_Alignment_Data.HostSpeedCompensationFactor < HOST_SPEED_COMP_FACTOR_MIN) ||
                                  (Xcp_Alignment_Data.HostSpeedCompensationFactor > HOST_SPEED_COMP_FACTOR_MAX)) ?
                                    1.0F :
                                    Xcp_Alignment_Data.HostSpeedCompensationFactor;

         AutoAlignment_Trigger = true;

         Update_Alignment_NVM_Data();
      }
   }
}

/******************************************************************************
   Function name        : Set_Calibration_Fault_Status
   Function Description : Sets calibration fault status for all alignment types
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_Faults, AlignmentShortTrack, AlignmentService, AlignmentStatic, AlignmentAuto
   SDD Requirements IDs :
*******************************************************************************/
static void Set_Calibration_Fault_Status(void)
{
   Alignment_Faults.ShortTrack_Calibration_error =
      (ALIGNMENT_FAILED == AlignmentShortTrack.AlignShortTrackSt) ? CODED_TRUE : CODED_FALSE;

   Alignment_Faults.Service_Calibration_error =
      (ALIGNMENT_FAILED == AlignmentService.AlignmentServiceSt) ? CODED_TRUE : CODED_FALSE;

   Alignment_Faults.Static_Calibration_error =
      (ALIGNMENT_FAILED == AlignmentStatic.AlignmentStaticStatus) ? CODED_TRUE : CODED_FALSE;

   Alignment_Faults.Autoalignment_algo_error = (ALIGNMENT_FAILED == AlignmentAuto.AlignAutoStatus) ? CODED_TRUE : CODED_FALSE;
}

/******************************************************************************
   Function name        : Check_No_Initial_Calibration_Error
   Function Description : Checks if no initial calibration error exists (auto off/failed and all others not successful)
   Input Parameters     : void
   Return               : bool - TRUE if no initial calibration error detected, FALSE otherwise
   Global Data used     : AlignmentAuto, AlignmentShortTrack, AlignmentService, AlignmentStatic
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_No_Initial_Calibration_Error(void)
{
   return (((ALIGNMENT_OFF == AlignmentAuto.AlignAutoStatus) || (ALIGNMENT_FAILED == AlignmentAuto.AlignAutoStatus)) &&
           (ALIGNMENT_SUCCESSFUL != AlignmentShortTrack.AlignShortTrackSt) &&
           (ALIGNMENT_SUCCESSFUL != AlignmentService.AlignmentServiceSt) &&
           (ALIGNMENT_SUCCESSFUL != AlignmentStatic.AlignmentStaticStatus));
}

/******************************************************************************
   Function name        : Update_Alignment_Faults
   Function Description : This function updates Alignment related faults
   Input Parameters     :
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Alignment_Faults(void)
{
   /* Set all calibration fault statuses */
   Set_Calibration_Fault_Status();

   /* Check and set no initial calibration error */
   Alignment_Faults.No_Initial_Calibration_error = Check_No_Initial_Calibration_Error() ? CODED_TRUE : CODED_FALSE;

#if ((ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON))
   Test_Alignment_Faults(&Alignment_Faults);
#endif
   (void)Rte_Write_Pp_Alignment_Faults_De_Alignment_Faults(&Alignment_Faults);
}

/******************************************************************************
   Function name        : Read_Alignment_Data
   Function Description : This function reads out the Alignment Data from the Current driving cycle
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Read_Dyn_Alignment_Data(void)
{
   /* AlignmentHandler.Radar_Type_Input*/
   AlignmentHandler.CoordinateSystem_Input =
      (DRA_Detection_Coordinate_System_T)alignment_ipc_data.dra_core_log_data.detection_coordinate_system;

   Complete_Percent_Az = (uint8_t)alignment_ipc_data.dra_core_log_data.alignment_complete_percent_az;
   Complete_Percent_El = (uint8_t)alignment_ipc_data.dra_core_log_data.alignment_complete_percent_el;

   if (AlignmentHandler.AlignmentModeOut != (Dt_Align_Mode_T)ALIGN_MODE_AUTO)
   {
      AlignmentHandler.AlignmentAzimuth   = ((alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated -
                                            alignment_ipc_data.dra_core_log_data.vacs_boresight_az_nominal) *
                                           Rad2Degree);
      AlignmentHandler.AlignmentElevation = ((alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated -
                                              alignment_ipc_data.dra_core_log_data.vacs_boresight_el_nominal) *
                                             Rad2Degree);
#ifdef FLR8
      AlignmentHandler.AlignmentRoll = (alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_estimated * Rad2Degree);
#endif
      AlignmentHandler.AzimuthStd   = (alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_az * Rad2Degree);
      AlignmentHandler.ElevationStd = (alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_el * Rad2Degree);
/* For AL build only Az progress percentage considered */
#ifndef AL_ALIGNMENT_BUILD
      AlignmentHandler.ProgressPercent = (uint8_t)((Complete_Percent_Az + Complete_Percent_El) / 2U);
#else
      AlignmentHandler.ProgressPercent = (uint8_t)((Complete_Percent_Az));
#endif
      AlignmentHandler.AzimuthQuality   = alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf;
      AlignmentHandler.ElevationQuality = alignment_ipc_data.dra_core_log_data.elevation_estimation_qf;
      AlignmentHandler.AlignmentRoll    = (alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_estimated);
      if ((alignment_initial_cals.short_track_submode == 1U) && (Alignment_Type == ALIGN_MODE_SHORT_TRACK))
      {
         /*Short Track Guardrail mode (Fast Service): Only use Azimuth completion percentage
         This is because Fast Service algorithm primarily focuses on azimuth alignment using guardrails
         and doesn't require elevation completion like other alignment methods*/
         AlignmentHandler.ProgressPercent = (uint8_t)Complete_Percent_Az;
      }
      else
      {
         /*Other alignment modes: Use average of both azimuth and elevation completion percentages
         This covers Short Track Standard mode, normal Service mode, and Static mode which require
         both azimuth and elevation alignment to be completed*/
         AlignmentHandler.ProgressPercent = (uint8_t)((Complete_Percent_Az + Complete_Percent_El) / 2U);
      }
   }
   else
   {
      /*Update Auto Alignment Specific Structre*/
      AlignmentAuto.AACurrentAzimuth   = alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated;
      AlignmentAuto.AACurrentElevation = alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated;
#ifdef FLR8
      AlignmentAuto.AACurrentRoll = alignment_ipc_data.dra_core_log_data.vacs_boresight_roll_estimated;
#endif
      AlignmentAuto.AAAzimuthStd   = alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_az;
      AlignmentAuto.AAElevationStd = alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_el;
      AlignmentAuto.AARollStd      = alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_rl;

      AlignmentAuto.AzimuthNumUpdates   = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
      AlignmentAuto.ElevationNumUpdates = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
      AlignmentAuto.RollUpdates         = alignment_ipc_data.dra_core_log_data.n_updates_roll;
      AlignmentAuto.HostScf             = alignment_ipc_data.dra_core_log_data.speed_compensation_factor_estimated;
      /* Enum Conversion. DRA Algo Enum for QF is differnet from Platform ENUM for QF, so below conversion done */
      uint8 align_qf_enum[3] = {0U, 2U, 3U};
      /* Ensure that SCF estimation quality factor is within the valid range */
      if (alignment_ipc_data.dra_core_log_data.scf_estimation_qf <= DRA_QF_OK)
      {
         AlignmentAuto.HostScf_QF = align_qf_enum[alignment_ipc_data.dra_core_log_data.scf_estimation_qf];
      }

      AlignmentAuto.Az_Err_positive    = alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_az;
      AlignmentAuto.El_Err_positive    = alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_el;
      AlignmentAuto.RollError_positive = alignment_ipc_data.dra_core_log_data.estimated_pos_error_bound_rl;
      AlignmentAuto.Az_Err_negative    = alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_az;
      AlignmentAuto.El_Err_negative    = alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_el;
      AlignmentAuto.RollError_negative = alignment_ipc_data.dra_core_log_data.estimated_neg_error_bound_rl;
   }
}

/******************************************************************************
   Function name        : Update_Current_Dyn_Alignment_Data
   Function Description : This function Updates the Respective dynamic structures with relevent datas
   Input Parameters     : dyn_d2m_ptr
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Current_Dyn_Alignment_Data(void)
{
   if ((DRA_ALGO_MODE_SHORT_TRACK == alignment_ipc_data.dra_core_log_data.alignment_mode) ||
       (DRA_ALGO_MODE_SERVICE == alignment_ipc_data.dra_core_log_data.alignment_mode) ||
       (DRA_ALGO_MODE_AUTO == alignment_ipc_data.dra_core_log_data.alignment_mode))
   {
      AlignmentDynamic.DynamicAlignmentModeOut        = (DRA_Algo_Mode_T)alignment_ipc_data.dra_core_log_data.alignment_mode;
      AlignmentDynamic.AzimuthMisalignmentAngle       = (alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated);
      AlignmentDynamic.ElevationMisalignmentAngle     = (alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated);
      AlignmentDynamic.AzimuthStdMisalignmentAngle    = alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_az;
      AlignmentDynamic.ElevationStdMisalignmentAngle  = alignment_ipc_data.dra_core_log_data.estimated_standard_deviation_el;
      AlignmentDynamic.ProgressPercent_az             = alignment_ipc_data.dra_core_log_data.alignment_complete_percent_az;
      AlignmentDynamic.ProgressPercent_el             = alignment_ipc_data.dra_core_log_data.alignment_complete_percent_el;
      AlignmentDynamic.NumberOfUpdatesAzimuth         = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
      AlignmentDynamic.NumberOfUpdatesElevation       = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
      AlignmentDynamic.AbsoluteTime                   = alignment_ipc_data.dra_core_log_data.total_time_since_start;
      AlignmentDynamic.EffectiveTimeAzimuth           = alignment_ipc_data.dra_core_log_data.total_time_running_az_scf;
      AlignmentDynamic.EffectiveTimeElevation         = alignment_ipc_data.dra_core_log_data.total_time_running_el;
      AlignmentDynamic.AbsoluteDistance               = alignment_ipc_data.dra_core_log_data.total_distance_since_start;
      AlignmentDynamic.EffectiveDistanceAzimuth       = alignment_ipc_data.dra_core_log_data.total_distance_running_az_scf;
      AlignmentDynamic.EffectiveDistanceElevation     = alignment_ipc_data.dra_core_log_data.total_distance_running_el;
      AlignmentDynamic.AbsoluteAverageSpeed           = alignment_ipc_data.dra_core_log_data.avg_spd_since_start;
      AlignmentDynamic.EffectiveAverageSpeedAzimuth   = alignment_ipc_data.dra_core_log_data.avg_spd_running_az_scf;
      AlignmentDynamic.EffectiveAverageSpeedElevation = alignment_ipc_data.dra_core_log_data.avg_spd_running_el;
      AlignmentDynamic.AzimuthQuality                 = alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf;
      AlignmentDynamic.ElevationQuality               = alignment_ipc_data.dra_core_log_data.elevation_estimation_qf;

      AlignmentDynamic.ErrSt_out_of_bounds_az    = alignment_ipc_data.dra_core_log_data.error_status_az_est_out_of_bounds;
      AlignmentDynamic.ErrSt_out_of_bounds_el    = alignment_ipc_data.dra_core_log_data.error_status_el_est_out_of_bounds;
      AlignmentDynamic.Failstatus_Initialization = alignment_ipc_data.dra_core_log_data.error_status_initialization;
      AlignmentDynamic.Failstatus_Blockage       = alignment_ipc_data.dra_core_log_data.error_status_excessive_blockage;
      AlignmentDynamic.FailStatus_Vehicle_In     = alignment_ipc_data.dra_core_log_data.error_status_vehicle_input;
   }
}

/******************************************************************************
   Function name        : Update_Successful_Dyn_Alignment_Data
   Function Description : This function populates the Successfull Alignment data to alignmnent handler
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Successful_Dyn_Alignment_Data(void)
{
   AlignmentHandler.InitialAlignmentResultAz        = AlignmentHandler.AlignmentAzimuth;
   AlignmentHandler.InitialAlignmentResultEl        = AlignmentHandler.AlignmentElevation;
   AlignmentHandler.InitialAlignmentResultRoll      = AlignmentHandler.AlignmentRoll;
   AlignmentHandler.InitialAlignmentResultAzUpdates = alignment_ipc_data.dra_core_log_data.n_updates_azimuth;
   AlignmentHandler.InitialAlignmentResultElUpdates = alignment_ipc_data.dra_core_log_data.n_updates_elevation;
#ifdef FLR8
   AlignmentHandler.InitialAlignmentResultRollUpdates = alignment_ipc_data.dra_core_log_data.n_updates_roll;
#endif
   AlignmentHandler.InitialAlignmentResultHostSCF   = alignment_ipc_data.dra_core_log_data.speed_compensation_factor_estimated;
   AlignmentHandler.InitialLastSuccessAlignmentMode = Alignment_Type;
   AlignmentHandler.AlignmentModeOut                = ALIGN_MODE_AUTO;

   Update_Alignment_NVM_Data();
}

/******************************************************************************
   Function name        : Update_Alignment_NVM_Data
   Function Description : This function updates the data that has to be stored in the NVM
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Alignment_NVM_Data(void)
{
   Alignment_NVM_Data.AACurrentAzimuth   = AlignmentAuto.AACurrentAzimuth;
   Alignment_NVM_Data.AACurrentElevation = AlignmentAuto.AACurrentElevation;

   Alignment_NVM_Data.InitialAlignmentResultAzimuth   = AlignmentHandler.InitialAlignmentResultAz;
   Alignment_NVM_Data.InitialAlignmentResultElevation = AlignmentHandler.InitialAlignmentResultEl;

   Alignment_NVM_Data.InitialLastSuccessfulAlignmentMode = AlignmentHandler.InitialLastSuccessAlignmentMode;

   Alignment_NVM_Data.AzimuthUpdates   = (float32_t)AlignmentAuto.AzimuthNumUpdates;
   Alignment_NVM_Data.ElevationUpdates = (float32_t)AlignmentAuto.ElevationNumUpdates;

   Alignment_NVM_Data.InitialAlignmentResultAzimuthUpdates   = AlignmentHandler.InitialAlignmentResultAzUpdates;
   Alignment_NVM_Data.InitialAlignmentResultElevationUpdates = AlignmentHandler.InitialAlignmentResultElUpdates;
#ifdef FLR8
   Alignment_NVM_Data.AACurrentRoll                     = AlignmentAuto.AACurrentRoll;
   Alignment_NVM_Data.InitialAlignmentResultRoll        = AlignmentHandler.InitialAlignmentResultRoll;
   Alignment_NVM_Data.RollUpdates                       = (float32_t)AlignmentAuto.RollUpdates;
   Alignment_NVM_Data.InitialAlignmentResultRollUpdates = AlignmentHandler.InitialAlignmentResultRollUpdates;
#endif
   Alignment_NVM_Data.HostSpeedCompensationFactor                       = AlignmentAuto.HostScf;
   Alignment_NVM_Data.InitialAlignmentResultHostSpeedCompensationFactor = AlignmentHandler.InitialAlignmentResultHostSCF;
   Alignment_NVM_Data.AlignmentModeOut                                  = AlignmentHandler.AlignmentModeOut;

   Alignment_NVM_Data.azimuth_estimation_qf   = alignment_ipc_data.dra_core_log_data.azimuth_estimation_qf;
   Alignment_NVM_Data.elevation_estimation_qf = alignment_ipc_data.dra_core_log_data.elevation_estimation_qf;
   Alignment_NVM_Data.scf_estimation_qf       = alignment_ipc_data.dra_core_log_data.scf_estimation_qf;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   Test_Alignment_NVM_Record_Write(&Alignment_NVM_Data);
#endif
   /*RTE call to initiate NVM write*/
   (void)Rte_Write_Pp_Align_Write_Nvm_Record_Alignment_Record(&Alignment_NVM_Data);
   (void)Rte_Call_CS_Rp_Trigger_Write_to_NvM_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, CDD_ALIGNMENT);
}
/******************************************************************************
   Function name        : Update_XCP_Alignment_Data
   Function Description : This function updates data to XCP structure
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_XCP_Alignment_Data(void)
{
   Dt_Auto_Alignment_Result_T xcp_auto_alignment_data           = {0};
   Dt_Initial_Alignment_Result_T xcp_initial_align_res          = {0};
   Dt_Initial_Alignment_Performance_Result_T xcp_align_perf_res = {0};

   xcp_auto_alignment_data.StartAzimuth                 = AlignmentAuto.StartAzimuth;
   xcp_auto_alignment_data.StartElevation               = AlignmentAuto.StartElevation;
   xcp_auto_alignment_data.AACurrentAzimuth             = AlignmentAuto.AACurrentAzimuth;
   xcp_auto_alignment_data.AACurrentElevation           = AlignmentAuto.AACurrentElevation;
   xcp_auto_alignment_data.AAAzimuthStd                 = AlignmentAuto.AAAzimuthStd;
   xcp_auto_alignment_data.AAElevationStd               = AlignmentAuto.AAElevationStd;
   xcp_auto_alignment_data.AzimuthError_positiveRead    = AlignmentAuto.Az_Err_positive;
   xcp_auto_alignment_data.AzimuthError_negativeRead    = AlignmentAuto.Az_Err_negative;
   xcp_auto_alignment_data.ElevationError_positive_Read = AlignmentAuto.El_Err_positive;
   xcp_auto_alignment_data.ElevationError_negative_Read = AlignmentAuto.El_Err_negative;
   xcp_auto_alignment_data.AlignmentAutoStatus          = AlignmentAuto.AlignAutoStatus;
   xcp_auto_alignment_data.AutoAlignmentFailRootCause   = AlignmentAuto.AutoAlignmentFailRootCause;

   xcp_initial_align_res.AlignmentAzimuth          = AlignmentHandler.AlignmentAzimuth;
   xcp_initial_align_res.AlignmentElevation        = AlignmentHandler.AlignmentElevation;
   xcp_initial_align_res.AzimuthStd                = AlignmentHandler.AzimuthStd;
   xcp_initial_align_res.ElevationStd              = AlignmentHandler.ElevationStd;
   xcp_initial_align_res.CalTime                   = AlignmentHandler.calTime;
   xcp_initial_align_res.AlignmentStaticStatus     = AlignmentStatic.AlignmentStaticStatus;
   xcp_initial_align_res.AlignmentServiceStatus    = AlignmentService.AlignmentServiceSt;
   xcp_initial_align_res.AlignmentShortTrackStatus = AlignmentShortTrack.AlignShortTrackSt;
   xcp_initial_align_res.ProgressPercent           = AlignmentHandler.ProgressPercent;
   xcp_initial_align_res.AlignmentError            = AlignmentHandler.AlignmentError;
#ifdef FLR8
   xcp_auto_alignment_data.RollError_positive_Read = AlignmentAuto.RollError_positive;
   xcp_auto_alignment_data.RollError_negative      = AlignmentAuto.RollError_negative;
   xcp_auto_alignment_data.StartRoll               = AlignmentAuto.StartRoll;
   xcp_auto_alignment_data.AACurrentRoll           = AlignmentAuto.AACurrentRoll;
   xcp_auto_alignment_data.AARollStd               = AlignmentAuto.AARollStd;
   xcp_initial_align_res.AlignmentRoll             = AlignmentHandler.AlignmentRoll;
   xcp_initial_align_res.RollStd                   = AlignmentHandler.RollStd;
#endif

   xcp_align_perf_res.MeasuredRange             = AlignmentStatic.MeasuredRange;
   xcp_align_perf_res.MeasuredRangeStd          = AlignmentStatic.MeasuredRangeStd;
   xcp_align_perf_res.MeasuredRangeRate         = AlignmentStatic.MeasuredRangeRate;
   xcp_align_perf_res.MeasuredRangeRateStd      = AlignmentStatic.MeasuredRangeRateStd;
   xcp_align_perf_res.MeasuredAmp               = AlignmentStatic.MeasuredAmplitude;
   xcp_align_perf_res.MeasuredAmpStd            = AlignmentStatic.MeasuredAmpStd;
   xcp_align_perf_res.DistanceAbsolute          = AlignmentService.DistanceAbsolute;
   xcp_align_perf_res.DistanceEffective         = AlignmentService.DistanceEffective;
   xcp_align_perf_res.AverageNumberOfDetections = (float32_t)AlignmentService.AvgNumOfDet;
   xcp_align_perf_res.DurationAbsolute          = AlignmentService.DurationAbsolute;
   xcp_align_perf_res.DurationEffective         = AlignmentService.DurationEffective;
   xcp_align_perf_res.AverageSpeed              = AlignmentService.AverageSpeed;
   xcp_align_perf_res.VehicleCondition          = AlignmentService.VehicleCondition;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   Test_Alignment_XCP_RTE_Writes(&xcp_auto_alignment_data, &xcp_initial_align_res, &xcp_align_perf_res);
#endif

   (void)Rte_Write_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform(&xcp_align_perf_res);
   (void)Rte_Write_Pp_Auto_Alignment_Data_Auto_Alignment_Data(&xcp_auto_alignment_data);
   (void)Rte_Write_Pp_Initial_Alignment_Result_Initial_Alignment_Result(&xcp_initial_align_res);
}

/******************************************************************************
   Function name        : Validate_Alignment_NVM_Data
   Function Description : This function Validate the data that has to be stored in the NVM
   Input Parameters     : void
   Return               : Dt_Align_Status
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static Dt_Align_Status Validate_Alignment_NVM_Data(void)
{
   Dt_Align_Status nvm_valid_chk  = ALIGNMENT_PAUSED; /*Set to Paused, to not report False DTC at StartUP */
   float32_t aacurrentazimuth_nvm = 0, aacurrentelevation_nvm = 0;

   /* Check for NVM corruption first */
   if (Check_NVM_Data_Corruption())
   {
      aacurrentazimuth_nvm   = Alignment_NVM_Data.AACurrentAzimuth;
      aacurrentelevation_nvm = Alignment_NVM_Data.AACurrentElevation;

      /* Validate all NVM data ranges */
      if (Check_NVM_Misalignment_Range(aacurrentazimuth_nvm, aacurrentelevation_nvm))
      {
         nvm_valid_chk = ALIGNMENT_FAILED;
      }
      else if (Check_NVM_Roll_Range())
      {
         nvm_valid_chk = ALIGNMENT_FAILED;
      }
      else if (Check_NVM_Update_Counts())
      {
         nvm_valid_chk = ALIGNMENT_FAILED;
      }
      else if (Check_NVM_Alignment_Mode())
      {
         nvm_valid_chk = ALIGNMENT_FAILED;
      }
      else
      {
         /*NVM data valid*/
      }

      /* Check and fix host speed compensation factor if needed */
      Check_And_Fix_Host_Speed_Factor();
   }
   else
   {
      /* NVM corruption detedted*/
      nvm_valid_chk = ALIGNMENT_FAILED;
   }
   return nvm_valid_chk;
}

/******************************************************************************
   Function name        : Check_NVM_Data_Corruption
   Function Description : Checks if NVM data is corrupted (all 0xFF) or default (all 0x00)
   Input Parameters     : void
   Return               : bool - TRUE if data is valid, FALSE if corrupted
   Global Data used     : Alignment_NVM_Data
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_NVM_Data_Corruption(void)
{
   Dt_Write_Alignment_NvM_Data_T nvm_corrupt_data;
   Dt_Write_Alignment_NvM_Data_T nvm_default_data;

   /* NVM corruption indicate all data is loaded as 0xFF*/
   memset(&nvm_corrupt_data, 0xff, sizeof(Dt_Write_Alignment_NvM_Data_T));
   memset(&nvm_default_data, 0x00, sizeof(Dt_Write_Alignment_NvM_Data_T));

   return ((memcmp(&Alignment_NVM_Data, &nvm_corrupt_data, sizeof(Dt_Write_Alignment_NvM_Data_T)) != 0) &&
           (memcmp(&Alignment_NVM_Data, &nvm_default_data, sizeof(Dt_Write_Alignment_NvM_Data_T)) != 0));
}

/******************************************************************************
   Function name        : Check_NVM_Misalignment_Range
   Function Description : Checks if azimuth and elevation misalignment are within valid range
   Input Parameters     : aacurrentazimuth_nvm - azimuth value from NVM
                          aacurrentelevation_nvm - elevation value from NVM
   Return               : bool - TRUE if out of range, FALSE if within range
   Global Data used     : k_sensor_mount_ornt_yaw_list_smc, k_sensor_mount_ornt_pitch_list_smc
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_NVM_Misalignment_Range(float32_t aacurrentazimuth_nvm, float32_t aacurrentelevation_nvm)
{
   float32_t misalignment_nvm_az = 0.0F;
   float32_t misalignment_nvm_el = 0.0F;

   Calib_Data_T volatile *calib_data_ptr = &Get_IPC_M2D_Onetime_Msg_Buffer()->calib_data;

   /*check if the Azimuth and elevation angle are with in the range*/
   /* Those input which are not cheked are not relevent*/
   misalignment_nvm_az = (float32_t)(fabs(aacurrentazimuth_nvm -
                                          (calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw * -1.0F)));
   misalignment_nvm_el = (float32_t)(fabs(
      aacurrentelevation_nvm - (calib_data_ptr->sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch * -1.0F)));

   return ((AZIMUTH_THRESHOLD_VALUE < misalignment_nvm_az) || (ELEVATION_THRESHOLD_VALUE < misalignment_nvm_el));
}

/******************************************************************************
   Function name        : Check_NVM_Roll_Range
   Function Description : Checks if roll value is within valid range
   Input Parameters     : void
   Return               : bool - TRUE if out of range, FALSE if within range
   Global Data used     : Alignment_NVM_Data
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_NVM_Roll_Range(void)
{
   return (Alignment_NVM_Data.AACurrentRoll > (2 * Deg2Radians));
}

/******************************************************************************
   Function name        : Check_NVM_Update_Counts
   Function Description : Checks if azimuth, elevation, and roll update counts are within valid ranges
   Input Parameters     : void
   Return               : bool - TRUE if any count out of range, FALSE if all within range
   Global Data used     : Alignment_NVM_Data
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_NVM_Update_Counts(void)
{
   return (((AZ_EL_UPDATE_MIN_VALUE > Alignment_NVM_Data.InitialAlignmentResultAzimuthUpdates) ||
            (AZ_EL_UPDATE_MAX_VALUE < Alignment_NVM_Data.InitialAlignmentResultAzimuthUpdates)) ||
           ((AZ_EL_UPDATE_MIN_VALUE > Alignment_NVM_Data.InitialAlignmentResultElevationUpdates) ||
            (AZ_EL_UPDATE_MAX_VALUE < Alignment_NVM_Data.InitialAlignmentResultElevationUpdates)) ||
           ((AZ_EL_UPDATE_MIN_VALUE > Alignment_NVM_Data.InitialAlignmentResultRollUpdates) ||
            (AZ_EL_UPDATE_MAX_VALUE < Alignment_NVM_Data.InitialAlignmentResultRollUpdates)));
}

/******************************************************************************
   Function name        : Check_NVM_Alignment_Mode
   Function Description : Checks if alignment mode value is within valid range
   Input Parameters     : void
   Return               : bool - TRUE if out of range, FALSE if within range
   Global Data used     : Alignment_NVM_Data
   SDD Requirements IDs :
*******************************************************************************/
static bool Check_NVM_Alignment_Mode(void)
{
   return (ALIGNMNET_MODE_MAX_VALUE < Alignment_NVM_Data.AlignmentModeOut);
}

/******************************************************************************
   Function name        : Check_And_Fix_Host_Speed_Factor
   Function Description : Checks host speed compensation factor and resets to default if out of range
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_NVM_Data
   SDD Requirements IDs :
*******************************************************************************/
static void Check_And_Fix_Host_Speed_Factor(void)
{
   if ((HOST_SPEED_COMP_FACTOR_MIN > Alignment_NVM_Data.HostSpeedCompensationFactor) ||
       (HOST_SPEED_COMP_FACTOR_MAX < Alignment_NVM_Data.HostSpeedCompensationFactor))
   {
      Alignment_NVM_Data.HostSpeedCompensationFactor = 1;
   }
}
/******************************************************************************
   Function name        : Update_Alignment_Output
   Function Description : This function Validate the data that has to be stored in the NVM
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Update_Alignment_Output(Dt_Align_Mode_T Align_Type)
{
   alignment_m2d_data.dynamic_alignment_data.auto_align_status = (uint8_t)AlignmentAuto.AlignAutoStatus;
   if (ALIGN_MODE_AUTO == Align_Type)
   {
      alignment_m2d_data.dynamic_alignment_data.aacurrent_elevation = AlignmentAuto.AACurrentElevation;
      alignment_m2d_data.dynamic_alignment_data.aacurrent_azimuth   = AlignmentAuto.AACurrentAzimuth;
   }
   else
   {
      alignment_m2d_data.dynamic_alignment_data.aacurrent_elevation = 0.0F;
      alignment_m2d_data.dynamic_alignment_data.aacurrent_azimuth   = 0.0F;
   }
}

/******************************************************************************
   Function name        : Initialize_Auto_Alignment_From_NVM
   Function Description : This function initializes auto alignment parameters from NVM data
   Input Parameters     : void
   Return               : void
   Global Data used     : Alignment_NVM_Data, AlignmentHandler, AlignmentAuto, alignment_m2d_data
   SDD Requirements IDs :
*******************************************************************************/
static void Initialize_Auto_Alignment_From_NVM(void)
{
   float32_t misaligned_azimuth_angle   = 0.00F;
   float32_t misaligned_elevation_angle = 0.00F;
   float32_t max_misalign_az            = 0.00F;
   float32_t max_misalign_el            = 0.00F;

   if (AlignmentAuto.AlignAutoStatus != ALIGNMENT_FAILED)
   {
      /*Hardcoded temporarily since rtes not avilable for reading nvm*/
      AlignmentHandler.InitialLastSuccessAlignmentMode = (Dt_Align_Mode_T)Alignment_NVM_Data.InitialLastSuccessfulAlignmentMode;
      AlignmentHandler.InitialAlignmentResultAz        = Alignment_NVM_Data.InitialAlignmentResultAzimuth;
      AlignmentHandler.InitialAlignmentResultEl        = Alignment_NVM_Data.InitialAlignmentResultElevation;
      AlignmentHandler.AlignmentAzimuth                = AlignmentHandler.InitialAlignmentResultAz;
      AlignmentHandler.AlignmentElevation              = AlignmentHandler.InitialAlignmentResultEl;
      AlignmentHandler.InitialAlignmentResultAzUpdates = (uint32_t)Alignment_NVM_Data.InitialAlignmentResultAzimuthUpdates;
      AlignmentHandler.InitialAlignmentResultElUpdates = (uint32_t)Alignment_NVM_Data.InitialAlignmentResultElevationUpdates;
#ifdef FLR8
      AlignmentHandler.InitialAlignmentResultRoll        = Alignment_NVM_Data.InitialAlignmentResultRoll;
      AlignmentHandler.InitialAlignmentResultRollUpdates = (uint32_t)Alignment_NVM_Data.InitialAlignmentResultRollUpdates;
#endif
      /*Read data from NVM and Update rele
      vant parameters*/
      misaligned_azimuth_angle =
         (Alignment_NVM_Data.AACurrentAzimuth - alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated);
      misaligned_elevation_angle =
         (Alignment_NVM_Data.AACurrentElevation - alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated);

      max_misalign_az = (misaligned_azimuth_angle >= 0.0F) ? MAX_AA_ANGLE_CHG_LIMIT : MAX_AA_ANGLE_CHG_LIMIT * -1.0F;
      max_misalign_el = (misaligned_elevation_angle >= 0.0F) ? MAX_AA_ANGLE_CHG_LIMIT : MAX_AA_ANGLE_CHG_LIMIT * -1.0F;

      AlignmentAuto.AACurrentAzimuth =
         ((fabsf(misaligned_azimuth_angle)) < MAX_AA_ANGLE_CHG_LIMIT) ?
            Alignment_NVM_Data.AACurrentAzimuth :
            alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated + max_misalign_az;
      AlignmentAuto.AACurrentElevation =
         ((fabsf(misaligned_elevation_angle)) < MAX_AA_ANGLE_CHG_LIMIT) ?
            Alignment_NVM_Data.AACurrentElevation :
            alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated + max_misalign_el;
#ifdef FLR8
      AlignmentAuto.AACurrentRoll =
         (Alignment_NVM_Data.AACurrentRoll < (MAX_AA_ROLL_ANGLE_CHG_LIMIT)) ? Alignment_NVM_Data.AACurrentRoll : 0.0F;
#endif
      AlignmentAuto.AzimuthNumUpdates   = (uint32_t)Alignment_NVM_Data.AzimuthUpdates;
      AlignmentAuto.ElevationNumUpdates = (uint32_t)Alignment_NVM_Data.ElevationUpdates;
#ifdef FLR8
      AlignmentAuto.RollUpdates = (uint32_t)Alignment_NVM_Data.RollUpdates;
#endif
      /*using available parameters from alignment_m2d_data temporarity to send out qf data to d2m*/
      alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_az =
         (float)((Alignment_NVM_Data.azimuth_estimation_qf <= 2) ? Alignment_NVM_Data.azimuth_estimation_qf : 0.0F);
      alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_el =
         (float)((Alignment_NVM_Data.elevation_estimation_qf <= 2) ? Alignment_NVM_Data.elevation_estimation_qf : 0.0F);

      /*scf_qf is not available in Dat type Dt_Dynamic_Alignment_Data so using unsued parameter (iso_sensor_z_posn) temporarily to
       * pass data to d2m*/
      alignment_m2d_data.dynamic_alignment_data.iso_sensor_z_posn =
         (float)((Alignment_NVM_Data.scf_estimation_qf <= 2) ? Alignment_NVM_Data.scf_estimation_qf : 0.0F);
   }
}

/******************************************************************************
   Function name        : Handle_Auto_Alignment_Precondition
   Function Description : This function checks if auto alignment precondition is met (WI-322574)
   Input Parameters     : void
   Return               : void
   Global Data used     : AlignmentHandler, Alignment_Type
   SDD Requirements IDs : WI-322574
*******************************************************************************/
static void Handle_Auto_Alignment_Precondition(void)
{
   if (AlignmentHandler.InitialLastSuccessAlignmentMode != ALIGN_MODE_OFF)
   {
      Auto_Alignment_Handler();
   }
   else
   {
      Alignment_Type                = ALIGN_MODE_OFF;
      AlignmentAuto.AlignAutoStatus = ALIGNMENT_OFF;
   }
}

/******************************************************************************
   Function name        : Handle_ShortTrack_Alignment
   Function Description : This function handles short track alignment mode execution
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, alignment_m2d_data
   SDD Requirements IDs :
*******************************************************************************/
static void Handle_ShortTrack_Alignment(void)
{
   /*Use alignment_initial_cals.short_track_submode to select Short Track submode */
   if (alignment_initial_cals.short_track_submode == 0U)
   {
      /*Standard Short Track mode*/
      alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_SHORT_TRACK;
      Update_Initial_Alignment_Value();
      if ((uint8_t)DRA_ALGO_MODE_SHORT_TRACK == alignment_ipc_data.dra_core_log_data.alignment_mode)
      {
         Dynamic_ShortTrack_Alignment_Handler();
      }
   }
   else if (alignment_initial_cals.short_track_submode == 1U)
   {
      /*Fast Service mode (Short Track Guardrail)*/
      alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_FAST_SERVICE;
      Update_Initial_Alignment_Value();
      if ((uint8_t)DRA_ALGO_MODE_FAST_SERVICE == alignment_ipc_data.dra_core_log_data.alignment_mode)
      {
         Dynamic_Service_Alignment_Handler(&AlignmentShortTrack.AlignShortTrackSt);
      }
   }
   else
   {
      /*do nothing*/
   }
}

/******************************************************************************
   Function name        : Handle_Service_Alignment
   Function Description : This function handles service alignment mode execution
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, alignment_m2d_data
   SDD Requirements IDs :
*******************************************************************************/
static void Handle_Service_Alignment(void)
{
   alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_SERVICE;
   Update_Initial_Alignment_Value();
   /* Execute Handler for Detection Error, to report Status as Paused */
   if ((uint8_t)DRA_ALGO_MODE_SERVICE == alignment_ipc_data.dra_core_log_data.alignment_mode)
   {
      Dynamic_Service_Alignment_Handler(&AlignmentService.AlignmentServiceSt);
   }
}

/******************************************************************************
   Function name        : Handle_Static_Alignment
   Function Description : This function handles static alignment mode execution
   Input Parameters     : void
   Return               : void
   Global Data used     : alignment_ipc_data, alignment_m2d_data
   SDD Requirements IDs :
*******************************************************************************/
static void Handle_Static_Alignment(void)
{
   alignment_m2d_data.static_alignment_data.align_cmd  = (uint8_t)SRA_ALGO_MODE_ACTIVE;
   alignment_m2d_data.dynamic_alignment_data.align_cmd = (uint8_t)DRA_ALGO_MODE_OFF; /*AutoAlignment Stop*/
   if ((uint8_t)1 == alignment_ipc_data.alignment_mode)                              /* 0: off, 1: static, 2: Dynamic*/
   {
      Static_Alignment_Handler();
   }
}

/******************************************************************************
   Function name        : Auto_Align_OOR_Fault_Check
   Function Description : This function checks for out-of-range faults in the alignment data
   Input Parameters     : void
   Return               : void
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
void Auto_Align_OOR_Fault_Check(void)
{
   float32_t az_angle_chg = fabsf(Alignment_NVM_Data.AACurrentAzimuth - (Align_Mounting_Parameters.iso_sensor_yaw * -1.0F));
   float32_t el_angle_chg = fabsf(Alignment_NVM_Data.AACurrentElevation - (Align_Mounting_Parameters.iso_sensor_pitch * -1.0F));

   if ((az_angle_chg > alignment_auto_cals.azimuth_threshold) || (el_angle_chg > alignment_auto_cals.elevation_threshold))
   {
      /*Set OOR Fault when azimuth or elevation angle change read from NVM exceeds limits*/
      Alignment_Faults.Autoalign_outof_range_error = CODED_TRUE;
   }
}

/******************************************************************************
   Function name        : Save_Unsuccesfull_Alignment_Data
   Function Description : Saves the alignment NVM data when alignment has failed.
   Input Parameters     : None
   Return               : None
   Global Data used     : NA
   SDD Requirements IDs :
*******************************************************************************/
static void Save_Unsuccesfull_Alignment_Data(void)
{
   AlignmentHandler.InitialLastSuccessAlignmentMode = ALIGN_MODE_OFF;
   AlignmentHandler.InitialAlignmentResultAz        = AlignmentHandler.AlignmentAzimuth;
   AlignmentHandler.InitialAlignmentResultEl        = AlignmentHandler.AlignmentElevation;
   AlignmentHandler.InitialAlignmentResultRoll      = AlignmentHandler.AlignmentRoll;
   Update_Alignment_NVM_Data();
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF011_Static_Alignment_Engineering_Non_Configuration_Parameters_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF013_Static_Alignment_Engineering_Write_Configuration_Parameter_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF014_Service_Alignment_Engineering_Non_Configuration_Parameters_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ConditionCheckRead)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF012_Static_Alignment_Engineering_Read_Parameters_ReadData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ConditionCheckRead)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF015_Service_Alignment_Result_Parameters_ReadData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF016_Auto_Alignment_Status_Information_ConditionCheckRead)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF016_Auto_Alignment_Status_Information_ReadData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF01B_Manual_Alignment_Execution_ConditionCheckRead)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF01B_Manual_Alignment_Execution_ReadData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF01B_Manual_Alignment_Execution_WriteData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ConditionCheckRead)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Data_0xF01C_Static_Alignment_Result_Parameters_ReadData)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_RequestResults)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Start)  */
   return RTE_E_OK;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7000_Static_Alignment_Execution_Start_Stop)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_RequestResults)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Start)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RoutineServices_Routine_0x7003_Service_Alignment_Execution_Start_Stop)  */

   return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
