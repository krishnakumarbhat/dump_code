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
 *              File: Os_Hal_EntryAsm_Lcfg.asm
 *   Generation Time: 2026-09-14 19:12:50
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
 *  INCLUDES
 *********************************************************************************************************************/
#include "Os_Cfg.h"
#if defined(OS_CFG_COMPILER_IAR)
# include "Os_Hal_Entry_IAR.inc"
#elif defined(OS_CFG_COMPILER_ARM6) || defined(OS_CFG_COMPILER_ARM)
# include "Os_Hal_Entry_ARM6.inc"
#else
# include "Os_Hal_Entry.inc"
#endif

/***********************************************************************************************************************
 *  DECLARATIONS
 **********************************************************************************************************************/


  OS_HAL_ASM_ARM_CODE

  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_IMPORT(Os_Hal_SysCallHandler)
  OS_HAL_ASM_IMPORT(Os_Hal_MemFault_PrefetchAbort)
  OS_HAL_ASM_IMPORT(Os_Hal_MemFault_DataAbort)

  OS_HAL_ASM_SECTION_END

  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_IMPORT(Os_Hal_IrqHandler2)

  /* GIC first level interrupt handler */

  OS_HAL_ASM_EXPORT(Os_Hal_IrqHandler1)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_IrqHandler1)
  Os_Hal_IsrEntry_Interrupt_Gic_ASIMD Os_Hal_IrqHandler2
  OS_HAL_ASM_FUNCTION_END(Os_Hal_IrqHandler1)
  OS_HAL_ASM_SECTION_END

/***********************************************************************************************************************
 *  Exception tables
 **********************************************************************************************************************/

  /* ----------------------------------------------------------------------------------
   *  Exception Table - OsCore0 - Logical core 0 - Physical core 0
   * --------------------------------------------------------------------------------- */

  /* Entry symbol declaration */

  OS_HAL_ASM_IMPORT(_start)


  /* User defined exception handler declarations */

  OS_HAL_ASM_IMPORT(ExceptionHandler_Illegal_Instruction)

  
  /* Exception Table - OsCore0 - Logical core 0 - Physical core 0 */

  OS_HAL_ASM_CODE_SECTION(OS_EXCVEC_CORE0_CODE)

  OS_HAL_ASM_EXPORT(OsCfg_Hal_Core_OsCore0_ExceptionTable)
OS_HAL_ASM_DEFINE_LABEL(OsCfg_Hal_Core_OsCore0_ExceptionTable)
  ldr pc,[pc,#0x18] /* Exception 0: Reset */
  ldr pc,[pc,#0x18] /* Exception 1: Undefined Instruction */
  ldr pc,[pc,#0x18] /* Exception 2: SVCall */
  ldr pc,[pc,#0x18] /* Exception 3: Abort Prefetch */
  ldr pc,[pc,#0x18] /* Exception 4: Abort Data */
  ldr pc,[pc,#0x18] /* Exception 5: Reserved */
  ldr pc,[pc,#0x18] /* Exception 6: IRQ */
  ldr pc,[pc,#0x18] /* Exception 7: FIQ */

OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_0_Address)
  OS_HAL_ASM_DEFINE_WORD(_start)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_1_Address)
  OS_HAL_ASM_DEFINE_WORD(ExceptionHandler_Illegal_Instruction)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_2_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_SysCallHandler)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_3_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_MemFault_PrefetchAbort)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_4_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_MemFault_DataAbort)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_5_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection_PMSA8)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_6_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_IrqHandler1)
OS_HAL_ASM_DEFINE_LABEL(Os_Hal_Core_0_Exception_7_Address)
  OS_HAL_ASM_DEFINE_WORD(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection_PMSA8)
  OS_HAL_ASM_SECTION_END



/***********************************************************************************************************************
 * Interrupt wrappers
 **********************************************************************************************************************/





  OS_HAL_ASM_MODULE_END


