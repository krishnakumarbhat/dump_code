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
 *              File: Os_Hal_Entry_Lcfg.c
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
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


#define OS_CORE0_START_SEC_CODE_INTVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Extern declarations of category 1 and 0 ISRs. */

#define OS_CORE0_STOP_SEC_CODE_INTVEC_ASIL_D_LOCAL
#include "Os_Code_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_CORE0_START_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static CONST(Os_Hal_IntcIrqSourceConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0_InterruptVectorTable[992] =
{
  /* 0 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 1 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 2 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 3 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 4 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 5 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 6 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 7 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 8 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 9 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 10 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 11 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 12 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 13 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 14 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 15 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 16 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 17 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 18 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 19 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 20 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 21 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 22 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 23 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 24 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 25 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 26 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 27 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 28 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 29 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 30 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CounterIsr_OsCounter,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 31 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 32 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CANFD0_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 33 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CANFD1_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 34 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_WATCHDOG_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 35 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 36 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 37 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 38 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 39 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 40 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 41 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 42 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 43 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_I2C_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 44 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_TIMER1_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 45 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_TIMER2_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 46 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_TIMER3_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 47 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet0_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 48 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet1_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 49 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet2_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 50 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet3_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 51 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet4_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 52 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet5_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 53 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet6_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 54 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Ethernet7_IRQ,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 55 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 56 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 57 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CMRT_ISR,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 58 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 59 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 60 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 61 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 62 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 63 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 64 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 65 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_DMA_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 66 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Artie_Mem_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 67 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_GPADC_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 68 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 69 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 70 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 71 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 72 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_BBE_SP_FUSA_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 73 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_BBE_SP_GPIO0_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 74 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 75 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 76 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 77 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_RA_ERROR_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 78 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_RA_FUSA_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 79 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Sysmem0_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 80 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Sysmem1_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 81 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_FRM_START_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 82 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_FRM_END_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 83 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_CHP_START_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 84 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_CHP_END_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 85 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_CHP_FUSA_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 86 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 87 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 88 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_AA0_FUSA_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 89 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_AA1_FUSA_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 90 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MM_INTF0_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 91 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 92 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 93 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 94 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 95 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 96 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 97 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 98 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 99 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 100 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 101 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 102 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 103 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 104 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 105 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 106 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 107 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 108 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_dsp_ctrl_err_fusa_irq_handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 109 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 110 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_mipi_err_fusa_handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 111 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 112 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 113 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 114 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 115 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 116 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 117 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_HSM_FUSA_ALARM_ISR,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 118 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 119 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 120 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 121 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CNOC_Latent_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 122 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 123 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 124 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_ANOC_Latent_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 125 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 126 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 127 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_SNOC_Latent_Fusa_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 128 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 129 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 130 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_HSM_DMB_ISR,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 131 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 132 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 133 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 134 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 135 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 136 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 137 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 138 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 139 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 140 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_DSP_Clock_Monitor_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 141 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_RA_Clock_Monitor_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 142 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_MIPI_Clock_Monitor_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 143 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_Serial_Clock_Monitor_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 144 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 145 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 146 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 147 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 148 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_CRG_RMON_SWS_IRQ_Handler,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 149 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 150 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 151 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 152 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 153 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 154 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 155 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 156 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_TIMER4_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 157 */
  {
    /* .InterruptType = */ OS_HAL_ISR_CAT2,
    /* .Os_Hal_IntcIrqDataType = */
    {
    /* .IsrConfigRef  = */ (P2VAR(void,OS_CONST,AUTOMATIC))&OsCfg_Isr_TIMER5_Handler_Isr,   /* PRQA S 0311, 0314 *//*  MD_Os_Hal_Rule11.8_0311, MD_Os_Hal_Dir1.1_0314 */
    /* .Cat1IsrFunction  = */ NULL_PTR
    }
  },
  /* 158 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 159 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 160 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 161 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 162 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 163 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 164 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 165 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 166 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 167 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 168 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 169 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 170 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 171 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 172 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 173 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 174 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 175 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 176 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 177 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 178 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 179 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 180 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 181 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 182 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 183 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 184 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 185 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 186 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 187 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 188 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 189 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 190 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 191 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 192 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 193 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 194 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 195 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 196 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 197 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 198 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 199 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 200 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 201 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 202 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 203 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 204 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 205 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 206 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 207 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 208 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 209 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 210 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 211 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 212 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 213 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 214 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 215 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 216 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 217 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 218 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 219 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 220 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 221 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 222 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 223 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 224 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 225 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 226 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 227 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 228 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 229 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 230 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 231 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 232 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 233 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 234 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 235 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 236 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 237 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 238 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 239 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 240 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 241 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 242 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 243 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 244 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 245 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 246 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 247 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 248 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 249 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 250 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 251 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 252 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 253 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 254 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 255 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 256 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 257 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 258 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 259 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 260 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 261 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 262 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 263 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 264 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 265 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 266 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 267 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 268 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 269 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 270 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 271 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 272 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 273 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 274 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 275 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 276 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 277 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 278 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 279 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 280 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 281 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 282 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 283 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 284 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 285 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 286 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 287 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 288 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 289 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 290 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 291 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 292 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 293 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 294 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 295 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 296 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 297 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 298 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 299 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 300 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 301 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 302 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 303 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 304 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 305 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 306 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 307 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 308 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 309 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 310 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 311 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 312 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 313 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 314 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 315 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 316 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 317 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 318 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 319 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 320 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 321 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 322 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 323 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 324 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 325 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 326 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 327 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 328 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 329 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 330 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 331 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 332 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 333 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 334 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 335 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 336 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 337 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 338 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 339 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 340 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 341 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 342 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 343 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 344 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 345 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 346 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 347 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 348 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 349 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 350 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 351 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 352 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 353 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 354 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 355 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 356 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 357 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 358 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 359 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 360 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 361 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 362 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 363 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 364 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 365 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 366 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 367 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 368 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 369 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 370 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 371 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 372 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 373 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 374 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 375 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 376 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 377 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 378 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 379 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 380 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 381 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 382 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 383 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 384 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 385 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 386 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 387 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 388 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 389 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 390 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 391 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 392 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 393 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 394 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 395 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 396 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 397 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 398 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 399 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 400 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 401 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 402 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 403 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 404 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 405 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 406 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 407 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 408 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 409 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 410 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 411 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 412 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 413 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 414 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 415 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 416 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 417 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 418 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 419 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 420 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 421 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 422 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 423 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 424 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 425 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 426 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 427 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 428 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 429 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 430 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 431 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 432 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 433 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 434 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 435 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 436 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 437 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 438 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 439 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 440 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 441 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 442 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 443 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 444 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 445 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 446 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 447 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 448 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 449 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 450 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 451 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 452 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 453 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 454 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 455 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 456 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 457 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 458 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 459 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 460 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 461 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 462 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 463 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 464 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 465 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 466 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 467 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 468 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 469 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 470 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 471 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 472 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 473 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 474 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 475 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 476 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 477 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 478 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 479 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 480 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 481 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 482 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 483 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 484 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 485 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 486 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 487 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 488 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 489 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 490 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 491 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 492 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 493 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 494 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 495 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 496 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 497 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 498 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 499 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 500 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 501 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 502 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 503 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 504 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 505 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 506 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 507 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 508 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 509 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 510 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 511 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 512 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 513 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 514 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 515 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 516 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 517 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 518 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 519 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 520 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 521 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 522 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 523 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 524 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 525 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 526 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 527 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 528 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 529 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 530 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 531 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 532 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 533 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 534 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 535 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 536 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 537 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 538 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 539 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 540 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 541 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 542 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 543 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 544 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 545 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 546 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 547 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 548 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 549 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 550 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 551 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 552 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 553 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 554 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 555 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 556 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 557 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 558 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 559 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 560 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 561 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 562 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 563 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 564 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 565 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 566 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 567 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 568 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 569 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 570 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 571 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 572 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 573 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 574 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 575 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 576 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 577 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 578 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 579 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 580 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 581 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 582 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 583 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 584 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 585 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 586 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 587 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 588 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 589 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 590 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 591 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 592 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 593 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 594 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 595 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 596 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 597 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 598 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 599 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 600 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 601 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 602 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 603 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 604 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 605 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 606 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 607 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 608 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 609 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 610 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 611 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 612 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 613 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 614 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 615 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 616 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 617 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 618 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 619 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 620 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 621 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 622 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 623 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 624 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 625 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 626 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 627 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 628 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 629 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 630 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 631 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 632 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 633 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 634 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 635 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 636 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 637 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 638 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 639 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 640 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 641 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 642 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 643 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 644 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 645 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 646 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 647 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 648 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 649 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 650 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 651 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 652 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 653 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 654 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 655 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 656 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 657 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 658 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 659 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 660 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 661 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 662 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 663 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 664 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 665 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 666 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 667 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 668 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 669 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 670 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 671 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 672 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 673 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 674 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 675 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 676 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 677 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 678 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 679 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 680 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 681 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 682 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 683 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 684 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 685 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 686 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 687 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 688 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 689 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 690 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 691 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 692 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 693 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 694 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 695 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 696 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 697 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 698 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 699 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 700 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 701 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 702 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 703 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 704 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 705 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 706 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 707 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 708 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 709 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 710 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 711 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 712 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 713 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 714 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 715 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 716 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 717 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 718 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 719 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 720 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 721 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 722 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 723 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 724 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 725 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 726 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 727 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 728 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 729 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 730 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 731 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 732 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 733 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 734 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 735 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 736 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 737 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 738 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 739 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 740 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 741 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 742 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 743 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 744 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 745 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 746 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 747 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 748 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 749 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 750 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 751 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 752 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 753 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 754 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 755 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 756 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 757 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 758 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 759 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 760 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 761 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 762 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 763 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 764 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 765 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 766 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 767 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 768 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 769 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 770 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 771 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 772 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 773 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 774 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 775 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 776 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 777 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 778 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 779 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 780 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 781 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 782 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 783 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 784 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 785 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 786 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 787 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 788 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 789 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 790 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 791 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 792 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 793 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 794 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 795 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 796 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 797 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 798 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 799 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 800 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 801 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 802 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 803 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 804 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 805 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 806 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 807 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 808 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 809 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 810 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 811 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 812 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 813 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 814 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 815 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 816 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 817 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 818 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 819 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 820 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 821 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 822 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 823 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 824 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 825 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 826 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 827 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 828 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 829 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 830 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 831 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 832 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 833 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 834 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 835 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 836 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 837 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 838 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 839 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 840 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 841 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 842 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 843 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 844 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 845 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 846 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 847 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 848 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 849 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 850 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 851 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 852 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 853 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 854 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 855 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 856 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 857 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 858 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 859 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 860 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 861 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 862 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 863 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 864 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 865 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 866 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 867 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 868 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 869 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 870 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 871 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 872 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 873 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 874 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 875 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 876 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 877 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 878 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 879 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 880 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 881 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 882 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 883 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 884 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 885 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 886 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 887 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 888 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 889 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 890 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 891 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 892 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 893 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 894 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 895 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 896 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 897 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 898 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 899 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 900 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 901 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 902 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 903 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 904 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 905 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 906 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 907 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 908 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 909 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 910 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 911 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 912 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 913 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 914 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 915 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 916 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 917 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 918 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 919 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 920 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 921 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 922 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 923 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 924 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 925 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 926 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 927 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 928 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 929 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 930 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 931 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 932 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 933 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 934 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 935 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 936 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 937 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 938 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 939 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 940 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 941 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 942 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 943 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 944 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 945 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 946 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 947 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 948 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 949 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 950 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 951 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 952 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 953 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 954 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 955 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 956 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 957 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 958 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 959 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 960 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 961 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 962 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 963 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 964 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 965 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 966 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 967 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 968 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 969 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 970 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 971 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 972 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 973 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 974 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 975 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 976 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 977 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 978 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 979 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 980 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 981 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 982 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 983 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 984 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 985 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 986 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 987 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 988 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 989 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 990 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
  /* 991 */
  {
    /* .InterruptType = */ OS_HAL_ISR_UNHANDLED,
    /* .Data          = */ {NULL_PTR}
  },
};

#define OS_CORE0_STOP_SEC_CONST_INTVEC_ASIL_D_LOCAL_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_INTVEC_ASIL_D_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to interrupt vector table configuration data. */
CONST(Os_Hal_Core2InterruptVectorTableType, OS_CONST) OsCfg_Hal_Core2InterruptVectorTable[2] =
{
  OsCfg_Hal_Core_OsCore0_InterruptVectorTable,
   NULL_PTR
};

#define OS_STOP_SEC_CONST_INTVEC_ASIL_D_UNSPECIFIED
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
