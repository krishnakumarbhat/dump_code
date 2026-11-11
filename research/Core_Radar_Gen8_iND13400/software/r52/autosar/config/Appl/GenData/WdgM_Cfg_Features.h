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
 *            Module: WdgM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg_Features.h
 *   Generation Time: 2026-07-13 09:03:33
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
#if !defined (WDGM_CFG_FEATURES_H)
# define WDGM_CFG_FEATURES_H

/**********************************************************************************************************************
 *  AUTOSAR feature defines
 *********************************************************************************************************************/
# define WDGM_VERSION_INFO_API                STD_OFF 
# define WDGM_DEV_ERROR_DETECT                STD_ON 
# define WDGM_DEFENSIVE_BEHAVIOR              STD_OFF 
# define WDGM_IMMEDIATE_RESET                 STD_ON 
# define WDGM_OFF_MODE_ENABLED                STD_ON 


/**********************************************************************************************************************
 *  WDGM-specific feature defines (user-defined)
 *********************************************************************************************************************/
# define WDGM_USE_OS_SUSPEND_INTERRUPT        STD_ON 
# define WDGM_TIMEBASE_SOURCE         WDGM_INTERNAL_SOFTWARE_TICK 
# define WDGM_SECOND_RESET_PATH               STD_ON 
# define WDGM_TICK_OVERRUN_CORRECTION         STD_OFF 
# define WDGM_ENTITY_DEACTIVATION_ENABLED     STD_ON 
# define WDGM_STATUS_REPORTING_MECHANISM WDGM_USE_MODE_SWITCH_PORTS 
# define WDGM_USE_RTE                         STD_ON 
# define WDGM_DEM_SUPERVISION_REPORT          STD_OFF 
# define WDGM_FIRSTCYCLE_ALIVECOUNTER_RESET   STD_OFF 
# define WDGM_AUTOSAR_DEBUGGING               STD_OFF 
# define WDGM_DEM_REPORT                      STD_OFF 
# define WDGM_NOTIFY_DETECTED_VIOLATIONS      STD_OFF 


/**********************************************************************************************************************
 *  WDGM-specific feature defines (automatically computed)
 *********************************************************************************************************************/
# define WDGM_GLOBAL_TRANSITIONS              STD_OFF 
# define WDGM_MULTIPLE_TRIGGER_MODES          STD_ON 


/**********************************************************************************************************************
 *  WDGM-specific feature defines for multi-core systems
 *  (all automatically computed except for OS core identification usage)
 *********************************************************************************************************************/
# define WDGM_MULTICORE_USAGE                 STD_OFF 


/**********************************************************************************************************************
 *  INCLUDES for Dem
 *********************************************************************************************************************/
/* Intentionally left empty. Preprocessor switch WDGM_DEM_REPORT is STD_OFF */ 



#endif /* WDGM_CFG_FEATURES_H */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg_Features.h
 *********************************************************************************************************************/

