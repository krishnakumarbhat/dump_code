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
 *            Module: Eth_30_Wrapper
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eth_30_Wrapper_Cfg.h
 *   Generation Time: 2026-08-27 14:12:18
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


#if !defined (ETH_30_WRAPPER_CFG_H)
# define ETH_30_WRAPPER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ETH_30_WRAPPER_CFG_MAJOR_VERSION    (5u)
#define ETH_30_WRAPPER_CFG_MINOR_VERSION    (3u)
#define ETH_30_WRAPPER_CFG_PATCH_VERSION    (1u)

/**********************************************************************************************************************
 *  GENERAL DEFINES
 *********************************************************************************************************************/
#ifndef ETH_30_WRAPPER_USE_DUMMY_STATEMENT
#define ETH_30_WRAPPER_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_WRAPPER_DUMMY_STATEMENT
#define ETH_30_WRAPPER_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_WRAPPER_DUMMY_STATEMENT_CONST
#define ETH_30_WRAPPER_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ETH_30_WRAPPER_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ETH_30_WRAPPER_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ETH_30_WRAPPER_ATOMIC_VARIABLE_ACCESS
#define ETH_30_WRAPPER_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ETH_30_WRAPPER_PROCESSOR_IND13400
#define ETH_30_WRAPPER_PROCESSOR_IND13400
#endif
#ifndef ETH_30_WRAPPER_COMP_LLVMDIAB
#define ETH_30_WRAPPER_COMP_LLVMDIAB
#endif
#ifndef ETH_30_WRAPPER_GEN_GENERATOR_MSR
#define ETH_30_WRAPPER_GEN_GENERATOR_MSR
#endif
#ifndef ETH_30_WRAPPER_CPUTYPE_BITORDER_LSB2MSB
#define ETH_30_WRAPPER_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ETH_30_WRAPPER_CONFIGURATION_VARIANT_PRECOMPILE
#define ETH_30_WRAPPER_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ETH_30_WRAPPER_CONFIGURATION_VARIANT_LINKTIME
#define ETH_30_WRAPPER_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ETH_30_WRAPPER_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ETH_30_WRAPPER_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ETH_30_WRAPPER_CONFIGURATION_VARIANT
#define ETH_30_WRAPPER_CONFIGURATION_VARIANT ETH_30_WRAPPER_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ETH_30_WRAPPER_POSTBUILD_VARIANT_SUPPORT
#define ETH_30_WRAPPER_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Defines whether development error detection or reporting is enabled (STD_ON) or not (STD_OFF). */
#ifndef ETH_30_WRAPPER_DEV_ERROR_DETECT
#define ETH_30_WRAPPER_DEV_ERROR_DETECT STD_ON
#endif
#ifndef ETH_30_WRAPPER_DEV_ERROR_REPORT
#define ETH_30_WRAPPER_DEV_ERROR_REPORT STD_OFF
#endif

/* Selects among different sets of callbacks APIs according to different AUTOSAR versions */
# define ETH_30_WRAPPER_CBKEQCLASS_2 /* Callback API set of AR_4_3_1, AR_4_4_0, AR_19_11, AR_20_11, AR_21_11, AR_22_11 */

/**********************************************************************************************************************
 *  SYMBOLIC NAME VALUES
 *********************************************************************************************************************/
#define EthConf_EthCtrlConfig_RDR_1_Eth_Controller_1_6addc1bb (0u)

/**********************************************************************************************************************
 *  SWITCH DEFINES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NUMERICAL DEFINES
 *********************************************************************************************************************/
/*! \brief   Controller Index Offset
 *  \details It can not be assumed that the smallest controller index starts with zero. This is because the controller
 *           indexes are calculated in an ascending order by the EthIf which might has also non 3th party controllers
 *           configured.
 *           Therefore it is necessary to offset the controller index by the smallest controller index, which was
 *           assigned by the EthIf. */
# define ETH_30_WRAPPER_CTRL_IDX_OFFSET                  0u

/*! \brief   Max Number of configured Buffers
 *  \details The Ethernet Stack has currently a limitation that only 255 Buffers can be configured.
             Therefore it is necessary to add the limitation of the max configured buffers to 255. */
# define ETH_30_WRAPPER_MAX_BUFFER_INDEX                 255u

/*! \brief The Buffer Index Offset as defined by AR24-11 */
# define ETH_30_WRAPPER_BUFFER_INDEX_OFFSET              0x10000u

#endif /* ETH_30_WRAPPER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Wrapper_Cfg.h
 *********************************************************************************************************************/

