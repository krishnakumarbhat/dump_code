#ifndef INTERFERENCE_DETECTION_ALGO_FAKE_H_
#define INTERFERENCE_DETECTION_ALGO_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "interference_detection.h"
#include "interference_detection_pvt.h"
#include "ipc_data.h"

   DECLARE_FAKE_VALUE_FUNC(ID_BB_Input_Params_T *, Get_ID_Init_Parameters);
   DECLARE_FAKE_VALUE_FUNC(ID_MDF_BB_Internals_T *, Get_ID_BB_Internals);
   DECLARE_FAKE_VOID_FUNC(Interference_Detection);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */

#define FFF_FAKES_INTERFERENCE_DETECTION_ALGO(FAKE)                                                                               \
   FAKE(Get_ID_Init_Parameters)                                                                                                   \
   FAKE(Get_ID_BB_Internals)                                                                                                      \
   FAKE(Interference_Detection)
#endif /* INTERFERENCE_DETECTION_ALGO_FAKE_H_ */
