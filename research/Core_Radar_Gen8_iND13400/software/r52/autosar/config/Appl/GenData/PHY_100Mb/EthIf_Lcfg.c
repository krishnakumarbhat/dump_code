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
 *              File: EthIf_Lcfg.c
 *   Generation Time: 2026-09-01 16:41:00
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
#define ETHIF_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/

/*********************************************************************************************************
 * Predefined file includes based on \trace DSGN-EthIfDiag1977
 *********************************************************************************************************/
#include "EthIf_Lcfg.h"

/*********************************************************************************************************
 * Dynamic includes depending on configuration
 *********************************************************************************************************/
#if (ETHIF_TXPDU_HANDLING_SUPPORT == STD_ON)
/* PduR Header Files */
#include "PduR_Cfg.h"
#include "PduR_EthIf.h"
#endif /* ETHIF_TXPDU_HANDLING_SUPPORT */



#include "TcpIp.h"
#include "EthTSyn.h"
#include "EthIf_User_Cbk.h"

#include "Eth_30_Wrapper.h"

#include "EthTrcv_30_Rtl9010.h"
#include "EthTrcv_30_Tja1103.h"


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(EthIf_EcucPartitionType, ETHIF_CONST) EthIf_EcucPartition[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    QualityLevel                                     Referable Keys */
  { /*     0 */ ETHIF_UNKNOWN_QUALITYLEVELOFECUCPARTITION }   /* [NO_ECUC_PARTITION_CONFIGURED] */
};
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
CONST(EthIf_EthCtrlType, ETHIF_CONST) EthIf_EthCtrl[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Snv                                                    BufIdxOffsetEnabled  EthArReleaseRxBufferSupported  ImplicitBufferReleaseNeeded  EthDrvApiIdx                        NumOfTxBuffers  TxContextEndIdx                                                                      TxContextLength                                                                      TxContextStartIdx                                                                            Referable Keys */
  { /*     0 */ EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb,               FALSE,                          TRUE,                       FALSE,           0u  /* Eth_30_Wrapper */,           100u,            100u  /* /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb */,            100u  /* /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb */,                0u  /* /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb */ }   /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_EthDrvApiType, ETHIF_CONST) EthIf_EthDrvApi[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CtrlInit                        EnableEgressTimeStamp                  GetBandwidthLimit  GetCtrlMode                        GetCurrentTime                 GetEgressTimeStamp                  GetIngressTimeStamp                  GetPhysAddr                  GetRxHeaderPtr  GetRxStats  GetSpiStatus  GetTxHeaderPtr  GetTxStats  ImmediateTransmit  ProvideExtTxBuffer  ProvideTxBuffer                  Receive                  ReceiveQueue  ReleaseRxBuffer  SetBandwidthLimit  SetCtrlMode                        SetPhysAddr                  Transmit                  TxConfirmation                  TxConfirmationQueue  UpdatePhysAddrFilter                  VGetEgressTimeStamp  VReleaseRxBuffer  VTransmit                        Referable Keys */
  { /*     0 */ &Eth_30_Wrapper_ControllerInit, &Eth_30_Wrapper_EnableEgressTimestamp, NULL_PTR         , &Eth_30_Wrapper_GetControllerMode, &Eth_30_Wrapper_GetGlobalTime, &Eth_30_Wrapper_GetEgressTimestamp, &Eth_30_Wrapper_GetIngressTimestamp, &Eth_30_Wrapper_GetPhysAddr, NULL_PTR      , NULL_PTR  , NULL_PTR    , NULL_PTR      , NULL_PTR  , NULL_PTR         , NULL_PTR          , &Eth_30_Wrapper_ProvideTxBuffer, &Eth_30_Wrapper_Receive, NULL_PTR    , NULL_PTR       , NULL_PTR         , &Eth_30_Wrapper_SetControllerMode, &Eth_30_Wrapper_SetPhysAddr, &Eth_30_Wrapper_Transmit, &Eth_30_Wrapper_TxConfirmation, NULL_PTR           , &Eth_30_Wrapper_UpdatePhysAddrFilter, NULL_PTR           , NULL_PTR        , &Eth_30_Wrapper_VTransmit }   /* [Eth_30_Wrapper, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */
};
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
CONST(EthIf_EthIfCtrlType, ETHIF_CONST) EthIf_EthIfCtrl[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Snv                                                  Mtu    VlanId             EcucPartitionIdx                                      EthCtrlIdx                                                                      EthIfCtrlToEtherTypeMapEndIdx                                                                    EthIfCtrlToEtherTypeMapLength                                                                    EthIfCtrlToEtherTypeMapStartIdx                                                                    EthIfPhysCtrlCfgIdx                                                                                        EthSwtDrvApiIdx                                                                                        GatewayDestEthIfCtrlIdx                      GatewayDestEthIfCtrlIdxIdx                                     LinkAggrThreshold  MacSecType                             MirrorRxDestIdx                      MirrorRxDestIdxIdx                                                                                        MirrorTxDestIdx                      MirrorTxDestIdxIdx                                                                                        PhysLayerInitElemsIdx                                                                    PhysLayerModeElemsIdx                                                                    Type                                                 Referable Keys */
  { /*     0 */ EthIfConf_EthIfController_cnctr_RDR_RdrNet_5172a59b, 1500u, ETHIF_INV_VLAN_ID,               0u  /* NO_ECUC_PARTITION_CONFIGURED */,         0u  /* /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb */,                            3u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,                            3u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,                              0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,                  0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_RADAR_EthConnector1_Controller_bbe781c0 */, ETHIF_NO_ETHSWTDRVAPIIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_GATEWAYDESTETHIFCTRLIDXOFETHIFCTRL, ETHIF_NO_GATEWAYDESTETHIFCTRLIDXIDXOFETHIFCTRL  /* No_Dest */,                1u, ETHIF_NO_MACSEC_MACSECTYPEOFETHIFCTRL, ETHIF_NO_MIRRORRXDESTIDXOFETHIFCTRL, ETHIF_NO_MIRRORRXDESTIDXIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_MIRRORTXDESTIDXOFETHIFCTRL, ETHIF_NO_MIRRORTXDESTIDXIDXOFETHIFCTRL  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_ETHIFCTRL_TYPE_PHYSICAL_TYPEOFETHIFCTRL }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
};
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
CONST(EthIf_EthIfCtrlOfEthTrcvIndType, ETHIF_CONST) EthIf_EthIfCtrlOfEthTrcvInd[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     EthIfCtrlOfEthTrcvInd      Referable Keys */
  /*     0 */                     0u   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
};
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
CONST(EthIf_EthIfCtrlToEtherTypeMapType, ETHIF_CONST) EthIf_EthIfCtrlToEtherTypeMap[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EtherType  RxIndicationsEndIdx                                                                                RxIndicationsLength                                                                                RxIndicationsStartIdx                                                                                TxConfirmationsEndIdx                                                                                                                  TxConfirmationsLength                                                                                TxConfirmationsStartIdx                                                                                                                        Referable Keys */
  { /*     0 */   0x0800u,                  1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */ ,                  1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */ ,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */ ,                                                      1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */ ,                    1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */ ,                                                        0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b */  },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  { /*     1 */   0x0806u,                  2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */  ,                  1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */  ,                    1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */  , ETHIF_NO_TXCONFIRMATIONSENDIDXOFETHIFCTRLTOETHERTYPEMAP  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */  ,                    0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */  , ETHIF_NO_TXCONFIRMATIONSSTARTIDXOFETHIFCTRLTOETHERTYPEMAP  /* /ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b */   },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  { /*     2 */   0x88F7u,                  3u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */,                  1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */,                    2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */,                                                      2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */,                    1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */,                                                        1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_EthIfPhysCtrlCfgType, ETHIF_CONST) EthIf_EthIfPhysCtrlCfg[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthCtrlIdx                                             EthIfPhysControllerIdx                                                       EthPhcSupportAvailable  EthDrvApiIdx                        EthIfClkUnitEndIdx                                                                                                                   EthIfClkUnitLength                                                                                        EthIfClkUnitStartIdx                                                                                                                         Referable Keys */
  { /*     0 */ EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb, EthIfConf_EthIfPhysController_EthIf_RADAR_EthConnector1_Controller_bbe781c0,                  FALSE,           0u  /* Eth_30_Wrapper */, ETHIF_NO_ETHIFCLKUNITENDIDXOFETHIFPHYSCTRLCFG  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_RADAR_EthConnector1_Controller_bbe781c0 */,                 0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_RADAR_EthConnector1_Controller_bbe781c0 */, ETHIF_NO_ETHIFCLKUNITSTARTIDXOFETHIFPHYSCTRLCFG  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_RADAR_EthConnector1_Controller_bbe781c0 */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_RADAR_EthConnector1_Controller_bbe781c0, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_01[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Snv                                                    AsyncProcessing  EthTrcvActAsSlavePassiveEnabled  MacSecSecured  EthIfCtrlOfEthTrcvIndEndIdx                                                                                              EthIfCtrlOfEthTrcvIndStartIdx                                                                                              EthIfQualifiedUnexpectedLinkDownTimeCounts  EthTrcvDrvApiIdx                            EthTrcvType                                    MkaPaeIdx  PortModeIdx                                                                                                RequestedPortModeIdx                                                                                                UserSleepIndication        Referable Keys */
  { /*     0 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA      ,           FALSE,                           FALSE,         FALSE,                                            1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      ,                                              0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      ,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  { /*     1 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA_100Mb,           FALSE,                           FALSE,         FALSE, 1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */, ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  { /*     2 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_TJA1103B     ,           FALSE,                           FALSE,         FALSE, 1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    , ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    ,                                         0u,               1u  /* EthTrcv_30_Tja1103 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , NULL_PTR            }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
};
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
CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_02[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Snv                                                    AsyncProcessing  EthTrcvActAsSlavePassiveEnabled  MacSecSecured  EthIfCtrlOfEthTrcvIndEndIdx                                                                                              EthIfCtrlOfEthTrcvIndStartIdx                                                                                              EthIfQualifiedUnexpectedLinkDownTimeCounts  EthTrcvDrvApiIdx                            EthTrcvType                                    MkaPaeIdx  PortModeIdx                                                                                                RequestedPortModeIdx                                                                                                UserSleepIndication        Referable Keys */
  { /*     0 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA      ,           FALSE,                           FALSE,         FALSE, ETHIF_NO_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      , ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      ,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  { /*     1 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA_100Mb,           FALSE,                           FALSE,         FALSE,                                            1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */,                                              0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  { /*     2 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_TJA1103B     ,           FALSE,                           FALSE,         FALSE, ETHIF_NO_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    , ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    ,                                         0u,               1u  /* EthTrcv_30_Tja1103 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , NULL_PTR            }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
};
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
CONST(EthIf_EthTrcvType, ETHIF_CONST) EthIf_EthTrcvRDR_03[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Snv                                                    AsyncProcessing  EthTrcvActAsSlavePassiveEnabled  MacSecSecured  EthIfCtrlOfEthTrcvIndEndIdx                                                                                              EthIfCtrlOfEthTrcvIndStartIdx                                                                                              EthIfQualifiedUnexpectedLinkDownTimeCounts  EthTrcvDrvApiIdx                            EthTrcvType                                    MkaPaeIdx  PortModeIdx                                                                                                RequestedPortModeIdx                                                                                                UserSleepIndication        Referable Keys */
  { /*     0 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA      ,           FALSE,                           FALSE,         FALSE, ETHIF_NO_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      , ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA */      ,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA */      , NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  { /*     1 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_9010BSA_100Mb,           FALSE,                           FALSE,         FALSE, ETHIF_NO_ETHIFCTRLOFETHTRCVINDENDIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */, ETHIF_NO_ETHIFCTRLOFETHTRCVINDSTARTIDXOFETHTRCV  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb */,                                         0u,               0u  /* EthTrcv_30_Rtl9010 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb */, NULL_PTR            },  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  { /*     2 */ EthTrcvConf_EthTrcvConfig_EthTrcvConfig_TJA1103B     ,           FALSE,                           FALSE,         FALSE,                                            1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    ,                                              0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B */    ,                                         0u,               1u  /* EthTrcv_30_Tja1103 */, ETHIF_ETHTRCV_STANDALONE_ETHTRCVTYPEOFETHTRCV,        0u, ETHIF_NO_PORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , ETHIF_NO_REQUESTEDPORTMODEIDXOFETHTRCV  /* /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B */     , NULL_PTR            }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_EthTrcvDrvApiType, ETHIF_CONST) EthIf_EthTrcvDrvApi[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CheckWakeup  GetBaudRate                      GetCableDiagnosticsResult                      GetDuplexMode                      GetLinkState                      GetPhySignalQuality                      GetPhyWakeupReason  GetTrcvMode                             RunCableDiagnostic                      SetPhyLoopbackMode                      SetPhyTestMode                      SetPhyTxMode                      SetTrcvMode                             StartAutoNeg                              TrcvInit                                   Referable Keys */
  { /*     0 */ NULL_PTR   , &EthTrcv_30_Rtl9010_GetBaudRate, &EthTrcv_30_Rtl9010_GetCableDiagnosticsResult, &EthTrcv_30_Rtl9010_GetDuplexMode, &EthTrcv_30_Rtl9010_GetLinkState, &EthTrcv_30_Rtl9010_GetPhySignalQuality, NULL_PTR          , &EthTrcv_30_Rtl9010_GetTransceiverMode, &EthTrcv_30_Rtl9010_RunCableDiagnostic, &EthTrcv_30_Rtl9010_SetPhyLoopbackMode, &EthTrcv_30_Rtl9010_SetPhyTestMode, &EthTrcv_30_Rtl9010_SetPhyTxMode, &EthTrcv_30_Rtl9010_SetTransceiverMode, &EthTrcv_30_Rtl9010_StartAutoNegotiation, &EthTrcv_30_Rtl9010_TransceiverInit },  /* [EthTrcv_30_Rtl9010, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  { /*     1 */ NULL_PTR   , &EthTrcv_30_Tja1103_GetBaudRate, &EthTrcv_30_Tja1103_GetCableDiagnosticsResult, &EthTrcv_30_Tja1103_GetDuplexMode, &EthTrcv_30_Tja1103_GetLinkState, &EthTrcv_30_Tja1103_GetPhySignalQuality, NULL_PTR          , &EthTrcv_30_Tja1103_GetTransceiverMode, &EthTrcv_30_Tja1103_RunCableDiagnostic, &EthTrcv_30_Tja1103_SetPhyLoopbackMode, &EthTrcv_30_Tja1103_SetPhyTestMode, &EthTrcv_30_Tja1103_SetPhyTxMode, &EthTrcv_30_Tja1103_SetTransceiverMode, NULL_PTR                                , &EthTrcv_30_Tja1103_TransceiverInit }   /* [EthTrcv_30_Tja1103, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
};
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
CONST(EthIf_LinkStateChgIndFctPtrType, ETHIF_CONST) EthIf_LinkStateChgIndications[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     LinkStateChgIndications    */
  /*     0 */ &EthTSyn_TrcvLinkStateChg ,
  /*     1 */ &CDD_Cbk_TrcvLinkStateChg 
};
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
CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_01[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthSwtIndEndIdx                                                                                                 EthSwtIndStartIdx                                                                                                 EthTrcvIdx                                                                          Referable Keys */
  { /*     0 */ ETHIF_NO_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,         0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_02[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthSwtIndEndIdx                                                                                                 EthSwtIndStartIdx                                                                                                 EthTrcvIdx                                                                          Referable Keys */
  { /*     0 */ ETHIF_NO_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,         1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_PhysLayerInitElemsType, ETHIF_CONST) EthIf_PhysLayerInitElemsRDR_03[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthSwtIndEndIdx                                                                                                 EthSwtIndStartIdx                                                                                                 EthTrcvIdx                                                                          Referable Keys */
  { /*     0 */ ETHIF_NO_ETHSWTINDENDIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_ETHSWTINDSTARTIDXOFPHYSLAYERINITELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */,         2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_01[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthTrcvIdx                                                                    PortGroupIdx                                                                                                       Referable Keys */
  { /*     0 */         0u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_02[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthTrcvIdx                                                                    PortGroupIdx                                                                                                       Referable Keys */
  { /*     0 */         1u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_PhysLayerModeElemsType, ETHIF_CONST) EthIf_PhysLayerModeElemsRDR_03[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EthTrcvIdx                                                                    PortGroupIdx                                                                                                       Referable Keys */
  { /*     0 */         2u  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */, ETHIF_NO_PORTGROUPIDXOFPHYSLAYERMODEELEMS  /* /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b */ }   /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_RxIndFctPtrType, ETHIF_CONST) EthIf_RxIndications[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RxIndications               Referable Keys */
  /*     0 */ &IpV4_Ip_RxIndication  ,  /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */ &IpV4_Arp_RxIndication ,  /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_ARP_cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */ &EthTSyn_RxIndication     /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b] */
};
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
CONST(EthIf_TxConfFctPtrType, ETHIF_CONST) EthIf_TxConfirmations[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     TxConfirmations              Referable Keys */
  /*     0 */ &IpV4_Ip_TxConfirmation ,  /* [/ActiveEcuC/EthIf/EthIfConfigSet/TcpIp_IPv4_cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */ &EthTSyn_TxConfirmation    /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthTSyn_PTP_cnctr_RDR_RdrNet_5172a59b] */
};
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
VAR(EthIf_EthCtrlInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlInitCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */

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
VAR(EthIf_EthCtrlModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlModeCnt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */

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
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthCtrlState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfControllerModeChangeReqCntType, ETHIF_VAR_NO_INIT) EthIf_EthIfControllerModeChangeReqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_EthIfCtrlInitStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlInitState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfCtrlLinkCountType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkCount[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfCtrlLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlLinkState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlMode[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfCtrlRxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlRxStats[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfCtrlTxStatsType, ETHIF_VAR_NO_INIT) EthIf_EthIfCtrlTxStats[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthIfMeasurementDataType, ETHIF_VAR_NO_INIT) EthIf_EthIfMeasurementData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounterType, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_QualifiedUnexpectedLinkDownTimerStateType, ETHIF_VAR_NO_INIT) EthIf_EthIfQualifiedUnexpectedLinkDownTimerState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_EthIfSwitchOffPortTimeDelayReqCntType, ETHIF_VAR_NO_INIT) EthIf_EthIfSwitchOffPortTimeDelayReqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthIfSwtPortGroupState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_EthTrcvInitCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvInitCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_PhyElemLinkStateType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvLinkState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvMode[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_EthTrcvModeChangeRetryCounterType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryCounter[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_EthTrcvModeChangeRetryPeriodCounterType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeChangeRetryPeriodCounter[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_EthTrcvModeCntType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvModeCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(Eth_ModeType, ETHIF_VAR_NO_INIT) EthIf_EthTrcvState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_GlobalStartupActiveTimerActiveType, ETHIF_VAR_NO_INIT) EthIf_GlobalStartupActiveTimerActive;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_InitLockedType, ETHIF_VAR_NO_INIT) EthIf_InitLocked;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_MainFuncStateDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_MainFuncStateDecoupleFreqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_ModeChangeLockedType, ETHIF_VAR_NO_INIT) EthIf_ModeChangeLocked;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_PortStartupActiveTimeCounterType, ETHIF_VAR_NO_INIT) EthIf_PortStartupActiveTimeCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthIfCtrlMode[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvMode[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedEthTrcvStateOfEthIfCtrl[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_RequestedModeType, ETHIF_VAR_NO_INIT) EthIf_RequestedPortGroupStateOfEthIfCtrl[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb] */

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
VAR(EthIf_SignalQualityDecoupleFreqCntType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityDecoupleFreqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_SignalQualityResultType, ETHIF_VAR_NO_INIT) EthIf_SignalQualityResult[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA] */
  /*     1 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B, /ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B] */

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
VAR(EthIf_SrcMacAddrBufferType, ETHIF_VAR_NO_INIT) EthIf_SrcMacAddrBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb, /ActiveEcuC/EthIf/EthIfConfigSet/cnctr_RDR_RdrNet_5172a59b] */

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
VAR(EthIf_SwtPortGroupModeChangeReqCntType, ETHIF_VAR_NO_INIT) EthIf_SwtPortGroupModeChangeReqCnt;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(EthIf_TxContextUType, ETHIF_VAR_NO_INIT) EthIf_TxContext;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
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
CONST(EthIf_PCConfigsType, ETHIF_CONST) EthIf_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_03] */
      NULL_PTR                                            /**< the pointer to EthIf_DedicatedRxPduNextFreePos in Config_RDR_03 */
    , EthIf_EcucPartition                                 /**< the pointer to EthIf_EcucPartition in Config_RDR_03 */
    , EthIf_EthCtrl                                       /**< the pointer to EthIf_EthCtrl in Config_RDR_03 */
    , EthIf_EthCtrlInitCnt                                /**< the pointer to EthIf_EthCtrlInitCnt in Config_RDR_03 */
    , EthIf_EthCtrlModeCnt                                /**< the pointer to EthIf_EthCtrlModeCnt in Config_RDR_03 */
    , EthIf_EthCtrlState                                  /**< the pointer to EthIf_EthCtrlState in Config_RDR_03 */
    , EthIf_EthDrvApi                                     /**< the pointer to EthIf_EthDrvApi in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfClkUnit in Config_RDR_03 */
    , (&(EthIf_EthIfControllerModeChangeReqCnt))          /**< the pointer to EthIf_EthIfControllerModeChangeReqCnt in Config_RDR_03 */
    , EthIf_EthIfCtrl                                     /**< the pointer to EthIf_EthIfCtrl in Config_RDR_03 */
    , EthIf_EthIfCtrlInitState                            /**< the pointer to EthIf_EthIfCtrlInitState in Config_RDR_03 */
    , EthIf_EthIfCtrlLinkCount                            /**< the pointer to EthIf_EthIfCtrlLinkCount in Config_RDR_03 */
    , EthIf_EthIfCtrlLinkState                            /**< the pointer to EthIf_EthIfCtrlLinkState in Config_RDR_03 */
    , EthIf_EthIfCtrlMode                                 /**< the pointer to EthIf_EthIfCtrlMode in Config_RDR_03 */
    , EthIf_EthIfCtrlOfEthTrcvInd                         /**< the pointer to EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_03 */
    , EthIf_EthIfCtrlRxStats                              /**< the pointer to EthIf_EthIfCtrlRxStats in Config_RDR_03 */
    , EthIf_EthIfCtrlToEtherTypeMap                       /**< the pointer to EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlToRxPduMap in Config_RDR_03 */
    , EthIf_EthIfCtrlTxStats                              /**< the pointer to EthIf_EthIfCtrlTxStats in Config_RDR_03 */
    , EthIf_EthIfMeasurementData                          /**< the pointer to EthIf_EthIfMeasurementData in Config_RDR_03 */
    , EthIf_EthIfPhysCtrlCfg                              /**< the pointer to EthIf_EthIfPhysCtrlCfg in Config_RDR_03 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter  /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter in Config_RDR_03 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerState    /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayState in Config_RDR_03 */
    , (&(EthIf_EthIfSwitchOffPortTimeDelayReqCnt))        /**< the pointer to EthIf_EthIfSwitchOffPortTimeDelayReqCnt in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortTimerDelayState in Config_RDR_03 */
    , EthIf_EthIfSwtPortGroupState                        /**< the pointer to EthIf_EthIfSwtPortGroupState in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthRxQueue in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwt in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrv in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrvApi in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInd in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInitCnt in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPort in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInEthSwtContext in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInd in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortLinkState in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortModeCnt in Config_RDR_03 */
    , EthIf_EthTrcvRDR_03                                 /**< the pointer to EthIf_EthTrcv in Config_RDR_03 */
    , EthIf_EthTrcvDrvApi                                 /**< the pointer to EthIf_EthTrcvDrvApi in Config_RDR_03 */
    , EthIf_EthTrcvInitCnt                                /**< the pointer to EthIf_EthTrcvInitCnt in Config_RDR_03 */
    , EthIf_EthTrcvLinkState                              /**< the pointer to EthIf_EthTrcvLinkState in Config_RDR_03 */
    , EthIf_EthTrcvMode                                   /**< the pointer to EthIf_EthTrcvMode in Config_RDR_03 */
    , EthIf_EthTrcvModeChangeRetryCounter                 /**< the pointer to EthIf_EthTrcvModeChangeRetryCounter in Config_RDR_03 */
    , EthIf_EthTrcvModeChangeRetryPeriodCounter           /**< the pointer to EthIf_EthTrcvModeChangeRetryPeriodCounter in Config_RDR_03 */
    , EthIf_EthTrcvModeCnt                                /**< the pointer to EthIf_EthTrcvModeCnt in Config_RDR_03 */
    , EthIf_EthTrcvState                                  /**< the pointer to EthIf_EthTrcvState in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthTxQueue in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_ExplicitBufReleaseFilter in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduMap in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduNextFreePos in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_GatewaySrcMacBlackList in Config_RDR_03 */
    , (&(EthIf_GlobalStartupActiveTimerActive))           /**< the pointer to EthIf_GlobalStartupActiveTimerActive in Config_RDR_03 */
    , (&(EthIf_InitLocked))                               /**< the pointer to EthIf_InitLocked in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_LegacyWakeupMap in Config_RDR_03 */
    , EthIf_LinkStateChgIndications                       /**< the pointer to EthIf_LinkStateChgIndications in Config_RDR_03 */
    , (&(EthIf_MainFuncStateDecoupleFreqCnt))             /**< the pointer to EthIf_MainFuncStateDecoupleFreqCnt in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionRxEthCtrl in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionTxEthCtrl in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorDest in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorTxInfo in Config_RDR_03 */
    , (&(EthIf_ModeChangeLocked))                         /**< the pointer to EthIf_ModeChangeLocked in Config_RDR_03 */
    , EthIf_PhysLayerInitElemsRDR_03                      /**< the pointer to EthIf_PhysLayerInitElems in Config_RDR_03 */
    , EthIf_PhysLayerModeElemsRDR_03                      /**< the pointer to EthIf_PhysLayerModeElems in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroup in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupInd in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupLinkState in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupMode in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupNoRoleLinkCount in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupStartupActiveTimerActive in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortMode in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortSignalQualityResult in Config_RDR_03 */
    , (&(EthIf_PortStartupActiveTimeCounter))             /**< the pointer to EthIf_PortStartupActiveTimeCounter in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortStartupActiveTimerActive in Config_RDR_03 */
    , EthIf_RequestedEthIfCtrlMode                        /**< the pointer to EthIf_RequestedEthIfCtrlMode in Config_RDR_03 */
    , EthIf_RequestedEthTrcvMode                          /**< the pointer to EthIf_RequestedEthTrcvMode in Config_RDR_03 */
    , EthIf_RequestedEthTrcvStateOfEthIfCtrl              /**< the pointer to EthIf_RequestedEthTrcvStateOfEthIfCtrl in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortGroupMode in Config_RDR_03 */
    , EthIf_RequestedPortGroupStateOfEthIfCtrl            /**< the pointer to EthIf_RequestedPortGroupStateOfEthIfCtrl in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortMode in Config_RDR_03 */
    , EthIf_RxIndications                                 /**< the pointer to EthIf_RxIndications in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPdu in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduContext in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFrameType in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFreeList in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduMetaData in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxQueueList in Config_RDR_03 */
    , (&(EthIf_SignalQualityDecoupleFreqCnt))             /**< the pointer to EthIf_SignalQualityDecoupleFreqCnt in Config_RDR_03 */
    , EthIf_SignalQualityResult                           /**< the pointer to EthIf_SignalQualityResult in Config_RDR_03 */
    , EthIf_SrcMacAddrBuffer                              /**< the pointer to EthIf_SrcMacAddrBuffer in Config_RDR_03 */
    , (&(EthIf_SwtPortGroupModeChangeReqCnt))             /**< the pointer to EthIf_SwtPortGroupModeChangeReqCnt in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryCounter in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryPeriodCounter in Config_RDR_03 */
    , EthIf_TxConfirmations                               /**< the pointer to EthIf_TxConfirmations in Config_RDR_03 */
    , EthIf_TxContext.raw                                 /**< the pointer to EthIf_TxContext in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPdu in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPduContext in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxQueueList in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupMap in Config_RDR_03 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupSrcDevice in Config_RDR_03 */
    , 1000u
    , 0u
    , 0u
    , 5u
    , 2u
    , 5u
    , 100u
    , 100u
    , 0u
    , 1u                                                  /**< the number of elements in EthIf_EcucPartition in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthCtrl in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthDrvApi in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfClkUnit in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrl in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_03 */
    , 3u                                                  /**< the number of elements in EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlToRxPduMap in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfMeasurementData in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfPhysCtrlCfg in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthRxQueue in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwt in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrv in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrvApi in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtInd in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPort in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInEthSwtContext in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInd in Config_RDR_03 */
    , 3u                                                  /**< the number of elements in EthIf_EthTrcv in Config_RDR_03 */
    , 2u                                                  /**< the number of elements in EthIf_EthTrcvDrvApi in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_EthTxQueue in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_ExplicitBufReleaseFilter in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_FloatingRxPduMap in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_GatewaySrcMacBlackList in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_LegacyWakeupMap in Config_RDR_03 */
    , 2u                                                  /**< the number of elements in EthIf_LinkStateChgIndications in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionRxEthCtrl in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionTxEthCtrl in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorDest in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorTxInfo in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerInitElems in Config_RDR_03 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerModeElems in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroup in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroupInd in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_PortMode in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_RequestedPortMode in Config_RDR_03 */
    , 3u                                                  /**< the number of elements in EthIf_RxIndications in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_RxPdu in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduFrameType in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduMetaData in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_RxQueueList in Config_RDR_03 */
    , 2u                                                  /**< the number of elements in EthIf_TxConfirmations in Config_RDR_03 */
    , 100u                                                /**< the number of elements in EthIf_TxContext in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_TxPdu in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_TxQueueList in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupMap in Config_RDR_03 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupSrcDevice in Config_RDR_03 */
  },
  { /* Index: 1 Keys: [Config_RDR_02, Config_RDR_04, Config_RDR_05, Config_RDR_06, Config_RDR_07, Config_RDR_08] */
      NULL_PTR                                            /**< the pointer to EthIf_DedicatedRxPduNextFreePos in Config_RDR_02 */
    , EthIf_EcucPartition                                 /**< the pointer to EthIf_EcucPartition in Config_RDR_02 */
    , EthIf_EthCtrl                                       /**< the pointer to EthIf_EthCtrl in Config_RDR_02 */
    , EthIf_EthCtrlInitCnt                                /**< the pointer to EthIf_EthCtrlInitCnt in Config_RDR_02 */
    , EthIf_EthCtrlModeCnt                                /**< the pointer to EthIf_EthCtrlModeCnt in Config_RDR_02 */
    , EthIf_EthCtrlState                                  /**< the pointer to EthIf_EthCtrlState in Config_RDR_02 */
    , EthIf_EthDrvApi                                     /**< the pointer to EthIf_EthDrvApi in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfClkUnit in Config_RDR_02 */
    , (&(EthIf_EthIfControllerModeChangeReqCnt))          /**< the pointer to EthIf_EthIfControllerModeChangeReqCnt in Config_RDR_02 */
    , EthIf_EthIfCtrl                                     /**< the pointer to EthIf_EthIfCtrl in Config_RDR_02 */
    , EthIf_EthIfCtrlInitState                            /**< the pointer to EthIf_EthIfCtrlInitState in Config_RDR_02 */
    , EthIf_EthIfCtrlLinkCount                            /**< the pointer to EthIf_EthIfCtrlLinkCount in Config_RDR_02 */
    , EthIf_EthIfCtrlLinkState                            /**< the pointer to EthIf_EthIfCtrlLinkState in Config_RDR_02 */
    , EthIf_EthIfCtrlMode                                 /**< the pointer to EthIf_EthIfCtrlMode in Config_RDR_02 */
    , EthIf_EthIfCtrlOfEthTrcvInd                         /**< the pointer to EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_02 */
    , EthIf_EthIfCtrlRxStats                              /**< the pointer to EthIf_EthIfCtrlRxStats in Config_RDR_02 */
    , EthIf_EthIfCtrlToEtherTypeMap                       /**< the pointer to EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlToRxPduMap in Config_RDR_02 */
    , EthIf_EthIfCtrlTxStats                              /**< the pointer to EthIf_EthIfCtrlTxStats in Config_RDR_02 */
    , EthIf_EthIfMeasurementData                          /**< the pointer to EthIf_EthIfMeasurementData in Config_RDR_02 */
    , EthIf_EthIfPhysCtrlCfg                              /**< the pointer to EthIf_EthIfPhysCtrlCfg in Config_RDR_02 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter  /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter in Config_RDR_02 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerState    /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayState in Config_RDR_02 */
    , (&(EthIf_EthIfSwitchOffPortTimeDelayReqCnt))        /**< the pointer to EthIf_EthIfSwitchOffPortTimeDelayReqCnt in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortTimerDelayState in Config_RDR_02 */
    , EthIf_EthIfSwtPortGroupState                        /**< the pointer to EthIf_EthIfSwtPortGroupState in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthRxQueue in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwt in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrv in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrvApi in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInd in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInitCnt in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPort in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInEthSwtContext in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInd in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortLinkState in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortModeCnt in Config_RDR_02 */
    , EthIf_EthTrcvRDR_02                                 /**< the pointer to EthIf_EthTrcv in Config_RDR_02 */
    , EthIf_EthTrcvDrvApi                                 /**< the pointer to EthIf_EthTrcvDrvApi in Config_RDR_02 */
    , EthIf_EthTrcvInitCnt                                /**< the pointer to EthIf_EthTrcvInitCnt in Config_RDR_02 */
    , EthIf_EthTrcvLinkState                              /**< the pointer to EthIf_EthTrcvLinkState in Config_RDR_02 */
    , EthIf_EthTrcvMode                                   /**< the pointer to EthIf_EthTrcvMode in Config_RDR_02 */
    , EthIf_EthTrcvModeChangeRetryCounter                 /**< the pointer to EthIf_EthTrcvModeChangeRetryCounter in Config_RDR_02 */
    , EthIf_EthTrcvModeChangeRetryPeriodCounter           /**< the pointer to EthIf_EthTrcvModeChangeRetryPeriodCounter in Config_RDR_02 */
    , EthIf_EthTrcvModeCnt                                /**< the pointer to EthIf_EthTrcvModeCnt in Config_RDR_02 */
    , EthIf_EthTrcvState                                  /**< the pointer to EthIf_EthTrcvState in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthTxQueue in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_ExplicitBufReleaseFilter in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduMap in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduNextFreePos in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_GatewaySrcMacBlackList in Config_RDR_02 */
    , (&(EthIf_GlobalStartupActiveTimerActive))           /**< the pointer to EthIf_GlobalStartupActiveTimerActive in Config_RDR_02 */
    , (&(EthIf_InitLocked))                               /**< the pointer to EthIf_InitLocked in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_LegacyWakeupMap in Config_RDR_02 */
    , EthIf_LinkStateChgIndications                       /**< the pointer to EthIf_LinkStateChgIndications in Config_RDR_02 */
    , (&(EthIf_MainFuncStateDecoupleFreqCnt))             /**< the pointer to EthIf_MainFuncStateDecoupleFreqCnt in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionRxEthCtrl in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionTxEthCtrl in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorDest in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorTxInfo in Config_RDR_02 */
    , (&(EthIf_ModeChangeLocked))                         /**< the pointer to EthIf_ModeChangeLocked in Config_RDR_02 */
    , EthIf_PhysLayerInitElemsRDR_02                      /**< the pointer to EthIf_PhysLayerInitElems in Config_RDR_02 */
    , EthIf_PhysLayerModeElemsRDR_02                      /**< the pointer to EthIf_PhysLayerModeElems in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroup in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupInd in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupLinkState in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupMode in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupNoRoleLinkCount in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupStartupActiveTimerActive in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortMode in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortSignalQualityResult in Config_RDR_02 */
    , (&(EthIf_PortStartupActiveTimeCounter))             /**< the pointer to EthIf_PortStartupActiveTimeCounter in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortStartupActiveTimerActive in Config_RDR_02 */
    , EthIf_RequestedEthIfCtrlMode                        /**< the pointer to EthIf_RequestedEthIfCtrlMode in Config_RDR_02 */
    , EthIf_RequestedEthTrcvMode                          /**< the pointer to EthIf_RequestedEthTrcvMode in Config_RDR_02 */
    , EthIf_RequestedEthTrcvStateOfEthIfCtrl              /**< the pointer to EthIf_RequestedEthTrcvStateOfEthIfCtrl in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortGroupMode in Config_RDR_02 */
    , EthIf_RequestedPortGroupStateOfEthIfCtrl            /**< the pointer to EthIf_RequestedPortGroupStateOfEthIfCtrl in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortMode in Config_RDR_02 */
    , EthIf_RxIndications                                 /**< the pointer to EthIf_RxIndications in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPdu in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduContext in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFrameType in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFreeList in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduMetaData in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxQueueList in Config_RDR_02 */
    , (&(EthIf_SignalQualityDecoupleFreqCnt))             /**< the pointer to EthIf_SignalQualityDecoupleFreqCnt in Config_RDR_02 */
    , EthIf_SignalQualityResult                           /**< the pointer to EthIf_SignalQualityResult in Config_RDR_02 */
    , EthIf_SrcMacAddrBuffer                              /**< the pointer to EthIf_SrcMacAddrBuffer in Config_RDR_02 */
    , (&(EthIf_SwtPortGroupModeChangeReqCnt))             /**< the pointer to EthIf_SwtPortGroupModeChangeReqCnt in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryCounter in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryPeriodCounter in Config_RDR_02 */
    , EthIf_TxConfirmations                               /**< the pointer to EthIf_TxConfirmations in Config_RDR_02 */
    , EthIf_TxContext.raw                                 /**< the pointer to EthIf_TxContext in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPdu in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPduContext in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxQueueList in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupMap in Config_RDR_02 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupSrcDevice in Config_RDR_02 */
    , 1000u
    , 0u
    , 0u
    , 5u
    , 2u
    , 5u
    , 100u
    , 100u
    , 0u
    , 1u                                                  /**< the number of elements in EthIf_EcucPartition in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthCtrl in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthDrvApi in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfClkUnit in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrl in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_02 */
    , 3u                                                  /**< the number of elements in EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlToRxPduMap in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfMeasurementData in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfPhysCtrlCfg in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthRxQueue in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwt in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrv in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrvApi in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtInd in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPort in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInEthSwtContext in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInd in Config_RDR_02 */
    , 3u                                                  /**< the number of elements in EthIf_EthTrcv in Config_RDR_02 */
    , 2u                                                  /**< the number of elements in EthIf_EthTrcvDrvApi in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_EthTxQueue in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_ExplicitBufReleaseFilter in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_FloatingRxPduMap in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_GatewaySrcMacBlackList in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_LegacyWakeupMap in Config_RDR_02 */
    , 2u                                                  /**< the number of elements in EthIf_LinkStateChgIndications in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionRxEthCtrl in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionTxEthCtrl in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorDest in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorTxInfo in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerInitElems in Config_RDR_02 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerModeElems in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroup in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroupInd in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_PortMode in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_RequestedPortMode in Config_RDR_02 */
    , 3u                                                  /**< the number of elements in EthIf_RxIndications in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_RxPdu in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduFrameType in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduMetaData in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_RxQueueList in Config_RDR_02 */
    , 2u                                                  /**< the number of elements in EthIf_TxConfirmations in Config_RDR_02 */
    , 100u                                                /**< the number of elements in EthIf_TxContext in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_TxPdu in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_TxQueueList in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupMap in Config_RDR_02 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupSrcDevice in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_01] */
      NULL_PTR                                            /**< the pointer to EthIf_DedicatedRxPduNextFreePos in Config_RDR_01 */
    , EthIf_EcucPartition                                 /**< the pointer to EthIf_EcucPartition in Config_RDR_01 */
    , EthIf_EthCtrl                                       /**< the pointer to EthIf_EthCtrl in Config_RDR_01 */
    , EthIf_EthCtrlInitCnt                                /**< the pointer to EthIf_EthCtrlInitCnt in Config_RDR_01 */
    , EthIf_EthCtrlModeCnt                                /**< the pointer to EthIf_EthCtrlModeCnt in Config_RDR_01 */
    , EthIf_EthCtrlState                                  /**< the pointer to EthIf_EthCtrlState in Config_RDR_01 */
    , EthIf_EthDrvApi                                     /**< the pointer to EthIf_EthDrvApi in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfClkUnit in Config_RDR_01 */
    , (&(EthIf_EthIfControllerModeChangeReqCnt))          /**< the pointer to EthIf_EthIfControllerModeChangeReqCnt in Config_RDR_01 */
    , EthIf_EthIfCtrl                                     /**< the pointer to EthIf_EthIfCtrl in Config_RDR_01 */
    , EthIf_EthIfCtrlInitState                            /**< the pointer to EthIf_EthIfCtrlInitState in Config_RDR_01 */
    , EthIf_EthIfCtrlLinkCount                            /**< the pointer to EthIf_EthIfCtrlLinkCount in Config_RDR_01 */
    , EthIf_EthIfCtrlLinkState                            /**< the pointer to EthIf_EthIfCtrlLinkState in Config_RDR_01 */
    , EthIf_EthIfCtrlMode                                 /**< the pointer to EthIf_EthIfCtrlMode in Config_RDR_01 */
    , EthIf_EthIfCtrlOfEthTrcvInd                         /**< the pointer to EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_01 */
    , EthIf_EthIfCtrlRxStats                              /**< the pointer to EthIf_EthIfCtrlRxStats in Config_RDR_01 */
    , EthIf_EthIfCtrlToEtherTypeMap                       /**< the pointer to EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfCtrlToRxPduMap in Config_RDR_01 */
    , EthIf_EthIfCtrlTxStats                              /**< the pointer to EthIf_EthIfCtrlTxStats in Config_RDR_01 */
    , EthIf_EthIfMeasurementData                          /**< the pointer to EthIf_EthIfMeasurementData in Config_RDR_01 */
    , EthIf_EthIfPhysCtrlCfg                              /**< the pointer to EthIf_EthIfPhysCtrlCfg in Config_RDR_01 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter  /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerCounter in Config_RDR_01 */
    , EthIf_EthIfQualifiedUnexpectedLinkDownTimerState    /**< the pointer to EthIf_EthIfQualifiedUnexpectedLinkDownTimerState in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayCounter in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortGroupTimerDelayState in Config_RDR_01 */
    , (&(EthIf_EthIfSwitchOffPortTimeDelayReqCnt))        /**< the pointer to EthIf_EthIfSwitchOffPortTimeDelayReqCnt in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthIfSwitchOffPortTimerDelayState in Config_RDR_01 */
    , EthIf_EthIfSwtPortGroupState                        /**< the pointer to EthIf_EthIfSwtPortGroupState in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthRxQueue in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwt in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrv in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtDrvApi in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInd in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtInitCnt in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPort in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInEthSwtContext in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortInd in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortLinkState in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthSwtPortModeCnt in Config_RDR_01 */
    , EthIf_EthTrcvRDR_01                                 /**< the pointer to EthIf_EthTrcv in Config_RDR_01 */
    , EthIf_EthTrcvDrvApi                                 /**< the pointer to EthIf_EthTrcvDrvApi in Config_RDR_01 */
    , EthIf_EthTrcvInitCnt                                /**< the pointer to EthIf_EthTrcvInitCnt in Config_RDR_01 */
    , EthIf_EthTrcvLinkState                              /**< the pointer to EthIf_EthTrcvLinkState in Config_RDR_01 */
    , EthIf_EthTrcvMode                                   /**< the pointer to EthIf_EthTrcvMode in Config_RDR_01 */
    , EthIf_EthTrcvModeChangeRetryCounter                 /**< the pointer to EthIf_EthTrcvModeChangeRetryCounter in Config_RDR_01 */
    , EthIf_EthTrcvModeChangeRetryPeriodCounter           /**< the pointer to EthIf_EthTrcvModeChangeRetryPeriodCounter in Config_RDR_01 */
    , EthIf_EthTrcvModeCnt                                /**< the pointer to EthIf_EthTrcvModeCnt in Config_RDR_01 */
    , EthIf_EthTrcvState                                  /**< the pointer to EthIf_EthTrcvState in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_EthTxQueue in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_ExplicitBufReleaseFilter in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduMap in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_FloatingRxPduNextFreePos in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_GatewaySrcMacBlackList in Config_RDR_01 */
    , (&(EthIf_GlobalStartupActiveTimerActive))           /**< the pointer to EthIf_GlobalStartupActiveTimerActive in Config_RDR_01 */
    , (&(EthIf_InitLocked))                               /**< the pointer to EthIf_InitLocked in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_LegacyWakeupMap in Config_RDR_01 */
    , EthIf_LinkStateChgIndications                       /**< the pointer to EthIf_LinkStateChgIndications in Config_RDR_01 */
    , (&(EthIf_MainFuncStateDecoupleFreqCnt))             /**< the pointer to EthIf_MainFuncStateDecoupleFreqCnt in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionRxEthCtrl in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_MainPartitionTxEthCtrl in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorDest in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_MirrorTxInfo in Config_RDR_01 */
    , (&(EthIf_ModeChangeLocked))                         /**< the pointer to EthIf_ModeChangeLocked in Config_RDR_01 */
    , EthIf_PhysLayerInitElemsRDR_01                      /**< the pointer to EthIf_PhysLayerInitElems in Config_RDR_01 */
    , EthIf_PhysLayerModeElemsRDR_01                      /**< the pointer to EthIf_PhysLayerModeElems in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroup in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupHostOrUpLinkPortRoleLinkCount in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupInd in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupLinkState in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupMode in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupNoRoleLinkCount in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortGroupStartupActiveTimerActive in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortMode in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortSignalQualityResult in Config_RDR_01 */
    , (&(EthIf_PortStartupActiveTimeCounter))             /**< the pointer to EthIf_PortStartupActiveTimeCounter in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_PortStartupActiveTimerActive in Config_RDR_01 */
    , EthIf_RequestedEthIfCtrlMode                        /**< the pointer to EthIf_RequestedEthIfCtrlMode in Config_RDR_01 */
    , EthIf_RequestedEthTrcvMode                          /**< the pointer to EthIf_RequestedEthTrcvMode in Config_RDR_01 */
    , EthIf_RequestedEthTrcvStateOfEthIfCtrl              /**< the pointer to EthIf_RequestedEthTrcvStateOfEthIfCtrl in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortGroupMode in Config_RDR_01 */
    , EthIf_RequestedPortGroupStateOfEthIfCtrl            /**< the pointer to EthIf_RequestedPortGroupStateOfEthIfCtrl in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RequestedPortMode in Config_RDR_01 */
    , EthIf_RxIndications                                 /**< the pointer to EthIf_RxIndications in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPdu in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduContext in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFrameType in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduFreeList in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxPduMetaData in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_RxQueueList in Config_RDR_01 */
    , (&(EthIf_SignalQualityDecoupleFreqCnt))             /**< the pointer to EthIf_SignalQualityDecoupleFreqCnt in Config_RDR_01 */
    , EthIf_SignalQualityResult                           /**< the pointer to EthIf_SignalQualityResult in Config_RDR_01 */
    , EthIf_SrcMacAddrBuffer                              /**< the pointer to EthIf_SrcMacAddrBuffer in Config_RDR_01 */
    , (&(EthIf_SwtPortGroupModeChangeReqCnt))             /**< the pointer to EthIf_SwtPortGroupModeChangeReqCnt in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryCounter in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_SwtPortGroupModeChangeRetryPeriodCounter in Config_RDR_01 */
    , EthIf_TxConfirmations                               /**< the pointer to EthIf_TxConfirmations in Config_RDR_01 */
    , EthIf_TxContext.raw                                 /**< the pointer to EthIf_TxContext in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPdu in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxPduContext in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_TxQueueList in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupMap in Config_RDR_01 */
    , NULL_PTR                                            /**< the pointer to EthIf_WakeupSrcDevice in Config_RDR_01 */
    , 1000u
    , 0u
    , 0u
    , 5u
    , 2u
    , 5u
    , 100u
    , 100u
    , 0u
    , 1u                                                  /**< the number of elements in EthIf_EcucPartition in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthCtrl in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthDrvApi in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfClkUnit in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrl in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfCtrlOfEthTrcvInd in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlOfPortGroupInd in Config_RDR_01 */
    , 3u                                                  /**< the number of elements in EthIf_EthIfCtrlToEtherTypeMap in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthIfCtrlToRxPduMap in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfMeasurementData in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_EthIfPhysCtrlCfg in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthRxQueue in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwt in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrv in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtDrvApi in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtInd in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPort in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInEthSwtContext in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthSwtPortInd in Config_RDR_01 */
    , 3u                                                  /**< the number of elements in EthIf_EthTrcv in Config_RDR_01 */
    , 2u                                                  /**< the number of elements in EthIf_EthTrcvDrvApi in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_EthTxQueue in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_ExplicitBufReleaseFilter in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_FloatingRxPduMap in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_GatewaySrcMacBlackList in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_LegacyWakeupMap in Config_RDR_01 */
    , 2u                                                  /**< the number of elements in EthIf_LinkStateChgIndications in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionRxEthCtrl in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_MainPartitionTxEthCtrl in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorDest in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_MirrorTxInfo in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerInitElems in Config_RDR_01 */
    , 1u                                                  /**< the number of elements in EthIf_PhysLayerModeElems in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroup in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_PortGroupInd in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_PortMode in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_RequestedPortMode in Config_RDR_01 */
    , 3u                                                  /**< the number of elements in EthIf_RxIndications in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_RxPdu in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduFrameType in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_RxPduMetaData in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_RxQueueList in Config_RDR_01 */
    , 2u                                                  /**< the number of elements in EthIf_TxConfirmations in Config_RDR_01 */
    , 100u                                                /**< the number of elements in EthIf_TxContext in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_TxPdu in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_TxQueueList in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupMap in Config_RDR_01 */
    , 0u                                                  /**< the number of elements in EthIf_WakeupSrcDevice in Config_RDR_01 */
  }
};
#define ETHIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/

/**********************************************************************************************************************
  EthIf_ConfigDataPtr
**********************************************************************************************************************/
/**
  \var    EthIf_ConfigDataPtr
  \brief  Points to the currently active configuration for EthIf
*/
#define ETHIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
P2CONST(EthIf_ConfigType, ETHIF_VAR_NO_INIT, ETHIF_INIT_DATA) EthIf_ConfigDataPtr;
#define ETHIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_Lcfg.c
 *********************************************************************************************************************/


