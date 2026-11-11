/****************************************************************************
 * Copyright 2022 APTIV, All Rights Reserved
 * Test Stub for PSC Calibration
 * File Name: psc_cal_stub.c
 *
 * Provides stub implementation of Get_Volt_Monitor_Cal_Impl() for unit tests.
 *****************************************************************************/
#include "psc_cal.h"

/* Stub calibration data for unit testing */
static Volt_Monitor_Cal_T Volt_Monitor_Stub_Cal = {
   {1U, 1U, 0U, 1U, 1U, 48U}, /* H3 header */
   (u6p10_T)8192,             /* k_norm_vmin */
   (u6p10_T)16384,            /* k_norm_vmax */
   (u6p10_T)7680,             /* k_L0_V1max */
   (u6p10_T)7168,             /* k_L0_V1min */
   (u6p10_T)6656,             /* k_L0_V2max */
   (u6p10_T)16896,            /* k_HI_V1min */
   (u16p0_T)17920,            /* k_HI_V1max */
   (u16p0_T)19456,            /* k_HI_V2min */
   (u16p0_T)200,              /* k_VRMtimeTolowV2 */
   (u16p0_T)200,              /* k_VRMtimeTolowV1 */
   (u16p0_T)200,              /* k_VRMtimelowVtempToNorm */
   (u16p0_T)200,              /* k_VRMtimelowV1ToNorm */
   (u16p0_T)200,              /* k_VRMtimelowV2ToNorm */
   (u16p0_T)200,              /* k_VRMtimeTohighV2 */
   (u16p0_T)200,              /* k_VRMtimeTohighV1 */
   (u16p0_T)200,              /* k_VRMtimehighVtempToNorm */
   (u16p0_T)200,              /* k_VRMtimehighV1ToNorm */
   (u16p0_T)200               /* k_VRMtimehighV2ToNorm */
};

volatile u8p0_T Proj_Electrical_System = (u8p0_T)PROJ_ELECTRICAL_SYSTEM_12V;

Volt_Monitor_Cal_T *Get_Volt_Monitor_Cal_Impl(void)
{
   return &Volt_Monitor_Stub_Cal;
}
