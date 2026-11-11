#ifndef __Sensor_SIGNAL_STRUCT_DEFINITION_VCAN__
#define __Sensor_SIGNAL_STRUCT_DEFINITION_VCAN__

/*Note : These structures are generated using DBC file as input*/

#include "fixmac.h"

/*MESSAGE BSD1 0xCF206B0*/
typedef struct
{
   uint8_t unused_area_1;
   uint8_t BlindSpotDetectionState:4;
   uint8_t BlindSpotCollisionWarningLevel:4;
   uint8_t BlindSpotWarnigRelevantObjDetect:3;
   uint8_t BendOffPrbablityofMstImportatObj:3;
   uint8_t unused_area_0_0:2;
   uint8_t unused_area_0_1[6];
} BSD1_VCAN_encoded_msg_t;

/*MESSAGE prop_ADAS_MOIS_BSIS_info 0x18FFA4D0*/
typedef struct
{
   uint8_t unused_area_1;
   uint8_t MovingObjectDetectionState:4;
   uint8_t MOIS_CollisionWarningLevel:4;
   uint8_t BlindSpotDetectionState:4;
   uint8_t BlindSpotCollisionWarningLevel:4;
   uint8_t unused_area_0[6];
} prop_ADAS_MOIS_BSIS_info_encoded_msg_t;

/*MESSAGE MOIS 0xCFF4AD0*/
typedef struct
{
   uint8_t unused_area_1;
   uint8_t ObjectDetectionState:4;
   uint8_t CollisionWarningLevel:4;
   uint8_t WarningRelevantObjectDetected:3;
   uint8_t unused_area_0_0:5;
   uint8_t unused_area_0_1[6];
} MOIS_encoded_msg_t;

/******************  Master structure *************************/
typedef struct
{
   prop_ADAS_MOIS_BSIS_info_encoded_msg_t prop_ADAS_MOIS_BSIS_info;
   MOIS_encoded_msg_t MOIS;
   BSD1_VCAN_encoded_msg_t BSD1;
} Sensor_encoded_types_VCAN_t;

#endif
