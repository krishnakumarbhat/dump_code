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
 *              File: WdgIf_Cfg_Features.h
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
#if !defined (WDGIF_CFG_FEATURES_H)
# define WDGIF_CFG_FEATURES_H
 
/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
# define WDGIF_CFG_FEATURE_MAJOR_VERSION (3u) 
# define WDGIF_CFG_FEATURE_MINOR_VERSION (0u) 
# define WDGIF_CFG_FEATURE_PATCH_VERSION (0u) 


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
# define WDGIF_VERSION_INFO_API                  STD_OFF
# define WDGIF_DEV_ERROR_DETECT                  STD_ON
# define WDGIF_USE_STATECOMBINER                 STD_OFF

# if (WDGIF_DEV_ERROR_DETECT == STD_ON)
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode) \
     ( (void) Det_ReportError( (WDGIF_MODULE_ID), (WDGIF_INSTANCE_ID), (WdgIf_FunctionId), (WdgIf_ErrorCode)) )
# else
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode)
# endif /* (WDGIF_DEV_ERROR_DETECT == STD_ON) */

#endif /* WDGIF_CFG_FEATURES_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Cfg_Features.h
 *********************************************************************************************************************/





