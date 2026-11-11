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
 *            Module: Os
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Counter_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:13
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
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_COUNTER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_CollectionInt.h"
#include "Os_PriorityQueue.h"
#include "Os_ArrayList.h"
#include "Os_Timer.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Timer_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic counter data: OsCounter */

OS_LOCAL VAR(Os_CollectionNodeType, OS_VAR_NOINIT)
OsCfg_Counter_OsCounter_ArrayList_Collection_Nodes_Dyn[OS_CFG_NUM_COUNTER_OSCOUNTER_JOBS + 1u];
OS_LOCAL VAR(Os_CollectionType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_ArrayList_Collection_Dyn;
OS_LOCAL VAR(Os_ArrayListType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_ArrayList_Dyn;
OS_LOCAL VAR(Os_TimerPfrtType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_Dyn;

#define OS_CORE0_STOP_SEC_VAR_CLEARED_ASIL_D_LOCAL_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! Counter configuration data: OsCounter */

CONST(Os_ArrayListConfigType, OS_CONST) OsCfg_Counter_OsCounter_ArrayList =
{
/* .Collection = */
{
  /* .Nodes = */ OsCfg_Counter_OsCounter_ArrayList_Collection_Nodes_Dyn,
  /* .Dyn   = */ &OsCfg_Counter_OsCounter_ArrayList_Collection_Dyn,
  /* .Size  = */ (Os_CollectionNodeIdxType)OS_CFG_NUM_COUNTER_OSCOUNTER_JOBS
},
/* .ListDyn = */ &OsCfg_Counter_OsCounter_ArrayList_Dyn
};

CONST(Os_TimerPfrtConfigType, OS_CONST) OsCfg_Counter_OsCounter =
{
  /* .SwCounter            = */
  {
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_OsCounter,
      /* .MaxCountingValue     = */ OS_TIMERPFRT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_OsCounter),
      /* .MaxDifferentialValue = */ OS_TIMERPFRT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_OsCounter),
      /* .MinCycle             = */ OSMINCYCLE_OsCounter,
      /* .TicksPerBase         = */ OSTICKSPERBASE_OsCounter
    },
    /* .Collection            = */ OS_COUNTER_CASTCONFIG_ARRAYLIST_2_COLLECTION(OsCfg_Counter_OsCounter_ArrayList),
    /* .CollectionType        = */ OS_COLLECTIONTYPE_ARRAYLIST,
    /* .DriverType            = */ OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  },
  /* .Dyn     = */ OS_ISR_CASTDYN_TIMERSW_2_TIMERPFRT(OsCfg_Counter_OsCounter_Dyn)
  },
  /* .Period               = */ 499999UL,
  /* .MaxDifferentialValue = */ OS_TIMERPFRT_HARDWAREGETMAXDIFFERENTIALVALUE(1073741823UL),
  /* .MaxCountingValue     = */ OS_TIMERPFRT_HARDWAREGETMAXCOUNTINGVALUE(1073741823UL),
  /* .HwConfig             = */ &OsCfg_Hal_TimerFrt_OsCounter
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for counters. */
CONSTP2CONST(Os_CounterConfigType, OS_CONST, OS_CONST) OsCfg_CounterRefs[OS_COUNTERID_COUNT + 1u] =            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_OsCounter),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Counter_Lcfg.c
 *********************************************************************************************************************/
