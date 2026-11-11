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
 *             File:  someip_services.c
 *           Config:  Core_Radar_Gen7_SAF85xx.dpa
 *        SW-C Type:  SWC_PLT_Appl_Communication
 *
 *        Generator:
 *          License:
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_Communication>
 *********************************************************************************************************************/
// #pragma clang optimize off
#include "someip_services.h"
#include "Rte_SWC_PLT_Appl_Communication.h"
#include "SWC_PLT_CDD_Logging.h"
#include "can_signals.h"
#include "detection_stream.h"
#include "ipc_data.h"
#include "mmic_error.h"
#include "smc_cal.h"
#include "usc_cal.h"
// #include "Rte_SWC_PLT_Appl_Diag.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "can_rx_msgs.h"
#include "radar_data.h"
#include "sensor_position.h"
#include "versions.h"
#undef RTE_APPLICATION_HEADER_FILE
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "ipc_mss.h"
#include <string.h>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

#define SIG_NOT_IMPLEMENTED       (0)
#define MAX_NUM_DETS_SOMEIP_ARXML (400U) /* In ARXML, SOMEIP detections are defined as 400 */

#define TS_GLOBAL_TIME_OUT              (0x01u)
#define Cx0_OUT_OF_SYNC                 (0U)
#define Cx1_SYNCED_AT_LEAST_ONCE        (1U)
#define Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR (2U)
/* Conversion factor from degrees to radians. */
#define DEG_TO_RAD_F32 (0.01745F)
/*===========================================================================*
 * Local Static Variable
 *===========================================================================*/

static SdEventHandlerState_T SdEventHandlerState;
static SR_DETECTIONS_RECORD gDetection_List;
static SR_RADAR_SW_INFO_RECORD gSW_Info;
static SR_RADAR_STATUS_RECORD gRDR_Status;
static SR_VEHICLE_STATUS_RECORD gReceived_Vehicle_Status_Data;
static SomeIpRxSignals_t g_someIpRxSig;

/*************************************************************
 * local function declaration
 **************************************************************/

/*Added extern as RTE port is not available*/
extern uint32_t Get_CPU_Load_C0(void);
/*populate detection struct*/
static void Vehicle_Com_Populate_Detections_Array(Rte_DT_SR_DETECTIONS_RECORD_2 DETECTIONS_ARRAY);
static void Send_Header_Alignment(SR_Header_Alignment *hdr_align_info);
static void Send_Header_Msg_TimeStamp(SR_Header_TimeStamp *hdr_timestamp);
static void Header_Msg_InformationDetection(SR_Header_InfoDetection *hdr_det_info);
static void Vehicle_Com_Populate_Detections_header(SR_EtoE_HDR *Det_E2EX_Header);
static void Vehicle_Com_Populate_header_interface_version(SR_Det_Header_Record *Det_Header_Interface_Version_Substruct);
static void Vehicle_Com_Populate_header_Radar_State(SR_Header_RadarState *Det_Header_Radar_State_Substruct);
static void Vehicle_Com_Populate_header_Sensor_Coverage(SR_Header_SensorCoverage *Det_Header_Sensor_Coverage_Substruct);
static void Vehicle_Com_Populate_Info_Detection(SR_Header_InfoDetection *Det_Header_Info_Detection_Substruct);
static void Send_Header_Mssage_Cores_TimingMeasure(SR_Header_Cores_TimingMeasure *msg_timestamp);
static void Vehicle_Com_Populate_Det(Rte_DT_SR_DETECTIONS_RECORD_2 DETECTIONS_ARRAY);

/*populate sw info struct*/
static void Vehicle_Com_Populate_Veh_Mounting_pos(SR_Status_MountingPos *STATUS_MOUNTING_POS_Subst);
static void Vehicle_Com_Populate_Veh_Hw_Version(SR_Status_HW_CAN_Version *STATUS_HW_VERSION_Subst);
static void Vehicle_Com_Populate_Veh_Calib_version(SR_Status_CalibrationVersion *STATUS_CALIB_VERSION_Subst);
static void Vehicle_Com_Populate_Veh_Sw_Version(SR_Status_SwVersion *STATUS_SW_VERSION_Subst);

/*populate radar status*/
static void Vehicle_Com_Populate_Rdr_Sensor_Performance_Status(SR_Status_SensorPerformance *STATUS_SENSOR_PERFORMANCE_Subst);
static void Vehicle_Com_Populate_Rdr_Time_Sync_Status(SR_Status_TimeSyncStatus *STATUS_TIME_SYNC_STATUS_Subst);
static void Vehicle_Com_Populate_Rdr_Radar_Status(SR_Status_Radar *STATUS_RADAR_Subst);
static void Vehicle_Com_Populate_Rdr_Vehicle_Status(SR_Status_Vehicle *STATUS_VEHICLE_Subst);
static void Vehicle_Com_Populate_Rdr_fault_Status(SR_Status_Faults *STATUS_FAULTS_Subst);
static void Vehicle_Com_Populate_Static_Alignment(SR_Alignment_Static *Det_Static_Alignment_Substruct);

static void Vehicle_Com_Update_Veh_Com_Detections(SR_DETECTIONS_RECORD *Detection_List);
static void Vehicle_Com_Update_Veh_Sw_Info_Status(SR_RADAR_SW_INFO_RECORD *SW_Info);
static void Vehicle_Com_Update_Veh_Com_Rdr_Status(SR_RADAR_STATUS_RECORD *RDR_Status);
static void Vehicle_Com_Read_ASDM_Vehicle_Status(SR_VEHICLE_STATUS_RECORD *veh_status_ptr);

/*************************************************************
 * public function definition
 **************************************************************/
/*****************************************************************************
 *. Name: Process_Consumed_Services
 *.   Checks Subscription and availability status of consumed services
 *.   Receives the services' data through RTE ports
 *.
 *. Parameters: void
 *. Return Value: void
 *. Shared Variables: None.
 ******************************************************************************/
void Process_Consumed_Services(void)
{
   SdEventHandlerState.Veh_Status_ConsumedServiceState =
      Rte_Mode_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState();
   SdEventHandlerState.Veh_Status_ConsumedEventGroupState =
      Rte_Mode_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState();
   if (RTE_MODE_SDC_SdClientServiceState_SDC_CLIENT_AVAILABLE == SdEventHandlerState.Veh_Status_ConsumedServiceState)
   {
      /* Read Vehicle Status Data */
      Rte_Read_RP_RDR_Vehicle_Status_Vehicle_Status(&gReceived_Vehicle_Status_Data);
      /* Copy Rx (gReceived_Vehicle_Status_Data) data to IPC structure. We might need to call RE_Vehicle_Com at 10ms rate */
      Vehicle_Com_Read_ASDM_Vehicle_Status(&gReceived_Vehicle_Status_Data);
   }
}

/*****************************************************************************
 *. Name: Process_Provided_Services
 *.   Checks Subscription and availability status of provided services
 *.   Transmits the services' data through RTE ports
 *.
 *. Parameters: void
 *. Return Value: void
 *. Shared Variables: None.
 ******************************************************************************/
void Process_Provided_Services(void)
{
   SdEventHandlerState.RDR_DetectionList_SdEventHandlerState =
      Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState();

   if (RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED == SdEventHandlerState.RDR_DetectionList_SdEventHandlerState)
   {
      Vehicle_Com_Update_Veh_Com_Detections((SR_DETECTIONS_RECORD *)&gDetection_List);

      /* Trigger TP Transmission */
      Rte_Write_Pp_RDR_DetectionList_Event_DetectionList_Event((SR_DETECTIONS_RECORD *)&gDetection_List);
   }

   SdEventHandlerState.RDR_SW_info_SdEventHandlerState =
      Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState();
   if (RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED == SdEventHandlerState.RDR_SW_info_SdEventHandlerState)
   {
      Vehicle_Com_Update_Veh_Sw_Info_Status((SR_RADAR_SW_INFO_RECORD *)&gSW_Info);

      /* Trigger SW Status Service */
      Rte_Write_Pp_RDR_Radar_SW_Info_RDR_SW_Info((SR_RADAR_SW_INFO_RECORD *)&gSW_Info);
   }

   SdEventHandlerState.RDR_Status_SdEventHandlerState =
      Rte_Mode_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState();
   if (RTE_MODE_SDC_SdEventHandlerState_SDC_EH_REQUESTED == SdEventHandlerState.RDR_Status_SdEventHandlerState)
   {
      Vehicle_Com_Update_Veh_Com_Rdr_Status((SR_RADAR_STATUS_RECORD *)&gRDR_Status);

      /* Trigger RDR Status Service */
      Rte_Write_Pp_RDR_Radar_Status_RDR_Status((SR_RADAR_STATUS_RECORD *)&gRDR_Status);
   }
}

/*****************************************************************************
 *. Name: Init_Consumed_Services
 *.   Sets consumed services as Requested
 *.
 *. Parameters: void
 *. Return Value: void
 *. Shared Variables: None.
 ******************************************************************************/
void Init_Consumed_Services(void)
{
   Rte_Write_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode(SDC_CLIENT_REQUESTED);
   Rte_Write_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode(
      SDC_CEG_REQUESTED);
}

/*****************************************************************************
 *. Name: Init_Provided_Services
 *.   Sets consumed services as Available
 *.
 *. Parameters: void
 *. Return Value: void
 *. Shared Variables: None.
 ******************************************************************************/
void Init_Provided_Services(void)
{
   Rte_Write_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode(SDC_SERVER_AVAILABE);
   Rte_Write_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode(SDC_SERVER_AVAILABE);
   Rte_Write_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode(SDC_SERVER_AVAILABE);
}
/*****************************************************************************
 *. Name: Vehicle_Com_Update_Veh_Com_Detections
 *. This function populates detection details
 *.
 *. Parameters: DETECTIONS_RECORD *Detection_List
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Update_Veh_Com_Detections(
   SR_DETECTIONS_RECORD *Detection_List) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /*populate header struct interface version */
   Vehicle_Com_Populate_header_interface_version(&Detection_List->DET_HEADER_STRUCT);

   /* Populate Detection data */
   Vehicle_Com_Populate_Detections_Array(Detection_List->DETECTIONS_ARRAY);

   /* populate detection header */
   Vehicle_Com_Populate_Detections_header(&Detection_List->DET_EtoE_HDR);

   /* populate radar state */
   Vehicle_Com_Populate_header_Radar_State(&Detection_List->DET_HEADER_STRUCT.HED_RADAR_STATE);

   /* populate header sensor coverage */
   Vehicle_Com_Populate_header_Sensor_Coverage(&Detection_List->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE);

   /* populate header info detection */
   Vehicle_Com_Populate_Info_Detection(&Detection_List->DET_HEADER_STRUCT.HED_DETECTION_INFO);

   /* populate header info Alignment */
   Send_Header_Alignment(&Detection_List->DET_HEADER_STRUCT.HED_ALIGNMENT);

   /* populate header info Msg_TimeStamp */
   Send_Header_Msg_TimeStamp(&Detection_List->DET_HEADER_STRUCT.HED_TIMESTAMP);

   /* populate header info InformationDetection */
   Header_Msg_InformationDetection(&Detection_List->DET_HEADER_STRUCT.HED_DETECTION_INFO);
   /*populate the Header messages*/
   Send_Header_Mssage_Cores_TimingMeasure(&Detection_List->DET_HEADER_STRUCT.HED_TIMING_PROFILES);
}
/*****************************************************************************
 *. Name: Vehicle_Com_Update_Veh_Sw_Info_Status
 *. This function populates veh sw info status
 *.
 *. Parameters: RADAR_SW_INFO_RECORD *SW_Info
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Update_Veh_Sw_Info_Status(SR_RADAR_SW_INFO_RECORD *SW_Info)
{
   /* Populate dummy SW Status Data */
   Vehicle_Com_Populate_Veh_Mounting_pos(&SW_Info->INFO_MOUNTING_POS);
   // populate hw version
   Vehicle_Com_Populate_Veh_Hw_Version(&SW_Info->INFO_HW_CAN_VERSION);
   // populate calib version
   Vehicle_Com_Populate_Veh_Calib_version(&SW_Info->INFO_CALIBRATION_VERSION);
   // populate sw version
   Vehicle_Com_Populate_Veh_Sw_Version(&SW_Info->INFO_SW_VERSION);
   // populate e2e header
   Vehicle_Com_Populate_Detections_header(&SW_Info->INFO_EtoE_HDR);
}
/*****************************************************************************
 *. Name: Vehicle_Com_Update_Veh_Com_Rdr_Status
 *. This function populates radar status
 *.
 *. Parameters: STATUS_STRUCT_EVENT_ETH *RDR_Status
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Update_Veh_Com_Rdr_Status(SR_RADAR_STATUS_RECORD *RDR_Status)
{
   /* Populate dummy RDR Status Data */
   // populate sensor performance
   Vehicle_Com_Populate_Rdr_Sensor_Performance_Status(&RDR_Status->STS_SENSOR_PERF);
   // populate time sync status
   Vehicle_Com_Populate_Rdr_Time_Sync_Status(&RDR_Status->STS_TIMESYNC_STATUS);
   // populate radar status
   Vehicle_Com_Populate_Rdr_Radar_Status(&RDR_Status->STS_RADAR_PROFILE);
   // populate vehicle status
   Vehicle_Com_Populate_Rdr_Vehicle_Status(&RDR_Status->STS_VEHICLE);
   // populate faults
   Vehicle_Com_Populate_Rdr_fault_Status(&RDR_Status->STS_FAULTS);
   // populate status header
   Vehicle_Com_Populate_Detections_header(&RDR_Status->STS_EtoE_HDR);
   // populate static alignment struct
   Vehicle_Com_Populate_Static_Alignment(&RDR_Status->STS_ALIGNMENT_STATIC);
}

void Vehicle_Com_Populate_Det(Rte_DT_SR_DETECTIONS_RECORD_2 DETECTIONS_ARRAY)
{
   uint16_t idx;
   uint16_t num_detections = 0;
   D2M_Msg_T *d2m_buf_ptr  = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   /* Populate detections array for all detections */
   if ((d2m_buf_ptr != NULL))
   {
      num_detections = (uint16_t)d2m_buf_ptr->payload.det_data.num_af_det;
   }
   if (num_detections >= MAX_NUM_DETS_SOMEIP_ARXML)
   {
      num_detections = MAX_NUM_DETS_SOMEIP_ARXML;
   }
   for (idx = 0u; idx < num_detections; idx++)
   {
      /* DET_BI_STATIC_FLAG */
      DETECTIONS_ARRAY[idx].DET_BI_STATIC_FLAG =
         (Rte_DT_SR_Detection_Record_2)d2m_buf_ptr->payload.det_data.af_dets[idx].f_bistatic;
      /* DET_AZIMUTH */
      DETECTIONS_ARRAY[idx].DET_AZIMUTH = (Rte_DT_SR_Detection_Record_0)d2m_buf_ptr->payload.det_data.af_dets[idx].theta;
      /* DET_AZIMUTH_ERR */
      DETECTIONS_ARRAY[idx].DET_AZIMUTH_ERR = SIG_NOT_IMPLEMENTED; // TOI Dependency
      /* DET_CONFD_AZIMUTH */
      DETECTIONS_ARRAY[idx].DET_CONFD_AZIMUTH = (Rte_DT_SR_Detection_Record_3)d2m_buf_ptr->payload.det_data.af_dets[idx].az_conf;
      /* DET_CONFD_ELEVATION */
      DETECTIONS_ARRAY[idx].DET_CONFD_ELEVATION = (Rte_DT_SR_Detection_Record_4)d2m_buf_ptr->payload.det_data.af_dets[idx].el_conf;
      /* DET_ELEVATION */
      DETECTIONS_ARRAY[idx].DET_ELEVATION = (Rte_DT_SR_Detection_Record_5)d2m_buf_ptr->payload.det_data.af_dets[idx].phi;
      /* DET_ELEVATION_ERR */
      DETECTIONS_ARRAY[idx].DET_ELEVATION_ERR = SIG_NOT_IMPLEMENTED;
      /* DET_HOST_VEH_CLUTTER */
      DETECTIONS_ARRAY[idx].DET_HVC_FLAG = SIG_NOT_IMPLEMENTED;
      /* DET_OUTSIDE_SECTOR -TBD */
      DETECTIONS_ARRAY[idx].DET_OUTSIDE_SECTOR = SIG_NOT_IMPLEMENTED;
      /* DET_POINT_TARGET_PROB */
      DETECTIONS_ARRAY[idx].DET_POINT_TARGET_PROB = SIG_NOT_IMPLEMENTED;
      /* DET_RANGE */
      DETECTIONS_ARRAY[idx].DET_RANGE = (Rte_DT_SR_Detection_Record_7)d2m_buf_ptr->payload.det_data.af_dets[idx].ran;
      /* DET_RANGE_ERR */
      DETECTIONS_ARRAY[idx].DET_RANGE_ERR = SIG_NOT_IMPLEMENTED; // TOI Dependency
      /* DET_RANGE_VELOCITY */
      DETECTIONS_ARRAY[idx].DET_RANGE_VELOCITY = (Rte_DT_SR_Detection_Record_13)d2m_buf_ptr->payload.det_data.af_dets[idx].vel;
      /* DET_RANGE_VELOCITY_ERR */
      DETECTIONS_ARRAY[idx].DET_RANGE_VELOCITY_ERR = SIG_NOT_IMPLEMENTED; // TOI Dependency
      /* DET_RCS */
      DETECTIONS_ARRAY[idx].DET_RCS = (Rte_DT_SR_Detection_Record_11)d2m_buf_ptr->payload.det_data.af_dets[idx].rcs;
      /* DET_SNR */
      DETECTIONS_ARRAY[idx].DET_SNR = (Rte_DT_SR_Detection_Record_12)d2m_buf_ptr->payload.det_data.af_dets[idx].snr;
      /* DET_SUPER_RES_TARGET */
      DETECTIONS_ARRAY[idx].DET_SUPER_RES_TARGET = d2m_buf_ptr->payload.det_data.af_dets[idx].f_superres_target;
      /* DET_VALID_FLAG */
      DETECTIONS_ARRAY[idx].DET_VALID_FLAG = SIG_NOT_IMPLEMENTED;
      /* DET_EXISTENCE_PROB */
      DETECTIONS_ARRAY[idx].DET_EXISTENCE_PROB = SIG_NOT_IMPLEMENTED; // TOI Dependency
   }
}

/*************************************************************
 * local function Defintion
 **************************************************************/
/*functions for of populate detection struct*/
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Detections_Array
 *. This function populates the detection details
 *.
 *. Parameters: Rte_DT_SR_DETECTIONS_RECORD_2 DETECTIONS_ARRAY
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Detections_Array(Rte_DT_SR_DETECTIONS_RECORD_2 DETECTIONS_ARRAY)
{
   /* Clear detections array */
   memset((void *)&DETECTIONS_ARRAY[0], 0U, sizeof(Rte_DT_SR_DETECTIONS_RECORD_2));
   Vehicle_Com_Populate_Det(DETECTIONS_ARRAY);
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_header_interface_version
 *. This function updates interface version
 *.
 *. Parameters: DET_HEADER_INTERFACE_VERSION_ETH *Det_Header_Interface_Version_Substruct
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_header_interface_version(SR_Det_Header_Record *Det_Header_Interface_Version_Substruct)
{
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_DET_RANGE_MAX       = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_DET_RANGE_MIN       = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MAX = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MIN = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_FOV_HOR_MAX         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_FOV_HOR_MIN         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_FOV_VER_MAX         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_SENSOR_COVERAGE.HED_FOV_VER_MIN         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_RADAR_STATE.HED_DATA_QUALIFIER          = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_RADAR_STATE.HED_NUM_OF_VALID_DETECTIONS = SIG_NOT_IMPLEMENTED;

   // Det_Header_Interface_Version_Substruct->HED_ALIGNMENT.HED_ALIGN_HOR_QF  = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_ALIGNMENT.HED_ALIGN_HOR_REF = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_ALIGNMENT.HED_ALIGN_VER_QF  = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_ALIGNMENT.HED_ALIGN_VER_REF = SIG_NOT_IMPLEMENTED;

   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_AF_TIME_INST        =
   // d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_inst;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_AF_TIME_PEAK        =
   // d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_peak;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_MAIN_CORE_TIME_INST = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_MAIN_CORE_TIME_PEAK = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_RDD_CORE_TIME_INST  =
   // d2m_buf_ptr->payload.dsp_timing_data.rdd_time;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_RDD_CORE_TIME_PEAK  = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_SP_CORE_TIME_INST   = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMING_PROFILES.HED_SP_CORE_TIME_PEAK   = SIG_NOT_IMPLEMENTED;
   Det_Header_Interface_Version_Substruct->HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_NS  = SIG_NOT_IMPLEMENTED;
   Det_Header_Interface_Version_Substruct->HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_SEC = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMESTAMP.HED_TIME_SYNC_SRC_MASTER    = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMESTAMP.HED_TIME_SYNC_VALIDITY_FLAG = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_TIMESTAMP.HED_TRIGGER_TIME            = SIG_NOT_IMPLEMENTED;

   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_DET_BI_STATIC_COUNT      = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_DET_NUM_OF_1PASS         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_DET_NUM_OF_2PASS         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_MAX_NUM_OF_DETECTIONS    = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_NUM_OF_RESTBINS_USED     = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_OPERATION_MODE           = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_PROCESSED_RANGE          = SIG_NOT_IMPLEMENTED;
   // Det_Header_Interface_Version_Substruct->HED_DETECTION_INFO.HED_SLOPE_CORR_EXECUTIONFLAG = SIG_NOT_IMPLEMENTED;

   if (NULL != d2m_buf_ptr)
   {
      Det_Header_Interface_Version_Substruct->HED_RADAR_STATE.HED_LOOK_ID = d2m_buf_ptr->payload.rdd_stream_data.look_data.look_id;
      Det_Header_Interface_Version_Substruct->HED_RADAR_STATE.HED_LOOK_INDEX =
         d2m_buf_ptr->payload.rdd_stream_data.look_data.look_index;
      Det_Header_Interface_Version_Substruct->HED_RADAR_STATE.HED_SCAN_INDEX =
         d2m_buf_ptr->payload.rdd_stream_data.look_data.scan_index;
   }

   Det_Header_Interface_Version_Substruct->HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MAJOR = SIG_NOT_IMPLEMENTED;
   Det_Header_Interface_Version_Substruct->HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MINOR = SIG_NOT_IMPLEMENTED;
   Det_Header_Interface_Version_Substruct->HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_PATCH = SIG_NOT_IMPLEMENTED;
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_header_Radar_State
 *. This function populates radar state
 *.
 *. Parameters: DET_HEADER_RADAR_STATE_ETH *Det_Header_Radar_State_Substruct
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/

void Vehicle_Com_Populate_header_Radar_State(SR_Header_RadarState *Det_Header_Radar_State_Substruct)
{
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   // volatile M2D_Msg_T *m2d_buf_ptr                      = Get_MSS_IPC_M2D_Msg_Buffer();
   Det_Header_Radar_State_Substruct->HED_LOOK_ID =
      (Rte_DT_SR_Header_RadarState_1)d2m_buf_ptr->payload.rdd_stream_data.look_data.look_id;
   Det_Header_Radar_State_Substruct->HED_LOOK_INDEX =
      (Rte_DT_SR_Header_RadarState_2)d2m_buf_ptr->payload.det_data.det_list_property.lookindex;
#if (DOWNSELECTION_ENABLE == 1U)
   Det_Header_Radar_State_Substruct->HED_NUM_OF_VALID_DETECTIONS =
      (Rte_DT_SR_Header_RadarState_3)d2m_buf_ptr->payload.downselection_data.num_af_ds_det;
   Det_Header_Radar_State_Substruct->HED_DATA_QUALIFIER = d2m_buf_ptr->payload.toi_ds_stream_data.toi_op_data.data_qualifier;
#else
   Det_Header_Radar_State_Substruct->HED_NUM_OF_VALID_DETECTIONS =
      (Rte_DT_SR_Header_RadarState_3)d2m_buf_ptr->payload.det_data.num_af_det;
   Det_Header_Radar_State_Substruct->HED_DATA_QUALIFIER = d2m_buf_ptr->payload.toi_stream_data.toi_op_data.data_qualifier;
#endif
   Det_Header_Radar_State_Substruct->HED_SCAN_INDEX =
      (Rte_DT_SR_Header_RadarState_4)d2m_buf_ptr->payload.det_data.det_list_property.scanindex;
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_header_Sensor_Coverage
 *. This function populates sensor coverage data
 *.
 *. Parameters: DET_HEADER_SENSOR_COVERAGE_ETH *Det_Header_Sensor_Coverage_Substruct
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_header_Sensor_Coverage(SR_Header_SensorCoverage *Det_Header_Sensor_Coverage_Substruct)
{
   // float32_t signal;
   u9p7_T range_min, range_max;
   s7p8_T doppler_min, doppler_max;
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   if (d2m_buf_ptr != NULL)
   {
      Radar_Look_T look_type = (Radar_Look_T)d2m_buf_ptr->payload.rdd_stream_data.look_data.look_id;

      if (look_type < RADAR_LOOK_D)
      {
         range_max   = k_detection_range_max_smc[(uint8_t)look_type];
         range_min   = k_detection_range_min_smc[(uint8_t)look_type];
         doppler_max = k_detection_range_rate_max_smc[(uint8_t)look_type];
         doppler_min = k_detection_range_rate_min_smc[(uint8_t)look_type];
      }
      else
      {
         range_max   = Init_Fixed_Point(0, u9p7_T);
         range_min   = Init_Fixed_Point(0, u9p7_T);
         doppler_max = Init_Fixed_Point(0, s7p8_T);
         doppler_min = Init_Fixed_Point(0, s7p8_T);
      }
      Det_Header_Sensor_Coverage_Substruct->HED_DET_RANGE_MAX       = (Rte_DT_SR_Header_SensorCoverage_0)range_max;
      Det_Header_Sensor_Coverage_Substruct->HED_DET_RANGE_MIN       = (Rte_DT_SR_Header_SensorCoverage_1)range_min;
      Det_Header_Sensor_Coverage_Substruct->HED_DET_SPEED_RANGE_MAX = (Rte_DT_SR_Header_SensorCoverage_2)doppler_max;
      Det_Header_Sensor_Coverage_Substruct->HED_DET_SPEED_RANGE_MIN = (Rte_DT_SR_Header_SensorCoverage_3)doppler_min;
      Det_Header_Sensor_Coverage_Substruct->HED_FOV_HOR_MAX         = (Rte_DT_SR_Header_SensorCoverage_4)k_fov_hor_end_smc;
      Det_Header_Sensor_Coverage_Substruct->HED_FOV_HOR_MIN         = (Rte_DT_SR_Header_SensorCoverage_5)k_fov_hor_begin_smc;
      Det_Header_Sensor_Coverage_Substruct->HED_FOV_VER_MAX         = (Rte_DT_SR_Header_SensorCoverage_6)k_fov_ver_end_smc;
      Det_Header_Sensor_Coverage_Substruct->HED_FOV_VER_MIN         = (Rte_DT_SR_Header_SensorCoverage_7)k_fov_ver_begin_smc;
   }
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Info_Detection
 *. This function populates detection info
 *.
 *. Parameters: DET_HEADER_INFO_DETECTION_ETH *Det_Header_Info_Detection_Substruct
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Info_Detection(SR_Header_InfoDetection *Det_Header_Info_Detection_Substruct)
{
   // Det_Header_Info_Detection_Substruct->HED_DET_BI_STATIC_COUNT      = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_DET_NUM_OF_1PASS         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_DET_NUM_OF_2PASS         = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_MAX_NUM_OF_DETECTIONS    = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_NUM_OF_RESTBINS_USED     = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_OPERATION_MODE           = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_PROCESSED_RANGE          = SIG_NOT_IMPLEMENTED;
   // Det_Header_Info_Detection_Substruct->HED_SLOPE_CORR_EXECUTIONFLAG = SIG_NOT_IMPLEMENTED;
}

/*****************************************************************************
 *. Name: Send_Header_Alignment
 *. This function populates detection info
 *.
 *. Parameters: SR_Header_Alignment *hdr_align_info
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Send_Header_Alignment(SR_Header_Alignment *hdr_align_info)
{
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   hdr_align_info->HED_ALIGN_HOR_QF =
      (Rte_DT_SR_Header_Alignment_0)d2m_buf_ptr->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf;
   hdr_align_info->HED_ALIGN_HOR_REF =
      (Rte_DT_SR_Header_Alignment_1)d2m_buf_ptr->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal;
   hdr_align_info->HED_ALIGN_VER_REF =
      (Rte_DT_SR_Header_Alignment_2)d2m_buf_ptr->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal;
   hdr_align_info->HED_ALIGN_VER_QF =
      (Rte_DT_SR_Header_Alignment_3)d2m_buf_ptr->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf;
}

/*****************************************************************************
 *. Name: Send_Header_Msg_TimeStamp
 *. This function populates detection info
 *.
 *. Parameters: SR_Header_TimeStamp *hdr_timestamp
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Send_Header_Msg_TimeStamp(SR_Header_TimeStamp *hdr_timestamp)
{
   uint32_t status        = 0x0;
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   hdr_timestamp->HED_TRIGGER_TIME = SIG_NOT_IMPLEMENTED;

   status = d2m_buf_ptr->payload.det_data.det_list_property.timestamp_status;
   if ((TS_POWER_ON_STATUS) == (status))
   {
      hdr_timestamp->HED_TIME_SYNC_SRC_MASTER = TS_SOURCE_LOCAL;
   }
   else
   {
      if ((TS_STBM_LSB) & (status))
      {
         hdr_timestamp->HED_TIME_SYNC_SRC_MASTER = TS_SOURCE_LOCAL;
      }
      else
      {
         hdr_timestamp->HED_TIME_SYNC_SRC_MASTER = TS_SOURCE_GLOBAL;
      }
   }

   /* when bit-3 is 1 and bit-0 is 0 */
   if (!(status & TS_GLOBAL_TIME_OUT) && (status & TS_GLOBAL_TIME_BASE))
   {
      /* Status = 8 (Synchronized, No Timeout) → VALID */
      hdr_timestamp->HED_TIME_SYNC_VALIDITY_FLAG = Cx1_SYNCED_AT_LEAST_ONCE;
   }
   /* when both bit-3 is 1 and bit-0 is 1 */
   else if ((status & TS_GLOBAL_TIME_OUT) && (status & TS_GLOBAL_TIME_BASE))
   {
      /* Status = 9 (Synchronized, Timeout) → INVALID */
      hdr_timestamp->HED_TIME_SYNC_VALIDITY_FLAG = Cx2_SYNC_MSG_TIMEOUT_OR_CRC_ERR;
   }
   /* when both bit-3 is 0 and bit-0 is 0 */
   else
   {
      /* Status = 0 (not synced) → INVALID */
      hdr_timestamp->HED_TIME_SYNC_VALIDITY_FLAG = Cx0_OUT_OF_SYNC;
   }
}

/*****************************************************************************
 *. Name: Header_Msg_InformationDetection
 *. This function populates detection info
 *.
 *. Parameters: SR_Header_InfoDetection *hdr_det_info
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Header_Msg_InformationDetection(SR_Header_InfoDetection *hdr_det_info)
{
   D2M_Msg_T *d2m_buf_ptr                = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   hdr_det_info->HED_DET_BI_STATIC_COUNT = SIG_NOT_IMPLEMENTED;
   hdr_det_info->HED_DET_NUM_OF_1PASS =
      (Rte_DT_SR_Header_InfoDetection_1)d2m_buf_ptr->payload.det_data.det_list_property.num_fp_detections;
   hdr_det_info->HED_DET_NUM_OF_2PASS =
      (Rte_DT_SR_Header_InfoDetection_2)d2m_buf_ptr->payload.det_data.det_list_property.num_sp_detections;
#if (1U == DOWNSELECTION_ENABLE)
   {
      hdr_det_info->HED_MAX_NUM_OF_DETECTIONS = MAX_TARGET_REPORTS;
   }
#else
   hdr_det_info->HED_MAX_NUM_OF_DETECTIONS              = AF_MAX_NUM_DET;
#endif
   hdr_det_info->HED_NUM_OF_RESTBINS_USED     = SIG_NOT_IMPLEMENTED;
   hdr_det_info->HED_OPERATION_MODE           = SIG_NOT_IMPLEMENTED;
   hdr_det_info->HED_PROCESSED_RANGE          = SIG_NOT_IMPLEMENTED;
   hdr_det_info->HED_SLOPE_CORR_EXECUTIONFLAG = SIG_NOT_IMPLEMENTED;
}

/*****************************************************************************
 *. Name: Send_Header_Mssage_Cores_TimingMeasure
 *. This function populates detection info
 *.
 *. Parameters: SR_Header_Cores_TimingMeasure *msg_timestamp
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
static void Send_Header_Mssage_Cores_TimingMeasure(SR_Header_Cores_TimingMeasure *msg_timestamp)
{
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   msg_timestamp->HED_AF_TIME_INST        = d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_inst;
   msg_timestamp->HED_AF_TIME_PEAK        = d2m_buf_ptr->payload.dsp_timing_data.af_time.af_xput_peak;
   msg_timestamp->HED_MAIN_CORE_TIME_INST = SIG_NOT_IMPLEMENTED;
   msg_timestamp->HED_MAIN_CORE_TIME_PEAK = SIG_NOT_IMPLEMENTED;
   msg_timestamp->HED_RDD_CORE_TIME_INST  = d2m_buf_ptr->payload.dsp_timing_data.rdd_time;
   msg_timestamp->HED_RDD_CORE_TIME_PEAK  = SIG_NOT_IMPLEMENTED;
   msg_timestamp->HED_SP_CORE_TIME_INST   = SIG_NOT_IMPLEMENTED;
   msg_timestamp->HED_SP_CORE_TIME_PEAK   = SIG_NOT_IMPLEMENTED;
}

/*functions for populate sw info struct*/
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Veh_Mounting_pos
 *. This function will get the pointer to ipc buffer
 *.
 *. Parameters: Status_MountingPos *STATUS_MOUNTING_POS_Subst
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Veh_Mounting_pos(SR_Status_MountingPos *STATUS_MOUNTING_POS_Subst)
{
   // static uint16 count;
   uint8_t radar_pos                                      = Get_Radar_Position();
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_POSITION         = radar_pos;
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_ORNT_YAW   = k_sensor_mount_ornt_yaw_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_ORNT_PITCH = k_sensor_mount_ornt_pitch_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_ORNT_ROLL  = k_sensor_mount_ornt_roll_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_POS_X      = k_sensor_mount_pos_x_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_POS_Y      = k_sensor_mount_pos_y_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_MOUNT_POS_Z      = k_sensor_mount_pos_z_list_smc[radar_pos];
   STATUS_MOUNTING_POS_Subst->STS_SENSOR_HEIGHT           = k_sensor_mount_height_list_smc[radar_pos];
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Veh_Hw_Version
 *. This function popultes veh hw version
 *.
 *. Parameters: Status_HW_CAN_Version *STATUS_HW_VERSION_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Veh_Hw_Version(SR_Status_HW_CAN_Version *STATUS_HW_VERSION_Subst)
{
   volatile const Application_Version_T *app_ver_ptr    = Get_Application_Version();
   STATUS_HW_VERSION_Subst->STS_PCAN_PROTOCOL_VER_MAJOR = SIG_NOT_IMPLEMENTED;
   STATUS_HW_VERSION_Subst->STS_PCAN_PROTOCOL_VER_MINOR = SIG_NOT_IMPLEMENTED;
   STATUS_HW_VERSION_Subst->STS_HARDWARE_VERSION        = app_ver_ptr->board_type;
   STATUS_HW_VERSION_Subst->STS_PLATFORM_VARIANT        = (Rte_DT_SR_Status_HW_CAN_Version_5)Get_SMC_Cal_Platform();
   STATUS_HW_VERSION_Subst->STS_SERIAL_NUM_JULIAN_YEAR  = SIG_NOT_IMPLEMENTED;
   STATUS_HW_VERSION_Subst->STS_SERIAL_NUM_JULIAN_DAY   = SIG_NOT_IMPLEMENTED;
   STATUS_HW_VERSION_Subst->STS_SERIAL_NUMBER_SEQUENCE  = SIG_NOT_IMPLEMENTED;
   STATUS_HW_VERSION_Subst->STS_DET_DBC_BASE_VER_MAJOR  = (Rte_DT_SR_Status_HW_CAN_Version_0)DET_DBC_BASE_VERSION_MAJOR;
   STATUS_HW_VERSION_Subst->STS_DET_DBC_BASE_VER_MINOR  = (Rte_DT_SR_Status_HW_CAN_Version_1)DET_DBC_BASE_VERSION_MINOR;
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Veh_Calib_version
 *. This function populates veh calibration version
 *.
 *. Parameters: Status_CalibrationVersion *STATUS_CALIB_VERSION_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Veh_Calib_version(SR_Status_CalibrationVersion *STATUS_CALIB_VERSION_Subst)
{
   STATUS_CALIB_VERSION_Subst->STS_USC_CAL_VER_MAJOR      = (Rte_DT_SR_Status_CalibrationVersion_4)Get_USC_Cal_Major();
   STATUS_CALIB_VERSION_Subst->STS_USC_CAL_VER_MINOR      = (Rte_DT_SR_Status_CalibrationVersion_5)Get_USC_Cal_Minor();
   STATUS_CALIB_VERSION_Subst->STS_USC_SECTION_COMPTBLITY = (Rte_DT_SR_Status_CalibrationVersion_6)Get_USC_Cal_Patch();
   STATUS_CALIB_VERSION_Subst->STS_SMC_CAL_VER_MAJOR      = (Rte_DT_SR_Status_CalibrationVersion_0)Get_SMC_Cal_Major();
   STATUS_CALIB_VERSION_Subst->STS_SMC_CAL_VER_MINOR      = (Rte_DT_SR_Status_CalibrationVersion_1)Get_SMC_Cal_Minor();
   STATUS_CALIB_VERSION_Subst->STS_SMC_SECTION_COMPTBLITY = (Rte_DT_SR_Status_CalibrationVersion_3)Get_SMC_Cal_Patch();
   STATUS_CALIB_VERSION_Subst->STS_SMC_PLATFROM_VERSION   = (Rte_DT_SR_Status_CalibrationVersion_2)Get_SMC_Cal_Platform();
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Veh_Sw_Version
 *. This function populates veh sw version
 *.
 *. Parameters: Status_SwVersion *STATUS_SW_VERSION_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Veh_Sw_Version(SR_Status_SwVersion *STATUS_SW_VERSION_Subst)
{
   volatile const Application_Version_T *app_ver_ptr = Get_Application_Version();
   volatile const Bootloader_Version_T *blr_ver_ptr  = Get_Bootloader_Version();

   STATUS_SW_VERSION_Subst->STS_SW_VERSION_FIELD1  = (Rte_DT_SR_Status_SwVersion_4)app_ver_ptr->variant;
   STATUS_SW_VERSION_Subst->STS_SW_VERSION_FIELD2  = (Rte_DT_SR_Status_SwVersion_5)app_ver_ptr->major;
   STATUS_SW_VERSION_Subst->STS_SW_VERSION_FIELD3  = (Rte_DT_SR_Status_SwVersion_6)app_ver_ptr->minor;
   STATUS_SW_VERSION_Subst->STS_SW_VERSION_FIELD4  = (Rte_DT_SR_Status_SwVersion_7)app_ver_ptr->patch;
   STATUS_SW_VERSION_Subst->STS_PBL_VERSION_FIELD1 = (Rte_DT_SR_Status_SwVersion_0)blr_ver_ptr->major;
   STATUS_SW_VERSION_Subst->STS_PBL_VERSION_FIELD2 = (Rte_DT_SR_Status_SwVersion_1)blr_ver_ptr->minor;
   STATUS_SW_VERSION_Subst->STS_PBL_VERSION_FIELD3 = (Rte_DT_SR_Status_SwVersion_2)blr_ver_ptr->patch;
   STATUS_SW_VERSION_Subst->STS_PBL_VERSION_FIELD4 = SIG_NOT_IMPLEMENTED;
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Rdr_Sensor_Performance_Status
 *. This function will populate sensor performance status
 *.
 *. Parameters: SR_Status_SensorPerformance *STATUS_SENSOR_PERFORMANCE_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Rdr_Sensor_Performance_Status(SR_Status_SensorPerformance *STATUS_SENSOR_PERFORMANCE_Subst)
{
   bool udp_logging_status, xcp_ovr_enet_status;
   udp_logging_status  = 0;
   xcp_ovr_enet_status = Get_XCP_Over_ETH_Status();
   if (udp_logging_status || xcp_ovr_enet_status)
   {
      STATUS_SENSOR_PERFORMANCE_Subst->STS_BRR_STATUS = STS_BRR_STATUS_LINK_UP_SERVICES_ENABLED;
   }
   else
   {
      STATUS_SENSOR_PERFORMANCE_Subst->STS_BRR_STATUS = STS_BRR_STATUS_LINK_UP_SERVICES_DISABLED;
   }
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Rdr_Time_Sync_Status
 *. This function will populate radar time sync status
 *.
 *. Parameters: SR_Status_TimeSyncStatus *STATUS_TIME_SYNC_STATUS_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Rdr_Time_Sync_Status(SR_Status_TimeSyncStatus *STATUS_TIME_SYNC_STATUS_Subst)
{
   uint32_t status        = 0U;
   D2M_Msg_T *d2m_buf_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   status                 = d2m_buf_ptr->payload.det_data.det_list_property.timestamp_status;
   /* when bit-3 is 1 and bit-0 is 0 */
   if (!(status & TS_GLOBAL_TIME_OUT) && (status & TS_GLOBAL_TIME_BASE))
   {
      STATUS_TIME_SYNC_STATUS_Subst->STS_NO_TSYN_ERROR = 1;
   }
   /* when both bit-3 is 1 and bit-0 is 1 */
   /* when both bit-3 is 0 and bit-0 is 0 */
   else
   {
      STATUS_TIME_SYNC_STATUS_Subst->STS_NO_TSYN_ERROR = 0;
   }

   STATUS_TIME_SYNC_STATUS_Subst->STS_POINT_OF_TRIGGER = SIG_NOT_IMPLEMENTED;
   STATUS_TIME_SYNC_STATUS_Subst->STS_TIME_SYNC_OFFSET = SIG_NOT_IMPLEMENTED;
}
/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Rdr_Radar_Status
 *. This function will populate radar status
 *.
 *. Parameters: SR_Status_Radar *STATUS_RADAR_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/

void Vehicle_Com_Populate_Rdr_Radar_Status(SR_Status_Radar *STATUS_RADAR_Subst)
{
   STATUS_RADAR_Subst->STS_AF_CORE_THROUGHPUT  = SIG_NOT_IMPLEMENTED;
   STATUS_RADAR_Subst->STS_MMIC_RE_INIT_COUNT  = Get_MMIC_Error_Reinit_Count();
   STATUS_RADAR_Subst->STS_RDD_CORE_THROUGHPUT = SIG_NOT_IMPLEMENTED;
   STATUS_RADAR_Subst->STS_SCAN_TYPE           = SIG_NOT_IMPLEMENTED;
   STATUS_RADAR_Subst->STS_XCVR_OPERATIONAL =
      (Rte_DT_SR_Status_Radar_4)(RADAR_CTL_INIT_SUCCESS == Get_Radar_Ctl_Init_Status()) ? true : false;
}

/*****************************************************************************
 *. Name: Vehicle_Com_Read_ASDM_Vehicle_Status
 *. This function will read ASDM vehicle status
 *.
 *. Parameters:SR_Status_Vehicle *STATUS_VEHICLE_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Read_ASDM_Vehicle_Status(SR_VEHICLE_STATUS_RECORD *veh_status_ptr)
{
   /* Vehicle info*/
   g_someIpRxSig.odometer_val     = veh_status_ptr->System_Status_Vehicle.SSTS_VEH_ODOMETER;
   g_someIpRxSig.veh_pwr_mode_sts = veh_status_ptr->System_Status_Vehicle.SSTS_VEH_POWER_MODE_STATUS;
   g_someIpRxSig.veh_sys_vtg      = veh_status_ptr->System_Status_Vehicle.SSTS_VEH_SYSTEM_VOLTAGE;

   g_someIpRxSig.veh_state = veh_status_ptr->System_Status_Vehicle.SSTS_VEHICLE_STATE;

   g_someIpRxSig.veh_speed                = veh_status_ptr->System_Status_Vehicle.SSTS_VEHICLE_SPEED_CALC;
   g_someIpRxSig.veh_yaw                  = veh_status_ptr->System_Status_Vehicle.SSTS_YAW_RATE_CALC;
   g_someIpRxSig.veh_steering_angle       = veh_status_ptr->System_Status_Vehicle.SSTS_STEERING_ANGLE;
   g_someIpRxSig.veh_speed_qf             = veh_status_ptr->System_Status_Vehicle.SSTS_VEHICLE_SPEED_CALC_QF;
   g_someIpRxSig.veh_yaw_qf               = veh_status_ptr->System_Status_Vehicle.SSTS_YAW_RATE_CALC_QF;
   g_someIpRxSig.veh_steering_sign_status = veh_status_ptr->System_Status_Vehicle.SSTS_STEERING_ANGLE_SIGN;

   g_someIpRxSig.drive_reverse       = veh_status_ptr->System_Status_Vehicle_State.SSTS_DRIVE_REVERSE;
   g_someIpRxSig.drive_dir           = veh_status_ptr->System_Status_Vehicle_State.SSTS_DRIVE_DIR;
   g_someIpRxSig.gear_position       = veh_status_ptr->System_Status_Vehicle_State.SSTS_GEAR_POSITION;
   g_someIpRxSig.veh_ign_status      = veh_status_ptr->System_Status_Vehicle_State.SSTS_IGN_STATUS;
   g_someIpRxSig.yaw_rate_bias       = veh_status_ptr->System_Status_Vehicle.SSTS_YAW_RATE_BIAS;
   g_someIpRxSig.veh_spd_comp_factor = veh_status_ptr->System_Status_Vehicle.SSTS_VEH_SPD_COMP_FACTOR;

   /* ADAS Version */
   g_someIpRxSig.sw_version_adas     = veh_status_ptr->System_Status_ADAS_Version.SSTS_SW_VERSION_ADAS;
   g_someIpRxSig.can_pcan_minor_adas = veh_status_ptr->System_Status_ADAS_Version.SSTS_CAN_PCAN_MINOR_ADAS;
   g_someIpRxSig.can_pcan_major_adas = veh_status_ptr->System_Status_ADAS_Version.SSTS_CAN_PCAN_MAJOR_ADAS;

   /* Absolute Time */
   g_someIpRxSig.veh_abs_time_day  = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Day;
   g_someIpRxSig.veh_abs_time_hr   = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Hour;
   g_someIpRxSig.veh_abs_time_min  = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Minute;
   g_someIpRxSig.veh_abs_time_mnth = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Month;
   g_someIpRxSig.veh_abs_time_sec  = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Second;
   g_someIpRxSig.veh_abs_time_yr   = veh_status_ptr->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Year;
}

/*****************************************************************************
 *. Name: Get_Vehicle_Com_Read_ASDM_Vehicle_Status
 *. This function will provide ASDM vehicle status to other
 *.
 *. Parameters: None
 *.
 *. Return Value: SR_SystemStatusVehicle *STATUS_VEHICLE_Subst
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
SR_SystemStatusVehicle *Get_Vehicle_Com_SOMEIP_Vehicle_Status(void)
{
   return ((SR_SystemStatusVehicle *)&gReceived_Vehicle_Status_Data.System_Status_Vehicle);
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Rdr_Vehicle_Status
 *. This function will populate radar vehicle status
 *.
 *. Parameters:SR_Status_Vehicle *STATUS_VEHICLE_Subst
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Rdr_Vehicle_Status(SR_Status_Vehicle *STATUS_VEHICLE_Subst)
{
   // D2M_Msg_T *d2m_buf_ptr                = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   volatile M2D_Msg_T *m2d_buf_ptr          = Get_MSS_IPC_M2D_Msg_Buffer();
   STATUS_VEHICLE_Subst->STS_STEERING_ANGLE = (m2d_buf_ptr->payload.veh_data.vse_output.comp_steering_angle_deg * DEG_TO_RAD_F32);
   STATUS_VEHICLE_Subst->STS_STEERING_ANGLE_SIGN =
      (m2d_buf_ptr->payload.veh_data.vse_output.comp_steering_angle_deg < 0.0f) ? 1 : 0;
   STATUS_VEHICLE_Subst->STS_VEH_SPEED_DIRECTION    = (m2d_buf_ptr->payload.veh_data.vse_output.reverse_status == 1) ? 1 : 0;
   STATUS_VEHICLE_Subst->STS_VEHICLE_SPEED_CALC     = m2d_buf_ptr->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
   STATUS_VEHICLE_Subst->STS_VEHICLE_SUPPLY_VOLTAGE = SIG_NOT_IMPLEMENTED;
   STATUS_VEHICLE_Subst->STS_YAW_RATE_BIAS          = m2d_buf_ptr->payload.veh_data.vse_output.yaw_rate_bias;
}

/*****************************************************************************
 *. Name:Vehicle_Com_Populate_Rdr_fault_Status
 *. This function will populate radar fault status
 *.
 *. Parameters:STATUS_FAULTS_ETH *STATUS_FAULTS_Subst
 *.
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Rdr_fault_Status(SR_Status_Faults *STATUS_FAULTS_Subst)
{
   STATUS_FAULTS_Subst->STS_CORE_ACTIVE_FAULTS = SIG_NOT_IMPLEMENTED;
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Detections_header
 *. This function populates e2e header data
 *.
 *. Parameters: SR_EtoE_HDR *Detections_E2E_header
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Detections_header(SR_EtoE_HDR *Det_E2EX_Header)
{
   Det_E2EX_Header->EtoE_CRC     = (Rte_DT_SR_EtoE_HDR_0)SIG_NOT_IMPLEMENTED;
   Det_E2EX_Header->EtoE_LENGTH  = (Rte_DT_SR_EtoE_HDR_3)SIG_NOT_IMPLEMENTED;
   Det_E2EX_Header->EtoE_COUNTER = (Rte_DT_SR_EtoE_HDR_1)SIG_NOT_IMPLEMENTED;
   Det_E2EX_Header->EtoE_DATA_ID = (Rte_DT_SR_EtoE_HDR_2)SIG_NOT_IMPLEMENTED;
}

/*****************************************************************************
 *. Name: Vehicle_Com_Populate_Static_Alignment
 *. This function popultaes header alignment detials
 *.
 *. Parameters: SR_Alignment_Static *Det_Static_Alignment_Substruct
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Vehicle_Com_Populate_Static_Alignment(SR_Alignment_Static *Det_Static_Alignment_Substruct)
{
   // float32_t rdr_align_msg_static_float;
   // AlignmentStatic_T AlignmentStatic;
   Det_Static_Alignment_Substruct->STS_AlignmentStaticStatus = Get_AlignmentStatic()->AlignmentStaticStatus;
   Det_Static_Alignment_Substruct->STS_ImpactByInterference  = Get_AlignmentStatic()->ImpactByInterference;
   Det_Static_Alignment_Substruct->STS_Measured_Range        = Get_AlignmentStatic()->MeasuredRange;
   Det_Static_Alignment_Substruct->STS_MeasuredRangeRate     = Get_AlignmentStatic()->MeasuredRangeRate;
   Det_Static_Alignment_Substruct->STS_MeasuredRangeRateStd  = Get_AlignmentStatic()->MeasuredRangeStd;
   Det_Static_Alignment_Substruct->STS_MeasuredRangeStd      = Get_AlignmentStatic()->MeasuredRangeRateStd;
   Det_Static_Alignment_Substruct->STS_MeasuredRCS           = Get_AlignmentStatic()->MeasuredAmplitude;
   Det_Static_Alignment_Substruct->STS_MeasuredRCSStd        = Get_AlignmentStatic()->MeasuredAmpStd;
}

// Nolan: I commented this out since this function and return value don't exist on this project as of now.
// #ifdef TRACKER_MAIN_FUSION_SENSOR
// REV2_DOWN_SEL_DETECTION_STRUCT_ETH *Get_Slave_Detections_data(void)
// {
//    return &gReceived_Slave_Detection_Data;
// }
// #endif

SomeIpRxSignals_t *Get_SomeIp_Rx_Sig(void)
{
   return ((SomeIpRxSignals_t *)&g_someIpRxSig);
}
// #pragma clang optimize on
