/**
 * @file Cdd_Cbk_wrapper.c
 * @brief Wrapper to compile Cdd_Cbk.c with fakes for unit testing
 */

#include "Cdd_Cbk_fakes.h"

#line 6 "software/r52/autosar/config/Appl/Source/Cdd_Cbk.c"
volatile uint32_t Veh_UDP_Stream_Rx_Cbk_counter  = 0U;
volatile uint32_t Cdd_SoAdIfRxIndication_counter = 0U;
volatile uint32_t HIL_Cbk_Counter                = 0U;

void Cdd_SoAdIfRxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr)
{
   Cdd_SoAdIfRxIndication_counter++;

   if (CddConf_CddSoAdUpperLayerRxPdu_RDR_Veh_UDP_Stream_Rx == RxPduId)
   {
      Veh_UDP_Stream_Rx_Cbk_counter++;
      Udp_Rx_Callback((uint8_t *)PduInfoPtr->SduDataPtr);
   }
   else if (CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX == RxPduId)
   {
      HIL_Cbk_Counter++;
   }
   else
   {
      /* This cannot be reached. Exception captured by SoAd at init level */
   }
}
