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
 *              File: J1939Dcm_Lcfg.c
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

/**********************************************************************************************************************
 * Include files
**********************************************************************************************************************/

#include "J1939Dcm_Lcfg.h"
#include "ComM.h"
#include "J1939Nm.h"
#include "J1939Rm.h"
#include "Dem_J1939Dcm.h"
#include "PduR_J1939Dcm.h"

/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  J1939Dcm_MetaDataGetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Dcm_MetaDataGetterTARGET_ADDRESS_16FctPtrType, J1939DCM_CONST) J1939Dcm_MetaDataGetterTARGET_ADDRESS_16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataGetterTARGET_ADDRESS_16                           Referable Keys */
  /*     0 */ J1939Dcm_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16    /* [TARGET_ADDRESS_16] */
};
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
CONST(J1939Dcm_MetaDataSetterTARGET_ADDRESS_16FctPtrType, J1939DCM_CONST) J1939Dcm_MetaDataSetterTARGET_ADDRESS_16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataSetterTARGET_ADDRESS_16                           Referable Keys */
  /*     0 */ J1939Dcm_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16    /* [TARGET_ADDRESS_16] */
};
#define J1939DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define J1939DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/* \spec requires metaDataPtr != NULL_PTR && $lengthOf(metaDataPtr) >= 2; \endspec  */
FUNC(uint16, J1939DCM_CODE) J1939Dcm_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2CONST(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr )
{
  uint16 metaDataValue = *(P2CONST(uint16, AUTOMATIC, J1939DCM_APPL_DATA))(&metaDataPtr[0]);  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return (metaDataValue);
}

/* \spec requires metaDataPtr != NULL_PTR && $lengthOf(metaDataPtr) >= 2; \endspec  */
FUNC(void, J1939DCM_CODE) J1939Dcm_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2VAR(uint8, AUTOMATIC, J1939DCM_APPL_DATA) metaDataPtr, uint16 item )
{
  *(P2VAR(uint16, AUTOMATIC, J1939DCM_APPL_DATA))(&metaDataPtr[0]) = item;  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return;
}

#define J1939DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Dcm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

