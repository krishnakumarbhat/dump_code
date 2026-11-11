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
 *            Module: J1939Dcm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: J1939Dcm_Lcfg.h
 *   Generation Time: 2026-05-11 17:41:04
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
     
#if !defined(J1939DCM_LCFG_H)
#define J1939DCM_LCFG_H


/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/

#include "J1939Dcm_Cfg.h"

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* --- Component Version Information ------------------------------------------------------------------------------- */

/* SW version number of BSW-IMPLEMENTATION */
#define J1939DCM_CFG_LCFG_MAJOR_VERSION                                     18u
#define J1939DCM_CFG_LCFG_MINOR_VERSION                                     4u
#define J1939DCM_CFG_LCFG_PATCH_VERSION                                     1u

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
  \defgroup  J1939DcmPCSizeOfTypes  J1939Dcm SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_ChannelSupportedArray */
typedef uint8 J1939Dcm_SizeOfCfg_ChannelSupportedArrayType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_ChannelTable */
typedef uint8 J1939Dcm_SizeOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_MessageTable */
typedef uint8 J1939Dcm_SizeOfCfg_MessageTableType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_MetaDataTypeArray */
typedef uint8 J1939Dcm_SizeOfCfg_MetaDataTypeArrayType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_NodeTable */
typedef uint8 J1939Dcm_SizeOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_PeerTxPduArray */
typedef uint8 J1939Dcm_SizeOfCfg_PeerTxPduArrayType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_RxPduTable */
typedef uint8 J1939Dcm_SizeOfCfg_RxPduTableType;

/**   \brief  value based type definition for J1939Dcm_SizeOfCfg_TxPduTable */
typedef uint8 J1939Dcm_SizeOfCfg_TxPduTableType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmPCIterableTypes  J1939Dcm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate J1939Dcm_Cfg_ChannelSupportedArray */
typedef uint8_least J1939Dcm_Cfg_ChannelSupportedArrayIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_ChannelTable */
typedef uint8_least J1939Dcm_Cfg_ChannelTableIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_MessageTable */
typedef uint8_least J1939Dcm_Cfg_MessageTableIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_MetaDataTypeArray */
typedef uint8_least J1939Dcm_Cfg_MetaDataTypeArrayIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_NodeTable */
typedef uint8_least J1939Dcm_Cfg_NodeTableIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_PeerTxPduArray */
typedef uint8_least J1939Dcm_Cfg_PeerTxPduArrayIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_RxPduTable */
typedef uint8_least J1939Dcm_Cfg_RxPduTableIterType;

/**   \brief  type used to iterate J1939Dcm_Cfg_TxPduTable */
typedef uint8_least J1939Dcm_Cfg_TxPduTableIterType;

/**   \brief  type used to iterate J1939Dcm_MetaDataGetterTARGET_ADDRESS_16 */
typedef uint8_least J1939Dcm_MetaDataGetterTARGET_ADDRESS_16IterType;

/**   \brief  type used to iterate J1939Dcm_MetaDataSetterTARGET_ADDRESS_16 */
typedef uint8_least J1939Dcm_MetaDataSetterTARGET_ADDRESS_16IterType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCValueTypes  J1939Dcm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelSupportedArray */
typedef boolean J1939Dcm_Cfg_ChannelSupportedArrayType;

/**   \brief  value based type definition for J1939Dcm_Cfg_BusTypeArrayOfCfg_ChannelTable */
typedef uint8 J1939Dcm_Cfg_BusTypeArrayOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelIdArrayOfCfg_ChannelTable */
typedef uint8 J1939Dcm_Cfg_ChannelIdArrayOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_IsobusChannelOfCfg_ChannelTable */
typedef boolean J1939Dcm_Cfg_IsobusChannelOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MessageTableEndIdxOfCfg_ChannelTable */
typedef uint8 J1939Dcm_Cfg_MessageTableEndIdxOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MessageTableStartIdxOfCfg_ChannelTable */
typedef uint8 J1939Dcm_Cfg_MessageTableStartIdxOfCfg_ChannelTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_DMArrayOfCfg_MessageTable */
typedef uint8 J1939Dcm_Cfg_DMArrayOfCfg_MessageTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_PGNArrayOfCfg_MessageTable */
typedef uint32 J1939Dcm_Cfg_PGNArrayOfCfg_MessageTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_PeerTxPduArrayEndIdxOfCfg_MessageTable */
typedef uint8 J1939Dcm_Cfg_PeerTxPduArrayEndIdxOfCfg_MessageTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_PeerTxPduArrayStartIdxOfCfg_MessageTable */
typedef uint8 J1939Dcm_Cfg_PeerTxPduArrayStartIdxOfCfg_MessageTableType;

/**   \brief  value based type definition for J1939Dcm_MetaDataGetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray */
typedef uint8 J1939Dcm_MetaDataGetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArrayType;

/**   \brief  value based type definition for J1939Dcm_MetaDataGetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray */
typedef boolean J1939Dcm_MetaDataGetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArrayType;

/**   \brief  value based type definition for J1939Dcm_MetaDataSetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArray */
typedef uint8 J1939Dcm_MetaDataSetterTARGET_ADDRESS_16IdxOfCfg_MetaDataTypeArrayType;

/**   \brief  value based type definition for J1939Dcm_MetaDataSetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArray */
typedef boolean J1939Dcm_MetaDataSetterTARGET_ADDRESS_16UsedOfCfg_MetaDataTypeArrayType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelSupportedArrayEndIdxOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_ChannelSupportedArrayEndIdxOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelSupportedArrayStartIdxOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_ChannelSupportedArrayStartIdxOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_DemClientIdArrayOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_DemClientIdArrayOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_NodeAddressArrayOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_NodeAddressArrayOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_NodeIdArrayOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_NodeIdArrayOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ObdSpecificArrayOfCfg_NodeTable */
typedef boolean J1939Dcm_Cfg_ObdSpecificArrayOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_UserIdArrayOfCfg_NodeTable */
typedef uint8 J1939Dcm_Cfg_UserIdArrayOfCfg_NodeTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MetaDataTypeArrayIdxOfCfg_PeerTxPduArray */
typedef uint8 J1939Dcm_Cfg_MetaDataTypeArrayIdxOfCfg_PeerTxPduArrayType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MetaDataTypeArrayUsedOfCfg_PeerTxPduArray */
typedef boolean J1939Dcm_Cfg_MetaDataTypeArrayUsedOfCfg_PeerTxPduArrayType;

/**   \brief  value based type definition for J1939Dcm_Cfg_PeerTxPduOfCfg_PeerTxPduArray */
typedef PduIdType J1939Dcm_Cfg_PeerTxPduOfCfg_PeerTxPduArrayType;

/**   \brief  value based type definition for J1939Dcm_Cfg_RxIsBroadcastOfCfg_RxPduTable */
typedef boolean J1939Dcm_Cfg_RxIsBroadcastOfCfg_RxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_RxNodeAddressOfCfg_RxPduTable */
typedef uint8 J1939Dcm_Cfg_RxNodeAddressOfCfg_RxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_RxSourceAddressOfCfg_RxPduTable */
typedef uint8 J1939Dcm_Cfg_RxSourceAddressOfCfg_RxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelTableIdxOfCfg_TxPduTable */
typedef uint8 J1939Dcm_Cfg_ChannelTableIdxOfCfg_TxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_ChannelTableUsedOfCfg_TxPduTable */
typedef boolean J1939Dcm_Cfg_ChannelTableUsedOfCfg_TxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MessageTableIdxOfCfg_TxPduTable */
typedef uint8 J1939Dcm_Cfg_MessageTableIdxOfCfg_TxPduTableType;

/**   \brief  value based type definition for J1939Dcm_Cfg_MessageTableUsedOfCfg_TxPduTable */
typedef boolean J1939Dcm_Cfg_MessageTableUsedOfCfg_TxPduTableType;

/**   \brief  value based type definition for J1939Dcm_CompatibilityVersion */
typedef uint32 J1939Dcm_CompatibilityVersionType;

/**   \brief  value based type definition for J1939Dcm_InitBroadcastStatus */
typedef uint8 J1939Dcm_InitBroadcastStatusType;

/**   \brief  value based type definition for J1939Dcm_NumberOfExistedRxPdus */
typedef uint8 J1939Dcm_NumberOfExistedRxPdusType;

/**   \brief  value based type definition for J1939Dcm_NumberOfExistedTxPdus */
typedef uint8 J1939Dcm_NumberOfExistedTxPdusType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  J1939DcmPCStructTypes  J1939Dcm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in J1939Dcm_Cfg_ChannelTable */
typedef struct sJ1939Dcm_Cfg_ChannelTableType
{
  uint8 J1939Dcm_Cfg_ChannelTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_ChannelTableType;

/**   \brief  type used in J1939Dcm_Cfg_MessageTable */
typedef struct sJ1939Dcm_Cfg_MessageTableType
{
  uint8 J1939Dcm_Cfg_MessageTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_MessageTableType;

/**   \brief  type used in J1939Dcm_Cfg_MetaDataTypeArray */
typedef struct sJ1939Dcm_Cfg_MetaDataTypeArrayType
{
  uint8 J1939Dcm_Cfg_MetaDataTypeArrayNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_MetaDataTypeArrayType;

/**   \brief  type used in J1939Dcm_Cfg_NodeTable */
typedef struct sJ1939Dcm_Cfg_NodeTableType
{
  uint8 J1939Dcm_Cfg_NodeTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_NodeTableType;

/**   \brief  type used in J1939Dcm_Cfg_PeerTxPduArray */
typedef struct sJ1939Dcm_Cfg_PeerTxPduArrayType
{
  uint8 J1939Dcm_Cfg_PeerTxPduArrayNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_PeerTxPduArrayType;

/**   \brief  type used in J1939Dcm_Cfg_RxPduTable */
typedef struct sJ1939Dcm_Cfg_RxPduTableType
{
  uint8 J1939Dcm_Cfg_RxPduTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_RxPduTableType;

/**   \brief  type used in J1939Dcm_Cfg_TxPduTable */
typedef struct sJ1939Dcm_Cfg_TxPduTableType
{
  uint8 J1939Dcm_Cfg_TxPduTableNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_Cfg_TxPduTableType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCFunctionPointerTypes  J1939Dcm Function Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point to the MetaData Getter and Setter Functions.
  \{
*/ 
/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataGetterTARGET_ADDRESS_16 */
typedef P2FUNC(uint16, J1939DCM_CODE, J1939Dcm_MetaDataGetterTARGET_ADDRESS_16FctPtrType) (P2CONST(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr);

/**   \brief  function pointer type used to point to MetaData Setter Function of MetaDataSetterTARGET_ADDRESS_16 */
typedef P2FUNC(void, J1939DCM_CODE, J1939Dcm_MetaDataSetterTARGET_ADDRESS_16FctPtrType) (P2VAR(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr, uint16 item);

/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCRootPointerTypes  J1939Dcm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to J1939Dcm_Cfg_ChannelSupportedArray */
typedef P2CONST(J1939Dcm_Cfg_ChannelSupportedArrayType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_ChannelSupportedArrayPtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_ChannelTable */
typedef P2CONST(J1939Dcm_Cfg_ChannelTableType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_ChannelTablePtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_MessageTable */
typedef P2CONST(J1939Dcm_Cfg_MessageTableType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_MessageTablePtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_MetaDataTypeArray */
typedef P2CONST(J1939Dcm_Cfg_MetaDataTypeArrayType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_MetaDataTypeArrayPtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_NodeTable */
typedef P2CONST(J1939Dcm_Cfg_NodeTableType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_NodeTablePtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_PeerTxPduArray */
typedef P2CONST(J1939Dcm_Cfg_PeerTxPduArrayType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_PeerTxPduArrayPtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_RxPduTable */
typedef P2CONST(J1939Dcm_Cfg_RxPduTableType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_RxPduTablePtrType;

/**   \brief  type used to point to J1939Dcm_Cfg_TxPduTable */
typedef P2CONST(J1939Dcm_Cfg_TxPduTableType, TYPEDEF, J1939DCM_CONST) J1939Dcm_Cfg_TxPduTablePtrType;

/**   \brief  type used to point to J1939Dcm_MetaDataGetterTARGET_ADDRESS_16 */
typedef P2CONST(J1939Dcm_MetaDataGetterTARGET_ADDRESS_16FctPtrType, TYPEDEF, J1939DCM_CONST) J1939Dcm_MetaDataGetterTARGET_ADDRESS_16PtrType;

/**   \brief  type used to point to J1939Dcm_MetaDataSetterTARGET_ADDRESS_16 */
typedef P2CONST(J1939Dcm_MetaDataSetterTARGET_ADDRESS_16FctPtrType, TYPEDEF, J1939DCM_CONST) J1939Dcm_MetaDataSetterTARGET_ADDRESS_16PtrType;

/** 
  \}
*/ 

/** 
  \defgroup  J1939DcmPCRootValueTypes  J1939Dcm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in J1939Dcm_PCConfig */
typedef struct sJ1939Dcm_PCConfigType
{
  uint8 J1939Dcm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} J1939Dcm_PCConfigType;

typedef J1939Dcm_PCConfigType J1939Dcm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  J1939Dcm_MetaDataGetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Dcm_MetaDataGetterTARGET_ADDRESS_16FctPtrType, J1939DCM_CONST) J1939Dcm_MetaDataGetterTARGET_ADDRESS_16[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Dcm_MetaDataSetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(J1939Dcm_MetaDataSetterTARGET_ADDRESS_16FctPtrType, J1939DCM_CONST) J1939Dcm_MetaDataSetterTARGET_ADDRESS_16[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define J1939DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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
#define J1939DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern FUNC(uint16, J1939DCM_CODE) J1939Dcm_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2CONST(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr );
extern FUNC(void, J1939DCM_CODE) J1939Dcm_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2VAR(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr, uint16 item );
#define J1939DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif /* J1939DCM_LCFG_H */
