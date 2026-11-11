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
 *            Module: MemMap
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Stacks_MemMap.h
 *   Generation Time: 2026-08-24 11:38:43
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
/* PRQA S 0883 EOF */ /* MD_MSR_MemMap */

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  PRE USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_BackgroundTask_VAR_CLEARED/OS_STACK_Appl_BackgroundTask_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_BackgroundTask_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_BackgroundTask_VAR_CLEARED/OS_STACK_Appl_BackgroundTask_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_IPC_Task_VAR_CLEARED/OS_STACK_Appl_IPC_Task_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_IPC_Task_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_IPC_Task_VAR_CLEARED/OS_STACK_Appl_IPC_Task_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_VAR_CLEARED/OS_STACK_Appl_Task_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_Task_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_VAR_CLEARED/OS_STACK_Appl_Task_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Communication_VAR_CLEARED/OS_STACK_Appl_Task_Communication_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_Task_Communication_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Communication_VAR_CLEARED/OS_STACK_Appl_Task_Communication_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Fast_VAR_CLEARED/OS_STACK_Appl_Task_Fast_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_Task_Fast_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Fast_VAR_CLEARED/OS_STACK_Appl_Task_Fast_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_High_Prio_VAR_CLEARED/OS_STACK_Appl_Task_High_Prio_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_Task_High_Prio_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_High_Prio_VAR_CLEARED/OS_STACK_Appl_Task_High_Prio_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Logging_VAR_CLEARED/OS_STACK_Appl_Task_Logging_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Appl_Task_Logging_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Appl_Task_Logging_VAR_CLEARED/OS_STACK_Appl_Task_Logging_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_BSW_Task_VAR_CLEARED/OS_STACK_BSW_Task_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_BSW_Task_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_BSW_Task_VAR_CLEARED/OS_STACK_BSW_Task_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Error_VAR_CLEARED/OS_STACK_OsCore0_Error_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Error_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Error_VAR_CLEARED/OS_STACK_OsCore0_Error_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Init_VAR_CLEARED/OS_STACK_OsCore0_Init_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Init_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Init_VAR_CLEARED/OS_STACK_OsCore0_Init_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Isr_Core_VAR_CLEARED/OS_STACK_OsCore0_Isr_Core_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Isr_Core_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Isr_Core_VAR_CLEARED/OS_STACK_OsCore0_Isr_Core_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Kernel_VAR_CLEARED/OS_STACK_OsCore0_Kernel_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Kernel_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Kernel_VAR_CLEARED/OS_STACK_OsCore0_Kernel_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Protection_VAR_CLEARED/OS_STACK_OsCore0_Protection_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Protection_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Protection_VAR_CLEARED/OS_STACK_OsCore0_Protection_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Shutdown_VAR_CLEARED/OS_STACK_OsCore0_Shutdown_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Shutdown_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Shutdown_VAR_CLEARED/OS_STACK_OsCore0_Shutdown_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Startup_VAR_CLEARED/OS_STACK_OsCore0_Startup_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Startup_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Startup_VAR_CLEARED/OS_STACK_OsCore0_Startup_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio190_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio190_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Task_Prio190_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio190_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio190_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio200_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio200_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Task_Prio200_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio200_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio200_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio210_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio210_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Task_Prio210_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio210_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio210_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio4294967295_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio4294967295_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_OsCore0_Task_Prio4294967295_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_OsCore0_Task_Prio4294967295_VAR_CLEARED/OS_STACK_OsCore0_Task_Prio4294967295_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Radar_Ctrl_Task_VAR_CLEARED/OS_STACK_Radar_Ctrl_Task_VAR_CLEARED */
# pragma clang section bss = ".OS_STACK_Radar_Ctrl_Task_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN
#  error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_STACK_Radar_Ctrl_Task_VAR_CLEARED/OS_STACK_Radar_Ctrl_Task_VAR_CLEARED */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_BackgroundTask_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_IPC_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Communication_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Fast_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_High_Prio_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Appl_Task_Logging_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_BSW_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Error_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Init_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Isr_Core_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Kernel_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Protection_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Shutdown_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Startup_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio190_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio200_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio210_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_OsCore0_Task_Prio4294967295_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_START_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED
# error Using OS_CORE0_STOP_SEC_VAR_CLEARED_STACK_Radar_Ctrl_Task_ASIL_D_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Os_Stacks_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Os_Stacks_MemMap.h
 *********************************************************************************************************************/

