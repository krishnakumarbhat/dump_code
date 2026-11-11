#ifndef __Sensor_message_decode_types_VCAN__
#define __Sensor_message_decode_types_VCAN__

#include "fixmac.h"

/*Note:These structures are used to read physical values.*/
/*Do not use these to copy the bus data. message_types.h shall be used for that purpose*/

typedef struct
{
   uint8_t BlindSpotDetectionState;
   uint8_t BlindSpotCollisionWarningLevel;
   uint8_t BlindSpotWarnigRelevantObjDetect;
   uint8_t BendOffPrbablityofMstImportatObj;
   unsigned int id;
   unsigned long long timestamp;
} BSD1_VCAN_decoded_msg_t;

typedef struct
{
   uint8_t ObjectDetectionState;
   uint8_t CollisionWarningLevel;
   uint8_t WarningRelevantObjectDetected;
   unsigned int id;
   unsigned long long timestamp;
} MOIS_decoded_msg_t;

typedef struct
{
   uint8_t MovingObjectDetectionState;
   uint8_t MOIS_CollisionWarningLevel;
   uint8_t BlindSpotDetectionState;
   uint8_t BlindSpotCollisionWarningLevel;
   unsigned int id;
   unsigned long long timestamp;
} prop_ADAS_MOIS_BSIS_info_decoded_msg_t;

typedef struct
{
   prop_ADAS_MOIS_BSIS_info_decoded_msg_t prop_ADAS_MOIS_BSIS_info;
   MOIS_decoded_msg_t MOIS;
   BSD1_VCAN_decoded_msg_t BSD1;
} Sensor_decoded_types_VCAN_t;

#endif
