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
 *            Module: SomeIpTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SomeIpTp_Types.h
 *   Generation Time: 2026-08-27 14:12:14
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

#if !defined (SOMEIPTP_TYPES_H)
# define SOMEIPTP_TYPES_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "ComStack_Types.h"


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
#if !defined (SOMEIPTP_LOCAL)
# define SOMEIPTP_LOCAL static
#endif

#if !defined (SOMEIPTP_LOCAL_INLINE)
# define SOMEIPTP_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* SOME/IP header length */
#define SOMEIPTP_SHORT_HEADER_LENGTH                 8u
/* SOME/IP TP header length */
#define SOMEIPTP_LONG_HEADER_LENGTH                  12u

typedef enum
{
 SOMEIPTP_TX_STATUS_IDLE = 0,
 SOMEIPTP_TX_STATUS_WAIT_TXCONF_SF,
 SOMEIPTP_TX_STATUS_WAIT_ST,
 SOMEIPTP_TX_STATUS_WAIT_TXCONF_LAST_SF
}SomeIpTp_StatusOfTxStateType;

typedef enum
{
 SOMEIPTP_RX_STATUS_IDLE = 0,
 SOMEIPTP_RX_STATUS_WAIT_NEXT_SF
}SomeIpTp_StatusOfRxStateType;

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  SomeIpTpPCSizeOfTypes  SomeIpTp SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for SomeIpTp_SizeOfChannel */
typedef uint8 SomeIpTp_SizeOfChannelType;

/**   \brief  value based type definition for SomeIpTp_SizeOfTXNSdu */
typedef uint8 SomeIpTp_SizeOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_SizeOfTxQueueElement */
typedef uint8 SomeIpTp_SizeOfTxQueueElementType;

/**   \brief  value based type definition for SomeIpTp_SizeOfTxShortHeaders */
typedef uint8 SomeIpTp_SizeOfTxShortHeadersType;

/**   \brief  value based type definition for SomeIpTp_SizeOfTxState */
typedef uint8 SomeIpTp_SizeOfTxStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SomeIpTpPCIterableTypes  SomeIpTp Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate SomeIpTp_Channel */
typedef uint8_least SomeIpTp_ChannelIterType;

/**   \brief  type used to iterate SomeIpTp_TXNSdu */
typedef uint8_least SomeIpTp_TXNSduIterType;

/**   \brief  type used to iterate SomeIpTp_TxQueueElement */
typedef uint8_least SomeIpTp_TxQueueElementIterType;

/**   \brief  type used to iterate SomeIpTp_TxShortHeaders */
typedef uint8_least SomeIpTp_TxShortHeadersIterType;

/**   \brief  type used to iterate SomeIpTp_TxState */
typedef uint8_least SomeIpTp_TxStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCValueTypes  SomeIpTp Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for SomeIpTp_NPduSeparationTimeOfChannel */
typedef uint8 SomeIpTp_NPduSeparationTimeOfChannelType;

/**   \brief  value based type definition for SomeIpTp_NumOfRxNSdusOfChannel */
typedef uint8 SomeIpTp_NumOfRxNSdusOfChannelType;

/**   \brief  value based type definition for SomeIpTp_NumOfTxNSdusOfChannel */
typedef uint8 SomeIpTp_NumOfTxNSdusOfChannelType;

/**   \brief  value based type definition for SomeIpTp_RxTimeoutTimeOfChannel */
typedef uint8 SomeIpTp_RxTimeoutTimeOfChannelType;

/**   \brief  value based type definition for SomeIpTp_TxConfTimeoutTimeOfChannel */
typedef uint8 SomeIpTp_TxConfTimeoutTimeOfChannelType;

/**   \brief  value based type definition for SomeIpTp_ChannelIdxOfTXNSdu */
typedef uint8 SomeIpTp_ChannelIdxOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_LowerLayerIdOfTXNSdu */
typedef PduIdType SomeIpTp_LowerLayerIdOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_MaxTxSFPayloadOfTXNSdu */
typedef uint16 SomeIpTp_MaxTxSFPayloadOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxBurstSizeOfTXNSdu */
typedef uint8 SomeIpTp_TxBurstSizeOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxNPduHandleIdOfTXNSdu */
typedef uint8 SomeIpTp_TxNPduHandleIdOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxNPduLengthOfTXNSdu */
typedef uint16 SomeIpTp_TxNPduLengthOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxNSduHandleIdOfTXNSdu */
typedef uint8 SomeIpTp_TxNSduHandleIdOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxShortHeadersEndIdxOfTXNSdu */
typedef uint8 SomeIpTp_TxShortHeadersEndIdxOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxShortHeadersStartIdxOfTXNSdu */
typedef uint8 SomeIpTp_TxShortHeadersStartIdxOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxStateIdxOfTXNSdu */
typedef uint8 SomeIpTp_TxStateIdxOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_UpperLayerIdOfTXNSdu */
typedef PduIdType SomeIpTp_UpperLayerIdOfTXNSduType;

/**   \brief  value based type definition for SomeIpTp_TxQueueElement */
typedef PduIdType SomeIpTp_TxQueueElementType;

/**   \brief  value based type definition for SomeIpTp_TxShortHeaders */
typedef uint8 SomeIpTp_TxShortHeadersType;

/**   \brief  value based type definition for SomeIpTp_DataIndexOfTxState */
typedef PduLengthType SomeIpTp_DataIndexOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_DataLengthOfTxState */
typedef PduLengthType SomeIpTp_DataLengthOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_MetadataOfTxState */
typedef uint16 SomeIpTp_MetadataOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_NextSegmentDLOfTxState */
typedef PduLengthType SomeIpTp_NextSegmentDLOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_OffsetOfTxState */
typedef uint32 SomeIpTp_OffsetOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_SegmentedOfTxState */
typedef boolean SomeIpTp_SegmentedOfTxStateType;

/**   \brief  value based type definition for SomeIpTp_TimerOfTxState */
typedef uint16 SomeIpTp_TimerOfTxStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SomeIpTpPCStructTypes  SomeIpTp Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in SomeIpTp_Channel */
typedef struct sSomeIpTp_ChannelType
{
  uint8 SomeIpTp_ChannelNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} SomeIpTp_ChannelType;

/**   \brief  type used in SomeIpTp_TXNSdu */
typedef struct sSomeIpTp_TXNSduType
{
  SomeIpTp_LowerLayerIdOfTXNSduType LowerLayerIdOfTXNSdu;  /**< SNV to the PDU referenced by the lower layer */
  SomeIpTp_UpperLayerIdOfTXNSduType UpperLayerIdOfTXNSdu;  /**< SNV to the PDU referenced by the upper layer */
} SomeIpTp_TXNSduType;

/**   \brief  type used in SomeIpTp_TxState */
typedef struct sSomeIpTp_TxStateType
{
  SomeIpTp_OffsetOfTxStateType OffsetOfTxState;  /**< Offset of the previous segment transmitted */
  SomeIpTp_DataIndexOfTxStateType DataIndexOfTxState;  /**< Index within the message */
  SomeIpTp_DataLengthOfTxStateType DataLengthOfTxState;  /**< Length of the complete frame */
  SomeIpTp_MetadataOfTxStateType MetadataOfTxState;  /**< Metadata of the active transmission. */
  SomeIpTp_NextSegmentDLOfTxStateType NextSegmentDLOfTxState;  /**< size of the next segmented PDU */
  SomeIpTp_TimerOfTxStateType TimerOfTxState;  /**< Separation time/Tx confirmation timeout timer of the SDU */
  SomeIpTp_SegmentedOfTxStateType SegmentedOfTxState;  /**< Flag indicating if the active transmission is segmented. */
  SomeIpTp_StatusOfTxStateType StatusOfTxState;  /**< State of the SDU */
} SomeIpTp_TxStateType;

/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCSymbolicStructTypes  SomeIpTp Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style for debugging purposes. These types are not used in the implementation!.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to SomeIpTp_TxShortHeaders for debugging purposes */
typedef struct SomeIpTp_TxShortHeadersStructSTag
{
  SomeIpTp_TxShortHeadersType PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced[8];
} SomeIpTp_TxShortHeadersStructSType;

/**   \brief  type to be used as symbolic data element access to SomeIpTp_TxState for debugging purposes */
typedef struct SomeIpTp_TxStateStructSTag
{
  SomeIpTp_TxStateType PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced;
} SomeIpTp_TxStateStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCUnionIndexAndSymbolTypes  SomeIpTp Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style. This type is for debugging purposes, in the implementation the access over the real array type with raw is always used.
  \{
*/ 
/**   \brief  type to access SomeIpTp_TxShortHeaders in an index and symbol based style for debugging purposes */
typedef union SomeIpTp_TxShortHeadersUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SomeIpTp_TxShortHeadersType raw[8];
  SomeIpTp_TxShortHeadersStructSType str;
} SomeIpTp_TxShortHeadersUType;

/**   \brief  type to access SomeIpTp_TxState in an index and symbol based style for debugging purposes */
typedef union SomeIpTp_TxStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SomeIpTp_TxStateType raw[1];
  SomeIpTp_TxStateStructSType str;
} SomeIpTp_TxStateUType;

/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCRootPointerTypes  SomeIpTp Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to SomeIpTp_Channel */
typedef P2CONST(SomeIpTp_ChannelType, TYPEDEF, SOMEIPTP_CONST) SomeIpTp_ChannelPtrType;

/**   \brief  type used to point to SomeIpTp_TXNSdu */
typedef P2CONST(SomeIpTp_TXNSduType, TYPEDEF, SOMEIPTP_CONST) SomeIpTp_TXNSduPtrType;

/**   \brief  type used to point to SomeIpTp_TxQueueElement */
typedef P2VAR(SomeIpTp_TxQueueElementType, TYPEDEF, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxQueueElementPtrType;

/**   \brief  type used to point to SomeIpTp_TxShortHeaders */
typedef P2VAR(SomeIpTp_TxShortHeadersType, TYPEDEF, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxShortHeadersPtrType;

/**   \brief  type used to point to SomeIpTp_TxState */
typedef P2VAR(SomeIpTp_TxStateType, TYPEDEF, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SomeIpTpPCRootValueTypes  SomeIpTp Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in SomeIpTp_PCConfig */
typedef struct sSomeIpTp_PCConfigType
{
  uint8 SomeIpTp_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} SomeIpTp_PCConfigType;

typedef SomeIpTp_PCConfigType SomeIpTp_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/




#endif /* SOMEIPTP_TYPES_H */
/**********************************************************************************************************************
  END OF FILE: SomeIpTp_Types.h
**********************************************************************************************************************/
