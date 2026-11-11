/**
 * @file EthIf_User_Cbk_fakes.h
 * @brief Fake function declarations for EthIf_User_Cbk testing
 */

#ifndef ETHIF_USER_CBK_FAKES_H
#define ETHIF_USER_CBK_FAKES_H

#include "fff.h"
#include <stdint.h>
#include <string.h>

// AUTOSAR types
typedef uint8_t Std_ReturnType;
typedef uint8_t EthIf_SwitchPortIdxType;
typedef uint8_t boolean;
typedef uint8_t Log_Cal_Src_T;
#define E_OK           ((Std_ReturnType)0x00u)
#define MAC_ADDR_BYTES 6u
#define SMC            0u

// SMC Calibration structure
typedef struct
{
   struct
   {
      uint8_t k_sensor_ethernet_lsb_list[8];
      uint8_t k_destination_ip[4];
   } Vehicle_Configuration_Cal;
} SMC_Cal_Data_T;

extern SMC_Cal_Data_T *SMC_Cal_Data_Ptr;

// External function declarations
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, EthIf_SetPhysAddr, uint8_t, const uint8_t *);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_SetUniqueRemoteAddr, uint16_t, const uint8_t *, uint16_t);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, EthIf_GetPhysAddr, uint8_t, uint8_t *);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_GetLocalAddr, uint16_t, uint8_t *, uint16_t *, uint8_t *);
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_GetRemoteAddr, uint16_t, uint8_t *, uint16_t *);
DECLARE_FAKE_VALUE_FUNC(boolean, Get_Cal_Load_Status, Log_Cal_Src_T);

#endif // ETHIF_USER_CBK_FAKES_H
