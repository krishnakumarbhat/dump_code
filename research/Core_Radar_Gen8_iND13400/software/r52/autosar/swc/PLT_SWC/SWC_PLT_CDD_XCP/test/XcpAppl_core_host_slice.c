#include <stdint.h>

typedef uint32_t Xcp_TimestampType;

typedef uint8_t uint8;

#define FUNC(rettype, memclass) rettype
#define XCP_CODE
#define XCP_LOCAL_CLOCK_STATE_FREE_RUNNING (0x01u)
#define XCP_GRANDM_CLOCK_STATE_SYNCH       (0x10u)

#line 251 "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Source/XcpAppl.c"
FUNC(Xcp_TimestampType, XCP_CODE) XcpAppl_GetTimestamp(void)
{
   Xcp_TimestampType XcpTimestampSlv = 0u;
   return (XcpTimestampSlv);
}

#line 307 "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Source/XcpAppl.c"
FUNC(uint8, XCP_CODE) XcpAppl_GetClockSyncState(void)
{
   return XCP_LOCAL_CLOCK_STATE_FREE_RUNNING | XCP_GRANDM_CLOCK_STATE_SYNCH;
}
