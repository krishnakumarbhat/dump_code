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
 *              File: Os_Task_Lcfg.h
 *   Generation Time: 2026-09-14 17:36:18
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
#ifndef OS_TASK_LCFG_H
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task configuration data: Appl_BackgroundTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_BackgroundTask;

/*! Task configuration data: Appl_IPC_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_IPC_Task;

/*! Task configuration data: Appl_Init */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Init;

/*! Task configuration data: Appl_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task;

/*! Task configuration data: Appl_Task_Communication */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Communication;

/*! Task configuration data: Appl_Task_Fast */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Fast;

/*! Task configuration data: Appl_Task_High_Prio */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_High_Prio;

/*! Task configuration data: Appl_Task_Logging */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Appl_Task_Logging;

/*! Task configuration data: BSW_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BSW_Task;

/*! Task configuration data: IdleTask_OsCore0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0;

/*! Task configuration data: Init_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Init_Task;

/*! Task configuration data: Init_Task_Qm */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Init_Task_Qm;

/*! Task configuration data: Radar_Ctrl_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Radar_Ctrl_Task;

# define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_ASIL_D_32
# include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
