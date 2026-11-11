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
 *              File: TcpIp_MemMap.h
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

#if defined TCPIP_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CODE_OPEN
#  error Using TCPIP_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CODE_ISR
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CODE_ISR is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CODE_ISR_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CODE_ISR
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CODE_ISR is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CODE_ISR_OPEN
#  error Using TCPIP_STOP_SEC_CODE_ISR is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CODE_ISR_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONFIG_DATA
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONFIG_DATA is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONFIG_DATA_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONFIG_DATA /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONFIG_DATA
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONFIG_DATA is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONFIG_DATA_OPEN
#  error Using TCPIP_STOP_SEC_CONFIG_DATA is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONFIG_DATA_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONFIG_DATA /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONST_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONST_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONST_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONST_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONST_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONST_16_OPEN
#  error Using TCPIP_STOP_SEC_CONST_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONST_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONST_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONST_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONST_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONST_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONST_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONST_32_OPEN
#  error Using TCPIP_STOP_SEC_CONST_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONST_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONST_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONST_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONST_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONST_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONST_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONST_8_OPEN
#  error Using TCPIP_STOP_SEC_CONST_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONST_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONST_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONST_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONST_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONST_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONST_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONST_PBCFG_OPEN
#  error Using TCPIP_STOP_SEC_CONST_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONST_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_CONST_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_CONST_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_PBCFG_OPEN
#  error Using TCPIP_STOP_SEC_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_PBCFG_GLOBALROOT
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_PBCFG_GLOBALROOT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_PBCFG_GLOBALROOT_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_PBCFG_GLOBALROOT
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_PBCFG_GLOBALROOT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_PBCFG_GLOBALROOT_OPEN
#  error Using TCPIP_STOP_SEC_PBCFG_GLOBALROOT is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_PBCFG_GLOBALROOT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_REASSEMBLYBUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_REASSEMBLYBUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_REASSEMBLYBUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_RXPROCESSBUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_RXPROCESSBUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_RXPROCESSBUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_SAENTRY_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_SAENTRY_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_SAENTRY_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TCPRXBUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TCPRXBUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TCPRXBUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TCPTXBUFFER_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TCPTXBUFFER_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TCPTXBUFFER_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TLSBUFFERRX_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TLSBUFFERRX_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TLSBUFFERRX_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_TLSBUFFERTX_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_TLSBUFFERTX_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_TLSBUFFERTX_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_CLEARED_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_CLEARED_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_CLEARED_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_CLEARED_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_CLEARED_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_CLEARED_8_OPEN
#  error Using TCPIP_STOP_SEC_VAR_CLEARED_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_CLEARED_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_CLEARED_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_CLEARED_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_CLEARED_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_NO_INIT_16
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_NO_INIT_16 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_NO_INIT_16_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_NO_INIT_16
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_16 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_NO_INIT_16_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_16 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_NO_INIT_16_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_NO_INIT_32
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_NO_INIT_32 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_NO_INIT_32_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_NO_INIT_32
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_32 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_NO_INIT_32_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_32 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_NO_INIT_32_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_NO_INIT_8
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_NO_INIT_8 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_NO_INIT_8_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_NO_INIT_8
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_8 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_NO_INIT_8_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_8 is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_NO_INIT_8_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_NO_INIT_UNSPECIFIED_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_NO_INIT_UNSPECIFIED_OPEN
#  error Using TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_NO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined TCPIP_START_SEC_VAR_PBCFG
# ifdef MEMMAP_SECTION_OPEN
#  error Using TCPIP_START_SEC_VAR_PBCFG is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define TCPIP_VAR_PBCFG_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined TCPIP_STOP_SEC_VAR_PBCFG
# ifndef MEMMAP_SECTION_OPEN
#  error Using TCPIP_STOP_SEC_VAR_PBCFG is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef TCPIP_VAR_PBCFG_OPEN
#  error Using TCPIP_STOP_SEC_VAR_PBCFG is not possible as the corresponding memory section has not been opened.
# endif
# undef TCPIP_VAR_PBCFG_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef TCPIP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef TCPIP_START_SEC_CODE
# error Using TCPIP_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CODE
# error Using TCPIP_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CODE_ISR
# error Using TCPIP_START_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CODE_ISR
# error Using TCPIP_STOP_SEC_CODE_ISR is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONFIG_DATA
# error Using TCPIP_START_SEC_CONFIG_DATA is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONFIG_DATA
# error Using TCPIP_STOP_SEC_CONFIG_DATA is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONST_16
# error Using TCPIP_START_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONST_16
# error Using TCPIP_STOP_SEC_CONST_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONST_32
# error Using TCPIP_START_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONST_32
# error Using TCPIP_STOP_SEC_CONST_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONST_8
# error Using TCPIP_START_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONST_8
# error Using TCPIP_STOP_SEC_CONST_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONST_PBCFG
# error Using TCPIP_START_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONST_PBCFG
# error Using TCPIP_STOP_SEC_CONST_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_CONST_UNSPECIFIED
# error Using TCPIP_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_CONST_UNSPECIFIED
# error Using TCPIP_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_IPV6FRAGMENTTXDATABUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_IPV6REASSEMBLYDATABUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_PBCFG
# error Using TCPIP_START_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_PBCFG
# error Using TCPIP_STOP_SEC_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_PBCFG_GLOBALROOT
# error Using TCPIP_START_SEC_PBCFG_GLOBALROOT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_PBCFG_GLOBALROOT
# error Using TCPIP_STOP_SEC_PBCFG_GLOBALROOT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_REASSEMBLYBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_RXPROCESSBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_START_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_STOP_SEC_SAENTRY_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_START_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_STOP_SEC_SOCKETTCPDYN_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_START_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_STOP_SEC_TCPOOOQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_START_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_STOP_SEC_TCPRETRYQELEMENT_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_TCPRXBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_TCPRXBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_TCPTXBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_TCPTXBUFFER_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_TLSBUFFERRX_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_TLSBUFFERRX_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_TLSBUFFERTX_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_TLSBUFFERTX_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_CLEARED_8
# error Using TCPIP_START_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_CLEARED_8
# error Using TCPIP_STOP_SEC_VAR_CLEARED_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
# error Using TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# error Using TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_NO_INIT_16
# error Using TCPIP_START_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_NO_INIT_16
# error Using TCPIP_STOP_SEC_VAR_NO_INIT_16 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_NO_INIT_32
# error Using TCPIP_START_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_NO_INIT_32
# error Using TCPIP_STOP_SEC_VAR_NO_INIT_32 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_NO_INIT_8
# error Using TCPIP_START_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_NO_INIT_8
# error Using TCPIP_STOP_SEC_VAR_NO_INIT_8 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# error Using TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_START_SEC_VAR_PBCFG
# error Using TCPIP_START_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef TCPIP_STOP_SEC_VAR_PBCFG
# error Using TCPIP_STOP_SEC_VAR_PBCFG is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#if defined MEMMAP_ERROR && !defined MEMMAP_ERROR_TOLERATE_INVALID_KEYWORD
# error No MemMap section found in TcpIp_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_MemMap.h
 *********************************************************************************************************************/

