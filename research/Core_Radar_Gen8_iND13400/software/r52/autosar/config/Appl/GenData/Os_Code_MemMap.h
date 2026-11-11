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
 *              File: Os_Code_MemMap.h
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

#if defined OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_CODE_EXCVEC_ASIL_D_LOCAL_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_EXCVEC_OsCore0_CODE/OS_EXCVEC_OsCore0_CODE */
# pragma clang section text = ".OS_EXCVEC_CORE0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_CODE_EXCVEC_ASIL_D_LOCAL_OPEN
#  error Using OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_CODE_EXCVEC_ASIL_D_LOCAL_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_EXCVEC_OsCore0_CODE/OS_EXCVEC_OsCore0_CODE */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CORE0_CODE_INTVEC_ASIL_D_LOCAL_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_INTVEC_OsCore0_CODE/OS_INTVEC_OsCore0_CODE */
# pragma clang section text = ".OS_INTVEC_CORE0_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CORE0_CODE_INTVEC_ASIL_D_LOCAL_OPEN
#  error Using OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CORE0_CODE_INTVEC_ASIL_D_LOCAL_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_INTVEC_OsCore0_CODE/OS_INTVEC_OsCore0_CODE */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_START_SEC_CODE_ASIL_D
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_START_SEC_CODE_ASIL_D is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CODE_ASIL_D_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_CODE/OS_CODE */
# pragma clang section text = ".OS_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_START_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_STOP_SEC_CODE_ASIL_D
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_STOP_SEC_CODE_ASIL_D is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CODE_ASIL_D_OPEN
#  error Using OS_STOP_SEC_CODE_ASIL_D is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CODE_ASIL_D_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_CODE/OS_CODE */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_STOP_SEC_CODE_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_START_SEC_CODE_EXCVEC_ASIL_D
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_START_SEC_CODE_EXCVEC_ASIL_D is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CODE_EXCVEC_ASIL_D_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_CODE/OS_CODE */
# pragma clang section text = ".OS_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_START_SEC_CODE_EXCVEC_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_STOP_SEC_CODE_EXCVEC_ASIL_D
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_STOP_SEC_CODE_EXCVEC_ASIL_D is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CODE_EXCVEC_ASIL_D_OPEN
#  error Using OS_STOP_SEC_CODE_EXCVEC_ASIL_D is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CODE_EXCVEC_ASIL_D_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_CODE/OS_CODE */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_STOP_SEC_CODE_EXCVEC_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined OS_START_SEC_CODE_INTVEC_ASIL_D
# ifdef MEMMAP_SECTION_OPEN
#  error Using OS_START_SEC_CODE_INTVEC_ASIL_D is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define OS_CODE_INTVEC_ASIL_D_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_INTVEC_CODE/OS_INTVEC_CODE */
# pragma clang section text = ".OS_INTVEC_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_START_SEC_CODE_INTVEC_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined OS_STOP_SEC_CODE_INTVEC_ASIL_D
# ifndef MEMMAP_SECTION_OPEN
#  error Using OS_STOP_SEC_CODE_INTVEC_ASIL_D is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef OS_CODE_INTVEC_ASIL_D_OPEN
#  error Using OS_STOP_SEC_CODE_INTVEC_ASIL_D is not possible as the corresponding memory section has not been opened.
# endif
# undef OS_CODE_INTVEC_ASIL_D_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_INTVEC_CODE/OS_INTVEC_CODE */
# pragma clang section text = "" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef OS_STOP_SEC_CODE_INTVEC_ASIL_D /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL
# error Using OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL
# error Using OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL
# error Using OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL
# error Using OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_START_SEC_CODE_ASIL_D
# error Using OS_START_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_STOP_SEC_CODE_ASIL_D
# error Using OS_STOP_SEC_CODE_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_START_SEC_CODE_EXCVEC_ASIL_D
# error Using OS_START_SEC_CODE_EXCVEC_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_STOP_SEC_CODE_EXCVEC_ASIL_D
# error Using OS_STOP_SEC_CODE_EXCVEC_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_START_SEC_CODE_INTVEC_ASIL_D
# error Using OS_START_SEC_CODE_INTVEC_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef OS_STOP_SEC_CODE_INTVEC_ASIL_D
# error Using OS_STOP_SEC_CODE_INTVEC_ASIL_D is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Os_Code_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Os_Code_MemMap.h
 *********************************************************************************************************************/

