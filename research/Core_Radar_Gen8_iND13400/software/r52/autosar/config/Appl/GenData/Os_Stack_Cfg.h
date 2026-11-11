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
 *              File: Os_Stack_Cfg.h
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
#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_ON)

/* Configured stack sizes (Total: 52736 Byte) */
# define OS_CFG_SIZE_APPL_BACKGROUNDTASK_STACK     (1024u)
# define OS_CFG_SIZE_APPL_IPC_TASK_STACK     (4096u)
# define OS_CFG_SIZE_APPL_TASK_STACK     (4096u)
# define OS_CFG_SIZE_APPL_TASK_COMMUNICATION_STACK     (2048u)
# define OS_CFG_SIZE_APPL_TASK_FAST_STACK     (2048u)
# define OS_CFG_SIZE_APPL_TASK_HIGH_PRIO_STACK     (1024u)
# define OS_CFG_SIZE_APPL_TASK_LOGGING_STACK     (2048u)
# define OS_CFG_SIZE_BSW_TASK_STACK     (2048u)
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (2048u)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_PROTECTION_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_STARTUP_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO190_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO200_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO210_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (512u)
# define OS_CFG_SIZE_RADAR_CTRL_TASK_STACK     (4096u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
