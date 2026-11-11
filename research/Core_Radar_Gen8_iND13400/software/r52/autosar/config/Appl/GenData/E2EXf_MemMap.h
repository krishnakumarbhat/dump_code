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
 *              File: E2EXf_MemMap.h
 *   Generation Time: 2026-08-06 12:46:12
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

#if defined E2EXF_START_SEC_CODE_ASIL_D
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CODE_ASIL_D is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CODE_ASIL_D_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CODE_ASIL_D
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CODE_ASIL_D is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CODE_ASIL_D_OPEN
#  error Using E2EXF_STOP_SEC_CODE_ASIL_D is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CODE_ASIL_D_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CONST_ASIL_D_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CONST_ASIL_D_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CONST_ASIL_D_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_LOCAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_NOCACHE_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_NOCACHE_GLOBAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_NOCACHE_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = "" bss = ""

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = "" bss = ""

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_ZERO_INIT/OS_OsCore_Qm_VAR_ZERO_INIT */
#pragma clang section data = "" bss = ""

# undef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_INIT_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = ".OS_OsCore0_ASIL_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsCore0_ASIL_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_INIT_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_INIT_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = ".OS_OsCore0_ASIL_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_OsCore0_ASIL_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore0_ASIL_VAR_INIT/OS_OsCore0_ASIL_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = ".logging.data" bss = ".logging.bss"

# undef E2EXF_START_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsCore_Qm_VAR_INIT/OS_OsCore_Qm_VAR_INIT */
#pragma clang section data = "" bss = ""

# undef E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma clang section bss = ".OS_CORE0_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = ".OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma clang section bss = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma clang section data = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef E2EXF_START_SEC_CODE_ASIL_D
# error Using E2EXF_START_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CODE_ASIL_D
# error Using E2EXF_STOP_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
# error Using E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# error Using E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_LOCAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_NOCACHE_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore0_ASIL_NOCACHE_ASIL_B_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_NOCACHE_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_CLEARED_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_NOCACHE_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8
# error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8
# error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_CLEARED_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_INIT_OsCore_Qm_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_INIT_SystemApplication_OsCore0_QM_LOCAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in E2EXf_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: E2EXf_MemMap.h
 *********************************************************************************************************************/

