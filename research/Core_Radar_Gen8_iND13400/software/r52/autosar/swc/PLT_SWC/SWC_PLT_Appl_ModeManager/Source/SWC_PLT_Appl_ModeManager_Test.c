/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_ModeManager_Test.c
 *
 * @todo Add a one line description of the implementation.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#if ((ENABLE_SIT_TEST_STUBS == STD_ON) || (ENABLE_SQT_TEST_STUBS == STD_ON))
   #include "Rte_SWC_PLT_Appl_ModeManager.h"
   #include "SWC_PLT_Appl_ModeManager_Cfg.h"
   #include "fixmac.h"
   #include "modemanager.h"
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
extern volatile Dt_SystemOperationMode OperationMode_System;
extern volatile uint8 CommandRadiate_Final;
extern volatile uint8 IsRadiateForced;
extern volatile Dt_InitializationStatus MCU_InitializationStatus_MM;
extern volatile Dt_RadarDiagRequest RadarDiagRequest;
extern volatile Dt_VBattState_T VehicleSupplyVoltageState;
extern volatile Dt_RadarCoreStatus RadarCoreStatus;
extern volatile Dt_RadarDiagRequest RadarDiagRequest;
extern volatile Dt_CustDegradation CustDegradation;
extern volatile Dt_OpModeShutdown OpModeShutdown;
extern volatile uint8 PlatformShutdownTaskCompleted;
extern volatile Dt_ForceRadiate CustForceRadiate;
extern volatile uint8 k_ForceRadiateOn;
extern volatile Dt_ForceRadiate XCPForceRadiate;
extern volatile uint8 CommandRadiate_Int;

   #if (ENABLE_SIT_TEST_STUBS == STD_ON)
volatile uint8 test_var_reset              = 0;
volatile uint8 test_radiate                = 0;
volatile uint8 test_opmode_sys             = 0;
volatile uint8 illegal_operation_test_stub = 0;
   #endif

   #if (TRUE == ENABLE_SQT_TEST_STUBS)
volatile uint8 test_var_T1           = 0;
volatile uint8 test_var_T2           = 0;
volatile uint8 test_var_T3           = 0;
volatile uint8 test_var_T4           = 0;
volatile uint8 test_var_T5           = 0;
volatile uint8 test_var_T6           = 0;
volatile uint8 test_var_T7           = 0;
volatile uint8 test_var_T8           = 0;
volatile uint8 test_var_T9           = 0;
volatile uint8 test_var_T10          = 0;
volatile uint8 test_var_T12          = 0;
volatile uint8 test_var_forceradiate = 0;
volatile uint8 test_var_cmnd         = 0;
   #endif
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Modemanager_Integration_Test
 *   This function includes stub code to verify interfaces of Mode Manager Component
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Mode_Manager.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/

   #if (ENABLE_SIT_TEST_STUBS == STD_ON)
void Modemanager_Integration_Test(void)
{
   /*Stub code to test interface of command radiate final and Is radiate forced  */
   if (test_radiate == 1)
   {
      IsRadiateForced      = CODED_TRUE;
      CommandRadiate_Final = CODED_TRUE;
   }
   else if (test_radiate == 2)
   {
      IsRadiateForced      = CODED_FALSE;
      CommandRadiate_Final = CODED_FALSE;
   }
   else
   {
      /*Do Nothing*/
   }

   /* Stub code to test ECU reset interface */
   if (test_var_reset == 1)
   {
      Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset();
   }
   else
   {
      /*Do Nothing*/
   }

   /* Stub code to test Operation mode system interface */
   if (test_opmode_sys == 0x01)
   {
      OperationMode_System = INIT_MCU;
   }
   else if (test_opmode_sys == 0x02)
   {
      OperationMode_System = RADAR_NOT_CONFIGURED;
   }
   else if (test_opmode_sys == 0x03)
   {
      OperationMode_System = OPERATIONAL;
   }
   else if (test_opmode_sys == 0x04)
   {
      OperationMode_System = FAULTY;
   }
   else if (test_opmode_sys == 0x05)
   {
      OperationMode_System = SHUTDOWN_INITIATED;
   }
   else if (test_opmode_sys == 0x06)
   {
      OperationMode_System = SHUTDOWN_COMPLETED;
   }
   else
   {
      /*Do Nothing*/
   }
}
   #endif

   /*===========================================================================*
    * Function Definitions
    *===========================================================================*/

   /******************************************************************************
    * Name:  Modemanager_Functionality_Test
    *   This function includes stub code to verify functionality of Mode Manager Component
    *
    * Shared Variables: none
    *
    * Parameters: none
    *
    * Return Value: none
    *
    * Design Information:
    *  - 531-SDD_Radar/AAU_SDD_CoreRadar_Mode_Manager.
    *
    *  Change References:
    *  - list change numbers
    *
    ******************************************************************************/
   #if (TRUE == ENABLE_SQT_TEST_STUBS)
void Modemanager_Functionality_Test(void)
{
   /*Stub code for checking SQT state transition  */
   if (test_var_T1 == 1)
   {
      MCU_InitializationStatus_MM                = COMPLETED;
      RadarDiagRequest.SafetyCriticalFaultActive = CODED_FALSE;
      VehicleSupplyVoltageState                  = NORMV;
      RadarCoreStatus.RadarInitializatonStatus   = 0;
      RadarDiagRequest.RadarDiagShutdown         = 0;
   }
   else if (test_var_T2 == 1)
   {
      MCU_InitializationStatus_MM                = FAILED;
      RadarDiagRequest.SafetyCriticalFaultActive = CODED_TRUE;
      RadarDiagRequest.RadarDiagShutdown         = CODED_TRUE;
      CustDegradation.Proj_RadarDiagShutdown     = CODED_TRUE;
   }
   else if (test_var_T3 == 1)
   {
      RadarCoreStatus.RadarReInitRequired            = CODED_TRUE;
      RadarDiagRequest.SafetyCriticalFaultActive     = CODED_FALSE;
      RadarDiagRequest.RadarDiagShutdown             = CODED_FALSE;
      CustDegradation.Proj_SafetyCriticalFaultActive = CODED_FALSE;
      CustDegradation.Proj_RadarDiagShutdown         = CODED_FALSE;
      VehicleSupplyVoltageState                      = NORMV;
      RadarCoreStatus.RadarInitializatonStatus       = 0;
   }
   else if (test_var_T4 == 1)
   {
      OpModeShutdown.ShutdownRequested = CODED_TRUE;
   }
   else if (test_var_T5 == 1)
   {
      RadarDiagRequest.SafetyCriticalFaultActive     = CODED_TRUE;
      RadarDiagRequest.RadarDiagShutdown             = CODED_TRUE;
      CustDegradation.Proj_SafetyCriticalFaultActive = CODED_TRUE;
      CustDegradation.Proj_RadarDiagShutdown         = CODED_TRUE;
   }
   else if (test_var_T6 == 1)
   {
      RadarCoreStatus.RadarInitializatonStatus       = RADAR_SUCCESS;
      RadarDiagRequest.SafetyCriticalFaultActive     = CODED_FALSE;
      RadarDiagRequest.RadarDiagShutdown             = CODED_FALSE;
      CustDegradation.Proj_SafetyCriticalFaultActive = CODED_FALSE;
      CustDegradation.Proj_RadarDiagShutdown         = CODED_FALSE;
   }
   else if (test_var_T7 == 1)
   {
      OpModeShutdown.ShutdownRequested = CODED_TRUE;
   }
   else if (test_var_T8 == 1)
   {
      RadarDiagRequest.SafetyCriticalFaultActive     = CODED_TRUE;
      RadarDiagRequest.RadarDiagShutdown             = CODED_TRUE;
      CustDegradation.Proj_SafetyCriticalFaultActive = CODED_TRUE;
      CustDegradation.Proj_RadarDiagShutdown         = CODED_TRUE;
      VehicleSupplyVoltageState                      = LO_V1;
   }
   else if (test_var_T9 == 1)
   {
      RadarDiagRequest.SafetyCriticalFaultActive = 0;
      RadarDiagRequest.RadarDiagShutdown         = 0;
      PlatformShutdownTaskCompleted              = CODED_TRUE;
      OpModeShutdown.ReturnToNormalRequested     = CODED_TRUE;
      OpModeShutdown.CustShutdownTaskCompleted   = CODED_TRUE;
   }
   else if (test_var_T10 == 1)
   {
      PlatformShutdownTaskCompleted            = CODED_TRUE;
      OpModeShutdown.ReturnToNormalRequested   = CODED_FALSE;
      OpModeShutdown.CustShutdownTaskCompleted = CODED_TRUE;
   }
   else if (test_var_T12 == 1)
   {
      OperationMode_System                       = INIT_MCU;
      RadarDiagRequest.SafetyCriticalFaultActive = 0;
   }
   else
   {
      /*Do Nothing*/
   }

   /* Stub code to verify CommandRadiate_Final when CustForceRadiate and XCPForceRadiate are NO_FORCE*/
   if (test_var_forceradiate == 1)
   {
      CustForceRadiate = NO_FORCE;
      XCPForceRadiate  = NO_FORCE;
      k_ForceRadiateOn = CODED_FALSE;
      if (test_var_cmnd == 1)
      {
         CommandRadiate_Int = CODED_FALSE;
      }
   }
   else
   {
      /*Do Nothing*/
   }
}
   #endif
#endif
