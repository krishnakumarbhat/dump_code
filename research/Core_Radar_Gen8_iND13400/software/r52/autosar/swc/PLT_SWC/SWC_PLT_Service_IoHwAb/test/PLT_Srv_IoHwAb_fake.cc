#include "PLT_Srv_IoHwAb_fake.h"
#include "Rte_Type.h"
DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, IoHwAb_RawAdcCount_Read, Dt_RawAdcData_T *);
DEFINE_FAKE_VOID_FUNC(Update_Thermal_Monitor_Values, DT_Thermal_mon_mes_results_T *);
DEFINE_FAKE_VOID_FUNC(IoHwAb_Adc_Main_5ms);
DEFINE_FAKE_VOID_FUNC(ADC_Channels_Init);
DEFINE_FAKE_VOID_FUNC(Dio_WriteChannel, Dio_ChannelType, Dio_LevelType);
DEFINE_FAKE_VALUE_FUNC(Dio_Wrapper_Status_T, Dio_Wrapper_WriteChannel, Dio_ChannelType, Dio_LevelType);
DEFINE_FAKE_VOID_FUNC(Read_PVT_Temperature_Values);
