/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "can_sil_iface.h"
#include "profile_timing.h"

#ifdef AL_TRACKER
void transmit_can_data(unsigned long long timestamp)
{
   /* Start Timer */
   TIMER_START(TRANSMIT_CAN);

   can_data_write(timestamp);

   /* Stop Timer */
   TIMER_STOP(TRANSMIT_CAN);
}
#endif
