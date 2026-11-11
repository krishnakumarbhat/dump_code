#ifndef SWC_PRJ_APPL_SECURITY_MANAGER_COMMON_H
#define SWC_PRJ_APPL_SECURITY_MANAGER_COMMON_H

/*===========================================================================*/
/*****************************************************************************
 * @file SWC_Security_Manager_Common.h
 *
 *  This file contains type definitions and function declarations required
 * for Security Manager common HSM custom operations.
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
 * This file contains macros, structure declarations and function prototypes
 * used by Security Manager common helper functionality.
 *
 */
/*==========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

#include "Rte_Type.h"
#include "Std_Types.h"

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#define CRYPTO_CUSTOMFUNCTIONS_GET_VERSION_INFO_KID                   1011u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_LENGTH                     10u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_CONTAINER_VERSION_LENGTH   3u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_MW_VERSION_LENGTH          4u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_SBOOT_VERSION_LENGTH       3u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_CONTAINER_VERSION_STARTIDX 0u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_MW_VERSION_STARTIDX        3u
#define CRYPTO_CUSTOMFUNCTIONS_VERSIONINFO_SBOOT_VERSION_STARTIDX     7u

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
Std_ReturnType Crypto_CustomFunctions_GetHSMComponentsVersions(Crypto_CustomFunctions_VersionStruct *HSMversionStructPtr);

#endif /* SWC_PRJ_APPL_SECURITY_MANAGER_COMMON_H */
