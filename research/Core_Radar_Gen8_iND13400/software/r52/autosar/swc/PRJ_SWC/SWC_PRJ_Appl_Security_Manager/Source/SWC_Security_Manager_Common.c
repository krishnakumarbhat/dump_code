/*===========================================================================*/
/*****************************************************************************
 * @file SWC_Security_Manager_Common.c
 *
 *  This file contains common Security Manager helper functions for
 * HSM custom version information retrieval.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains implementation of common Security Manager helper APIs.
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
\*===========================================================================*/
#include "SWC_Security_Manager_Common.h"
#include "Crypto_182_iND13400_Cfg.h"
#include "Crypto_182_iND13400_IPC.h"
#include "Csm.h"
#include "Csm_Cfg.h"

/*===========================================================================*\
 * Module State Variables
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
Std_ReturnType Crypto_CustomFunctions_GetHSMComponentsVersions(Crypto_CustomFunctions_VersionStruct *HSMversionStructPtr)
{
   uint8 version_Info[CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_LENGTH] = {0u};
   uint32 version_Info_Size                                      = (uint32)CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_LENGTH;
   Std_ReturnType Local_uint8Return                              = E_NOT_OK;

   if (HSMversionStructPtr == NULL_PTR)
   {
      return E_NOT_OK;
   }

   Local_uint8Return = Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_Custom_Operations, CRYPTO_CUSTOMFUNCTIONS_GET_VERSION_INFO_KID,
                                         version_Info, &version_Info_Size);

   if ((Local_uint8Return == E_OK) && (version_Info_Size >= (uint32)CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_LENGTH))
   {
      Crypto_182_iND13400_Ipc_UtiMemCopyUint32(&version_Info[CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_CONTAINER_VERSION_STARTIDX],
                                               &HSMversionStructPtr->containerVersion,
                                               CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_CONTAINER_VERSION_LENGTH);

      Crypto_182_iND13400_Ipc_UtiMemCopyUint32(&version_Info[CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_MW_VERSION_STARTIDX],
                                               &HSMversionStructPtr->mwVersion,
                                               CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_MW_VERSION_LENGTH);

      Crypto_182_iND13400_Ipc_UtiMemCopyUint32(&version_Info[CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_SBOOT_VERSION_STARTIDX],
                                               &HSMversionStructPtr->sBoot,
                                               CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_SBOOT_VERSION_LENGTH);
   }
   else
   {
      HSMversionStructPtr->containerVersion = 0u;
      HSMversionStructPtr->mwVersion        = 0u;
      HSMversionStructPtr->sBoot            = 0u;
   }

   return Local_uint8Return;
}

/*==========================================================================*/
