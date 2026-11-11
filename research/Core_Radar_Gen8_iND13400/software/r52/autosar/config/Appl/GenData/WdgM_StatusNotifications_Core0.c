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
 *              File: WdgM_StatusNotifications_Core0.c
 *   Generation Time: 2026-08-21 18:28:43
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
#define WDGM_STATUS_NOTIFICATIONS_CORE_0_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Rte_WdgM_OsCore0_ASIL.h" 

#define WDGM_START_SEC_CODE_ASIL_D
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WdgM_GlobalStatusChangeNotificationCore0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the global status of core 0
 *              changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode status)
{
  (void) Rte_Switch_globalmode_Core0_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_Dummy changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_Dummy_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE1
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE1(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE2
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Alive_Program_Flow_Monitoring changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE2(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Alive_Program_Flow_Monitoring_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE3
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_Appl_IPC_Task changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE3(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_Appl_IPC_Task_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE4
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_PLT_Appl_Task changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE4(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_PLT_Appl_Task_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE5
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_Appl_Task_Communication changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE5(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_Appl_Task_Communication_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE6
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_Appl_Task_Radar_Control changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE6(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_Appl_Task_Radar_Control_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE7
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              SE_Internal_Wdg_BSW_Task changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE7(WdgMMode status)
{
  (void) Rte_Switch_mode_SE_Internal_Wdg_BSW_Task_currentMode(status);
}

#define WDGM_STOP_SEC_CODE_ASIL_D
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_StatusNotifications_Core0.h
 *********************************************************************************************************************/

