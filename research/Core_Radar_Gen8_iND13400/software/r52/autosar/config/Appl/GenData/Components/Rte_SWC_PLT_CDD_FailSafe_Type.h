/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_CDD_FailSafe_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_CDD_FailSafe>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_FAILSAFE_TYPE_H
# define RTE_SWC_PLT_CDD_FAILSAFE_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DEFAULT_RESET_REASON
#   define DEFAULT_RESET_REASON (0U)
#  endif

#  ifndef OS_ACCESS
#   define OS_ACCESS (1U)
#  endif

#  ifndef OS_CALLEVEL
#   define OS_CALLEVEL (2U)
#  endif

#  ifndef OS_ID
#   define OS_ID (3U)
#  endif

#  ifndef OS_LIMIT
#   define OS_LIMIT (4U)
#  endif

#  ifndef OS_NOFUNC
#   define OS_NOFUNC (5U)
#  endif

#  ifndef OS_RESOURCE
#   define OS_RESOURCE (6U)
#  endif

#  ifndef OS_STATE
#   define OS_STATE (7U)
#  endif

#  ifndef OS_VALUE
#   define OS_VALUE (8U)
#  endif

#  ifndef OS_SERVICEID
#   define OS_SERVICEID (9U)
#  endif

#  ifndef OS_ILLEGAL_ADDRESS
#   define OS_ILLEGAL_ADDRESS (10U)
#  endif

#  ifndef OS_MISSINGEND
#   define OS_MISSINGEND (11U)
#  endif

#  ifndef OS_DISABLEDINT
#   define OS_DISABLEDINT (12U)
#  endif

#  ifndef OS_STACKFAULT
#   define OS_STACKFAULT (13U)
#  endif

#  ifndef OS_PROTECTION_MEMORY
#   define OS_PROTECTION_MEMORY (14U)
#  endif

#  ifndef OS_PROTECTION_TIME
#   define OS_PROTECTION_TIME (15U)
#  endif

#  ifndef OS_PROTECTION_ARRIVAL
#   define OS_PROTECTION_ARRIVAL (16U)
#  endif

#  ifndef OS_PROTECTION_LOCKED
#   define OS_PROTECTION_LOCKED (17U)
#  endif

#  ifndef OS_PROTECTION_EXCEPTION
#   define OS_PROTECTION_EXCEPTION (18U)
#  endif

#  ifndef OS_INTERFERENCE_DEADLOCK
#   define OS_INTERFERENCE_DEADLOCK (19U)
#  endif

#  ifndef OS_NESTING_DEADLOCK
#   define OS_NESTING_DEADLOCK (20U)
#  endif

#  ifndef OS_SPINLOCK
#   define OS_SPINLOCK (21U)
#  endif

#  ifndef OS_CORE
#   define OS_CORE (22U)
#  endif

#  ifndef OS_PARAM_POINTER
#   define OS_PARAM_POINTER (23U)
#  endif

#  ifndef MCU_FAILSAFE_POWER_ON_RESET
#   define MCU_FAILSAFE_POWER_ON_RESET (25U)
#  endif

#  ifndef MCU_FAILSAFE_SOFT_FUNC_RESET
#   define MCU_FAILSAFE_SOFT_FUNC_RESET (26U)
#  endif

#  ifndef MCU_FAILSAFE_STACK_UNDERFLOW_RESET_REASON
#   define MCU_FAILSAFE_STACK_UNDERFLOW_RESET_REASON (27U)
#  endif

#  ifndef MCU_FAILSAFE_WDG_RESET_REASON
#   define MCU_FAILSAFE_WDG_RESET_REASON (28U)
#  endif

#  ifndef MCU_FAILSAFE_HSM_WDT_RESET_REASON
#   define MCU_FAILSAFE_HSM_WDT_RESET_REASON (29U)
#  endif

#  ifndef MCU_FAILSAFE_CORESELF_TEST_RESET_REASON
#   define MCU_FAILSAFE_CORESELF_TEST_RESET_REASON (30U)
#  endif

#  ifndef MCU_FAILSAFE_CRC_REGISTER_TEST_RESET_REASON
#   define MCU_FAILSAFE_CRC_REGISTER_TEST_RESET_REASON (31U)
#  endif

#  ifndef MCU_FAILSAFE_EXR_RESET
#   define MCU_FAILSAFE_EXR_RESET (32U)
#  endif

#  ifndef MCU_FAILSAFE_NO_RESET_REASON
#   define MCU_FAILSAFE_NO_RESET_REASON (33U)
#  endif

#  ifndef MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION
#   define MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION (34U)
#  endif

#  ifndef MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION
#   define MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION (35U)
#  endif

#  ifndef MCU_FAILSAFE_ABORT_DATA_EXCEPTION
#   define MCU_FAILSAFE_ABORT_DATA_EXCEPTION (36U)
#  endif

#  ifndef OS_PANICHOOK
#   define OS_PANICHOOK (37U)
#  endif

#  ifndef MCU_FAILSAFE_DSP_CLK_FAILURE
#   define MCU_FAILSAFE_DSP_CLK_FAILURE (38U)
#  endif

#  ifndef MCU_FAILSAFE_RA_CLK_FAILURE
#   define MCU_FAILSAFE_RA_CLK_FAILURE (39U)
#  endif

#  ifndef MCU_FAILSAFE_MIPI_CLK_FAILURE
#   define MCU_FAILSAFE_MIPI_CLK_FAILURE (40U)
#  endif

#  ifndef MCU_FAILSAFE_SERIAL_CLK_FAILURE
#   define MCU_FAILSAFE_SERIAL_CLK_FAILURE (41U)
#  endif

#  ifndef MCU_FAILSAFE_MARS_API_FAILURE
#   define MCU_FAILSAFE_MARS_API_FAILURE (42U)
#  endif

#  ifndef MCU_FAILSAFE_RMON_RA_FAILURE
#   define MCU_FAILSAFE_RMON_RA_FAILURE (43U)
#  endif

#  ifndef MCU_FAILSAFE_RMON_MIPI_FAILURE
#   define MCU_FAILSAFE_RMON_MIPI_FAILURE (44U)
#  endif

#  ifndef MCU_FAILSAFE_RMON_DSP_FAILURE
#   define MCU_FAILSAFE_RMON_DSP_FAILURE (45U)
#  endif

#  ifndef MCU_FAILSAFE_RMON_REF_FAILURE
#   define MCU_FAILSAFE_RMON_REF_FAILURE (46U)
#  endif

#  ifndef MCU_FAILSAFE_RMON_SER_FAILURE
#   define MCU_FAILSAFE_RMON_SER_FAILURE (47U)
#  endif

#  ifndef RESERVE_15
#   define RESERVE_15 (48U)
#  endif

#  ifndef RESERVE_16
#   define RESERVE_16 (49U)
#  endif

#  ifndef RESERVE_17
#   define RESERVE_17 (50U)
#  endif

#  ifndef RESERVE_18
#   define RESERVE_18 (51U)
#  endif

#  ifndef RESERVE_19
#   define RESERVE_19 (52U)
#  endif

#  ifndef RESERVE_20
#   define RESERVE_20 (53U)
#  endif

#  ifndef RESERVE_21
#   define RESERVE_21 (54U)
#  endif

#  ifndef RESERVE_22
#   define RESERVE_22 (55U)
#  endif

#  ifndef RESERVE_23
#   define RESERVE_23 (56U)
#  endif

#  ifndef RESERVE_24
#   define RESERVE_24 (57U)
#  endif

#  ifndef RESERVE_25
#   define RESERVE_25 (58U)
#  endif

#  ifndef RESERVE_26
#   define RESERVE_26 (59U)
#  endif

#  ifndef RESERVE_27
#   define RESERVE_27 (60U)
#  endif

#  ifndef RESERVE_28
#   define RESERVE_28 (61U)
#  endif

#  ifndef RESERVE_29
#   define RESERVE_29 (62U)
#  endif

#  ifndef RESERVE_30
#   define RESERVE_30 (63U)
#  endif

#  ifndef RESERVE_31
#   define RESERVE_31 (64U)
#  endif

#  ifndef RESERVE_32
#   define RESERVE_32 (65U)
#  endif

#  ifndef RESERVE_33
#   define RESERVE_33 (66U)
#  endif

#  ifndef RESERVE_34
#   define RESERVE_34 (67U)
#  endif

#  ifndef RESERVE_35
#   define RESERVE_35 (68U)
#  endif

#  ifndef RESERVE_36
#   define RESERVE_36 (69U)
#  endif

#  ifndef RESERVE_37
#   define RESERVE_37 (70U)
#  endif

#  ifndef RESERVE_38
#   define RESERVE_38 (71U)
#  endif

#  ifndef RESERVE_39
#   define RESERVE_39 (72U)
#  endif

#  ifndef RESERVE_40
#   define RESERVE_40 (73U)
#  endif

#  ifndef RESERVE_41
#   define RESERVE_41 (74U)
#  endif

#  ifndef RESERVE_42
#   define RESERVE_42 (75U)
#  endif

#  ifndef RESERVE_43
#   define RESERVE_43 (76U)
#  endif

#  ifndef RESERVE_44
#   define RESERVE_44 (77U)
#  endif

#  ifndef RESERVE_45
#   define RESERVE_45 (78U)
#  endif

#  ifndef RESERVE_46
#   define RESERVE_46 (79U)
#  endif

#  ifndef RESERVE_47
#   define RESERVE_47 (80U)
#  endif

#  ifndef FAILSAFE_SM_090_SYSMEM0
#   define FAILSAFE_SM_090_SYSMEM0 (81U)
#  endif

#  ifndef FAILSAFE_SM_090_SYSMEM1
#   define FAILSAFE_SM_090_SYSMEM1 (82U)
#  endif

#  ifndef FAILSAFE_SM_05_ARTIEMEM_ECC
#   define FAILSAFE_SM_05_ARTIEMEM_ECC (83U)
#  endif

#  ifndef MCU_PVT_TEMPERATURE_DEVIATION_RESET
#   define MCU_PVT_TEMPERATURE_DEVIATION_RESET (84U)
#  endif

#  ifndef RESERVE_52
#   define RESERVE_52 (85U)
#  endif

#  ifndef RESERVE_53
#   define RESERVE_53 (86U)
#  endif

#  ifndef RESERVE_54
#   define RESERVE_54 (87U)
#  endif

#  ifndef RESERVE_55
#   define RESERVE_55 (88U)
#  endif

#  ifndef RESERVE_56
#   define RESERVE_56 (89U)
#  endif

#  ifndef RESERVE_57
#   define RESERVE_57 (90U)
#  endif

#  ifndef RESERVE_58
#   define RESERVE_58 (91U)
#  endif

#  ifndef RESERVE_59
#   define RESERVE_59 (92U)
#  endif

#  ifndef RESERVE_60
#   define RESERVE_60 (93U)
#  endif

#  ifndef RESERVE_61
#   define RESERVE_61 (94U)
#  endif

#  ifndef RESERVE_62
#   define RESERVE_62 (95U)
#  endif

#  ifndef RESERVE_63
#   define RESERVE_63 (96U)
#  endif

#  ifndef RESERVE_64
#   define RESERVE_64 (97U)
#  endif

#  ifndef RESERVE_65
#   define RESERVE_65 (98U)
#  endif

#  ifndef RESERVE_66
#   define RESERVE_66 (99U)
#  endif

#  ifndef MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD
#   define MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD (100U)
#  endif

#  ifndef MCU_FCRU_FAULT_1_UNDERVOLTAGE_VDDIO
#   define MCU_FCRU_FAULT_1_UNDERVOLTAGE_VDDIO (101U)
#  endif

#  ifndef MCU_FCRU_FAULT_2_CLOCK_MONITOR_FAILURE
#   define MCU_FCRU_FAULT_2_CLOCK_MONITOR_FAILURE (102U)
#  endif

#  ifndef MCU_FCRU_FAULT_3_PLL_LOCK_LOST
#   define MCU_FCRU_FAULT_3_PLL_LOCK_LOST (103U)
#  endif

#  ifndef MCU_FCRU_FAULT_4_PVT0_TEMP_ALARM
#   define MCU_FCRU_FAULT_4_PVT0_TEMP_ALARM (104U)
#  endif

#  ifndef MCU_FCRU_FAULT_5_PVT1_TEMP_ALARM
#   define MCU_FCRU_FAULT_5_PVT1_TEMP_ALARM (105U)
#  endif

#  ifndef MCU_FCRU_FAULT_6_BIST_FAILURE
#   define MCU_FCRU_FAULT_6_BIST_FAILURE (106U)
#  endif

#  ifndef MCU_FCRU_FAULT_7_WDG_TIMEOUT
#   define MCU_FCRU_FAULT_7_WDG_TIMEOUT (107U)
#  endif

#  ifndef MCU_FCRU_FAULT_8_LOCKSTEP_FAIL_0
#   define MCU_FCRU_FAULT_8_LOCKSTEP_FAIL_0 (108U)
#  endif

#  ifndef MCU_FCRU_FAULT_9_LOCKSTEP_FAIL_1
#   define MCU_FCRU_FAULT_9_LOCKSTEP_FAIL_1 (109U)
#  endif

#  ifndef MCU_FCRU_FAULT_10_LOCKSTEP_FAIL_2
#   define MCU_FCRU_FAULT_10_LOCKSTEP_FAIL_2 (110U)
#  endif

#  ifndef MCU_FCRU_FAULT_11_LOCKSTEP_FAIL_3
#   define MCU_FCRU_FAULT_11_LOCKSTEP_FAIL_3 (111U)
#  endif

#  ifndef MCU_FCRU_FAULT_12_LOCKSTEP_FAIL_4
#   define MCU_FCRU_FAULT_12_LOCKSTEP_FAIL_4 (112U)
#  endif

#  ifndef MCU_FCRU_FAULT_13_LOCKSTEP_FAIL_5
#   define MCU_FCRU_FAULT_13_LOCKSTEP_FAIL_5 (113U)
#  endif

#  ifndef MCU_FCRU_FAULT_14_LOCKSTEP_FAIL_6
#   define MCU_FCRU_FAULT_14_LOCKSTEP_FAIL_6 (114U)
#  endif

#  ifndef MCU_FCRU_FAULT_15_LOCKSTEP_FAIL_7
#   define MCU_FCRU_FAULT_15_LOCKSTEP_FAIL_7 (115U)
#  endif

#  ifndef MCU_FCRU_FAULT_16_LOCKSTEP_FAIL_8
#   define MCU_FCRU_FAULT_16_LOCKSTEP_FAIL_8 (116U)
#  endif

#  ifndef MCU_FCRU_FAULT_17_LOCKSTEP_FAIL_9
#   define MCU_FCRU_FAULT_17_LOCKSTEP_FAIL_9 (117U)
#  endif

#  ifndef MCU_FCRU_FAULT_18_LOCKSTEP_FAIL_10
#   define MCU_FCRU_FAULT_18_LOCKSTEP_FAIL_10 (118U)
#  endif

#  ifndef MCU_FCRU_FAULT_19_LOCKSTEP_FAIL_11
#   define MCU_FCRU_FAULT_19_LOCKSTEP_FAIL_11 (119U)
#  endif

#  ifndef MCU_FCRU_FAULT_20_LOCKSTEP_FAIL_12
#   define MCU_FCRU_FAULT_20_LOCKSTEP_FAIL_12 (120U)
#  endif

#  ifndef MCU_FCRU_FAULT_21_LOCKSTEP_FAIL_13
#   define MCU_FCRU_FAULT_21_LOCKSTEP_FAIL_13 (121U)
#  endif

#  ifndef MCU_FCRU_FAULT_22_LOCKSTEP_FAIL_14
#   define MCU_FCRU_FAULT_22_LOCKSTEP_FAIL_14 (122U)
#  endif

#  ifndef MCU_FCRU_FAULT_23_LOCKSTEP_FAIL_15
#   define MCU_FCRU_FAULT_23_LOCKSTEP_FAIL_15 (123U)
#  endif

#  ifndef MCU_FCRU_FAULT_24_LOCKSTEP_FAIL_16
#   define MCU_FCRU_FAULT_24_LOCKSTEP_FAIL_16 (124U)
#  endif

#  ifndef MCU_FCRU_FAULT_25_LOCKSTEP_FAIL_17
#   define MCU_FCRU_FAULT_25_LOCKSTEP_FAIL_17 (125U)
#  endif

#  ifndef MCU_FCRU_FAULT_26_AXIS_DATA_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_26_AXIS_DATA_ERROR_CORRECTABLE (126U)
#  endif

#  ifndef MCU_FCRU_FAULT_27_AXIS_DATA_ERROR_UNCORRECTABLE
#   define MCU_FCRU_FAULT_27_AXIS_DATA_ERROR_UNCORRECTABLE (127U)
#  endif

#  ifndef MCU_FCRU_FAULT_28_AXIS_HANDSHAKE_ERROR_FATAL
#   define MCU_FCRU_FAULT_28_AXIS_HANDSHAKE_ERROR_FATAL (128U)
#  endif

#  ifndef MCU_FCRU_FAULT_29_AXIS_DATA_ERROR_FATAL
#   define MCU_FCRU_FAULT_29_AXIS_DATA_ERROR_FATAL (129U)
#  endif

#  ifndef MCU_FCRU_FAULT_30_AXIS_CONTROL_ERROR_FATAL
#   define MCU_FCRU_FAULT_30_AXIS_CONTROL_ERROR_FATAL (130U)
#  endif

#  ifndef MCU_FCRU_FAULT_31_L1_CACHE_TCM_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_31_L1_CACHE_TCM_ERROR_CORRECTABLE (131U)
#  endif

#  ifndef MCU_FCRU_FAULT_32_TCM_MEMORY_ERROR_FATAL
#   define MCU_FCRU_FAULT_32_TCM_MEMORY_ERROR_FATAL (132U)
#  endif

#  ifndef MCU_FCRU_FAULT_33_AXIM_DATA_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_33_AXIM_DATA_ERROR_CORRECTABLE (133U)
#  endif

#  ifndef MCU_FCRU_FAULT_34_AXIM_DATA_ERROR_FATAL
#   define MCU_FCRU_FAULT_34_AXIM_DATA_ERROR_FATAL (134U)
#  endif

#  ifndef MCU_FCRU_FAULT_35_AXIM_HANDSHAKE_ERROR_FATAL
#   define MCU_FCRU_FAULT_35_AXIM_HANDSHAKE_ERROR_FATAL (135U)
#  endif

#  ifndef MCU_FCRU_FAULT_36_AXIM_DATA_ERROR_FATAL_DUP
#   define MCU_FCRU_FAULT_36_AXIM_DATA_ERROR_FATAL_DUP (136U)
#  endif

#  ifndef MCU_FCRU_FAULT_37_AXIM_CONTROL_ERROR_FATAL
#   define MCU_FCRU_FAULT_37_AXIM_CONTROL_ERROR_FATAL (137U)
#  endif

#  ifndef MCU_FCRU_FAULT_38_L1_ICACHE_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_38_L1_ICACHE_ERROR_CORRECTABLE (138U)
#  endif

#  ifndef MCU_FCRU_FAULT_39_L1_DCACHE_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_39_L1_DCACHE_ERROR_CORRECTABLE (139U)
#  endif

#  ifndef MCU_FCRU_FAULT_40_TCM_ERROR_CORRECTABLE
#   define MCU_FCRU_FAULT_40_TCM_ERROR_CORRECTABLE (140U)
#  endif

#  ifndef MCU_FCRU_FAULT_41_TCM_ERROR_FATAL
#   define MCU_FCRU_FAULT_41_TCM_ERROR_FATAL (141U)
#  endif

#  ifndef MCU_FCRU_FAULT_42_AXIM_TIMEOUT
#   define MCU_FCRU_FAULT_42_AXIM_TIMEOUT (142U)
#  endif

#  ifndef MCU_FCRU_FAULT_43_L1_CACHE_TCM_ERROR_CORRECTABLE_DUP
#   define MCU_FCRU_FAULT_43_L1_CACHE_TCM_ERROR_CORRECTABLE_DUP (143U)
#  endif

#  ifndef MCU_FCRU_FAULT_44_L1_TCM_ERROR_FATAL
#   define MCU_FCRU_FAULT_44_L1_TCM_ERROR_FATAL (144U)
#  endif

#  ifndef MCU_FCRU_FAULT_45_HYPERVISOR_INTERRUPT_TIMEOUT
#   define MCU_FCRU_FAULT_45_HYPERVISOR_INTERRUPT_TIMEOUT (145U)
#  endif

#  ifndef MCU_FCRU_FAULT_46_HYPERVISOR_MEMORY_BUS_ERROR_FATAL
#   define MCU_FCRU_FAULT_46_HYPERVISOR_MEMORY_BUS_ERROR_FATAL (146U)
#  endif

#  ifndef MCU_FCRU_FAULT_47_EL2_MPU_VIOLATION
#   define MCU_FCRU_FAULT_47_EL2_MPU_VIOLATION (147U)
#  endif

#  ifndef MCU_FCRU_FAULT_48_EL1_MPU_VIOLATION
#   define MCU_FCRU_FAULT_48_EL1_MPU_VIOLATION (148U)
#  endif

#  ifndef MCU_FCRU_FAULT_49_INTERNAL_EXCEPTION
#   define MCU_FCRU_FAULT_49_INTERNAL_EXCEPTION (149U)
#  endif

#  ifndef MCU_FCRU_FAULT_50_EL1_EL2_MPU_CONFLICT
#   define MCU_FCRU_FAULT_50_EL1_EL2_MPU_CONFLICT (150U)
#  endif

#  ifndef MCU_FCRU_FAULT_51_LIVELOCK_HARD_ERROR
#   define MCU_FCRU_FAULT_51_LIVELOCK_HARD_ERROR (151U)
#  endif

#  ifndef MCU_FCRU_FAULT_52_EL2_IMP_TESTR1_UNLOCKED
#   define MCU_FCRU_FAULT_52_EL2_IMP_TESTR1_UNLOCKED (152U)
#  endif

#  ifndef MCU_FCRU_FAULT_53_RT640_SAFETY_ERROR
#   define MCU_FCRU_FAULT_53_RT640_SAFETY_ERROR (153U)
#  endif

#  ifndef MCU_FCRU_FAULT_54_OTP_READ_FAILURE
#   define MCU_FCRU_FAULT_54_OTP_READ_FAILURE (154U)
#  endif

#  ifndef MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT
#   define MCU_FCRU_FAULT_55_ARTIE_NOC_FAULT (155U)
#  endif

#  ifndef RESERVE_67
#   define RESERVE_67 (156U)
#  endif

#  ifndef MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT
#   define MCU_FCRU_FAULT_57_CHANDRA_NOC_FAULT (157U)
#  endif

#  ifndef MCU_FCRU_FAULT_58_SMALL_NOC_FAULT
#   define MCU_FCRU_FAULT_58_SMALL_NOC_FAULT (158U)
#  endif

#  ifndef RESERVE_68
#   define RESERVE_68 (159U)
#  endif

#  ifndef RESERVE_69
#   define RESERVE_69 (160U)
#  endif

#  ifndef MCU_FCRU_FAULT_61_SYSTEM_RESET_FAULT
#   define MCU_FCRU_FAULT_61_SYSTEM_RESET_FAULT (161U)
#  endif

#  ifndef MCU_FCRU_FAULT_62_CORE_RESET_FAULT
#   define MCU_FCRU_FAULT_62_CORE_RESET_FAULT (162U)
#  endif

#  ifndef MCU_FCRU_FAULT_63_TOP_RESET_FAULT
#   define MCU_FCRU_FAULT_63_TOP_RESET_FAULT (163U)
#  endif

#  ifndef FAILSAFE_SM_010_CSI2_CRC
#   define FAILSAFE_SM_010_CSI2_CRC (200U)
#  endif

#  ifndef FAILSAFE_SM_011_CSI2_ECC
#   define FAILSAFE_SM_011_CSI2_ECC (201U)
#  endif

#  ifndef FAILSAFE_SM_012_CSI2_INTERNALSTATECHECK
#   define FAILSAFE_SM_012_CSI2_INTERNALSTATECHECK (202U)
#  endif

#  ifndef FAILSAFE_SM_013_CSI2_PIXEL_PARITY
#   define FAILSAFE_SM_013_CSI2_PIXEL_PARITY (203U)
#  endif

#  ifndef FAILSAFE_SM_014_CSI2_WDT
#   define FAILSAFE_SM_014_CSI2_WDT (204U)
#  endif

#  ifndef FAILSAFE_SM_016_DSP_AHB_S_PARITY
#   define FAILSAFE_SM_016_DSP_AHB_S_PARITY (205U)
#  endif

#  ifndef FAILSAFE_SM_017_DSP_AXI_ECC
#   define FAILSAFE_SM_017_DSP_AXI_ECC (206U)
#  endif

#  ifndef FAILSAFE_SM_018_DSP_CSR_PARITY
#   define FAILSAFE_SM_018_DSP_CSR_PARITY (207U)
#  endif

#  ifndef FAILSAFE_SM_019_DSP_DCACHE_ECC
#   define FAILSAFE_SM_019_DSP_DCACHE_ECC (208U)
#  endif

#  ifndef FAILSAFE_SM_020_DSP_DRAM_ECC
#   define FAILSAFE_SM_020_DSP_DRAM_ECC (209U)
#  endif

#  ifndef FAILSAFE_SM_021_DSP_ICACHE_ECC
#   define FAILSAFE_SM_021_DSP_ICACHE_ECC (210U)
#  endif

#  ifndef FAILSAFE_SM_022_DSP_IRAM_ECC
#   define FAILSAFE_SM_022_DSP_IRAM_ECC (211U)
#  endif

#  ifndef FAILSAFE_SM_043_MIPI_AHB_S_PARITY
#   define FAILSAFE_SM_043_MIPI_AHB_S_PARITY (212U)
#  endif

#  ifndef FAILSAFE_SM_044_MIPI_APB_S_PARITY
#   define FAILSAFE_SM_044_MIPI_APB_S_PARITY (213U)
#  endif

#  ifndef FAILSAFE_SM_045_MIPI_IDM_MEM_ECC
#   define FAILSAFE_SM_045_MIPI_IDM_MEM_ECC (214U)
#  endif

#  ifndef FAILSAFE_SM_046_MIPI_META_OVERFLOW
#   define FAILSAFE_SM_046_MIPI_META_OVERFLOW (215U)
#  endif

#  ifndef FAILSAFE_SM_047_MIPI_OCP_S_PARITY
#   define FAILSAFE_SM_047_MIPI_OCP_S_PARITY (216U)
#  endif

#  ifndef FAILSAFE_SM_048_MIPI_PP_MEM_ECC
#   define FAILSAFE_SM_048_MIPI_PP_MEM_ECC (217U)
#  endif

#  ifndef FAILSAFE_SM_049_MIPI_PP_OVERFLOW
#   define FAILSAFE_SM_049_MIPI_PP_OVERFLOW (218U)
#  endif

#  ifndef FAILSAFE_SM_050_MIPI_PP_UNDERFLOW
#   define FAILSAFE_SM_050_MIPI_PP_UNDERFLOW (219U)
#  endif

#  ifndef FAILSAFE_SM_051_MIPI_TB_MEM_ECC
#   define FAILSAFE_SM_051_MIPI_TB_MEM_ECC (220U)
#  endif

#  ifndef FAILSAFE_SM_02_NOC_AA
#   define FAILSAFE_SM_02_NOC_AA (221U)
#  endif

#  ifndef FAILSAFE_SM_02_AA_NOC
#   define FAILSAFE_SM_02_AA_NOC (222U)
#  endif

#  ifndef FAILSAFE_SM_03_AA_MEM_ECC
#   define FAILSAFE_SM_03_AA_MEM_ECC (223U)
#  endif

#  ifndef RESERVE_73
#   define RESERVE_73 (224U)
#  endif

#  ifndef RESERVE_74
#   define RESERVE_74 (225U)
#  endif

#  ifndef RESERVE_75
#   define RESERVE_75 (226U)
#  endif

#  ifndef RESERVE_76
#   define RESERVE_76 (227U)
#  endif

#  ifndef RESERVE_77
#   define RESERVE_77 (228U)
#  endif

#  ifndef RESERVE_78
#   define RESERVE_78 (229U)
#  endif

#  ifndef RESERVE_79
#   define RESERVE_79 (230U)
#  endif

#  ifndef RESERVE_80
#   define RESERVE_80 (231U)
#  endif

#  ifndef RESERVE_81
#   define RESERVE_81 (232U)
#  endif

#  ifndef RESERVE_82
#   define RESERVE_82 (233U)
#  endif

#  ifndef RESERVE_83
#   define RESERVE_83 (234U)
#  endif

#  ifndef RESERVE_84
#   define RESERVE_84 (235U)
#  endif

#  ifndef RESERVE_85
#   define RESERVE_85 (236U)
#  endif

#  ifndef RESERVE_86
#   define RESERVE_86 (237U)
#  endif

#  ifndef RESERVE_87
#   define RESERVE_87 (238U)
#  endif

#  ifndef RESERVE_88
#   define RESERVE_88 (239U)
#  endif

#  ifndef RESERVE_89
#   define RESERVE_89 (240U)
#  endif

#  ifndef OS_SYS_DISABLED
#   define OS_SYS_DISABLED (241U)
#  endif

#  ifndef OS_SYS_NO_BARRIER_PARTICIPANT
#   define OS_SYS_NO_BARRIER_PARTICIPANT (242U)
#  endif

#  ifndef OS_SYS_UNIMPLEMENTED_FUNCTIONALITY
#   define OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (243U)
#  endif

#  ifndef OS_SYS_NO_NTFSTACK
#   define OS_SYS_NO_NTFSTACK (244U)
#  endif

#  ifndef OS_SYS_OVERFLOW
#   define OS_SYS_OVERFLOW (245U)
#  endif

#  ifndef OS_SYS_KILL_KERNEL_OBJ
#   define OS_SYS_KILL_KERNEL_OBJ (246U)
#  endif

#  ifndef OS_SYS_NO_RESTARTTASK
#   define OS_SYS_NO_RESTARTTASK (247U)
#  endif

#  ifndef OS_SYS_CALL_NOT_ALLOWED
#   define OS_SYS_CALL_NOT_ALLOWED (248U)
#  endif

#  ifndef OS_SYS_FUNCTION_UNAVAILABLE
#   define OS_SYS_FUNCTION_UNAVAILABLE (249U)
#  endif

#  ifndef OS_SYS_PROTECTION_SYSCALL
#   define OS_SYS_PROTECTION_SYSCALL (250U)
#  endif

#  ifndef OS_SYS_PROTECTION_IRQ
#   define OS_SYS_PROTECTION_IRQ (251U)
#  endif

#  ifndef OS_SYS_API_ERROR
#   define OS_SYS_API_ERROR (252U)
#  endif

#  ifndef OS_SYS_ASSERTION
#   define OS_SYS_ASSERTION (253U)
#  endif

#  ifndef OS_SYS_OVERLOAD
#   define OS_SYS_OVERLOAD (254U)
#  endif

#  ifndef OS_SYS_CROSS_CORE_REQUESTED
#   define OS_SYS_CROSS_CORE_REQUESTED (255U)
#  endif
#  ifndef SMC_CHECKSUM_FAULT
#   define SMC_CHECKSUM_FAULT (0U)
#  endif

#  ifndef USC_VALIDATION_FAULT
#   define USC_VALIDATION_FAULT (1U)
#  endif

#  ifndef MMIC_B_ID_FAULT
#   define MMIC_B_ID_FAULT (2U)
#  endif

#  ifndef MMIC_TEMPERATURE_HIGH_FAULT
#   define MMIC_TEMPERATURE_HIGH_FAULT (3U)
#  endif

#  ifndef MMIC_TEMPERATURE_LOW_FAULT
#   define MMIC_TEMPERATURE_LOW_FAULT (4U)
#  endif

#  ifndef MMIC_A_SAFESTART
#   define MMIC_A_SAFESTART (5U)
#  endif

#  ifndef MMIC_B_SAFESTART
#   define MMIC_B_SAFESTART (6U)
#  endif

#  ifndef MMIC_A_SAFETY_INTEGRITY_RFBIST
#   define MMIC_A_SAFETY_INTEGRITY_RFBIST (7U)
#  endif

#  ifndef MMIC_A_SENSOR_FAULT
#   define MMIC_A_SENSOR_FAULT (8U)
#  endif

#  ifndef MMIC_TEMPERATURE_CONSISTANCY_FAILURE
#   define MMIC_TEMPERATURE_CONSISTANCY_FAILURE (9U)
#  endif

#  ifndef PLATFORM_TIME_FAULT
#   define PLATFORM_TIME_FAULT (10U)
#  endif

#  ifndef TX_BALL_BREAK_FAULT
#   define TX_BALL_BREAK_FAULT (11U)
#  endif

#  ifndef BLOCKAGE_ALGO_ERROR_FAULT
#   define BLOCKAGE_ALGO_ERROR_FAULT (12U)
#  endif

#  ifndef MCU_STARTUP_FAULT
#   define MCU_STARTUP_FAULT (13U)
#  endif

#  ifndef MCU_REPETATIVE_RESET_FAULT
#   define MCU_REPETATIVE_RESET_FAULT (14U)
#  endif

#  ifndef A53_TO_CM7_IPC_FAULT
#   define A53_TO_CM7_IPC_FAULT (15U)
#  endif

#  ifndef CM7_TO_DSP_IPC_FAULT
#   define CM7_TO_DSP_IPC_FAULT (16U)
#  endif

#  ifndef EDMA_FAULT_CALIBRATION
#   define EDMA_FAULT_CALIBRATION (17U)
#  endif

#  ifndef DSP_TO_A53_IPC_FAULT
#   define DSP_TO_A53_IPC_FAULT (18U)
#  endif

#  ifndef DSP_TO_CM7_IPC_FAULT
#   define DSP_TO_CM7_IPC_FAULT (19U)
#  endif

#  ifndef MAX_FAULT_NUMBER
#   define MAX_FAULT_NUMBER (20U)
#  endif
#  ifndef INVALID
#   define INVALID (0U)
#  endif

#  ifndef CDD_FAIL_SAFE
#   define CDD_FAIL_SAFE (1U)
#  endif

#  ifndef CDD_ESM
#   define CDD_ESM (2U)
#  endif

#  ifndef APPL_DIAG
#   define APPL_DIAG (3U)
#  endif

#  ifndef CDD_ALIGNMENT
#   define CDD_ALIGNMENT (4U)
#  endif

#  ifndef DYNAMIC_ALIGNMENT
#   define DYNAMIC_ALIGNMENT (5U)
#  endif

#  ifndef RFE_R1R2_FAULT
#   define RFE_R1R2_FAULT (6U)
#  endif

#  ifndef CDD_FAILSAFE_ECC
#   define CDD_FAILSAFE_ECC (7U)
#  endif

#  ifndef CDD_SENSORPOS
#   define CDD_SENSORPOS (8U)
#  endif

#  ifndef UDS_MANUAL_ALIGNMENT
#   define UDS_MANUAL_ALIGNMENT (9U)
#  endif

#  ifndef UDS_STATIC_ALIGNMENT
#   define UDS_STATIC_ALIGNMENT (10U)
#  endif
#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_FAILSAFE_TYPE_H */
