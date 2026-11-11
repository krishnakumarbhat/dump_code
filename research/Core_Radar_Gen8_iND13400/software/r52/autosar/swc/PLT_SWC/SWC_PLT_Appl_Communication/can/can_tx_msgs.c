/*===========================================================================*/
/**
 * @file can_tx_msgs.c
 *
 * CAN transmission message composition and handling for radar and tracker signals.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This module handles the composition and transmission of CAN messages containing
 * radar detection reports, tracker objects, alignment status, and capability information.
 * It manages frame construction, signal packing, and CAN TX output for the Core Radar Gen8.
 *
 * @section ABBR ABBREVIATIONS:
 *   - AF: Adaptive Filter
 *   - DS: DownSelection
 *   - DBC: CAN Database
 *   - CAN: Controller Area Network
 *   - ECU: Electronic Control Unit
 *   - IPC: Inter-Processor Communication
 *   - MSS: Master Subsystem
 *   - RDR: Radar
 *   - TOI: Target Of Interest
 *   - VDP: Vehicle Data Port
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Core_Radar_Gen8_CAN_Messaging_Architecture
 *     - SWC_PLT_Appl_Communication_Design
 *
 *   - Requirements Document(s):
 *     - Core_Radar_Gen8_System_Requirements
 *     - CAN_Messaging_Protocol_Specification
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - AUTOSAR C Coding Standards
 *     - CAN Protocol Standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <math.h>
#include <string.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_Appl_Communication.h"
#include "Rte_Type.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Dynamic_alignment_stream.h"
#include "Rte_SWC_PLT_Appl_Diag.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "Rte_SWC_PLT_CDD_Logging.h"
#include "SWC_PLT_CDD_ECUSync.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "SWC_PLT_CDD_Logging.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "can_rx_msgs.h"
#include "can_signals.h"
#include "can_tx_msgs.h"
#if defined(VEH_AL_CAN_STANDALONE)
   #if defined(FEATURE_ENABLE)
      #include "can_tx_msgs_al.h"
   #endif
#endif
#include "dd_mmic.h"
#include "detection_stream.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "mmic_error.h"
#include "mmic_interface.h"
#include "radar_data.h"
#include "radar_sw_config.h"
#include "sensor_position.h"
#include "smc_cal.h"
#include "usc_cal.h"
#include "versions.h"
#include "xcp_bb.h"

/*===========================================================================*
 * Local Preprocessor #define Configurations
 *===========================================================================*/
// #define RADAR_CYCLE_MS_TEMP (50) /* It needs to be removed once RADAR_CYCLE_MS is available*/
#define CONV_PERCENT_TO_VALUE(X)                                                                                                  \
   ((TIMESYNC_CYCLE_TIMERPERIOD_MS) * ((X) / 100.0f)) /* It needs to be removed once RADAR_CYCLE_MS is available*/
#define CONV_VALUE_TO_PERCENT(X)                                                                                                  \
   (((X) * (100.0f)) / (TIMESYNC_CYCLE_TIMERPERIOD_MS)) /* It needs to be removed once RADAR_CYCLE_MS is available*/
#define CONV_US_VALUE_TO_MS(X) ((X) / 1000)

/* macro below helps visualize scan skips on debugger */
// #define DEBUG_SCAN_SKIPS

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define CAN_SIG_NOT_IMPLEMENTED (0)
#define DIV_1000_MS             (20)
#define OP_MODE_CAN_SIG_OFFSET  (1U)
#define SMC_PLATFROM_VERSION    (0xd)
#define DEG_TO_RAD              (3.14159265359f / 180.0f)

#ifdef FLR8
   #define MAX_RDR_DETECTIONS_REPORTS_DBC (400U) /* Max value is 400 as per DBC*/
#elif defined(SRR8P)
   #ifdef VEH_AL_CAN_STANDALONE
      #define MAX_RDR_DETECTIONS_REPORTS_DBC (128U) /* For AL standalone 128 Detections on CAN*/
   #else
      #define MAX_RDR_DETECTIONS_REPORTS_DBC (200U) /* Max Detections on CAN for SRR8p satellite*/
   #endif
#else
   #error "Wrong Radar Variant"
#endif

#define MAX_TRACKER_OBJECT_REPORTS_DBC      (64U) /* Max value is 64 as per DBC */
#define DETECTIONS_PER_FRAME                (4U)
#define MAX_RDR_DETECTIONS_FRAMES_CANTX_DBC (MAX_RDR_DETECTIONS_REPORTS_DBC / DETECTIONS_PER_FRAME)
#define MAX_TARGET_REPORTS_CANTX            (MAX_TARGET_REPORTS / DETECTIONS_PER_FRAME)
#define MAX_TARGET_REPORTS_CANTX_SRR        (64U / DETECTIONS_PER_FRAME)
#define F360

#if (DOWNSELECTION_ENABLE == 1U)
   #define TARGET_REPORT_T          AF_DS_Str_Detection_T
   #define GET_TARGET_REPORT_PTR(x) ((x).downselection_data.af_ds_dets)
   #define STS_SCAN_TYPE(x)         ((x)->payload.downselection_data.det_list_property.look_type)
   #define VALID_DETECTIONS(x)      ((x)->payload.downselection_data.num_af_ds_det)
   #define TOI_DET_STD(x)           ((x)->payload.toi_ds_stream_data.toi_op_data.toi_det_std)
   #define FIRST_PASS(x)            ((x)->payload.downselection_data.det_list_property.num_fp_detections)
   #define SECOND_PASS(x)           ((x)->payload.downselection_data.det_list_property.num_sp_detections)
   #define GET_NUM_DET(x)           ((x)->num_af_ds_det)
   #define START_DWELL(x)           ((x)->payload.rdd_stream_data.look_data.start_dwell_nanosec)
   #define START_DWELL_SEC(x)       ((x)->payload.rdd_stream_data.look_data.start_dwell_sec)
   #define HED_DATA_QUALIFIER(x)                                                                                                  \
      (((x)->payload.toi_ds_stream_data.toi_op_data.data_qualifier) - 1U) // Subtracting 1 to match with DBC's DQ Enum sequence.
   #define MAX_NUM_OF_DETS MAX_TARGET_REPORTS
#else
   #define TARGET_REPORT_T          AF_Str_Detection_T
   #define GET_TARGET_REPORT_PTR(x) ((x).det_data.af_dets)
   #define STS_SCAN_TYPE(x)         ((x)->payload.det_data.det_list_property.look_type)
   #define VALID_DETECTIONS(x)      ((x)->payload.det_data.num_af_det)
   #define TOI_DET_STD(x)           ((x)->payload.toi_stream_data.toi_op_data.toi_det_std)
   #define FIRST_PASS(x)            ((x)->payload.det_data.det_list_property.num_fp_detections)
   #define SECOND_PASS(x)           ((x)->payload.det_data.det_list_property.num_sp_detections)
   #define GET_NUM_DET(x)           ((x)->num_af_det)
   #define START_DWELL(x)           ((x)->payload.rdd_stream_data.look_data.start_dwell_nanosec)
   #define START_DWELL_SEC(x)       ((x)->payload.rdd_stream_data.look_data.start_dwell_sec)
   #define HED_DATA_QUALIFIER(x)    ((x)->payload.toi_stream_data.toi_op_data.data_qualifier)
   #define MAX_NUM_OF_DETS          AF_MAX_NUM_DET
#endif /* (DOWNSELECTION_ENABLE) */

#define MAX_NUM_OF_DETS_SRR 64U
#define TS_GLOBAL_TIME_OUT  (0x01u)
#ifndef NEG_FLOAT
   #define NEG_FLOAT (-1.0f)
#endif

#define SRR8_VARIANT_CAN 0x11U /* Platform variant identifier for SRR8(CAN signal: STS_PLATFORM_VARIANT) */
#define FLR8_VARIANT_CAN 0x12U /* Platform variant identifier for FLR8 (CAN signal: STS_PLATFORM_VARIANT) */
#define S_TO_MS          1000U

/* Macros to facilitate BCD to Decimal Conversion*/
#define BCD_SHIFT 4U
#define BCD_MASK  0x0F
#define BCD_BASE  10U

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define Write_Header_Msg               Rte_Write_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN
#define Write_RDR_Status_Msg_001       Rte_Write_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN
#define Write_RDR_Status_Msg_002       Rte_Write_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL
#define Write_Alignment_Status_Msg_001 Rte_Write_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL
#define Write_Alignment_Status_Msg_002 Rte_Write_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL
#define Write_Capability_Msg           Rte_Write_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL
#define Write_Tracker_Header_Msg       Rte_Write_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader
#define Write_Tracker_Status_Msg       Rte_Write_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus

/* #define Write_Header_Msg_2nd_CAN         Rte_Write_Pp_SG_RadarHeader_2ndCAN_Vdp_SG_RadarHeader_2ndCAN */
/* #define Write_RDR_Status_Msg_001_2nd_CAN Rte_Write_Pp_SG_RadarStatus1_2ndCAN_Vdp_SG_RadarStatus1_2ndCAN */

#define DET_WRITE_CAST(fn) ((Write_Detection_fptr)(fn))
static uint8_t Get_Vehicle_Supply_Vtg(Dt_VBattState_T vbatt);

/* compatibility for USC files that define _USC suffix — expose as _usc */
#if defined(k_Mfg_Sequence_Number_USC) && !defined(k_Mfg_Sequence_Number_usc)
   #define k_Mfg_Sequence_Number_usc k_Mfg_Sequence_Number_USC
#endif

#if defined(k_Julian_Production_Date_USC) && !defined(k_Julian_Production_Date_usc)
   #define k_Julian_Production_Date_usc k_Julian_Production_Date_USC
#endif

#if defined(k_Julian_Year_USC) && !defined(k_Julian_Year_usc)
   #define k_Julian_Year_usc k_Julian_Year_USC
#endif

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef FUNC(Std_ReturnType, RTE_CODE) (*Write_Detection_fptr)(P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC,
                                                                       RTE_SWC_PLT_CDD_SPT_IPC_APPL_DATA) data);

typedef FUNC(Std_ReturnType, RTE_CODE) (*Write_TrackerObject_fptr)(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC,
                                                                           RTE_SWC_PLT_CDD_SPT_IPC_APPL_DATA) data);

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
bool FactoryAlignRunning  = true;
volatile int ts_test_stub = 0;

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if defined(FEATURE_ENABLE)
Self_Feature_Degradation_Params_T Feature_Degradation_Params;
#endif
static I_SG_Detections_001_004_AL Radar_Detection_Signals[MAX_TARGET_REPORTS_CANTX];

#ifndef VEH_AL_CAN_STANDALONE
static Write_Detection_fptr Write_Radar_Detection_Signals[] = {
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL)};
#else
static Write_Detection_fptr Write_Radar_Detection_Signals[] = {
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL),
   DET_WRITE_CAST(Rte_Write_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL)};
#endif

#ifdef TRACKER_ENABLED
static Write_TrackerObject_fptr Write_Tracker_Object_Signals[] = {
   Rte_Write_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001, Rte_Write_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002,
   Rte_Write_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003, Rte_Write_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004,
   Rte_Write_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005, Rte_Write_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006,
   Rte_Write_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007, Rte_Write_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008,
   Rte_Write_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009, Rte_Write_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010,
   Rte_Write_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011, Rte_Write_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012,
   Rte_Write_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013, Rte_Write_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014,
   Rte_Write_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015, Rte_Write_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016,
   Rte_Write_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017, Rte_Write_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018,
   Rte_Write_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019, Rte_Write_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020,
   Rte_Write_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021, Rte_Write_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022,
   Rte_Write_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023, Rte_Write_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024,
   Rte_Write_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025, Rte_Write_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026,
   Rte_Write_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027, Rte_Write_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028,
   Rte_Write_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029, Rte_Write_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030,
   Rte_Write_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031, Rte_Write_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032,
   Rte_Write_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033, Rte_Write_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034,
   Rte_Write_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035, Rte_Write_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036,
   Rte_Write_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037, Rte_Write_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038,
   Rte_Write_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039, Rte_Write_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040,
   Rte_Write_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041, Rte_Write_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042,
   Rte_Write_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043, Rte_Write_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044,
   Rte_Write_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045, Rte_Write_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046,
   Rte_Write_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047, Rte_Write_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048,
   Rte_Write_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049, Rte_Write_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050,
   Rte_Write_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051, Rte_Write_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052,
   Rte_Write_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053, Rte_Write_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054,
   Rte_Write_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055, Rte_Write_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056,
   Rte_Write_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057, Rte_Write_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058,
   Rte_Write_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059, Rte_Write_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060,
   Rte_Write_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061, Rte_Write_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062,
   Rte_Write_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063, Rte_Write_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064};
#endif
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static uint8_t Get_Operation_Mode(Dt_SystemOperationMode op_mode);
static uint32_t BCD_To_Decimal(uint32_t bcd);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Get_Radar_Detection_Signals_Ptr
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Points to the list of radar detection signals to be sent on CAN
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
static I_SG_Detections_001_004_AL *Get_Radar_Detection_Signals_Ptr(void)
{
   return (&Radar_Detection_Signals[0]);
}

/*===========================================================================*\
 * FUNCTION: Init_Radar_Detection_Signals
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * - Radar_Detection_Signals: Global array of radar detection signals
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function initializes the Radar_Detection_Signals array by setting all
 * its elements to zero.
 *
 * DESCRIPTION:
 * - Uses memset to efficiently set all bytes of Radar_Detection_Signals to 0
 * - The size of the array is determined using sizeof()
 *
 * NOTES:
 * - This function should be called before any operations on
 *   Radar_Detection_Signals to ensure a clean initial state
 * - The function is static, indicating it's only used within its own
 *   translation unit
 *
\*===========================================================================*/
static void Init_Radar_Detection_Signals(void)
{
   memset((void *)&Radar_Detection_Signals[0], 0U, sizeof(Radar_Detection_Signals));
}

/*===========================================================================*\
 * FUNCTION: modify_status
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * uint32_t *
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Get the start dwell status for start acquisition stage
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
void modify_status(uint32_t *status)
{
   /* This function modifies the value pointed to by status. */
   if (ts_test_stub == 1)
   {
      *status = 8;
   }
   else if (ts_test_stub == 2)
   {
      *status = 9;
   }
   else
   {
      *status = 0;
   }
}

/*===========================================================================*\
 * FUNCTION: Send_Radar_Header_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Header messages InformationDetections, TimeStamps,
 * CompensatedSysStatus, AlignmentState, SensorCoverage, SensorPosition
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
__attribute__((optnone)) void Send_Radar_Header_Messages(void)
{
#if (0U != DEBUG_SCAN_SKIPS)
   static uint16_t scan_index_prv = 0U;
   static uint16_t buf_init_cnt   = 0;
   uint16_t temp;
#endif

   I_SG_RadarHeader_ALPCAN Rdr_Header_Messages;
   uint32_t status = 0x0;

   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   uint8_t radar_pos = Get_Radar_Position();
#if defined(FEATURE_ENABLE)
   Platform_fault_T *pflttbl_ptr   = Get_Platform_Active_Fault_Table();
   volatile M2D_Msg_T *m2d_buf_ptr = Get_MSS_IPC_M2D_Msg_Buffer();
#endif

#if (0U != DEBUG_SCAN_SKIPS)
   if (d2m_buf_ptr != NULL)
   {
      if (buf_init_cnt < 2)
      {
         /* for initial ping pong buffers */
         buf_init_cnt++;
      }
      else
      {
         /* below code catches scan index skips */
         temp = scan_index_prv + Scan_Id_Delta;

         if (temp != d2m_buf_ptr->payload.rdd_stream_data.look_data.scan_index)
         {
            /* skips observed */
            Scan_Id_Skip_Cnt++;
            Scan_Id_Skip_Latch = true;
         }

         scan_index_prv = d2m_buf_ptr->payload.rdd_stream_data.look_data.scan_index;
      }
   }
#endif
   if (d2m_buf_ptr != NULL)
   {
#if (STD_ON == ENABLE_SQT_TEST_STUBS)
      modify_status(&status);
#else
      status                                         = d2m_buf_ptr->payload.det_data.det_list_property.timestamp_status;
#endif

      Dt_SystemOperationMode hdr_operation_mode = 0;
      Rte_Read_Rp_OperationMode_System_De_OperationMode_System(&hdr_operation_mode);
      float32_t hdr_phy_sig;
      float hdr_range_max                                = Init_Fixed_Point(0, u9p7_T);
      float hdr_range_min                                = Init_Fixed_Point(0, u9p7_T);
      float hdr_dop_max                                  = Init_Fixed_Point(0, s7p8_T);
      float hdr_dop_min                                  = Init_Fixed_Point(0, s7p8_T);
      float hdr_r_wrapping                               = 0.0f;
      float hdr_v_wrapping                               = 0.0f;
      DRA_Core_Log_Data_T *hdr_dra_ptr                   = &d2m_buf_ptr->payload.dynamic_alignment_log_stream.dra_core_data;
      Radar_Look_T hdr_look_type                         = (Radar_Look_T)d2m_buf_ptr->payload.rdd_stream_data.look_data.look_id;
      volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_Onetime_Msg_Buffer();
      Sensor_Calib_Data_T *const sensor_data_buf =
         (Sensor_Calib_Data_T *const)&(m2d_one_time_init_ptr->calib_data.sensor_calib_data);
      if (hdr_look_type <= RADAR_LOOK_D)
      {
         hdr_range_max  = k_detection_range_max_smc[(uint8_t)hdr_look_type];
         hdr_range_min  = k_detection_range_min_smc[(uint8_t)hdr_look_type];
         hdr_dop_max    = k_detection_range_rate_max_smc[(uint8_t)hdr_look_type];
         hdr_dop_min    = k_detection_range_rate_min_smc[(uint8_t)hdr_look_type];
         hdr_r_wrapping = k_rwrapping_smc[(uint8_t)hdr_look_type];
         hdr_v_wrapping = k_vwrapping_smc[(uint8_t)hdr_look_type];
      }
      /* DET_RANGE_MAX */
      hdr_phy_sig                           = FXP2FLP_Fnc(hdr_range_max, BPP_u9p7_T, SIGNED_u9p7_T);
      hdr_phy_sig                           = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_DET_RANGE_MAX);
      Rdr_Header_Messages.HED_DET_RANGE_MAX = Init_Pos_Fixed_Point(hdr_phy_sig, u16p0_T);
      /* DET_RANGE_MIN */
      hdr_phy_sig                           = FXP2FLP_Fnc(hdr_range_min, BPP_u9p7_T, SIGNED_u9p7_T);
      hdr_phy_sig                           = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_DET_RANGE_MIN);
      Rdr_Header_Messages.HED_DET_RANGE_MIN = Init_Pos_Fixed_Point(hdr_phy_sig, u16p0_T);
      /* DET_SPEED_RANGE_MAX */
      hdr_phy_sig                                 = FXP2FLP_Fnc(hdr_dop_max, BPP_s7p8_T, SIGNED_s7p8_T);
      hdr_phy_sig                                 = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_DET_SPEED_RANGE_MAX);
      Rdr_Header_Messages.HED_DET_SPEED_RANGE_MAX = Init_Pos_Fixed_Point(hdr_phy_sig, u16p0_T);
      /* DET_SPEED_RANGE_MIN */
      hdr_phy_sig                                 = FXP2FLP_Fnc(hdr_dop_min, BPP_s7p8_T, SIGNED_s7p8_T);
      hdr_phy_sig                                 = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_DET_SPEED_RANGE_MIN);
      Rdr_Header_Messages.HED_DET_SPEED_RANGE_MIN = Init_Pos_Fixed_Point(hdr_phy_sig, u16p0_T);
      /* HED_R_WRAPPING */
      hdr_phy_sig                        = FXP2FLP_Fnc(hdr_r_wrapping, BPP_s0p31_T, SIGNED_s0p31_T);
      hdr_phy_sig                        = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_R_WRAPPING);
      Rdr_Header_Messages.HED_R_WRAPPING = Init_Pos_Fixed_Point(hdr_phy_sig, u8p0_T);
      /* HED_V_WRAPPING */
      hdr_phy_sig                        = FXP2FLP_Fnc(hdr_v_wrapping, BPP_s10p21_T, SIGNED_s10p21_T);
      hdr_phy_sig                        = CAN_TX_SIGNAL_CORRECTION(hdr_phy_sig, HED_V_WRAPPING);
      Rdr_Header_Messages.HED_V_WRAPPING = Init_Pos_Fixed_Point(hdr_phy_sig, u16p0_T);
      /* HED_FOV_HOR_MAX */
      hdr_phy_sig                         = CAN_TX_SIGNAL_CORRECTION(sensor_data_buf->k_fov_hor_end, HED_FOV_HOR_MAX);
      Rdr_Header_Messages.HED_FOV_HOR_MAX = Init_Pos_Fixed_Point(hdr_phy_sig, u8p0_T);
      /* HED_FOV_HOR_MIN */
      hdr_phy_sig                         = CAN_TX_SIGNAL_CORRECTION(sensor_data_buf->k_fov_hor_begin, HED_FOV_HOR_MIN);
      Rdr_Header_Messages.HED_FOV_HOR_MIN = Float2Fix(hdr_phy_sig, s7p0_T);
      /* HED_FOV_VER_MAX */
      hdr_phy_sig                         = CAN_TX_SIGNAL_CORRECTION(sensor_data_buf->k_fov_ver_end, HED_FOV_VER_MAX);
      Rdr_Header_Messages.HED_FOV_VER_MAX = Init_Pos_Fixed_Point(hdr_phy_sig, u8p0_T);
      /* HED_FOV_VER_MIN */
      hdr_phy_sig                         = CAN_TX_SIGNAL_CORRECTION(sensor_data_buf->k_fov_ver_begin, HED_FOV_VER_MIN);
      Rdr_Header_Messages.HED_FOV_VER_MIN = Float2Fix(hdr_phy_sig, s7p0_T);
      Rdr_Header_Messages.HED_LOOK_ID     = d2m_buf_ptr->payload.rdd_stream_data.look_data.look_id;
      Rdr_Header_Messages.HED_SCAN_INDEX  = d2m_buf_ptr->payload.rdd_stream_data.look_data.scan_index;
      Rdr_Header_Messages.HED_LOOK_INDEX  = d2m_buf_ptr->payload.rdd_stream_data.look_data.look_index;
      Rdr_Header_Messages.HED_NUM_OF_VALID_DETECTIONS = VALID_DETECTIONS(d2m_buf_ptr);
      if (!(FactoryAlignRunning))
      {
         /* Rdr_Header_Messages.HED_ALIGN_VER_QF  = CAN_SIG_NOT_IMPLEMENTED; same */
         Rdr_Header_Messages.HED_ALIGN_VER_REF = CAN_SIG_NOT_IMPLEMENTED;
         Rdr_Header_Messages.HED_ALIGN_HOR_REF = CAN_SIG_NOT_IMPLEMENTED;
         /* Rdr_Header_Messages.HED_ALIGN_HOR_QF  = CAN_SIG_NOT_IMPLEMENTED; same */
      }
      else
      {
         /* Rdr_Header_Messages.HED_ALIGN_HOR_QF  = CAN_SIG_NOT_IMPLEMENTED; same */
         Rdr_Header_Messages.HED_ALIGN_VER_REF = hdr_dra_ptr->vacs_boresight_el_kf_internal;
         Rdr_Header_Messages.HED_ALIGN_HOR_REF = hdr_dra_ptr->vacs_boresight_az_kf_internal;
         /* Rdr_Header_Messages.HED_ALIGN_VER_QF  = CAN_SIG_NOT_IMPLEMENTED; same */
      }
      Rdr_Header_Messages.HED_SENSOR_TIME_STAMP_NS  = START_DWELL(d2m_buf_ptr);
      Rdr_Header_Messages.HED_SENSOR_TIME_STAMP_SEC = START_DWELL_SEC(d2m_buf_ptr);
      Rdr_Header_Messages.HED_OPERATION_MODE        = Get_Operation_Mode(hdr_operation_mode);
      Rdr_Header_Messages.HED_DET_BI_STATIC_COUNT   = CAN_SIG_NOT_IMPLEMENTED;
      Rdr_Header_Messages.HED_DET_NUM_OF_1PASS      = FIRST_PASS(d2m_buf_ptr);
      Rdr_Header_Messages.HED_DET_NUM_OF_2PASS      = SECOND_PASS(d2m_buf_ptr);
      Rdr_Header_Messages.HED_NUM_OF_RESTBINS_USED  = CAN_SIG_NOT_IMPLEMENTED;

      if ((SRR_L1 == radar_pos) || (SRR_L2 == radar_pos))
      {
         Rdr_Header_Messages.HED_MAX_NUM_OF_DETECTIONS = MAX_NUM_OF_DETS_SRR;
      }
      else
      {
         Rdr_Header_Messages.HED_MAX_NUM_OF_DETECTIONS = MAX_NUM_OF_DETS;
      }

      Rdr_Header_Messages.HED_PROCESSED_RANGE          = CAN_SIG_NOT_IMPLEMENTED;
      Rdr_Header_Messages.HED_SLOPE_CORR_EXECUTIONFLAG = CAN_SIG_NOT_IMPLEMENTED;
      /* Rdr_Header_Messages.HED_INTRFC_VERSION_ID_MAJOR  = CAN_SIG_NOT_IMPLEMENTED; same */
      /* Rdr_Header_Messages.HED_INTRFC_VERSION_ID_MINOR  = CAN_SIG_NOT_IMPLEMENTED; same */
      /* Rdr_Header_Messages.HED_INTRFC_VERSION_ID_PATCH  = CAN_SIG_NOT_IMPLEMENTED; same */
      Rdr_Header_Messages.HED_DATA_QUALIFIER = HED_DATA_QUALIFIER(d2m_buf_ptr);
      Rdr_Header_Messages.HED_TRIGGER_TIME   = CAN_SIG_NOT_IMPLEMENTED;
   }
   if ((TS_POWER_ON_STATUS) == (status))
   {
      Rdr_Header_Messages.HED_TIME_SYNC_VALIDITY_FLAG = TS_SOURCE_LOCAL;
   }
   else
   {
      if ((TS_STBM_LSB) & (status))
      {
         Rdr_Header_Messages.HED_TIME_SYNC_SRC_MASTER = TS_SOURCE_LOCAL;
      }
      else
      {
         Rdr_Header_Messages.HED_TIME_SYNC_SRC_MASTER = TS_SOURCE_GLOBAL;
      }
   }
   /* when bit-3 is 1 and bit-0 is 0 */
   if (!((status)&TS_GLOBAL_TIME_OUT) && ((status)&TS_GLOBAL_TIME_BASE))
   {
      /* Status = 8 (Synchronized, No Timeout) → VALID */
      Rdr_Header_Messages.HED_TIME_SYNC_VALIDITY_FLAG = Cx1_SYNCED_AT_LEAST_ONCE;
   }
   /* when both bit-3 is 1 and bit-0 is 1 */
   else if (((status)&TS_GLOBAL_TIME_OUT) && ((status)&TS_GLOBAL_TIME_BASE))
   {
      /* Status = 9 (Synchronized, Timeout/CRC) → INVALID */
      Rdr_Header_Messages.HED_TIME_SYNC_VALIDITY_FLAG = Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR;
   }
   /* when both bit-3 is 0 and bit-0 is 0 */
   else
   {
      /* Status = 0 (not synced) → INVALID */
      Rdr_Header_Messages.HED_TIME_SYNC_VALIDITY_FLAG = Cx0_OUT_OF_SYNC;
   }

   Write_Header_Msg(&Rdr_Header_Messages);

#ifdef VEH_AL_CAN_STANDALONE
   #if defined(FEATURE_ENABLE)
   Feature_Degradation_Params.self_time_sync_validity_flag = Rdr_Header_Messages.HED_TIME_SYNC_VALIDITY_FLAG;
   Feature_Degradation_Params.self_op_mode                 = Rdr_Header_Messages.HED_OPERATION_MODE;
   Feature_Degradation_Params.self_align_init_calib_flag = pflttbl_ptr->Platform_Bits.alignment_no_initial_calibration_error_fault;

   m2d_buf_ptr->payload.feature_input.mois_feat_degrade_flag =
      (CODED_TRUE == FC_MOIS_Feature_Degradation_Check(Feature_Degradation_Params)) ? CODED_TRUE : CODED_FALSE;
   m2d_buf_ptr->payload.feature_input.bsis_feat_degrade_flag =
      (CODED_TRUE == L2_BSIS_Feature_Degradation_Check(Feature_Degradation_Params)) ? CODED_TRUE : CODED_FALSE;
   m2d_buf_ptr->payload.feature_input.bsis_feat_degrade_flag =
      (CODED_TRUE == m2d_buf_ptr->payload.feature_input.bsis_feat_degrade_flag) ? CODED_TRUE : Get_L1_BSIS_Degradation_Flag_Sts();
   #endif
#endif
}

/*===========================================================================*\
 * FUNCTION: Send_Radar_Status_001_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Status messages Radar, Status_CalibrationVersion, Status_MountingPos
 * SerialNumber, HwVersion, CalVersion, SwVersion
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_Radar_Status_001_Messages(void)
{
   static uint8_t counter_50ms = 0;

   float phy_signal                                   = 0.0F;
   uint32_t year_temp                                 = 0U;
   D2M_Msg_T *d2m_buf_ptr                             = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_Onetime_Msg_Buffer();
   volatile Sensor_Calib_Data_T *sensor_data_buf      = &(m2d_one_time_init_ptr->calib_data.sensor_calib_data);
   volatile Vehicle_Calib_Data_T *vehicle_data_buf    = &(m2d_one_time_init_ptr->calib_data.vehicle_calib_data);
   Platform_fault_T *pflttbl_ptr                      = Get_Platform_Active_Fault_Table();
   Dt_SystemOperationMode hdr_operation_mode          = 0;
   Rte_Read_Rp_OperationMode_System_De_OperationMode_System(&hdr_operation_mode);
   if (0 == counter_50ms % DIV_1000_MS)
   {
      float32_t sts_phy;
      I_SG_RadarStatus1_ALPCAN Rdr_Status_001_Messages;
      const Application_Version_T *sts_app_ver    = Get_Application_Version();
      const Bootloader_Version_T *sts_blr_ver     = Get_Bootloader_Version();
      const Application_Version_T *sts_app_data   = Get_Application_Version();
      uint8_t sts_radar_pos                       = Get_Radar_Position();
      Rdr_Status_001_Messages.STS_SENSOR_POSITION = sts_radar_pos;
      /* "z_pos" assigned to "height" directly as the "z_pos" is in ISO co-ordinate system, which is z-axis pointing towards sky */
      sts_phy                                     = sensor_data_buf->sensor_mount_data.k_sensor_mount_pos_z;
      sts_phy                                     = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_HEIGHT);
      (Rdr_Status_001_Messages).STS_SENSOR_HEIGHT = Init_Pos_Fixed_Point(sts_phy, u32p0_T);

      sts_phy                                               = sensor_data_buf->sensor_mount_data.k_sensor_mount_ornt_pitch;
      sts_phy                                               = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_ORNT_PITCH);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_ORNT_PITCH = Float2Fix(sts_phy, s15p0_T);

      sts_phy                                              = sensor_data_buf->sensor_mount_data.k_sensor_mount_ornt_roll;
      sts_phy                                              = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_ORNT_ROLL);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_ORNT_ROLL = Init_Pos_Fixed_Point(sts_phy, u16p0_T);

      sts_phy                                             = sensor_data_buf->sensor_mount_data.k_sensor_mount_ornt_yaw;
      sts_phy                                             = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_ORNT_YAW);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_ORNT_YAW = Float2Fix(sts_phy, s15p0_T);

      sts_phy                                          = sensor_data_buf->sensor_mount_data.k_sensor_mount_pos_x;
      sts_phy                                          = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_POS_X);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_POS_X = Float2Fix(sts_phy, s15p0_T);

      sts_phy                                          = sensor_data_buf->sensor_mount_data.k_sensor_mount_pos_y;
      sts_phy                                          = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_POS_Y);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_POS_Y = Float2Fix(sts_phy, s15p0_T);

      sts_phy                                          = sensor_data_buf->sensor_mount_data.k_sensor_mount_pos_z;
      sts_phy                                          = CAN_TX_SIGNAL_CORRECTION(sts_phy, STS_SENSOR_MOUNT_POS_Z);
      (Rdr_Status_001_Messages).STS_SENSOR_MOUNT_POS_Z = Float2Fix(sts_phy, s15p0_T);

      (Rdr_Status_001_Messages).STS_SENSOR_POLARITY =
         ((int8_t)m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll < 0.1F ?
             (int8_t)(0) :
             (int8_t)(1));

      (Rdr_Status_001_Messages).STS_PBL_VERSION_FIELD1      = sts_blr_ver->major;
      (Rdr_Status_001_Messages).STS_PBL_VERSION_FIELD2      = sts_blr_ver->minor;
      (Rdr_Status_001_Messages).STS_PBL_VERSION_FIELD3      = sts_blr_ver->patch;
      (Rdr_Status_001_Messages).STS_PBL_VERSION_FIELD4      = Get_Operation_Mode(hdr_operation_mode);
      (Rdr_Status_001_Messages).STS_SW_VERSION_FIELD1       = sts_app_ver->variant;
      (Rdr_Status_001_Messages).STS_SW_VERSION_FIELD2       = sts_app_ver->major;
      (Rdr_Status_001_Messages).STS_SW_VERSION_FIELD3       = sts_app_ver->minor;
      (Rdr_Status_001_Messages).STS_SW_VERSION_FIELD4       = sts_app_ver->patch;
      (Rdr_Status_001_Messages).STS_DET_DBC_BASE_VER_MAJOR  = pflttbl_ptr->Platform_byte[0U];
      (Rdr_Status_001_Messages).STS_DET_DBC_BASE_VER_MINOR  = pflttbl_ptr->Platform_byte[2U];
      (Rdr_Status_001_Messages).STS_PCAN_PROTOCOL_VER_MAJOR = DET_DBC_BASE_VERSION_MAJOR;
      (Rdr_Status_001_Messages).STS_PCAN_PROTOCOL_VER_MINOR = DET_DBC_BASE_VERSION_MINOR;

      memcpy(&Rdr_Status_001_Messages.STS_SERIAL_NUMBER_SEQUENCE, &pflttbl_ptr->Platform_byte[4U], sizeof(uint8_t));

#ifdef SRR8P
      (Rdr_Status_001_Messages).STS_PLATFORM_VARIANT = SRR8_VARIANT_CAN;
#elif defined(FLR8)
      (Rdr_Status_001_Messages).STS_PLATFORM_VARIANT = FLR8_VARIANT_CAN;
#else
      (Rdr_Status_001_Messages).STS_PLATFORM_VARIANT = 0U;
#endif

      (Rdr_Status_001_Messages).STS_HARDWARE_VERSION = sts_app_data->board_type;
      //(Rdr_Status_001_Messages).STS_SERIAL_NUMBER_SEQUENCE = BCD_To_Decimal(k_Mfg_Sequence_Number_usc);
      (Rdr_Status_001_Messages).STS_SERIAL_NUM_JULIAN_DAY = BCD_To_Decimal(k_Julian_Production_Date_usc);
      /* Convert Julian year from BCD to decimal, then extract last digit */
      year_temp = BCD_To_Decimal(k_Julian_Year_usc);
      year_temp %= (uint32_t)10U;
      (Rdr_Status_001_Messages).STS_SERIAL_NUM_JULIAN_YEAR = year_temp;
      (Rdr_Status_001_Messages).STS_SMC_SECTION_COMPTBLITY = Get_SMC_Cal_Major();
      (Rdr_Status_001_Messages).STS_SMC_PLATFROM_VERSION   = Get_SMC_Cal_Platform();
      (Rdr_Status_001_Messages).STS_SMC_CAL_VER_MAJOR      = Get_SMC_Cal_Minor();
      (Rdr_Status_001_Messages).STS_SMC_CAL_VER_MINOR      = Get_SMC_Cal_Patch();
      (Rdr_Status_001_Messages).STS_USC_SECTION_COMPTBLITY = Get_USC_Cal_Major();
      (Rdr_Status_001_Messages).STS_USC_CAL_VER_MAJOR      = Get_USC_Cal_Minor();
      (Rdr_Status_001_Messages).STS_USC_CAL_VER_MINOR      = Get_USC_Cal_Patch();

      memcpy(&Rdr_Status_001_Messages.STS_TIME_SINCE_POWER_ON, &pflttbl_ptr->Platform_byte[14U], sizeof(uint16_t));

      // Rdr_Status_001_Messages.STS_VIN_Status = pflttbl_ptr->Platform_byte[9U];;

      /* STS_DIST_FRNT_BMPR_TO_RR_AXL */
      phy_signal                                           = vehicle_data_buf->k_distance_front_bumper_to_rear_axle;
      phy_signal                                           = CAN_TX_SIGNAL_CORRECTION(phy_signal, STS_DIST_FRNT_BMPR_TO_RR_AXL);
      Rdr_Status_001_Messages.STS_DIST_FRNT_BMPR_TO_RR_AXL = Init_Pos_Fixed_Point(phy_signal, u16p0_T);

      // if (NULL != d2m_buf_ptr)
      if (0)
      {
         phy_signal                               = d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_inst * (S_TO_MS);
         phy_signal                               = CAN_TX_SIGNAL_CORRECTION(phy_signal, STS_AF_TIME_INST);
         Rdr_Status_001_Messages.STS_AF_TIME_INST = Init_Pos_Fixed_Point(phy_signal, u8p0_T);

         phy_signal                               = d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_peak * (S_TO_MS);
         phy_signal                               = CAN_TX_SIGNAL_CORRECTION(phy_signal, STS_AF_TIME_PEAK);
         Rdr_Status_001_Messages.STS_AF_TIME_PEAK = Init_Pos_Fixed_Point(phy_signal, u8p0_T);
      }
      else
      {
         Rdr_Status_001_Messages.STS_AF_TIME_INST = pflttbl_ptr->Platform_byte[5U];
         Rdr_Status_001_Messages.STS_AF_TIME_PEAK = pflttbl_ptr->Platform_byte[7U];
      }
      if (0)
      {
         Dt_CPU_Load cpu_load_primary = {0};
         (void)Rte_Read_Rp_CPU_Load_De_CPU_Load(&cpu_load_primary);
         Rdr_Status_001_Messages.STS_MAIN_CORE_TIME_INST = cpu_load_primary.CPU_Load;
         Rdr_Status_001_Messages.STS_MAIN_CORE_TIME_PEAK = cpu_load_primary.CPU_Load_Max;
      }
      else
      {
         Rdr_Status_001_Messages.STS_MAIN_CORE_TIME_INST = pflttbl_ptr->Platform_byte[8U];
         Rdr_Status_001_Messages.STS_MAIN_CORE_TIME_PEAK = pflttbl_ptr->Platform_byte[9U];
      }
      Rdr_Status_001_Messages.STS_RDD_CORE_TIME_INST = pflttbl_ptr->Platform_byte[10U];
      Rdr_Status_001_Messages.STS_RDD_CORE_TIME_PEAK = pflttbl_ptr->Platform_byte[11U];
      Rdr_Status_001_Messages.STS_SP_CORE_TIME_INST  = pflttbl_ptr->Platform_byte[12U];
      Rdr_Status_001_Messages.STS_SP_CORE_TIME_PEAK  = pflttbl_ptr->Platform_byte[13U];

      Write_RDR_Status_Msg_001(&Rdr_Status_001_Messages);
      counter_50ms = 0;
   }
   counter_50ms++;
}

/*===========================================================================*\
 * FUNCTION: Send_Radar_Status_002_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Status messages Radar, Status_CalibrationVersion, Status_MountingPos
 * SerialNumber, HwVersion, CalVersion, SwVersion
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_Radar_Status_002_Messages(void)
{
   float32_t phy_signal = 0.0F;
   uint32_t status      = 0x0;
   bool udp_logging_status, xcp_ovr_enet_status;
   float32_t rdr_mmic_temp_data_float, af_xput_inst_data;
   I_SG_RadarStatus2_AL Rdr_Status_002_Messages;
   Dt_VBattState_T vbatt                 = {0};
   D2M_Msg_T *d2m_buf_ptr                = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   volatile M2D_Msg_T *m2d_buf_ptr       = Get_MSS_IPC_M2D_Msg_Buffer();
   volatile float32_t *mcu_temp_data_ptr = Get_XCP_MCU_Temperature_Data();
   Platform_fault_T *pflttbl_ptr         = Get_Platform_Active_Fault_Table();

   Rte_Read_SWC_PLT_Appl_Communication_Rp_Vbatt_State_De_Vbatt_State(&vbatt);

   if (NULL != d2m_buf_ptr)
   {
      Rdr_Status_002_Messages.STS_SCAN_TYPE = STS_SCAN_TYPE(d2m_buf_ptr);
      status                                = d2m_buf_ptr->payload.det_data.det_list_property.timestamp_status;
      af_xput_inst_data = CONV_VALUE_TO_PERCENT(((d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_inst) * (1000U)));
      phy_signal        = CAN_TX_SIGNAL_CORRECTION(af_xput_inst_data, STS_AF_CORE_THROUGHPUT);
      Rdr_Status_002_Messages.STS_AF_CORE_THROUGHPUT = Init_Pos_Fixed_Point(phy_signal, u8p0_T);
   }
   else
   {
      Rdr_Status_002_Messages.STS_AF_CORE_THROUGHPUT = CAN_SIG_NOT_IMPLEMENTED;
   }

   Rdr_Status_002_Messages.STS_MMIC_RE_INIT_COUNT = Get_MMIC_Error_Reinit_Count();

   Rdr_Status_002_Messages.STS_XCVR_OPERATIONAL = (RADAR_CTL_INIT_SUCCESS == Get_Radar_Ctl_Init_Status()) ? true : false;

   phy_signal =
      CAN_TX_SIGNAL_CORRECTION(m2d_buf_ptr->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground, STS_VEHICLE_SPEED_CALC);
   Rdr_Status_002_Messages.STS_VEHICLE_SPEED_CALC = Init_Pos_Fixed_Point(phy_signal, u16p0_T);

   phy_signal                                = m2d_buf_ptr->payload.veh_data.vse_output.yaw_rate_bias;
   phy_signal                                = CAN_TX_SIGNAL_CORRECTION(phy_signal, STS_YAW_RATE_BIAS);
   Rdr_Status_002_Messages.STS_YAW_RATE_BIAS = Init_Pos_Fixed_Point(phy_signal, u8p0_T);

   Rdr_Status_002_Messages.STS_VEH_SPEED_DIRECTION = (m2d_buf_ptr->payload.veh_data.vse_output.reverse_status) ? 1 : 0;

   Rdr_Status_002_Messages.STS_VEHICLE_SUPPLY_VOLTAGE = Get_Vehicle_Supply_Vtg(vbatt);

   if ((m2d_buf_ptr->payload.veh_data.vse_output.comp_steering_angle_deg) < 0.0f)
   {
      Rdr_Status_002_Messages.STS_STEERING_ANGLE_SIGN = true;
   }
   else
   {
      Rdr_Status_002_Messages.STS_STEERING_ANGLE_SIGN = false;
   }
   phy_signal = CAN_TX_SIGNAL_CORRECTION(fabsf(m2d_buf_ptr->payload.veh_data.vse_output.comp_steering_angle_deg * DEG_TO_RAD),
                                         STS_STEERING_ANGLE);
   Rdr_Status_002_Messages.STS_STEERING_ANGLE = Init_Pos_Fixed_Point(phy_signal, u8p0_T);
   Rdr_Status_002_Messages.STS_Gear_Position  = m2d_buf_ptr->payload.veh_data.veh_raw_misc.gear_pos;

   Rdr_Status_002_Messages.STS_POINT_OF_TRIGGER = CAN_SIG_NOT_IMPLEMENTED;

   /* when bit-3 is 1 and bit-0 is 0 */
   if (!(status & TS_GLOBAL_TIME_OUT) && (status & TS_GLOBAL_TIME_BASE))
   {
      Rdr_Status_002_Messages.STS_NO_TSYN_ERROR = 1;
   }
   /* when both bit-3 is 1 and bit-0 is 1 */
   /* when both bit-3 is 0 and bit-0 is 0 */
   else
   {
      Rdr_Status_002_Messages.STS_NO_TSYN_ERROR = 0;
   }

   /* link is up */
   /*udp_logging_status = Get_Stream_Recording_Status();*/
   udp_logging_status  = 0;
   xcp_ovr_enet_status = Get_XCP_Over_ETH_Status();
   if (udp_logging_status || xcp_ovr_enet_status)
   {
      /* udp logging or xcp over enet is enabled */
      Rdr_Status_002_Messages.STS_BRR_STATUS = STS_BRR_STATUS_LINK_UP_SERVICES_ENABLED;
   }
   else
   {
      /* udp logging or xcp over enet is disabled */
      Rdr_Status_002_Messages.STS_BRR_STATUS = STS_BRR_STATUS_LINK_UP_SERVICES_DISABLED;
   }

   rdr_mmic_temp_data_float             = *mcu_temp_data_ptr;
   rdr_mmic_temp_data_float             = CAN_TX_SIGNAL_CORRECTION(rdr_mmic_temp_data_float, STS_MCU_TEMP);
   Rdr_Status_002_Messages.STS_MCU_TEMP = Init_Pos_Fixed_Point(rdr_mmic_temp_data_float, u8p0_T);

   /* STS_MMIC_TEMP_RX */
   rdr_mmic_temp_data_float                 = Fix2Float(Get_MMIC_Temp_Rx0(), s15p0_T);
   rdr_mmic_temp_data_float                 = CAN_TX_SIGNAL_CORRECTION(rdr_mmic_temp_data_float, STS_MMIC_TEMP_RX);
   Rdr_Status_002_Messages.STS_MMIC_TEMP_RX = Init_Pos_Fixed_Point(rdr_mmic_temp_data_float, u8p0_T);

   /* STS_MMIC_TEMP_TX0 */
   rdr_mmic_temp_data_float                  = Fix2Float(Get_MMIC_Temp_Tx0(), s15p0_T);
   rdr_mmic_temp_data_float                  = CAN_TX_SIGNAL_CORRECTION(rdr_mmic_temp_data_float, STS_MMIC_TEMP_TX0);
   Rdr_Status_002_Messages.STS_MMIC_TEMP_TX0 = Init_Pos_Fixed_Point(rdr_mmic_temp_data_float, u8p0_T);

   /* STS_MMIC_TEMP_TX1_2 */
   rdr_mmic_temp_data_float                    = Fix2Float(Get_MMIC_Temp_Tx1(), s15p0_T);
   rdr_mmic_temp_data_float                    = CAN_TX_SIGNAL_CORRECTION(rdr_mmic_temp_data_float, STS_MMIC_TEMP_TX1_2);
   Rdr_Status_002_Messages.STS_MMIC_TEMP_TX1_2 = Init_Pos_Fixed_Point(rdr_mmic_temp_data_float, u8p0_T);

   /* STS_MMIC_TEMP_TX3_4 */
   rdr_mmic_temp_data_float                    = Fix2Float(Get_MMIC_Temp_Tx3(), s15p0_T);
   rdr_mmic_temp_data_float                    = CAN_TX_SIGNAL_CORRECTION(rdr_mmic_temp_data_float, STS_MMIC_TEMP_TX3_4);
   Rdr_Status_002_Messages.STS_MMIC_TEMP_TX3_4 = Init_Pos_Fixed_Point(rdr_mmic_temp_data_float, u8p0_T);
   /* Rdr_Status_002_Messages.STS_CORE_ACTIVE_FAULTS = CAN_SIG_NOT_IMPLEMENTED; same */
   /* STS_RAIN_COUNT*/
   Rdr_Status_002_Messages.STS_RAIN_COUNT = CAN_SIG_NOT_IMPLEMENTED;

   memcpy(&Rdr_Status_002_Messages.STS_CORE_ACTV_FLT_BYTE_0_to_3, &pflttbl_ptr->Platform_byte[0U], sizeof(uint32_t));

   memcpy(&Rdr_Status_002_Messages.STS_CORE_ACTV_FLT_BYTE_4_to_7, &pflttbl_ptr->Platform_byte[4U], sizeof(uint32_t));

   memcpy(&Rdr_Status_002_Messages.STS_CORE_ACTV_FLT_BYTE_8_to_11, &pflttbl_ptr->Platform_byte[8U], sizeof(uint32_t));

   memcpy(&Rdr_Status_002_Messages.STS_CORE_ACTV_FLT_BYTE_11_to_15, &pflttbl_ptr->Platform_byte[12U], sizeof(uint32_t));

   Write_RDR_Status_Msg_002(&Rdr_Status_002_Messages);
}

/*===========================================================================*\
 * FUNCTION: Send_Alignment_Status_001_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Status messages alignment_handler, alignment_auto
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_Alignment_Status_001_Messages(void)
{
   I_SG_AlignmentStatus1_AL Alignment_Status_001_Messages = {0};
   float32_t rdr_alignment_data_float;
   float32_t rdr_align_msg_auto_data_float;

   rdr_alignment_data_float                           = Get_AlignmentHandler()->AlignmentAzimuth;
   rdr_alignment_data_float                           = CAN_TX_SIGNAL_CORRECTION(rdr_alignment_data_float, STS_AlignmentAzimuth);
   Alignment_Status_001_Messages.STS_AlignmentAzimuth = Float2Fix(rdr_alignment_data_float, s15p0_T);

   /* STS_AlignmentElevation */
   rdr_alignment_data_float = Get_AlignmentHandler()->AlignmentElevation;
   rdr_alignment_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_alignment_data_float, STS_AlignmentElevation);
   Alignment_Status_001_Messages.STS_AlignmentElevation = Float2Fix(rdr_alignment_data_float, s15p0_T);

   /* STS_AzimuthStd */
   rdr_alignment_data_float                     = Get_AlignmentHandler()->AzimuthStd;
   rdr_alignment_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_alignment_data_float, STS_AzimuthStd);
   Alignment_Status_001_Messages.STS_AzimuthStd = Init_Pos_Fixed_Point(rdr_alignment_data_float, u16p0_T);

   /* STS_ElevationStd */
   rdr_alignment_data_float                       = Get_AlignmentHandler()->ElevationStd;
   rdr_alignment_data_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_alignment_data_float, STS_ElevationStd);
   Alignment_Status_001_Messages.STS_ElevationStd = Init_Pos_Fixed_Point(rdr_alignment_data_float, u16p0_T);

   /* STS_InitAlignRsltHostSpdCompFac */
   rdr_alignment_data_float = Get_AlignmentHandler()->InitialAlignmentResultHostSCF;
   rdr_alignment_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_alignment_data_float, STS_InitAlignRsltHostSpdCompFac);
   Alignment_Status_001_Messages.STS_InitAlignRsltHostSpdCompFac = Init_Pos_Fixed_Point(rdr_alignment_data_float, u8p0_T);

   /* STS_AlignmentError */
   Alignment_Status_001_Messages.STS_AlignmentError = (uint8_t)Get_AlignmentHandler()->AlignmentError;

   /* STS_AlignmentModeIn */
   Alignment_Status_001_Messages.STS_AlignmentModeIn = Get_AlignmentHandler()->Alignment_modeIn;

   /* STS_AlignmentModeOut */
   Alignment_Status_001_Messages.STS_AlignmentModeOut = Get_AlignmentHandler()->AlignmentModeOut;

   /* STS_CalDisplay */
   Alignment_Status_001_Messages.STS_CalDisplay = (bool)Get_AlignmentHandler()->CalDisplay;

   /* STS_CalTime */
   Alignment_Status_001_Messages.STS_CalTime = Init_Pos_Fixed_Point(Get_AlignmentHandler()->calTime, u16p0_T);

   /* STS_CoordinateSystemInput */
   Alignment_Status_001_Messages.STS_CoordinateSystemInput = (uint8_t)Get_AlignmentHandler()->CoordinateSystem_Input;

   /* STS_InitAlignmentResultAzimuth */
   Alignment_Status_001_Messages.STS_InitAlignmentResultAzimuth =
      Float2Fix(Get_AlignmentHandler()->InitialAlignmentResultAz, s7p0_T);

   /* STS_InitAlignmentResultElevation */
   Alignment_Status_001_Messages.STS_InitAlignmentResultElevation =
      Float2Fix(Get_AlignmentHandler()->InitialAlignmentResultEl, s7p0_T);

   /* STS_InitAlignResultAzimuthUpdate */
   Alignment_Status_001_Messages.STS_InitAlignResultAzimuthUpdate = Get_AlignmentHandler()->InitialAlignmentResultAzUpdates;

   /* STS_InitAlignRsltElevationUpdate */
   Alignment_Status_001_Messages.STS_InitAlignRsltElevationUpdate = Get_AlignmentHandler()->InitialAlignmentResultElUpdates;

   /* STS_InitLastSuccessfulAlignMode */
   Alignment_Status_001_Messages.STS_InitLastSuccessfulAlignMode = Get_AlignmentHandler()->InitialLastSuccessAlignmentMode;

   /* STS_ProgressPercent */
   Alignment_Status_001_Messages.STS_ProgressPercent = Get_AlignmentHandler()->ProgressPercent;

   /* STS_RadarTypeInput */
   Alignment_Status_001_Messages.STS_RadarTypeInput = Get_AlignmentHandler()->Radar_Type_Input;

   /* STS_AACurrentAzimuth */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->AACurrentAzimuth;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AACurrentAzimuth);
   Alignment_Status_001_Messages.STS_AACurrentAzimuth = Float2Fix(rdr_align_msg_auto_data_float, s15p0_T);

   /* STS_AACurrentElevation */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->AACurrentElevation;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AACurrentElevation);
   Alignment_Status_001_Messages.STS_AACurrentElevation = Float2Fix(rdr_align_msg_auto_data_float, s15p0_T);

   /* STS_AAElevationStd */
   rdr_align_msg_auto_data_float                    = Get_AlignmentAuto()->AAElevationStd;
   rdr_align_msg_auto_data_float                    = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AAElevationStd);
   Alignment_Status_001_Messages.STS_AAElevationStd = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u16p0_T);

   /* STS_AAAzimuthStd */
   rdr_align_msg_auto_data_float                  = Get_AlignmentAuto()->AAAzimuthStd;
   rdr_align_msg_auto_data_float                  = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AAAzimuthStd);
   Alignment_Status_001_Messages.STS_AAAzimuthStd = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u16p0_T);

   /* STS_AARoll_Std */
   rdr_align_msg_auto_data_float                = Get_AlignmentAuto()->AARollStd;
   rdr_align_msg_auto_data_float                = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AARoll_Std);
   Alignment_Status_001_Messages.STS_AARoll_Std = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u16p0_T);

   /* STS_AlignmentAutoStatus */
   Alignment_Status_001_Messages.STS_AlignmentAutoStatus = (uint8_t)Get_AlignmentAuto()->AlignAutoStatus;

   /* STS_AutoAlignmentFailRootCause */
   Alignment_Status_001_Messages.STS_AutoAlignmentFailRootCause = Get_AlignmentAuto()->AutoAlignmentFailRootCause;

   /* STS_AzimuthErrorNegative */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->Az_Err_negative;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AzimuthErrorNegative);
   Alignment_Status_001_Messages.STS_AzimuthErrorNegative = Float2Fix(rdr_align_msg_auto_data_float, s15p0_T);

   /* STS_AzimuthErrorPositive */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->Az_Err_positive;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_AzimuthErrorPositive);
   Alignment_Status_001_Messages.STS_AzimuthErrorPositive = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u16p0_T);

   /* STS_AzimuthUpdates */
   Alignment_Status_001_Messages.STS_AzimuthUpdates = Get_AlignmentAuto()->AzimuthNumUpdates;

   /* STS_ElevationErrorNegative */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->El_Err_negative;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_ElevationErrorNegative);
   Alignment_Status_001_Messages.STS_ElevationErrorNegative = Float2Fix(rdr_align_msg_auto_data_float, s7p0_T);

   /* STS_ElevationErrorPositive */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->El_Err_positive;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_ElevationErrorPositive);
   Alignment_Status_001_Messages.STS_ElevationErrorPositive = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u8p0_T);

   /* STS_ElevationUpdates */
   Alignment_Status_001_Messages.STS_ElevationUpdates = Get_AlignmentAuto()->ElevationNumUpdates;

   /* STS_HostSpdCompensationFactorQF */
   Alignment_Status_001_Messages.STS_HostSpdCompensationFactorQF = Get_AlignmentAuto()->HostScf_QF;

   /* STS_HostSpeedCompensationFactor */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->HostScf;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_HostSpeedCompensationFactor);
   Alignment_Status_001_Messages.STS_HostSpeedCompensationFactor = Init_Pos_Fixed_Point(rdr_align_msg_auto_data_float, u8p0_T);

   /* STS_RollErrorPositive */
   rdr_align_msg_auto_data_float = Get_AlignmentAuto()->RollError_positive;
   rdr_align_msg_auto_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_auto_data_float, STS_RollErrorPositive);
   Alignment_Status_001_Messages.STS_RollErrorPositive = Float2Fix(rdr_align_msg_auto_data_float, s15p0_T);

   /* STS_StartAzimuth */
   Alignment_Status_001_Messages.STS_StartAzimuth = Float2Fix(Get_AlignmentAuto()->StartAzimuth, s15p0_T);

   /* STS_StartElevation */
   Alignment_Status_001_Messages.STS_StartElevation = Float2Fix(Get_AlignmentAuto()->StartElevation, s15p0_T);

   Write_Alignment_Status_Msg_001(&Alignment_Status_001_Messages);
}

/*===========================================================================*\
 * FUNCTION: Send_Alignment_Status_002_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Status messages Alignment static, auto, short track
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_Alignment_Status_002_Messages(void)
{
   I_SG_AlignmentStatus2_AL Alignment_Status_002_Messages = {0};
   float32_t rdr_align_msg_static_float;

   Alignment_Status_002_Messages.STS_AlignmentStaticStatus = Get_AlignmentStatic()->AlignmentStaticStatus;
   Alignment_Status_002_Messages.STS_ImpactByInterference  = Get_AlignmentStatic()->ImpactByInterference;
   Alignment_Status_002_Messages.STS_Measured_Range        = Init_Pos_Fixed_Point(Get_AlignmentStatic()->MeasuredRange, u16p0_T);
   Alignment_Status_002_Messages.STS_MeasuredRangeStd = Init_Pos_Fixed_Point(Get_AlignmentStatic()->MeasuredRangeStd, u16p0_T);

   /* STS_MeasuredRangeRate */
   rdr_align_msg_static_float = Get_AlignmentStatic()->MeasuredRangeRate;
   rdr_align_msg_static_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_static_float, STS_MeasuredRangeRate);
   Alignment_Status_002_Messages.STS_MeasuredRangeRate = Float2Fix(rdr_align_msg_static_float, s7p0_T);

   /* STS_MeasuredRangeRateStd */
   rdr_align_msg_static_float = Get_AlignmentStatic()->MeasuredRangeRateStd;
   rdr_align_msg_static_float = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_static_float, STS_MeasuredRangeRateStd);
   Alignment_Status_002_Messages.STS_MeasuredRangeRateStd = Init_Pos_Fixed_Point(rdr_align_msg_static_float, u16p0_T);

   /* STS_MeasuredRawAmplitude */
   Alignment_Status_002_Messages.STS_MeasuredRawAmplitude = Float2Fix(Get_AlignmentStatic()->MeasuredAmplitude, s15p0_T);

   /* STS_MeasuredAmpSTD */
   rdr_align_msg_static_float                       = Get_AlignmentStatic()->MeasuredAmpStd;
   rdr_align_msg_static_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_align_msg_static_float, STS_MeasuredRCSStd);
   Alignment_Status_002_Messages.STS_MeasuredAmpSTD = Init_Pos_Fixed_Point(rdr_align_msg_static_float, u16p0_T);

   Alignment_Status_002_Messages.STS_AlignmentServiceStatus    = (uint8_t)Get_AlignmentService()->AlignmentServiceSt;
   Alignment_Status_002_Messages.STS_AverageNumberOfDetections = (uint16_t)Get_AlignmentService()->AvgNumOfDet;
   Alignment_Status_002_Messages.STS_AverageSpeed              = Float2Fix(Get_AlignmentService()->AverageSpeed, s15p0_T);
   Alignment_Status_002_Messages.STS_DistanceAbsolute  = Init_Pos_Fixed_Point(Get_AlignmentService()->DistanceAbsolute, u32p0_T);
   Alignment_Status_002_Messages.STS_DistanceEffective = Init_Pos_Fixed_Point(Get_AlignmentService()->DistanceEffective, u32p0_T);
   Alignment_Status_002_Messages.STS_DurationAbsolute  = Init_Pos_Fixed_Point(Get_AlignmentService()->DurationAbsolute, u32p0_T);
   Alignment_Status_002_Messages.STS_DurationEffective = Init_Pos_Fixed_Point(Get_AlignmentService()->DurationEffective, u32p0_T);
   Alignment_Status_002_Messages.STS_VehicleCondition  = Get_AlignmentService()->VehicleCondition;

   Alignment_Status_002_Messages.STS_AlignmentShortTrackStatus = (uint8_t)Get_AlignmentShortTrack()->AlignShortTrackSt;

   Write_Alignment_Status_Msg_002(&Alignment_Status_002_Messages);
}

/*===========================================================================*\
 * FUNCTION: Send_Radar_Capability_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the messages performance, Damping, Range detection, SIL monitor
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Send_Radar_Capability_Messages(void)
{
   D2M_Msg_T *D2M_target_report_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   float32_t rdr_cap_msg_data_float;
   I_SG_RadarCapability_AL Rdr_Capability_Messages = {0};

   if (NULL != D2M_target_report_ptr)
   {
      Rdr_Capability_Messages.CAP_BlockageActive = D2M_target_report_ptr->payload.radar_capability_data.blockage.blockage_active;
      Rdr_Capability_Messages.CAP_BlockageProbability =
         D2M_target_report_ptr->payload.radar_capability_data.blockage.blockage.probability;
      Rdr_Capability_Messages.CAP_BlockageSensitivity = D2M_target_report_ptr->payload.radar_capability_data.sensitivity_level;
      Rdr_Capability_Messages.CAP_BlockageStatus = D2M_target_report_ptr->payload.radar_capability_data.blockage.blockage_status;
      Rdr_Capability_Messages.CAP_BlockageValue  = D2M_target_report_ptr->payload.radar_capability_data.blockage.blockage.value;
      Rdr_Capability_Messages.CAP_FreeSightCheckActive  = D2M_target_report_ptr->payload.radar_capability_data.fsc.run_status;
      Rdr_Capability_Messages.CAP_FreeSightCheckStatus  = D2M_target_report_ptr->payload.radar_capability_data.fsc.fault_status;
      Rdr_Capability_Messages.CAP_SLBlockageFilterValue = CAN_SIG_NOT_IMPLEMENTED;
      Rdr_Capability_Messages.CAP_SLBlockageFlag        = CAN_SIG_NOT_IMPLEMENTED;

      /* CAP_DampingCurrent */
      rdr_cap_msg_data_float                     = D2M_target_report_ptr->payload.radar_capability_data.dm.damping.current_dB;
      rdr_cap_msg_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_cap_msg_data_float, CAP_DampingCurrent);
      Rdr_Capability_Messages.CAP_DampingCurrent = Init_Pos_Fixed_Point(rdr_cap_msg_data_float, u16p0_T);

      Rdr_Capability_Messages.CAP_DampingActive = D2M_target_report_ptr->payload.radar_capability_data.dm.dm_active;
      Rdr_Capability_Messages.CAP_DampingStandardDeviation =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.dm.damping.std_dB, u8p0_T);
      Rdr_Capability_Messages.CAP_DampingStatus = D2M_target_report_ptr->payload.radar_capability_data.dm.dm_status;

      Rdr_Capability_Messages.CAP_AngleAzimuthRangeEnd =
         Float2Fix(D2M_target_report_ptr->payload.radar_capability_data.az_fov_end_rad[0], s15p0_T);
      Rdr_Capability_Messages.CAP_AngleAzimuthRangeStart =
         Float2Fix(D2M_target_report_ptr->payload.radar_capability_data.az_fov_begin_rad[0], s15p0_T);
      Rdr_Capability_Messages.CAP_MaxDetectionRangeCar_0 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_car[0], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetectionRangeCar_1 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_car[1], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetectionRangeCar_2 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_car[2], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangeMotorbike_0 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_motorbike[0], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangeMotorbike_1 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_motorbike[1], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangeMotorbike_2 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_motorbike[2], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangePedestrian_0 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_pedestrian[0], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangePedestrian_1 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_pedestrian[1], u16p0_T);
      Rdr_Capability_Messages.CAP_MaxDetRangePedestrian_2 =
         Init_Pos_Fixed_Point(D2M_target_report_ptr->payload.radar_capability_data.re.max_det_range_pedestrian[2], u16p0_T);
      Rdr_Capability_Messages.CAP_RangeEstimationActive = D2M_target_report_ptr->payload.radar_capability_data.re.re_active;
      Rdr_Capability_Messages.CAP_RangeEstimationStatus = D2M_target_report_ptr->payload.radar_capability_data.re.re_status;
      Rdr_Capability_Messages.CAP_SideLobeLevelBeamformer =
         D2M_target_report_ptr->payload.radar_capability_data.pbd.az_sector[0].side_lobe_level;
      Rdr_Capability_Messages.CAP_SLLMonitoringActive = D2M_target_report_ptr->payload.radar_capability_data.pbd.pbd_active;
      Rdr_Capability_Messages.CAP_SLLMonitoringStatus = D2M_target_report_ptr->payload.radar_capability_data.pbd.status;
   }
   Write_Capability_Msg(&Rdr_Capability_Messages);
}

/*===========================================================================*\
 * FUNCTION: Send_Radar_Detection_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:Populate radar detections information from Core2
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
void Send_Radar_Detection_Messages(void)
{
   uint32_t det_idx_ipc             = 0;
   uint16_t det_idx                 = 0;
   static uint16_t det_transmit_max = 0;
   float32_t rdr_detn_data_float;
   uint8_t radar_pos = Get_Radar_Position();
   I_SG_Detections_001_004_AL *Radar_Detection_Messages;
   volatile M2D_Msg_T *m2d_buf_ptr  = Get_MSS_IPC_M2D_Msg_Buffer();
   D2M_Msg_T *D2M_target_report_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   Radar_Detection_Messages         = Get_Radar_Detection_Signals_Ptr();

   if ((D2M_target_report_ptr != NULL) && (m2d_buf_ptr != NULL))
   {
      /* dbc supports max 400 detections. limiting to 400 detections in cases AF / Down Selected Detections is more than 400 */
      if (MAX_RDR_DETECTIONS_FRAMES_CANTX_DBC <= MAX_TARGET_REPORTS_CANTX)
      {
         /* TODO: This case should not occur -- add assert. Ideally the Down selected detections and Dbc detections should match */
         det_transmit_max = MAX_RDR_DETECTIONS_FRAMES_CANTX_DBC;
      }
      else
      {
         det_transmit_max = MAX_TARGET_REPORTS_CANTX;
      }

      if ((SRR_L1 == radar_pos) || (SRR_L2 == radar_pos))
      {
         det_transmit_max = MAX_TARGET_REPORTS_CANTX_SRR;
      }

      Init_Radar_Detection_Signals();
      TARGET_REPORT_T *af_target_report_ptr = GET_TARGET_REPORT_PTR(D2M_target_report_ptr->payload);

      for (det_idx = 0; det_idx < det_transmit_max; det_idx++)
      {
         det_idx_ipc = det_idx * DETECTIONS_PER_FRAME;

         /* DET_RANGE */
         rdr_detn_data_float                     = af_target_report_ptr[det_idx_ipc].ran;
         rdr_detn_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE);
         Radar_Detection_Messages->DET_RANGE_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_ERR */
         rdr_detn_data_float                         = TOI_DET_STD(D2M_target_report_ptr).std_ran[det_idx_ipc];
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_ERR);
         Radar_Detection_Messages->DET_RANGE_ERR_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_RANGE_VELOCITY */
         rdr_detn_data_float                              = af_target_report_ptr[det_idx_ipc].vel;
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_VELOCITY_ERR */
         rdr_detn_data_float = TOI_DET_STD(D2M_target_report_ptr).std_vel[det_idx_ipc];
         rdr_detn_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY_ERR);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_ERR_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_AZIMUTH */
         rdr_detn_data_float                       = af_target_report_ptr[det_idx_ipc].theta;
         rdr_detn_data_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH);
         Radar_Detection_Messages->DET_AZIMUTH_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_AZIMUTH_ERR */
         rdr_detn_data_float                           = TOI_DET_STD(D2M_target_report_ptr).std_theta[det_idx_ipc];
         rdr_detn_data_float                           = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH_ERR);
         Radar_Detection_Messages->DET_AZIMUTH_ERR_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION */
         rdr_detn_data_float                         = af_target_report_ptr[det_idx_ipc].phi;
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION);
         Radar_Detection_Messages->DET_ELEVATION_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION_ERR */
         rdr_detn_data_float                             = TOI_DET_STD(D2M_target_report_ptr).std_phi[det_idx_ipc];
         rdr_detn_data_float                             = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION_ERR);
         Radar_Detection_Messages->DET_ELEVATION_ERR_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_EXISTENCE_PROB */
         rdr_detn_data_float                              = TOI_DET_STD(D2M_target_report_ptr).existence_prob[det_idx_ipc];
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_EXISTENCE_PROB);
         Radar_Detection_Messages->DET_EXISTENCE_PROB_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* Radar_Detection_Messages->DET_POINT_TARGET_PROB_001 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_RCS */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].rcs;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RCS);
         Radar_Detection_Messages->DET_RCS_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_SNR */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].snr;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_SNR);
         Radar_Detection_Messages->DET_SNR_001 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_BI_STATIC_FLAG */
         Radar_Detection_Messages->DET_BI_STATIC_FLAG_001 = af_target_report_ptr[det_idx_ipc].f_bistatic;

         /* DET_CONFD_AZIMUTH */
         Radar_Detection_Messages->DET_CONFD_AZIMUTH_001 = af_target_report_ptr[det_idx_ipc].az_conf;

         /* DET_CONFD_ELEVATION */
         Radar_Detection_Messages->DET_CONFD_ELEVATION_001 = af_target_report_ptr[det_idx_ipc].el_conf;

         /* Radar_Detection_Messages->DET_VALID_FLAG_001 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_SUPER_RES_TARGET */
         Radar_Detection_Messages->DET_SUPER_RES_TARGET_001 = af_target_report_ptr[det_idx_ipc].f_superres_target;

         /* DET_HOST_VEH_CLUTTER */
         Radar_Detection_Messages->DET_HVC_FLAG_001 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_BELOW_RAIN_THOLD */
         Radar_Detection_Messages->DET_BELOW_RAIN_THOLD_001 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_IDM */
         Radar_Detection_Messages->DET_IDM_001 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_MTD */
         Radar_Detection_Messages->DET_MTD_001 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_PROB_1STAZHYPO */
         Radar_Detection_Messages->DET_PROB_1STAZHYPO_001 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_OUTSIDE_SECTOR -TBD */
         /* Radar_Detection_Messages->DET_OUTSIDE_SECTOR_001 = CAN_SIG_NOT_IMPLEMENTED; same */

         det_idx_ipc++;

         /* DET_RANGE */
         rdr_detn_data_float                     = af_target_report_ptr[det_idx_ipc].ran;
         rdr_detn_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE);
         Radar_Detection_Messages->DET_RANGE_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_ERR */
         rdr_detn_data_float                         = TOI_DET_STD(D2M_target_report_ptr).std_ran[det_idx_ipc];
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_ERR);
         Radar_Detection_Messages->DET_RANGE_ERR_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_RANGE_VELOCITY */
         rdr_detn_data_float                              = af_target_report_ptr[det_idx_ipc].vel;
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_VELOCITY_ERR */
         rdr_detn_data_float = TOI_DET_STD(D2M_target_report_ptr).std_vel[det_idx_ipc];
         rdr_detn_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY_ERR);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_ERR_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_AZIMUTH */
         rdr_detn_data_float                       = af_target_report_ptr[det_idx_ipc].theta;
         rdr_detn_data_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH);
         Radar_Detection_Messages->DET_AZIMUTH_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_AZIMUTH_ERR */
         rdr_detn_data_float                           = TOI_DET_STD(D2M_target_report_ptr).std_theta[det_idx_ipc];
         rdr_detn_data_float                           = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH_ERR);
         Radar_Detection_Messages->DET_AZIMUTH_ERR_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION */
         rdr_detn_data_float                         = af_target_report_ptr[det_idx_ipc].phi;
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION);
         Radar_Detection_Messages->DET_ELEVATION_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION_ERR */
         rdr_detn_data_float                             = TOI_DET_STD(D2M_target_report_ptr).std_phi[det_idx_ipc];
         rdr_detn_data_float                             = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION_ERR);
         Radar_Detection_Messages->DET_ELEVATION_ERR_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_EXISTENCE_PROB */
         rdr_detn_data_float                              = TOI_DET_STD(D2M_target_report_ptr).existence_prob[det_idx_ipc];
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_EXISTENCE_PROB);
         Radar_Detection_Messages->DET_EXISTENCE_PROB_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* Radar_Detection_Messages->DET_POINT_TARGET_PROB_002 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_RCS */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].rcs;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RCS);
         Radar_Detection_Messages->DET_RCS_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_SNR */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].snr;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_SNR);
         Radar_Detection_Messages->DET_SNR_002 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_BI_STATIC_FLAG */
         Radar_Detection_Messages->DET_BI_STATIC_FLAG_002 = af_target_report_ptr[det_idx_ipc].f_bistatic;

         /* DET_CONFD_AZIMUTH */
         Radar_Detection_Messages->DET_CONFD_AZIMUTH_002 = af_target_report_ptr[det_idx_ipc].az_conf;

         /* DET_CONFD_ELEVATION */
         Radar_Detection_Messages->DET_CONFD_ELEVATION_002 = af_target_report_ptr[det_idx_ipc].el_conf;

         /* DET_VALID_FLAG - Can be removed as per discussion with AF team */
         /* Radar_Detection_Messages->DET_VALID_FLAG_002 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_SUPER_RES_TARGET */
         Radar_Detection_Messages->DET_SUPER_RES_TARGET_002 = af_target_report_ptr[det_idx_ipc].f_superres_target;

         /* DET_HOST_VEH_CLUTTER */
         Radar_Detection_Messages->DET_HVC_FLAG_002 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_BELOW_RAIN_THOLD */
         Radar_Detection_Messages->DET_BELOW_RAIN_THOLD_002 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_IDM */
         Radar_Detection_Messages->DET_IDM_002 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_MTD */
         Radar_Detection_Messages->DET_MTD_002 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_PROB_1STAZHYPO */
         Radar_Detection_Messages->DET_PROB_1STAZHYPO_002 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_OUTSIDE_SECTOR -TBD */
         /* Radar_Detection_Messages->DET_OUTSIDE_SECTOR_002 = CAN_SIG_NOT_IMPLEMENTED; same */

         det_idx_ipc++;

         /* DET_RANGE */
         rdr_detn_data_float                     = af_target_report_ptr[det_idx_ipc].ran;
         rdr_detn_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE);
         Radar_Detection_Messages->DET_RANGE_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_ERR */
         rdr_detn_data_float                         = TOI_DET_STD(D2M_target_report_ptr).std_ran[det_idx_ipc];
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_ERR);
         Radar_Detection_Messages->DET_RANGE_ERR_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_RANGE_VELOCITY */
         rdr_detn_data_float                              = af_target_report_ptr[det_idx_ipc].vel;
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_VELOCITY_ERR */
         rdr_detn_data_float = TOI_DET_STD(D2M_target_report_ptr).std_vel[det_idx_ipc];
         rdr_detn_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY_ERR);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_ERR_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_AZIMUTH */
         rdr_detn_data_float                       = af_target_report_ptr[det_idx_ipc].theta;
         rdr_detn_data_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH);
         Radar_Detection_Messages->DET_AZIMUTH_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_AZIMUTH_ERR */
         rdr_detn_data_float                           = TOI_DET_STD(D2M_target_report_ptr).std_theta[det_idx_ipc];
         rdr_detn_data_float                           = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH_ERR);
         Radar_Detection_Messages->DET_AZIMUTH_ERR_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION */
         rdr_detn_data_float                         = af_target_report_ptr[det_idx_ipc].phi;
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION);
         Radar_Detection_Messages->DET_ELEVATION_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION_ERR */
         rdr_detn_data_float                             = TOI_DET_STD(D2M_target_report_ptr).std_phi[det_idx_ipc];
         rdr_detn_data_float                             = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION_ERR);
         Radar_Detection_Messages->DET_ELEVATION_ERR_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_EXISTENCE_PROB */
         rdr_detn_data_float                              = TOI_DET_STD(D2M_target_report_ptr).existence_prob[det_idx_ipc];
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_EXISTENCE_PROB);
         Radar_Detection_Messages->DET_EXISTENCE_PROB_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_POINT_TARGET_PROB */
         /* Radar_Detection_Messages->DET_POINT_TARGET_PROB_003 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_RCS */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].rcs;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RCS);
         Radar_Detection_Messages->DET_RCS_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_SNR */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].snr;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_SNR);
         Radar_Detection_Messages->DET_SNR_003 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_BI_STATIC_FLAG */
         Radar_Detection_Messages->DET_BI_STATIC_FLAG_003 = af_target_report_ptr[det_idx_ipc].f_bistatic;

         /* DET_CONFD_AZIMUTH */
         Radar_Detection_Messages->DET_CONFD_AZIMUTH_003 = af_target_report_ptr[det_idx_ipc].az_conf;

         /* DET_CONFD_ELEVATION */
         Radar_Detection_Messages->DET_CONFD_ELEVATION_003 = af_target_report_ptr[det_idx_ipc].el_conf;

         /* DET_VALID_FLAG - Can be removed as per discussion with AF team */
         /* Radar_Detection_Messages->DET_VALID_FLAG_003 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_SUPER_RES_TARGET */
         Radar_Detection_Messages->DET_SUPER_RES_TARGET_003 = af_target_report_ptr[det_idx_ipc].f_superres_target;

         /* DET_HOST_VEH_CLUTTER */
         Radar_Detection_Messages->DET_HVC_FLAG_003 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_BELOW_RAIN_THOLD */
         Radar_Detection_Messages->DET_BELOW_RAIN_THOLD_003 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_IDM */
         Radar_Detection_Messages->DET_IDM_003 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_MTD */
         Radar_Detection_Messages->DET_MTD_003 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_PROB_1STAZHYPO */
         Radar_Detection_Messages->DET_PROB_1STAZHYPO_003 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_OUTSIDE_SECTOR -TBD */
         /* Radar_Detection_Messages->DET_OUTSIDE_SECTOR_003 = CAN_SIG_NOT_IMPLEMENTED; same */

         det_idx_ipc++;

         /* DET_RANGE */
         rdr_detn_data_float                     = af_target_report_ptr[det_idx_ipc].ran;
         rdr_detn_data_float                     = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE);
         Radar_Detection_Messages->DET_RANGE_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_ERR */
         rdr_detn_data_float                         = TOI_DET_STD(D2M_target_report_ptr).std_ran[det_idx_ipc];
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_ERR);
         Radar_Detection_Messages->DET_RANGE_ERR_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_RANGE_VELOCITY */
         rdr_detn_data_float                              = af_target_report_ptr[det_idx_ipc].vel;
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_RANGE_VELOCITY_ERR */
         rdr_detn_data_float = TOI_DET_STD(D2M_target_report_ptr).std_vel[det_idx_ipc];
         rdr_detn_data_float = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RANGE_VELOCITY_ERR);
         Radar_Detection_Messages->DET_RANGE_VELOCITY_ERR_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_AZIMUTH */
         rdr_detn_data_float                       = af_target_report_ptr[det_idx_ipc].theta;
         rdr_detn_data_float                       = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH);
         Radar_Detection_Messages->DET_AZIMUTH_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u16p0_T);

         /* DET_AZIMUTH_ERR */
         rdr_detn_data_float                           = TOI_DET_STD(D2M_target_report_ptr).std_theta[det_idx_ipc];
         rdr_detn_data_float                           = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_AZIMUTH_ERR);
         Radar_Detection_Messages->DET_AZIMUTH_ERR_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION */
         rdr_detn_data_float                         = af_target_report_ptr[det_idx_ipc].phi;
         rdr_detn_data_float                         = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION);
         Radar_Detection_Messages->DET_ELEVATION_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_ELEVATION_ERR */
         rdr_detn_data_float                             = TOI_DET_STD(D2M_target_report_ptr).std_phi[det_idx_ipc];
         rdr_detn_data_float                             = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_ELEVATION_ERR);
         Radar_Detection_Messages->DET_ELEVATION_ERR_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_EXISTENCE_PROB */
         rdr_detn_data_float                              = TOI_DET_STD(D2M_target_report_ptr).existence_prob[det_idx_ipc];
         rdr_detn_data_float                              = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_EXISTENCE_PROB);
         Radar_Detection_Messages->DET_EXISTENCE_PROB_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_POINT_TARGET_PROB */
         /* Radar_Detection_Messages->DET_POINT_TARGET_PROB_004 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_RCS */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].rcs;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_RCS);
         Radar_Detection_Messages->DET_RCS_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_SNR */
         rdr_detn_data_float                   = af_target_report_ptr[det_idx_ipc].snr;
         rdr_detn_data_float                   = CAN_TX_SIGNAL_CORRECTION(rdr_detn_data_float, DET_SNR);
         Radar_Detection_Messages->DET_SNR_004 = Init_Pos_Fixed_Point(rdr_detn_data_float, u8p0_T);

         /* DET_BI_STATIC_FLAG */
         Radar_Detection_Messages->DET_BI_STATIC_FLAG_004 = af_target_report_ptr[det_idx_ipc].f_bistatic;

         /* DET_CONFD_AZIMUTH */
         Radar_Detection_Messages->DET_CONFD_AZIMUTH_004 = af_target_report_ptr[det_idx_ipc].az_conf;

         /* DET_CONFD_ELEVATION */
         Radar_Detection_Messages->DET_CONFD_ELEVATION_004 = af_target_report_ptr[det_idx_ipc].el_conf;

         /* DET_VALID_FLAG - Can be removed as per discussion with AF team */
         /* Radar_Detection_Messages->DET_VALID_FLAG_004 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* DET_SUPER_RES_TARGET */
         Radar_Detection_Messages->DET_SUPER_RES_TARGET_004 = af_target_report_ptr[det_idx_ipc].f_superres_target;

         /* DET_HOST_VEH_CLUTTER */
         Radar_Detection_Messages->DET_HVC_FLAG_004 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_BELOW_RAIN_THOLD */
         Radar_Detection_Messages->DET_BELOW_RAIN_THOLD_004 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_IDM */
         Radar_Detection_Messages->DET_IDM_004 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_MTD */
         Radar_Detection_Messages->DET_MTD_004 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_PROB_1STAZHYPO */
         Radar_Detection_Messages->DET_PROB_1STAZHYPO_004 = CAN_SIG_NOT_IMPLEMENTED;

         /* DET_OUTSIDE_SECTOR -TBD */
         /* Radar_Detection_Messages->DET_OUTSIDE_SECTOR_004 = CAN_SIG_NOT_IMPLEMENTED; same */

         /* Send out the CAN frame */
         Write_Radar_Detection_Signals[det_idx](Radar_Detection_Messages);

         /* next detection */
         Radar_Detection_Messages++;
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Send_Tracker_Header_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Header message for Tracker Information
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
void Send_Tracker_Header_Messages(void)
{
#ifdef TRACKER_ENABLED
   SG_TrackerHeader_impdt Tracker_Header_Messages;

   Tracker_Header_Messages.HED_TRKR_TIME_PEAK            = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_TIME_INST            = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_DATA_QUALIFIER       = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_IDX                  = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_NUM_OF_ACTIV_OBJS    = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_OBJLST_TIME_STAMP_NS = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_OBJLST_TIME_STAMP_SC = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_VEH_COORD_TYPE       = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Header_Messages.HED_TRKR_VEHICLE_IDX          = CAN_SIG_NOT_IMPLEMENTED;
   Write_Tracker_Header_Msg(&Tracker_Header_Messages);
#endif
}

/*===========================================================================*\
 * FUNCTION: Send_Tracker_Status_Messages
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ----------------------------------------------------------------------------------
 * ABSTRACT: Send the Tracker Status Signals
 * ----------------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
void Send_Tracker_Status_Messages(void)
{
#ifdef TRACKER_ENABLED
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   if (d2m_buf_ptr != NULL)
   {
      SG_TrackerStatus_impdt Tracker_Status_Messages;

      Tracker_Status_Messages.STS_OBJ_DBC_BASE_VER_MINOR = CAN_SIG_NOT_IMPLEMENTED;
      Tracker_Status_Messages.STS_PERCEPTION_MODULE_ID   = d2m_buf_ptr->payload.tracker_info_stream.tracker_variant_type;
      Tracker_Status_Messages.STS_TRKR_MAJOR_VERSION     = d2m_buf_ptr->payload.tracker_info_stream.sw_version_major;
      Tracker_Status_Messages.STS_TRKR_MINOR_VERSION     = d2m_buf_ptr->payload.tracker_info_stream.sw_version_minor;
      Tracker_Status_Messages.STS_TRKR_PATCH_VERSION     = d2m_buf_ptr->payload.tracker_info_stream.sw_version_patch;
      Write_Tracker_Status_Msg(&Tracker_Status_Messages);
      return;
   }

   SG_TrackerStatus_impdt Tracker_Status_Messages;
   Tracker_Status_Messages.STS_OBJ_DBC_BASE_VER_MINOR = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Status_Messages.STS_PERCEPTION_MODULE_ID   = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Status_Messages.STS_TRKR_MAJOR_VERSION     = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Status_Messages.STS_TRKR_MINOR_VERSION     = CAN_SIG_NOT_IMPLEMENTED;
   Tracker_Status_Messages.STS_TRKR_PATCH_VERSION     = CAN_SIG_NOT_IMPLEMENTED;
   Write_Tracker_Status_Msg(&Tracker_Status_Messages);
#endif
}

/*===========================================================================*\
 * FUNCTION: Send_Tracker_Objects_On_CAN
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Send the Object Information signal group Tracker Object msgs
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
void Send_Tracker_Objects_On_CAN(void)
{
#ifdef TRACKER_ENABLED
   /* Note from Nolan: These mappings need updated and verified since switching object streams */

   SG_TrackerObject001_impdt TrackerObject;
   D2M_Msg_T *d2m_buf_ptr                           = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   volatile Vehicle_Calib_Data_T *vehicle_calib_ptr = &Get_IPC_M2D_Onetime_Msg_Buffer()->calib_data.vehicle_calib_data;
   if (d2m_buf_ptr != NULL)
   {
      for (uint8_t obj_idx = 0; obj_idx < MAX_TRACKER_OBJECT_REPORTS_DBC; obj_idx++)
      {
         F360_Object_Log_T *obj_ptr = &d2m_buf_ptr->payload.object_list_stream.object[obj_idx];

         /* If object not downselected, send zeroed object */
         if (obj_ptr->reducedID == 0)
         {
            memset(&TrackerObject, 0, sizeof(TrackerObject));
         }
         /* Otherwise, populate object values and send */
         else
         {
            TrackerObject.OBJ_ACCEL_ERR_CRR_COEF_001    = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_ACCELERATION_LAT_001      = NEG_FLOAT * obj_ptr->yaccel;
            TrackerObject.OBJ_ACCELERATION_LAT_ERR_001  = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_ACCELERATION_LONG_001     = obj_ptr->xaccel;
            TrackerObject.OBJ_ACCELERATION_LONG_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_ALIVE_TIME_001     = obj_ptr->time_since_initialization;
            TrackerObject.OBJ_CLS_TYPE1_001      = obj_ptr->object_class;
            TrackerObject.OBJ_CLS_TYPE1_PROB_001 = obj_ptr->probability_car;
            TrackerObject.OBJ_CLS_TYPE2_001      = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_CLS_TYPE2_PROB_001 = obj_ptr->probability_motorcycle;
            TrackerObject.OBJ_CLS_TYPE3_001      = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_CLS_TYPE3_PROB_001 = obj_ptr->probability_truck;
            TrackerObject.OBJ_CLS_TYPE4_001      = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_CLS_TYPE4_PROB_001 = obj_ptr->probability_pedestrian;
            TrackerObject.OBJ_CLS_TYPE5_001      = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_CLS_TYPE5_PROB_001 = obj_ptr->probability_bicycle;
            TrackerObject.OBJ_CLS_TYPE6_001      = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_CLS_TYPE6_PROB_001 = obj_ptr->probability_undet;

            TrackerObject.OBJ_DIMENSION_LENGTH_001     = obj_ptr->length;
            TrackerObject.OBJ_DIMENSION_LENGTH_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_DIMENSION_WIDTH_001     = obj_ptr->width;
            TrackerObject.OBJ_DIMENSION_WIDTH_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_EXISTENCE_PROB_001     = obj_ptr->existence_probability;
            TrackerObject.OBJ_GROUP_ID_001           = obj_ptr->unique_id;
            TrackerObject.OBJ_ID_001                 = obj_ptr->reducedID;
            TrackerObject.OBJ_MEASUREMENT_STATUS_001 = obj_ptr->status;
            TrackerObject.OBJ_MH_CRC16_001 =
               d2m_buf_ptr->payload.functional_safety_faults_stream.scl_output_faults.overall_fault_status;
            TrackerObject.OBJ_MH_CYCLE_COUNTER_001 = d2m_buf_ptr->payload.tracker_info_stream.tracker_index;

            TrackerObject.OBJ_MOVEMENT_STATUS_001 = obj_ptr->f_moving;

            TrackerObject.OBJ_POS_ERR_CRR_COEF_001 = CAN_SIG_NOT_IMPLEMENTED;

            /* ISO conversion: Y position negated, X position offset by distance to rear axle */
            TrackerObject.OBJ_POS_LAT_001      = NEG_FLOAT * obj_ptr->yposn;
            TrackerObject.OBJ_POS_LAT_ERR_001  = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_POS_LONG_001     = obj_ptr->xposn + vehicle_calib_ptr->k_distance_front_bumper_to_rear_axle;
            TrackerObject.OBJ_POS_LONG_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_RCS_001                = obj_ptr->radar_cross_section;
            TrackerObject.OBJ_REF_PT_LAT_OFFSET_001  = obj_ptr->reference_point;
            TrackerObject.OBJ_REF_PT_LONG_OFFSET_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_TRACK_MOTION_MODEL_001 = obj_ptr->trk_fltr_type;
            TrackerObject.OBJ_VEH_TRACK_FLAG_001     = obj_ptr->status;

            TrackerObject.OBJ_VELOCITY_ERR_CRR_COEF_001 = CAN_SIG_NOT_IMPLEMENTED;

            /* ISO conversion: Y velocity negated */
            TrackerObject.OBJ_VELOCITY_LAT_001     = NEG_FLOAT * obj_ptr->yvel;
            TrackerObject.OBJ_VELOCITY_LAT_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            TrackerObject.OBJ_VELOCITY_LONG_001     = obj_ptr->xvel;
            TrackerObject.OBJ_VELOCITY_LONG_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;

            /* ISO conversion: heading/pointing angle negated */
            TrackerObject.OBJ_YAW_ANGLE_001     = NEG_FLOAT * obj_ptr->orientation;
            TrackerObject.OBJ_YAW_ANGLE_ERR_001 = CAN_SIG_NOT_IMPLEMENTED; /* No orientation variance in f360_object_log.h */

            /* Yaw rate not directly available; set to NOT_IMPLEMENTED */
            TrackerObject.OBJ_YAW_RATE_001     = CAN_SIG_NOT_IMPLEMENTED;
            TrackerObject.OBJ_YAW_RATE_ERR_001 = CAN_SIG_NOT_IMPLEMENTED;
         }

         /* Send out the CAN frame */
         (void)Write_Tracker_Object_Signals[obj_idx](&TrackerObject);
      }
   }
#endif
}

/*===========================================================================*\
 * FUNCTION: Get_Operation_Mode
 *===========================================================================
 * RETURN VALUE:
 * uint8_t
 *
 * PARAMETERS:
 * Dt_SystemOperationMode
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Get the operation mode data for CAN signal population
 * --------------------------------------------------------------------------
 * This function takes the operation mode state from software as input and
 * provides the operation mode state according to the DBC values
\*===========================================================================*/
static uint8_t Get_Operation_Mode(Dt_SystemOperationMode op_mode)
{
   return (op_mode - OP_MODE_CAN_SIG_OFFSET);
}
/*===========================================================================*\
 * FUNCTION: Get_Vehicle_Supply_Vtg
 *===========================================================================
 * RETURN VALUE:
 * uint8_t
 *
 * PARAMETERS:
 * Dt_VBattState_T
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Get the vehicle supply voltage information for CAN signal population
 * --------------------------------------------------------------------------
 * This function takes the battery voltage state from software as input and
 * provides the battery voltage state according to the DBC values
\*===========================================================================*/
static uint8_t Get_Vehicle_Supply_Vtg(Dt_VBattState_T vbatt)
{
   uint8_t supply_vtg_arr[] = {0,
                               NORM_V,
                               LOW_V1,
                               HIGH_V1,
                               LOW_V2,
                               HIGH_V2,
                               LOW_V_TEMP,
                               LOW_V_TEMP_TO_NORM,
                               LOW_V1_TO_NORM,
                               LOW_V2_TO_NORM,
                               HIGH_V_TEMP_TO_NORM,
                               HIGH_V1_TO_NORM,
                               HIGH_V2_TO_NORM,
                               HIGH_V_TEMP};

   if (vbatt < sizeof(supply_vtg_arr))
   {
      return supply_vtg_arr[vbatt];
   }
   return 0;
}

/*===========================================================================*\
 * FUNCTION: BCD_To_Decimal
 *===========================================================================
* RETURN VALUE:
* uint32_t
*
* PARAMETERS:
* uint32_t bcd
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * CAVEATS:
 * This function does not validate whether the input is a valid BCD value.
 * Invalid BCD digits (0xA-0xF in any nibble) will produce incorrect results.
 * Caller is responsible for ensuring input contains only valid BCD digits (0-9).
 *
 * --------------------------------------------------------------------------
* ABSTRACT: Convert a Binary Coded Decimal (BCD) value to its decimal equivalent.
* --------------------------------------------------------------------------
* This function extracts each BCD digit using a mask and shift, multiplies by the appropriate power of ten,
* and accumulates the result to produce the decimal value. Macros are used for mask, shift, and base.
\*===========================================================================*/
static uint32_t BCD_To_Decimal(uint32_t bcd)
{
   uint32_t result     = 0U;
   uint32_t multiplier = 1U;
   while (bcd > 0U)
   {
      result += (bcd & BCD_MASK) * multiplier;
      bcd >>= BCD_SHIFT;
      multiplier *= BCD_BASE;
   }
   return result;
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *    Date      userid  (Description on following lines: SCR #, etc.)
 * -----------  ------  ------------------------------------------------
 * 03-Mar-2025  xj0l28  DND-3402 Update for TX can msgs dbcv2.0 Gen8 RdrPlatform
 * 01-Mar-2025  xj0l28  DND-3402: New file checkin
\*===========================================================================*/
