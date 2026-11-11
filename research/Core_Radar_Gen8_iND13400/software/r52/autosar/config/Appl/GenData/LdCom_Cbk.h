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
 *            Module: LdCom
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LdCom_Cbk.h
 *   Generation Time: 2026-04-02 15:09:55
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

#if !defined (LDCOM_CBK_H)
# define LDCOM_CBK_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LdCom_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
#include "LdCom_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * LdCom_RxIndication()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer when an LdCom IF I-PDU has been received.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     RxPduId             ID of the LdCom I-PDU/Signal that has been received.
 *  \param[in]     PduInfoPtr          Pointer to a PduInfoType structure.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_COMMUNICATION_INTERFACE
 *  \trace         CREQ-106201
 *********************************************************************************************************************/
FUNC(void, LDCOM_CODE) LdCom_RxIndication(PduIdType RxPduId,
                                          P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
 * LdCom_TxConfirmation()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer after an Ldcom IF I-PDU has been transmitted.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     TxPduId             ID of the LdCom I-PDU/Signal that has been transmitted.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TX_CONFIRMATION_API, LDCOM_COMMUNICATION_INTERFACE
 *  \trace         CREQ-106200
 *********************************************************************************************************************/
FUNC(void, LDCOM_CODE) LdCom_TxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
 * LdCom_TriggerTransmit()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer when an LdCom IF I-PDU shall be transmitted.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     TxPduId             ID of the LdCom I-PDU/Signal that is requested to be transmitted.
 *  \param[in,out] PduInfoPtr          Pointer to a PduInfoType structure. Contains i.a. a pointer to a buffer (SduDataPtr) to where the SDU
                                       data shall be copied, and the available buffer size in SduLengh.
                                       On return, the service will indicate the length of the copied SDU
                                       data in SduLength.
 *  \return        E_OK:               The SDU has been copied and the SduLength indicates the number of copied bytes.
 *                 E_NOT_OK:           A Det error occurred and the SDU has not been copied and the SduLength has not
 *                                     been set.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRIGGER_TRANSMIT_API, LDCOM_COMMUNICATION_INTERFACE
 *  \trace         CREQ-106200
 *********************************************************************************************************************/
FUNC(Std_ReturnType, LDCOM_CODE) LdCom_TriggerTransmit(PduIdType TxPduId,
                                                       P2VAR(PduInfoType, AUTOMATIC, LDCOM_APPL_VAR) PduInfoPtr);

/**********************************************************************************************************************
 * LdCom_StartOfReception()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer to indicate the start of an incoming TP connection.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     id                  ID of LdCom I-PDU/Signal that shall be received.
 *  \param[in]     info                Pointer to a PduInfoType structure.
 *  \param[in]     TpSduLength         Total length of the TP I-PDU to be received.
 *  \param[out]    bufferSizePtr       The LdCom returns in this value the remaining TP buffer size to the lower layer.
 *  \return        BUFREQ_OK:          Connection has been accepted.
 *                                     RxBufferSizePtr indicates the available receive buffer.
 *                 BUFREQ_E_NOT_OK:    Connection has been rejected. RxBufferSizePtr remains unchanged.
 *                 BUFREQ_E_OVFL:      In case the related upper layer module has rejected the reception.
 *                 BUFREQ_E_BUSY:      The case the related upper layer module is currently busy.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRANSPORT_PROTOCOL
 *  \trace         CREQ-108861
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, LDCOM_CODE) LdCom_StartOfReception(PduIdType id,
                                                           P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA) info,
                                                           PduLengthType TpSduLength,
                                                           P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_VAR) bufferSizePtr);

/**********************************************************************************************************************
 * LdCom_CopyRxData()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer once upon reception of each TP segment.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     id                  ID of LdCom I-PDU/Signal that shall be received.
 *  \param[in]     info                Pointer to a PduInfoType structure.
 *  \param[out]    bufferSizePtr       Remaining receive buffer size after completion of this call.
 *  \return        BUFREQ_OK:          Data successfully copied.
 *                                     RxBufferSizePtr indicates the remaining receive buffer size.
 *                 BUFREQ_E_NOT_OK:    Data was not copied because an error occurred.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRANSPORT_PROTOCOL
 *  \trace         CREQ-108861
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, LDCOM_CODE) LdCom_CopyRxData(PduIdType id,
                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA) info,
                                                     P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_VAR) bufferSizePtr);

/**********************************************************************************************************************
 * LdCom_TpRxIndication()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer after an LdCom TP I-PDU has been received.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     id                  ID of LdCom I-PDU/Signal that has been received.
 *  \param[in]     result              Indicates the reception result of the TP I-PDU.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRANSPORT_PROTOCOL
 *  \trace         CREQ-108861
 *********************************************************************************************************************/
FUNC(void, LDCOM_CODE) LdCom_TpRxIndication(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 * LdCom_CopyTxData()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer once upon transmission of each TP segment.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     id                  ID of LdCom I-PDU/Signal that shall be transmitted.
 *  \param[in,out] info                Pointer to a PduInfoType structure. Provides i.a. the destination buffer and the number of bytes to be copied.
 *                                     An SduLength of 0 is possible in order to poll the available transmit data
 *                                     count. In this case, no data has to be copied and SduDataPtr might be invalid.
 *  \param[in]     retry               This parameter is used to acknowledge transmitted data or to retransmit data
 *                                     after transmission problems.
 *  \param[out]    availableDataPtr    Remaining transmit buffer size after completion of this call.
 *  \return        BUFREQ_OK:          Data has been copied to the transmit buffer completely as requested.
 *                 BUFREQ_E_BUSY:      The transmission buffer is actually not available (implementation specific).
 *                 BUFREQ_E_NOT_OK:    Data has not been copied.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRANSPORT_PROTOCOL
 *  \trace         CREQ-108860
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, LDCOM_CODE) LdCom_CopyTxData(PduIdType id,
                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA) info,
                                                     P2VAR(RetryInfoType, AUTOMATIC, LDCOM_APPL_VAR) retry,
                                                     P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_VAR) availableDataPtr);

/**********************************************************************************************************************
 * LdCom_TpTxConfirmation()
 *********************************************************************************************************************/
/*! \brief         This function is called by the lower layer after a TP I-PDU has been transmitted.
 *  \details       LdCom evaluates the I-PDU/Signal handle and identifies the destination Signal.
 *                 The call is routed to the upper layer module using the appropriate API.
 *  \param[in]     id                  ID of LdCom I-PDU/Signal that has been transmitted.
 *  \param[in]     result              Indicates the transmission result of the TP I-PDU.
 *  \context       TASK|ISR
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \pre           -
 *  \note          The function is called by the lower layer.
 *  \config        LDCOM_TRANSPORT_PROTOCOL
 *  \trace         CREQ-108860
 *********************************************************************************************************************/
FUNC(void, LDCOM_CODE) LdCom_TpTxConfirmation(PduIdType id, Std_ReturnType result);

#define LDCOM_STOP_SEC_CODE
#include "LdCom_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* LDCOM_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: LdCom_Cbk.h
 *********************************************************************************************************************/
