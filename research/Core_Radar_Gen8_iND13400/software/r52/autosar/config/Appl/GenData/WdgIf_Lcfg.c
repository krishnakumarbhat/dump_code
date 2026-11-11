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
 *            Module: WdgIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgIf_Lcfg.c
 *   Generation Time: 2026-04-02 15:09:56
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
#define WDGIF_LCFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SWC_PLT_CDD_WdgHandler_cfg.h" 
#include "WdgIf_Lcfg.h" 
#include "WdgIf.h" 


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGIF_LCFG_C_MAJOR_VERSION (3u) 
#define WDGIF_LCFG_C_MINOR_VERSION (0u) 
#define WDGIF_LCFG_C_PATCH_VERSION (0u) 

/* Check the version of WdgIf header file */
#if ( (WDGIF_SW_MAJOR_VERSION != (6u)) \
   || (WDGIF_SW_MINOR_VERSION != (0u)) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf.h are inconsistent!"
#endif

/* Check the version of WdgIf_Lcfg header file */
#if ( (WDGIF_LCFG_MAJOR_VERSION != WDGIF_LCFG_C_MAJOR_VERSION) \
   || (WDGIF_LCFG_MINOR_VERSION != WDGIF_LCFG_C_MINOR_VERSION) \
   || (WDGIF_LCFG_PATCH_VERSION != WDGIF_LCFG_C_PATCH_VERSION) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf_Lcfg.h are inconsistent!"
#endif

#if !defined (WDGIF_LOCAL) /* COV_WDGIF_COMPATIBILITY */
# define WDGIF_LOCAL static
#endif

#define WDGIF_START_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDGIF_LOCAL CONST(WdgIf_InterfaceFunctionsType, WDGIF_CONST) wdgifdevice_functions = 
{
  Internal_Wdg_Instance_SetMode /*  Wdg_SetMode  */ , 
  Internal_Wdg_Instance_SetTriggerCondition /*  Wdg_SetTriggerCondition  */ 
}; /* WdgGeneral */ 


WDGIF_LOCAL CONST(WdgIf_InterfaceFunctionsPerWdgDeviceType, WDGIF_CONST) WdgIf_FunctionsPerWdg [WDGIF_NUMBER_OF_WDGIFDEVICES] =
{
  {
    &wdgifdevice_functions /*  WdgFunctions  */ 
  } /*  [0]  */ 
};

CONST(WdgIf_InterfaceType, WDGIF_CONST) WdgIf_Interface =
{
  WDGIF_NUMBER_OF_WDGIFDEVICES /*  NumOfWdgs  */ , 
  WdgIf_FunctionsPerWdg /*  WdgFunctionsPerDevice  */ 
};

#define WDGIF_STOP_SEC_CONST_ASIL_D_LOCAL_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
  MD_WdgIf_1297: rule 10.3
    Reason:     In case OSSpinlock is used there is the possibility to define explicit the ID which will be forwarded.
                In this case the forwarded OSSpinlock ID is of integer type instead of an OS provided enum type.
    Risk:       None
    Prevention: User must ensure that the explicit configured ID will match with the related OS Spinlock ID (Safety-Manual Item: SMI-522).

*/

/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Lcfg.c
 *********************************************************************************************************************/

