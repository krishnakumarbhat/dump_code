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
 *              File: Crypto_MemMap.h
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

#if defined CRYPTO_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_CODE_OPEN
#  error Using CRYPTO_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_CONST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_CONST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_CONST_16BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_CONST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_CONST_16BIT_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_CONST_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_CONST_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_CONST_32BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_CONST_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_CONST_32BIT_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_CONST_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_CONST_8BIT_OPEN
#  error Using CRYPTO_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_IPC_DATA_BUFFER_128BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_IPC_DATA_BUFFER_128BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_IPC_DATA_BUFFER_128BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_IPC_DataBuffer/MemMapAddressingMode */
#pragma clang section bss=".Crypto_iNDI13400_IPC_Section.Align16Var1"

# undef CRYPTO_START_SEC_IPC_DATA_BUFFER_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_IPC_DATA_BUFFER_128BIT_OPEN
#  error Using CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_IPC_DATA_BUFFER_128BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_IPC_DataBuffer/MemMapAddressingMode */
#pragma clang section bss=""

# undef CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_IPC_LENGTH_BUFFER_128BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_IPC_LENGTH_BUFFER_128BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_IPC_LENGTH_BUFFER_128BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_IPC_LengthBuffer/MemMapAddressingMode */
#pragma clang section data=".Crypto_iNDI13400_TestData"

# undef CRYPTO_START_SEC_IPC_LENGTH_BUFFER_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_IPC_LENGTH_BUFFER_128BIT_OPEN
#  error Using CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_IPC_LENGTH_BUFFER_128BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_IPC_LengthBuffer/MemMapAddressingMode */
#pragma clang section data=""

# undef CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_KEYSTRUCT_INITDATA_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_KEYSTRUCT_INITDATA_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_KEYSTRUCT_INITDATA_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_KeyStruct_InitData/MemMapAddressingMode */
#pragma clang section rodata=".Crypto_iNDI13400_KeyStruct_InitData"

# undef CRYPTO_START_SEC_KEYSTRUCT_INITDATA_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_KEYSTRUCT_INITDATA_8BIT_OPEN
#  error Using CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_KEYSTRUCT_INITDATA_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_KeyStruct_InitData/MemMapAddressingMode */
#pragma clang section rodata=""

# undef CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_KEYSTRUCT_METADATA_128BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_KEYSTRUCT_METADATA_128BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_KEYSTRUCT_METADATA_128BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_KeyStruct_MetaData/MemMapAddressingMode */
#pragma clang section bss=".Crypto_iNDI13400_KeyStruct_MetaData"

# undef CRYPTO_START_SEC_KEYSTRUCT_METADATA_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_KEYSTRUCT_METADATA_128BIT_OPEN
#  error Using CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_KEYSTRUCT_METADATA_128BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_KeyStruct_MetaData/MemMapAddressingMode */
#pragma clang section bss=""

# undef CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_TESTDATA_128BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_TESTDATA_128BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_TESTDATA_128BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_TestData/MemMapAddressingMode */
#pragma clang section bss=".Crypto_iNDI13400_IPC_Section.Align16Var1"

# undef CRYPTO_START_SEC_TESTDATA_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_TESTDATA_128BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_TESTDATA_128BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_TESTDATA_128BIT_OPEN
#  error Using CRYPTO_STOP_SEC_TESTDATA_128BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_TESTDATA_128BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CRYPTO_TestData/MemMapAddressingMode */
#pragma clang section bss=""

# undef CRYPTO_STOP_SEC_TESTDATA_128BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_VAR_INIT_UNSPECIFIED_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_VAR_NOINIT_16BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_VAR_NOINIT_16BIT_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_VAR_NOINIT_32BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_VAR_NOINIT_32BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_VAR_NOINIT_32BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_VAR_NOINIT_32BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_32BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_VAR_NOINIT_32BIT_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_32BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_VAR_NOINIT_8BIT_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_VAR_NOINIT_8BIT_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYPTO_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYPTO_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYPTO_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYPTO_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef CRYPTO_START_SEC_CODE
# error Using CRYPTO_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_CODE
# error Using CRYPTO_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_CONST_16BIT
# error Using CRYPTO_START_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_CONST_16BIT
# error Using CRYPTO_STOP_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_CONST_32BIT
# error Using CRYPTO_START_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_CONST_32BIT
# error Using CRYPTO_STOP_SEC_CONST_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_CONST_8BIT
# error Using CRYPTO_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_CONST_8BIT
# error Using CRYPTO_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_IPC_DATA_BUFFER_128BIT
# error Using CRYPTO_START_SEC_IPC_DATA_BUFFER_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT
# error Using CRYPTO_STOP_SEC_IPC_DATA_BUFFER_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_IPC_LENGTH_BUFFER_128BIT
# error Using CRYPTO_START_SEC_IPC_LENGTH_BUFFER_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT
# error Using CRYPTO_STOP_SEC_IPC_LENGTH_BUFFER_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_KEYSTRUCT_INITDATA_8BIT
# error Using CRYPTO_START_SEC_KEYSTRUCT_INITDATA_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT
# error Using CRYPTO_STOP_SEC_KEYSTRUCT_INITDATA_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_KEYSTRUCT_METADATA_128BIT
# error Using CRYPTO_START_SEC_KEYSTRUCT_METADATA_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT
# error Using CRYPTO_STOP_SEC_KEYSTRUCT_METADATA_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_TESTDATA_128BIT
# error Using CRYPTO_START_SEC_TESTDATA_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_TESTDATA_128BIT
# error Using CRYPTO_STOP_SEC_TESTDATA_128BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
# error Using CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_VAR_NOINIT_16BIT
# error Using CRYPTO_START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_VAR_NOINIT_16BIT
# error Using CRYPTO_STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_START_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_VAR_NOINIT_32BIT
# error Using CRYPTO_STOP_SEC_VAR_NOINIT_32BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_VAR_NOINIT_8BIT
# error Using CRYPTO_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using CRYPTO_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Crypto_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Crypto_MemMap.h
 *********************************************************************************************************************/

