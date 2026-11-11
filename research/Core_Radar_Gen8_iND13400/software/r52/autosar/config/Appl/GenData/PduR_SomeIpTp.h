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
 *            Module: PduR
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_SomeIpTp.h
 *   Generation Time: 2026-04-02 15:10:04
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
#if !defined (PDUR_SOMEIPTP_H)
# define PDUR_SOMEIPTP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Cfg.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* \trace SPEC-629 */

#define PDUR_START_SEC_CODE
# include "PduR_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PduR_SomeIpTpIfRxIndication
 *********************************************************************************************************************/
/*!
 * \brief        This function receives a SomeIpTpIf I-PDU and routes it to the configured destinations.
 *               The I-PDU is routed to the destination module using the appropriate I-PDU handle of the destination module.
 * \details      -
 * \param[in]    RxPduId    ID of the received SomeIpTpIf I-PDU
 * \param[in]    info       Pointer to the Pdu data:
                            - info->MetaDataPtr may contain optional meta data or NULL_PTR.
                            - info->SduDataPtr contains the contents of the Pdu.
                            - info->SduLength indicates the length of the Pdu.
 * \pre          -
 * \context      TASK|ISR1|ISR2
 * \reentrant    TRUE for different handle IDs
 * \synchronous  TRUE
 * \note         The function is called by SomeIpTpIf.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SomeIpTpIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

/**********************************************************************************************************************
 * PduR_SomeIpTpIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief       This function is called by SomeIpTpIf to confirm the complete transmission of a lower layer I-PDU.
 *              The call will either be forwarded to the upper layer module or is used to confirm the latest transmitted Pdu from a PduR queue. 
 *              In this context the next Pdu from the queue will be transmitted to the destination.
 * \details     -
 * \param[in]   TxPduId           ID of the transmitted SomeIpTpIf I-PDU
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTpIf.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SomeIpTpIfTxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
 * PduR_SomeIpTpIfTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \brief          This function is called by SomeIpTpIf to request the lower layer TX I-PDU before transmission.
 *                 The call will either be forwarded to the upper layer module or
 *                 the I-PDU data will be read from a PduR queue in case of a queued routing path.
 * \details        -
 * \param[in]      TxPduId       ID of the SomeIpTpIf I-PDU that will be transmitted
 * \param[in,out]  info          Contains a pointer to a buffer to which the destination module copies the data:
                                 - info->MetaDataPtr Is ignored. No meta data is copied in the TriggerTransmit API. The meta data has to be provided in the Transmit API.
                                 - info->SduDataPtr Contains a pointer to the buffer.
                                 - info->SduLength In: Contains the length of the provided buffer. Out: Contains the amount of bytes which were actually copied.
 * \return         Std_ReturnType
 *                 E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
 * \return         E_NOT_OK      No data has been copied, because
 *                               PduR is not initialized
 *                               or the input parameters are incorrect
 *                               or there is no data available.
 * \pre            -
 * \context        TASK|ISR1|ISR2
 * \reentrant      TRUE for different handle IDs
 * \synchronous    TRUE
 * \note           The function is called by SomeIpTpIf.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SomeIpTpIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);




/**********************************************************************************************************************
 * PduR_SomeIpTpRxIndication
 *********************************************************************************************************************/
/*!
 * \brief       The function is called by SomeIpTp to indicate the complete reception of a lower layer Tp I-PDU or to
 *              report an error that occurred during reception.
 *              The call is either routed to an upper Tp module using the appropriate I-PDU handle of the destination module
 *              or it finishes the reception to the internal PduR queue in case of a queued routing path.
 * \details     -
 * \param[in]   id               ID of the received SomeIpTp I-PDU
 * \param[in]   result           Result of the TP reception
 *              E_OK             The TP Reception has been completed successfully.
 *              E_NOT_OK         The TP Reception has been aborted.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SomeIpTpRxIndication(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 * PduR_SomeIpTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief       The function is called by SomeIpTp to finish and confirm the complete transmission of a lower layer Tp I-PDU.
 *              The call is either forwarded to the upper layer module module
 *              or it will be forwarded to the internal PduR queue in case of a queued routing path.
 * \details     -
 * \param[in]   id                              ID of the transmitted SomeIpTp I-PDU
 * \param[in]   result                          Result of the TP transmission
 *              E_OK                            The TP transmission has been completed successfully.
 *              E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state
 *                                              or the SomeIpTpTxPduId is not valid
 *                                              or the SomeIpTpTxPduId is not forwarded in this identity
 *                                              or the request was not accepted by the destination upper layer.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SomeIpTpTxConfirmation(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 * PduR_SomeIpTpStartOfReception
 *********************************************************************************************************************/
/*!
 * \brief       This function will be called by SomeIpTp at the start of an I-PDU reception.
 *              The I-PDU might be fragmented into multiple N-PDUs
 *              (FF with one or more following CFs) or might consist of a single N-PDU (SF).
 *              The call will either be forwarded to the upper layer module or
 *              it will be processed by the internal PduR queue in case of a queued routing path.
 * \details     -
 * \param[in]   id                ID of the SomeIpTp I-PDU that will be received
 * \param[in]   info              info->MetaDataPtr may contain optional meta data or NULL_PTR.
                                  info->SduDataPtr may contain contents of the first frame of the Tp Pdu or NULL_PTR.
                                  info->SduLength may indicate the length of the first frame or zero.
                                  info may be NULL_PTR if None of the above parameters are used.
 * \param[in]   TpSduLength       Length of the entire the SomeIpTp SDU which will be received
 * \param[out]  bufferSizePtr     This parameter is used to return the available buffer size.
 * \return      BufReq_ReturnType
 *              BUFREQ_OK         StartOfReception request has been accepted. bufferSizePtr indicates the available receive buffer.
 *              BUFREQ_E_NOT_OK   PduR is not initialized
 *                                 or the input parameters are incorrect
 *                                 or the request was not accepted by the upper layer module
 *                                 or no queue slot is available.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
 * PduR_SomeIpTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \brief       This function is called by SomeIpTp if data has to be copied to the receiving module.
 *              Each call to this function copies the next part of the received data. Several calls may be made during reception of a TP-PDU.
 *              The call will either be forwarded to the upper layer module
 *              or it will be copied into the internal PduR queue in case of a queued routing path.
 * \details     -
 * \param[in]   id        ID of the SomeIpTp I-PDU that will be received
 * \param[in]   info      Contains a pointer to a buffer from which the destination module copies the received data:
                           - info->MetaDataPtr Is ignored. No meta data is copied in the CopyRxData API. The meta data has to be provided in the StartOfReception API.
                           - info->SduDataPtr Contains a pointer to the data.
                           - info->SduLength Contains the length of the provided data. A Pdu size of 0 can be used to poll the available buffer size via bufferSizePtr.
 * \param[out]  bufferSizePtr     Available receive buffer after data has been copied.
 * \return      BufReq_ReturnType
 *              BUFREQ_OK        Data has been copied successfully. The returned bufferSizePtr is valid.
 *              BUFREQ_E_NOT_OK  PduR is not initialized
 *                               or the input parameters are incorrect
 *                               or the request was not accepted by the upper layer module
 *                               or no buffer is available.
 *              BUFREQ_E_OVFL    The upper TP module is not able to receive the number of bytes.
 *                               The request was not accepted by the destination module.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
 * PduR_SomeIpTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \brief       This function is called by SomeIpTp to query the transmit data of an I-PDU segment.
 *              Each call to this function copies the next part of the transmit data.
 *              The call is either forwarded to an upper layer module
 *              or it will be forwarded to the internal PduR queue in case of a queued routing path.
 * \details     -
 * \param[in]   id                ID of the SomeIpTp I-PDU that will be transmitted
 * \param[in]   info              Contains a pointer to a buffer to which the destination module copies the data:
                                  - info->MetaDataPtr Is ignored. No meta data is copied in the CopyTxData API. The meta data has to be provided in the Transmit API.
                                  - info->SduDataPtr Contains a pointer to the buffer.
                                  - info->SduLength Contains the length of the provided buffer. A Pdu size of 0 can be used to poll the available Tx data via availableDataPtr.
                                  The Pdu data will be copied to this buffer either by the upper layer module or by the PduR in case of a queue routing path.
 * \param[in]   retry             Retry is not supported.
 * \param[out]  availableDataPtr  Indicates the remaining number of bytes that are available in the PduR buffer.
 * \return      BufReq_ReturnType
 *              BUFREQ_OK         The data has been copied to the transmit buffer successfully. Available data size was returned via availableDataPtr.
 *              BUFREQ_E_BUSY     Request could not be fulfilled, because the required amount of
 *                                Tx data is not available. The LoTp module can retry the request later.
 *              BUFREQ_E_NOT_OK   PduR is not initialized
 *                                or the input parameters are incorrect
 *                                or the request was not accepted by the upper layer module
 *                                or the requested length to copy is greater than the remaining buffer size
 *                                or there is no data in the buffer.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_SomeIpTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);




/**********************************************************************************************************************
 * PduR_SomeIpTpTransmit
 *********************************************************************************************************************/
/*!
 * \brief       This function transmits the corresponding SomeIpTp I-PDU to the configured destinations.
 *              The I-PDU is routed to the destination module using the appropriate I-PDU handle of the destination module.
 * \details     -
 * \param[in]   id                ID of the SomeIpTp I-PDU to be transmitted
 * \param[in]   info              Pointer to the Pdu data:
                                  - info->MetaDataPtr may contain optional meta data or NULL_PTR.
                                  - info->SduDataPtr may contain contents of the Pdu or NULL_PTR.
                                  - info->SduLength may indicate the length of the entire Pdu or zero.
 * \return      Std_ReturnType
 *              E_OK              The request was accepted by the PDU Router and by the destination module.
 *              E_NOT_OK          The PduR is not initialized
 *                                or the input parameters are incorrect
 *                                or the transmit request was not accepted by PduR or the destination module.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SomeIpTp.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SomeIpTpTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);








#define PDUR_STOP_SEC_CODE
# include "PduR_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* PDUR_SOMEIPTP_H */


/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * END OF FILE: PduR_SomeIpTp.h
 *********************************************************************************************************************/

