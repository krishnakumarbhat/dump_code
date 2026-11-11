/* J1939_Stubs.c - Stub implementations for J1939Nm and J1939Rm
 * Provided per J1939Dcm TechRef section 6.4:
 * "How to support AUTOSAR definitions of J1939Rm and J1939Nm"
 * These stubs are used when J1939Dcm is operated without MICROSAR J1939Nm and J1939Rm. */

#include "ComStack_Types.h"
#include "Compiler.h"
#include "J1939Rm_Types.h"
#include "Std_Types.h"

/* J1939Nm stubs - called by CanSM bus-off handling */
void J1939Nm_GetBusOffDelay(NetworkHandleType channel, uint8 *delayCyclesPtr)
{
   if (delayCyclesPtr != NULL_PTR)
   {
      *delayCyclesPtr = 0u;
   }
}

void J1939Nm_BusOffEnd(NetworkHandleType channel)
{
   /* no action required without MICROSAR J1939Nm */
}

/* J1939Rm stub - called by J1939Dcm to send acknowledgement */
Std_ReturnType J1939Rm_SendAck(uint8 userId, NetworkHandleType channel, uint32 ackPgn, const J1939Rm_ExtIdInfoType *extIdInfo,
                               J1939Rm_AckCode ackCode, uint8 ackAddress, uint8 priority, boolean broadcast)
{
   return E_OK;
}
