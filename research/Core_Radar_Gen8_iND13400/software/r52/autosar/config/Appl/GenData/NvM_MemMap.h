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
 *              File: NvM_MemMap.h
 *   Generation Time: 2026-07-13 12:27:08
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

#if defined NVM_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_APPL_CODE_OPEN
#  error Using NVM_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CODE_OPEN
#  error Using NVM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_16_OPEN
#  error Using NVM_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_32_OPEN
#  error Using NVM_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_64_OPEN
#  error Using NVM_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_8_OPEN
#  error Using NVM_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_PBCFG_OPEN
#  error Using NVM_STOP_SEC_CONST_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_CONST_UNSPECIFIED_OPEN
#  error Using NVM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_PBCFG_OPEN
#  error Using NVM_STOP_SEC_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_CLEARED_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_CLEARED_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_CLEARED_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_CLEARED_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_CLEARED_16_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_CLEARED_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_CLEARED_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_CLEARED_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_CLEARED_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_CLEARED_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_CLEARED_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_CLEARED_32_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_CLEARED_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_CLEARED_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_CLEARED_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_CLEARED_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_CLEARED_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_CLEARED_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_CLEARED_64_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_CLEARED_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_CLEARED_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_CLEARED_8_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_FAST_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_FAST_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_FAST_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_FAST_NO_INIT_8_OPEN
#  error Using NVM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_FAST_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_FAST_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INIT_16_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INIT_32_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INIT_64_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INIT_8_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using NVM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_INTERNAL_BUFFER
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_INTERNAL_BUFFER is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_INTERNAL_BUFFER_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_INTERNAL_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_INTERNAL_BUFFER
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_INTERNAL_BUFFER is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_INTERNAL_BUFFER_OPEN
#  error Using NVM_STOP_SEC_VAR_INTERNAL_BUFFER is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_INTERNAL_BUFFER_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_INTERNAL_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_NO_INIT_16_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_NO_INIT_32_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_NO_INIT_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_NO_INIT_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_NO_INIT_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_NO_INIT_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_NO_INIT_64_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_NO_INIT_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_NO_INIT_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_NO_INIT_8_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_PBCFG_OPEN
#  error Using NVM_STOP_SEC_VAR_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_POWER_ON_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_POWER_ON_CLEARED_UNSPECIFIED_OPEN
#  error Using NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_POWER_ON_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NVM_START_SEC_VAR_SHARED_DATA
# ifdef MEMMAP_SECTION_OPEN
#  error Using NVM_START_SEC_VAR_SHARED_DATA is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NVM_VAR_SHARED_DATA_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_START_SEC_VAR_SHARED_DATA /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NVM_STOP_SEC_VAR_SHARED_DATA
# ifndef MEMMAP_SECTION_OPEN
#  error Using NVM_STOP_SEC_VAR_SHARED_DATA is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NVM_VAR_SHARED_DATA_OPEN
#  error Using NVM_STOP_SEC_VAR_SHARED_DATA is not possible as the corresponding memory section has not been opened.
# endif
# undef NVM_VAR_SHARED_DATA_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NVM_STOP_SEC_VAR_SHARED_DATA /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NvM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using NvM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NvM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NvM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using NvM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NvM_CODE_OPEN
#  error Using NvM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef NvM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NvM_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NvM_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NvM_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NvM_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NvM_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NvM_CONST_UNSPECIFIED_OPEN
#  error Using NvM_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NvM_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NvM_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NvM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NvM_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NvM_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NvM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NvM_VAR_INIT_UNSPECIFIED_OPEN
#  error Using NvM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NvM_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NvM_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NvM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NvM_VAR_NOINIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NvM_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NvM_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined NvM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using NvM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define NvM_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef NvM_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef NvM_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef NVM_START_SEC_APPL_CODE
# error Using NVM_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_APPL_CODE
# error Using NVM_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CODE
# error Using NVM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CODE
# error Using NVM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_16
# error Using NVM_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_16
# error Using NVM_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_32
# error Using NVM_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_32
# error Using NVM_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_64
# error Using NVM_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_64
# error Using NVM_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_8
# error Using NVM_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_8
# error Using NVM_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_PBCFG
# error Using NVM_START_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_PBCFG
# error Using NVM_STOP_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_CONST_UNSPECIFIED
# error Using NVM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
# error Using NVM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_PBCFG
# error Using NVM_START_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_PBCFG
# error Using NVM_STOP_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_CLEARED_16
# error Using NVM_START_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_CLEARED_16
# error Using NVM_STOP_SEC_VAR_CLEARED_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_CLEARED_32
# error Using NVM_START_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_CLEARED_32
# error Using NVM_STOP_SEC_VAR_CLEARED_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_CLEARED_64
# error Using NVM_START_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_CLEARED_64
# error Using NVM_STOP_SEC_VAR_CLEARED_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_CLEARED_8
# error Using NVM_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_CLEARED_8
# error Using NVM_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using NVM_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_FAST_NO_INIT_8
# error Using NVM_START_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_NO_INIT_8
# error Using NVM_STOP_SEC_VAR_FAST_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INIT_16
# error Using NVM_START_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INIT_16
# error Using NVM_STOP_SEC_VAR_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INIT_32
# error Using NVM_START_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INIT_32
# error Using NVM_STOP_SEC_VAR_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INIT_64
# error Using NVM_START_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INIT_64
# error Using NVM_STOP_SEC_VAR_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INIT_8
# error Using NVM_START_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INIT_8
# error Using NVM_STOP_SEC_VAR_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using NVM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using NVM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_INTERNAL_BUFFER
# error Using NVM_START_SEC_VAR_INTERNAL_BUFFER is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_INTERNAL_BUFFER
# error Using NVM_STOP_SEC_VAR_INTERNAL_BUFFER is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_NO_INIT_16
# error Using NVM_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_NO_INIT_16
# error Using NVM_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_NO_INIT_32
# error Using NVM_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_NO_INIT_32
# error Using NVM_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_NO_INIT_64
# error Using NVM_START_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_NO_INIT_64
# error Using NVM_STOP_SEC_VAR_NO_INIT_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_NO_INIT_8
# error Using NVM_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_NO_INIT_8
# error Using NVM_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_PBCFG
# error Using NVM_START_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_PBCFG
# error Using NVM_STOP_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
# error Using NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
# error Using NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_START_SEC_VAR_SHARED_DATA
# error Using NVM_START_SEC_VAR_SHARED_DATA is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NVM_STOP_SEC_VAR_SHARED_DATA
# error Using NVM_STOP_SEC_VAR_SHARED_DATA is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_START_SEC_CODE
# error Using NvM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_STOP_SEC_CODE
# error Using NvM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_START_SEC_CONST_UNSPECIFIED
# error Using NvM_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_STOP_SEC_CONST_UNSPECIFIED
# error Using NvM_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_START_SEC_VAR_INIT_UNSPECIFIED
# error Using NvM_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using NvM_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using NvM_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using NvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using NvM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using NvM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in NvM_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: NvM_MemMap.h
 *********************************************************************************************************************/

