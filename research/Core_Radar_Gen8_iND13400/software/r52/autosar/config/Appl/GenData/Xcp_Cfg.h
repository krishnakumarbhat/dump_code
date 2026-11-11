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
 *            Module: Xcp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Xcp_Cfg.h
 *   Generation Time: 2026-05-11 17:41:29
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
    
#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__ /* PRQA S 0602, 0603 */ /* MD_XCP_0602_03 */

#ifndef XCP_USE_DUMMY_STATEMENT
#define XCP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT_CONST
#define XCP_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XCP_ATOMIC_VARIABLE_ACCESS
#define XCP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XCP_PROCESSOR_IND13400
#define XCP_PROCESSOR_IND13400
#endif
#ifndef XCP_COMP_LLVMDIAB
#define XCP_COMP_LLVMDIAB
#endif
#ifndef XCP_GEN_GENERATOR_MSR
#define XCP_GEN_GENERATOR_MSR
#endif
#ifndef XCP_CPUTYPE_BITORDER_LSB2MSB
#define XCP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef XCP_CONFIGURATION_VARIANT_PRECOMPILE
#define XCP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XCP_CONFIGURATION_VARIANT_LINKTIME
#define XCP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XCP_CONFIGURATION_VARIANT
#define XCP_CONFIGURATION_VARIANT XCP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XCP_POSTBUILD_VARIANT_SUPPORT
#define XCP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Development error detecting and reporting */
#define XCP_DEV_ERROR_DETECT                 STD_ON
#define XCP_DEV_ERROR_REPORT                 STD_ON

/* General settings */
#define XCP_BOOTLOADER_DOWNLOAD              STD_OFF
#define XCP_AMD_RUNTIME_MEASUREMENT          STD_ON
#define XCP_VERSION_INFO_API                 STD_OFF 
#define XCP_GET_SESSION_STATUS_API           STD_ON
#define XCP_TYPESAVE_COPY                    STD_OFF
#define XCP_DAQ_MEM_ACCESS_BY_APPL			 STD_ON
/* Legacy settings */
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE

/* Service Request Message */
#define XCP_SERV_TEXT                        STD_OFF
#define XCP_SEND_EVENT                       STD_ON

/* Commands */
#define XCP_OPEN_COMMAND_IF                  STD_OFF

/*  - Standard Commands */
#define XCP_BLOCK_UPLOAD                     STD_ON
#define XCP_COMM_MODE_INFO                   STD_ON
#define XCP_USER_COMMAND                     STD_ON
#define XCP_SEED_KEY                         STD_ON
#define XCP_READ_PROTECTION                  STD_OFF
#define XCP_GET_ID_GENERIC                   STD_ON
#define kXcpStationIdLength                  (0u)

/*    - CRC */
#define XCP_CHECKSUM                         STD_ON
#define XCP_CUSTOM_CRC                       STD_OFF
#define XCP_AUTOSAR_CRC_MODULE               STD_ON
#define kXcpChecksumMethod                   XCP_CHECKSUM_TYPE_ADD14
#define kXcpChecksumBlockSize                (256u)

/*  - Calibration commands */
#define XCP_CALIBRATION                      STD_ON
#define XCP_BLOCK_DOWNLOAD                   STD_ON
#define XCP_MODIFY_BITS                      STD_OFF
#define XCP_SHORT_DOWNLOAD                   STD_OFF
#define XCP_BLOCK_DOWNLOAD_MIN_ST            (0u)

/*  - Synchronous Data Acquisition (DAQ) commands */
#define XCP_DAQ                              STD_ON
#define XCP_NUMBER_OF_CORES                  (1u)
#define XCP_DAQ_COMPLEMENTARY_CHANNEL        STD_OFF
#define XCP_STIM                             STD_ON
#define XCP_DAQ_PRESCALER                    STD_OFF
#define XCP_DAQ_OVERRUN_INDICATION           STD_ON
#define XCP_WRITE_DAQ_MULTIPLE               STD_ON
#define XCP_DAQ_HDR_LEN                      (0x00u + 1U)
#define XCP_DAQ_RESUME                       STD_OFF
#define XCP_DAQ_PROCESSOR_INFO               STD_ON
#define XCP_DAQ_RESOLUTION_INFO              STD_OFF
#define XCP_DAQ_TIMESYNC                     STD_OFF

#define XCP_MAX_DAQ                          (4U)
#define XCP_MAX_ODT_DAQ                      (123u)
#define XCP_MAX_ODT_ENTRIES                  (255u)
#define XCP_MAX_ODT_STIM                     (18u)

/*    - DAQ event Info */
#define XCP_DAQ_EVENT_INFO                   STD_ON
#define XCP_MAX_EVENT                        (4u)

/*    - DAQ Timestamp */
#define XCP_DAQ_TIMESTAMP_FIXED              STD_OFF
#define XCP_DAQ_TIMESTAMP_SIZE               XCP_DAQ_TIMESTAMP_OFF
#define XCP_DAQ_TIMESTAMP_UNIT               XCP_DAQ_TIMESTAMP_UNIT_1MS
#define XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT     (1U)
#define XCP_DAQ_GMTIMESTAMP_UNIT             XCP_DAQ_TIMESTAMP_UNIT_1NS
#define XCP_DAQ_GMTIMESTAMP_TICKS_PER_UNIT   (1U)

/*  - Page switching */
#define XCP_CALIBRATION_PAGE                 STD_OFF
#define XCP_PAGE_INFO                        STD_OFF
#define XCP_MAX_SEGMENT                      (0u)
#define XCP_MAX_PAGES                        (0u)
#define XCP_PAGE_FREEZE                      STD_OFF
#define XCP_COPY_CAL_PAGE                    STD_OFF

/*  - Programming */
#define XCP_PROGRAM                          STD_ON
#define kXcpProgramMinStPgm                  (0u)
#define XCP_PROGRAMMING_WRITE_PROTECTION     STD_OFF
#define XCP_MAX_SECTOR                       (2u)
#define XCP_PROGRAM_INFO                     STD_ON

#ifndef XCP_AUTOSARVERSION
#define XCP_AUTOSARVERSION                   (4u) 
#endif

#define XCP_CANOE_EMU                        STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Multiple transport layer support
 ----------------------------------------------------------------------------- */

#define XCP_MAX_CTO_MAX                      (255u)
#define XCP_MAX_CTO_MIN                      (8u)
#define XCP_MAX_DTO_MAX                      (1444u)
#define XCP_MAX_DTO_MIN                      (8u)
/* Multiple transport layer support */
#define XCP_NUMBER_OF_TRANSPORTLAYERS        (2u)
#define XCP_NUMBER_OF_CHANNELS               ((1U))               

#define XCP_TRANSPORT_LAYER_TYPE_CAN_ASR
#define XCP_TRANSPORT_LAYER_CAN              (0u)
#define XCP_TRANSPORT_LAYER_TYPE_TCPIP_ASR
#define XCP_TRANSPORT_LAYER_TCPIP            (1u)

/* -----------------------------------------------------------------------------
    &&&~ FlexRay parameter access
 ----------------------------------------------------------------------------- */

#define XCP_READCCCONFIG                     STD_OFF
#define XCP_ADDR_EXT_READCCCONFIG            (0u)
    

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */

