#ifndef PLT_Srv_IoHwAb_fake_H
#define PLT_Srv_IoHwAb_fake_H

#include "Dio.h"
#include "Rte_Type.h"
#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "dio_wrapper.h"

   DECLARE_FAKE_VOID_FUNC(Update_Thermal_Monitor_Values, DT_Thermal_mon_mes_results_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, IoHwAb_RawAdcCount_Read, Dt_RawAdcData_T *);
   DECLARE_FAKE_VOID_FUNC(IoHwAb_Adc_Main_5ms);
   DECLARE_FAKE_VOID_FUNC(ADC_Channels_Init);
   DECLARE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);
   DECLARE_FAKE_VALUE_FUNC(Dio_Wrapper_Status_T, Dio_Wrapper_WriteChannel, Dio_ChannelType, Dio_LevelType);
   DECLARE_FAKE_VOID_FUNC(Read_PVT_Temperature_Values);

#ifdef __cplusplus
}
#endif

#define FFF_FAKES_ADCINIT_FUNCTION(FAKE)     FAKE(ADC_Channels_Init)
#define FFF_FAKES_RAWADCCOUNT_FUNCTION(FAKE) FAKE(IoHwAb_RawAdcCount_Read)
#define FFF_FAKES_ADCMAIN_FUNCTION(FAKE)     FAKE(IoHwAb_Adc_Main_5ms)

#endif
