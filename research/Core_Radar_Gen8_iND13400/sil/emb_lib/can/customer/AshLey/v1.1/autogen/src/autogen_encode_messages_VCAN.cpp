#include "autogen_message_decode_types_VCAN.h"
#include "autogen_message_encoded_types_VCAN.h"
#include "autogen_signal_macros_VCAN.h"

typedef int8_t sint8_t;
typedef int16_t sint16_t;
typedef int32_t sint32_t;

void encode_message_BSD1_VCAN(void *encode_ptr, void *decode_ptr)
{
   BSD1_VCAN_decoded_msg_t *d_ptr = (BSD1_VCAN_decoded_msg_t *)decode_ptr;
   BSD1_VCAN_encoded_msg_t *e_ptr = (BSD1_VCAN_encoded_msg_t *)encode_ptr;

   e_ptr->BlindSpotDetectionState          = (uint8_t)(((uint64_t)d_ptr->BlindSpotDetectionState & 0xF) >> 0);
   e_ptr->BlindSpotCollisionWarningLevel   = (uint8_t)(((uint64_t)d_ptr->BlindSpotCollisionWarningLevel & 0xF) >> 0);
   e_ptr->BlindSpotWarnigRelevantObjDetect = (uint8_t)(((uint64_t)d_ptr->BlindSpotWarnigRelevantObjDetect & 0x7) >> 0);
   e_ptr->BendOffPrbablityofMstImportatObj = (uint8_t)(((uint64_t)d_ptr->BendOffPrbablityofMstImportatObj & 0x7) >> 0);
}

void encode_message_prop_ADAS_MOIS_BSIS_info(void *encode_ptr, void *decode_ptr)
{
   prop_ADAS_MOIS_BSIS_info_decoded_msg_t *d_ptr = (prop_ADAS_MOIS_BSIS_info_decoded_msg_t *)decode_ptr;
   prop_ADAS_MOIS_BSIS_info_encoded_msg_t *e_ptr = (prop_ADAS_MOIS_BSIS_info_encoded_msg_t *)encode_ptr;

   e_ptr->MovingObjectDetectionState     = (uint8_t)(((uint64_t)d_ptr->MovingObjectDetectionState & 0xF) >> 0);
   e_ptr->MOIS_CollisionWarningLevel     = (uint8_t)(((uint64_t)d_ptr->MOIS_CollisionWarningLevel & 0xF) >> 0);
   e_ptr->BlindSpotDetectionState        = (uint8_t)(((uint64_t)d_ptr->BlindSpotDetectionState & 0xF) >> 0);
   e_ptr->BlindSpotCollisionWarningLevel = (uint8_t)(((uint64_t)d_ptr->BlindSpotCollisionWarningLevel & 0xF) >> 0);
}

void encode_message_MOIS(void *encode_ptr, void *decode_ptr)
{
   MOIS_decoded_msg_t *d_ptr = (MOIS_decoded_msg_t *)decode_ptr;
   MOIS_encoded_msg_t *e_ptr = (MOIS_encoded_msg_t *)encode_ptr;

   e_ptr->ObjectDetectionState          = (uint8_t)(((uint64_t)d_ptr->ObjectDetectionState & 0xF) >> 0);
   e_ptr->CollisionWarningLevel         = (uint8_t)(((uint64_t)d_ptr->CollisionWarningLevel & 0xF) >> 0);
   e_ptr->WarningRelevantObjectDetected = (uint8_t)(((uint64_t)d_ptr->WarningRelevantObjectDetected & 0x7) >> 0);
}
