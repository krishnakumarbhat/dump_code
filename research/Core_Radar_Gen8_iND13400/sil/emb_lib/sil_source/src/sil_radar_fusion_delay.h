#ifndef SIL_RADAR_FUSION_DELAY_H
#define SIL_RADAR_FUSION_DELAY_H

#include "sil_input_symbol.h"

namespace sil_symbol_wrapper_internal
{
#ifdef TRACKER_ENABLED
/* Fills the IPC partner-sensor detection/mounting streams from the opposite radar's symbol data,
   applying the REAR_LEFT<-FRONT_LEFT fusion cycle delay where applicable */
void Populate_Partner_Sensor_Data_With_Fusion_Delay(SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr);
#endif
} // namespace sil_symbol_wrapper_internal

#endif // SIL_RADAR_FUSION_DELAY_H
