#ifndef SIL_WRAPPER_UTILS_H
#define SIL_WRAPPER_UTILS_H

#include "ipc_data.h"
#include "rdd_stream.h"
#include "stdint.h"
#include "stream_header.h"
#include "vse_stream.h"

/*===========================================================================*
 * Function declarations
 *===========================================================================*/
bool readcals(char *cal_base_path);
bool Read_Rdd_Data_Bin(const char *base_path, RDD_Data_T *input_buff_ptr);
bool Stream_Header_Data_Bin(const char *base_path, Stream_Hdr_T *input_buff_ptr);
bool Read_Look_Data_Bin(const char *base_path, Look_Data_T *input_buff_ptr);
bool Read_Vse_Stream_Data_Bin(const char *base_path, Vse_Stream_T *input_buff_ptr);
bool Read_Rdd_Stream_Data_Bin(const char *base_path, Rdd_Stream_T *input_buff_ptr);
bool Read_Psp_Input_bin(const char *base_path, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data);
#endif
