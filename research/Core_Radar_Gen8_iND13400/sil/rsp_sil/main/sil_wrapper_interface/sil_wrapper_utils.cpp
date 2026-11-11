#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <tuple>

#include "fixmac.h"
#include "ipc_data.h"
#include "psp_sil_api.hpp"
#include "sil_wrapper_utils.hpp"
#include "smc_cal.h"
#include "usc_cal.h"

/**
 * @brief Reads calibration data from SMC and USC files.
 *
 * This function reads calibration data from two separate files: SMC and USC. It populates global structures with the read data.
 *
 * @param cal_base_path A pointer to a character array containing the base path for calibration files.
 *
 * @return bool Returns true if both files are successfully read, false otherwise.
 *
 * @note The function uses global structures SMC_Cal_Data and USC_Cal_Data to store the read calibration data.
 * @note The function skips the first 8 bytes of each file before reading the calibration data.
 * @note The function assumes the existence of SMC_Cal_T and USC_Cal_T structures.
 *
 * Local variables:
 * - g_smc_cal: Temporary structure to hold SMC calibration data.
 * - g_usc_cal: Temporary structure to hold USC calibration data.
 * - SMC_CAL_FNAME: Static constant char pointer for SMC bin file.
 * - USC_CAL_FNAME: Static constant char pointer for USC bin file.
 * - ptr_smc: File pointer for SMC calibration file.
 * - ptr_usc: File pointer for USC calibration file.
 * - smc_path: Character array to store the full path of the SMC.
 * - usc_path: Character array to store the full path of the USC.
 *
 * @warning The function does not perform any error checking on the size or format of the read data.
 * @warning The function uses fixed-size buffers for file paths, which may lead to buffer overflow if paths are too long.
 *
 */
bool readcals(char *cal_base_path)
{
   int ret = false;

   SMC_Cal_T g_smc_cal    = {0};
   USC_Cal_T g_usc_cal    = {0};
   SMC_Cal_T SMC_Cal_Data = {0};
   USC_Cal_T USC_Cal_Data = {0};

   static const char *SMC_CAL_FNAME = "";
   static const char *USC_CAL_FNAME = "";

   FILE *ptr_smc, *ptr_usc;
   char smc_path[256] = {0};
   char usc_path[256] = {0};

   memset(&g_smc_cal, 0, sizeof(g_smc_cal));
   memset(&g_usc_cal, 0, sizeof(g_usc_cal));
   sprintf(smc_path, "%s/%s", cal_base_path, SMC_CAL_FNAME);

   ptr_smc = fopen(smc_path, "rb");

   if (!ptr_smc)
   {
      printf("SMC File read failed.\n");
      return ret;
   }
   fseek(ptr_smc, 8, SEEK_SET); /*number of 8 bytes to offset from start position */
   fread(&g_smc_cal, sizeof(g_smc_cal), 1, ptr_smc);
   memcpy(&SMC_Cal_Data, &g_smc_cal, sizeof(SMC_Cal_T));

   fclose(ptr_smc);

   ptr_usc = fopen(usc_path, "rb");

   if (!ptr_usc)
   {
      printf("USC File read failed.\n");
      return ret;
   }
   fseek(ptr_usc, 8, SEEK_SET); /*number of 8 bytes to offset from start position */
   fread(&g_usc_cal, sizeof(g_usc_cal), 1, ptr_usc);
   memcpy(&USC_Cal_Data, &g_usc_cal, sizeof(USC_Cal_T));

   fclose(ptr_usc);

   return true;
}

/**
 * @brief Reads RDD data from a binary file.
 *
 * This function reads RDD data from a binary file named "rdd_input.bin"
 * It reads the look_index and other RDD parameters like NF_EST, CFAR_Thr and MPRB.
 * and populates the provided RDD_Data_T structure with the read data.
 *
 * @param base_path A pointer to a character array containing the base path where the RDD binary file is located.
 * @param input_buff_ptr A pointer to an RDD_Data_T structure where the read data will be stored.
 *
 * @return bool Returns true if the file is successfully read and the data is valid, false otherwise.
 * @note The function checks if the file size is a multiple of the RDD_Data_T structure size.
 *
 * Local variables:
 * - ret: Boolean flag to store the return value, initialized to false.
 * - size: Long integer to store the file size.
 * - RDD_BIN_FILE_FNAME: Static constant char pointer for the RDD binary file name.
 * - ptr_rdd_bin: File pointer for the RDD binary file.
 * - file_path: Character array to store the full path of the RDD binary file.
 */
bool Read_Rdd_Data_Bin(const char *base_path, RDD_Data_T *input_buff_ptr)
{
   int ret = false;
   long size;
   static const char *RDD_BIN_FILE_FNAME = "rdd_input.bin";

   FILE *ptr_rdd_bin;
   char file_path[256] = {0};

   sprintf(file_path, "%s/%s", base_path, RDD_BIN_FILE_FNAME);

   ptr_rdd_bin = fopen(file_path, "rb");

   if (!ptr_rdd_bin)
   {
      return ret;
   }

   fseek(ptr_rdd_bin, 0, SEEK_END);
   size = ftell(ptr_rdd_bin);
   fseek(ptr_rdd_bin, 0, SEEK_SET);

   if (size % sizeof(RDD_Data_T) != 0U)
   {
      return ret;
   }

   fread(input_buff_ptr, sizeof(RDD_Data_T), 1, ptr_rdd_bin);
   fclose(ptr_rdd_bin);

   return true;
}

/**
 * @brief Reads stream header data from a binary file.
 *
 * This function reads stream header data from a binary file named "stream_hdr.bin"
 * It populates the provided Stream_Hdr_T structure with the read data.
 *
 * @param base_path A pointer to a character array containing the base path where the stream header binary file is located.
 * @param input_buff_ptr A pointer to a Stream_Hdr_T structure where the read data will be stored.
 *
 * @return bool Returns true if the file is successfully read and the data is valid, false otherwise.
 *
 * @note The function checks if the file size is a multiple of the Stream_Hdr_T structure size.
 *
 * Local variables:
 * - ret: Boolean flag to store the return value, initialized to false.
 * - size: Long integer to store the file size.
 * - STREAM_HEADER_BIN_FILE_FNAME: Static constant char pointer for the stream header binary file name.
 * - ptr_stream_header_bin: File pointer for the stream header binary file.
 * - file_path: Character array to store the full path of the stream header binary file.
 */
bool Stream_Header_Data_Bin(const char *base_path, Stream_Hdr_T *input_buff_ptr)
{
   int ret = false;
   long size;
   static const char *STREAM_HEADER_BIN_FILE_FNAME = "stream_hdr.bin";

   FILE *ptr_stream_header_bin;
   char file_path[256] = {0};

   sprintf(file_path, "%s/%s", base_path, STREAM_HEADER_BIN_FILE_FNAME);

   ptr_stream_header_bin = fopen(file_path, "rb");

   if (!ptr_stream_header_bin)
   {
      return ret;
   }

   fseek(ptr_stream_header_bin, 0, SEEK_END);
   size = ftell(ptr_stream_header_bin);
   fseek(ptr_stream_header_bin, 0, SEEK_SET);

   if (size % sizeof(Stream_Hdr_T) != 0U)
   {
      return ret;
   }

   fread(input_buff_ptr, sizeof(Stream_Hdr_T), 1, ptr_stream_header_bin);
   fclose(ptr_stream_header_bin);

   return true;
}

/**
 * @brief Reads Look data from a binary file.
 *
 * This function reads Look data from a binary file named "look_data_input.bin"
 * It populates the provided Look_Data_T structure with the read data.
 *
 * @param base_path A pointer to a character array containing the base path where the Look data binary file is located.
 * @param input_buff_ptr A pointer to a Look_Data_T structure where the read data will be stored.
 *
 * @return bool Returns true if the file is successfully read and the data is valid, false otherwise.
 *
 * Local variables:
 * - ret: Boolean flag to store the return value, initialized to false.
 * - size: Long integer to store the file size.
 * - LOOK_DATA_BIN_FILE_FNAME: Static constant char pointer for the Look data binary file name.
 * - ptr_look_data_bin: File pointer for the Look data binary file.
 * - file_path: Character array to store the full path of the Look data binary file.
 */
bool Read_Look_Data_Bin(const char *base_path, Look_Data_T *input_buff_ptr)
{
   int ret = false;
   long size;
   static const char *LOOK_DATA_BIN_FILE_FNAME = "look_data_input.bin";

   FILE *ptr_look_data_bin;
   char file_path[256] = {0};

   sprintf(file_path, "%s/%s", base_path, LOOK_DATA_BIN_FILE_FNAME);

   ptr_look_data_bin = fopen(file_path, "rb");

   if (!ptr_look_data_bin)
   {
      return ret;
   }

   fseek(ptr_look_data_bin, 0, SEEK_END);
   size = ftell(ptr_look_data_bin);
   fseek(ptr_look_data_bin, 0, SEEK_SET);

   if (size % sizeof(Look_Data_T) != 0U)
   {
      return ret;
   }

   fread(input_buff_ptr, sizeof(Look_Data_T), 1, ptr_look_data_bin);
   fclose(ptr_look_data_bin);

   return true;
}

/**
 * @brief Reads VSE stream data from a binary file.
 *
 * This function reads VSE stream data from a binary file
 * It populates  * the provided Vse_Stream_T structure with the read data.
 *
 * @param base_path A pointer to a character array containing the base path where the VSE stream binary file is located.
 * @param input_buff_ptr A pointer to a Vse_Stream_T structure where the read data will be stored.
 *
 * @return bool Returns true if the file is successfully read and the data is valid, false otherwise.
 *
 * Local variables:
 * - ret: Boolean flag to store the return value, initialized to false.
 * - size: Long integer to store the file size.
 * - VSE_STREAM_BIN_FILE_FNAME: Static constant char pointer for the VSE stream binary file name.
 * - ptr_vse_stream_bin: File pointer for the VSE stream binary file.
 * - file_path: Character array to store the full path of the VSE stream binary file.
 *
 */
bool Read_Vse_Stream_Data_Bin(const char *base_path, Vse_Stream_T *input_buff_ptr)
{
   int ret = false;
   long size;
   static const char *VSE_STREAM_BIN_FILE_FNAME = "vse_stream_input.bin";
   FILE *ptr_vse_stream_bin;
   char file_path[256] = {0};
   sprintf(file_path, "%s/%s", base_path, VSE_STREAM_BIN_FILE_FNAME);
   ptr_vse_stream_bin = fopen(file_path, "rb");
   if (!ptr_vse_stream_bin)
   {
      return ret;
   }
   fseek(ptr_vse_stream_bin, 0, SEEK_END);
   size = ftell(ptr_vse_stream_bin);
   fseek(ptr_vse_stream_bin, 0, SEEK_SET);
   if ((size % sizeof(input_buff_ptr->veh_raw_data[0]) != 0U))
   {
      return ret;
   }
   fread(&(input_buff_ptr->veh_raw_data[0]), sizeof(input_buff_ptr->veh_raw_data[0]), 1, ptr_vse_stream_bin);
   input_buff_ptr->latest_raw_index = 0U;
   fclose(ptr_vse_stream_bin);

   return true;
}

/**
 * @brief Reads RDD stream data from a binary file.
 *
 * This function reads RDD stream data from a binary file named "rdd_stream_input.bin"
 * located in the specified base path. It populates the provided Rdd_Stream_T structure
 * with the read data.
 *
 * @param base_path A pointer to a character array containing the base path where the RDD stream binary file is located.
 * @param input_buff_ptr A pointer to an Rdd_Stream_T structure where the read data will be stored.
 *
 * @return bool Returns true if the file is successfully read and the data is valid, false otherwise.
 *
 * @note The function checks if the file size is a multiple of the Rdd_Stream_T structure size.
 *
 * Local variables:
 * - ret: Boolean flag to store the return value, initialized to false.
 * - size: Long integer to store the file size.
 * - RDD_STREAM_BIN_FILE_FNAME: Static constant char pointer for the RDD stream binary file name.
 * - ptr_rdd_stream_bin: File pointer for the RDD stream binary file.
 * - file_path: Character array to store the full path of the RDD stream binary file.
 */
bool Read_Rdd_Stream_Data_Bin(const char *base_path, Rdd_Stream_T *input_buff_ptr)
{
   int ret = false;
   long size;
   static const char *RDD_STREAM_BIN_FILE_FNAME = "rdd_stream_input.bin";

   FILE *ptr_rdd_stream_bin;
   char file_path[256] = {0};

   sprintf(file_path, "%s/%s", base_path, RDD_STREAM_BIN_FILE_FNAME);

   ptr_rdd_stream_bin = fopen(file_path, "rb");

   if (!ptr_rdd_stream_bin)
   {
      return ret;
   }

   fseek(ptr_rdd_stream_bin, 0, SEEK_END);
   size = ftell(ptr_rdd_stream_bin);
   fseek(ptr_rdd_stream_bin, 0, SEEK_SET);

   if ((size % sizeof(Rdd_Stream_T) != 0U))
   {
      return ret;
   }

   fread(input_buff_ptr, sizeof(Rdd_Stream_T), 1, ptr_rdd_stream_bin);
   fclose(ptr_rdd_stream_bin);

   return true;
}

/*Read_Psp_Input_bin function would read the required stream in logs and uses it
   to initialize IPC Buffers*/

bool Read_Psp_Input_bin(const char *base_path, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data)
{
   int ret                              = false;
   static const char *PSP_BIN_FILE_NAME = "psp_input.bin";

   FILE *ptr_psp_bin;
   char file_path[256] = {0};

   sprintf(file_path, "%s/%s", base_path, PSP_BIN_FILE_NAME);

   ptr_psp_bin = fopen(file_path, "rb");

   if (!ptr_psp_bin)
   {
      return ret;
   }
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.yaw), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.pitch), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.plate_angle_deg_scs), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.plate_distance), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.polarity), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.horz_angle_min), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.horz_angle_max), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.vert_angle_min), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.vert_angle_max), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.plate_lat_position), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.mount_loc), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.align_cmd), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.static_alignment_data.f_data_valid), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_vacs_boresight_az_estimated), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_vacs_boresight_el_estimated), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_vacs_boresight_rl_estimated), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_speed_compensation_factor), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.max_abs_misalignment_az), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.max_abs_misalignment_el_sky), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.max_abs_misalignment_el_ground), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_num_updates_az), sizeof(uint32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_num_updates_el), sizeof(uint32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_num_updates_rl), sizeof(uint32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_align_quality_factor_az), sizeof(uint8_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.initial_align_quality_factor_el), sizeof(uint8_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.align_cmd), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.short_track_target_height), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.short_track_target_range_rate), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.az_scf_kf_covariance[0]), sizeof(float32_t) * 4, 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.el_roll_kf_covariance[0]), sizeof(float32_t) * 4, 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.short_track_exit_condition), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_x_posn), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_y_posn), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_z_posn), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_yaw), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_pitch), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.iso_sensor_roll), sizeof(float32_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.distance_rear_axle_to_front_bumper), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.mount_loc), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.coordinate_system_input), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.f_data_valid), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_m2d_data->payload.alignment_Info.dynamic_alignment_data.operation_mode_status), sizeof(uint8_t), 1, ptr_psp_bin);
   fread(&(p_d2m_data->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_d2m_data->payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal), sizeof(float32_t), 1,
         ptr_psp_bin);
   fread(&(p_d2m_data->payload.dynamic_alignment_log_stream.dra_core_data.n_updates_azimuth), sizeof(uint32_t), 1, ptr_psp_bin);
   fclose(ptr_psp_bin);
   return true;
}
