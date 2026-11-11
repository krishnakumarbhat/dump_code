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
 *            Module: EthIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthIf_GenTypes.h
 *   Generation Time: 2026-09-01 16:35:07
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA_100Mb is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_TJA1103B is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_EthIf_0883 */


#if !defined (ETHIF_GENTYPES_H)
# define ETHIF_GENTYPES_H

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1977
 *********************************************************************************************************/
/* \trace SPEC-2393859 */
# include "EthIf_Cfg.h"
# include "EthIf_HwTypes.h"

/*********************************************************************************************************
 * Dynamic includes depending on configuration
 *********************************************************************************************************/
# include "EcuM_Generated_Types.h"

# include "ComStack_Types.h"


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA TYPES AND STRUCTURES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**   \brief  uint8 type for the EthIf requested mode */
typedef uint8 EthIf_RequestedModeType;
# define ETH_MODE_NO_REQUEST              (0xFFU)

/**   \brief  reset the Timer Period Counts. */
# define ETHIF_RESET_TIMER_PERIOD_COUNTS  (0x0U)

/**   \brief  reset counter value. */
# define ETHIF_RESET_COUNTER_VALUE  (0x0U)

/**
  \defgroup  EthIfPCNonComStackLibTypes  EthIf Non ComStackLib Types (PRE_COMPILE)
  \brief  These type definitions are provided by the EthIf itself.
  \{
*/
/**   \brief  enumeration type definition for states of EthIf QualifiedUnexpectedLinkDownTimerState */
typedef enum EthIfQualifiedUnexpectedLinkDownTimerStateEnum
{
  ETHIF_QUALIFIEDUNEEXPECTEDLINKDOWNTIMER_STATE_IDLE     = 0,       /**< EthIf QualifiedUnexpectedLinkDownTimerState is Idle */
  ETHIF_QUALIFIEDUNEEXPECTEDLINKDOWNTIMER_STATE_RUNNING  = 1,       /**< EthIf QualifiedUnexpectedLinkDownTimerState is Running */
  ETHIF_QUALIFIEDUNEEXPECTEDLINKDOWNTIMER_STATE_ELAPSED  = 2,       /**< EthIf QualifiedUnexpectedLinkDownTimerState is Elapsed*/
  ETHIF_QUALIFIEDUNEEXPECTEDLINKDOWNTIMER_STATE_SLEEP_REPORTED  = 3 /**< EthIf QualifiedUnexpectedLinkDownTimerState is reported*/
}EthIf_QualifiedUnexpectedLinkDownTimerStateType;

/**
  \defgroup  EthIfPCNonComStackLibTypes  EthIf Non ComStackLib Types (PRE_COMPILE)
  \brief  These type definitions are provided by the EthIf itself.
  \{
*/
/**   \brief  enumeration type definition for states of EthIf SwitchOffPortGroupDelayState */
typedef enum EthIf_SwitchOffPortGroupDelayStateEnum
{
  ETHIF_SWITCHOFF_PORT_TIMERDELAY_IDLE     = 0, /**< EthIf SwitchOffPortGroupDelayState is Idle */
  ETHIF_SWITCHOFF_PORT_TIMERDELAY_RUNNING  = 1, /**< EthIf SwitchOffPortGroupDelayState is Running */
  ETHIF_SWITCHOFF_PORT_TIMERDELAY_ELAPSED  = 2  /**< EthIf SwitchOffPortGroupDelayState is Elapsed*/
}EthIf_SwitchOffPortGroupDelayStateType;

/**   \brief  function pointer type definition for <User>_SleepIndication() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_UserSleepIndicationFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  SwitchPortGroup Idx type */
typedef uint8 EthIf_SwitchPortGroupIdxType;

/**
  \defgroup  EthIfPCNonComStackLibTypes  EthIf Non ComStackLib Types (PRE_COMPILE)
  \brief  These type definitions are provided by the EthIf itself.
  \{
*/
/**   \brief  enumeration type definition for initialization states of EthIf controller */
typedef enum EthIf_EthIfCtrlInitStateEnum
{
  ETHIF_ETHIFCTRL_INIT_STATE_UNINIT = 0, /**< EthIf controller is in uninitialized state */
  ETHIF_ETHIFCTRL_INIT_STATE_INIT   = 1  /**< EthIf controller is in initialized state */
} EthIf_EthIfCtrlInitStateType;

/**   \brief  enumeration type definition for link state of EthIf controller */
typedef enum EthIf_EthIfCtrlLinkStateEnum
{
  ETHIF_ETHIFCTRL_LINK_STATE_NO_LINK          = 0, /**< EthIf controller has no link */
  ETHIF_ETHIFCTRL_LINK_STATE_LINK_CHANGE_DOWN = 1, /**< EthIf controller has a link change from up to down */
  ETHIF_ETHIFCTRL_LINK_STATE_LINK_CHANGE_UP   = 2, /**< EthIf controller has a link change from down to up */
  ETHIF_ETHIFCTRL_LINK_STATE_LINK             = 3  /**< EthIf controller has link */
} EthIf_EthIfCtrlLinkStateType;

/**   \brief  enumeration type definition for link state of EthIf port group */
typedef enum EthIf_PortGroupLinkStateEnum
{
  ETHIF_PORTGROUP_LINK_STATE_NO_LINK          = 0, /**< EthIf port group has no link */
  ETHIF_PORTGROUP_LINK_STATE_LINK_CHANGE_DOWN = 1, /**< EthIf port group has a link change from up to down */
  ETHIF_PORTGROUP_LINK_STATE_LINK_CHANGE_UP   = 2, /**< EthIf port group has a link change from down to up */
  ETHIF_PORTGROUP_LINK_STATE_LINK             = 3  /**< EthIf port group has link */
} EthIf_PortGroupLinkStateType;

/**   \brief  enumeration type definition for link state of EthIf physical elements */
typedef enum EthIf_PhyElemLinkStateEnum
{
  ETHIF_PHYELEM_LINK_STATE_DOWN       = 0, /**< Physical element is down */
  ETHIF_PHYELEM_LINK_STATE_PHY_ACTIVE = 1, /**< Physical element is up and link change is reported to mka */
  ETHIF_PHYELEM_LINK_STATE_ACTIVE     = 2  /**< Physical element is up */
} EthIf_PhyElemLinkStateType;

/**   \brief  the invalid CLK Unit Idx */
# define ETHIF_INV_CLK_UNIT_IDX  (0xFFu)

/**   \brief  the invalid VLAN ID */
# define ETHIF_INV_VLAN_ID  (4095u)

/**   \brief  the Buffer Index Offset as defined by AR24-11 SWS_Eth_00414 */
# define ETHIF_BUFFER_INDEX_OFFSET  (0x10000u)

/**  \brief  the invalid MetaData offset. */
# define ETHIF_INV_METADATA_OFFSET  (0xFFFFu)

/**  \brief  the MetaData alignment in bytes. */
# define ETHIF_METADATA_ALIGNMENT_BYTES  (0x8u)

/**  \brief  the EthIf controller to Ether type map index (Frame owner/User) for Pdu handling. */
# define ETHIF_CTRL_TO_ETHER_TYPE_MAP_IDX_FOR_PDU  (EthIf_GetSizeOfEthIfCtrlToEtherTypeMap())

/**  \brief  the invalid Frame Priority. */
# define ETHIF_INV_FRAME_PRIORITY  (0xFFu)

/**  \brief  flags for usage of EthIf_SwtTsPRocFlagsType */
# define ETHIF_SWT_TIMESTAMP_PROC_FLAG_INGRESS_TS_PENDING  (0x01U)
# define ETHIF_SWT_TIMESTAMP_PROC_FLAG_EGRESS_TS_PENDING   (0x02U)

/**  \brief  Length of the QTag */
# define ETHIF_QTAG_LEN_BYTE  (4u)

/**  \brief  the frame header length in bytes. */
# define ETHIF_ETH_HEADER_LEN_BYTE  (ETH_PHYS_ADDR_LEN_BYTE + ETH_PHYS_ADDR_LEN_BYTE + ETHIF_QTAG_LEN_BYTE)

/**  \brief  type definition for Ethernet header buffer in bytes. */
typedef uint8 EthIfFrameHdrBufferType[ETHIF_ETH_HEADER_LEN_BYTE];

/**  \brief  pointer type definition for internal usage for time tuple. */
typedef P2VAR(TimeTupleType, TYPEDEF, ETHIF_APPL_VAR) EthIfTimeTuplePtrType;

/**  \brief  pointer type definition for internal usage of Eth buffers */
typedef P2VAR(uint8, TYPEDEF, ETHIF_APPL_VAR) EthIf_FrameBufferPtrType;

/**  \brief  bit-field type definition for Ethernet switch timestamp handling */
typedef uint8 EthIf_SwtTsProcFlagsType;

/**  \brief  Ethernet header information on VLAN level */
typedef struct
{
  P2CONST(uint8, TYPEDEF, ETHIF_APPL_DATA) DstMacAddrPtr;  /**< Destination MAC address contained in Ethernet header */
  P2CONST(uint8, TYPEDEF, ETHIF_APPL_DATA) SrcMacAddrPtr;  /**< Source MAC address contained in Ethernet header */
          Eth_FrameType                     EtherType;     /**< EtherType contained in Ethernet header */
          uint16                            VlanId;        /**< VLAN ID contained in VLAN tag of Ethernet header - if not VLAN tagged it holds ETHIF_INV_VLAN_ID */
          uint8                             Priority;      /**< VLAN PCP contained in VLAN tag of Ethernet header - only valid if VlanId is not equal ETHIF_INV_VLAN_ID */
} EthIf_FrameHdrType;

/* Signal Quality Signal Type */
typedef struct sEthIf_SignalQualityResultType
{
  uint32 HighestSignalQuality;  /**< The highest signal quality of a link since last clear */
  uint32 LowestSignalQuality;  /**< The lowest link signal quality of a link since last clear */
  uint32 ActualSignalQuality;  /**< The actual signal quality */
}EthIf_SignalQualityResultType;

/* Function pointer type definitions for Ethernet Controller */
/**   \brief  function pointer type definition for Eth_ControllerInit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthCtrlInitFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_SetControllerMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSetCtrlModeFctPtrType)(uint8, Eth_ModeType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetControllerMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetCtrlModeFctPtrType)(uint8, P2VAR(Eth_ModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_SetPhysAddr() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthSetPhysAddrFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetPhysAddr() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthGetPhysAddrFctPtrType)(uint8, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_UpdatePhysAddrFilter() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthUpdatePhysAddrFilterFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), Eth_FilterActionType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ProvideTxBuffer() */
typedef P2FUNC(BufReq_ReturnType, ETHIF_APPL_CODE, EthIf_EthProvideTxBufferFctPtrType)(uint8, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA), AUTOMATIC, ETHIF_APPL_DATA), P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ProvideExtTxBuffer() */
typedef P2FUNC(BufReq_ReturnType, ETHIF_APPL_CODE, EthIf_EthProvideExtTxBufferFctPtrType)(uint8, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA), AUTOMATIC, ETHIF_APPL_DATA), P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ReleaseRxBuffer() */
typedef P2FUNC(void,    ETHIF_APPL_CODE, EthIf_EthReleaseRxBufferFctPtrType)(uint8, Eth_BufIdxType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ReleaseRxBuffer() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthVReleaseRxBufferFctPtrType)(uint8, P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetTxHeaderPtr() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetTxHeaderPtrFctPtrType)(uint8, uint8, P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA), AUTOMATIC, ETHIF_APPL_DATA), P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetRxHeaderPtr() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetRxHeaderPtrFctPtrType)(uint8, P2VAR(P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA), AUTOMATIC, ETHIF_APPL_DATA), P2VAR(uint16, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_Transmit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTransmitFctPtrType)(uint8, uint8, Eth_FrameType, boolean, uint16, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_VTransmit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthVTransmitFctPtrType)(uint8, uint8, Eth_FrameType, boolean, uint16, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ImmediateTransmit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthImmediateTransmitFctPtrType)(uint8, Eth_BufIdxType, uint8, P2VAR(ListElemStructType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), uint16); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_Receive() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthReceiveFctPtrType)(uint8, P2VAR(Eth_RxStatusType, AUTOMATIC, ETHIF_VAR_NO_INIT)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_ReceiveQueue() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthReceiveQueueFctPtrType)(uint8, uint8, P2VAR(Eth_RxStatusType, AUTOMATIC, ETHIF_VAR_NO_INIT)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_TxConfirmation() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthTxConfirmationFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_TxConfirmationQueue() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EthTxConfirmationQueueFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetCurrentTime() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetCurrentTimeFctPtrType)(uint8, P2VAR(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_EnableEgressTimeStamp() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthEnableEgressTimeStampFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetEgressTimeStamp() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetEgressTimeStampFctPtrType)(uint8, Eth_BufIdxType, P2VAR(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_VGetEgressTimeStamp() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthVGetEgressTimeStampFctPtrType)(uint8, uint8, P2VAR(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetIngressTimeStamp() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetIngressTimeStampFctPtrType)(uint8, P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_SetBandwidthLimit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSetBandwidthLimitFctPtrType)(uint8, uint8, uint32); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetBandwidthLimit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetBandwidthLimitFctPtrType)(uint8, uint8, P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetTxStats() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetTxStatsFctPtrType)(uint8, P2VAR(Eth_TxStatsType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for Eth_GetRxStats() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetRxStatsFctPtrType)(uint8, P2VAR(Eth_RxStatsType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */


/**   \brief  function pointer type definition for Eth_GetSpiStatus() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthGetSpiStatusFctPtrType)(uint8, P2VAR(Eth_SpiStatusType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */


/* Function pointer type definitions for Ethernet Transceivers */
/**   \brief  function pointer type definition for EthTrcv_TransceiverInit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvTrcvInitFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_SetTransceiverMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvSetTrcvModeFctPtrType)(uint8, EthTrcv_ModeType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetTransceiverMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetTrcvModeFctPtrType)(uint8, P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_StartAutoNegotiation() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvStartAutoNegFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetLinkState() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetLinkStateFctPtrType)(uint8, P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetBaudRate() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetBaudRateFctPtrType)(uint8, P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetDuplexMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetDuplexModeFctPtrType)(uint8, P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */



/**   \brief  function pointer type definition for EthTrcv_SetTransceiverWakeupMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvSetTrcvWakeupModeFctPtrType)(uint8, EthTrcv_WakeupModeType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetTransceiverWakeupMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetTrcvWakeupModeFctPtrType)(uint8, P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_CheckWakeup() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvCheckWakeupFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetBusWakeupReason() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetPhyWakeupReasonFctPtrType)(uint8, P2VAR(EthTrcv_WakeupReasonType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_SetPhyTxMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvSetPhyTxModeFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetPhySignalQuality() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetPhySignalQualityFctPtrType)(uint8, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_GetCableDiagnosticsResult() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvGetCableDiagnosticsResultFctPtrType)(uint8, P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_SetPhyTestMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvSetPhyTestModeFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_SetPhyLoopbackMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvSetPhyLoopbackModeFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthTrcv_RunCableDiagnostic() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthTrcvRunCableDiagnosticFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/* Function pointer type definitions for Ethernet Switches */
/**   \brief  function pointer type definition for EthSwt_CheckWakeup() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtCheckWakeupFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetSwitchPortWakeupReason() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetSwitchPortWakeupReasonFctPtrType)(uint8, uint8, P2VAR(EthTrcv_WakeupReasonType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_SwitchInit() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtSwtInitFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_SetSwitchPortMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtSetSwtPortModeFctPtrType)(uint8, uint8, EthTrcv_ModeType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetSwitchPortMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetSwtPortModeFctPtrType)(uint8, uint8, P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_StartSwitchPortAutoNegotiation() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtStartSwtPortAutoNegFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetLinkState() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetLinkStateFctPtrType)(uint8, uint8, P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetBaudRate() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetBaudRateFctPtrType)(uint8, uint8, P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetDuplexMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetDuplexModeFctPtrType)(uint8, uint8, P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetPortMacAddrVlan() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetPortMacAddrVlanFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_VAR), P2CONST(uint16, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetPortMacAddr() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetPortMacAddrFctPtrType)(P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetPortSignalQuality() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetPortSignalQualityFctPtrType)(uint8, uint8, P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_RunPortCableDiagnostic() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtRunPortCableDiagnosticFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetPortCableDiagnosticsResult() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetPortCableDiagnosticsResultFctPtrType)(uint8, uint8, P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetArlTable() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetArlTableFctPtrType)(uint8, P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(EthSwt_MacVlanType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetBufferLevel() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetBufferLevelFctPtrType)(uint8, P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetDropCount() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetDropCountFctPtrType)(uint8, P2VAR(uint16, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(uint32, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_EnableVlan() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtEnableVlanFctPtrType)(uint8, uint8, uint16, boolean); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_StoreConfiguration() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtStoreConfigFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_ResetConfiguration() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtResetConfigFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_SetMacLearningMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtSetMacLearningModeFctPtrType)(uint8, uint8, EthSwt_MacLearningType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetMacLearningMode() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetMacLearningModeFctPtrType)(uint8, uint8, P2VAR(EthSwt_MacLearningType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_SetMgmtInfo() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtSetSwtMgmtInfoFctPtrType)(uint8, Eth_BufIdxType, P2CONST(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetRxMgmtObject() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetRxMgmtObjectFctPtrType)(uint8, P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(P2VAR(EthSwt_MgmtObjectType, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetTxMgmtObject() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetTxMgmtObjectFctPtrType)(uint8, Eth_BufIdxType, P2VAR(P2VAR(EthSwt_MgmtObjectType, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_PortEnableTimeStamp() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtPortEnableTimeStampFctPtrType)(uint8, Eth_BufIdxType, P2VAR(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_UpdateMCastPortAssignment() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtUpdateMCastPortAssignmentFctPtrType)(uint8, uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), EthSwt_MCastPortAssignActionType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_SetCorrectionTime() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtSetCorrectionTimeFctPtrType)(uint8, P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(float64, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_StartQbvSchedule() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtStartQbvScheduleFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_StopQbvSchedule() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtStopQbvScheduleFctPtrType)(uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetCounterValues() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetCounterValuesFctPtrType)(uint8, uint8, P2VAR(Eth_CounterType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetRxStats() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetRxStatsFctPtrType)(uint8, uint8, P2VAR(Eth_RxStatsType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetTxErrorCounterValues() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetTxErrorCounterValuesFctPtrType)(uint8, uint8, P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for EthSwt_GetTxStats() */
typedef P2FUNC(Std_ReturnType,    ETHIF_APPL_CODE, EthIf_EthSwtGetTxStatsFctPtrType)(uint8, uint8, P2VAR(Eth_TxStatsType, AUTOMATIC, ETHIF_APPL_VAR)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_RxIndication() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_RxIndFctPtrType)(uint8, uint16, boolean, P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), uint16); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_TxConfirmation() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_TxConfFctPtrType)(uint8, uint8); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_TrcvLinkStateChg() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_LinkStateChgIndFctPtrType)(uint8, EthTrcv_LinkStateType); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_MgmtInfoIndication() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_MgmtInfoIndFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_IngressTimeStampIndication() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_IngressTsIndFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */

/**   \brief  function pointer type definition for <User>_EgressTimeStampIndication() */
typedef P2FUNC(void,              ETHIF_APPL_CODE, EthIf_EgressTsIndFctPtrType)(uint8, P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_DATA), P2CONST(Eth_TimeStampType, AUTOMATIC, ETHIF_APPL_DATA)); /* PRQA S 1336 */ /* MD_EthIf_1336 */


/**
  \}
*/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCDataSwitches  EthIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ETHIF_DEDICATEDRXPDUNEXTFREEPOS                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ECUCPARTITION                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_QUALITYLEVELOFECUCPARTITION                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRL                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_BUFIDXOFFSETENABLEDOFETHCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHARRELEASERXBUFFERSUPPORTEDOFETHCTRL                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHDRVAPIIDXOFETHCTRL                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_IMPLICITBUFFERRELEASENEEDEDOFETHCTRL                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NUMOFTXBUFFERSOFETHCTRL                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFETHCTRL                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONTEXTENDIDXOFETHCTRL                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONTEXTLENGTHOFETHCTRL                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONTEXTSTARTIDXOFETHCTRL                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLINITCNT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLMODECNT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLSTATE                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHDRVAPI                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_CTRLINITOFETHDRVAPI                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ENABLEEGRESSTIMESTAMPOFETHDRVAPI                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETBANDWIDTHLIMITOFETHDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCTRLMODEOFETHDRVAPI                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCURRENTTIMEOFETHDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCURRENTTIMETUPLEOFETHDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_GETEGRESSTIMESTAMPOFETHDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETINGRESSTIMESTAMPOFETHDRVAPI                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPHCTIMEOFETHDRVAPI                                                                 STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.GetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.GetPhcTime' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_GETPHYSADDROFETHDRVAPI                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETRXHEADERPTROFETHDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETRXSTATSOFETHDRVAPI                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETSPISTATUSOFETHDRVAPI                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTXHEADERPTROFETHDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTXSTATSOFETHDRVAPI                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_IMMEDIATETRANSMITOFETHDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PROVIDEEXTTXBUFFEROFETHDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PROVIDETXBUFFEROFETHDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RECEIVEOFETHDRVAPI                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RECEIVEQUEUEOFETHDRVAPI                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RELEASERXBUFFEROFETHDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETBANDWIDTHLIMITOFETHDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETCTRLMODEOFETHDRVAPI                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETPHCCORRECTIONOFETHDRVAPI                                                           STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.SetPhcCorrection' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_SETPHCTIMEOFETHDRVAPI                                                                 STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.SetPhcTime' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.SetPhcTime' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_SETPHYSADDROFETHDRVAPI                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETPPSSIGNALMODEOFETHDRVAPI                                                           STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.SetPpsSignalMode' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_TRANSMITOFETHDRVAPI                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONOFETHDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONQUEUEOFETHDRVAPI                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_UPDATEPHYSADDRFILTEROFETHDRVAPI                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VGETEGRESSTIMESTAMPOFETHDRVAPI                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VRELEASERXBUFFEROFETHDRVAPI                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VSETPHCCORRECTIONOFETHDRVAPI                                                          STD_OFF  /**< Deactivateable: 'EthIf_EthDrvApiRDR_01.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_02.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_03.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_04.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_05.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_06.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_07.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthDrvApiRDR_08.VSetPhcCorrection' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_VTRANSMITOFETHDRVAPI                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNIT                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCLKUNITIDXOFETHIFCLKUNIT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITIDXOFETHIFCLKUNIT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCONTROLLERMODECHANGEREQCNT                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRL                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ECUCPARTITIONIDXOFETHIFCTRL                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ECUCPARTITIONUSEDOFETHIFCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFETHIFCTRL                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAPENDIDXOFETHIFCTRL                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAPLENGTHOFETHIFCTRL                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAPSTARTIDXOFETHIFCTRL                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFPHYSCTRLCFGIDXOFETHIFCTRL                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVAPIIDXOFETHIFCTRL                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVAPIUSEDOFETHIFCTRL                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GATEWAYDESTETHIFCTRLIDXUSEDOFETHIFCTRL                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKAGGRTHRESHOLDOFETHIFCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MACSECTYPEOFETHIFCTRL                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORRXDESTIDXIDXOFETHIFCTRL                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORRXDESTIDXOFETHIFCTRL                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORRXDESTIDXUSEDOFETHIFCTRL                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORTXDESTIDXIDXOFETHIFCTRL                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORTXDESTIDXOFETHIFCTRL                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORTXDESTIDXUSEDOFETHIFCTRL                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MTUOFETHIFCTRL                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERINITELEMSIDXOFETHIFCTRL                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERMODEELEMSIDXOFETHIFCTRL                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFETHIFCTRL                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TYPEOFETHIFCTRL                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VLANIDOFETHIFCTRL                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLINITSTATE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLLINKCOUNT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLLINKSTATE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLMODE                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFETHTRCVIND                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPORTGROUPIND                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLRXSTATS                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NUMRXBYTESOFETHIFCTRLRXSTATS                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NUMRXPKTSOFETHIFCTRLRXSTATS                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAP                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHERTYPEOFETHIFCTRLTOETHERTYPEMAP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUCOUNTOFETHIFCTRLTORXPDUMAP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUENDIDXOFETHIFCTRLTORXPDUMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDULENGTHOFETHIFCTRLTORXPDUMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUSTARTIDXOFETHIFCTRLTORXPDUMAP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUUSEDOFETHIFCTRLTORXPDUMAP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTXSTATS                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NUMTXBYTESOFETHIFCTRLTXSTATS                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NUMTXPKTSOFETHIFCTRLTXSTATS                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFMEASUREMENTDATA                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_DROPCTRLIDXOFETHIFMEASUREMENTDATA                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_UNKNOWNETHERTYPEOFETHIFMEASUREMENTDATA                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VLANDOUBLETAGGEDOFETHIFMEASUREMENTDATA                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFPHYSCTRLCFG                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFETHIFPHYSCTRLCFG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHDRVAPIIDXOFETHIFPHYSCTRLCFG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITLENGTHOFETHIFPHYSCTRLCFG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITUSEDOFETHIFPHYSCTRLCFG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFPHYSCONTROLLERIDXOFETHIFPHYSCTRLCFG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHPHCSUPPORTAVAILABLEOFETHIFPHYSCTRLCFG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTER                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATE                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATE                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMEDELAYCOUNTS                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMEDELAYREQCNT                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMERDELAYSTATE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWTPORTGROUPSTATE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUE                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFETHRXQUEUE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_QUEUEINDEXOFETHRXQUEUE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWT                                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVAPIIDXOFETHSWT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXTENDIDXOFETHSWT                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXTLENGTHOFETHSWT                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXTSTARTIDXOFETHSWT                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXTUSEDOFETHSWT                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFETHSWT                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRV                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTENDIDXOFETHSWTDRV                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTLENGTHOFETHSWTDRV                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTSTARTIDXOFETHSWTDRV                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVAPI                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_CHECKWAKEUPOFETHSWTDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ENABLEVLANOFETHSWTDRVAPI                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETARLTABLEOFETHSWTDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETBAUDRATEOFETHSWTDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETBUFFERLEVELOFETHSWTDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCOUNTERVALUESOFETHSWTDRVAPI                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCURRENTTIMETUPLEOFETHSWTDRVAPI                                                     STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetCurrentTimeTuple' Reason: 'EthIf PHC support is disabled' */
#define ETHIF_GETDROPCOUNTOFETHSWTDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETDUPLEXMODEOFETHSWTDRVAPI                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETLINKSTATEOFETHSWTDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETMACLEARNINGMODEOFETHSWTDRVAPI                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPORTCABLEDIAGNOSTICSRESULTOFETHSWTDRVAPI                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPORTMACADDROFETHSWTDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPORTMACADDRVLANOFETHSWTDRVAPI                                                      STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.GetPortMacAddrVlan' Reason: 'EthIf GetPortMacAddrVlanApi support is disabled' */
#define ETHIF_GETPORTSIGNALQUALITYOFETHSWTDRVAPI                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETRXMGMTOBJECTOFETHSWTDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETRXSTATSOFETHSWTDRVAPI                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETSWITCHPORTWAKEUPREASONOFETHSWTDRVAPI                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETSWTPORTMODEOFETHSWTDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTXERRORCOUNTERVALUESOFETHSWTDRVAPI                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTXMGMTOBJECTOFETHSWTDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTXSTATSOFETHSWTDRVAPI                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MACSECADDRXSAOFETHSWTDRVAPI                                                           STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECADDTXSAOFETHSWTDRVAPI                                                           STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecAddTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECDELETERXSAOFETHSWTDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECDELETETXSAOFETHSWTDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecDeleteTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECGETMACSECSTATSOFETHSWTDRVAPI                                                    STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetMacSecStats' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECGETTXSANEXTPNOFETHSWTDRVAPI                                                     STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECINITRXSCOFETHSWTDRVAPI                                                          STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecInitRxSc' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECRESETRXSCOFETHSWTDRVAPI                                                         STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecResetRxSc' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECSETCONTROLLEDPORTENABLEDOFETHSWTDRVAPI                                          STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATERXSAOFETHSWTDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATESECYOFETHSWTDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateSecY' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATETXSAOFETHSWTDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthSwtDrvApi.MacSecUpdateTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_PORTENABLETIMESTAMPOFETHSWTDRVAPI                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RESETCONFIGOFETHSWTDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RUNPORTCABLEDIAGNOSTICOFETHSWTDRVAPI                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETCORRECTIONTIMEOFETHSWTDRVAPI                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETMACLEARNINGMODEOFETHSWTDRVAPI                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETSWTMGMTINFOOFETHSWTDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETSWTPORTMODEOFETHSWTDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STARTQBVSCHEDULEOFETHSWTDRVAPI                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STARTSWTPORTAUTONEGOFETHSWTDRVAPI                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STOPQBVSCHEDULEOFETHSWTDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STORECONFIGOFETHSWTDRVAPI                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTINITOFETHSWTDRVAPI                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_UPDATEMCASTPORTASSIGNMENTOFETHSWTDRVAPI                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTIND                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINITCNT                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORT                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ASYNCPROCESSINGOFETHSWTPORT                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTIDXOFETHSWTPORT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTHOSTORUPLINKPORTIDXOFETHSWTPORT                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MACSECSECUREDOFETHSWTPORT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MKAPAEIDXOFETHSWTPORT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPINDENDIDXOFETHSWTPORT                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPINDSTARTIDXOFETHSWTPORT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTROLEOFETHSWTPORT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFETHSWTPORT                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTUSEDOFETHSWTPORTINETHSWTCONTEXT                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTIND                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTLINKSTATE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTMODECNT                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCV                                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ASYNCPROCESSINGOFETHTRCV                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFETHTRCVINDUSEDOFETHTRCV                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMECOUNTSOFETHTRCV                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVACTASSLAVEPASSIVEENABLEDOFETHTRCV                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVDRVAPIIDXOFETHTRCV                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVTYPEOFETHTRCV                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MACSECSECUREDOFETHTRCV                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MKAPAEIDXOFETHTRCV                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTMODEIDXOFETHTRCV                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTMODEUSEDOFETHTRCV                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTMODEIDXOFETHTRCV                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTMODEUSEDOFETHTRCV                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFETHTRCV                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_USERSLEEPINDICATIONOFETHTRCV                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVDRVAPI                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_CHECKWAKEUPOFETHTRCVDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETBAUDRATEOFETHTRCVDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETCABLEDIAGNOSTICSRESULTOFETHTRCVDRVAPI                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETDUPLEXMODEOFETHTRCVDRVAPI                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETLINKSTATEOFETHTRCVDRVAPI                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPHYSIGNALQUALITYOFETHTRCVDRVAPI                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETPHYWAKEUPREASONOFETHTRCVDRVAPI                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTRCVMODEOFETHTRCVDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GETTRCVWAKEUPMODEOFETHTRCVDRVAPI                                                      STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.GetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' */
#define ETHIF_MACSECADDRXSAOFETHTRCVDRVAPI                                                          STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecAddRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecAddRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECADDTXSAOFETHTRCVDRVAPI                                                          STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecAddTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecAddTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECDELETERXSAOFETHTRCVDRVAPI                                                       STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecDeleteRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecDeleteRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECDELETETXSAOFETHTRCVDRVAPI                                                       STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecDeleteTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecDeleteTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECGETMACSECSTATSOFETHTRCVDRVAPI                                                   STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecGetMacSecStats' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecGetMacSecStats' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECGETTXSANEXTPNOFETHTRCVDRVAPI                                                    STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecGetTxSaNextPn' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECINITRXSCOFETHTRCVDRVAPI                                                         STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecInitRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecInitRxSc' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECRESETRXSCOFETHTRCVDRVAPI                                                        STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecResetRxSc' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecResetRxSc' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECSETCONTROLLEDPORTENABLEDOFETHTRCVDRVAPI                                         STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecSetControlledPortEnabled' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATERXSAOFETHTRCVDRVAPI                                                       STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecUpdateRxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecUpdateRxSa' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATESECYOFETHTRCVDRVAPI                                                       STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecUpdateSecY' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecUpdateSecY' Reason: 'MacSec is disabled' */
#define ETHIF_MACSECUPDATETXSAOFETHTRCVDRVAPI                                                       STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.MacSecUpdateTxSa' Reason: 'MacSec is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.MacSecUpdateTxSa' Reason: 'MacSec is disabled' */
#define ETHIF_RUNCABLEDIAGNOSTICOFETHTRCVDRVAPI                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETPHYLOOPBACKMODEOFETHTRCVDRVAPI                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETPHYTESTMODEOFETHTRCVDRVAPI                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETPHYTXMODEOFETHTRCVDRVAPI                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETTRCVMODEOFETHTRCVDRVAPI                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETTRCVWAKEUPMODEOFETHTRCVDRVAPI                                                      STD_OFF  /**< Deactivateable: 'EthIf_EthTrcvDrvApiRDR_01.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_02.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_03.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_04.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_05.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_06.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_07.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' and Deactivateable: 'EthIf_EthTrcvDrvApiRDR_08.SetTrcvWakeupMode' Reason: 'Legacy wakeup support is disabled' */
#define ETHIF_STARTAUTONEGOFETHTRCVDRVAPI                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TRCVINITOFETHTRCVDRVAPI                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVINITCNT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVLINKSTATE                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODE                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECHANGERETRYCOUNTER                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECHANGERETRYPERIODCOUNTER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECNT                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVSTATE                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUE                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFETHTXQUEUE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_QUEUEINDEXOFETHTXQUEUE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_EXPLICITBUFRELEASEFILTER                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLIDXOFEXPLICITBUFRELEASEFILTER                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHERTYPECONFIGUREDOFEXPLICITBUFRELEASEFILTER                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHERTYPEOFEXPLICITBUFRELEASEFILTER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'EthIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHIF_FLOATINGRXPDUMAP                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUENDIDXOFFLOATINGRXPDUMAP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDULENGTHOFFLOATINGRXPDUMAP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUSTARTIDXOFFLOATINGRXPDUMAP                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUUSEDOFFLOATINGRXPDUMAP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUNEXTFREEPOS                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GATEWAYSRCMACBLACKLIST                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MACADDROFGATEWAYSRCMACBLACKLIST                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALMODECHANGEMAXRETRYCOUNT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALMODECHANGERETRYPERIODCOUNT                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALSTARTUPACTIVETIMERACTIVE                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'EthIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHIF_INITLOCKED                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LEGACYWAKEUPMAP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVIDXOFLEGACYWAKEUPMAP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSOURCEOFLEGACYWAKEUPMAP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKSTATECHGINDICATIONS                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKSTATECHGMAINRELOAD                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINFUNCSTATEDECOUPLEFREQCNT                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINPARTITIONRXETHCTRL                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFMAINPARTITIONRXETHCTRL                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINPARTITIONTXETHCTRL                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFMAINPARTITIONTXETHCTRL                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAXRXFRAMEPERETHCTRL                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAXTXBUFPERETHCTRL                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORDEST                                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLIDXOFMIRRORDEST                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_KEEPSRCMACENABLEDOFMIRRORDEST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORTXINFO                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_DESTETHTXBUFFERIDXOFMIRRORTXINFO                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_DESTPAYLOADPTROFMIRRORTXINFO                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLIDXOFMIRRORTXINFO                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_INFOVALIDOFMIRRORTXINFO                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SRCETHTXBUFFERIDXOFMIRRORTXINFO                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SRCPAYLOADPTROFMIRRORTXINFO                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_USEDOFMIRRORTXINFO                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MODECHANGELOCKED                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERINITELEMS                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINDUSEDOFPHYSLAYERINITELEMS                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVIDXOFPHYSLAYERINITELEMS                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVUSEDOFPHYSLAYERINITELEMS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERMODEELEMS                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVIDXOFPHYSLAYERMODEELEMS                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVUSEDOFPHYSLAYERMODEELEMS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPIDXOFPHYSLAYERMODEELEMS                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPUSEDOFPHYSLAYERMODEELEMS                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPORTGROUPINDENDIDXOFPORTGROUP                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPORTGROUPINDUSEDOFPORTGROUP                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINDENDIDXOFPORTGROUP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINDSTARTIDXOFPORTGROUP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_HOSTANDUPLINKPORTTHRESHOLDOFPORTGROUP                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_NOROLEPORTTHRESHOLDOFPORTGROUP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SEMANTICOFPORTGROUP                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SNVOFPORTGROUP                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNT                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPIND                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPLINKSTATE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPMODE                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPNOROLELINKCOUNT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPSTARTUPACTIVETIMERACTIVE                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTMODE                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSIGNALQUALITYRESULT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMECOUNTER                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMEFREQ                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMERACTIVE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHIFCTRLMODE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHTRCVMODE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHTRCVSTATEOFETHIFCTRL                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTGROUPMODE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTGROUPSTATEOFETHIFCTRL                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTMODE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONS                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDU                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPIDXOFRXPDU                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPUSEDOFRXPDU                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHMACADDROFFSETOFRXPDU                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGPOOLOFRXPDU                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPIDXOFRXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPUSEDOFRXPDU                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_KEEPLOCALBUFFEROFRXPDU                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATAENDIDXOFRXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATALENGTHOFRXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATASTARTIDXOFRXPDU                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATAUSEDOFRXPDU                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TIMETUPLEPTROFFSETOFRXPDU                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ULPDUIDOFRXPDU                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDETHMACADDRMETADATAOFRXPDU                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDTIMETUPLEMETADATAOFRXPDU                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUCONTEXT                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLIDXOFRXPDUCONTEXT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXHANDLEIDOFRXPDUCONTEXT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STATEOFRXPDUCONTEXT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TIMETUPLEOFRXPDUCONTEXT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUFRAMETYPE                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPENDIDXOFRXPDUFRAMETYPE                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPLENGTHOFRXPDUFRAMETYPE                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPUSEDOFRXPDUFRAMETYPE                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHERTYPEOFRXPDUFRAMETYPE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPENDIDXOFRXPDUFRAMETYPE                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPLENGTHOFRXPDUFRAMETYPE                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUMAPUSEDOFRXPDUFRAMETYPE                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUFREELIST                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PDUIDOFRXPDUFREELIST                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATA                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXQUEUELIST                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUEENDIDXOFRXQUEUELIST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUELENGTHOFRXQUEUELIST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUESTARTIDXOFRXQUEUELIST                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUEUSEDOFRXQUEUELIST                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETCONTROLLERMODETIMEOUT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYCHGMAINRELOAD                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYDECOUPLEFREQCNT                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYRESULT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFDEDICATEDRXPDUNEXTFREEPOS                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFECUCPARTITION                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRL                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLINITCNT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLMODECNT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLSTATE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHDRVAPI                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCLKUNIT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRL                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLINITSTATE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLLINKCOUNT                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLLINKSTATE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLMODE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLOFETHTRCVIND                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLOFPORTGROUPIND                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLRXSTATS                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTOETHERTYPEMAP                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTORXPDUMAP                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTXSTATS                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFMEASUREMENTDATA                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFPHYSCTRLCFG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTER                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATE                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTER                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATE                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTTIMERDELAYSTATE                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWTPORTGROUPSTATE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHRXQUEUE                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWT                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTDRV                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTDRVAPI                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTIND                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTINITCNT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORT                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTINETHSWTCONTEXT                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTIND                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTLINKSTATE                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTMODECNT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCV                                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVDRVAPI                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVINITCNT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVLINKSTATE                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODE                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECHANGERETRYCOUNTER                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECHANGERETRYPERIODCOUNTER                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECNT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVSTATE                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTXQUEUE                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFEXPLICITBUFRELEASEFILTER                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFFLOATINGRXPDUMAP                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFFLOATINGRXPDUNEXTFREEPOS                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFGATEWAYSRCMACBLACKLIST                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFLEGACYWAKEUPMAP                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFLINKSTATECHGINDICATIONS                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMAINPARTITIONRXETHCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMAINPARTITIONTXETHCTRL                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMIRRORDEST                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMIRRORTXINFO                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPHYSLAYERINITELEMS                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPHYSLAYERMODEELEMS                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPHOSTORUPLINKPORTROLELINKCOUNT                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPIND                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPLINKSTATE                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPMODE                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPNOROLELINKCOUNT                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPSTARTUPACTIVETIMERACTIVE                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTMODE                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTSIGNALQUALITYRESULT                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTSTARTUPACTIVETIMERACTIVE                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHIFCTRLMODE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHTRCVMODE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHTRCVSTATEOFETHIFCTRL                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTGROUPMODE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTGROUPSTATEOFETHIFCTRL                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTMODE                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXINDICATIONS                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDU                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUCONTEXT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUFRAMETYPE                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUFREELIST                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUMETADATA                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXQUEUELIST                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSIGNALQUALITYRESULT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSRCMACADDRBUFFER                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSWTPORTGROUPMODECHANGERETRYCOUNTER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSWTPORTGROUPMODECHANGERETRYPERIODCOUNTER                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXCONFIRMATIONS                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXCONTEXT                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXPDU                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXPDUCONTEXT                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXQUEUELIST                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFWAKEUPMAP                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFWAKEUPSRCDEVICE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SRCMACADDRBUFFER                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SRCMACOFSRCMACADDRBUFFER                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDOFSRCMACADDRBUFFER                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGEREQCNT                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGERETRYCOUNTER                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTER                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONS                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONTEXT                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLIDXOFTXCONTEXT                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAPIDXOFTXCONTEXT                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FRAMEHDROFTXCONTEXT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKEDPDUIDOFTXCONTEXT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PAYLOADLENOFTXCONTEXT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PAYLOADPTROFTXCONTEXT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXPENDINGOFTXCONTEXT                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDOFTXCONTEXT                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDPDUIDOFTXCONTEXT                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXPDU                                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_DIRECTDATAPROVISIONOFTXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_EGRESSHARDWARESUPPORTEDDATATRANSFEROFTXPDU                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLIDXOFTXPDU                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLUSEDOFTXPDU                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHMACADDROFFSETOFTXPDU                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHERTYPEOFTXPDU                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FRAMETXPRIORITYOFTXPDU                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_KEEPLOCALBUFFEROFTXPDU                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LISTITEMPTROFFSETOFTXPDU                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PRIORITYOFFSETOFTXPDU                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TIMETUPLEPTROFFSETOFTXPDU                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TOTALMETADATALENGTHOFTXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ULPDUIDOFTXPDU                                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VLANOFFSETOFTXPDU                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDETHMACADDRMETADATAOFTXPDU                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDLISTITEMMETADATAOFTXPDU                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDPRIORITY8METADATAOFTXPDU                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDTIMETUPLEMETADATAOFTXPDU                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_VALIDVLAN16METADATAOFTXPDU                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXPDUCONTEXT                                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FRAMEHDRBUFOFTXPDUCONTEXT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FRAMEHDROFTXPDUCONTEXT                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LISTELEMENTOFTXPDUCONTEXT                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_STATEOFTXPDUCONTEXT                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TIMETUPLEPTROFTXPDUCONTEXT                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXQUEUELIST                                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUEENDIDXOFTXQUEUELIST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUELENGTHOFTXQUEUELIST                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUESTARTIDXOFTXQUEUELIST                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUEUSEDOFTXQUEUELIST                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPMAP                                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSOURCEMASKOFWAKEUPMAP                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICEENDIDXOFWAKEUPMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICELENGTHOFWAKEUPMAP                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICESTARTIDXOFWAKEUPMAP                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICEUSEDOFWAKEUPMAP                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICE                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTIDXOFWAKEUPSRCDEVICE                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTUSEDOFWAKEUPSRCDEVICE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVIDXOFWAKEUPSRCDEVICE                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVUSEDOFWAKEUPSRCDEVICE                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TYPEOFWAKEUPSRCDEVICE                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PCCONFIG                                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_DEDICATEDRXPDUNEXTFREEPOSOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ECUCPARTITIONOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLINITCNTOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLMODECNTOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLOFPCCONFIG                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHCTRLSTATEOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHDRVAPIOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCLKUNITOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCONTROLLERMODECHANGEREQCNTOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLINITSTATEOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLLINKCOUNTOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLLINKSTATEOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLMODEOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFETHTRCVINDOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLRXSTATSOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTORXPDUMAPOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFCTRLTXSTATSOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFMEASUREMENTDATAOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFPHYSCTRLCFGOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTEROFPCCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATEOFPCCONFIG                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTEROFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATEOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMEDELAYCOUNTSOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMEDELAYREQCNTOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWITCHOFFPORTTIMERDELAYSTATEOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHIFSWTPORTGROUPSTATEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHRXQUEUEOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVAPIOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTDRVOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINDOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTINITCNTOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTOFPCCONFIG                                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTINDOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTLINKSTATEOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTMODECNTOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHSWTPORTOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVDRVAPIOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVINITCNTOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVLINKSTATEOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECHANGERETRYCOUNTEROFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODECNTOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVMODEOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVOFPCCONFIG                                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTRCVSTATEOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_ETHTXQUEUEOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_EXPLICITBUFRELEASEFILTEROFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'EthIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ETHIF_FLOATINGRXPDUMAPOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_FLOATINGRXPDUNEXTFREEPOSOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GATEWAYSRCMACBLACKLISTOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALMODECHANGEMAXRETRYCOUNTOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALMODECHANGERETRYPERIODCOUNTOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_GLOBALSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'EthIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ETHIF_INITLOCKEDOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LEGACYWAKEUPMAPOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKSTATECHGINDICATIONSOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_LINKSTATECHGMAINRELOADOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINFUNCSTATEDECOUPLEFREQCNTOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINPARTITIONRXETHCTRLOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAINPARTITIONTXETHCTRLOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAXRXFRAMEPERETHCTRLOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MAXTXBUFPERETHCTRLOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORDESTOFPCCONFIG                                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MIRRORTXINFOOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_MODECHANGELOCKEDOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERINITELEMSOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PHYSLAYERMODEELEMSOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNTOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPINDOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPLINKSTATEOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPMODEOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPNOROLELINKCOUNTOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTGROUPSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTMODEOFPCCONFIG                                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSIGNALQUALITYRESULTOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMECOUNTEROFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMEFREQOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_PORTSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHIFCTRLMODEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHTRCVMODEOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDETHTRCVSTATEOFETHIFCTRLOFPCCONFIG                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTGROUPMODEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTGROUPSTATEOFETHIFCTRLOFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_REQUESTEDPORTMODEOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXINDICATIONSOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUCONTEXTOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUFRAMETYPEOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUFREELISTOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUMETADATAOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXPDUOFPCCONFIG                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_RXQUEUELISTOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SETCONTROLLERMODETIMEOUTOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYCHGMAINRELOADOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYDECOUPLEFREQCNTOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIGNALQUALITYRESULTOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFDEDICATEDRXPDUNEXTFREEPOSOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFECUCPARTITIONOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLINITCNTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLMODECNTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHCTRLSTATEOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHDRVAPIOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCLKUNITOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLINITSTATEOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLLINKCOUNTOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLLINKSTATEOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLMODEOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLOFETHTRCVINDOFPCCONFIG                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLRXSTATSOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTORXPDUMAPOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFCTRLTXSTATSOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFMEASUREMENTDATAOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFPHYSCTRLCFGOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTEROFPCCONFIG                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATEOFPCCONFIG                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTEROFPCCONFIG                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATEOFPCCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWITCHOFFPORTTIMERDELAYSTATEOFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHIFSWTPORTGROUPSTATEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHRXQUEUEOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTDRVAPIOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTDRVOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTINDOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTINITCNTOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTINDOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTLINKSTATEOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTMODECNTOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHSWTPORTOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVDRVAPIOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVINITCNTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVLINKSTATEOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECHANGERETRYCOUNTEROFPCCONFIG                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODECNTOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVMODEOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVOFPCCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTRCVSTATEOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFETHTXQUEUEOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFEXPLICITBUFRELEASEFILTEROFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFFLOATINGRXPDUMAPOFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFFLOATINGRXPDUNEXTFREEPOSOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFGATEWAYSRCMACBLACKLISTOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFLEGACYWAKEUPMAPOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFLINKSTATECHGINDICATIONSOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMAINPARTITIONRXETHCTRLOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMAINPARTITIONTXETHCTRLOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMIRRORDESTOFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFMIRRORTXINFOOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPHYSLAYERINITELEMSOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPHYSLAYERMODEELEMSOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPHOSTORUPLINKPORTROLELINKCOUNTOFPCCONFIG                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPINDOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPLINKSTATEOFPCCONFIG                                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPMODEOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPNOROLELINKCOUNTOFPCCONFIG                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTGROUPSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTMODEOFPCCONFIG                                                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTSIGNALQUALITYRESULTOFPCCONFIG                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFPORTSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHIFCTRLMODEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHTRCVMODEOFPCCONFIG                                                  STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDETHTRCVSTATEOFETHIFCTRLOFPCCONFIG                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTGROUPMODEOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTGROUPSTATEOFETHIFCTRLOFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFREQUESTEDPORTMODEOFPCCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXINDICATIONSOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUCONTEXTOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUFRAMETYPEOFPCCONFIG                                                        STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUFREELISTOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUMETADATAOFPCCONFIG                                                         STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXPDUOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFRXQUEUELISTOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSIGNALQUALITYRESULTOFPCCONFIG                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSRCMACADDRBUFFEROFPCCONFIG                                                      STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSWTPORTGROUPMODECHANGERETRYCOUNTEROFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFSWTPORTGROUPMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                              STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXCONFIRMATIONSOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXCONTEXTOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXPDUCONTEXTOFPCCONFIG                                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXPDUOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFTXQUEUELISTOFPCCONFIG                                                           STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFWAKEUPMAPOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SIZEOFWAKEUPSRCDEVICEOFPCCONFIG                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SRCMACADDRBUFFEROFPCCONFIG                                                            STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGEREQCNTOFPCCONFIG                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGERETRYCOUNTEROFPCCONFIG                                          STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                    STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONFIRMATIONSOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXCONTEXTOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXPDUCONTEXTOFPCCONFIG                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXPDUOFPCCONFIG                                                                       STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_TXQUEUELISTOFPCCONFIG                                                                 STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPMAPOFPCCONFIG                                                                   STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define ETHIF_WAKEUPSRCDEVICEOFPCCONFIG                                                             STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCMinNumericValueDefines  EthIf Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define ETHIF_MIN_DEDICATEDRXPDUNEXTFREEPOS                                                         0u
#define ETHIF_MIN_ETHCTRLINITCNT                                                                    0u
#define ETHIF_MIN_ETHCTRLMODECNT                                                                    0u
#define ETHIF_MIN_ETHIFCONTROLLERMODECHANGEREQCNT                                                   0u
#define ETHIF_MIN_ETHIFCTRLLINKCOUNT                                                                0u
#define ETHIF_MIN_NUMRXBYTESOFETHIFCTRLRXSTATS                                                      0u
#define ETHIF_MIN_NUMRXPKTSOFETHIFCTRLRXSTATS                                                       0u
#define ETHIF_MIN_NUMTXBYTESOFETHIFCTRLTXSTATS                                                      0u
#define ETHIF_MIN_NUMTXPKTSOFETHIFCTRLTXSTATS                                                       0u
#define ETHIF_MIN_DROPCTRLIDXOFETHIFMEASUREMENTDATA                                                 0u
#define ETHIF_MIN_UNKNOWNETHERTYPEOFETHIFMEASUREMENTDATA                                            0u
#define ETHIF_MIN_VLANDOUBLETAGGEDOFETHIFMEASUREMENTDATA                                            0u
#define ETHIF_MIN_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTER                                      0u
#define ETHIF_MIN_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTER                                          0u
#define ETHIF_MIN_ETHIFSWITCHOFFPORTTIMEDELAYREQCNT                                                 0u
#define ETHIF_MIN_ETHSWTINITCNT                                                                     0u
#define ETHIF_MIN_ETHSWTPORTMODECNT                                                                 0u
#define ETHIF_MIN_ETHTRCVINITCNT                                                                    0u
#define ETHIF_MIN_ETHTRCVMODECHANGERETRYCOUNTER                                                     0u
#define ETHIF_MIN_ETHTRCVMODECHANGERETRYPERIODCOUNTER                                               0u
#define ETHIF_MIN_ETHTRCVMODECNT                                                                    0u
#define ETHIF_MIN_FLOATINGRXPDUNEXTFREEPOS                                                          0u
#define ETHIF_MIN_MAINFUNCSTATEDECOUPLEFREQCNT                                                      0u
#define ETHIF_MIN_DESTETHTXBUFFERIDXOFMIRRORTXINFO                                                  0u
#define ETHIF_MIN_ETHIFCTRLIDXOFMIRRORTXINFO                                                        0u
#define ETHIF_MIN_SRCETHTXBUFFERIDXOFMIRRORTXINFO                                                   0u
#define ETHIF_MIN_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNT                                            0u
#define ETHIF_MIN_PORTGROUPNOROLELINKCOUNT                                                          0u
#define ETHIF_MIN_PORTSTARTUPACTIVETIMECOUNTER                                                      0u
#define ETHIF_MIN_ETHIFCTRLIDXOFRXPDUCONTEXT                                                        0u
#define ETHIF_MIN_RXHANDLEIDOFRXPDUCONTEXT                                                          0u
#define ETHIF_MIN_PDUIDOFRXPDUFREELIST                                                              0u
#define ETHIF_MIN_RXPDUMETADATA                                                                     0u
#define ETHIF_MIN_SIGNALQUALITYDECOUPLEFREQCNT                                                      0u
#define ETHIF_MIN_SWTPORTGROUPMODECHANGEREQCNT                                                      0u
#define ETHIF_MIN_SWTPORTGROUPMODECHANGERETRYCOUNTER                                                0u
#define ETHIF_MIN_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTER                                          0u
#define ETHIF_MIN_ETHIFCTRLIDXOFTXCONTEXT                                                           0u
#define ETHIF_MIN_ETHIFCTRLTOETHERTYPEMAPIDXOFTXCONTEXT                                             0u
#define ETHIF_MIN_PAYLOADLENOFTXCONTEXT                                                             0u
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCMaxNumericValueDefines  EthIf Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define ETHIF_MAX_DEDICATEDRXPDUNEXTFREEPOS                                                         65535u
#define ETHIF_MAX_ETHCTRLINITCNT                                                                    255u
#define ETHIF_MAX_ETHCTRLMODECNT                                                                    255u
#define ETHIF_MAX_ETHIFCONTROLLERMODECHANGEREQCNT                                                   65535u
#define ETHIF_MAX_ETHIFCTRLLINKCOUNT                                                                255u
#define ETHIF_MAX_NUMRXBYTESOFETHIFCTRLRXSTATS                                                      4294967295u
#define ETHIF_MAX_NUMRXPKTSOFETHIFCTRLRXSTATS                                                       4294967295u
#define ETHIF_MAX_NUMTXBYTESOFETHIFCTRLTXSTATS                                                      4294967295u
#define ETHIF_MAX_NUMTXPKTSOFETHIFCTRLTXSTATS                                                       4294967295u
#define ETHIF_MAX_DROPCTRLIDXOFETHIFMEASUREMENTDATA                                                 4294967295u
#define ETHIF_MAX_UNKNOWNETHERTYPEOFETHIFMEASUREMENTDATA                                            4294967295u
#define ETHIF_MAX_VLANDOUBLETAGGEDOFETHIFMEASUREMENTDATA                                            4294967295u
#define ETHIF_MAX_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTER                                      65535u
#define ETHIF_MAX_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTER                                          65535u
#define ETHIF_MAX_ETHIFSWITCHOFFPORTTIMEDELAYREQCNT                                                 65535u
#define ETHIF_MAX_ETHSWTINITCNT                                                                     255u
#define ETHIF_MAX_ETHSWTPORTMODECNT                                                                 255u
#define ETHIF_MAX_ETHTRCVINITCNT                                                                    255u
#define ETHIF_MAX_ETHTRCVMODECHANGERETRYCOUNTER                                                     65535u
#define ETHIF_MAX_ETHTRCVMODECHANGERETRYPERIODCOUNTER                                               65535u
#define ETHIF_MAX_ETHTRCVMODECNT                                                                    255u
#define ETHIF_MAX_FLOATINGRXPDUNEXTFREEPOS                                                          65535u
#define ETHIF_MAX_MAINFUNCSTATEDECOUPLEFREQCNT                                                      65535u
#define ETHIF_MAX_DESTETHTXBUFFERIDXOFMIRRORTXINFO                                                  255u
#define ETHIF_MAX_ETHIFCTRLIDXOFMIRRORTXINFO                                                        255u
#define ETHIF_MAX_SRCETHTXBUFFERIDXOFMIRRORTXINFO                                                   255u
#define ETHIF_MAX_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNT                                            255u
#define ETHIF_MAX_PORTGROUPNOROLELINKCOUNT                                                          255u
#define ETHIF_MAX_PORTSTARTUPACTIVETIMECOUNTER                                                      65535u
#define ETHIF_MAX_ETHIFCTRLIDXOFRXPDUCONTEXT                                                        255u
#define ETHIF_MAX_RXHANDLEIDOFRXPDUCONTEXT                                                          4294967295u
#define ETHIF_MAX_PDUIDOFRXPDUFREELIST                                                              65535u
#define ETHIF_MAX_RXPDUMETADATA                                                                     255u
#define ETHIF_MAX_SIGNALQUALITYDECOUPLEFREQCNT                                                      65535u
#define ETHIF_MAX_SWTPORTGROUPMODECHANGEREQCNT                                                      65535u
#define ETHIF_MAX_SWTPORTGROUPMODECHANGERETRYCOUNTER                                                65535u
#define ETHIF_MAX_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTER                                          65535u
#define ETHIF_MAX_ETHIFCTRLIDXOFTXCONTEXT                                                           255u
#define ETHIF_MAX_ETHIFCTRLTOETHERTYPEMAPIDXOFTXCONTEXT                                             255u
#define ETHIF_MAX_PAYLOADLENOFTXCONTEXT                                                             65535u
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCNoReferenceDefines  EthIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define ETHIF_NO_NUMOFTXBUFFERSOFETHCTRL                                                            255u
#define ETHIF_NO_ECUCPARTITIONIDXOFETHIFCTRL                                                        255u
#define ETHIF_NO_ETHSWTDRVAPIIDXOFETHIFCTRL                                                         255u
#define ETHIF_NO_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL                                              255u
#define ETHIF_NO_LINKAGGRTHRESHOLDOFETHIFCTRL                                                       255u
#define ETHIF_NO_MIRRORRXDESTIDXIDXOFETHIFCTRL                                                      255u
#define ETHIF_NO_MIRRORTXDESTIDXIDXOFETHIFCTRL                                                      255u
#define ETHIF_NO_MTUOFETHIFCTRL                                                                     65535u
#define ETHIF_NO_VLANIDOFETHIFCTRL                                                                  65535u
#define ETHIF_NO_ETHERTYPEOFETHIFCTRLTOETHERTYPEMAP                                                 65535u
#define ETHIF_NO_RXINDICATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                       255u
#define ETHIF_NO_RXINDICATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                     255u
#define ETHIF_NO_TXCONFIRMATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                     255u
#define ETHIF_NO_TXCONFIRMATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                   255u
#define ETHIF_NO_RXPDUCOUNTOFETHIFCTRLTORXPDUMAP                                                    255u
#define ETHIF_NO_RXPDUENDIDXOFETHIFCTRLTORXPDUMAP                                                   255u
#define ETHIF_NO_RXPDUSTARTIDXOFETHIFCTRLTORXPDUMAP                                                 255u
#define ETHIF_NO_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG                                               255u
#define ETHIF_NO_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG                                             255u
#define ETHIF_NO_QUEUEINDEXOFETHRXQUEUE                                                             255u
#define ETHIF_NO_ETHSWTPORTINETHSWTCONTEXTENDIDXOFETHSWT                                            255u
#define ETHIF_NO_ETHSWTPORTINETHSWTCONTEXTSTARTIDXOFETHSWT                                          255u
#define ETHIF_NO_MKAPAEIDXOFETHSWTPORT                                                              255u
#define ETHIF_NO_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT                                           255u
#define ETHIF_NO_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV                                               255u
#define ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV                                             255u
#define ETHIF_NO_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMECOUNTSOFETHTRCV                                255u
#define ETHIF_NO_MKAPAEIDXOFETHTRCV                                                                 255u
#define ETHIF_NO_PORTMODEIDXOFETHTRCV                                                               255u
#define ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV                                                      255u
#define ETHIF_NO_QUEUEINDEXOFETHTXQUEUE                                                             255u
#define ETHIF_NO_ETHERTYPEOFEXPLICITBUFRELEASEFILTER                                                255u
#define ETHIF_NO_RXPDUENDIDXOFFLOATINGRXPDUMAP                                                      255u
#define ETHIF_NO_RXPDUSTARTIDXOFFLOATINGRXPDUMAP                                                    255u
#define ETHIF_NO_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS                                                255u
#define ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS                                              255u
#define ETHIF_NO_ETHTRCVIDXOFPHYSLAYERINITELEMS                                                     255u
#define ETHIF_NO_ETHTRCVIDXOFPHYSLAYERMODEELEMS                                                     255u
#define ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS                                                   255u
#define ETHIF_NO_ETHIFCTRLOFPORTGROUPINDENDIDXOFPORTGROUP                                           255u
#define ETHIF_NO_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP                                         255u
#define ETHIF_NO_HOSTANDUPLINKPORTTHRESHOLDOFPORTGROUP                                              255u
#define ETHIF_NO_NOROLEPORTTHRESHOLDOFPORTGROUP                                                     255u
#define ETHIF_NO_ETHIFCTRLTORXPDUMAPIDXOFRXPDU                                                      255u
#define ETHIF_NO_ETHMACADDROFFSETOFRXPDU                                                            255u
#define ETHIF_NO_FLOATINGRXPDUMAPIDXOFRXPDU                                                         255u
#define ETHIF_NO_RXPDUMETADATAENDIDXOFRXPDU                                                         255u
#define ETHIF_NO_RXPDUMETADATASTARTIDXOFRXPDU                                                       255u
#define ETHIF_NO_TIMETUPLEPTROFFSETOFRXPDU                                                          255u
#define ETHIF_NO_ULPDUIDOFRXPDU                                                                     255u
#define ETHIF_NO_ETHIFCTRLTORXPDUMAPENDIDXOFRXPDUFRAMETYPE                                          255u
#define ETHIF_NO_ETHIFCTRLTORXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                        255u
#define ETHIF_NO_ETHERTYPEOFRXPDUFRAMETYPE                                                          255u
#define ETHIF_NO_FLOATINGRXPDUMAPENDIDXOFRXPDUFRAMETYPE                                             255u
#define ETHIF_NO_FLOATINGRXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                           255u
#define ETHIF_NO_ETHRXQUEUEENDIDXOFRXQUEUELIST                                                      255u
#define ETHIF_NO_ETHRXQUEUESTARTIDXOFRXQUEUELIST                                                    255u
#define ETHIF_NO_ETHIFCTRLIDXOFTXPDU                                                                255u
#define ETHIF_NO_ETHMACADDROFFSETOFTXPDU                                                            255u
#define ETHIF_NO_ETHERTYPEOFTXPDU                                                                   255u
#define ETHIF_NO_FRAMETXPRIORITYOFTXPDU                                                             255u
#define ETHIF_NO_LISTITEMPTROFFSETOFTXPDU                                                           255u
#define ETHIF_NO_PRIORITYOFFSETOFTXPDU                                                              255u
#define ETHIF_NO_TIMETUPLEPTROFFSETOFTXPDU                                                          255u
#define ETHIF_NO_TOTALMETADATALENGTHOFTXPDU                                                         255u
#define ETHIF_NO_VLANOFFSETOFTXPDU                                                                  255u
#define ETHIF_NO_ETHTXQUEUEENDIDXOFTXQUEUELIST                                                      255u
#define ETHIF_NO_ETHTXQUEUESTARTIDXOFTXQUEUELIST                                                    255u
#define ETHIF_NO_WAKEUPSRCDEVICEENDIDXOFWAKEUPMAP                                                   255u
#define ETHIF_NO_WAKEUPSRCDEVICESTARTIDXOFWAKEUPMAP                                                 255u
#define ETHIF_NO_ETHSWTIDXOFWAKEUPSRCDEVICE                                                         255u
#define ETHIF_NO_ETHTRCVIDXOFWAKEUPSRCDEVICE                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCEnumExistsDefines  EthIf Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define ETHIF_EXISTS_ASIL_D_QUALITYLEVELOFECUCPARTITION                                             STD_ON
#define ETHIF_EXISTS_ASIL_C_QUALITYLEVELOFECUCPARTITION                                             STD_ON
#define ETHIF_EXISTS_ASIL_B_QUALITYLEVELOFECUCPARTITION                                             STD_ON
#define ETHIF_EXISTS_ASIL_A_QUALITYLEVELOFECUCPARTITION                                             STD_ON
#define ETHIF_EXISTS_QM_QUALITYLEVELOFECUCPARTITION                                                 STD_ON
#define ETHIF_EXISTS_UNKNOWN_QUALITYLEVELOFECUCPARTITION                                            STD_ON
#define ETHIF_EXISTS_ETHIFCTRL_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                   STD_ON
#define ETHIF_EXISTS_NO_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                          STD_ON
#define ETHIF_EXISTS_HW_MACSEC_MACSECTYPEOFETHIFCTRL                                                STD_ON
#define ETHIF_EXISTS_NO_MACSEC_MACSECTYPEOFETHIFCTRL                                                STD_ON
#define ETHIF_EXISTS_MIRRORDEST_MIRRORRXDESTIDXOFETHIFCTRL                                          STD_ON
#define ETHIF_EXISTS_NO_MIRRORRXDESTIDXOFETHIFCTRL                                                  STD_ON
#define ETHIF_EXISTS_MIRRORDEST_MIRRORTXDESTIDXOFETHIFCTRL                                          STD_ON
#define ETHIF_EXISTS_NO_MIRRORTXDESTIDXOFETHIFCTRL                                                  STD_ON
#define ETHIF_EXISTS_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL                                        STD_ON
#define ETHIF_EXISTS_ETHIFCTRL_TYPE_Q_TAGGED_VLAN_TYPEOFETHIFCTRL                                   STD_ON
#define ETHIF_EXISTS_ETHIFCTRL_TYPE_Q_TAGGED_PRIO_TYPEOFETHIFCTRL                                   STD_ON
#define ETHIF_EXISTS_PORT_ROLE_HOST_PORT_PORTROLEOFETHSWTPORT                                       STD_ON
#define ETHIF_EXISTS_PORT_ROLE_UP_LINK_PORT_PORTROLEOFETHSWTPORT                                    STD_ON
#define ETHIF_EXISTS_PORT_ROLE_NO_ROLE_PORTROLEOFETHSWTPORT                                         STD_ON
#define ETHIF_EXISTS_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV                                        STD_ON
#define ETHIF_EXISTS_ETHTRCV_CONNECTED_TO_SWT_PORT_ETHTRCVTYPEOFETHTRCV                             STD_ON
#define ETHIF_EXISTS_PORTGROUP_SEMANTIC_CONTROL_SEMANTICOFPORTGROUP                                 STD_ON
#define ETHIF_EXISTS_PORTGROUP_SEMANTIC_LINK_INFO_SEMANTICOFPORTGROUP                               STD_ON
#define ETHIF_EXISTS_ETHTRCV_DEVICE_TYPEOFWAKEUPSRCDEVICE                                           STD_ON
#define ETHIF_EXISTS_SWITCH_DEVICE_TYPEOFWAKEUPSRCDEVICE                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCEnumDefines  EthIf Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define ETHIF_ASIL_D_QUALITYLEVELOFECUCPARTITION                                                    0x00u
#define ETHIF_ASIL_C_QUALITYLEVELOFECUCPARTITION                                                    0x01u
#define ETHIF_ASIL_B_QUALITYLEVELOFECUCPARTITION                                                    0x02u
#define ETHIF_ASIL_A_QUALITYLEVELOFECUCPARTITION                                                    0x03u
#define ETHIF_QM_QUALITYLEVELOFECUCPARTITION                                                        0x04u
#define ETHIF_UNKNOWN_QUALITYLEVELOFECUCPARTITION                                                   0x05u
#define ETHIF_ETHIFCTRL_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                          0x00u
#define ETHIF_NO_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                                 0xFFu
#define ETHIF_HW_MACSEC_MACSECTYPEOFETHIFCTRL                                                       0x00u
#define ETHIF_NO_MACSEC_MACSECTYPEOFETHIFCTRL                                                       0x01u
#define ETHIF_MIRRORDEST_MIRRORRXDESTIDXOFETHIFCTRL                                                 0x00u
#define ETHIF_NO_MIRRORRXDESTIDXOFETHIFCTRL                                                         0xFFu
#define ETHIF_MIRRORDEST_MIRRORTXDESTIDXOFETHIFCTRL                                                 0x00u
#define ETHIF_NO_MIRRORTXDESTIDXOFETHIFCTRL                                                         0xFFu
#define ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL                                               0x00u
#define ETHIF_ETHIFCTRL_TYPE_Q_TAGGED_VLAN_TYPEOFETHIFCTRL                                          0x01u
#define ETHIF_ETHIFCTRL_TYPE_Q_TAGGED_PRIO_TYPEOFETHIFCTRL                                          0x02u
#define ETHIF_PORT_ROLE_HOST_PORT_PORTROLEOFETHSWTPORT                                              0x00u
#define ETHIF_PORT_ROLE_UP_LINK_PORT_PORTROLEOFETHSWTPORT                                           0x01u
#define ETHIF_PORT_ROLE_NO_ROLE_PORTROLEOFETHSWTPORT                                                0x02u
#define ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV                                               0x00u
#define ETHIF_ETHTRCV_CONNECTED_TO_SWT_PORT_ETHTRCVTYPEOFETHTRCV                                    0x01u
#define ETHIF_PORTGROUP_SEMANTIC_CONTROL_SEMANTICOFPORTGROUP                                        0x00u
#define ETHIF_PORTGROUP_SEMANTIC_LINK_INFO_SEMANTICOFPORTGROUP                                      0x01u
#define ETHIF_PDU_AVAILABLE_STATEOFRXPDUCONTEXT                                                     0x00u
#define ETHIF_PDU_IN_USE_STATEOFRXPDUCONTEXT                                                        0x01u
#define ETHIF_PDU_AVAILABLE_STATEOFTXPDUCONTEXT                                                     0x00u
#define ETHIF_PDU_IN_USE_STATEOFTXPDUCONTEXT                                                        0x01u
#define ETHIF_ETHTRCV_DEVICE_TYPEOFWAKEUPSRCDEVICE                                                  0x00u
#define ETHIF_SWITCH_DEVICE_TYPEOFWAKEUPSRCDEVICE                                                   0x01u
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCIsReducedToDefineDefines  EthIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ETHIF_ISDEF_QUALITYLEVELOFECUCPARTITION                                                     STD_OFF
#define ETHIF_ISDEF_BUFIDXOFFSETENABLEDOFETHCTRL                                                    STD_OFF
#define ETHIF_ISDEF_ETHARRELEASERXBUFFERSUPPORTEDOFETHCTRL                                          STD_OFF
#define ETHIF_ISDEF_ETHDRVAPIIDXOFETHCTRL                                                           STD_OFF
#define ETHIF_ISDEF_IMPLICITBUFFERRELEASENEEDEDOFETHCTRL                                            STD_OFF
#define ETHIF_ISDEF_NUMOFTXBUFFERSOFETHCTRL                                                         STD_OFF
#define ETHIF_ISDEF_SNVOFETHCTRL                                                                    STD_OFF
#define ETHIF_ISDEF_TXCONTEXTENDIDXOFETHCTRL                                                        STD_OFF
#define ETHIF_ISDEF_TXCONTEXTLENGTHOFETHCTRL                                                        STD_OFF
#define ETHIF_ISDEF_TXCONTEXTSTARTIDXOFETHCTRL                                                      STD_OFF
#define ETHIF_ISDEF_CTRLINITOFETHDRVAPI                                                             STD_OFF
#define ETHIF_ISDEF_ENABLEEGRESSTIMESTAMPOFETHDRVAPI                                                STD_OFF
#define ETHIF_ISDEF_GETBANDWIDTHLIMITOFETHDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_GETCTRLMODEOFETHDRVAPI                                                          STD_OFF
#define ETHIF_ISDEF_GETCURRENTTIMEOFETHDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_GETEGRESSTIMESTAMPOFETHDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_GETINGRESSTIMESTAMPOFETHDRVAPI                                                  STD_OFF
#define ETHIF_ISDEF_GETPHYSADDROFETHDRVAPI                                                          STD_OFF
#define ETHIF_ISDEF_GETRXHEADERPTROFETHDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_GETRXSTATSOFETHDRVAPI                                                           STD_OFF
#define ETHIF_ISDEF_GETSPISTATUSOFETHDRVAPI                                                         STD_OFF
#define ETHIF_ISDEF_GETTXHEADERPTROFETHDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_GETTXSTATSOFETHDRVAPI                                                           STD_OFF
#define ETHIF_ISDEF_IMMEDIATETRANSMITOFETHDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_PROVIDEEXTTXBUFFEROFETHDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_PROVIDETXBUFFEROFETHDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_RECEIVEOFETHDRVAPI                                                              STD_OFF
#define ETHIF_ISDEF_RECEIVEQUEUEOFETHDRVAPI                                                         STD_OFF
#define ETHIF_ISDEF_RELEASERXBUFFEROFETHDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_SETBANDWIDTHLIMITOFETHDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_SETCTRLMODEOFETHDRVAPI                                                          STD_OFF
#define ETHIF_ISDEF_SETPHYSADDROFETHDRVAPI                                                          STD_OFF
#define ETHIF_ISDEF_TRANSMITOFETHDRVAPI                                                             STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONOFETHDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONQUEUEOFETHDRVAPI                                                  STD_OFF
#define ETHIF_ISDEF_UPDATEPHYSADDRFILTEROFETHDRVAPI                                                 STD_OFF
#define ETHIF_ISDEF_VGETEGRESSTIMESTAMPOFETHDRVAPI                                                  STD_OFF
#define ETHIF_ISDEF_VRELEASERXBUFFEROFETHDRVAPI                                                     STD_OFF
#define ETHIF_ISDEF_VTRANSMITOFETHDRVAPI                                                            STD_OFF
#define ETHIF_ISDEF_ETHCLKUNITIDXOFETHIFCLKUNIT                                                     STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITIDXOFETHIFCLKUNIT                                                   STD_OFF
#define ETHIF_ISDEF_ECUCPARTITIONIDXOFETHIFCTRL                                                     STD_OFF
#define ETHIF_ISDEF_ECUCPARTITIONUSEDOFETHIFCTRL                                                    STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFETHIFCTRL                                                           STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTOETHERTYPEMAPENDIDXOFETHIFCTRL                                        STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTOETHERTYPEMAPLENGTHOFETHIFCTRL                                        STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTOETHERTYPEMAPSTARTIDXOFETHIFCTRL                                      STD_OFF
#define ETHIF_ISDEF_ETHIFPHYSCTRLCFGIDXOFETHIFCTRL                                                  STD_OFF
#define ETHIF_ISDEF_ETHSWTDRVAPIIDXOFETHIFCTRL                                                      STD_OFF
#define ETHIF_ISDEF_ETHSWTDRVAPIUSEDOFETHIFCTRL                                                     STD_OFF
#define ETHIF_ISDEF_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL                                           STD_OFF
#define ETHIF_ISDEF_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                              STD_OFF
#define ETHIF_ISDEF_GATEWAYDESTETHIFCTRLIDXUSEDOFETHIFCTRL                                          STD_OFF
#define ETHIF_ISDEF_LINKAGGRTHRESHOLDOFETHIFCTRL                                                    STD_OFF
#define ETHIF_ISDEF_MACSECTYPEOFETHIFCTRL                                                           STD_OFF
#define ETHIF_ISDEF_MIRRORRXDESTIDXIDXOFETHIFCTRL                                                   STD_OFF
#define ETHIF_ISDEF_MIRRORRXDESTIDXOFETHIFCTRL                                                      STD_OFF
#define ETHIF_ISDEF_MIRRORRXDESTIDXUSEDOFETHIFCTRL                                                  STD_OFF
#define ETHIF_ISDEF_MIRRORTXDESTIDXIDXOFETHIFCTRL                                                   STD_OFF
#define ETHIF_ISDEF_MIRRORTXDESTIDXOFETHIFCTRL                                                      STD_OFF
#define ETHIF_ISDEF_MIRRORTXDESTIDXUSEDOFETHIFCTRL                                                  STD_OFF
#define ETHIF_ISDEF_MTUOFETHIFCTRL                                                                  STD_OFF
#define ETHIF_ISDEF_PHYSLAYERINITELEMSIDXOFETHIFCTRL                                                STD_OFF
#define ETHIF_ISDEF_PHYSLAYERMODEELEMSIDXOFETHIFCTRL                                                STD_OFF
#define ETHIF_ISDEF_SNVOFETHIFCTRL                                                                  STD_OFF
#define ETHIF_ISDEF_TYPEOFETHIFCTRL                                                                 STD_OFF
#define ETHIF_ISDEF_VLANIDOFETHIFCTRL                                                               STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFETHTRCVIND                                                           STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPORTGROUPIND                                                         STD_OFF
#define ETHIF_ISDEF_ETHERTYPEOFETHIFCTRLTOETHERTYPEMAP                                              STD_OFF
#define ETHIF_ISDEF_RXINDICATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                    STD_OFF
#define ETHIF_ISDEF_RXINDICATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                    STD_OFF
#define ETHIF_ISDEF_RXINDICATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                  STD_OFF
#define ETHIF_ISDEF_RXINDICATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                      STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                  STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                  STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                    STD_OFF
#define ETHIF_ISDEF_RXPDUCOUNTOFETHIFCTRLTORXPDUMAP                                                 STD_OFF
#define ETHIF_ISDEF_RXPDUENDIDXOFETHIFCTRLTORXPDUMAP                                                STD_OFF
#define ETHIF_ISDEF_RXPDULENGTHOFETHIFCTRLTORXPDUMAP                                                STD_OFF
#define ETHIF_ISDEF_RXPDUSTARTIDXOFETHIFCTRLTORXPDUMAP                                              STD_OFF
#define ETHIF_ISDEF_RXPDUUSEDOFETHIFCTRLTORXPDUMAP                                                  STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFETHIFPHYSCTRLCFG                                                    STD_OFF
#define ETHIF_ISDEF_ETHDRVAPIIDXOFETHIFPHYSCTRLCFG                                                  STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG                                            STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITLENGTHOFETHIFPHYSCTRLCFG                                            STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG                                          STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITUSEDOFETHIFPHYSCTRLCFG                                              STD_OFF
#define ETHIF_ISDEF_ETHIFPHYSCONTROLLERIDXOFETHIFPHYSCTRLCFG                                        STD_OFF
#define ETHIF_ISDEF_ETHPHCSUPPORTAVAILABLEOFETHIFPHYSCTRLCFG                                        STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFETHRXQUEUE                                                          STD_OFF
#define ETHIF_ISDEF_QUEUEINDEXOFETHRXQUEUE                                                          STD_OFF
#define ETHIF_ISDEF_ETHSWTDRVAPIIDXOFETHSWT                                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINETHSWTCONTEXTENDIDXOFETHSWT                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINETHSWTCONTEXTLENGTHOFETHSWT                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINETHSWTCONTEXTSTARTIDXOFETHSWT                                       STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINETHSWTCONTEXTUSEDOFETHSWT                                           STD_OFF
#define ETHIF_ISDEF_SNVOFETHSWT                                                                     STD_OFF
#define ETHIF_ISDEF_ETHSWTENDIDXOFETHSWTDRV                                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTLENGTHOFETHSWTDRV                                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTSTARTIDXOFETHSWTDRV                                                       STD_OFF
#define ETHIF_ISDEF_CHECKWAKEUPOFETHSWTDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_ENABLEVLANOFETHSWTDRVAPI                                                        STD_OFF
#define ETHIF_ISDEF_GETARLTABLEOFETHSWTDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_GETBAUDRATEOFETHSWTDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_GETBUFFERLEVELOFETHSWTDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_GETCOUNTERVALUESOFETHSWTDRVAPI                                                  STD_OFF
#define ETHIF_ISDEF_GETDROPCOUNTOFETHSWTDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_GETDUPLEXMODEOFETHSWTDRVAPI                                                     STD_OFF
#define ETHIF_ISDEF_GETLINKSTATEOFETHSWTDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_GETMACLEARNINGMODEOFETHSWTDRVAPI                                                STD_OFF
#define ETHIF_ISDEF_GETPORTCABLEDIAGNOSTICSRESULTOFETHSWTDRVAPI                                     STD_OFF
#define ETHIF_ISDEF_GETPORTMACADDROFETHSWTDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_GETPORTSIGNALQUALITYOFETHSWTDRVAPI                                              STD_OFF
#define ETHIF_ISDEF_GETRXMGMTOBJECTOFETHSWTDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_GETRXSTATSOFETHSWTDRVAPI                                                        STD_OFF
#define ETHIF_ISDEF_GETSWITCHPORTWAKEUPREASONOFETHSWTDRVAPI                                         STD_OFF
#define ETHIF_ISDEF_GETSWTPORTMODEOFETHSWTDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_GETTXERRORCOUNTERVALUESOFETHSWTDRVAPI                                           STD_OFF
#define ETHIF_ISDEF_GETTXMGMTOBJECTOFETHSWTDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_GETTXSTATSOFETHSWTDRVAPI                                                        STD_OFF
#define ETHIF_ISDEF_PORTENABLETIMESTAMPOFETHSWTDRVAPI                                               STD_OFF
#define ETHIF_ISDEF_RESETCONFIGOFETHSWTDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_RUNPORTCABLEDIAGNOSTICOFETHSWTDRVAPI                                            STD_OFF
#define ETHIF_ISDEF_SETCORRECTIONTIMEOFETHSWTDRVAPI                                                 STD_OFF
#define ETHIF_ISDEF_SETMACLEARNINGMODEOFETHSWTDRVAPI                                                STD_OFF
#define ETHIF_ISDEF_SETSWTMGMTINFOOFETHSWTDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_SETSWTPORTMODEOFETHSWTDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_STARTQBVSCHEDULEOFETHSWTDRVAPI                                                  STD_OFF
#define ETHIF_ISDEF_STARTSWTPORTAUTONEGOFETHSWTDRVAPI                                               STD_OFF
#define ETHIF_ISDEF_STOPQBVSCHEDULEOFETHSWTDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_STORECONFIGOFETHSWTDRVAPI                                                       STD_OFF
#define ETHIF_ISDEF_SWTINITOFETHSWTDRVAPI                                                           STD_OFF
#define ETHIF_ISDEF_UPDATEMCASTPORTASSIGNMENTOFETHSWTDRVAPI                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTIND                                                                       STD_OFF
#define ETHIF_ISDEF_ASYNCPROCESSINGOFETHSWTPORT                                                     STD_OFF
#define ETHIF_ISDEF_ETHSWTIDXOFETHSWTPORT                                                           STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTHOSTORUPLINKPORTIDXOFETHSWTPORT                                       STD_OFF
#define ETHIF_ISDEF_MACSECSECUREDOFETHSWTPORT                                                       STD_OFF
#define ETHIF_ISDEF_MKAPAEIDXOFETHSWTPORT                                                           STD_OFF
#define ETHIF_ISDEF_PORTGROUPINDENDIDXOFETHSWTPORT                                                  STD_OFF
#define ETHIF_ISDEF_PORTGROUPINDSTARTIDXOFETHSWTPORT                                                STD_OFF
#define ETHIF_ISDEF_PORTROLEOFETHSWTPORT                                                            STD_OFF
#define ETHIF_ISDEF_SNVOFETHSWTPORT                                                                 STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT                                        STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTUSEDOFETHSWTPORTINETHSWTCONTEXT                                       STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTIND                                                                   STD_OFF
#define ETHIF_ISDEF_ASYNCPROCESSINGOFETHTRCV                                                        STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV                                            STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV                                          STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFETHTRCVINDUSEDOFETHTRCV                                              STD_OFF
#define ETHIF_ISDEF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMECOUNTSOFETHTRCV                             STD_OFF
#define ETHIF_ISDEF_ETHTRCVACTASSLAVEPASSIVEENABLEDOFETHTRCV                                        STD_OFF
#define ETHIF_ISDEF_ETHTRCVDRVAPIIDXOFETHTRCV                                                       STD_OFF
#define ETHIF_ISDEF_ETHTRCVTYPEOFETHTRCV                                                            STD_OFF
#define ETHIF_ISDEF_MACSECSECUREDOFETHTRCV                                                          STD_OFF
#define ETHIF_ISDEF_MKAPAEIDXOFETHTRCV                                                              STD_OFF
#define ETHIF_ISDEF_PORTMODEIDXOFETHTRCV                                                            STD_OFF
#define ETHIF_ISDEF_PORTMODEUSEDOFETHTRCV                                                           STD_OFF
#define ETHIF_ISDEF_REQUESTEDPORTMODEIDXOFETHTRCV                                                   STD_OFF
#define ETHIF_ISDEF_REQUESTEDPORTMODEUSEDOFETHTRCV                                                  STD_OFF
#define ETHIF_ISDEF_SNVOFETHTRCV                                                                    STD_OFF
#define ETHIF_ISDEF_USERSLEEPINDICATIONOFETHTRCV                                                    STD_OFF
#define ETHIF_ISDEF_CHECKWAKEUPOFETHTRCVDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_GETBAUDRATEOFETHTRCVDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_GETCABLEDIAGNOSTICSRESULTOFETHTRCVDRVAPI                                        STD_OFF
#define ETHIF_ISDEF_GETDUPLEXMODEOFETHTRCVDRVAPI                                                    STD_OFF
#define ETHIF_ISDEF_GETLINKSTATEOFETHTRCVDRVAPI                                                     STD_OFF
#define ETHIF_ISDEF_GETPHYSIGNALQUALITYOFETHTRCVDRVAPI                                              STD_OFF
#define ETHIF_ISDEF_GETPHYWAKEUPREASONOFETHTRCVDRVAPI                                               STD_OFF
#define ETHIF_ISDEF_GETTRCVMODEOFETHTRCVDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_RUNCABLEDIAGNOSTICOFETHTRCVDRVAPI                                               STD_OFF
#define ETHIF_ISDEF_SETPHYLOOPBACKMODEOFETHTRCVDRVAPI                                               STD_OFF
#define ETHIF_ISDEF_SETPHYTESTMODEOFETHTRCVDRVAPI                                                   STD_OFF
#define ETHIF_ISDEF_SETPHYTXMODEOFETHTRCVDRVAPI                                                     STD_OFF
#define ETHIF_ISDEF_SETTRCVMODEOFETHTRCVDRVAPI                                                      STD_OFF
#define ETHIF_ISDEF_STARTAUTONEGOFETHTRCVDRVAPI                                                     STD_OFF
#define ETHIF_ISDEF_TRCVINITOFETHTRCVDRVAPI                                                         STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFETHTXQUEUE                                                          STD_OFF
#define ETHIF_ISDEF_QUEUEINDEXOFETHTXQUEUE                                                          STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLIDXOFEXPLICITBUFRELEASEFILTER                                          STD_OFF
#define ETHIF_ISDEF_ETHERTYPECONFIGUREDOFEXPLICITBUFRELEASEFILTER                                   STD_OFF
#define ETHIF_ISDEF_ETHERTYPEOFEXPLICITBUFRELEASEFILTER                                             STD_OFF
#define ETHIF_ISDEF_RXPDUENDIDXOFFLOATINGRXPDUMAP                                                   STD_OFF
#define ETHIF_ISDEF_RXPDULENGTHOFFLOATINGRXPDUMAP                                                   STD_OFF
#define ETHIF_ISDEF_RXPDUSTARTIDXOFFLOATINGRXPDUMAP                                                 STD_OFF
#define ETHIF_ISDEF_RXPDUUSEDOFFLOATINGRXPDUMAP                                                     STD_OFF
#define ETHIF_ISDEF_MACADDROFGATEWAYSRCMACBLACKLIST                                                 STD_OFF
#define ETHIF_ISDEF_ETHTRCVIDXOFLEGACYWAKEUPMAP                                                     STD_OFF
#define ETHIF_ISDEF_WAKEUPSOURCEOFLEGACYWAKEUPMAP                                                   STD_OFF
#define ETHIF_ISDEF_LINKSTATECHGINDICATIONS                                                         STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFMAINPARTITIONRXETHCTRL                                              STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFMAINPARTITIONTXETHCTRL                                              STD_OFF
#define ETHIF_ISDEF_ETHCTRLIDXOFMIRRORDEST                                                          STD_OFF
#define ETHIF_ISDEF_KEEPSRCMACENABLEDOFMIRRORDEST                                                   STD_OFF
#define ETHIF_ISDEF_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS                                             STD_OFF
#define ETHIF_ISDEF_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS                                           STD_OFF
#define ETHIF_ISDEF_ETHSWTINDUSEDOFPHYSLAYERINITELEMS                                               STD_OFF
#define ETHIF_ISDEF_ETHTRCVIDXOFPHYSLAYERINITELEMS                                                  STD_OFF
#define ETHIF_ISDEF_ETHTRCVUSEDOFPHYSLAYERINITELEMS                                                 STD_OFF
#define ETHIF_ISDEF_ETHTRCVIDXOFPHYSLAYERMODEELEMS                                                  STD_OFF
#define ETHIF_ISDEF_ETHTRCVUSEDOFPHYSLAYERMODEELEMS                                                 STD_OFF
#define ETHIF_ISDEF_PORTGROUPIDXOFPHYSLAYERMODEELEMS                                                STD_OFF
#define ETHIF_ISDEF_PORTGROUPUSEDOFPHYSLAYERMODEELEMS                                               STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPORTGROUPINDENDIDXOFPORTGROUP                                        STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP                                      STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPORTGROUPINDUSEDOFPORTGROUP                                          STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINDENDIDXOFPORTGROUP                                                  STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINDSTARTIDXOFPORTGROUP                                                STD_OFF
#define ETHIF_ISDEF_HOSTANDUPLINKPORTTHRESHOLDOFPORTGROUP                                           STD_OFF
#define ETHIF_ISDEF_NOROLEPORTTHRESHOLDOFPORTGROUP                                                  STD_OFF
#define ETHIF_ISDEF_SEMANTICOFPORTGROUP                                                             STD_OFF
#define ETHIF_ISDEF_SNVOFPORTGROUP                                                                  STD_OFF
#define ETHIF_ISDEF_PORTGROUPIND                                                                    STD_OFF
#define ETHIF_ISDEF_RXINDICATIONS                                                                   STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPIDXOFRXPDU                                                   STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPUSEDOFRXPDU                                                  STD_OFF
#define ETHIF_ISDEF_ETHMACADDROFFSETOFRXPDU                                                         STD_OFF
#define ETHIF_ISDEF_FLOATINGPOOLOFRXPDU                                                             STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPIDXOFRXPDU                                                      STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPUSEDOFRXPDU                                                     STD_OFF
#define ETHIF_ISDEF_KEEPLOCALBUFFEROFRXPDU                                                          STD_OFF
#define ETHIF_ISDEF_RXPDUMETADATAENDIDXOFRXPDU                                                      STD_OFF
#define ETHIF_ISDEF_RXPDUMETADATALENGTHOFRXPDU                                                      STD_OFF
#define ETHIF_ISDEF_RXPDUMETADATASTARTIDXOFRXPDU                                                    STD_OFF
#define ETHIF_ISDEF_RXPDUMETADATAUSEDOFRXPDU                                                        STD_OFF
#define ETHIF_ISDEF_TIMETUPLEPTROFFSETOFRXPDU                                                       STD_OFF
#define ETHIF_ISDEF_ULPDUIDOFRXPDU                                                                  STD_OFF
#define ETHIF_ISDEF_VALIDETHMACADDRMETADATAOFRXPDU                                                  STD_OFF
#define ETHIF_ISDEF_VALIDTIMETUPLEMETADATAOFRXPDU                                                   STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPENDIDXOFRXPDUFRAMETYPE                                       STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPLENGTHOFRXPDUFRAMETYPE                                       STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                     STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPUSEDOFRXPDUFRAMETYPE                                         STD_OFF
#define ETHIF_ISDEF_ETHERTYPEOFRXPDUFRAMETYPE                                                       STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPENDIDXOFRXPDUFRAMETYPE                                          STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPLENGTHOFRXPDUFRAMETYPE                                          STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                        STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPUSEDOFRXPDUFRAMETYPE                                            STD_OFF
#define ETHIF_ISDEF_ETHRXQUEUEENDIDXOFRXQUEUELIST                                                   STD_OFF
#define ETHIF_ISDEF_ETHRXQUEUELENGTHOFRXQUEUELIST                                                   STD_OFF
#define ETHIF_ISDEF_ETHRXQUEUESTARTIDXOFRXQUEUELIST                                                 STD_OFF
#define ETHIF_ISDEF_ETHRXQUEUEUSEDOFRXQUEUELIST                                                     STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONS                                                                 STD_OFF
#define ETHIF_ISDEF_DIRECTDATAPROVISIONOFTXPDU                                                      STD_OFF
#define ETHIF_ISDEF_EGRESSHARDWARESUPPORTEDDATATRANSFEROFTXPDU                                      STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLIDXOFTXPDU                                                             STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLUSEDOFTXPDU                                                            STD_OFF
#define ETHIF_ISDEF_ETHMACADDROFFSETOFTXPDU                                                         STD_OFF
#define ETHIF_ISDEF_ETHERTYPEOFTXPDU                                                                STD_OFF
#define ETHIF_ISDEF_FRAMETXPRIORITYOFTXPDU                                                          STD_OFF
#define ETHIF_ISDEF_KEEPLOCALBUFFEROFTXPDU                                                          STD_OFF
#define ETHIF_ISDEF_LISTITEMPTROFFSETOFTXPDU                                                        STD_OFF
#define ETHIF_ISDEF_PRIORITYOFFSETOFTXPDU                                                           STD_OFF
#define ETHIF_ISDEF_TIMETUPLEPTROFFSETOFTXPDU                                                       STD_OFF
#define ETHIF_ISDEF_TOTALMETADATALENGTHOFTXPDU                                                      STD_OFF
#define ETHIF_ISDEF_ULPDUIDOFTXPDU                                                                  STD_OFF
#define ETHIF_ISDEF_VLANOFFSETOFTXPDU                                                               STD_OFF
#define ETHIF_ISDEF_VALIDETHMACADDRMETADATAOFTXPDU                                                  STD_OFF
#define ETHIF_ISDEF_VALIDLISTITEMMETADATAOFTXPDU                                                    STD_OFF
#define ETHIF_ISDEF_VALIDPRIORITY8METADATAOFTXPDU                                                   STD_OFF
#define ETHIF_ISDEF_VALIDTIMETUPLEMETADATAOFTXPDU                                                   STD_OFF
#define ETHIF_ISDEF_VALIDVLAN16METADATAOFTXPDU                                                      STD_OFF
#define ETHIF_ISDEF_ETHTXQUEUEENDIDXOFTXQUEUELIST                                                   STD_OFF
#define ETHIF_ISDEF_ETHTXQUEUELENGTHOFTXQUEUELIST                                                   STD_OFF
#define ETHIF_ISDEF_ETHTXQUEUESTARTIDXOFTXQUEUELIST                                                 STD_OFF
#define ETHIF_ISDEF_ETHTXQUEUEUSEDOFTXQUEUELIST                                                     STD_OFF
#define ETHIF_ISDEF_WAKEUPSOURCEMASKOFWAKEUPMAP                                                     STD_OFF
#define ETHIF_ISDEF_WAKEUPSRCDEVICEENDIDXOFWAKEUPMAP                                                STD_OFF
#define ETHIF_ISDEF_WAKEUPSRCDEVICELENGTHOFWAKEUPMAP                                                STD_OFF
#define ETHIF_ISDEF_WAKEUPSRCDEVICESTARTIDXOFWAKEUPMAP                                              STD_OFF
#define ETHIF_ISDEF_WAKEUPSRCDEVICEUSEDOFWAKEUPMAP                                                  STD_OFF
#define ETHIF_ISDEF_ETHSWTIDXOFWAKEUPSRCDEVICE                                                      STD_OFF
#define ETHIF_ISDEF_ETHSWTUSEDOFWAKEUPSRCDEVICE                                                     STD_OFF
#define ETHIF_ISDEF_ETHTRCVIDXOFWAKEUPSRCDEVICE                                                     STD_OFF
#define ETHIF_ISDEF_ETHTRCVUSEDOFWAKEUPSRCDEVICE                                                    STD_OFF
#define ETHIF_ISDEF_TYPEOFWAKEUPSRCDEVICE                                                           STD_OFF
#define ETHIF_ISDEF_DEDICATEDRXPDUNEXTFREEPOSOFPCCONFIG                                             STD_OFF
#define ETHIF_ISDEF_ECUCPARTITIONOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_ETHCTRLINITCNTOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_ETHCTRLMODECNTOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_ETHCTRLOFPCCONFIG                                                               STD_OFF
#define ETHIF_ISDEF_ETHCTRLSTATEOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_ETHDRVAPIOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_ETHIFCLKUNITOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_ETHIFCONTROLLERMODECHANGEREQCNTOFPCCONFIG                                       STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLINITSTATEOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLLINKCOUNTOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLLINKSTATEOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLMODEOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFETHTRCVINDOFPCCONFIG                                                 STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                               STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLRXSTATSOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                               STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTORXPDUMAPOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_ETHIFCTRLTXSTATSOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_ETHIFMEASUREMENTDATAOFPCCONFIG                                                  STD_OFF
#define ETHIF_ISDEF_ETHIFPHYSCTRLCFGOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTEROFPCCONFIG                          STD_OFF
#define ETHIF_ISDEF_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATEOFPCCONFIG                            STD_OFF
#define ETHIF_ISDEF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTEROFPCCONFIG                              STD_OFF
#define ETHIF_ISDEF_ETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATEOFPCCONFIG                                STD_OFF
#define ETHIF_ISDEF_ETHIFSWITCHOFFPORTTIMEDELAYCOUNTSOFPCCONFIG                                     STD_OFF
#define ETHIF_ISDEF_ETHIFSWITCHOFFPORTTIMEDELAYREQCNTOFPCCONFIG                                     STD_OFF
#define ETHIF_ISDEF_ETHIFSWITCHOFFPORTTIMERDELAYSTATEOFPCCONFIG                                     STD_OFF
#define ETHIF_ISDEF_ETHIFSWTPORTGROUPSTATEOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_ETHRXQUEUEOFPCCONFIG                                                            STD_OFF
#define ETHIF_ISDEF_ETHSWTDRVAPIOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_ETHSWTDRVOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_ETHSWTINDOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_ETHSWTINITCNTOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTOFPCCONFIG                                                                STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                             STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTINDOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTLINKSTATEOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTMODECNTOFPCCONFIG                                                     STD_OFF
#define ETHIF_ISDEF_ETHSWTPORTOFPCCONFIG                                                            STD_OFF
#define ETHIF_ISDEF_ETHTRCVDRVAPIOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_ETHTRCVINITCNTOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_ETHTRCVLINKSTATEOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_ETHTRCVMODECHANGERETRYCOUNTEROFPCCONFIG                                         STD_OFF
#define ETHIF_ISDEF_ETHTRCVMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                   STD_OFF
#define ETHIF_ISDEF_ETHTRCVMODECNTOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_ETHTRCVMODEOFPCCONFIG                                                           STD_OFF
#define ETHIF_ISDEF_ETHTRCVOFPCCONFIG                                                               STD_OFF
#define ETHIF_ISDEF_ETHTRCVSTATEOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_ETHTXQUEUEOFPCCONFIG                                                            STD_OFF
#define ETHIF_ISDEF_EXPLICITBUFRELEASEFILTEROFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUMAPOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_FLOATINGRXPDUNEXTFREEPOSOFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_GATEWAYSRCMACBLACKLISTOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_GLOBALMODECHANGEMAXRETRYCOUNTOFPCCONFIG                                         STD_OFF
#define ETHIF_ISDEF_GLOBALMODECHANGERETRYPERIODCOUNTOFPCCONFIG                                      STD_OFF
#define ETHIF_ISDEF_GLOBALSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                        STD_OFF
#define ETHIF_ISDEF_INITLOCKEDOFPCCONFIG                                                            STD_OFF
#define ETHIF_ISDEF_LEGACYWAKEUPMAPOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_LINKSTATECHGINDICATIONSOFPCCONFIG                                               STD_OFF
#define ETHIF_ISDEF_LINKSTATECHGMAINRELOADOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_MAINFUNCSTATEDECOUPLEFREQCNTOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_MAINPARTITIONRXETHCTRLOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_MAINPARTITIONTXETHCTRLOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_MAXRXFRAMEPERETHCTRLOFPCCONFIG                                                  STD_OFF
#define ETHIF_ISDEF_MAXTXBUFPERETHCTRLOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_MIRRORDESTOFPCCONFIG                                                            STD_OFF
#define ETHIF_ISDEF_MIRRORTXINFOOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_MODECHANGELOCKEDOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_PHYSLAYERINITELEMSOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_PHYSLAYERMODEELEMSOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNTOFPCCONFIG                                STD_OFF
#define ETHIF_ISDEF_PORTGROUPINDOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_PORTGROUPLINKSTATEOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_PORTGROUPMODEOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_PORTGROUPNOROLELINKCOUNTOFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_PORTGROUPOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_PORTGROUPSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                     STD_OFF
#define ETHIF_ISDEF_PORTMODEOFPCCONFIG                                                              STD_OFF
#define ETHIF_ISDEF_PORTSIGNALQUALITYRESULTOFPCCONFIG                                               STD_OFF
#define ETHIF_ISDEF_PORTSTARTUPACTIVETIMECOUNTEROFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_PORTSTARTUPACTIVETIMEFREQOFPCCONFIG                                             STD_OFF
#define ETHIF_ISDEF_PORTSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_REQUESTEDETHIFCTRLMODEOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_REQUESTEDETHTRCVMODEOFPCCONFIG                                                  STD_OFF
#define ETHIF_ISDEF_REQUESTEDETHTRCVSTATEOFETHIFCTRLOFPCCONFIG                                      STD_OFF
#define ETHIF_ISDEF_REQUESTEDPORTGROUPMODEOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_REQUESTEDPORTGROUPSTATEOFETHIFCTRLOFPCCONFIG                                    STD_OFF
#define ETHIF_ISDEF_REQUESTEDPORTMODEOFPCCONFIG                                                     STD_OFF
#define ETHIF_ISDEF_RXINDICATIONSOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_RXPDUCONTEXTOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_RXPDUFRAMETYPEOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_RXPDUFREELISTOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_RXPDUMETADATAOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_RXPDUOFPCCONFIG                                                                 STD_OFF
#define ETHIF_ISDEF_RXQUEUELISTOFPCCONFIG                                                           STD_OFF
#define ETHIF_ISDEF_SETCONTROLLERMODETIMEOUTOFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_SIGNALQUALITYCHGMAINRELOADOFPCCONFIG                                            STD_OFF
#define ETHIF_ISDEF_SIGNALQUALITYDECOUPLEFREQCNTOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_SIGNALQUALITYRESULTOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFECUCPARTITIONOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFETHCTRLOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_SIZEOFETHDRVAPIOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCLKUNITOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCTRLOFETHTRCVINDOFPCCONFIG                                           STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCTRLOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                         STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                         STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFCTRLTORXPDUMAPOFPCCONFIG                                             STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFMEASUREMENTDATAOFPCCONFIG                                            STD_OFF
#define ETHIF_ISDEF_SIZEOFETHIFPHYSCTRLCFGOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_SIZEOFETHRXQUEUEOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTDRVAPIOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTDRVOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTINDOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTPORTINDOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFETHSWTPORTOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_SIZEOFETHTRCVDRVAPIOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFETHTRCVOFPCCONFIG                                                         STD_OFF
#define ETHIF_ISDEF_SIZEOFETHTXQUEUEOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_SIZEOFEXPLICITBUFRELEASEFILTEROFPCCONFIG                                        STD_OFF
#define ETHIF_ISDEF_SIZEOFFLOATINGRXPDUMAPOFPCCONFIG                                                STD_OFF
#define ETHIF_ISDEF_SIZEOFGATEWAYSRCMACBLACKLISTOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_SIZEOFLEGACYWAKEUPMAPOFPCCONFIG                                                 STD_OFF
#define ETHIF_ISDEF_SIZEOFLINKSTATECHGINDICATIONSOFPCCONFIG                                         STD_OFF
#define ETHIF_ISDEF_SIZEOFMAINPARTITIONRXETHCTRLOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_SIZEOFMAINPARTITIONTXETHCTRLOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_SIZEOFMIRRORDESTOFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_SIZEOFMIRRORTXINFOOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_SIZEOFPHYSLAYERINITELEMSOFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_SIZEOFPHYSLAYERMODEELEMSOFPCCONFIG                                              STD_OFF
#define ETHIF_ISDEF_SIZEOFPORTGROUPINDOFPCCONFIG                                                    STD_OFF
#define ETHIF_ISDEF_SIZEOFPORTGROUPOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFPORTMODEOFPCCONFIG                                                        STD_OFF
#define ETHIF_ISDEF_SIZEOFREQUESTEDPORTMODEOFPCCONFIG                                               STD_OFF
#define ETHIF_ISDEF_SIZEOFRXINDICATIONSOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFRXPDUFRAMETYPEOFPCCONFIG                                                  STD_OFF
#define ETHIF_ISDEF_SIZEOFRXPDUMETADATAOFPCCONFIG                                                   STD_OFF
#define ETHIF_ISDEF_SIZEOFRXPDUOFPCCONFIG                                                           STD_OFF
#define ETHIF_ISDEF_SIZEOFRXQUEUELISTOFPCCONFIG                                                     STD_OFF
#define ETHIF_ISDEF_SIZEOFTXCONFIRMATIONSOFPCCONFIG                                                 STD_OFF
#define ETHIF_ISDEF_SIZEOFTXCONTEXTOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFTXPDUOFPCCONFIG                                                           STD_OFF
#define ETHIF_ISDEF_SIZEOFTXQUEUELISTOFPCCONFIG                                                     STD_OFF
#define ETHIF_ISDEF_SIZEOFWAKEUPMAPOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_SIZEOFWAKEUPSRCDEVICEOFPCCONFIG                                                 STD_OFF
#define ETHIF_ISDEF_SRCMACADDRBUFFEROFPCCONFIG                                                      STD_OFF
#define ETHIF_ISDEF_SWTPORTGROUPMODECHANGEREQCNTOFPCCONFIG                                          STD_OFF
#define ETHIF_ISDEF_SWTPORTGROUPMODECHANGERETRYCOUNTEROFPCCONFIG                                    STD_OFF
#define ETHIF_ISDEF_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                              STD_OFF
#define ETHIF_ISDEF_TXCONFIRMATIONSOFPCCONFIG                                                       STD_OFF
#define ETHIF_ISDEF_TXCONTEXTOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_TXPDUCONTEXTOFPCCONFIG                                                          STD_OFF
#define ETHIF_ISDEF_TXPDUOFPCCONFIG                                                                 STD_OFF
#define ETHIF_ISDEF_TXQUEUELISTOFPCCONFIG                                                           STD_OFF
#define ETHIF_ISDEF_WAKEUPMAPOFPCCONFIG                                                             STD_OFF
#define ETHIF_ISDEF_WAKEUPSRCDEVICEOFPCCONFIG                                                       STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCEqualsAlwaysToDefines  EthIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ETHIF_EQ2_QUALITYLEVELOFECUCPARTITION                                                       
#define ETHIF_EQ2_BUFIDXOFFSETENABLEDOFETHCTRL                                                      
#define ETHIF_EQ2_ETHARRELEASERXBUFFERSUPPORTEDOFETHCTRL                                            
#define ETHIF_EQ2_ETHDRVAPIIDXOFETHCTRL                                                             
#define ETHIF_EQ2_IMPLICITBUFFERRELEASENEEDEDOFETHCTRL                                              
#define ETHIF_EQ2_NUMOFTXBUFFERSOFETHCTRL                                                           
#define ETHIF_EQ2_SNVOFETHCTRL                                                                      
#define ETHIF_EQ2_TXCONTEXTENDIDXOFETHCTRL                                                          
#define ETHIF_EQ2_TXCONTEXTLENGTHOFETHCTRL                                                          
#define ETHIF_EQ2_TXCONTEXTSTARTIDXOFETHCTRL                                                        
#define ETHIF_EQ2_CTRLINITOFETHDRVAPI                                                               
#define ETHIF_EQ2_ENABLEEGRESSTIMESTAMPOFETHDRVAPI                                                  
#define ETHIF_EQ2_GETBANDWIDTHLIMITOFETHDRVAPI                                                      
#define ETHIF_EQ2_GETCTRLMODEOFETHDRVAPI                                                            
#define ETHIF_EQ2_GETCURRENTTIMEOFETHDRVAPI                                                         
#define ETHIF_EQ2_GETEGRESSTIMESTAMPOFETHDRVAPI                                                     
#define ETHIF_EQ2_GETINGRESSTIMESTAMPOFETHDRVAPI                                                    
#define ETHIF_EQ2_GETPHYSADDROFETHDRVAPI                                                            
#define ETHIF_EQ2_GETRXHEADERPTROFETHDRVAPI                                                         
#define ETHIF_EQ2_GETRXSTATSOFETHDRVAPI                                                             
#define ETHIF_EQ2_GETSPISTATUSOFETHDRVAPI                                                           
#define ETHIF_EQ2_GETTXHEADERPTROFETHDRVAPI                                                         
#define ETHIF_EQ2_GETTXSTATSOFETHDRVAPI                                                             
#define ETHIF_EQ2_IMMEDIATETRANSMITOFETHDRVAPI                                                      
#define ETHIF_EQ2_PROVIDEEXTTXBUFFEROFETHDRVAPI                                                     
#define ETHIF_EQ2_PROVIDETXBUFFEROFETHDRVAPI                                                        
#define ETHIF_EQ2_RECEIVEOFETHDRVAPI                                                                
#define ETHIF_EQ2_RECEIVEQUEUEOFETHDRVAPI                                                           
#define ETHIF_EQ2_RELEASERXBUFFEROFETHDRVAPI                                                        
#define ETHIF_EQ2_SETBANDWIDTHLIMITOFETHDRVAPI                                                      
#define ETHIF_EQ2_SETCTRLMODEOFETHDRVAPI                                                            
#define ETHIF_EQ2_SETPHYSADDROFETHDRVAPI                                                            
#define ETHIF_EQ2_TRANSMITOFETHDRVAPI                                                               
#define ETHIF_EQ2_TXCONFIRMATIONOFETHDRVAPI                                                         
#define ETHIF_EQ2_TXCONFIRMATIONQUEUEOFETHDRVAPI                                                    
#define ETHIF_EQ2_UPDATEPHYSADDRFILTEROFETHDRVAPI                                                   
#define ETHIF_EQ2_VGETEGRESSTIMESTAMPOFETHDRVAPI                                                    
#define ETHIF_EQ2_VRELEASERXBUFFEROFETHDRVAPI                                                       
#define ETHIF_EQ2_VTRANSMITOFETHDRVAPI                                                              
#define ETHIF_EQ2_ETHCLKUNITIDXOFETHIFCLKUNIT                                                       
#define ETHIF_EQ2_ETHIFCLKUNITIDXOFETHIFCLKUNIT                                                     
#define ETHIF_EQ2_ECUCPARTITIONIDXOFETHIFCTRL                                                       
#define ETHIF_EQ2_ECUCPARTITIONUSEDOFETHIFCTRL                                                      
#define ETHIF_EQ2_ETHCTRLIDXOFETHIFCTRL                                                             
#define ETHIF_EQ2_ETHIFCTRLTOETHERTYPEMAPENDIDXOFETHIFCTRL                                          
#define ETHIF_EQ2_ETHIFCTRLTOETHERTYPEMAPLENGTHOFETHIFCTRL                                          
#define ETHIF_EQ2_ETHIFCTRLTOETHERTYPEMAPSTARTIDXOFETHIFCTRL                                        
#define ETHIF_EQ2_ETHIFPHYSCTRLCFGIDXOFETHIFCTRL                                                    
#define ETHIF_EQ2_ETHSWTDRVAPIIDXOFETHIFCTRL                                                        
#define ETHIF_EQ2_ETHSWTDRVAPIUSEDOFETHIFCTRL                                                       
#define ETHIF_EQ2_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL                                             
#define ETHIF_EQ2_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL                                                
#define ETHIF_EQ2_GATEWAYDESTETHIFCTRLIDXUSEDOFETHIFCTRL                                            
#define ETHIF_EQ2_LINKAGGRTHRESHOLDOFETHIFCTRL                                                      
#define ETHIF_EQ2_MACSECTYPEOFETHIFCTRL                                                             
#define ETHIF_EQ2_MIRRORRXDESTIDXIDXOFETHIFCTRL                                                     
#define ETHIF_EQ2_MIRRORRXDESTIDXOFETHIFCTRL                                                        
#define ETHIF_EQ2_MIRRORRXDESTIDXUSEDOFETHIFCTRL                                                    
#define ETHIF_EQ2_MIRRORTXDESTIDXIDXOFETHIFCTRL                                                     
#define ETHIF_EQ2_MIRRORTXDESTIDXOFETHIFCTRL                                                        
#define ETHIF_EQ2_MIRRORTXDESTIDXUSEDOFETHIFCTRL                                                    
#define ETHIF_EQ2_MTUOFETHIFCTRL                                                                    
#define ETHIF_EQ2_PHYSLAYERINITELEMSIDXOFETHIFCTRL                                                  
#define ETHIF_EQ2_PHYSLAYERMODEELEMSIDXOFETHIFCTRL                                                  
#define ETHIF_EQ2_SNVOFETHIFCTRL                                                                    
#define ETHIF_EQ2_TYPEOFETHIFCTRL                                                                   
#define ETHIF_EQ2_VLANIDOFETHIFCTRL                                                                 
#define ETHIF_EQ2_ETHIFCTRLOFETHTRCVIND                                                             
#define ETHIF_EQ2_ETHIFCTRLOFPORTGROUPIND                                                           
#define ETHIF_EQ2_ETHERTYPEOFETHIFCTRLTOETHERTYPEMAP                                                
#define ETHIF_EQ2_RXINDICATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                      
#define ETHIF_EQ2_RXINDICATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                      
#define ETHIF_EQ2_RXINDICATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                    
#define ETHIF_EQ2_RXINDICATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                        
#define ETHIF_EQ2_TXCONFIRMATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP                                    
#define ETHIF_EQ2_TXCONFIRMATIONSLENGTHOFETHIFCTRLTOETHERTYPEMAP                                    
#define ETHIF_EQ2_TXCONFIRMATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP                                  
#define ETHIF_EQ2_TXCONFIRMATIONSUSEDOFETHIFCTRLTOETHERTYPEMAP                                      
#define ETHIF_EQ2_RXPDUCOUNTOFETHIFCTRLTORXPDUMAP                                                   
#define ETHIF_EQ2_RXPDUENDIDXOFETHIFCTRLTORXPDUMAP                                                  
#define ETHIF_EQ2_RXPDULENGTHOFETHIFCTRLTORXPDUMAP                                                  
#define ETHIF_EQ2_RXPDUSTARTIDXOFETHIFCTRLTORXPDUMAP                                                
#define ETHIF_EQ2_RXPDUUSEDOFETHIFCTRLTORXPDUMAP                                                    
#define ETHIF_EQ2_ETHCTRLIDXOFETHIFPHYSCTRLCFG                                                      
#define ETHIF_EQ2_ETHDRVAPIIDXOFETHIFPHYSCTRLCFG                                                    
#define ETHIF_EQ2_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG                                              
#define ETHIF_EQ2_ETHIFCLKUNITLENGTHOFETHIFPHYSCTRLCFG                                              
#define ETHIF_EQ2_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG                                            
#define ETHIF_EQ2_ETHIFCLKUNITUSEDOFETHIFPHYSCTRLCFG                                                
#define ETHIF_EQ2_ETHIFPHYSCONTROLLERIDXOFETHIFPHYSCTRLCFG                                          
#define ETHIF_EQ2_ETHPHCSUPPORTAVAILABLEOFETHIFPHYSCTRLCFG                                          
#define ETHIF_EQ2_ETHCTRLIDXOFETHRXQUEUE                                                            
#define ETHIF_EQ2_QUEUEINDEXOFETHRXQUEUE                                                            
#define ETHIF_EQ2_ETHSWTDRVAPIIDXOFETHSWT                                                           
#define ETHIF_EQ2_ETHSWTPORTINETHSWTCONTEXTENDIDXOFETHSWT                                           
#define ETHIF_EQ2_ETHSWTPORTINETHSWTCONTEXTLENGTHOFETHSWT                                           
#define ETHIF_EQ2_ETHSWTPORTINETHSWTCONTEXTSTARTIDXOFETHSWT                                         
#define ETHIF_EQ2_ETHSWTPORTINETHSWTCONTEXTUSEDOFETHSWT                                             
#define ETHIF_EQ2_SNVOFETHSWT                                                                       
#define ETHIF_EQ2_ETHSWTENDIDXOFETHSWTDRV                                                           
#define ETHIF_EQ2_ETHSWTLENGTHOFETHSWTDRV                                                           
#define ETHIF_EQ2_ETHSWTSTARTIDXOFETHSWTDRV                                                         
#define ETHIF_EQ2_CHECKWAKEUPOFETHSWTDRVAPI                                                         
#define ETHIF_EQ2_ENABLEVLANOFETHSWTDRVAPI                                                          
#define ETHIF_EQ2_GETARLTABLEOFETHSWTDRVAPI                                                         
#define ETHIF_EQ2_GETBAUDRATEOFETHSWTDRVAPI                                                         
#define ETHIF_EQ2_GETBUFFERLEVELOFETHSWTDRVAPI                                                      
#define ETHIF_EQ2_GETCOUNTERVALUESOFETHSWTDRVAPI                                                    
#define ETHIF_EQ2_GETDROPCOUNTOFETHSWTDRVAPI                                                        
#define ETHIF_EQ2_GETDUPLEXMODEOFETHSWTDRVAPI                                                       
#define ETHIF_EQ2_GETLINKSTATEOFETHSWTDRVAPI                                                        
#define ETHIF_EQ2_GETMACLEARNINGMODEOFETHSWTDRVAPI                                                  
#define ETHIF_EQ2_GETPORTCABLEDIAGNOSTICSRESULTOFETHSWTDRVAPI                                       
#define ETHIF_EQ2_GETPORTMACADDROFETHSWTDRVAPI                                                      
#define ETHIF_EQ2_GETPORTSIGNALQUALITYOFETHSWTDRVAPI                                                
#define ETHIF_EQ2_GETRXMGMTOBJECTOFETHSWTDRVAPI                                                     
#define ETHIF_EQ2_GETRXSTATSOFETHSWTDRVAPI                                                          
#define ETHIF_EQ2_GETSWITCHPORTWAKEUPREASONOFETHSWTDRVAPI                                           
#define ETHIF_EQ2_GETSWTPORTMODEOFETHSWTDRVAPI                                                      
#define ETHIF_EQ2_GETTXERRORCOUNTERVALUESOFETHSWTDRVAPI                                             
#define ETHIF_EQ2_GETTXMGMTOBJECTOFETHSWTDRVAPI                                                     
#define ETHIF_EQ2_GETTXSTATSOFETHSWTDRVAPI                                                          
#define ETHIF_EQ2_PORTENABLETIMESTAMPOFETHSWTDRVAPI                                                 
#define ETHIF_EQ2_RESETCONFIGOFETHSWTDRVAPI                                                         
#define ETHIF_EQ2_RUNPORTCABLEDIAGNOSTICOFETHSWTDRVAPI                                              
#define ETHIF_EQ2_SETCORRECTIONTIMEOFETHSWTDRVAPI                                                   
#define ETHIF_EQ2_SETMACLEARNINGMODEOFETHSWTDRVAPI                                                  
#define ETHIF_EQ2_SETSWTMGMTINFOOFETHSWTDRVAPI                                                      
#define ETHIF_EQ2_SETSWTPORTMODEOFETHSWTDRVAPI                                                      
#define ETHIF_EQ2_STARTQBVSCHEDULEOFETHSWTDRVAPI                                                    
#define ETHIF_EQ2_STARTSWTPORTAUTONEGOFETHSWTDRVAPI                                                 
#define ETHIF_EQ2_STOPQBVSCHEDULEOFETHSWTDRVAPI                                                     
#define ETHIF_EQ2_STORECONFIGOFETHSWTDRVAPI                                                         
#define ETHIF_EQ2_SWTINITOFETHSWTDRVAPI                                                             
#define ETHIF_EQ2_UPDATEMCASTPORTASSIGNMENTOFETHSWTDRVAPI                                           
#define ETHIF_EQ2_ETHSWTIND                                                                         
#define ETHIF_EQ2_ASYNCPROCESSINGOFETHSWTPORT                                                       
#define ETHIF_EQ2_ETHSWTIDXOFETHSWTPORT                                                             
#define ETHIF_EQ2_ETHSWTPORTHOSTORUPLINKPORTIDXOFETHSWTPORT                                         
#define ETHIF_EQ2_MACSECSECUREDOFETHSWTPORT                                                         
#define ETHIF_EQ2_MKAPAEIDXOFETHSWTPORT                                                             
#define ETHIF_EQ2_PORTGROUPINDENDIDXOFETHSWTPORT                                                    
#define ETHIF_EQ2_PORTGROUPINDSTARTIDXOFETHSWTPORT                                                  
#define ETHIF_EQ2_PORTROLEOFETHSWTPORT                                                              
#define ETHIF_EQ2_SNVOFETHSWTPORT                                                                   
#define ETHIF_EQ2_ETHSWTPORTIDXOFETHSWTPORTINETHSWTCONTEXT                                          
#define ETHIF_EQ2_ETHSWTPORTUSEDOFETHSWTPORTINETHSWTCONTEXT                                         
#define ETHIF_EQ2_ETHSWTPORTIND                                                                     
#define ETHIF_EQ2_ASYNCPROCESSINGOFETHTRCV                                                          
#define ETHIF_EQ2_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV                                              
#define ETHIF_EQ2_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV                                            
#define ETHIF_EQ2_ETHIFCTRLOFETHTRCVINDUSEDOFETHTRCV                                                
#define ETHIF_EQ2_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMECOUNTSOFETHTRCV                               
#define ETHIF_EQ2_ETHTRCVACTASSLAVEPASSIVEENABLEDOFETHTRCV                                          
#define ETHIF_EQ2_ETHTRCVDRVAPIIDXOFETHTRCV                                                         
#define ETHIF_EQ2_ETHTRCVTYPEOFETHTRCV                                                              
#define ETHIF_EQ2_MACSECSECUREDOFETHTRCV                                                            
#define ETHIF_EQ2_MKAPAEIDXOFETHTRCV                                                                
#define ETHIF_EQ2_PORTMODEIDXOFETHTRCV                                                              
#define ETHIF_EQ2_PORTMODEUSEDOFETHTRCV                                                             
#define ETHIF_EQ2_REQUESTEDPORTMODEIDXOFETHTRCV                                                     
#define ETHIF_EQ2_REQUESTEDPORTMODEUSEDOFETHTRCV                                                    
#define ETHIF_EQ2_SNVOFETHTRCV                                                                      
#define ETHIF_EQ2_USERSLEEPINDICATIONOFETHTRCV                                                      
#define ETHIF_EQ2_CHECKWAKEUPOFETHTRCVDRVAPI                                                        
#define ETHIF_EQ2_GETBAUDRATEOFETHTRCVDRVAPI                                                        
#define ETHIF_EQ2_GETCABLEDIAGNOSTICSRESULTOFETHTRCVDRVAPI                                          
#define ETHIF_EQ2_GETDUPLEXMODEOFETHTRCVDRVAPI                                                      
#define ETHIF_EQ2_GETLINKSTATEOFETHTRCVDRVAPI                                                       
#define ETHIF_EQ2_GETPHYSIGNALQUALITYOFETHTRCVDRVAPI                                                
#define ETHIF_EQ2_GETPHYWAKEUPREASONOFETHTRCVDRVAPI                                                 
#define ETHIF_EQ2_GETTRCVMODEOFETHTRCVDRVAPI                                                        
#define ETHIF_EQ2_RUNCABLEDIAGNOSTICOFETHTRCVDRVAPI                                                 
#define ETHIF_EQ2_SETPHYLOOPBACKMODEOFETHTRCVDRVAPI                                                 
#define ETHIF_EQ2_SETPHYTESTMODEOFETHTRCVDRVAPI                                                     
#define ETHIF_EQ2_SETPHYTXMODEOFETHTRCVDRVAPI                                                       
#define ETHIF_EQ2_SETTRCVMODEOFETHTRCVDRVAPI                                                        
#define ETHIF_EQ2_STARTAUTONEGOFETHTRCVDRVAPI                                                       
#define ETHIF_EQ2_TRCVINITOFETHTRCVDRVAPI                                                           
#define ETHIF_EQ2_ETHCTRLIDXOFETHTXQUEUE                                                            
#define ETHIF_EQ2_QUEUEINDEXOFETHTXQUEUE                                                            
#define ETHIF_EQ2_ETHIFCTRLIDXOFEXPLICITBUFRELEASEFILTER                                            
#define ETHIF_EQ2_ETHERTYPECONFIGUREDOFEXPLICITBUFRELEASEFILTER                                     
#define ETHIF_EQ2_ETHERTYPEOFEXPLICITBUFRELEASEFILTER                                               
#define ETHIF_EQ2_RXPDUENDIDXOFFLOATINGRXPDUMAP                                                     
#define ETHIF_EQ2_RXPDULENGTHOFFLOATINGRXPDUMAP                                                     
#define ETHIF_EQ2_RXPDUSTARTIDXOFFLOATINGRXPDUMAP                                                   
#define ETHIF_EQ2_RXPDUUSEDOFFLOATINGRXPDUMAP                                                       
#define ETHIF_EQ2_MACADDROFGATEWAYSRCMACBLACKLIST                                                   
#define ETHIF_EQ2_ETHTRCVIDXOFLEGACYWAKEUPMAP                                                       
#define ETHIF_EQ2_WAKEUPSOURCEOFLEGACYWAKEUPMAP                                                     
#define ETHIF_EQ2_LINKSTATECHGINDICATIONS                                                           
#define ETHIF_EQ2_ETHCTRLIDXOFMAINPARTITIONRXETHCTRL                                                
#define ETHIF_EQ2_ETHCTRLIDXOFMAINPARTITIONTXETHCTRL                                                
#define ETHIF_EQ2_ETHCTRLIDXOFMIRRORDEST                                                            
#define ETHIF_EQ2_KEEPSRCMACENABLEDOFMIRRORDEST                                                     
#define ETHIF_EQ2_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS                                               
#define ETHIF_EQ2_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS                                             
#define ETHIF_EQ2_ETHSWTINDUSEDOFPHYSLAYERINITELEMS                                                 
#define ETHIF_EQ2_ETHTRCVIDXOFPHYSLAYERINITELEMS                                                    
#define ETHIF_EQ2_ETHTRCVUSEDOFPHYSLAYERINITELEMS                                                   
#define ETHIF_EQ2_ETHTRCVIDXOFPHYSLAYERMODEELEMS                                                    
#define ETHIF_EQ2_ETHTRCVUSEDOFPHYSLAYERMODEELEMS                                                   
#define ETHIF_EQ2_PORTGROUPIDXOFPHYSLAYERMODEELEMS                                                  
#define ETHIF_EQ2_PORTGROUPUSEDOFPHYSLAYERMODEELEMS                                                 
#define ETHIF_EQ2_ETHIFCTRLOFPORTGROUPINDENDIDXOFPORTGROUP                                          
#define ETHIF_EQ2_ETHIFCTRLOFPORTGROUPINDSTARTIDXOFPORTGROUP                                        
#define ETHIF_EQ2_ETHIFCTRLOFPORTGROUPINDUSEDOFPORTGROUP                                            
#define ETHIF_EQ2_ETHSWTPORTINDENDIDXOFPORTGROUP                                                    
#define ETHIF_EQ2_ETHSWTPORTINDSTARTIDXOFPORTGROUP                                                  
#define ETHIF_EQ2_HOSTANDUPLINKPORTTHRESHOLDOFPORTGROUP                                             
#define ETHIF_EQ2_NOROLEPORTTHRESHOLDOFPORTGROUP                                                    
#define ETHIF_EQ2_SEMANTICOFPORTGROUP                                                               
#define ETHIF_EQ2_SNVOFPORTGROUP                                                                    
#define ETHIF_EQ2_PORTGROUPIND                                                                      
#define ETHIF_EQ2_RXINDICATIONS                                                                     
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPIDXOFRXPDU                                                     
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPUSEDOFRXPDU                                                    
#define ETHIF_EQ2_ETHMACADDROFFSETOFRXPDU                                                           
#define ETHIF_EQ2_FLOATINGPOOLOFRXPDU                                                               
#define ETHIF_EQ2_FLOATINGRXPDUMAPIDXOFRXPDU                                                        
#define ETHIF_EQ2_FLOATINGRXPDUMAPUSEDOFRXPDU                                                       
#define ETHIF_EQ2_KEEPLOCALBUFFEROFRXPDU                                                            
#define ETHIF_EQ2_RXPDUMETADATAENDIDXOFRXPDU                                                        
#define ETHIF_EQ2_RXPDUMETADATALENGTHOFRXPDU                                                        
#define ETHIF_EQ2_RXPDUMETADATASTARTIDXOFRXPDU                                                      
#define ETHIF_EQ2_RXPDUMETADATAUSEDOFRXPDU                                                          
#define ETHIF_EQ2_TIMETUPLEPTROFFSETOFRXPDU                                                         
#define ETHIF_EQ2_ULPDUIDOFRXPDU                                                                    
#define ETHIF_EQ2_VALIDETHMACADDRMETADATAOFRXPDU                                                    
#define ETHIF_EQ2_VALIDTIMETUPLEMETADATAOFRXPDU                                                     
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPENDIDXOFRXPDUFRAMETYPE                                         
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPLENGTHOFRXPDUFRAMETYPE                                         
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                       
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPUSEDOFRXPDUFRAMETYPE                                           
#define ETHIF_EQ2_ETHERTYPEOFRXPDUFRAMETYPE                                                         
#define ETHIF_EQ2_FLOATINGRXPDUMAPENDIDXOFRXPDUFRAMETYPE                                            
#define ETHIF_EQ2_FLOATINGRXPDUMAPLENGTHOFRXPDUFRAMETYPE                                            
#define ETHIF_EQ2_FLOATINGRXPDUMAPSTARTIDXOFRXPDUFRAMETYPE                                          
#define ETHIF_EQ2_FLOATINGRXPDUMAPUSEDOFRXPDUFRAMETYPE                                              
#define ETHIF_EQ2_ETHRXQUEUEENDIDXOFRXQUEUELIST                                                     
#define ETHIF_EQ2_ETHRXQUEUELENGTHOFRXQUEUELIST                                                     
#define ETHIF_EQ2_ETHRXQUEUESTARTIDXOFRXQUEUELIST                                                   
#define ETHIF_EQ2_ETHRXQUEUEUSEDOFRXQUEUELIST                                                       
#define ETHIF_EQ2_TXCONFIRMATIONS                                                                   
#define ETHIF_EQ2_DIRECTDATAPROVISIONOFTXPDU                                                        
#define ETHIF_EQ2_EGRESSHARDWARESUPPORTEDDATATRANSFEROFTXPDU                                        
#define ETHIF_EQ2_ETHIFCTRLIDXOFTXPDU                                                               
#define ETHIF_EQ2_ETHIFCTRLUSEDOFTXPDU                                                              
#define ETHIF_EQ2_ETHMACADDROFFSETOFTXPDU                                                           
#define ETHIF_EQ2_ETHERTYPEOFTXPDU                                                                  
#define ETHIF_EQ2_FRAMETXPRIORITYOFTXPDU                                                            
#define ETHIF_EQ2_KEEPLOCALBUFFEROFTXPDU                                                            
#define ETHIF_EQ2_LISTITEMPTROFFSETOFTXPDU                                                          
#define ETHIF_EQ2_PRIORITYOFFSETOFTXPDU                                                             
#define ETHIF_EQ2_TIMETUPLEPTROFFSETOFTXPDU                                                         
#define ETHIF_EQ2_TOTALMETADATALENGTHOFTXPDU                                                        
#define ETHIF_EQ2_ULPDUIDOFTXPDU                                                                    
#define ETHIF_EQ2_VLANOFFSETOFTXPDU                                                                 
#define ETHIF_EQ2_VALIDETHMACADDRMETADATAOFTXPDU                                                    
#define ETHIF_EQ2_VALIDLISTITEMMETADATAOFTXPDU                                                      
#define ETHIF_EQ2_VALIDPRIORITY8METADATAOFTXPDU                                                     
#define ETHIF_EQ2_VALIDTIMETUPLEMETADATAOFTXPDU                                                     
#define ETHIF_EQ2_VALIDVLAN16METADATAOFTXPDU                                                        
#define ETHIF_EQ2_ETHTXQUEUEENDIDXOFTXQUEUELIST                                                     
#define ETHIF_EQ2_ETHTXQUEUELENGTHOFTXQUEUELIST                                                     
#define ETHIF_EQ2_ETHTXQUEUESTARTIDXOFTXQUEUELIST                                                   
#define ETHIF_EQ2_ETHTXQUEUEUSEDOFTXQUEUELIST                                                       
#define ETHIF_EQ2_WAKEUPSOURCEMASKOFWAKEUPMAP                                                       
#define ETHIF_EQ2_WAKEUPSRCDEVICEENDIDXOFWAKEUPMAP                                                  
#define ETHIF_EQ2_WAKEUPSRCDEVICELENGTHOFWAKEUPMAP                                                  
#define ETHIF_EQ2_WAKEUPSRCDEVICESTARTIDXOFWAKEUPMAP                                                
#define ETHIF_EQ2_WAKEUPSRCDEVICEUSEDOFWAKEUPMAP                                                    
#define ETHIF_EQ2_ETHSWTIDXOFWAKEUPSRCDEVICE                                                        
#define ETHIF_EQ2_ETHSWTUSEDOFWAKEUPSRCDEVICE                                                       
#define ETHIF_EQ2_ETHTRCVIDXOFWAKEUPSRCDEVICE                                                       
#define ETHIF_EQ2_ETHTRCVUSEDOFWAKEUPSRCDEVICE                                                      
#define ETHIF_EQ2_TYPEOFWAKEUPSRCDEVICE                                                             
#define ETHIF_EQ2_DEDICATEDRXPDUNEXTFREEPOSOFPCCONFIG                                               
#define ETHIF_EQ2_ECUCPARTITIONOFPCCONFIG                                                           
#define ETHIF_EQ2_ETHCTRLINITCNTOFPCCONFIG                                                          
#define ETHIF_EQ2_ETHCTRLMODECNTOFPCCONFIG                                                          
#define ETHIF_EQ2_ETHCTRLOFPCCONFIG                                                                 
#define ETHIF_EQ2_ETHCTRLSTATEOFPCCONFIG                                                            
#define ETHIF_EQ2_ETHDRVAPIOFPCCONFIG                                                               
#define ETHIF_EQ2_ETHIFCLKUNITOFPCCONFIG                                                            
#define ETHIF_EQ2_ETHIFCONTROLLERMODECHANGEREQCNTOFPCCONFIG                                         
#define ETHIF_EQ2_ETHIFCTRLINITSTATEOFPCCONFIG                                                      
#define ETHIF_EQ2_ETHIFCTRLLINKCOUNTOFPCCONFIG                                                      
#define ETHIF_EQ2_ETHIFCTRLLINKSTATEOFPCCONFIG                                                      
#define ETHIF_EQ2_ETHIFCTRLMODEOFPCCONFIG                                                           
#define ETHIF_EQ2_ETHIFCTRLOFETHTRCVINDOFPCCONFIG                                                   
#define ETHIF_EQ2_ETHIFCTRLOFPCCONFIG                                                               
#define ETHIF_EQ2_ETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                                 
#define ETHIF_EQ2_ETHIFCTRLRXSTATSOFPCCONFIG                                                        
#define ETHIF_EQ2_ETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                                 
#define ETHIF_EQ2_ETHIFCTRLTORXPDUMAPOFPCCONFIG                                                     
#define ETHIF_EQ2_ETHIFCTRLTXSTATSOFPCCONFIG                                                        
#define ETHIF_EQ2_ETHIFMEASUREMENTDATAOFPCCONFIG                                                    
#define ETHIF_EQ2_ETHIFPHYSCTRLCFGOFPCCONFIG                                                        
#define ETHIF_EQ2_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERCOUNTEROFPCCONFIG                            
#define ETHIF_EQ2_ETHIFQUALIFIEDUNEXPECTEDLINKDOWNTIMERSTATEOFPCCONFIG                              
#define ETHIF_EQ2_ETHIFSWITCHOFFPORTGROUPTIMERDELAYCOUNTEROFPCCONFIG                                
#define ETHIF_EQ2_ETHIFSWITCHOFFPORTGROUPTIMERDELAYSTATEOFPCCONFIG                                  
#define ETHIF_EQ2_ETHIFSWITCHOFFPORTTIMEDELAYCOUNTSOFPCCONFIG                                       
#define ETHIF_EQ2_ETHIFSWITCHOFFPORTTIMEDELAYREQCNTOFPCCONFIG                                       
#define ETHIF_EQ2_ETHIFSWITCHOFFPORTTIMERDELAYSTATEOFPCCONFIG                                       
#define ETHIF_EQ2_ETHIFSWTPORTGROUPSTATEOFPCCONFIG                                                  
#define ETHIF_EQ2_ETHRXQUEUEOFPCCONFIG                                                              
#define ETHIF_EQ2_ETHSWTDRVAPIOFPCCONFIG                                                            
#define ETHIF_EQ2_ETHSWTDRVOFPCCONFIG                                                               
#define ETHIF_EQ2_ETHSWTINDOFPCCONFIG                                                               
#define ETHIF_EQ2_ETHSWTINITCNTOFPCCONFIG                                                           
#define ETHIF_EQ2_ETHSWTOFPCCONFIG                                                                  
#define ETHIF_EQ2_ETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                               
#define ETHIF_EQ2_ETHSWTPORTINDOFPCCONFIG                                                           
#define ETHIF_EQ2_ETHSWTPORTLINKSTATEOFPCCONFIG                                                     
#define ETHIF_EQ2_ETHSWTPORTMODECNTOFPCCONFIG                                                       
#define ETHIF_EQ2_ETHSWTPORTOFPCCONFIG                                                              
#define ETHIF_EQ2_ETHTRCVDRVAPIOFPCCONFIG                                                           
#define ETHIF_EQ2_ETHTRCVINITCNTOFPCCONFIG                                                          
#define ETHIF_EQ2_ETHTRCVLINKSTATEOFPCCONFIG                                                        
#define ETHIF_EQ2_ETHTRCVMODECHANGERETRYCOUNTEROFPCCONFIG                                           
#define ETHIF_EQ2_ETHTRCVMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                     
#define ETHIF_EQ2_ETHTRCVMODECNTOFPCCONFIG                                                          
#define ETHIF_EQ2_ETHTRCVMODEOFPCCONFIG                                                             
#define ETHIF_EQ2_ETHTRCVOFPCCONFIG                                                                 
#define ETHIF_EQ2_ETHTRCVSTATEOFPCCONFIG                                                            
#define ETHIF_EQ2_ETHTXQUEUEOFPCCONFIG                                                              
#define ETHIF_EQ2_EXPLICITBUFRELEASEFILTEROFPCCONFIG                                                
#define ETHIF_EQ2_FLOATINGRXPDUMAPOFPCCONFIG                                                        
#define ETHIF_EQ2_FLOATINGRXPDUNEXTFREEPOSOFPCCONFIG                                                
#define ETHIF_EQ2_GATEWAYSRCMACBLACKLISTOFPCCONFIG                                                  
#define ETHIF_EQ2_GLOBALMODECHANGEMAXRETRYCOUNTOFPCCONFIG                                           
#define ETHIF_EQ2_GLOBALMODECHANGERETRYPERIODCOUNTOFPCCONFIG                                        
#define ETHIF_EQ2_GLOBALSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                          
#define ETHIF_EQ2_INITLOCKEDOFPCCONFIG                                                              
#define ETHIF_EQ2_LEGACYWAKEUPMAPOFPCCONFIG                                                         
#define ETHIF_EQ2_LINKSTATECHGINDICATIONSOFPCCONFIG                                                 
#define ETHIF_EQ2_LINKSTATECHGMAINRELOADOFPCCONFIG                                                  
#define ETHIF_EQ2_MAINFUNCSTATEDECOUPLEFREQCNTOFPCCONFIG                                            
#define ETHIF_EQ2_MAINPARTITIONRXETHCTRLOFPCCONFIG                                                  
#define ETHIF_EQ2_MAINPARTITIONTXETHCTRLOFPCCONFIG                                                  
#define ETHIF_EQ2_MAXRXFRAMEPERETHCTRLOFPCCONFIG                                                    
#define ETHIF_EQ2_MAXTXBUFPERETHCTRLOFPCCONFIG                                                      
#define ETHIF_EQ2_MIRRORDESTOFPCCONFIG                                                              
#define ETHIF_EQ2_MIRRORTXINFOOFPCCONFIG                                                            
#define ETHIF_EQ2_MODECHANGELOCKEDOFPCCONFIG                                                        
#define ETHIF_EQ2_PHYSLAYERINITELEMSOFPCCONFIG                                                      
#define ETHIF_EQ2_PHYSLAYERMODEELEMSOFPCCONFIG                                                      
#define ETHIF_EQ2_PORTGROUPHOSTORUPLINKPORTROLELINKCOUNTOFPCCONFIG                                  
#define ETHIF_EQ2_PORTGROUPINDOFPCCONFIG                                                            
#define ETHIF_EQ2_PORTGROUPLINKSTATEOFPCCONFIG                                                      
#define ETHIF_EQ2_PORTGROUPMODEOFPCCONFIG                                                           
#define ETHIF_EQ2_PORTGROUPNOROLELINKCOUNTOFPCCONFIG                                                
#define ETHIF_EQ2_PORTGROUPOFPCCONFIG                                                               
#define ETHIF_EQ2_PORTGROUPSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                       
#define ETHIF_EQ2_PORTMODEOFPCCONFIG                                                                
#define ETHIF_EQ2_PORTSIGNALQUALITYRESULTOFPCCONFIG                                                 
#define ETHIF_EQ2_PORTSTARTUPACTIVETIMECOUNTEROFPCCONFIG                                            
#define ETHIF_EQ2_PORTSTARTUPACTIVETIMEFREQOFPCCONFIG                                               
#define ETHIF_EQ2_PORTSTARTUPACTIVETIMERACTIVEOFPCCONFIG                                            
#define ETHIF_EQ2_REQUESTEDETHIFCTRLMODEOFPCCONFIG                                                  
#define ETHIF_EQ2_REQUESTEDETHTRCVMODEOFPCCONFIG                                                    
#define ETHIF_EQ2_REQUESTEDETHTRCVSTATEOFETHIFCTRLOFPCCONFIG                                        
#define ETHIF_EQ2_REQUESTEDPORTGROUPMODEOFPCCONFIG                                                  
#define ETHIF_EQ2_REQUESTEDPORTGROUPSTATEOFETHIFCTRLOFPCCONFIG                                      
#define ETHIF_EQ2_REQUESTEDPORTMODEOFPCCONFIG                                                       
#define ETHIF_EQ2_RXINDICATIONSOFPCCONFIG                                                           
#define ETHIF_EQ2_RXPDUCONTEXTOFPCCONFIG                                                            
#define ETHIF_EQ2_RXPDUFRAMETYPEOFPCCONFIG                                                          
#define ETHIF_EQ2_RXPDUFREELISTOFPCCONFIG                                                           
#define ETHIF_EQ2_RXPDUMETADATAOFPCCONFIG                                                           
#define ETHIF_EQ2_RXPDUOFPCCONFIG                                                                   
#define ETHIF_EQ2_RXQUEUELISTOFPCCONFIG                                                             
#define ETHIF_EQ2_SETCONTROLLERMODETIMEOUTOFPCCONFIG                                                
#define ETHIF_EQ2_SIGNALQUALITYCHGMAINRELOADOFPCCONFIG                                              
#define ETHIF_EQ2_SIGNALQUALITYDECOUPLEFREQCNTOFPCCONFIG                                            
#define ETHIF_EQ2_SIGNALQUALITYRESULTOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFECUCPARTITIONOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFETHCTRLOFPCCONFIG                                                           
#define ETHIF_EQ2_SIZEOFETHDRVAPIOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFETHIFCLKUNITOFPCCONFIG                                                      
#define ETHIF_EQ2_SIZEOFETHIFCTRLOFETHTRCVINDOFPCCONFIG                                             
#define ETHIF_EQ2_SIZEOFETHIFCTRLOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFETHIFCTRLOFPORTGROUPINDOFPCCONFIG                                           
#define ETHIF_EQ2_SIZEOFETHIFCTRLTOETHERTYPEMAPOFPCCONFIG                                           
#define ETHIF_EQ2_SIZEOFETHIFCTRLTORXPDUMAPOFPCCONFIG                                               
#define ETHIF_EQ2_SIZEOFETHIFMEASUREMENTDATAOFPCCONFIG                                              
#define ETHIF_EQ2_SIZEOFETHIFPHYSCTRLCFGOFPCCONFIG                                                  
#define ETHIF_EQ2_SIZEOFETHRXQUEUEOFPCCONFIG                                                        
#define ETHIF_EQ2_SIZEOFETHSWTDRVAPIOFPCCONFIG                                                      
#define ETHIF_EQ2_SIZEOFETHSWTDRVOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFETHSWTINDOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFETHSWTOFPCCONFIG                                                            
#define ETHIF_EQ2_SIZEOFETHSWTPORTINETHSWTCONTEXTOFPCCONFIG                                         
#define ETHIF_EQ2_SIZEOFETHSWTPORTINDOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFETHSWTPORTOFPCCONFIG                                                        
#define ETHIF_EQ2_SIZEOFETHTRCVDRVAPIOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFETHTRCVOFPCCONFIG                                                           
#define ETHIF_EQ2_SIZEOFETHTXQUEUEOFPCCONFIG                                                        
#define ETHIF_EQ2_SIZEOFEXPLICITBUFRELEASEFILTEROFPCCONFIG                                          
#define ETHIF_EQ2_SIZEOFFLOATINGRXPDUMAPOFPCCONFIG                                                  
#define ETHIF_EQ2_SIZEOFGATEWAYSRCMACBLACKLISTOFPCCONFIG                                            
#define ETHIF_EQ2_SIZEOFLEGACYWAKEUPMAPOFPCCONFIG                                                   
#define ETHIF_EQ2_SIZEOFLINKSTATECHGINDICATIONSOFPCCONFIG                                           
#define ETHIF_EQ2_SIZEOFMAINPARTITIONRXETHCTRLOFPCCONFIG                                            
#define ETHIF_EQ2_SIZEOFMAINPARTITIONTXETHCTRLOFPCCONFIG                                            
#define ETHIF_EQ2_SIZEOFMIRRORDESTOFPCCONFIG                                                        
#define ETHIF_EQ2_SIZEOFMIRRORTXINFOOFPCCONFIG                                                      
#define ETHIF_EQ2_SIZEOFPHYSLAYERINITELEMSOFPCCONFIG                                                
#define ETHIF_EQ2_SIZEOFPHYSLAYERMODEELEMSOFPCCONFIG                                                
#define ETHIF_EQ2_SIZEOFPORTGROUPINDOFPCCONFIG                                                      
#define ETHIF_EQ2_SIZEOFPORTGROUPOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFPORTMODEOFPCCONFIG                                                          
#define ETHIF_EQ2_SIZEOFREQUESTEDPORTMODEOFPCCONFIG                                                 
#define ETHIF_EQ2_SIZEOFRXINDICATIONSOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFRXPDUFRAMETYPEOFPCCONFIG                                                    
#define ETHIF_EQ2_SIZEOFRXPDUMETADATAOFPCCONFIG                                                     
#define ETHIF_EQ2_SIZEOFRXPDUOFPCCONFIG                                                             
#define ETHIF_EQ2_SIZEOFRXQUEUELISTOFPCCONFIG                                                       
#define ETHIF_EQ2_SIZEOFTXCONFIRMATIONSOFPCCONFIG                                                   
#define ETHIF_EQ2_SIZEOFTXCONTEXTOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFTXPDUOFPCCONFIG                                                             
#define ETHIF_EQ2_SIZEOFTXQUEUELISTOFPCCONFIG                                                       
#define ETHIF_EQ2_SIZEOFWAKEUPMAPOFPCCONFIG                                                         
#define ETHIF_EQ2_SIZEOFWAKEUPSRCDEVICEOFPCCONFIG                                                   
#define ETHIF_EQ2_SRCMACADDRBUFFEROFPCCONFIG                                                        
#define ETHIF_EQ2_SWTPORTGROUPMODECHANGEREQCNTOFPCCONFIG                                            
#define ETHIF_EQ2_SWTPORTGROUPMODECHANGERETRYCOUNTEROFPCCONFIG                                      
#define ETHIF_EQ2_SWTPORTGROUPMODECHANGERETRYPERIODCOUNTEROFPCCONFIG                                
#define ETHIF_EQ2_TXCONFIRMATIONSOFPCCONFIG                                                         
#define ETHIF_EQ2_TXCONTEXTOFPCCONFIG                                                               
#define ETHIF_EQ2_TXPDUCONTEXTOFPCCONFIG                                                            
#define ETHIF_EQ2_TXPDUOFPCCONFIG                                                                   
#define ETHIF_EQ2_TXQUEUELISTOFPCCONFIG                                                             
#define ETHIF_EQ2_WAKEUPMAPOFPCCONFIG                                                               
#define ETHIF_EQ2_WAKEUPSRCDEVICEOFPCCONFIG                                                         
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSymbolicInitializationPointers  EthIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define EthIf_Config_RDR_01_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_01)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_02_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_03_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_03)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_04_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_05_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_06_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_07_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
#define EthIf_Config_RDR_08_Ptr                                                                     &(EthIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'EthIf' */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCInitializationSymbols  EthIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define EthIf_Config_RDR_01                                                                         EthIf_PCConfig.Config_RDR_01  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_02                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_03                                                                         EthIf_PCConfig.Config_RDR_03  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_04                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_05                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_06                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_07                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
#define EthIf_Config_RDR_08                                                                         EthIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'EthIf */
/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCGeneral  EthIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ETHIF_CHECK_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ETHIF_FINAL_MAGIC_NUMBER                                                                    0x891Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of EthIf */
#define ETHIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'EthIf' is not configured to be postbuild capable. */
#define ETHIF_INIT_DATA                                                                             ETHIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ETHIF_INIT_DATA_HASH_CODE                                                                   1009827189  /**< the precompile constant to validate the initialization structure at initialization time of EthIf with a hashcode. The seed value is '0x891Eu' */
#define ETHIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ETHIF_USE_INIT_POINTER                                                                      STD_ON  /**< STD_ON if the init pointer EthIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCSizeOfTypes  EthIf SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for EthIf_SizeOfDedicatedRxPduNextFreePos */
typedef uint8 EthIf_SizeOfDedicatedRxPduNextFreePosType;

/**   \brief  value based type definition for EthIf_SizeOfEcucPartition */
typedef uint8 EthIf_SizeOfEcucPartitionType;

/**   \brief  value based type definition for EthIf_SizeOfEthCtrl */
typedef uint8 EthIf_SizeOfEthCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfEthCtrlInitCnt */
typedef uint8 EthIf_SizeOfEthCtrlInitCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthCtrlModeCnt */
typedef uint8 EthIf_SizeOfEthCtrlModeCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthCtrlState */
typedef uint8 EthIf_SizeOfEthCtrlStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthDrvApi */
typedef uint8 EthIf_SizeOfEthDrvApiType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfClkUnit */
typedef uint8 EthIf_SizeOfEthIfClkUnitType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrl */
typedef uint8 EthIf_SizeOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlInitState */
typedef uint8 EthIf_SizeOfEthIfCtrlInitStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlLinkCount */
typedef uint8 EthIf_SizeOfEthIfCtrlLinkCountType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlLinkState */
typedef uint8 EthIf_SizeOfEthIfCtrlLinkStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlMode */
typedef uint8 EthIf_SizeOfEthIfCtrlModeType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlOfEthTrcvInd */
typedef uint8 EthIf_SizeOfEthIfCtrlOfEthTrcvIndType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlOfPortGroupInd */
typedef uint8 EthIf_SizeOfEthIfCtrlOfPortGroupIndType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlRxStats */
typedef uint8 EthIf_SizeOfEthIfCtrlRxStatsType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_SizeOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlToRxPduMap */
typedef uint8 EthIf_SizeOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfCtrlTxStats */
typedef uint8 EthIf_SizeOfEthIfCtrlTxStatsType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfMeasurementData */
typedef uint8 EthIf_SizeOfEthIfMeasurementDataType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfPhysCtrlCfg */
typedef uint8 EthIf_SizeOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfQualifiedUnexpectedLinkDownTimerCounter */
typedef uint8 EthIf_SizeOfEthIfQualifiedUnexpectedLinkDownTimerCounterType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfQualifiedUnexpectedLinkDownTimerState */
typedef uint8 EthIf_SizeOfEthIfQualifiedUnexpectedLinkDownTimerStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfSwitchOffPortGroupTimerDelayCounter */
typedef uint8 EthIf_SizeOfEthIfSwitchOffPortGroupTimerDelayCounterType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfSwitchOffPortGroupTimerDelayState */
typedef uint8 EthIf_SizeOfEthIfSwitchOffPortGroupTimerDelayStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfSwitchOffPortTimerDelayState */
typedef uint8 EthIf_SizeOfEthIfSwitchOffPortTimerDelayStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthIfSwtPortGroupState */
typedef uint8 EthIf_SizeOfEthIfSwtPortGroupStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthRxQueue */
typedef uint8 EthIf_SizeOfEthRxQueueType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwt */
typedef uint8 EthIf_SizeOfEthSwtType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtDrv */
typedef uint8 EthIf_SizeOfEthSwtDrvType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtDrvApi */
typedef uint8 EthIf_SizeOfEthSwtDrvApiType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtInd */
typedef uint8 EthIf_SizeOfEthSwtIndType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtInitCnt */
typedef uint8 EthIf_SizeOfEthSwtInitCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtPort */
typedef uint8 EthIf_SizeOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtPortInEthSwtContext */
typedef uint8 EthIf_SizeOfEthSwtPortInEthSwtContextType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtPortInd */
typedef uint8 EthIf_SizeOfEthSwtPortIndType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtPortLinkState */
typedef uint8 EthIf_SizeOfEthSwtPortLinkStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthSwtPortModeCnt */
typedef uint8 EthIf_SizeOfEthSwtPortModeCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcv */
typedef uint8 EthIf_SizeOfEthTrcvType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvDrvApi */
typedef uint8 EthIf_SizeOfEthTrcvDrvApiType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvInitCnt */
typedef uint8 EthIf_SizeOfEthTrcvInitCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvLinkState */
typedef uint8 EthIf_SizeOfEthTrcvLinkStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvMode */
typedef uint8 EthIf_SizeOfEthTrcvModeType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvModeChangeRetryCounter */
typedef uint8 EthIf_SizeOfEthTrcvModeChangeRetryCounterType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvModeChangeRetryPeriodCounter */
typedef uint8 EthIf_SizeOfEthTrcvModeChangeRetryPeriodCounterType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvModeCnt */
typedef uint8 EthIf_SizeOfEthTrcvModeCntType;

/**   \brief  value based type definition for EthIf_SizeOfEthTrcvState */
typedef uint8 EthIf_SizeOfEthTrcvStateType;

/**   \brief  value based type definition for EthIf_SizeOfEthTxQueue */
typedef uint8 EthIf_SizeOfEthTxQueueType;

/**   \brief  value based type definition for EthIf_SizeOfExplicitBufReleaseFilter */
typedef uint8 EthIf_SizeOfExplicitBufReleaseFilterType;

/**   \brief  value based type definition for EthIf_SizeOfFloatingRxPduMap */
typedef uint8 EthIf_SizeOfFloatingRxPduMapType;

/**   \brief  value based type definition for EthIf_SizeOfFloatingRxPduNextFreePos */
typedef uint8 EthIf_SizeOfFloatingRxPduNextFreePosType;

/**   \brief  value based type definition for EthIf_SizeOfGatewaySrcMacBlackList */
typedef uint8 EthIf_SizeOfGatewaySrcMacBlackListType;

/**   \brief  value based type definition for EthIf_SizeOfLegacyWakeupMap */
typedef uint8 EthIf_SizeOfLegacyWakeupMapType;

/**   \brief  value based type definition for EthIf_SizeOfLinkStateChgIndications */
typedef uint8 EthIf_SizeOfLinkStateChgIndicationsType;

/**   \brief  value based type definition for EthIf_SizeOfMainPartitionRxEthCtrl */
typedef uint8 EthIf_SizeOfMainPartitionRxEthCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfMainPartitionTxEthCtrl */
typedef uint8 EthIf_SizeOfMainPartitionTxEthCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfMirrorDest */
typedef uint8 EthIf_SizeOfMirrorDestType;

/**   \brief  value based type definition for EthIf_SizeOfMirrorTxInfo */
typedef uint8 EthIf_SizeOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_SizeOfPhysLayerInitElems */
typedef uint8 EthIf_SizeOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_SizeOfPhysLayerModeElems */
typedef uint8 EthIf_SizeOfPhysLayerModeElemsType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroup */
typedef uint8 EthIf_SizeOfPortGroupType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupHostOrUpLinkPortRoleLinkCount */
typedef uint8 EthIf_SizeOfPortGroupHostOrUpLinkPortRoleLinkCountType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupInd */
typedef uint8 EthIf_SizeOfPortGroupIndType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupLinkState */
typedef uint8 EthIf_SizeOfPortGroupLinkStateType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupMode */
typedef uint8 EthIf_SizeOfPortGroupModeType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupNoRoleLinkCount */
typedef uint8 EthIf_SizeOfPortGroupNoRoleLinkCountType;

/**   \brief  value based type definition for EthIf_SizeOfPortGroupStartupActiveTimerActive */
typedef uint8 EthIf_SizeOfPortGroupStartupActiveTimerActiveType;

/**   \brief  value based type definition for EthIf_SizeOfPortMode */
typedef uint8 EthIf_SizeOfPortModeType;

/**   \brief  value based type definition for EthIf_SizeOfPortSignalQualityResult */
typedef uint8 EthIf_SizeOfPortSignalQualityResultType;

/**   \brief  value based type definition for EthIf_SizeOfPortStartupActiveTimerActive */
typedef uint8 EthIf_SizeOfPortStartupActiveTimerActiveType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedEthIfCtrlMode */
typedef uint8 EthIf_SizeOfRequestedEthIfCtrlModeType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedEthTrcvMode */
typedef uint8 EthIf_SizeOfRequestedEthTrcvModeType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedEthTrcvStateOfEthIfCtrl */
typedef uint8 EthIf_SizeOfRequestedEthTrcvStateOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedPortGroupMode */
typedef uint8 EthIf_SizeOfRequestedPortGroupModeType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedPortGroupStateOfEthIfCtrl */
typedef uint8 EthIf_SizeOfRequestedPortGroupStateOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_SizeOfRequestedPortMode */
typedef uint8 EthIf_SizeOfRequestedPortModeType;

/**   \brief  value based type definition for EthIf_SizeOfRxIndications */
typedef uint8 EthIf_SizeOfRxIndicationsType;

/**   \brief  value based type definition for EthIf_SizeOfRxPdu */
typedef uint8 EthIf_SizeOfRxPduType;

/**   \brief  value based type definition for EthIf_SizeOfRxPduContext */
typedef uint8 EthIf_SizeOfRxPduContextType;

/**   \brief  value based type definition for EthIf_SizeOfRxPduFrameType */
typedef uint8 EthIf_SizeOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_SizeOfRxPduFreeList */
typedef uint8 EthIf_SizeOfRxPduFreeListType;

/**   \brief  value based type definition for EthIf_SizeOfRxPduMetaData */
typedef uint8 EthIf_SizeOfRxPduMetaDataType;

/**   \brief  value based type definition for EthIf_SizeOfRxQueueList */
typedef uint8 EthIf_SizeOfRxQueueListType;

/**   \brief  value based type definition for EthIf_SizeOfSignalQualityResult */
typedef uint8 EthIf_SizeOfSignalQualityResultType;

/**   \brief  value based type definition for EthIf_SizeOfSrcMacAddrBuffer */
typedef uint8 EthIf_SizeOfSrcMacAddrBufferType;

/**   \brief  value based type definition for EthIf_SizeOfSwtPortGroupModeChangeRetryCounter */
typedef uint8 EthIf_SizeOfSwtPortGroupModeChangeRetryCounterType;

/**   \brief  value based type definition for EthIf_SizeOfSwtPortGroupModeChangeRetryPeriodCounter */
typedef uint8 EthIf_SizeOfSwtPortGroupModeChangeRetryPeriodCounterType;

/**   \brief  value based type definition for EthIf_SizeOfTxConfirmations */
typedef uint8 EthIf_SizeOfTxConfirmationsType;

/**   \brief  value based type definition for EthIf_SizeOfTxContext */
typedef uint8 EthIf_SizeOfTxContextType;

/**   \brief  value based type definition for EthIf_SizeOfTxPdu */
typedef uint8 EthIf_SizeOfTxPduType;

/**   \brief  value based type definition for EthIf_SizeOfTxPduContext */
typedef uint8 EthIf_SizeOfTxPduContextType;

/**   \brief  value based type definition for EthIf_SizeOfTxQueueList */
typedef uint8 EthIf_SizeOfTxQueueListType;

/**   \brief  value based type definition for EthIf_SizeOfWakeupMap */
typedef uint8 EthIf_SizeOfWakeupMapType;

/**   \brief  value based type definition for EthIf_SizeOfWakeupSrcDevice */
typedef uint8 EthIf_SizeOfWakeupSrcDeviceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCIterableTypes  EthIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate EthIf_EcucPartition */
typedef uint8_least EthIf_EcucPartitionIterType;

/**   \brief  type used to iterate EthIf_EthCtrl */
typedef uint8_least EthIf_EthCtrlIterType;

/**   \brief  type used to iterate EthIf_EthDrvApi */
typedef uint8_least EthIf_EthDrvApiIterType;

/**   \brief  type used to iterate EthIf_EthIfClkUnit */
typedef uint8_least EthIf_EthIfClkUnitIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrl */
typedef uint8_least EthIf_EthIfCtrlIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlOfEthTrcvInd */
typedef uint8_least EthIf_EthIfCtrlOfEthTrcvIndIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlOfPortGroupInd */
typedef uint8_least EthIf_EthIfCtrlOfPortGroupIndIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlToEtherTypeMap */
typedef uint8_least EthIf_EthIfCtrlToEtherTypeMapIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlToRxPduMap */
typedef uint8_least EthIf_EthIfCtrlToRxPduMapIterType;

/**   \brief  type used to iterate EthIf_EthIfMeasurementData */
typedef uint8_least EthIf_EthIfMeasurementDataIterType;

/**   \brief  type used to iterate EthIf_EthIfPhysCtrlCfg */
typedef uint8_least EthIf_EthIfPhysCtrlCfgIterType;

/**   \brief  type used to iterate EthIf_EthRxQueue */
typedef uint8_least EthIf_EthRxQueueIterType;

/**   \brief  type used to iterate EthIf_EthSwt */
typedef uint8_least EthIf_EthSwtIterType;

/**   \brief  type used to iterate EthIf_EthSwtDrv */
typedef uint8_least EthIf_EthSwtDrvIterType;

/**   \brief  type used to iterate EthIf_EthSwtDrvApi */
typedef uint8_least EthIf_EthSwtDrvApiIterType;

/**   \brief  type used to iterate EthIf_EthSwtInd */
typedef uint8_least EthIf_EthSwtIndIterType;

/**   \brief  type used to iterate EthIf_EthSwtPort */
typedef uint8_least EthIf_EthSwtPortIterType;

/**   \brief  type used to iterate EthIf_EthSwtPortInEthSwtContext */
typedef uint8_least EthIf_EthSwtPortInEthSwtContextIterType;

/**   \brief  type used to iterate EthIf_EthSwtPortInd */
typedef uint8_least EthIf_EthSwtPortIndIterType;

/**   \brief  type used to iterate EthIf_EthTrcv */
typedef uint8_least EthIf_EthTrcvIterType;

/**   \brief  type used to iterate EthIf_EthTrcvDrvApi */
typedef uint8_least EthIf_EthTrcvDrvApiIterType;

/**   \brief  type used to iterate EthIf_EthTxQueue */
typedef uint8_least EthIf_EthTxQueueIterType;

/**   \brief  type used to iterate EthIf_ExplicitBufReleaseFilter */
typedef uint8_least EthIf_ExplicitBufReleaseFilterIterType;

/**   \brief  type used to iterate EthIf_FloatingRxPduMap */
typedef uint8_least EthIf_FloatingRxPduMapIterType;

/**   \brief  type used to iterate EthIf_GatewaySrcMacBlackList */
typedef uint8_least EthIf_GatewaySrcMacBlackListIterType;

/**   \brief  type used to iterate EthIf_LegacyWakeupMap */
typedef uint8_least EthIf_LegacyWakeupMapIterType;

/**   \brief  type used to iterate EthIf_LinkStateChgIndications */
typedef uint8_least EthIf_LinkStateChgIndicationsIterType;

/**   \brief  type used to iterate EthIf_MainPartitionRxEthCtrl */
typedef uint8_least EthIf_MainPartitionRxEthCtrlIterType;

/**   \brief  type used to iterate EthIf_MainPartitionTxEthCtrl */
typedef uint8_least EthIf_MainPartitionTxEthCtrlIterType;

/**   \brief  type used to iterate EthIf_MirrorDest */
typedef uint8_least EthIf_MirrorDestIterType;

/**   \brief  type used to iterate EthIf_MirrorTxInfo */
typedef uint8_least EthIf_MirrorTxInfoIterType;

/**   \brief  type used to iterate EthIf_PhysLayerInitElems */
typedef uint8_least EthIf_PhysLayerInitElemsIterType;

/**   \brief  type used to iterate EthIf_PhysLayerModeElems */
typedef uint8_least EthIf_PhysLayerModeElemsIterType;

/**   \brief  type used to iterate EthIf_PortGroup */
typedef uint8_least EthIf_PortGroupIterType;

/**   \brief  type used to iterate EthIf_PortGroupInd */
typedef uint8_least EthIf_PortGroupIndIterType;

/**   \brief  type used to iterate EthIf_PortMode */
typedef uint8_least EthIf_PortModeIterType;

/**   \brief  type used to iterate EthIf_RequestedPortMode */
typedef uint8_least EthIf_RequestedPortModeIterType;

/**   \brief  type used to iterate EthIf_RxIndications */
typedef uint8_least EthIf_RxIndicationsIterType;

/**   \brief  type used to iterate EthIf_RxPdu */
typedef uint8_least EthIf_RxPduIterType;

/**   \brief  type used to iterate EthIf_RxPduFrameType */
typedef uint8_least EthIf_RxPduFrameTypeIterType;

/**   \brief  type used to iterate EthIf_RxPduMetaData */
typedef uint8_least EthIf_RxPduMetaDataIterType;

/**   \brief  type used to iterate EthIf_RxQueueList */
typedef uint8_least EthIf_RxQueueListIterType;

/**   \brief  type used to iterate EthIf_TxConfirmations */
typedef uint8_least EthIf_TxConfirmationsIterType;

/**   \brief  type used to iterate EthIf_TxContext */
typedef uint8_least EthIf_TxContextIterType;

/**   \brief  type used to iterate EthIf_TxPdu */
typedef uint8_least EthIf_TxPduIterType;

/**   \brief  type used to iterate EthIf_TxQueueList */
typedef uint8_least EthIf_TxQueueListIterType;

/**   \brief  type used to iterate EthIf_WakeupMap */
typedef uint8_least EthIf_WakeupMapIterType;

/**   \brief  type used to iterate EthIf_WakeupSrcDevice */
typedef uint8_least EthIf_WakeupSrcDeviceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCIterableTypesWithSizeRelations  EthIf Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate EthIf_DedicatedRxPduNextFreePos */
typedef EthIf_EthIfCtrlToRxPduMapIterType EthIf_DedicatedRxPduNextFreePosIterType;

/**   \brief  type used to iterate EthIf_EthCtrlInitCnt */
typedef EthIf_EthCtrlIterType EthIf_EthCtrlInitCntIterType;

/**   \brief  type used to iterate EthIf_EthCtrlModeCnt */
typedef EthIf_EthCtrlIterType EthIf_EthCtrlModeCntIterType;

/**   \brief  type used to iterate EthIf_EthCtrlState */
typedef EthIf_EthIfCtrlIterType EthIf_EthCtrlStateIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlInitState */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlInitStateIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlLinkCount */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlLinkCountIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlLinkState */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlLinkStateIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlMode */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlModeIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlRxStats */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlRxStatsIterType;

/**   \brief  type used to iterate EthIf_EthIfCtrlTxStats */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfCtrlTxStatsIterType;

/**   \brief  type used to iterate EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter */
typedef EthIf_EthTrcvIterType EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterIterType;

/**   \brief  type used to iterate EthIf_EthIfQualifiedUnexpectedLinkDownTimerState */
typedef EthIf_EthTrcvIterType EthIf_EthIfQualifiedUnexpectedLinkDownTimerStateIterType;

/**   \brief  type used to iterate EthIf_EthIfSwitchOffPortGroupTimerDelayCounter */
typedef EthIf_PortGroupIterType EthIf_EthIfSwitchOffPortGroupTimerDelayCounterIterType;

/**   \brief  type used to iterate EthIf_EthIfSwitchOffPortGroupTimerDelayState */
typedef EthIf_PortGroupIterType EthIf_EthIfSwitchOffPortGroupTimerDelayStateIterType;

/**   \brief  type used to iterate EthIf_EthIfSwitchOffPortTimerDelayState */
typedef EthIf_EthSwtPortIterType EthIf_EthIfSwitchOffPortTimerDelayStateIterType;

/**   \brief  type used to iterate EthIf_EthIfSwtPortGroupState */
typedef EthIf_EthIfCtrlIterType EthIf_EthIfSwtPortGroupStateIterType;

/**   \brief  type used to iterate EthIf_EthSwtInitCnt */
typedef EthIf_EthSwtIterType EthIf_EthSwtInitCntIterType;

/**   \brief  type used to iterate EthIf_EthSwtPortLinkState */
typedef EthIf_EthSwtPortIterType EthIf_EthSwtPortLinkStateIterType;

/**   \brief  type used to iterate EthIf_EthSwtPortModeCnt */
typedef EthIf_EthSwtPortIterType EthIf_EthSwtPortModeCntIterType;

/**   \brief  type used to iterate EthIf_EthTrcvInitCnt */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvInitCntIterType;

/**   \brief  type used to iterate EthIf_EthTrcvLinkState */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvLinkStateIterType;

/**   \brief  type used to iterate EthIf_EthTrcvMode */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvModeIterType;

/**   \brief  type used to iterate EthIf_EthTrcvModeChangeRetryCounter */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvModeChangeRetryCounterIterType;

/**   \brief  type used to iterate EthIf_EthTrcvModeChangeRetryPeriodCounter */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvModeChangeRetryPeriodCounterIterType;

/**   \brief  type used to iterate EthIf_EthTrcvModeCnt */
typedef EthIf_EthTrcvIterType EthIf_EthTrcvModeCntIterType;

/**   \brief  type used to iterate EthIf_EthTrcvState */
typedef EthIf_EthIfCtrlIterType EthIf_EthTrcvStateIterType;

/**   \brief  type used to iterate EthIf_FloatingRxPduNextFreePos */
typedef EthIf_FloatingRxPduMapIterType EthIf_FloatingRxPduNextFreePosIterType;

/**   \brief  type used to iterate EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
typedef EthIf_PortGroupIterType EthIf_PortGroupHostOrUpLinkPortRoleLinkCountIterType;

/**   \brief  type used to iterate EthIf_PortGroupLinkState */
typedef EthIf_PortGroupIterType EthIf_PortGroupLinkStateIterType;

/**   \brief  type used to iterate EthIf_PortGroupMode */
typedef EthIf_PortGroupIterType EthIf_PortGroupModeIterType;

/**   \brief  type used to iterate EthIf_PortGroupNoRoleLinkCount */
typedef EthIf_PortGroupIterType EthIf_PortGroupNoRoleLinkCountIterType;

/**   \brief  type used to iterate EthIf_PortGroupStartupActiveTimerActive */
typedef EthIf_PortGroupIterType EthIf_PortGroupStartupActiveTimerActiveIterType;

/**   \brief  type used to iterate EthIf_PortSignalQualityResult */
typedef EthIf_EthSwtPortIterType EthIf_PortSignalQualityResultIterType;

/**   \brief  type used to iterate EthIf_PortStartupActiveTimerActive */
typedef EthIf_EthSwtPortIterType EthIf_PortStartupActiveTimerActiveIterType;

/**   \brief  type used to iterate EthIf_RequestedEthIfCtrlMode */
typedef EthIf_EthIfCtrlIterType EthIf_RequestedEthIfCtrlModeIterType;

/**   \brief  type used to iterate EthIf_RequestedEthTrcvMode */
typedef EthIf_EthTrcvIterType EthIf_RequestedEthTrcvModeIterType;

/**   \brief  type used to iterate EthIf_RequestedEthTrcvStateOfEthIfCtrl */
typedef EthIf_EthIfCtrlIterType EthIf_RequestedEthTrcvStateOfEthIfCtrlIterType;

/**   \brief  type used to iterate EthIf_RequestedPortGroupMode */
typedef EthIf_PortGroupIterType EthIf_RequestedPortGroupModeIterType;

/**   \brief  type used to iterate EthIf_RequestedPortGroupStateOfEthIfCtrl */
typedef EthIf_EthIfCtrlIterType EthIf_RequestedPortGroupStateOfEthIfCtrlIterType;

/**   \brief  type used to iterate EthIf_RxPduContext */
typedef EthIf_RxPduIterType EthIf_RxPduContextIterType;

/**   \brief  type used to iterate EthIf_RxPduFreeList */
typedef EthIf_RxPduIterType EthIf_RxPduFreeListIterType;

/**   \brief  type used to iterate EthIf_SignalQualityResult */
typedef EthIf_EthTrcvIterType EthIf_SignalQualityResultIterType;

/**   \brief  type used to iterate EthIf_SrcMacAddrBuffer */
typedef EthIf_EthCtrlIterType EthIf_SrcMacAddrBufferIterType;

/**   \brief  type used to iterate EthIf_SwtPortGroupModeChangeRetryCounter */
typedef EthIf_PortGroupIterType EthIf_SwtPortGroupModeChangeRetryCounterIterType;

/**   \brief  type used to iterate EthIf_SwtPortGroupModeChangeRetryPeriodCounter */
typedef EthIf_PortGroupIterType EthIf_SwtPortGroupModeChangeRetryPeriodCounterIterType;

/**   \brief  type used to iterate EthIf_TxPduContext */
typedef EthIf_TxPduIterType EthIf_TxPduContextIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCValueTypes  EthIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for EthIf_DedicatedRxPduNextFreePos */
typedef uint16 EthIf_DedicatedRxPduNextFreePosType;

/**   \brief  value based type definition for EthIf_QualityLevelOfEcucPartition */
typedef uint8 EthIf_QualityLevelOfEcucPartitionType;

/**   \brief  value based type definition for EthIf_BufIdxOffsetEnabledOfEthCtrl */
typedef boolean EthIf_BufIdxOffsetEnabledOfEthCtrlType;

/**   \brief  value based type definition for EthIf_EthArReleaseRxBufferSupportedOfEthCtrl */
typedef boolean EthIf_EthArReleaseRxBufferSupportedOfEthCtrlType;

/**   \brief  value based type definition for EthIf_EthDrvApiIdxOfEthCtrl */
typedef uint8 EthIf_EthDrvApiIdxOfEthCtrlType;

/**   \brief  value based type definition for EthIf_ImplicitBufferReleaseNeededOfEthCtrl */
typedef boolean EthIf_ImplicitBufferReleaseNeededOfEthCtrlType;

/**   \brief  value based type definition for EthIf_NumOfTxBuffersOfEthCtrl */
typedef uint8 EthIf_NumOfTxBuffersOfEthCtrlType;

/**   \brief  value based type definition for EthIf_SnvOfEthCtrl */
typedef uint32 EthIf_SnvOfEthCtrlType;

/**   \brief  value based type definition for EthIf_TxContextEndIdxOfEthCtrl */
typedef uint8 EthIf_TxContextEndIdxOfEthCtrlType;

/**   \brief  value based type definition for EthIf_TxContextLengthOfEthCtrl */
typedef uint8 EthIf_TxContextLengthOfEthCtrlType;

/**   \brief  value based type definition for EthIf_TxContextStartIdxOfEthCtrl */
typedef uint8 EthIf_TxContextStartIdxOfEthCtrlType;

/**   \brief  value based type definition for EthIf_EthCtrlInitCnt */
typedef uint8 EthIf_EthCtrlInitCntType;

/**   \brief  value based type definition for EthIf_EthCtrlModeCnt */
typedef uint8 EthIf_EthCtrlModeCntType;

/**   \brief  value based type definition for EthIf_EthClkUnitIdxOfEthIfClkUnit */
typedef uint32 EthIf_EthClkUnitIdxOfEthIfClkUnitType;

/**   \brief  value based type definition for EthIf_EthIfClkUnitIdxOfEthIfClkUnit */
typedef uint32 EthIf_EthIfClkUnitIdxOfEthIfClkUnitType;

/**   \brief  value based type definition for EthIf_EthIfControllerModeChangeReqCnt */
typedef uint16 EthIf_EthIfControllerModeChangeReqCntType;

/**   \brief  value based type definition for EthIf_EcucPartitionIdxOfEthIfCtrl */
typedef uint8 EthIf_EcucPartitionIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EcucPartitionUsedOfEthIfCtrl */
typedef boolean EthIf_EcucPartitionUsedOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfEthIfCtrl */
typedef uint8 EthIf_EthCtrlIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrl */
typedef uint8 EthIf_EthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToEtherTypeMapLengthOfEthIfCtrl */
typedef uint8 EthIf_EthIfCtrlToEtherTypeMapLengthOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrl */
typedef uint8 EthIf_EthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrl */
typedef uint8 EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthSwtDrvApiIdxOfEthIfCtrl */
typedef uint8 EthIf_EthSwtDrvApiIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthSwtDrvApiUsedOfEthIfCtrl */
typedef boolean EthIf_EthSwtDrvApiUsedOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_GatewayDestEthIfCtrlIdxIdxOfEthIfCtrl */
typedef uint8 EthIf_GatewayDestEthIfCtrlIdxIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_GatewayDestEthIfCtrlIdxOfEthIfCtrl */
typedef uint8 EthIf_GatewayDestEthIfCtrlIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_GatewayDestEthIfCtrlIdxUsedOfEthIfCtrl */
typedef boolean EthIf_GatewayDestEthIfCtrlIdxUsedOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_LinkAggrThresholdOfEthIfCtrl */
typedef uint8 EthIf_LinkAggrThresholdOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MacSecTypeOfEthIfCtrl */
typedef uint8 EthIf_MacSecTypeOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorRxDestIdxIdxOfEthIfCtrl */
typedef uint8 EthIf_MirrorRxDestIdxIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorRxDestIdxOfEthIfCtrl */
typedef uint8 EthIf_MirrorRxDestIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorRxDestIdxUsedOfEthIfCtrl */
typedef boolean EthIf_MirrorRxDestIdxUsedOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorTxDestIdxIdxOfEthIfCtrl */
typedef uint8 EthIf_MirrorTxDestIdxIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorTxDestIdxOfEthIfCtrl */
typedef uint8 EthIf_MirrorTxDestIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MirrorTxDestIdxUsedOfEthIfCtrl */
typedef boolean EthIf_MirrorTxDestIdxUsedOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_MtuOfEthIfCtrl */
typedef uint16 EthIf_MtuOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_PhysLayerInitElemsIdxOfEthIfCtrl */
typedef uint8 EthIf_PhysLayerInitElemsIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_PhysLayerModeElemsIdxOfEthIfCtrl */
typedef uint8 EthIf_PhysLayerModeElemsIdxOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_SnvOfEthIfCtrl */
typedef uint32 EthIf_SnvOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_TypeOfEthIfCtrl */
typedef uint8 EthIf_TypeOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_VlanIdOfEthIfCtrl */
typedef uint16 EthIf_VlanIdOfEthIfCtrlType;

/**   \brief  value based type definition for EthIf_EthIfCtrlLinkCount */
typedef uint8 EthIf_EthIfCtrlLinkCountType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfEthTrcvInd */
typedef uint8 EthIf_EthIfCtrlOfEthTrcvIndType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfPortGroupInd */
typedef uint8 EthIf_EthIfCtrlOfPortGroupIndType;

/**   \brief  value based type definition for EthIf_NumRxBytesOfEthIfCtrlRxStats */
typedef uint32 EthIf_NumRxBytesOfEthIfCtrlRxStatsType;

/**   \brief  value based type definition for EthIf_NumRxPktsOfEthIfCtrlRxStats */
typedef uint32 EthIf_NumRxPktsOfEthIfCtrlRxStatsType;

/**   \brief  value based type definition for EthIf_EtherTypeOfEthIfCtrlToEtherTypeMap */
typedef uint16 EthIf_EtherTypeOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_RxIndicationsEndIdxOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_RxIndicationsEndIdxOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_RxIndicationsLengthOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_RxIndicationsLengthOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_RxIndicationsStartIdxOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_RxIndicationsStartIdxOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_RxIndicationsUsedOfEthIfCtrlToEtherTypeMap */
typedef boolean EthIf_RxIndicationsUsedOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_TxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_TxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_TxConfirmationsLengthOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_TxConfirmationsLengthOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_TxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMap */
typedef uint8 EthIf_TxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_TxConfirmationsUsedOfEthIfCtrlToEtherTypeMap */
typedef boolean EthIf_TxConfirmationsUsedOfEthIfCtrlToEtherTypeMapType;

/**   \brief  value based type definition for EthIf_RxPduCountOfEthIfCtrlToRxPduMap */
typedef uint8 EthIf_RxPduCountOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduEndIdxOfEthIfCtrlToRxPduMap */
typedef uint8 EthIf_RxPduEndIdxOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduLengthOfEthIfCtrlToRxPduMap */
typedef uint8 EthIf_RxPduLengthOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduStartIdxOfEthIfCtrlToRxPduMap */
typedef uint8 EthIf_RxPduStartIdxOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduUsedOfEthIfCtrlToRxPduMap */
typedef boolean EthIf_RxPduUsedOfEthIfCtrlToRxPduMapType;

/**   \brief  value based type definition for EthIf_NumTxBytesOfEthIfCtrlTxStats */
typedef uint32 EthIf_NumTxBytesOfEthIfCtrlTxStatsType;

/**   \brief  value based type definition for EthIf_NumTxPktsOfEthIfCtrlTxStats */
typedef uint32 EthIf_NumTxPktsOfEthIfCtrlTxStatsType;

/**   \brief  value based type definition for EthIf_DropCtrlIdxOfEthIfMeasurementData */
typedef uint32 EthIf_DropCtrlIdxOfEthIfMeasurementDataType;

/**   \brief  value based type definition for EthIf_UnknownEtherTypeOfEthIfMeasurementData */
typedef uint32 EthIf_UnknownEtherTypeOfEthIfMeasurementDataType;

/**   \brief  value based type definition for EthIf_VlanDoubleTaggedOfEthIfMeasurementData */
typedef uint32 EthIf_VlanDoubleTaggedOfEthIfMeasurementDataType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfEthIfPhysCtrlCfg */
typedef uint32 EthIf_EthCtrlIdxOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfg */
typedef uint8 EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfClkUnitEndIdxOfEthIfPhysCtrlCfg */
typedef uint8 EthIf_EthIfClkUnitEndIdxOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfClkUnitLengthOfEthIfPhysCtrlCfg */
typedef uint8 EthIf_EthIfClkUnitLengthOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfClkUnitStartIdxOfEthIfPhysCtrlCfg */
typedef uint8 EthIf_EthIfClkUnitStartIdxOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfClkUnitUsedOfEthIfPhysCtrlCfg */
typedef boolean EthIf_EthIfClkUnitUsedOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfPhysControllerIdxOfEthIfPhysCtrlCfg */
typedef uint32 EthIf_EthIfPhysControllerIdxOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthPhcSupportAvailableOfEthIfPhysCtrlCfg */
typedef boolean EthIf_EthPhcSupportAvailableOfEthIfPhysCtrlCfgType;

/**   \brief  value based type definition for EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter */
typedef uint16 EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterType;

/**   \brief  value based type definition for EthIf_EthIfSwitchOffPortGroupTimerDelayCounter */
typedef uint16 EthIf_EthIfSwitchOffPortGroupTimerDelayCounterType;

/**   \brief  value based type definition for EthIf_EthIfSwitchOffPortTimeDelayCounts */
typedef uint8 EthIf_EthIfSwitchOffPortTimeDelayCountsType;

/**   \brief  value based type definition for EthIf_EthIfSwitchOffPortTimeDelayReqCnt */
typedef uint16 EthIf_EthIfSwitchOffPortTimeDelayReqCntType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfEthRxQueue */
typedef uint8 EthIf_EthCtrlIdxOfEthRxQueueType;

/**   \brief  value based type definition for EthIf_QueueIndexOfEthRxQueue */
typedef uint8 EthIf_QueueIndexOfEthRxQueueType;

/**   \brief  value based type definition for EthIf_EthSwtDrvApiIdxOfEthSwt */
typedef uint8 EthIf_EthSwtDrvApiIdxOfEthSwtType;

/**   \brief  value based type definition for EthIf_EthSwtPortInEthSwtContextEndIdxOfEthSwt */
typedef uint8 EthIf_EthSwtPortInEthSwtContextEndIdxOfEthSwtType;

/**   \brief  value based type definition for EthIf_EthSwtPortInEthSwtContextLengthOfEthSwt */
typedef uint8 EthIf_EthSwtPortInEthSwtContextLengthOfEthSwtType;

/**   \brief  value based type definition for EthIf_EthSwtPortInEthSwtContextStartIdxOfEthSwt */
typedef uint8 EthIf_EthSwtPortInEthSwtContextStartIdxOfEthSwtType;

/**   \brief  value based type definition for EthIf_EthSwtPortInEthSwtContextUsedOfEthSwt */
typedef boolean EthIf_EthSwtPortInEthSwtContextUsedOfEthSwtType;

/**   \brief  value based type definition for EthIf_SnvOfEthSwt */
typedef uint32 EthIf_SnvOfEthSwtType;

/**   \brief  value based type definition for EthIf_EthSwtEndIdxOfEthSwtDrv */
typedef uint8 EthIf_EthSwtEndIdxOfEthSwtDrvType;

/**   \brief  value based type definition for EthIf_EthSwtLengthOfEthSwtDrv */
typedef uint8 EthIf_EthSwtLengthOfEthSwtDrvType;

/**   \brief  value based type definition for EthIf_EthSwtStartIdxOfEthSwtDrv */
typedef uint8 EthIf_EthSwtStartIdxOfEthSwtDrvType;

/**   \brief  value based type definition for EthIf_EthSwtInd */
typedef uint8 EthIf_EthSwtIndType;

/**   \brief  value based type definition for EthIf_EthSwtInitCnt */
typedef uint8 EthIf_EthSwtInitCntType;

/**   \brief  value based type definition for EthIf_AsyncProcessingOfEthSwtPort */
typedef boolean EthIf_AsyncProcessingOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_EthSwtIdxOfEthSwtPort */
typedef uint8 EthIf_EthSwtIdxOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_EthSwtPortHostOrUpLinkPortIdxOfEthSwtPort */
typedef uint8 EthIf_EthSwtPortHostOrUpLinkPortIdxOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_MacSecSecuredOfEthSwtPort */
typedef boolean EthIf_MacSecSecuredOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_MkaPaeIdxOfEthSwtPort */
typedef uint8 EthIf_MkaPaeIdxOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_PortGroupIndEndIdxOfEthSwtPort */
typedef uint8 EthIf_PortGroupIndEndIdxOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_PortGroupIndStartIdxOfEthSwtPort */
typedef uint8 EthIf_PortGroupIndStartIdxOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_PortRoleOfEthSwtPort */
typedef uint8 EthIf_PortRoleOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_SnvOfEthSwtPort */
typedef uint32 EthIf_SnvOfEthSwtPortType;

/**   \brief  value based type definition for EthIf_EthSwtPortIdxOfEthSwtPortInEthSwtContext */
typedef uint8 EthIf_EthSwtPortIdxOfEthSwtPortInEthSwtContextType;

/**   \brief  value based type definition for EthIf_EthSwtPortUsedOfEthSwtPortInEthSwtContext */
typedef boolean EthIf_EthSwtPortUsedOfEthSwtPortInEthSwtContextType;

/**   \brief  value based type definition for EthIf_EthSwtPortInd */
typedef uint8 EthIf_EthSwtPortIndType;

/**   \brief  value based type definition for EthIf_EthSwtPortModeCnt */
typedef uint8 EthIf_EthSwtPortModeCntType;

/**   \brief  value based type definition for EthIf_AsyncProcessingOfEthTrcv */
typedef boolean EthIf_AsyncProcessingOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv */
typedef uint8 EthIf_EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv */
typedef uint8 EthIf_EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfEthTrcvIndUsedOfEthTrcv */
typedef boolean EthIf_EthIfCtrlOfEthTrcvIndUsedOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcv */
typedef uint8 EthIf_EthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthTrcvActAsSlavePassiveEnabledOfEthTrcv */
typedef boolean EthIf_EthTrcvActAsSlavePassiveEnabledOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthTrcvDrvApiIdxOfEthTrcv */
typedef uint8 EthIf_EthTrcvDrvApiIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthTrcvTypeOfEthTrcv */
typedef uint8 EthIf_EthTrcvTypeOfEthTrcvType;

/**   \brief  value based type definition for EthIf_MacSecSecuredOfEthTrcv */
typedef boolean EthIf_MacSecSecuredOfEthTrcvType;

/**   \brief  value based type definition for EthIf_MkaPaeIdxOfEthTrcv */
typedef uint8 EthIf_MkaPaeIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_PortModeIdxOfEthTrcv */
typedef uint8 EthIf_PortModeIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_PortModeUsedOfEthTrcv */
typedef boolean EthIf_PortModeUsedOfEthTrcvType;

/**   \brief  value based type definition for EthIf_RequestedPortModeIdxOfEthTrcv */
typedef uint8 EthIf_RequestedPortModeIdxOfEthTrcvType;

/**   \brief  value based type definition for EthIf_RequestedPortModeUsedOfEthTrcv */
typedef boolean EthIf_RequestedPortModeUsedOfEthTrcvType;

/**   \brief  value based type definition for EthIf_SnvOfEthTrcv */
typedef uint32 EthIf_SnvOfEthTrcvType;

/**   \brief  value based type definition for EthIf_EthTrcvInitCnt */
typedef uint8 EthIf_EthTrcvInitCntType;

/**   \brief  value based type definition for EthIf_EthTrcvModeChangeRetryCounter */
typedef uint16 EthIf_EthTrcvModeChangeRetryCounterType;

/**   \brief  value based type definition for EthIf_EthTrcvModeChangeRetryPeriodCounter */
typedef uint16 EthIf_EthTrcvModeChangeRetryPeriodCounterType;

/**   \brief  value based type definition for EthIf_EthTrcvModeCnt */
typedef uint8 EthIf_EthTrcvModeCntType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfEthTxQueue */
typedef uint8 EthIf_EthCtrlIdxOfEthTxQueueType;

/**   \brief  value based type definition for EthIf_QueueIndexOfEthTxQueue */
typedef uint8 EthIf_QueueIndexOfEthTxQueueType;

/**   \brief  value based type definition for EthIf_EthIfCtrlIdxOfExplicitBufReleaseFilter */
typedef uint8 EthIf_EthIfCtrlIdxOfExplicitBufReleaseFilterType;

/**   \brief  value based type definition for EthIf_EtherTypeConfiguredOfExplicitBufReleaseFilter */
typedef boolean EthIf_EtherTypeConfiguredOfExplicitBufReleaseFilterType;

/**   \brief  value based type definition for EthIf_EtherTypeOfExplicitBufReleaseFilter */
typedef uint8 EthIf_EtherTypeOfExplicitBufReleaseFilterType;

/**   \brief  value based type definition for EthIf_RxPduEndIdxOfFloatingRxPduMap */
typedef uint8 EthIf_RxPduEndIdxOfFloatingRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduLengthOfFloatingRxPduMap */
typedef uint8 EthIf_RxPduLengthOfFloatingRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduStartIdxOfFloatingRxPduMap */
typedef uint8 EthIf_RxPduStartIdxOfFloatingRxPduMapType;

/**   \brief  value based type definition for EthIf_RxPduUsedOfFloatingRxPduMap */
typedef boolean EthIf_RxPduUsedOfFloatingRxPduMapType;

/**   \brief  value based type definition for EthIf_FloatingRxPduNextFreePos */
typedef uint16 EthIf_FloatingRxPduNextFreePosType;

/**   \brief  value based type definition for EthIf_GlobalModeChangeMaxRetryCount */
typedef uint8 EthIf_GlobalModeChangeMaxRetryCountType;

/**   \brief  value based type definition for EthIf_GlobalModeChangeRetryPeriodCount */
typedef uint8 EthIf_GlobalModeChangeRetryPeriodCountType;

/**   \brief  value based type definition for EthIf_GlobalStartupActiveTimerActive */
typedef boolean EthIf_GlobalStartupActiveTimerActiveType;

/**   \brief  value based type definition for EthIf_InitLocked */
typedef boolean EthIf_InitLockedType;

/**   \brief  value based type definition for EthIf_EthTrcvIdxOfLegacyWakeupMap */
typedef uint8 EthIf_EthTrcvIdxOfLegacyWakeupMapType;

/**   \brief  value based type definition for EthIf_LinkStateChgMainReload */
typedef uint8 EthIf_LinkStateChgMainReloadType;

/**   \brief  value based type definition for EthIf_MainFuncStateDecoupleFreqCnt */
typedef uint16 EthIf_MainFuncStateDecoupleFreqCntType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfMainPartitionRxEthCtrl */
typedef uint8 EthIf_EthCtrlIdxOfMainPartitionRxEthCtrlType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfMainPartitionTxEthCtrl */
typedef uint8 EthIf_EthCtrlIdxOfMainPartitionTxEthCtrlType;

/**   \brief  value based type definition for EthIf_MaxRxFramePerEthCtrl */
typedef uint8 EthIf_MaxRxFramePerEthCtrlType;

/**   \brief  value based type definition for EthIf_MaxTxBufPerEthCtrl */
typedef uint8 EthIf_MaxTxBufPerEthCtrlType;

/**   \brief  value based type definition for EthIf_EthCtrlIdxOfMirrorDest */
typedef uint8 EthIf_EthCtrlIdxOfMirrorDestType;

/**   \brief  value based type definition for EthIf_KeepSrcMacEnabledOfMirrorDest */
typedef boolean EthIf_KeepSrcMacEnabledOfMirrorDestType;

/**   \brief  value based type definition for EthIf_DestEthTxBufferIdxOfMirrorTxInfo */
typedef uint8 EthIf_DestEthTxBufferIdxOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_EthIfCtrlIdxOfMirrorTxInfo */
typedef uint8 EthIf_EthIfCtrlIdxOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_InfoValidOfMirrorTxInfo */
typedef boolean EthIf_InfoValidOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_SrcEthTxBufferIdxOfMirrorTxInfo */
typedef uint8 EthIf_SrcEthTxBufferIdxOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_UsedOfMirrorTxInfo */
typedef boolean EthIf_UsedOfMirrorTxInfoType;

/**   \brief  value based type definition for EthIf_ModeChangeLocked */
typedef boolean EthIf_ModeChangeLockedType;

/**   \brief  value based type definition for EthIf_EthSwtIndEndIdxOfPhysLayerInitElems */
typedef uint8 EthIf_EthSwtIndEndIdxOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_EthSwtIndStartIdxOfPhysLayerInitElems */
typedef uint8 EthIf_EthSwtIndStartIdxOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_EthSwtIndUsedOfPhysLayerInitElems */
typedef boolean EthIf_EthSwtIndUsedOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_EthTrcvIdxOfPhysLayerInitElems */
typedef uint8 EthIf_EthTrcvIdxOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_EthTrcvUsedOfPhysLayerInitElems */
typedef boolean EthIf_EthTrcvUsedOfPhysLayerInitElemsType;

/**   \brief  value based type definition for EthIf_EthTrcvIdxOfPhysLayerModeElems */
typedef uint8 EthIf_EthTrcvIdxOfPhysLayerModeElemsType;

/**   \brief  value based type definition for EthIf_EthTrcvUsedOfPhysLayerModeElems */
typedef boolean EthIf_EthTrcvUsedOfPhysLayerModeElemsType;

/**   \brief  value based type definition for EthIf_PortGroupIdxOfPhysLayerModeElems */
typedef uint8 EthIf_PortGroupIdxOfPhysLayerModeElemsType;

/**   \brief  value based type definition for EthIf_PortGroupUsedOfPhysLayerModeElems */
typedef boolean EthIf_PortGroupUsedOfPhysLayerModeElemsType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfPortGroupIndEndIdxOfPortGroup */
typedef uint8 EthIf_EthIfCtrlOfPortGroupIndEndIdxOfPortGroupType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfPortGroupIndStartIdxOfPortGroup */
typedef uint8 EthIf_EthIfCtrlOfPortGroupIndStartIdxOfPortGroupType;

/**   \brief  value based type definition for EthIf_EthIfCtrlOfPortGroupIndUsedOfPortGroup */
typedef boolean EthIf_EthIfCtrlOfPortGroupIndUsedOfPortGroupType;

/**   \brief  value based type definition for EthIf_EthSwtPortIndEndIdxOfPortGroup */
typedef uint8 EthIf_EthSwtPortIndEndIdxOfPortGroupType;

/**   \brief  value based type definition for EthIf_EthSwtPortIndStartIdxOfPortGroup */
typedef uint8 EthIf_EthSwtPortIndStartIdxOfPortGroupType;

/**   \brief  value based type definition for EthIf_HostAndUpLinkPortThresholdOfPortGroup */
typedef uint8 EthIf_HostAndUpLinkPortThresholdOfPortGroupType;

/**   \brief  value based type definition for EthIf_NoRolePortThresholdOfPortGroup */
typedef uint8 EthIf_NoRolePortThresholdOfPortGroupType;

/**   \brief  value based type definition for EthIf_SemanticOfPortGroup */
typedef uint8 EthIf_SemanticOfPortGroupType;

/**   \brief  value based type definition for EthIf_SnvOfPortGroup */
typedef uint32 EthIf_SnvOfPortGroupType;

/**   \brief  value based type definition for EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
typedef uint8 EthIf_PortGroupHostOrUpLinkPortRoleLinkCountType;

/**   \brief  value based type definition for EthIf_PortGroupInd */
typedef uint8 EthIf_PortGroupIndType;

/**   \brief  value based type definition for EthIf_PortGroupNoRoleLinkCount */
typedef uint8 EthIf_PortGroupNoRoleLinkCountType;

/**   \brief  value based type definition for EthIf_PortGroupStartupActiveTimerActive */
typedef boolean EthIf_PortGroupStartupActiveTimerActiveType;

/**   \brief  value based type definition for EthIf_PortStartupActiveTimeCounter */
typedef uint16 EthIf_PortStartupActiveTimeCounterType;

/**   \brief  value based type definition for EthIf_PortStartupActiveTimeFreq */
typedef uint8 EthIf_PortStartupActiveTimeFreqType;

/**   \brief  value based type definition for EthIf_PortStartupActiveTimerActive */
typedef boolean EthIf_PortStartupActiveTimerActiveType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapIdxOfRxPdu */
typedef uint8 EthIf_EthIfCtrlToRxPduMapIdxOfRxPduType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapUsedOfRxPdu */
typedef boolean EthIf_EthIfCtrlToRxPduMapUsedOfRxPduType;

/**   \brief  value based type definition for EthIf_EthMacAddrOffsetOfRxPdu */
typedef uint8 EthIf_EthMacAddrOffsetOfRxPduType;

/**   \brief  value based type definition for EthIf_FloatingPoolOfRxPdu */
typedef boolean EthIf_FloatingPoolOfRxPduType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapIdxOfRxPdu */
typedef uint8 EthIf_FloatingRxPduMapIdxOfRxPduType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapUsedOfRxPdu */
typedef boolean EthIf_FloatingRxPduMapUsedOfRxPduType;

/**   \brief  value based type definition for EthIf_KeepLocalBufferOfRxPdu */
typedef boolean EthIf_KeepLocalBufferOfRxPduType;

/**   \brief  value based type definition for EthIf_RxPduMetaDataEndIdxOfRxPdu */
typedef uint8 EthIf_RxPduMetaDataEndIdxOfRxPduType;

/**   \brief  value based type definition for EthIf_RxPduMetaDataLengthOfRxPdu */
typedef uint8 EthIf_RxPduMetaDataLengthOfRxPduType;

/**   \brief  value based type definition for EthIf_RxPduMetaDataStartIdxOfRxPdu */
typedef uint8 EthIf_RxPduMetaDataStartIdxOfRxPduType;

/**   \brief  value based type definition for EthIf_RxPduMetaDataUsedOfRxPdu */
typedef boolean EthIf_RxPduMetaDataUsedOfRxPduType;

/**   \brief  value based type definition for EthIf_TimeTuplePtrOffsetOfRxPdu */
typedef uint8 EthIf_TimeTuplePtrOffsetOfRxPduType;

/**   \brief  value based type definition for EthIf_UlPduIdOfRxPdu */
typedef uint8 EthIf_UlPduIdOfRxPduType;

/**   \brief  value based type definition for EthIf_ValidEthMacAddrMetaDataOfRxPdu */
typedef boolean EthIf_ValidEthMacAddrMetaDataOfRxPduType;

/**   \brief  value based type definition for EthIf_ValidTimeTupleMetaDataOfRxPdu */
typedef boolean EthIf_ValidTimeTupleMetaDataOfRxPduType;

/**   \brief  value based type definition for EthIf_EthIfCtrlIdxOfRxPduContext */
typedef uint8 EthIf_EthIfCtrlIdxOfRxPduContextType;

/**   \brief  value based type definition for EthIf_RxHandleIdOfRxPduContext */
typedef uint32 EthIf_RxHandleIdOfRxPduContextType;

/**   \brief  value based type definition for EthIf_StateOfRxPduContext */
typedef uint8 EthIf_StateOfRxPduContextType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapEndIdxOfRxPduFrameType */
typedef uint8 EthIf_EthIfCtrlToRxPduMapEndIdxOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapLengthOfRxPduFrameType */
typedef uint8 EthIf_EthIfCtrlToRxPduMapLengthOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapStartIdxOfRxPduFrameType */
typedef uint8 EthIf_EthIfCtrlToRxPduMapStartIdxOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToRxPduMapUsedOfRxPduFrameType */
typedef boolean EthIf_EthIfCtrlToRxPduMapUsedOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_EtherTypeOfRxPduFrameType */
typedef uint8 EthIf_EtherTypeOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapEndIdxOfRxPduFrameType */
typedef uint8 EthIf_FloatingRxPduMapEndIdxOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapLengthOfRxPduFrameType */
typedef uint8 EthIf_FloatingRxPduMapLengthOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapStartIdxOfRxPduFrameType */
typedef uint8 EthIf_FloatingRxPduMapStartIdxOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_FloatingRxPduMapUsedOfRxPduFrameType */
typedef boolean EthIf_FloatingRxPduMapUsedOfRxPduFrameTypeType;

/**   \brief  value based type definition for EthIf_PduIdOfRxPduFreeList */
typedef uint16 EthIf_PduIdOfRxPduFreeListType;

/**   \brief  value based type definition for EthIf_RxPduMetaData */
typedef uint8 EthIf_RxPduMetaDataType;

/**   \brief  value based type definition for EthIf_EthRxQueueEndIdxOfRxQueueList */
typedef uint8 EthIf_EthRxQueueEndIdxOfRxQueueListType;

/**   \brief  value based type definition for EthIf_EthRxQueueLengthOfRxQueueList */
typedef uint8 EthIf_EthRxQueueLengthOfRxQueueListType;

/**   \brief  value based type definition for EthIf_EthRxQueueStartIdxOfRxQueueList */
typedef uint8 EthIf_EthRxQueueStartIdxOfRxQueueListType;

/**   \brief  value based type definition for EthIf_EthRxQueueUsedOfRxQueueList */
typedef boolean EthIf_EthRxQueueUsedOfRxQueueListType;

/**   \brief  value based type definition for EthIf_SetControllerModeTimeout */
typedef uint16 EthIf_SetControllerModeTimeoutType;

/**   \brief  value based type definition for EthIf_SignalQualityChgMainReload */
typedef uint8 EthIf_SignalQualityChgMainReloadType;

/**   \brief  value based type definition for EthIf_SignalQualityDecoupleFreqCnt */
typedef uint16 EthIf_SignalQualityDecoupleFreqCntType;

/**   \brief  value based type definition for EthIf_ValidOfSrcMacAddrBuffer */
typedef boolean EthIf_ValidOfSrcMacAddrBufferType;

/**   \brief  value based type definition for EthIf_SwtPortGroupModeChangeReqCnt */
typedef uint16 EthIf_SwtPortGroupModeChangeReqCntType;

/**   \brief  value based type definition for EthIf_SwtPortGroupModeChangeRetryCounter */
typedef uint16 EthIf_SwtPortGroupModeChangeRetryCounterType;

/**   \brief  value based type definition for EthIf_SwtPortGroupModeChangeRetryPeriodCounter */
typedef uint16 EthIf_SwtPortGroupModeChangeRetryPeriodCounterType;

/**   \brief  value based type definition for EthIf_EthIfCtrlIdxOfTxContext */
typedef uint8 EthIf_EthIfCtrlIdxOfTxContextType;

/**   \brief  value based type definition for EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContext */
typedef uint8 EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContextType;

/**   \brief  value based type definition for EthIf_PayloadLenOfTxContext */
typedef uint16 EthIf_PayloadLenOfTxContextType;

/**   \brief  value based type definition for EthIf_TxPendingOfTxContext */
typedef boolean EthIf_TxPendingOfTxContextType;

/**   \brief  value based type definition for EthIf_ValidOfTxContext */
typedef boolean EthIf_ValidOfTxContextType;

/**   \brief  value based type definition for EthIf_ValidPduIdOfTxContext */
typedef boolean EthIf_ValidPduIdOfTxContextType;

/**   \brief  value based type definition for EthIf_DirectDataProvisionOfTxPdu */
typedef boolean EthIf_DirectDataProvisionOfTxPduType;

/**   \brief  value based type definition for EthIf_EgressHardwareSupportedDataTransferOfTxPdu */
typedef boolean EthIf_EgressHardwareSupportedDataTransferOfTxPduType;

/**   \brief  value based type definition for EthIf_EthIfCtrlIdxOfTxPdu */
typedef uint8 EthIf_EthIfCtrlIdxOfTxPduType;

/**   \brief  value based type definition for EthIf_EthIfCtrlUsedOfTxPdu */
typedef boolean EthIf_EthIfCtrlUsedOfTxPduType;

/**   \brief  value based type definition for EthIf_EthMacAddrOffsetOfTxPdu */
typedef uint8 EthIf_EthMacAddrOffsetOfTxPduType;

/**   \brief  value based type definition for EthIf_EtherTypeOfTxPdu */
typedef uint8 EthIf_EtherTypeOfTxPduType;

/**   \brief  value based type definition for EthIf_FrameTxPriorityOfTxPdu */
typedef uint8 EthIf_FrameTxPriorityOfTxPduType;

/**   \brief  value based type definition for EthIf_KeepLocalBufferOfTxPdu */
typedef boolean EthIf_KeepLocalBufferOfTxPduType;

/**   \brief  value based type definition for EthIf_ListItemPtrOffsetOfTxPdu */
typedef uint8 EthIf_ListItemPtrOffsetOfTxPduType;

/**   \brief  value based type definition for EthIf_PriorityOffsetOfTxPdu */
typedef uint8 EthIf_PriorityOffsetOfTxPduType;

/**   \brief  value based type definition for EthIf_TimeTuplePtrOffsetOfTxPdu */
typedef uint8 EthIf_TimeTuplePtrOffsetOfTxPduType;

/**   \brief  value based type definition for EthIf_TotalMetaDataLengthOfTxPdu */
typedef uint8 EthIf_TotalMetaDataLengthOfTxPduType;

/**   \brief  value based type definition for EthIf_UlPduIdOfTxPdu */
typedef uint32 EthIf_UlPduIdOfTxPduType;

/**   \brief  value based type definition for EthIf_VLanOffsetOfTxPdu */
typedef uint8 EthIf_VLanOffsetOfTxPduType;

/**   \brief  value based type definition for EthIf_ValidEthMacAddrMetaDataOfTxPdu */
typedef boolean EthIf_ValidEthMacAddrMetaDataOfTxPduType;

/**   \brief  value based type definition for EthIf_ValidListItemMetaDataOfTxPdu */
typedef boolean EthIf_ValidListItemMetaDataOfTxPduType;

/**   \brief  value based type definition for EthIf_ValidPriority8MetaDataOfTxPdu */
typedef boolean EthIf_ValidPriority8MetaDataOfTxPduType;

/**   \brief  value based type definition for EthIf_ValidTimeTupleMetaDataOfTxPdu */
typedef boolean EthIf_ValidTimeTupleMetaDataOfTxPduType;

/**   \brief  value based type definition for EthIf_ValidVlan16MetaDataOfTxPdu */
typedef boolean EthIf_ValidVlan16MetaDataOfTxPduType;

/**   \brief  value based type definition for EthIf_StateOfTxPduContext */
typedef uint8 EthIf_StateOfTxPduContextType;

/**   \brief  value based type definition for EthIf_EthTxQueueEndIdxOfTxQueueList */
typedef uint8 EthIf_EthTxQueueEndIdxOfTxQueueListType;

/**   \brief  value based type definition for EthIf_EthTxQueueLengthOfTxQueueList */
typedef uint8 EthIf_EthTxQueueLengthOfTxQueueListType;

/**   \brief  value based type definition for EthIf_EthTxQueueStartIdxOfTxQueueList */
typedef uint8 EthIf_EthTxQueueStartIdxOfTxQueueListType;

/**   \brief  value based type definition for EthIf_EthTxQueueUsedOfTxQueueList */
typedef boolean EthIf_EthTxQueueUsedOfTxQueueListType;

/**   \brief  value based type definition for EthIf_WakeupSrcDeviceEndIdxOfWakeupMap */
typedef uint8 EthIf_WakeupSrcDeviceEndIdxOfWakeupMapType;

/**   \brief  value based type definition for EthIf_WakeupSrcDeviceLengthOfWakeupMap */
typedef uint8 EthIf_WakeupSrcDeviceLengthOfWakeupMapType;

/**   \brief  value based type definition for EthIf_WakeupSrcDeviceStartIdxOfWakeupMap */
typedef uint8 EthIf_WakeupSrcDeviceStartIdxOfWakeupMapType;

/**   \brief  value based type definition for EthIf_WakeupSrcDeviceUsedOfWakeupMap */
typedef boolean EthIf_WakeupSrcDeviceUsedOfWakeupMapType;

/**   \brief  value based type definition for EthIf_EthSwtIdxOfWakeupSrcDevice */
typedef uint8 EthIf_EthSwtIdxOfWakeupSrcDeviceType;

/**   \brief  value based type definition for EthIf_EthSwtUsedOfWakeupSrcDevice */
typedef boolean EthIf_EthSwtUsedOfWakeupSrcDeviceType;

/**   \brief  value based type definition for EthIf_EthTrcvIdxOfWakeupSrcDevice */
typedef uint8 EthIf_EthTrcvIdxOfWakeupSrcDeviceType;

/**   \brief  value based type definition for EthIf_EthTrcvUsedOfWakeupSrcDevice */
typedef boolean EthIf_EthTrcvUsedOfWakeupSrcDeviceType;

/**   \brief  value based type definition for EthIf_TypeOfWakeupSrcDevice */
typedef uint8 EthIf_TypeOfWakeupSrcDeviceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthIfPCStructTypes  EthIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in EthIf_EcucPartition */
typedef struct sEthIf_EcucPartitionType
{
  EthIf_QualityLevelOfEcucPartitionType QualityLevelOfEcucPartition;  /**< EcuC partition quality level */
} EthIf_EcucPartitionType;

/**   \brief  type used in EthIf_EthCtrl */
typedef struct sEthIf_EthCtrlType
{
  EthIf_SnvOfEthCtrlType SnvOfEthCtrl;  /**< SNV of the Eth controller */
  EthIf_BufIdxOffsetEnabledOfEthCtrlType BufIdxOffsetEnabledOfEthCtrl;  /**< Indicates if the buffer index offset as per AR24-11 is enabled. */
  EthIf_EthArReleaseRxBufferSupportedOfEthCtrlType EthArReleaseRxBufferSupportedOfEthCtrl;  /**< Indicates if the Ethernet Controller supports the Eth_Drv_ReleaseRxBuffer API as per AR23-11. */
  EthIf_ImplicitBufferReleaseNeededOfEthCtrlType ImplicitBufferReleaseNeededOfEthCtrl;  /**< Indicates if frames shall be implicitly released by the EthIf. */
  EthIf_EthDrvApiIdxOfEthCtrlType EthDrvApiIdxOfEthCtrl;  /**< the index of the 1:1 relation pointing to EthIf_EthDrvApi */
  EthIf_NumOfTxBuffersOfEthCtrlType NumOfTxBuffersOfEthCtrl;  /**< Total number of Tx buffers configured in this controller. */
  EthIf_TxContextEndIdxOfEthCtrlType TxContextEndIdxOfEthCtrl;  /**< the end index of the 1:n relation pointing to EthIf_TxContext */
  EthIf_TxContextLengthOfEthCtrlType TxContextLengthOfEthCtrl;  /**< the number of relations pointing to EthIf_TxContext */
  EthIf_TxContextStartIdxOfEthCtrlType TxContextStartIdxOfEthCtrl;  /**< the start index of the 1:n relation pointing to EthIf_TxContext */
} EthIf_EthCtrlType;

/**   \brief  type used in EthIf_EthDrvApi */
typedef struct sEthIf_EthDrvApiType
{
  EthIf_EthCtrlInitFctPtrType CtrlInitOfEthDrvApi;  /**< Eth_ControllerInit() of Eth driver */
  EthIf_EthEnableEgressTimeStampFctPtrType EnableEgressTimeStampOfEthDrvApi;  /**< Eth_EnableEgressTimeStamp() of Eth driver. */
  EthIf_EthGetBandwidthLimitFctPtrType GetBandwidthLimitOfEthDrvApi;  /**< Eth_GetBandwidthLimit() of Eth driver. */
  EthIf_EthGetCtrlModeFctPtrType GetCtrlModeOfEthDrvApi;  /**< Eth_GetControllerMode() of Eth driver */
  EthIf_EthGetCurrentTimeFctPtrType GetCurrentTimeOfEthDrvApi;  /**< Eth_GetCurrentTime() of Eth driver. */
  EthIf_EthGetEgressTimeStampFctPtrType GetEgressTimeStampOfEthDrvApi;  /**< Eth_GetEgressTimeStamp() of Eth driver. */
  EthIf_EthGetIngressTimeStampFctPtrType GetIngressTimeStampOfEthDrvApi;  /**< Eth_GetIngressTimeStamp() of Eth driver. */
  EthIf_EthGetPhysAddrFctPtrType GetPhysAddrOfEthDrvApi;  /**< Eth_GetPhysAddr() of Eth driver */
  EthIf_EthGetRxHeaderPtrFctPtrType GetRxHeaderPtrOfEthDrvApi;  /**< Eth_GetRxHeaderPtr() of Eth driver. */
  EthIf_EthGetRxStatsFctPtrType GetRxStatsOfEthDrvApi;  /**< Eth_GetRxStats() of Eth driver */
  EthIf_EthGetSpiStatusFctPtrType GetSpiStatusOfEthDrvApi;  /**< Eth_GetSpiStatus() of Eth driver */
  EthIf_EthGetTxHeaderPtrFctPtrType GetTxHeaderPtrOfEthDrvApi;  /**< Eth_GetTxHeaderPtr() of Eth driver. */
  EthIf_EthGetTxStatsFctPtrType GetTxStatsOfEthDrvApi;  /**< Eth_GetTxStats() of Eth driver */
  EthIf_EthImmediateTransmitFctPtrType ImmediateTransmitOfEthDrvApi;  /**< Eth_ImmediateTransmit() of Eth driver */
  EthIf_EthProvideExtTxBufferFctPtrType ProvideExtTxBufferOfEthDrvApi;  /**< Eth_ProvideExtTxBuffer() of Eth driver. */
  EthIf_EthProvideTxBufferFctPtrType ProvideTxBufferOfEthDrvApi;  /**< Eth_ProvideTxBuffer() of Eth driver */
  EthIf_EthReceiveFctPtrType ReceiveOfEthDrvApi;  /**< Eth_Receive() of Eth driver */
  EthIf_EthReceiveQueueFctPtrType ReceiveQueueOfEthDrvApi;  /**< Eth_ReceiveQueue() of Eth driver (Fifo/Queue specific reception) */
  EthIf_EthReleaseRxBufferFctPtrType ReleaseRxBufferOfEthDrvApi;  /**< Eth_ReleaseRxBuffer() of Eth driver as per AR23-11. */
  EthIf_EthSetBandwidthLimitFctPtrType SetBandwidthLimitOfEthDrvApi;  /**< Eth_SetBandwidthLimit() of Eth driver. */
  EthIf_EthSetCtrlModeFctPtrType SetCtrlModeOfEthDrvApi;  /**< Eth_SetControllerMode() of Eth driver */
  EthIf_EthSetPhysAddrFctPtrType SetPhysAddrOfEthDrvApi;  /**< Eth_SetPhysAddr() of Eth driver */
  EthIf_EthTransmitFctPtrType TransmitOfEthDrvApi;  /**< Eth_Transmit() of Eth driver */
  EthIf_EthTxConfirmationFctPtrType TxConfirmationOfEthDrvApi;  /**< Eth_TxConfirmation() of Eth driver */
  EthIf_EthTxConfirmationQueueFctPtrType TxConfirmationQueueOfEthDrvApi;  /**< Eth_TxConfirmationQueue() of Eth driver (Fifo/Queue specific reception) */
  EthIf_EthUpdatePhysAddrFilterFctPtrType UpdatePhysAddrFilterOfEthDrvApi;  /**< Eth_UpdatePhysAddrFilter() of Eth driver */
  EthIf_EthVGetEgressTimeStampFctPtrType VGetEgressTimeStampOfEthDrvApi;  /**< Eth_VGetEgressTimeStamp() of Eth driver. */
  EthIf_EthVReleaseRxBufferFctPtrType VReleaseRxBufferOfEthDrvApi;  /**< Eth_ReleaseRxBuffer() of Eth driver as per vector extension. */
  EthIf_EthVTransmitFctPtrType VTransmitOfEthDrvApi;  /**< Eth_VTransmit() of Eth driver */
} EthIf_EthDrvApiType;

/**   \brief  type used in EthIf_EthIfClkUnit */
typedef struct sEthIf_EthIfClkUnitType
{
  EthIf_EthClkUnitIdxOfEthIfClkUnitType EthClkUnitIdxOfEthIfClkUnit;  /**< Zero-based consecutive index of the HW clock units in the Ethernet Controller in Eth context. */
  EthIf_EthIfClkUnitIdxOfEthIfClkUnitType EthIfClkUnitIdxOfEthIfClkUnit;  /**< Zero-based consecutive index of the HW clock units in the Ethernet Controller in EthIf context. */
} EthIf_EthIfClkUnitType;

/**   \brief  type used in EthIf_EthIfCtrl */
typedef struct sEthIf_EthIfCtrlType
{
  EthIf_SnvOfEthIfCtrlType SnvOfEthIfCtrl;  /**< SNV of the EthIf Controller */
  EthIf_MtuOfEthIfCtrlType MtuOfEthIfCtrl;  /**< Maximum transfer unit of the EthIf Controller */
  EthIf_VlanIdOfEthIfCtrlType VlanIdOfEthIfCtrl;  /**< VLAN ID associated with the EthIf Controller */
  EthIf_EcucPartitionIdxOfEthIfCtrlType EcucPartitionIdxOfEthIfCtrl;  /**< the index of the 0:1 relation pointing to EthIf_EcucPartition */
  EthIf_EthCtrlIdxOfEthIfCtrlType EthCtrlIdxOfEthIfCtrl;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
  EthIf_EthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrlType EthIfCtrlToEtherTypeMapEndIdxOfEthIfCtrl;  /**< the end index of the 1:n relation pointing to EthIf_EthIfCtrlToEtherTypeMap */
  EthIf_EthIfCtrlToEtherTypeMapLengthOfEthIfCtrlType EthIfCtrlToEtherTypeMapLengthOfEthIfCtrl;  /**< the number of relations pointing to EthIf_EthIfCtrlToEtherTypeMap */
  EthIf_EthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrlType EthIfCtrlToEtherTypeMapStartIdxOfEthIfCtrl;  /**< the start index of the 1:n relation pointing to EthIf_EthIfCtrlToEtherTypeMap */
  EthIf_EthIfPhysCtrlCfgIdxOfEthIfCtrlType EthIfPhysCtrlCfgIdxOfEthIfCtrl;  /**< the index of the 1:1 relation pointing to EthIf_EthIfPhysCtrlCfg */
  EthIf_EthSwtDrvApiIdxOfEthIfCtrlType EthSwtDrvApiIdxOfEthIfCtrl;  /**< the index of the 0:1 relation pointing to EthIf_EthSwtDrvApi */
  EthIf_GatewayDestEthIfCtrlIdxOfEthIfCtrlType GatewayDestEthIfCtrlIdxOfEthIfCtrl;  /**< the enum value of the according target of the 0:1 relation pointing to EthIf_EthIfCtrl */
  EthIf_GatewayDestEthIfCtrlIdxIdxOfEthIfCtrlType GatewayDestEthIfCtrlIdxIdxOfEthIfCtrl;  /**< the index of the 0:1 relation pointing to EthIf_EthIfCtrl */
  EthIf_LinkAggrThresholdOfEthIfCtrlType LinkAggrThresholdOfEthIfCtrl;  /**< Threshold when a link is issued on EthIf controller level. */
  EthIf_MacSecTypeOfEthIfCtrlType MacSecTypeOfEthIfCtrl;  /**< MACsec Type of the EthIf Controller */
  EthIf_MirrorRxDestIdxOfEthIfCtrlType MirrorRxDestIdxOfEthIfCtrl;  /**< the enum value of the according target of the 0:1 relation pointing to EthIf_MirrorDest */
  EthIf_MirrorRxDestIdxIdxOfEthIfCtrlType MirrorRxDestIdxIdxOfEthIfCtrl;  /**< the index of the 0:1 relation pointing to EthIf_MirrorDest */
  EthIf_MirrorTxDestIdxOfEthIfCtrlType MirrorTxDestIdxOfEthIfCtrl;  /**< the enum value of the according target of the 0:1 relation pointing to EthIf_MirrorDest */
  EthIf_MirrorTxDestIdxIdxOfEthIfCtrlType MirrorTxDestIdxIdxOfEthIfCtrl;  /**< the index of the 0:1 relation pointing to EthIf_MirrorDest */
  EthIf_PhysLayerInitElemsIdxOfEthIfCtrlType PhysLayerInitElemsIdxOfEthIfCtrl;  /**< the index of the 1:1 relation pointing to EthIf_PhysLayerInitElems */
  EthIf_PhysLayerModeElemsIdxOfEthIfCtrlType PhysLayerModeElemsIdxOfEthIfCtrl;  /**< the index of the 1:1 relation pointing to EthIf_PhysLayerModeElems */
  EthIf_TypeOfEthIfCtrlType TypeOfEthIfCtrl;  /**< Type of the EthIf Controller */
} EthIf_EthIfCtrlType;

/**   \brief  type used in EthIf_EthIfCtrlRxStats */
typedef struct sEthIf_EthIfCtrlRxStatsType
{
  EthIf_NumRxBytesOfEthIfCtrlRxStatsType NumRxBytesOfEthIfCtrlRxStats;  /**< Number of bytes received on EthIf controller */
  EthIf_NumRxPktsOfEthIfCtrlRxStatsType NumRxPktsOfEthIfCtrlRxStats;  /**< Number of packets received on EthIf controller */
} EthIf_EthIfCtrlRxStatsType;

/**   \brief  type used in EthIf_EthIfCtrlToEtherTypeMap */
typedef struct sEthIf_EthIfCtrlToEtherTypeMapType
{
  EthIf_EtherTypeOfEthIfCtrlToEtherTypeMapType EtherTypeOfEthIfCtrlToEtherTypeMap;  /**< EtherType linked to an EthIf controller users RxIndication/TxConfirmation. */
  EthIf_RxIndicationsEndIdxOfEthIfCtrlToEtherTypeMapType RxIndicationsEndIdxOfEthIfCtrlToEtherTypeMap;  /**< the end index of the 0:n relation pointing to EthIf_RxIndications */
  EthIf_RxIndicationsLengthOfEthIfCtrlToEtherTypeMapType RxIndicationsLengthOfEthIfCtrlToEtherTypeMap;  /**< the number of relations pointing to EthIf_RxIndications */
  EthIf_RxIndicationsStartIdxOfEthIfCtrlToEtherTypeMapType RxIndicationsStartIdxOfEthIfCtrlToEtherTypeMap;  /**< the start index of the 0:n relation pointing to EthIf_RxIndications */
  EthIf_TxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMapType TxConfirmationsEndIdxOfEthIfCtrlToEtherTypeMap;  /**< the end index of the 0:n relation pointing to EthIf_TxConfirmations */
  EthIf_TxConfirmationsLengthOfEthIfCtrlToEtherTypeMapType TxConfirmationsLengthOfEthIfCtrlToEtherTypeMap;  /**< the number of relations pointing to EthIf_TxConfirmations */
  EthIf_TxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMapType TxConfirmationsStartIdxOfEthIfCtrlToEtherTypeMap;  /**< the start index of the 0:n relation pointing to EthIf_TxConfirmations */
} EthIf_EthIfCtrlToEtherTypeMapType;

/**   \brief  type used in EthIf_EthIfCtrlToRxPduMap */
typedef struct sEthIf_EthIfCtrlToRxPduMapType
{
  EthIf_RxPduCountOfEthIfCtrlToRxPduMapType RxPduCountOfEthIfCtrlToRxPduMap;  /**< Total number of Rx PDUs configured for the given EtherType and EthIf controller. */
  EthIf_RxPduEndIdxOfEthIfCtrlToRxPduMapType RxPduEndIdxOfEthIfCtrlToRxPduMap;  /**< the end index of the 0:n relation pointing to EthIf_RxPdu */
  EthIf_RxPduLengthOfEthIfCtrlToRxPduMapType RxPduLengthOfEthIfCtrlToRxPduMap;  /**< the number of relations pointing to EthIf_RxPdu */
  EthIf_RxPduStartIdxOfEthIfCtrlToRxPduMapType RxPduStartIdxOfEthIfCtrlToRxPduMap;  /**< the start index of the 0:n relation pointing to EthIf_RxPdu */
} EthIf_EthIfCtrlToRxPduMapType;

/**   \brief  type used in EthIf_EthIfCtrlTxStats */
typedef struct sEthIf_EthIfCtrlTxStatsType
{
  EthIf_NumTxBytesOfEthIfCtrlTxStatsType NumTxBytesOfEthIfCtrlTxStats;  /**< Number of bytes transmitted on EthIf controller */
  EthIf_NumTxPktsOfEthIfCtrlTxStatsType NumTxPktsOfEthIfCtrlTxStats;  /**< Number of packets transmitted on EthIf controller */
} EthIf_EthIfCtrlTxStatsType;

/**   \brief  type used in EthIf_EthIfMeasurementData */
typedef struct sEthIf_EthIfMeasurementDataType
{
  EthIf_DropCtrlIdxOfEthIfMeasurementDataType DropCtrlIdxOfEthIfMeasurementData;  /**< Number of dropped datagrams caused by invalid CtrlIdx/VLAN */
  EthIf_UnknownEtherTypeOfEthIfMeasurementDataType UnknownEtherTypeOfEthIfMeasurementData;  /**< Number of dropped datagrams caused by unknown EtherType */
  EthIf_VlanDoubleTaggedOfEthIfMeasurementDataType VlanDoubleTaggedOfEthIfMeasurementData;  /**< Number of received datagrams with detected double VLAN tag */
} EthIf_EthIfMeasurementDataType;

/**   \brief  type used in EthIf_EthIfPhysCtrlCfg */
typedef struct sEthIf_EthIfPhysCtrlCfgType
{
  EthIf_EthCtrlIdxOfEthIfPhysCtrlCfgType EthCtrlIdxOfEthIfPhysCtrlCfg;  /**< SNV of the Eth controller */
  EthIf_EthIfPhysControllerIdxOfEthIfPhysCtrlCfgType EthIfPhysControllerIdxOfEthIfPhysCtrlCfg;  /**< Zero-based consecutive index of the physical Ethernet Controllers in EthIf context. */
  EthIf_EthPhcSupportAvailableOfEthIfPhysCtrlCfgType EthPhcSupportAvailableOfEthIfPhysCtrlCfg;  /**< Indicates if the PhcSupport APIs (AR&gt;=23-11) are supported by the controller. */
  EthIf_EthDrvApiIdxOfEthIfPhysCtrlCfgType EthDrvApiIdxOfEthIfPhysCtrlCfg;  /**< the index of the 1:1 relation pointing to EthIf_EthDrvApi */
  EthIf_EthIfClkUnitEndIdxOfEthIfPhysCtrlCfgType EthIfClkUnitEndIdxOfEthIfPhysCtrlCfg;  /**< the end index of the 0:n relation pointing to EthIf_EthIfClkUnit */
  EthIf_EthIfClkUnitLengthOfEthIfPhysCtrlCfgType EthIfClkUnitLengthOfEthIfPhysCtrlCfg;  /**< the number of relations pointing to EthIf_EthIfClkUnit */
  EthIf_EthIfClkUnitStartIdxOfEthIfPhysCtrlCfgType EthIfClkUnitStartIdxOfEthIfPhysCtrlCfg;  /**< the start index of the 0:n relation pointing to EthIf_EthIfClkUnit */
} EthIf_EthIfPhysCtrlCfgType;

/**   \brief  type used in EthIf_EthRxQueue */
typedef struct sEthIf_EthRxQueueType
{
  EthIf_EthCtrlIdxOfEthRxQueueType EthCtrlIdxOfEthRxQueue;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
  EthIf_QueueIndexOfEthRxQueueType QueueIndexOfEthRxQueue;  /**< Index of the Rx queue. */
} EthIf_EthRxQueueType;

/**   \brief  type used in EthIf_EthSwt */
typedef struct sEthIf_EthSwtType
{
  EthIf_SnvOfEthSwtType SnvOfEthSwt;  /**< SNV of the Eth switch */
  EthIf_EthSwtDrvApiIdxOfEthSwtType EthSwtDrvApiIdxOfEthSwt;  /**< the index of the 1:1 relation pointing to EthIf_EthSwtDrvApi */
  EthIf_EthSwtPortInEthSwtContextEndIdxOfEthSwtType EthSwtPortInEthSwtContextEndIdxOfEthSwt;  /**< the end index of the 0:n relation pointing to EthIf_EthSwtPortInEthSwtContext */
  EthIf_EthSwtPortInEthSwtContextLengthOfEthSwtType EthSwtPortInEthSwtContextLengthOfEthSwt;  /**< the number of relations pointing to EthIf_EthSwtPortInEthSwtContext */
  EthIf_EthSwtPortInEthSwtContextStartIdxOfEthSwtType EthSwtPortInEthSwtContextStartIdxOfEthSwt;  /**< the start index of the 0:n relation pointing to EthIf_EthSwtPortInEthSwtContext */
} EthIf_EthSwtType;

/**   \brief  type used in EthIf_EthSwtDrv */
typedef struct sEthIf_EthSwtDrvType
{
  EthIf_EthSwtEndIdxOfEthSwtDrvType EthSwtEndIdxOfEthSwtDrv;  /**< the end index of the 1:n relation pointing to EthIf_EthSwt */
  EthIf_EthSwtLengthOfEthSwtDrvType EthSwtLengthOfEthSwtDrv;  /**< the number of relations pointing to EthIf_EthSwt */
  EthIf_EthSwtStartIdxOfEthSwtDrvType EthSwtStartIdxOfEthSwtDrv;  /**< the start index of the 1:n relation pointing to EthIf_EthSwt */
} EthIf_EthSwtDrvType;

/**   \brief  type used in EthIf_EthSwtDrvApi */
typedef struct sEthIf_EthSwtDrvApiType
{
  EthIf_EthSwtCheckWakeupFctPtrType CheckWakeupOfEthSwtDrvApi;  /**< EthSwt_CheckWakeup() of the EthSwt driver */
  EthIf_EthSwtEnableVlanFctPtrType EnableVlanOfEthSwtDrvApi;  /**< EthSwt_EnableVlan() of the EthSwt driver */
  EthIf_EthSwtGetArlTableFctPtrType GetArlTableOfEthSwtDrvApi;  /**< EthSwt_GetArlTable() of the EthSwt driver */
  EthIf_EthSwtGetBaudRateFctPtrType GetBaudRateOfEthSwtDrvApi;  /**< EthSwt_GetBaudRate() of the EthSwt driver */
  EthIf_EthSwtGetBufferLevelFctPtrType GetBufferLevelOfEthSwtDrvApi;  /**< EthSwt_GetBufferLevel() of the EthSwt driver */
  EthIf_EthSwtGetCounterValuesFctPtrType GetCounterValuesOfEthSwtDrvApi;  /**< EthSwt_GetCounterValues() of the EthSwt driver */
  EthIf_EthSwtGetDropCountFctPtrType GetDropCountOfEthSwtDrvApi;  /**< EthSwt_GetDropCount() of the EthSwt driver */
  EthIf_EthSwtGetDuplexModeFctPtrType GetDuplexModeOfEthSwtDrvApi;  /**< EthSwt_GetDuplexMode() of the EthSwt driver */
  EthIf_EthSwtGetLinkStateFctPtrType GetLinkStateOfEthSwtDrvApi;  /**< EthSwt_GetLinkState() of the EthSwt driver */
  EthIf_EthSwtGetMacLearningModeFctPtrType GetMacLearningModeOfEthSwtDrvApi;  /**< EthSwt_GetMacLearningMode() of the EthSwt driver */
  EthIf_EthSwtGetPortCableDiagnosticsResultFctPtrType GetPortCableDiagnosticsResultOfEthSwtDrvApi;  /**< EthSwt_GetPortCableDiagnosticsResult() of the EthSwt driver */
  EthIf_EthSwtGetPortMacAddrFctPtrType GetPortMacAddrOfEthSwtDrvApi;  /**< EthSwt_GetPortMacAddr() of the EthSwt driver */
  EthIf_EthSwtGetPortSignalQualityFctPtrType GetPortSignalQualityOfEthSwtDrvApi;  /**< EthSwt_GetPortSignalQuality() of the EthSwt driver */
  EthIf_EthSwtGetRxMgmtObjectFctPtrType GetRxMgmtObjectOfEthSwtDrvApi;  /**< EthSwt_GetRxMgmtObject() of the EthSwt driver */
  EthIf_EthSwtGetRxStatsFctPtrType GetRxStatsOfEthSwtDrvApi;  /**< EthSwt_GetRxStats() of the EthSwt driver */
  EthIf_EthSwtGetSwitchPortWakeupReasonFctPtrType GetSwitchPortWakeupReasonOfEthSwtDrvApi;  /**< EthSwt_GetSwitchPortWakeupReason() of the EthSwt driver */
  EthIf_EthSwtGetSwtPortModeFctPtrType GetSwtPortModeOfEthSwtDrvApi;  /**< EthSwt_GetSwitchPortMode() of the EthSwt driver */
  EthIf_EthSwtGetTxErrorCounterValuesFctPtrType GetTxErrorCounterValuesOfEthSwtDrvApi;  /**< EthSwt_GetTxErrorCounterValues() of the EthSwt driver */
  EthIf_EthSwtGetTxMgmtObjectFctPtrType GetTxMgmtObjectOfEthSwtDrvApi;  /**< EthSwt_GetTxMgmtObject() of the EthSwt driver */
  EthIf_EthSwtGetTxStatsFctPtrType GetTxStatsOfEthSwtDrvApi;  /**< EthSwt_GetTxStats() of the EthSwt driver */
  EthIf_EthSwtPortEnableTimeStampFctPtrType PortEnableTimeStampOfEthSwtDrvApi;  /**< EthSwt_PortEnableTimeStamp() of the EthSwt driver */
  EthIf_EthSwtResetConfigFctPtrType ResetConfigOfEthSwtDrvApi;  /**< EthSwt_ResetConfig() of the EthSwt driver */
  EthIf_EthSwtRunPortCableDiagnosticFctPtrType RunPortCableDiagnosticOfEthSwtDrvApi;  /**< EthSwt_RunPortCableDiagnostic() of the EthSwt driver */
  EthIf_EthSwtSetCorrectionTimeFctPtrType SetCorrectionTimeOfEthSwtDrvApi;  /**< EthSwt_SetCorrectionTime() of the EthSwt driver */
  EthIf_EthSwtSetMacLearningModeFctPtrType SetMacLearningModeOfEthSwtDrvApi;  /**< EthSwt_SetMacLearningMode() of the EthSwt driver */
  EthIf_EthSwtSetSwtMgmtInfoFctPtrType SetSwtMgmtInfoOfEthSwtDrvApi;  /**< EthSwt_SetSwtMgmtInfo() of the EthSwt driver */
  EthIf_EthSwtSetSwtPortModeFctPtrType SetSwtPortModeOfEthSwtDrvApi;  /**< EthSwt_SetSwitchPortMode() of the EthSwt driver */
  EthIf_EthSwtStartQbvScheduleFctPtrType StartQbvScheduleOfEthSwtDrvApi;  /**< EthSwt_StartQbvSchedule() of the EthSwt driver */
  EthIf_EthSwtStartSwtPortAutoNegFctPtrType StartSwtPortAutoNegOfEthSwtDrvApi;  /**< EthSwt_StartSwitchPortAutoNegotiation() of the EthSwt driver */
  EthIf_EthSwtStopQbvScheduleFctPtrType StopQbvScheduleOfEthSwtDrvApi;  /**< EthSwt_StopQbvSchedule() of the EthSwt driver */
  EthIf_EthSwtStoreConfigFctPtrType StoreConfigOfEthSwtDrvApi;  /**< EthSwt_StoreConfig() of the EthSwt driver */
  EthIf_EthSwtSwtInitFctPtrType SwtInitOfEthSwtDrvApi;  /**< EthSwt_SwitchInit() of the EthSwt driver */
  EthIf_EthSwtUpdateMCastPortAssignmentFctPtrType UpdateMCastPortAssignmentOfEthSwtDrvApi;  /**< EthSwt_UpdateMCastPortAssignment() of the EthSwt driver */
} EthIf_EthSwtDrvApiType;

/**   \brief  type used in EthIf_EthSwtPort */
typedef struct sEthIf_EthSwtPortType
{
  EthIf_SnvOfEthSwtPortType SnvOfEthSwtPort;  /**< SNV of the EthSwt port */
  EthIf_AsyncProcessingOfEthSwtPortType AsyncProcessingOfEthSwtPort;  /**< Indicates if the mode change in the switch port is performed asynchronously */
  EthIf_MacSecSecuredOfEthSwtPortType MacSecSecuredOfEthSwtPort;  /**< Indicates if switch port is MACsec secured */
  EthIf_EthSwtIdxOfEthSwtPortType EthSwtIdxOfEthSwtPort;  /**< the index of the 1:1 relation pointing to EthIf_EthSwt */
  EthIf_EthSwtPortHostOrUpLinkPortIdxOfEthSwtPortType EthSwtPortHostOrUpLinkPortIdxOfEthSwtPort;  /**< the index of the 1:1 relation pointing to EthIf_EthSwtPort */
  EthIf_MkaPaeIdxOfEthSwtPortType MkaPaeIdxOfEthSwtPort;  /**< PaeIdx of switch port */
  EthIf_PortGroupIndEndIdxOfEthSwtPortType PortGroupIndEndIdxOfEthSwtPort;  /**< the end index of the 1:n relation pointing to EthIf_PortGroupInd */
  EthIf_PortGroupIndStartIdxOfEthSwtPortType PortGroupIndStartIdxOfEthSwtPort;  /**< the start index of the 1:n relation pointing to EthIf_PortGroupInd */
  EthIf_PortRoleOfEthSwtPortType PortRoleOfEthSwtPort;  /**< Port Role of switch port */
} EthIf_EthSwtPortType;

/**   \brief  type used in EthIf_EthSwtPortInEthSwtContext */
typedef struct sEthIf_EthSwtPortInEthSwtContextType
{
  EthIf_EthSwtPortIdxOfEthSwtPortInEthSwtContextType EthSwtPortIdxOfEthSwtPortInEthSwtContext;  /**< the index of the 0:1 relation pointing to EthIf_EthSwtPort */
} EthIf_EthSwtPortInEthSwtContextType;

/**   \brief  type used in EthIf_EthTrcv */
typedef struct sEthIf_EthTrcvType
{
  EthIf_SnvOfEthTrcvType SnvOfEthTrcv;  /**< SNV of the EthTrcv */
  EthIf_AsyncProcessingOfEthTrcvType AsyncProcessingOfEthTrcv;  /**< Indicates if the mode change in the transceiver is performed asynchronously */
  EthIf_EthTrcvActAsSlavePassiveEnabledOfEthTrcvType EthTrcvActAsSlavePassiveEnabledOfEthTrcv;  /**< Indicates if Passive slave enabled for Eth Trcv */
  EthIf_MacSecSecuredOfEthTrcvType MacSecSecuredOfEthTrcv;  /**< Indicates if transceiver is MACsec secured */
  EthIf_EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcvType EthIfCtrlOfEthTrcvIndEndIdxOfEthTrcv;  /**< the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd */
  EthIf_EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcvType EthIfCtrlOfEthTrcvIndStartIdxOfEthTrcv;  /**< the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd */
  EthIf_EthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcvType EthIfQualifiedUnexpectedLinkDownTimeCountsOfEthTrcv;  /**< Specifies the time in main function periodicity if an unexpected link down is qualified. */
  EthIf_EthTrcvDrvApiIdxOfEthTrcvType EthTrcvDrvApiIdxOfEthTrcv;  /**< the index of the 1:1 relation pointing to EthIf_EthTrcvDrvApi */
  EthIf_EthTrcvTypeOfEthTrcvType EthTrcvTypeOfEthTrcv;  /**< Indicates if the transceiver is standalone or connected to a switch port. */
  EthIf_MkaPaeIdxOfEthTrcvType MkaPaeIdxOfEthTrcv;  /**< PaeIdx of transceiver */
  EthIf_PortModeIdxOfEthTrcvType PortModeIdxOfEthTrcv;  /**< the index of the 0:1 relation pointing to EthIf_PortMode */
  EthIf_RequestedPortModeIdxOfEthTrcvType RequestedPortModeIdxOfEthTrcv;  /**< the index of the 0:1 relation pointing to EthIf_RequestedPortMode */
  EthIf_UserSleepIndicationFctPtrType UserSleepIndicationOfEthTrcv;  /**< User sleep indication of the EthIf Trcv. */
} EthIf_EthTrcvType;

/**   \brief  type used in EthIf_EthTrcvDrvApi */
typedef struct sEthIf_EthTrcvDrvApiType
{
  EthIf_EthTrcvCheckWakeupFctPtrType CheckWakeupOfEthTrcvDrvApi;  /**< EthTrcv_CheckWakeup() of the EthTrcv driver */
  EthIf_EthTrcvGetBaudRateFctPtrType GetBaudRateOfEthTrcvDrvApi;  /**< EthTrcv_GetBaudRate() of the EthTrcv driver */
  EthIf_EthTrcvGetCableDiagnosticsResultFctPtrType GetCableDiagnosticsResultOfEthTrcvDrvApi;  /**< EthTrcv_GetCableDiagnosticsResult() of the EthTrcv driver */
  EthIf_EthTrcvGetDuplexModeFctPtrType GetDuplexModeOfEthTrcvDrvApi;  /**< EthTrcv_GetDuplexMode() of the EthTrcv driver */
  EthIf_EthTrcvGetLinkStateFctPtrType GetLinkStateOfEthTrcvDrvApi;  /**< EthTrcv_GetLinkState() of the EthTrcv driver */
  EthIf_EthTrcvGetPhySignalQualityFctPtrType GetPhySignalQualityOfEthTrcvDrvApi;  /**< EthTrcv_GetPhySignalQuality() of the EthTrcv driver */
  EthIf_EthTrcvGetPhyWakeupReasonFctPtrType GetPhyWakeupReasonOfEthTrcvDrvApi;  /**< EthTrcv_GetBusWuReason() of the EthTrcv driver */
  EthIf_EthTrcvGetTrcvModeFctPtrType GetTrcvModeOfEthTrcvDrvApi;  /**< EthTrcv_GetTransceiverMode() of the EthTrcv driver */
  EthIf_EthTrcvRunCableDiagnosticFctPtrType RunCableDiagnosticOfEthTrcvDrvApi;  /**< RunCableDiagnostic() of the EthTrcv driver */
  EthIf_EthTrcvSetPhyLoopbackModeFctPtrType SetPhyLoopbackModeOfEthTrcvDrvApi;  /**< SetPhyLoopbackMode() of the EthTrcv driver */
  EthIf_EthTrcvSetPhyTestModeFctPtrType SetPhyTestModeOfEthTrcvDrvApi;  /**< EthTrcv_SetPhyTestMode() of the EthTrcv driver */
  EthIf_EthTrcvSetPhyTxModeFctPtrType SetPhyTxModeOfEthTrcvDrvApi;  /**< EthTrcv_SetPhyTxMode() of the EthTrcv driver */
  EthIf_EthTrcvSetTrcvModeFctPtrType SetTrcvModeOfEthTrcvDrvApi;  /**< EthTrcv_SetTransceiverMode() of the EthTrcv driver */
  EthIf_EthTrcvStartAutoNegFctPtrType StartAutoNegOfEthTrcvDrvApi;  /**< EthTrcv_StartAutoNegotiation() of the EthTrcv driver */
  EthIf_EthTrcvTrcvInitFctPtrType TrcvInitOfEthTrcvDrvApi;  /**< EthTrcv_TransceiverInit() of the EthTrcv driver */
} EthIf_EthTrcvDrvApiType;

/**   \brief  type used in EthIf_EthTxQueue */
typedef struct sEthIf_EthTxQueueType
{
  EthIf_EthCtrlIdxOfEthTxQueueType EthCtrlIdxOfEthTxQueue;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
  EthIf_QueueIndexOfEthTxQueueType QueueIndexOfEthTxQueue;  /**< Index of the Tx queue. */
} EthIf_EthTxQueueType;

/**   \brief  type used in EthIf_ExplicitBufReleaseFilter */
typedef struct sEthIf_ExplicitBufReleaseFilterType
{
  EthIf_EtherTypeConfiguredOfExplicitBufReleaseFilterType EtherTypeConfiguredOfExplicitBufReleaseFilter;  /**< Indicates whether a valid EtherType is configured in this filter entry. */
  EthIf_EthIfCtrlIdxOfExplicitBufReleaseFilterType EthIfCtrlIdxOfExplicitBufReleaseFilter;  /**< the index of the 1:1 relation pointing to EthIf_EthIfCtrl */
  EthIf_EtherTypeOfExplicitBufReleaseFilterType EtherTypeOfExplicitBufReleaseFilter;  /**< EtherType in EthIf EthType Filter (for EthIf ZeroCopy) that isn't automatically released by EthIf during RxIndication. */
} EthIf_ExplicitBufReleaseFilterType;

/**   \brief  type used in EthIf_FloatingRxPduMap */
typedef struct sEthIf_FloatingRxPduMapType
{
  EthIf_RxPduEndIdxOfFloatingRxPduMapType RxPduEndIdxOfFloatingRxPduMap;  /**< the end index of the 0:n relation pointing to EthIf_RxPdu */
  EthIf_RxPduLengthOfFloatingRxPduMapType RxPduLengthOfFloatingRxPduMap;  /**< the number of relations pointing to EthIf_RxPdu */
  EthIf_RxPduStartIdxOfFloatingRxPduMapType RxPduStartIdxOfFloatingRxPduMap;  /**< the start index of the 0:n relation pointing to EthIf_RxPdu */
} EthIf_FloatingRxPduMapType;

/**   \brief  type used in EthIf_GatewaySrcMacBlackList */
typedef struct sEthIf_GatewaySrcMacBlackListType
{
  Eth_PhysAddrType MacAddrOfGatewaySrcMacBlackList;  /**< Source MAC address */
} EthIf_GatewaySrcMacBlackListType;

/**   \brief  type used in EthIf_LegacyWakeupMap */
typedef struct sEthIf_LegacyWakeupMapType
{
  EthIf_EthTrcvIdxOfLegacyWakeupMapType EthTrcvIdxOfLegacyWakeupMap;  /**< the index of the 1:1 relation pointing to EthIf_EthTrcv */
  EcuM_WakeupSourceType WakeupSourceOfLegacyWakeupMap;  /**< EcuM wakeup source related to the EthTrcv */
} EthIf_LegacyWakeupMapType;

/**   \brief  type used in EthIf_MainPartitionRxEthCtrl */
typedef struct sEthIf_MainPartitionRxEthCtrlType
{
  EthIf_EthCtrlIdxOfMainPartitionRxEthCtrlType EthCtrlIdxOfMainPartitionRxEthCtrl;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
} EthIf_MainPartitionRxEthCtrlType;

/**   \brief  type used in EthIf_MainPartitionTxEthCtrl */
typedef struct sEthIf_MainPartitionTxEthCtrlType
{
  EthIf_EthCtrlIdxOfMainPartitionTxEthCtrlType EthCtrlIdxOfMainPartitionTxEthCtrl;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
} EthIf_MainPartitionTxEthCtrlType;

/**   \brief  type used in EthIf_MirrorDest */
typedef struct sEthIf_MirrorDestType
{
  EthIf_KeepSrcMacEnabledOfMirrorDestType KeepSrcMacEnabledOfMirrorDest;  /**< Shall source MAC address be forwarded unchanged */
  EthIf_EthCtrlIdxOfMirrorDestType EthCtrlIdxOfMirrorDest;  /**< the index of the 1:1 relation pointing to EthIf_EthCtrl */
} EthIf_MirrorDestType;

/**   \brief  type used in EthIf_MirrorTxInfo */
typedef struct sEthIf_MirrorTxInfoType
{
  EthIf_DestEthTxBufferIdxOfMirrorTxInfoType DestEthTxBufferIdxOfMirrorTxInfo;  /**< Tx buffer index occupied for mirror frame */
  EthIf_EthIfCtrlIdxOfMirrorTxInfoType EthIfCtrlIdxOfMirrorTxInfo;  /**< EthIf controller related to mirroring */
  EthIf_InfoValidOfMirrorTxInfoType InfoValidOfMirrorTxInfo;  /**< Flag indicating if Tx traffic information is valid */
  EthIf_SrcEthTxBufferIdxOfMirrorTxInfoType SrcEthTxBufferIdxOfMirrorTxInfo;  /**< Tx buffer index used for transmission of regular frame */
  EthIf_UsedOfMirrorTxInfoType UsedOfMirrorTxInfo;  /**< Flag indicating if Tx traffic information is alread in use */
  EthIf_FrameBufferPtrType DestPayloadPtrOfMirrorTxInfo;  /**< Pointer to the payload section (after EtherType) of mirror frame */
  EthIf_FrameBufferPtrType SrcPayloadPtrOfMirrorTxInfo;  /**< Pointer to the payload section (after EtherType) of frame to be mirrored */
} EthIf_MirrorTxInfoType;

/**   \brief  type used in EthIf_PhysLayerInitElems */
typedef struct sEthIf_PhysLayerInitElemsType
{
  EthIf_EthSwtIndEndIdxOfPhysLayerInitElemsType EthSwtIndEndIdxOfPhysLayerInitElems;  /**< the end index of the 0:n relation pointing to EthIf_EthSwtInd */
  EthIf_EthSwtIndStartIdxOfPhysLayerInitElemsType EthSwtIndStartIdxOfPhysLayerInitElems;  /**< the start index of the 0:n relation pointing to EthIf_EthSwtInd */
  EthIf_EthTrcvIdxOfPhysLayerInitElemsType EthTrcvIdxOfPhysLayerInitElems;  /**< the index of the 0:1 relation pointing to EthIf_EthTrcv */
} EthIf_PhysLayerInitElemsType;

/**   \brief  type used in EthIf_PhysLayerModeElems */
typedef struct sEthIf_PhysLayerModeElemsType
{
  EthIf_EthTrcvIdxOfPhysLayerModeElemsType EthTrcvIdxOfPhysLayerModeElems;  /**< the index of the 0:1 relation pointing to EthIf_EthTrcv */
  EthIf_PortGroupIdxOfPhysLayerModeElemsType PortGroupIdxOfPhysLayerModeElems;  /**< the index of the 0:1 relation pointing to EthIf_PortGroup */
} EthIf_PhysLayerModeElemsType;

/**   \brief  type used in EthIf_PortGroup */
typedef struct sEthIf_PortGroupType
{
  EthIf_SnvOfPortGroupType SnvOfPortGroup;  /**< SNV of the EthIf port group */
  EthIf_EthIfCtrlOfPortGroupIndEndIdxOfPortGroupType EthIfCtrlOfPortGroupIndEndIdxOfPortGroup;  /**< the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfPortGroupInd */
  EthIf_EthIfCtrlOfPortGroupIndStartIdxOfPortGroupType EthIfCtrlOfPortGroupIndStartIdxOfPortGroup;  /**< the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfPortGroupInd */
  EthIf_EthSwtPortIndEndIdxOfPortGroupType EthSwtPortIndEndIdxOfPortGroup;  /**< the end index of the 1:n relation pointing to EthIf_EthSwtPortInd */
  EthIf_EthSwtPortIndStartIdxOfPortGroupType EthSwtPortIndStartIdxOfPortGroup;  /**< the start index of the 1:n relation pointing to EthIf_EthSwtPortInd */
  EthIf_HostAndUpLinkPortThresholdOfPortGroupType HostAndUpLinkPortThresholdOfPortGroup;  /**< Threshold that indicates how many Host and Uplink ports need to be up to issue a link on the Port group */
  EthIf_NoRolePortThresholdOfPortGroupType NoRolePortThresholdOfPortGroup;  /**< Threshold that indicates how many No Role ports need to be up to issue a link on the Port group */
  EthIf_SemanticOfPortGroupType SemanticOfPortGroup;  /**< Semantic of the EthIf port group */
} EthIf_PortGroupType;

/**   \brief  type used in EthIf_RxPdu */
typedef struct sEthIf_RxPduType
{
  EthIf_FloatingPoolOfRxPduType FloatingPoolOfRxPdu;  /**< Indicates if the Rx PDU is part of a floating pool. */
  EthIf_KeepLocalBufferOfRxPduType KeepLocalBufferOfRxPdu;  /**< Indicates if the frame shall be explicitly released by the Upper layer. */
  EthIf_ValidEthMacAddrMetaDataOfRxPduType ValidEthMacAddrMetaDataOfRxPdu;  /**< Indicates if the MetaData Item ETHERNET_MAC_64 Offset is valid. */
  EthIf_ValidTimeTupleMetaDataOfRxPduType ValidTimeTupleMetaDataOfRxPdu;  /**< Indicates if the MetaData Item TIMETUPLE_TYPE_PTR Offset is valid. */
  EthIf_EthIfCtrlToRxPduMapIdxOfRxPduType EthIfCtrlToRxPduMapIdxOfRxPdu;  /**< the index of the 0:1 relation pointing to EthIf_EthIfCtrlToRxPduMap */
  EthIf_EthMacAddrOffsetOfRxPduType EthMacAddrOffsetOfRxPdu;  /**< MetaData Item ETHERNET_MAC_64 Offset */
  EthIf_FloatingRxPduMapIdxOfRxPduType FloatingRxPduMapIdxOfRxPdu;  /**< the index of the 0:1 relation pointing to EthIf_FloatingRxPduMap */
  EthIf_RxPduMetaDataEndIdxOfRxPduType RxPduMetaDataEndIdxOfRxPdu;  /**< the end index of the 0:n relation pointing to EthIf_RxPduMetaData */
  EthIf_RxPduMetaDataLengthOfRxPduType RxPduMetaDataLengthOfRxPdu;  /**< the number of relations pointing to EthIf_RxPduMetaData */
  EthIf_RxPduMetaDataStartIdxOfRxPduType RxPduMetaDataStartIdxOfRxPdu;  /**< the start index of the 0:n relation pointing to EthIf_RxPduMetaData */
  EthIf_TimeTuplePtrOffsetOfRxPduType TimeTuplePtrOffsetOfRxPdu;  /**< MetaData Item TIMETUPLE_TYPE_PTR Offset */
  EthIf_UlPduIdOfRxPduType UlPduIdOfRxPdu;  /**< Upper layer PDU ID. */
} EthIf_RxPduType;

/**   \brief  type used in EthIf_RxPduContext */
typedef struct sEthIf_RxPduContextType
{
  EthIf_RxHandleIdOfRxPduContextType RxHandleIdOfRxPduContext;  /**< Rx Handle Id (Provided by Eth driver) mapped to the Rx PDU. */
  EthIf_EthIfCtrlIdxOfRxPduContextType EthIfCtrlIdxOfRxPduContext;  /**< Index of the EthIf Controller on which the frame was received. */
  EthIf_StateOfRxPduContextType StateOfRxPduContext;  /**< Current usage status of the Rx PDU. */
  TimeTupleType TimeTupleOfRxPduContext;  /**< TimeTuple variable to store the ingress time tuple indicated by the EthDrv. */
} EthIf_RxPduContextType;

/**   \brief  type used in EthIf_RxPduFrameType */
typedef struct sEthIf_RxPduFrameTypeType
{
  EthIf_EthIfCtrlToRxPduMapEndIdxOfRxPduFrameTypeType EthIfCtrlToRxPduMapEndIdxOfRxPduFrameType;  /**< the end index of the 0:n relation pointing to EthIf_EthIfCtrlToRxPduMap */
  EthIf_EthIfCtrlToRxPduMapLengthOfRxPduFrameTypeType EthIfCtrlToRxPduMapLengthOfRxPduFrameType;  /**< the number of relations pointing to EthIf_EthIfCtrlToRxPduMap */
  EthIf_EthIfCtrlToRxPduMapStartIdxOfRxPduFrameTypeType EthIfCtrlToRxPduMapStartIdxOfRxPduFrameType;  /**< the start index of the 0:n relation pointing to EthIf_EthIfCtrlToRxPduMap */
  EthIf_EtherTypeOfRxPduFrameTypeType EtherTypeOfRxPduFrameType;  /**< Ethernet frame type. */
  EthIf_FloatingRxPduMapEndIdxOfRxPduFrameTypeType FloatingRxPduMapEndIdxOfRxPduFrameType;  /**< the end index of the 0:n relation pointing to EthIf_FloatingRxPduMap */
  EthIf_FloatingRxPduMapLengthOfRxPduFrameTypeType FloatingRxPduMapLengthOfRxPduFrameType;  /**< the number of relations pointing to EthIf_FloatingRxPduMap */
  EthIf_FloatingRxPduMapStartIdxOfRxPduFrameTypeType FloatingRxPduMapStartIdxOfRxPduFrameType;  /**< the start index of the 0:n relation pointing to EthIf_FloatingRxPduMap */
} EthIf_RxPduFrameTypeType;

/**   \brief  type used in EthIf_RxPduFreeList */
typedef struct sEthIf_RxPduFreeListType
{
  EthIf_PduIdOfRxPduFreeListType PduIdOfRxPduFreeList;  /**< Stack of free Rx PDU indices available for frame reception. */
} EthIf_RxPduFreeListType;

/**   \brief  type used in EthIf_RxQueueList */
typedef struct sEthIf_RxQueueListType
{
  EthIf_EthRxQueueEndIdxOfRxQueueListType EthRxQueueEndIdxOfRxQueueList;  /**< the end index of the 0:n relation pointing to EthIf_EthRxQueue */
  EthIf_EthRxQueueLengthOfRxQueueListType EthRxQueueLengthOfRxQueueList;  /**< the number of relations pointing to EthIf_EthRxQueue */
  EthIf_EthRxQueueStartIdxOfRxQueueListType EthRxQueueStartIdxOfRxQueueList;  /**< the start index of the 0:n relation pointing to EthIf_EthRxQueue */
} EthIf_RxQueueListType;

/**   \brief  type used in EthIf_SrcMacAddrBuffer */
typedef struct sEthIf_SrcMacAddrBufferType
{
  EthIf_ValidOfSrcMacAddrBufferType ValidOfSrcMacAddrBuffer;  /**< Flag defining if buffer holds a valid MAC address */
  Eth_PhysAddrType SrcMacOfSrcMacAddrBuffer;  /**< MAC address */
} EthIf_SrcMacAddrBufferType;

/**   \brief  type used in EthIf_TxContext */
typedef struct sEthIf_TxContextType
{
  EthIf_PayloadLenOfTxContextType PayloadLenOfTxContext;  /**< Length of the frames payload */
  EthIf_EthIfCtrlIdxOfTxContextType EthIfCtrlIdxOfTxContext;  /**< Index of the EthIf controller the frame shall be send on */
  EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContextType EthIfCtrlToEtherTypeMapIdxOfTxContext;  /**< Index of the EthIf controller to the Frame owner Map */
  EthIf_TxPendingOfTxContextType TxPendingOfTxContext;  /**< Flag indicating if transmission is pending */
  EthIf_ValidOfTxContextType ValidOfTxContext;  /**< Flag indicating if the context information is valid (buffer is in use) */
  EthIf_ValidPduIdOfTxContextType ValidPduIdOfTxContext;  /**< Flag indicating if the linked Pdu is valid. */
  EthIf_FrameHdrType FrameHdrOfTxContext;  /**< Ethernet frame header information */
  PduIdType LinkedPduIdOfTxContext;  /**< PduId attached to this TxContext. */
  EthIf_FrameBufferPtrType PayloadPtrOfTxContext;  /**< Pointer to the frames payload */
} EthIf_TxContextType;

/**   \brief  type used in EthIf_TxPdu */
typedef struct sEthIf_TxPduType
{
  EthIf_UlPduIdOfTxPduType UlPduIdOfTxPdu;  /**< SNV of upper layer PDU ID */
  EthIf_DirectDataProvisionOfTxPduType DirectDataProvisionOfTxPdu;  /**< Indicates if the Pdu is using direct data provision. */
  EthIf_EgressHardwareSupportedDataTransferOfTxPduType EgressHardwareSupportedDataTransferOfTxPdu;  /**< EgressHardwareSupportedDataTransfer is Enabled. */
  EthIf_KeepLocalBufferOfTxPduType KeepLocalBufferOfTxPdu;  /**< Indicates if the frame shall be explicitly released by the Upper layer. */
  EthIf_ValidEthMacAddrMetaDataOfTxPduType ValidEthMacAddrMetaDataOfTxPdu;  /**< Indicates if the MetaData Item ETHERNET_MAC_64 Offset is valid. */
  EthIf_ValidListItemMetaDataOfTxPduType ValidListItemMetaDataOfTxPdu;  /**< Indicates if the MetaData Item LISTELEM_PTR Offset is valid. */
  EthIf_ValidPriority8MetaDataOfTxPduType ValidPriority8MetaDataOfTxPdu;  /**< Indicates if the MetaData Item PRIORITY_8 Offset is valid. */
  EthIf_ValidTimeTupleMetaDataOfTxPduType ValidTimeTupleMetaDataOfTxPdu;  /**< Indicates if the MetaData Item TIMETUPLE_TYPE_PTR Offset is valid. */
  EthIf_ValidVlan16MetaDataOfTxPduType ValidVlan16MetaDataOfTxPdu;  /**< Indicates if the MetaData Item VLAN_16 Offset is valid. */
  EthIf_EthIfCtrlIdxOfTxPduType EthIfCtrlIdxOfTxPdu;  /**< the index of the 0:1 relation pointing to EthIf_EthIfCtrl */
  EthIf_EthMacAddrOffsetOfTxPduType EthMacAddrOffsetOfTxPdu;  /**< MetaData Item ETHERNET_MAC_64 Offset */
  EthIf_EtherTypeOfTxPduType EtherTypeOfTxPdu;  /**< EtherType of the frameOwner */
  EthIf_FrameTxPriorityOfTxPduType FrameTxPriorityOfTxPdu;  /**< VLAN priority of the PDU Tx pool. */
  EthIf_ListItemPtrOffsetOfTxPduType ListItemPtrOffsetOfTxPdu;  /**< MetaData Item LISTELEM_PTR Offset */
  EthIf_PriorityOffsetOfTxPduType PriorityOffsetOfTxPdu;  /**< MetaData Item PRIORITY_8 Offset */
  EthIf_TimeTuplePtrOffsetOfTxPduType TimeTuplePtrOffsetOfTxPdu;  /**< MetaData Item TIMETUPLE_TYPE_PTR Offset */
  EthIf_TotalMetaDataLengthOfTxPduType TotalMetaDataLengthOfTxPdu;  /**< Sum of the length of all the configured meta data elements. */
  EthIf_VLanOffsetOfTxPduType VLanOffsetOfTxPdu;  /**< MetaData Item VLAN_16 Offset */
} EthIf_TxPduType;

/**   \brief  type used in EthIf_TxPduContext */
typedef struct sEthIf_TxPduContextType
{
  EthIf_StateOfTxPduContextType StateOfTxPduContext;  /**< Tx Pdu State enumeration */
  EthIf_FrameHdrType FrameHdrOfTxPduContext;  /**< Ethernet frame header information */
  EthIfFrameHdrBufferType FrameHdrBufOfTxPduContext;  /**< Ethernet frame header buffer */
  ListElemStructType ListElementOfTxPduContext;  /**< ListElement attached to this PDU */
  EthIfTimeTuplePtrType TimeTuplePtrOfTxPduContext;  /**< TimeTuplePtr attached to this PDU */
} EthIf_TxPduContextType;

/**   \brief  type used in EthIf_TxQueueList */
typedef struct sEthIf_TxQueueListType
{
  EthIf_EthTxQueueEndIdxOfTxQueueListType EthTxQueueEndIdxOfTxQueueList;  /**< the end index of the 0:n relation pointing to EthIf_EthTxQueue */
  EthIf_EthTxQueueLengthOfTxQueueListType EthTxQueueLengthOfTxQueueList;  /**< the number of relations pointing to EthIf_EthTxQueue */
  EthIf_EthTxQueueStartIdxOfTxQueueListType EthTxQueueStartIdxOfTxQueueList;  /**< the start index of the 0:n relation pointing to EthIf_EthTxQueue */
} EthIf_TxQueueListType;

/**   \brief  type used in EthIf_WakeupMap */
typedef struct sEthIf_WakeupMapType
{
  EthIf_WakeupSrcDeviceEndIdxOfWakeupMapType WakeupSrcDeviceEndIdxOfWakeupMap;  /**< the end index of the 0:n relation pointing to EthIf_WakeupSrcDevice */
  EthIf_WakeupSrcDeviceLengthOfWakeupMapType WakeupSrcDeviceLengthOfWakeupMap;  /**< the number of relations pointing to EthIf_WakeupSrcDevice */
  EthIf_WakeupSrcDeviceStartIdxOfWakeupMapType WakeupSrcDeviceStartIdxOfWakeupMap;  /**< the start index of the 0:n relation pointing to EthIf_WakeupSrcDevice */
  EcuM_WakeupSourceType WakeupSourceMaskOfWakeupMap;  /**< EcuM wakeup source related to the wakeup source device */
} EthIf_WakeupMapType;

/**   \brief  type used in EthIf_WakeupSrcDevice */
typedef struct sEthIf_WakeupSrcDeviceType
{
  EthIf_EthSwtIdxOfWakeupSrcDeviceType EthSwtIdxOfWakeupSrcDevice;  /**< the index of the 0:1 relation pointing to EthIf_EthSwt */
  EthIf_EthTrcvIdxOfWakeupSrcDeviceType EthTrcvIdxOfWakeupSrcDevice;  /**< the index of the 0:1 relation pointing to EthIf_EthTrcv */
  EthIf_TypeOfWakeupSrcDeviceType TypeOfWakeupSrcDevice;  /**< Source device type which initiate the wake up event. */
} EthIf_WakeupSrcDeviceType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCSymbolicStructTypes  EthIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_01 */
typedef struct EthIf_TxContextRDR_01StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_02 */
typedef struct EthIf_TxContextRDR_02StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_03 */
typedef struct EthIf_TxContextRDR_03StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_04 */
typedef struct EthIf_TxContextRDR_04StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_05 */
typedef struct EthIf_TxContextRDR_05StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_06 */
typedef struct EthIf_TxContextRDR_06StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_07 */
typedef struct EthIf_TxContextRDR_07StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to EthIf_TxContext for debugging purposes in the predefined variant RDR_08 */
typedef struct EthIf_TxContextRDR_08StructSTag
{
  EthIf_TxContextType RDR_1_Eth_Controller_1_6addc1bb[12];
} EthIf_TxContextRDR_08StructSType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCUnionIndexAndSymbolTypes  EthIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access EthIf_TxContext in an index and symbol based style for debugging purposes */
typedef union EthIf_TxContextUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  EthIf_TxContextType raw[12];
  EthIf_TxContextRDR_01StructSType strRDR_01;
  EthIf_TxContextRDR_02StructSType strRDR_02;
  EthIf_TxContextRDR_03StructSType strRDR_03;
  EthIf_TxContextRDR_04StructSType strRDR_04;
  EthIf_TxContextRDR_05StructSType strRDR_05;
  EthIf_TxContextRDR_06StructSType strRDR_06;
  EthIf_TxContextRDR_07StructSType strRDR_07;
  EthIf_TxContextRDR_08StructSType strRDR_08;
} EthIf_TxContextUType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCRootPointerTypes  EthIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to EthIf_DedicatedRxPduNextFreePos */
typedef P2VAR(EthIf_DedicatedRxPduNextFreePosType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_DedicatedRxPduNextFreePosPtrType;

/**   \brief  type used to point to EthIf_EcucPartition */
typedef P2CONST(EthIf_EcucPartitionType, TYPEDEF, ETHIF_CONST) EthIf_EcucPartitionPtrType;

/**   \brief  type used to point to EthIf_EthCtrl */
typedef P2CONST(EthIf_EthCtrlType, TYPEDEF, ETHIF_CONST) EthIf_EthCtrlPtrType;

/**   \brief  type used to point to EthIf_EthCtrlInitCnt */
typedef P2VAR(EthIf_EthCtrlInitCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthCtrlInitCntPtrType;

/**   \brief  type used to point to EthIf_EthCtrlModeCnt */
typedef P2VAR(EthIf_EthCtrlModeCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthCtrlModeCntPtrType;

/**   \brief  type used to point to EthIf_EthCtrlState */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthCtrlStatePtrType;

/**   \brief  type used to point to EthIf_EthDrvApi */
typedef P2CONST(EthIf_EthDrvApiType, TYPEDEF, ETHIF_CONST) EthIf_EthDrvApiPtrType;

/**   \brief  type used to point to EthIf_EthIfClkUnit */
typedef P2CONST(EthIf_EthIfClkUnitType, TYPEDEF, ETHIF_CONST) EthIf_EthIfClkUnitPtrType;

/**   \brief  type used to point to EthIf_EthIfControllerModeChangeReqCnt */
typedef P2VAR(EthIf_EthIfControllerModeChangeReqCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfControllerModeChangeReqCntPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrl */
typedef P2CONST(EthIf_EthIfCtrlType, TYPEDEF, ETHIF_CONST) EthIf_EthIfCtrlPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlInitState */
typedef P2VAR(EthIf_EthIfCtrlInitStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlInitStatePtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlLinkCount */
typedef P2VAR(EthIf_EthIfCtrlLinkCountType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkCountPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlLinkState */
typedef P2VAR(EthIf_EthIfCtrlLinkStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkStatePtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlMode */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlModePtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlOfEthTrcvInd */
typedef P2CONST(EthIf_EthIfCtrlOfEthTrcvIndType, TYPEDEF, ETHIF_CONST) EthIf_EthIfCtrlOfEthTrcvIndPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlOfPortGroupInd */
typedef P2CONST(EthIf_EthIfCtrlOfPortGroupIndType, TYPEDEF, ETHIF_CONST) EthIf_EthIfCtrlOfPortGroupIndPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlRxStats */
typedef P2VAR(EthIf_EthIfCtrlRxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlRxStatsPtrType;

/**   \brief  type used to point to EthIf_NumRxBytesOfEthIfCtrlRxStats */
typedef P2VAR(EthIf_NumRxBytesOfEthIfCtrlRxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_NumRxBytesOfEthIfCtrlRxStatsPtrType;

/**   \brief  type used to point to EthIf_NumRxPktsOfEthIfCtrlRxStats */
typedef P2VAR(EthIf_NumRxPktsOfEthIfCtrlRxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_NumRxPktsOfEthIfCtrlRxStatsPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlToEtherTypeMap */
typedef P2CONST(EthIf_EthIfCtrlToEtherTypeMapType, TYPEDEF, ETHIF_CONST) EthIf_EthIfCtrlToEtherTypeMapPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlToRxPduMap */
typedef P2CONST(EthIf_EthIfCtrlToRxPduMapType, TYPEDEF, ETHIF_CONST) EthIf_EthIfCtrlToRxPduMapPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlTxStats */
typedef P2VAR(EthIf_EthIfCtrlTxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlTxStatsPtrType;

/**   \brief  type used to point to EthIf_NumTxBytesOfEthIfCtrlTxStats */
typedef P2VAR(EthIf_NumTxBytesOfEthIfCtrlTxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_NumTxBytesOfEthIfCtrlTxStatsPtrType;

/**   \brief  type used to point to EthIf_NumTxPktsOfEthIfCtrlTxStats */
typedef P2VAR(EthIf_NumTxPktsOfEthIfCtrlTxStatsType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_NumTxPktsOfEthIfCtrlTxStatsPtrType;

/**   \brief  type used to point to EthIf_EthIfMeasurementData */
typedef P2VAR(EthIf_EthIfMeasurementDataType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfMeasurementDataPtrType;

/**   \brief  type used to point to EthIf_DropCtrlIdxOfEthIfMeasurementData */
typedef P2VAR(EthIf_DropCtrlIdxOfEthIfMeasurementDataType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_DropCtrlIdxOfEthIfMeasurementDataPtrType;

/**   \brief  type used to point to EthIf_UnknownEtherTypeOfEthIfMeasurementData */
typedef P2VAR(EthIf_UnknownEtherTypeOfEthIfMeasurementDataType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_UnknownEtherTypeOfEthIfMeasurementDataPtrType;

/**   \brief  type used to point to EthIf_VlanDoubleTaggedOfEthIfMeasurementData */
typedef P2VAR(EthIf_VlanDoubleTaggedOfEthIfMeasurementDataType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_VlanDoubleTaggedOfEthIfMeasurementDataPtrType;

/**   \brief  type used to point to EthIf_EthIfPhysCtrlCfg */
typedef P2CONST(EthIf_EthIfPhysCtrlCfgType, TYPEDEF, ETHIF_CONST) EthIf_EthIfPhysCtrlCfgPtrType;

/**   \brief  type used to point to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter */
typedef P2VAR(EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterPtrType;

/**   \brief  type used to point to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState */
typedef P2VAR(EthIf_QualifiedUnexpectedLinkDownTimerStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerStatePtrType;

/**   \brief  type used to point to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter */
typedef P2VAR(EthIf_EthIfSwitchOffPortGroupTimerDelayCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortGroupTimerDelayCounterPtrType;

/**   \brief  type used to point to EthIf_EthIfSwitchOffPortGroupTimerDelayState */
typedef P2VAR(EthIf_SwitchOffPortGroupDelayStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortGroupTimerDelayStatePtrType;

/**   \brief  type used to point to EthIf_EthIfSwitchOffPortTimeDelayReqCnt */
typedef P2VAR(EthIf_EthIfSwitchOffPortTimeDelayReqCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortTimeDelayReqCntPtrType;

/**   \brief  type used to point to EthIf_EthIfSwitchOffPortTimerDelayState */
typedef P2VAR(EthIf_SwitchOffPortGroupDelayStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortTimerDelayStatePtrType;

/**   \brief  type used to point to EthIf_EthIfSwtPortGroupState */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfSwtPortGroupStatePtrType;

/**   \brief  type used to point to EthIf_EthRxQueue */
typedef P2CONST(EthIf_EthRxQueueType, TYPEDEF, ETHIF_CONST) EthIf_EthRxQueuePtrType;

/**   \brief  type used to point to EthIf_EthSwt */
typedef P2CONST(EthIf_EthSwtType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtPtrType;

/**   \brief  type used to point to EthIf_EthSwtDrv */
typedef P2CONST(EthIf_EthSwtDrvType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtDrvPtrType;

/**   \brief  type used to point to EthIf_EthSwtDrvApi */
typedef P2CONST(EthIf_EthSwtDrvApiType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtDrvApiPtrType;

/**   \brief  type used to point to EthIf_EthSwtInd */
typedef P2CONST(EthIf_EthSwtIndType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtIndPtrType;

/**   \brief  type used to point to EthIf_EthSwtInitCnt */
typedef P2VAR(EthIf_EthSwtInitCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthSwtInitCntPtrType;

/**   \brief  type used to point to EthIf_EthSwtPort */
typedef P2CONST(EthIf_EthSwtPortType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtPortPtrType;

/**   \brief  type used to point to EthIf_EthSwtPortInEthSwtContext */
typedef P2CONST(EthIf_EthSwtPortInEthSwtContextType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtPortInEthSwtContextPtrType;

/**   \brief  type used to point to EthIf_EthSwtPortInd */
typedef P2CONST(EthIf_EthSwtPortIndType, TYPEDEF, ETHIF_CONST) EthIf_EthSwtPortIndPtrType;

/**   \brief  type used to point to EthIf_EthSwtPortLinkState */
typedef P2VAR(EthIf_PhyElemLinkStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthSwtPortLinkStatePtrType;

/**   \brief  type used to point to EthIf_EthSwtPortModeCnt */
typedef P2VAR(EthIf_EthSwtPortModeCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthSwtPortModeCntPtrType;

/**   \brief  type used to point to EthIf_EthTrcv */
typedef P2CONST(EthIf_EthTrcvType, TYPEDEF, ETHIF_CONST) EthIf_EthTrcvPtrType;

/**   \brief  type used to point to EthIf_EthTrcvDrvApi */
typedef P2CONST(EthIf_EthTrcvDrvApiType, TYPEDEF, ETHIF_CONST) EthIf_EthTrcvDrvApiPtrType;

/**   \brief  type used to point to EthIf_EthTrcvInitCnt */
typedef P2VAR(EthIf_EthTrcvInitCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvInitCntPtrType;

/**   \brief  type used to point to EthIf_EthTrcvLinkState */
typedef P2VAR(EthIf_PhyElemLinkStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvLinkStatePtrType;

/**   \brief  type used to point to EthIf_EthTrcvMode */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModePtrType;

/**   \brief  type used to point to EthIf_EthTrcvModeChangeRetryCounter */
typedef P2VAR(EthIf_EthTrcvModeChangeRetryCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryCounterPtrType;

/**   \brief  type used to point to EthIf_EthTrcvModeChangeRetryPeriodCounter */
typedef P2VAR(EthIf_EthTrcvModeChangeRetryPeriodCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryPeriodCounterPtrType;

/**   \brief  type used to point to EthIf_EthTrcvModeCnt */
typedef P2VAR(EthIf_EthTrcvModeCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeCntPtrType;

/**   \brief  type used to point to EthIf_EthTrcvState */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthTrcvStatePtrType;

/**   \brief  type used to point to EthIf_EthTxQueue */
typedef P2CONST(EthIf_EthTxQueueType, TYPEDEF, ETHIF_CONST) EthIf_EthTxQueuePtrType;

/**   \brief  type used to point to EthIf_ExplicitBufReleaseFilter */
typedef P2CONST(EthIf_ExplicitBufReleaseFilterType, TYPEDEF, ETHIF_CONST) EthIf_ExplicitBufReleaseFilterPtrType;

/**   \brief  type used to point to EthIf_FloatingRxPduMap */
typedef P2CONST(EthIf_FloatingRxPduMapType, TYPEDEF, ETHIF_CONST) EthIf_FloatingRxPduMapPtrType;

/**   \brief  type used to point to EthIf_FloatingRxPduNextFreePos */
typedef P2VAR(EthIf_FloatingRxPduNextFreePosType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_FloatingRxPduNextFreePosPtrType;

/**   \brief  type used to point to EthIf_GatewaySrcMacBlackList */
typedef P2CONST(EthIf_GatewaySrcMacBlackListType, TYPEDEF, ETHIF_CONST) EthIf_GatewaySrcMacBlackListPtrType;

/**   \brief  type used to point to EthIf_GlobalStartupActiveTimerActive */
typedef P2VAR(EthIf_GlobalStartupActiveTimerActiveType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_GlobalStartupActiveTimerActivePtrType;

/**   \brief  type used to point to EthIf_InitLocked */
typedef P2VAR(EthIf_InitLockedType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_InitLockedPtrType;

/**   \brief  type used to point to EthIf_LegacyWakeupMap */
typedef P2CONST(EthIf_LegacyWakeupMapType, TYPEDEF, ETHIF_CONST) EthIf_LegacyWakeupMapPtrType;

/**   \brief  type used to point to EthIf_LinkStateChgIndications */
typedef P2CONST(EthIf_LinkStateChgIndFctPtrType, TYPEDEF, ETHIF_CONST) EthIf_LinkStateChgIndicationsPtrType;

/**   \brief  type used to point to EthIf_MainFuncStateDecoupleFreqCnt */
typedef P2VAR(EthIf_MainFuncStateDecoupleFreqCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_MainFuncStateDecoupleFreqCntPtrType;

/**   \brief  type used to point to EthIf_MainPartitionRxEthCtrl */
typedef P2CONST(EthIf_MainPartitionRxEthCtrlType, TYPEDEF, ETHIF_CONST) EthIf_MainPartitionRxEthCtrlPtrType;

/**   \brief  type used to point to EthIf_MainPartitionTxEthCtrl */
typedef P2CONST(EthIf_MainPartitionTxEthCtrlType, TYPEDEF, ETHIF_CONST) EthIf_MainPartitionTxEthCtrlPtrType;

/**   \brief  type used to point to EthIf_MirrorDest */
typedef P2CONST(EthIf_MirrorDestType, TYPEDEF, ETHIF_CONST) EthIf_MirrorDestPtrType;

/**   \brief  type used to point to EthIf_MirrorTxInfo */
typedef P2VAR(EthIf_MirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_MirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_DestEthTxBufferIdxOfMirrorTxInfo */
typedef P2VAR(EthIf_DestEthTxBufferIdxOfMirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_DestEthTxBufferIdxOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_DestPayloadPtrOfMirrorTxInfo */
typedef P2VAR(EthIf_FrameBufferPtrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_DestPayloadPtrOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlIdxOfMirrorTxInfo */
typedef P2VAR(EthIf_EthIfCtrlIdxOfMirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlIdxOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_InfoValidOfMirrorTxInfo */
typedef P2VAR(EthIf_InfoValidOfMirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_InfoValidOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_SrcEthTxBufferIdxOfMirrorTxInfo */
typedef P2VAR(EthIf_SrcEthTxBufferIdxOfMirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SrcEthTxBufferIdxOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_SrcPayloadPtrOfMirrorTxInfo */
typedef P2VAR(EthIf_FrameBufferPtrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SrcPayloadPtrOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_UsedOfMirrorTxInfo */
typedef P2VAR(EthIf_UsedOfMirrorTxInfoType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_UsedOfMirrorTxInfoPtrType;

/**   \brief  type used to point to EthIf_ModeChangeLocked */
typedef P2VAR(EthIf_ModeChangeLockedType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_ModeChangeLockedPtrType;

/**   \brief  type used to point to EthIf_PhysLayerInitElems */
typedef P2CONST(EthIf_PhysLayerInitElemsType, TYPEDEF, ETHIF_CONST) EthIf_PhysLayerInitElemsPtrType;

/**   \brief  type used to point to EthIf_PhysLayerModeElems */
typedef P2CONST(EthIf_PhysLayerModeElemsType, TYPEDEF, ETHIF_CONST) EthIf_PhysLayerModeElemsPtrType;

/**   \brief  type used to point to EthIf_PortGroup */
typedef P2CONST(EthIf_PortGroupType, TYPEDEF, ETHIF_CONST) EthIf_PortGroupPtrType;

/**   \brief  type used to point to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
typedef P2VAR(EthIf_PortGroupHostOrUpLinkPortRoleLinkCountType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortGroupHostOrUpLinkPortRoleLinkCountPtrType;

/**   \brief  type used to point to EthIf_PortGroupInd */
typedef P2CONST(EthIf_PortGroupIndType, TYPEDEF, ETHIF_CONST) EthIf_PortGroupIndPtrType;

/**   \brief  type used to point to EthIf_PortGroupLinkState */
typedef P2VAR(EthIf_PortGroupLinkStateType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortGroupLinkStatePtrType;

/**   \brief  type used to point to EthIf_PortGroupMode */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortGroupModePtrType;

/**   \brief  type used to point to EthIf_PortGroupNoRoleLinkCount */
typedef P2VAR(EthIf_PortGroupNoRoleLinkCountType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortGroupNoRoleLinkCountPtrType;

/**   \brief  type used to point to EthIf_PortGroupStartupActiveTimerActive */
typedef P2VAR(EthIf_PortGroupStartupActiveTimerActiveType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortGroupStartupActiveTimerActivePtrType;

/**   \brief  type used to point to EthIf_PortMode */
typedef P2VAR(Eth_ModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortModePtrType;

/**   \brief  type used to point to EthIf_PortSignalQualityResult */
typedef P2VAR(EthIf_SignalQualityResultType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortSignalQualityResultPtrType;

/**   \brief  type used to point to EthIf_PortStartupActiveTimeCounter */
typedef P2VAR(EthIf_PortStartupActiveTimeCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimeCounterPtrType;

/**   \brief  type used to point to EthIf_PortStartupActiveTimerActive */
typedef P2VAR(EthIf_PortStartupActiveTimerActiveType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimerActivePtrType;

/**   \brief  type used to point to EthIf_RequestedEthIfCtrlMode */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedEthIfCtrlModePtrType;

/**   \brief  type used to point to EthIf_RequestedEthTrcvMode */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvModePtrType;

/**   \brief  type used to point to EthIf_RequestedEthTrcvStateOfEthIfCtrl */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvStateOfEthIfCtrlPtrType;

/**   \brief  type used to point to EthIf_RequestedPortGroupMode */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedPortGroupModePtrType;

/**   \brief  type used to point to EthIf_RequestedPortGroupStateOfEthIfCtrl */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedPortGroupStateOfEthIfCtrlPtrType;

/**   \brief  type used to point to EthIf_RequestedPortMode */
typedef P2VAR(EthIf_RequestedModeType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RequestedPortModePtrType;

/**   \brief  type used to point to EthIf_RxIndications */
typedef P2CONST(EthIf_RxIndFctPtrType, TYPEDEF, ETHIF_CONST) EthIf_RxIndicationsPtrType;

/**   \brief  type used to point to EthIf_RxPdu */
typedef P2CONST(EthIf_RxPduType, TYPEDEF, ETHIF_CONST) EthIf_RxPduPtrType;

/**   \brief  type used to point to EthIf_RxPduContext */
typedef P2VAR(EthIf_RxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RxPduContextPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlIdxOfRxPduContext */
typedef P2VAR(EthIf_EthIfCtrlIdxOfRxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlIdxOfRxPduContextPtrType;

/**   \brief  type used to point to EthIf_RxHandleIdOfRxPduContext */
typedef P2VAR(EthIf_RxHandleIdOfRxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RxHandleIdOfRxPduContextPtrType;

/**   \brief  type used to point to EthIf_StateOfRxPduContext */
typedef P2VAR(EthIf_StateOfRxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_StateOfRxPduContextPtrType;

/**   \brief  type used to point to EthIf_TimeTupleOfRxPduContext */
typedef P2VAR(TimeTupleType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_TimeTupleOfRxPduContextPtrType;

/**   \brief  type used to point to EthIf_RxPduFrameType */
typedef P2CONST(EthIf_RxPduFrameTypeType, TYPEDEF, ETHIF_CONST) EthIf_RxPduFrameTypePtrType;

/**   \brief  type used to point to EthIf_RxPduFreeList */
typedef P2VAR(EthIf_RxPduFreeListType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RxPduFreeListPtrType;

/**   \brief  type used to point to EthIf_PduIdOfRxPduFreeList */
typedef P2VAR(EthIf_PduIdOfRxPduFreeListType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PduIdOfRxPduFreeListPtrType;

/**   \brief  type used to point to EthIf_RxPduMetaData */
typedef P2VAR(EthIf_RxPduMetaDataType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_RxPduMetaDataPtrType;

/**   \brief  type used to point to EthIf_RxQueueList */
typedef P2CONST(EthIf_RxQueueListType, TYPEDEF, ETHIF_CONST) EthIf_RxQueueListPtrType;

/**   \brief  type used to point to EthIf_SignalQualityDecoupleFreqCnt */
typedef P2VAR(EthIf_SignalQualityDecoupleFreqCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SignalQualityDecoupleFreqCntPtrType;

/**   \brief  type used to point to EthIf_SignalQualityResult */
typedef P2VAR(EthIf_SignalQualityResultType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SignalQualityResultPtrType;

/**   \brief  type used to point to EthIf_SrcMacAddrBuffer */
typedef P2VAR(EthIf_SrcMacAddrBufferType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SrcMacAddrBufferPtrType;

/**   \brief  type used to point to EthIf_SrcMacOfSrcMacAddrBuffer */
typedef P2VAR(Eth_PhysAddrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SrcMacOfSrcMacAddrBufferPtrType;

/**   \brief  type used to point to EthIf_ValidOfSrcMacAddrBuffer */
typedef P2VAR(EthIf_ValidOfSrcMacAddrBufferType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_ValidOfSrcMacAddrBufferPtrType;

/**   \brief  type used to point to EthIf_SwtPortGroupModeChangeReqCnt */
typedef P2VAR(EthIf_SwtPortGroupModeChangeReqCntType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SwtPortGroupModeChangeReqCntPtrType;

/**   \brief  type used to point to EthIf_SwtPortGroupModeChangeRetryCounter */
typedef P2VAR(EthIf_SwtPortGroupModeChangeRetryCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SwtPortGroupModeChangeRetryCounterPtrType;

/**   \brief  type used to point to EthIf_SwtPortGroupModeChangeRetryPeriodCounter */
typedef P2VAR(EthIf_SwtPortGroupModeChangeRetryPeriodCounterType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_SwtPortGroupModeChangeRetryPeriodCounterPtrType;

/**   \brief  type used to point to EthIf_TxConfirmations */
typedef P2CONST(EthIf_TxConfFctPtrType, TYPEDEF, ETHIF_CONST) EthIf_TxConfirmationsPtrType;

/**   \brief  type used to point to EthIf_TxContext */
typedef P2VAR(EthIf_TxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_TxContextPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlIdxOfTxContext */
typedef P2VAR(EthIf_EthIfCtrlIdxOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlIdxOfTxContextPtrType;

/**   \brief  type used to point to EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContext */
typedef P2VAR(EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlToEtherTypeMapIdxOfTxContextPtrType;

/**   \brief  type used to point to EthIf_FrameHdrOfTxContext */
typedef P2VAR(EthIf_FrameHdrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_FrameHdrOfTxContextPtrType;

/**   \brief  type used to point to EthIf_LinkedPduIdOfTxContext */
typedef P2VAR(PduIdType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_LinkedPduIdOfTxContextPtrType;

/**   \brief  type used to point to EthIf_PayloadLenOfTxContext */
typedef P2VAR(EthIf_PayloadLenOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PayloadLenOfTxContextPtrType;

/**   \brief  type used to point to EthIf_PayloadPtrOfTxContext */
typedef P2VAR(EthIf_FrameBufferPtrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_PayloadPtrOfTxContextPtrType;

/**   \brief  type used to point to EthIf_TxPendingOfTxContext */
typedef P2VAR(EthIf_TxPendingOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_TxPendingOfTxContextPtrType;

/**   \brief  type used to point to EthIf_ValidOfTxContext */
typedef P2VAR(EthIf_ValidOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_ValidOfTxContextPtrType;

/**   \brief  type used to point to EthIf_ValidPduIdOfTxContext */
typedef P2VAR(EthIf_ValidPduIdOfTxContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_ValidPduIdOfTxContextPtrType;

/**   \brief  type used to point to EthIf_TxPdu */
typedef P2CONST(EthIf_TxPduType, TYPEDEF, ETHIF_CONST) EthIf_TxPduPtrType;

/**   \brief  type used to point to EthIf_TxPduContext */
typedef P2VAR(EthIf_TxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_TxPduContextPtrType;

/**   \brief  type used to point to EthIf_FrameHdrBufOfTxPduContext */
typedef P2VAR(EthIfFrameHdrBufferType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_FrameHdrBufOfTxPduContextPtrType;

/**   \brief  type used to point to EthIf_FrameHdrOfTxPduContext */
typedef P2VAR(EthIf_FrameHdrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_FrameHdrOfTxPduContextPtrType;

/**   \brief  type used to point to EthIf_ListElementOfTxPduContext */
typedef P2VAR(ListElemStructType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_ListElementOfTxPduContextPtrType;

/**   \brief  type used to point to EthIf_StateOfTxPduContext */
typedef P2VAR(EthIf_StateOfTxPduContextType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_StateOfTxPduContextPtrType;

/**   \brief  type used to point to EthIf_TimeTuplePtrOfTxPduContext */
typedef P2VAR(EthIfTimeTuplePtrType, TYPEDEF, ETHIF_VAR_NO_INIT) EthIf_TimeTuplePtrOfTxPduContextPtrType;

/**   \brief  type used to point to EthIf_TxQueueList */
typedef P2CONST(EthIf_TxQueueListType, TYPEDEF, ETHIF_CONST) EthIf_TxQueueListPtrType;

/**   \brief  type used to point to EthIf_WakeupMap */
typedef P2CONST(EthIf_WakeupMapType, TYPEDEF, ETHIF_CONST) EthIf_WakeupMapPtrType;

/**   \brief  type used to point to EthIf_WakeupSrcDevice */
typedef P2CONST(EthIf_WakeupSrcDeviceType, TYPEDEF, ETHIF_CONST) EthIf_WakeupSrcDevicePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  EthIfPCRootValueTypes  EthIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in EthIf_PCConfig */
typedef struct sEthIf_PCConfigType
{
  EthIf_DedicatedRxPduNextFreePosPtrType DedicatedRxPduNextFreePosOfPCConfig;  /**< the pointer to EthIf_DedicatedRxPduNextFreePos */
  EthIf_EcucPartitionPtrType EcucPartitionOfPCConfig;  /**< the pointer to EthIf_EcucPartition */
  EthIf_EthCtrlPtrType EthCtrlOfPCConfig;  /**< the pointer to EthIf_EthCtrl */
  EthIf_EthCtrlInitCntPtrType EthCtrlInitCntOfPCConfig;  /**< the pointer to EthIf_EthCtrlInitCnt */
  EthIf_EthCtrlModeCntPtrType EthCtrlModeCntOfPCConfig;  /**< the pointer to EthIf_EthCtrlModeCnt */
  EthIf_EthCtrlStatePtrType EthCtrlStateOfPCConfig;  /**< the pointer to EthIf_EthCtrlState */
  EthIf_EthDrvApiPtrType EthDrvApiOfPCConfig;  /**< the pointer to EthIf_EthDrvApi */
  EthIf_EthIfClkUnitPtrType EthIfClkUnitOfPCConfig;  /**< the pointer to EthIf_EthIfClkUnit */
  EthIf_EthIfControllerModeChangeReqCntPtrType EthIfControllerModeChangeReqCntOfPCConfig;  /**< the pointer to EthIf_EthIfControllerModeChangeReqCnt */
  EthIf_EthIfCtrlPtrType EthIfCtrlOfPCConfig;  /**< the pointer to EthIf_EthIfCtrl */
  EthIf_EthIfCtrlInitStatePtrType EthIfCtrlInitStateOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlInitState */
  EthIf_EthIfCtrlLinkCountPtrType EthIfCtrlLinkCountOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlLinkCount */
  EthIf_EthIfCtrlLinkStatePtrType EthIfCtrlLinkStateOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlLinkState */
  EthIf_EthIfCtrlModePtrType EthIfCtrlModeOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlMode */
  EthIf_EthIfCtrlOfEthTrcvIndPtrType EthIfCtrlOfEthTrcvIndOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlOfEthTrcvInd */
  EthIf_EthIfCtrlOfPortGroupIndPtrType EthIfCtrlOfPortGroupIndOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlOfPortGroupInd */
  EthIf_EthIfCtrlRxStatsPtrType EthIfCtrlRxStatsOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlRxStats */
  EthIf_EthIfCtrlToEtherTypeMapPtrType EthIfCtrlToEtherTypeMapOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlToEtherTypeMap */
  EthIf_EthIfCtrlToRxPduMapPtrType EthIfCtrlToRxPduMapOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlToRxPduMap */
  EthIf_EthIfCtrlTxStatsPtrType EthIfCtrlTxStatsOfPCConfig;  /**< the pointer to EthIf_EthIfCtrlTxStats */
  EthIf_EthIfMeasurementDataPtrType EthIfMeasurementDataOfPCConfig;  /**< the pointer to EthIf_EthIfMeasurementData */
  EthIf_EthIfPhysCtrlCfgPtrType EthIfPhysCtrlCfgOfPCConfig;  /**< the pointer to EthIf_EthIfPhysCtrlCfg */
  EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterPtrType EthIfQualifiedUnexpectedLinkDownTimerCounterOfPCConfig;  /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter */
  EthIf_EthIfQualifiedUnexpectedLinkDownTimerStatePtrType EthIfQualifiedUnexpectedLinkDownTimerStateOfPCConfig;  /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState */
  EthIf_EthIfSwitchOffPortGroupTimerDelayCounterPtrType EthIfSwitchOffPortGroupTimerDelayCounterOfPCConfig;  /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter */
  EthIf_EthIfSwitchOffPortGroupTimerDelayStatePtrType EthIfSwitchOffPortGroupTimerDelayStateOfPCConfig;  /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayState */
  EthIf_EthIfSwitchOffPortTimeDelayReqCntPtrType EthIfSwitchOffPortTimeDelayReqCntOfPCConfig;  /**< the pointer to EthIf_EthIfSwitchOffPortTimeDelayReqCnt */
  EthIf_EthIfSwitchOffPortTimerDelayStatePtrType EthIfSwitchOffPortTimerDelayStateOfPCConfig;  /**< the pointer to EthIf_EthIfSwitchOffPortTimerDelayState */
  EthIf_EthIfSwtPortGroupStatePtrType EthIfSwtPortGroupStateOfPCConfig;  /**< the pointer to EthIf_EthIfSwtPortGroupState */
  EthIf_EthRxQueuePtrType EthRxQueueOfPCConfig;  /**< the pointer to EthIf_EthRxQueue */
  EthIf_EthSwtPtrType EthSwtOfPCConfig;  /**< the pointer to EthIf_EthSwt */
  EthIf_EthSwtDrvPtrType EthSwtDrvOfPCConfig;  /**< the pointer to EthIf_EthSwtDrv */
  EthIf_EthSwtDrvApiPtrType EthSwtDrvApiOfPCConfig;  /**< the pointer to EthIf_EthSwtDrvApi */
  EthIf_EthSwtIndPtrType EthSwtIndOfPCConfig;  /**< the pointer to EthIf_EthSwtInd */
  EthIf_EthSwtInitCntPtrType EthSwtInitCntOfPCConfig;  /**< the pointer to EthIf_EthSwtInitCnt */
  EthIf_EthSwtPortPtrType EthSwtPortOfPCConfig;  /**< the pointer to EthIf_EthSwtPort */
  EthIf_EthSwtPortInEthSwtContextPtrType EthSwtPortInEthSwtContextOfPCConfig;  /**< the pointer to EthIf_EthSwtPortInEthSwtContext */
  EthIf_EthSwtPortIndPtrType EthSwtPortIndOfPCConfig;  /**< the pointer to EthIf_EthSwtPortInd */
  EthIf_EthSwtPortLinkStatePtrType EthSwtPortLinkStateOfPCConfig;  /**< the pointer to EthIf_EthSwtPortLinkState */
  EthIf_EthSwtPortModeCntPtrType EthSwtPortModeCntOfPCConfig;  /**< the pointer to EthIf_EthSwtPortModeCnt */
  EthIf_EthTrcvPtrType EthTrcvOfPCConfig;  /**< the pointer to EthIf_EthTrcv */
  EthIf_EthTrcvDrvApiPtrType EthTrcvDrvApiOfPCConfig;  /**< the pointer to EthIf_EthTrcvDrvApi */
  EthIf_EthTrcvInitCntPtrType EthTrcvInitCntOfPCConfig;  /**< the pointer to EthIf_EthTrcvInitCnt */
  EthIf_EthTrcvLinkStatePtrType EthTrcvLinkStateOfPCConfig;  /**< the pointer to EthIf_EthTrcvLinkState */
  EthIf_EthTrcvModePtrType EthTrcvModeOfPCConfig;  /**< the pointer to EthIf_EthTrcvMode */
  EthIf_EthTrcvModeChangeRetryCounterPtrType EthTrcvModeChangeRetryCounterOfPCConfig;  /**< the pointer to EthIf_EthTrcvModeChangeRetryCounter */
  EthIf_EthTrcvModeChangeRetryPeriodCounterPtrType EthTrcvModeChangeRetryPeriodCounterOfPCConfig;  /**< the pointer to EthIf_EthTrcvModeChangeRetryPeriodCounter */
  EthIf_EthTrcvModeCntPtrType EthTrcvModeCntOfPCConfig;  /**< the pointer to EthIf_EthTrcvModeCnt */
  EthIf_EthTrcvStatePtrType EthTrcvStateOfPCConfig;  /**< the pointer to EthIf_EthTrcvState */
  EthIf_EthTxQueuePtrType EthTxQueueOfPCConfig;  /**< the pointer to EthIf_EthTxQueue */
  EthIf_ExplicitBufReleaseFilterPtrType ExplicitBufReleaseFilterOfPCConfig;  /**< the pointer to EthIf_ExplicitBufReleaseFilter */
  EthIf_FloatingRxPduMapPtrType FloatingRxPduMapOfPCConfig;  /**< the pointer to EthIf_FloatingRxPduMap */
  EthIf_FloatingRxPduNextFreePosPtrType FloatingRxPduNextFreePosOfPCConfig;  /**< the pointer to EthIf_FloatingRxPduNextFreePos */
  EthIf_GatewaySrcMacBlackListPtrType GatewaySrcMacBlackListOfPCConfig;  /**< the pointer to EthIf_GatewaySrcMacBlackList */
  EthIf_GlobalStartupActiveTimerActivePtrType GlobalStartupActiveTimerActiveOfPCConfig;  /**< the pointer to EthIf_GlobalStartupActiveTimerActive */
  EthIf_InitLockedPtrType InitLockedOfPCConfig;  /**< the pointer to EthIf_InitLocked */
  EthIf_LegacyWakeupMapPtrType LegacyWakeupMapOfPCConfig;  /**< the pointer to EthIf_LegacyWakeupMap */
  EthIf_LinkStateChgIndicationsPtrType LinkStateChgIndicationsOfPCConfig;  /**< the pointer to EthIf_LinkStateChgIndications */
  EthIf_MainFuncStateDecoupleFreqCntPtrType MainFuncStateDecoupleFreqCntOfPCConfig;  /**< the pointer to EthIf_MainFuncStateDecoupleFreqCnt */
  EthIf_MainPartitionRxEthCtrlPtrType MainPartitionRxEthCtrlOfPCConfig;  /**< the pointer to EthIf_MainPartitionRxEthCtrl */
  EthIf_MainPartitionTxEthCtrlPtrType MainPartitionTxEthCtrlOfPCConfig;  /**< the pointer to EthIf_MainPartitionTxEthCtrl */
  EthIf_MirrorDestPtrType MirrorDestOfPCConfig;  /**< the pointer to EthIf_MirrorDest */
  EthIf_MirrorTxInfoPtrType MirrorTxInfoOfPCConfig;  /**< the pointer to EthIf_MirrorTxInfo */
  EthIf_ModeChangeLockedPtrType ModeChangeLockedOfPCConfig;  /**< the pointer to EthIf_ModeChangeLocked */
  EthIf_PhysLayerInitElemsPtrType PhysLayerInitElemsOfPCConfig;  /**< the pointer to EthIf_PhysLayerInitElems */
  EthIf_PhysLayerModeElemsPtrType PhysLayerModeElemsOfPCConfig;  /**< the pointer to EthIf_PhysLayerModeElems */
  EthIf_PortGroupPtrType PortGroupOfPCConfig;  /**< the pointer to EthIf_PortGroup */
  EthIf_PortGroupHostOrUpLinkPortRoleLinkCountPtrType PortGroupHostOrUpLinkPortRoleLinkCountOfPCConfig;  /**< the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount */
  EthIf_PortGroupIndPtrType PortGroupIndOfPCConfig;  /**< the pointer to EthIf_PortGroupInd */
  EthIf_PortGroupLinkStatePtrType PortGroupLinkStateOfPCConfig;  /**< the pointer to EthIf_PortGroupLinkState */
  EthIf_PortGroupModePtrType PortGroupModeOfPCConfig;  /**< the pointer to EthIf_PortGroupMode */
  EthIf_PortGroupNoRoleLinkCountPtrType PortGroupNoRoleLinkCountOfPCConfig;  /**< the pointer to EthIf_PortGroupNoRoleLinkCount */
  EthIf_PortGroupStartupActiveTimerActivePtrType PortGroupStartupActiveTimerActiveOfPCConfig;  /**< the pointer to EthIf_PortGroupStartupActiveTimerActive */
  EthIf_PortModePtrType PortModeOfPCConfig;  /**< the pointer to EthIf_PortMode */
  EthIf_PortSignalQualityResultPtrType PortSignalQualityResultOfPCConfig;  /**< the pointer to EthIf_PortSignalQualityResult */
  EthIf_PortStartupActiveTimeCounterPtrType PortStartupActiveTimeCounterOfPCConfig;  /**< the pointer to EthIf_PortStartupActiveTimeCounter */
  EthIf_PortStartupActiveTimerActivePtrType PortStartupActiveTimerActiveOfPCConfig;  /**< the pointer to EthIf_PortStartupActiveTimerActive */
  EthIf_RequestedEthIfCtrlModePtrType RequestedEthIfCtrlModeOfPCConfig;  /**< the pointer to EthIf_RequestedEthIfCtrlMode */
  EthIf_RequestedEthTrcvModePtrType RequestedEthTrcvModeOfPCConfig;  /**< the pointer to EthIf_RequestedEthTrcvMode */
  EthIf_RequestedEthTrcvStateOfEthIfCtrlPtrType RequestedEthTrcvStateOfEthIfCtrlOfPCConfig;  /**< the pointer to EthIf_RequestedEthTrcvStateOfEthIfCtrl */
  EthIf_RequestedPortGroupModePtrType RequestedPortGroupModeOfPCConfig;  /**< the pointer to EthIf_RequestedPortGroupMode */
  EthIf_RequestedPortGroupStateOfEthIfCtrlPtrType RequestedPortGroupStateOfEthIfCtrlOfPCConfig;  /**< the pointer to EthIf_RequestedPortGroupStateOfEthIfCtrl */
  EthIf_RequestedPortModePtrType RequestedPortModeOfPCConfig;  /**< the pointer to EthIf_RequestedPortMode */
  EthIf_RxIndicationsPtrType RxIndicationsOfPCConfig;  /**< the pointer to EthIf_RxIndications */
  EthIf_RxPduPtrType RxPduOfPCConfig;  /**< the pointer to EthIf_RxPdu */
  EthIf_RxPduContextPtrType RxPduContextOfPCConfig;  /**< the pointer to EthIf_RxPduContext */
  EthIf_RxPduFrameTypePtrType RxPduFrameTypeOfPCConfig;  /**< the pointer to EthIf_RxPduFrameType */
  EthIf_RxPduFreeListPtrType RxPduFreeListOfPCConfig;  /**< the pointer to EthIf_RxPduFreeList */
  EthIf_RxPduMetaDataPtrType RxPduMetaDataOfPCConfig;  /**< the pointer to EthIf_RxPduMetaData */
  EthIf_RxQueueListPtrType RxQueueListOfPCConfig;  /**< the pointer to EthIf_RxQueueList */
  EthIf_SignalQualityDecoupleFreqCntPtrType SignalQualityDecoupleFreqCntOfPCConfig;  /**< the pointer to EthIf_SignalQualityDecoupleFreqCnt */
  EthIf_SignalQualityResultPtrType SignalQualityResultOfPCConfig;  /**< the pointer to EthIf_SignalQualityResult */
  EthIf_SrcMacAddrBufferPtrType SrcMacAddrBufferOfPCConfig;  /**< the pointer to EthIf_SrcMacAddrBuffer */
  EthIf_SwtPortGroupModeChangeReqCntPtrType SwtPortGroupModeChangeReqCntOfPCConfig;  /**< the pointer to EthIf_SwtPortGroupModeChangeReqCnt */
  EthIf_SwtPortGroupModeChangeRetryCounterPtrType SwtPortGroupModeChangeRetryCounterOfPCConfig;  /**< the pointer to EthIf_SwtPortGroupModeChangeRetryCounter */
  EthIf_SwtPortGroupModeChangeRetryPeriodCounterPtrType SwtPortGroupModeChangeRetryPeriodCounterOfPCConfig;  /**< the pointer to EthIf_SwtPortGroupModeChangeRetryPeriodCounter */
  EthIf_TxConfirmationsPtrType TxConfirmationsOfPCConfig;  /**< the pointer to EthIf_TxConfirmations */
  EthIf_TxContextPtrType TxContextOfPCConfig;  /**< the pointer to EthIf_TxContext */
  EthIf_TxPduPtrType TxPduOfPCConfig;  /**< the pointer to EthIf_TxPdu */
  EthIf_TxPduContextPtrType TxPduContextOfPCConfig;  /**< the pointer to EthIf_TxPduContext */
  EthIf_TxQueueListPtrType TxQueueListOfPCConfig;  /**< the pointer to EthIf_TxQueueList */
  EthIf_WakeupMapPtrType WakeupMapOfPCConfig;  /**< the pointer to EthIf_WakeupMap */
  EthIf_WakeupSrcDevicePtrType WakeupSrcDeviceOfPCConfig;  /**< the pointer to EthIf_WakeupSrcDevice */
  EthIf_SetControllerModeTimeoutType SetControllerModeTimeoutOfPCConfig;  /**< Maximum number of clock cycles to wait for the Eth driver to set its controller mode to ACTIVE */
  EthIf_EthIfSwitchOffPortTimeDelayCountsType EthIfSwitchOffPortTimeDelayCountsOfPCConfig;  /**< EthIfSwitchOffPortTimeDelay timer in terms of main function periodicity */
  EthIf_GlobalModeChangeMaxRetryCountType GlobalModeChangeMaxRetryCountOfPCConfig;  /**< EthIf mode request retry max counter */
  EthIf_GlobalModeChangeRetryPeriodCountType GlobalModeChangeRetryPeriodCountOfPCConfig;  /**< EthIf Mode request retry period in terms of main function periodicity */
  EthIf_LinkStateChgMainReloadType LinkStateChgMainReloadOfPCConfig;  /**< Amount of calls link state observation isn't triggerd if observation is done within EthIf_MainFunctionTx() instead of using an explicit EthIf_MainFunctionState(). */
  EthIf_MaxRxFramePerEthCtrlType MaxRxFramePerEthCtrlOfPCConfig;  /**< Maximum number of frames that can be received during a single invocation of EthIf_MainFunctionRx() in polling mode on one Ethernet controller (or per queue if EthBswSplit with polling is configured). */
  EthIf_MaxTxBufPerEthCtrlType MaxTxBufPerEthCtrlOfPCConfig;  /**< Maximum amount of Tx buffers configured for an Ethernet controller */
  EthIf_PortStartupActiveTimeFreqType PortStartupActiveTimeFreqOfPCConfig;  /**< Port startup activation timer in terms of main function periodicity */
  EthIf_SignalQualityChgMainReloadType SignalQualityChgMainReloadOfPCConfig;  /**< Amount of calls signal quality observation in EthIf_MainFunctionState(). */
  EthIf_SizeOfEcucPartitionType SizeOfEcucPartitionOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EcucPartition */
  EthIf_SizeOfEthCtrlType SizeOfEthCtrlOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthCtrl */
  EthIf_SizeOfEthDrvApiType SizeOfEthDrvApiOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthDrvApi */
  EthIf_SizeOfEthIfClkUnitType SizeOfEthIfClkUnitOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfClkUnit */
  EthIf_SizeOfEthIfCtrlType SizeOfEthIfCtrlOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfCtrl */
  EthIf_SizeOfEthIfCtrlOfEthTrcvIndType SizeOfEthIfCtrlOfEthTrcvIndOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfCtrlOfEthTrcvInd */
  EthIf_SizeOfEthIfCtrlOfPortGroupIndType SizeOfEthIfCtrlOfPortGroupIndOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfCtrlOfPortGroupInd */
  EthIf_SizeOfEthIfCtrlToEtherTypeMapType SizeOfEthIfCtrlToEtherTypeMapOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfCtrlToEtherTypeMap */
  EthIf_SizeOfEthIfCtrlToRxPduMapType SizeOfEthIfCtrlToRxPduMapOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfCtrlToRxPduMap */
  EthIf_SizeOfEthIfMeasurementDataType SizeOfEthIfMeasurementDataOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfMeasurementData */
  EthIf_SizeOfEthIfPhysCtrlCfgType SizeOfEthIfPhysCtrlCfgOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthIfPhysCtrlCfg */
  EthIf_SizeOfEthRxQueueType SizeOfEthRxQueueOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthRxQueue */
  EthIf_SizeOfEthSwtType SizeOfEthSwtOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwt */
  EthIf_SizeOfEthSwtDrvType SizeOfEthSwtDrvOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtDrv */
  EthIf_SizeOfEthSwtDrvApiType SizeOfEthSwtDrvApiOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtDrvApi */
  EthIf_SizeOfEthSwtIndType SizeOfEthSwtIndOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtInd */
  EthIf_SizeOfEthSwtPortType SizeOfEthSwtPortOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtPort */
  EthIf_SizeOfEthSwtPortInEthSwtContextType SizeOfEthSwtPortInEthSwtContextOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtPortInEthSwtContext */
  EthIf_SizeOfEthSwtPortIndType SizeOfEthSwtPortIndOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthSwtPortInd */
  EthIf_SizeOfEthTrcvType SizeOfEthTrcvOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthTrcv */
  EthIf_SizeOfEthTrcvDrvApiType SizeOfEthTrcvDrvApiOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthTrcvDrvApi */
  EthIf_SizeOfEthTxQueueType SizeOfEthTxQueueOfPCConfig;  /**< the number of accomplishable value elements in EthIf_EthTxQueue */
  EthIf_SizeOfExplicitBufReleaseFilterType SizeOfExplicitBufReleaseFilterOfPCConfig;  /**< the number of accomplishable value elements in EthIf_ExplicitBufReleaseFilter */
  EthIf_SizeOfFloatingRxPduMapType SizeOfFloatingRxPduMapOfPCConfig;  /**< the number of accomplishable value elements in EthIf_FloatingRxPduMap */
  EthIf_SizeOfGatewaySrcMacBlackListType SizeOfGatewaySrcMacBlackListOfPCConfig;  /**< the number of accomplishable value elements in EthIf_GatewaySrcMacBlackList */
  EthIf_SizeOfLegacyWakeupMapType SizeOfLegacyWakeupMapOfPCConfig;  /**< the number of accomplishable value elements in EthIf_LegacyWakeupMap */
  EthIf_SizeOfLinkStateChgIndicationsType SizeOfLinkStateChgIndicationsOfPCConfig;  /**< the number of accomplishable value elements in EthIf_LinkStateChgIndications */
  EthIf_SizeOfMainPartitionRxEthCtrlType SizeOfMainPartitionRxEthCtrlOfPCConfig;  /**< the number of accomplishable value elements in EthIf_MainPartitionRxEthCtrl */
  EthIf_SizeOfMainPartitionTxEthCtrlType SizeOfMainPartitionTxEthCtrlOfPCConfig;  /**< the number of accomplishable value elements in EthIf_MainPartitionTxEthCtrl */
  EthIf_SizeOfMirrorDestType SizeOfMirrorDestOfPCConfig;  /**< the number of accomplishable value elements in EthIf_MirrorDest */
  EthIf_SizeOfMirrorTxInfoType SizeOfMirrorTxInfoOfPCConfig;  /**< the number of accomplishable value elements in EthIf_MirrorTxInfo */
  EthIf_SizeOfPhysLayerInitElemsType SizeOfPhysLayerInitElemsOfPCConfig;  /**< the number of accomplishable value elements in EthIf_PhysLayerInitElems */
  EthIf_SizeOfPhysLayerModeElemsType SizeOfPhysLayerModeElemsOfPCConfig;  /**< the number of accomplishable value elements in EthIf_PhysLayerModeElems */
  EthIf_SizeOfPortGroupType SizeOfPortGroupOfPCConfig;  /**< the number of accomplishable value elements in EthIf_PortGroup */
  EthIf_SizeOfPortGroupIndType SizeOfPortGroupIndOfPCConfig;  /**< the number of accomplishable value elements in EthIf_PortGroupInd */
  EthIf_SizeOfPortModeType SizeOfPortModeOfPCConfig;  /**< the number of accomplishable value elements in EthIf_PortMode */
  EthIf_SizeOfRequestedPortModeType SizeOfRequestedPortModeOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RequestedPortMode */
  EthIf_SizeOfRxIndicationsType SizeOfRxIndicationsOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RxIndications */
  EthIf_SizeOfRxPduType SizeOfRxPduOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RxPdu */
  EthIf_SizeOfRxPduFrameTypeType SizeOfRxPduFrameTypeOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RxPduFrameType */
  EthIf_SizeOfRxPduMetaDataType SizeOfRxPduMetaDataOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RxPduMetaData */
  EthIf_SizeOfRxQueueListType SizeOfRxQueueListOfPCConfig;  /**< the number of accomplishable value elements in EthIf_RxQueueList */
  EthIf_SizeOfTxConfirmationsType SizeOfTxConfirmationsOfPCConfig;  /**< the number of accomplishable value elements in EthIf_TxConfirmations */
  EthIf_SizeOfTxContextType SizeOfTxContextOfPCConfig;  /**< the number of accomplishable value elements in EthIf_TxContext */
  EthIf_SizeOfTxPduType SizeOfTxPduOfPCConfig;  /**< the number of accomplishable value elements in EthIf_TxPdu */
  EthIf_SizeOfTxQueueListType SizeOfTxQueueListOfPCConfig;  /**< the number of accomplishable value elements in EthIf_TxQueueList */
  EthIf_SizeOfWakeupMapType SizeOfWakeupMapOfPCConfig;  /**< the number of accomplishable value elements in EthIf_WakeupMap */
  EthIf_SizeOfWakeupSrcDeviceType SizeOfWakeupSrcDeviceOfPCConfig;  /**< the number of accomplishable value elements in EthIf_WakeupSrcDevice */
} EthIf_PCConfigType;  /* PRQA S 0639 */  /* MD_MSR_Dir1.1 */

typedef EthIf_PCConfigType EthIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access EthIf_PCConfig in a symbol based style. */
typedef struct sEthIf_PCConfigsType
{
  EthIf_PCConfigType Config_RDR_03;  /**< [Config_RDR_03] */
  EthIf_PCConfigType Config_RDR_02;  /**< [Config_RDR_02, Config_RDR_04, Config_RDR_05, Config_RDR_06, Config_RDR_07, Config_RDR_08] */
  EthIf_PCConfigType Config_RDR_01;  /**< [Config_RDR_01] */
} EthIf_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthIf_EcucPartition
**********************************************************************************************************************/
/** 
  \var    EthIf_EcucPartition
  \brief  Instances of the ECU partitions.
  \details
  Element         Description
  QualityLevel    EcuC partition quality level
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EcucPartitionType, ETHIF_CONST) EthIf_EcucPartition[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrl
  \brief  Eth controllers abstracted by the EthIf
  \details
  Element                          Description
  Snv                              SNV of the Eth controller
  BufIdxOffsetEnabled              Indicates if the buffer index offset as per AR24-11 is enabled.
  EthArReleaseRxBufferSupported    Indicates if the Ethernet Controller supports the Eth_Drv_ReleaseRxBuffer API as per AR23-11.
  ImplicitBufferReleaseNeeded      Indicates if frames shall be implicitly released by the EthIf.
  EthDrvApiIdx                     the index of the 1:1 relation pointing to EthIf_EthDrvApi
  NumOfTxBuffers                   Total number of Tx buffers configured in this controller.
  TxContextEndIdx                  the end index of the 1:n relation pointing to EthIf_TxContext
  TxContextLength                  the number of relations pointing to EthIf_TxContext
  TxContextStartIdx                the start index of the 1:n relation pointing to EthIf_TxContext
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthCtrlType, ETHIF_CONST) EthIf_EthCtrl[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthDrvApi
**********************************************************************************************************************/
/** 
  \var    EthIf_EthDrvApi
  \brief  APIs of the Ethernet drivers abstracted by EthIf
  \details
  Element                  Description
  CtrlInit                 Eth_ControllerInit() of Eth driver
  EnableEgressTimeStamp    Eth_EnableEgressTimeStamp() of Eth driver.
  GetBandwidthLimit        Eth_GetBandwidthLimit() of Eth driver.
  GetCtrlMode              Eth_GetControllerMode() of Eth driver
  GetCurrentTime           Eth_GetCurrentTime() of Eth driver.
  GetEgressTimeStamp       Eth_GetEgressTimeStamp() of Eth driver.
  GetIngressTimeStamp      Eth_GetIngressTimeStamp() of Eth driver.
  GetPhysAddr              Eth_GetPhysAddr() of Eth driver
  GetRxHeaderPtr           Eth_GetRxHeaderPtr() of Eth driver.
  GetRxStats               Eth_GetRxStats() of Eth driver
  GetSpiStatus             Eth_GetSpiStatus() of Eth driver
  GetTxHeaderPtr           Eth_GetTxHeaderPtr() of Eth driver.
  GetTxStats               Eth_GetTxStats() of Eth driver
  ImmediateTransmit        Eth_ImmediateTransmit() of Eth driver
  ProvideExtTxBuffer       Eth_ProvideExtTxBuffer() of Eth driver.
  ProvideTxBuffer          Eth_ProvideTxBuffer() of Eth driver
  Receive                  Eth_Receive() of Eth driver
  ReceiveQueue             Eth_ReceiveQueue() of Eth driver (Fifo/Queue specific reception)
  ReleaseRxBuffer          Eth_ReleaseRxBuffer() of Eth driver as per AR23-11.
  SetBandwidthLimit        Eth_SetBandwidthLimit() of Eth driver.
  SetCtrlMode              Eth_SetControllerMode() of Eth driver
  SetPhysAddr              Eth_SetPhysAddr() of Eth driver
  Transmit                 Eth_Transmit() of Eth driver
  TxConfirmation           Eth_TxConfirmation() of Eth driver
  TxConfirmationQueue      Eth_TxConfirmationQueue() of Eth driver (Fifo/Queue specific reception)
  UpdatePhysAddrFilter     Eth_UpdatePhysAddrFilter() of Eth driver
  VGetEgressTimeStamp      Eth_VGetEgressTimeStamp() of Eth driver.
  VReleaseRxBuffer         Eth_ReleaseRxBuffer() of Eth driver as per vector extension.
  VTransmit                Eth_VTransmit() of Eth driver
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthDrvApiType, ETHIF_CONST) EthIf_EthDrvApi[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrl
  \brief  EthIf controllers
  \details
  Element                            Description
  Snv                                SNV of the EthIf Controller
  Mtu                                Maximum transfer unit of the EthIf Controller
  VlanId                             VLAN ID associated with the EthIf Controller
  EcucPartitionIdx                   the index of the 0:1 relation pointing to EthIf_EcucPartition
  EthCtrlIdx                         the index of the 1:1 relation pointing to EthIf_EthCtrl
  EthIfCtrlToEtherTypeMapEndIdx      the end index of the 1:n relation pointing to EthIf_EthIfCtrlToEtherTypeMap
  EthIfCtrlToEtherTypeMapLength      the number of relations pointing to EthIf_EthIfCtrlToEtherTypeMap
  EthIfCtrlToEtherTypeMapStartIdx    the start index of the 1:n relation pointing to EthIf_EthIfCtrlToEtherTypeMap
  EthIfPhysCtrlCfgIdx                the index of the 1:1 relation pointing to EthIf_EthIfPhysCtrlCfg
  EthSwtDrvApiIdx                    the index of the 0:1 relation pointing to EthIf_EthSwtDrvApi
  GatewayDestEthIfCtrlIdx            the enum value of the according target of the 0:1 relation pointing to EthIf_EthIfCtrl
  GatewayDestEthIfCtrlIdxIdx         the index of the 0:1 relation pointing to EthIf_EthIfCtrl
  LinkAggrThreshold                  Threshold when a link is issued on EthIf controller level.
  MacSecType                         MACsec Type of the EthIf Controller
  MirrorRxDestIdx                    the enum value of the according target of the 0:1 relation pointing to EthIf_MirrorDest
  MirrorRxDestIdxIdx                 the index of the 0:1 relation pointing to EthIf_MirrorDest
  MirrorTxDestIdx                    the enum value of the according target of the 0:1 relation pointing to EthIf_MirrorDest
  MirrorTxDestIdxIdx                 the index of the 0:1 relation pointing to EthIf_MirrorDest
  PhysLayerInitElemsIdx              the index of the 1:1 relation pointing to EthIf_PhysLayerInitElems
  PhysLayerModeElemsIdx              the index of the 1:1 relation pointing to EthIf_PhysLayerModeElems
  Type                               Type of the EthIf Controller
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthIfCtrlType, ETHIF_CONST) EthIf_EthIfCtrl[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlOfEthTrcvInd
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlOfEthTrcvInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthIf_EthIfCtrl
*/ 
#define ETHIF_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthIfCtrlOfEthTrcvIndType, ETHIF_CONST) EthIf_EthIfCtrlOfEthTrcvInd[1];
#define ETHIF_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlToEtherTypeMap
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlToEtherTypeMap
  \brief  Mapping between EthIf controller and the EtherType (Frame Owner/User).
  \details
  Element                    Description
  EtherType                  EtherType linked to an EthIf controller users RxIndication/TxConfirmation.
  RxIndicationsEndIdx        the end index of the 0:n relation pointing to EthIf_RxIndications
  RxIndicationsLength        the number of relations pointing to EthIf_RxIndications
  RxIndicationsStartIdx      the start index of the 0:n relation pointing to EthIf_RxIndications
  TxConfirmationsEndIdx      the end index of the 0:n relation pointing to EthIf_TxConfirmations
  TxConfirmationsLength      the number of relations pointing to EthIf_TxConfirmations
  TxConfirmationsStartIdx    the start index of the 0:n relation pointing to EthIf_TxConfirmations
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthIfCtrlToEtherTypeMapType, ETHIF_CONST) EthIf_EthIfCtrlToEtherTypeMap[3];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfPhysCtrlCfg
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfPhysCtrlCfg
  \brief  Configuration of EthIfPhysController abstracted by EthIf
  \details
  Element                   Description
  EthCtrlIdx                SNV of the Eth controller
  EthIfPhysControllerIdx    Zero-based consecutive index of the physical Ethernet Controllers in EthIf context.
  EthPhcSupportAvailable    Indicates if the PhcSupport APIs (AR&gt;=23-11) are supported by the controller.
  EthDrvApiIdx              the index of the 1:1 relation pointing to EthIf_EthDrvApi
  EthIfClkUnitEndIdx        the end index of the 0:n relation pointing to EthIf_EthIfClkUnit
  EthIfClkUnitLength        the number of relations pointing to EthIf_EthIfClkUnit
  EthIfClkUnitStartIdx      the start index of the 0:n relation pointing to EthIf_EthIfClkUnit
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthIfPhysCtrlCfgType, ETHIF_CONST) EthIf_EthIfPhysCtrlCfg[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvRDR_01
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvRDR_01
  \brief  Eth transceivers abstracted by EthIf
  \details
  Element                                       Description
  Snv                                           SNV of the EthTrcv
  AsyncProcessing                               Indicates if the mode change in the transceiver is performed asynchronously
  EthTrcvActAsSlavePassiveEnabled               Indicates if Passive slave enabled for Eth Trcv
  MacSecSecured                                 Indicates if transceiver is MACsec secured
  EthIfCtrlOfEthTrcvIndEndIdx                   the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfEthTrcvIndStartIdx                 the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfQualifiedUnexpectedLinkDownTimeCounts    Specifies the time in main function periodicity if an unexpected link down is qualified.
  EthTrcvDrvApiIdx                              the index of the 1:1 relation pointing to EthIf_EthTrcvDrvApi
  EthTrcvType                                   Indicates if the transceiver is standalone or connected to a switch port.
  MkaPaeIdx                                     PaeIdx of transceiver
  PortModeIdx                                   the index of the 0:1 relation pointing to EthIf_PortMode
  RequestedPortModeIdx                          the index of the 0:1 relation pointing to EthIf_RequestedPortMode
  UserSleepIndication                           User sleep indication of the EthIf Trcv.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_01[3];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvRDR_02
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvRDR_02
  \brief  Eth transceivers abstracted by EthIf
  \details
  Element                                       Description
  Snv                                           SNV of the EthTrcv
  AsyncProcessing                               Indicates if the mode change in the transceiver is performed asynchronously
  EthTrcvActAsSlavePassiveEnabled               Indicates if Passive slave enabled for Eth Trcv
  MacSecSecured                                 Indicates if transceiver is MACsec secured
  EthIfCtrlOfEthTrcvIndEndIdx                   the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfEthTrcvIndStartIdx                 the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfQualifiedUnexpectedLinkDownTimeCounts    Specifies the time in main function periodicity if an unexpected link down is qualified.
  EthTrcvDrvApiIdx                              the index of the 1:1 relation pointing to EthIf_EthTrcvDrvApi
  EthTrcvType                                   Indicates if the transceiver is standalone or connected to a switch port.
  MkaPaeIdx                                     PaeIdx of transceiver
  PortModeIdx                                   the index of the 0:1 relation pointing to EthIf_PortMode
  RequestedPortModeIdx                          the index of the 0:1 relation pointing to EthIf_RequestedPortMode
  UserSleepIndication                           User sleep indication of the EthIf Trcv.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_02[3];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvRDR_03
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvRDR_03
  \brief  Eth transceivers abstracted by EthIf
  \details
  Element                                       Description
  Snv                                           SNV of the EthTrcv
  AsyncProcessing                               Indicates if the mode change in the transceiver is performed asynchronously
  EthTrcvActAsSlavePassiveEnabled               Indicates if Passive slave enabled for Eth Trcv
  MacSecSecured                                 Indicates if transceiver is MACsec secured
  EthIfCtrlOfEthTrcvIndEndIdx                   the end index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfEthTrcvIndStartIdx                 the start index of the 0:n relation pointing to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfQualifiedUnexpectedLinkDownTimeCounts    Specifies the time in main function periodicity if an unexpected link down is qualified.
  EthTrcvDrvApiIdx                              the index of the 1:1 relation pointing to EthIf_EthTrcvDrvApi
  EthTrcvType                                   Indicates if the transceiver is standalone or connected to a switch port.
  MkaPaeIdx                                     PaeIdx of transceiver
  PortModeIdx                                   the index of the 0:1 relation pointing to EthIf_PortMode
  RequestedPortModeIdx                          the index of the 0:1 relation pointing to EthIf_RequestedPortMode
  UserSleepIndication                           User sleep indication of the EthIf Trcv.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_03[3];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvDrvApi
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvDrvApi
  \brief  APIs of the EthTrcv drivers abstracted by EthIf
  \details
  Element                      Description
  CheckWakeup                  EthTrcv_CheckWakeup() of the EthTrcv driver
  GetBaudRate                  EthTrcv_GetBaudRate() of the EthTrcv driver
  GetCableDiagnosticsResult    EthTrcv_GetCableDiagnosticsResult() of the EthTrcv driver
  GetDuplexMode                EthTrcv_GetDuplexMode() of the EthTrcv driver
  GetLinkState                 EthTrcv_GetLinkState() of the EthTrcv driver
  GetPhySignalQuality          EthTrcv_GetPhySignalQuality() of the EthTrcv driver
  GetPhyWakeupReason           EthTrcv_GetBusWuReason() of the EthTrcv driver
  GetTrcvMode                  EthTrcv_GetTransceiverMode() of the EthTrcv driver
  RunCableDiagnostic           RunCableDiagnostic() of the EthTrcv driver
  SetPhyLoopbackMode           SetPhyLoopbackMode() of the EthTrcv driver
  SetPhyTestMode               EthTrcv_SetPhyTestMode() of the EthTrcv driver
  SetPhyTxMode                 EthTrcv_SetPhyTxMode() of the EthTrcv driver
  SetTrcvMode                  EthTrcv_SetTransceiverMode() of the EthTrcv driver
  StartAutoNeg                 EthTrcv_StartAutoNegotiation() of the EthTrcv driver
  TrcvInit                     EthTrcv_TransceiverInit() of the EthTrcv driver
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_EthTrcvDrvApiType, ETHIF_CONST) EthIf_EthTrcvDrvApi[2];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_LinkStateChgIndications
**********************************************************************************************************************/
/** 
  \var    EthIf_LinkStateChgIndications
  \brief  Link State change indications of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_LinkStateChgIndFctPtrType, ETHIF_CONST) EthIf_LinkStateChgIndications[2];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerInitElemsRDR_01
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerInitElemsRDR_01
  \brief  Hardware that the EthIf controllers trigger initialization for
  \details
  Element              Description
  EthSwtIndEndIdx      the end index of the 0:n relation pointing to EthIf_EthSwtInd
  EthSwtIndStartIdx    the start index of the 0:n relation pointing to EthIf_EthSwtInd
  EthTrcvIdx           the index of the 0:1 relation pointing to EthIf_EthTrcv
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_01[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerInitElemsRDR_02
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerInitElemsRDR_02
  \brief  Hardware that the EthIf controllers trigger initialization for
  \details
  Element              Description
  EthSwtIndEndIdx      the end index of the 0:n relation pointing to EthIf_EthSwtInd
  EthSwtIndStartIdx    the start index of the 0:n relation pointing to EthIf_EthSwtInd
  EthTrcvIdx           the index of the 0:1 relation pointing to EthIf_EthTrcv
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_02[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerInitElemsRDR_03
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerInitElemsRDR_03
  \brief  Hardware that the EthIf controllers trigger initialization for
  \details
  Element              Description
  EthSwtIndEndIdx      the end index of the 0:n relation pointing to EthIf_EthSwtInd
  EthSwtIndStartIdx    the start index of the 0:n relation pointing to EthIf_EthSwtInd
  EthTrcvIdx           the index of the 0:1 relation pointing to EthIf_EthTrcv
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_03[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerModeElemsRDR_01
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerModeElemsRDR_01
  \brief  Hardware that the EthIf controllers trigger mode changes for
  \details
  Element         Description
  EthTrcvIdx      the index of the 0:1 relation pointing to EthIf_EthTrcv
  PortGroupIdx    the index of the 0:1 relation pointing to EthIf_PortGroup
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_01[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerModeElemsRDR_02
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerModeElemsRDR_02
  \brief  Hardware that the EthIf controllers trigger mode changes for
  \details
  Element         Description
  EthTrcvIdx      the index of the 0:1 relation pointing to EthIf_EthTrcv
  PortGroupIdx    the index of the 0:1 relation pointing to EthIf_PortGroup
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_02[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PhysLayerModeElemsRDR_03
**********************************************************************************************************************/
/** 
  \var    EthIf_PhysLayerModeElemsRDR_03
  \brief  Hardware that the EthIf controllers trigger mode changes for
  \details
  Element         Description
  EthTrcvIdx      the index of the 0:1 relation pointing to EthIf_EthTrcv
  PortGroupIdx    the index of the 0:1 relation pointing to EthIf_PortGroup
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_03[1];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RxIndications
**********************************************************************************************************************/
/** 
  \var    EthIf_RxIndications
  \brief  Rx indications of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_RxIndFctPtrType, ETHIF_CONST) EthIf_RxIndications[3];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_TxConfirmations
**********************************************************************************************************************/
/** 
  \var    EthIf_TxConfirmations
  \brief  Tx confirmations of the EthIf users.
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_TxConfFctPtrType, ETHIF_CONST) EthIf_TxConfirmations[2];
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlInitCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlInitCnt
  \brief  Initialization counts for the Eth controllers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthCtrlInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlInitCnt[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlModeCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlModeCnt
  \brief  Mode request counts for the Eth controllers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthCtrlModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlModeCnt[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthCtrlState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthCtrlState
  \brief  State of Eth controllers in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlState[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfControllerModeChangeReqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfControllerModeChangeReqCnt
  \brief  Counter used to trigger deactivation of switch port groups which were activated through EthIf_StartAllPorts API
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfControllerModeChangeReqCntType, ETHIF_VAR_NO_INIT) EthIf_EthIfControllerModeChangeReqCnt;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlInitState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlInitState
  \brief  Initialization state of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfCtrlInitStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlInitState[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlLinkCount
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlLinkCount
  \brief  Count of active links on the related hardware layer of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfCtrlLinkCountType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkCount[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlLinkState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlLinkState
  \brief  Link state of the EthIf controllers.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfCtrlLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkState[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlMode
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlMode
  \brief  Mode of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlMode[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlRxStats
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlRxStats
  \brief  Reception statistics for the EthIf controllers
  \details
  Element       Description
  NumRxBytes    Number of bytes received on EthIf controller
  NumRxPkts     Number of packets received on EthIf controller
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfCtrlRxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlRxStats[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfCtrlTxStats
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfCtrlTxStats
  \brief  Transmission statistics for the EthIf controllers
  \details
  Element       Description
  NumTxBytes    Number of bytes transmitted on EthIf controller
  NumTxPkts     Number of packets transmitted on EthIf controller
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfCtrlTxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlTxStats[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfMeasurementData
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfMeasurementData
  \brief  EthIf measurement data
  \details
  Element             Description
  DropCtrlIdx         Number of dropped datagrams caused by invalid CtrlIdx/VLAN
  UnknownEtherType    Number of dropped datagrams caused by unknown EtherType
  VlanDoubleTagged    Number of received datagrams with detected double VLAN tag
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfMeasurementDataType, ETHIF_VAR_NO_INIT) EthIf_EthIfMeasurementData[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter
  \brief  Qualified Unexpected link down timer counter per EthTrcv
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterType, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfQualifiedUnexpectedLinkDownTimerState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfQualifiedUnexpectedLinkDownTimerState
  \brief  Qualified Unexpected link down timer state per port EthTrcv
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_QualifiedUnexpectedLinkDownTimerStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerState[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfSwitchOffPortTimeDelayReqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfSwitchOffPortTimeDelayReqCnt
  \brief  Counter used to trigger deactivation of switch port groups which were activated through EthIf_StartAllPorts API
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthIfSwitchOffPortTimeDelayReqCntType, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortTimeDelayReqCnt;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthIfSwtPortGroupState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthIfSwtPortGroupState
  \brief  State of EthIf port groups in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfSwtPortGroupState[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvInitCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvInitCnt
  \brief  Initialization counts for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthTrcvInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvInitCnt[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvLinkState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvLinkState
  \brief  Link state of the EthIf tranceivers.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_PhyElemLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvLinkState[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvMode
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvMode
  \brief  Current mode of the EthTrcv
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvMode[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvModeChangeRetryCounter
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvModeChangeRetryCounter
  \brief  Mode request retry counts for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthTrcvModeChangeRetryCounterType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryCounter[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvModeChangeRetryPeriodCounter
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvModeChangeRetryPeriodCounter
  \brief  Mode request retry period counter for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthTrcvModeChangeRetryPeriodCounterType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryPeriodCounter[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvModeCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvModeCnt
  \brief  Mode request counts for the Eth transceivers abstracted by EthIf
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_EthTrcvModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeCnt[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_EthTrcvState
**********************************************************************************************************************/
/** 
  \var    EthIf_EthTrcvState
  \brief  State of Eth Transceiver in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvState[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_GlobalStartupActiveTimerActive
**********************************************************************************************************************/
/** 
  \var    EthIf_GlobalStartupActiveTimerActive
  \brief  Flag to enable/disable GlobalStartupActiveTimerActive
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_GlobalStartupActiveTimerActiveType, ETHIF_VAR_NO_INIT) EthIf_GlobalStartupActiveTimerActive;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_InitLocked
**********************************************************************************************************************/
/** 
  \var    EthIf_InitLocked
  \brief  Semaphore to protect EthIf_ControllerInit() against concurrent calls.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_InitLockedType, ETHIF_VAR_NO_INIT) EthIf_InitLocked;
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_MainFuncStateDecoupleFreqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_MainFuncStateDecoupleFreqCnt
  \brief  Counter used to decouple triggers for link state change observation within EthIf_MainFunctionTx()
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_MainFuncStateDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_MainFuncStateDecoupleFreqCnt;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_ModeChangeLocked
**********************************************************************************************************************/
/** 
  \var    EthIf_ModeChangeLocked
  \brief  Semaphore to protect EthIf_SetControllerMode() against concurrent calls.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_ModeChangeLockedType, ETHIF_VAR_NO_INIT) EthIf_ModeChangeLocked;
#define ETHIF_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PortStartupActiveTimeCounter
**********************************************************************************************************************/
/** 
  \var    EthIf_PortStartupActiveTimeCounter
  \brief  Counter used to trigger deactivation of switch port groups which were activated through EthIf_StartAllPorts API
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_PortStartupActiveTimeCounterType, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimeCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RequestedEthIfCtrlMode
**********************************************************************************************************************/
/** 
  \var    EthIf_RequestedEthIfCtrlMode
  \brief  Requested Mode of the EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthIfCtrlMode[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RequestedEthTrcvMode
**********************************************************************************************************************/
/** 
  \var    EthIf_RequestedEthTrcvMode
  \brief  Requested mode of the EthTrcv
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvMode[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RequestedEthTrcvStateOfEthIfCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_RequestedEthTrcvStateOfEthIfCtrl
  \brief  Requested mode of Eth Transceiver in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvStateOfEthIfCtrl[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_RequestedPortGroupStateOfEthIfCtrl
**********************************************************************************************************************/
/** 
  \var    EthIf_RequestedPortGroupStateOfEthIfCtrl
  \brief  Requested Mode of EthIf port groups in context of their specific EthIf controllers
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedPortGroupStateOfEthIfCtrl[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SignalQualityDecoupleFreqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_SignalQualityDecoupleFreqCnt
  \brief  Counter used to decouple triggers for signal quality observation within EthIf_MainFunctionState()
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_SignalQualityDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityDecoupleFreqCnt;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SignalQualityResult
**********************************************************************************************************************/
/** 
  \var    EthIf_SignalQualityResult
  \brief  Signal Quality of the transceiver.
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_SignalQualityResultType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityResult[3];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SrcMacAddrBuffer
**********************************************************************************************************************/
/** 
  \var    EthIf_SrcMacAddrBuffer
  \brief  Buffer holding latest MAC address used for the Ethernet-controller
  \details
  Element    Description
  Valid      Flag defining if buffer holds a valid MAC address
  SrcMac     MAC address
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_SrcMacAddrBufferType, ETHIF_VAR_NO_INIT) EthIf_SrcMacAddrBuffer[1];
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_SwtPortGroupModeChangeReqCnt
**********************************************************************************************************************/
/** 
  \var    EthIf_SwtPortGroupModeChangeReqCnt
  \brief  Counter used to trigger deactivation of switch port groups which were activated through EthIf_StartAllPorts API
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_SwtPortGroupModeChangeReqCntType, ETHIF_VAR_NO_INIT) EthIf_SwtPortGroupModeChangeReqCnt;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHIF_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_TxContext
**********************************************************************************************************************/
/** 
  \var    EthIf_TxContext
  \brief  Context information of each tx buffer that can be provided by the Eth drivers
  \details
  Element                       Description
  PayloadLen                    Length of the frames payload
  EthIfCtrlIdx                  Index of the EthIf controller the frame shall be send on
  EthIfCtrlToEtherTypeMapIdx    Index of the EthIf controller to the Frame owner Map
  TxPending                     Flag indicating if transmission is pending
  Valid                         Flag indicating if the context information is valid (buffer is in use)
  ValidPduId                    Flag indicating if the linked Pdu is valid.
  FrameHdr                      Ethernet frame header information
  LinkedPduId                   PduId attached to this TxContext.
  PayloadPtr                    Pointer to the frames payload
*/ 
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthIf_TxContextUType, ETHIF_VAR_NO_INIT) EthIf_TxContext;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthIf_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthIf_PCConfig
  \details
  Element                                         Description
  DedicatedRxPduNextFreePos                       the pointer to EthIf_DedicatedRxPduNextFreePos
  EcucPartition                                   the pointer to EthIf_EcucPartition
  EthCtrl                                         the pointer to EthIf_EthCtrl
  EthCtrlInitCnt                                  the pointer to EthIf_EthCtrlInitCnt
  EthCtrlModeCnt                                  the pointer to EthIf_EthCtrlModeCnt
  EthCtrlState                                    the pointer to EthIf_EthCtrlState
  EthDrvApi                                       the pointer to EthIf_EthDrvApi
  EthIfClkUnit                                    the pointer to EthIf_EthIfClkUnit
  EthIfControllerModeChangeReqCnt                 the pointer to EthIf_EthIfControllerModeChangeReqCnt
  EthIfCtrl                                       the pointer to EthIf_EthIfCtrl
  EthIfCtrlInitState                              the pointer to EthIf_EthIfCtrlInitState
  EthIfCtrlLinkCount                              the pointer to EthIf_EthIfCtrlLinkCount
  EthIfCtrlLinkState                              the pointer to EthIf_EthIfCtrlLinkState
  EthIfCtrlMode                                   the pointer to EthIf_EthIfCtrlMode
  EthIfCtrlOfEthTrcvInd                           the pointer to EthIf_EthIfCtrlOfEthTrcvInd
  EthIfCtrlOfPortGroupInd                         the pointer to EthIf_EthIfCtrlOfPortGroupInd
  EthIfCtrlRxStats                                the pointer to EthIf_EthIfCtrlRxStats
  EthIfCtrlToEtherTypeMap                         the pointer to EthIf_EthIfCtrlToEtherTypeMap
  EthIfCtrlToRxPduMap                             the pointer to EthIf_EthIfCtrlToRxPduMap
  EthIfCtrlTxStats                                the pointer to EthIf_EthIfCtrlTxStats
  EthIfMeasurementData                            the pointer to EthIf_EthIfMeasurementData
  EthIfPhysCtrlCfg                                the pointer to EthIf_EthIfPhysCtrlCfg
  EthIfQualifiedUnexpectedLinkDownTimerCounter    the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter
  EthIfQualifiedUnexpectedLinkDownTimerState      the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState
  EthIfSwitchOffPortGroupTimerDelayCounter        the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter
  EthIfSwitchOffPortGroupTimerDelayState          the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayState
  EthIfSwitchOffPortTimeDelayReqCnt               the pointer to EthIf_EthIfSwitchOffPortTimeDelayReqCnt
  EthIfSwitchOffPortTimerDelayState               the pointer to EthIf_EthIfSwitchOffPortTimerDelayState
  EthIfSwtPortGroupState                          the pointer to EthIf_EthIfSwtPortGroupState
  EthRxQueue                                      the pointer to EthIf_EthRxQueue
  EthSwt                                          the pointer to EthIf_EthSwt
  EthSwtDrv                                       the pointer to EthIf_EthSwtDrv
  EthSwtDrvApi                                    the pointer to EthIf_EthSwtDrvApi
  EthSwtInd                                       the pointer to EthIf_EthSwtInd
  EthSwtInitCnt                                   the pointer to EthIf_EthSwtInitCnt
  EthSwtPort                                      the pointer to EthIf_EthSwtPort
  EthSwtPortInEthSwtContext                       the pointer to EthIf_EthSwtPortInEthSwtContext
  EthSwtPortInd                                   the pointer to EthIf_EthSwtPortInd
  EthSwtPortLinkState                             the pointer to EthIf_EthSwtPortLinkState
  EthSwtPortModeCnt                               the pointer to EthIf_EthSwtPortModeCnt
  EthTrcv                                         the pointer to EthIf_EthTrcv
  EthTrcvDrvApi                                   the pointer to EthIf_EthTrcvDrvApi
  EthTrcvInitCnt                                  the pointer to EthIf_EthTrcvInitCnt
  EthTrcvLinkState                                the pointer to EthIf_EthTrcvLinkState
  EthTrcvMode                                     the pointer to EthIf_EthTrcvMode
  EthTrcvModeChangeRetryCounter                   the pointer to EthIf_EthTrcvModeChangeRetryCounter
  EthTrcvModeChangeRetryPeriodCounter             the pointer to EthIf_EthTrcvModeChangeRetryPeriodCounter
  EthTrcvModeCnt                                  the pointer to EthIf_EthTrcvModeCnt
  EthTrcvState                                    the pointer to EthIf_EthTrcvState
  EthTxQueue                                      the pointer to EthIf_EthTxQueue
  ExplicitBufReleaseFilter                        the pointer to EthIf_ExplicitBufReleaseFilter
  FloatingRxPduMap                                the pointer to EthIf_FloatingRxPduMap
  FloatingRxPduNextFreePos                        the pointer to EthIf_FloatingRxPduNextFreePos
  GatewaySrcMacBlackList                          the pointer to EthIf_GatewaySrcMacBlackList
  GlobalStartupActiveTimerActive                  the pointer to EthIf_GlobalStartupActiveTimerActive
  InitLocked                                      the pointer to EthIf_InitLocked
  LegacyWakeupMap                                 the pointer to EthIf_LegacyWakeupMap
  LinkStateChgIndications                         the pointer to EthIf_LinkStateChgIndications
  MainFuncStateDecoupleFreqCnt                    the pointer to EthIf_MainFuncStateDecoupleFreqCnt
  MainPartitionRxEthCtrl                          the pointer to EthIf_MainPartitionRxEthCtrl
  MainPartitionTxEthCtrl                          the pointer to EthIf_MainPartitionTxEthCtrl
  MirrorDest                                      the pointer to EthIf_MirrorDest
  MirrorTxInfo                                    the pointer to EthIf_MirrorTxInfo
  ModeChangeLocked                                the pointer to EthIf_ModeChangeLocked
  PhysLayerInitElems                              the pointer to EthIf_PhysLayerInitElems
  PhysLayerModeElems                              the pointer to EthIf_PhysLayerModeElems
  PortGroup                                       the pointer to EthIf_PortGroup
  PortGroupHostOrUpLinkPortRoleLinkCount          the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount
  PortGroupInd                                    the pointer to EthIf_PortGroupInd
  PortGroupLinkState                              the pointer to EthIf_PortGroupLinkState
  PortGroupMode                                   the pointer to EthIf_PortGroupMode
  PortGroupNoRoleLinkCount                        the pointer to EthIf_PortGroupNoRoleLinkCount
  PortGroupStartupActiveTimerActive               the pointer to EthIf_PortGroupStartupActiveTimerActive
  PortMode                                        the pointer to EthIf_PortMode
  PortSignalQualityResult                         the pointer to EthIf_PortSignalQualityResult
  PortStartupActiveTimeCounter                    the pointer to EthIf_PortStartupActiveTimeCounter
  PortStartupActiveTimerActive                    the pointer to EthIf_PortStartupActiveTimerActive
  RequestedEthIfCtrlMode                          the pointer to EthIf_RequestedEthIfCtrlMode
  RequestedEthTrcvMode                            the pointer to EthIf_RequestedEthTrcvMode
  RequestedEthTrcvStateOfEthIfCtrl                the pointer to EthIf_RequestedEthTrcvStateOfEthIfCtrl
  RequestedPortGroupMode                          the pointer to EthIf_RequestedPortGroupMode
  RequestedPortGroupStateOfEthIfCtrl              the pointer to EthIf_RequestedPortGroupStateOfEthIfCtrl
  RequestedPortMode                               the pointer to EthIf_RequestedPortMode
  RxIndications                                   the pointer to EthIf_RxIndications
  RxPdu                                           the pointer to EthIf_RxPdu
  RxPduContext                                    the pointer to EthIf_RxPduContext
  RxPduFrameType                                  the pointer to EthIf_RxPduFrameType
  RxPduFreeList                                   the pointer to EthIf_RxPduFreeList
  RxPduMetaData                                   the pointer to EthIf_RxPduMetaData
  RxQueueList                                     the pointer to EthIf_RxQueueList
  SignalQualityDecoupleFreqCnt                    the pointer to EthIf_SignalQualityDecoupleFreqCnt
  SignalQualityResult                             the pointer to EthIf_SignalQualityResult
  SrcMacAddrBuffer                                the pointer to EthIf_SrcMacAddrBuffer
  SwtPortGroupModeChangeReqCnt                    the pointer to EthIf_SwtPortGroupModeChangeReqCnt
  SwtPortGroupModeChangeRetryCounter              the pointer to EthIf_SwtPortGroupModeChangeRetryCounter
  SwtPortGroupModeChangeRetryPeriodCounter        the pointer to EthIf_SwtPortGroupModeChangeRetryPeriodCounter
  TxConfirmations                                 the pointer to EthIf_TxConfirmations
  TxContext                                       the pointer to EthIf_TxContext
  TxPdu                                           the pointer to EthIf_TxPdu
  TxPduContext                                    the pointer to EthIf_TxPduContext
  TxQueueList                                     the pointer to EthIf_TxQueueList
  WakeupMap                                       the pointer to EthIf_WakeupMap
  WakeupSrcDevice                                 the pointer to EthIf_WakeupSrcDevice
  SetControllerModeTimeout                        Maximum number of clock cycles to wait for the Eth driver to set its controller mode to ACTIVE
  EthIfSwitchOffPortTimeDelayCounts               EthIfSwitchOffPortTimeDelay timer in terms of main function periodicity
  GlobalModeChangeMaxRetryCount                   EthIf mode request retry max counter
  GlobalModeChangeRetryPeriodCount                EthIf Mode request retry period in terms of main function periodicity
  LinkStateChgMainReload                          Amount of calls link state observation isn't triggerd if observation is done within EthIf_MainFunctionTx() instead of using an explicit EthIf_MainFunctionState().
  MaxRxFramePerEthCtrl                            Maximum number of frames that can be received during a single invocation of EthIf_MainFunctionRx() in polling mode on one Ethernet controller (or per queue if EthBswSplit with polling is configured).
  MaxTxBufPerEthCtrl                              Maximum amount of Tx buffers configured for an Ethernet controller
  PortStartupActiveTimeFreq                       Port startup activation timer in terms of main function periodicity
  SignalQualityChgMainReload                      Amount of calls signal quality observation in EthIf_MainFunctionState().
  SizeOfEcucPartition                             the number of accomplishable value elements in EthIf_EcucPartition
  SizeOfEthCtrl                                   the number of accomplishable value elements in EthIf_EthCtrl
  SizeOfEthDrvApi                                 the number of accomplishable value elements in EthIf_EthDrvApi
  SizeOfEthIfClkUnit                              the number of accomplishable value elements in EthIf_EthIfClkUnit
  SizeOfEthIfCtrl                                 the number of accomplishable value elements in EthIf_EthIfCtrl
  SizeOfEthIfCtrlOfEthTrcvInd                     the number of accomplishable value elements in EthIf_EthIfCtrlOfEthTrcvInd
  SizeOfEthIfCtrlOfPortGroupInd                   the number of accomplishable value elements in EthIf_EthIfCtrlOfPortGroupInd
  SizeOfEthIfCtrlToEtherTypeMap                   the number of accomplishable value elements in EthIf_EthIfCtrlToEtherTypeMap
  SizeOfEthIfCtrlToRxPduMap                       the number of accomplishable value elements in EthIf_EthIfCtrlToRxPduMap
  SizeOfEthIfMeasurementData                      the number of accomplishable value elements in EthIf_EthIfMeasurementData
  SizeOfEthIfPhysCtrlCfg                          the number of accomplishable value elements in EthIf_EthIfPhysCtrlCfg
  SizeOfEthRxQueue                                the number of accomplishable value elements in EthIf_EthRxQueue
  SizeOfEthSwt                                    the number of accomplishable value elements in EthIf_EthSwt
  SizeOfEthSwtDrv                                 the number of accomplishable value elements in EthIf_EthSwtDrv
  SizeOfEthSwtDrvApi                              the number of accomplishable value elements in EthIf_EthSwtDrvApi
  SizeOfEthSwtInd                                 the number of accomplishable value elements in EthIf_EthSwtInd
  SizeOfEthSwtPort                                the number of accomplishable value elements in EthIf_EthSwtPort
  SizeOfEthSwtPortInEthSwtContext                 the number of accomplishable value elements in EthIf_EthSwtPortInEthSwtContext
  SizeOfEthSwtPortInd                             the number of accomplishable value elements in EthIf_EthSwtPortInd
  SizeOfEthTrcv                                   the number of accomplishable value elements in EthIf_EthTrcv
  SizeOfEthTrcvDrvApi                             the number of accomplishable value elements in EthIf_EthTrcvDrvApi
  SizeOfEthTxQueue                                the number of accomplishable value elements in EthIf_EthTxQueue
  SizeOfExplicitBufReleaseFilter                  the number of accomplishable value elements in EthIf_ExplicitBufReleaseFilter
  SizeOfFloatingRxPduMap                          the number of accomplishable value elements in EthIf_FloatingRxPduMap
  SizeOfGatewaySrcMacBlackList                    the number of accomplishable value elements in EthIf_GatewaySrcMacBlackList
  SizeOfLegacyWakeupMap                           the number of accomplishable value elements in EthIf_LegacyWakeupMap
  SizeOfLinkStateChgIndications                   the number of accomplishable value elements in EthIf_LinkStateChgIndications
  SizeOfMainPartitionRxEthCtrl                    the number of accomplishable value elements in EthIf_MainPartitionRxEthCtrl
  SizeOfMainPartitionTxEthCtrl                    the number of accomplishable value elements in EthIf_MainPartitionTxEthCtrl
  SizeOfMirrorDest                                the number of accomplishable value elements in EthIf_MirrorDest
  SizeOfMirrorTxInfo                              the number of accomplishable value elements in EthIf_MirrorTxInfo
  SizeOfPhysLayerInitElems                        the number of accomplishable value elements in EthIf_PhysLayerInitElems
  SizeOfPhysLayerModeElems                        the number of accomplishable value elements in EthIf_PhysLayerModeElems
  SizeOfPortGroup                                 the number of accomplishable value elements in EthIf_PortGroup
  SizeOfPortGroupInd                              the number of accomplishable value elements in EthIf_PortGroupInd
  SizeOfPortMode                                  the number of accomplishable value elements in EthIf_PortMode
  SizeOfRequestedPortMode                         the number of accomplishable value elements in EthIf_RequestedPortMode
  SizeOfRxIndications                             the number of accomplishable value elements in EthIf_RxIndications
  SizeOfRxPdu                                     the number of accomplishable value elements in EthIf_RxPdu
  SizeOfRxPduFrameType                            the number of accomplishable value elements in EthIf_RxPduFrameType
  SizeOfRxPduMetaData                             the number of accomplishable value elements in EthIf_RxPduMetaData
  SizeOfRxQueueList                               the number of accomplishable value elements in EthIf_RxQueueList
  SizeOfTxConfirmations                           the number of accomplishable value elements in EthIf_TxConfirmations
  SizeOfTxContext                                 the number of accomplishable value elements in EthIf_TxContext
  SizeOfTxPdu                                     the number of accomplishable value elements in EthIf_TxPdu
  SizeOfTxQueueList                               the number of accomplishable value elements in EthIf_TxQueueList
  SizeOfWakeupMap                                 the number of accomplishable value elements in EthIf_WakeupMap
  SizeOfWakeupSrcDevice                           the number of accomplishable value elements in EthIf_WakeupSrcDevice
*/ 
#define ETHIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthIf_PCConfigsType, ETHIF_CONST) EthIf_PCConfig;
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#endif /* ETHIF_GENTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_GenTypes.h
 *********************************************************************************************************************/


