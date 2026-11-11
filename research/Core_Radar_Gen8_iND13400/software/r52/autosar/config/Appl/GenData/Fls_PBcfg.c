/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @Fls PBcfg source
 *
 * @file 	 Fls_PBcfg.c
 * @Date     Generation Time:   2026-08-28 16:45:33
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2025. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary. 
 * 
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @FLS PBcfg source file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of Flash Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of Flash Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Fls.h"
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define FLS_START_SEC_CONFIG_DATA_POSTBUILD
#include "Fls_MemMap.h"		/* polyspace MISRA-C3:20.1 "AUTOSAR Memory Mapping" */
static const Fls_SectorType FlsSectorSet[1] =
{
    {
       .FlsNumberOfSectors      = FLS_NUMBER_OF_SECTORS_VALUE,
       .FlsPageSize             = FLS_PAGE_SIZE_VALUE,
       .FlsSectorSize           = FLS_SECTOR_SIZE_VALUE,
       .FlsSectorStartaddress   = FLS_SECTOR_START_ADDRESS_VALUE, 
    },
};
const Fls_ConfigType Fls_Config =
 {
    .FlsAcErase                = 0,
    .FlsAcWrite                = 0,
    .FlsCallCycle              = 5,         
    .FlsDefaultMode            = MEMIF_MODE_SLOW, 
	.FlsJobEndNotification     = NULL_PTR,
	.FlsJobErrorNotification   = NULL_PTR,
    .FlsMaxReadFastMode        = 4096,    
    .FlsMaxReadNormalMode      = 4096,    
    .FlsMaxWriteFastMode       = 4096,    
    .FlsMaxWriteNormalMode     = 4096,  
    .FlsProtection             = 0,
	.FlsDriverStrength         = 500,
    .FlsReceiveSampleDelay     = 1,
    .FlsSector                 = &FlsSectorSet[0],
 };

#define FLS_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Fls_MemMap.h"		/* polyspace MISRA-C-2023:20.1 [Justified:Low] Required by AUTOSAR MemMap to close section */ /* polyspace DEFECT:USELESS_INCLUDE [Justified:Low] "AUTOSAR Memory Mapping" */
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/*===========================================================================*
 *  Local Function Definitions
 *===========================================================================*/
