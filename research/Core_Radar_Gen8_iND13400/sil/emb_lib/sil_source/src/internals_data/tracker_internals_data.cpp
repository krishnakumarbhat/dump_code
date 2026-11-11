#include "tracker_internals_data.h"

static ROT_Internals_Stream_T ROT_Internals_Obj;

ROT_Internals_Stream_T *Get_ROT_Internals_Data_Ptr()
{
   return &ROT_Internals_Obj;
}
