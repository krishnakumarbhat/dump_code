#include "afbb_cfg.h" /* provides AF_DOWNSELECTION_ENABLE_L */
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"

void Write_AF_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff, Down_selection_Stream_T *ds_buff);
void Write_AF_Det_CSV_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff);
void Print_AF_Det_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff);
void Write_AF_DS_Det_CSV_Outputs(Down_selection_Stream_T *out_buff);
void Print_AF_DS_Det_Outputs(Down_selection_Stream_T *out_buff);
