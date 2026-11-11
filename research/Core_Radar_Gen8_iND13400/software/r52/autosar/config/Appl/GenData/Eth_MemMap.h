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
 *              File: Eth_MemMap.h
 *   Generation Time: 2026-08-27 00:57:16
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

#if defined ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_BUF_RX/MemMapAddressingMode */
#pragma clang section bss=".eth_buffer_rx"

# undef ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_BUFFER_INIT_RX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_BUF_RX/MemMapAddressingMode */
#pragma clang section bss=""

# undef ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_BUF_TX/MemMapAddressingMode */
#pragma clang section bss=".eth_buffer_tx"

# undef ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_BUFFER_INIT_TX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_BUF_TX/MemMapAddressingMode */
#pragma clang section bss=""

# undef ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_BUFFER_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_BUFFER_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_BUFFER_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_BUFFER_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_BUFFER_INIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_BUFFER_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_CODE_OPEN
#  error Using ETH_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_CONST_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_CONST_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_CONST_16BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_CONST_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_CONST_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_CONST_16BIT_OPEN
#  error Using ETH_STOP_SEC_CONST_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_CONST_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_CONST_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_CONST_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_CONST_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_CONST_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_CONST_8BIT_OPEN
#  error Using ETH_STOP_SEC_CONST_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_CONST_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_CONST_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_DESC_RX/MemMapAddressingMode */
#pragma clang section bss=".eth_descriptor_rx"

# undef ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_DESCRIPTOR_INIT_RX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_DESC_RX/MemMapAddressingMode */
#pragma clang section bss=""

# undef ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_DESC_TX/MemMapAddressingMode */
#pragma clang section bss=".eth_descriptor_tx"

# undef ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_DESCRIPTOR_INIT_TX_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_ETH_DESC_TX/MemMapAddressingMode */
#pragma clang section bss=""

# undef ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_DESCRIPTOR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_DESCRIPTOR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_DESCRIPTOR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_DESCRIPTOR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_DESCRIPTOR_INIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_DESCRIPTOR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_INIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_INIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_NOINIT_16BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_NOINIT_16BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_NOINIT_16BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_NOINIT_16BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_16BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_NOINIT_16BIT_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_16BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_NOINIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_NOINIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_NOINIT_8BIT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_NOINIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_NOINIT_8BIT_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_NOINIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas entered manually. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_MCAL_VAR_NO_INIT/MemMapAddressingMode */


# undef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
# ifdef MEMMAP_SECTION_OPEN
#  error Using ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define ETH_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
# ifndef MEMMAP_SECTION_OPEN
#  error Using ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef ETH_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE_OPEN
#  error Using ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE is not possible as the corresponding memory section has not been opened.
# endif
# undef ETH_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED
# error Using ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED
# error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED
# error Using ETH_START_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED
# error Using ETH_STOP_SEC_BUFFER_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED
# error Using ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED
# error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED
# error Using ETH_START_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED
# error Using ETH_STOP_SEC_BUFFER_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_BUFFER_INIT_UNSPECIFIED
# error Using ETH_START_SEC_BUFFER_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED
# error Using ETH_STOP_SEC_BUFFER_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_CODE
# error Using ETH_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_CODE
# error Using ETH_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_CONST_16BIT
# error Using ETH_START_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_CONST_16BIT
# error Using ETH_STOP_SEC_CONST_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_CONST_8BIT
# error Using ETH_START_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_CONST_8BIT
# error Using ETH_STOP_SEC_CONST_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_CONST_UNSPECIFIED
# error Using ETH_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_CONST_UNSPECIFIED
# error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_CONST_UNSPECIFIED
# error Using ETH_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_CONST_UNSPECIFIED
# error Using ETH_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# error Using ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# error Using ETH_START_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED
# error Using ETH_STOP_SEC_DESCRIPTOR_INIT_RX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# error Using ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# error Using ETH_START_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED
# error Using ETH_STOP_SEC_DESCRIPTOR_INIT_TX_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_DESCRIPTOR_INIT_UNSPECIFIED
# error Using ETH_START_SEC_DESCRIPTOR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED
# error Using ETH_STOP_SEC_DESCRIPTOR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_INIT_UNSPECIFIED
# error Using ETH_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_INIT_UNSPECIFIED
# error Using ETH_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using ETH_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_16BIT
# error Using ETH_START_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_16BIT
# error Using ETH_STOP_SEC_VAR_NOINIT_16BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_8BIT
# error Using ETH_START_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_8BIT
# error Using ETH_STOP_SEC_VAR_NOINIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using ETH_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using ETH_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
# error Using ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
# error Using ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in Eth_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Eth_MemMap.h
 *********************************************************************************************************************/

