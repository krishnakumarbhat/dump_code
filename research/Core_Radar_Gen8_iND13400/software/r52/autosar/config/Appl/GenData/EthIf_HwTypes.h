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
 *            Module: EthIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthIf_HwTypes.h
 *   Generation Time: 2026-08-27 14:12:19
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_9010BSA_100Mb is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_9010BSA_100Mb[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_RTL/EthTrcvConfigSet/EthTrcvConfig_9010BSA_100Mb) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 * 
 * [Warning] ETHIF01440 - Missing EthIfTransceiver configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] EthTrcvConfig_TJA1103B is referenced by EthIfTransceiver which is not used by EthSwtPort referenced by EthIfSwtPortGroup or directly via EthIfController.
 * [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/EthIf/EthIfConfigSet (DefRef: /MICROSAR/EthIf/EthIfConfigSet)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver)
 * /ActiveEcuC/EthIf/EthIfConfigSet/EthIf_EthTrcvConfig_TJA_1103B[0:EthIfEthTrcvRef](value=/ActiveEcuC/EthTrcv_NXP/EthTrcvConfigSet/EthTrcvConfig_TJA1103B) (DefRef: /MICROSAR/EthIf/EthIfConfigSet/EthIfTransceiver/EthIfEthTrcvRef)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#if !defined (ETHIF_HWTYPES_H)
# define ETHIF_HWTYPES_H

/**********************************************************************************************************************
 *  INCLUDE
 *********************************************************************************************************************/
/* \trace SPEC-2393718 */
/* \trace SPEC-2393858 */

#include "Eth_30_Wrapper_Types.h"


#include "EthTrcv_30_Rtl9010_Types.h"
#include "EthTrcv_30_Tja1103_Types.h"

/*********************************************************************************************************
 * Dynamic includes depending on configuration
 *********************************************************************************************************/

/*********************************************************************************************************
 * Platform-specific data type selected based on the underlying CPU type
 *********************************************************************************************************/
typedef uint32 EthIf_PlatformUIntType;

#endif /* ETHIF_HWTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthIf_HwTypes.h
 *********************************************************************************************************************/


