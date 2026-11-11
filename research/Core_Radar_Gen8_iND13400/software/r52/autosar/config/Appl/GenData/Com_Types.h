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
 *            Module: Com
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Types.h
 *   Generation Time: 2026-04-02 15:10:43
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

#if !defined (COM_TYPES_H)
# define COM_TYPES_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#if !defined (COM_LOCAL_INLINE)
# define COM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

typedef P2FUNC(void, COM_APPL_CODE, ComNotificationType) (void);
typedef P2FUNC(boolean, COM_APPL_CODE, ComRxIPduCalloutType) (PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
typedef P2FUNC(boolean, COM_APPL_CODE, ComTxIPduCalloutType) (PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/** Struct used for caching ReportingIdxs (for function ptr callbacks) and RxPduIds (deferred and gateway event). */
typedef struct
{
  P2VAR(uint32, AUTOMATIC, COM_APPL_VAR) ptrToCache;  /** pointer to the actual cache */
  uint32 cacheIndex; /** current fillevel of the cache */
  uint32 cacheMaxSize; /** dictates the number of elements that can be stored in the cache */
  uint32 numberOfElementsRead; /** counts the read operations on the cache. */
  boolean overflowOccurred; /** flag to check if all previous push operations where successful */
} ComCacheType; 

/** Struct used to ensure the consistency of length and dataPtr.
*   Void is used for dataptr, since different appl types need to be handled by the struct.
*   Provides a P2VAR for write operations.
*/
typedef struct
{
  P2VAR(void, AUTOMATIC, AUTOMATIC) dataPtr;
  PduLengthType dataLength;
} ComDataTypeVar;

/** Struct used to ensure the consistency of length and dataPtr.
*   Void is used for dataptr, since different appl types need to be handled by the struct.
*   Provides a P2CONST for read-only operations.
*/
typedef struct
{
  P2CONST(void, AUTOMATIC, AUTOMATIC) dataPtr;
  PduLengthType dataLength;
} ComDataTypeConst;


/** AUTOSAR COM signal object identifier. */
typedef uint16 Com_SignalIdType;

/** AUTOSAR COM signal group object identifier. */
typedef uint16 Com_SignalGroupIdType;

/** AUTOSAR COM PDU group object identifier. */
typedef uint16 Com_IpduGroupIdType;

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif  /* COM_TYPES_H */
/**********************************************************************************************************************
  END OF FILE: Com_Types.h
**********************************************************************************************************************/

