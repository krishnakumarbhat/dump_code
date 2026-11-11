#include <algorithm>
#include <cstddef>
#include <iostream>

#include "emblib_ipc_data.h"
#include "sil_radar_fusion_delay.h"
#include "sil_symbol_wrapper_internal.h"
#include "sil_wrapper_common.h"

#ifdef TRACKER_ENABLED
namespace sil_symbol_wrapper_internal
{
namespace
{
Detection_Data_Input_T *Get_Opp_Radar_Detections_Pointer(SIL_RADAR_Input_Symbol_T *input_symbol_pointer)
{
   if (input_symbol_pointer == nullptr)
   {
      return nullptr;
   }

   Radar_Position radar_position                 = Get_Radar_Position();
   Detection_Data_Input_T *opp_detection_pointer = nullptr;

   switch (radar_position)
   {
      case REAR_LEFT:
         opp_detection_pointer = &input_symbol_pointer->detection_fl_radar;
         break;
      default:
         /* Non-RL positions (e.g. FL, FC) don't consume partner detections here */
         break;
   }
   return opp_detection_pointer;
}

void populate_partner_sensor_data_with_symbol_data(Detection_Data_Input_T *opp_dets_ptr)
{
   M2D_Msg_T *p_ipc_m2d                             = Get_IPC_M2D_Buffer();
   Partner_Sensor_Stream_T *partner_sensor_data_ptr = &p_ipc_m2d->payload.partners_data;

   partner_sensor_data_ptr->partner_det_list_property_data[0].ts_mid_dwell_nanosec =
      (opp_dets_ptr->dets_info.timestamp / 1000) * 1e6;
   partner_sensor_data_ptr->partner_det_list_property_data[0].ts_mid_dwell_sec = (opp_dets_ptr->dets_info.timestamp / 1000);
   partner_sensor_data_ptr->partner_det_list_property_data[0].look_index       = opp_dets_ptr->dets_info.ScanIndex;
   partner_sensor_data_ptr->partner_det_list_property_data[0].look_type        = opp_dets_ptr->dets_info.LookType;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].vacs_boresight_az_estimated =
      opp_dets_ptr->dets_info.AutoAlignAzimuth;

   partner_sensor_data_ptr->partner_sensor_alignment_info[0].vacs_boresight_el_estimated =
      opp_dets_ptr->dets_info.AutoAlignElevation;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].alignment_mode = opp_dets_ptr->dets_info.alignment_mode;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].alignment_error_status_combined = 0;
   partner_sensor_data_ptr->partner_sensor_diag_data[0].det_recvd_flag                       = 1;
   partner_sensor_data_ptr->partner_sensor_diag_data[0].status_recvd_flag                    = 1;
   partner_sensor_data_ptr->partner_sensor_blockage_info[0].blockage_value =
      opp_dets_ptr->dets_info.blockage_value; // Replace with actual blockage value if available
   partner_sensor_data_ptr->partner_sensor_blockage_info[0].blockage_status =
      opp_dets_ptr->dets_info.blockage_status; // Replace with actual blockage status if available

   partner_sensor_data_ptr->partner_sensor_det_data.num_af_det = opp_dets_ptr->dets_info.Count;

   const uint32_t max_partner_det_index =
      std::min((uint32_t)partner_sensor_data_ptr->partner_sensor_det_data.num_af_det, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR);
   for (uint32_t index = 0; index < max_partner_det_index; index++)
   {
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].theta   = opp_dets_ptr->dets_input[index].azimuth_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].phi     = opp_dets_ptr->dets_input[index].elevation_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].ran     = opp_dets_ptr->dets_input[index].range;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].vel     = opp_dets_ptr->dets_input[index].range_rate_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].snr     = opp_dets_ptr->dets_input[index].detection_snr;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].rcs     = opp_dets_ptr->dets_input[index].amplitude;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].az_conf = opp_dets_ptr->dets_input[index].azimuth_confidence;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].el_conf =
         opp_dets_ptr->dets_input[index].elevation_confidence;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_superres_target =
         opp_dets_ptr->dets_input[index].super_res_target;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_bistatic = opp_dets_ptr->dets_input[index].bistatic;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_ci_det   = false;
   }
}

void Get_Opp_Radar_Mounting_Pointer(const MOUNTING_VALUES_XML_T *fl_mounting_values_ptr)
{
   Radar_Position radar_position                    = Get_Radar_Position();
   M2D_Msg_T *p_ipc_m2d                             = Get_IPC_M2D_Buffer();
   Partner_Sensor_Stream_T *partner_sensor_data_ptr = &p_ipc_m2d->payload.partners_data;

   switch (radar_position)
   {
      case REAR_LEFT:
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll =
            fl_mounting_values_ptr->azimuth_polarity == 1.0F ? 0.0F : 180.0F * DEG2RAD_SIL;
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch = 0.0F;
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw =
            fl_mounting_values_ptr->boresight_angle * DEG2RAD_SIL;
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_z = fl_mounting_values_ptr->vcs_z_position;
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_y =
            fl_mounting_values_ptr->vcs_lat_position;
         partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_x =
            fl_mounting_values_ptr->vcs_lon_position;
         break;
      default:
         break;
   }
}
} // namespace

void Populate_Partner_Sensor_Data_With_Fusion_Delay(SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr)
{
   if (Get_Radar_Position() == REAR_LEFT)
   {
      Detection_Data_Input_T *opp_dets_ptr = Get_Opp_Radar_Detections_Pointer(sil_radar_input_symbol_ptr);

      /* Fusion latency: RL consumes the FL symbol snapshot from FL_FUSION_DELAY_CYCLES cycles earlier */
      constexpr std::size_t FL_FUSION_DELAY_CYCLES = 1U;
      static Delay_Line_T<Detection_Data_Input_T, FL_FUSION_DELAY_CYCLES> fl_dets_delay;
      static Delay_Line_T<MOUNTING_VALUES_XML_T, FL_FUSION_DELAY_CYCLES> fl_mounting_delay;

      const Detection_Data_Input_T live_dets = (opp_dets_ptr != nullptr) ? *opp_dets_ptr : Detection_Data_Input_T{};

      Detection_Data_Input_T &delayed_dets    = fl_dets_delay.Push_And_Pop(live_dets);
      MOUNTING_VALUES_XML_T &delayed_mounting = fl_mounting_delay.Push_And_Pop(sil_radar_input_symbol_ptr->Mounting_Values_FL);

      populate_partner_sensor_data_with_symbol_data(&delayed_dets);
      Get_Opp_Radar_Mounting_Pointer(&delayed_mounting);
   }
}
} // namespace sil_symbol_wrapper_internal
#endif
