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
 *              File: Rte_MemMap.h
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

#if defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_BackgroundTask_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_BackgroundTask_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_BackgroundTask_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_IPC_Task_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_IPC_Task_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_IPC_Task_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_Init_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Init_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Init_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_Communication_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_Communication_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_Communication_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_High_Prio_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_High_Prio_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Appl_Task_High_Prio_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_BSW_Task_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_BSW_Task_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_BSW_Task_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Init_Task_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Init_Task_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Init_Task_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Init_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Init_Task_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Init_Task_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CODE_Radar_Ctrl_Task_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CODE_Radar_Ctrl_Task_ASIL_B_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CODE_Radar_Ctrl_Task_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_CONST_ASIL_B_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_CONST_ASIL_B_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_CONST_ASIL_B_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_8_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = ".OS_OsCore0_ASIL_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsCore0_ASIL_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_Core0_ASIL_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = ".OS_OsCore0_ASIL_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsCore0_ASIL_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_Core0_ASIL_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_Core0_ASIL_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Fast_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Fast_QM_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Fast_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Logging_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Logging_QM_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_CODE_Appl_Task_Logging_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_CODE_Init_Task_Qm_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_CODE_Init_Task_Qm_QM_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_CODE_Init_Task_Qm_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_CODE_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_CODE_QM_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_CODE_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_CONST_QM_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_CONST_QM_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_CONST_QM_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_8_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = "" bss = ""

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = "" bss = ""

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = "" bss = ""

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_OsCore0_QM_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_OsCore0_QM_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_OsCore0_QM_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = "" bss = ""

# undef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_IdleTask_OsCore0_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_IdleTask_OsCore0_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_CODE_IdleTask_OsCore0_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_IdleTask_OsCore0_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_CODE_IdleTask_OsCore0_QM_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_CODE_IdleTask_OsCore0_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_QM
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_QM is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_CODE_QM_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_CODE_QM_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_CODE_QM_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CONST_QM_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CONST_QM_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_CONST_QM_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CONST_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_CONST_QM_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_CONST_QM_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_8_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_VAR_CLEARED_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_EcucPartition_SystemApplication_OsCore0_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma clang section bss = ".OS_CORE0_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_EcucPartition_SystemApplication_OsCore0_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_EcucPartition_SystemApplication_OsCore0_VAR_INIT_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_Lib_START_SEC_CODE_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_Lib_START_SEC_CODE_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_Lib_CODE_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Lib_START_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_Lib_STOP_SEC_CODE_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_Lib_STOP_SEC_CODE_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_Lib_CODE_ASIL_B_OPEN
#  error Using RTE_Lib_STOP_SEC_CODE_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_Lib_CODE_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Lib_STOP_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_Lifecycle_START_SEC_CODE_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_Lifecycle_START_SEC_CODE_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_Lifecycle_CODE_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Lifecycle_START_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_Lifecycle_STOP_SEC_CODE_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_Lifecycle_CODE_ASIL_B_OPEN
#  error Using RTE_Lifecycle_STOP_SEC_CODE_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_Lifecycle_CODE_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Lifecycle_STOP_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CODE_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CODE_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CODE_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CODE_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CODE_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CODE_ASIL_B_OPEN
#  error Using RTE_STOP_SEC_CODE_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CODE_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CODE_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_ASIL_B_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_ASIL_B_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_ASIL_B_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_CLEARED_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_CLEARED_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_CLEARED_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_CLEARED_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_CLEARED_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_CLEARED_LOCAL_8_OPEN
#  error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_CLEARED_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_CLEARED_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_INIT_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = ".OS_OsCore0_ASIL_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsCore0_ASIL_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_INIT_LOCAL_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_INIT_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_Trace_START_SEC_CODE_APPL_ASIL_B
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_Trace_START_SEC_CODE_APPL_ASIL_B is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_Trace_CODE_APPL_ASIL_B_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Trace_START_SEC_CODE_APPL_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_Trace_CODE_APPL_ASIL_B_OPEN
#  error Using RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_Trace_CODE_APPL_ASIL_B_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Init_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Init_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Init_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_8
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_IdleTask_OsCore0_QM
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_IdleTask_OsCore0_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_IdleTask_OsCore0_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_QM
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CODE_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CODE_QM is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CONST_QM_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_CONST_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_CONST_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_8
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
# error Using RTE_EcucPartition_SystemApplication_OsCore0_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Lib_START_SEC_CODE_ASIL_B
# error Using RTE_Lib_START_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Lib_STOP_SEC_CODE_ASIL_B
# error Using RTE_Lib_STOP_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Lifecycle_START_SEC_CODE_ASIL_B
# error Using RTE_Lifecycle_START_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
# error Using RTE_Lifecycle_STOP_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CODE_ASIL_B
# error Using RTE_START_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CODE_ASIL_B
# error Using RTE_STOP_SEC_CODE_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED
# error Using RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# error Using RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_CLEARED_LOCAL_8
# error Using RTE_START_SEC_VAR_CLEARED_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_CLEARED_LOCAL_8
# error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# error Using RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# error Using RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Trace_START_SEC_CODE_APPL_ASIL_B
# error Using RTE_Trace_START_SEC_CODE_APPL_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B
# error Using RTE_Trace_STOP_SEC_CODE_APPL_ASIL_B is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Rte_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Rte_MemMap.h
 *********************************************************************************************************************/

