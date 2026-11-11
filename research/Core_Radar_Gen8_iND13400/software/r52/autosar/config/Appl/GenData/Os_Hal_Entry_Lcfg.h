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
 *            Module: Os
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.h
 *   Generation Time: 2026-09-14 17:36:15
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

                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_ENTRY_LCFG_H
# define OS_HAL_ENTRY_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"
# include "Os_Hal_Compiler.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_CORE0_START_SEC_CONST_EXCVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Os_Hal_ExceptionTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore0_ExceptionTable[8];

#define OS_CORE0_STOP_SEC_CONST_EXCVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_CORE0_START_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Os_Hal_VectorTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore0_VectorTable[992];

#define OS_CORE0_STOP_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FIQ VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_CORE0_START_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Os_Hal_VectorTableEntryType, OS_CONST) OsCfg_Hal_Core_OsCore0_FiqVectorTable[32];

#define OS_CORE0_STOP_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE_INTVEC_ASIL_D
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_STOP_SEC_CODE_INTVEC_ASIL_D
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_CORE0_START_SEC_CODE_EXCVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_CORE0_STOP_SEC_CODE_EXCVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_ENTRY_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.h
 *********************************************************************************************************************/
