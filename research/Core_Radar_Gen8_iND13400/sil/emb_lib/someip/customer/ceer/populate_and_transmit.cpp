#include "populate_and_transmit.h"
#include "emblib_ipc_data.h"
#include "sil_wrapper_common.h"
#include "someip_driver.h"
#include <cstring>

#define SIZE_OF_IPV4_HEADER_16BITS (10)
#define POSITION_OF_CHECKSUM       (5)
#define MAX_16BIT_VALUE            (0xFFFF)
#define CS_CARRY_MASK              (uint32_t)(0xFFFF0000)
#define CS_CARRY_SHIFT             (16)
#define CS_MASK                    (uint32_t)(0x0000FFFF)
// #define VLAN_ID                   (0x0068)
// #define SRC_MAC                   (0xC0A80147)
// #define DST_MAC                   (0xC0A80164)
// #define ETH_TYPE                  (0x0800)
#define SOMEIP_DATA_BUFFER_SIZE   (1500)
#define SOMEIP_HDR_SIZE           (48)
#define DETECTION_CHUNK_SIZE      (1392)
#define DETECTION_LAST_CHUNK_SIZE (392)

static ENET_Decoded_Types_T data_ptr;
static ENET_Encoded_Types_T encode_ptr;
static SOMEIP_ID_Struct_T SOMEIP_Tx_Buff_someip[MAX_SOMEIP_MESSAGES];
static uint16_t total_someip_buff_Len = 0;
static int frame_index                = 0;
// static int time =0;
unsigned char *buffer_temp      = NULL;
unsigned char UDPbyteBuffer[12] = {0};
unsigned char byteBuffer[1450]  = {0};

D2M_Msg_T *ipc_d2m_Someip                = Get_IPC_D2M_Buffer();
D2M_Msg_T *ipc_d2m_Someip                = Get_IPC_D2M_Buffer();
M2D_Msg_T *ipc_m2d_Someip                = Get_IPC_M2D_Buffer();
M2D_One_Time_Msg_T *ipc_m2d_One_Time_Msg = Get_IPC_M2D_One_Time_Buffer();
#if (DOWNSELECTION_ENABLE == 1U)
Down_selection_Stream_T *af_target_report_ptr_Someip = &(ipc_d2m_Someip->payload.downselection_data);
#else
AF_Det_T *af_target_report_ptr_Someip = &(ipc_d2m_Someip->payload.det_data.af_data);
#endif
Toi_Stream_T *TOI_Stream_Ptr_Someip                  = &ipc_d2m_Someip->payload.toi_stream_data;
Damping_Monitor_Output_Stream_T *Damping_data        = &(ipc_d2m_Someip->payload.radar_capability_data.dm);
STATIC_ALIGNMENT_STREAM_LOGGING_T *static_Stream_ptr = &(ipc_d2m_Someip->payload.alignment_stream_data.static_align_stream_output);
Dynamic_Alignment_Data_T *dynamic_alignment_data     = &(ipc_m2d_Someip->payload.alignment_Info.dynamic_alignment_data);
Radar_Capability_Stream_T *Radar_Capability_Stream_ptr    = &(ipc_d2m_Someip->payload.radar_capability_data);
Blockage_Output_Stream_T *block_output_ptr                = &(ipc_d2m_Someip->payload.radar_capability_data.blockage);
Free_Sight_Check_Output_Stream_T *free_sight_ptr          = &(ipc_d2m_Someip->payload.radar_capability_data.fsc);
Range_Estimation_Output_Stream_T *range_estimation_ptr    = &(ipc_d2m_Someip->payload.radar_capability_data.re);
Side_Lobe_Level_Output_Stream_T *side_lobe_ptr            = &(ipc_d2m_Someip->payload.radar_capability_data.sll);
ALIGNMENT_FLAT_PLATE_OUTPUT_T *alignment_flat_ptr         = &(ipc_d2m_Someip->payload.alignment_stream_data.static_align_output);
ALIGNMENT_FLAT_PLATE_INTERNALS_T *alignment_internals_ptr = &(ipc_d2m_Someip->payload.alignment_stream_data.static_align_internal);
Dynamic_Alignment_Log_Stream_T *da_log_stream             = &(Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream);
Veh_Raw_Data_T *veh_info_ptr =
   &(Get_IPC_M2D_Buffer()->payload.veh_data.veh_raw_data[Get_IPC_M2D_Buffer()->payload.veh_data.latest_raw_index]);
Header_Stream_T *header_stream_ptr   = Get_Header_Log_Data_Ptr();
Status_Stream_T *status_log_data_ptr = Get_Status_Log_Data_Ptr();

unsigned short B2L_s(unsigned short arg)
{
   unsigned short ret = 0;
   unsigned short i   = 0;

   char *dst       = (char *)(&ret);
   const char *src = (const char *)(&arg + 1);

   for (; i < sizeof(unsigned short); i++)
      *dst++ = *--src;

   return ret;
}

uint16_t ComputeIPV4_Checksum(uint8_t *input_buff)
{
   char idx                = 0;
   char f_cs_done          = 0;
   uint32_t checksum       = 0;
   uint16_t checksum_carry = 0;
   uint16_t ip_word        = 0;
   uint16_t ret_cs         = 0;
   uint16_t low_byte_word  = 0;
   uint16_t high_byte_word = 0;

   for (idx = 0; idx < SIZE_OF_IPV4_HEADER_16BITS; idx++)
   {
      if (idx != POSITION_OF_CHECKSUM) /* Skip CS word while computing CS*/
      {
         ip_word = (uint16_t)((uint16_t)input_buff[idx * 2] << 8) | (input_buff[idx * 2 + 1]);
         checksum += ip_word;
      }
   }

   while (!f_cs_done)
   {
      if (checksum > (uint32_t)MAX_16BIT_VALUE)
      {
         checksum_carry = (checksum & CS_CARRY_MASK) >> CS_CARRY_SHIFT;
         checksum &= CS_MASK;
         checksum += checksum_carry;
      }
      else
      {
         f_cs_done = 1;
      }
   }

   ret_cs = (uint16_t)(~checksum);
   ret_cs = B2L_s(ret_cs);

   return (ret_cs);
}

uint16_t ComputeUDP_Checksum_SOMEIP(SOMEIP_ID_Struct_T SomIP)
{
   char f_cs_done          = 0;
   uint32_t checksum       = 0;
   uint16_t checksum_carry = 0;
   uint16_t UDP_word       = 0;
   uint16_t ret_cs         = 0;

   memset(&byteBuffer[0], 0, 1450);
   uint16_t dataLength    = 0;
   SOMIP_RECORD_T recordd = {0};

   UDPpseudoHeader_T UDPpseudoHeader;
   memcpy(&recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_Dest, &SomIP.SOMEIP_Buff[16], 40);
   memcpy(&recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_Source, &SomIP.SOMEIP_Buff[12], 40);
   memcpy(&recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_protocol, &SomIP.SOMEIP_Buff[9], 40);
   memcpy(&recordd.Eth_StackHeaderInfo.UDP_HeaderInfo.UDP_Length, &SomIP.SOMEIP_Buff[24], 40);
   memcpy(&recordd.SOMIP_payload, &SomIP.SOMEIP_Buff[28], sizeof(recordd.SOMIP_payload));

   UDPpseudoHeader.UPH_Dest     = recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_Dest;
   UDPpseudoHeader.UPH_Source   = recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_Source;
   UDPpseudoHeader.UPH_protocol = recordd.Eth_StackHeaderInfo.IPV4_HeaderInfo.IP_protocol;
   UDPpseudoHeader.UPH_Length   = recordd.Eth_StackHeaderInfo.UDP_HeaderInfo.UDP_Length;
   dataLength                   = B2L_s(UDPpseudoHeader.UPH_Length);
   memcpy(&UDPbyteBuffer[0], &UDPpseudoHeader, sizeof(UDPpseudoHeader_T));

   memcpy(&byteBuffer[0], &recordd.Eth_StackHeaderInfo.UDP_HeaderInfo, dataLength);
   byteBuffer[6] = 0x00;
   byteBuffer[7] = 0x00;
   memcpy(&byteBuffer[8], recordd.SOMIP_payload, dataLength);
   // compute pseudo header CS
   for (char idx = 0; idx < 5; idx++)
   {
      UDP_word = (uint16_t)((uint16_t)UDPbyteBuffer[idx * 2] << 8) | (UDPbyteBuffer[idx * 2 + 1]);
      checksum += UDP_word;
   }
   UDP_word = 0X0011;
   checksum += UDP_word; // protocol & length

   // compute UDP+data  CS
   for (uint16_t id = 0; (id < 1450 && id < dataLength); id++)
   {
      if (id & 1)
         checksum += (uint32_t)byteBuffer[id];
      else
         checksum += (uint32_t)byteBuffer[id] << 8;
   }

   while (!f_cs_done)
   {
      if (checksum > (uint32_t)MAX_16BIT_VALUE)
      {
         checksum_carry = (checksum & CS_CARRY_MASK) >> CS_CARRY_SHIFT;
         checksum &= CS_MASK;
         checksum += checksum_carry;
      }
      else
      {
         f_cs_done = 1;
      }
   }

   ret_cs = (uint16_t)(~checksum);
   ret_cs = B2L_s(ret_cs);

   return (ret_cs);
}

void Populate_SomeIP_CommonBytes(uint8_t *p_SomeIP, int *index)
{
   static int id_counter = 0x002E;
   id_counter++;

   // IPv4
   p_SomeIP[0] = 0x45; // Version & Header Length
   p_SomeIP[1] = 0x00; // Svc Field

   p_SomeIP[4] = 0xC8; // id_counter >> 8;
   p_SomeIP[5] = 0xCD; // id_counter;		//id

   p_SomeIP[6] = 0x40;
   p_SomeIP[7] = 0x00;
   p_SomeIP[8] = 0x40; // TTL
   p_SomeIP[9] = 0x11; // UDP - Protocol

   // Source IP Address filling Ipv4
   p_SomeIP[12] = 0xC0;
   p_SomeIP[13] = 0xA8;
   p_SomeIP[14] = 0x01;
   if (FRONT_LEFT == Get_Radar_Position())
      p_SomeIP[15] = 0x4A;
   else if (FRONT_RIGHT == Get_Radar_Position())
      p_SomeIP[15] = 0x49;
   else if (REAR_LEFT == Get_Radar_Position())
      p_SomeIP[15] = 0x47;
   else if (REAR_RIGHT == Get_Radar_Position())
      p_SomeIP[15] = 0x48;
   else
      p_SomeIP[15] = 0x4B;

   p_SomeIP[16] = 0xC0;
   p_SomeIP[17] = 0xA8;
   p_SomeIP[18] = 0x01;
   p_SomeIP[19] = 0x64; // Destination

   p_SomeIP[36] = 0x00;
   p_SomeIP[37] = 0x00; // Client ID
   p_SomeIP[38] = Get_Current_Scan_Index() >> 8;
   p_SomeIP[39] = Get_Current_Scan_Index();
   p_SomeIP[40] = 0x01; // Protocol Ver
   p_SomeIP[41] = 0x01; // Interface Ver
}

void populate_object_data()
{
   memset(&data_ptr, 0, sizeof(data_ptr));

   for (int index = 0; index < 127; index++)
   {
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE = af_target_report_ptr_Someip->af_ds_data.ran[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE_ERR = TOI_Stream_Ptr_Someip->toi_data.std_ran[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE_VELOCITY =
         af_target_report_ptr_Someip->af_ds_data.vel[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_ELEVATION =
         af_target_report_ptr_Someip->af_ds_data.phi[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_ELEVATION_ERR =
         TOI_Stream_Ptr_Someip->toi_data.std_phi[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_AZIMUTH =
         af_target_report_ptr_Someip->af_ds_data.theta[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_AZIMUTH_ERR =
         TOI_Stream_Ptr_Someip->toi_data.std_theta[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_SUPER_RES_TARGET =
         af_target_report_ptr_Someip->af_ds_data.f_superres_target[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_HVC_FLAG          = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_POINT_TARGET_PROB = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_CONFD_AZIMUTH =
         af_target_report_ptr_Someip->af_ds_data.az_conf[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_CONFD_ELEVATION =
         af_target_report_ptr_Someip->af_ds_data.el_conf[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_OUTSIDE_SECTOR = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_EXISTENCE_PROB = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_SNR = af_target_report_ptr_Someip->af_ds_data.snr[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RCS = af_target_report_ptr_Someip->af_ds_data.rcs[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_BI_STATIC_FLAG =
         af_target_report_ptr_Someip->af_ds_data.f_bistatic[index];
   }

#if (DOWNSELECTION_ENABLE != 1)
   for (; index < AF_MAX_NUM_DET; index++)
   {
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE = af_target_report_ptr_Someip->af_ds_data.ran[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE_ERR = TOI_Stream_Ptr_Someip->toi_data.std_ran[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RANGE_VELOCITY =
         af_target_report_ptr_Someip->af_ds_data.vel[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_ELEVATION =
         af_target_report_ptr_Someip->af_ds_data.phi[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_ELEVATION_ERR =
         TOI_Stream_Ptr_Someip->toi_data.std_phi[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_AZIMUTH =
         af_target_report_ptr_Someip->af_ds_data.theta[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_AZIMUTH_ERR =
         TOI_Stream_Ptr_Someip->toi_data.std_theta[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_SUPER_RES_TARGET =
         af_target_report_ptr_Someip->af_ds_data.f_superres_target[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_HVC_FLAG          = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_POINT_TARGET_PROB = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_CONFD_AZIMUTH =
         af_target_report_ptr_Someip->af_ds_data.az_conf[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_CONFD_ELEVATION =
         af_target_report_ptr_Someip->af_ds_data.el_conf[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_OUTSIDE_SECTOR = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_EXISTENCE_PROB = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_SNR = af_target_report_ptr_Someip->af_ds_data.snr[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_RCS = af_target_report_ptr_Someip->af_ds_data.rcs[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_BI_STATIC_FLAG =
         af_target_report_ptr_Someip->af_ds_data.f_bistatic[index];
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_MH_CYCLE_COUNTER = 0;
      data_ptr.DETECTIONS_RECORD.DETECTIONS_ARRAY.Dimension[index].DET_MH_CRC           = 0;
   }
#endif

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MAJOR = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MINOR = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_PATCH = 0;

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_RADAR_STATE.HED_DATA_QUALIFIER =
      TOI_Stream_Ptr_Someip->toi_data.data_qualifier;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_RADAR_STATE.HED_LOOK_ID                 = header_stream_ptr->lookindex;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_RADAR_STATE.HED_NUM_OF_VALID_DETECTIONS = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_RADAR_STATE.HED_LOOK_INDEX = ipc_m2d_Someip->payload.look_Info.look_index;

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_RANGE_MAX       = header_stream_ptr->det_range_max;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_RANGE_MIN       = header_stream_ptr->det_range_min;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MAX = header_stream_ptr->speed_range_max;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MIN = header_stream_ptr->speed_range_min;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_HOR_MAX = header_stream_ptr->sensor_fov_hor_max;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_HOR_MIN = header_stream_ptr->sensor_fov_hor_min;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_VER_MAX = header_stream_ptr->sensor_fov_ver_max;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_VER_MIN = header_stream_ptr->sensor_fov_ver_min;

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_NS  = header_stream_ptr->sensor_timestamp_ns;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_SEC = header_stream_ptr->sensor_timestamp_sec;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TIME_SYNC_SRC_MASTER =
      header_stream_ptr->time_sync_source_master;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TIME_SYNC_VALIDITY_FLAG =
      header_stream_ptr->time_sync_validity_flag;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TRIGGER_TIME = 0;

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_AF_TIME_PEAK       = header_stream_ptr->af_xput_peak;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_AF_TIME_INST       = header_stream_ptr->af_xput_inst;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_RDD_CORE_TIME_PEAK = header_stream_ptr->rdd_xput_peak;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_RDD_CORE_TIME_INST = header_stream_ptr->rdd_xput_inst;

   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_NUM_OF_1PASS =
      header_stream_ptr->detection_num_1st_pass;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_NUM_OF_2PASS =
      header_stream_ptr->detection_num_2nd_pass;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_BI_STATIC_COUNT      = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_MAX_NUM_OF_DETECTIONS    = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_OPERATION_MODE           = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_NUM_OF_RESTBINS_USED     = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_PROCESSED_RANGE          = 0;
   data_ptr.DETECTIONS_RECORD.DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_SLOPE_CORR_EXECUTIONFLAG = 0;

   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_USC_CAL_VER_MAJOR      = status_log_data_ptr->usc_version_major;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_USC_CAL_VER_MINOR      = status_log_data_ptr->usc_version_minor;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_USC_SECTION_COMPTBLITY = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_SMC_CAL_VER_MAJOR      = status_log_data_ptr->smc_version_major;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_SMC_CAL_VER_MINOR      = status_log_data_ptr->smc_version_minor;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_SMC_SECTION_COMPTBLITY = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_CALIBRATION_VERSION.STS_SMC_PLATFROM_VERSION   = 0;

   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_POSITION         = ipc_m2d_One_Time_Msg->radar_position;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_PITCH = dynamic_alignment_data->iso_sensor_pitch;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_ROLL  = dynamic_alignment_data->iso_sensor_roll;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_X      = dynamic_alignment_data->iso_sensor_x_posn;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_Y      = dynamic_alignment_data->iso_sensor_y_posn;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_YAW   = dynamic_alignment_data->iso_sensor_yaw;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_Z      = dynamic_alignment_data->iso_sensor_z_posn;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_MOUNT_LOCATION   = dynamic_alignment_data->mount_loc;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_MOUNTING_POS.STS_SENSOR_HEIGHT           = 0;

   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_DET_DBC_BASE_VER_MINOR = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_DET_DBC_BASE_VER_MAJOR = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_HARDWARE_VERSION       = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_PLATFORM_VARIANT       = status_log_data_ptr->platform_variant;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_SERIAL_NUM_JULIAN_YEAR = status_log_data_ptr->sts_serial_num_julian_year;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_SERIAL_NUM_JULIAN_DAY  = status_log_data_ptr->sts_serial_num_julian_day;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_HW_CAN_VERSION.STS_SERIAL_NUMBER_SEQUENCE = status_log_data_ptr->sts_serial_number_sequence;

   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_SW_VERSION_FIELD1  = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_SW_VERSION_FIELD2  = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_SW_VERSION_FIELD3  = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_SW_VERSION_FIELD4  = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_PBL_VERSION_FIELD1 = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_PBL_VERSION_FIELD2 = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_PBL_VERSION_FIELD3 = 0;
   data_ptr.RADAR_SW_INFO_RECORD.INFO_SW_VERSION.STS_PBL_VERSION_FIELD4 = 0;

   // data_ptr.Status_System_Time.STS_TIME_SINCE_POWER_ON = status_log_data_ptr->time_since_power_on;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_VEH_SPEED_DIRECTION    = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_STEERING_ANGLE_SIGN    = (veh_info_ptr->steering_whl_angle >= 0) ? 0 : 1;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_VEHICLE_SPEED_CALC     = veh_info_ptr->ego_vehicle_speed;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_VEHICLE_SUPPLY_VOLTAGE = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_YAW_RATE_BIAS          = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_VEHICLE.STS_STEERING_ANGLE         = veh_info_ptr->steering_whl_angle;

   data_ptr.RADAR_STATUS_RECORD.STS_SENSOR_PERF.STS_BRR_STATUS = 0;

   data_ptr.RADAR_STATUS_RECORD.STS_TIMESYNC_STATUS.STS_POINT_OF_TRIGGER = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_TIMESYNC_STATUS.STS_NO_TSYN_ERROR    = 0;

   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_BlockageSensitivity   = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_BlockageActive        = block_output_ptr->blockage_active;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_BlockageStatus        = block_output_ptr->blockage_status;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_BlockageValue         = block_output_ptr->blockage.value;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_BlockageProbability   = block_output_ptr->blockage.probability;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_FreeSightCheckActive  = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_FreeSightCheckStatus  = free_sight_ptr->run_status;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_SLBlockageFlag        = 0;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RDR_PERF.CAP_SLBlockageFilterValue = 0;

   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_DAMPING.CAP_DampingCurrent           = Damping_data->damping.current_dB;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_DAMPING.CAP_DampingActive            = Damping_data->dm_active;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_DAMPING.CAP_DampingStatus            = Damping_data->dm_status;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_DAMPING.CAP_DampingStandardDeviation = Damping_data->damping.std_dB; // need to confirm.

   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RANGE_DET.CAP_RangeEstimationActive = range_estimation_ptr->re_active;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RANGE_DET.CAP_RangeEstimationStatus = range_estimation_ptr->re_status;
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RANGE_DET.CAP_MaxDetectionRangeCar.Element[0] =
      range_estimation_ptr->max_det_range_car[0];
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RANGE_DET.CAP_MaxDetRangeMotorbike.Element[0] =
      range_estimation_ptr->max_det_range_motorbike[0];
   data_ptr.RADAR_STATUS_RECORD.STS_CAPAB_RANGE_DET.CAP_MaxDetRangePedestrian.Element[0] =
      range_estimation_ptr->max_det_range_pedestrian[0];
   data_ptr.RADAR_STATUS_RECORD.STS_ALIGNMENT_HANDLER.STS_CalDisplay = 0;
}

void encode_someip_messages()
{
   // memcpy(&encode_ptr,&data_ptr,sizeof(encode_ptr));
   encode_DETECTIONS_RECORD(&encode_ptr, &data_ptr);
   encode_RADAR_STATUS_RECORD(&encode_ptr, &data_ptr);
   encode_RADAR_SW_INFO_RECORD(&encode_ptr, &data_ptr);
   encode_VEHICLE_STATUS_RECORD(&encode_ptr, &data_ptr);
}

void Prepare_detection_HDR(unsigned char *p_SomeIP, uint8_t chunk_num, boolean_t lastchunk)
{
   if (lastchunk)
   {
      p_SomeIP[2]  = 0x01;
      p_SomeIP[3]  = 0xB8; // Length - IPv4
      p_SomeIP[24] = 0x01;
      p_SomeIP[25] = 0x9C; // Length - UDP

      p_SomeIP[32] = 0x00;
      p_SomeIP[33] = 0x00;
      p_SomeIP[34] = 0x01;
      p_SomeIP[35] = 0x8C; // Length - PDU

      p_SomeIP[42] = 0x22; // Msg Type
      p_SomeIP[43] = 0x00;
      p_SomeIP[44] = 0x00;
      p_SomeIP[45] = 0x00;
      p_SomeIP[46] = 0x2B;
      p_SomeIP[47] = 0x80;
   }
   else
   {
      p_SomeIP[2]  = 0x05;
      p_SomeIP[3]  = 0xA0; // Length - IPv4
      p_SomeIP[24] = 0x05;
      p_SomeIP[25] = 0x8C; // Length - UDP

      p_SomeIP[32] = 0x00;
      p_SomeIP[33] = 0x00;
      p_SomeIP[34] = 0x05;
      p_SomeIP[35] = 0x7C;

      p_SomeIP[42]        = 0x22; // Msg Type
      p_SomeIP[43]        = 0x00;
      p_SomeIP[44]        = 0x00;
      p_SomeIP[45]        = 0x00;
      uint16_t offset_val = (chunk_num - 1) * 87;
      offset_val          = (offset_val << 4) | 0b0001;
      p_SomeIP[46]        = offset_val >> 8;
      p_SomeIP[47]        = offset_val;
   }

   p_SomeIP[20] = 0x86;
   p_SomeIP[21] = 0xC5; // Source port udp
   p_SomeIP[22] = 0x77;
   p_SomeIP[23] = 0x25; // Dest port UDP

   p_SomeIP[28] = 0x00;
   p_SomeIP[29] = 0x10;
   p_SomeIP[30] = 0x80;
   p_SomeIP[31] = 0x01; // AUTOSAR PDU MULTIPLEXING ID

   Populate_SomeIP_CommonBytes(p_SomeIP, &frame_index);

   uint16_t udpchecksum = ComputeUDP_Checksum_SOMEIP(SOMEIP_Tx_Buff_someip[chunk_num - 1]);
   //(*index)++;
   p_SomeIP[26] = udpchecksum;
   p_SomeIP[27] = udpchecksum >> 8;

   uint16_t ipv4checksum = ComputeIPV4_Checksum(p_SomeIP);
   p_SomeIP[10]          = ipv4checksum;
   p_SomeIP[11]          = ipv4checksum >> 8;
}

void add_encoded_Detections(ENET_encoded::DETECTIONS_RECORD_T *e_ptr, SOMEIP_Radar_Struct_T *someip_radar_data)
{
   unsigned char *detection_buffer_temp = new unsigned char[sizeof(encode_ptr.DETECTIONS_RECORD)];
   memset(detection_buffer_temp, 0, sizeof(*detection_buffer_temp));
   memcpy(detection_buffer_temp, e_ptr, sizeof(encode_ptr.DETECTIONS_RECORD));
   int det_frames = 0;
   int index      = 0;
   ++time;
   for (; det_frames < 30; det_frames++)
   {
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Flag         = 1;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_PLPTimeStamp = time;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_VLAN_ID      = someip_radar_data->Vlan_id;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_src_MACaddr  = someip_radar_data->Src_Mac;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Dest_MACaddr = someip_radar_data->Dst_Mac;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Ether_type   = someip_radar_data->Eth_Type;
      SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Data_Len     = DETECTION_CHUNK_SIZE + SOMEIP_HDR_SIZE;
      memcpy(&SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Buff[SOMEIP_HDR_SIZE], &(detection_buffer_temp[index]),
             DETECTION_CHUNK_SIZE);
      Prepare_detection_HDR(SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff, det_frames + 1, 0);
      ++frame_index;
      ++total_someip_buff_Len;
      index += DETECTION_CHUNK_SIZE;
   }
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Flag         = 1;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_PLPTimeStamp = time;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_VLAN_ID      = someip_radar_data->Vlan_id;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_src_MACaddr  = someip_radar_data->Src_Mac;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Dest_MACaddr = someip_radar_data->Dst_Mac;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Ether_type   = someip_radar_data->Eth_Type;
   SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Data_Len     = DETECTION_LAST_CHUNK_SIZE + SOMEIP_HDR_SIZE;
   Prepare_detection_HDR(SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff, det_frames + 1, 1);
   memcpy(&SOMEIP_Tx_Buff_someip[det_frames].SOMEIP_Buff[SOMEIP_HDR_SIZE], &(detection_buffer_temp[index]),
          DETECTION_LAST_CHUNK_SIZE);
   ++frame_index;
   ++total_someip_buff_Len;
   memset(&SOMEIP_Tx_Buff_someip[det_frames + 1].SOMEIP_Buff[0], 0, SOMEIP_DATA_BUFFER_SIZE);
   delete detection_buffer_temp;
}

void prepare_rdr_status_HDR(unsigned char *bufferdet, uint8_t chunk_num)
{
   bufferdet[2]  = 0x01;
   bufferdet[3]  = 0x31; // Length - IPv4
   bufferdet[24] = 0x01;
   bufferdet[25] = 0x1D; // Length - UDP

   bufferdet[32] = 0x00;
   bufferdet[33] = 0x00;
   bufferdet[34] = 0x01;
   bufferdet[35] = 0x0D; // AUTOSAR PDU MULTIPLEXING Length

   bufferdet[42] = 0x02; // Msg Type
   bufferdet[43] = 0x00;
   bufferdet[44] = 0x00;
   bufferdet[45] = 0x00;
   bufferdet[46] = 0x00;
   bufferdet[47] = 0x00;

   bufferdet[20] = 0x86;
   bufferdet[21] = 0xC5; // Source port udp
   bufferdet[22] = 0x77;
   bufferdet[23] = 0x25; // Dest port UDP

   bufferdet[28] = 0x00;
   bufferdet[29] = 0x11;
   bufferdet[30] = 0x80;
   bufferdet[31] = 0x03; // AUTOSAR PDU MULTIPLEXING ID

   Populate_SomeIP_CommonBytes(bufferdet, &frame_index);

   uint16_t udpchecksum = 0;
   udpchecksum          = ComputeUDP_Checksum_SOMEIP(SOMEIP_Tx_Buff_someip[chunk_num - 1]);
   //(*index)++;
   bufferdet[26] = udpchecksum;
   bufferdet[27] = udpchecksum >> 8;

   uint16_t ipv4checksum = ComputeIPV4_Checksum(bufferdet);
   bufferdet[10]         = ipv4checksum;
   bufferdet[11]         = ipv4checksum >> 8;
}

void add_encoded_RADAR_STATUS_RECORD_T(ENET_encoded::RADAR_STATUS_RECORD_T *e_ptr, unsigned char *buffer_temp,
                                       SOMEIP_Radar_Struct_T *someip_radar_data)
{
   memset(buffer_temp, 0, sizeof(buffer_temp));
   memcpy(buffer_temp, e_ptr, sizeof(ENET_encoded::RADAR_STATUS_RECORD_T));

   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Flag         = 1;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_PLPTimeStamp = ++time;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_VLAN_ID      = someip_radar_data->Vlan_id;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_src_MACaddr  = someip_radar_data->Src_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Dest_MACaddr = someip_radar_data->Dst_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Ether_type   = someip_radar_data->Eth_Type;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Data_Len     = sizeof(ENET_encoded::RADAR_STATUS_RECORD_T) + SOMEIP_HDR_SIZE;
   memcpy(&SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff[SOMEIP_HDR_SIZE], buffer_temp,
          sizeof(ENET_encoded::RADAR_STATUS_RECORD_T));
   prepare_rdr_status_HDR(SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff, frame_index + 1);
   ++frame_index;
   ++total_someip_buff_Len;
   memset(&SOMEIP_Tx_Buff_someip[frame_index + 1].SOMEIP_Buff[0], 0, SOMEIP_DATA_BUFFER_SIZE);
}

void add_encoded_VEHICLE_STATUS_RECORD_T(ENET_encoded::VEHICLE_STATUS_RECORD_T *e_ptr, unsigned char *buffer_temp,
                                         SOMEIP_Radar_Struct_T *someip_radar_data)
{
   memset(buffer_temp, 0, sizeof(buffer_temp));
   memcpy(buffer_temp, e_ptr, sizeof(ENET_encoded::VEHICLE_STATUS_RECORD_T));

   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Flag         = 1;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_PLPTimeStamp = ++time;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_VLAN_ID      = someip_radar_data->Vlan_id;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_src_MACaddr  = someip_radar_data->Src_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Dest_MACaddr = someip_radar_data->Dst_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Ether_type   = someip_radar_data->Eth_Type;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Data_Len     = sizeof(ENET_encoded::VEHICLE_STATUS_RECORD_T) + SOMEIP_HDR_SIZE;
   memcpy(&SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff[SOMEIP_HDR_SIZE], buffer_temp,
          sizeof(ENET_encoded::VEHICLE_STATUS_RECORD_T));
   ++frame_index;
   ++total_someip_buff_Len;
   memset(&SOMEIP_Tx_Buff_someip[frame_index + 1].SOMEIP_Buff[0], 0, SOMEIP_DATA_BUFFER_SIZE);
}

void prepare_rdr_sw_HDR(unsigned char *bufferdet, uint8_t chunk_num)
{
   // fill message headers as per ppt
   bufferdet[2]  = 0x00;
   bufferdet[3]  = 0x88; // Length - IPv4
   bufferdet[24] = 0x00;
   bufferdet[25] = 0x74; // Length - UDP

   bufferdet[32] = 0x00;
   bufferdet[33] = 0x00;
   bufferdet[34] = 0x00;
   bufferdet[35] = 0x64; // AUTOSAR PDU MULTIPLEXING Length

   bufferdet[42] = 0x02; // Msg Type
   bufferdet[43] = 0x00;
   bufferdet[44] = 0x00;
   bufferdet[45] = 0x00;
   bufferdet[46] = 0x00;
   bufferdet[47] = 0x00;

   bufferdet[20] = 0x86;
   bufferdet[21] = 0xC5; // Source port udp
   bufferdet[22] = 0x77;
   bufferdet[23] = 0x25; // Dest port UDP

   bufferdet[28] = 0x00;
   bufferdet[29] = 0x12;
   bufferdet[30] = 0x80;
   bufferdet[31] = 0x02; // AUTOSAR PDU MULTIPLEXING ID

   Populate_SomeIP_CommonBytes(bufferdet, &frame_index);

   uint16_t udpchecksum = 0;
   udpchecksum          = ComputeUDP_Checksum_SOMEIP(SOMEIP_Tx_Buff_someip[chunk_num - 1]);
   bufferdet[26]        = udpchecksum;
   bufferdet[27]        = udpchecksum >> 8;

   uint16_t ipv4checksum = ComputeIPV4_Checksum(bufferdet);
   bufferdet[10]         = ipv4checksum;
   bufferdet[11]         = ipv4checksum >> 8;
}

void add_encoded_RADAR_SW_INFO_RECORD_T(ENET_encoded::RADAR_SW_INFO_RECORD_T *e_ptr, unsigned char *buffer_temp,
                                        SOMEIP_Radar_Struct_T *someip_radar_data)
{
   memset(buffer_temp, 0, sizeof(buffer_temp));
   memcpy(buffer_temp, e_ptr, sizeof(ENET_encoded::RADAR_SW_INFO_RECORD_T));

   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Flag         = 1;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_PLPTimeStamp = ++time;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_VLAN_ID      = someip_radar_data->Vlan_id;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_src_MACaddr  = someip_radar_data->Src_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Dest_MACaddr = someip_radar_data->Dst_Mac;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Ether_type   = someip_radar_data->Eth_Type;
   SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Data_Len     = sizeof(ENET_encoded::RADAR_SW_INFO_RECORD_T) + SOMEIP_HDR_SIZE;
   memcpy(&SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff[SOMEIP_HDR_SIZE], buffer_temp,
          sizeof(ENET_encoded::RADAR_SW_INFO_RECORD_T));
   prepare_rdr_sw_HDR(SOMEIP_Tx_Buff_someip[frame_index].SOMEIP_Buff, frame_index + 1);
   ++frame_index;
   ++total_someip_buff_Len;
   memset(&SOMEIP_Tx_Buff_someip[frame_index + 1].SOMEIP_Buff[0], 0, SOMEIP_DATA_BUFFER_SIZE);
}

void fill_someip_data(unsigned long long *timestamp, SOMEIP_Radar_Struct_T *someip_radar_data)
{
   unsigned char *buffer_temp = new unsigned char[SOMEIP_DATA_BUFFER_SIZE];
   add_encoded_Detections(&encode_ptr.DETECTIONS_RECORD, someip_radar_data);
   add_encoded_RADAR_STATUS_RECORD_T(&encode_ptr.RADAR_STATUS_RECORD, buffer_temp, someip_radar_data);
   add_encoded_RADAR_SW_INFO_RECORD_T(&encode_ptr.RADAR_SW_INFO_RECORD, buffer_temp, someip_radar_data);
   // add_encoded_VEHICLE_STATUS_RECORD_T(&encode_ptr.VEHICLE_STATUS_RECORD,buffer_temp,someip_radar_data);

   Transmit_SOMEIP_Signals(SOMEIP_Tx_Buff_someip, &total_someip_buff_Len, timestamp);
   clear_someip_buffer();
   if (buffer_temp != NULL)
   {
      delete buffer_temp;
      buffer_temp = NULL;
   }
}

void clear_someip_buffer()
{
   memset(SOMEIP_Tx_Buff_someip, 0, sizeof(SOMEIP_ID_Struct_T));
   frame_index           = 0;
   total_someip_buff_Len = 0;
}
