#ifndef RTE_SWC_PLT_CDD_RADAR_CONTROL_FAKE_H
#define RTE_SWC_PLT_CDD_RADAR_CONTROL_FAKE_H

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

   typedef uint8_t Std_ReturnType;

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation, uint8_t);
   DECLARE_FAKE_VOID_FUNC(Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream);
   DECLARE_FAKE_VALUE_FUNC(
      Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx);

#ifdef __cplusplus
}
#endif
/* Reset fake functions */
#define FFF_FAKES_RTE_SWC_PLT_CDD_RADAR_CONTROL(FAKE)                                                                             \
   FAKE(Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation)                                                                     \
   FAKE(Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger)                                                       \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream)                                           \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream)                                           \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream)                               \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream)                 \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream)                                     \
   FAKE(Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx)

#endif /* RTE_SWC_PLT_CDD_RADAR_CONTROL_FAKE_H */
