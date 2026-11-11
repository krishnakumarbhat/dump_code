#include "Rte_SWC_PLT_Appl_IntWDG.h"
#include "SWC_PLT_Appl_IntWDG.h"
#if (STD_ON == ENABLE_SQT_TEST_STUBS)
volatile uint8 test_var_wdg           = 0;
volatile uint8 Min_Threshold_Test     = 2;
volatile uint8 Min_Threshold_Test1    = 1; /* Min margin: skip 1 alive indication per 10-cycle window */
volatile uint8 Max_Threshold_Test     = 1;
volatile uint8 Max_Threshold_Test1    = 1; /* Max margin: add 1 extra alive indication per 10-cycle window */
volatile uint8 Supervision_Test       = 0;
volatile uint8 test_disable           = 0;
volatile uint8 test_var_wdg_Asil_Task = 0;

static void Checkpoint_Missed_Check(void);
static void Software_Stuck_Check(void);
static void Boundary_Check_Test(uint8_t boundaryType);
static void Failure_Check_Test(uint8_t failureType);
static void Slow_Mode_Test(void);
static void Disable_Internal_Wdg(void);
#endif

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
volatile uint8 Disable_SE_Flag = 0;
volatile uint8 Disable_Wdg     = 0;
#endif

#if (STD_ON == ENABLE_SQT_TEST_STUBS)
/**
 * FUNCTION: Test_WDG_Task_Monitoring
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * uint8
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to Handle SQT Test.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
uint16 Test_WDG_Task_Monitoring(uint16 se_id_info)
{
   uint16 Task_SE_Id = se_id_info;
   if (test_var_wdg_Asil_Task == se_id_info)
   {
      Task_SE_Id = 0xFF;
   }
   return Task_SE_Id;
}
/*====================================================================================================================*/
/**
 * FUNCTION: Perform_SWT_SQT_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to Perform SQT Test.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Perform_SWT_SQT_Test(void)
{
   switch (test_var_wdg)
   {
      case 0:
         Checkpoint_Missed_Check();
         break;
      case 2:
         Software_Stuck_Check();
         break;
      case 3:
         Failure_Check_Test(1);
         break;
      case 4:
         Boundary_Check_Test(1);
         break;
      case 5:
         Failure_Check_Test(2);
         break;
      case 6:
         Boundary_Check_Test(2);
         break;
      case 7:
         Slow_Mode_Test();
         break;
      case 8:
         Disable_Internal_Wdg();
         break;
      default:
         break;
   }
}
/*====================================================================================================================*/
/**
 * FUNCTION: Checkpoint_Missed_Check
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Checkpoint Missed Check.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

static void Checkpoint_Missed_Check(void)
{
   Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Software_Stuck_Check
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Software Stuck Check.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
static void Software_Stuck_Check(void)
{
   while (1)
      ;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Boundary_Check_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Max and Min Value Boundary Check Test
 * Max Value : Supervision Cycle = 50ms, Max Throshold = 1, Expected max Alive indication = 10+1=11
 * With this test Alive Indications will be 11 in 50ms
 * Min Value : Supervision Cycle = 50ms, Min Throshold = 5, Expected Min Alive indication = 10-5=5
 * With this test Alive Indications will be 5 in 50ms
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

static void Boundary_Check_Test(uint8_t boundaryType)
{
   /*
    * Updated boundary behavior:
    * - Max boundary: total alive indications = 10 + 1 = 11 per 10-cycle window
    *   Add an extra alive indication in 1 cycle while still sending the normal one each cycle.
    * - Min boundary: total alive indications = 10 - 1 = 9 per 10-cycle window
    *   Suppress the alive indication in 1 cycle; send it in the remaining 9 cycles.
    */
   if (boundaryType == 1) // Max Boundary Check (add 5 extra across 10 cycles)
   {
      Supervision_Test++;
      /* Extra alive indications while quota remains */
      if (Max_Threshold_Test1 > 0)
      {
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
         Max_Threshold_Test1--;
      }
      /* Normal alive indication every cycle */
      Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);

      if (Supervision_Test == 10)
      {
         Supervision_Test    = 0;
         Max_Threshold_Test1 = 1;
      }
   }
   else if (boundaryType == 2) // Min Boundary Check (suppress 1 across 10 cycles)
   {
      Supervision_Test++;
      if (Min_Threshold_Test1 > 0)
      {
         /* Skip alive indication for this cycle and reduce remaining suppressions */
         Min_Threshold_Test1--;
      }
      else
      {
         /* Send alive indication for remaining cycles in the window */
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
      }

      if (Supervision_Test == 10)
      {
         Supervision_Test    = 0;
         Min_Threshold_Test1 = 1; /* reset quota for next window */
      }
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Failure_Check_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Max and Min Value Failure Check
 * Max Value : Supervision Cycle = 50ms, Max Throshold = 1, Expected max Alive indication = 10+1=11
 * With this test Alive Indications will be 12 in 50ms
 * Min Value : Supervision Cycle = 50ms, Min Throshold = 1, Expected Min Alive indication = 10-1=9
 * With this test Alive Indications will be 8 in 50ms
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

static void Failure_Check_Test(uint8_t failureType)
{
   if (failureType == 1) // Max Failure Check
   {
      Supervision_Test++;
      if (Max_Threshold_Test == 1)
      {
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
         Max_Threshold_Test = 0;
      }
      Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);

      if (Supervision_Test == 10)
      {
         Supervision_Test   = 0;
         Max_Threshold_Test = 1;
      }
   }
   else if (failureType == 2) // Min Failure Check
   {
      Supervision_Test++;
      if (Min_Threshold_Test == 0)
      {
         Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(WdgMConf_WdgMCheckpoint_CP_Internal_Wdg);
         Min_Threshold_Test = 0;
      }
      else
      {
         Min_Threshold_Test--;
      }

      if (Supervision_Test == 10)
      {
         Supervision_Test   = 0;
         Min_Threshold_Test = 2;
      }
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Slow_Mode_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Slow Mode Test.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

static void Slow_Mode_Test(void)
{
   Rte_Call_CS_WdgM_General_SetMode(WDGIF_SLOW_MODE, 0);
   test_var_wdg = 0;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Disable_Internal_Wdg
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * Void
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used to perform Disable Internal Wdg.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

static void Disable_Internal_Wdg(void)
{
   Rte_Call_CS_Wdg_Disable_Read(INT_WDG);
   test_var_wdg = 0;
}

#endif
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
void Deactivate_SE_On_Req(void)
{
   if (Disable_SE_Flag == 1)
   {
      /* Deactivate Supervision Entities */
      Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity(
         (WdgM_SupervisedEntityIdType)WdgMConf_WdgMSupervisedEntity_SE_Internal_Wdg);
   }
}
void Disable_Internal_Wdg_Sit(void)
{
   if (Disable_Wdg == 1)
   {
      Rte_Call_CS_Wdg_Disable_Read(INT_WDG);
   }
}

#endif
