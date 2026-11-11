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
 *            Module: EthTrcv_30_Tja1103
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTrcv_30_Tja1103_Cfg.h
 *   Generation Time: 2026-09-03 22:28:16
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

#if !defined (ETHTRCV_30_TJA1103_CFG_H)
# define ETHTRCV_30_TJA1103_CFG_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETHTRCV_30_TJA1103_USE_DUMMY_STATEMENT
#define ETHTRCV_30_TJA1103_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_TJA1103_DUMMY_STATEMENT
#define ETHTRCV_30_TJA1103_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_TJA1103_DUMMY_STATEMENT_CONST
#define ETHTRCV_30_TJA1103_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETHTRCV_30_TJA1103_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETHTRCV_30_TJA1103_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETHTRCV_30_TJA1103_ATOMIC_VARIABLE_ACCESS
#define ETHTRCV_30_TJA1103_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETHTRCV_30_TJA1103_PROCESSOR_IND13400
#define ETHTRCV_30_TJA1103_PROCESSOR_IND13400
#endif
#ifndef ETHTRCV_30_TJA1103_COMP_LLVMDIAB
#define ETHTRCV_30_TJA1103_COMP_LLVMDIAB
#endif
#ifndef ETHTRCV_30_TJA1103_GEN_GENERATOR_MSR
#define ETHTRCV_30_TJA1103_GEN_GENERATOR_MSR
#endif
#ifndef ETHTRCV_30_TJA1103_CPUTYPE_BITORDER_LSB2MSB
#define ETHTRCV_30_TJA1103_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_PRECOMPILE
#define ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_LINKTIME
#define ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT
#define ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT ETHTRCV_30_TJA1103_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETHTRCV_30_TJA1103_POSTBUILD_VARIANT_SUPPORT
#define ETHTRCV_30_TJA1103_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  SYMBOLIC NAME DEFINES
 *********************************************************************************************************************/
#define EthTrcvConf_EthTrcvConfig_EthTrcvConfig_TJA1103B (0u)

/**********************************************************************************************************************
 *  CONFIGURATION VERSION
 *********************************************************************************************************************/
# define ETHTRCV_30_TJA1103_CFG_MAJOR_VERSION                       (4u)
# define ETHTRCV_30_TJA1103_CFG_MINOR_VERSION                       (0u)

/**********************************************************************************************************************
 *  SWITCH DEFINES
 *********************************************************************************************************************/
# define ETHTRCV_30_TJA1103_DEV_ERROR_DETECT                                     (STD_ON)
# define ETHTRCV_30_TJA1103_DEV_ERROR_REPORT                                     (STD_ON)
# define ETHTRCV_30_TJA1103_PROD_ERROR_REPORTING                                 (STD_OFF)
# define ETHTRCV_30_TJA1103_VERSION_INFO_API                                     (STD_OFF)
# define ETHTRCV_30_TJA1103_ENABLE_GET_TRCV_MODE                                 (STD_ON)
# define ETHTRCV_30_TJA1103_ENABLE_SET_TRCV_MODE                                 (STD_ON)
# define ETHTRCV_30_TJA1103_ENABLE_START_AUTO_NEG                                (STD_OFF)
# define ETHTRCV_30_TJA1103_ENABLE_GET_LINK_STATE                                (STD_ON)
# define ETHTRCV_30_TJA1103_ENABLE_GET_BAUD_RATE                                 (STD_ON)
# define ETHTRCV_30_TJA1103_ENABLE_GET_DUPLEX_MODE                               (STD_ON)
# define ETHTRCV_30_TJA1103_ENABLE_GET_TRANSCEIVER_WAKEUP_MODE_API               (STD_OFF)
# define ETHTRCV_30_TJA1103_WAKEUP_TYPE                                          (ETHTRCV_WAKEUP_NOT_SUPPORTED)
# define ETHTRCV_30_TJA1103_WAKEUP_INSPECTION_ICU_CHANNEL                        (STD_OFF)
# define ETHTRCV_30_TJA1103_ENABLE_RUN_CABLE_DIAGNOSTIC                          (STD_ON)
# define ETHTRCV_30_TJA1103_MACSEC_API                                           (STD_OFF)

/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - START
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USER SPECIFIC CONTENT - END
 *********************************************************************************************************************/

#endif /* ETHTRCV_30_TJA1103_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1103_Cfg.h
 *********************************************************************************************************************/
 

