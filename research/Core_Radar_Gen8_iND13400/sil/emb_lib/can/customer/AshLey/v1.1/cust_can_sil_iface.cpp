#include "cust_can_sil_iface.h"
#include "can_sil_driver.h"
#include "populate_and_transmit_signals.h"
#include "sil_wrapper_common.h"

void can_data_write(unsigned long long timestamp)
{
   int posn = Get_Radar_Position();
   switch (posn)
   {
      case FRONT_LEFT:
         Populate_Front_Left_Messages();
         break;

      case REAR_LEFT:
         Populate_Rear_Left_Messages();
         break;

      case FRONT_CENTER:
         Populate_FLR_Messages();
         Populate_FLR_VCAN_Messages();
         break;
   }
   // Transmit_CAN_over_UDP();
   Transmit_CAN_Signals(timestamp);
}

float32_t FXP2FLP_Fnc(int32_t value, int32_t bpp_num, bool signed_flag)
{
   float32_t result = 0.0f;
   if ((bpp_num > 31) || (bpp_num < -31))
   {
      // result = FXP2FLP_Fnc_Ext(value,bpp_num,signed_flag);
   }
   else if (bpp_num >= 0)
   {
      if (signed_flag)
      {
         result = ((value) / (float32_t)(1ul << (bpp_num)));
      }
      else
      {
         result = (((uint32_t)value) / (float32_t)(1ul << (bpp_num)));
      }
   }
   else
   {
      if (signed_flag)
      {
         result = ((value) * (float32_t)(1ul << (-1 * (bpp_num))));
      }
      else
      {
         result = (((uint32_t)value) * (float32_t)(1ul << (-1 * (bpp_num))));
      }
   }
   return result;
}
