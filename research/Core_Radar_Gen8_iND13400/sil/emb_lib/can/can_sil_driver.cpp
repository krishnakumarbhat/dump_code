/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "can_sil_driver.h"
#include "plp_iface.h"
#include "sil_version.h"
#include "sil_wrapper_common.h"
#include <string.h>

static uint32_t tx_fd_channel[MAX_CAN_MESSAGES];
static Can_FD_ID_Struct_T Can_FD_Id_Enable[MAX_CAN_MESSAGES];
static uint16_t total_can_fd_msg_cnt = 0;
static bool Can_FD_Flag;

void Fill_CAN_buffer(uint32_t Handle, uint32_t CanID, uint8_t DLC, const uint8_t *Data)
{
   Can_FD_Id_Enable[total_can_fd_msg_cnt].Can_Id = CanID;
   memcpy((uint8_t *)&Can_FD_Id_Enable[total_can_fd_msg_cnt].Can_Data[0], (uint8_t *)Data, DLC);
   Can_FD_Id_Enable[total_can_fd_msg_cnt].Can_FD_Flag = 1;
   Can_FD_Id_Enable[total_can_fd_msg_cnt].Can_FD_DLC  = DLC;
   Can_FD_Id_Enable[total_can_fd_msg_cnt].channelID   = Handle;
   tx_fd_channel[total_can_fd_msg_cnt]                = Handle;
   total_can_fd_msg_cnt++;

   if (MAX_CAN_MESSAGES == total_can_fd_msg_cnt)
   {
      total_can_fd_msg_cnt = 0;
   }
}

void Transmit_CAN_Signals(unsigned long long timestamp)
{
   SIL_RADAR_Output_Data_T *Output_Ptr = Get_Sil_Radar_Output_Data_Ptr();
   Emb_Lib_Output_Control_T control    = get_output_control();

   for (int i = 0; i < total_can_fd_msg_cnt /*i < Output_Ptr->dvl_payload_out.msg_count*/ && i < MAX_CAN_MESSAGES; i++)
   {
      if (Can_FD_Id_Enable[i].Can_FD_Flag == 1)
      {
         if (control.plp_algorithms == RADAR_PLP_SYNC_ENABLE)
         {
            PLP_ProcessOutput(&Can_FD_Id_Enable[i]);
         }
         else
         {
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.id               = Can_FD_Id_Enable[i].Can_Id;
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.channel          = tx_fd_channel[i];
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.length           = Can_FD_Id_Enable[i].Can_FD_DLC;
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.info.timestamp   = timestamp;
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.info.messageSize = Can_FD_Id_Enable[i].Can_FD_DLC;
            Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.info.messageType = DVL_MESSAGE_TYPE_CAN_FD;
            memcpy(Output_Ptr->dvl_payload_out.dvl[i].dvlCANFD.data, Can_FD_Id_Enable[i].Can_Data,
                   sizeof(Can_FD_Id_Enable[i].Can_Data));
            timestamp += 100;
         }
      }
   }

   memset(Can_FD_Id_Enable, 0, sizeof(Can_FD_Id_Enable));
   // TODO: Check the total msg count depends on the input filled struct
   if (control.plp_algorithms != RADAR_PLP_SYNC_ENABLE)
      Output_Ptr->dvl_payload_out.msg_count = total_can_fd_msg_cnt;
   total_can_fd_msg_cnt = 0;
}

void Transmit_CAN_over_UDP()
{
   CAN_OVER_UDP CAN_UDP;
   SIL_RADAR_Output_Data_T *Output_UDP_Ptr  = Get_Sil_Radar_Output_Data_Ptr();
   const Status_Stream_T *status_stream_ptr = Get_Status_Log_Data_Ptr();

   // Build CAN-over-UDP from synchronized shared output payload.
   const unsigned int total_msg_count = Output_UDP_Ptr->dvl_payload_out.msg_count;
   unsigned int total_can_fd_msgs     = 0;

   for (unsigned int i = 0; i < total_msg_count && i < MAX_CAN_MESSAGES; i++)
   {
      if (Output_UDP_Ptr->dvl_payload_out.dvl[i].info.messageType == DVL_MESSAGE_TYPE_CAN_FD)
      {
         total_can_fd_msgs++;
      }
   }

   memset(Output_UDP_Ptr->Can_UDP_Tx_Buff, 0, sizeof(Output_UDP_Ptr->Can_UDP_Tx_Buff));
   memset(&CAN_UDP.can_rawframe, 0, sizeof(CAN_UDP.can_rawframe));

   int number_of_udp_frames = (int)(total_can_fd_msgs / CAN_Signals_per_UDP_frame);
   if ((total_can_fd_msgs % CAN_Signals_per_UDP_frame) != 0)
   {
      number_of_udp_frames++;
   }

   if (number_of_udp_frames > (int)(sizeof(Output_UDP_Ptr->Can_UDP_Tx_Buff) / sizeof(Output_UDP_Ptr->Can_UDP_Tx_Buff[0])))
   {
      number_of_udp_frames = (int)(sizeof(Output_UDP_Ptr->Can_UDP_Tx_Buff) / sizeof(Output_UDP_Ptr->Can_UDP_Tx_Buff[0]));
   }

   int current_frame         = 0;
   unsigned int source_index = 0;

   for (int i = 0; i < number_of_udp_frames; i++)
   {
      memset(&CAN_UDP.can_rawframe, 0, sizeof(CAN_UDP.can_rawframe));

      CAN_UDP.can_frame_data.header.Identification                        = CANOVERUDP_IDENTIFICATION_WORD;
      CAN_UDP.can_frame_data.header.CANOVERUDP_Implentation_version_Major = (uint8_t)CAN_OVER_UDP_VERSION_MAJOR;
      CAN_UDP.can_frame_data.header.CANOVERUDP_Implentation_version_Minor = (uint8_t)CAN_OVER_UDP_VERSION_MINOR;
      CAN_UDP.can_frame_data.header.SW_APPlication_Version_Major          = SIL_MAJOR_VERSION;
      CAN_UDP.can_frame_data.header.SW_APPlication_Version_Minor          = SIL_MINOR_VERSION;
      CAN_UDP.can_frame_data.header.SW_APPlication_Version_Patch          = SIL_PATCH_VERSION;
      CAN_UDP.can_frame_data.header.CAN_DBC_Version_Major                 = (uint8_t)DET_DBC_BASE_VERSION_MAJOR;
      CAN_UDP.can_frame_data.header.CAN_DBC_Version_Minor                 = (uint8_t)DET_DBC_BASE_VERSION_MINOR;
      memset(CAN_UDP.can_frame_data.header.reserved1, 0, sizeof(CAN_UDP.can_frame_data.header.reserved1));
      CAN_UDP.can_frame_data.header.Scan_Index                = (uint16_t)Get_Current_Scan_Index();
      CAN_UDP.can_frame_data.header.Total_CANOVERUDP_Frames   = (uint8_t)number_of_udp_frames;
      CAN_UDP.can_frame_data.header.Current_CANOVERUDP_Frames = (uint8_t)current_frame;
      CAN_UDP.can_frame_data.header.Frame_Data_Size           = 0;
      CAN_UDP.can_frame_data.header.Radar_posn                = (uint8_t)Get_Radar_Position();
      CAN_UDP.can_frame_data.header.Customer = (status_stream_ptr != NULL) ? status_stream_ptr->customer_info.customer_id : 0U;
      memset(CAN_UDP.can_frame_data.header.reserved2, 0, sizeof(CAN_UDP.can_frame_data.header.reserved2));

      unsigned int frame_msg_count = 0;

      for (int j = 0; j < CAN_Signals_per_UDP_frame; j++)
      {
         while (source_index < total_msg_count && source_index < MAX_CAN_MESSAGES &&
                Output_UDP_Ptr->dvl_payload_out.dvl[source_index].info.messageType != DVL_MESSAGE_TYPE_CAN_FD)
         {
            source_index++;
         }

         if (source_index < total_msg_count && source_index < MAX_CAN_MESSAGES)
         {
            const dvlCanMessageFD *src_msg                    = &Output_UDP_Ptr->dvl_payload_out.dvl[source_index].dvlCANFD;
            CAN_UDP.can_frame_data.data[j].Cycle_Timestamp_us = src_msg->info.timestamp;
            CAN_UDP.can_frame_data.data[j].Can_Id             = src_msg->id;
            memcpy(CAN_UDP.can_frame_data.data[j].Can_Data, src_msg->data, sizeof(CAN_UDP.can_frame_data.data[j].Can_Data));
            frame_msg_count++;
            source_index++;
         }
         else
         {
            // Clear the remaining data if there are no more CAN messages
            memset(&CAN_UDP.can_frame_data.data[j], 0, sizeof(CAN_UDP.can_frame_data.data[j]));
         }
      }

      CAN_UDP.can_frame_data.header.Frame_Data_Size = (uint16_t)(frame_msg_count * sizeof(CAN_FD_ID_UDP_T));

      // send udp frame
      memcpy(Output_UDP_Ptr->Can_UDP_Tx_Buff[current_frame].Buf_Bytes, &CAN_UDP.can_rawframe, sizeof(CAN_UDP.can_rawframe));
      current_frame++;
   }
   Output_UDP_Ptr->f_CAN_UDP_buff_valid = true;
   Output_UDP_Ptr->Buff_CAN_UDP_Len     = current_frame;
}
