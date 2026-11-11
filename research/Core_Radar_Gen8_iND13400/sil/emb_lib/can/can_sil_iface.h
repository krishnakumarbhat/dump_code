#ifndef CAN_SIL_IFACE_H
#define CAN_SIL_IFACE_H

#ifdef AL_TRACKER
   #include "cust_can_sil_iface.h"

void transmit_can_data(unsigned long long timestamp);
#endif

#endif // CAN_SIL_IFACE_H
