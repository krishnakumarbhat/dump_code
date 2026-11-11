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
 *             File:  SWC_PLT_CDD_Logging.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_Logging
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_Logging>
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
 * Dt_DRA_Detection_Coordinate_System
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * StbM_TimeBaseStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_Logging.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dynamic_alignment_stream.h"
#include "EthIf_GenTypes.h"
#include "Fault_Lib_Plt.h"
#include "SWC_PLT_Appl_IoHwAb_Cfg.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "SWC_PLT_CDD_Logging.h"
#include "SWC_PLT_CDD_XCP.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "SoAd.h"
#include "Xcp.h"
#include "dd_mmic.h"
#include "debug_stream.h"
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "dsp_setup.h"
#include "header_stream.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "mmic_interface.h"
#include "program_flow_monitor.h"
#include "rdd_stream.h"
#include "reuse.h"
#include "sensor_position.h"
#include "smc_cal.h"
#include "stack_monitor_r52.h"
#include "static_alignment_stream.h"
#include "status_stream.h"
#include "usc_cal.h"
#include "versions.h"
#include "vse_stream.h"
#include "xcp_bb.h"
#include "xcp_bb_types.h"
/* TODO: Remove after Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable */
#include "Fault_Lib_Prj.h"
#include "SWC_PLT_CDD_Logging.h"
#include "calibration_if.h"
#include "dd_pmic.h"
#include "radar_data.h"
#include "sh_comm.h"
#include "sh_interface.h"
#include "sh_module_cfg.h"

#if (defined(CDC_ENABLE))
   #include "cdc_frame_interface.h"
   #include "cdc_stream.h"
#endif
#include "hil_communication_handler.h"
#include "hil_types.h"

#define MIN_SUB_STREAM_CNT (1U)
/*#define ETH_PERIODIC_TEST_TIME*/ /*Enable this for testing purpose*/
#ifdef ETH_PERIODIC_TEST_TIME
   #include "platformtime.h"
   #define UNIT16_MAX_VALUE (65535U)
#endif
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "id_stream.h"

#define SWC_PLT_CDD_Logging_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile uint32_t Test_PostRadarProcessing_ADC_Populate_ADC_Stream                           = 0;
volatile uint32_t Test_PostRadarProcessing_MMIC_Populate_MMIC_Stream                         = 0;
volatile uint32_t Test_PostRadarProcessing_Status_Populate_Status_Stream                     = 0;
volatile uint32_t Test_PostRadarProcessing_Debug_Populate_Debug_Stream                       = 0;
volatile uint32_t Test_PostRadarProcessing_Detection_Populate_Detection_Stream               = 0;
volatile uint32_t Test_PostRadarProcessing_RDD_Populate_RDD_Stream                           = 0;
volatile uint32_t Test_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream = 0;
uint8_t Stream_Handler_En_XCP   = CODED_TRUE;  /*Variable to enable/diable periodic message TX*/
static uint8_t HIL_Req_Stop_CDC = CODED_FALSE; /*Variable to stop CDC Tx during HIL*/
static Vse_Stream_T Vse_Stream  = {0};

static Stream_Error_T RDD_Stream_Err;
static Stream_Error_T RDD_Debug_Stream_Err;
static volatile Radar_Look_T XCP_Look_Select = NUM_LOOKS;
static bool K_Disable_CDC_Logging            = false; /*This flag will be enabled in future */
static bool XCP_Connection_Status            = false;
#ifdef TRACKER_ENABLED
static uint32_t Tracker_Ref_Index = 0U;
#endif

Dt_CPU_Load CPU_Load_C0_Logging = {0U, 0U, 0U, 0U};

GLOB_TS_STRUCT_TYPE cur_timestamp_start;
GLOB_TS_STRUCT_TYPE cur_timestamp_end;
GLOB_TS_STRUCT_TYPE cur_mid_dwell;

#define NUM_THERMAL_SENSORS (2U)

#if (defined(CDC_ENABLE))
volatile static uint16_t C0_CDC_Current_Index                = 0U;
volatile static uint16_t C0_CDC_Previous_Index               = 0U;
volatile static uint32_t C0_CDC_Transmit_Success_Cnt         = 0U;
volatile static uint32_t C0_CDC_Transmit_Fail_Cnt            = 0U;
volatile static uint16_t C0_CDC_Transmitted_In_Cycle_Cnt     = 0U;
volatile static uint16_t C0_CDC_Transmitted_In_Cycle_Cnt_Max = 0U;
volatile static uint16_t C0_CDC_Current_Index_Cnt            = 0U;
volatile static uint32_t C0_CDC_Current_Index_Error_Cnt      = 0U;
volatile static uint16_t C0_CDC_Enet_Buffer_Max_Depth        = 0U;
volatile bool C0_CDC_Radar_Frame_Reset                       = false;
volatile static uint32_t CDC_Prev_Interface_Index            = 0U;
   /*#define CDC_FRAME_SYNC_VERIFY*/ /*while enable this macro please enable DSP_CDC_VERIFY macro in CDC_packing.c file( both macro
                                       required)*/
   #ifdef CDC_FRAME_SYNC_VERIFY
volatile static uint16_t C0_CDC_Frame_Sync_Count     = 0U;
volatile static uint16_t C0_CDC_Frame_Sync_Error_Cnt = 0U;
   #endif

#endif

#define LOG_SIGNAL_INVALID_VALUE (0xA5A5U) /* Invalid value for 16 bit signals */
/* Protocol dependent configs*/
#ifndef MULTICAST_LOG_TX_ENABLE
   #define REGULAR_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_LOGGING_TX;
   #define DYNAMIC_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_ETH_XCP_TX;
   #define FAST_STREAM_PDU_ID    SoAdConf_SoAdPduRoute_RDR_LOGGING_TX_FAST;
#else
   #define REGULAR_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_LOGGING_TX;
   #define DYNAMIC_STREAM_PDU_ID SoAdConf_SoAdPduRoute_RDR_ETH_XCP_TX;
   #define FAST_STREAM_PDU_ID    SoAdConf_SoAdPduRoute_RDR_LOGGING_TX_FAST;
#endif

#ifndef US_2_MS
   #define US_2_MS (0.001F)
#endif

#ifndef STACK_MONITORING_CYCLE
   #define STACK_MONITORING_CYCLE (1000U)
#endif

/* Test variables for Ethernet Stack verification */
volatile static uint32_t Frame_Tx_Success_Cnt = 0U;
volatile static uint32_t Frame_Tx_Failure_Cnt = 0U;
#if defined(SH_ENABLE_CALIB_STREAM)
static void Config_Calib_Stream(void);
#endif
#ifdef TRACKER_ENABLED
static bool Is_Tracker_Stream_Applicable(void);
static void Config_Tracker_Streams(void);
#endif
static Status_Stream_T Status_Stream = {0};
static Debug_Stream_T Debug_Stream   = {0};
static Header_Stream_T Header_Stream = {0};

#define STREAM_TX_ENABLE                 ((uint8_t)1) /* To enable the stream transmission at runtime */
#define STREAM_TX_CFG_APPLY_MAX_ATTEMPTS (5U)         /* Max count to retry applying stream Tx config in case of failure */
static uint8_t Stream_Tx_Cfg_Apply_Retry_Count = 0U;  /* Counter to track the application of stream enable/disable config */
#if defined(ALL_LOGGING_STREAMS_TX_DISABLE) || (defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE))
volatile static uint8_t Streams_Tx_Cfg_Apply   = CODED_TRUE; /* Apply stream enable/disable config once at runtime */
volatile static uint8_t Stream_Tx_Enable_State = 0U;         /* Stream TX enable state (0=disable, 1=enable) */
volatile static uint32_t Stream_Num_Bitfield[STREAM_NUM_BITFIELD_WORDS] = {
   0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00}; /* Bitfield to select which stream to enable/disable; all stream disabled by default */
#else
volatile static uint8_t Streams_Tx_Cfg_Apply   = CODED_FALSE;      /* No one-time apply needed by default */
volatile static uint8_t Stream_Tx_Enable_State = STREAM_TX_ENABLE; /* Stream TX enable state (0=disable, 1=enable) */
volatile static uint32_t Stream_Num_Bitfield[STREAM_NUM_BITFIELD_WORDS] = {
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00}; /* Bitfield to select which stream to enable/disable; no stream selected by default */

#endif
volatile uint8_t Test_PostRadarProcessing_Header_Populate_Header_Stream = 0;

/** R52 to DSP buffer ping pong index*/
extern uint8_t R52_M2D_Buffer_Index;
/** Flag to indicate range process config init is complete*/
// extern volatile DSP_Config_Type_T DSP_Cfg_Init;
extern volatile bool DSP_Init;
extern uint32_t R52_M2D_Msg_Header_Cnt;
extern uint32_t Dsp_Cfg_Error_Counter;

/** Debug counters*/
extern uint32_t M2D_DSP_Not_Ready_Counter;

extern volatile uint8_t DSP_Processing_Error_Counter;
extern volatile uint8_t DSP_Reset_Counter;
extern volatile uint8_t DSP_Skipped_Frame_Error_Counter;
extern uint32_t DSP_Skipped_Frame;
extern uint16_t MMIC_Not_Configured_Error;
static uint8_t One_Time_Call           = 1U;
volatile uint32_t Test_Re_50ms_Counter = 0;
extern volatile uint32_t Ubsan_Divzero_Count;
extern volatile uint32_t Ubsan_Divzero_Caller_LR;

static void Populate_Status_Stream(void);
static void Populate_Header_Stream(void);
static void Populate_Debug_Stream(void);
static void Populate_Vse_Stream(void);
#ifdef TRACKER_ENABLED
static void Populate_Partner_Sensor_Stream(void);
#endif

#ifdef VEH_AL_CAN_STANDALONE
   #if defined(FEATURE_ENABLE)
static void Populate_BSIS_Stream(void);
static void Populate_MOIS_Stream(void);
static void Populate_Olp_Stream(void);
   #endif
#endif

volatile uint32_t RE_2ms_Task_Cnt;
volatile uint16_t Test_Counter_StreamHandler = 0U;

bool HIL_Header_Bypass = false;
bool HIL_Status_Bypass = false;

#ifdef ETH_PERIODIC_TEST_TIME
   #define ETH_DEBUG_LOGGING_MAX_ARRAY (20U)
typedef struct
{
   uint32_t Time_us;
   uint16_t Tx_Frames;
} Eth_Logging_Debug_Info;

uint64_t Eth_5ms_Logging_Start_Time_us                                   = 0U;
uint8_t Eth_Timer_Cnt_5ms                                                = 0U;
Eth_Logging_Debug_Info Eth_5ms_Logging_Max                               = {0U, 0U};
Eth_Logging_Debug_Info Eth_5ms_Logging_Diff[ETH_DEBUG_LOGGING_MAX_ARRAY] = {
   {0U, 0U},
};

uint64_t Eth_2ms_Logging_Start_Time_us                                   = 0U;
uint8_t Eth_Timer_Cnt_2ms                                                = 0U;
Eth_Logging_Debug_Info Eth_2ms_Logging_Max                               = {0U, 0U};
Eth_Logging_Debug_Info Eth_2ms_Logging_Diff[ETH_DEBUG_LOGGING_MAX_ARRAY] = {
   {0U, 0U},
};

uint64_t Eth_50ms_Logging_Start_Time_us                                   = 0U;
uint8_t Eth_Timer_Cnt_50ms                                                = 0U;
Eth_Logging_Debug_Info Eth_50ms_Logging_Max                               = {0U, 0U};
Eth_Logging_Debug_Info Eth_50ms_Logging_Diff[ETH_DEBUG_LOGGING_MAX_ARRAY] = {
   {0U, 0U},
};

   #define GET_SOURCE_TX_CNT() Get_Source_Tx_Cnt()

   #define GET_PLT_ETH_LOG_TIME(period) Get_Platform_ustime(&Eth_##period##_Logging_Start_Time_us)

   #define GET_PLT_ETH_LOG_ELAPSED_TIME(period, x)                                                                                \
      Get_Elapse_Time_And_Tx_Frames_Logging(&Eth_Timer_Cnt_##period, &Eth_##period##_Logging_Diff[0U],                            \
                                            Eth_##period##_Logging_Start_Time_us, &Eth_##period##_Logging_Max, x)
#else
   #define GET_SOURCE_TX_CNT() ((uint16_t)0)
   #define GET_PLT_ETH_LOG_TIME(period)
   #define GET_PLT_ETH_LOG_ELAPSED_TIME(period, x) (x = 0)
#endif

#if (defined(CDC_ENABLE))
static void Config_CDC_Stream(void);
static void Reset_CDC_Radar_Frame_Flags(Cdc_Frame_Interface_T *cdc_interface_address_ptr);
static void Trigger_CDC_Frames(uint16_t start_index, uint16_t end_index, CDC_Stream_T *CDC_Data_addr,
                               bool C0_CDC_Radar_Frame_Reset);
#endif
#if defined(TRACKER_ENABLED)
static void Set_Tracker_Stream_Ref_Index(uint32_t val);
#endif
static uint8_t SoAd_Frame_Transmit(Tx_Frame_Param_T *tx_frame_param_ptr);
static void Trigger_XCP_DAQ(uint8_t look_id, uint8_t event);
static void Update_Stream_Table_Debug_Data(Debug_Stream_T *stream_ptr);
static void Populate_Alignment_Data(Header_Stream_T *stream_ptr);
#ifdef ETH_PERIODIC_TEST_TIME
static void Get_Elapse_Time_And_Tx_Frames_Logging(uint8_t *p_eth_timer_index, Eth_Logging_Debug_Info *p_eth_logging_diff,
                                                  uint64_t eth_logging_start_time_us, Eth_Logging_Debug_Info *p_eth_logging_max,
                                                  uint16_t source_tx_cnt_start);
#endif
#if defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE)
static void Set_StreamNum_BitfieldBit(uint8_t stream_num, uint32_t *stream_num_bitfield_ptr);
static void Clear_StreamNum_BitfieldBit(uint8_t stream_num, uint32_t *stream_num_bitfield_ptr);
#endif

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
Dt_AlignmentAuto AlignmentAuto_Data __attribute__((used));
Dt_AlignmentService AlignmentService_Data __attribute__((used));
Dt_AlignmentShortTrack AlignmentShortTrack_Data __attribute__((used));
Dt_AlignmentStatic AlignmentStatic_Data __attribute__((used));
Dt_Alignment_Handler AlignmentHandler_Data __attribute__((used));
Dt_Alignment_M2D_Data Alignment_M2D_Data __attribute__((used));
#endif
#define ADC_BATT_OFFSET ((float32)0.3f)
#define ADC_IGN_OFFSET  ((float32)0.325f)

#define SWC_PLT_CDD_Logging_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
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
 * Dt_STS_No_TSyn_Error: Integer in interval [0...255]
 * Dt_Time_Stamp_Delta: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
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
 * Dt_DRA_Detection_Coordinate_System: Enumeration of integer in interval [0...255] with enumerators
 *   DRA_DET_COORD_SYS_UNDEFINED_ALIGN (0U)
 *   DRA_DET_COORD_SYS_SAE_ALIGN (1U)
 *   DRA_DET_COORD_SYS_ISO_ALIGN (2U)
 * Dt_SystemOperationMode: Enumeration of integer in interval [0...255] with enumerators
 *   INIT_MCU (1U)
 *   RADAR_NOT_CONFIGURED (2U)
 *   OPERATIONAL (3U)
 *   FAULTY (4U)
 *   SHUTDOWN_INITIATED (5U)
 *   SHUTDOWN_COMPLETED (6U)
 * StbM_TimeBaseStatusType: Enumeration of integer in interval [0...63] with enumerators
 *   TIMEOUT__FALSE (0U)
 *   TIMEOUT_BflMask 1U (0b00000001)
 *   TIMEOUT_BflPn 0
 *   TIMEOUT_BflLn 1
 *   TIMEOUT (1U)
 *   TIMEOUT_BflMask 1U (0b00000001)
 *   TIMEOUT_BflPn 0
 *   TIMEOUT_BflLn 1
 *   SYNC_TO_GATEWAY__FALSE (0U)
 *   SYNC_TO_GATEWAY_BflMask 4U (0b00000100)
 *   SYNC_TO_GATEWAY_BflPn 2
 *   SYNC_TO_GATEWAY_BflLn 1
 *   SYNC_TO_GATEWAY (4U)
 *   SYNC_TO_GATEWAY_BflMask 4U (0b00000100)
 *   SYNC_TO_GATEWAY_BflPn 2
 *   SYNC_TO_GATEWAY_BflLn 1
 *   GLOBAL_TIME_BASE__FALSE (0U)
 *   GLOBAL_TIME_BASE_BflMask 8U (0b00001000)
 *   GLOBAL_TIME_BASE_BflPn 3
 *   GLOBAL_TIME_BASE_BflLn 1
 *   GLOBAL_TIME_BASE (8U)
 *   GLOBAL_TIME_BASE_BflMask 8U (0b00001000)
 *   GLOBAL_TIME_BASE_BflPn 3
 *   GLOBAL_TIME_BASE_BflLn 1
 *   TIMELEAP_FUTURE__FALSE (0U)
 *   TIMELEAP_FUTURE_BflMask 16U (0b00010000)
 *   TIMELEAP_FUTURE_BflPn 4
 *   TIMELEAP_FUTURE_BflLn 1
 *   TIMELEAP_FUTURE (16U)
 *   TIMELEAP_FUTURE_BflMask 16U (0b00010000)
 *   TIMELEAP_FUTURE_BflPn 4
 *   TIMELEAP_FUTURE_BflLn 1
 *   TIMELEAP_PAST__FALSE (0U)
 *   TIMELEAP_PAST_BflMask 32U (0b00100000)
 *   TIMELEAP_PAST_BflPn 5
 *   TIMELEAP_PAST_BflLn 1
 *   TIMELEAP_PAST (32U)
 *   TIMELEAP_PAST_BflMask 32U (0b00100000)
 *   TIMELEAP_PAST_BflPn 5
 *   TIMELEAP_PAST_BflLn 1
 *
 * Array Types:
 * ============
 * Dt_Fault_T: Array with 16 element(s) of type uint8
 * Rte_DT_Dt_Dynamic_Alignment_Data_30: Array with 4 element(s) of type float32
 * Rte_DT_Dt_Dynamic_Alignment_Data_6: Array with 4 element(s) of type float32
 * Rte_DT_Dt_FailSafe_ResetReason_T_0: Array with 5 element(s) of type uint8
 * Rte_DT_Dt_FailSafe_ResetReason_T_7: Array with 5 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_8: Array with 10 element(s) of type uint16
 * Rte_DT_Dt_FailSafe_ResetReason_T_9: Array with 35 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Crypto_CustomFunctions_VersionStruct: Record with elements
 *   containerVersion of type uint32
 *   mwVersion of type uint32
 *   sBoot of type uint32
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
 * Dt_Alignment_M2D_Data: Record with elements
 *   static_alignment_data of type Dt_Static_Alignment_Data
 *   dynamic_alignment_data of type Dt_Dynamic_Alignment_Data
 * Dt_CPU_Load: Record with elements
 *   CPU_Load of type uint32
 *   CPU_Load_Max of type uint32
 *   CPU_Load_Min of type uint32
 *   CPU_Load_Avg of type uint32
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
 * Dt_FailSafe_ResetReason_T: Record with elements
 *   reset_reason of type Rte_DT_Dt_FailSafe_ResetReason_T_0
 *   reset_counter of type uint8
 *   last_cycle_reset of type uint8
 *   reset_reason_crnt_indx of type uint8
 *   repetitive_reset_counter of type uint8
 *   RFE_Repetitive_Reset_Counter of type uint8
 *   mem_exception_reason of type Dt_Memory_Exception_Info_T
 *   wdg_failed_SE_info of type Rte_DT_Dt_FailSafe_ResetReason_T_7
 *   FCCU_Faults of type Rte_DT_Dt_FailSafe_ResetReason_T_8
 *   StaticRegCheckFailureInfo of type Rte_DT_Dt_FailSafe_ResetReason_T_9
 *   NOC_LatentIntFault_Info of type Dt_NOC_Fault_Info_T
 * Dt_Memory_Exception_Info_T: Record with elements
 *   ExceptionType of type uint32
 *   ExceptionCausingAddress of type uint32
 *   ExceptionStatusRegister of type uint32
 *   IsMemException_Occured of type boolean
 *   MemoryExceptionAddress of type uint32
 *   StackPointer of type uint32
 * Dt_NOC_Fault_Info_T: Record with elements
 *   LatentFault0 of type uint32
 *   LatentFault1 of type uint32
 *   LatentFault2 of type uint32
 *   LatentFault3 of type uint32
 *   Resnum of type uint16
 * Dt_RTM_parameters_T: Record with elements
 *   Runtime_average of type uint32
 *   Runtime_overall of type uint32
 *   Runtime_MAX of type uint32
 *   Runtime_MIN of type uint32
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
 * StbM_SyncRecordTableBlockType: Record with elements
 *   GlbSeconds of type uint32
 *   GlbNanoSeconds of type uint32
 *   TimeBaseStatus of type StbM_TimeBaseStatusType
 *   VirtualLocalTimeLow of type uint32
 *   RateDeviation of type sint16
 *   LocSeconds of type uint32
 *   LocNanoSeconds of type uint32
 *   PathDelay of type uint32
 *
 *********************************************************************************************************************/
#define SWC_PLT_CDD_Logging_START_SEC_CODE
#include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_ADC_Populate_ADC_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_ADC_Stream> of PortPrototype <PostRadarProcessing_ADC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_ADC_Populate_ADC_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_ADC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_ADC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_ADC_E_OK
 *   RTE_E_PostRadarProcessing_ADC_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_ADC_Populate_ADC_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_ADC_Populate_ADC_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_ADC_Populate_ADC_Stream (returns application error)
    *********************************************************************************************************************/

   /* Enable/Disable stream logging upon XCP request */
   /* ADC Event */
   D2M_Msg_T *p_ipc_d2m_msg = (D2M_Msg_T *)Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   M2D_Msg_T *p_ipc_m2d_msg = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   /*if (CODED_TRUE == Stream_Handler_En_XCP)*/ /*No ADC Stream for Logging so Commented */
   {
      if ((NULL != p_ipc_d2m_msg) && (NULL != p_ipc_m2d_msg))
      {
         p_ipc_m2d_msg->payload.xcp_info.xcp_look_select = XCP_Look_Select;
         Trigger_XCP_DAQ(p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_id, XcpConf_XcpEventChannel_Xcp_Daq_Event_1_ADC);
      }
   }
   Test_PostRadarProcessing_ADC_Populate_ADC_Stream++;
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Debug_Populate_Debug_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Debug_Stream> of PortPrototype <PostRadarProcessing_Debug>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Debug_Populate_Debug_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Debug_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Debug_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Debug_E_OK
 *   RTE_E_PostRadarProcessing_Debug_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Debug_Populate_Debug_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Debug_Populate_Debug_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Debug_Populate_Debug_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Debug_Stream_T *stream_ptr      = &Debug_Stream;
   Test_PostRadarProcessing_Debug_Populate_Debug_Stream++;

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      Populate_Debug_Stream();

      /* Trigger the stream handler for Debug stream */
      sh_output_data_ptr->sh_trigger_stream_handler_fptr(DEBUG, (uint8_t *)stream_ptr);
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Detection_Populate_Detection_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Detection_Stream> of PortPrototype
 *<PostRadarProcessing_Detection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Detection_Populate_Detection_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Detection_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Detection_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Detection_E_OK
 *   RTE_E_PostRadarProcessing_Detection_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Detection_Populate_Detection_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Detection_Populate_Detection_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Detection_Populate_Detection_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Test_PostRadarProcessing_Detection_Populate_Detection_Stream++;
   Detection_Stream_T *stream_ptr;
   Detection_Debug_Stream_T *det_debug_stream_ptr;

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Sp_Post_Proc_Buffer();
      if (NULL != p_ipc_d2m_msg)
      {
         stream_ptr           = (Detection_Stream_T *)&(p_ipc_d2m_msg->payload.det_data);
         det_debug_stream_ptr = (Detection_Debug_Stream_T *)&(p_ipc_d2m_msg->payload.det_debug_data);
#if (DOWNSELECTION_ENABLE == 1U)
         Down_selection_Stream_T *ds_stream_ptr = &(p_ipc_d2m_msg->payload.downselection_data);
#endif

         /* Send UDP streams */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(DETECTION, (uint8_t *)stream_ptr);
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(DETECTION_DEBUG, (uint8_t *)det_debug_stream_ptr);

#if (DOWNSELECTION_ENABLE == 1U)
         /* Calculate checksum */
         /*Calculate_Checksum((uint8_t *)ds_stream_ptr, sizeof(Down_selection_Stream_T));*/
         /* Send UDP streams */
         sh_output_data_ptr->sh_trigger_stream_handler_fptr(DOWN_SELECTION, (uint8_t *)ds_stream_ptr);
#endif
      }
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Header_Populate_Header_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Header_Stream> of PortPrototype <PostRadarProcessing_Header>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Header_Populate_Header_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Header_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Header_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Header_E_OK
 *   RTE_E_PostRadarProcessing_Header_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Header_Populate_Header_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Header_Populate_Header_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Header_Populate_Header_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr   = Get_SH_Output_Data_Ptr();
   Header_Stream_T *stream_ptr       = Get_Header_Stream_Ptr();
   HIL_Output_T *hil_output_data_ptr = Get_HIL_Output_Data_Ptr();

   Test_PostRadarProcessing_Header_Populate_Header_Stream++;
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      if ((CODED_TRUE == hil_output_data_ptr->hil_enabled_streams[HEADER]) &&
          (CODED_TRUE == hil_output_data_ptr->hil_mode_enabled))
      {
         HIL_Header_Bypass = true;
      }
      else
      {
         HIL_Header_Bypass = false;
         Populate_Header_Stream();
      }

      /* Trigger the stream handler for Header stream */
      sh_output_data_ptr->sh_trigger_stream_handler_fptr(HEADER, (uint8_t *)stream_ptr);
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_MMIC_Populate_MMIC_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_MMIC_Stream> of PortPrototype <PostRadarProcessing_MMIC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_MMIC_Populate_MMIC_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_MMIC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_NOT_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_OK
 *   RTE_E_PostRadarProcessing_MMIC_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_MMIC_Populate_MMIC_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_MMIC_Populate_MMIC_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_MMIC_Populate_MMIC_Stream (returns application error)
    *********************************************************************************************************************/

   D2M_Msg_T *p_ipc_d2m_msg = (D2M_Msg_T *)Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   M2D_Msg_T *p_ipc_m2d_msg = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   if ((NULL != p_ipc_d2m_msg) && (NULL != p_ipc_m2d_msg))
   {
      p_ipc_m2d_msg->payload.xcp_info.xcp_look_select = XCP_Look_Select;
      Test_PostRadarProcessing_MMIC_Populate_MMIC_Stream++;
      if (CODED_TRUE == Stream_Handler_En_XCP)
      {
         Populate_MMIC_Stream();
      }

      Trigger_XCP_DAQ(p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_id, XcpConf_XcpEventChannel_Xcp_Daq_Event_2_MMIC);
   }

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_RDD_Populate_RDD_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_RDD_Stream> of PortPrototype <PostRadarProcessing_RDD>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_RDD_Populate_RDD_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_RDD_E_NOT_OK
 *   RTE_E_PostRadarProcessing_RDD_E_NOT_OK
 *   RTE_E_PostRadarProcessing_RDD_E_OK
 *   RTE_E_PostRadarProcessing_RDD_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_RDD_Populate_RDD_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_RDD_Populate_RDD_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_RDD_Populate_RDD_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Test_PostRadarProcessing_RDD_Populate_RDD_Stream++;
   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      /* RDD stream shall be directly triggered by DSS later */
      D2M_Msg_T *p_ipc_d2m_msg = (D2M_Msg_T *)Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
      if (NULL != p_ipc_d2m_msg)
      {
         Rdd_Stream_T *stream_ptr             = &p_ipc_d2m_msg->payload.rdd_stream_data;
         Rdd_Debug_Stream_T *debug_stream_ptr = &p_ipc_d2m_msg->payload.rdd_debug_data;
         RDD_Stream_Err                       = Get_Stream_Error(RDD, 0U);
         RDD_Debug_Stream_Err                 = Get_Stream_Error(RDD_DEBUG, 0U);
         HIL_Output_T *hil_output_data_ptr    = Get_HIL_Output_Data_Ptr();
         uint8_t hil_active                   = hil_output_data_ptr->hil_mode_enabled;
         uint8_t *hil_enabled_streams         = hil_output_data_ptr->hil_enabled_streams;

         /**
          * Update checksum and size field.
          * This could also be moved to source DSS.
          * @note: For now checksum calc is disabled.
          * Need to check the timing impact once enabled.
          */
         /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Rdd_Stream_T)); */

         if ((CODED_TRUE != hil_active) || ((CODED_TRUE == hil_active) && ((CODED_TRUE != hil_enabled_streams[DETECTION]) ||
                                                                           (CODED_TRUE != hil_enabled_streams[DOWN_SELECTION]))))
         {
            /* Trigger RDD Stream handler */
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(RDD, (uint8_t *)stream_ptr);
         }
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(RDD_DEBUG, (uint8_t *)debug_stream_ptr);
      }
      /* Populate VSE stream */
      Populate_Vse_Stream();

#ifdef TRACKER_ENABLED
      Populate_Partner_Sensor_Stream();
#endif
   }

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Radar_Capability_Stream> of PortPrototype
 *<PostRadarProcessing_Radar_Capability>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_OK
 *   RTE_E_PostRadarProcessing_Radar_Capability_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Test_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream++;
   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Sp_Post_Proc_Buffer();
      if (NULL != p_ipc_d2m_msg)
      {
         Static_Alignment_Log_Stream_T *sa_stream_ptr =
            (Static_Alignment_Log_Stream_T *)&p_ipc_d2m_msg->payload.alignment_stream_data;
         Dynamic_Alignment_Log_Stream_T *dra_dtram_ptr =
            (Dynamic_Alignment_Log_Stream_T *)&p_ipc_d2m_msg->payload.dynamic_alignment_log_stream;
         Radar_Capability_Stream_T *rc_stream_ptr = (Radar_Capability_Stream_T *)&p_ipc_d2m_msg->payload.radar_capability_data;
         ID_Stream_T *id_stream_ptr               = (ID_Stream_T *)&p_ipc_d2m_msg->payload.interference_detection_data;
#if (DOWNSELECTION_ENABLE == 1U)
         TOI_DS_Stream_T *toi_ds_stream_ptr = (TOI_DS_Stream_T *)(&p_ipc_d2m_msg->payload.toi_ds_stream_data);
#else
         TOI_Stream_T *toi_stream_ptr = (TOI_Stream_T *)(&p_ipc_d2m_msg->payload.toi_stream_data);
#endif
         /* Commenting out checksum because memory write access don't have on IPC structures */
         /* Calculate checksum */
         /* Calculate_Checksum((uint8_t *)dra_dtram_ptr, sizeof(Dynamic_Alignment_Log_Stream_T)); */

         /* Trigger Alignment Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SRA, (uint8_t *)sa_stream_ptr);

         /* Trigger Radar Capability Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(RADAR_CAPABILITY, (uint8_t *)rc_stream_ptr);
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(ID, (uint8_t *)id_stream_ptr);

         /* Trigger Alignment Stream handler */
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(DRA, (uint8_t *)dra_dtram_ptr);

#if (DOWNSELECTION_ENABLE == 1U)
   #if (DOWNSELECTION_ENABLE == 1U)
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TOI_DS, (uint8_t *)toi_ds_stream_ptr);
   #else
         (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TOI, (uint8_t *)toi_stream_ptr);
   #endif
#endif

#ifdef TRACKER_ENABLED
         if (Is_Tracker_Stream_Applicable())
         {
            Set_Tracker_Stream_Ref_Index(p_ipc_d2m_msg->payload.emb_tracker_status.scan_index);

            Sync_Info_Stream_T *sync_info_stream_ptr = &p_ipc_d2m_msg->payload.sync_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SYNC_INFO, (uint8_t *)sync_info_stream_ptr);
            Vehicle_Info_Stream_T *vehicle_info_stream_ptr = &p_ipc_d2m_msg->payload.vehicle_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(VEHICLE_INFO, (uint8_t *)vehicle_info_stream_ptr);
            Tracker_Info_Stream_T *tracker_info_stream_ptr = &p_ipc_d2m_msg->payload.tracker_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TRACKER_INFO, (uint8_t *)tracker_info_stream_ptr);
            Timing_Info_Stream_T *timing_info_stream_ptr = &p_ipc_d2m_msg->payload.timing_info_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TIMING_INFO, (uint8_t *)timing_info_stream_ptr);
            Host_Calibs_Stream_T *host_calibs_stream_ptr = &p_ipc_d2m_msg->payload.host_calibs_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(HOST_CALIBS, (uint8_t *)host_calibs_stream_ptr);
            Host_Props_Stream_T *host_props_stream_ptr = &p_ipc_d2m_msg->payload.host_props_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(HOST_PROPS, (uint8_t *)host_props_stream_ptr);
            Static_Env_Poly_Stream_T *static_env_poly_stream_ptr = &p_ipc_d2m_msg->payload.static_env_poly_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(STATIC_ENV_POLY, (uint8_t *)static_env_poly_stream_ptr);
            Functional_Safety_Faults_Stream_T *functional_safety_faults_stream_ptr =
               &p_ipc_d2m_msg->payload.functional_safety_faults_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(FUNCTIONAL_SAFETY_FAULTS,
                                                                     (uint8_t *)functional_safety_faults_stream_ptr);
            Object_List_Stream_T *object_list_stream_ptr = &p_ipc_d2m_msg->payload.object_list_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(OBJECT_LIST, (uint8_t *)object_list_stream_ptr);
            Processed_Detection_Stream_T *processed_detection_stream_ptr = &p_ipc_d2m_msg->payload.processed_detection_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(PROCESSED_DETECTION,
                                                                     (uint8_t *)processed_detection_stream_ptr);
            Sensor_Calib_Stream_T *sensor_calib_stream_ptr = &p_ipc_d2m_msg->payload.sensor_calib_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(SENSOR_CALIB, (uint8_t *)sensor_calib_stream_ptr);
            Trailer_Detector_Stream_T *trailer_detector_stream_ptr = &p_ipc_d2m_msg->payload.trailer_detector_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(TRAILER_DETECTOR, (uint8_t *)trailer_detector_stream_ptr);
            Cv_Trailer_Stream_T *cv_trailer_stream_ptr = &p_ipc_d2m_msg->payload.cv_trailer_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(CV_TRAILER, (uint8_t *)cv_trailer_stream_ptr);

   #if ENABLE_INTERNAL_TRACKER_STREAMS
            Internal_Trailer_Detector_Stream_T *internal_trailer_detector_stream_ptr =
               &p_ipc_d2m_msg->payload.internal_trailer_detector_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_TRAILER_DETECTOR,
                                                                     (uint8_t *)internal_trailer_detector_stream_ptr);
            Internal_Object_Stream_T *internal_object_stream_ptr = &p_ipc_d2m_msg->payload.internal_object_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_OBJECT, (uint8_t *)internal_object_stream_ptr);
            Internal_Cluster_Stream_T *internal_cluster_stream_ptr = &p_ipc_d2m_msg->payload.internal_cluster_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_CLUSTER, (uint8_t *)internal_cluster_stream_ptr);
            Internal_Detection_Hist_Stream_T *internal_detection_hist_stream_ptr =
               &p_ipc_d2m_msg->payload.internal_detection_hist_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_DETECTION_HIST,
                                                                     (uint8_t *)internal_detection_hist_stream_ptr);
            Internal_Reflection_Buffer_Stream_T *internal_reflection_buffer_stream_ptr =
               &p_ipc_d2m_msg->payload.internal_reflection_buffer_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_REFLECTION_BUFFER,
                                                                     (uint8_t *)internal_reflection_buffer_stream_ptr);
            Internal_CWD_Stream_T *internal_cwd_stream_ptr = &p_ipc_d2m_msg->payload.internal_cwd_stream;
            (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(INTERNAL_CWD, (uint8_t *)internal_cwd_stream_ptr);
   #endif
         }
   #ifdef VEH_AL_CAN_STANDALONE
      #if defined(FEATURE_ENABLE)
         /* populate BSIS stream */
         Populate_BSIS_Stream();
         /* populate MOIS stream */
         Populate_MOIS_Stream();
         Populate_Olp_Stream();
      #endif
   #endif
#endif
      }
   }
   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PostRadarProcessing_Status_Populate_Status_Stream
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Populate_Status_Stream> of PortPrototype <PostRadarProcessing_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PostRadarProcessing_Status_Populate_Status_Stream(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_NOT_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *   RTE_E_PostRadarProcessing_Status_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PostRadarProcessing_Status_Populate_Status_Stream_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Status_Populate_Status_Stream(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: PostRadarProcessing_Status_Populate_Status_Stream (returns application error)
    * *********************************************************************************************************************/
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   D2M_Msg_T *p_ipc_d2m_msg        = (D2M_Msg_T *)Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   M2D_Msg_T *p_ipc_m2d_msg        = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   Status_Stream_T *stream_ptr     = Get_Status_Stream_Ptr();

   const void *ptr[] = {(const void *)p_ipc_d2m_msg, (const void *)p_ipc_m2d_msg};

   if (NULL_PTR_CHECK(ptr))
   {
      p_ipc_m2d_msg->payload.xcp_info.xcp_look_select = XCP_Look_Select;
      Trigger_XCP_DAQ(p_ipc_d2m_msg->payload.rdd_stream_data.look_data.look_id, XcpConf_XcpEventChannel_Xcp_Daq_Event_0_Post_RDD);
   }

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      Populate_Status_Stream();
      /* Trigger the stream handler for Status stream */
      sh_output_data_ptr->sh_trigger_stream_handler_fptr(STATUS, (uint8_t *)stream_ptr);
   }

   return (Std_ReturnType)RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_10ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_10ms
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_2ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_2ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_2ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_2ms
    *********************************************************************************************************************/
   uint16_t source_tx_cnt_start = GET_SOURCE_TX_CNT();

   GET_PLT_ETH_LOG_TIME(2ms);

   RE_2ms_Task_Cnt++;

#if (defined(CDC_ENABLE))
   #if defined(CDC_FRAME_SYNC_VERIFY)
   CDC_Stream_T *CDC_stream_ptr = NULL;
   #endif
   PduInfoType pduInfo;
   Cdc_Frame_Interface_T *cdc_interface_address = NULL;
   CDC_Stream_T *cdc_packet_base_addr           = NULL;
   C0_CDC_Transmitted_In_Cycle_Cnt              = 0U;

   /* Enable/Disable stream logging upon XCP request and Disable CDC when HIL is enabled */
   if ((CODED_TRUE == Stream_Handler_En_XCP) && (CODED_TRUE != *Get_Req_En_Dis_CDC_Stream()))
   {
      /* Start CDC Transmission logic */

      pduInfo.SduLength = ETH_DATA_PAYLOAD; /* Length of payload */
      if (EthIf_EthIfCtrlLinkState[0] != ETHIF_ETHIFCTRL_LINK_STATE_LINK)
      {
         return;
      }

      /* Read the interface once in an exclusive area */
      DisableAllInterrupts();
      cdc_interface_address = (Cdc_Frame_Interface_T *)Cdc_Frame_Interface_Addr;
      EnableAllInterrupts();

      if (NULL_PTR != cdc_interface_address)
      {
         cdc_packet_base_addr     = (CDC_Stream_T *)cdc_interface_address->cdc_enet_buffer_addr;
         C0_CDC_Radar_Frame_Reset = cdc_interface_address->cdc_radar_frame_reset;

         C0_CDC_Current_Index = cdc_interface_address->cdc_enet_packet_index;

         /* Three scenarios exist when reading CDC frame interface data during DSP and M7 core synchronization:
          * 1. New radar look/cycle started with last range bin data available (reset flag set, counter incremented)
          * 2. Same radar look/cycle continues with last range bin data received (reset flag set, counter unchanged)
          * 3. New radar look/cycle started but last range bin data not yet received (reset flag clear, counter incremented)
          */

         if (C0_CDC_Radar_Frame_Reset)
         { /* when new radar cycle/look detected: if reset flag (last rbin) is set AND interface index counter has changed */
            if (CDC_Prev_Interface_Index != cdc_interface_address->cdc_frame_interface_index)
            {
               C0_CDC_Enet_Buffer_Max_Depth = cdc_interface_address->cdc_enet_buffer_max_depth;
               /*reset frame interface flags*/
               Reset_CDC_Radar_Frame_Flags(cdc_interface_address);
            }
            else
            {
               /* Frame reset (last rbin) is within same radar_cycle/look period */
               C0_CDC_Enet_Buffer_Max_Depth = C0_CDC_Current_Index;
            }
         }
         /* Normal operation: no frame reset (last rbin), check for counter change indicating frame transition */
         else
         {
            C0_CDC_Enet_Buffer_Max_Depth = cdc_interface_address->cdc_enet_buffer_max_depth;
            /* when new radar cycle/look but still not set frame reset flag. */
            if (CDC_Prev_Interface_Index != cdc_interface_address->cdc_frame_interface_index)
            {
               /*reset the frame interface flags*/
               Reset_CDC_Radar_Frame_Flags(cdc_interface_address);
            }
            else
            {
               /* keep previous index */
            }
         }
         CDC_Prev_Interface_Index = cdc_interface_address->cdc_frame_interface_index;

         if (C0_CDC_Current_Index < C0_CDC_Previous_Index) /* Count for loop-around case */
         {
            /* Send positions until end of the circular buffer */
            Trigger_CDC_Frames(C0_CDC_Previous_Index, C0_CDC_Enet_Buffer_Max_Depth, cdc_packet_base_addr,
                               C0_CDC_Radar_Frame_Reset);

            /* Send from start of circular buffer until new filled index */
            Trigger_CDC_Frames(0U, C0_CDC_Current_Index, cdc_packet_base_addr, C0_CDC_Radar_Frame_Reset);
         }
         else /* if there is no looping around the circular buffer */
         {
            Trigger_CDC_Frames(C0_CDC_Previous_Index, C0_CDC_Current_Index, cdc_packet_base_addr, C0_CDC_Radar_Frame_Reset);
         }
      }
      else
      {
         /* Address has not been updated correctly from IPC. Do nothing */
      }

      if (C0_CDC_Transmitted_In_Cycle_Cnt > C0_CDC_Transmitted_In_Cycle_Cnt_Max)
      {
         C0_CDC_Transmitted_In_Cycle_Cnt_Max = C0_CDC_Transmitted_In_Cycle_Cnt;
      }

      C0_CDC_Previous_Index           = C0_CDC_Current_Index;
      C0_CDC_Transmitted_In_Cycle_Cnt = 0U;

      /* End CDC Transmission logic */
   }
#endif

   GET_PLT_ETH_LOG_ELAPSED_TIME(2ms, source_tx_cnt_start);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_50ms
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
 *   Std_ReturnType Rte_Read_Rp_AlignmentAuto_De_AlignmentAuto(Dt_AlignmentAuto *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentService_De_AlignmentService(Dt_AlignmentService *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentShortTrack_De_AlignmentShortTrack(Dt_AlignmentShortTrack *data)
 *   Std_ReturnType Rte_Read_Rp_AlignmentStatic_De_AlignmentStatic(Dt_AlignmentStatic *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_Handler_De_Alignment_Handler(Dt_Alignment_Handler *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(Dt_Alignment_M2D_Data *data)
 *   Std_ReturnType Rte_Read_Rp_CPU_Load_De_CPU_Load(Dt_CPU_Load *data)
 *   Std_ReturnType
 *Rte_Read_Rp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version(Crypto_CustomFunctions_VersionStruct *data)
 *   Std_ReturnType Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(Dt_FailSafe_ResetReason_T *data)
 *   Std_ReturnType Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_OperationModeType_De_OperationMode_System(Dt_SystemOperationMode *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis(uint8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Rtm_task_measurement_Operation(Dt_RTM_parameters_T *destination)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_50ms
    *********************************************************************************************************************/

   /* This flag shall be updated from the BSW's input - a flag indicating the communication is established
   Currently made true to indicate communication is enabled directly*/
   SH_Output_T *sh_output_data_ptr        = Get_SH_Output_Data_Ptr();
   static bool enable_tx                  = true;
   static uint8 XCP_Stop_PeriodicMessages = XCP_NORMAL_MSG;
   uint8_t streamTxRetValue               = REC_HANDLER_NOT_OK;
#if defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE)
   uint8_t streamTxRetValue2 = REC_HANDLER_NOT_OK;
#endif
   uint16_t source_tx_cnt_start = GET_SOURCE_TX_CNT();

   GET_PLT_ETH_LOG_TIME(50ms);

#ifndef DISBLE_STACK_MONITOR_R52
   volatile static uint16_t stack_monitor_execution_cycle = 50U;

   /* Executing Stack Monitoring at every 1 sec */
   if (STACK_MONITORING_CYCLE > stack_monitor_execution_cycle)
   {
      stack_monitor_execution_cycle += 50;
   }
   else
   {
      Stack_Monitor_R52();
      stack_monitor_execution_cycle = 50U;
   }
#endif

   if (enable_tx)
   {
      Set_Stream_Tx_Enable_Status(enable_tx);
   }

   /*EthEventHdlr();*/ /*Commented since autosar eth functions are used*/

   if (One_Time_Call)
   {
      RE_Logging_Init();
      One_Time_Call = 0U;
   }

   if (CODED_TRUE == Streams_Tx_Cfg_Apply)
   {
      Stream_Tx_Cfg_Apply_Retry_Count++; /* Increment the counter to apply stream Tx config in next cycle to avoid impacting
                                            current Tx */
      streamTxRetValue = Apply_Stream_Enable_Config(&Stream_Num_Bitfield[0], Stream_Tx_Enable_State);
#if defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE)
      /* Clear bit0 to indicate All streams are set default, and set the CDC stream bit to enable CDC stream */
      Clear_StreamNum_BitfieldBit(0U, &Stream_Num_Bitfield[0]);
      Set_StreamNum_BitfieldBit(CDC_STREAM_NUMBER, &Stream_Num_Bitfield[0]);
      streamTxRetValue2 = Apply_Stream_Enable_Config(&Stream_Num_Bitfield[0], STREAM_TX_ENABLE);
#endif
      if ((REC_HANDLER_OK == streamTxRetValue
#if defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE)
           && REC_HANDLER_OK == streamTxRetValue2
#endif
           ) ||
          (STREAM_TX_CFG_APPLY_MAX_ATTEMPTS >=
           Stream_Tx_Cfg_Apply_Retry_Count) /* Retry applying stream Tx config for STREAM_TX_CFG_APPLY_MAX_ATTEMPTS cycles in case
                                               of failure */
      )
      {
         Streams_Tx_Cfg_Apply            = CODED_FALSE;
         Stream_Tx_Cfg_Apply_Retry_Count = 0U;
      }
   }
   else
   {
      Stream_Tx_Cfg_Apply_Retry_Count = 0U;
   }

   Test_Re_50ms_Counter++;

   if (Get_Is_Doppler_Comp_RDD_Stream_Ready())
   {
      /* populate RDD stream */
      Set_Is_Doppler_Comp_RDD_Stream_Ready(false);
   }
   /*Read the RTE, if any request is made to stop periodic message Tx from XCP */
   (void)Rte_Read_Rp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis(&XCP_Stop_PeriodicMessages);
   if ((uint8)(XCP_STOP_MSG) == XCP_Stop_PeriodicMessages)
   {
      Stream_Handler_En_XCP = CODED_FALSE;
   }
   else
   {
      Stream_Handler_En_XCP = CODED_TRUE;
   }

   /* Enable/Disable stream logging upon XCP request */
   if (CODED_TRUE == Stream_Handler_En_XCP)
   {
      /* This stream can be triggered independently of radar cycle rate */
      sh_output_data_ptr->sh_trigger_stream_handler_fptr(CALIB, (uint8_t *)NULL);
   }

   GET_PLT_ETH_LOG_ELAPSED_TIME(50ms, source_tx_cnt_start);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_5ms
    *********************************************************************************************************************/

   uint16_t source_tx_cnt_start = GET_SOURCE_TX_CNT();

   GET_PLT_ETH_LOG_TIME(5ms);

   /* Periodic Stream handling */
   if (EthIf_EthIfCtrlLinkState[0] == ETHIF_ETHIFCTRL_LINK_STATE_LINK)
   {
      if (Test_Counter_StreamHandler < 500U)
      {
         Test_Counter_StreamHandler++;
      }
      else
      {
         Periodic_Stream_Handler();
      }
   }

   GET_PLT_ETH_LOG_ELAPSED_TIME(5ms, source_tx_cnt_start);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Logging_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Logging_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Logging_CODE) RE_Logging_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Logging_Init
    *********************************************************************************************************************/

   /* Initialize stream handler */
   Stream_Handler_Init_Params_T sh_ip;
   sh_ip.sensor_id     = (uint8_t)Get_Radar_Position();
   sh_ip.source_info   = (uint8_t)STREAM_SOURCE;       /*radar variant (Platform id)- Srr7p, flr8*/
   sh_ip.source_info1  = (uint8_t)SENSOR_RADAR;        /*sensor type - radar, lidar, camera etc.*/
   sh_ip.source_info2  = (uint8_t)Get_SMC_Cal_Minor(); /* customer ID info from SMC - BMW, CEER etc.*/
   sh_ip.tx_frame_fptr = SoAd_Frame_Transmit;

   Update_Stream_Handler_Input(&sh_ip);

   Update_SH_Input_Interface();

   Update_SH_Output_Interface();

#if defined(SH_ENABLE_CALIB_STREAM)
   Config_Calib_Stream();
#endif

#if (defined(CDC_ENABLE))
   Config_CDC_Stream();
#endif
#ifdef TRACKER_ENABLED
   Config_Tracker_Streams();
#endif
   /*Stream_Init_Cfg_T rdd_init_cfg = {(uint8_t)ALL_CHUNKS, STREAM_REGULAR_FAST, (uint8_t) true, 0U};
   (void)Stream_Config_Init(RDD, &rdd_init_cfg);*/
   Stream_Handler_Init();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TimeRecordBlock_Callback> of PortPrototype
 *<StbM_MeasurementNotification_StbMSynchronizedTimeBase>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback(const
 *StbM_SyncRecordTableBlockType *syncRecordTableBlock)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_StbM_MeasurementNotification_StbMSynchronizedTimeBase_E_NOT_OK
 *   RTE_E_StbM_MeasurementNotification_StbMSynchronizedTimeBase_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback(
   P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_DATA)
      syncRecordTableBlock) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback (returns application error)
    *********************************************************************************************************************/

   int16_t TimeStamp_delta
      __attribute__((__unused__)); /*Added unused attribute temporarily to be removed on Tomestamp_delta is populated in stream*/
   float32_t time_diff_us;
   int32_t time_diff_sec;

   /*Get the time difference of global and internal time in both seconds and MicroSeconds*/
   time_diff_sec = syncRecordTableBlock->GlbSeconds - syncRecordTableBlock->LocSeconds;
   time_diff_us  = (syncRecordTableBlock->GlbNanoSeconds - syncRecordTableBlock->LocNanoSeconds) * NS_2_US;

   if (time_diff_sec > 0)
   {
      time_diff_us += S_2_US;
   }
   else if (time_diff_sec < 0)
   {
      time_diff_us -= S_2_US;
   }
   else
   {
      /*Do Nothing*/
   }
   /*TimeStamp_delta should be in range  -32768.0f(INT16_MIN_F) and +32767.0f (INT16_MAX_F)*/
   /*Updating the max value to time stamp delta if greater than 32767*/
   if (time_diff_us > INT16_MAX_F)
   {
      TimeStamp_delta = (int16_t)INT16_MAX_F;
   }
   /*Updating the min value to time stamp delta if less than -32768*/
   else if (time_diff_us < INT16_MIN_F)
   {
      TimeStamp_delta = (int16_t)INT16_MIN_F;
   }
   else
   {
      TimeStamp_delta = (int16_t)time_diff_us;
   }

   return E_OK;

   /**********************************************************************************************************************
    * DO
     * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

     * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/
#if defined(SH_ENABLE_CALIB_STREAM)
/******************************************************************************
 *. Name: Config_Calib_Stream
 *.    Provide params to configure a calibration stream (Static stream)
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Config_Calib_Stream(void)
{
   // uint8_t config_result;
   Stream_Init_Cfg_T calib_init_cfg = {(uint8_t)CHUNK_1, STREAM_STATIC, (uint8_t) true, 0U};
   // config_result                    = Calib_Stream_Config_Init(&calib_init_cfg); //CSH
   (void)Calib_Stream_Config_Init(&calib_init_cfg);
   /*Use of config_result depends on application requirement*/
}
#endif
/******************************************************************************
 *. Name: Populate_Status_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Status_Stream(void)
{
#if 0
   uint8_t status_trigger_state;
#endif
   uint8_t sensor_location;
   static bool one_time_flag = true;
   Status_Stream_T *stream_ptr;
   stream_ptr = &Status_Stream;

   const Application_Version_T *app_version       = Get_Application_Version();
   const Bootloader_Version_T *bootloader_version = Get_Bootloader_Version();

   D2M_Msg_T *p_ipc_d2m_msg                           = Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_Onetime_Msg_Buffer();
   HIL_Output_T *hil_output_data_ptr                  = Get_HIL_Output_Data_Ptr();

   DT_Thermal_mon_mes_results_T thermal_mcu_temp;
   Update_Thermal_Monitor_Values(&thermal_mcu_temp);

   if (NULL != p_ipc_d2m_msg)
   {
      Look_Data_T *ipc_look_data_ptr      = &(p_ipc_d2m_msg->payload.rdd_stream_data.look_data);
      const Diag_Data_T *p_ipc_dsp_to_cm7 = &(p_ipc_d2m_msg->payload.diag_data);
      stream_ptr->stream_hdr.scan_index   = (uint16_t)ipc_look_data_ptr->scan_index;
      stream_ptr->scanindex               = (uint16_t)ipc_look_data_ptr->scan_index;
      stream_ptr->lookindex               = (uint16_t)ipc_look_data_ptr->look_index;
      stream_ptr->look_type               = (uint16_t)ipc_look_data_ptr->look_id;
      if (k_isUWB_smc[ipc_look_data_ptr->look_id])
      {
         stream_ptr->usc_SF_UFC = k_sensitivity_SF_USC_UWB_usc;
      }
      else
      {
         stream_ptr->usc_SF_UFC = k_sensitivity_SF_USC_USC;
      }

      stream_ptr->doppler_overrun_cnt = p_ipc_dsp_to_cm7->dfft_rdd_xput_overrun_cnt;
      stream_ptr->range_overrun_cnt   = p_ipc_dsp_to_cm7->rfft_xput_overrun_cnt;
   }
   else
   {
      stream_ptr->stream_hdr.scan_index = LOG_SIGNAL_INVALID_VALUE; /* Invalid value */

      stream_ptr->scanindex  = LOG_SIGNAL_INVALID_VALUE;
      stream_ptr->lookindex  = LOG_SIGNAL_INVALID_VALUE;
      stream_ptr->look_type  = LOG_SIGNAL_INVALID_VALUE;
      stream_ptr->usc_SF_UFC = LOG_SIGNAL_INVALID_VALUE;
   }

   HIL_Status_Bypass =
      ((CODED_TRUE == hil_output_data_ptr->hil_enabled_streams[STATUS]) && (CODED_TRUE == hil_output_data_ptr->hil_mode_enabled));

   if (!HIL_Status_Bypass)
   {
      if (one_time_flag)
      {
         stream_ptr->app_version_Info.output_type = app_version->output_type; /* SubVariant of SW: RADAR_SATELLITE/ RADAR_MASTER*/
         stream_ptr->app_version_Info.output_sub_type = app_version->output_sub_type; /* DET/OBJ/CDC    */
         stream_ptr->app_version_Info.veh_com_type    = app_version->veh_com_type;    /* Communication type CAN/ETH  etc   */
         stream_ptr->app_version_Info.board_type      = app_version->board_type;      /* Board type B3/A1/A2  etc  */

         stream_ptr->app_version_Info.generation   = app_version->generation; /* SW generation   eg: 7/8/9  */
         stream_ptr->app_version_Info.reserved     = app_version->rsvd;       /* reserved for future purpose.*/
         stream_ptr->app_version_Info.appl_type    = app_version->appl_type;  /* Radar Application type srr/flr/img etc*/
         stream_ptr->app_version_Info.appl_variant = app_version->variant;    /* Platform variant Eg: SRR7P, FLR7V2, FLR8 etc*/

         stream_ptr->app_version_Info.major_release_revision = app_version->major;   /* SW major revision */
         stream_ptr->app_version_Info.minor_release_revision = app_version->minor;   /* SW minor revision */
         stream_ptr->app_version_Info.patch_release_revision = app_version->patch;   /* SW patch revision */
         stream_ptr->app_version_Info.pre_release_revision   = app_version->pre_rel; /* SW pre-release    */
         stream_ptr->customer_info.customer_id               = Get_SMC_Cal_Minor();  /*Customer ID Eg: CEER/BMW ect*/
         stream_ptr->customer_info.customer_my      = LOG_SIG_NOT_IMPLEMENTED; /*Customer_Model_Year MY25/MY26/SP25/SP26 ect*/
         stream_ptr->customer_info.customer_variant = LOG_SIG_NOT_IMPLEMENTED; /*customer_Variant LOW/MID/HIGH*/

         stream_ptr->stream_hdr.version = STATUS_STREAM_VERSION;
         stream_ptr->stream_hdr.size    = sizeof(Status_Stream_T);

         stream_ptr->software_version_gen     = app_version->generation;
         stream_ptr->software_version_variant = app_version->variant;
         stream_ptr->software_version_maj     = app_version->major;
         stream_ptr->software_version_min     = app_version->minor;
         stream_ptr->software_version_patch   = app_version->patch;
         stream_ptr->software_version_pre_rel = app_version->pre_rel;

         stream_ptr->pbl_version_maj   = bootloader_version->major;
         stream_ptr->pbl_version_min   = bootloader_version->minor;
         stream_ptr->pbl_version_patch = bootloader_version->patch;

         stream_ptr->usc_version_major    = Get_USC_Cal_Major();
         stream_ptr->usc_version_minor    = Get_USC_Cal_Minor();
         stream_ptr->usc_version_patch    = Get_USC_Cal_Patch();
         stream_ptr->usc_version_platform = Get_USC_Cal_Platform();

         stream_ptr->sts_serial_num_julian_day  = k_Julian_Production_Date_USC;
         stream_ptr->sts_serial_num_julian_year = k_Julian_Year_USC;
         stream_ptr->sts_serial_number_sequence = k_Mfg_Sequence_Number_USC;

         stream_ptr->smc_version_major    = Get_SMC_Cal_Major();
         stream_ptr->smc_version_minor    = Get_SMC_Cal_Minor();
         stream_ptr->smc_version_patch    = Get_SMC_Cal_Patch();
         stream_ptr->smc_version_platform = Get_SMC_Cal_Platform();

         stream_ptr->usc_load_status = Get_Cal_Load_Status((Log_Cal_Src_T)USC);

         stream_ptr->smc_load_status = Get_Cal_Load_Status((Log_Cal_Src_T)SMC);

         stream_ptr->stream1_version = (uint8_t)DETECTION_STREAM_VERSION;
         stream_ptr->stream2_version = (uint8_t)HEADER_STREAM_VERSION;
         stream_ptr->stream3_version = (uint8_t)STATUS_STREAM_VERSION;
         stream_ptr->stream4_version = (uint8_t)RDD_STREAM_VERSION;

         stream_ptr->stream5_version = (uint8_t)VSE_STREAM_VERSION;

         stream_ptr->stream6_version = (uint8_t)MMIC_STREAM_VERSION;

         /* Sensor Position */
         sensor_location                   = (uint8_t)(Get_Radar_Position() - 1u);
         stream_ptr->sensor_mount_location = Get_Radar_Position();
         if (NULL != m2d_one_time_init_ptr)
         {
            stream_ptr->sensor_mount_ornt_yaw =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw;
            stream_ptr->sensor_mount_ornt_pitch =
               m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch;
            stream_ptr->sensor_mount_ornt_roll =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll;
            stream_ptr->sensor_mount_pos_x =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x;
            stream_ptr->sensor_mount_pos_y =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y;
            stream_ptr->sensor_mount_pos_z =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z;
            stream_ptr->sensor_height =
               (float32_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height;

            /*Calculate the polarity based on roll*/
            stream_ptr->sensor_polarity =
               ((int8_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll < 0.1F ?
                   (int8_t)(1) :
                   (int8_t)(-1));

            stream_ptr->sensor_long_offset =
               (float32_t)m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
         }
         else
         {
            /*No sensor position data available*/
            stream_ptr->sensor_mount_ornt_yaw   = 0.0F;
            stream_ptr->sensor_mount_ornt_pitch = 0.0F;
            stream_ptr->sensor_mount_ornt_roll  = 0.0F;
            stream_ptr->sensor_mount_pos_x      = 0.0F;
            stream_ptr->sensor_mount_pos_y      = 0.0F;
            stream_ptr->sensor_mount_pos_z      = 0.0F;
            stream_ptr->sensor_height           = 0.0F;
            stream_ptr->sensor_polarity         = (int8_t)1;
            stream_ptr->sensor_long_offset      = 0.0F;
         }

         stream_ptr->radar_ethernet = k_sensor_ethernet_lsb_list_smc[sensor_location];

         stream_ptr->platform_variant = Get_SMC_Cal_Platform();

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
         /* Fascia Compensation Params */
         stream_ptr->fc_params.fc_enable = m2d_one_time_init_ptr->fascia_compensation_params.axis_enable;
   #if (AF_MAX_NUM_FASCIA_COEF > FC_COEF_MAX_NUMBER)
      #error Status Stream FC_COEF_MAX_NUMBER not large enough to contain AF_MAX_NUM_FASCIA_COEF)
   #endif
         memset(stream_ptr->fc_params.az_coefficients, 0, sizeof(stream_ptr->fc_params.az_coefficients));
         memset(stream_ptr->fc_params.el_coefficients, 0, sizeof(stream_ptr->fc_params.el_coefficients));
         memcpy(stream_ptr->fc_params.az_coefficients,
                (const void *)m2d_one_time_init_ptr->fascia_compensation_params.az_coefficients,
                sizeof(float32_t) * AF_MAX_NUM_FASCIA_COEF);
         memcpy(stream_ptr->fc_params.el_coefficients,
                (const void *)m2d_one_time_init_ptr->fascia_compensation_params.el_coefficients,
                sizeof(float32_t) * AF_MAX_NUM_FASCIA_COEF);
#endif

         one_time_flag = false;
      }

#if 0
      stream_ptr->range_overrun_cnt = spt_errors.range_overrun_cnt;
      stream_ptr->doppler_overrun_cnt = spt_errors.doppler_overrun_cnt;
      stream_ptr->chirp_out_of_sync_cnt = spt_errors.chirp_out_of_sync_cnt;

      stream_ptr->evt_disp_overrun_cnt = p_ipc_dsp_to_cm7->ipc_evt_disp_overrun_cnt;
      stream_ptr->ipc_dsp_to_sram_cnt = p_ipc_dsp_to_cm7->IPC_DSP_To_CM70_Header.counter;
      stream_ptr->ipc_cm7_to_dsp_err_cnt = p_ipc_dsp_to_cm7->ipc_cm7_to_dsp_err_cnt;
#endif
      stream_ptr->radar_post_daq_count = 0U; // radar_post_daq_count;
      stream_ptr->radar_post_rdd_count = 0U; // radar_post_rdd_count;
      stream_ptr->mode_trig_count      = 0U; /*mode_trig_count*/

      /* Need to ensure the address received is non-zero */
      stream_ptr->ipc_dsp_smc_incompatibilty_error = 0U; // p_ipc_dsp_to_cm7->ipc_dsp_smc_incompatibilty_error;
#if 0
      stream_ptr->range_overrun = spt_errors.range_overrun;
      stream_ptr->doppler_overrun = spt_errors.doppler_overrun;
      stream_ptr->chirp_out_of_sync = spt_errors.chirp_out_of_sync;
      stream_ptr->heartbeat_count = Heartbeat_counter;
#endif

      stream_ptr->mmic_temp_rx0       = (int16_t)Get_MMIC_Temp_Rx0();
      stream_ptr->mmic_temp_pvt_tsens = (int16_t)Get_MMIC_Temp_PVT_TSENS();
      stream_ptr->mmic_temp_rx2       = 0U;
      stream_ptr->mmic_temp_rx3       = 0U;
      stream_ptr->mmic_temp_tx0       = (int16_t)Get_MMIC_Temp_Tx0();
      stream_ptr->mmic_temp_tx1       = (int16_t)Get_MMIC_Temp_Tx1();
      stream_ptr->mmic_temp_tx2       = (int16_t)Get_MMIC_Temp_Tx2();
      stream_ptr->mmic_temp_tx3       = (int16_t)Get_MMIC_Temp_Tx3();
      stream_ptr->mmic_temp_pm        = (int16_t)Get_MMIC_Temp_PVT();
      /* Populate temperatures */
      stream_ptr->dsp_temp = 0; //(int16_t)Get_On_Chip_Temp_Dsp();
      stream_ptr->hwa_temp = 0; //(int16_t)Get_On_Chip_Temp_Hwa();
      stream_ptr->hsm_temp = 0; //(int16_t)Get_On_Chip_Temp_Hsm();

      stream_ptr->radar_position = Get_Radar_Position();

      /*Calibration parameters*/
      stream_ptr->usc_ADP_serial_number = k_ADP_Serial_Number_USC;
      stream_ptr->usc_peak_SNR          = k_Peak_SNR_USC;

      for (uint8_t idx = 0; idx < NUM_THERMAL_SENSORS; idx++)
      {
         stream_ptr->thermal_mcu_temp.immediate_temp_c[idx] = thermal_mcu_temp.immediate_temp_c.temperature[idx];
         stream_ptr->thermal_mcu_temp.average_temp_c[idx]   = thermal_mcu_temp.average_temp_c.temperature[idx];
         stream_ptr->thermal_mcu_temp.immediate_temp_f[idx] = thermal_mcu_temp.immediate_temp_f.temperature[idx];
         stream_ptr->thermal_mcu_temp.average_temp_f[idx]   = thermal_mcu_temp.average_temp_f.temperature[idx];
      }

      stream_ptr->divide_by_zero_count_r52     = Ubsan_Divzero_Count;
      stream_ptr->divide_by_zero_caller_lr_r52 = Ubsan_Divzero_Caller_LR;

      stream_ptr->fc_params.K_Unused16_1 = (uint16_t)MMIC_Not_Configured_Error;
      stream_ptr->fc_params.K_Unused8_1  = (uint8_t)Get_Radar_Ctl_State();
   }
}

/******************************************************************************
 *. Name: populate_alignment_data
 *.
 *. Populates all alignment sub-fields of the header stream.
 *. Extracted from Populate_Header_Stream to reduce cyclomatic complexity.
 *.
 *. Parameters: stream_ptr, alignment data source pointers
 *. Return Value: void
 ******************************************************************************/
static void Populate_Alignment_Data(Header_Stream_T *stream_ptr)
{
   Dt_Alignment_M2D_Data alignment_m2d_data         = {0};
   Dt_Alignment_Handler alignment_handler_data      = {0};
   Dt_AlignmentService alignment_service_data       = {0};
   Dt_AlignmentShortTrack alignment_shorttrack_data = {0};
   Dt_AlignmentAuto alignment_auto_data             = {0};
   Dt_AlignmentStatic alignment_static_data         = {0};
   (void)Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(&alignment_m2d_data);
   (void)Rte_Read_Rp_Alignment_Handler_De_Alignment_Handler(&alignment_handler_data);
   (void)Rte_Read_Rp_AlignmentService_De_AlignmentService(&alignment_service_data);
   (void)Rte_Read_Rp_AlignmentShortTrack_De_AlignmentShortTrack(&alignment_shorttrack_data);
   (void)Rte_Read_Rp_AlignmentAuto_De_AlignmentAuto(&alignment_auto_data);
   (void)Rte_Read_Rp_AlignmentStatic_De_AlignmentStatic(&alignment_static_data);

   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultAz = alignment_handler_data.InitialAlignmentResultAz;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultEl = alignment_handler_data.InitialAlignmentResultEl;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultHostSCF =
      alignment_handler_data.InitialAlignmentResultHostSCF;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultAzUpdates =
      alignment_handler_data.InitialAlignmentResultAzUpdates;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultElUpdates =
      alignment_handler_data.InitialAlignmentResultElUpdates;
   stream_ptr->alignment_data.AlignmentHandler.AlignmentAzimuth           = alignment_handler_data.AlignmentAzimuth;
   stream_ptr->alignment_data.AlignmentHandler.AlignmentElevation         = alignment_handler_data.AlignmentElevation;
   stream_ptr->alignment_data.AlignmentHandler.AzimuthStd                 = alignment_handler_data.AzimuthStd;
   stream_ptr->alignment_data.AlignmentHandler.ElevationStd               = alignment_handler_data.ElevationStd;
   stream_ptr->alignment_data.AlignmentHandler.calTime                    = alignment_handler_data.calTime;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultRoll = alignment_handler_data.InitialAlignmentResultRoll;
   stream_ptr->alignment_data.AlignmentHandler.InitialAlignmentResultRollUpdates =
      alignment_handler_data.InitialAlignmentResultRollUpdates;
   stream_ptr->alignment_data.AlignmentHandler.AlignmentRoll    = alignment_handler_data.AlignmentRoll;
   stream_ptr->alignment_data.AlignmentHandler.CalDisplay       = alignment_handler_data.CalDisplay;
   stream_ptr->alignment_data.AlignmentHandler.ProgressPercent  = alignment_handler_data.ProgressPercent;
   stream_ptr->alignment_data.AlignmentHandler.AlignmentError   = alignment_handler_data.AlignmentError;
   stream_ptr->alignment_data.AlignmentHandler.ElevationQuality = alignment_handler_data.ElevationQuality;
   stream_ptr->alignment_data.AlignmentHandler.AzimuthQuality   = alignment_handler_data.AzimuthQuality;
   stream_ptr->alignment_data.AlignmentHandler.Alignment_modeIn = alignment_handler_data.Alignment_modeIn;
   stream_ptr->alignment_data.AlignmentHandler.AlignmentModeOut = alignment_handler_data.AlignmentModeOut;
   stream_ptr->alignment_data.AlignmentHandler.InitialLastSuccessAlignmentMode =
      alignment_handler_data.InitialLastSuccessAlignmentMode;
   stream_ptr->alignment_data.AlignmentHandler.Radar_Type_Input       = alignment_handler_data.Radar_Type_Input;
   stream_ptr->alignment_data.AlignmentHandler.CoordinateSystem_Input = alignment_handler_data.CoordinateSystem_Input;

   stream_ptr->alignment_data.AlignmentService.DistanceAbsolute = alignment_service_data.DistanceAbsolute;
   stream_ptr->alignment_data.AlignmentService.DistanceEffective =
      alignment_service_data.DistanceEffective; /*Distance excluding PAUSE*/
   stream_ptr->alignment_data.AlignmentService.AvgNumOfDet      = alignment_service_data.AvgNumOfDet;
   stream_ptr->alignment_data.AlignmentService.DurationAbsolute = alignment_service_data.DurationAbsolute;
   stream_ptr->alignment_data.AlignmentService.DurationEffective =
      alignment_service_data.DurationEffective; /*Time excluding PAUSE*/
   stream_ptr->alignment_data.AlignmentService.AverageSpeed       = alignment_service_data.AverageSpeed;
   stream_ptr->alignment_data.AlignmentService.AlignmentServiceSt = alignment_service_data.AlignmentServiceSt;
   stream_ptr->alignment_data.AlignmentService.VehicleCondition   = alignment_service_data.VehicleCondition;

   stream_ptr->alignment_data.AlignmentShortTrack.AlignShortTrackSt = alignment_shorttrack_data.AlignShortTrackSt;

   stream_ptr->alignment_data.AlignmentAuto.StartAzimuth               = alignment_auto_data.StartAzimuth;
   stream_ptr->alignment_data.AlignmentAuto.StartElevation             = alignment_auto_data.StartElevation;
   stream_ptr->alignment_data.AlignmentAuto.AACurrentAzimuth           = alignment_auto_data.AACurrentAzimuth;
   stream_ptr->alignment_data.AlignmentAuto.AACurrentElevation         = alignment_auto_data.AACurrentElevation;
   stream_ptr->alignment_data.AlignmentAuto.AAAzimuthStd               = alignment_auto_data.AAAzimuthStd;
   stream_ptr->alignment_data.AlignmentAuto.AAElevationStd             = alignment_auto_data.AAElevationStd;
   stream_ptr->alignment_data.AlignmentAuto.Az_Err_positive            = alignment_auto_data.Az_Err_positive;
   stream_ptr->alignment_data.AlignmentAuto.Az_Err_negative            = alignment_auto_data.Az_Err_negative;
   stream_ptr->alignment_data.AlignmentAuto.El_Err_positive            = alignment_auto_data.El_Err_positive;
   stream_ptr->alignment_data.AlignmentAuto.El_Err_negative            = alignment_auto_data.El_Err_negative;
   stream_ptr->alignment_data.AlignmentAuto.RollError_positive         = alignment_auto_data.RollError_positive;
   stream_ptr->alignment_data.AlignmentAuto.RollError_negative         = alignment_auto_data.RollError_negative;
   stream_ptr->alignment_data.AlignmentAuto.HostScf                    = alignment_auto_data.HostScf;
   stream_ptr->alignment_data.AlignmentAuto.AzimuthNumUpdates          = alignment_auto_data.AzimuthNumUpdates;
   stream_ptr->alignment_data.AlignmentAuto.ElevationNumUpdates        = alignment_auto_data.ElevationNumUpdates;
   stream_ptr->alignment_data.AlignmentAuto.StartRoll                  = alignment_auto_data.StartRoll;
   stream_ptr->alignment_data.AlignmentAuto.AACurrentRoll              = alignment_auto_data.AACurrentRoll;
   stream_ptr->alignment_data.AlignmentAuto.RollUpdates                = alignment_auto_data.RollUpdates;
   stream_ptr->alignment_data.AlignmentAuto.AutoAlignmentFailRootCause = alignment_auto_data.AutoAlignmentFailRootCause;
   stream_ptr->alignment_data.AlignmentAuto.AlignAutoStatus            = alignment_auto_data.AlignAutoStatus;
   stream_ptr->alignment_data.AlignmentAuto.HostScf_QF                 = alignment_auto_data.HostScf_QF;

   stream_ptr->alignment_data.AlignmentStatic.MeasuredAzimuth       = alignment_static_data.MeasuredAzimuth;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredElevation     = alignment_static_data.MeasuredElevation;
   stream_ptr->alignment_data.AlignmentStatic.Measured_Az_Std       = alignment_static_data.Measured_Az_Std;
   stream_ptr->alignment_data.AlignmentStatic.Measured_El_Std       = alignment_static_data.Measured_El_Std;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredRange         = alignment_static_data.MeasuredRange;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredRangeStd      = alignment_static_data.MeasuredRangeStd;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredRangeRate     = alignment_static_data.MeasuredRangeRate;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredRangeRateStd  = alignment_static_data.MeasuredRangeRateStd;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredAmplitude     = alignment_static_data.MeasuredAmplitude;
   stream_ptr->alignment_data.AlignmentStatic.MeasuredAmpStd        = alignment_static_data.MeasuredAmpStd;
   stream_ptr->alignment_data.AlignmentStatic.AlignmentStaticStatus = alignment_static_data.AlignmentStaticStatus;
   stream_ptr->alignment_data.AlignmentStatic.StatusOfPlate         = alignment_static_data.StatusOfPlate;
   stream_ptr->alignment_data.AlignmentStatic.StatusOfAzimuth       = alignment_static_data.StatusOfAzimuth;
   stream_ptr->alignment_data.AlignmentStatic.StatusOfElevation     = alignment_static_data.StatusOfElevation;
   stream_ptr->alignment_data.AlignmentStatic.ImpactByInterference  = alignment_static_data.ImpactByInterference;

   stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated =
      alignment_m2d_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_speed_compensation_factor =
      alignment_m2d_data.dynamic_alignment_data.initial_speed_compensation_factor;
   stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_az =
      alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_az;
   stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_el_sky =
      alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_sky;
   stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_el_ground =
      alignment_m2d_data.dynamic_alignment_data.max_abs_misalignment_el_ground;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_az =
      alignment_m2d_data.dynamic_alignment_data.initial_num_updates_az;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_el =
      alignment_m2d_data.dynamic_alignment_data.initial_num_updates_el;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_rl =
      alignment_m2d_data.dynamic_alignment_data.initial_num_updates_rl;
   stream_ptr->alignment_data.dynamic_alignment_data.short_track_target_height =
      alignment_m2d_data.dynamic_alignment_data.short_track_target_height;
   stream_ptr->alignment_data.dynamic_alignment_data.short_track_target_range_rate =
      alignment_m2d_data.dynamic_alignment_data.short_track_target_range_rate;
   stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[0] =
      alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[0];
   stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[1] =
      alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[1];
   stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[2] =
      alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[2];
   stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[3] =
      alignment_m2d_data.dynamic_alignment_data.az_scf_kf_covariance[3];
   stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[0] =
      alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[0];
   stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[1] =
      alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[1];
   stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[2] =
      alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[2];
   stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[3] =
      alignment_m2d_data.dynamic_alignment_data.el_roll_kf_covariance[3];
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_x_posn =
      alignment_m2d_data.dynamic_alignment_data.iso_sensor_x_posn;
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_y_posn =
      alignment_m2d_data.dynamic_alignment_data.iso_sensor_y_posn;
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_z_posn =
      alignment_m2d_data.dynamic_alignment_data.iso_sensor_z_posn;
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_yaw   = alignment_m2d_data.dynamic_alignment_data.iso_sensor_yaw;
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_pitch = alignment_m2d_data.dynamic_alignment_data.iso_sensor_pitch;
   stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_roll  = alignment_m2d_data.dynamic_alignment_data.iso_sensor_roll;
   stream_ptr->alignment_data.dynamic_alignment_data.distance_rear_axle_to_front_bumper =
      alignment_m2d_data.dynamic_alignment_data.distance_rear_axle_to_front_bumper;
   stream_ptr->alignment_data.dynamic_alignment_data.alignment_handler_out.auto_align_status =
      alignment_m2d_data.dynamic_alignment_data.auto_align_status;
   stream_ptr->alignment_data.dynamic_alignment_data.alignment_handler_out.aacurrent_azimuth =
      alignment_m2d_data.dynamic_alignment_data.aacurrent_azimuth;
   stream_ptr->alignment_data.dynamic_alignment_data.alignment_handler_out.aacurrent_elevation =
      alignment_m2d_data.dynamic_alignment_data.aacurrent_elevation;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_align_quality_factor_az =
      alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_az;
   stream_ptr->alignment_data.dynamic_alignment_data.initial_align_quality_factor_el =
      alignment_m2d_data.dynamic_alignment_data.initial_align_quality_factor_el;
   stream_ptr->alignment_data.dynamic_alignment_data.align_cmd = alignment_m2d_data.dynamic_alignment_data.align_cmd;
   stream_ptr->alignment_data.dynamic_alignment_data.short_track_exit_condition =
      alignment_m2d_data.dynamic_alignment_data.short_track_exit_condition;
   stream_ptr->alignment_data.dynamic_alignment_data.mount_loc = alignment_m2d_data.dynamic_alignment_data.mount_loc;
   stream_ptr->alignment_data.dynamic_alignment_data.coordinate_system_input =
      alignment_m2d_data.dynamic_alignment_data.coordinate_system_input;
   stream_ptr->alignment_data.dynamic_alignment_data.f_data_valid = alignment_m2d_data.dynamic_alignment_data.f_data_valid;
   stream_ptr->alignment_data.dynamic_alignment_data.operation_mode_status =
      alignment_m2d_data.dynamic_alignment_data.Align_RadarOperation_Mode;

   stream_ptr->alignment_data.static_alignment_data.yaw   = alignment_m2d_data.static_alignment_data.yaw;
   stream_ptr->alignment_data.static_alignment_data.pitch = alignment_m2d_data.static_alignment_data.pitch;
   stream_ptr->alignment_data.static_alignment_data.plate_angle_deg_scs =
      alignment_m2d_data.static_alignment_data.plate_angle_deg_scs;
   stream_ptr->alignment_data.static_alignment_data.plate_distance = alignment_m2d_data.static_alignment_data.plate_distance;
   stream_ptr->alignment_data.static_alignment_data.polarity       = alignment_m2d_data.static_alignment_data.polarity;
   stream_ptr->alignment_data.static_alignment_data.horz_angle_min = alignment_m2d_data.static_alignment_data.horz_angle_min;
   stream_ptr->alignment_data.static_alignment_data.horz_angle_max = alignment_m2d_data.static_alignment_data.horz_angle_max;
   stream_ptr->alignment_data.static_alignment_data.vert_angle_min = alignment_m2d_data.static_alignment_data.vert_angle_min;
   stream_ptr->alignment_data.static_alignment_data.vert_angle_max = alignment_m2d_data.static_alignment_data.vert_angle_max;
   stream_ptr->alignment_data.static_alignment_data.plate_lat_position =
      alignment_m2d_data.static_alignment_data.plate_lat_position;
   stream_ptr->alignment_data.static_alignment_data.mount_loc    = alignment_m2d_data.static_alignment_data.mount_loc;
   stream_ptr->alignment_data.static_alignment_data.align_cmd    = alignment_m2d_data.static_alignment_data.align_cmd;
   stream_ptr->alignment_data.static_alignment_data.f_data_valid = alignment_m2d_data.static_alignment_data.f_data_valid;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   Rte_Read_Rp_AlignmentAuto_De_AlignmentAuto(&AlignmentAuto_Data);
   Rte_Read_Rp_AlignmentService_De_AlignmentService(&AlignmentService_Data);
   Rte_Read_Rp_AlignmentShortTrack_De_AlignmentShortTrack(&AlignmentShortTrack_Data);
   Rte_Read_Rp_AlignmentStatic_De_AlignmentStatic(&AlignmentStatic_Data);
   Rte_Read_Rp_Alignment_Handler_De_Alignment_Handler(&AlignmentHandler_Data);
   Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(&Alignment_M2D_Data);
#endif
}

/******************************************************************************
 *. Name: Populate_Header_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Header_Stream(void)
{
   Header_Stream_T *stream_ptr;
   Dt_FailSafe_ResetReason_T plt_reset_reason_local;
   stream_ptr = &Header_Stream;
   uint8_t operation_mode;

   D2M_Msg_T *p_ipc_d2m_msg = (D2M_Msg_T *)Get_IPC_D2M_Sp_Post_Proc_Buffer();

   Platform_fault_T *SWC_PLT_Appl_Active_Table_Local = Get_Platform_Active_Fault_Table();

   /* TODO: Remove after Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable */
   Customer_fault_T *History_Fault_Table_Local = Get_SWC_Appl_History_Fault_Table();

   float32_t bbe_overall_idle_xput;
   static float32_t bbe_overall_idle_xput_peak = 0.0F;

   if ((NULL != p_ipc_d2m_msg))
   {
      Rdd_Stream_T *ipc_rdd_log_ptr    = &p_ipc_d2m_msg->payload.rdd_stream_data;
      RDD_Data_T *p_ipc_d2m_rdd_data   = &(ipc_rdd_log_ptr->rdd_data);
      DSP_Timing_Data_T *p_timing_data = &p_ipc_d2m_msg->payload.dsp_timing_data;
#if 0
   Radar_TimeSync_Info_Status_T* p_temp_ts_status = Get_Radar_TimeSync_Info_Status_Ptr();
   TS_Current_Time_T* p_data_acq_time = Get_TS_Current_Time(TS_READ_START_DATA_ACQ);
   TS_Current_Time_T* p_data_dwell_time = Get_TS_Current_Time(TS_READ_DWELL_TIME);
   VCAN_Rx_Signals_T* vcan_rx_signals =  Get_VCAN_Rx_Signals();
#endif

      stream_ptr->xput_info.data_cache_info.cache_hit_count            = p_timing_data->data_cache_info.cache_hit_count;
      stream_ptr->xput_info.data_cache_info.cache_miss_count           = p_timing_data->data_cache_info.cache_miss_count;
      stream_ptr->xput_info.data_cache_info.cache_hit_count_max        = p_timing_data->data_cache_info.cache_hit_count_max;
      stream_ptr->xput_info.data_cache_info.cache_miss_count_max       = p_timing_data->data_cache_info.cache_miss_count_max;
      stream_ptr->xput_info.instruction_cache_info.cache_hit_count     = p_timing_data->instruction_cache_info.cache_hit_count;
      stream_ptr->xput_info.instruction_cache_info.cache_miss_count    = p_timing_data->instruction_cache_info.cache_miss_count;
      stream_ptr->xput_info.instruction_cache_info.cache_hit_count_max = p_timing_data->instruction_cache_info.cache_hit_count_max;
      stream_ptr->xput_info.instruction_cache_info.cache_miss_count_max =
         p_timing_data->instruction_cache_info.cache_miss_count_max;

      stream_ptr->xput_info.idle_xput_inst = (float32_t)p_timing_data->state_profiling[IDLE].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.idle_xput_peak = (float32_t)p_timing_data->state_profiling[IDLE].maxRuntime * (float)US_2_MS;

      /*Some of the below member of RDD Structure should be defined*/
      stream_ptr->xput_info.RDD_xput_inst =
         (float32_t)p_timing_data->state_profiling[DOPPLER_AND_RDD_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.RDD_xput_peak =
         (float32_t)p_timing_data->state_profiling[DOPPLER_AND_RDD_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.bbe_stl_xput_inst =
         (float32_t)p_timing_data->state_profiling[FUSA_BBE_SELF_TEST_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.bbe_stl_xput_peak =
         (float32_t)p_timing_data->state_profiling[FUSA_BBE_SELF_TEST_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.RFFT_xput_inst =
         (float32_t)p_timing_data->state_profiling[RANGE_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.RFFT_xput_peak =
         (float32_t)p_timing_data->state_profiling[RANGE_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.chirping_time_inst =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.range_process_time.lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.chirping_time_peak =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.range_process_time.maxRuntime * (float)US_2_MS;

      // copy anglefinding timing structure to the stream
      // these timestamps are in seconds instead of ms and represent the time taken as computed
      // internally within the angle-finding process, itself
      memcpy(&stream_ptr->xput_info.af_time, &p_timing_data->af_time, sizeof(stream_ptr->xput_info.af_time));
      // these timestamps come from the state-machine wrapper
      // so they include some additional overhead from initializing the AF inputs
      stream_ptr->xput_info.af_xput_inst =
         (float32_t)p_timing_data->state_profiling[ANGLE_FINDING_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.af_xput_peak =
         (float32_t)p_timing_data->state_profiling[ANGLE_FINDING_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.rc_xput_inst =
         (float32_t)p_timing_data->state_profiling[RADAR_CAPABILITY_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.rc_xput_peak =
         (float32_t)p_timing_data->state_profiling[RADAR_CAPABILITY_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.id_xput_inst =
         (float32_t)p_timing_data->state_profiling[INTERFERENCE_DETECTION_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.id_xput_peak =
         (float32_t)p_timing_data->state_profiling[INTERFERENCE_DETECTION_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.alignment_xput_inst =
         (float32_t)p_timing_data->state_profiling[TOI_ALIGNMENT_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.alignment_xput_peak =
         (float32_t)p_timing_data->state_profiling[TOI_ALIGNMENT_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.tracker_xput_inst =
         (float32_t)p_timing_data->state_profiling[TRACKER_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.tracker_xput_peak =
         (float32_t)p_timing_data->state_profiling[TRACKER_PROCESSING].maxRuntime * (float)US_2_MS;
      stream_ptr->xput_info.feature_xput_inst =
         (float32_t)p_timing_data->state_profiling[FEATURE_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.feature_xput_peak =
         (float32_t)p_timing_data->state_profiling[FEATURE_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.sig_proc_done_inst =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.sig_proc_done_peak =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.sig_proc_done_error_inst =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING_ERROR].lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.sig_proc_done_error_peak =
         (float32_t)p_timing_data->state_profiling[SIGPROC_POST_PROCESSING_ERROR].maxRuntime * (float)US_2_MS;

      stream_ptr->xput_info.bbe_state_machine_xput_inst =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.curr_overall_frame_time.lastRuntime * (float)US_2_MS;
      stream_ptr->xput_info.bbe_state_machine_xput_peak =
         (float32_t)p_ipc_d2m_msg->payload.dsp_timing_data.curr_overall_frame_time.maxRuntime * (float)US_2_MS;

      bbe_overall_idle_xput = ((float32_t)p_timing_data->state_profiling[IDLE].lastRuntime * (float)US_2_MS) +
                              (float32_t)p_timing_data->range_process_idle_time * (float)US_2_MS; /* idle + range_idle */
      stream_ptr->xput_info.bbe_overall_idle_xput_inst = bbe_overall_idle_xput;

      bbe_overall_idle_xput_peak =
         (bbe_overall_idle_xput_peak > bbe_overall_idle_xput) ? bbe_overall_idle_xput_peak : bbe_overall_idle_xput;
      stream_ptr->xput_info.bbe_overall_idle_xput_peak = bbe_overall_idle_xput_peak;

      stream_ptr->xput_info.frame_overall_time_inst =
         (float32_t)Get_Frame_Time(ipc_rdd_log_ptr->look_data.look_index) * (float)US_2_MS;
      stream_ptr->xput_info.frame_overall_time_peak =
         (float32_t)Get_Frame_Time(ipc_rdd_log_ptr->look_data.look_index) * (float)US_2_MS;

      /*RDD detection information*/
      stream_ptr->detection_num_1st_pass = p_ipc_d2m_rdd_data->rdd1_num_detect;
      stream_ptr->detection_num_2nd_pass = p_ipc_d2m_rdd_data->rdd2_num_detect;
      stream_ptr->look_type              = ipc_rdd_log_ptr->look_data.look_id;
      stream_ptr->scanindex              = ipc_rdd_log_ptr->look_data.scan_index;
      stream_ptr->stream_hdr.scan_index  = ipc_rdd_log_ptr->look_data.scan_index;
      stream_ptr->lookindex              = ipc_rdd_log_ptr->look_data.look_index;

      stream_ptr->sensor_timestamp_sec      = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.start_dwell_sec;
      stream_ptr->sensor_timestamp_ns       = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.start_dwell_nanosec;
      stream_ptr->sensor_dwell_time_sec     = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_sec;
      stream_ptr->sensor_dwell_time_ns      = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_nanosec;
      stream_ptr->sensor_mid_dwell_time_ns  = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.mid_dwell_nanosec;
      stream_ptr->sensor_mid_dwell_time_sec = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.mid_dwell_sec;

      stream_ptr->time_sync_validity_flag = p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_status;

      stream_ptr->time_sync_no_tsyn_error =
         (uint8_t)((TS_GLOBAL_TIME_BASE == p_ipc_d2m_msg->payload.rdd_stream_data.look_data
                                              .end_dwell_status)); /* This is to maintain the backward compatibility of
                                                                      time_sync_no_tsyn_error signal as part of header stream*/

      if (TS_POWER_ON_STATUS == p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_status)
      {
         stream_ptr->time_sync_source_master = TS_SOURCE_LOCAL;
      }
      else
      {
         if (TS_STBM_LSB & p_ipc_d2m_msg->payload.rdd_stream_data.look_data.end_dwell_status)
         {
            stream_ptr->time_sync_source_master = TS_SOURCE_LOCAL;
         }
         else
         {
            stream_ptr->time_sync_source_master = TS_SOURCE_GLOBAL;
         }
      }

      /*CPU load */
      (void)Rte_Read_Rp_CPU_Load_De_CPU_Load(&CPU_Load_C0_Logging);
      stream_ptr->mss_stream_data.CPU_Load     = CPU_Load_C0_Logging.CPU_Load;
      stream_ptr->mss_stream_data.CPU_Load_Max = CPU_Load_C0_Logging.CPU_Load_Avg;
      stream_ptr->mss_stream_data.CPU_Load_Avg = CPU_Load_C0_Logging.CPU_Load_Avg;
      stream_ptr->mss_stream_data.CPU_Load_Min = CPU_Load_C0_Logging.CPU_Load_Min;
   }
   else
   {
      stream_ptr->scanindex = LOG_SIGNAL_INVALID_VALUE;
   }

#if 0
/*Time stamp information*/
stream_ptr->time_sync_timesync_jitter = p_temp_ts_status->TIMESYNC_JITTER;
stream_ptr->time_sync_offset = p_temp_ts_status->TS_ADJUST_DELTA;

/*Measurement latency*/
ts_time_ptr = Get_TS_Current_Time(TS_READ_DATA_OUT_LATENCY);
stream_ptr->measurement_latency = ts_time_ptr->TimeNSec / LATENCY_SIGNAL_CONVERSION;
#endif

#if 0
/*Time synchronization flags*/
stream_ptr->time_sync_syn_seq_cnt_error = (p_temp_ts_status->SYN_SEQ_CNT_ERROR_FLAG);
stream_ptr->time_sync_fup_seq_cnt_error = (p_temp_ts_status->FUP_SEQ_CNT_ERROR_FLAG);
stream_ptr->time_sync_sec_out_of_range = (p_temp_ts_status->SYN_SEC_OUT_OF_RANGE_FLAG);
stream_ptr->time_sync_fup_nsec_out_of_range = (p_temp_ts_status->FUP_NSEC_OUT_OF_RANGE_FLAG);
stream_ptr->time_sync_threshold_flag = (p_temp_ts_status->THRESHOLD_FLAG);
stream_ptr->time_sync_timesync_correction_type = (p_temp_ts_status->TIMESYNC_CORRECTION_TYP);
stream_ptr->time_sync_no_tsyn_error = (p_temp_ts_status->NO_TSYN_ERROR_FLAG);
stream_ptr->time_sync_invalid_pdu = (p_temp_ts_status->INVALID_PDU_FLAG);
stream_ptr->time_sync_sync_crc_error = (p_temp_ts_status->SYN_CRC_ERROR_FLAG);
stream_ptr->time_sync_fup_crc_error = (p_temp_ts_status->FUP_CRC_ERROR_FLAG);
stream_ptr->timestamp_delta = (p_temp_ts_status->TIMESTAMP_DELTA);

/*Coverage information*/

stream_ptr->rdd_range_coverage = ipc_rdd_log_ptr->look_data.range_coverage;
stream_ptr->rdd_dopp_coverage  = ipc_rdd_log_ptr->look_data.doppler_coverage;

/* Hed Fov Hor Min*/
stream_ptr->sensor_fov_hor_min = k_FOV_hor_begin_SMC;

/* Hed Fov Hor Max*/
stream_ptr->sensor_fov_hor_max = k_FOV_hor_end_SMC;

/* Hed Fov Ver Min*/
stream_ptr->sensor_fov_ver_min = k_FOV_ver_begin_SMC;

/* Hed Fov Ver Max*/
stream_ptr->sensor_fov_ver_max = k_FOV_ver_end_SMC;
#endif

/*Vehicle ego motion*/
#if 0
stream_ptr->yaw_rate = p_ipc_m2d_msg->payload. vcan_rx_signals->ssts_yaw_rate_calc;
stream_ptr->veh_speed = vcan_rx_signals->ssts_vehicle_speed_calc;
#endif

   /*FailSafe ResetReason*/
   (void)Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(&plt_reset_reason_local);

   {
      stream_ptr->mss_stream_data.reset_counter            = plt_reset_reason_local.reset_counter;
      stream_ptr->mss_stream_data.last_cycle_reset         = plt_reset_reason_local.last_cycle_reset;
      stream_ptr->mss_stream_data.reset_reason_crnt_indx   = plt_reset_reason_local.reset_reason_crnt_indx;
      stream_ptr->mss_stream_data.repetitive_reset_counter = plt_reset_reason_local.repetitive_reset_counter;

      stream_ptr->mss_stream_data.reset_reason_info_0 = plt_reset_reason_local.reset_reason[0];
      stream_ptr->mss_stream_data.reset_reason_info_1 = plt_reset_reason_local.reset_reason[1];
      stream_ptr->mss_stream_data.reset_reason_info_2 = plt_reset_reason_local.reset_reason[2];
      stream_ptr->mss_stream_data.reset_reason_info_3 = plt_reset_reason_local.reset_reason[3];
      stream_ptr->mss_stream_data.reset_reason_info_4 = plt_reset_reason_local.reset_reason[4];

      stream_ptr->mss_stream_data.Exception_type         = plt_reset_reason_local.mem_exception_reason.ExceptionType;
      stream_ptr->mss_stream_data.Program_counter        = plt_reset_reason_local.mem_exception_reason.ExceptionCausingAddress;
      stream_ptr->mss_stream_data.Machine_State          = plt_reset_reason_local.mem_exception_reason.ExceptionStatusRegister;
      stream_ptr->mss_stream_data.IsMemException_Occured = plt_reset_reason_local.mem_exception_reason.IsMemException_Occured;
      stream_ptr->mss_stream_data.Variable_address       = plt_reset_reason_local.mem_exception_reason.MemoryExceptionAddress;
      // stream_ptr->mss_stream_data.StackPointer = plt_reset_reason_local.mem_exception_reason.StackPointer;

      stream_ptr->mss_stream_data.wdg_failed_SE_info_0 = plt_reset_reason_local.wdg_failed_SE_info[0];
      stream_ptr->mss_stream_data.wdg_failed_SE_info_1 = plt_reset_reason_local.wdg_failed_SE_info[1];
      stream_ptr->mss_stream_data.wdg_failed_SE_info_2 = plt_reset_reason_local.wdg_failed_SE_info[2];
      stream_ptr->mss_stream_data.wdg_failed_SE_info_3 = plt_reset_reason_local.wdg_failed_SE_info[3];
      stream_ptr->mss_stream_data.wdg_failed_SE_info_4 = plt_reset_reason_local.wdg_failed_SE_info[4];

      /* missing on right hand side: Also can we save the index where it fails instead of all the fault comparision */
      // stream_ptr->mss_stream_data.StaticRegCheckFailureInfo_0 = plt_reset_reason_local.StaticRegCheckFailureInfo_0;

      /* missing on both left and right hand side: */
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_0 = plt_reset_reason_local.FCCU_Faults[0];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_1 = plt_reset_reason_local.FCCU_Faults[1];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_2 = plt_reset_reason_local.FCCU_Faults[2];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_3 = plt_reset_reason_local.FCCU_Faults[3];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_4 = plt_reset_reason_local.FCCU_Faults[4];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_5 = plt_reset_reason_local.FCCU_Faults[5];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_6 = plt_reset_reason_local.FCCU_Faults[6];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_7 = plt_reset_reason_local.FCCU_Faults[7];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_8 = plt_reset_reason_local.FCCU_Faults[8];
      // stream_ptr->mss_stream_data.failsafe_reset_reason_info_9 = plt_reset_reason_local.FCCU_Faults[9];
   }
   /*Populate Alignment data*/
   Populate_Alignment_Data(stream_ptr);

   /*Platform Active Fault table*/
   if (NULL != SWC_PLT_Appl_Active_Table_Local)
   {
      stream_ptr->mss_stream_data.Active_Fault_byte0  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[0];
      stream_ptr->mss_stream_data.Active_Fault_byte1  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[1];
      stream_ptr->mss_stream_data.Active_Fault_byte2  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[2];
      stream_ptr->mss_stream_data.Active_Fault_byte3  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[3];
      stream_ptr->mss_stream_data.Active_Fault_byte4  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[4];
      stream_ptr->mss_stream_data.Active_Fault_byte5  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[5];
      stream_ptr->mss_stream_data.Active_Fault_byte6  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[6];
      stream_ptr->mss_stream_data.Active_Fault_byte7  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[7];
      stream_ptr->mss_stream_data.Active_Fault_byte8  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[8];
      stream_ptr->mss_stream_data.Active_Fault_byte9  = SWC_PLT_Appl_Active_Table_Local->Platform_byte[9];
      stream_ptr->mss_stream_data.Active_Fault_byte10 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[10];
      stream_ptr->mss_stream_data.Active_Fault_byte11 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[11];
      stream_ptr->mss_stream_data.Active_Fault_byte12 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[12];
      stream_ptr->mss_stream_data.Active_Fault_byte13 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[13];
      stream_ptr->mss_stream_data.Active_Fault_byte14 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[14];
      stream_ptr->mss_stream_data.Active_Fault_byte15 = SWC_PLT_Appl_Active_Table_Local->Platform_byte[15];
   }

   /*Platform Active Fault table*/
   if (NULL != History_Fault_Table_Local)
   {
      stream_ptr->mss_stream_data.History_Fault_byte0  = History_Fault_Table_Local->Platform_byte[0];
      stream_ptr->mss_stream_data.History_Fault_byte1  = History_Fault_Table_Local->Platform_byte[1];
      stream_ptr->mss_stream_data.History_Fault_byte2  = History_Fault_Table_Local->Platform_byte[2];
      stream_ptr->mss_stream_data.History_Fault_byte3  = History_Fault_Table_Local->Platform_byte[3];
      stream_ptr->mss_stream_data.History_Fault_byte4  = History_Fault_Table_Local->Platform_byte[4];
      stream_ptr->mss_stream_data.History_Fault_byte5  = History_Fault_Table_Local->Platform_byte[5];
      stream_ptr->mss_stream_data.History_Fault_byte6  = History_Fault_Table_Local->Platform_byte[6];
      stream_ptr->mss_stream_data.History_Fault_byte7  = History_Fault_Table_Local->Platform_byte[7];
      stream_ptr->mss_stream_data.History_Fault_byte8  = History_Fault_Table_Local->Platform_byte[8];
      stream_ptr->mss_stream_data.History_Fault_byte9  = History_Fault_Table_Local->Platform_byte[9];
      stream_ptr->mss_stream_data.History_Fault_byte10 = History_Fault_Table_Local->Platform_byte[10];
      stream_ptr->mss_stream_data.History_Fault_byte11 = History_Fault_Table_Local->Platform_byte[11];
      stream_ptr->mss_stream_data.History_Fault_byte12 = History_Fault_Table_Local->Platform_byte[12];
      stream_ptr->mss_stream_data.History_Fault_byte13 = History_Fault_Table_Local->Platform_byte[13];
      stream_ptr->mss_stream_data.History_Fault_byte14 = History_Fault_Table_Local->Platform_byte[14];
   }

   /*OperationMode_System*/
   (void)Rte_Read_Rp_OperationModeType_De_OperationMode_System(&operation_mode);
   stream_ptr->mss_stream_data.OperationMode_System = operation_mode;
}

/******************************************************************************
 *. Name: Populate_Debug_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Debug_Stream(void)
{
   /*pmic's spread spectrum status*/
   uint8_t enss_enable  = 0U;
   uint8_t enss_disable = 0U;

   Dt_RawAdcData_T raw_adc_data                          = {0};
   Debug_Stream_T *stream_ptr                            = &Debug_Stream;
   IPC_Message_Counter_T dsp_range_cfg_count             = Get_DSP_Range_Config_Counts();
   IPC_Message_Counter_T dsp_range_proc_complete_count   = Get_DSP_Range_Process_Complete_Counts();
   IPC_Message_Counter_T dsp_doppler_proc_complete_count = Get_DSP_Doppler_Process_Complete_Counts();
   IPC_Message_Counter_T dsp_sp_post_complete_count      = Get_DSP_Sp_Post_Complete_Counts();

   D2M_Msg_T *p_ipc_d2m_msg          = Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   IPC_Shared_Buffers_T *ipc_buf_add = (IPC_Shared_Buffers_T *)Get_Ipc_Shared_Buffer_Base_Address();

   if ((NULL != p_ipc_d2m_msg) && (NULL != ipc_buf_add))
   {
      Look_Data_T *ipc_look_data_ptr = &(p_ipc_d2m_msg->payload.rdd_stream_data.look_data);

      (void)memcpy(&stream_ptr->ipc_shared_debug_buffer, ipc_buf_add, sizeof(IPC_Shared_Debug_Buffer_T));

      stream_ptr->debug_scanindex       = ipc_look_data_ptr->scan_index;
      stream_ptr->stream_hdr.scan_index = ipc_look_data_ptr->scan_index;
   }
   else
   {
      stream_ptr->stream_hdr.scan_index = LOG_SIGNAL_INVALID_VALUE;
   }
#if 0

   Stack_ISR_mss_T *mss_stack_isr                  = Get_stack_isr_mss();
   Stack_TASK_mss_T *mss_stack_task                = Get_stack_task_mss();
   Stack_CORE_mss_T *mss_stack_core                = Get_stack_core_mss();
#endif
   void *dest_ptr = (Logging_Statistics_T *)&stream_ptr->logging_statistics; /*Data to be provided by packing core - Good to get
                                                                          stats here - No CDC interrupts post RDD task*/

   ((Logging_Statistics_T *)(dest_ptr))->CDC_MAX_LOG_BINS                       = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Range_Bins_Limited_Count           = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_ENET_Partial_Buffer_Mismatch_Count = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_ENET_Buffer_UNAVBL_Count           = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Frames_Max                = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Frames                    = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Bins                      = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Total_Bins_Max                = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Total_Bins                    = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Look_Num_Dbins_Per_Rbin_Max        = 0;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Num_Dbins_Per_Rbin_Max             = 0;
   ((Logging_Statistics_T *)(dest_ptr))->ENET_TxBuffers_Pending_Count           = 0;
   ((Logging_Statistics_T *)(dest_ptr))->ENET_TxBuffers_Pending_Count_MAX       = 0;
   ((Logging_Statistics_T *)(dest_ptr))->ENET_ARP_Tx_Buf_UNAVBL_Count           = 0;
   ((Logging_Statistics_T *)(dest_ptr))->ENET_CDC_Tx_Buf_UNAVBL_Count           = 0;
   ((Logging_Statistics_T *)(dest_ptr))->ENET_Logging_Tx_Buf_UNAVBL_Count       = 0;
#if (defined(CDC_ENABLE))
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Current_Index_Error_Cnt = C0_CDC_Current_Index_Error_Cnt;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Fail_Cnt       = C0_CDC_Transmit_Fail_Cnt;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Success_Cnt    = C0_CDC_Transmit_Success_Cnt;
#else
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Current_Index_Error_Cnt          = 0U;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Fail_Cnt                = 0U;
   ((Logging_Statistics_T *)(dest_ptr))->CDC_Transmit_Success_Cnt             = 0U;
#endif
   ((Logging_Statistics_T *)(dest_ptr))->Frame_Transmit_Success_Cnt = Frame_Tx_Success_Cnt;
   ((Logging_Statistics_T *)(dest_ptr))->Frame_Transmit_Failure_Cnt = Frame_Tx_Failure_Cnt;
#ifndef DISBLE_STACK_MONITOR_DSS
   #if 0
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Bytes = p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.stack_utilization_bytes;
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Percentage = p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.stack_utilization_percentage;
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_State = p_ipc_d2m_msg->payload.stack_usage_data.Stack_Utilization_Max.current_state;
   #endif
#else
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Bytes      = 0;
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_Percentage = 0;
   ((Logging_Statistics_T *)(dest_ptr))->MAX_DSS_Stack_Utilization_State      = 0;

#endif

   dest_ptr = (MSS_Stack_Coverage_Info_T *)&stream_ptr->mss_stack_coverage;
   if ((MSS_NUM_ISR >= TOTAL_NUM_ISRS) && (MSS_NUM_TASK >= TOTAL_NUM_TASKS))
   {
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_valid_stack_info       = true;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Kernel       = 0U; // mss_stack_core->MSS_StackCore_Kernel;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Startuphook  = 0U; // mss_stack_core->MSS_StackCore_Startuphook;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Errorhook    = 0U; // mss_stack_core->MSS_StackCore_Errorhook;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Shutdownhook = 0U; // mss_stack_core->MSS_StackCore_Shutdownhook;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Protectionhook =
         0U; // mss_stack_core->MSS_StackCore_Protectionhook;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Kernel_percentage =
         0U; // mss_stack_core->MSS_StackCore_Kernel_percentage;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Startuphook_percentage =
         0U; // mss_stack_core->MSS_StackCore_Startuphook_percentage;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Errorhook_percentage =
         0U; // mss_stack_core->MSS_StackCore_Errorhook_percentage;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Shutdownhook_percentage =
         0U; // mss_stack_core->MSS_StackCore_Shutdownhook_percentage;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Protectionhook_percentage =
         0U; // mss_stack_core->MSS_StackCore_Protectionhook_percentage;
#if 0
      for (uint8_t i = 0; i < TOTAL_NUM_ISRS; i++)
      {
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR[i]              = mss_stack_isr->stack_isr[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_percentage[i]   = mss_stack_isr->stack_isr_percentage[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_stacksharing[i] = mss_stack_isr->ISR_stack_sharing[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_Type[i]         = (ISRType)mss_stack_isr->ISR_Type[i];
      }
      for (uint8_t i = 0; i < TOTAL_NUM_TASKS; i++)
      {
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK[i]              = mss_stack_task->stack_task[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_percentage[i]   = mss_stack_task->stack_task_percentage[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_stacksharing[i] = mss_stack_task->TASk_stack_sharing[i];
         ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_Type[i]         = (TaskType)mss_stack_task->TASK_Type[i];
      }
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Total_ISR_Configured = (uint8_t)TOTAL_NUM_ISRS;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Total_TASK_Configred = (uint8_t)TOTAL_NUM_TASKS;
#endif
   }
   else
   {
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_valid_stack_info                    = false;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Kernel                    = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Startuphook               = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Errorhook                 = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Shutdownhook              = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Protectionhook            = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Kernel_percentage         = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Startuphook_percentage    = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Errorhook_percentage      = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Shutdownhook_percentage   = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_StackCore_Protectionhook_percentage = INVALID_VALUE;
#if 0
   for (uint8_t i = 0; i < MSS_NUM_ISR; i++)
   {
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR[i]              = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_percentage[i]   = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_stacksharing[i] = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_ISR_Type[i]         = INVALID_VALUE;
   }
   for (uint8_t i = 0; i < MSS_NUM_TASK; i++)
   {
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK[i]              = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_percentage[i]   = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_stacksharing[i] = INVALID_VALUE;
      ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Stack_TASK_Type[i]         = INVALID_VALUE;
   }
   ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Total_ISR_Configured = (uint8_t)INVALID_VALUE;
   ((MSS_Stack_Coverage_Info_T *)(dest_ptr))->MSS_Total_TASK_Configred = (uint8_t)INVALID_VALUE;
#endif
   }

   // stream_ptr->dsp_setup_debug.DSP_Cfg_Init                                  = DSP_Cfg_Init;
   stream_ptr->dsp_setup_debug.DSP_Doppler_Process_Complete_Counts.error_count = dsp_doppler_proc_complete_count.error_count;
   stream_ptr->dsp_setup_debug.DSP_Doppler_Process_Complete_Counts.rx_count    = dsp_doppler_proc_complete_count.rx_count;
   stream_ptr->dsp_setup_debug.DSP_Init                                        = DSP_Init;
   stream_ptr->dsp_setup_debug.DSP_No_Command_Cnt                              = Get_DSP_No_Command_Cnt();
   stream_ptr->dsp_setup_debug.DSP_Range_Config_Counts.error_count             = dsp_range_cfg_count.error_count;
   stream_ptr->dsp_setup_debug.DSP_Range_Config_Counts.rx_count                = dsp_range_cfg_count.rx_count;
   stream_ptr->dsp_setup_debug.DSP_Range_Process_Complete_Counts.error_count   = dsp_range_proc_complete_count.error_count;
   stream_ptr->dsp_setup_debug.DSP_Range_Process_Complete_Counts.rx_count      = dsp_range_proc_complete_count.rx_count;
   stream_ptr->dsp_setup_debug.DSP_Sp_Post_Complete_Counts.error_count         = dsp_sp_post_complete_count.error_count;
   stream_ptr->dsp_setup_debug.DSP_Sp_Post_Complete_Counts.rx_count            = dsp_sp_post_complete_count.rx_count;
   stream_ptr->dsp_setup_debug.R52_D2M_Msg_Header_Cnt                          = Get_R52_D2M_Msg_Header_Cnt();
   stream_ptr->dsp_setup_debug.R52_M2D_Buffer_Index                            = R52_M2D_Buffer_Index;
   stream_ptr->dsp_setup_debug.R52_M2D_Msg_Header_Cnt                          = R52_M2D_Msg_Header_Cnt;
   stream_ptr->dsp_setup_debug.Received_Doppler_Done                           = Get_Received_Doppler_Done();
   stream_ptr->dsp_setup_debug.Received_Doppler_Stream                         = Get_Is_Doppler_Comp_RDD_Stream_Ready();
   stream_ptr->dsp_setup_debug.M2D_Buffer_Full_Error_Counter                   = Get_M2D_Buffer_Full_Error_Counter();
   stream_ptr->dsp_setup_debug.M2D_DSP_Not_Ready_Counter                       = M2D_DSP_Not_Ready_Counter;
   stream_ptr->dsp_setup_debug.DSP_Processing_Error_Counter                    = DSP_Processing_Error_Counter;
   stream_ptr->dsp_setup_debug.DSP_Skipped_Frame_Error_Counter                 = DSP_Skipped_Frame_Error_Counter;
   stream_ptr->dsp_setup_debug.DSP_Skipped_Frame                               = DSP_Skipped_Frame;
   stream_ptr->dsp_setup_debug.Dsp_Cfg_Error_Counter                           = Dsp_Cfg_Error_Counter;
   stream_ptr->dsp_setup_debug.DSP_Reset_Counter                               = DSP_Reset_Counter;
   stream_ptr->dsp_setup_debug.ipc_d2m_max_delta_time_us                       = Get_IPC_D2M_Max_Delta_Time_Us();
   stream_ptr->dsp_setup_debug.ipc_d2m_min_delta_time_us                       = Get_IPC_D2M_Min_Delta_Time_Us();

   stream_ptr->mars_debug_data.Mars_Data_drvStatus =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_drvStatus;
   stream_ptr->mars_debug_data.Mars_Data_mblError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_mblError;
   stream_ptr->mars_debug_data.Mars_Data_mafError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_mafError;
   stream_ptr->mars_debug_data.Mars_Data_sftError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_sftError;
   stream_ptr->mars_debug_data.Mars_Data_ssiError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_ssiError;
   stream_ptr->mars_debug_data.Mars_Data_scpError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_scpError;
   stream_ptr->mars_debug_data.Mars_Data_pcwError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_pcwError;
   stream_ptr->mars_debug_data.Mars_Data_stsError =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_stsError;
   stream_ptr->mars_debug_data.Mars_Data_mcuStatus =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_mcuStatus;
   stream_ptr->mars_debug_data.Mars_Data_ctrlStatus =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_ctrlStatus;
   stream_ptr->mars_debug_data.Mars_Data_opModeStatus =
      (uint32_t)Mars_Self_Layer2_InstanceDriver0.Mars_Data.Mars_Status.Mars_Data_opModeStatus;

   stream_ptr->mars_debug_data.total_reset_counter              = (uint32_t)MARS_Reset_Counters.total_reset_counter;
   stream_ptr->mars_debug_data.mars_init_fail_reset_counter     = (uint32_t)MARS_Reset_Counters.mars_init_fail_reset_counter;
   stream_ptr->mars_debug_data.mars_init_fail_reset_reason      = (uint32_t)MARS_Reset_Counters.mars_init_fail_reset_reason;
   stream_ptr->mars_debug_data.look_config_fail_reset_counter   = (uint32_t)MARS_Reset_Counters.look_config_fail_reset_counter;
   stream_ptr->mars_debug_data.look_config_fail_reset_reason    = (uint32_t)MARS_Reset_Counters.look_config_fail_reset_reason;
   stream_ptr->mars_debug_data.look_trigger_fail_reset_counter  = (uint32_t)MARS_Reset_Counters.look_trigger_fail_reset_counter;
   stream_ptr->mars_debug_data.look_trigger_fail_reset_reason   = (uint32_t)MARS_Reset_Counters.look_trigger_fail_reset_reason;
   stream_ptr->mars_debug_data.look_complete_fail_reset_counter = (uint32_t)MARS_Reset_Counters.look_complete_fail_reset_counter;
   stream_ptr->mars_debug_data.look_complete_fail_reset_reason  = (uint32_t)MARS_Reset_Counters.look_complete_fail_reset_reason;
   stream_ptr->mars_debug_data.bist_non_recoverable_fault_count = (uint32_t)MARS_Reset_Counters.bist_non_recoverable_fault_count;

   stream_ptr->pfm_debug_data.pfm_success_count = PFM_Get_Success_Count();
   stream_ptr->pfm_debug_data.pfm_fail_count    = PFM_Get_Fail_Count();

   {
      volatile uint16_t *xcp_raw_adc_ptr = Get_XCP_Raw_ADC_Data();
      (void)memcpy((void *)&raw_adc_data, (const void *)xcp_raw_adc_ptr, sizeof(raw_adc_data));
   }

   stream_ptr->raw_adc_data.brd_rev_adc_counts    = raw_adc_data.Adc_Board_Rev;
   stream_ptr->raw_adc_data.batt_adc_counts       = raw_adc_data.Adc_Batt_Volt;
   stream_ptr->raw_adc_data.eth_0v9_adc_counts    = raw_adc_data.Adc_Eth_0v9;
   stream_ptr->raw_adc_data.rdi_detect_adc_counts = raw_adc_data.Adc_Rdi_Detect;
   /* ADC CH8 is MMIC_TEMP in EDU and ADC_POS_GND_C in AL A3 and B Sample */
   stream_ptr->raw_adc_data.ign_adc_counts        = raw_adc_data.Adc_Pos_Gnd_C;
   stream_ptr->raw_adc_data.mcu_temp_counts       = raw_adc_data.Adc_Mcu_Temp;
   stream_ptr->raw_adc_data.pos_gnd_adc_counts[0] = raw_adc_data.Adc_Pos_Gnd_A;
   stream_ptr->raw_adc_data.pos_gnd_adc_counts[1] = raw_adc_data.Adc_Pos_Gnd_B;
   /* ADC CH4 is ADC_POS_GND_C in EDU and A1; and IGN in AL A3 and B Sample */
   stream_ptr->raw_adc_data.pos_gnd_adc_counts[2] = raw_adc_data.Adc_MMIC_Temp;
   stream_ptr->raw_adc_data.pos_gnd_adc_counts[3] = raw_adc_data.Adc_Pos_Gnd_D;

   stream_ptr->conv_adc_data.brd_rev_adc_volts = (float32_t)raw_adc_data.Adc_Board_Rev * (float32_t)ADC_COUNTS_TO_VOLTS;
   if ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||
       (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))
   {
      stream_ptr->conv_adc_data.batt_adc_volts =
         (float32_t)(((float32_t)((float32_t)raw_adc_data.Adc_Batt_Volt * (float32_t)BATT_SCALE_FACTOR)) + ADC_BATT_OFFSET);
   }
   else
   {
      stream_ptr->conv_adc_data.batt_adc_volts = (float32_t)raw_adc_data.Adc_Batt_Volt * (float32_t)BATT_SCALE_FACTOR;
   }

   stream_ptr->conv_adc_data.eth_0v9_adc_volts    = (float32_t)raw_adc_data.Adc_Eth_0v9 * (float32_t)ETH_0V9_SCALE_FACTOR;
   stream_ptr->conv_adc_data.rdi_detect_adc_volts = (float32_t)raw_adc_data.Adc_Rdi_Detect * (float32_t)RDI_DETECT_SCALE_FACTOR;
   /* ADC CH4 is ADC_POS_GND_C in EDU and A1; and IGN in AL A3 and B Sample */
   if ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||
       (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))
   {
      stream_ptr->conv_adc_data.ign_adc_volts =
         (float32_t)((float32_t)((float32_t)raw_adc_data.Adc_Pos_Gnd_C * (float32_t)IGN_SCALE_FACTOR) + ADC_IGN_OFFSET);
   }
   else
   {
      stream_ptr->conv_adc_data.ign_adc_volts =
         (float32_t)((float32_t)((float32_t)raw_adc_data.Adc_Pos_Gnd_C * (float32_t)IGN_SCALE_FACTOR));
   }
   stream_ptr->conv_adc_data.mcu_temp_volts       = (float32_t)raw_adc_data.Adc_Mcu_Temp * (float32_t)ADC_TEMP_SCALE_FACTOR;
   stream_ptr->conv_adc_data.pos_gnd_adc_volts[0] = (float32_t)raw_adc_data.Adc_Pos_Gnd_A * (float32_t)POSGND_CONVERSION_CONSTANT;
   stream_ptr->conv_adc_data.pos_gnd_adc_volts[1] = (float32_t)raw_adc_data.Adc_Pos_Gnd_B * (float32_t)POSGND_CONVERSION_CONSTANT;
   /* ADC CH8 is MMIC_TEMP in EDU and ADC_POS_GND_C in AL A3 and B Sample */
   stream_ptr->conv_adc_data.pos_gnd_adc_volts[2] = (float32_t)raw_adc_data.Adc_MMIC_Temp * (float32_t)POSGND_CONVERSION_CONSTANT;
   stream_ptr->conv_adc_data.pos_gnd_adc_volts[3] = (float32_t)raw_adc_data.Adc_Pos_Gnd_D * (float32_t)POSGND_CONVERSION_CONSTANT;

   Get_Pmic_Enss_Status(&enss_enable, &enss_disable);
   stream_ptr->pmic_enss_status.enable  = enss_enable;
   stream_ptr->pmic_enss_status.disable = enss_disable;
   /* Populate FuSa fault bits into debug stream payload. */
   Populate_Fusa_Faults_In_Debug_Stream(stream_ptr);
   /*Populate Each Stream Information in Stream_details Structure*/
   Update_Stream_Table_Debug_Data(stream_ptr);
   /* Calculate checksum */
   /*Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Debug_Stream_T));*/
}

/******************************************************************************
 *. Name: Update_Stream_Table_Debug_Data
 *.
 *.
 *. Parameters: Debug_Stream_T *stream_ptr
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Update_Stream_Table_Debug_Data(Debug_Stream_T *stream_ptr)
{
   uint16_t stream_idx             = 0U;
   uint8_t stream_table_idx        = 0U;
   uint8_t sub_stream_count        = MIN_SUB_STREAM_CNT;
   uint16_t stream_count           = Get_Total_Streams();
   Stream_Cfg_T *stream_table_info = Get_Stream_Table();
   uint8_t sub_stream_data_present = CODED_FALSE;
   Rec_Hdl_T *rec_hdl_ptr          = NULL;

   if (NULL != stream_table_info)
   {
      for (stream_idx = 0; stream_idx < stream_count; stream_idx++)
      {
         rec_hdl_ptr = Get_Rec_Hdl_Ptr(stream_idx);

         if (NULL != rec_hdl_ptr)
         {
            /*Here structure variable pre-fix "s_" refers that it derived from "streams" structure  and "st_" refers to
             * "stream_table"
             */
            stream_ptr->stream_details[stream_idx].s_txcount           = rec_hdl_ptr->txcount;
            stream_ptr->stream_details[stream_idx].s_ref_idx           = rec_hdl_ptr->ref_idx;
            stream_ptr->stream_details[stream_idx].s_id                = rec_hdl_ptr->id;
            stream_ptr->stream_details[stream_idx].st_stream_failure   = stream_table_info[stream_table_idx].stream_failure;
            stream_ptr->stream_details[stream_idx].st_stream_overwrite = stream_table_info[stream_table_idx].stream_overwrite;
            stream_ptr->stream_details[stream_idx].s_chunks_per_cycle  = rec_hdl_ptr->chunks_per_cycle;
            stream_ptr->stream_details[stream_idx].s_state             = rec_hdl_ptr->state;
            stream_ptr->stream_details[stream_idx].s_stream_type       = rec_hdl_ptr->stream_type;
            stream_ptr->stream_details[stream_idx].st_stream_idx       = stream_table_info[stream_table_idx].stream_idx;
            stream_ptr->stream_details[stream_idx].st_stream_num       = stream_table_info[stream_table_idx].stream_num;
            stream_ptr->stream_details[stream_idx].st_stream_mode      = stream_table_info[stream_table_idx].stream_mode;
            stream_ptr->stream_details[stream_idx].st_last_failure     = stream_table_info[stream_table_idx].last_failure;
            stream_ptr->stream_details[stream_idx].st_sub_stream_cnt   = stream_table_info[stream_table_idx].sub_stream_cnt;
            stream_ptr->stream_details[stream_idx].s_stream_ver        = rec_hdl_ptr->rec_ptr->rec_hdr.streamVersion;

            /*If a Stream contain More than 1 Sub stream then Update the sub stream details in main stream */
            if (MIN_SUB_STREAM_CNT < stream_table_info[stream_table_idx].sub_stream_cnt)
            {
               if (CODED_FALSE == sub_stream_data_present)
               {
                  sub_stream_count        = (stream_table_info[stream_table_idx].sub_stream_cnt) - MIN_SUB_STREAM_CNT;
                  sub_stream_data_present = CODED_TRUE;
               }
               else
               {
                  sub_stream_count--;
               }
               if (MIN_SUB_STREAM_CNT > sub_stream_count)
               {
                  stream_table_idx++;
                  sub_stream_data_present = CODED_FALSE;
               }
            }
            else
            {
               stream_table_idx++;
            }
         }
      }
   }
}

/******************************************************************************
 *. Name: Populate_Vse_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Vse_Stream(void)
{
   SH_Output_T *sh_output_data_ptr   = Get_SH_Output_Data_Ptr();
   HIL_Output_T *hil_output_data_ptr = Get_HIL_Output_Data_Ptr();
   /*uint8_t vse_trigger_state;*/
   Vse_Stream_T *stream_ptr = &Vse_Stream;

   uint8_t buf_read_idx_raw      = Get_Fetch_M2D_Buffer_Idx_HIL_Injection();
   M2D_Msg_T *ptr_ipc_mss_to_dss = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buf_Addr(buf_read_idx_raw);

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer();
   if ((NULL != ptr_ipc_mss_to_dss) && (NULL != p_ipc_d2m_msg))
   {
      const Vse_Stream_T *src_vse_ptr = &ptr_ipc_mss_to_dss->payload.veh_data;
      (void)memcpy((void *)stream_ptr, (const void *)src_vse_ptr, sizeof(Vse_Stream_T));

      if ((CODED_TRUE != hil_output_data_ptr->hil_enabled_streams[VSE]) && (CODED_TRUE != hil_output_data_ptr->hil_mode_enabled))
      {
         stream_ptr->stream_hdr.scan_index = ptr_ipc_mss_to_dss->payload.look_Info.scan_index;
      }

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Vse_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(VSE, (uint8_t *)stream_ptr);
   }
}

#ifdef TRACKER_ENABLED
/******************************************************************************
 *. Name: Populate_Partner_Sensor_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Partner_Sensor_Stream(void)
{
   D2M_Msg_T *p_ipc_d2m_msg          = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   SH_Output_T *sh_output_data_ptr   = Get_SH_Output_Data_Ptr();
   HIL_Output_T *hil_output_data_ptr = Get_HIL_Output_Data_Ptr();
   uint8_t buf_read_idx_raw          = Get_Fetch_M2D_Buffer_Idx_HIL_Injection();
   M2D_Msg_T *p_ipc_m2d_msg          = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buf_Addr(buf_read_idx_raw);

   if ((NULL != p_ipc_m2d_msg) && (NULL != p_ipc_d2m_msg))
   {
      Partner_Sensor_Stream_T *stream_ptr = &p_ipc_m2d_msg->payload.partners_data;

      if (CODED_TRUE != hil_output_data_ptr->hil_mode_enabled)
      {
         stream_ptr->stream_hdr.scan_index = p_ipc_d2m_msg->payload.det_data.det_list_property.scanindex;
      }

      sh_output_data_ptr->sh_trigger_stream_handler_fptr(PARTNER_SENSOR, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Set_Tracker_Stream_Ref_Index
 *.    Function to set scan index to use for tracker streams
 *.
 *. Parameters: uint32_t
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Set_Tracker_Stream_Ref_Index(uint32_t val)
{
   Tracker_Ref_Index = val;
}

/******************************************************************************
 *. Name: Get_Tracker_Stream_Ref_Index
 *.    Function to get scan index to use for tracker streams
 *.
 *. Parameters: void
 *. Return Value: uint32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.

 *. JIRA Issues:
 ******************************************************************************/
uint32_t Get_Tracker_Ref_Index(void)
{
   return Tracker_Ref_Index;
}

#endif

#ifdef FEATURE_ENABLE
/******************************************************************************
 *. Name: Populate_BSIS_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_BSIS_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Bsis_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Bsis_Stream_T *)&(p_ipc_d2m_msg->payload.Bsis_IPC_Output);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Bsis_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(BSIS, (uint8_t *)stream_ptr);
   }
}

/******************************************************************************
 *. Name: Populate_MOIS_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_MOIS_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Mois_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Mois_Stream_T *)&(p_ipc_d2m_msg->payload.Mois_IPC_Output);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Mois_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(MOIS, (uint8_t *)stream_ptr);
   }
}
/******************************************************************************
 *. Name: Populate_Olp_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Populate_Olp_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   Olp_Stream_T *stream_ptr;

   D2M_Msg_T *p_ipc_d2m_msg = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   if (NULL != p_ipc_d2m_msg)
   {
      stream_ptr = (Olp_Stream_T *)&(p_ipc_d2m_msg->payload.Olp_Object_Data);

      /* Calculate checksum */
      /* Calculate_Checksum((uint8_t *)stream_ptr, sizeof(Olp_Stream_T));*/

      (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(OLP, (uint8_t *)stream_ptr);
   }
}
#endif

/******************************************************************************
 *. Name: SoAd_Frame_Transmit
 *.    Driver call to send out ethernet frame
 *.
 *. Parameters: uint8_t pdu_id, Rec_Frame_T *frame_ptr
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t SoAd_Frame_Transmit(Tx_Frame_Param_T *tx_frame_param_ptr)
{
   PduInfoType pdu_info;
   uint8_t pdu_id;
   uint8_t ret_val;

   pdu_info.SduLength  = (uint16_t)sizeof(Rec_Frame_T);
   pdu_info.SduDataPtr = (uint8_t *)tx_frame_param_ptr->frame_ptr;
   if ((STREAM_DYNAMIC == tx_frame_param_ptr->stream_type))
   {
      /*pdu_id = DYNAMIC_STREAM_PDU_ID;*/ /*Enable this when DYNAMIC_STREAM_PDU_ID is updtaed and delete the below line*/
      pdu_id = REGULAR_STREAM_PDU_ID;
   }
   else if ((STREAM_REGULAR_FAST == tx_frame_param_ptr->stream_type))
   {
      pdu_id = FAST_STREAM_PDU_ID;
   }
   else
   {
      pdu_id = REGULAR_STREAM_PDU_ID;
   }

   ret_val = SoAd_IfTransmit(pdu_id, &pdu_info);

   if (E_OK == ret_val)
   {
      Frame_Tx_Success_Cnt++;
   }
   else
   {
      Frame_Tx_Failure_Cnt++;
   }
   return ret_val;
}

#if (defined(CDC_ENABLE))
/******************************************************************************
 *. Name: Config_CDC_Stream
 *.    Provide init params to configure CDC stream (Dynamic stream)
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Config_CDC_Stream(void)
{
   // uint8_t config_result;
   Stream_Init_Cfg_T cdc_init_cfg = {(uint8_t)ALL_CHUNKS, STREAM_DYNAMIC, (uint8_t) true, 0U};
   // config_result                  = Stream_Config_Init(CDC, &cdc_init_cfg);
   (void)Stream_Config_Init(CDC, &cdc_init_cfg);
   /*Use of config_result depends on application requirement*/
}
#endif

#ifdef TRACKER_ENABLED
/******************************************************************************
 *. Name: Config_Tracker_Streams
 *.    Configure tracker streams (TRACKER_INFO, TRACKER_OBJECT) as STREAM_STATIC
 *.    with ALL_CHUNKS to send all data every cycle without requiring Stream_Hdr_T
 *.
 *. Parameters: None
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Config_Tracker_Streams(void)
{
   const bool enable = Is_Tracker_Stream_Applicable();

   Stream_Init_Cfg_T tracker_cfg = {(uint8_t)ALL_CHUNKS, STREAM_STATIC, (uint8_t)enable, 0U};
   (void)Stream_Config_Init(SYNC_INFO, &tracker_cfg);
   (void)Stream_Config_Init(VEHICLE_INFO, &tracker_cfg);
   (void)Stream_Config_Init(TRACKER_INFO, &tracker_cfg);
   (void)Stream_Config_Init(TIMING_INFO, &tracker_cfg);
   (void)Stream_Config_Init(HOST_CALIBS, &tracker_cfg);
   (void)Stream_Config_Init(HOST_PROPS, &tracker_cfg);
   (void)Stream_Config_Init(STATIC_ENV_POLY, &tracker_cfg);
   (void)Stream_Config_Init(FUNCTIONAL_SAFETY_FAULTS, &tracker_cfg);
   (void)Stream_Config_Init(OBJECT_LIST, &tracker_cfg);
   (void)Stream_Config_Init(PROCESSED_DETECTION, &tracker_cfg);
   (void)Stream_Config_Init(SENSOR_CALIB, &tracker_cfg);
   (void)Stream_Config_Init(TRAILER_DETECTOR, &tracker_cfg);
   (void)Stream_Config_Init(CV_TRAILER, &tracker_cfg);

   #if ENABLE_INTERNAL_TRACKER_STREAMS
   (void)Stream_Config_Init(INTERNAL_TRAILER_DETECTOR, &tracker_cfg);
   (void)Stream_Config_Init(INTERNAL_OBJECT, &tracker_cfg);
   (void)Stream_Config_Init(INTERNAL_CLUSTER, &tracker_cfg);
   (void)Stream_Config_Init(INTERNAL_DETECTION_HIST, &tracker_cfg);
   (void)Stream_Config_Init(INTERNAL_REFLECTION_BUFFER, &tracker_cfg);
   (void)Stream_Config_Init(INTERNAL_CWD, &tracker_cfg);
   #endif
}

/******************************************************************************
 *. Name: Is_Tracker_Stream_Applicable
 *.    Check if the tracker stream is enabled for the current radar.
 *.
 *. Parameters: None
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static bool Is_Tracker_Stream_Applicable(void)
{
   #if defined(AL_TRACKER)
   return ((Get_Radar_Position() == RADAR_POSITION_FRONT_CENTER) || (Get_Radar_Position() == RADAR_POSITION_REAR_LEFT));
   #else
   return true;
   #endif
}
#endif

/******************************************************************************
 *. Name: Get_Header_Stream_Ptr
 *.
 *.
 *. Parameters: None
 *. Return Value: Header_Stream_T*
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Header_Stream_T *Get_Header_Stream_Ptr(void)
{
   return &Header_Stream;
}

/******************************************************************************
 *. Name: Get_Status_Stream_Ptr
 *.
 *.
 *. Parameters: None
 *. Return Value: Status_Stream_T*
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
Status_Stream_T *Get_Status_Stream_Ptr(void)
{
   return &Status_Stream;
}

/******************************************************************************
 *. Name: Get_Req_En_Dis_CDC_Stream
 *.
 *.
 *. Parameters: None
 *. Return Value: uint8_t*
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t *Get_Req_En_Dis_CDC_Stream(void)
{
   return &HIL_Req_Stop_CDC;
}

/******************************************************************************
 *. Name: Trigger_XCP_DAQ
 *.
 *.
 *. Parameters: uint8_t look_id, uint8_t event
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/

static void Trigger_XCP_DAQ(uint8_t look_id, uint8_t event)
{
   if (NUM_LOOKS != XCP_Look_Select)
   {
      if (look_id == (uint8_t)XCP_Look_Select)
      {
         /* RDD Event */
         /* Send the event for the look which is selected in Canope */
         (void)Xcp_Event(event);
      }
   }
   else
   {
      /* Send XCP data for every look when no XCP_Look_Select is set in Canope */
      (void)Xcp_Event(event);
   }
}

#ifdef ETH_PERIODIC_TEST_TIME
/******************************************************************************
 *. Name: Get_Elapse_Time_And_Tx_Frames_Logging
 *.
 *.
 *. Parameters: uint8_t *p_eth_timer_index, Eth_Logging_Debug_Info *p_eth_logging_diff, uint64_t eth_logging_start_time_us,
 *Eth_Logging_Debug_Info *p_eth_logging_max, uint16_t source_tx_cnt_start . Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Get_Elapse_Time_And_Tx_Frames_Logging(uint8_t *p_eth_timer_index, Eth_Logging_Debug_Info *p_eth_logging_diff,
                                                  uint64_t eth_logging_start_time_us, Eth_Logging_Debug_Info *p_eth_logging_max,
                                                  uint16_t source_tx_cnt_start)
{
   uint16_t source_tx_cnt_end = 0U;

   const void *ptr[] = {(const void *)p_eth_timer_index, (const void *)p_eth_logging_diff, (const void *)p_eth_logging_max};

   if (NULL_PTR_CHECK(ptr))
   {
      (*p_eth_timer_index)++;
      if (ETH_DEBUG_LOGGING_MAX_ARRAY <= (*p_eth_timer_index))
      {
         *p_eth_timer_index = 0U;
      }

      Get_Platform_Elapsed_ustime(&(p_eth_logging_diff[*p_eth_timer_index].Time_us), eth_logging_start_time_us);

      source_tx_cnt_end = Get_Source_Tx_Cnt();
      if (source_tx_cnt_start <= source_tx_cnt_end)
      {
         p_eth_logging_diff[*p_eth_timer_index].Tx_Frames = source_tx_cnt_end - source_tx_cnt_start;
      }
      else
      {
         p_eth_logging_diff[*p_eth_timer_index].Tx_Frames = ((uint16_t)UNIT16_MAX_VALUE - source_tx_cnt_start) + source_tx_cnt_end;
      }

      if (p_eth_logging_max->Time_us < p_eth_logging_diff[*p_eth_timer_index].Time_us)
      {
         p_eth_logging_max->Time_us   = p_eth_logging_diff[*p_eth_timer_index].Time_us;
         p_eth_logging_max->Tx_Frames = p_eth_logging_diff[*p_eth_timer_index].Tx_Frames;
      }
   }
}
#endif

#if defined(CDC_ENABLE) && defined(UDP_LOGGING_STREAMS_TX_DISABLE)
/******************************************************************************
 *. Name: Set_StreamNum_BitfieldBit
 *.
 *.
 *. Parameters: uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Set_StreamNum_BitfieldBit(uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr)
{
   uint8_t bitfield_idx = stream_num / STREAM_NUM_BITFIELD_WORD_BITS;

   if ((NULL != stream_num_bitfield_ptr) && (bitfield_idx < STREAM_NUM_BITFIELD_WORDS))
   {
      /* set the bit corresponding to stream_num */
      stream_num_bitfield_ptr[bitfield_idx] |= (1U << (stream_num % STREAM_NUM_BITFIELD_WORD_BITS));
   }
}

/******************************************************************************
 *. Name: Clear_StreamNum_BitfieldBit
 *.
 *.
 *. Parameters: uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Clear_StreamNum_BitfieldBit(uint8_t stream_num, volatile uint32_t *stream_num_bitfield_ptr)
{
   uint8_t bitfield_idx = stream_num / STREAM_NUM_BITFIELD_WORD_BITS;

   if ((NULL != stream_num_bitfield_ptr) && (bitfield_idx < STREAM_NUM_BITFIELD_WORDS))
   {
      /* clear the bit corresponding to stream_num */
      stream_num_bitfield_ptr[bitfield_idx] &= ~(1U << (stream_num % STREAM_NUM_BITFIELD_WORD_BITS));
   }
}
#endif

#if (defined(CDC_ENABLE))
/******************************************************************************
 *. Name: Reset_CDC_Radar_Frame_Flags
 *.
 *.
 *.
 * Parameters: Cdc_Frame_Interface_T *cdc_interface_address_ptr
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place
 * references to requirements and design IDs here.
 *.
 *. JIRA Issues:

 * ******************************************************************************/
static void Reset_CDC_Radar_Frame_Flags(Cdc_Frame_Interface_T *cdc_interface_address_ptr)
{
   #if defined(CDC_FRAME_SYNC_VERIFY)
   CDC_Stream_T *CDC_stream_ptr           = NULL;
   CDC_Stream_T *cdc_packet_base_addr_ptr = (CDC_Stream_T *)cdc_interface_address_ptr->cdc_enet_buffer_addr;
   #endif

   /*Check the previous look all frames transmitted or not*/
   if (cdc_interface_address_ptr->cdc_prev_cycle_total_frame_cnt != C0_CDC_Current_Index_Cnt)
   {
      C0_CDC_Current_Index_Error_Cnt++;
   }
   C0_CDC_Current_Index_Cnt = 0U; /*New Look required to start count from 0*/
   C0_CDC_Previous_Index    = 0U; /* New Look requires restarting at index 0 */
   /*if BBE/DSP core reset , need to sync CDC frame with m7 core */
   #ifdef CDC_FRAME_SYNC_VERIFY
   CDC_stream_ptr = (CDC_Stream_T *)&(cdc_packet_base_addr_ptr[0]);
   if (0U == CDC_stream_ptr->dyn_hdr.records_cnt)
   {
      C0_CDC_Frame_Sync_Count = CDC_stream_ptr->dyn_hdr.records_cnt;
   }
   #endif
}
/******************************************************************************
 *. Name: Trigger_CDC_Frames
 *.
 *.
 *.
 * Parameters: uint16_t start_index, uint16_t end_index, CDC_Stream_T * CDC_Data_addr, bool C0_CDC_Radar_Frame_Reset
 *. Return
 * Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:

 * ******************************************************************************/
static void Trigger_CDC_Frames(uint16_t start_index, uint16_t end_index, CDC_Stream_T *CDC_Data_addr, bool CDC_Frame_Reset)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   uint16_t idx                    = 0U;
   Std_ReturnType result           = E_NOT_OK;
   #if defined(CDC_FRAME_SYNC_VERIFY)
   CDC_Stream_T *CDC_stream_ptr = NULL;
   #endif
   #if (defined(VALIDATE_CDC_BUFFER_CRC) && defined(ENABLE_CDC_CRC))
   uint8_t *crc_compute_data_ptr = NULL;
   #endif
   PduInfoType pduInfo;
   pduInfo.SduLength = ETH_DATA_PAYLOAD; /* Length of payload */

   for (idx = start_index; idx < end_index; idx++)
   {
   #ifdef CDC_TOTAL_CHUNK_INDICATION_FROM_DSP
      if ((CDC_Frame_Reset) && (idx == (end_index - LAST_FRAME_INDICATION_CNT)))
      {
         Set_CDC_Last_Chunk_Flag_Of_Current_Cycle(); /* call to enabled the flag to indicate the last of CDC stream */
      }
   #endif
      pduInfo.SduDataPtr = (SduDataPtrType) & (CDC_Data_addr[idx]);
      result             = sh_output_data_ptr->sh_trigger_stream_handler_fptr(CDC, (uint8_t *)pduInfo.SduDataPtr);

      if (E_OK == result)
      {
         C0_CDC_Transmit_Success_Cnt++;
         C0_CDC_Transmitted_In_Cycle_Cnt++;
      }
      else
      {
         C0_CDC_Transmit_Fail_Cnt++;
      }

      /*count transmitted frame for one Look or scan_index */
      C0_CDC_Current_Index_Cnt++;

   #ifdef CDC_FRAME_SYNC_VERIFY
      CDC_stream_ptr = (CDC_Stream_T *)&(CDC_Data_addr[idx]);
      if (C0_CDC_Frame_Sync_Count != CDC_stream_ptr->dyn_hdr.records_cnt)
      {
         C0_CDC_Frame_Sync_Error_Cnt++;
         C0_CDC_Frame_Sync_Count = CDC_stream_ptr->dyn_hdr.records_cnt;
      }
      C0_CDC_Frame_Sync_Count++;
   #endif
   }
}
#endif
/******************************************************************************
 *. Name: Get_Status_Calibration_Disable_CDC_Logging
 *.    Function to get CDC logging disable status.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_Status_Calibration_Disable_CDC_Logging(void)
{
   return K_Disable_CDC_Logging;
}

/******************************************************************************
 *. Name: Udp_Rx_Callback
 *.    Udp Rx callback when the data is received on ethernet
 *.
 *. Parameters: udp_rx_ptr - received data pointer
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Udp_Rx_Callback(const uint8_t *udp_rx_ptr)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   sh_output_data_ptr->sh_udp_rx_callback_update_fptr((uint8_t *)udp_rx_ptr);
}

/******************************************************************************
 *. Name: Get_XCP_Over_ETH_Status
 *.    Function to get XCP over Ethernet.
 *.
 *. Parameters: void
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
bool Get_XCP_Over_ETH_Status(void)
{
   return XCP_Connection_Status;
}

/******************************************************************************
 *. Name: Set_XCP_Over_ETH_Status
 *.    Function to set XCP over Ethernet.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Set_XCP_Over_ETH_Status(bool val)
{
   XCP_Connection_Status = val;
}

#if COMMENTED_SH /* Currently checksum is not calculated so commented. */
/******************************************************************************
 *. Name: Calculate_Checksum
 *.    Function to calculate a checksum.
 *.
 *. Parameters: uint8_t*, uint32_t
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Calculate_Checksum(uint8_t *ptr, uint32_t len)
{
   Stream_Hdr_T *hdr_ptr;
   uint8_t *xsum_ptr;
   uint32_t xsum_len;

   /* stream header is at the beginning */
   hdr_ptr = (Stream_Hdr_T *)(void *)ptr;

   /* offset by stream header */
   xsum_len = len - LOG_DATA_HDR_LEN;
   xsum_ptr = ptr + LOG_DATA_HDR_LEN;

   /* Disable checksum calculation if it takes more time */
   hdr_ptr->size     = xsum_len;
   hdr_ptr->checksum = CalcSum16(xsum_ptr, xsum_len);
}
#endif

#define SWC_PLT_CDD_Logging_STOP_SEC_CODE
#include "SWC_PLT_CDD_Logging_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

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
