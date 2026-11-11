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
 *            Module: Cdd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cdd_Cbk.h
 *   Generation Time: 2026-05-11 18:34:37
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


#if !defined (CDD_CBK_H)
# define CDD_CBK_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"



/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CDD_USE_DUMMY_STATEMENT
#define CDD_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_DUMMY_STATEMENT
#define CDD_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_DUMMY_STATEMENT_CONST
#define CDD_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CDD_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CDD_ATOMIC_VARIABLE_ACCESS
#define CDD_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CDD_PROCESSOR_IND13400
#define CDD_PROCESSOR_IND13400
#endif
#ifndef CDD_COMP_LLVMDIAB
#define CDD_COMP_LLVMDIAB
#endif
#ifndef CDD_GEN_GENERATOR_MSR
#define CDD_GEN_GENERATOR_MSR
#endif
#ifndef CDD_CPUTYPE_BITORDER_LSB2MSB
#define CDD_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CDD_CONFIGURATION_VARIANT_PRECOMPILE
#define CDD_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CDD_CONFIGURATION_VARIANT_LINKTIME
#define CDD_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CDD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CDD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CDD_CONFIGURATION_VARIANT
#define CDD_CONFIGURATION_VARIANT CDD_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CDD_POSTBUILD_VARIANT_SUPPORT
#define CDD_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CDD_COMIF  STD_OFF
#define CDD_COMIF_RX  STD_OFF
#define CDD_COMIF_TX  STD_OFF
#define CDD_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_UL_COMIF  STD_OFF
#define CDD_PDUR_UL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_UL_COMTP  STD_OFF

#define CDD_PDUR_LL_COMIF  STD_OFF
#define CDD_PDUR_LL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_PDUR_LL_COMTP  STD_OFF

#define CDD_SOADUL_COMIF_RX  STD_ON
#define CDD_SOADUL_COMIF_TRIGGERTRANSMIT  STD_OFF
#define CDD_SOADUL_COMIF_TXCONFIRMATION   STD_OFF

#define CDD_SOADUL_COMTP_RX  STD_OFF
#define CDD_SOADUL_COMTP_TX  STD_OFF





/**
 * \defgroup CddHandleIdsSoAdUpperLayerIfRx Handle IDs of handle space SoAdUpperLayerIfRx.
 * \brief CddSoAdUpperLayerContribution communication interface Rx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX                 0u      /**< [PostBuildInvariantValuesModelView] */
#define CddConf_CddSoAdUpperLayerRxPdu_RDR_VEH_UDP_STREAM_RX          1u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**
 * \defgroup CddHandleIdsSoAdUpperLayerIfTx Handle IDs of handle space SoAdUpperLayerIfTx.
 * \brief CddSoAdUpperLayerContribution communication interface Tx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CddConf_CddSoAdUpperLayerTxPdu_RDR_HIL_Res_Tx                 0u      /**< [PostBuildInvariantValuesModelView] */
#define CddConf_CddSoAdUpperLayerTxPdu_RDR_LOGGING_TX                 1u      /**< [PostBuildInvariantValuesModelView] */
#define CddConf_CddSoAdUpperLayerTxPdu_RDR_LOGGING_TX_FAST            2u      /**< [PostBuildInvariantValuesModelView] */
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define CDD_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "Cdd_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */




/*! \defgroup ProvidedCddCddUpperLayerInterface2SoAd Provided Cdd communication interface to SoAd
    \brief    These services have to be provided by the Cdd if the CDD is an upper layer for the SoAd. */
/*\{*/

# if (CDD_SOADUL_COMIF_RX == STD_ON)
/**********************************************************************************************************************
  Cdd_SoAdIfRxIndication
**********************************************************************************************************************/
/*! \brief         The function is called to indicate the complete reception of a RX I-PDU.
    \param[in]     RxPduId      Id of the IF CddSoAdUpperLayerRxPdu.
    \param[in]     PduInfoPtr   MetaDataPtr may contain optional meta data or NULL_PTR.
                                SduDataPtr contains payload information of the received I-PDU.
                                SduLength contains data length of the received I-PDU.
    \return        none
    \pre           The Cdd is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_SoAdIfRxIndication call for the same RxPduId.
    \note          The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Cdd_SoAdIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr);
# endif

# if (CDD_SOADUL_COMIF_TXCONFIRMATION == STD_ON)
/**********************************************************************************************************************
  Cdd_SoAdIfTxConfirmation
**********************************************************************************************************************/
/*! \brief         The function is called to confirm the complete transmission of a TX I-PDU.
    \param[in]     TxPduId      Id of the IF CddSoAdUpperLayerTxPdu.
    \return        none
    \pre           The Cdd is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_SoAdIfTxConfirmation call for the same TxPduId.
    \note          The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Cdd_SoAdIfTxConfirmation(PduIdType TxPduId);
# endif

# if (CDD_SOADUL_COMIF_TRIGGERTRANSMIT == STD_ON)
/**********************************************************************************************************************
  Cdd_SoAdIfTriggerTransmit
**********************************************************************************************************************/
/*! \brief         The function is called to request the TX I-PDU data before transmission.
    \param[in]     TxPduId      Id of the IF CddSoAdUpperLayerTxPdu.
    \param[in,out] PduInfoPtr   MetaDataPtr is ignored. No meta data is copied in the TriggerTransmit API.
                                SduDataPtr points to a buffer where the SDU shall be copied to.
                                SduLength contains the available buffer size in SduDataPtr. On return, the service will indicate the length of the copied SDU data in the SduLength.
    \return        E_OK         SDU has been copied and SduLength indicates the number of copied bytes.
    \return        E_NOT_OK     No data has been copied, because
                                Cdd is not initialized
                                or TxPduId is not valid
                                or PduInfoPtr is NULL_PTR
                                or SduDataPtr is NULL_PTR
                                or SduLength is too small.
    \pre           The Cdd is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_SoAdIfTriggerTransmit call for the same TxPduId.
    \note          The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_CODE) Cdd_SoAdIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, CDD_APPL_DATA) PduInfoPtr);
# endif
/*\}*/

/*! \defgroup ProvidedCddCddUpperLayerInterface2SoAd Provided Cdd transport protocol interface to SoAd
    \brief    These services have to be provided by the Cdd if the CDD is an upper layer for the SoAd. */
/*\{*/

# if (CDD_SOADUL_COMTP_RX == STD_ON)
/**********************************************************************************************************************
  Cdd_SoAdTpStartOfReception
**********************************************************************************************************************/
/*! \brief       The function call indicates the reception start of a segmented PDU.
    \param[in]   id             Id of the TP CddSoAdUpperLayerRxPdu.
    \param[in]   info           MetaDataPtr contains optional meta data or NULL_PTR.
                                SduDataPtr contains payload data of the first frame or single frame of a transport protocol I-PDU reception or NULL_PTR.
                                SduLength contains the payload length of the first frame or single frame of a transport protocol I-PDU reception or 0 in case of a NULL_PTR in SduDataPtr.
    \param[in]   TpSduLength    Length of the entire the TP SDU that will be received.
    \param[out]  bufferSizePtr  Length of the available receive buffer in Cdd.\n
                                This parameter is used e.g. in CanTp to calculate the Block Size (BS).
    \return      a BufReq_ReturnType constant of ComStackTypes.h.
    \pre         The Cdd is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Cdd_SoAdTpStartOfReception calls for the same id.
    \note        The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDD_CODE) Cdd_SoAdTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, CDD_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, CDD_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
  Cdd_SoAdTpCopyRxData
**********************************************************************************************************************/
/*! \brief       This function is called to trigger the copy process of a segmented PDU.\n
                 The function can be called several times and\n
                 each call to this function copies parts of the received data.\n
    \param[in]   id             Id of the TP CddSoAdUpperLayerRxPdu.
    \param[in]   info           MetaDataPtr is ignored. No meta data is copied in the CopyRxData API.
                                SduDataPtr contains data to be copied in the <CDD> data buffer.
                                SduLength contains length of the aforementioned data.
    \param[out]  bufferSizePtr  Available receive buffer after data has been copied.
    \return      a BufReq_ReturnType constant of ComStackTypes.h.      
    \pre         The Cdd is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Cdd_SoAdTpCopyRxData calls for the same id.
    \note        The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDD_CODE) Cdd_SoAdTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, CDD_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, CDD_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
  Cdd_SoAdTpRxIndication
**********************************************************************************************************************/
/*! \brief       The function is called to indicate the complete reception of a Cdd TP SDU
                 or to report an error that occurred during reception.
    \param[in]   id             Id of the TP CddSoAdUpperLayerRxPdu.
    \param[in]   result         A Std_ReturnType to indicate the result of the reception.
    \return      none
    \pre         The Cdd is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Cdd_SoAdTpRxIndication calls for the same id.
    \note        The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Cdd_SoAdTpRxIndication(PduIdType id, Std_ReturnType result);
# endif

# if (CDD_SOADUL_COMTP_TX == STD_ON)
/**********************************************************************************************************************
  Cdd_SoAdTpCopyTxData
**********************************************************************************************************************/
/*! \brief       This function is called to request transmit data of a TP CddSoAdUpperLayerTxPdu\n
                 The function can be called several times and\n
                 each call to this function copies the next part of the data to be transmitted.\n
    \param[in]   id             Id of the TP CddSoAdUpperLayerTxPdu.
    \param[in]   info           MetaDataPtr is ignored. No meta data is copied in the CopyTxData API.
                                SduDataPtr points to the destination buffer.
                                SduLength contains the length of the destination buffer.
    \param[in]   retry          NULL_PTR to indicate a successful copy process\n
                                or a RetryInfoType containing a TpDataStateType constant of ComStackTypes.h.
    \param       availableDataPtr   Indicates the remaining number of bytes that are available in the TX buffer.\n
                                availableDataPtr can be used by TP modules that support dynamic payload lengths\n
                                (e.g. Iso FrTp) to determine the size of the following CFs.
    \return      A BufReq_ReturnType constant of ComStackTypes.h.
    \pre         The Cdd is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Cdd_SoAdTpCopyTxData calls for the same id.
    \note        The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDD_CODE) Cdd_SoAdTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, CDD_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, CDD_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, CDD_APPL_DATA) availableDataPtr);

/**********************************************************************************************************************
  Cdd_SoAdTpTxConfirmation
**********************************************************************************************************************/
/*! \brief       The function is called to confirm a successful transmission of a TP CddSoAdUpperLayerTxPdu\n
                 or to report an error that occurred during transmission.
    \param[in]   id             Id of the TP CddSoAdUpperLayerTxPdu.
    \param[in]   result         A Std_ReturnType to indicate the result of the transmission.
    \return      none
    \pre         The Cdd is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Cdd_SoAdTpTxConfirmation calls for the same id.
    \note        The function is called by the SoAd.
**********************************************************************************************************************/
FUNC(void, CDD_CODE) Cdd_SoAdTpTxConfirmation(PduIdType id, Std_ReturnType result);
# endif

/*\}*/



# define CDD_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "Cdd_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */

#endif  /* CDD_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Cdd_Cbk.h
**********************************************************************************************************************/


