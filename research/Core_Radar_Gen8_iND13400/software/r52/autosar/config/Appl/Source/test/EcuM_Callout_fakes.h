/**
 * @file EcuM_Callout_fakes.h
 * @brief Fake function declarations for EcuM_Callout_Stubs testing
 */

#ifndef ECUM_CALLOUT_FAKES_H
#define ECUM_CALLOUT_FAKES_H

#include "fff.h"
#include <stdint.h>

// AUTOSAR types
typedef uint8_t EcuM_UserType;
typedef uint32_t EcuM_WakeupSourceType;
typedef struct
{
   const void *BswMConfigPtr;
} EcuM_GlobalPCConfigType;

extern const EcuM_GlobalPCConfigType *EcuM_GlobalPCConfig_Ptr;
extern const void *Det_Config_Ptr;
extern const void *ComM_Config_Ptr;
extern const void *PduR_Config_Ptr;
extern const void *SoAd_Config_Ptr;

// Sensor position types
typedef enum
{
   APTIV_FLR = 0,
   APTIV_SRR = 1
} Sensor_Position_E;

typedef void *(*Sensor_Pos_SPC_Flash_Read_T)(void *, const void *, uintptr_t);

typedef struct
{
   Sensor_Position_E Position;
   Sensor_Pos_SPC_Flash_Read_T flash_read;
} Sensor_Position_Config_T;

// EcuM Error Hook reasons
#define ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT 1
#define ECUM_E_HOOK_INVALID_COREID                  2
#define ECUM_NUMBER_OF_CORES                        1
#define ECUM_MODULE_ID                              10

// External function declarations
DECLARE_FAKE_VOID_FUNC(BswM_InitMemory);
DECLARE_FAKE_VOID_FUNC(ComM_InitMemory);
DECLARE_FAKE_VOID_FUNC(Com_InitMemory);
DECLARE_FAKE_VOID_FUNC(Det_InitMemory);
DECLARE_FAKE_VOID_FUNC(EthIf_InitMemory);
DECLARE_FAKE_VOID_FUNC(EthSM_InitMemory);
DECLARE_FAKE_VOID_FUNC(PduR_InitMemory);
DECLARE_FAKE_VOID_FUNC(Rte_InitMemory);
DECLARE_FAKE_VOID_FUNC(SoAd_InitMemory);
DECLARE_FAKE_VOID_FUNC(TcpIp_InitMemory);
DECLARE_FAKE_VOID_FUNC(EthTrcv_30_Rtl9010_InitMemory);
DECLARE_FAKE_VOID_FUNC(Xcp_InitMemory);
DECLARE_FAKE_VOID_FUNC(TcpIpXcp_InitMemory);
DECLARE_FAKE_VOID_FUNC(CanIf_InitMemory);
DECLARE_FAKE_VOID_FUNC(CanSM_InitMemory);
DECLARE_FAKE_VOID_FUNC(MCAL_Init);
DECLARE_FAKE_VALUE_FUNC(Sensor_Position_Config_T, Get_Default_Sensor_Position_Config);
DECLARE_FAKE_VOID_FUNC(Init_Sensor_Position, Sensor_Position_Config_T *);
DECLARE_FAKE_VOID_FUNC(Read_Sensor_Position_Pins);
DECLARE_FAKE_VOID_FUNC(Det_Init, const void *);
DECLARE_FAKE_VOID_FUNC(BswM_PreInit, const void *);
DECLARE_FAKE_VOID_FUNC(ComM_PreInit, const void *);
DECLARE_FAKE_VOID_FUNC(PduR_PreInit, const void *);
DECLARE_FAKE_VOID_FUNC(SoAd_PreInit, const void *);
DECLARE_FAKE_VOID_FUNC(Eth_30_Wrapper_Init, const void *);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DECLARE_FAKE_VOID_FUNC(DisableAllInterrupts);
DECLARE_FAKE_VOID_FUNC(EnableAllInterrupts);
DECLARE_FAKE_VOID_FUNC(StartOS, uint8_t);
DECLARE_FAKE_VOID_FUNC(ShutdownOS, uint16_t);

// Driver Flash types and fakes
typedef struct
{
   uint32_t busy:1;
   uint32_t error:1;
} ARM_FLASH_STATUS;

typedef struct
{
   uint32_t data_width:3;
} ARM_FLASH_CAPABILITIES;

typedef int32_t (*FlashReadData_T)(uint32_t, void *, uint32_t);
typedef ARM_FLASH_STATUS (*FlashGetStatus_T)(void);
typedef ARM_FLASH_CAPABILITIES (*FlashGetCapabilities_T)(void);

typedef struct
{
   FlashReadData_T ReadData;
   FlashGetStatus_T GetStatus;
   FlashGetCapabilities_T GetCapabilities;
} ARM_DRIVER_FLASH;

extern ARM_DRIVER_FLASH Driver_Flash0;
extern volatile uint16_t SPC_load_fail;

#endif // ECUM_CALLOUT_FAKES_H
