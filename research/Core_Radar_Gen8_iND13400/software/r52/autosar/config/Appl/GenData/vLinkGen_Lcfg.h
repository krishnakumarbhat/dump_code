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
 *            Module: vLinkGen
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Lcfg.h
 *   Generation Time: 2026-08-24 12:05:29
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
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_DATA_CORE0_VAR[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_DATA_SHARED_VAR[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_GLOBALSHARED_VAR[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_GLOBALSHARED_VAR_SAVED_ZONE[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore0_ASIL_VAR[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore0_ASIL_VAR_SAVED_ZONE[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore_Qm_VAR[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03000 - Invalid logical group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore_Qm_VAR_SAVED_ZONE[0:vLinkGenVarGroupRomRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRomRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_CODE[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_EXCVEC_CORE0_CODE[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_EXCVEC_CORE0_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_GLOBALSHARED_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_INTVEC_CODE[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_INTVEC_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_INTVEC_CORE0_CODE[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_INTVEC_CORE0_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_USER_CODE[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03100 - Invalid logical CONST group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_SYSMEM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_USER_CONST[0:vLinkGenConstGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalConstGroup/vLinkGenConstGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_DATA_CORE0_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_DATA_SHARED_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_GLOBALSHARED_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_GLOBALSHARED_VAR_SAVED_ZONE[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore0_ASIL_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore0_ASIL_VAR_SAVED_ZONE[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore_Qm_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_OsCore_Qm_VAR_SAVED_ZONE[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_BackgroundTask_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_IPC_Task_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_Task_Communication_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_Task_Fast_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_Task_High_Prio_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_Task_Logging_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Appl_Task_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_BSW_Task_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Error_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Init_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Isr_Core_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Kernel_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Protection_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Shutdown_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Startup_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Task_Prio0_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Task_Prio190_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Task_Prio200_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Task_Prio210_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_OsCore0_Task_Prio4294967295_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 * 
 * [Warning] VLINKGEN03200 - Invalid logical VAR group configuration 
 * - [Reduced Severity due to User-Defined Parameter] Due to the specified meta data (Content Type, Core Id), an available memory region block ( /ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_RAM/SYSTEM_RAM) was found which is set automatically. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/vLinkGen/vLinkGenMemLayout/OS_STACK_Radar_Ctrl_Task_VAR[0:vLinkGenVarGroupRegion](value=/ActiveEcuC/vLinkGen/vLinkGenMemLayout/SYSTEM_ROM/R52_TCM_STACK) (DefRef: /MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenLogicalVarGroup/vLinkGenVarGroupRegion)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#ifndef VLINKGEN_LCFG_H
# define VLINKGEN_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "vLinkGen_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Definition of a generic memory area to be initialized. */
typedef struct
{
  /*! Start address of the memory area. */
  uint32 Start;
  /*! End address of the memory area. */
  uint32 End;
  /*! Core ID to perform the initialization. */
  uint32 Core;
  /*! ECC alignment of memory area in bytes. */
  uint32 Alignment;
} vLinkGen_MemArea;

/*! Definition of a generic initialization set. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint32 Num;
  /*! Table of generic memory areas. */
  const vLinkGen_MemArea *Areas;
} vLinkGen_MemAreaSet;

/*! Definition of a RAM memory area to be initialized with concrete data from ROM. */
typedef struct
{
  /*! Start address of the RAM memory area. */
  uint32 Start;
  /*! End address of the RAM memory area. */
  uint32 End;
  /*! Start address of the ROM memory area containing the init data. */
  uint32 Romstart;
  /*! End address of the ROM memory area containing the init data. */
  uint32 Romend;
  /*! Core ID to perform the initialization. */
  uint32 Core;
  /*! ECC alignment of memory area in bytes. */
  uint32 Alignment;
} vLinkGen_RamMemArea;

/*! Definition of a ROM to RAM initialization set. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint32 Num;
  /*! Table of ROM to RAM memory areas. */
  const vLinkGen_RamMemArea *Areas;
} vLinkGen_RamMemAreaSet;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* Extern declarations of start/limit address labels. */
extern uint8 _OS_DATA_CORE0_VAR_CLEARED_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_CLEARED_START[]; 
extern uint8 _OS_DATA_CORE0_VAR_INIT_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_INIT_ROM_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_INIT_ROM_START[]; 
extern uint8 _OS_DATA_CORE0_VAR_INIT_START[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_DATA_CORE0_VAR_POWER_ON_INIT_START[]; 
extern uint8 _OS_DATA_SHARED_VAR_CLEARED_LIMIT[]; 
extern uint8 _OS_DATA_SHARED_VAR_CLEARED_START[]; 
extern uint8 _OS_DATA_SHARED_VAR_INIT_LIMIT[]; 
extern uint8 _OS_DATA_SHARED_VAR_INIT_ROM_LIMIT[]; 
extern uint8 _OS_DATA_SHARED_VAR_INIT_ROM_START[]; 
extern uint8 _OS_DATA_SHARED_VAR_INIT_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_CLEARED_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_CLEARED_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_INIT_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_INIT_ROM_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_INIT_ROM_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_INIT_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_POWER_ON_INIT_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_GLOBALSHARED_VAR_SAVED_ZONE_POWER_ON_INIT_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_CLEARED_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_INIT_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_INIT_ROM_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_INIT_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_POWER_ON_INIT_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_OsCore0_ASIL_VAR_SAVED_ZONE_POWER_ON_INIT_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_CLEARED_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_INIT_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_INIT_ROM_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_INIT_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_POWER_ON_INIT_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_CLEARED_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_CLEARED_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_INIT_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_LIMIT[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_INIT_ROM_START[]; 
extern uint8 _OS_OsCore_Qm_VAR_SAVED_ZONE_POWER_ON_INIT_START[]; 

/* Extern declarations of initialization tables. */
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_One_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_PowerOn_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_POWER_ON_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_PowerOn_Groups[VLINKGEN_CFG_NUM_INIT_POWER_ON_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS]; 

/* Extern declarations of initialization structures. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_PowerOn_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Three_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Two_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Zero_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_HardReset_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_One_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_PowerOn_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Three_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Two_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Zero_GroupsSet; 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VLINKGEN_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Lcfg.h
 *********************************************************************************************************************/
