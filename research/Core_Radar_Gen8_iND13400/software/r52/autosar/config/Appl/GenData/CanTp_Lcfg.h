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
 *            Module: CanTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.h
 *   Generation Time: 2026-08-05 12:38:40
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

#if !defined(CANTP_LCFG_H)
#define CANTP_LCFG_H
/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "CanTp_Types.h"
#include "Os.h"
#include "CanTp_PBcfg.h"


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCSizeOfTypes  CanTp SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for CanTp_SizeOfCalcBS */
typedef uint8 CanTp_SizeOfCalcBSType;

/**   \brief  value based type definition for CanTp_SizeOfPartitionIdentifiers */
typedef uint8 CanTp_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTp_SizeOfRxPdu2RxSduInd */
typedef uint8 CanTp_SizeOfRxPdu2RxSduIndType;

/**   \brief  value based type definition for CanTp_SizeOfRxPdu2TxSduInd */
typedef uint8 CanTp_SizeOfRxPdu2TxSduIndType;

/**   \brief  value based type definition for CanTp_SizeOfRxPduMap */
typedef uint8 CanTp_SizeOfRxPduMapType;

/**   \brief  value based type definition for CanTp_SizeOfRxSduCfg */
typedef uint8 CanTp_SizeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_SizeOfRxSduSnv2Hdl */
typedef uint8 CanTp_SizeOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_SizeOfRxState */
typedef uint8 CanTp_SizeOfRxStateType;

/**   \brief  value based type definition for CanTp_SizeOfTxPdu2RxSduInd */
typedef uint8 CanTp_SizeOfTxPdu2RxSduIndType;

/**   \brief  value based type definition for CanTp_SizeOfTxPdu2TxSduInd */
typedef uint8 CanTp_SizeOfTxPdu2TxSduIndType;

/**   \brief  value based type definition for CanTp_SizeOfTxPduMap */
typedef uint8 CanTp_SizeOfTxPduMapType;

/**   \brief  value based type definition for CanTp_SizeOfTxSduCfg */
typedef uint8 CanTp_SizeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_SizeOfTxSduSnv2Hdl */
typedef uint8 CanTp_SizeOfTxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_SizeOfTxSemaphores */
typedef uint8 CanTp_SizeOfTxSemaphoresType;

/**   \brief  value based type definition for CanTp_SizeOfTxState */
typedef uint8 CanTp_SizeOfTxStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCIterableTypes  CanTp Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanTp_CalcBS */
typedef uint8_least CanTp_CalcBSIterType;

/**   \brief  type used to iterate CanTp_PartitionIdentifiers */
typedef uint8_least CanTp_PartitionIdentifiersIterType;

/**   \brief  type used to iterate CanTp_RxPdu2RxSduInd */
typedef uint8_least CanTp_RxPdu2RxSduIndIterType;

/**   \brief  type used to iterate CanTp_RxPdu2TxSduInd */
typedef uint8_least CanTp_RxPdu2TxSduIndIterType;

/**   \brief  type used to iterate CanTp_RxPduMap */
typedef uint8_least CanTp_RxPduMapIterType;

/**   \brief  type used to iterate CanTp_RxSduCfg */
typedef uint8_least CanTp_RxSduCfgIterType;

/**   \brief  type used to iterate CanTp_RxSduSnv2Hdl */
typedef uint8_least CanTp_RxSduSnv2HdlIterType;

/**   \brief  type used to iterate CanTp_RxState */
typedef uint8_least CanTp_RxStateIterType;

/**   \brief  type used to iterate CanTp_TxPdu2RxSduInd */
typedef uint8_least CanTp_TxPdu2RxSduIndIterType;

/**   \brief  type used to iterate CanTp_TxPdu2TxSduInd */
typedef uint8_least CanTp_TxPdu2TxSduIndIterType;

/**   \brief  type used to iterate CanTp_TxPduMap */
typedef uint8_least CanTp_TxPduMapIterType;

/**   \brief  type used to iterate CanTp_TxSduCfg */
typedef uint8_least CanTp_TxSduCfgIterType;

/**   \brief  type used to iterate CanTp_TxSduSnv2Hdl */
typedef uint8_least CanTp_TxSduSnv2HdlIterType;

/**   \brief  type used to iterate CanTp_TxSemaphores */
typedef uint8_least CanTp_TxSemaphoresIterType;

/**   \brief  type used to iterate CanTp_TxState */
typedef uint8_least CanTp_TxStateIterType;

/**   \brief  type used to iterate CanTp_PCPartitionConfig */
typedef uint8_least CanTp_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCValueTypes  CanTp Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanTp_CalcBS */
typedef uint8 CanTp_CalcBSType;

/**   \brief  value based type definition for CanTp_CompatibilityVersion */
typedef uint32 CanTp_CompatibilityVersionType;

/**   \brief  value based type definition for CanTp_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 CanTp_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for CanTp_RxPdu2RxSduInd */
typedef uint8 CanTp_RxPdu2RxSduIndType;

/**   \brief  value based type definition for CanTp_RxPdu2TxSduInd */
typedef uint8 CanTp_RxPdu2TxSduIndType;

/**   \brief  value based type definition for CanTp_AddressingFormatOfRxPduMap */
typedef uint8 CanTp_AddressingFormatOfRxPduMapType;

/**   \brief  value based type definition for CanTp_GenericConnectionOfRxPduMap */
typedef boolean CanTp_GenericConnectionOfRxPduMapType;

/**   \brief  value based type definition for CanTp_PduMetadataOfRxPduMap */
typedef boolean CanTp_PduMetadataOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2RxSduEndIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2RxSduEndIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2RxSduPartitionIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2RxSduPartitionIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2RxSduStartIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2RxSduStartIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2RxSduUsedOfRxPduMap */
typedef boolean CanTp_RxPdu2RxSduUsedOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2TxSduEndIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2TxSduEndIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2TxSduPartitionIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2TxSduPartitionIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2TxSduStartIdxOfRxPduMap */
typedef uint8 CanTp_RxPdu2TxSduStartIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxPdu2TxSduUsedOfRxPduMap */
typedef boolean CanTp_RxPdu2TxSduUsedOfRxPduMapType;

/**   \brief  value based type definition for CanTp_BlockSizeOfRxSduCfg */
typedef uint8 CanTp_BlockSizeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_CanTypeOfRxSduCfg */
typedef uint8 CanTp_CanTypeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_ChannelModeOfRxSduCfg */
typedef uint8 CanTp_ChannelModeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_GenericConnectionOfRxSduCfg */
typedef boolean CanTp_GenericConnectionOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_LoLayerTxFcPduIdOfRxSduCfg */
typedef PduIdType CanTp_LoLayerTxFcPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NArOfRxSduCfg */
typedef uint8 CanTp_NArOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NBrOfRxSduCfg */
typedef uint8 CanTp_NBrOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NCrOfRxSduCfg */
typedef uint8 CanTp_NCrOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_PduRRxSduIdOfRxSduCfg */
typedef PduIdType CanTp_PduRRxSduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxAddressOfRxSduCfg */
typedef uint8 CanTp_RxAddressOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxAddressingFormatOfRxSduCfg */
typedef uint8 CanTp_RxAddressingFormatOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxMaxPayloadLengthOfRxSduCfg */
typedef uint8 CanTp_RxMaxPayloadLengthOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPaddingActivationOfRxSduCfg */
typedef boolean CanTp_RxPaddingActivationOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduIdOfRxSduCfg */
typedef PduIdType CanTp_RxPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduMapIdxOfRxSduCfg */
typedef uint8 CanTp_RxPduMapIdxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduMapUsedOfRxSduCfg */
typedef boolean CanTp_RxPduMapUsedOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxTaTypeOfRxSduCfg */
typedef uint8 CanTp_RxTaTypeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxWftMaxOfRxSduCfg */
typedef uint8 CanTp_RxWftMaxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_STminOfRxSduCfg */
typedef uint8 CanTp_STminOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_SduMetadataLengthOfRxSduCfg */
typedef uint8 CanTp_SduMetadataLengthOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxFcAddressOfRxSduCfg */
typedef uint8 CanTp_TxFcAddressOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxFcPduConfirmationPduIdOfRxSduCfg */
typedef PduIdType CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduMapIdxOfRxSduCfg */
typedef uint8 CanTp_TxPduMapIdxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduMapUsedOfRxSduCfg */
typedef boolean CanTp_TxPduMapUsedOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxSduCfgIdxOfRxSduCfg */
typedef uint8 CanTp_TxSduCfgIdxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxSduCfgUsedOfRxSduCfg */
typedef boolean CanTp_TxSduCfgUsedOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxNSduHdlIdxOfRxSduSnv2Hdl */
typedef uint8 CanTp_RxNSduHdlIdxOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_RxNSduHdlPartitionIdxOfRxSduSnv2Hdl */
typedef uint8 CanTp_RxNSduHdlPartitionIdxOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_RxNSduHdlUsedOfRxSduSnv2Hdl */
typedef boolean CanTp_RxNSduHdlUsedOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_TxPdu2RxSduInd */
typedef uint8 CanTp_TxPdu2RxSduIndType;

/**   \brief  value based type definition for CanTp_TxPdu2TxSduInd */
typedef uint8 CanTp_TxPdu2TxSduIndType;

/**   \brief  value based type definition for CanTp_CanIdOfTxPduMap */
typedef uint32 CanTp_CanIdOfTxPduMapType;

/**   \brief  value based type definition for CanTp_MaskOfTxPduMap */
typedef uint32 CanTp_MaskOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2RxSduEndIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2RxSduEndIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2RxSduPartitionIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2RxSduPartitionIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2RxSduStartIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2RxSduStartIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2RxSduUsedOfTxPduMap */
typedef boolean CanTp_TxPdu2RxSduUsedOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2TxSduEndIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2TxSduEndIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2TxSduPartitionIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2TxSduPartitionIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2TxSduStartIdxOfTxPduMap */
typedef uint8 CanTp_TxPdu2TxSduStartIdxOfTxPduMapType;

/**   \brief  value based type definition for CanTp_TxPdu2TxSduUsedOfTxPduMap */
typedef boolean CanTp_TxPdu2TxSduUsedOfTxPduMapType;

/**   \brief  value based type definition for CanTp_CanTypeOfTxSduCfg */
typedef uint8 CanTp_CanTypeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_ChannelModeOfTxSduCfg */
typedef uint8 CanTp_ChannelModeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_LoLayerTxPduIdOfTxSduCfg */
typedef PduIdType CanTp_LoLayerTxPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NAsOfTxSduCfg */
typedef uint8 CanTp_NAsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NBsOfTxSduCfg */
typedef uint8 CanTp_NBsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NCsOfTxSduCfg */
typedef uint8 CanTp_NCsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_PduRTxSduIdOfTxSduCfg */
typedef PduIdType CanTp_PduRTxSduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxFcAddressOfTxSduCfg */
typedef uint8 CanTp_RxFcAddressOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxFcPduIdOfTxSduCfg */
typedef PduIdType CanTp_RxFcPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduMapIdxOfTxSduCfg */
typedef uint8 CanTp_RxPduMapIdxOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduMapUsedOfTxSduCfg */
typedef boolean CanTp_RxPduMapUsedOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxSduCfgIdxOfTxSduCfg */
typedef uint8 CanTp_RxSduCfgIdxOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxSduCfgUsedOfTxSduCfg */
typedef boolean CanTp_RxSduCfgUsedOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_SduMetadataLengthOfTxSduCfg */
typedef uint8 CanTp_SduMetadataLengthOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TransmitCancellationOfTxSduCfg */
typedef boolean CanTp_TransmitCancellationOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxAddressOfTxSduCfg */
typedef uint8 CanTp_TxAddressOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxAddressingFormatOfTxSduCfg */
typedef uint8 CanTp_TxAddressingFormatOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxMaxPayloadLengthOfTxSduCfg */
typedef uint8 CanTp_TxMaxPayloadLengthOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPaddingActivationOfTxSduCfg */
typedef boolean CanTp_TxPaddingActivationOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduConfirmationPduIdOfTxSduCfg */
typedef PduIdType CanTp_TxPduConfirmationPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduMapIdxOfTxSduCfg */
typedef uint8 CanTp_TxPduMapIdxOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduMapUsedOfTxSduCfg */
typedef boolean CanTp_TxPduMapUsedOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxTaTypeOfTxSduCfg */
typedef uint8 CanTp_TxTaTypeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxNSduHdlIdxOfTxSduSnv2Hdl */
typedef uint8 CanTp_TxNSduHdlIdxOfTxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_TxNSduHdlPartitionIdxOfTxSduSnv2Hdl */
typedef uint8 CanTp_TxNSduHdlPartitionIdxOfTxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_TxNSduHdlUsedOfTxSduSnv2Hdl */
typedef boolean CanTp_TxNSduHdlUsedOfTxSduSnv2HdlType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCStructTypes  CanTp Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanTp_PartitionIdentifiers */
typedef struct sCanTp_PartitionIdentifiersType
{
  CanTp_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  CanTp_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to CanTp_PCPartitionConfig */
} CanTp_PartitionIdentifiersType;

/**   \brief  type used in CanTp_RxPduMap */
typedef struct sCanTp_RxPduMapType
{
  CanTp_RxPdu2RxSduEndIdxOfRxPduMapType RxPdu2RxSduEndIdxOfRxPduMap;  /**< the end index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd */
  CanTp_RxPdu2RxSduStartIdxOfRxPduMapType RxPdu2RxSduStartIdxOfRxPduMap;  /**< the start index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd */
  CanTp_RxPdu2TxSduEndIdxOfRxPduMapType RxPdu2TxSduEndIdxOfRxPduMap;  /**< the end index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd */
  CanTp_RxPdu2TxSduPartitionIdxOfRxPduMapType RxPdu2TxSduPartitionIdxOfRxPduMap;  /**< the partition index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd */
  CanTp_RxPdu2TxSduStartIdxOfRxPduMapType RxPdu2TxSduStartIdxOfRxPduMap;  /**< the start index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd */
} CanTp_RxPduMapType;

/**   \brief  type used in CanTp_RxSduCfg */
typedef struct sCanTp_RxSduCfgType
{
  CanTp_LoLayerTxFcPduIdOfRxSduCfgType LoLayerTxFcPduIdOfRxSduCfg;
  CanTp_PduRRxSduIdOfRxSduCfgType PduRRxSduIdOfRxSduCfg;
  CanTp_RxPduIdOfRxSduCfgType RxPduIdOfRxSduCfg;
  CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType TxFcPduConfirmationPduIdOfRxSduCfg;
  CanTp_CanTypeOfRxSduCfgType CanTypeOfRxSduCfg;
  CanTp_NArOfRxSduCfgType NArOfRxSduCfg;
  CanTp_NBrOfRxSduCfgType NBrOfRxSduCfg;
  CanTp_NCrOfRxSduCfgType NCrOfRxSduCfg;
  CanTp_RxMaxPayloadLengthOfRxSduCfgType RxMaxPayloadLengthOfRxSduCfg;
  CanTp_RxPduMapIdxOfRxSduCfgType RxPduMapIdxOfRxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_RxPduMap */
  CanTp_RxTaTypeOfRxSduCfgType RxTaTypeOfRxSduCfg;
  CanTp_STminOfRxSduCfgType STminOfRxSduCfg;
  CanTp_TxPduMapIdxOfRxSduCfgType TxPduMapIdxOfRxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_TxPduMap */
  CanTp_TxSduCfgIdxOfRxSduCfgType TxSduCfgIdxOfRxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_TxSduCfg */
} CanTp_RxSduCfgType;

/**   \brief  type used in CanTp_RxSduSnv2Hdl */
typedef struct sCanTp_RxSduSnv2HdlType
{
  CanTp_RxNSduHdlIdxOfRxSduSnv2HdlType RxNSduHdlIdxOfRxSduSnv2Hdl;  /**< the index of the 0:1 relation pointing to CanTp_RxSduCfg */
} CanTp_RxSduSnv2HdlType;

/**   \brief  type used in CanTp_TxPduMap */
typedef struct sCanTp_TxPduMapType
{
  CanTp_CanIdOfTxPduMapType CanIdOfTxPduMap;
  CanTp_TxPdu2RxSduEndIdxOfTxPduMapType TxPdu2RxSduEndIdxOfTxPduMap;  /**< the end index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd */
  CanTp_TxPdu2RxSduStartIdxOfTxPduMapType TxPdu2RxSduStartIdxOfTxPduMap;  /**< the start index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd */
  CanTp_TxPdu2TxSduEndIdxOfTxPduMapType TxPdu2TxSduEndIdxOfTxPduMap;  /**< the end index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd */
  CanTp_TxPdu2TxSduStartIdxOfTxPduMapType TxPdu2TxSduStartIdxOfTxPduMap;  /**< the start index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd */
} CanTp_TxPduMapType;

/**   \brief  type used in CanTp_TxSduCfg */
typedef struct sCanTp_TxSduCfgType
{
  CanTp_LoLayerTxPduIdOfTxSduCfgType LoLayerTxPduIdOfTxSduCfg;
  CanTp_PduRTxSduIdOfTxSduCfgType PduRTxSduIdOfTxSduCfg;
  CanTp_RxFcPduIdOfTxSduCfgType RxFcPduIdOfTxSduCfg;
  CanTp_TxPduConfirmationPduIdOfTxSduCfgType TxPduConfirmationPduIdOfTxSduCfg;
  CanTp_CanTypeOfTxSduCfgType CanTypeOfTxSduCfg;
  CanTp_RxPduMapIdxOfTxSduCfgType RxPduMapIdxOfTxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_RxPduMap */
  CanTp_RxSduCfgIdxOfTxSduCfgType RxSduCfgIdxOfTxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_RxSduCfg */
  CanTp_TxMaxPayloadLengthOfTxSduCfgType TxMaxPayloadLengthOfTxSduCfg;
  CanTp_TxPduMapIdxOfTxSduCfgType TxPduMapIdxOfTxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_TxPduMap */
} CanTp_TxSduCfgType;

/**   \brief  type used in CanTp_TxSduSnv2Hdl */
typedef struct sCanTp_TxSduSnv2HdlType
{
  CanTp_TxNSduHdlIdxOfTxSduSnv2HdlType TxNSduHdlIdxOfTxSduSnv2Hdl;  /**< the index of the 0:1 relation pointing to CanTp_TxSduCfg */
} CanTp_TxSduSnv2HdlType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCRootPointerTypes  CanTp Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanTp_CalcBS */
typedef P2VAR(CanTp_CalcBSType, TYPEDEF, CANTP_VAR_NO_INIT) CanTp_CalcBSPtrType;

/**   \brief  type used to point to CanTp_PartitionIdentifiers */
typedef P2CONST(CanTp_PartitionIdentifiersType, TYPEDEF, CANTP_CONST) CanTp_PartitionIdentifiersPtrType;

/**   \brief  type used to point to CanTp_RxPdu2RxSduInd */
typedef P2CONST(CanTp_RxPdu2RxSduIndType, TYPEDEF, CANTP_CONST) CanTp_RxPdu2RxSduIndPtrType;

/**   \brief  type used to point to CanTp_RxPdu2TxSduInd */
typedef P2CONST(CanTp_RxPdu2TxSduIndType, TYPEDEF, CANTP_CONST) CanTp_RxPdu2TxSduIndPtrType;

/**   \brief  type used to point to CanTp_RxPduMap */
typedef P2CONST(CanTp_RxPduMapType, TYPEDEF, CANTP_CONST) CanTp_RxPduMapPtrType;

/**   \brief  type used to point to CanTp_RxSduCfg */
typedef P2CONST(CanTp_RxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_RxSduCfgPtrType;

/**   \brief  type used to point to CanTp_RxSduSnv2Hdl */
typedef P2CONST(CanTp_RxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_RxSduSnv2HdlPtrType;

/**   \brief  type used to point to CanTp_RxState */
typedef P2VAR(CanTp_RxStateType, TYPEDEF, CANTP_VAR_NO_INIT) CanTp_RxStatePtrType;

/**   \brief  type used to point to CanTp_TxPdu2RxSduInd */
typedef P2CONST(CanTp_TxPdu2RxSduIndType, TYPEDEF, CANTP_CONST) CanTp_TxPdu2RxSduIndPtrType;

/**   \brief  type used to point to CanTp_TxPdu2TxSduInd */
typedef P2CONST(CanTp_TxPdu2TxSduIndType, TYPEDEF, CANTP_CONST) CanTp_TxPdu2TxSduIndPtrType;

/**   \brief  type used to point to CanTp_TxPduMap */
typedef P2CONST(CanTp_TxPduMapType, TYPEDEF, CANTP_CONST) CanTp_TxPduMapPtrType;

/**   \brief  type used to point to CanTp_TxSduCfg */
typedef P2CONST(CanTp_TxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_TxSduCfgPtrType;

/**   \brief  type used to point to CanTp_TxSduSnv2Hdl */
typedef P2CONST(CanTp_TxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_TxSduSnv2HdlPtrType;

/**   \brief  type used to point to CanTp_TxSemaphores */
typedef P2VAR(CanTp_TxSemaphoreType, TYPEDEF, CANTP_VAR_NO_INIT) CanTp_TxSemaphoresPtrType;

/**   \brief  type used to point to CanTp_TxState */
typedef P2VAR(CanTp_TxStateType, TYPEDEF, CANTP_VAR_NO_INIT) CanTp_TxStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCPartitionRootPointer  CanTp Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in CanTp_PCPartitionConfig */
typedef struct sCanTp_PCPartitionConfigType
{
  CanTp_RxPdu2RxSduIndPtrType RxPdu2RxSduIndOfPCPartitionConfig;  /**< the pointer to CanTp_RxPdu2RxSduInd */
  CanTp_RxPdu2TxSduIndPtrType RxPdu2TxSduIndOfPCPartitionConfig;  /**< the pointer to CanTp_RxPdu2TxSduInd */
  CanTp_RxSduCfgPtrType RxSduCfgOfPCPartitionConfig;  /**< the pointer to CanTp_RxSduCfg */
  CanTp_TxPdu2RxSduIndPtrType TxPdu2RxSduIndOfPCPartitionConfig;  /**< the pointer to CanTp_TxPdu2RxSduInd */
  CanTp_TxPdu2TxSduIndPtrType TxPdu2TxSduIndOfPCPartitionConfig;  /**< the pointer to CanTp_TxPdu2TxSduInd */
  CanTp_TxSduCfgPtrType TxSduCfgOfPCPartitionConfig;  /**< the pointer to CanTp_TxSduCfg */
} CanTp_PCPartitionConfigType;

/**   \brief  type used to point to CanTp_PCPartitionConfig */
typedef P2CONST(CanTp_PCPartitionConfigType, TYPEDEF, CANTP_CONST) CanTp_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCRootValueTypes  CanTp Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanTp_PCConfig */
typedef struct sCanTp_PCConfigType
{
  CanTp_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to CanTp_PCPartitionConfig */
} CanTp_PCConfigType;

typedef CanTp_PCConfigType CanTp_PBConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanTp_PCConfig in a symbol based style. */
typedef struct sCanTp_PCConfigsType
{
  CanTp_PCConfigType Config_RDR_01;  /**< [Config_RDR_01] */
  CanTp_PCConfigType Config_RDR_02;  /**< [Config_RDR_02] */
  CanTp_PCConfigType Config_RDR_03;  /**< [Config_RDR_03] */
  CanTp_PCConfigType Config_RDR_04;  /**< [Config_RDR_04] */
  CanTp_PCConfigType Config_RDR_05;  /**< [Config_RDR_05] */
  CanTp_PCConfigType Config_RDR_06;  /**< [Config_RDR_06] */
  CanTp_PCConfigType Config_RDR_07;  /**< [Config_RDR_07] */
  CanTp_PCConfigType Config_RDR_08;  /**< [Config_RDR_08] */
} CanTp_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


#define CanTp_IsPreInitialized()        (CanTp_PreInitialized != FALSE)
#define CanTp_SetPreInitialized(Value)  (CanTp_PreInitialized = (Value))

/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(CANTP_USE_INIT_POINTER == STD_ON)
extern P2CONST(CanTp_PBConfigType, CANTP_VAR_CLEARED, CANTP_PBCFG) CanTp_ConfigDataPtr;
#endif

#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, CANTP_VAR_NO_INIT) CanTp_PreInitialized;

#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTp_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTp_PCPartitionConfig
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PartitionIdentifiersType, CANTP_CONST) CanTp_PartitionIdentifiers[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_01[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_02[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_03[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_04[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_05[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_06[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_07[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2RxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2RxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2RxSduIndType, CANTP_CONST) CanTp_RxPdu2RxSduIndRDR_08[24];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_01[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_02[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_03[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_04[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_05[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_06[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_07[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPdu2TxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPdu2TxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPdu2TxSduIndType, CANTP_CONST) CanTp_RxPdu2TxSduIndRDR_08[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \brief  Table of Addressing Infos of RxNPdus
  \details
  Element                    Description
  RxPdu2RxSduEndIdx          the end index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd
  RxPdu2RxSduStartIdx        the start index of the 0:n relation pointing to one of CanTp_RxPdu2RxSduInd
  RxPdu2TxSduEndIdx          the end index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
  RxPdu2TxSduPartitionIdx    the partition index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
  RxPdu2TxSduStartIdx        the start index of the 0:n relation pointing to one of CanTp_RxPdu2TxSduInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_01
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_01[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_02
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_02[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_03
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_03[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_04
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_04[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_05
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_05[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_06
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_06[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_07
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_07[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRDR_08
  \brief  CanTp RxNSdu Configuration
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  CanType                 
  NAr                     
  NBr                     
  NCr                     
  RxMaxPayloadLength      
  RxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxTaType                
  STmin                   
  TxPduMapIdx                 the index of the 0:1 relation pointing to CanTp_TxPduMap
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRDR_08[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \brief  CanTpRxNSdu SNV to Handle (i.e. internal index) mapping
  \details
  Element         Description
  RxNSduHdlIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[24];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_01[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_02[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_03[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_04[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_05[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_06[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_07[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2RxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2RxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2RxSduIndType, CANTP_CONST) CanTp_TxPdu2RxSduIndRDR_08[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_01
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_01[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_02
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_02[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_03
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_03[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_04
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_04[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_05
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_05[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_06
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_06[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_07
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_07[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPdu2TxSduIndRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPdu2TxSduIndRDR_08
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPdu2TxSduIndType, CANTP_CONST) CanTp_TxPdu2TxSduIndRDR_08[12];
#define CANTP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_TxPduMap
  \brief  Table of Usage Infos of TxNPdus
  \details
  Element                Description
  CanId              
  TxPdu2RxSduEndIdx      the end index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd
  TxPdu2RxSduStartIdx    the start index of the 0:n relation pointing to one of CanTp_TxPdu2RxSduInd
  TxPdu2TxSduEndIdx      the end index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd
  TxPdu2TxSduStartIdx    the start index of the 0:n relation pointing to one of CanTp_TxPdu2TxSduInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxPduMapType, CANTP_CONST) CanTp_TxPduMap[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_01
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_01[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_02
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_02[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_03
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_03[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_04
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_04[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_05
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_05[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_06
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_06[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_07
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_07[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRDR_08
  \brief  CanTp TxNSdu Configuration
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxPduMapIdx               the index of the 0:1 relation pointing to CanTp_RxPduMap
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
  TxPduMapIdx               the index of the 0:1 relation pointing to CanTp_TxPduMap
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRDR_08[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \brief  CanTpTxNSdu SNV to Handle (i.e. internal index) mapping
  \details
  Element         Description
  TxNSduHdlIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[12];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
/** 
  \var    CanTp_CalcBS
  \brief  CalcBS array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_CalcBSType, CANTP_VAR_NO_INIT) CanTp_CalcBS[24];
#define CANTP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
/** 
  \var    CanTp_RxState
  \brief  RxState array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_RxStateType, CANTP_VAR_NO_INIT) CanTp_RxState[24];
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSemaphores
  \brief  TxSemaphores array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_TxSemaphoreType, CANTP_VAR_NO_INIT) CanTp_TxSemaphores[12];
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
/** 
  \var    CanTp_TxState
  \brief  TxState array
*/ 
#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_TxStateType, CANTP_VAR_NO_INIT) CanTp_TxState[12];
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTp_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to CanTp_PCPartitionConfig
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCConfigsType, CANTP_CONST) CanTp_PCConfig;
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_01
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_01[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_02
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_02
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_02[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_03
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_03
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_03[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_04
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_04
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_04[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_05
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_05[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_06
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_06
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_06[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_07
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_07
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_07[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCPartitionConfigRDR_08
**********************************************************************************************************************/
/** 
  \var    CanTp_PCPartitionConfigRDR_08
  \details
  Element           Description
  RxPdu2RxSduInd    the pointer to CanTp_RxPdu2RxSduInd
  RxPdu2TxSduInd    the pointer to CanTp_RxPdu2TxSduInd
  RxSduCfg          the pointer to CanTp_RxSduCfg
  TxPdu2RxSduInd    the pointer to CanTp_TxPdu2RxSduInd
  TxPdu2TxSduInd    the pointer to CanTp_TxPdu2TxSduInd
  TxSduCfg          the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCPartitionConfigType, CANTP_CONST) CanTp_PCPartitionConfigRDR_08[1];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/* -----------------------------------------------------------------------------
    &&&~ Global data types and structures
 ----------------------------------------------------------------------------- */



#endif /* CANTP_LCFG_H */
