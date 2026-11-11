/**
 * @file BswM_Callout_fakes.h
 * @brief Fake function declarations for BswM_Callout_Stubs testing
 */

#ifndef BSWM_CALLOUT_FAKES_H
#define BSWM_CALLOUT_FAKES_H

#include "fff.h"
#include <stdint.h>

// AUTOSAR types
typedef uint8_t Std_ReturnType;
typedef uint8_t NvM_RequestResultType;
#define E_OK                    ((Std_ReturnType)0x00u)
#define NVM_REQ_PENDING         1u
#define NVM_REQ_OK              0u
#define COMM_FULL_COMMUNICATION 2u

// External function declarations
DECLARE_FAKE_VOID_FUNC(Gpt_EnableNotification, uint8_t);
DECLARE_FAKE_VOID_FUNC(Gpt_StartTimer, uint8_t, uint32_t);
DECLARE_FAKE_VOID_FUNC(EcuM_SetWakeupEvent, uint32_t);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Mcu_InitClock, uint8_t);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Mcu_DistributePllClock);
DECLARE_FAKE_VOID_FUNC(Sys_Printf_Information, const char *);
DECLARE_FAKE_VOID_FUNC(NvM_ReadAll);
DECLARE_FAKE_VOID_FUNC(NvM_MainFunction);
DECLARE_FAKE_VOID_FUNC(Fee_30_FlexNor_MainFunction);
DECLARE_FAKE_VOID_FUNC(Fls_MainFunction);
DECLARE_FAKE_VOID_FUNC(NvM_GetErrorStatus, uint8_t, NvM_RequestResultType *);
DECLARE_FAKE_VOID_FUNC(ComM_RequestComMode, uint8_t, uint8_t);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DECLARE_FAKE_VOID_FUNC(Com_IpduGroupStart, uint16_t, uint8_t);
DECLARE_FAKE_VOID_FUNC(Com_Init, const void *);

// Config pointers
extern const void *EcuM_Config_Ptr;
typedef struct
{
   const void *CfgPtr_Com_Init;
} EcuM_GlobalPCConfigType;
extern const EcuM_GlobalPCConfigType *EcuM_GlobalPCConfig_Ptr;

// Constants
#define NvMConf___MultiBlockRequest                        0u
#define ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b     0u
#define ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1 0x01
#define ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067 0x02
#define ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313 0x03
#define ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495 0x04
#define ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282 0x05
#define ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504 0x06
#define ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7 0x07
#define ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71 0x08
#define ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66 0x09
#define ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0 0x0A
#define ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94 0x0B
#define ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812 0x0C
#define ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05 0x0D
#define ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983 0x0E
#define ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f 0x0F
#define ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9 0x10

#endif // BSWM_CALLOUT_FAKES_H
