#ifndef __Sensor_SIGNAL_MACROS_VCAN__
#define __Sensor_SIGNAL_MACROS_VCAN__
#include "fixmac.h"

typedef int8_t sint8_t;
typedef int16_t sint16_t;
typedef int32_t sint32_t;

#define _is_sign_bit_set(x, y, z) (((x & y) >> z) ? (1) : (0))

/*****************************************************/
#define Engg_val_of_signal_BlindSpotCollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x)                                  \
   ((x->BlindSpotCollisionWarningLevel))

#define Phys_Val_of_signal_BlindSpotCollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x)                                  \
   ((uint8_t)Engg_val_of_signal_BlindSpotCollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x))

/*****************************************************/
#define Engg_val_of_signal_MOIS_CollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x) ((x->MOIS_CollisionWarningLevel))

#define Phys_Val_of_signal_MOIS_CollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x)                                      \
   ((uint8_t)Engg_val_of_signal_MOIS_CollisionWarningLevel_in_message_prop_ADAS_MOIS_BSIS_info(x))

/*****************************************************/
#define Engg_val_of_signal_MovingObjectDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x) ((x->MovingObjectDetectionState))

#define Phys_Val_of_signal_MovingObjectDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x)                                      \
   ((uint8_t)Engg_val_of_signal_MovingObjectDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x))

/*****************************************************/
#define Engg_val_of_signal_BlindSpotDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x) ((x->BlindSpotDetectionState))

#define Phys_Val_of_signal_BlindSpotDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x)                                         \
   ((uint8_t)Engg_val_of_signal_BlindSpotDetectionState_in_message_prop_ADAS_MOIS_BSIS_info(x))

/*****************************************************/

/*****************************************************/
#define Engg_val_of_signal_CollisionWarningLevel_in_message_MOIS(x) ((x->CollisionWarningLevel))

#define Phys_Val_of_signal_CollisionWarningLevel_in_message_MOIS(x)                                                               \
   ((uint8_t)Engg_val_of_signal_CollisionWarningLevel_in_message_MOIS(x))

/*****************************************************/
#define Engg_val_of_signal_ObjectDetectionState_in_message_MOIS(x) ((x->ObjectDetectionState))

#define Phys_Val_of_signal_ObjectDetectionState_in_message_MOIS(x)                                                                \
   ((uint8_t)Engg_val_of_signal_ObjectDetectionState_in_message_MOIS(x))

/*****************************************************/
#define Engg_val_of_signal_WarningRelevantObjectDetected_in_message_MOIS(x) ((x->WarningRelevantObjectDetected))

#define Phys_Val_of_signal_WarningRelevantObjectDetected_in_message_MOIS(x)                                                       \
   ((uint8_t)Engg_val_of_signal_WarningRelevantObjectDetected_in_message_MOIS(x))

/*****************************************************/
#define Engg_val_of_signal_BlindSpotWarnigRelevantObjDetect_in_message_BSD1(x) ((x->BlindSpotWarnigRelevantObjDetect))

#define Phys_Val_of_signal_BlindSpotWarnigRelevantObjDetect_in_message_BSD1(x)                                                    \
   ((uint8_t)Engg_val_of_signal_BlindSpotWarnigRelevantObjDetect_in_message_BSD1(x))

/*****************************************************/
#define Engg_val_of_signal_BendOffPrbablityofMstImportatObj_in_message_BSD1(x) ((x->BendOffPrbablityofMstImportatObj))

#define Phys_Val_of_signal_BendOffPrbablityofMstImportatObj_in_message_BSD1(x)                                                    \
   ((uint8_t)Engg_val_of_signal_BendOffPrbablityofMstImportatObj_in_message_BSD1(x))

/*****************************************************/
#define Engg_val_of_signal_BlindSpotCollisionWarningLevel_in_message_BSD1(x) ((x->BlindSpotCollisionWarningLevel))

#define Phys_Val_of_signal_BlindSpotCollisionWarningLevel_in_message_BSD1(x)                                                      \
   ((uint8_t)Engg_val_of_signal_BlindSpotCollisionWarningLevel_in_message_BSD1(x))

/*****************************************************/
#define Engg_val_of_signal_BlindSpotDetectionState_in_message_BSD1(x) ((x->BlindSpotDetectionState))

#define Phys_Val_of_signal_BlindSpotDetectionState_in_message_BSD1(x)                                                             \
   ((uint8_t)Engg_val_of_signal_BlindSpotDetectionState_in_message_BSD1(x))

/*****************************************************/

#endif
