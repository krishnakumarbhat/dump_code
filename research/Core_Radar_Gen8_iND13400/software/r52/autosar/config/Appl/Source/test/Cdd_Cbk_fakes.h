/**
 * @file Cdd_Cbk_fakes.h
 * @brief Fake function declarations for Cdd_Cbk testing
 */

#ifndef CDD_CBK_FAKES_H
#define CDD_CBK_FAKES_H

#include "fff.h"
#include <stdint.h>

// AUTOSAR types
typedef uint16_t PduIdType;
typedef struct
{
   uint8_t *SduDataPtr;
   uint16_t SduLength;
} PduInfoType;

// Configuration IDs from Cdd_Cbk_Cfg.h
#define CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx 0u
#define CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX        1u

// External function declarations
DECLARE_FAKE_VOID_FUNC(Udp_Rx_Callback, uint8_t *);

#endif // CDD_CBK_FAKES_H
