#ifndef NVM_H
#define NVM_H

#include <stdint.h>

typedef uint16_t NvM_BlockIdType;
typedef uint8_t NvM_RequestResultType;
typedef uint8_t Std_ReturnType;

#ifndef E_OK
   #define E_OK ((Std_ReturnType)0U)
#endif
#ifndef E_NOT_OK
   #define E_NOT_OK ((Std_ReturnType)1U)
#endif

#ifndef NVM_REQ_OK
   #define NVM_REQ_OK ((NvM_RequestResultType)0U)
#endif
#ifndef NVM_REQ_PENDING
   #define NVM_REQ_PENDING ((NvM_RequestResultType)2U)
#endif

#ifndef NvMConf_NvMBlockDescriptor_SWC_Appl_Faultmgr
   #define NvMConf_NvMBlockDescriptor_SWC_Appl_Faultmgr (6u)
#endif

Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType blockId, NvM_RequestResultType *requestResultPtr);
Std_ReturnType NvM_WriteBlock(NvM_BlockIdType blockId, const void *srcPtr);

#endif
