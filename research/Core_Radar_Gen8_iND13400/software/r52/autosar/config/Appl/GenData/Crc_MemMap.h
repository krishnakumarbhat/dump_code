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
 *              File: Crc_MemMap.h
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

#if defined CRC_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRC_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRC_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRC_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRC_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRC_CODE_OPEN
#  error Using CRC_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRC_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRC_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRC_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRC_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRC_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRC_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRC_CONST_16_OPEN
#  error Using CRC_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef CRC_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRC_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRC_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRC_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRC_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRC_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRC_CONST_32_OPEN
#  error Using CRC_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef CRC_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRC_START_SEC_CONST_64
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRC_START_SEC_CONST_64 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRC_CONST_64_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_START_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRC_STOP_SEC_CONST_64
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRC_STOP_SEC_CONST_64 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRC_CONST_64_OPEN
#  error Using CRC_STOP_SEC_CONST_64 is not possible as the corresponding memory section has not been opened.
# endif
# undef CRC_CONST_64_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_STOP_SEC_CONST_64 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRC_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRC_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRC_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRC_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRC_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRC_CONST_8_OPEN
#  error Using CRC_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef CRC_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRC_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef CRC_START_SEC_CODE
# error Using CRC_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_STOP_SEC_CODE
# error Using CRC_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_START_SEC_CONST_16
# error Using CRC_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_STOP_SEC_CONST_16
# error Using CRC_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_START_SEC_CONST_32
# error Using CRC_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_STOP_SEC_CONST_32
# error Using CRC_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_START_SEC_CONST_64
# error Using CRC_START_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_STOP_SEC_CONST_64
# error Using CRC_STOP_SEC_CONST_64 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_START_SEC_CONST_8
# error Using CRC_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRC_STOP_SEC_CONST_8
# error Using CRC_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Crc_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Crc_MemMap.h
 *********************************************************************************************************************/

