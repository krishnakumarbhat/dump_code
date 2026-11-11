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
 *              File: Os_XSignal_Lcfg.c
 *   Generation Time: 2026-09-14 17:36:19
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

#define OS_XSIGNAL_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os kernel module dependencies */
#include "Os_Common.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"

/* Os hal dependencies */


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

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_CORE0_START_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_CORE0_STOP_SEC_VAR_CLEARED_NOCACHE_ASIL_D_32
#include "Os_Var_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal used services map. */
CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_COUNT + 1] =                                  /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  /* USED */
  /* UNUSED */
  OSServiceId_ActivateTask,
  OSServiceId_AddDeferredPriorities,
  OSServiceId_CancelAlarm,
  OSServiceId_ControlIdle,
  OSServiceId_GetAlarm,
  OSServiceId_GetApplicationState,
  OSServiceId_GetCounterValue,
  OSServiceId_GetErrorHookStackUsage,
  OSServiceId_GetEvent,
  OSServiceId_GetISRStackUsage,
  OSServiceId_GetInitHookStackUsage,
  OSServiceId_GetKernelStackUsage,
  OSServiceId_GetNonTrustedFunctionStackUsage,
  OSServiceId_GetProtectionHookStackUsage,
  OSServiceId_GetScheduleTableStatus,
  OSServiceId_GetShutdownHookStackUsage,
  OSServiceId_GetStartupHookStackUsage,
  OSServiceId_GetTaskStackUsage,
  OSServiceId_GetTaskState,
  OSServiceId_HookCallCallback,
  OSServiceId_NextScheduleTable,
  OSServiceId_RemoveDeferredPriorities,
  OSServiceId_SetAbsAlarm,
  OSServiceId_SetDeferredPriorities,
  OSServiceId_SetEvent,
  OSServiceId_SetRelAlarm,
  OSServiceId_ShutdownAllCores,
  OSServiceId_StartScheduleTableAbs,
  OSServiceId_StartScheduleTableRel,
  OSServiceId_StopScheduleTable,
  OSServiceId_TerminateApplication,
  OSSERVICEID_COUNT
};

#define OS_STOP_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
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
 *  END OF FILE: Os_XSignal_Lcfg.c
 *********************************************************************************************************************/
