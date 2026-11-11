/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "someip_iface.h"
#include "cust_someip_iface.h"

void transmit_someip_data(unsigned long long timestamp)
{
   someip_data_write(timestamp);
}
