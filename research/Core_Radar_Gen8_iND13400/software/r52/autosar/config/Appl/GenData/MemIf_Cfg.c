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
 *            Module: MemIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemIf_Cfg.c
 *   Generation Time: 2026-04-02 15:09:55
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

#define MEMIF_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MemIf.h"

/****  Include of MemHwA Modules ************************************************************************************/
#include "Fee_30_FlexNor.h" 



/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (MEMIF_CFG_MAJOR_VERSION != (6u)) \
     || (MEMIF_CFG_MINOR_VERSION != (1u)))
# error "Version numbers of MemIf_Cfg.c and MemIf_Cfg.h are inconsistent!"
#endif

#if (   (MEMIF_SW_MAJOR_VERSION != (4u)) \
     || (MEMIF_SW_MINOR_VERSION != (1u)))
# error "Version numbers of MemIf_Cfg.c and MemIf.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
#ifndef MEMIF_LOCAL /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL static
#endif

#if !defined (MEMIF_LOCAL_INLINE) /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL_INLINE LOCAL_INLINE
#endif
 
#define MEMIF_START_SEC_CONST_8
#include "MemIf_MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices = MEMIF_NUMBER_OF_DEVICES;

#define MEMIF_STOP_SEC_CONST_8
#include "MemIf_MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MemHwA Function Pointer Tables
 *********************************************************************************************************************/
#define MEMIF_START_SEC_CODE
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**-- MemHwA Write Wrapper Functions --**/
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_30_FlexNor_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr); 

 
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_30_FlexNor_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr) /* PRQA S 3673 */ /* MD_MEMIF_16.7 */ 
{ 
    return Fee_30_FlexNor_Write(BlockNumber, DataBufferPtr); /* SBSW_MEMIF_04 */ 
}
 

#define MEMIF_STOP_SEC_CODE
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define MEMIF_START_SEC_CONST_32
#include "MemIf_MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */

/**-- MemHwA Function Pointers --**/
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis[MEMIF_NUMBER_OF_DEVICES] =
{
   /*  Fee_30_FlexNor  */ {
    Fee_30_FlexNor_Read, 
    MemIf_Fee_30_FlexNor_WriteWrapper, 
    Fee_30_FlexNor_EraseImmediateBlock, 
    Fee_30_FlexNor_InvalidateBlock, 
    Fee_30_FlexNor_Cancel, 
    Fee_30_FlexNor_GetStatus, 
    Fee_30_FlexNor_GetJobResult, 
    NULL_PTR
  }
};
    
#define MEMIF_STOP_SEC_CONST_32
#include "MemIf_MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */
    
/* Justification for module-specific MISRA deviations:     
  MD_MEMIF_16.7: rule 16.7
      Reason:     Buffer pointer is not declared const in order to support EA/FEE write interfaces with const and non-const buffers.
      Risk:       No risk. By using this wrapper functions without const pointers compiler warnings are solved.
      Prevention: Program flow has been verified by component tests and review.
*/
        
/**********************************************************************************************************************
 *  END OF FILE: MemIf_Cfg.c
 *********************************************************************************************************************/   

