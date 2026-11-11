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
 *            Module: CanIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Cfg.h
 *   Generation Time: 2026-09-10 14:58:59
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
 * [Warning] CANIF10063 - The configured X-ID (X: CAN, MASK, Upper-CAN or Lower-CAN) of a Rx-PDU is invalid. 
 * - [Reduced Severity due to User-Defined Parameter] According to value of "CanIfRxPduCanIdType" the maximum possible value for "CanIfRxPduCanId" is: "0x7ff".
 * Erroneous configuration elements:
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx[0:CanIfRxPduCanId](value=417002673) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfRxPduCfg/CanIfRxPduCanId)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx[0:CanIfRxPduCanIdType]{RDR_01}(value=STANDARD_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfRxPduCfg/CanIfRxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_1d0fb5b4_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_79efce4a_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_ebda6543_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_a38832c1_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_697bc1d9_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_0d9bba27_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2e7c92c0_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 * 
 * [Warning] CANIF10073 - Parameter has a wrong value. 
 * - [Reduced Severity due to User-Defined Parameter] The selected "CanIfTxPduCanIdType" of Tx PDU: "SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx" supports max. "PduLength" = 8.
 * Erroneous configuration elements:
 * /ActiveEcuC/EcuC/EcucPduCollection/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_90ff5b50_Tx[0:PduLength](value=64) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/CanIf/CanIfInitCfg/SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx[0:CanIfTxPduCanIdType](value=EXTENDED_CAN) (DefRef: /MICROSAR/CanIf/CanIfInitCfg/CanIfTxPduCfg/CanIfTxPduCanIdType)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/
#include "Can.h"




/**********************************************************************************************************************
  \def  Version defines
**********************************************************************************************************************/

/* Configuration major version identification. */
# define CANIF_CFG_MAJOR_VERSION 0x09u
/* Configuration minor version identification. */
# define CANIF_CFG_MINOR_VERSION 0x00u
/* Configuration patch version identification. */
# define CANIF_CFG_PATCH_VERSION 0x01u

/* Compatibility version between generated data and static code */
#define CANIF_CFG_GENERATOR_COMPATIBILITY_VERSION 0x0302u

/**********************************************************************************************************************
  \def  Switches
**********************************************************************************************************************/

#define CANIF_TRANSMIT_BUFFER                              STD_ON /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_ON
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_ON
#define CANIF_STATIC_FD_TXQUEUE                            STD_OFF
#define CANIF_WAKEUP_SUPPORT                               STD_OFF
#define CANIF_WAKEUP_VALIDATION                            STD_OFF
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_OFF
#define CANIF_CANDRV_WAKEUP_HANDLING                       STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_OFF
#define CANIF_TRANSMIT_CANCELLATION                        STD_OFF
#define CANIF_CANCEL_SUPPORT_API                           STD_OFF
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_ON
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_OFF
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_ON
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_SETDYNAMICRXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_ON
#define CANIF_META_DATA_TX_SUPPORT                         STD_ON
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_ON
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_ON
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_OFF
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF
#define CANIF_BUS_MIRRORING_SUPPORT                        STD_OFF
#define CANIF_HTH_TYPE_FIFO_IS_USED                        STD_OFF
#define CANIF_HTH_TYPE_MUX_OR_SIZEONE_IS_USED              STD_OFF
#define CANIF_ENABLE_SECURITY_EVENT_REPORTING              STD_OFF
#define CANIF_SUPPORT_MULTIPARTITION                       STD_OFF
#define CANIF_SUPPORT_CAN_XL                               STD_OFF
#define CANIF_BUSLOAD_MEASUREMENT_SUPPORT                  STD_OFF

#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANIF_PROCESSOR_IND13400
#define CANIF_PROCESSOR_IND13400
#endif
#ifndef CANIF_COMP_LLVMDIAB
#define CANIF_COMP_LLVMDIAB
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32

/**********************************************************************************************************************
  \def  CAN Driver equivalence classes
**********************************************************************************************************************/
#define CANIF_SUPPORT_CANDRV_EQC_MSRC                      STD_OFF
#define CANIF_SUPPORT_CANDRV_EQC_AR_403                    STD_OFF
#define CANIF_SUPPORT_CANDRV_EQC_AR_421                    STD_OFF
#define CANIF_SUPPORT_CANDRV_EQC_AR_431                    STD_ON
#define CANIF_SUPPORT_CANDRV_EQC_AR_431_OR_MSRC            STD_ON
#define CANIF_SUPPORT_CANDRV_EQC_AR_403_OR_AR_421          STD_OFF
#define CANIF_SUPPORT_CANDRV_EQC_AR_403_OR_AR_421_OR_MSRC  STD_OFF

/**********************************************************************************************************************
  \def  Search algorithm
**********************************************************************************************************************/
#define CANIF_SEARCH_ALGORITHM                             CANIF_LINEAR


/**********************************************************************************************************************
  \def  Configuration variant
**********************************************************************************************************************/
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME


/**********************************************************************************************************************
  Type definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  \def  Tx-buffer - queue size type
**********************************************************************************************************************/
typedef uint8 CanIf_TxBufferSizeType;


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
#include "CanIf_Types.h"

/**********************************************************************************************************************
  \def  Memory mapping keywords
**********************************************************************************************************************/
#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT


/**********************************************************************************************************************
  \def  Invalid PDU handle
**********************************************************************************************************************/
#define CanIf_TxPduHnd_INVALID                             0xFFFFu
#define CanIf_RxPduHnd_INVALID                             0xFFFFu


/**********************************************************************************************************************
  \def  Tx-buffer - handling types
**********************************************************************************************************************/
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u



/**********************************************************************************************************************
  \def  CAN controller - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfCtrlCfg_CT_VCAN_RADAR_a3a0f56c                                               0u
#define CanIfConf_CanIfCtrlCfg_CT_PCAN_RADAR_a3a0f56c                                               1u








/**********************************************************************************************************************
  \def  Tx PDU handles
**********************************************************************************************************************/

#define CanIfTxPduHnd_BSD1_oVCAN_RADAR_64acbe01_Tx                                                  0u
#define CanIfTxPduHnd_DM1_B0_oVCAN_RADAR_8817cb52_Tx                                                1u
#define CanIfTxPduHnd_DM1_B1_oVCAN_RADAR_c2a11718_Tx                                                2u
#define CanIfTxPduHnd_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx                               3u
#define CanIfTxPduHnd_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx                               4u
#define CanIfTxPduHnd_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx                                5u
#define CanIfTxPduHnd_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx                              6u
#define CanIfTxPduHnd_GW_ADAS_FN_Enable_disable_sts_Tx_oPCAN_RADAR_b3ed1cbc_Tx                      7u
#define CanIfTxPduHnd_GW_CCVS1_Tx_oPCAN_RADAR_de02a585_Tx                                           8u
#define CanIfTxPduHnd_GW_CLS_Tx_4_Tx_oPCAN_RADAR_33bc88fd_Tx                                        9u
#define CanIfTxPduHnd_GW_CLS_Tx_16_Tx_oPCAN_RADAR_9dad2921_Tx                                       10u
#define CanIfTxPduHnd_GW_ETC2_03_Tx_oPCAN_RADAR_6fe44ee0_Tx                                         11u
#define CanIfTxPduHnd_GW_ETC2_Tx_oPCAN_RADAR_5963dc30_Tx                                            12u
#define CanIfTxPduHnd_GW_OEL_Tx_oPCAN_RADAR_a8245947_Tx                                             13u
#define CanIfTxPduHnd_GW_SAS_Tx_oPCAN_RADAR_2217d6e9_Tx                                             14u
#define CanIfTxPduHnd_GW_TD_Tx_oPCAN_RADAR_2f7068b5_Tx                                              15u
#define CanIfTxPduHnd_GW_VDC2_Tx_oPCAN_RADAR_f54084fa_Tx                                            16u
#define CanIfTxPduHnd_GW_VD_Tx_oPCAN_RADAR_56fb68b9_Tx                                              17u
#define CanIfTxPduHnd_GW_VI_Tx_oPCAN_RADAR_ba7d49ea_Tx                                              18u
#define CanIfTxPduHnd_GW_prop_ADAS_BSIS_info_oPCAN_RADAR_14d3ec96_Tx                                19u
#define CanIfTxPduHnd_MOIS_oVCAN_RADAR_edd3b80a_Tx                                                  20u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx                           21u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx                        22u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx                        23u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx                           24u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx                         25u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx                            26u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx                          27u
#define CanIfTxPduHnd_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx                       28u
#define CanIfTxPduHnd_RDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_caaee0a2_Tx                              29u
#define CanIfTxPduHnd_RDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_899d4639_Tx                              30u
#define CanIfTxPduHnd_RDR_BSD1_Tx_oPCAN_RADAR_ec8026a7_Tx                                           31u
#define CanIfTxPduHnd_RDR_CAPABILITY_oPCAN_RADAR_834d4809_Tx                                        32u
#define CanIfTxPduHnd_RDR_DETECTION_001_004_oPCAN_RADAR_456a1641_Tx                                 33u
#define CanIfTxPduHnd_RDR_DETECTION_005_008_oPCAN_RADAR_907c961b_Tx                                 34u
#define CanIfTxPduHnd_RDR_DETECTION_009_012_oPCAN_RADAR_83a4abae_Tx                                 35u
#define CanIfTxPduHnd_RDR_DETECTION_013_016_oPCAN_RADAR_897f6817_Tx                                 36u
#define CanIfTxPduHnd_RDR_DETECTION_017_020_oPCAN_RADAR_94d1abf5_Tx                                 37u
#define CanIfTxPduHnd_RDR_DETECTION_021_024_oPCAN_RADAR_35f4b8e7_Tx                                 38u
#define CanIfTxPduHnd_RDR_DETECTION_025_028_oPCAN_RADAR_e0e238bd_Tx                                 39u
#define CanIfTxPduHnd_RDR_DETECTION_029_032_oPCAN_RADAR_f33a0508_Tx                                 40u
#define CanIfTxPduHnd_RDR_DETECTION_033_036_oPCAN_RADAR_f9e1c6b1_Tx                                 41u
#define CanIfTxPduHnd_RDR_DETECTION_037_040_oPCAN_RADAR_d1647cc0_Tx                                 42u
#define CanIfTxPduHnd_RDR_DETECTION_041_044_oPCAN_RADAR_a4574b0d_Tx                                 43u
#define CanIfTxPduHnd_RDR_DETECTION_045_048_oPCAN_RADAR_7141cb57_Tx                                 44u
#define CanIfTxPduHnd_RDR_DETECTION_049_052_oPCAN_RADAR_6299f6e2_Tx                                 45u
#define CanIfTxPduHnd_RDR_DETECTION_053_056_oPCAN_RADAR_6842355b_Tx                                 46u
#define CanIfTxPduHnd_RDR_DETECTION_057_060_oPCAN_RADAR_75ecf6b9_Tx                                 47u
#define CanIfTxPduHnd_RDR_DETECTION_061_064_oPCAN_RADAR_d4c9e5ab_Tx                                 48u
#define CanIfTxPduHnd_RDR_DETECTION_065_068_oPCAN_RADAR_01df65f1_Tx                                 49u
#define CanIfTxPduHnd_RDR_DETECTION_069_072_oPCAN_RADAR_12075844_Tx                                 50u
#define CanIfTxPduHnd_RDR_DETECTION_073_076_oPCAN_RADAR_18dc9bfd_Tx                                 51u
#define CanIfTxPduHnd_RDR_DETECTION_077_080_oPCAN_RADAR_5a0fd2aa_Tx                                 52u
#define CanIfTxPduHnd_RDR_DETECTION_081_084_oPCAN_RADAR_5c61aa98_Tx                                 53u
#define CanIfTxPduHnd_RDR_DETECTION_085_088_oPCAN_RADAR_89772ac2_Tx                                 54u
#define CanIfTxPduHnd_RDR_DETECTION_089_092_oPCAN_RADAR_9aaf1777_Tx                                 55u
#define CanIfTxPduHnd_RDR_DETECTION_093_096_oPCAN_RADAR_9074d4ce_Tx                                 56u
#define CanIfTxPduHnd_RDR_DETECTION_097_100_oPCAN_RADAR_9189e332_Tx                                 57u
#define CanIfTxPduHnd_RDR_DETECTION_101_104_oPCAN_RADAR_b7305958_Tx                                 58u
#define CanIfTxPduHnd_RDR_DETECTION_105_108_oPCAN_RADAR_6226d902_Tx                                 59u
#define CanIfTxPduHnd_RDR_DETECTION_109_112_oPCAN_RADAR_71fee4b7_Tx                                 60u
#define CanIfTxPduHnd_RDR_DETECTION_113_116_oPCAN_RADAR_7b25270e_Tx                                 61u
#define CanIfTxPduHnd_RDR_DETECTION_117_120_oPCAN_RADAR_668be4ec_Tx                                 62u
#define CanIfTxPduHnd_RDR_DETECTION_121_124_oPCAN_RADAR_c7aef7fe_Tx                                 63u
#define CanIfTxPduHnd_RDR_DETECTION_125_128_oPCAN_RADAR_12b877a4_Tx                                 64u
#define CanIfTxPduHnd_RDR_DETECTION_129_132_oPCAN_RADAR_01604a11_Tx                                 65u
#define CanIfTxPduHnd_RDR_DETECTION_133_136_oPCAN_RADAR_0bbb89a8_Tx                                 66u
#define CanIfTxPduHnd_RDR_DETECTION_137_140_oPCAN_RADAR_233e33d9_Tx                                 67u
#define CanIfTxPduHnd_RDR_DETECTION_141_144_oPCAN_RADAR_560d0414_Tx                                 68u
#define CanIfTxPduHnd_RDR_DETECTION_145_148_oPCAN_RADAR_831b844e_Tx                                 69u
#define CanIfTxPduHnd_RDR_DETECTION_149_152_oPCAN_RADAR_90c3b9fb_Tx                                 70u
#define CanIfTxPduHnd_RDR_DETECTION_153_156_oPCAN_RADAR_9a187a42_Tx                                 71u
#define CanIfTxPduHnd_RDR_DETECTION_157_160_oPCAN_RADAR_87b6b9a0_Tx                                 72u
#define CanIfTxPduHnd_RDR_DETECTION_161_164_oPCAN_RADAR_2693aab2_Tx                                 73u
#define CanIfTxPduHnd_RDR_DETECTION_165_168_oPCAN_RADAR_f3852ae8_Tx                                 74u
#define CanIfTxPduHnd_RDR_DETECTION_169_172_oPCAN_RADAR_e05d175d_Tx                                 75u
#define CanIfTxPduHnd_RDR_DETECTION_173_176_oPCAN_RADAR_ea86d4e4_Tx                                 76u
#define CanIfTxPduHnd_RDR_DETECTION_177_180_oPCAN_RADAR_a8559db3_Tx                                 77u
#define CanIfTxPduHnd_RDR_DETECTION_181_184_oPCAN_RADAR_ae3be581_Tx                                 78u
#define CanIfTxPduHnd_RDR_DETECTION_185_188_oPCAN_RADAR_7b2d65db_Tx                                 79u
#define CanIfTxPduHnd_RDR_DETECTION_189_192_oPCAN_RADAR_68f5586e_Tx                                 80u
#define CanIfTxPduHnd_RDR_DETECTION_193_196_oPCAN_RADAR_622e9bd7_Tx                                 81u
#define CanIfTxPduHnd_RDR_DETECTION_197_200_oPCAN_RADAR_baf2dbc8_Tx                                 82u
#define CanIfTxPduHnd_RDR_DETECTION_201_204_oPCAN_RADAR_7aaf8e32_Tx                                 83u
#define CanIfTxPduHnd_RDR_DETECTION_205_208_oPCAN_RADAR_afb90e68_Tx                                 84u
#define CanIfTxPduHnd_RDR_DETECTION_209_212_oPCAN_RADAR_bc6133dd_Tx                                 85u
#define CanIfTxPduHnd_RDR_DETECTION_213_216_oPCAN_RADAR_b6baf064_Tx                                 86u
#define CanIfTxPduHnd_RDR_DETECTION_217_220_oPCAN_RADAR_ab143386_Tx                                 87u
#define CanIfTxPduHnd_RDR_DETECTION_221_224_oPCAN_RADAR_0a312094_Tx                                 88u
#define CanIfTxPduHnd_RDR_DETECTION_225_228_oPCAN_RADAR_df27a0ce_Tx                                 89u
#define CanIfTxPduHnd_RDR_DETECTION_229_232_oPCAN_RADAR_ccff9d7b_Tx                                 90u
#define CanIfTxPduHnd_RDR_DETECTION_233_236_oPCAN_RADAR_c6245ec2_Tx                                 91u
#define CanIfTxPduHnd_RDR_DETECTION_237_240_oPCAN_RADAR_eea1e4b3_Tx                                 92u
#define CanIfTxPduHnd_RDR_DETECTION_241_244_oPCAN_RADAR_9b92d37e_Tx                                 93u
#define CanIfTxPduHnd_RDR_DETECTION_245_248_oPCAN_RADAR_4e845324_Tx                                 94u
#define CanIfTxPduHnd_RDR_DETECTION_249_252_oPCAN_RADAR_5d5c6e91_Tx                                 95u
#define CanIfTxPduHnd_RDR_DETECTION_253_256_oPCAN_RADAR_5787ad28_Tx                                 96u
#define CanIfTxPduHnd_RDR_DETECTION_257_260_oPCAN_RADAR_4a296eca_Tx                                 97u
#define CanIfTxPduHnd_RDR_DETECTION_261_264_oPCAN_RADAR_eb0c7dd8_Tx                                 98u
#define CanIfTxPduHnd_RDR_DETECTION_265_268_oPCAN_RADAR_3e1afd82_Tx                                 99u
#define CanIfTxPduHnd_RDR_DETECTION_269_272_oPCAN_RADAR_2dc2c037_Tx                                 100u
#define CanIfTxPduHnd_RDR_DETECTION_273_276_oPCAN_RADAR_2719038e_Tx                                 101u
#define CanIfTxPduHnd_RDR_DETECTION_277_280_oPCAN_RADAR_65ca4ad9_Tx                                 102u
#define CanIfTxPduHnd_RDR_DETECTION_281_284_oPCAN_RADAR_63a432eb_Tx                                 103u
#define CanIfTxPduHnd_RDR_DETECTION_285_288_oPCAN_RADAR_b6b2b2b1_Tx                                 104u
#define CanIfTxPduHnd_RDR_DETECTION_289_292_oPCAN_RADAR_a56a8f04_Tx                                 105u
#define CanIfTxPduHnd_RDR_DETECTION_293_296_oPCAN_RADAR_afb14cbd_Tx                                 106u
#define CanIfTxPduHnd_RDR_DETECTION_297_300_oPCAN_RADAR_ae4c7b41_Tx                                 107u
#define CanIfTxPduHnd_RDR_DETECTION_301_304_oPCAN_RADAR_88f5c12b_Tx                                 108u
#define CanIfTxPduHnd_RDR_DETECTION_305_308_oPCAN_RADAR_5de34171_Tx                                 109u
#define CanIfTxPduHnd_RDR_DETECTION_309_312_oPCAN_RADAR_4e3b7cc4_Tx                                 110u
#define CanIfTxPduHnd_RDR_DETECTION_313_316_oPCAN_RADAR_44e0bf7d_Tx                                 111u
#define CanIfTxPduHnd_RDR_DETECTION_317_320_oPCAN_RADAR_594e7c9f_Tx                                 112u
#define CanIfTxPduHnd_RDR_DETECTION_321_324_oPCAN_RADAR_f86b6f8d_Tx                                 113u
#define CanIfTxPduHnd_RDR_DETECTION_325_328_oPCAN_RADAR_2d7defd7_Tx                                 114u
#define CanIfTxPduHnd_RDR_DETECTION_329_332_oPCAN_RADAR_3ea5d262_Tx                                 115u
#define CanIfTxPduHnd_RDR_DETECTION_333_336_oPCAN_RADAR_347e11db_Tx                                 116u
#define CanIfTxPduHnd_RDR_DETECTION_337_340_oPCAN_RADAR_1cfbabaa_Tx                                 117u
#define CanIfTxPduHnd_RDR_DETECTION_341_344_oPCAN_RADAR_69c89c67_Tx                                 118u
#define CanIfTxPduHnd_RDR_DETECTION_345_348_oPCAN_RADAR_bcde1c3d_Tx                                 119u
#define CanIfTxPduHnd_RDR_DETECTION_349_352_oPCAN_RADAR_af062188_Tx                                 120u
#define CanIfTxPduHnd_RDR_DETECTION_353_356_oPCAN_RADAR_a5dde231_Tx                                 121u
#define CanIfTxPduHnd_RDR_DETECTION_357_360_oPCAN_RADAR_b87321d3_Tx                                 122u
#define CanIfTxPduHnd_RDR_DETECTION_361_364_oPCAN_RADAR_195632c1_Tx                                 123u
#define CanIfTxPduHnd_RDR_DETECTION_365_368_oPCAN_RADAR_cc40b29b_Tx                                 124u
#define CanIfTxPduHnd_RDR_DETECTION_369_372_oPCAN_RADAR_df988f2e_Tx                                 125u
#define CanIfTxPduHnd_RDR_DETECTION_373_376_oPCAN_RADAR_d5434c97_Tx                                 126u
#define CanIfTxPduHnd_RDR_DETECTION_377_380_oPCAN_RADAR_979005c0_Tx                                 127u
#define CanIfTxPduHnd_RDR_DETECTION_381_384_oPCAN_RADAR_91fe7df2_Tx                                 128u
#define CanIfTxPduHnd_RDR_DETECTION_385_388_oPCAN_RADAR_44e8fda8_Tx                                 129u
#define CanIfTxPduHnd_RDR_DETECTION_389_392_oPCAN_RADAR_5730c01d_Tx                                 130u
#define CanIfTxPduHnd_RDR_DETECTION_393_396_oPCAN_RADAR_5deb03a4_Tx                                 131u
#define CanIfTxPduHnd_RDR_DETECTION_397_400_oPCAN_RADAR_ec04aa3c_Tx                                 132u
#define CanIfTxPduHnd_RDR_HEADER_001_oPCAN_RADAR_051a0060_Tx                                        133u
#define CanIfTxPduHnd_RDR_OBJ_HEADER_002_oPCAN_RADAR_0a1b3262_Tx                                    134u
#define CanIfTxPduHnd_RDR_OBJ_STATUS_003_oPCAN_RADAR_24cf7f10_Tx                                    135u
#define CanIfTxPduHnd_RDR_STATUS_001_oPCAN_RADAR_0ddc5064_Tx                                        136u
#define CanIfTxPduHnd_RDR_STATUS_002_oPCAN_RADAR_b26a35a7_Tx                                        137u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_001_oPCAN_RADAR_7d6cb36b_Tx                                   138u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_002_oPCAN_RADAR_62323590_Tx                                   139u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_003_oPCAN_RADAR_68f84839_Tx                                   140u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_004_oPCAN_RADAR_5c8f3866_Tx                                   141u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_005_oPCAN_RADAR_564545cf_Tx                                   142u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_006_oPCAN_RADAR_491bc334_Tx                                   143u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_007_oPCAN_RADAR_43d1be9d_Tx                                   144u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_008_oPCAN_RADAR_21f5238a_Tx                                   145u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_009_oPCAN_RADAR_2b3f5e23_Tx                                   146u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_010_oPCAN_RADAR_d8a61ff3_Tx                                   147u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_011_oPCAN_RADAR_d26c625a_Tx                                   148u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_012_oPCAN_RADAR_cd32e4a1_Tx                                   149u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_013_oPCAN_RADAR_c7f89908_Tx                                   150u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_014_oPCAN_RADAR_f38fe957_Tx                                   151u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_015_oPCAN_RADAR_f94594fe_Tx                                   152u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_016_oPCAN_RADAR_e61b1205_Tx                                   153u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_017_oPCAN_RADAR_ecd16fac_Tx                                   154u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_018_oPCAN_RADAR_8ef5f2bb_Tx                                   155u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_019_oPCAN_RADAR_843f8f12_Tx                                   156u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_020_oPCAN_RADAR_f2d66ae1_Tx                                   157u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_021_oPCAN_RADAR_f81c1748_Tx                                   158u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_022_oPCAN_RADAR_e74291b3_Tx                                   159u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_023_oPCAN_RADAR_ed88ec1a_Tx                                   160u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_024_oPCAN_RADAR_d9ff9c45_Tx                                   161u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_025_oPCAN_RADAR_d335e1ec_Tx                                   162u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_026_oPCAN_RADAR_cc6b6717_Tx                                   163u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_027_oPCAN_RADAR_c6a11abe_Tx                                   164u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_028_oPCAN_RADAR_a48587a9_Tx                                   165u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_029_oPCAN_RADAR_ae4ffa00_Tx                                   166u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_030_oPCAN_RADAR_5dd6bbd0_Tx                                   167u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_031_oPCAN_RADAR_571cc679_Tx                                   168u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_032_oPCAN_RADAR_48424082_Tx                                   169u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_033_oPCAN_RADAR_42883d2b_Tx                                   170u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_034_oPCAN_RADAR_76ff4d74_Tx                                   171u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_035_oPCAN_RADAR_7c3530dd_Tx                                   172u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_036_oPCAN_RADAR_636bb626_Tx                                   173u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_037_oPCAN_RADAR_69a1cb8f_Tx                                   174u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_038_oPCAN_RADAR_0b855698_Tx                                   175u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_039_oPCAN_RADAR_014f2b31_Tx                                   176u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_040_oPCAN_RADAR_a63680c5_Tx                                   177u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_041_oPCAN_RADAR_acfcfd6c_Tx                                   178u
#define CanIfTxPduHnd_TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49            179u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_042_oPCAN_RADAR_b3a27b97_Tx                                   180u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_043_oPCAN_RADAR_b968063e_Tx                                   181u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_044_oPCAN_RADAR_8d1f7661_Tx                                   182u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_045_oPCAN_RADAR_87d50bc8_Tx                                   183u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_046_oPCAN_RADAR_988b8d33_Tx                                   184u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_047_oPCAN_RADAR_9241f09a_Tx                                   185u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_048_oPCAN_RADAR_f0656d8d_Tx                                   186u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_049_oPCAN_RADAR_faaf1024_Tx                                   187u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_050_oPCAN_RADAR_093651f4_Tx                                   188u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_051_oPCAN_RADAR_03fc2c5d_Tx                                   189u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_052_oPCAN_RADAR_1ca2aaa6_Tx                                   190u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_053_oPCAN_RADAR_1668d70f_Tx                                   191u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_054_oPCAN_RADAR_221fa750_Tx                                   192u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_055_oPCAN_RADAR_28d5daf9_Tx                                   193u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_056_oPCAN_RADAR_378b5c02_Tx                                   194u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_057_oPCAN_RADAR_3d4121ab_Tx                                   195u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_058_oPCAN_RADAR_5f65bcbc_Tx                                   196u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_059_oPCAN_RADAR_55afc115_Tx                                   197u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_060_oPCAN_RADAR_234624e6_Tx                                   198u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_061_oPCAN_RADAR_298c594f_Tx                                   199u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_062_oPCAN_RADAR_36d2dfb4_Tx                                   200u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_063_oPCAN_RADAR_3c18a21d_Tx                                   201u
#define CanIfTxPduHnd_RDR_TRACKER_OBJ_064_oPCAN_RADAR_086fd242_Tx                                   202u
#define CanIfTxPduHnd_RDR_XCP_CTO_RESP_oPCAN_RADAR_ebd76419_Tx                                      203u
#define CanIfTxPduHnd_RDR_XCP_DAQ_RESP_oPCAN_RADAR_42f3f200_Tx                                      204u
#define CanIfTxPduHnd_SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx                                 205u
#define CanIfTxPduHnd_SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx                                 206u
#define CanIfTxPduHnd_SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx                                  207u
#define CanIfTxPduHnd_SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx                                208u
#define CanIfTxPduHnd_SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx                                 209u
#define CanIfTxPduHnd_SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx                                 210u
#define CanIfTxPduHnd_SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx                                  211u
#define CanIfTxPduHnd_SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx                                212u
#define CanIfTxPduHnd_SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx                          213u
#define CanIfTxPduHnd_SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx                          214u
#define CanIfTxPduHnd_SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx                           215u
#define CanIfTxPduHnd_SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx                         216u
#define CanIfTxPduHnd_SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx                          217u
#define CanIfTxPduHnd_SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx                          218u
#define CanIfTxPduHnd_SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx                           219u
#define CanIfTxPduHnd_SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx                         220u
#define CanIfTxPduHnd_TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx                                              221u
#define CanIfTxPduHnd_TPCM_SR2_oVCAN_RADAR_e86476d4_Tx                                              222u
#define CanIfTxPduHnd_TPCM_Tp_oVCAN_RADAR_229e257c_Tx                                               223u
#define CanIfTxPduHnd_TPDT_B0_oVCAN_RADAR_d6e4df39_Tx                                               224u
#define CanIfTxPduHnd_TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx                                               225u
#define CanIfTxPduHnd_TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx                                               226u
#define CanIfTxPduHnd_prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx                                   227u
#define CanIfTxPduHnd_prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx                                   228u
#define CanIfTxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx                                         229u


/**********************************************************************************************************************
  \def  Rx PDU handles (Rx indication function specific ones)
**********************************************************************************************************************/

/* These definitions can change at Post-build configuration time. Use them wisely. */
/* Assigned to: NULL_PTR*/
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx                                 0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_01                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_02                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_03                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_04                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_05                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_06                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_07                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx_RDR_08                          0u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx                                 1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_01                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_02                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_03                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_04                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_05                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_06                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_07                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx_RDR_08                          1u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx                                  2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_01                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_02                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_03                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_04                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_05                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_06                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_07                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx_RDR_08                           2u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx                                3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_01                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_02                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_03                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_04                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_05                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_06                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_07                         3u
#define CanIfRxPduHnd_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx_RDR_08                         3u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx                                 4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_01                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_02                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_03                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_04                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_05                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_06                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_07                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx_RDR_08                          4u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx                                 5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_01                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_02                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_03                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_04                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_05                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_06                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_07                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx_RDR_08                          5u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx                                  6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_01                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_02                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_03                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_04                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_05                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_06                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_07                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx_RDR_08                           6u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx                                7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_01                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_02                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_03                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_04                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_05                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_06                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_07                         7u
#define CanIfRxPduHnd_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx_RDR_08                         7u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_01                                   8u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_02                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_03                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_04                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_05                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_06                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_07                                   13u
#define CanIfRxPduHnd_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx_RDR_08                                   13u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_01                   9u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_02                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_03                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_04                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_05                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_06                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_07                   16u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx_RDR_08                   16u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_01                                      10u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_02                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_03                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_04                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_05                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_06                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_07                                      8u
#define CanIfRxPduHnd_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx_RDR_08                                      8u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_01                                      11u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_02                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_03                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_04                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_05                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_06                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_07                                      9u
#define CanIfRxPduHnd_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx_RDR_08                                      9u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_01                                   12u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_02                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_03                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_04                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_05                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_06                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_07                                   10u
#define CanIfRxPduHnd_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx_RDR_08                                   10u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_01                                   13u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_02                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_03                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_04                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_05                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_06                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_07                                   11u
#define CanIfRxPduHnd_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx_RDR_08                                   11u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_01                                   14u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_02                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_03                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_04                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_05                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_06                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_07                                   12u
#define CanIfRxPduHnd_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx_RDR_08                                   12u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_01                 15u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_02                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_03                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_04                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_05                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_06                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_07                 14u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx_RDR_08                 14u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_01                 16u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_02                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_03                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_04                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_05                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_06                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_07                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx_RDR_08                 15u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx                          17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_01                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_02                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_03                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_04                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_05                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_06                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_07                   17u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx_RDR_08                   17u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx                         18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_01                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_02                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_03                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_04                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_05                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_06                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_07                  18u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx_RDR_08                  18u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx                         19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_01                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_02                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_03                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_04                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_05                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_06                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_07                  19u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx_RDR_08                  19u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx                         20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_01                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_02                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_03                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_04                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_05                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_06                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_07                  20u
#define CanIfRxPduHnd_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx_RDR_08                  20u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx                         21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_01                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_02                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_03                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_04                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_05                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_06                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_07                  21u
#define CanIfRxPduHnd_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx_RDR_08                  21u
/* Assigned to: CanTSyn_RxIndication*/
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx                                         0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_01                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_02                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_03                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_04                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_06                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_07                                  0u
#define CanIfRxPduHnd_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx_RDR_08                                  0u
/* Assigned to: CanTp_RxIndication*/
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx                                 0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_01                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_02                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_03                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_04                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_05                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_06                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_07                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx_RDR_08                          0u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx                                   1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_01                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_02                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_03                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_04                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_05                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_06                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_07                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx_RDR_08                            1u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx                                  2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_01                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_02                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_03                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_04                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_05                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_06                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_07                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx_RDR_08                           2u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx                                  3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_01                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_02                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_03                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_04                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_05                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_06                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_07                           3u
#define CanIfRxPduHnd_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx_RDR_08                           3u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx                              4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_01                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_02                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_03                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_04                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_05                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_06                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_07                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx_RDR_08                       4u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx                                5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_01                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_02                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_03                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_04                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_05                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_06                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_07                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx_RDR_08                         5u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx                               6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_01                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_02                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_03                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_04                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_05                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_06                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_07                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx_RDR_08                        6u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx                               7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_01                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_02                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_03                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_04                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_05                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_06                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_07                        7u
#define CanIfRxPduHnd_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx_RDR_08                        7u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx                           8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_01                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_02                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_03                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_04                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_05                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_06                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_07                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx_RDR_08                    8u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx                        9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_01                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_02                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_03                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_04                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_05                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_06                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_07                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx_RDR_08                 9u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx                             10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_01                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_02                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_03                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_04                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_05                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_06                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_07                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx_RDR_08                      10u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx                          11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_01                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_02                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_03                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_04                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_05                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_06                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_07                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx_RDR_08                   11u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx                            12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_01                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_02                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_03                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_04                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_05                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_06                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_07                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx_RDR_08                     12u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx                         13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_01                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_02                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_03                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_04                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_05                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_06                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_07                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx_RDR_08                  13u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx                            14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_01                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_02                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_03                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_04                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_05                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_06                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_07                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx_RDR_08                     14u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx                         15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_01                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_02                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_03                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_04                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_05                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_06                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_07                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx_RDR_08                  15u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx                           16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_01                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_02                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_03                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_04                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_05                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_06                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_07                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx_RDR_08                    16u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx                        17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_01                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_02                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_03                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_04                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_05                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_06                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_07                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx_RDR_08                 17u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx                             18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_01                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_02                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_03                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_04                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_05                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_06                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_07                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx_RDR_08                      18u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx                          19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_01                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_02                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_03                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_04                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_05                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_06                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_07                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx_RDR_08                   19u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx                            20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_01                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_02                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_03                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_04                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_05                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_06                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_07                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx_RDR_08                     20u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx                         21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_01                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_02                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_03                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_04                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_05                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_06                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_07                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx_RDR_08                  21u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx                            22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_01                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_02                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_03                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_04                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_05                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_06                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_07                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx_RDR_08                     22u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx                         23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_01                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_02                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_03                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_04                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_05                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_06                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_07                  23u
#define CanIfRxPduHnd_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx_RDR_08                  23u
/* Assigned to: PduR_CanIfRxIndication*/
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx                            0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_01                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_02                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_03                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_04                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_05                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_06                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_07                     0u
#define CanIfRxPduHnd_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx_RDR_08                     0u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx                                                 1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_01                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_02                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_03                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_04                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_05                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_06                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_07                                          1u
#define CanIfRxPduHnd_CCVS1_oVCAN_RADAR_2823bd01_Rx_RDR_08                                          1u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx                                             2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_01                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_02                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_03                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_04                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_05                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_06                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_07                                      2u
#define CanIfRxPduHnd_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx_RDR_08                                      2u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx                                              3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_01                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_02                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_03                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_04                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_05                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_06                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_07                                       3u
#define CanIfRxPduHnd_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx_RDR_08                                       3u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx                                               4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_01                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_02                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_03                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_04                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_05                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_06                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_07                                        4u
#define CanIfRxPduHnd_ETC2_00_oVCAN_RADAR_bceeb942_Rx_RDR_08                                        4u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx                                               5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_01                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_02                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_03                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_04                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_05                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_06                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_07                                        5u
#define CanIfRxPduHnd_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx_RDR_08                                        5u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx                                                   6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_01                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_02                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_03                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_04                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_05                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_06                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_07                                            6u
#define CanIfRxPduHnd_OEL_oVCAN_RADAR_8850ccda_Rx_RDR_08                                            6u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx                                                   7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_01                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_02                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_03                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_04                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_05                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_06                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_07                                            7u
#define CanIfRxPduHnd_SAS_oVCAN_RADAR_0befc4d7_Rx_RDR_08                                            7u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx                                                    8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_01                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_02                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_03                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_04                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_05                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_06                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_07                                             8u
#define CanIfRxPduHnd_TD_oVCAN_RADAR_e2a191e5_Rx_RDR_08                                             8u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx                                                  9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_01                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_02                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_03                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_04                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_05                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_06                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_07                                           9u
#define CanIfRxPduHnd_VDC2_oVCAN_RADAR_2417bb2a_Rx_RDR_08                                           9u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx                                                    10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_01                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_02                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_03                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_04                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_05                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_06                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_07                                             10u
#define CanIfRxPduHnd_VD_oVCAN_RADAR_4ccaa5be_Rx_RDR_08                                             10u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx                                                    11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_01                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_02                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_03                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_04                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_05                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_06                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_07                                             11u
#define CanIfRxPduHnd_VI_oVCAN_RADAR_3ac3c5b8_Rx_RDR_08                                             11u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx                               12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_01                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_02                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_03                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_04                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_05                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_06                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_07                        12u
#define CanIfRxPduHnd_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx_RDR_08                        12u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx                                           13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_01                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_02                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_03                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_04                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_05                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_06                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_07                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx_RDR_08                                    13u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx                                          14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_01                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_02                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_03                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_04                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_05                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_06                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_07                                   14u
#define CanIfRxPduHnd_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx_RDR_08                                   14u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx                                              15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_01                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_02                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_03                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_04                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_05                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_06                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_07                                       15u
#define CanIfRxPduHnd_GW_CCVS1_oPCAN_RADAR_dee05550_Rx_RDR_08                                       15u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx                                                 16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_01                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_02                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_03                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_04                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_05                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_06                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_07                                          16u
#define CanIfRxPduHnd_GW_VI_oPCAN_RADAR_50142625_Rx_RDR_08                                          16u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx                                                 17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_01                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_02                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_03                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_04                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_05                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_06                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_07                                          17u
#define CanIfRxPduHnd_GW_TD_oPCAN_RADAR_8d3696b8_Rx_RDR_08                                          17u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx                                                 18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_01                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_02                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_03                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_04                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_05                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_06                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_07                                          18u
#define CanIfRxPduHnd_GW_VD_oPCAN_RADAR_c4632d82_Rx_RDR_08                                          18u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx                                                19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_01                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_02                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_03                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_04                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_05                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_06                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_07                                         19u
#define CanIfRxPduHnd_GW_SAS_oPCAN_RADAR_e942763a_Rx_RDR_08                                         19u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx                                               20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_01                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_02                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_03                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_04                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_05                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_06                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_07                                        20u
#define CanIfRxPduHnd_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx_RDR_08                                        20u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx                                            21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_01                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_02                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_03                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_04                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_05                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_06                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_07                                     21u
#define CanIfRxPduHnd_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx_RDR_08                                     21u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx                                               22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_01                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_02                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_03                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_04                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_05                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_06                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_07                                        22u
#define CanIfRxPduHnd_GW_ETC2_oPCAN_RADAR_71fbc026_Rx_RDR_08                                        22u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_01                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_02                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_03                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_04                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_05                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_06                  23u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_07                  55u
#define CanIfRxPduHnd_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx_RDR_08                  55u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_01                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_02                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_03                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_04                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_05                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_06                                         24u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_07                                         56u
#define CanIfRxPduHnd_GW_OEL_oPCAN_RADAR_072b70f3_Rx_RDR_08                                         56u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_01                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_02                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_03                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_04                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_05                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_06                                       25u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_07                                       57u
#define CanIfRxPduHnd_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx_RDR_08                                       57u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_01                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_02                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_03                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_04                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_05                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_06                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_07                         23u
#define CanIfRxPduHnd_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx_RDR_08                         23u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_01                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_02                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_03                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_04                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_05                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_06                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_07                         24u
#define CanIfRxPduHnd_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx_RDR_08                         24u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_01                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_02                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_03                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_04                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_05                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_06                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_07                         25u
#define CanIfRxPduHnd_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx_RDR_08                         25u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_01                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_02                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_03                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_04                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_05                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_06                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_07                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx_RDR_08                         26u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_01                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_02                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_03                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_04                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_05                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_06                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_07                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx_RDR_08                         27u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_01                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_02                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_03                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_04                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_05                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_06                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_07                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx_RDR_08                         28u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_01                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_02                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_03                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_04                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_05                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_06                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_07                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx_RDR_08                         29u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_01                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_02                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_03                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_04                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_05                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_06                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_07                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx_RDR_08                         30u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_01                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_02                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_03                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_04                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_05                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_06                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_07                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx_RDR_08                         31u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_01                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_02                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_03                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_04                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_05                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_06                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_07                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx_RDR_08                         32u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_01                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_02                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_03                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_04                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_05                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_06                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_07                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx_RDR_08                         33u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_01                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_02                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_03                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_04                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_05                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_06                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_07                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx_RDR_08                         34u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_01                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_02                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_03                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_04                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_05                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_06                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_07                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx_RDR_08                         35u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_01                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_02                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_03                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_04                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_05                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_06                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_07                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx_RDR_08                         36u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_01                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_02                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_03                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_04                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_05                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_06                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_07                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx_RDR_08                         37u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_01                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_02                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_03                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_04                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_05                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_06                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_07                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx_RDR_08                         38u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_01                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_02                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_03                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_04                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_05                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_06                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_07                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx_RDR_08                         39u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_01                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_02                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_03                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_04                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_05                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_06                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_07                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx_RDR_08                         40u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_01                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_02                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_03                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_04                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_05                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_06                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_07                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx_RDR_08                         41u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_01                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_02                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_03                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_04                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_05                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_06                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_07                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx_RDR_08                         42u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_01                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_02                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_03                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_04                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_05                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_06                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_07                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx_RDR_08                         43u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_01                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_02                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_03                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_04                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_05                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_06                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_07                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx_RDR_08                         44u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_01                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_02                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_03                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_04                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_05                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_06                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_07                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx_RDR_08                         45u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_01                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_02                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_03                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_04                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_05                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_06                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_07                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx_RDR_08                         46u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_01                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_02                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_03                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_04                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_05                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_06                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_07                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx_RDR_08                         47u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_01                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_02                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_03                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_04                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_05                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_06                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_07                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx_RDR_08                         48u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_01                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_02                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_03                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_04                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_05                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_06                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_07                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx_RDR_08                         49u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_01                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_02                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_03                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_04                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_05                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_06                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_07                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx_RDR_08                         50u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_01                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_02                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_03                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_04                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_05                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_06                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_07                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx_RDR_08                         51u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_01                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_02                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_03                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_04                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_05                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_06                         55u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_07                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx_RDR_08                         52u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_01                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_02                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_03                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_04                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_05                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_06                         56u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_07                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx_RDR_08                         53u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_01                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_02                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_03                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_04                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_05                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_06                         57u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_07                         54u
#define CanIfRxPduHnd_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx_RDR_08                         54u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx                                 58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_01                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_02                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_03                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_04                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_05                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_06                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_07                          58u
#define CanIfRxPduHnd_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx_RDR_08                          58u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx                       59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_01                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_02                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_03                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_04                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_05                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_06                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_07                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx_RDR_08                59u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx                       60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_01                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_02                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_03                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_04                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_05                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_06                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_07                60u
#define CanIfRxPduHnd_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx_RDR_08                60u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx                                 61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_01                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_02                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_03                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_04                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_05                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_06                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_07                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx_RDR_08                          61u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx                                 62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_01                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_02                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_03                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_04                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_05                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_06                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_07                          62u
#define CanIfRxPduHnd_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx_RDR_08                          62u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx                                 63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_01                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_02                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_03                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_04                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_05                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_06                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_07                          63u
#define CanIfRxPduHnd_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx_RDR_08                          63u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx                                    64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_01                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_02                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_03                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_04                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_05                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_06                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_07                             64u
#define CanIfRxPduHnd_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx_RDR_08                             64u
/* Assigned to: Xcp_CanIfRxIndication*/
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx                                       0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_01                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_02                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_03                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_04                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_05                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_06                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_07                                0u
#define CanIfRxPduHnd_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx_RDR_08                                0u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_BSD1_oVCAN_RADAR_64acbe01_Tx                                        0u
#define CanIfConf_CanIfTxPduCfg_DM1_B0_oVCAN_RADAR_8817cb52_Tx                                      1u
#define CanIfConf_CanIfTxPduCfg_DM1_B1_oVCAN_RADAR_c2a11718_Tx                                      2u
#define CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx                     3u
#define CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx                     4u
#define CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx                      5u
#define CanIfConf_CanIfTxPduCfg_FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx                    6u
#define CanIfConf_CanIfTxPduCfg_GW_ADAS_FN_Enable_disable_sts_Tx_oPCAN_RADAR_b3ed1cbc_Tx            7u
#define CanIfConf_CanIfTxPduCfg_GW_CCVS1_Tx_oPCAN_RADAR_de02a585_Tx                                 8u
#define CanIfConf_CanIfTxPduCfg_GW_CLS_Tx_4_Tx_oPCAN_RADAR_33bc88fd_Tx                              9u
#define CanIfConf_CanIfTxPduCfg_GW_CLS_Tx_16_Tx_oPCAN_RADAR_9dad2921_Tx                             10u
#define CanIfConf_CanIfTxPduCfg_GW_ETC2_03_Tx_oPCAN_RADAR_6fe44ee0_Tx                               11u
#define CanIfConf_CanIfTxPduCfg_GW_ETC2_Tx_oPCAN_RADAR_5963dc30_Tx                                  12u
#define CanIfConf_CanIfTxPduCfg_GW_OEL_Tx_oPCAN_RADAR_a8245947_Tx                                   13u
#define CanIfConf_CanIfTxPduCfg_GW_SAS_Tx_oPCAN_RADAR_2217d6e9_Tx                                   14u
#define CanIfConf_CanIfTxPduCfg_GW_TD_Tx_oPCAN_RADAR_2f7068b5_Tx                                    15u
#define CanIfConf_CanIfTxPduCfg_GW_VDC2_Tx_oPCAN_RADAR_f54084fa_Tx                                  16u
#define CanIfConf_CanIfTxPduCfg_GW_VD_Tx_oPCAN_RADAR_56fb68b9_Tx                                    17u
#define CanIfConf_CanIfTxPduCfg_GW_VI_Tx_oPCAN_RADAR_ba7d49ea_Tx                                    18u
#define CanIfConf_CanIfTxPduCfg_GW_prop_ADAS_BSIS_info_oPCAN_RADAR_14d3ec96_Tx                      19u
#define CanIfConf_CanIfTxPduCfg_MOIS_oVCAN_RADAR_edd3b80a_Tx                                        20u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_8c240349_Tx                 21u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD1_Tp_oPCAN_RADAR_20_317d1888_Tx              22u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_20_fc5af980_Tx              23u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OBD2_Tp_oPCAN_RADAR_b153d036_Tx                 24u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_20_07246a50_Tx               25u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_OTA_Tp_oPCAN_RADAR_c2db48e7_Tx                  26u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_2ddb0a0a_Tx                27u
#define CanIfConf_CanIfTxPduCfg_PCAN_DIAG_RESP_PHYS_PLANT_Tp_oPCAN_RADAR_20_656ccdb7_Tx             28u
#define CanIfConf_CanIfTxPduCfg_RDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_caaee0a2_Tx                    29u
#define CanIfConf_CanIfTxPduCfg_RDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_899d4639_Tx                    30u
#define CanIfConf_CanIfTxPduCfg_RDR_BSD1_Tx_oPCAN_RADAR_ec8026a7_Tx                                 31u
#define CanIfConf_CanIfTxPduCfg_RDR_CAPABILITY_oPCAN_RADAR_834d4809_Tx                              32u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_001_004_oPCAN_RADAR_456a1641_Tx                       33u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_005_008_oPCAN_RADAR_907c961b_Tx                       34u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_009_012_oPCAN_RADAR_83a4abae_Tx                       35u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_013_016_oPCAN_RADAR_897f6817_Tx                       36u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_017_020_oPCAN_RADAR_94d1abf5_Tx                       37u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_021_024_oPCAN_RADAR_35f4b8e7_Tx                       38u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_025_028_oPCAN_RADAR_e0e238bd_Tx                       39u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_029_032_oPCAN_RADAR_f33a0508_Tx                       40u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_033_036_oPCAN_RADAR_f9e1c6b1_Tx                       41u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_037_040_oPCAN_RADAR_d1647cc0_Tx                       42u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_041_044_oPCAN_RADAR_a4574b0d_Tx                       43u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_045_048_oPCAN_RADAR_7141cb57_Tx                       44u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_049_052_oPCAN_RADAR_6299f6e2_Tx                       45u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_053_056_oPCAN_RADAR_6842355b_Tx                       46u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_057_060_oPCAN_RADAR_75ecf6b9_Tx                       47u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_061_064_oPCAN_RADAR_d4c9e5ab_Tx                       48u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_065_068_oPCAN_RADAR_01df65f1_Tx                       49u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_069_072_oPCAN_RADAR_12075844_Tx                       50u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_073_076_oPCAN_RADAR_18dc9bfd_Tx                       51u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_077_080_oPCAN_RADAR_5a0fd2aa_Tx                       52u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_081_084_oPCAN_RADAR_5c61aa98_Tx                       53u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_085_088_oPCAN_RADAR_89772ac2_Tx                       54u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_089_092_oPCAN_RADAR_9aaf1777_Tx                       55u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_093_096_oPCAN_RADAR_9074d4ce_Tx                       56u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_097_100_oPCAN_RADAR_9189e332_Tx                       57u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_101_104_oPCAN_RADAR_b7305958_Tx                       58u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_105_108_oPCAN_RADAR_6226d902_Tx                       59u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_109_112_oPCAN_RADAR_71fee4b7_Tx                       60u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_113_116_oPCAN_RADAR_7b25270e_Tx                       61u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_117_120_oPCAN_RADAR_668be4ec_Tx                       62u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_121_124_oPCAN_RADAR_c7aef7fe_Tx                       63u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_125_128_oPCAN_RADAR_12b877a4_Tx                       64u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_129_132_oPCAN_RADAR_01604a11_Tx                       65u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_133_136_oPCAN_RADAR_0bbb89a8_Tx                       66u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_137_140_oPCAN_RADAR_233e33d9_Tx                       67u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_141_144_oPCAN_RADAR_560d0414_Tx                       68u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_145_148_oPCAN_RADAR_831b844e_Tx                       69u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_149_152_oPCAN_RADAR_90c3b9fb_Tx                       70u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_153_156_oPCAN_RADAR_9a187a42_Tx                       71u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_157_160_oPCAN_RADAR_87b6b9a0_Tx                       72u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_161_164_oPCAN_RADAR_2693aab2_Tx                       73u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_165_168_oPCAN_RADAR_f3852ae8_Tx                       74u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_169_172_oPCAN_RADAR_e05d175d_Tx                       75u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_173_176_oPCAN_RADAR_ea86d4e4_Tx                       76u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_177_180_oPCAN_RADAR_a8559db3_Tx                       77u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_181_184_oPCAN_RADAR_ae3be581_Tx                       78u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_185_188_oPCAN_RADAR_7b2d65db_Tx                       79u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_189_192_oPCAN_RADAR_68f5586e_Tx                       80u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_193_196_oPCAN_RADAR_622e9bd7_Tx                       81u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_197_200_oPCAN_RADAR_baf2dbc8_Tx                       82u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_201_204_oPCAN_RADAR_7aaf8e32_Tx                       83u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_205_208_oPCAN_RADAR_afb90e68_Tx                       84u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_209_212_oPCAN_RADAR_bc6133dd_Tx                       85u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_213_216_oPCAN_RADAR_b6baf064_Tx                       86u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_217_220_oPCAN_RADAR_ab143386_Tx                       87u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_221_224_oPCAN_RADAR_0a312094_Tx                       88u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_225_228_oPCAN_RADAR_df27a0ce_Tx                       89u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_229_232_oPCAN_RADAR_ccff9d7b_Tx                       90u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_233_236_oPCAN_RADAR_c6245ec2_Tx                       91u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_237_240_oPCAN_RADAR_eea1e4b3_Tx                       92u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_241_244_oPCAN_RADAR_9b92d37e_Tx                       93u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_245_248_oPCAN_RADAR_4e845324_Tx                       94u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_249_252_oPCAN_RADAR_5d5c6e91_Tx                       95u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_253_256_oPCAN_RADAR_5787ad28_Tx                       96u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_257_260_oPCAN_RADAR_4a296eca_Tx                       97u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_261_264_oPCAN_RADAR_eb0c7dd8_Tx                       98u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_265_268_oPCAN_RADAR_3e1afd82_Tx                       99u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_269_272_oPCAN_RADAR_2dc2c037_Tx                       100u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_273_276_oPCAN_RADAR_2719038e_Tx                       101u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_277_280_oPCAN_RADAR_65ca4ad9_Tx                       102u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_281_284_oPCAN_RADAR_63a432eb_Tx                       103u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_285_288_oPCAN_RADAR_b6b2b2b1_Tx                       104u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_289_292_oPCAN_RADAR_a56a8f04_Tx                       105u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_293_296_oPCAN_RADAR_afb14cbd_Tx                       106u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_297_300_oPCAN_RADAR_ae4c7b41_Tx                       107u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_301_304_oPCAN_RADAR_88f5c12b_Tx                       108u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_305_308_oPCAN_RADAR_5de34171_Tx                       109u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_309_312_oPCAN_RADAR_4e3b7cc4_Tx                       110u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_313_316_oPCAN_RADAR_44e0bf7d_Tx                       111u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_317_320_oPCAN_RADAR_594e7c9f_Tx                       112u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_321_324_oPCAN_RADAR_f86b6f8d_Tx                       113u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_325_328_oPCAN_RADAR_2d7defd7_Tx                       114u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_329_332_oPCAN_RADAR_3ea5d262_Tx                       115u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_333_336_oPCAN_RADAR_347e11db_Tx                       116u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_337_340_oPCAN_RADAR_1cfbabaa_Tx                       117u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_341_344_oPCAN_RADAR_69c89c67_Tx                       118u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_345_348_oPCAN_RADAR_bcde1c3d_Tx                       119u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_349_352_oPCAN_RADAR_af062188_Tx                       120u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_353_356_oPCAN_RADAR_a5dde231_Tx                       121u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_357_360_oPCAN_RADAR_b87321d3_Tx                       122u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_361_364_oPCAN_RADAR_195632c1_Tx                       123u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_365_368_oPCAN_RADAR_cc40b29b_Tx                       124u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_369_372_oPCAN_RADAR_df988f2e_Tx                       125u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_373_376_oPCAN_RADAR_d5434c97_Tx                       126u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_377_380_oPCAN_RADAR_979005c0_Tx                       127u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_381_384_oPCAN_RADAR_91fe7df2_Tx                       128u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_385_388_oPCAN_RADAR_44e8fda8_Tx                       129u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_389_392_oPCAN_RADAR_5730c01d_Tx                       130u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_393_396_oPCAN_RADAR_5deb03a4_Tx                       131u
#define CanIfConf_CanIfTxPduCfg_RDR_DETECTION_397_400_oPCAN_RADAR_ec04aa3c_Tx                       132u
#define CanIfConf_CanIfTxPduCfg_RDR_HEADER_001_oPCAN_RADAR_051a0060_Tx                              133u
#define CanIfConf_CanIfTxPduCfg_RDR_OBJ_HEADER_002_oPCAN_RADAR_0a1b3262_Tx                          134u
#define CanIfConf_CanIfTxPduCfg_RDR_OBJ_STATUS_003_oPCAN_RADAR_24cf7f10_Tx                          135u
#define CanIfConf_CanIfTxPduCfg_RDR_STATUS_001_oPCAN_RADAR_0ddc5064_Tx                              136u
#define CanIfConf_CanIfTxPduCfg_RDR_STATUS_002_oPCAN_RADAR_b26a35a7_Tx                              137u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_001_oPCAN_RADAR_7d6cb36b_Tx                         138u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_002_oPCAN_RADAR_62323590_Tx                         139u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_003_oPCAN_RADAR_68f84839_Tx                         140u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_004_oPCAN_RADAR_5c8f3866_Tx                         141u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_005_oPCAN_RADAR_564545cf_Tx                         142u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_006_oPCAN_RADAR_491bc334_Tx                         143u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_007_oPCAN_RADAR_43d1be9d_Tx                         144u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_008_oPCAN_RADAR_21f5238a_Tx                         145u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_009_oPCAN_RADAR_2b3f5e23_Tx                         146u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_010_oPCAN_RADAR_d8a61ff3_Tx                         147u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_011_oPCAN_RADAR_d26c625a_Tx                         148u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_012_oPCAN_RADAR_cd32e4a1_Tx                         149u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_013_oPCAN_RADAR_c7f89908_Tx                         150u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_014_oPCAN_RADAR_f38fe957_Tx                         151u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_015_oPCAN_RADAR_f94594fe_Tx                         152u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_016_oPCAN_RADAR_e61b1205_Tx                         153u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_017_oPCAN_RADAR_ecd16fac_Tx                         154u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_018_oPCAN_RADAR_8ef5f2bb_Tx                         155u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_019_oPCAN_RADAR_843f8f12_Tx                         156u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_020_oPCAN_RADAR_f2d66ae1_Tx                         157u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_021_oPCAN_RADAR_f81c1748_Tx                         158u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_022_oPCAN_RADAR_e74291b3_Tx                         159u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_023_oPCAN_RADAR_ed88ec1a_Tx                         160u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_024_oPCAN_RADAR_d9ff9c45_Tx                         161u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_025_oPCAN_RADAR_d335e1ec_Tx                         162u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_026_oPCAN_RADAR_cc6b6717_Tx                         163u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_027_oPCAN_RADAR_c6a11abe_Tx                         164u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_028_oPCAN_RADAR_a48587a9_Tx                         165u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_029_oPCAN_RADAR_ae4ffa00_Tx                         166u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_030_oPCAN_RADAR_5dd6bbd0_Tx                         167u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_031_oPCAN_RADAR_571cc679_Tx                         168u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_032_oPCAN_RADAR_48424082_Tx                         169u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_033_oPCAN_RADAR_42883d2b_Tx                         170u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_034_oPCAN_RADAR_76ff4d74_Tx                         171u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_035_oPCAN_RADAR_7c3530dd_Tx                         172u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_036_oPCAN_RADAR_636bb626_Tx                         173u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_037_oPCAN_RADAR_69a1cb8f_Tx                         174u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_038_oPCAN_RADAR_0b855698_Tx                         175u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_039_oPCAN_RADAR_014f2b31_Tx                         176u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_040_oPCAN_RADAR_a63680c5_Tx                         177u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_041_oPCAN_RADAR_acfcfd6c_Tx                         178u
#define CanIfConf_CanIfTxPduCfg_TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49  179u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_042_oPCAN_RADAR_b3a27b97_Tx                         180u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_043_oPCAN_RADAR_b968063e_Tx                         181u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_044_oPCAN_RADAR_8d1f7661_Tx                         182u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_045_oPCAN_RADAR_87d50bc8_Tx                         183u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_046_oPCAN_RADAR_988b8d33_Tx                         184u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_047_oPCAN_RADAR_9241f09a_Tx                         185u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_048_oPCAN_RADAR_f0656d8d_Tx                         186u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_049_oPCAN_RADAR_faaf1024_Tx                         187u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_050_oPCAN_RADAR_093651f4_Tx                         188u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_051_oPCAN_RADAR_03fc2c5d_Tx                         189u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_052_oPCAN_RADAR_1ca2aaa6_Tx                         190u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_053_oPCAN_RADAR_1668d70f_Tx                         191u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_054_oPCAN_RADAR_221fa750_Tx                         192u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_055_oPCAN_RADAR_28d5daf9_Tx                         193u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_056_oPCAN_RADAR_378b5c02_Tx                         194u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_057_oPCAN_RADAR_3d4121ab_Tx                         195u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_058_oPCAN_RADAR_5f65bcbc_Tx                         196u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_059_oPCAN_RADAR_55afc115_Tx                         197u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_060_oPCAN_RADAR_234624e6_Tx                         198u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_061_oPCAN_RADAR_298c594f_Tx                         199u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_062_oPCAN_RADAR_36d2dfb4_Tx                         200u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_063_oPCAN_RADAR_3c18a21d_Tx                         201u
#define CanIfConf_CanIfTxPduCfg_RDR_TRACKER_OBJ_064_oPCAN_RADAR_086fd242_Tx                         202u
#define CanIfConf_CanIfTxPduCfg_RDR_XCP_CTO_RESP_oPCAN_RADAR_ebd76419_Tx                            203u
#define CanIfConf_CanIfTxPduCfg_RDR_XCP_DAQ_RESP_oPCAN_RADAR_42f3f200_Tx                            204u
#define CanIfConf_CanIfTxPduCfg_SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx                       205u
#define CanIfConf_CanIfTxPduCfg_SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx                       206u
#define CanIfConf_CanIfTxPduCfg_SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx                        207u
#define CanIfConf_CanIfTxPduCfg_SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx                      208u
#define CanIfConf_CanIfTxPduCfg_SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx                       209u
#define CanIfConf_CanIfTxPduCfg_SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx                       210u
#define CanIfConf_CanIfTxPduCfg_SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx                        211u
#define CanIfConf_CanIfTxPduCfg_SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx                      212u
#define CanIfConf_CanIfTxPduCfg_SRR_FL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_47cc77aa_Tx                213u
#define CanIfConf_CanIfTxPduCfg_SRR_FL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_965c3a17_Tx                214u
#define CanIfConf_CanIfTxPduCfg_SRR_FL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2ec4d37f_Tx                 215u
#define CanIfConf_CanIfTxPduCfg_SRR_FL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_82406e1b_Tx               216u
#define CanIfConf_CanIfTxPduCfg_SRR_RL_DIAG_REQ_PHYS_OBD1_Tx_oPCAN_RADAR_d15e4aba_Tx                217u
#define CanIfConf_CanIfTxPduCfg_SRR_RL_DIAG_REQ_PHYS_OBD2_Tx_oPCAN_RADAR_00ce0707_Tx                218u
#define CanIfConf_CanIfTxPduCfg_SRR_RL_DIAG_REQ_PHYS_OTA_Tx_oPCAN_RADAR_2be0d721_Tx                 219u
#define CanIfConf_CanIfTxPduCfg_SRR_RL_DIAG_REQ_PHYS_PLANT_Tx_oPCAN_RADAR_b38606fa_Tx               220u
#define CanIfConf_CanIfTxPduCfg_TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx                                    221u
#define CanIfConf_CanIfTxPduCfg_TPCM_SR2_oVCAN_RADAR_e86476d4_Tx                                    222u
#define CanIfConf_CanIfTxPduCfg_TPCM_Tp_oVCAN_RADAR_229e257c_Tx                                     223u
#define CanIfConf_CanIfTxPduCfg_TPDT_B0_oVCAN_RADAR_d6e4df39_Tx                                     224u
#define CanIfConf_CanIfTxPduCfg_TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx                                     225u
#define CanIfConf_CanIfTxPduCfg_TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx                                     226u
#define CanIfConf_CanIfTxPduCfg_prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx                         227u
#define CanIfConf_CanIfTxPduCfg_prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx                         228u
#define CanIfConf_CanIfTxPduCfg_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx                               229u


/**********************************************************************************************************************
  \def  AUTOSAR Rx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfRxPduCfg_ADAS_FN_Enable_disable_sts_oVCAN_RADAR_12bee21f_Rx                  0u
#define CanIfConf_CanIfRxPduCfg_CCVS1_oVCAN_RADAR_2823bd01_Rx                                       1u
#define CanIfConf_CanIfRxPduCfg_CLS_Tx_4_oVCAN_RADAR_86e16ec0_Rx                                    2u
#define CanIfConf_CanIfRxPduCfg_CLS_Tx_16_oVCAN_RADAR_b5bd9e87_Rx                                   3u
#define CanIfConf_CanIfRxPduCfg_DIAG_REQ_FNC_OBD1_Tp_oVCAN_RADAR_6a2825b2_Rx                        4u
#define CanIfConf_CanIfRxPduCfg_DIAG_REQ_FNC_OBD2_Tp_oVCAN_RADAR_f27c52d9_Rx                        5u
#define CanIfConf_CanIfRxPduCfg_DIAG_REQ_FNC_OTA_Tp_oVCAN_RADAR_99d98f80_Rx                         6u
#define CanIfConf_CanIfRxPduCfg_DIAG_REQ_FNC_PLANT_Tp_oVCAN_RADAR_db883021_Rx                       7u
#define CanIfConf_CanIfRxPduCfg_DM1_B0_Rx_oPCAN_RADAR_a5672d71_Rx                                   8u
#define CanIfConf_CanIfRxPduCfg_DM1_B1_Rx_oPCAN_RADAR_1c7ee3a2_Rx                                   9u
#define CanIfConf_CanIfRxPduCfg_ETC2_00_oVCAN_RADAR_bceeb942_Rx                                     10u
#define CanIfConf_CanIfRxPduCfg_ETC2_03_oVCAN_RADAR_6f7e9f8c_Rx                                     11u
#define CanIfConf_CanIfRxPduCfg_FR_DIAG_REQ_PHY_OBD1_Tp_oVCAN_RADAR_ecc1c765_Rx                     12u
#define CanIfConf_CanIfRxPduCfg_FR_DIAG_REQ_PHY_OBD2_Tp_oVCAN_RADAR_2f8767b4_Rx                     13u
#define CanIfConf_CanIfRxPduCfg_FR_DIAG_REQ_PHY_OTA_Tp_oVCAN_RADAR_a23061a0_Rx                      14u
#define CanIfConf_CanIfRxPduCfg_FR_DIAG_REQ_PHY_PLANT_Tp_oVCAN_RADAR_4a486df0_Rx                    15u
#define CanIfConf_CanIfRxPduCfg_GW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e7ed2761_Rx               16u
#define CanIfConf_CanIfRxPduCfg_GW_CCVS1_oPCAN_RADAR_dee05550_Rx                                    17u
#define CanIfConf_CanIfRxPduCfg_GW_CLS_Tx_4_oPCAN_RADAR_2550d3a5_Rx                                 18u
#define CanIfConf_CanIfRxPduCfg_GW_CLS_Tx_16_oPCAN_RADAR_5cbae8ef_Rx                                19u
#define CanIfConf_CanIfRxPduCfg_GW_ETC2_03_oPCAN_RADAR_c594f99d_Rx                                  20u
#define CanIfConf_CanIfRxPduCfg_GW_ETC2_oPCAN_RADAR_71fbc026_Rx                                     21u
#define CanIfConf_CanIfRxPduCfg_GW_OEL_oPCAN_RADAR_072b70f3_Rx                                      22u
#define CanIfConf_CanIfRxPduCfg_GW_SAS_oPCAN_RADAR_e942763a_Rx                                      23u
#define CanIfConf_CanIfRxPduCfg_GW_TD_oPCAN_RADAR_8d3696b8_Rx                                       24u
#define CanIfConf_CanIfRxPduCfg_GW_VDC2_oPCAN_RADAR_aaaa415e_Rx                                     25u
#define CanIfConf_CanIfRxPduCfg_GW_VD_oPCAN_RADAR_c4632d82_Rx                                       26u
#define CanIfConf_CanIfRxPduCfg_GW_VI_oPCAN_RADAR_50142625_Rx                                       27u
#define CanIfConf_CanIfRxPduCfg_OEL_oVCAN_RADAR_8850ccda_Rx                                         28u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_20_be38c2c7_Rx               29u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OBD1_Tp_oPCAN_RADAR_a49340df_Rx                  30u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_20_5e2c4885_Rx               31u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OBD2_Tp_oPCAN_RADAR_92dcb903_Rx                  32u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_0aa5e66e_Rx                   33u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_OTA_Tp_oPCAN_RADAR_20_8f3fcd60_Rx                34u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_7e247c91_Rx                 35u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_FUNC_PLANT_Tp_oPCAN_RADAR_20_f0f9d98a_Rx              36u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_20_31a2624c_Rx               37u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OBD1_Tp_oPCAN_RADAR_dcf5a9e3_Rx                  38u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_20_d1b6e80e_Rx               39u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OBD2_Tp_oPCAN_RADAR_eaba503f_Rx                  40u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_20_f8b78b8f_Rx                41u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_OTA_Tp_oPCAN_RADAR_bab5b90f_Rx                   42u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_20_6343000b_Rx              43u
#define CanIfConf_CanIfRxPduCfg_PCAN_DIAG_REQ_PHYS_PLANT_Tp_oPCAN_RADAR_9297cde2_Rx                 44u
#define CanIfConf_CanIfRxPduCfg_RDR_BSD1_oPCAN_RADAR_04bcead5_Rx                                    45u
#define CanIfConf_CanIfRxPduCfg_RDR_CM_B0_Rx_oPCAN_RADAR_e767bdf0_Rx                                46u
#define CanIfConf_CanIfRxPduCfg_RDR_CM_B1_Rx_oPCAN_RADAR_477108f1_Rx                                47u
#define CanIfConf_CanIfRxPduCfg_RDR_DT_B0_Rx_oPCAN_RADAR_842ebd81_Rx                                48u
#define CanIfConf_CanIfRxPduCfg_RDR_DT_B1_Rx_oPCAN_RADAR_24380880_Rx                                49u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_3c4e871e_Rx             50u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_666234f7_Rx             51u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_CAPABILITY_oPCAN_RADAR_11f796c7_Rx                       52u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_001_004_oPCAN_RADAR_4b7989b8_Rx                      53u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_005_008_oPCAN_RADAR_0b00c023_Rx                      54u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_009_012_oPCAN_RADAR_00c92885_Rx                      55u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_013_016_oPCAN_RADAR_577f1aa5_Rx                      56u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_017_020_oPCAN_RADAR_e1253ccd_Rx                      57u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_021_024_oPCAN_RADAR_9f591705_Rx                      58u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_025_028_oPCAN_RADAR_df205e9e_Rx                      59u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_029_032_oPCAN_RADAR_d4e9b638_Rx                      60u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_033_036_oPCAN_RADAR_835f8418_Rx                      61u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_037_040_oPCAN_RADAR_3f53262f_Rx                      62u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_041_044_oPCAN_RADAR_3849b283_Rx                      63u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_045_048_oPCAN_RADAR_7830fb18_Rx                      64u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_049_052_oPCAN_RADAR_73f913be_Rx                      65u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_053_056_oPCAN_RADAR_244f219e_Rx                      66u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_057_060_oPCAN_RADAR_921507f6_Rx                      67u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_061_064_oPCAN_RADAR_ec692c3e_Rx                      68u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_065_068_oPCAN_RADAR_ac1065a5_Rx                      69u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_069_072_oPCAN_RADAR_a7d98d03_Rx                      70u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_073_076_oPCAN_RADAR_f06fbf23_Rx                      71u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_077_080_oPCAN_RADAR_58ce15aa_Rx                      72u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_081_084_oPCAN_RADAR_ad19ffce_Rx                      73u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_085_088_oPCAN_RADAR_ed60b655_Rx                      74u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_089_092_oPCAN_RADAR_e6a95ef3_Rx                      75u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_093_096_oPCAN_RADAR_b11f6cd3_Rx                      76u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_097_100_oPCAN_RADAR_b3504422_Rx                      77u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_101_104_oPCAN_RADAR_fc437d4f_Rx                      78u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_105_108_oPCAN_RADAR_bc3a34d4_Rx                      79u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_109_112_oPCAN_RADAR_b7f3dc72_Rx                      80u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_113_116_oPCAN_RADAR_e045ee52_Rx                      81u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_117_120_oPCAN_RADAR_561fc83a_Rx                      82u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_121_124_oPCAN_RADAR_2863e3f2_Rx                      83u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_DET_125_128_oPCAN_RADAR_681aaa69_Rx                      84u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_HEADER_001_oPCAN_RADAR_9f0679aa_Rx                       85u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_STATUS_001_oPCAN_RADAR_5a3f0fa3_Rx                       86u
#define CanIfConf_CanIfRxPduCfg_RDR_FUSION_STATUS_002_oPCAN_RADAR_32e3e17d_Rx                       87u
#define CanIfConf_CanIfRxPduCfg_RDR_XCP_CTO_REQ_oPCAN_RADAR_90586adf_Rx                             88u
#define CanIfConf_CanIfRxPduCfg_RDR_prop_ADAS_BSIS_info_oPCAN_RADAR_1b1aa0fc_Rx                     89u
#define CanIfConf_CanIfRxPduCfg_SAS_oVCAN_RADAR_0befc4d7_Rx                                         90u
#define CanIfConf_CanIfRxPduCfg_SR1_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_d087a8f3_Rx                       91u
#define CanIfConf_CanIfRxPduCfg_SR1_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_b85b462d_Rx                       92u
#define CanIfConf_CanIfRxPduCfg_SR1_DIAG_REQ_PHY_OTA_oVCAN_RADAR_2599cadf_Rx                        93u
#define CanIfConf_CanIfRxPduCfg_SR1_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_5b5133c5_Rx                      94u
#define CanIfConf_CanIfRxPduCfg_SR2_DIAG_REQ_PHY_OBD1_oVCAN_RADAR_c5936bcf_Rx                       95u
#define CanIfConf_CanIfRxPduCfg_SR2_DIAG_REQ_PHY_OBD2_oVCAN_RADAR_ad4f8511_Rx                       96u
#define CanIfConf_CanIfRxPduCfg_SR2_DIAG_REQ_PHY_OTA_oVCAN_RADAR_13148e4e_Rx                        97u
#define CanIfConf_CanIfRxPduCfg_SR2_DIAG_REQ_PHY_PLANT_oVCAN_RADAR_fe78030d_Rx                      98u
#define CanIfConf_CanIfRxPduCfg_SRR_FL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_09ba8005_Rx               99u
#define CanIfConf_CanIfRxPduCfg_SRR_FL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_e9ae0a47_Rx               100u
#define CanIfConf_CanIfRxPduCfg_SRR_FL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_f82256d0_Rx                101u
#define CanIfConf_CanIfRxPduCfg_SRR_FL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_3f679b05_Rx              102u
#define CanIfConf_CanIfRxPduCfg_SRR_RL_DIAG_RESP_PHYS_OBD1_Rx_oPCAN_RADAR_387ce8e4_Rx               103u
#define CanIfConf_CanIfRxPduCfg_SRR_RL_DIAG_RESP_PHYS_OBD2_Rx_oPCAN_RADAR_d86862a6_Rx               104u
#define CanIfConf_CanIfRxPduCfg_SRR_RL_DIAG_RESP_PHYS_OTA_Rx_oPCAN_RADAR_6eb06bc0_Rx                105u
#define CanIfConf_CanIfRxPduCfg_SRR_RL_DIAG_RESP_PHYS_PLANT_Rx_oPCAN_RADAR_84988cb2_Rx              106u
#define CanIfConf_CanIfRxPduCfg_SYS_VEHICLE_STATUS_oPCAN_RADAR_877cfaa4_Rx                          107u
#define CanIfConf_CanIfRxPduCfg_TD_oVCAN_RADAR_e2a191e5_Rx                                          108u
#define CanIfConf_CanIfRxPduCfg_VDC2_oVCAN_RADAR_2417bb2a_Rx                                        109u
#define CanIfConf_CanIfRxPduCfg_VD_oVCAN_RADAR_4ccaa5be_Rx                                          110u
#define CanIfConf_CanIfRxPduCfg_VI_oVCAN_RADAR_3ac3c5b8_Rx                                          111u
#define CanIfConf_CanIfRxPduCfg_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Rx                               112u



/**********************************************************************************************************************
  \def  Indirection macros for CAN Driver EQC specific callback functions
**********************************************************************************************************************/
#define CanIf_RxIndication(Mailbox, PduInfoPtr)                                                     CanIf_RxIndicationAsr403(((Mailbox)->Hoh), (Mailbox)->CanId, (uint8)((PduInfoPtr)->SduLength), (P2CONST(uint8, AUTOMATIC, CANIF_CBK_DRV_VAR))((PduInfoPtr)->SduDataPtr)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define CanIf_ControllerModeIndication(ControllerId, ControllerMode)                                (CanIf_ControllerModeIndicationAr431((ControllerId), (ControllerMode))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */









/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* Coded in RxPduCanId of table CanIf_RxPduConfig[] */
#define CANIF_MASKCODE_RANGE_FLAG                                                                   0x20000000u
#define CANIF_FD_FLAG                                                                               0x40000000u
#define CANIF_FD_FLAG_MASKOUT                                                                       0xBFFFFFFFu
#define CANIF_FD_FLAG_SHIFTPOS                                                                      30u
/* Coded in RxPduMask of table CanIf_RxPduConfig[] */
#define CANIF_STOP_FLAG                                                                             0x40000000u
#define CANIF_RANGE_FLAG                                                                            0x20000000u
#define CANIF_STOP_RANGE_FLAG                                                                       0x60000000u
#define CANIF_STOP_RANGE_FLAG_MASKOUT                                                               0x9FFFFFFFu


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCDataSwitches  CanIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_ACTIVETXREQUESTDATA                                                                   STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' */
#define CANIF_ACTIVETXREQUESTFIFO                                                                   STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' */
#define CANIF_FILLCOUNTOFACTIVETXREQUESTFIFO                                                        STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.FillCount' Reason: 'Bus Mirroring is disabled' */
#define CANIF_READINDEXOFACTIVETXREQUESTFIFO                                                        STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.ReadIndex' Reason: 'Bus Mirroring is disabled' */
#define CANIF_WRITEINDEXOFACTIVETXREQUESTFIFO                                                       STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo.WriteIndex' Reason: 'Bus Mirroring is disabled' */
#define CANIF_ACTIVETXREQUESTINFO                                                                   STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' */
#define CANIF_CANIDOFACTIVETXREQUESTINFO                                                            STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.CanId' Reason: 'Bus Mirroring is disabled' */
#define CANIF_PDUIDOFACTIVETXREQUESTINFO                                                            STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.PduId' Reason: 'Bus Mirroring is disabled' */
#define CANIF_SDULENOFACTIVETXREQUESTINFO                                                           STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduLen' Reason: 'Bus Mirroring is disabled' */
#define CANIF_SDUPTROFACTIVETXREQUESTINFO                                                           STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.SduPtr' Reason: 'Bus Mirroring is disabled' */
#define CANIF_STATEOFACTIVETXREQUESTINFO                                                            STD_OFF  /**< Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo.State' Reason: 'Bus Mirroring is disabled' */
#define CANIF_BAUDRATECONFIG                                                                        STD_OFF  /**< Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' */
#define CANIF_ARBITRATIONBAUDRATEOFBAUDRATECONFIG                                                   STD_OFF  /**< Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.ArbitrationBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' */
#define CANIF_FDBAUDRATEOFBAUDRATECONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.FdBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' */
#define CANIF_XLBAUDRATEOFBAUDRATECONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig.XLBaudrate' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' */
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                                              STD_ON
#define CANIF_CANCONTROLLERIDUPTOLOWMAP                                                             STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' */
#define CANIF_CANDRVEQCARVERSIONOFCANCONTROLLERIDUPTOLOWMAP                                         STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvEqcArVersion' Reason: 'Multiple CAN Driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLIDXOFCANCONTROLLERIDUPTOLOWMAP                                            STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN Driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLUSEDOFCANCONTROLLERIDUPTOLOWMAP                                           STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN Driver support is deactivated.' */
#define CANIF_CONTROLLEROFCANCONTROLLERIDUPTOLOWMAP                                                 STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN Driver support is deactivated.' */
#define CANIF_CANDRVFCTTBL                                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                                                        STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERERRORSTATEFCTOFCANDRVFCTTBL                                              STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERRXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERTXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_XLWRITEOFCANDRVFCTTBL                                                                 STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.XLWrite' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANIFCTRLID2MAPPEDHTHS                                                                STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' */
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDHTHS                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.InvalidHnd' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAPPEDHTSENDIDXOFCANIFCTRLID2MAPPEDHTHS                                               STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsEndIdx' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAPPEDHTSSTARTIDXOFCANIFCTRLID2MAPPEDHTHS                                             STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsStartIdx' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAPPEDHTSUSEDOFCANIFCTRLID2MAPPEDHTHS                                                 STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths.MappedHtsUsed' Reason: 'Bus Mirroring is disabled' */
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                                     STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                         STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_01.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_02.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_03.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_04.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_05.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_06.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_07.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfigRDR_08.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' */
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                        STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                      STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGUSEDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                          STD_ON
#define CANIF_CANTRCVFCTTBL                                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CTRLCONFIG                                                                            STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_BAUDRATECONFIGENDIDXOFCTRLCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigEndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_BAUDRATECONFIGSTARTIDXOFCTRLCONFIG                                                    STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigStartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_BAUDRATECONFIGUSEDOFCTRLCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.BaudrateConfigUsed' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_DEFAULTBAUDRATEIDOFCTRLCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.DefaultBaudrateID' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG                                             STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDT3ENDIDXOFCTRLCONFIG                                          STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDT3STARTIDXOFCTRLCONFIG                                        STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDT3USEDOFCTRLCONFIG                                            STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdt3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDTNOT3ENDIDXOFCTRLCONFIG                                       STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3EndIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDTNOT3STARTIDXOFCTRLCONFIG                                     STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3StartIdx' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXPDUCONFIGCANXLRXPDUSSDTNOT3USEDOFCTRLCONFIG                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxPduConfigCanXLRxPdusSdtNot3Used' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_CTRLMODEINDICATIONFCTPTR                                                              STD_ON
#define CANIF_CTRLSTATES                                                                            STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                                                  STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                                                   STD_ON
#define CANIF_DYNRXID                                                                               STD_OFF  /**< Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSION                                                         STD_ON
#define CANIF_GENERATORVERSION                                                                      STD_ON
#define CANIF_HXHOFFSET                                                                             STD_OFF  /**< Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIG                                                                         STD_ON
#define CANIF_ACTIVETXREQUESTDATAENDIDXOFMAILBOXCONFIG                                              STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestDataEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTDATASTARTIDXOFMAILBOXCONFIG                                            STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestDataStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTDATAUSEDOFMAILBOXCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestDataUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestDataUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTFIFOIDXOFMAILBOXCONFIG                                                 STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestFifoIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTFIFOUSEDOFMAILBOXCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestFifoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestFifoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTINFOENDIDXOFMAILBOXCONFIG                                              STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestInfoEndIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTINFOLENGTHOFMAILBOXCONFIG                                              STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestInfoLength' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTINFOSTARTIDXOFMAILBOXCONFIG                                            STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestInfoStartIdx' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_ACTIVETXREQUESTINFOUSEDOFMAILBOXCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.ActiveTxRequestInfoUsed' Reason: 'the optional indirection is deactivated because ActiveTxRequestInfoUsedOfMailBoxConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                                                          STD_ON
#define CANIF_HTHMAXSDULENOFMAILBOXCONFIG                                                           STD_OFF  /**< Deactivateable: 'CanIf_MailBoxConfigRDR_01.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_02.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_03.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_04.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_05.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_06.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_07.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MailBoxConfigRDR_08.HthMaxSduLen' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                                                             STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                                              STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                         STD_ON
#define CANIF_TXBUFFERCFGOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                        STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                                   STD_ON
#define CANIF_MAPPEDHTS                                                                             STD_OFF  /**< Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDHTS                                                           STD_OFF  /**< Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts.MailBoxConfigIdx' Reason: 'Bus Mirroring is disabled' */
#define CANIF_MAPPEDTXBUFFERSCONFIG                                                                 STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_NUMOFCANXLRXPDUS                                                                      STD_OFF  /**< Deactivateable: 'CanIf_NumOfCanXLRxPdus' Reason: 'CAN XL support is disabled' */
#define CANIF_NUMOFNONCANXLRXPDUS                                                                   STD_OFF  /**< Deactivateable: 'CanIf_NumOfNonCanXLRxPdus' Reason: 'Only CAN 2.0/FD PDUs can be configured' */
#define CANIF_PDURXMODE                                                                             STD_OFF  /**< Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_RXDHADJUST                                                                            STD_OFF  /**< Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' */
#define CANIF_RXINDICATIONFCTLIST                                                                   STD_ON
#define CANIF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                                  STD_ON
#define CANIF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                               STD_ON
#define CANIF_RXPDUCANXLPROPS                                                                       STD_OFF  /**< Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' */
#define CANIF_ACCEPTANCEFIELDOFRXPDUCANXLPROPS                                                      STD_OFF  /**< Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' */
#define CANIF_PRIORITYIDOFRXPDUCANXLPROPS                                                           STD_OFF  /**< Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' */
#define CANIF_SDUTYPEOFRXPDUCANXLPROPS                                                              STD_OFF  /**< Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' */
#define CANIF_VCIDOFRXPDUCANXLPROPS                                                                 STD_OFF  /**< Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' */
#define CANIF_RXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigRDR_01.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_02.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_03.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_04.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_05.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_06.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_07.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_08.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_HASMETADATAITEMCANID32OFRXPDUCONFIG                                                   STD_ON
#define CANIF_ISCANNMRXPDUOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigRDR_01.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_02.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_03.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_04.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_05.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_06.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_07.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_08.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' */
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigRDR_01.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_02.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_03.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_04.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_05.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_06.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_07.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRDR_08.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_MSGTYPEOFRXPDUCONFIG                                                                  STD_ON
#define CANIF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                                   STD_ON
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_RXPDUCANXLPROPSIDXOFRXPDUCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigRDR_01.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_02.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_03.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_04.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_05.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_06.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_07.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_08.RxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_RXPDUCANXLPROPSUSEDOFRXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigRDR_01.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_02.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_03.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_04.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_05.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_06.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_07.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_RxPduConfigRDR_08.RxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because RxPduCanXLPropsUsedOfRxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_RXPDUDLCOFRXPDUCONFIG                                                                 STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                                                STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_SIZEOFACTIVETXREQUESTDATA                                                             STD_OFF  /**< Deactivateable: 'CanIf_SizeOfActiveTxRequestData' Reason: 'Deactivateable: 'ActiveTxRequestData' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFACTIVETXREQUESTFIFO                                                             STD_OFF  /**< Deactivateable: 'CanIf_SizeOfActiveTxRequestFifo' Reason: 'Deactivateable: 'ActiveTxRequestFifo' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFACTIVETXREQUESTINFO                                                             STD_OFF  /**< Deactivateable: 'CanIf_SizeOfActiveTxRequestInfo' Reason: 'Deactivateable: 'ActiveTxRequestInfo' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFBAUDRATECONFIG                                                                  STD_OFF  /**< Deactivateable: 'CanIf_SizeOfBaudrateConfig' Reason: 'Deactivateable: 'BaudrateConfig' Reason: 'Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.''' */
#define CANIF_SIZEOFCANCONTROLLERIDUPTOLOWMAP                                                       STD_OFF  /**< Deactivateable: 'CanIf_SizeOfCanControllerIdUpToLowMap' Reason: 'Deactivateable: 'CanControllerIdUpToLowMap' Reason: 'Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.''' */
#define CANIF_SIZEOFCANDRVFCTTBL                                                                    STD_OFF  /**< Deactivateable: 'CanIf_SizeOfCanDrvFctTbl' Reason: 'Deactivateable: 'CanDrvFctTbl' Reason: 'Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.''' */
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDHTHS                                                          STD_OFF  /**< Deactivateable: 'CanIf_SizeOfCanIfCtrlId2MappedHths' Reason: 'Deactivateable: 'CanIfCtrlId2MappedHths' Reason: 'Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_SIZEOFCANTRCVFCTTBL                                                                   STD_OFF  /**< Deactivateable: 'CanIf_SizeOfCanTrcvFctTbl' Reason: 'Deactivateable: 'CanTrcvFctTbl' Reason: 'Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFCTRLCONFIG                                                                      STD_OFF  /**< Deactivateable: 'CanIf_SizeOfCtrlConfig' Reason: 'Deactivateable: 'CtrlConfig' Reason: 'Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.''' */
#define CANIF_SIZEOFCTRLSTATES                                                                      STD_ON
#define CANIF_SIZEOFDYNRXID                                                                         STD_OFF  /**< Deactivateable: 'CanIf_SizeOfDynRxId' Reason: 'Deactivateable: 'DynRxId' Reason: 'Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define CANIF_SIZEOFHXHOFFSET                                                                       STD_OFF  /**< Deactivateable: 'CanIf_SizeOfHxhOffset' Reason: 'Deactivateable: 'HxhOffset' Reason: 'Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.''' */
#define CANIF_SIZEOFMAILBOXCONFIG                                                                   STD_ON
#define CANIF_SIZEOFMAPPEDHTS                                                                       STD_OFF  /**< Deactivateable: 'CanIf_SizeOfMappedHts' Reason: 'Deactivateable: 'MappedHts' Reason: 'Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                                                           STD_ON
#define CANIF_SIZEOFPDURXMODE                                                                       STD_OFF  /**< Deactivateable: 'CanIf_SizeOfPduRxMode' Reason: 'Deactivateable: 'PduRxMode' Reason: 'Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define CANIF_SIZEOFRXDHADJUST                                                                      STD_OFF  /**< Deactivateable: 'CanIf_SizeOfRxDHAdjust' Reason: 'Deactivateable: 'RxDHAdjust' Reason: 'Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.''' */
#define CANIF_SIZEOFRXINDICATIONFCTLIST                                                             STD_ON
#define CANIF_SIZEOFRXPDUCANXLPROPS                                                                 STD_OFF  /**< Deactivateable: 'CanIf_SizeOfRxPduCanXLProps' Reason: 'Deactivateable: 'RxPduCanXLProps' Reason: 'Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled''' */
#define CANIF_SIZEOFRXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTRANSCEIVERUPTOLOWMAP                                                           STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTransceiverUpToLowMap' Reason: 'Deactivateable: 'TransceiverUpToLowMap' Reason: 'Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFTRANSCEIVERUPTOUPPERMAP                                                         STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTransceiverUpToUpperMap' Reason: 'Deactivateable: 'TransceiverUpToUpperMap' Reason: 'Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFTRCVTOCTRLMAP                                                                   STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTrcvToCtrlMap' Reason: 'Deactivateable: 'TrcvToCtrlMap' Reason: 'Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.''' */
#define CANIF_SIZEOFTXBUFFERFIFOBASE                                                                STD_ON
#define CANIF_SIZEOFTXBUFFERFIFOCONFIG                                                              STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                                                         STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                                                           STD_ON
#define CANIF_SIZEOFTXFIFOQUEUEBASE                                                                 STD_ON
#define CANIF_SIZEOFTXFIFOQUEUEDATA                                                                 STD_ON
#define CANIF_SIZEOFTXPDUCANXLPROPS                                                                 STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTxPduCanXLProps' Reason: 'Deactivateable: 'TxPduCanXLProps' Reason: 'Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled''' */
#define CANIF_SIZEOFTXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                                                 STD_ON
#define CANIF_SIZEOFTXPDUSTATIC2DYNAMICINDIRECTION                                                  STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTxPduStatic2DynamicIndirection' Reason: 'Deactivateable: 'TxPduStatic2DynamicIndirection' Reason: 'Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.''' */
#define CANIF_SIZEOFTXQUEUE                                                                         STD_ON
#define CANIF_SIZEOFTXQUEUEFLAGS                                                                    STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOP                                                      STD_OFF  /**< Deactivateable: 'CanIf_SizeOfTxQueueIndex2DataStartStop' Reason: 'Deactivateable: 'TxQueueIndex2DataStartStop' Reason: 'Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.''' */
#define CANIF_SIZEOFULRXPDUID2INTERNALRXPDUID                                                       STD_OFF  /**< Deactivateable: 'CanIf_SizeOfUlRxPduId2InternalRxPduId' Reason: 'Deactivateable: 'UlRxPduId2InternalRxPduId' Reason: 'Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!''' */
#define CANIF_SIZEOFULTXPDUID2INTERNALTXPDUID                                                       STD_ON
#define CANIF_SIZEOFWAKEUPCONFIG                                                                    STD_OFF  /**< Deactivateable: 'CanIf_SizeOfWakeUpConfig' Reason: 'Deactivateable: 'WakeUpConfig' Reason: 'Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.''' */
#define CANIF_TRANSCEIVERUPTOLOWMAP                                                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVEROFTRANSCEIVERUPTOLOWMAP                                                    STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRCVTOCTRLMAP                                                                         STD_OFF  /**< Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' */
#define CANIF_TXBUFFERFIFOBASE                                                                      STD_ON
#define CANIF_TXBUFFERFIFOCONFIG                                                                    STD_ON
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                                                STD_ON
#define CANIF_TXBUFFERFIFOBASEIDXOFTXBUFFERFIFOCONFIG                                               STD_ON
#define CANIF_TXFIFOQUEUEBASEENDIDXOFTXBUFFERFIFOCONFIG                                             STD_ON
#define CANIF_TXFIFOQUEUEBASELENGTHOFTXBUFFERFIFOCONFIG                                             STD_ON
#define CANIF_TXFIFOQUEUEBASESTARTIDXOFTXBUFFERFIFOCONFIG                                           STD_ON
#define CANIF_TXFIFOQUEUEDATAENDIDXOFTXBUFFERFIFOCONFIG                                             STD_ON
#define CANIF_TXFIFOQUEUEDATASTARTIDXOFTXBUFFERFIFOCONFIG                                           STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDCONFIG                                                             STD_ON
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDCONFIG                                       STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDCONFIG                                 STD_ON
#define CANIF_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDCONFIG                                         STD_ON
#define CANIF_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDCONFIG                                       STD_ON
#define CANIF_TXCONFIRMATIONFCTLIST                                                                 STD_ON
#define CANIF_TXFIFOQUEUEBASE                                                                       STD_ON
#define CANIF_TXFIFOQUEUEDATA                                                                       STD_ON
#define CANIF_TXPDUCANXLPROPS                                                                       STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' */
#define CANIF_ACCEPTANCEFIELDOFTXPDUCANXLPROPS                                                      STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.AcceptanceField' Reason: 'CAN XL support is disabled' */
#define CANIF_CANXLHTHOFTXPDUCANXLPROPS                                                             STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.CanXLHth' Reason: 'CAN XL support is disabled' */
#define CANIF_PRIORITYIDOFTXPDUCANXLPROPS                                                           STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.PriorityId' Reason: 'CAN XL support is disabled' */
#define CANIF_SDUTYPEOFTXPDUCANXLPROPS                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.SduType' Reason: 'CAN XL support is disabled' */
#define CANIF_VCIDOFTXPDUCANXLPROPS                                                                 STD_OFF  /**< Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps.Vcid' Reason: 'CAN XL support is disabled' */
#define CANIF_TXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                                                    STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                                              STD_ON
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                                                            STD_ON
#define CANIF_HASMETADATAITEMCANID32OFTXPDUCONFIG                                                   STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigRDR_01.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_02.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_03.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_04.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_05.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_06.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_07.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_08.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' */
#define CANIF_ISPNWUTXPDUOFTXPDUCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigRDR_01.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_02.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_03.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_04.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_05.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_06.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_07.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRDR_08.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' */
#define CANIF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                        STD_ON
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                         STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                                 STD_ON
#define CANIF_TXPDUCANXLPROPSIDXOFTXPDUCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigRDR_01.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_02.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_03.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_04.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_05.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_06.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_07.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_08.TxPduCanXLPropsIdx' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_TXPDUCANXLPROPSUSEDOFTXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigRDR_01.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_02.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_03.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_04.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_05.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_06.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_07.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanIf_TxPduConfigRDR_08.TxPduCanXLPropsUsed' Reason: 'the optional indirection is deactivated because TxPduCanXLPropsUsedOfTxPduConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANIF_TXPDULENGTHOFTXPDUCONFIG                                                              STD_ON
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                        STD_ON
#define CANIF_TXPDUQUEUEINDEX                                                                       STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                           STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                          STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                                                        STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUE                                                                               STD_ON
#define CANIF_TXQUEUEFLAGS                                                                          STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                                                            STD_OFF  /**< Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' */
#define CANIF_ULRXPDUID2INTERNALRXPDUID                                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' */
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' */
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID                                            STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' */
#define CANIF_ULTXPDUID2INTERNALTXPDUID                                                             STD_ON
#define CANIF_WAKEUPCONFIG                                                                          STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' */
#define CANIF_CONTROLLERIDOFWAKEUPCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.ControllerId' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                                     STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' */
#define CANIF_PCCONFIG                                                                              STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                           STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                                                  STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                               STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                                                            STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                                               STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                       STD_ON
#define CANIF_NUMOFCANXLRXPDUSOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.NumOfCanXLRxPdus' Reason: 'CAN XL support is disabled' */
#define CANIF_NUMOFNONCANXLRXPDUSOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.NumOfNonCanXLRxPdus' Reason: 'Only CAN 2.0/FD PDUs can be configured' */
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                                                         STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_SIZEOFACTIVETXREQUESTDATAOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfActiveTxRequestData' Reason: 'Deactivateable: 'ActiveTxRequestData' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestData' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFACTIVETXREQUESTFIFOOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfActiveTxRequestFifo' Reason: 'Deactivateable: 'ActiveTxRequestFifo' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestFifo' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFACTIVETXREQUESTINFOOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfActiveTxRequestInfo' Reason: 'Deactivateable: 'ActiveTxRequestInfo' Reason: 'Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_ActiveTxRequestInfo' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFBAUDRATECONFIGOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfBaudrateConfig' Reason: 'Deactivateable: 'BaudrateConfig' Reason: 'Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.' and Deactivateable: 'CanIf_BaudrateConfig' Reason: 'Table: CanIf_BaudrateConfig[] is not required.''' */
#define CANIF_SIZEOFCANCONTROLLERIDUPTOLOWMAPOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfCanControllerIdUpToLowMap' Reason: 'Deactivateable: 'CanControllerIdUpToLowMap' Reason: 'Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN Driver support is deactivated.''' */
#define CANIF_SIZEOFCANDRVFCTTBLOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfCanDrvFctTbl' Reason: 'Deactivateable: 'CanDrvFctTbl' Reason: 'Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.''' */
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDHTHSOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfCanIfCtrlId2MappedHths' Reason: 'Deactivateable: 'CanIfCtrlId2MappedHths' Reason: 'Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_CanIfCtrlId2MappedHths' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_SIZEOFCANTRCVFCTTBLOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfCanTrcvFctTbl' Reason: 'Deactivateable: 'CanTrcvFctTbl' Reason: 'Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFCTRLCONFIGOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfCtrlConfig' Reason: 'Deactivateable: 'CtrlConfig' Reason: 'Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.''' */
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_SIZEOFDYNRXIDOFPCCONFIG                                                               STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfDynRxId' Reason: 'Deactivateable: 'DynRxId' Reason: 'Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_DynRxId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define CANIF_SIZEOFHXHOFFSETOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfHxhOffset' Reason: 'Deactivateable: 'HxhOffset' Reason: 'Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.''' */
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                                                         STD_ON
#define CANIF_SIZEOFMAPPEDHTSOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfMappedHts' Reason: 'Deactivateable: 'MappedHts' Reason: 'Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled' and Deactivateable: 'CanIf_MappedHts' Reason: 'Bus Mirroring is disabled''' */
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFPDURXMODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfPduRxMode' Reason: 'Deactivateable: 'PduRxMode' Reason: 'Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define CANIF_SIZEOFRXDHADJUSTOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfRxDHAdjust' Reason: 'Deactivateable: 'RxDHAdjust' Reason: 'Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.''' */
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_SIZEOFRXPDUCANXLPROPSOFPCCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfRxPduCanXLProps' Reason: 'Deactivateable: 'RxPduCanXLProps' Reason: 'Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_RxPduCanXLProps' Reason: 'CAN XL support is disabled''' */
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTRANSCEIVERUPTOLOWMAPOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTransceiverUpToLowMap' Reason: 'Deactivateable: 'TransceiverUpToLowMap' Reason: 'Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFTRANSCEIVERUPTOUPPERMAPOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTransceiverUpToUpperMap' Reason: 'Deactivateable: 'TransceiverUpToUpperMap' Reason: 'Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.''' */
#define CANIF_SIZEOFTRCVTOCTRLMAPOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTrcvToCtrlMap' Reason: 'Deactivateable: 'TrcvToCtrlMap' Reason: 'Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.''' */
#define CANIF_SIZEOFTXBUFFERFIFOBASEOFPCCONFIG                                                      STD_ON
#define CANIF_SIZEOFTXBUFFERFIFOCONFIGOFPCCONFIG                                                    STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDCONFIGOFPCCONFIG                                             STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFTXFIFOQUEUEBASEOFPCCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXFIFOQUEUEDATAOFPCCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXPDUCANXLPROPSOFPCCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTxPduCanXLProps' Reason: 'Deactivateable: 'TxPduCanXLProps' Reason: 'Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled' and Deactivateable: 'CanIf_TxPduCanXLProps' Reason: 'CAN XL support is disabled''' */
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXPDUSTATIC2DYNAMICINDIRECTIONOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTxPduStatic2DynamicIndirection' Reason: 'Deactivateable: 'TxPduStatic2DynamicIndirection' Reason: 'Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.''' */
#define CANIF_SIZEOFTXQUEUEFLAGSOFPCCONFIG                                                          STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfTxQueueIndex2DataStartStop' Reason: 'Deactivateable: 'TxQueueIndex2DataStartStop' Reason: 'Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx buffer is deactivated.''' */
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_SIZEOFULRXPDUID2INTERNALRXPDUIDOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfUlRxPduId2InternalRxPduId' Reason: 'Deactivateable: 'UlRxPduId2InternalRxPduId' Reason: 'Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile or the features Rx PDU reception mode and dynamic Rx PDU are disabled!''' */
#define CANIF_SIZEOFULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                             STD_ON
#define CANIF_SIZEOFWAKEUPCONFIGOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.SizeOfWakeUpConfig' Reason: 'Deactivateable: 'WakeUpConfig' Reason: 'Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' and Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.''' */
#define CANIF_TXBUFFERFIFOBASEOFPCCONFIG                                                            STD_ON
#define CANIF_TXBUFFERFIFOCONFIGOFPCCONFIG                                                          STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                     STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDCONFIGOFPCCONFIG                                                   STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                       STD_ON
#define CANIF_TXFIFOQUEUEBASEOFPCCONFIG                                                             STD_ON
#define CANIF_TXFIFOQUEUEDATAOFPCCONFIG                                                             STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                                                             STD_ON
#define CANIF_TXQUEUEFLAGSOFPCCONFIG                                                                STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                                                     STD_ON
#define CANIF_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMinNumericValueDefines  CanIf Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANIF_MIN_TXFIFOQUEUEDATA                                                                   0u
#define CANIF_MIN_TXQUEUEFLAGS                                                                      0u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMaxNumericValueDefines  CanIf Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANIF_MAX_TXFIFOQUEUEDATA                                                                   255u
#define CANIF_MAX_TXQUEUEFLAGS                                                                      4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCNoReferenceDefines  CanIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANIF_NO_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                     255u
#define CANIF_NO_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                   255u
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                      255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumExistsDefines  CanIf Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANIF_EXISTS_TXBUFFERFIFOCONFIG_TXBUFFERCFGOFMAILBOXCONFIG                                  STD_ON
#define CANIF_EXISTS_TXBUFFERPRIOBYCANIDCONFIG_TXBUFFERCFGOFMAILBOXCONFIG                           STD_ON
#define CANIF_EXISTS_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumDefines  CanIf Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANIF_TXBUFFERFIFOCONFIG_TXBUFFERCFGOFMAILBOXCONFIG                                         0x00u
#define CANIF_TXBUFFERPRIOBYCANIDCONFIG_TXBUFFERCFGOFMAILBOXCONFIG                                  0x01u
#define CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                         0xFFu
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGUSEDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                    STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                                                    STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                                                       STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                                                        STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                             STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                         STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                            STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                         STD_OFF
#define CANIF_ISDEF_HASMETADATAITEMCANID32OFRXPDUCONFIG                                             STD_OFF
#define CANIF_ISDEF_MSGTYPEOFRXPDUCONFIG                                                            STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                             STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_RXPDUDLCOFRXPDUCONFIG                                                           STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                                                          STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                                          STD_OFF
#define CANIF_ISDEF_TXBUFFERFIFOBASEIDXOFTXBUFFERFIFOCONFIG                                         STD_OFF
#define CANIF_ISDEF_TXFIFOQUEUEBASEENDIDXOFTXBUFFERFIFOCONFIG                                       STD_OFF
#define CANIF_ISDEF_TXFIFOQUEUEBASELENGTHOFTXBUFFERFIFOCONFIG                                       STD_OFF
#define CANIF_ISDEF_TXFIFOQUEUEBASESTARTIDXOFTXBUFFERFIFOCONFIG                                     STD_OFF
#define CANIF_ISDEF_TXFIFOQUEUEDATAENDIDXOFTXBUFFERFIFOCONFIG                                       STD_OFF
#define CANIF_ISDEF_TXFIFOQUEUEDATASTARTIDXOFTXBUFFERFIFOCONFIG                                     STD_OFF
#define CANIF_ISDEF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDCONFIG                                 STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDCONFIG                           STD_OFF
#define CANIF_ISDEF_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDCONFIG                                   STD_OFF
#define CANIF_ISDEF_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDCONFIG                                 STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                                                           STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                                              STD_OFF
#define CANIF_ISDEF_CANIDTXMASKOFTXPDUCONFIG                                                        STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                                                      STD_OFF
#define CANIF_ISDEF_HASMETADATAITEMCANID32OFTXPDUCONFIG                                             STD_OFF
#define CANIF_ISDEF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                           STD_OFF
#define CANIF_ISDEF_TXPDULENGTHOFTXPDUCONFIG                                                        STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                     STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                    STD_OFF
#define CANIF_ISDEF_ULTXPDUID2INTERNALTXPDUID                                                       STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                                                         STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                                                           STD_OFF
#define CANIF_ISDEF_SIZEOFRXPDUCONFIGOFPCCONFIG                                                     STD_OFF
#define CANIF_ISDEF_SIZEOFTXFIFOQUEUEBASEOFPCCONFIG                                                 STD_OFF
#define CANIF_ISDEF_SIZEOFTXFIFOQUEUEDATAOFPCCONFIG                                                 STD_OFF
#define CANIF_ISDEF_SIZEOFTXPDUCONFIGOFPCCONFIG                                                     STD_OFF
#define CANIF_ISDEF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                                                 STD_OFF
#define CANIF_ISDEF_SIZEOFULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                       STD_OFF
#define CANIF_ISDEF_TXBUFFERFIFOBASEOFPCCONFIG                                                      STD_ON
#define CANIF_ISDEF_TXBUFFERFIFOCONFIGOFPCCONFIG                                                    STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDCONFIGOFPCCONFIG                                             STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_TXFIFOQUEUEBASEOFPCCONFIG                                                       STD_ON
#define CANIF_ISDEF_TXFIFOQUEUEDATAOFPCCONFIG                                                       STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                                                           STD_OFF
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_ISDEF_TXQUEUEFLAGSOFPCCONFIG                                                          STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_ISDEF_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEqualsAlwaysToDefines  CanIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                    
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGUSEDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                      
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                                                      
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                                                         
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                                                          
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                     
#define CANIF_EQ2_TXBUFFERCFGOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                    
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                               
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                           
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                              
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                           
#define CANIF_EQ2_HASMETADATAITEMCANID32OFRXPDUCONFIG                                               
#define CANIF_EQ2_MSGTYPEOFRXPDUCONFIG                                                              
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                               
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_RXPDUDLCOFRXPDUCONFIG                                                             
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG                                                            
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                                            
#define CANIF_EQ2_TXBUFFERFIFOBASEIDXOFTXBUFFERFIFOCONFIG                                           
#define CANIF_EQ2_TXFIFOQUEUEBASEENDIDXOFTXBUFFERFIFOCONFIG                                         
#define CANIF_EQ2_TXFIFOQUEUEBASELENGTHOFTXBUFFERFIFOCONFIG                                         
#define CANIF_EQ2_TXFIFOQUEUEBASESTARTIDXOFTXBUFFERFIFOCONFIG                                       
#define CANIF_EQ2_TXFIFOQUEUEDATAENDIDXOFTXBUFFERFIFOCONFIG                                         
#define CANIF_EQ2_TXFIFOQUEUEDATASTARTIDXOFTXBUFFERFIFOCONFIG                                       
#define CANIF_EQ2_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDCONFIG                                   
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDCONFIG                             
#define CANIF_EQ2_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDCONFIG                                     
#define CANIF_EQ2_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDCONFIG                                   
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                                                             
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                                                
#define CANIF_EQ2_CANIDTXMASKOFTXPDUCONFIG                                                          
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                                                        
#define CANIF_EQ2_HASMETADATAITEMCANID32OFTXPDUCONFIG                                               
#define CANIF_EQ2_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                    
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                     
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                             
#define CANIF_EQ2_TXPDULENGTHOFTXPDUCONFIG                                                          
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                    
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                       
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                      
#define CANIF_EQ2_ULTXPDUID2INTERNALTXPDUID                                                         
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                (&(CanIf_BusOffNotificationFctPtr))
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                       CanIf_CanIfCtrlId2MappedTxBuffersConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                (&(CanIf_CtrlModeIndicationFctPtr))
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                                              CanIf_CtrlStates.raw
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                                                           
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                   CanIf_MappedTxBuffersConfig
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                                                     CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                                                             
#define CANIF_EQ2_SIZEOFRXPDUCONFIGOFPCCONFIG                                                       
#define CANIF_EQ2_SIZEOFTXFIFOQUEUEBASEOFPCCONFIG                                                   
#define CANIF_EQ2_SIZEOFTXFIFOQUEUEDATAOFPCCONFIG                                                   
#define CANIF_EQ2_SIZEOFTXPDUCONFIGOFPCCONFIG                                                       
#define CANIF_EQ2_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                                                   
#define CANIF_EQ2_SIZEOFULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                         
#define CANIF_EQ2_TXBUFFERFIFOBASEOFPCCONFIG                                                        CanIf_TxBufferFifoBase.raw
#define CANIF_EQ2_TXBUFFERFIFOCONFIGOFPCCONFIG                                                      
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                 CanIf_TxBufferPrioByCanIdBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDCONFIGOFPCCONFIG                                               CanIf_TxBufferPrioByCanIdConfig
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                   CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXFIFOQUEUEBASEOFPCCONFIG                                                         CanIf_TxFifoQueueBase.raw
#define CANIF_EQ2_TXFIFOQUEUEDATAOFPCCONFIG                                                         CanIf_TxFifoQueueData.raw
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                                                             
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                                                         CanIf_TxPduQueueIndex
#define CANIF_EQ2_TXQUEUEFLAGSOFPCCONFIG                                                            CanIf_TxQueueFlags.raw
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                                                 CanIf_TxQueue.raw
#define CANIF_EQ2_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                               
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicInitializationPointers  CanIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanIf_Config_RDR_01_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_01)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_02_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_02)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_03_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_03)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_04_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_04)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_05_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_05)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_06_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_06)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_07_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_07)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_RDR_08_Ptr                                                                     &(CanIf_PCConfig.Config_RDR_08)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCInitializationSymbols  CanIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanIf_Config_RDR_01                                                                         CanIf_PCConfig.Config_RDR_01  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_02                                                                         CanIf_PCConfig.Config_RDR_02  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_03                                                                         CanIf_PCConfig.Config_RDR_03  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_04                                                                         CanIf_PCConfig.Config_RDR_04  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_05                                                                         CanIf_PCConfig.Config_RDR_05  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_06                                                                         CanIf_PCConfig.Config_RDR_06  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_07                                                                         CanIf_PCConfig.Config_RDR_07  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_RDR_08                                                                         CanIf_PCConfig.Config_RDR_08  /**< symbolic identifier which could be used to initialize 'CanIf */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGeneral  CanIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANIF_CHECK_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANIF_FINAL_MAGIC_NUMBER                                                                    0x3C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanIf */
#define CANIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanIf' is not configured to be postbuild capable. */
#define CANIF_INIT_DATA                                                                             CANIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANIF_INIT_DATA_HASH_CODE                                                                   -1038733679  /**< the precompile constant to validate the initialization structure at initialization time of CanIf with a hashcode. The seed value is '0x3C1Eu' */
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANIF_USE_INIT_POINTER                                                                      STD_ON  /**< STD_ON if the init pointer CanIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPBDataSwitches  CanIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CanIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



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
  \defgroup  CanIfPCGetRootDataMacros  CanIf Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanIf_GetMailBoxConfigOfPCConfig()                                                          CanIf_ConfigDataPtr->MailBoxConfigOfPCConfig
#define CanIf_GetRxPduConfigOfPCConfig()                                                            CanIf_ConfigDataPtr->RxPduConfigOfPCConfig
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                                                      CanIf_ConfigDataPtr->SizeOfRxPduConfigOfPCConfig
#define CanIf_GetSizeOfTxFifoQueueBaseOfPCConfig()                                                  CanIf_ConfigDataPtr->SizeOfTxFifoQueueBaseOfPCConfig
#define CanIf_GetSizeOfTxFifoQueueDataOfPCConfig()                                                  CanIf_ConfigDataPtr->SizeOfTxFifoQueueDataOfPCConfig
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                                                      CanIf_ConfigDataPtr->SizeOfTxPduConfigOfPCConfig
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                                                  CanIf_ConfigDataPtr->SizeOfTxPduQueueIndexOfPCConfig
#define CanIf_GetSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()                                        CanIf_ConfigDataPtr->SizeOfUlTxPduId2InternalTxPduIdOfPCConfig
#define CanIf_GetTxBufferFifoConfigOfPCConfig()                                                     CanIf_ConfigDataPtr->TxBufferFifoConfigOfPCConfig
#define CanIf_GetTxPduConfigOfPCConfig()                                                            CanIf_ConfigDataPtr->TxPduConfigOfPCConfig
#define CanIf_GetUlTxPduId2InternalTxPduIdOfPCConfig()                                              CanIf_ConfigDataPtr->UlTxPduId2InternalTxPduIdOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetConstantDuplicatedRootDataMacros  CanIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                                               (&(CanIf_BusOffNotificationFctPtr))  /**< the pointer to CanIf_BusOffNotificationFctPtr */
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      CanIf_CanIfCtrlId2MappedTxBuffersConfig  /**< the pointer to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                                               (&(CanIf_CtrlModeIndicationFctPtr))  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                                                             CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()                                          0x0302u
#define CanIf_GetGeneratorVersionOfPCConfig()                                                       0x00090001u
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                                                  CanIf_MappedTxBuffersConfig  /**< the pointer to CanIf_MappedTxBuffersConfig */
#define CanIf_GetRxIndicationFctListOfPCConfig()                                                    CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                2u  /**< the number of accomplishable value elements in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                                                    4u  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()                                            2u  /**< the number of accomplishable value elements in CanIf_MappedTxBuffersConfig */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                                              5u  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfTxBufferFifoBaseOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in CanIf_TxBufferFifoBase */
#define CanIf_GetSizeOfTxBufferFifoConfigOfPCConfig()                                               1u  /**< the number of accomplishable value elements in CanIf_TxBufferFifoConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetSizeOfTxBufferPrioByCanIdConfigOfPCConfig()                                        1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdConfig */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()                                            5u  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxQueueFlagsOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in CanIf_TxQueueFlags */
#define CanIf_GetSizeOfTxQueueOfPCConfig()                                                          25u  /**< the number of accomplishable value elements in CanIf_TxQueue */
#define CanIf_GetTxBufferFifoBaseOfPCConfig()                                                       CanIf_TxBufferFifoBase.raw  /**< the pointer to CanIf_TxBufferFifoBase */
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                                                CanIf_TxBufferPrioByCanIdBase.raw  /**< the pointer to CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetTxBufferPrioByCanIdConfigOfPCConfig()                                              CanIf_TxBufferPrioByCanIdConfig  /**< the pointer to CanIf_TxBufferPrioByCanIdConfig */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                                                  CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxFifoQueueBaseOfPCConfig()                                                        CanIf_TxFifoQueueBase.raw  /**< the pointer to CanIf_TxFifoQueueBase */
#define CanIf_GetTxFifoQueueDataOfPCConfig()                                                        CanIf_TxFifoQueueData.raw  /**< the pointer to CanIf_TxFifoQueueData */
#define CanIf_GetTxPduQueueIndexOfPCConfig()                                                        CanIf_TxPduQueueIndex  /**< the pointer to CanIf_TxPduQueueIndex */
#define CanIf_GetTxQueueFlagsOfPCConfig()                                                           CanIf_TxQueueFlags.raw  /**< the pointer to CanIf_TxQueueFlags */
#define CanIf_GetTxQueueOfPCConfig()                                                                CanIf_TxQueue.raw  /**< the pointer to CanIf_TxQueue */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDataMacros  CanIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtr()                                                         ((*(CanIf_GetBusOffNotificationFctPtrOfPCConfig())))
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)              (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)            (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                                                         ((*(CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())))
#define CanIf_GetCtrlModeOfCtrlStates(Index)                                                        (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                                                         (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                                                (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                                                   (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                                                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                                               (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferCfgOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)                                         (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)                                     (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)                                        (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)                                     (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_IsHasMetaDataItemCanId32OfRxPduConfig(Index)                                          ((CanIf_GetRxPduConfigOfPCConfig()[(Index)].HasMetaDataItemCanId32OfRxPduConfig) != FALSE)
#define CanIf_GetMsgTypeOfRxPduConfig(Index)                                                        (CanIf_GetRxPduConfigOfPCConfig()[(Index)].MsgTypeOfRxPduConfig)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)                                         (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduDlcOfRxPduConfig(Index)                                                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduDlcOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                                                      (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTxBufferFifoBase(Index)                                                            (CanIf_GetTxBufferFifoBaseOfPCConfig()[(Index)])
#define CanIf_GetSizeOfOnePayloadElOfTxBufferFifoConfig(Index)                                      (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].SizeOfOnePayloadElOfTxBufferFifoConfig)
#define CanIf_GetTxBufferFifoBaseIdxOfTxBufferFifoConfig(Index)                                     (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxBufferFifoBaseIdxOfTxBufferFifoConfig)
#define CanIf_GetTxFifoQueueBaseEndIdxOfTxBufferFifoConfig(Index)                                   (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxFifoQueueBaseEndIdxOfTxBufferFifoConfig)
#define CanIf_GetTxFifoQueueBaseLengthOfTxBufferFifoConfig(Index)                                   (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxFifoQueueBaseLengthOfTxBufferFifoConfig)
#define CanIf_GetTxFifoQueueBaseStartIdxOfTxBufferFifoConfig(Index)                                 (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxFifoQueueBaseStartIdxOfTxBufferFifoConfig)
#define CanIf_GetTxFifoQueueDataEndIdxOfTxBufferFifoConfig(Index)                                   (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxFifoQueueDataEndIdxOfTxBufferFifoConfig)
#define CanIf_GetTxFifoQueueDataStartIdxOfTxBufferFifoConfig(Index)                                 (CanIf_GetTxBufferFifoConfigOfPCConfig()[(Index)].TxFifoQueueDataStartIdxOfTxBufferFifoConfig)
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                                                     (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetBitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfig(Index)                             (CanIf_GetTxBufferPrioByCanIdConfigOfPCConfig()[(Index)].BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfig)
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfig(Index)                       (CanIf_GetTxBufferPrioByCanIdConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfig)
#define CanIf_GetTxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfig(Index)                               (CanIf_GetTxBufferPrioByCanIdConfigOfPCConfig()[(Index)].TxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfig)
#define CanIf_GetTxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfig(Index)                             (CanIf_GetTxBufferPrioByCanIdConfigOfPCConfig()[(Index)].TxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfig)
#define CanIf_GetTxConfirmationFctList(Index)                                                       (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetTxFifoQueueBase(Index)                                                             (CanIf_GetTxFifoQueueBaseOfPCConfig()[(Index)])
#define CanIf_GetTxFifoQueueData(Index)                                                             (CanIf_GetTxFifoQueueDataOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                                                          (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCanIdTxMaskOfTxPduConfig(Index)                                                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdTxMaskOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                                                  (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_IsHasMetaDataItemCanId32OfTxPduConfig(Index)                                          ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].HasMetaDataItemCanId32OfTxPduConfig) != FALSE)
#define CanIf_IsIsTxPduTruncationOfTxPduConfig(Index)                                               ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsTxPduTruncationOfTxPduConfig) != FALSE)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                                               (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)                                       (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetTxPduLengthOfTxPduConfig(Index)                                                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxPduLengthOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                                              (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                                                 (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                                                     (CanIf_GetTxQueueOfPCConfig()[(Index)])
#define CanIf_GetTxQueueFlags(Index)                                                                (CanIf_GetTxQueueFlagsOfPCConfig()[(Index)])
#define CanIf_GetUlTxPduId2InternalTxPduId(Index)                                                   (CanIf_GetUlTxPduId2InternalTxPduIdOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDeduplicatedDataMacros  CanIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanIf_IsMappedTxBuffersConfigUsedOfCanIfCtrlId2MappedTxBuffersConfig(Index)                 (((boolean)(CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) != CANIF_NO_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanIf_MappedTxBuffersConfig */
#define CanIf_GetGeneratorCompatibilityVersion()                                                    CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                                                 CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                                               (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                                                 CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                                              CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                                                      CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                                                        CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                                                CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferFifoBase()                                                           CanIf_GetSizeOfTxBufferFifoBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferFifoConfig()                                                         CanIf_GetSizeOfTxBufferFifoConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                                                    CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdConfig()                                                  CanIf_GetSizeOfTxBufferPrioByCanIdConfigOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                                                      CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxFifoQueueBase()                                                            CanIf_GetSizeOfTxFifoQueueBaseOfPCConfig()
#define CanIf_GetSizeOfTxFifoQueueData()                                                            CanIf_GetSizeOfTxFifoQueueDataOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                                                CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                                                            CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                                                    CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_GetSizeOfTxQueueFlags()                                                               CanIf_GetSizeOfTxQueueFlagsOfPCConfig()
#define CanIf_GetSizeOfUlTxPduId2InternalTxPduId()                                                  CanIf_GetSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                                                 (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueue */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSetDataMacros  CanIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                                                  CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetTxBufferFifoBase(Index, Value)                                                     CanIf_GetTxBufferFifoBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxFifoQueueBase(Index, Value)                                                      CanIf_GetTxFifoQueueBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxFifoQueueData(Index, Value)                                                      CanIf_GetTxFifoQueueDataOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                                              CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueueFlags(Index, Value)                                                         CanIf_GetTxQueueFlagsOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetAddressOfDataMacros  CanIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanIf_GetAddrTxFifoQueueData(Index)                                                         (&CanIf_GetTxFifoQueueData(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                                                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig()                   (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig()                 (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigUsedOfCanIfCtrlId2MappedTxBuffersConfig()                     (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                                                       (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                                                             (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                                              (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                                                    (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                                                 (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                                                    (CanIf_GetMailBoxConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                                                     (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                                                        (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                                                         (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxBufferCfgOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                                              (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                                                            (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                                              (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()                                          (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                                                      (CanIf_GetRxPduConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasHasMetaDataItemCanId32OfRxPduConfig()                                              (TRUE != FALSE)
#define CanIf_HasMsgTypeOfRxPduConfig()                                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                                              (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasRxPduDlcOfRxPduConfig()                                                            (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                                                           (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                                              (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                                                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferFifoBase()                                                           (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferFifoConfig()                                                         (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxFifoQueueBase()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxFifoQueueData()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueFlags()                                                               (TRUE != FALSE)
#define CanIf_HasSizeOfUlTxPduId2InternalTxPduId()                                                  (TRUE != FALSE)
#define CanIf_HasTxBufferFifoBase()                                                                 (TRUE != FALSE)
#define CanIf_HasTxBufferFifoConfig()                                                               (CanIf_GetTxBufferFifoConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasSizeOfOnePayloadElOfTxBufferFifoConfig()                                           (TRUE != FALSE)
#define CanIf_HasTxBufferFifoBaseIdxOfTxBufferFifoConfig()                                          (TRUE != FALSE)
#define CanIf_HasTxFifoQueueBaseEndIdxOfTxBufferFifoConfig()                                        (TRUE != FALSE)
#define CanIf_HasTxFifoQueueBaseLengthOfTxBufferFifoConfig()                                        (TRUE != FALSE)
#define CanIf_HasTxFifoQueueBaseStartIdxOfTxBufferFifoConfig()                                      (TRUE != FALSE)
#define CanIf_HasTxFifoQueueDataEndIdxOfTxBufferFifoConfig()                                        (TRUE != FALSE)
#define CanIf_HasTxFifoQueueDataStartIdxOfTxBufferFifoConfig()                                      (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                                                          (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdConfig()                                                        (TRUE != FALSE)
#define CanIf_HasBitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfig()                                  (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfig()                            (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfig()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfig()                                  (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                                                            (TRUE != FALSE)
#define CanIf_HasTxFifoQueueBase()                                                                  (TRUE != FALSE)
#define CanIf_HasTxFifoQueueData()                                                                  (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                                                      (CanIf_GetTxPduConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasCanIdOfTxPduConfig()                                                               (TRUE != FALSE)
#define CanIf_HasCanIdTxMaskOfTxPduConfig()                                                         (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                                                       (TRUE != FALSE)
#define CanIf_HasHasMetaDataItemCanId32OfTxPduConfig()                                              (TRUE != FALSE)
#define CanIf_HasIsTxPduTruncationOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()                                            (TRUE != FALSE)
#define CanIf_HasTxPduLengthOfTxPduConfig()                                                         (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                                                  (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                                                      (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                                                     (TRUE != FALSE)
#define CanIf_HasTxQueue()                                                                          (TRUE != FALSE)
#define CanIf_HasTxQueueFlags()                                                                     (TRUE != FALSE)
#define CanIf_HasUlTxPduId2InternalTxPduId()                                                        (CanIf_GetUlTxPduId2InternalTxPduIdOfPCConfig() != NULL_PTR)
#define CanIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                                                             (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                                              (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferFifoBaseOfPCConfig()                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferFifoConfigOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdConfigOfPCConfig()                                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxFifoQueueBaseOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxFifoQueueDataOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueFlagsOfPCConfig()                                                     (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()                                        (TRUE != FALSE)
#define CanIf_HasTxBufferFifoBaseOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasTxBufferFifoConfigOfPCConfig()                                                     (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                                                (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdConfigOfPCConfig()                                              (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasTxFifoQueueBaseOfPCConfig()                                                        (TRUE != FALSE)
#define CanIf_HasTxFifoQueueDataOfPCConfig()                                                        (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                                                        (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsOfPCConfig()                                                           (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                                                (TRUE != FALSE)
#define CanIf_HasUlTxPduId2InternalTxPduIdOfPCConfig()                                              (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIncrementDataMacros  CanIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanIf_IncCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncTxBufferFifoBase(Index)                                                            CanIf_GetTxBufferFifoBase(Index)++
#define CanIf_IncTxFifoQueueBase(Index)                                                             CanIf_GetTxFifoQueueBase(Index)++
#define CanIf_IncTxFifoQueueData(Index)                                                             CanIf_GetTxFifoQueueData(Index)++
#define CanIf_IncTxQueueFlags(Index)                                                                CanIf_GetTxQueueFlags(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCDecrementDataMacros  CanIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanIf_DecCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecTxBufferFifoBase(Index)                                                            CanIf_GetTxBufferFifoBase(Index)--
#define CanIf_DecTxFifoQueueBase(Index)                                                             CanIf_GetTxFifoQueueBase(Index)--
#define CanIf_DecTxFifoQueueData(Index)                                                             CanIf_GetTxFifoQueueData(Index)--
#define CanIf_DecTxQueueFlags(Index)                                                                CanIf_GetTxQueueFlags(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCAddDataMacros  CanIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanIf_AddCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) + Value))
#define CanIf_AddPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) + Value))
#define CanIf_AddTxBufferFifoBase(Index, Value)                                                     CanIf_SetTxBufferFifoBase(Index, (CanIf_GetTxBufferFifoBase(Index) + Value))
#define CanIf_AddTxFifoQueueBase(Index, Value)                                                      CanIf_SetTxFifoQueueBase(Index, (CanIf_GetTxFifoQueueBase(Index) + Value))
#define CanIf_AddTxFifoQueueData(Index, Value)                                                      CanIf_SetTxFifoQueueData(Index, (CanIf_GetTxFifoQueueData(Index) + Value))
#define CanIf_AddTxQueueFlags(Index, Value)                                                         CanIf_SetTxQueueFlags(Index, (CanIf_GetTxQueueFlags(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSubstractDataMacros  CanIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanIf_SubCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) - Value))
#define CanIf_SubPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) - Value))
#define CanIf_SubTxBufferFifoBase(Index, Value)                                                     CanIf_SetTxBufferFifoBase(Index, (CanIf_GetTxBufferFifoBase(Index) - Value))
#define CanIf_SubTxFifoQueueBase(Index, Value)                                                      CanIf_SetTxFifoQueueBase(Index, (CanIf_GetTxFifoQueueBase(Index) - Value))
#define CanIf_SubTxFifoQueueData(Index, Value)                                                      CanIf_SetTxFifoQueueData(Index, (CanIf_GetTxFifoQueueData(Index) - Value))
#define CanIf_SubTxQueueFlags(Index, Value)                                                         CanIf_SetTxQueueFlags(Index, (CanIf_GetTxQueueFlags(Index) - Value))
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCSizeOfTypes  CanIf SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfMappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferFifoBase */
typedef uint8 CanIf_SizeOfTxBufferFifoBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferFifoConfig */
typedef uint8 CanIf_SizeOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBase */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdConfig */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxFifoQueueBase */
typedef uint8 CanIf_SizeOfTxFifoQueueBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxFifoQueueData */
typedef uint16 CanIf_SizeOfTxFifoQueueDataType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduQueueIndex */
typedef uint8 CanIf_SizeOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueue */
typedef uint8 CanIf_SizeOfTxQueueType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueFlags */
typedef uint8 CanIf_SizeOfTxQueueFlagsType;

/**   \brief  value based type definition for CanIf_SizeOfUlTxPduId2InternalTxPduId */
typedef uint8 CanIf_SizeOfUlTxPduId2InternalTxPduIdType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCIterableTypes  CanIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef uint8_least CanIf_CanIfCtrlId2MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_MappedTxBuffersConfig */
typedef uint8_least CanIf_MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferFifoBase */
typedef uint8_least CanIf_TxBufferFifoBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferFifoConfig */
typedef uint8_least CanIf_TxBufferFifoConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBase */
typedef uint8_least CanIf_TxBufferPrioByCanIdBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdConfig */
typedef uint8_least CanIf_TxBufferPrioByCanIdConfigIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxFifoQueueBase */
typedef uint8_least CanIf_TxFifoQueueBaseIterType;

/**   \brief  type used to iterate CanIf_TxFifoQueueData */
typedef uint16_least CanIf_TxFifoQueueDataIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxPduQueueIndex */
typedef uint8_least CanIf_TxPduQueueIndexIterType;

/**   \brief  type used to iterate CanIf_TxQueue */
typedef uint8_least CanIf_TxQueueIterType;

/**   \brief  type used to iterate CanIf_TxQueueFlags */
typedef uint8_least CanIf_TxQueueFlagsIterType;

/**   \brief  type used to iterate CanIf_UlTxPduId2InternalTxPduId */
typedef uint8_least CanIf_UlTxPduId2InternalTxPduIdIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCValueTypes  CanIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigUsedOfCanIfCtrlId2MappedTxBuffersConfig */
typedef boolean CanIf_MappedTxBuffersConfigUsedOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_GeneratorCompatibilityVersion */
typedef uint16 CanIf_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanIf_GeneratorVersion */
typedef uint32 CanIf_GeneratorVersionType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfMailBoxConfig */
typedef uint8 CanIf_CtrlStatesIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdFirstOfMailBoxConfig */
typedef uint8 CanIf_PduIdFirstOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdLastOfMailBoxConfig */
typedef uint8 CanIf_PduIdLastOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgIdxOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgUsedOfMailBoxConfig */
typedef boolean CanIf_TxBufferCfgUsedOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferHandlingTypeOfMailBoxConfig */
typedef uint8 CanIf_TxBufferHandlingTypeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfMappedTxBuffersConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_HasMetaDataItemCanId32OfRxPduConfig */
typedef boolean CanIf_HasMetaDataItemCanId32OfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxIndicationFctListIdxOfRxPduConfig */
typedef uint8 CanIf_RxIndicationFctListIdxOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduCanIdOfRxPduConfig */
typedef uint32 CanIf_RxPduCanIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduDlcOfRxPduConfig */
typedef uint8 CanIf_RxPduDlcOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduMaskOfRxPduConfig */
typedef uint32 CanIf_RxPduMaskOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperPduIdOfRxPduConfig */
typedef PduIdType CanIf_UpperPduIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfOnePayloadElOfTxBufferFifoConfig */
typedef uint8 CanIf_SizeOfOnePayloadElOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxBufferFifoBaseIdxOfTxBufferFifoConfig */
typedef uint8 CanIf_TxBufferFifoBaseIdxOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueBaseEndIdxOfTxBufferFifoConfig */
typedef uint8 CanIf_TxFifoQueueBaseEndIdxOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueBaseLengthOfTxBufferFifoConfig */
typedef uint8 CanIf_TxFifoQueueBaseLengthOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueBaseStartIdxOfTxBufferFifoConfig */
typedef uint8 CanIf_TxFifoQueueBaseStartIdxOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueDataEndIdxOfTxBufferFifoConfig */
typedef uint16 CanIf_TxFifoQueueDataEndIdxOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueDataStartIdxOfTxBufferFifoConfig */
typedef uint16 CanIf_TxFifoQueueDataStartIdxOfTxBufferFifoConfigType;

/**   \brief  value based type definition for CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfig */
typedef uint8 CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfigType;

/**   \brief  value based type definition for CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfig */
typedef uint8 CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfigType;

/**   \brief  value based type definition for CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfig */
typedef uint8 CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfigType;

/**   \brief  value based type definition for CanIf_TxFifoQueueData */
typedef uint8 CanIf_TxFifoQueueDataType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint32 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CanIdTxMaskOfTxPduConfig */
typedef uint32 CanIf_CanIdTxMaskOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_HasMetaDataItemCanId32OfTxPduConfig */
typedef boolean CanIf_HasMetaDataItemCanId32OfTxPduConfigType;

/**   \brief  value based type definition for CanIf_IsTxPduTruncationOfTxPduConfig */
typedef boolean CanIf_IsTxPduTruncationOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfTxPduConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxConfirmationFctListIdxOfTxPduConfig */
typedef uint8 CanIf_TxConfirmationFctListIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxPduLengthOfTxPduConfig */
typedef uint8 CanIf_TxPduLengthOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperLayerTxPduIdOfTxPduConfig */
typedef PduIdType CanIf_UpperLayerTxPduIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxQueueIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueFlags */
typedef uint32 CanIf_TxQueueFlagsType;

/**   \brief  value based type definition for CanIf_UlTxPduId2InternalTxPduId */
typedef uint8 CanIf_UlTxPduId2InternalTxPduIdType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCStructTypes  CanIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef struct sCanIf_CanIfCtrlId2MappedTxBuffersConfigType
{
  CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the end index of the 0:n relation pointing to CanIf_MappedTxBuffersConfig */
  CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the start index of the 0:n relation pointing to CanIf_MappedTxBuffersConfig */
} CanIf_CanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_CtrlStates */
typedef struct sCanIf_CtrlStatesType
{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;  /**< Controller mode. */
  CanIf_PduGetModeType PduModeOfCtrlStates;  /**< PDU mode state. */
} CanIf_CtrlStatesType;

/**   \brief  type used in CanIf_MailBoxConfig */
typedef struct sCanIf_MailBoxConfigType
{
  CanIf_CtrlStatesIdxOfMailBoxConfigType CtrlStatesIdxOfMailBoxConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_PduIdFirstOfMailBoxConfigType PduIdFirstOfMailBoxConfig;  /**< "First" PDU mapped to the mailbox. */
  CanIf_PduIdLastOfMailBoxConfigType PduIdLastOfMailBoxConfig;  /**< "Last" PDU mapped to the mailbox. */
  CanIf_TxBufferCfgOfMailBoxConfigType TxBufferCfgOfMailBoxConfig;  /**< the enum value of the according target of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig */
  CanIf_TxBufferCfgIdxOfMailBoxConfigType TxBufferCfgIdxOfMailBoxConfig;  /**< the index of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig */
  CanIf_TxBufferHandlingTypeOfMailBoxConfigType TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of the mailbox: Rx-/Tx- BasicCAN/FullCAN/Unused. */
} CanIf_MailBoxConfigType;

/**   \brief  type used in CanIf_MappedTxBuffersConfig */
typedef struct sCanIf_MappedTxBuffersConfigType
{
  CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType MailBoxConfigIdxOfMappedTxBuffersConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
} CanIf_MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_RxIndicationFctList */
typedef struct sCanIf_RxIndicationFctListType
{
  CanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;  /**< Rx indication function. */
  CanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;  /**< Layout of Rx indication function. */
} CanIf_RxIndicationFctListType;

/**   \brief  type used in CanIf_RxPduConfig */
typedef struct sCanIf_RxPduConfigType
{
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;  /**< Rx-PDU: CAN identifier. */
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;  /**< Rx-PDU: CAN identifier mask. */
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;  /**< PDU ID defined by upper layer. */
  CanIf_HasMetaDataItemCanId32OfRxPduConfigType HasMetaDataItemCanId32OfRxPduConfig;  /**< TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32. */
  CanIf_RxIndicationFctListIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_RxIndicationFctList */
  CanIf_RxPduDlcOfRxPduConfigType RxPduDlcOfRxPduConfig;  /**< Rx-PDU length (DLC). */
  CanIf_MsgType MsgTypeOfRxPduConfig;  /**< Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0). */
} CanIf_RxPduConfigType;

/**   \brief  type used in CanIf_TxBufferFifoConfig */
typedef struct sCanIf_TxBufferFifoConfigType
{
  CanIf_TxFifoQueueDataEndIdxOfTxBufferFifoConfigType TxFifoQueueDataEndIdxOfTxBufferFifoConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxFifoQueueData */
  CanIf_TxFifoQueueDataStartIdxOfTxBufferFifoConfigType TxFifoQueueDataStartIdxOfTxBufferFifoConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxFifoQueueData */
  CanIf_SizeOfOnePayloadElOfTxBufferFifoConfigType SizeOfOnePayloadElOfTxBufferFifoConfig;
  CanIf_TxBufferFifoBaseIdxOfTxBufferFifoConfigType TxBufferFifoBaseIdxOfTxBufferFifoConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferFifoBase */
  CanIf_TxFifoQueueBaseEndIdxOfTxBufferFifoConfigType TxFifoQueueBaseEndIdxOfTxBufferFifoConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxFifoQueueBase */
  CanIf_TxFifoQueueBaseLengthOfTxBufferFifoConfigType TxFifoQueueBaseLengthOfTxBufferFifoConfig;  /**< the number of relations pointing to CanIf_TxFifoQueueBase */
  CanIf_TxFifoQueueBaseStartIdxOfTxBufferFifoConfigType TxFifoQueueBaseStartIdxOfTxBufferFifoConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxFifoQueueBase */
} CanIf_TxBufferFifoConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdConfig */
typedef struct sCanIf_TxBufferPrioByCanIdConfigType
{
  CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfigType BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdConfig;
  CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase */
  CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfigType TxQueueFlagsEndIdxOfTxBufferPrioByCanIdConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxQueueFlags */
  CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfigType TxQueueFlagsStartIdxOfTxBufferPrioByCanIdConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxQueueFlags */
} CanIf_TxBufferPrioByCanIdConfigType;

/**   \brief  type used in CanIf_TxPduConfig */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_CanIdTxMaskOfTxPduConfigType CanIdTxMaskOfTxPduConfig;  /**< CAN identifier mask (16bit / 32bit). */
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle-Id (8bit / 16bit). */
  CanIf_HasMetaDataItemCanId32OfTxPduConfigType HasMetaDataItemCanId32OfTxPduConfig;  /**< TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32. */
  CanIf_IsTxPduTruncationOfTxPduConfigType IsTxPduTruncationOfTxPduConfig;  /**< TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
  CanIf_TxPduLengthOfTxPduConfigType TxPduLengthOfTxPduConfig;  /**< Tx PDU length. */
} CanIf_TxPduConfigType;

/**   \brief  type used in CanIf_TxPduQueueIndex */
typedef struct sCanIf_TxPduQueueIndexType
{
  CanIf_TxQueueIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueue */
} CanIf_TxPduQueueIndexType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicStructTypes  CanIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_CtrlStatesRDR_01StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_CtrlStatesRDR_02StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_CtrlStatesRDR_03StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_CtrlStatesRDR_04StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_CtrlStatesRDR_05StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_CtrlStatesRDR_06StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_CtrlStatesRDR_07StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_CtrlStatesRDR_08StructSTag
{
  CanIf_CtrlStatesType CT_VCAN_RADAR_a3a0f56c;
  CanIf_CtrlStatesType CT_PCAN_RADAR_a3a0f56c;
} CanIf_CtrlStatesRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxBufferFifoBaseRDR_01StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxBufferFifoBaseRDR_02StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxBufferFifoBaseRDR_03StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxBufferFifoBaseRDR_04StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxBufferFifoBaseRDR_05StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxBufferFifoBaseRDR_06StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxBufferFifoBaseRDR_07StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferFifoBase for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxBufferFifoBaseRDR_08StructSTag
{
  CanIf_TxBufferFifoBaseType CHNL_2ad3227b_PCAN;
} CanIf_TxBufferFifoBaseRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_01StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_02StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_03StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_04StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_05StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_06StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_07StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxBufferPrioByCanIdBaseRDR_08StructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0829f689;
} CanIf_TxBufferPrioByCanIdBaseRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxFifoQueueBaseRDR_01StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[196];
} CanIf_TxFifoQueueBaseRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxFifoQueueBaseRDR_02StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[175];
} CanIf_TxFifoQueueBaseRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxFifoQueueBaseRDR_03StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[175];
} CanIf_TxFifoQueueBaseRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxFifoQueueBaseRDR_04StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[196];
} CanIf_TxFifoQueueBaseRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxFifoQueueBaseRDR_05StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[197];
} CanIf_TxFifoQueueBaseRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxFifoQueueBaseRDR_06StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[175];
} CanIf_TxFifoQueueBaseRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxFifoQueueBaseRDR_07StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[175];
} CanIf_TxFifoQueueBaseRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueBase for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxFifoQueueBaseRDR_08StructSTag
{
  CanIf_TxFifoQueueBaseType CHNL_2ad3227b_PCAN[175];
} CanIf_TxFifoQueueBaseRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxFifoQueueDataRDR_01StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[12544];
} CanIf_TxFifoQueueDataRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxFifoQueueDataRDR_02StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[11200];
} CanIf_TxFifoQueueDataRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxFifoQueueDataRDR_03StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[11200];
} CanIf_TxFifoQueueDataRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxFifoQueueDataRDR_04StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[12544];
} CanIf_TxFifoQueueDataRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxFifoQueueDataRDR_05StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[12608];
} CanIf_TxFifoQueueDataRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxFifoQueueDataRDR_06StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[11200];
} CanIf_TxFifoQueueDataRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxFifoQueueDataRDR_07StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[11200];
} CanIf_TxFifoQueueDataRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxFifoQueueData for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxFifoQueueDataRDR_08StructSTag
{
  CanIf_TxFifoQueueDataType CHNL_2ad3227b_PCAN[11200];
} CanIf_TxFifoQueueDataRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxQueueRDR_01StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxQueueRDR_02StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxQueueRDR_03StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxQueueRDR_04StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxQueueRDR_05StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxQueueRDR_06StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxQueueRDR_07StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxQueueRDR_08StructSTag
{
  CanIf_TxPrioByCanIdType TPCM_Tp_oVCAN_RADAR_229e257c_Tx;
  CanIf_TxPrioByCanIdType TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_MOIS_info_oVCAN_RADAR_dba7da57_Tx;
  CanIf_TxPrioByCanIdType prop_ADAS_BSIS_info_oVCAN_RADAR_42f884ce_Tx;
  CanIf_TxPrioByCanIdType TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49;
  CanIf_TxPrioByCanIdType DM1_B1_oVCAN_RADAR_c2a11718_Tx;
  CanIf_TxPrioByCanIdType DM1_B0_oVCAN_RADAR_8817cb52_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR2_oVCAN_RADAR_e86476d4_Tx;
  CanIf_TxPrioByCanIdType TPCM_SR1_oVCAN_RADAR_264f0b3c_Tx;
  CanIf_TxPrioByCanIdType TPDT_B1_oVCAN_RADAR_2ebbc0bc_Tx;
  CanIf_TxPrioByCanIdType TPDT_B0_oVCAN_RADAR_d6e4df39_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_PLANT_Tp_oVCAN_RADAR_d5d0b00c_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_PLANT_oVCAN_RADAR_16d34ef3_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_PLANT_oVCAN_RADAR_b3fa7e3b_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OTA_Tp_oVCAN_RADAR_0ba1e84f_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OTA_oVCAN_RADAR_b9a3928f_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OTA_oVCAN_RADAR_8f2ed61e_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD2_Tp_oVCAN_RADAR_3e9c737e_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD2_oVCAN_RADAR_3bc93779_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD2_oVCAN_RADAR_2eddf445_Tx;
  CanIf_TxPrioByCanIdType FR_DIAG_RES_PHY_OBD1_Tp_oVCAN_RADAR_fddad3af_Tx;
  CanIf_TxPrioByCanIdType SR1_DIAG_RES_PHY_OBD1_oVCAN_RADAR_5315d9a7_Tx;
  CanIf_TxPrioByCanIdType SR2_DIAG_RES_PHY_OBD1_oVCAN_RADAR_46011a9b_Tx;
  CanIf_TxPrioByCanIdType MOIS_oVCAN_RADAR_edd3b80a_Tx;
  CanIf_TxPrioByCanIdType BSD1_oVCAN_RADAR_64acbe01_Tx;
} CanIf_TxQueueRDR_08StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_01 */
typedef struct CanIf_TxQueueFlagsRDR_01StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_01StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_02 */
typedef struct CanIf_TxQueueFlagsRDR_02StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_02StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_03 */
typedef struct CanIf_TxQueueFlagsRDR_03StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_03StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_04 */
typedef struct CanIf_TxQueueFlagsRDR_04StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_04StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_05 */
typedef struct CanIf_TxQueueFlagsRDR_05StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_05StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_06 */
typedef struct CanIf_TxQueueFlagsRDR_06StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_06StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_07 */
typedef struct CanIf_TxQueueFlagsRDR_07StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_07StructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags for debugging purposes in the predefined variant RDR_08 */
typedef struct CanIf_TxQueueFlagsRDR_08StructSTag
{
  CanIf_TxQueueFlagsType CHNL_0829f689;
} CanIf_TxQueueFlagsRDR_08StructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCUnionIndexAndSymbolTypes  CanIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access CanIf_CtrlStates in an index and symbol based style for debugging purposes */
typedef union CanIf_CtrlStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_CtrlStatesType raw[2];
  CanIf_CtrlStatesRDR_01StructSType strRDR_01;
  CanIf_CtrlStatesRDR_02StructSType strRDR_02;
  CanIf_CtrlStatesRDR_03StructSType strRDR_03;
  CanIf_CtrlStatesRDR_04StructSType strRDR_04;
  CanIf_CtrlStatesRDR_05StructSType strRDR_05;
  CanIf_CtrlStatesRDR_06StructSType strRDR_06;
  CanIf_CtrlStatesRDR_07StructSType strRDR_07;
  CanIf_CtrlStatesRDR_08StructSType strRDR_08;
} CanIf_CtrlStatesUType;

/**   \brief  type to access CanIf_TxBufferFifoBase in an index and symbol based style for debugging purposes */
typedef union CanIf_TxBufferFifoBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxBufferFifoBaseType raw[1];
  CanIf_TxBufferFifoBaseRDR_01StructSType strRDR_01;
  CanIf_TxBufferFifoBaseRDR_02StructSType strRDR_02;
  CanIf_TxBufferFifoBaseRDR_03StructSType strRDR_03;
  CanIf_TxBufferFifoBaseRDR_04StructSType strRDR_04;
  CanIf_TxBufferFifoBaseRDR_05StructSType strRDR_05;
  CanIf_TxBufferFifoBaseRDR_06StructSType strRDR_06;
  CanIf_TxBufferFifoBaseRDR_07StructSType strRDR_07;
  CanIf_TxBufferFifoBaseRDR_08StructSType strRDR_08;
} CanIf_TxBufferFifoBaseUType;

/**   \brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style for debugging purposes */
typedef union CanIf_TxBufferPrioByCanIdBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxBufferPrioByCanIdBaseType raw[1];
  CanIf_TxBufferPrioByCanIdBaseRDR_01StructSType strRDR_01;
  CanIf_TxBufferPrioByCanIdBaseRDR_02StructSType strRDR_02;
  CanIf_TxBufferPrioByCanIdBaseRDR_03StructSType strRDR_03;
  CanIf_TxBufferPrioByCanIdBaseRDR_04StructSType strRDR_04;
  CanIf_TxBufferPrioByCanIdBaseRDR_05StructSType strRDR_05;
  CanIf_TxBufferPrioByCanIdBaseRDR_06StructSType strRDR_06;
  CanIf_TxBufferPrioByCanIdBaseRDR_07StructSType strRDR_07;
  CanIf_TxBufferPrioByCanIdBaseRDR_08StructSType strRDR_08;
} CanIf_TxBufferPrioByCanIdBaseUType;

/**   \brief  type to access CanIf_TxFifoQueueBase in an index and symbol based style for debugging purposes */
typedef union CanIf_TxFifoQueueBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxFifoQueueBaseType raw[197];
  CanIf_TxFifoQueueBaseRDR_01StructSType strRDR_01;
  CanIf_TxFifoQueueBaseRDR_02StructSType strRDR_02;
  CanIf_TxFifoQueueBaseRDR_03StructSType strRDR_03;
  CanIf_TxFifoQueueBaseRDR_04StructSType strRDR_04;
  CanIf_TxFifoQueueBaseRDR_05StructSType strRDR_05;
  CanIf_TxFifoQueueBaseRDR_06StructSType strRDR_06;
  CanIf_TxFifoQueueBaseRDR_07StructSType strRDR_07;
  CanIf_TxFifoQueueBaseRDR_08StructSType strRDR_08;
} CanIf_TxFifoQueueBaseUType;

/**   \brief  type to access CanIf_TxFifoQueueData in an index and symbol based style for debugging purposes */
typedef union CanIf_TxFifoQueueDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxFifoQueueDataType raw[12608];
  CanIf_TxFifoQueueDataRDR_01StructSType strRDR_01;
  CanIf_TxFifoQueueDataRDR_02StructSType strRDR_02;
  CanIf_TxFifoQueueDataRDR_03StructSType strRDR_03;
  CanIf_TxFifoQueueDataRDR_04StructSType strRDR_04;
  CanIf_TxFifoQueueDataRDR_05StructSType strRDR_05;
  CanIf_TxFifoQueueDataRDR_06StructSType strRDR_06;
  CanIf_TxFifoQueueDataRDR_07StructSType strRDR_07;
  CanIf_TxFifoQueueDataRDR_08StructSType strRDR_08;
} CanIf_TxFifoQueueDataUType;

/**   \brief  type to access CanIf_TxQueue in an index and symbol based style for debugging purposes */
typedef union CanIf_TxQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxPrioByCanIdType raw[25];
  CanIf_TxQueueRDR_01StructSType strRDR_01;
  CanIf_TxQueueRDR_02StructSType strRDR_02;
  CanIf_TxQueueRDR_03StructSType strRDR_03;
  CanIf_TxQueueRDR_04StructSType strRDR_04;
  CanIf_TxQueueRDR_05StructSType strRDR_05;
  CanIf_TxQueueRDR_06StructSType strRDR_06;
  CanIf_TxQueueRDR_07StructSType strRDR_07;
  CanIf_TxQueueRDR_08StructSType strRDR_08;
} CanIf_TxQueueUType;

/**   \brief  type to access CanIf_TxQueueFlags in an index and symbol based style for debugging purposes */
typedef union CanIf_TxQueueFlagsUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxQueueFlagsType raw[1];
  CanIf_TxQueueFlagsRDR_01StructSType strRDR_01;
  CanIf_TxQueueFlagsRDR_02StructSType strRDR_02;
  CanIf_TxQueueFlagsRDR_03StructSType strRDR_03;
  CanIf_TxQueueFlagsRDR_04StructSType strRDR_04;
  CanIf_TxQueueFlagsRDR_05StructSType strRDR_05;
  CanIf_TxQueueFlagsRDR_06StructSType strRDR_06;
  CanIf_TxQueueFlagsRDR_07StructSType strRDR_07;
  CanIf_TxQueueFlagsRDR_08StructSType strRDR_08;
} CanIf_TxQueueFlagsUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootPointerTypes  CanIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanIf_BusOffNotificationFctPtr */
typedef P2CONST(CanIf_BusOffNotificationFctType, TYPEDEF, CANIF_CONST) CanIf_BusOffNotificationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef P2CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlModeIndicationFctPtr */
typedef P2CONST(CanIf_CtrlModeIndicationFctType, TYPEDEF, CANIF_CONST) CanIf_CtrlModeIndicationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CtrlStates */
typedef P2VAR(CanIf_CtrlStatesType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_CtrlStatesPtrType;

/**   \brief  type used to point to CanIf_MailBoxConfig */
typedef P2CONST(CanIf_MailBoxConfigType, TYPEDEF, CANIF_CONST) CanIf_MailBoxConfigPtrType;

/**   \brief  type used to point to CanIf_MappedTxBuffersConfig */
typedef P2CONST(CanIf_MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_RxIndicationFctList */
typedef P2CONST(CanIf_RxIndicationFctListType, TYPEDEF, CANIF_CONST) CanIf_RxIndicationFctListPtrType;

/**   \brief  type used to point to CanIf_RxPduConfig */
typedef P2CONST(CanIf_RxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_RxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxBufferFifoBase */
typedef P2VAR(CanIf_TxBufferFifoBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxBufferFifoBasePtrType;

/**   \brief  type used to point to CanIf_TxBufferFifoConfig */
typedef P2CONST(CanIf_TxBufferFifoConfigType, TYPEDEF, CANIF_CONST) CanIf_TxBufferFifoConfigPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdBase */
typedef P2VAR(CanIf_TxBufferPrioByCanIdBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBasePtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdConfig */
typedef P2CONST(CanIf_TxBufferPrioByCanIdConfigType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdConfigPtrType;

/**   \brief  type used to point to CanIf_TxConfirmationFctList */
typedef P2CONST(CanIf_TxConfirmationFctType, TYPEDEF, CANIF_CONST) CanIf_TxConfirmationFctListPtrType;

/**   \brief  type used to point to CanIf_TxFifoQueueBase */
typedef P2VAR(CanIf_TxFifoQueueBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxFifoQueueBasePtrType;

/**   \brief  type used to point to CanIf_TxFifoQueueData */
typedef P2VAR(CanIf_TxFifoQueueDataType, TYPEDEF, CANIF_VAR_NOINIT_FAST) CanIf_TxFifoQueueDataPtrType;

/**   \brief  type used to point to CanIf_TxPduConfig */
typedef P2CONST(CanIf_TxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_TxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxPduQueueIndex */
typedef P2CONST(CanIf_TxPduQueueIndexType, TYPEDEF, CANIF_CONST) CanIf_TxPduQueueIndexPtrType;

/**   \brief  type used to point to CanIf_TxQueue */
typedef P2VAR(CanIf_TxPrioByCanIdType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueuePtrType;

/**   \brief  type used to point to CanIf_TxQueueFlags */
typedef P2VAR(CanIf_TxQueueFlagsType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueueFlagsPtrType;

/**   \brief  type used to point to CanIf_UlTxPduId2InternalTxPduId */
typedef P2CONST(CanIf_UlTxPduId2InternalTxPduIdType, TYPEDEF, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduIdPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootValueTypes  CanIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanIf_PCConfig */
typedef struct sCanIf_PCConfigType
{
  CanIf_MailBoxConfigPtrType MailBoxConfigOfPCConfig;  /**< the pointer to CanIf_MailBoxConfig */
  CanIf_RxPduConfigPtrType RxPduConfigOfPCConfig;  /**< the pointer to CanIf_RxPduConfig */
  CanIf_TxBufferFifoConfigPtrType TxBufferFifoConfigOfPCConfig;  /**< the pointer to CanIf_TxBufferFifoConfig */
  CanIf_TxPduConfigPtrType TxPduConfigOfPCConfig;  /**< the pointer to CanIf_TxPduConfig */
  CanIf_UlTxPduId2InternalTxPduIdPtrType UlTxPduId2InternalTxPduIdOfPCConfig;  /**< the pointer to CanIf_UlTxPduId2InternalTxPduId */
  CanIf_SizeOfTxFifoQueueDataType SizeOfTxFifoQueueDataOfPCConfig;  /**< the number of accomplishable value elements in CanIf_TxFifoQueueData */
  CanIf_SizeOfRxPduConfigType SizeOfRxPduConfigOfPCConfig;  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
  CanIf_SizeOfTxFifoQueueBaseType SizeOfTxFifoQueueBaseOfPCConfig;  /**< the number of accomplishable value elements in CanIf_TxFifoQueueBase */
  CanIf_SizeOfTxPduConfigType SizeOfTxPduConfigOfPCConfig;  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
  CanIf_SizeOfTxPduQueueIndexType SizeOfTxPduQueueIndexOfPCConfig;  /**< the number of accomplishable value elements in CanIf_TxPduQueueIndex */
  CanIf_SizeOfUlTxPduId2InternalTxPduIdType SizeOfUlTxPduId2InternalTxPduIdOfPCConfig;  /**< the number of accomplishable value elements in CanIf_UlTxPduId2InternalTxPduId */
} CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanIf_PCConfig in a symbol based style. */
typedef struct sCanIf_PCConfigsType
{
  CanIf_PCConfigType Config_RDR_01;  /**< [Config_RDR_01] */
  CanIf_PCConfigType Config_RDR_02;  /**< [Config_RDR_02] */
  CanIf_PCConfigType Config_RDR_03;  /**< [Config_RDR_03] */
  CanIf_PCConfigType Config_RDR_04;  /**< [Config_RDR_04] */
  CanIf_PCConfigType Config_RDR_05;  /**< [Config_RDR_05] */
  CanIf_PCConfigType Config_RDR_06;  /**< [Config_RDR_06] */
  CanIf_PCConfigType Config_RDR_07;  /**< [Config_RDR_07] */
  CanIf_PCConfigType Config_RDR_08;  /**< [Config_RDR_08] */
} CanIf_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 0:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 0:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfigRDR_01
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to the mailbox.
  PduIdLast               "Last" PDU mapped to the mailbox.
  TxBufferCfg             the enum value of the according target of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferHandlingType
  MailBoxType             Type of the mailbox: Rx-/Tx- BasicCAN/FullCAN/Unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfigRDR_01[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfigRDR_02
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to the mailbox.
  PduIdLast               "Last" PDU mapped to the mailbox.
  TxBufferCfg             the enum value of the according target of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferHandlingType
  MailBoxType             Type of the mailbox: Rx-/Tx- BasicCAN/FullCAN/Unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfigRDR_02[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfigRDR_05
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to the mailbox.
  PduIdLast               "Last" PDU mapped to the mailbox.
  TxBufferCfg             the enum value of the according target of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferFifoConfig,CanIf_TxBufferPrioByCanIdConfig
  TxBufferHandlingType
  MailBoxType             Type of the mailbox: Rx-/Tx- BasicCAN/FullCAN/Unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfigRDR_05[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[5];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_01
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_01[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_02
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_02[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_03
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_03[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_04
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_04[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_05
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_05[112];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_06
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_06[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_07
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_07[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRDR_08
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  HasMetaDataItemCanId32    TRUE: The Rx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Rx PDU does not reference a MetaDataItem of type CAN_ID_32.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRDR_08[113];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferFifoConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferFifoConfigRDR_01
  \brief  Tx-buffer: FIFO
  \details
  Element                    Description
  TxFifoQueueDataEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueData
  TxFifoQueueDataStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueData
  SizeOfOnePayloadEl     
  TxBufferFifoBaseIdx        the index of the 1:1 relation pointing to CanIf_TxBufferFifoBase
  TxFifoQueueBaseEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseLength      the number of relations pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueBase
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferFifoConfigType, CANIF_CONST) CanIf_TxBufferFifoConfigRDR_01[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferFifoConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferFifoConfigRDR_02
  \brief  Tx-buffer: FIFO
  \details
  Element                    Description
  TxFifoQueueDataEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueData
  TxFifoQueueDataStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueData
  SizeOfOnePayloadEl     
  TxBufferFifoBaseIdx        the index of the 1:1 relation pointing to CanIf_TxBufferFifoBase
  TxFifoQueueBaseEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseLength      the number of relations pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueBase
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferFifoConfigType, CANIF_CONST) CanIf_TxBufferFifoConfigRDR_02[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferFifoConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferFifoConfigRDR_05
  \brief  Tx-buffer: FIFO
  \details
  Element                    Description
  TxFifoQueueDataEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueData
  TxFifoQueueDataStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueData
  SizeOfOnePayloadEl     
  TxBufferFifoBaseIdx        the index of the 1:1 relation pointing to CanIf_TxBufferFifoBase
  TxFifoQueueBaseEndIdx      the end index of the 1:n relation pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseLength      the number of relations pointing to CanIf_TxFifoQueueBase
  TxFifoQueueBaseStartIdx    the start index of the 1:n relation pointing to CanIf_TxFifoQueueBase
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferFifoConfigType, CANIF_CONST) CanIf_TxBufferFifoConfigRDR_05[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdConfig
  \brief  Tx-buffer: PRIO_BY_CANID
  \details
  Element                       Description
  BitPos2TxPduIdOffset      
  TxBufferPrioByCanIdBaseIdx    the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxQueueFlagsEndIdx            the end index of the 1:n relation pointing to CanIf_TxQueueFlags
  TxQueueFlagsStartIdx          the start index of the 1:n relation pointing to CanIf_TxQueueFlags
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdConfig[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[5];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_01
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_01[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_02
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_02[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_03
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_03[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_04
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_04[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_05
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_05[230];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_06
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_06[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_07
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_07[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRDR_08
  \brief  Tx PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  CanIdTxMask                 CAN identifier mask (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  HasMetaDataItemCanId32      TRUE: The Tx PDU references a MetaDataItem of type CAN_ID_32, FALSE: The Tx PDU does not reference a MetaDataItem of type CAN_ID_32.
  IsTxPduTruncation           TRUE: Truncation of Tx PDU is enabled, FALSE: Truncation of Tx PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRDR_08[229];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx PDU ID to corresponding Tx buffer of type PrioByCanId handle-ID. NOTE: Only Basic-CAN Tx PDUs which are mapped to a Tx buffer of type PrioByCanId have a valid indirection.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[230];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_UlTxPduId2InternalTxPduIdRDR_01
**********************************************************************************************************************/
/** 
  \var    CanIf_UlTxPduId2InternalTxPduIdRDR_01
  \brief  Indirection table - Upper layer Tx PDU ID to internal one.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduIdRDR_01[229];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_UlTxPduId2InternalTxPduIdRDR_05
**********************************************************************************************************************/
/** 
  \var    CanIf_UlTxPduId2InternalTxPduIdRDR_05
  \brief  Indirection table - Upper layer Tx PDU ID to internal one.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduIdRDR_05[230];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_UlTxPduId2InternalTxPduIdRDR_06
**********************************************************************************************************************/
/** 
  \var    CanIf_UlTxPduId2InternalTxPduIdRDR_06
  \brief  Indirection table - Upper layer Tx PDU ID to internal one.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduIdRDR_06[229];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferFifoBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferFifoBase
  \brief  Variable declaration - Tx-buffer FIFO: buffer-base: write-/read-index, counter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxBufferFifoBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferFifoBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx buffer: PRIO_BY_CANID. Stores the current number of buffered PDUs per Tx Buffer.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxFifoQueueBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxFifoQueueBase
  \brief  Variable declaration - Tx-buffer FIFO: queue-base: CAN identifier, data length, queued / NOT queued.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxFifoQueueBaseUType, CANIF_VAR_NOINIT) CanIf_TxFifoQueueBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxFifoQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxFifoQueueData
  \brief  Variable declaration - Tx-buffer FIFO: queue-data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxFifoQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxFifoQueueData;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx buffer: PRIO_BY_CANID. Stores the CAN ID, SDU length and SDU of a buffered PDU.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueFlags
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueFlags
  \brief  Variable declaration - Tx buffer: PRIO_BY_CANID. Stores the flags indicating whether the corresponding PDU is buffered or not.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueFlagsUType, CANIF_VAR_NOINIT) CanIf_TxQueueFlags;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_PCConfig
  \details
  Element                            Description
  MailBoxConfig                      the pointer to CanIf_MailBoxConfig
  RxPduConfig                        the pointer to CanIf_RxPduConfig
  TxBufferFifoConfig                 the pointer to CanIf_TxBufferFifoConfig
  TxPduConfig                        the pointer to CanIf_TxPduConfig
  UlTxPduId2InternalTxPduId          the pointer to CanIf_UlTxPduId2InternalTxPduId
  SizeOfTxFifoQueueData              the number of accomplishable value elements in CanIf_TxFifoQueueData
  SizeOfRxPduConfig                  the number of accomplishable value elements in CanIf_RxPduConfig
  SizeOfTxFifoQueueBase              the number of accomplishable value elements in CanIf_TxFifoQueueBase
  SizeOfTxPduConfig                  the number of accomplishable value elements in CanIf_TxPduConfig
  SizeOfTxPduQueueIndex              the number of accomplishable value elements in CanIf_TxPduQueueIndex
  SizeOfUlTxPduId2InternalTxPduId    the number of accomplishable value elements in CanIf_UlTxPduId2InternalTxPduId
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_PCConfigsType, CANIF_CONST) CanIf_PCConfig;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* CANIF_CFG_H */
/**********************************************************************************************************************
  END OF FILE: CanIf_Cfg.h
**********************************************************************************************************************/


