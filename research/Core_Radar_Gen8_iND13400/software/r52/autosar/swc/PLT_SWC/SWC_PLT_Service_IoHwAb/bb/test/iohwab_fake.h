#ifndef IOHWAB_ADC_FAKE_H_
#define IOHWAB_ADC_FAKE_H_

#include "Adc.h"
#include "Rte_SWC_PLT_Service_IoHwAb.h"
#ifdef FFF_FUNCTION_WRAPPERS
   #undef FFF_FUNCTION_WRAPPERS
#endif
#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "SWC_PLT_Service_IoHwAb.h"
#ifdef Get_ADC_Counts
   #undef Get_ADC_Counts
#endif
   DECLARE_FAKE_VOID_FUNC(Adc_StopGroupConversion, Adc_GroupType);
   DECLARE_FAKE_VOID_FUNC(IoHwAb_ADC_PosPin_Prj_cbk, IoHwAb_Adc_PosPin_Hw_Ckt_T);
   DECLARE_FAKE_VOID_FUNC(PVT_Monitoring_Init);
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_ADC_Counts, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(bool, Check_RDI_Log_Connection);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);
#ifdef __cplusplus
}
#endif
/* Reset fake functions */
#define FFF_FAKES_ADC_PosPin_Prj_FUNCTION(FAKE) FAKE(IoHwAb_ADC_PosPin_Prj_cbk)
#define FFF_FAKES_ADCSTOP_FUNCTION(FAKE)        FAKE(Adc_StopGroupConversion)
#define FFF_FAKES_THERMAL_MONITOR_INIT(FAKE)    FAKE(PVT_Monitoring_Init)
#define FFF_FAKES_RDI_LOG_BOARD_FUNCTIONS(FAKE)                                                                                   \
   FAKE(Check_RDI_Log_Connection)                                                                                                 \
   FAKE(Get_RDI_Log_Board_Connected)
#endif
