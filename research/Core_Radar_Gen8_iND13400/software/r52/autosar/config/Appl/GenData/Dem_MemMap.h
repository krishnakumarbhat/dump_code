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
 *              File: Dem_MemMap.h
 *   Generation Time: 2026-07-13 12:27:07
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

#if defined DEM_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CODE_OPEN
#  error Using DEM_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CODE_ASIL_D
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CODE_ASIL_D is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CODE_ASIL_D_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CODE_ASIL_D
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CODE_ASIL_D is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CODE_ASIL_D_OPEN
#  error Using DEM_STOP_SEC_CODE_ASIL_D is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CODE_ASIL_D_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_16_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_32_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_64_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_8_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_PTR_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_16_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_32_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_64_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_8_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_PTR_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_CONST_ASIL_D_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_CONST_ASIL_D_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_CONST_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_CONST_ASIL_D_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_CONST_ASIL_D_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_CLEARED_RESTRICTED_ASIL_D_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_CLEARED_RESTRICTED_ASIL_D_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_CLEARED_RESTRICTED_ASIL_D_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_INIT_RESTRICTED_ASIL_D_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_INIT_RESTRICTED_ASIL_D_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_INIT_RESTRICTED_ASIL_D_8_OPEN
#  error Using DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_INIT_RESTRICTED_ASIL_D_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SAVED_ZONE_0_QM_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SAVED_ZONE_0_QM_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SAVED_ZONE_0_QM_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_16_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_32_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_64_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_8_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_PTR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_PTR_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_PTR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define DEM_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef DEM_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED_OPEN
#  error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef DEM_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef DEM_START_SEC_CODE
# error Using DEM_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CODE
# error Using DEM_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CODE_ASIL_D
# error Using DEM_START_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CODE_ASIL_D
# error Using DEM_STOP_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_16
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_32
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_64
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_8
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_PTR
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED
# error Using DEM_START_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED
# error Using DEM_STOP_SEC_CONFIG_DATA_PREBUILD_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_CONST_ASIL_D_UNSPECIFIED
# error Using DEM_START_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
# error Using DEM_STOP_SEC_CONST_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_CLEARED_INVALID_OSAPPLICATION_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR
# error Using DEM_START_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR
# error Using DEM_STOP_SEC_VAR_CLEARED_RESTRICTED_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_FAST_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_FAST_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_FAST_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_INIT_RESTRICTED_ASIL_D_8
# error Using DEM_START_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8
# error Using DEM_STOP_SEC_VAR_INIT_RESTRICTED_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_16
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_32
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_64
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_8
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_ASIL_D_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_16
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_32
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_64
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_8
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_PTR
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SAVED_ZONE_0_QM_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SLOW_CLEARED_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_ASIL_D_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_16
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_32
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_64
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_8
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_BOOLEAN is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_PTR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_START_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED
# error Using DEM_STOP_SEC_VAR_SLOW_INIT_QM_GLOBAL_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Dem_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Dem_MemMap.h
 *********************************************************************************************************************/

