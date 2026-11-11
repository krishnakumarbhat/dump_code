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
 *              File: Os_Hal_MemoryProtection_Cfg.h
 *   Generation Time: 2026-09-14 17:36:16
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

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_MEMORYPROTECTION_CFG_H 
# define OS_HAL_MEMORYPROTECTION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define OS_HAL_MP_STACK_REGION_NUMBER      (0uL)
# define OS_HAL_MP_STACK_REGION_NUMBER_ASM  0
# define OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER     (1)
# define OS_HAL_MP_STACK_PROTECTION_REGION_1_NUMBER     (2)

# define OS_HAL_ASM_MP_STACK_REGION_NUMBER                   0
# define OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER      1
# define OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER      2

# define OS_HAL_MP_MAIR0_ATTR0     (OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_OUTER_NON_CACHEABLE)
# define OS_HAL_MP_MAIR0_ATTR1     (0)
# define OS_HAL_MP_MAIR0_ATTR2     (0)
# define OS_HAL_MP_MAIR0_ATTR3     (0)
# define OS_HAL_MP_MAIR1_ATTR4     (0)
# define OS_HAL_MP_MAIR1_ATTR5     (0)
# define OS_HAL_MP_MAIR1_ATTR6     (0)
# define OS_HAL_MP_MAIR1_ATTR7     (0)

# define OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS     (0uL << 1)
    
# define OS_HAL_CONTEXT_MP_STACK_ATTRIDX (0)

/*! Defines whether memory protection is active (STD_ON). */
# define OS_HAL_CFG_MEMORY_PROTECTION_ASM   (STD_ON)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_MEMORYPROTECTION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_Cfg.h
 *********************************************************************************************************************/
