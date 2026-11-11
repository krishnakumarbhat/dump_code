#ifndef SWC_PLT_CDD_XCP_H
#define SWC_PLT_CDD_XCP_H

#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

#define CODED_TRUE  (1U)
#define CODED_FALSE (0U)

#define XCP_CHANNEL_IDX       (0U)
#define XCP_SESSION_CONNECTED (0x0001U)

#define XCP_CMD_OK     (0U)
#define XCP_CMD_DENIED (1U)

#define XCP_CODE
#define FUNC(type, memclass) type

#define R52TCMA_ADDR_START_WRITE 0x00000040U

typedef uint32 Xcp_AddressPtrType;

typedef struct
{
   uint8 payload[16];
} D2M_Msg_T;

#endif
