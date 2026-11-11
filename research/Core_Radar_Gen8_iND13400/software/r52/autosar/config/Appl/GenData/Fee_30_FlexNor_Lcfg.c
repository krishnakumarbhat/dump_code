/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Fee_30_FlexNor
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_30_FlexNor_Lcfg.c
 *   Generation Time: 2026-08-31 14:31:29
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


#define FEE_30_FLEXNOR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
 
#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTableSize  (32u) 

#define FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTableFlagsSize  (4u) 


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_ChunkLocationType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTable[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTableSize];

FEE_30_FLEXNOR_LOCAL VAR(Fee_30_FlexNor_FlagContainerType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_ChunkReallocationFlags[FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTableFlagsSize];

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_Blocks[31u] = {
  { /*  FeeBlockConfiguration  */ 
    0x0003u /*  Id  */ , 
    0x0010u /*  Number  */ , 
    0x0004u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeLookupTableBlock_FeePartitionConfiguration  */ 
    0x0001u /*  Id  */ , 
    0x00E0u /*  Number  */ , 
    0x0080u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeBlockConfiguration_01  */ 
    0x0004u /*  Id  */ , 
    0x0011u /*  Number  */ , 
    0x0004u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerAlignment_NvMBlock  */ 
    0x0005u /*  Id  */ , 
    0x0110u /*  Number  */ , 
    0x0042u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerRFE_R1R2_Fault_NvM  */ 
    0x0006u /*  Id  */ , 
    0x0140u /*  Number  */ , 
    0x0048u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe  */ 
    0x0007u /*  Id  */ , 
    0x0170u /*  Number  */ , 
    0x007Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerBringup_NvMBlock  */ 
    0x0008u /*  Id  */ , 
    0x0120u /*  Number  */ , 
    0x0042u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_Appl_Faultmgr  */ 
    0x0009u /*  Id  */ , 
    0x0150u /*  Number  */ , 
    0x0014u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM  */ 
    0x000Au /*  Id  */ , 
    0x0130u /*  Number  */ , 
    0x001Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemAdminDataBlock  */ 
    0x000Bu /*  Id  */ , 
    0x0020u /*  Number  */ , 
    0x000Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemStatusDataBlock  */ 
    0x000Cu /*  Id  */ , 
    0x00D0u /*  Number  */ , 
    0x0048u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock0  */ 
    0x000Du /*  Id  */ , 
    0x0030u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN  */ 
    0x0017u /*  Id  */ , 
    0x0100u /*  Number  */ , 
    0x0013u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSensorPos_NvM  */ 
    0x0018u /*  Id  */ , 
    0x01A0u /*  Number  */ , 
    0x000Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSensorPos_NvM_01  */ 
    0x0002u /*  Id  */ , 
    0x01A1u /*  Number  */ , 
    0x000Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock1  */ 
    0x000Eu /*  Id  */ , 
    0x0040u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock2  */ 
    0x000Fu /*  Id  */ , 
    0x0050u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock3  */ 
    0x0010u /*  Id  */ , 
    0x0060u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock4  */ 
    0x0011u /*  Id  */ , 
    0x0070u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock5  */ 
    0x0012u /*  Id  */ , 
    0x0080u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock6  */ 
    0x0013u /*  Id  */ , 
    0x0090u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock7  */ 
    0x0014u /*  Id  */ , 
    0x00A0u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock8  */ 
    0x0015u /*  Id  */ , 
    0x00B0u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeDemPrimaryDataBlock9  */ 
    0x0016u /*  Id  */ , 
    0x00C0u /*  Number  */ , 
    0x001Cu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter  */ 
    0x0019u /*  Id  */ , 
    0x00F0u /*  Number  */ , 
    0x0004u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution  */ 
    0x001Au /*  Id  */ , 
    0x0160u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters  */ 
    0x001Bu /*  Id  */ , 
    0x0180u /*  Number  */ , 
    0x000Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params  */ 
    0x001Cu /*  Id  */ , 
    0x0190u /*  Number  */ , 
    0x0016u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution_01  */ 
    0x001Du /*  Id  */ , 
    0x0161u /*  Number  */ , 
    0x0012u /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters_01  */ 
    0x001Eu /*  Id  */ , 
    0x0181u /*  Number  */ , 
    0x000Eu /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }, 
  { /*  FeeSWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM_01  */ 
    0x001Fu /*  Id  */ , 
    0x0131u /*  Number  */ , 
    0x001Au /*  Length  */ , 
    FALSE /*  HasImmediateData  */ 
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC) FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_Sectors[2u] = {
  { /*  FeeSectorConfiguration  */ 
    0x003C0000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00020000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }, 
  { /*  FeeSectorConfiguration_1  */ 
    0x003E0000u /*  StartAddress  */  /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */, 
    0x00020000u /*  Length  */        /* PRQA S 1257 */ /* MD_Fee_30_FlexNor_IntegerSuffixedWithLOrLL */
  }
};

FEE_30_FLEXNOR_LOCAL CONST(Fee_30_FlexNor_PartitionConfigType, AUTOMATIC) Fee_30_FlexNor_PartitionConfig[FEE_30_FLEXNOR_CONFIGURED_PARTITIONS] = 
{
  { /*  FeePartitionConfiguration  */ 
    0u /*  PartitionId  */ , 
    FEE_30_FLEXNOR_SECURELAYOUT /*  Layout  */ , 
    FALSE /*  BlankCheckRequired  */ , 
    256u /*  PageAlignment  */ , 
    1u /*  ReadAlignment  */ , 
    256u /*  InterferenceFreeAlignment  */ , 
    0xFFu /*  ErasedValue  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_Sectors /*  Sectors  */ , 
    2u /*  SectorCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_Blocks /*  Blocks  */ , 
    31u /*  BlockCount  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTable /*  LookupTable  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_ChunkReallocationFlags /*  ChunkReallocationFlags  */ , 
    FeeConf_FeePartitionConfiguration_FeePartitionConfiguration_LookupTableSize /*  LookupTableSize  */ , 
    0x00000407u /*  TotalConfiguredPayloadSize  */ , 
    0x00010000u /*  MaximalEraseCycles  */ 
  }
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Fee_30_FlexNor_ConfigType, AUTOMATIC) Fee_30_FlexNor_Config = {
    FALSE, /*  BootloaderModeEnabled  */
    Fee_30_FlexNor_PartitionConfig,
    FEE_30_FLEXNOR_CONFIGURED_PARTITIONS
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Fee_30_FlexNor_DataType Fee_30_FlexNor_InternalBuffer[FEE_30_FLEXNOR_INTERNALBUFFER_SIZE];

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  END OF FILE: Fee_30_FlexNor_Lcfg.c
**********************************************************************************************************************/


 
