/*===========================================================================*\
 * FILE: program_flow_monitor.c
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains code for state machine for Program flow monitoring
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *   Requirements Document(s):
 *   (Design & Requirements)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   None
 *
\*===========================================================================*/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "program_flow_monitor.h"
#include "ipc_data.h"
#include "reuse.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS (object-like MACROS)
\*===========================================================================*/
#define PFM_BUFFER_INDEX (4U)
/*===========================================================================*\
 * Local preprocessor #define MACROS() (i.e., those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations (enum, struct, union, typedef)
\*===========================================================================*/

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Local Object Definitions                        */
/* ========================================================================== */
static PFM_Stage_T PFM_Prev_Stage[PFM_BUFFER_INDEX] = {PFM_SYSTEM_INIT_DONE_STAGE};
static volatile PFM_Flow_Status_T PFM_Flow_Status   = PFM_NO_ERROR;

/* used for debugging */
static volatile uint32_t PFM_Fail_Count    = 0U;
static volatile uint32_t PFM_Success_Count = 0U;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static PFM_Stage_T Get_Next_Stage(PFM_Stage_T stage);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  @b Description
 *  @n
 *       returns next expected stage for PFM
 *  @param[in] stage
 *    current stage of PFM.
 * @retval PFM_Stage_T
 *    expected next stage of PFM.
 */
static PFM_Stage_T Get_Next_Stage(PFM_Stage_T stage)
{
   PFM_Stage_T next_stage = (PFM_Stage_T)(((uint8_t)stage + PFM_ONE) % (uint8_t)PFM_INVALID_STAGE);

   /* successful state completion*/
   if (PFM_SYSTEM_INIT_DONE_STAGE == next_stage)
   {
      PFM_Success_Count++;
      next_stage = PFM_RANGE_CONFIG_DONE_STAGE;
   }
   return next_stage;
}

/**
 *  @b Description
 *  @n
 *       Update stage of PFM to new stage
 *       if new stage is not valid stage then calls failed_callback hook function
 *  @param[in] current_stage
 *    new stage for PFM
 *  @param[in] buf_idx
 *    buffer index of ipc notify structure
 * @retval void
 */
void PFM_Update_Stage(PFM_Stage_T current_stage, uint32_t buf_idx)
{
#ifndef PFM_DISABLE
   PFM_Stage_T expected_stage;
   buf_idx        = buf_idx % PFM_BUFFER_INDEX;
   expected_stage = Get_Next_Stage(PFM_Prev_Stage[buf_idx]);
   if (current_stage == expected_stage)
   {
      PFM_Prev_Stage[buf_idx] = current_stage;
   }
   else
   {
      PFM_Fail_Count++;
      PFM_Flow_Status = PFM_INVALID_FLOW_ERROR;
   }
#else
   (void)current_stage;
   (void)buf_idx;
   (void)PFM_Prev_Stage;
   (void)Get_Next_Stage;
   PFM_Flow_Status = PFM_NO_ERROR;
#endif
}

/**
 *  @b Description
 *  @n
 *       returns the current status of program flow monitor
 *  @param[in] none
 * @retval PFM_Flow_Status_T
 */
PFM_Flow_Status_T PFM_Get_Status(void)
{
   return PFM_Flow_Status;
}

/**
 *  @b Description
 *  @n
 *       returns the PFM fail count.
 *  @param[in] none
 * @retval int
 */
uint32_t PFM_Get_Fail_Count(void)
{
   return PFM_Fail_Count;
}

/**
 *  @b Description
 *  @n
 *       returns the PFM success count.
 *  @param[in] none
 * @retval int
 */
uint32_t PFM_Get_Success_Count(void)
{
   return PFM_Success_Count;
}
