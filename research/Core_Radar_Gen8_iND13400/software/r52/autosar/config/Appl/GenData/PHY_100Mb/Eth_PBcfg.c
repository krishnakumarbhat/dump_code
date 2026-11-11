/*===========================================================================*//**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference EthCtrlConfigEgressLastSchedulerRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Eth_Indie/EthConfigSet/RADAR_EthConnector1_Controller_bbe781c0/EthCtrlConfigEgress[0:EthCtrlConfigEgressLastSchedulerRef](value={empty}) (DefRef: /indieSemi/Eth/EthConfigSet/EthCtrlConfig/EthCtrlConfigEgress/EthCtrlConfigEgressLastSchedulerRef)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/** 
 * @file Eth_PBcfg.c
 * Eth PBcfg source
 *
 * @date    Date created:   09-01-2026
  * 
 * @details 
 * ### Full description
 * Ethernet post-build configuration source file
 * 
 * ### Traceability info
 * + **Design documents:**
 *     + Specification of Ethernet Driver AUTOSAR CP Release 4.4.0
 * 
 * + **Requirements document:**
 *     + Requirements on Ethernet Support in AUTOSAR CP Release 4.4.0
 *
 * 
 * + **Applicable standards:**
 *     + Autosar 4.4.0
 * 
 * + **Deviations from standards:**
 *     + None
 * 
 * @copyright (c) indie Semiconductor 2023-2024. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary. 
 *
 *  ---- AUTOGENERATED FILE - DO NOT EDIT! ---- 
 *
 */
/*===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Eth.h"
#include "Eth_PBcfg.h"

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/


/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/
 
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

CONST(Eth_ConfigType, ETH_VAR) Eth_Config;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

STATIC CONST(EthCtrlConfigSchedulerPredecessorType, ETH_CODE) CfgPredecessorOrderListSch0[ETH_CFG_ETHCTRLCONFIGPREDECTOTAL_SCH0]= {
    {
        ._PredecessorOrder = 0
    },
};


STATIC CONST(EthCtrlConfigSchedulerType, ETH_CODE) SchedulerLists[ETH_CFG_ETHCTRLCONFIGSCHEDULERTOTAL] = {
    {
        ._PredecessorList = CfgPredecessorOrderListSch0
    },
};


/* Array Size will be 1 when empty assignation with assigned Queue as 0 */
STATIC CONST(uint16, ETH_CODE) EthCtrlConfigEgressFifoPriorityAssignment_Q0[3]= {
        0 ,
        1 ,
        2 
};

STATIC CONST(EthCtrlConfigEgressFifoType, ETH_CODE) EgressFifoList[1] = {
    {
        .EthCtrlConfigEgressFifoBufLenByte = 1522u,
        .EthCtrlConfigEgressFifoBufTotal = 100u,
        .EthCtrlConfigEgressFifoPriorityAssignmentListSize=3u,
        .EthCtrlConfigEgressFifoPriorityAssignment=EthCtrlConfigEgressFifoPriorityAssignment_Q0,
        .EthCtrlConfigEgressFifoIdx = 0,
    },
};



/**
 * @brief Mapping table from Ethernet traffic priority to Tx queue index.
 *
 * This lookup table maps Ethernet frame priority values (0?7) to
 * hardware-specific DMA Tx queue indices. This is used to direct frames
 * with different priorities to different queues for QoS handling.
 */

STATIC CONST(EthCtrlConfigEgressQueueTransmissionSelectionType, ETH_CODE) EthCtrlConfigEgressQueueTransmissionSelection = {
    .EthCtrlConfigEgressQueueTransmissionSelectionAlgorithm = ETH_TRANSMISSION_SELECTION_UNSHAPED,
    .EthCtrlConfigEgressQueueTransmissionSelectionCBSConfig = NULL_PTR
};


STATIC CONST(EthCtrlConfigEgressQueueType, ETH_CODE) EgressQueueList[1] = {
    {
        .EthCtrlConfigEgressQueueBufLenByte = 1522u,
        .EthCtrlConfigEgressQueueBufTotal = 100u,
        .EthCtrlConfigEgressQueueIdx = 0,
        .EthCtrlConfigEgressQueueTransmissionSelection = &EthCtrlConfigEgressQueueTransmissionSelection
    },
};


CONST(EthCtrlConfigEgressType, ETH_CODE) Eth_CtrlCfgEgress = 
{
    .EgressFifoListSize = 1u,
    ._EgressFifoList = &EgressFifoList[0],
    ._EgressQueueList = &EgressQueueList[0],
    ._SchedulerList = &SchedulerLists[0],
    ._ConfigShaperList = NULL_PTR
};


CONST(EthCtrlOffloadingType, ETH_CODE) Eth_CtrlOffloading = {
    .bf.ICMP = 1u,
    .bf.IPV4 = 1u,
    .bf.TCP =  1u,
    .bf.UDP =  1u,
    .bf.RFU =  0u
};



STATIC CONST(uint16, ETH_CODE) EthCtrlConfigIngressFifoPriorityAssignment_Q0[1]={
0
};

STATIC CONST(EthCtrlConfigIngressFifoType, ETH_CODE) IngressFifoList[1] = 
{
    {
        .EthCtrlConfigIngressFifoBufLenByte = 1522u,
        .EthCtrlConfigIngressFifoBufTotal = 2u,
        .EthCtrlConfigIngressFifoPriorityAssignment = EthCtrlConfigIngressFifoPriorityAssignment_Q0 ,
        .EthCtrlConfigIngressFifoPriorityAssignmentListSize=0u,
        .EthCtrlConfigIngressFifoIdx = 0,
    },
};


CONST(EthCtrlConfigIngressType, ETH_CODE) Eth_CtrlCfgIngress = {
    .IngressFifoListSize = 1u,
    ._IngressFifoList = IngressFifoList
};


/* ================= Single Variant Configuration ================= */
CONST(Eth_ConfigType, ETH_CODE) Eth_Config = {
    .CtrlMacLayerSpeed = ETH_MAC_LAYER_SPEED_100M,
    .phyAddress = {0x00,0x1A,0xA0,0x22,0x0E,0xB0},
    ._CtrlCfgEgress =  &Eth_CtrlCfgEgress,
    ._CtrlCfgIngress = &Eth_CtrlCfgIngress,
    ._CtrlCfgOffload = &Eth_CtrlOffloading
};

#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"


