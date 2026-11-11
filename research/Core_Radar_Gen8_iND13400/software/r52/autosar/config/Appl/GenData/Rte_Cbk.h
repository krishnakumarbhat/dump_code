/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cbk.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CBK_H
# define RTE_CBK_H

# include "Com.h"
# include "LdCom.h"


# define RTE_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * LDCOM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_LdComCbkRxIndication_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx(P2CONST(PduInfoType, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
 * LDCOM-Callbacks for TP CopyTxData
 *********************************************************************************************************************/

FUNC(BufReq_ReturnType, RTE_CODE) Rte_LdComCbkCopyTxData_signalPdu_RDR_1_Detections_52b391ee_Tx(P2CONST(PduInfoType, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr, P2VAR(RetryInfoType, AUTOMATIC, RTE_APPL_VAR) RetryInfoPtr, P2VAR(PduLengthType, AUTOMATIC, RTE_APPL_VAR) TxDataCntPtr);

/**********************************************************************************************************************
 * LDCOM-Callbacks for TP Tx Confirmation
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_LdComCbkTpTxConfirmation_signalPdu_RDR_1_Detections_52b391ee_Tx(Std_ReturnType Result);

# define RTE_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_CBK_H */
