#include "Cdd_Cbk.h"
#include "SWC_PLT_CDD_Logging.h"
#include "SoAd.h"
#include "hil_communication_handler.h"

#pragma clang optimize off
/* FUNC(void, RTE_SWC_PLT_CDD_WDGHANDLER_APPL_CODE) CS_Wdg_Disable(void); */
volatile uint32 Veh_UDP_Stream_Rx_Cbk_counter  = 0U;
volatile uint32 Cdd_SoAdIfRxIndication_counter = 0U;
volatile uint32 HIL_Cbk_Counter                = 0U;
volatile uint32 Evaluate_HIL_Request_Counter   = 0U;

FUNC(void, CDD_CODE) Cdd_SoAdIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr)
{
   Cdd_SoAdIfRxIndication_counter++;
   /* for break point testing Enable ENABLE_EXTERNAL_WDG */
   /* FUNC(void, RTE_SWC_PLT_CDD_WDGHANDLER_APPL_CODE) CS_Wdg_Disable(void); add this prototype to resolve build issue*/
   /* call CS_Wdg_Disable() here*/
   /* mss_main_asr.c - > main_asr() - > add while(!Go) -> volatile uint8 G0 = 0  : help to check exception*/

   if (CddConf_CddSoAdUpperLayerRxPdu_RDR_VEH_UDP_STREAM_RX == RxPduId)
   {
      Veh_UDP_Stream_Rx_Cbk_counter++;
      Udp_Rx_Callback((uint8_t *)PduInfoPtr->SduDataPtr);
   }
   else if (CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX == RxPduId)
   {
      HIL_Cbk_Counter++;
      /* CS_Wdg_Disable();*/
      if (NULL != PduInfoPtr->SduDataPtr)
      {
         Evaluate_HIL_Request_Counter++;
         /*Call the HIL function to evalute the request from HIL PC*/
         Evaluate_HIL_Request((Rec_Frame_T *)PduInfoPtr->SduDataPtr);
      }
   }
   else
   {
      /* This cannot be reached. Exception captured by SoAd at init level */
   }

   return;
}
#pragma clang optimize on
