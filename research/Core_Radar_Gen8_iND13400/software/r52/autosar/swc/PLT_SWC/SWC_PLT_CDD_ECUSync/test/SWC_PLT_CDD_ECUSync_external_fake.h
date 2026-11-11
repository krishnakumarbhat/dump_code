#ifndef SWC_PLT_CDD_ECUSYNC_FAKE_H
#define SWC_PLT_CDD_ECUSYNC_FAKE_H

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/Include/SWC_PLT_CDD_ECUSync_external.h"
#include <stdint.h>

   DECLARE_FAKE_VOID_FUNC(Tsync_calculateTimeDiff);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, CaptureGlobalTimestamp, GLOB_TS_MEAS_PTS, GLOB_TS_STRUCT_TYPE *);
#ifdef __cplusplus
}
#endif

/* Reset fake functions */
#define FFF_FAKES_SWC_PLT_CDD_ECUSYNC(FAKE)                                                                                       \
   FAKE(Tsync_calculateTimeDiff)                                                                                                  \
   FAKE(CaptureGlobalTimestamp)

#endif /* SWC_PLT_CDD_ECUSYNC_FAKE_H */
