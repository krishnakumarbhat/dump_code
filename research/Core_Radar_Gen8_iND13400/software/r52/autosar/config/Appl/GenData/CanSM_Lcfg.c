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
 *            Module: CanSM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanSM_Lcfg.c
 *   Generation Time: 2026-05-11 17:41:19
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



#define CANSM_LCFG_C


 /**********************************************************************************************************************
 *  Includes
 **********************************************************************************************************************/

#include "CanSM_Cfg.h"
#include "CanSM_EcuM.h"



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanSM_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfig
  \details
  Element         Description
  ControllerId
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ControllerId */
  { /*     0 */           1u },
  { /*     1 */           0u }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanSM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_PartitionIdentifiersType, CANSM_CONST) CanSM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          */
  { /*     0 */ CANSM_SINGLEPARTITION }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelVarRecord
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NO_INIT) CanSM_ChannelVarRecord[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_PartitionInitializationState
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_PartitionInitializationStateType, CANSM_VAR_NO_INIT) CanSM_PartitionInitializationState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  VAR DATA PROTOTYPES
 **********************************************************************************************************************/

#if ( CANSM_USE_INIT_POINTER == STD_ON )
# define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* \trace SPEC-640 */

P2CONST( CanSM_ConfigType, CANSM_VAR_NO_INIT, CANSM_CONST ) CanSM_ConfigDataPtr;

# define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* ( CANSM_USE_INIT_POINTER == STD_ON ) */

#define CANSM_START_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Used values are CANSM_PRE_INIT_NOT_CALLED, CANSM_PRE_INIT_FINISHED */
VAR( uint8, CANSM_VAR_CLEARED ) CanSM_PreInitializationState = CANSM_PRE_INIT_NOT_CALLED;
/* \trace SPEC-11327, SPEC-47131 */

#define CANSM_STOP_SEC_VAR_CLEARED_8
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

 /* -----------------------------------------------
 BusOffIndicationFct  Begin
 ----------------------------------------------- */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(CanSM_BusOffDelayFctPtrType, CANSM_CONST) CanSM_BusOffDelayFctPtr = J1939Nm_GetBusOffDelay;  /* PRQA S 1533 */ /* MD_CANSM_Rule8.9 */

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


 /* -----------------------------------------------
 BusOffIndicationFct  End
 ----------------------------------------------- */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(CanSM_BusOffEndIndicationFctPtrType, CANSM_CONST) CanSM_BusOffEndIndicationFctPtr = J1939Nm_BusOffEnd;   /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */







