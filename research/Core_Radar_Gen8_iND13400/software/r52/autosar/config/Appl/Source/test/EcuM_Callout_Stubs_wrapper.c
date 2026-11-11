/**
 * @file EcuM_Callout_Stubs_wrapper.c
 * @brief Wrapper for EcuM_Callout_Stubs.c with testable functions
 */

#include "EcuM_Callout_fakes.h"
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/* Mock config pointers */
static const void *mock_bswm_config                    = (void *)0x5000;
static EcuM_GlobalPCConfigType mock_global_config      = {&mock_bswm_config};
const EcuM_GlobalPCConfigType *EcuM_GlobalPCConfig_Ptr = &mock_global_config;
const void *Det_Config_Ptr                             = (void *)0x1000;
const void *ComM_Config_Ptr                            = (void *)0x2000;
const void *PduR_Config_Ptr                            = (void *)0x3000;
const void *SoAd_Config_Ptr                            = (void *)0x4000;

// Flash driver mock implementation
volatile uint16_t SPC_load_fail = 0;

#ifdef __cplusplus
extern "C"
{
#endif

   int32_t mock_ReadData(uint32_t addr, void *data, uint32_t cnt)
   {
      return (int32_t)cnt;
   }

   ARM_FLASH_STATUS mock_GetStatus(void)
   {
      ARM_FLASH_STATUS status = {0, 0};
      return status;
   }

   ARM_FLASH_CAPABILITIES mock_GetCapabilities(void)
   {
      ARM_FLASH_CAPABILITIES cap = {0};
      return cap;
   }

#ifdef __cplusplus
}
#endif

ARM_DRIVER_FLASH Driver_Flash0 = {mock_ReadData, mock_GetStatus, mock_GetCapabilities};

#line 139 "software/r52/autosar/config/Appl/Source/EcuM_Callout_Stubs.c"
void *Sensor_Pos_SPC_Flash_Read_Wrapper(void *dst, const void *src, uintptr_t length)
{
   ARM_FLASH_STATUS status;
   int32_t ReadData_result                   = 0;
   const ARM_FLASH_CAPABILITIES capabilities = Driver_Flash0.GetCapabilities();
   uint8_t read_buffer[64] __attribute__((aligned(16)));
   static int16_t SPC_timeout_counter;
   while (length)
   {
      const uint32_t read_size = length > sizeof(read_buffer) ? sizeof(read_buffer) : length;
      SPC_timeout_counter      = 1000;
      ReadData_result          = Driver_Flash0.ReadData((uint32_t)src, read_buffer, read_size >> capabilities.data_width);
      if (((int32_t)read_size) == ReadData_result)
      {
         do
         {
            status = Driver_Flash0.GetStatus();
            SPC_timeout_counter--;
         } while (status.busy && !status.error && SPC_timeout_counter);
         if ((status.error) || (0 == SPC_timeout_counter))
         {
            SPC_load_fail = 1;
         }
         memcpy(dst, read_buffer, read_size);
         dst = ((uint8_t *)dst) + read_size;
         src = ((uint8_t *)src) + read_size;
         length -= read_size;
      }
      else
      {
         // do nothing
      }
   }
   return NULL;
}

#line 1 "software/r52/autosar/config/Appl/Source/EcuM_Callout_Stubs.c"
void EcuM_ErrorHook(uint16_t reason)
{
   if (reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
   {
#ifndef UNIT_TEST
      while (1)
      {
      }
#endif
   }

#if (ECUM_NUMBER_OF_CORES > 1)
   if (reason == ECUM_E_HOOK_INVALID_COREID)
   {
   #ifndef UNIT_TEST
      while (1)
      {
      }
   #endif
   }
#endif

   return;
}

void EcuM_AL_DriverInitZero(void)
{
   BswM_InitMemory();
   ComM_InitMemory();
   Com_InitMemory();
   Det_InitMemory();
   EthIf_InitMemory();
   EthSM_InitMemory();
   PduR_InitMemory();
   Rte_InitMemory();
   SoAd_InitMemory();
   TcpIp_InitMemory();
   EthTrcv_30_Rtl9010_InitMemory();
   Det_Init(Det_Config_Ptr);
   Xcp_InitMemory();
   TcpIpXcp_InitMemory();
   CanIf_InitMemory();
   CanSM_InitMemory();

   MCAL_Init();

   Sensor_Position_Config_T sensor_position_config = Get_Default_Sensor_Position_Config();
   sensor_position_config.flash_read               = Sensor_Pos_SPC_Flash_Read_Wrapper;
   Init_Sensor_Position(&sensor_position_config);
   Read_Sensor_Position_Pins();
}

void EcuM_AL_DriverInitOne_RDR_01(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_01(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_02(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_02(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_03(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_03(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_04(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_04(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_05(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_05(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_06(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_06(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_07(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_07(void)
{
   // Empty
}

void EcuM_AL_DriverInitOne_RDR_08(void)
{
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->BswMConfigPtr);
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(PduR_Config_Ptr);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(NULL);
}

void EcuM_AL_DriverRestartList_RDR_08(void)
{
   // Empty
}

typedef struct
{
   const void *RDR_01;
   const void *RDR_02;
   const void *RDR_03;
   const void *RDR_04;
   const void *RDR_05;
   const void *RDR_06;
   const void *RDR_07;
   const void *RDR_08;
} EcuM_GlobalConfigRoot_T;

static EcuM_GlobalConfigRoot_T EcuM_GlobalConfigRoot = {(void *)0x1001, (void *)0x1002, (void *)0x1003, (void *)0x1004,
                                                        (void *)0x1005, (void *)0x1006, (void *)0x1007, (void *)0x1008};

const void *EcuM_DeterminePbConfiguration(void)
{
   const void *RetVal;
   uint8_t ecu_position;

   DisableAllInterrupts();

   ecu_position = Get_Radar_Position();

   switch (ecu_position)
   {
      case 1:
         RetVal = EcuM_GlobalConfigRoot.RDR_01;
         break;
      case 2:
         RetVal = EcuM_GlobalConfigRoot.RDR_02;
         break;
      case 3:
         RetVal = EcuM_GlobalConfigRoot.RDR_03;
         break;
      case 4:
         RetVal = EcuM_GlobalConfigRoot.RDR_04;
         break;
      case 5:
         RetVal = EcuM_GlobalConfigRoot.RDR_05;
         break;
      case 6:
         RetVal = EcuM_GlobalConfigRoot.RDR_06;
         break;
      case 7:
         RetVal = EcuM_GlobalConfigRoot.RDR_07;
         break;
      case 8:
         RetVal = EcuM_GlobalConfigRoot.RDR_08;
         break;
      default:
         RetVal = EcuM_GlobalConfigRoot.RDR_01;
         break;
   }

   EnableAllInterrupts();

   return RetVal;
}

void EcuM_StartOS(uint8_t appMode)
{
   StartOS(appMode);
   return;
}

void EcuM_ShutdownOS(uint16_t ErrCode)
{
   ShutdownOS(ErrCode);
   return;
}

void EcuM_BswErrorHook(uint16_t BswModuleId, uint8_t ErrorId)
{
#ifndef ECUM_MODULE_ID
   #define ECUM_MODULE_ID 10
#endif
   if (BswModuleId == ECUM_MODULE_ID)
   {
#ifndef UNIT_TEST
      while (1)
      {
      }
#endif
   }
   return;
}

void EcuM_AL_SetProgrammableInterrupts(void)
{
   // Empty
}

void EcuM_OnGoOffOne(void)
{
   // Empty
}

void EcuM_OnGoOffTwo(void)
{
   // Empty
}

void EcuM_AL_SwitchOff(void)
{
   // Empty
}

void EcuM_AL_Reset(uint8_t reset_type)
{
   // Empty
}

// Additional sleep mode functions
void EcuM_GenerateRamHash(void)
{
   // Empty
}

uint8_t EcuM_CheckRamHash(void)
{
   return 1u;
}

void EcuM_McuSetMode(uint8_t McuMode)
{
   // Empty - calls Mcu_SetMode in actual implementation
}

void EcuM_SleepActivity(void)
{
   // Empty
}

void EcuM_EnableWakeupSources(uint32_t wakeupSource)
{
   // Empty
}

void EcuM_DisableWakeupSources(uint32_t wakeupSource)
{
   // Empty
}

void EcuM_CheckWakeup(uint32_t wakeupSource)
{
   // Empty
}

void EcuM_StartWakeupSources(uint32_t wakeupSource)
{
   // Empty
}

void EcuM_StopWakeupSources(uint32_t wakeupSource)
{
   // Empty
}

void EcuM_CheckValidation(uint32_t wakeupSource)
{
   // Empty
}
