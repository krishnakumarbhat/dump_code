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
 *            Module: NvM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2026-08-19 10:49:41
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

/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (10u)
#define NVM_CFG_MINOR_VERSION    (5u)
#define NVM_CFG_PATCH_VERSION    (2u)

/**********************************************************************************************************************
 * STD TYPE INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switches that are used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_ON)
#define NVM_USE_CONFIG_ID_CALLBACK            (STD_OFF)
#define NVM_CONFIG_BLOCK_LENGTH               (2u)

#define NVM_API_CONFIG_CLASS_1                (1u)
#define NVM_API_CONFIG_CLASS_2                (3u)
#define NVM_API_CONFIG_CLASS_3                (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1u)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for data integrity handling */
#define NVM_DATA_INTEGRITY_INT_BUFFER         (STD_ON)

/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS         (26u)

/* internal buffer size */
#define NVM_INTERNAL_BUFFER_LENGTH            126u

/* internal immediate data buffer size */
/* No block with immediate data buffer handling is configured. The minimal size of the immediate data buffer is one. 
   An array of size zero would lead to undefined behavior. */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER_LENGTH  (1u)

/* version info api switch */
#define NVM_VERSION_INFO_API                  (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API          (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_OFF)

/* switch to enable the pre readall api to be able to split the readall into two phases */
#define NVM_PRE_READALL_API                   (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS            (4u)

/* switch for enabling the job forwading from the application to the memory core */
#define  NVM_JOB_FORWARDING_TO_MEMORY_CORE    (STD_OFF) 

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET                  0x8000u

/* Enabled if at least one block used NvMCalcRamblockCrc and ExplicitSync mechanisms */
#define NVM_CRC_USE_INTERNAL_EXPLICIT_SYNC_BUFFER (STD_OFF)

/* switch for using AUTOSAR 4.4.0 callback interface */
#define NVM_USE_ASR440_CALLBACK_INTERFACE     (STD_OFF)

/* Report development errors */
# define NVM_DEV_ERROR_REPORT (STD_ON)


/* Enabled if at least one block used immediate data */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER  (STD_OFF)

/* returns corresponding DCM BlockId of an original NVRAM Block */
#define NvM_GetDcmBlockId(MyApplBlockId)      ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptorTable_at
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf___MultiBlockRequest (0u) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerAlignment_NvMBlock (2u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerBringup_NvMBlock (3u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerRFE_R1R2_Fault_NvM (4u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe (5u) 
#define NvMConf_NvMBlockDescriptor_SWC_Appl_Faultmgr (6u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM (7u) 
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock (8u) 
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock (9u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 (10u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 (11u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 (12u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 (13u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 (14u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 (15u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 (16u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 (17u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 (18u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 (19u) 
#define NvMConf_NvMBlockDescriptor_SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN (20u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerSensorPos_NvM (21u) 
#define NvMConf_NvMBlockDescriptor_SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter (22u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution (23u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters (24u) 
#define NvMConf_NvMBlockDescriptor_SWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params (25u) 


/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined) */
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_IND13400
#define NVM_PROCESSOR_IND13400
#endif
#ifndef NVM_COMP_LLVMDIAB
#define NVM_COMP_LLVMDIAB
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* define NvM Generation Version */
#define NVM_GENERATION_VERSION                (1u)

/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/* PRQA L:MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.h
 *********************************************************************************************************************/

