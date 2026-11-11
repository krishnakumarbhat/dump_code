#ifndef NVM_H
#define NVM_H

#include "Rte_Type.h"

typedef uint8 NvM_RequestResultType;
typedef uint16 NvM_BlockIdType;

#define NVM_REQ_OK      ((NvM_RequestResultType)0U)
#define NVM_REQ_NOT_OK  ((NvM_RequestResultType)1U)
#define NVM_REQ_PENDING ((NvM_RequestResultType)2U)

#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1U)

uint8 NvM_GetErrorStatus(NvM_BlockIdType blockId, NvM_RequestResultType *requestResultPtr);
uint8 NvM_WriteBlock(NvM_BlockIdType blockId, const void *srcPtr);

#ifndef NVM_PUBLIC_CODE
   #define NVM_PUBLIC_CODE
#endif

#endif
