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
 *            Module: CanSM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanSM_Cfg.h
 *   Generation Time: 2026-08-12 18:54:35
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

#if !defined (CANSM_CFG_H)
# define CANSM_CFG_H

 /**********************************************************************************************************************
 *  Includes
 **********************************************************************************************************************/

#include "CanSM_Int.h"
#include "Os.h"



 /**********************************************************************************************************************
 *  Precompile Definitions
 **********************************************************************************************************************/


#define CANSM_VERSION_INFO_API                STD_OFF

#define CANSM_BOR_CHECK_LEVEL                 STD_OFF
#define CANSM_BUSOFF_DELAY_FUNCTION           STD_ON
#define CANSM_BUSOFF_END_INDICATION           STD_ON
#define CANSM_CHANGE_BAUDRATE_API             STD_OFF
#define CANSM_SET_BAUDRATE_API                STD_OFF
#define CANSM_ECU_PASSIVE_MODE                STD_OFF
#define CANSM_PREVENT_BUSSLEEP_AT_STARTUP     STD_OFF
#define CANSM_SWIFT_TX_TIMEOUT_RECOVERY       STD_OFF
#define CANSM_EXPANDED_TX_TIMEOUT_RECOVERY    STD_OFF
#define CANSM_EXTENDED_RAM_CHECK              STD_OFF


/* Multi-Partition */
#define CANSM_MULTIPARTITION_ENABLED          STD_OFF

/* Single-Partition */
#define CANSM_SINGLEPARTITION                 0u



/* General Module Defines */
#ifndef CANSM_DEV_ERROR_DETECT
#define CANSM_DEV_ERROR_DETECT STD_OFF
#endif
#ifndef CANSM_DEV_ERROR_REPORT
#define CANSM_DEV_ERROR_REPORT STD_OFF
#endif
#ifndef CANSM_USE_DUMMY_STATEMENT
#define CANSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_DUMMY_STATEMENT
#define CANSM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_DUMMY_STATEMENT_CONST
#define CANSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANSM_ATOMIC_VARIABLE_ACCESS
#define CANSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANSM_PROCESSOR_IND13400
#define CANSM_PROCESSOR_IND13400
#endif
#ifndef CANSM_COMP_LLVMDIAB
#define CANSM_COMP_LLVMDIAB
#endif
#ifndef CANSM_GEN_GENERATOR_MSR
#define CANSM_GEN_GENERATOR_MSR
#endif
#ifndef CANSM_CPUTYPE_BITORDER_LSB2MSB
#define CANSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CANSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_LINKTIME
#define CANSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANSM_CONFIGURATION_VARIANT
#define CANSM_CONFIGURATION_VARIANT CANSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANSM_POSTBUILD_VARIANT_SUPPORT
#define CANSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



 /* \trace SPEC-634 */


# define  CanSM_Dem_ReportErrorEvent(Index, eventStatus )


#define CANSM_CFG_MAJOR_VERSION               (8u)
#define CANSM_CFG_MINOR_VERSION               (1u)


/* CanSM_IsInitialized values */
#define CANSM_PRE_INIT_NOT_CALLED             0x00u
#define CANSM_PRE_INIT_FINISHED               0x01u


#if !defined ( CANSM_LOCAL_INLINE ) /* COV_CANSM_CHECKDEFINE */
# define CANSM_LOCAL_INLINE LOCAL_INLINE
#endif


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCGetRootDataMacros  CanSM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanSM_GetFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetConstantDuplicatedRootDataMacros  CanSM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanSM_GetPCPartitionConfigOfPCConfig()                                                        /**< PartitionConfig is empty */
#define CanSM_GetPartitionIdentifiersOfPCConfig()                                                   CanSM_PartitionIdentifiers  /**< the pointer to CanSM_PartitionIdentifiers */
#define CanSM_GetSizeOfPartitionIdentifiersOfPCConfig()                                             1u  /**< the number of accomplishable value elements in CanSM_PartitionIdentifiers */
#define CanSM_GetChannelConfigOfPCPartitionConfig(partitionIndex)                                   CanSM_ChannelConfig  /**< the pointer to CanSM_ChannelConfig */
#define CanSM_GetChannelVarRecordOfPCPartitionConfig(partitionIndex)                                CanSM_ChannelVarRecord  /**< the pointer to CanSM_ChannelVarRecord */
#define CanSM_GetModeRequestRepetitionMaxOfPCPartitionConfig(partitionIndex)                        10u  /**< getCanSMModeRequestRepetitionMax */
#define CanSM_GetModeRequestRepetitionTimeOfPCPartitionConfig(partitionIndex)                       10u  /**< periond of ModeRequest Repetition */
#define CanSM_GetPartitionInitializationStateOfPCPartitionConfig(partitionIndex)                    (&(CanSM_PartitionInitializationState))  /**< the pointer to CanSM_PartitionInitializationState */
#define CanSM_GetSizeOfChannelConfigOfPCPartitionConfig(partitionIndex)                             2u  /**< the number of accomplishable value elements in CanSM_ChannelConfig */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDuplicatedRootDataMacros  CanSM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define CanSM_GetSizeOfChannelVarRecordOfPCPartitionConfig(partitionIndex)                          CanSM_GetSizeOfChannelConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in CanSM_ChannelVarRecord */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDataMacros  CanSM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanSM_IsBor_Tx_Confirmation_PollingOfChannelConfig(Index, partitionIndex)                     /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_GetControllerIdOfChannelConfig(Index, partitionIndex)                                 (CanSM_GetChannelConfigOfPCPartitionConfig(partitionIndex)[(Index)].ControllerIdOfChannelConfig)
#define CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig(Index, partitionIndex)                    /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsPartial_Network_Wakeup_FilterOfChannelConfig(Index, partitionIndex)                   /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsProdErrorDetect_BusOff_OfChannelConfig(Index, partitionIndex)                         /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_IsProdErrorDetect_ModeRequest_OfChannelConfig(Index, partitionIndex)                    /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_GetTransceiverIdOfChannelConfig(Index, partitionIndex)                                  /**< Deactivateable: 'CanSM_ChannelConfig.TransceiverId' Reason: 'the value of CanSM_TransceiverIdOfChannelConfig is always 'CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG' due to this, the array is deactivated.' */
#define CanSM_IsTransceiver_Channel_SupportOfChannelConfig(Index, partitionIndex)                     /**< Deactivateable: 'CanSM_ChannelConfig.Transceiver_Channel_Support' Reason: 'the value of CanSM_Transceiver_Channel_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_GetChannelVarRecord(Index, partitionIndex)                                            (CanSM_GetChannelVarRecordOfPCPartitionConfig(partitionIndex)[(Index)])
#define CanSM_IsEcuPassiveModePartitionState(partitionIndex)                                          /**< Deactivateable: 'CanSM_EcuPassiveModePartitionState' Reason: 'Only used for passive mode in a multi partition usecase.' */
#define CanSM_GetPartitionSNVOfPartitionIdentifiers(Index)                                          (CanSM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define CanSM_GetPartitionInitializationState(partitionIndex)                                       ((*(CanSM_GetPartitionInitializationStateOfPCPartitionConfig(partitionIndex))))
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetDeduplicatedDataMacros  CanSM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanSM_GetBorCounterL1ToL2OfChannelConfig(Index, partitionIndex)                             5u
#define CanSM_GetBorTimeL1OfChannelConfig(Index, partitionIndex)                                    5u
#define CanSM_GetBorTimeL2OfChannelConfig(Index, partitionIndex)                                    20u
#define CanSM_GetBorTimeTxEnsuredOfChannelConfig(Index, partitionIndex)                             7u
#define CanSM_GetDemEventId_BusOff_OfChannelConfig(Index, partitionIndex)                           0xFFu
#define CanSM_GetDemEventId_ModeRequest_OfChannelConfig(Index, partitionIndex)                      0xFFu
#define CanSM_GetNetworkHandleOfChannelConfig(Index, partitionIndex)                                ((CanSM_NetworkHandleOfChannelConfigType)((((CanSM_NetworkHandleOfChannelConfigType)(Index)) + 1u)))
#define CanSM_IsTrcv_InActive_AtAll_NonPNCannelsOfChannelConfig(Index, partitionIndex)              (((TRUE)) != FALSE)  /**< Config feature which determines if Trvc is active at a Non PN channel */
#define CanSM_GetFinalMagicNumber()                                                                   /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetInitDataHashCode()                                                                   /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_GetModeRequestRepetitionMax(partitionIndex)                                           CanSM_GetModeRequestRepetitionMaxOfPCPartitionConfig(partitionIndex)
#define CanSM_GetModeRequestRepetitionTime(partitionIndex)                                          CanSM_GetModeRequestRepetitionTimeOfPCPartitionConfig(partitionIndex)
#define CanSM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                  ((CanSM_PCPartitionConfigIdxOfPartitionIdentifiersType)((Index)))  /**< the index of the 1:1 relation pointing to CanSM_PCPartitionConfig */
#define CanSM_GetSizeOfChannelConfig(partitionIndex)                                                CanSM_GetSizeOfChannelConfigOfPCPartitionConfig(partitionIndex)
#define CanSM_GetSizeOfChannelVarRecord(partitionIndex)                                             CanSM_GetSizeOfChannelVarRecordOfPCPartitionConfig(partitionIndex)
#define CanSM_GetSizeOfPartitionIdentifiers()                                                       CanSM_GetSizeOfPartitionIdentifiersOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSetDataMacros  CanSM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanSM_SetChannelVarRecord(Index, Value, partitionIndex)                                     CanSM_GetChannelVarRecordOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define CanSM_SetEcuPassiveModePartitionState(Value, partitionIndex)                                  /**< Deactivateable: 'CanSM_EcuPassiveModePartitionState' Reason: 'Only used for passive mode in a multi partition usecase.' */
#define CanSM_SetPartitionInitializationState(Value, partitionIndex)                                (*(CanSM_GetPartitionInitializationStateOfPCPartitionConfig(partitionIndex))) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGetAddressOfDataMacros  CanSM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanSM_GetAddrChannelVarRecord(Index, partitionIndex)                                        (&CanSM_GetChannelVarRecord(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCHasMacros  CanSM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanSM_HasChannelConfig(partitionIndex)                                                      (TRUE != FALSE)
#define CanSM_HasBorCounterL1ToL2OfChannelConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanSM_HasBorTimeL1OfChannelConfig(partitionIndex)                                           (TRUE != FALSE)
#define CanSM_HasBorTimeL2OfChannelConfig(partitionIndex)                                           (TRUE != FALSE)
#define CanSM_HasBorTimeTxEnsuredOfChannelConfig(partitionIndex)                                    (TRUE != FALSE)
#define CanSM_HasBor_Tx_Confirmation_PollingOfChannelConfig(partitionIndex)                           /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasControllerIdOfChannelConfig(partitionIndex)                                        (TRUE != FALSE)
#define CanSM_HasDemEventId_BusOff_OfChannelConfig(partitionIndex)                                  (TRUE != FALSE)
#define CanSM_HasDemEventId_ModeRequest_OfChannelConfig(partitionIndex)                             (TRUE != FALSE)
#define CanSM_HasNetworkHandleOfChannelConfig(partitionIndex)                                       (TRUE != FALSE)
#define CanSM_HasPartial_Network_Trcv_SupportOfChannelConfig(partitionIndex)                          /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasPartial_Network_Wakeup_FilterOfChannelConfig(partitionIndex)                         /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasProdErrorDetect_BusOff_OfChannelConfig(partitionIndex)                               /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasProdErrorDetect_ModeRequest_OfChannelConfig(partitionIndex)                          /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasTransceiverIdOfChannelConfig(partitionIndex)                                         /**< Deactivateable: 'CanSM_ChannelConfig.TransceiverId' Reason: 'the value of CanSM_TransceiverIdOfChannelConfig is always 'CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG' due to this, the array is deactivated.' */
#define CanSM_HasTransceiver_Channel_SupportOfChannelConfig(partitionIndex)                           /**< Deactivateable: 'CanSM_ChannelConfig.Transceiver_Channel_Support' Reason: 'the value of CanSM_Transceiver_Channel_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CanSM_HasTrcv_InActive_AtAll_NonPNCannelsOfChannelConfig(partitionIndex)                    (TRUE != FALSE)
#define CanSM_HasChannelVarRecord(partitionIndex)                                                   (TRUE != FALSE)
#define CanSM_HasEcuPassiveModePartitionState(partitionIndex)                                         /**< Deactivateable: 'CanSM_EcuPassiveModePartitionState' Reason: 'Only used for passive mode in a multi partition usecase.' */
#define CanSM_HasFinalMagicNumber()                                                                   /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasInitDataHashCode()                                                                   /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasModeRequestRepetitionMax(partitionIndex)                                           (TRUE != FALSE)
#define CanSM_HasModeRequestRepetitionTime(partitionIndex)                                          (TRUE != FALSE)
#define CanSM_HasPartitionIdentifiers()                                                             (TRUE != FALSE)
#define CanSM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                       (TRUE != FALSE)
#define CanSM_HasPartitionSNVOfPartitionIdentifiers()                                               (TRUE != FALSE)
#define CanSM_HasPartitionInitializationState(partitionIndex)                                       (TRUE != FALSE)
#define CanSM_HasSizeOfChannelConfig(partitionIndex)                                                (TRUE != FALSE)
#define CanSM_HasSizeOfChannelVarRecord(partitionIndex)                                             (TRUE != FALSE)
#define CanSM_HasSizeOfPartitionIdentifiers()                                                       (TRUE != FALSE)
#define CanSM_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanSM_HasFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CanSM_HasPCPartitionConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanSM_HasPartitionIdentifiersOfPCConfig()                                                   (TRUE != FALSE)
#define CanSM_HasSizeOfPartitionIdentifiersOfPCConfig()                                             (TRUE != FALSE)
#define CanSM_HasPCPartitionConfig()                                                                (TRUE != FALSE)
#define CanSM_HasChannelConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define CanSM_HasChannelVarRecordOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define CanSM_HasModeRequestRepetitionMaxOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define CanSM_HasModeRequestRepetitionTimeOfPCPartitionConfig(partitionIndex)                       (TRUE != FALSE)
#define CanSM_HasPartitionInitializationStateOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define CanSM_HasSizeOfChannelConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define CanSM_HasSizeOfChannelVarRecordOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIncrementDataMacros  CanSM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanSM_IncChannelVarRecord(Index, partitionIndex)                                            CanSM_GetChannelVarRecord(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCDecrementDataMacros  CanSM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanSM_DecChannelVarRecord(Index, partitionIndex)                                            CanSM_GetChannelVarRecord(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCAddDataMacros  CanSM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanSM_AddChannelVarRecord(Index, Value, partitionIndex)                                     CanSM_SetChannelVarRecord(Index, (CanSM_GetChannelVarRecord(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSubstractDataMacros  CanSM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanSM_SubChannelVarRecord(Index, Value, partitionIndex)                                     CanSM_SetChannelVarRecord(Index, (CanSM_GetChannelVarRecord(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCDataSwitches  CanSM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANSM_CHANNELCONFIG                                                                         STD_ON
#define CANSM_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                       STD_ON
#define CANSM_BORTIMEL1OFCHANNELCONFIG                                                              STD_ON
#define CANSM_BORTIMEL2OFCHANNELCONFIG                                                              STD_ON
#define CANSM_BORTIMETXENSUREDOFCHANNELCONFIG                                                       STD_ON
#define CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                            STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Bor_Tx_Confirmation_Polling' Reason: 'the value of CanSM_Bor_Tx_Confirmation_PollingOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_CONTROLLERIDOFCHANNELCONFIG                                                           STD_ON
#define CANSM_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                                     STD_ON
#define CANSM_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                                STD_ON
#define CANSM_NETWORKHANDLEOFCHANNELCONFIG                                                          STD_ON
#define CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                           STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Trcv_Support' Reason: 'the value of CanSM_Partial_Network_Trcv_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                          STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Partial_Network_Wakeup_Filter' Reason: 'the value of CanSM_Partial_Network_Wakeup_FilterOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                                STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_BusOff_' Reason: 'the value of CanSM_ProdErrorDetect_BusOff_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                           STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.ProdErrorDetect_ModeRequest_' Reason: 'the value of CanSM_ProdErrorDetect_ModeRequest_OfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_TRANSCEIVERIDOFCHANNELCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.TransceiverId' Reason: 'the value of CanSM_TransceiverIdOfChannelConfig is always 'CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG' due to this, the array is deactivated.' */
#define CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                            STD_OFF  /**< Deactivateable: 'CanSM_ChannelConfig.Transceiver_Channel_Support' Reason: 'the value of CanSM_Transceiver_Channel_SupportOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANSM_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                       STD_ON
#define CANSM_CHANNELVARRECORD                                                                      STD_ON
#define CANSM_ECUPASSIVEMODEPARTITIONSTATE                                                          STD_OFF  /**< Deactivateable: 'CanSM_EcuPassiveModePartitionState' Reason: 'Only used for passive mode in a multi partition usecase.' */
#define CANSM_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_MODEREQUESTREPETITIONMAX                                                              STD_ON
#define CANSM_MODEREQUESTREPETITIONTIME                                                             STD_ON
#define CANSM_PARTITIONIDENTIFIERS                                                                  STD_ON
#define CANSM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                            STD_ON
#define CANSM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                    STD_ON
#define CANSM_PARTITIONINITIALIZATIONSTATE                                                          STD_ON
#define CANSM_SIZEOFCHANNELCONFIG                                                                   STD_ON
#define CANSM_SIZEOFCHANNELVARRECORD                                                                STD_ON
#define CANSM_SIZEOFPARTITIONIDENTIFIERS                                                            STD_ON
#define CANSM_PCCONFIG                                                                              STD_ON
#define CANSM_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANSM_PCPARTITIONCONFIGOFPCCONFIG                                                           STD_ON
#define CANSM_PARTITIONIDENTIFIERSOFPCCONFIG                                                        STD_ON
#define CANSM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                  STD_ON
#define CANSM_PCPARTITIONCONFIG                                                                     STD_ON
#define CANSM_CHANNELCONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define CANSM_CHANNELVARRECORDOFPCPARTITIONCONFIG                                                   STD_ON
#define CANSM_MODEREQUESTREPETITIONMAXOFPCPARTITIONCONFIG                                           STD_ON
#define CANSM_MODEREQUESTREPETITIONTIMEOFPCPARTITIONCONFIG                                          STD_ON
#define CANSM_PARTITIONINITIALIZATIONSTATEOFPCPARTITIONCONFIG                                       STD_ON
#define CANSM_SIZEOFCHANNELCONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define CANSM_SIZEOFCHANNELVARRECORDOFPCPARTITIONCONFIG                                             STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCNoReferenceDefines  CanSM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANSM_NO_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                    255u
#define CANSM_NO_BORTIMEL1OFCHANNELCONFIG                                                           255u
#define CANSM_NO_BORTIMEL2OFCHANNELCONFIG                                                           255u
#define CANSM_NO_BORTIMETXENSUREDOFCHANNELCONFIG                                                    255u
#define CANSM_NO_CONTROLLERIDOFCHANNELCONFIG                                                        255u
#define CANSM_NO_NETWORKHANDLEOFCHANNELCONFIG                                                       255u
#define CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCEnumDefines  CanSM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANSM_NOT_CALLED_PARTITIONINITIALIZATIONSTATE                                               0x00u
#define CANSM_PRE_INIT_PARTITIONINITIALIZATIONSTATE                                                 0x01u
#define CANSM_RUNNING_PARTITIONINITIALIZATIONSTATE                                                  0x02u
#define CANSM_FINISHED_PARTITIONINITIALIZATIONSTATE                                                 0x03u
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIsReducedToDefineDefines  CanSM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANSM_ISDEF_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                 STD_ON
#define CANSM_ISDEF_BORTIMEL1OFCHANNELCONFIG                                                        STD_ON
#define CANSM_ISDEF_BORTIMEL2OFCHANNELCONFIG                                                        STD_ON
#define CANSM_ISDEF_BORTIMETXENSUREDOFCHANNELCONFIG                                                 STD_ON
#define CANSM_ISDEF_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                      STD_OFF
#define CANSM_ISDEF_CONTROLLERIDOFCHANNELCONFIG                                                     STD_OFF
#define CANSM_ISDEF_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                               STD_ON
#define CANSM_ISDEF_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                          STD_ON
#define CANSM_ISDEF_NETWORKHANDLEOFCHANNELCONFIG                                                    STD_OFF
#define CANSM_ISDEF_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                     STD_OFF
#define CANSM_ISDEF_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                    STD_OFF
#define CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                          STD_OFF
#define CANSM_ISDEF_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                     STD_OFF
#define CANSM_ISDEF_TRANSCEIVERIDOFCHANNELCONFIG                                                    STD_OFF
#define CANSM_ISDEF_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                      STD_OFF
#define CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                 STD_ON
#define CANSM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                      STD_OFF
#define CANSM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                              STD_OFF
#define CANSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF
#define CANSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF
#define CANSM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                     STD_ON
#define CANSM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                  STD_ON
#define CANSM_ISDEF_CHANNELCONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define CANSM_ISDEF_CHANNELVARRECORDOFPCPARTITIONCONFIG                                             STD_ON
#define CANSM_ISDEF_PARTITIONINITIALIZATIONSTATEOFPCPARTITIONCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCEqualsAlwaysToDefines  CanSM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANSM_EQ2_BORCOUNTERL1TOL2OFCHANNELCONFIG                                                   5u
#define CANSM_EQ2_BORTIMEL1OFCHANNELCONFIG                                                          5u
#define CANSM_EQ2_BORTIMEL2OFCHANNELCONFIG                                                          20u
#define CANSM_EQ2_BORTIMETXENSUREDOFCHANNELCONFIG                                                   7u
#define CANSM_EQ2_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG                                        
#define CANSM_EQ2_CONTROLLERIDOFCHANNELCONFIG                                                       
#define CANSM_EQ2_DEMEVENTID_BUSOFF_OFCHANNELCONFIG                                                 0xFFu
#define CANSM_EQ2_DEMEVENTID_MODEREQUEST_OFCHANNELCONFIG                                            0xFFu
#define CANSM_EQ2_NETWORKHANDLEOFCHANNELCONFIG                                                      
#define CANSM_EQ2_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG                                       
#define CANSM_EQ2_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG                                      
#define CANSM_EQ2_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG                                            
#define CANSM_EQ2_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG                                       
#define CANSM_EQ2_TRANSCEIVERIDOFCHANNELCONFIG                                                      
#define CANSM_EQ2_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG                                        
#define CANSM_EQ2_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG                                   TRUE
#define CANSM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                        
#define CANSM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                
#define CANSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                        
#define CANSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                        
#define CANSM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                       CanSM_PCPartitionConfig
#define CANSM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                    CanSM_PartitionIdentifiers
#define CANSM_EQ2_CHANNELCONFIGOFPCPARTITIONCONFIG                                                  CanSM_ChannelConfig
#define CANSM_EQ2_CHANNELVARRECORDOFPCPARTITIONCONFIG                                               CanSM_ChannelVarRecord
#define CANSM_EQ2_PARTITIONINITIALIZATIONSTATEOFPCPARTITIONCONFIG                                   (&(CanSM_PartitionInitializationState))
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSymbolicInitializationPointers  CanSM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanSM_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanSM' */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCInitializationSymbols  CanSM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanSM_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanSM */
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCGeneral  CanSM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANSM_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANSM_FINAL_MAGIC_NUMBER                                                                    0x8C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanSM */
#define CANSM_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanSM' is not configured to be postbuild capable. */
#define CANSM_INIT_DATA                                                                             CANSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANSM_INIT_DATA_HASH_CODE                                                                   337218771  /**< the precompile constant to validate the initialization structure at initialization time of CanSM with a hashcode. The seed value is '0x8C1Eu' */
#define CANSM_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANSM_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer CanSM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCSizeOfTypes  CanSM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for CanSM_SizeOfChannelConfig */
typedef uint8 CanSM_SizeOfChannelConfigType;

/**   \brief  value based type definition for CanSM_SizeOfChannelVarRecord */
typedef uint8 CanSM_SizeOfChannelVarRecordType;

/**   \brief  value based type definition for CanSM_SizeOfPartitionIdentifiers */
typedef uint8 CanSM_SizeOfPartitionIdentifiersType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCIterableTypes  CanSM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanSM_ChannelConfig */
typedef uint8_least CanSM_ChannelConfigIterType;

/**   \brief  type used to iterate CanSM_PartitionIdentifiers */
typedef uint8_least CanSM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate CanSM_PCPartitionConfig */
typedef uint8_least CanSM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCIterableTypesWithSizeRelations  CanSM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate CanSM_ChannelVarRecord */
typedef CanSM_ChannelConfigIterType CanSM_ChannelVarRecordIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCValueTypes  CanSM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanSM_BorCounterL1ToL2OfChannelConfig */
typedef uint8 CanSM_BorCounterL1ToL2OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeL1OfChannelConfig */
typedef uint8 CanSM_BorTimeL1OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeL2OfChannelConfig */
typedef uint8 CanSM_BorTimeL2OfChannelConfigType;

/**   \brief  value based type definition for CanSM_BorTimeTxEnsuredOfChannelConfig */
typedef uint8 CanSM_BorTimeTxEnsuredOfChannelConfigType;

/**   \brief  value based type definition for CanSM_ControllerIdOfChannelConfig */
typedef uint8 CanSM_ControllerIdOfChannelConfigType;

/**   \brief  value based type definition for CanSM_NetworkHandleOfChannelConfig */
typedef uint8 CanSM_NetworkHandleOfChannelConfigType;

/**   \brief  value based type definition for CanSM_Trcv_InActive_AtAll_NonPNCannelsOfChannelConfig */
typedef boolean CanSM_Trcv_InActive_AtAll_NonPNCannelsOfChannelConfigType;

/**   \brief  value based type definition for CanSM_ModeRequestRepetitionMax */
typedef uint8 CanSM_ModeRequestRepetitionMaxType;

/**   \brief  value based type definition for CanSM_ModeRequestRepetitionTime */
typedef uint8 CanSM_ModeRequestRepetitionTimeType;

/**   \brief  value based type definition for CanSM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 CanSM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanSM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 CanSM_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanSM_PartitionInitializationState */
typedef uint8 CanSM_PartitionInitializationStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanSMPCStructTypes  CanSM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanSM_ChannelConfig */
typedef struct sCanSM_ChannelConfigType
{
  CanSM_ControllerIdOfChannelConfigType ControllerIdOfChannelConfig;
} CanSM_ChannelConfigType;

/**   \brief  type used in CanSM_PartitionIdentifiers */
typedef struct sCanSM_PartitionIdentifiersType
{
  CanSM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
} CanSM_PartitionIdentifiersType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCSymbolicStructTypes  CanSM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCUnionIndexAndSymbolTypes  CanSM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCRootPointerTypes  CanSM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanSM_ChannelConfig */
typedef P2CONST(CanSM_ChannelConfigType, TYPEDEF, CANSM_CONST) CanSM_ChannelConfigPtrType;

/**   \brief  type used to point to CanSM_ChannelVarRecord */
typedef P2VAR(CanSM_ChannelVarRecordType, TYPEDEF, CANSM_VAR_NO_INIT) CanSM_ChannelVarRecordPtrType;

/**   \brief  type used to point to CanSM_PartitionIdentifiers */
typedef P2CONST(CanSM_PartitionIdentifiersType, TYPEDEF, CANSM_CONST) CanSM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to CanSM_PartitionInitializationState */
typedef P2VAR(CanSM_PartitionInitializationStateType, TYPEDEF, CANSM_VAR_NO_INIT) CanSM_PartitionInitializationStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCPartitionRootPointer  CanSM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in CanSM_PCPartitionConfig */
typedef struct sCanSM_PCPartitionConfigType
{
  uint8 CanSM_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanSM_PCPartitionConfigType;

/**   \brief  type used to point to CanSM_PCPartitionConfig */
typedef P2CONST(CanSM_PCPartitionConfigType, TYPEDEF, CANSM_CONST) CanSM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanSMPCRootValueTypes  CanSM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanSM_PCConfig */
typedef struct sCanSM_PCConfigType
{
  uint8 CanSM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanSM_PCConfigType;

typedef CanSM_PCConfigType CanSM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



typedef CanSM_PCPartitionConfigIdxOfPartitionIdentifiersType CanSM_PartitionIdxType;

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanSM_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfig
  \details
  Element         Description
  ControllerId
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfig[2];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanSM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanSM_PartitionIdentifiersType, CANSM_CONST) CanSM_PartitionIdentifiers[1];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelVarRecord
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NO_INIT) CanSM_ChannelVarRecord[2];
#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_PartitionInitializationState
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanSM_PartitionInitializationStateType, CANSM_VAR_NO_INIT) CanSM_PartitionInitializationState;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/




#if ( CANSM_USE_INIT_POINTER == STD_ON )
# define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* \trace SPEC-640 */

extern P2CONST( CanSM_ConfigType, CANSM_VAR_NO_INIT, CANSM_CONST ) CanSM_ConfigDataPtr;

# define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* ( CANSM_USE_INIT_POINTER == STD_ON ) */


#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR( uint8, CANSM_VAR_CLEARED ) CanSM_PreInitializationState;

#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */







typedef P2FUNC(void, CANSM_APPL_CODE, CanSM_BusOffDelayFctPtrType) ( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr ); /* PRQA S 0850 */  /* MD_MSR_MacroArgumentEmpty  */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST ( CanSM_BusOffDelayFctPtrType, CANSM_CONST ) CanSM_BusOffDelayFctPtr;

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern FUNC(void, CANSM_APPL_CODE) J1939Nm_GetBusOffDelay( NetworkHandleType  NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr );




typedef P2FUNC(void, CANSM_APPL_CODE, CanSM_BusOffEndIndicationFctPtrType) ( NetworkHandleType  NetworkHandle ); /* PRQA S 0850 */  /* MD_MSR_MacroArgumentEmpty  */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST ( CanSM_BusOffEndIndicationFctPtrType, CANSM_CONST ) CanSM_BusOffEndIndicationFctPtr;

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


extern FUNC(void, CANSM_APPL_CODE) J1939Nm_BusOffEnd( NetworkHandleType  NetworkHandle );




/* -----------------------------------------------------------------------------
   Lcfg Inline Functions
 ----------------------------------------------------------------------------- */




#endif /* CANSM_CFG_H */

