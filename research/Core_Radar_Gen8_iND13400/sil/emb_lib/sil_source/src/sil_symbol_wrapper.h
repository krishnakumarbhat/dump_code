#ifndef SIL_SYMBOL_WRAPPER_H
#define SIL_SYMBOL_WRAPPER_H

#include "RR_ADAS_SYMBOL_Data.h"

bool populate_ipc_with_symbol_data(const UDPRecord_SIL *raw_stream);

extern "C" uint8_t RL_bsis_alert_level;
extern "C" uint8_t RL_BlindSpotDetectionState;
extern "C" uint8_t RL_BendOffPrbablityofMstImportatObj;
extern "C" uint8_t RL_BlindSpotWarnigRelevantObjDetect;

#endif // SIL_SYMBOL_WRAPPER_H
