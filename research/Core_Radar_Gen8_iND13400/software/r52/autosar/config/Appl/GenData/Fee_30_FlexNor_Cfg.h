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
 *              File: Fee_30_FlexNor_Cfg.h
 *   Generation Time: 2026-08-19 18:11:03
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
#if !defined (FEE_30_FLEXNOR_CFG_H)
#define FEE_30_FLEXNOR_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fee_30_FlexNor_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_CFG_MAJOR_VERSION (4u) 
#define FEE_30_FLEXNOR_CFG_MINOR_VERSION (4u) 
#define FEE_30_FLEXNOR_CFG_PATCH_VERSION (1u) 


#define FEE_30_FLEXNOR_DEV_ERROR_DETECT                           (STD_ON)
#define FEE_30_FLEXNOR_DEV_ERROR_REPORT                           (STD_ON)
#define FEE_30_FLEXNOR_VERSION_INFO_API                           (STD_OFF)

#define FEE_30_FLEXNOR_CFG_POLLING_MODE                           (STD_ON)
#define FEE_30_FLEXNOR_CFG_BLANKCHECK_ENABLED                     (STD_OFF)

#ifndef FEE_USE_DUMMY_STATEMENT
#define FEE_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT
#define FEE_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT_CONST
#define FEE_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FEE_ATOMIC_VARIABLE_ACCESS
#define FEE_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FEE_PROCESSOR_IND13400
#define FEE_PROCESSOR_IND13400
#endif
#ifndef FEE_COMP_LLVMDIAB
#define FEE_COMP_LLVMDIAB
#endif
#ifndef FEE_GEN_GENERATOR_MSR
#define FEE_GEN_GENERATOR_MSR
#endif
#ifndef FEE_CPUTYPE_BITORDER_LSB2MSB
#define FEE_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FEE_CONFIGURATION_VARIANT_PRECOMPILE
#define FEE_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FEE_CONFIGURATION_VARIANT_LINKTIME
#define FEE_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FEE_CONFIGURATION_VARIANT
#define FEE_CONFIGURATION_VARIANT FEE_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FEE_POSTBUILD_VARIANT_SUPPORT
#define FEE_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define FEE_30_FLEXNOR_CONFIGURED_PARTITIONS                      (0x01u)
#define FEE_30_FLEXNOR_MAX_CONFIGURED_SECTORS                     (0x02u)

#define FEE_30_FLEXNOR_SECURELAYOUT_ENABLED                       (STD_ON)
#define FEE_30_FLEXNOR_SLIMLAYOUT_ENABLED                         (STD_OFF)

#define FEE_30_FLEXNOR_LOOKUPTABLE_COMPATIBILITY_MODE             (STD_ON)

#define FEE_30_FLEXNOR_REPORT_EXCEPTION_ENABLED                   (STD_OFF)

#define FEE_30_FLEXNOR_REPORT_DEBUG_NOTIFICATIONS_ENABLED         (STD_OFF)

#define FEE_30_FLEXNOR_INTERNALBUFFER_SIZE                        (0x0400u)

#define FEE_30_FLEXNOR_LUTBLOCKID                                 (0x0001u)

/* Block aliases */
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration                                               (16u) 
#define FeeConf_FeeBlockConfiguration_FeeLookupTableBlock_FeePartitionConfiguration                       (224u) 
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_01                                            (17u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerAlignment_NvMBlock                        (272u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerRFE_R1R2_Fault_NvM                        (320u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe                      (368u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerBringup_NvMBlock                          (288u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_Appl_Faultmgr                         (336u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM                     (304u) 
#define FeeConf_FeeBlockConfiguration_FeeDemAdminDataBlock                                                (32u) 
#define FeeConf_FeeBlockConfiguration_FeeDemStatusDataBlock                                               (208u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock0                                             (48u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN                         (256u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSensorPos_NvM                             (416u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSensorPos_NvM_01                          (417u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock1                                             (64u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock2                                             (80u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock3                                             (96u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock4                                             (112u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock5                                             (128u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock6                                             (144u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock7                                             (160u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock8                                             (176u) 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock9                                             (192u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter              (240u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution            (352u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters     (384u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params                        (400u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution_01         (353u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters_01  (385u) 
#define FeeConf_FeeBlockConfiguration_FeeSWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM_01                  (305u) 


# define FEE_30_FLEXNOR_NVM_POLLING_MODE                                (STD_ON)

# if (FEE_30_FLEXNOR_NVM_POLLING_MODE == STD_OFF)

#  define Fee_30_FlexNor_NvMJobEndNotification()                        ()
#  define Fee_30_FlexNor_NvMJobErrorNotification()                      ()
# endif

# define FEE_30_FLEXNOR_MEMORY_VARIANT_FLS    (0u)
# define FEE_30_FLEXNOR_MEMORY_VARIANT_MEMACC (1u)

# define FEE_30_FLEXNOR_MEMORY_VARIANT FEE_30_FLEXNOR_MEMORY_VARIANT_FLS

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Block Config Type */
typedef struct{
    Fee_30_FlexNor_BlockIdType Id;
    Fee_30_FlexNor_BlockNumberType Number;
    Fee_30_FlexNor_LengthType Length;
    boolean HasImmediateData;
} Fee_30_FlexNor_BlockConfigType;

typedef P2VAR(Fee_30_FlexNor_BlockConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_BlockConfigPtrType;
typedef P2CONST(Fee_30_FlexNor_BlockConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstBlockConfigPtrType;

/* Sector Config Type */
typedef struct
{
    Fee_30_FlexNor_AddressType StartAddress;
    Fee_30_FlexNor_LengthType Length;
}Fee_30_FlexNor_SectorConfigType;

typedef P2VAR(Fee_30_FlexNor_SectorConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SectorConfigPtrType;
typedef P2CONST(Fee_30_FlexNor_SectorConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstSectorConfigPtrType;

/* Partition Config Type */
typedef struct{
    uint8 PartitionId;
    Fee_30_FlexNor_LayoutOptionType Layout;
    boolean BlankCheckRequired;
    uint16 PageAlignment;
    uint16 ReadAlignment;
    uint16 InterferenceFreeAlignment;
    uint8 ErasedValue;

    Fee_30_FlexNor_ConstSectorConfigPtrType Sectors;
    uint8 SectorCount;

    Fee_30_FlexNor_ConstBlockConfigPtrType Blocks;
    uint32 BlockCount;

    Fee_30_FlexNor_ChunkLocationPtrType LookupTable;
    Fee_30_FlexNor_FlagContainerPtrType ChunkReallocationFlags;
        
    uint32 LookupTableSize;
    uint32 TotalConfiguredPayloadSize;
    Fee_30_FlexNor_EraseCycleCounterType MaximalEraseCycles;
} Fee_30_FlexNor_PartitionConfigType;

typedef CONST(Fee_30_FlexNor_PartitionConfigType, AUTOMATIC) Fee_30_FlexNor_ConstPartitionConfigType;
typedef P2VAR(Fee_30_FlexNor_PartitionConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_PartitionConfigPtrType;
typedef P2CONST(Fee_30_FlexNor_PartitionConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstPartitionConfigPtrType;

/* FEE Config Type */
typedef struct{
	boolean BootloaderModeEnabled;
    Fee_30_FlexNor_ConstPartitionConfigPtrType Partitions;
    uint8 PartitionCount;
} Fee_30_FlexNor_ConfigType;

typedef P2CONST(Fee_30_FlexNor_ConfigType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_ConstConfigPtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Fee_30_FlexNor_ConfigType, AUTOMATIC) Fee_30_FlexNor_Config;

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern Fee_30_FlexNor_DataType Fee_30_FlexNor_InternalBuffer[FEE_30_FLEXNOR_INTERNALBUFFER_SIZE];

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
#include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* FEE_30_FLEXNOR_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Fee_30_FlexNor_Cfg.h
**********************************************************************************************************************/


 
