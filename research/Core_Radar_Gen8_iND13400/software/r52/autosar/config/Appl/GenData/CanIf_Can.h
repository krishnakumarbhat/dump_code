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
 *              File: CanIf_Can.h
 *   Generation Time: 2026-08-05 12:38:45
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
#if !defined(CANIF_CAN_H)
# define CANIF_CAN_H

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/

# include "CanIf_Cbk.h" /* Contains the expected CAN Interface callback functions for the CAN Driver modules */

#endif /* CANIF_CAN_H */


