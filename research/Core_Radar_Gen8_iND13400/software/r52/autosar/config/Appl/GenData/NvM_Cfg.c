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
 *              File: NvM_Cfg.c
 *   Generation Time: 2026-08-31 13:04:45
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
 *  MODULE SWITCH
 *********************************************************************************************************************/
/* this switch enables the header file(s) to hide some parts. */
#define NVM_CFG_SOURCE

/* multiple inclusion protection */
#define NVM_H_

/* Required for RTE ROM block definitions */
#define RTE_MICROSAR_PIM_EXPORT

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* This tag will only be replaced, if one or more callbacks via Service Ports had been configured */


/**********************************************************************************************************************
 *  MODULE HEADER INCLUDES
 *********************************************************************************************************************/
/* only includes the public part of config */
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

#include "BswM_NvM.h"

/* include list of the callback definitions */
#include "SWC_Appl_FaultMgr_Cfg.h" 
#include "Dem_Cbk.h" 
#include "SWC_PLT_Appl_NvMHandler.h" 


/**********************************************************************************************************************
 *  VERSION CHECKS
 *********************************************************************************************************************/
#if ((NVM_CFG_MAJOR_VERSION != (10u)) \
        || (NVM_CFG_MINOR_VERSION != (5u)))
# error "Version numbers of NvM_Cfg.c and NvM_Cfg.h are inconsistent!"
#endif

/* include configured file declaring or defining resource (un)locking service(s) */
#include "SchM_NvM.h"

/**********************************************************************************************************************
 *  PUBLIC CONSTANTS
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_16
#include "NvM_MemMap.h"

/* maximum number of bytes to be processed in one crc calculation step */
CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16 = 64u;

/* constant holding Crc queue size value */
CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16 = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

#define NVM_STOP_SEC_CONST_16
#include "NvM_MemMap.h"

/* 8Bit Data section containing the data integrity buffers */
#define NVM_START_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"



#if ((NVM_DATA_INTEGRITY_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerAlignment_NvMBlock_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerBringup_NvMBlock_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_Appl_Faultmgr_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerSensorPos_NvM_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params_Crc[2u]; 


#endif






#define NVM_STOP_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

/* Data section containing the internal buffers. If job forwarding from application to memory core is enabled the buffer must be placed in the shared memory. */
#define NVM_START_SEC_VAR_INTERNAL_BUFFER
#include "NvM_MemMap.h"

#if ((NVM_DATA_INTEGRITY_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON) \
    || (NVM_JOB_FORWARDING_TO_MEMORY_CORE == STD_ON) || (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
/* create the internal buffer of size NVM_INTERNAL_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[NVM_INTERNAL_BUFFER_LENGTH]; /* PRQA S 1533 */ /* MD_NvM_Cfg_8.9_InternalBuffer */
#endif


#define NVM_STOP_SEC_VAR_INTERNAL_BUFFER
#include "NvM_MemMap.h"

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
 

 
/* block descriptor table that holds the static configuration parameters of the RAM, ROM and NVBlocks.
* This table has to be adjusted according to the configuration of the NVManager.
*/

CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS] =
    {
      { /*  MultiBlockRequest  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
        { 0u } /*  Flags  */ , 
        0x0001u /*  NV block Base number (defined by FEE/EA)  */ , 
        0U /*  NvMNvBlockLength  */ , 
        0U /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        0u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        0u /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMConfigBlock  */ 
        (NvM_RamAddressType)&NVM_Config_Ram_Block /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0010u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(NVM_Config_Ram_Block) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(NVM_Config_Ram_Block) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerAlignment_NvMBlock  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Alignment_NvMBlock_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerAlignment_NvMBlock_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0110u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerBringup_NvMBlock  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerBringup_NvMBlock_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0120u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        128u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerRFE_R1R2_Fault_NvM  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_Fault_NvM_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0140u /*  NV block Base number (defined by FEE/EA)  */ , 
        72u /*  NvMNvBlockLength  */ , 
        72u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_FailSafe_ResetReason_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_SWC_PLT_CDD_FailSafe_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerSWC_PLT_CDD_FailSafe_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0170u /*  NV block Base number (defined by FEE/EA)  */ , 
        124u /*  NvMNvBlockLength  */ , 
        124u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_Appl_Faultmgr  */ 
        (NvM_RamAddressType)&SWC_Appl_FaultMgr_NVblock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&SWC_Appl_FaultMgr_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_Appl_Faultmgr_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0150u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(SWC_Appl_FaultMgr_NVblock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(SWC_Appl_FaultMgr_NVblock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_NvM_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerCorrectable_Fault_NvM_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0130u /*  NV block Base number (defined by FEE/EA)  */ , 
        24u /*  NvMNvBlockLength  */ , 
        24u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemAdminDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_AdminData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitAdminData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0020u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemStatusDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_StatusData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitStatusData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock0  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_0 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0030u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock1  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_1 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0040u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock2  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_2 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0050u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock3  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_3 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0060u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock4  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_4 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0070u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock5  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_5 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0080u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock6  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_6 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0090u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock7  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_7 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock8  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_8 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  DemPrimaryDataBlock9  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_9 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_PrimaryEventEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN  */ 
        (NvM_RamAddressType)&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_VIN_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_VIN_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0100u /*  NV block Base number (defined by FEE/EA)  */ , 
        17u /*  NvMNvBlockLength  */ , 
        17u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerSensorPos_NvM  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Sensorpos_PIM_UDS /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_SensorPos_NvM_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerSensorPos_NvM_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        8u /*  NvMNvBlockLength  */ , 
        8u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter  */ 
        (NvM_RamAddressType)&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_AttemptCounter /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_Attemptcounter_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_CMP_PRJ_UDSHandlerSWC_UDSHandler_Attemptcounter_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Manual_Alignment_Execution_Data_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_SWC_Manual_alignment_Execution_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerSWC_Manual_alignment_Execution_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0160u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_SWC_Static_Alignment_Write_Parameters_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerSWC_Static_Alignment_Write_Parameters_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0180u /*  NV block Base number (defined by FEE/EA)  */ , 
        12u /*  NvMNvBlockLength  */ , 
        12u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params  */ 
        (NvM_RamAddressType)&Rte_SWC_PLT_Appl_NvMHandler_VSE_NVM_Params_PIM /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PLT_Appl_NvMHandler_SWC_VSE_NVM_Params_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PLT_Appl_NvMHandlerSWC_VSE_NVM_Params_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  DataIntegrityRecordCompMechanismBuffer (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0190u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_FlexNor /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }
    };

/* Permanent RAM and ROM block length checks - compile time (only available for blocks with enabled length check */

/* PRQA S 3494, 3213, 1755 BlockLengthChecks */ /* MD_NvM_Cfg_14.3, MD_NvM_Cfg_2.4 */

/* How does it work:
 * data length = sizeof(ramBlock - CrcLength 
 *     - CRC internal buffer enabled: CRC length == 0, RAM blocks store only data, CRC is handles internally
 *     - CRC internal buffer disabled: CRC length is the number of CRC bytes, for blocks without CRC the length == 0
 *     - for ROM blocks the CRC does not matter
 * Data length has to be > or < or == to configured NvM block length, depending on configuration (see above). 
 * In case the lengths do not match a bitfield with length -1 will be created and shall cause a compiler error.
 * The compiler error shall mark the line with invalid bitfield (bitfield length == -1) - the line includes all required information:
 *     - Block_ + NvM block name
 *     - length error description
 *     - RAM block name, CRC length and configured NvM block length
 */

typedef unsigned int NvM_LengthCheck;
 
/* Block Length Check and Automatic Block Length enabled: error if sizeof RAM block is greater than the configured block length */
#define SizeOfRamBlockGreaterThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) > (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof RAM block does not match the configured block length */
#define SizeOfRamBlockDoesNotMatchConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled and Strict Length Check disabled: error if the sizeof RAM block is less than the configured block length */
#define SizeOfRamBlockLessThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* RAM block length checks */
struct PermanentRamBlockLengthChecks {
  NvM_LengthCheck Block_SWC_Appl_Faultmgr : SizeOfRamBlockGreaterThanConfiguredLength(SWC_Appl_FaultMgr_NVblock, 0u, 16u);
};

/* Block Length Check and Automatic Block Length enabled: error if sizeof ROM block is less than sizeof RAM block */
#define SizeOfRomBlockLessThanSizeOfRamBlock(romBlock, ramBlock) ((sizeof(romBlock) < sizeof(ramBlock)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof ROM block does not match the configured block length */
#define SizeOfRomBlockDoesNotMatchConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled, Strict Length disabled: error if the sizeof ROM block is less than the configured block length */
#define SizeOfRomBlockLessThanConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* ROM block length checks */
struct PermRomBlockLengthCheck {
  NvM_LengthCheck Block_SWC_Appl_Faultmgr : SizeOfRomBlockLessThanSizeOfRamBlock(SWC_Appl_FaultMgr_DefaultValue, SWC_Appl_FaultMgr_NVblock);
};

/* PRQA L:BlockLengthChecks */

/* Permanent RAM and ROM block length checks - END */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* Job Queue used for normal and immediate prio jobs */
VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**********************************************************************************************************************
*  NvM_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 enter SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void)
{
  /* do what ever was defined to do for locking the resources */
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
*  NvM_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 exit SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void)
{
  /* do what ever was defined to do for unlocking the resources */
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* PRQA L:MemMap */

/* Justification for module specific MISRA deviations:

MD_NvM_Cfg_2.4
Reason: NvM provides compile time block length checks via structures with bitfields with positive or negative length -
        the negative length lead to compiler errors. It is possible to use == or even >= check, if only one is used,
        the other one will never be used. The macros are always available. The created structures will never be used by NvM.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.9_InternalBuffer:
Reason: NvM uses an internal buffer for explicit synchronization, in internal CRC buffer use case and for repair redundant blocks.
        Depending on configuration all, one or even none of the uses is enabled - therefore sometimes the internal buffer is
        used only once.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.11:
Reason: Array of unknown size is used in order to reduce dependencies.
Risk: In case the array size shall be determined it would be incorrect.
Prevention: No prevention.

MD_NvM_Cfg_14.3:
Reason: NvM provides compile time block length checks via bitfields with positive or negative length - the negative length
        lead to compiler errors. With valid configuration (all block length are configured correctly), all checks are false.
Risk: No risk.
Prevention: No prevention. If needed the compile time checks can be disabled via configuration.

 */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.c
 *********************************************************************************************************************/


