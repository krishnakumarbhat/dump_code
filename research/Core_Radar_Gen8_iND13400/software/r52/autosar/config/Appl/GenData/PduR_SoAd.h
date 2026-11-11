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
 *              File: PduR_SoAd.h
 *   Generation Time: 2026-04-02 15:10:03
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
#if !defined (PDUR_SOAD_H)
# define PDUR_SOAD_H

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
 * PduR_SoAdIfRxIndication
 *********************************************************************************************************************/
/*!
 * \brief        This function receives a SoAdIf I-PDU and routes it to the configured destinations.
 *               The I-PDU is routed to the destination module using the appropriate I-PDU handle of the destination module.
 * \details      -
 * \param[in]    RxPduId    ID of the received SoAdIf I-PDU
 * \param[in]    info       Pointer to the Pdu data:
                            - info->MetaDataPtr may contain optional meta data or NULL_PTR.
                            - info->SduDataPtr contains the contents of the Pdu.
                            - info->SduLength indicates the length of the Pdu.
 * \pre          -
 * \context      TASK|ISR1|ISR2
 * \reentrant    TRUE for different handle IDs
 * \synchronous  TRUE
 * \note         The function is called by SoAdIf.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SoAdIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

/**********************************************************************************************************************
 * PduR_SoAdIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief       This function is called by SoAdIf to confirm the complete transmission of a lower layer I-PDU.
 *              The call will either be forwarded to the upper layer module or is used to confirm the latest transmitted Pdu from a PduR queue. 
 *              In this context the next Pdu from the queue will be transmitted to the destination.
 * \details     -
 * \param[in]   TxPduId           ID of the transmitted SoAdIf I-PDU
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different handle IDs
 * \synchronous TRUE
 * \note        The function is called by SoAdIf.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SoAdIfTxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
 * PduR_SoAdIfTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \brief          This function is called by SoAdIf to request the lower layer TX I-PDU before transmission.
 *                 The call will either be forwarded to the upper layer module or
 *                 the I-PDU data will be read from a PduR queue in case of a queued routing path.
 * \details        -
 * \param[in]      TxPduId       ID of the SoAdIf I-PDU that will be transmitted
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
 * \note           The function is called by SoAdIf.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SoAdIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);









#define PDUR_STOP_SEC_CODE
# include "PduR_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* PDUR_SOAD_H */


/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * END OF FILE: PduR_SoAd.h
 *********************************************************************************************************************/

