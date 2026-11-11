#include "SWC_PLT_CDD_ECUSync_external_fake.h"

DEFINE_FAKE_VOID_FUNC(Tsync_calculateTimeDiff);
DEFINE_FAKE_VALUE_FUNC(uint8_t, CaptureGlobalTimestamp, GLOB_TS_MEAS_PTS, GLOB_TS_STRUCT_TYPE *);

//    GLOB_TS_STRUCT_TYPE *GetGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
//    GLOB_TS_STRUCT_TYPE *PeekGlobalTimestamp(GLOB_TS_MEAS_PTS meas_point);
//    uint8_t GetTimeStampDiff_Ns(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, uint32_t *result);
//    uint8_t GetMidTimeStamps(GLOB_TS_STRUCT_TYPE *param1, GLOB_TS_STRUCT_TYPE *param2, GLOB_TS_STRUCT_TYPE *result, uint32_t
//    *diff);
