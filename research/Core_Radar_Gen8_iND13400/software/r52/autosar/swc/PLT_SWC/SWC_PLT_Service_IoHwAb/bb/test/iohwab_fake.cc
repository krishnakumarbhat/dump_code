#include "iohwab_fake.h"

#ifdef Get_ADC_Counts
   #undef Get_ADC_Counts
#endif
DEFINE_FAKE_VOID_FUNC(IoHwAb_ADC_PosPin_Prj_cbk, IoHwAb_Adc_PosPin_Hw_Ckt_T);
DEFINE_FAKE_VOID_FUNC(Adc_StopGroupConversion, Adc_GroupType);
DEFINE_FAKE_VOID_FUNC(PVT_Monitoring_Init);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_ADC_Counts, uint8_t);
