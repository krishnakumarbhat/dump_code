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
 *            Module: SomeIpTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SomeIpTp_Lcfg.h
 *   Generation Time: 2026-08-27 14:12:14
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

#if !defined (SOMEIPTP_LCFG_H)
# define SOMEIPTP_LCFG_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "SomeIpTp_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SomeIpTpLTDataSwitches  SomeIpTp Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SOMEIPTP_LTCONFIG                                                                           STD_OFF  /**< Deactivateable: 'SomeIpTp_LTConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  SomeIpTp_TXNSdu
**********************************************************************************************************************/
/** 
  \var    SomeIpTp_TXNSdu
  \brief  List of TX NSDUs
  \details
  Element         Description
  LowerLayerId    SNV to the PDU referenced by the lower layer
  UpperLayerId    SNV to the PDU referenced by the upper layer
*/ 
#define SOMEIPTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SomeIpTp_TXNSduType, SOMEIPTP_CONST) SomeIpTp_TXNSdu[1];
#define SOMEIPTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxQueueElement
**********************************************************************************************************************/
#define SOMEIPTP_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SomeIpTp_TxQueueElementType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxQueueElement[1];
#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxShortHeaders
**********************************************************************************************************************/
#define SOMEIPTP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SomeIpTp_TxShortHeadersUType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxShortHeaders;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxState
**********************************************************************************************************************/
/** 
  \var    SomeIpTp_TxState
  \brief  TX NSDU Info
  \details
  Element          Description
  Offset           Offset of the previous segment transmitted
  DataIndex        Index within the message
  DataLength       Length of the complete frame
  Metadata         Metadata of the active transmission.
  NextSegmentDL    size of the next segmented PDU
  Timer            Separation time/Tx confirmation timeout timer of the SDU
  Segmented        Flag indicating if the active transmission is segmented.
  Status           State of the SDU
*/ 
#define SOMEIPTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SomeIpTp_TxStateUType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  SomeIpTpPCGetConstantDuplicatedRootDataMacros  SomeIpTp Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define SomeIpTp_GetChannelOfPCConfig()                                                             SomeIpTp_Channel  /**< the pointer to SomeIpTp_Channel */
#define SomeIpTp_GetSizeOfChannelOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in SomeIpTp_Channel */
#define SomeIpTp_GetSizeOfTXNSduOfPCConfig()                                                        1u  /**< the number of accomplishable value elements in SomeIpTp_TXNSdu */
#define SomeIpTp_GetSizeOfTxQueueElementOfPCConfig()                                                1u  /**< the number of accomplishable value elements in SomeIpTp_TxQueueElement */
#define SomeIpTp_GetSizeOfTxShortHeadersOfPCConfig()                                                8u  /**< the number of accomplishable value elements in SomeIpTp_TxShortHeaders */
#define SomeIpTp_GetSizeOfTxStateOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in SomeIpTp_TxState */
#define SomeIpTp_GetTXNSduOfPCConfig()                                                              SomeIpTp_TXNSdu  /**< the pointer to SomeIpTp_TXNSdu */
#define SomeIpTp_GetTxQueueElementOfPCConfig()                                                      SomeIpTp_TxQueueElement  /**< the pointer to SomeIpTp_TxQueueElement */
#define SomeIpTp_GetTxShortHeadersOfPCConfig()                                                      SomeIpTp_TxShortHeaders.raw  /**< the pointer to SomeIpTp_TxShortHeaders */
#define SomeIpTp_GetTxStateOfPCConfig()                                                             SomeIpTp_TxState.raw  /**< the pointer to SomeIpTp_TxState */
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCGetDataMacros  SomeIpTp Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define SomeIpTp_GetLowerLayerIdOfTXNSdu(Index)                                                     (SomeIpTp_GetTXNSduOfPCConfig()[(Index)].LowerLayerIdOfTXNSdu)
#define SomeIpTp_GetUpperLayerIdOfTXNSdu(Index)                                                     (SomeIpTp_GetTXNSduOfPCConfig()[(Index)].UpperLayerIdOfTXNSdu)
#define SomeIpTp_GetTxQueueElement(Index)                                                           (SomeIpTp_GetTxQueueElementOfPCConfig()[(Index)])
#define SomeIpTp_GetTxShortHeaders(Index)                                                           (SomeIpTp_GetTxShortHeadersOfPCConfig()[(Index)])
#define SomeIpTp_GetDataIndexOfTxState(Index)                                                       (SomeIpTp_GetTxStateOfPCConfig()[(Index)].DataIndexOfTxState)
#define SomeIpTp_GetDataLengthOfTxState(Index)                                                      (SomeIpTp_GetTxStateOfPCConfig()[(Index)].DataLengthOfTxState)
#define SomeIpTp_GetMetadataOfTxState(Index)                                                        (SomeIpTp_GetTxStateOfPCConfig()[(Index)].MetadataOfTxState)
#define SomeIpTp_GetNextSegmentDLOfTxState(Index)                                                   (SomeIpTp_GetTxStateOfPCConfig()[(Index)].NextSegmentDLOfTxState)
#define SomeIpTp_GetOffsetOfTxState(Index)                                                          (SomeIpTp_GetTxStateOfPCConfig()[(Index)].OffsetOfTxState)
#define SomeIpTp_IsSegmentedOfTxState(Index)                                                        ((SomeIpTp_GetTxStateOfPCConfig()[(Index)].SegmentedOfTxState) != FALSE)
#define SomeIpTp_GetStatusOfTxState(Index)                                                          (SomeIpTp_GetTxStateOfPCConfig()[(Index)].StatusOfTxState)
#define SomeIpTp_GetTimerOfTxState(Index)                                                           (SomeIpTp_GetTxStateOfPCConfig()[(Index)].TimerOfTxState)
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCGetDeduplicatedDataMacros  SomeIpTp Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define SomeIpTp_GetNPduSeparationTimeOfChannel(Index)                                              ((SomeIpTp_NPduSeparationTimeOfChannelType)((Index)))  /**< DefinitionRef: /MICROSAR/SomeIpTp/SomeIpTpChannel/SomeIpTpNPduSeparationTime */
#define SomeIpTp_GetNumOfRxNSdusOfChannel(Index)                                                    ((SomeIpTp_NumOfRxNSdusOfChannelType)((Index)))  /**< Number of RX NSdus mapped to this channel */
#define SomeIpTp_GetNumOfTxNSdusOfChannel(Index)                                                    ((SomeIpTp_NumOfTxNSdusOfChannelType)((((SomeIpTp_NumOfTxNSdusOfChannelType)(Index)) + 1u)))  /**< Number of TX NSdus mapped to this channel */
#define SomeIpTp_GetRxTimeoutTimeOfChannel(Index)                                                   ((SomeIpTp_RxTimeoutTimeOfChannelType)((((SomeIpTp_RxTimeoutTimeOfChannelType)(Index)) + 100u)))  /**< DefinitionRef: /MICROSAR/SomeIpTp/SomeIpTpChannel/SomeIpTpTxConfTimeoutTime */
#define SomeIpTp_GetTxConfTimeoutTimeOfChannel(Index)                                               ((SomeIpTp_TxConfTimeoutTimeOfChannelType)((((SomeIpTp_TxConfTimeoutTimeOfChannelType)(Index)) + 100u)))
#define SomeIpTp_GetSizeOfChannel()                                                                 SomeIpTp_GetSizeOfChannelOfPCConfig()
#define SomeIpTp_GetSizeOfTXNSdu()                                                                  SomeIpTp_GetSizeOfTXNSduOfPCConfig()
#define SomeIpTp_GetSizeOfTxQueueElement()                                                          SomeIpTp_GetSizeOfTxQueueElementOfPCConfig()
#define SomeIpTp_GetSizeOfTxShortHeaders()                                                          SomeIpTp_GetSizeOfTxShortHeadersOfPCConfig()
#define SomeIpTp_GetSizeOfTxState()                                                                 SomeIpTp_GetSizeOfTxStateOfPCConfig()
#define SomeIpTp_GetChannelIdxOfTXNSdu(Index)                                                       ((SomeIpTp_ChannelIdxOfTXNSduType)((Index)))  /**< the index of the 1:1 relation pointing to SomeIpTp_Channel */
#define SomeIpTp_GetMaxTxSFPayloadOfTXNSdu(Index)                                                   ((SomeIpTp_MaxTxSFPayloadOfTXNSduType)((((SomeIpTp_MaxTxSFPayloadOfTXNSduType)(Index)) + 1404u)))
#define SomeIpTp_GetTxBurstSizeOfTXNSdu(Index)                                                      ((SomeIpTp_TxBurstSizeOfTXNSduType)((((SomeIpTp_TxBurstSizeOfTXNSduType)(Index)) + 8u)))  /**< DefinitionRef: /MICROSAR/SomeIpTp/SomeIpTpChannel/SomeIpTpTxNSdu/SomeIpTpTxBurstSize */
#define SomeIpTp_GetTxNPduHandleIdOfTXNSdu(Index)                                                   ((SomeIpTp_TxNPduHandleIdOfTXNSduType)((Index)))  /**< DefinitionRef: /MICROSAR/SomeIpTp/SomeIpTpChannel/SomeIpTpTxNSdu/SomeIpTpTxNPdu/SomeIpTpTxNPduHandleId */
#define SomeIpTp_GetTxNPduLengthOfTXNSdu(Index)                                                     ((SomeIpTp_TxNPduLengthOfTXNSduType)((((SomeIpTp_TxNPduLengthOfTXNSduType)(Index)) + 1404u)))
#define SomeIpTp_GetTxNSduHandleIdOfTXNSdu(Index)                                                   ((SomeIpTp_TxNSduHandleIdOfTXNSduType)((Index)))  /**< Possible maximum size of each segment */
#define SomeIpTp_GetTxShortHeadersEndIdxOfTXNSdu(Index)                                             ((SomeIpTp_TxShortHeadersEndIdxOfTXNSduType)((((SomeIpTp_TxShortHeadersEndIdxOfTXNSduType)(Index)) + 8u)))  /**< the end index of the 1:n relation pointing to SomeIpTp_TxShortHeaders */
#define SomeIpTp_GetTxShortHeadersStartIdxOfTXNSdu(Index)                                           ((SomeIpTp_TxShortHeadersStartIdxOfTXNSduType)((Index)))  /**< the start index of the 1:n relation pointing to SomeIpTp_TxShortHeaders */
#define SomeIpTp_GetTxStateIdxOfTXNSdu(Index)                                                       ((SomeIpTp_TxStateIdxOfTXNSduType)((Index)))  /**< the index of the 1:1 relation pointing to SomeIpTp_TxState */
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCSetDataMacros  SomeIpTp Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define SomeIpTp_SetTxQueueElement(Index, Value)                                                    SomeIpTp_GetTxQueueElementOfPCConfig()[(Index)] = (Value)
#define SomeIpTp_SetTxShortHeaders(Index, Value)                                                    SomeIpTp_GetTxShortHeadersOfPCConfig()[(Index)] = (Value)
#define SomeIpTp_SetDataIndexOfTxState(Index, Value)                                                SomeIpTp_GetTxStateOfPCConfig()[(Index)].DataIndexOfTxState = (Value)
#define SomeIpTp_SetDataLengthOfTxState(Index, Value)                                               SomeIpTp_GetTxStateOfPCConfig()[(Index)].DataLengthOfTxState = (Value)
#define SomeIpTp_SetMetadataOfTxState(Index, Value)                                                 SomeIpTp_GetTxStateOfPCConfig()[(Index)].MetadataOfTxState = (Value)
#define SomeIpTp_SetNextSegmentDLOfTxState(Index, Value)                                            SomeIpTp_GetTxStateOfPCConfig()[(Index)].NextSegmentDLOfTxState = (Value)
#define SomeIpTp_SetOffsetOfTxState(Index, Value)                                                   SomeIpTp_GetTxStateOfPCConfig()[(Index)].OffsetOfTxState = (Value)
#define SomeIpTp_SetSegmentedOfTxState(Index, Value)                                                SomeIpTp_GetTxStateOfPCConfig()[(Index)].SegmentedOfTxState = (Value)
#define SomeIpTp_SetStatusOfTxState(Index, Value)                                                   SomeIpTp_GetTxStateOfPCConfig()[(Index)].StatusOfTxState = (Value)
#define SomeIpTp_SetTimerOfTxState(Index, Value)                                                    SomeIpTp_GetTxStateOfPCConfig()[(Index)].TimerOfTxState = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCHasMacros  SomeIpTp Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define SomeIpTp_HasChannel()                                                                       (TRUE != FALSE)
#define SomeIpTp_HasNPduSeparationTimeOfChannel()                                                   (TRUE != FALSE)
#define SomeIpTp_HasNumOfRxNSdusOfChannel()                                                         (TRUE != FALSE)
#define SomeIpTp_HasNumOfTxNSdusOfChannel()                                                         (TRUE != FALSE)
#define SomeIpTp_HasRxTimeoutTimeOfChannel()                                                        (TRUE != FALSE)
#define SomeIpTp_HasTxConfTimeoutTimeOfChannel()                                                    (TRUE != FALSE)
#define SomeIpTp_HasSizeOfChannel()                                                                 (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTXNSdu()                                                                  (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxQueueElement()                                                          (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxShortHeaders()                                                          (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxState()                                                                 (TRUE != FALSE)
#define SomeIpTp_HasTXNSdu()                                                                        (TRUE != FALSE)
#define SomeIpTp_HasChannelIdxOfTXNSdu()                                                            (TRUE != FALSE)
#define SomeIpTp_HasLowerLayerIdOfTXNSdu()                                                          (TRUE != FALSE)
#define SomeIpTp_HasMaxTxSFPayloadOfTXNSdu()                                                        (TRUE != FALSE)
#define SomeIpTp_HasTxBurstSizeOfTXNSdu()                                                           (TRUE != FALSE)
#define SomeIpTp_HasTxNPduHandleIdOfTXNSdu()                                                        (TRUE != FALSE)
#define SomeIpTp_HasTxNPduLengthOfTXNSdu()                                                          (TRUE != FALSE)
#define SomeIpTp_HasTxNSduHandleIdOfTXNSdu()                                                        (TRUE != FALSE)
#define SomeIpTp_HasTxShortHeadersEndIdxOfTXNSdu()                                                  (TRUE != FALSE)
#define SomeIpTp_HasTxShortHeadersStartIdxOfTXNSdu()                                                (TRUE != FALSE)
#define SomeIpTp_HasTxStateIdxOfTXNSdu()                                                            (TRUE != FALSE)
#define SomeIpTp_HasUpperLayerIdOfTXNSdu()                                                          (TRUE != FALSE)
#define SomeIpTp_HasTxQueueElement()                                                                (TRUE != FALSE)
#define SomeIpTp_HasTxShortHeaders()                                                                (TRUE != FALSE)
#define SomeIpTp_HasTxState()                                                                       (TRUE != FALSE)
#define SomeIpTp_HasDataIndexOfTxState()                                                            (TRUE != FALSE)
#define SomeIpTp_HasDataLengthOfTxState()                                                           (TRUE != FALSE)
#define SomeIpTp_HasMetadataOfTxState()                                                             (TRUE != FALSE)
#define SomeIpTp_HasNextSegmentDLOfTxState()                                                        (TRUE != FALSE)
#define SomeIpTp_HasOffsetOfTxState()                                                               (TRUE != FALSE)
#define SomeIpTp_HasSegmentedOfTxState()                                                            (TRUE != FALSE)
#define SomeIpTp_HasStatusOfTxState()                                                               (TRUE != FALSE)
#define SomeIpTp_HasTimerOfTxState()                                                                (TRUE != FALSE)
#define SomeIpTp_HasPCConfig()                                                                      (TRUE != FALSE)
#define SomeIpTp_HasChannelOfPCConfig()                                                             (TRUE != FALSE)
#define SomeIpTp_HasSizeOfChannelOfPCConfig()                                                       (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTXNSduOfPCConfig()                                                        (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxQueueElementOfPCConfig()                                                (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxShortHeadersOfPCConfig()                                                (TRUE != FALSE)
#define SomeIpTp_HasSizeOfTxStateOfPCConfig()                                                       (TRUE != FALSE)
#define SomeIpTp_HasTXNSduOfPCConfig()                                                              (TRUE != FALSE)
#define SomeIpTp_HasTxQueueElementOfPCConfig()                                                      (TRUE != FALSE)
#define SomeIpTp_HasTxShortHeadersOfPCConfig()                                                      (TRUE != FALSE)
#define SomeIpTp_HasTxStateOfPCConfig()                                                             (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCIncrementDataMacros  SomeIpTp Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define SomeIpTp_IncTxQueueElement(Index)                                                           SomeIpTp_GetTxQueueElement(Index)++
#define SomeIpTp_IncTxShortHeaders(Index)                                                           SomeIpTp_GetTxShortHeaders(Index)++
#define SomeIpTp_IncDataIndexOfTxState(Index)                                                       SomeIpTp_GetDataIndexOfTxState(Index)++
#define SomeIpTp_IncDataLengthOfTxState(Index)                                                      SomeIpTp_GetDataLengthOfTxState(Index)++
#define SomeIpTp_IncMetadataOfTxState(Index)                                                        SomeIpTp_GetMetadataOfTxState(Index)++
#define SomeIpTp_IncNextSegmentDLOfTxState(Index)                                                   SomeIpTp_GetNextSegmentDLOfTxState(Index)++
#define SomeIpTp_IncOffsetOfTxState(Index)                                                          SomeIpTp_GetOffsetOfTxState(Index)++
#define SomeIpTp_IncStatusOfTxState(Index)                                                          SomeIpTp_GetStatusOfTxState(Index)++
#define SomeIpTp_IncTimerOfTxState(Index)                                                           SomeIpTp_GetTimerOfTxState(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCDecrementDataMacros  SomeIpTp Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define SomeIpTp_DecTxQueueElement(Index)                                                           SomeIpTp_GetTxQueueElement(Index)--
#define SomeIpTp_DecTxShortHeaders(Index)                                                           SomeIpTp_GetTxShortHeaders(Index)--
#define SomeIpTp_DecDataIndexOfTxState(Index)                                                       SomeIpTp_GetDataIndexOfTxState(Index)--
#define SomeIpTp_DecDataLengthOfTxState(Index)                                                      SomeIpTp_GetDataLengthOfTxState(Index)--
#define SomeIpTp_DecMetadataOfTxState(Index)                                                        SomeIpTp_GetMetadataOfTxState(Index)--
#define SomeIpTp_DecNextSegmentDLOfTxState(Index)                                                   SomeIpTp_GetNextSegmentDLOfTxState(Index)--
#define SomeIpTp_DecOffsetOfTxState(Index)                                                          SomeIpTp_GetOffsetOfTxState(Index)--
#define SomeIpTp_DecStatusOfTxState(Index)                                                          SomeIpTp_GetStatusOfTxState(Index)--
#define SomeIpTp_DecTimerOfTxState(Index)                                                           SomeIpTp_GetTimerOfTxState(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCAddDataMacros  SomeIpTp Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define SomeIpTp_AddTxQueueElement(Index, Value)                                                    SomeIpTp_SetTxQueueElement(Index, (SomeIpTp_GetTxQueueElement(Index) + Value))
#define SomeIpTp_AddTxShortHeaders(Index, Value)                                                    SomeIpTp_SetTxShortHeaders(Index, (SomeIpTp_GetTxShortHeaders(Index) + Value))
#define SomeIpTp_AddDataIndexOfTxState(Index, Value)                                                SomeIpTp_SetDataIndexOfTxState(Index, (SomeIpTp_GetDataIndexOfTxState(Index) + Value))
#define SomeIpTp_AddDataLengthOfTxState(Index, Value)                                               SomeIpTp_SetDataLengthOfTxState(Index, (SomeIpTp_GetDataLengthOfTxState(Index) + Value))
#define SomeIpTp_AddMetadataOfTxState(Index, Value)                                                 SomeIpTp_SetMetadataOfTxState(Index, (SomeIpTp_GetMetadataOfTxState(Index) + Value))
#define SomeIpTp_AddNextSegmentDLOfTxState(Index, Value)                                            SomeIpTp_SetNextSegmentDLOfTxState(Index, (SomeIpTp_GetNextSegmentDLOfTxState(Index) + Value))
#define SomeIpTp_AddOffsetOfTxState(Index, Value)                                                   SomeIpTp_SetOffsetOfTxState(Index, (SomeIpTp_GetOffsetOfTxState(Index) + Value))
#define SomeIpTp_AddStatusOfTxState(Index, Value)                                                   SomeIpTp_SetStatusOfTxState(Index, (SomeIpTp_GetStatusOfTxState(Index) + Value))
#define SomeIpTp_AddTimerOfTxState(Index, Value)                                                    SomeIpTp_SetTimerOfTxState(Index, (SomeIpTp_GetTimerOfTxState(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCSubstractDataMacros  SomeIpTp Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define SomeIpTp_SubTxQueueElement(Index, Value)                                                    SomeIpTp_SetTxQueueElement(Index, (SomeIpTp_GetTxQueueElement(Index) - Value))
#define SomeIpTp_SubTxShortHeaders(Index, Value)                                                    SomeIpTp_SetTxShortHeaders(Index, (SomeIpTp_GetTxShortHeaders(Index) - Value))
#define SomeIpTp_SubDataIndexOfTxState(Index, Value)                                                SomeIpTp_SetDataIndexOfTxState(Index, (SomeIpTp_GetDataIndexOfTxState(Index) - Value))
#define SomeIpTp_SubDataLengthOfTxState(Index, Value)                                               SomeIpTp_SetDataLengthOfTxState(Index, (SomeIpTp_GetDataLengthOfTxState(Index) - Value))
#define SomeIpTp_SubMetadataOfTxState(Index, Value)                                                 SomeIpTp_SetMetadataOfTxState(Index, (SomeIpTp_GetMetadataOfTxState(Index) - Value))
#define SomeIpTp_SubNextSegmentDLOfTxState(Index, Value)                                            SomeIpTp_SetNextSegmentDLOfTxState(Index, (SomeIpTp_GetNextSegmentDLOfTxState(Index) - Value))
#define SomeIpTp_SubOffsetOfTxState(Index, Value)                                                   SomeIpTp_SetOffsetOfTxState(Index, (SomeIpTp_GetOffsetOfTxState(Index) - Value))
#define SomeIpTp_SubStatusOfTxState(Index, Value)                                                   SomeIpTp_SetStatusOfTxState(Index, (SomeIpTp_GetStatusOfTxState(Index) - Value))
#define SomeIpTp_SubTimerOfTxState(Index, Value)                                                    SomeIpTp_SetTimerOfTxState(Index, (SomeIpTp_GetTimerOfTxState(Index) - Value))
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

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/



#endif /* SOMEIPTP_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: SomeIpTp_Lcfg.h
**********************************************************************************************************************/
