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
 *              File: Os_Hal_MemoryProtection_Lcfg.c
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
/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_MEMORYPROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_MemoryProtection_Cfg.h"
#include "Os_Hal_MemoryProtection_Lcfg.h"
#include "Os_Hal_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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

#define OS_CORE0_START_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: OsCore0 */
OS_LOCAL CONST(Os_Hal_MpRegionType, OS_CONST) OsCfg_Hal_Mp_OsCore0_Regions[11] =
{
  {
    /* .RegionNumber        = */ 0x00000000u,
    /* .RegionBaseAddress   = */ (uint32)&_OS_CORE0_STACKS_START,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&_OS_CORE0_STACKS_LIMIT, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000001u,
    /* .RegionBaseAddress   = */ (uint32)&_OS_CORE0_STACKS_START,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&_OS_CORE0_STACKS_START, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000002u,
    /* .RegionBaseAddress   = */ (uint32)&_OS_CORE0_STACKS_LIMIT,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&_OS_CORE0_STACKS_LIMIT, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000003u,
    /* .RegionBaseAddress   = */ (uint32)&__R52_TCMBC_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__R52_TCMBC_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000004u,
    /* .RegionBaseAddress   = */ (uint32)&__R52_TCMA_NULL_GUARD_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__R52_TCMA_NULL_GUARD_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_R_U_NONE | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000005u,
    /* .RegionBaseAddress   = */ (uint32)&__R52_TCMA_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__R52_TCMA_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000006u,
    /* .RegionBaseAddress   = */ (uint32)&__SYSMEM0_R52_SYSMEM_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__SYSMEM0_R52_SYSMEM_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000007u,
    /* .RegionBaseAddress   = */ (uint32)&__SYSMEM0_R52_DATA_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__SYSMEM0_R52_DATA_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000008u,
    /* .RegionBaseAddress   = */ (uint32)&__ARTIE_MEM_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__ARTIE_MEM_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x00000009u,
    /* .RegionBaseAddress   = */ (uint32)&__SYSMEM1_R52_DATA_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__SYSMEM1_R52_DATA_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }
,
  {
    /* .RegionNumber        = */ 0x0000000Au,
    /* .RegionBaseAddress   = */ (uint32)&__SYSMEM0_R52_QM_BASE__,   /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionEndAddress = */ (uint32)&__SYSMEM0_R52_QM_LIMIT__, /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* .RegionAccessControl = */ OS_HAL_MP_ACCESS_S_RW_U_RW | OS_HAL_MP_ACCESS_EXECUTE_ALLOWED,
    /* .RegionEnableAndFlags = */ OS_HAL_MP_REGION_SIZE_ENABLE | OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE_FLAGS
  }

};

CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)11,
  /* .MpuRegions     = */ OsCfg_Hal_Mp_OsCore0_Regions
};

/*! HAL memory protection configuration data: OsCore0_ASIL */

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0_ASIL =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: OsCore_Qm */

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore_Qm =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SystemApplication_OsCore0 */

CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: AA0_FUSA_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_AA0_FUSA_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: AA1_FUSA_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_AA1_FUSA_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: ANOC_Latent_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ANOC_Latent_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Artie_Mem_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Artie_Mem_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: BBE_SP_FUSA_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BBE_SP_FUSA_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: BBE_SP_GPIO0_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BBE_SP_GPIO0_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CANFD0_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CANFD0_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CANFD1_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CANFD1_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CMRT_ISR */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CMRT_ISR =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CNOC_Latent_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CNOC_Latent_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CRG_RMON_SWS_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CRG_RMON_SWS_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: CounterIsr_OsCounter */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_OsCounter =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: DMA_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DMA_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: DSP_Clock_Monitor_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DSP_Clock_Monitor_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet0_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet0_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet1_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet1_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet2_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet2_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet3_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet3_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet4_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet4_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet5_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet5_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet6_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet6_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Ethernet7_IRQ */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Ethernet7_IRQ =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: GPADC_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_GPADC_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: HSM_DMB_ISR */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_HSM_DMB_ISR =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: HSM_FUSA_ALARM_ISR */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_HSM_FUSA_ALARM_ISR =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: I2C_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_I2C_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_CHP_END_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_END_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_CHP_FUSA_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_FUSA_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_CHP_START_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_CHP_START_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_Clock_Monitor_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_Clock_Monitor_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_FRM_END_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_FRM_END_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MIPI_FRM_START_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MIPI_FRM_START_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: MM_INTF0_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MM_INTF0_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: RA_Clock_Monitor_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_Clock_Monitor_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: RA_ERROR_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_ERROR_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: RA_FUSA_IRQ_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_RA_FUSA_IRQ_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: SNOC_Latent_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SNOC_Latent_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Serial_Clock_Monitor_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Serial_Clock_Monitor_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Sysmem0_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Sysmem0_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Sysmem1_Fusa_Handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Sysmem1_Fusa_Handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: TIMER1_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER1_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: TIMER2_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER2_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: TIMER3_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER3_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: TIMER4_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER4_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: TIMER5_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TIMER5_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: WATCHDOG_Handler_Isr */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_WATCHDOG_Handler_Isr =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: dsp_ctrl_err_fusa_irq_handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_dsp_ctrl_err_fusa_irq_handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: mipi_err_fusa_handler */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_mipi_err_fusa_handler =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_BackgroundTask */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_BackgroundTask =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_IPC_Task */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_IPC_Task =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Init */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Init =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Task */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Task_Communication */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Communication =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Task_Fast */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Fast =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Task_High_Prio */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_High_Prio =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Appl_Task_Logging */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Appl_Task_Logging =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: BSW_Task */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_Task =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: IdleTask_OsCore0 */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore0 =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Init_Task */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Init_Task =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Init_Task_Qm */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Init_Task_Qm =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

/*! HAL memory protection configuration data: Radar_Ctrl_Task */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Radar_Ctrl_Task =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

#define OS_CORE0_STOP_SEC_CONST_ASIL_D_LOCAL_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: SystemMpu */
CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu =
{
  /* .Dummy     = */ 0uL,
};

/*! HAL memory protection configuration data: EmptyThread */

CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread =
{
  /* .MpuRegionCount = */ (uint32)0,
  /* .MpuRegions     = */ NULL_PTR
};

#define OS_STOP_SEC_CONST_ASIL_D_32
#include "Os_Const_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
