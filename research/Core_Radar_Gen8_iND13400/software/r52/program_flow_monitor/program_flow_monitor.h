#ifndef PROGRAM_FLOW_MONITOR_H
#define PROGRAM_FLOW_MONITOR_H

/*===========================================================================*\
 * FILE: program_flow_monitor.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains declarations for state machine for Program flow monitoring
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

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

#include "ipc_commands.h"
   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/
#define PFM_ONE (1U)
   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
#define PFM_ENABLE STD_ON /* Macro to enable/disable PFM Check*/
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum PFM_Stage_Tag
   {
      PFM_SYSTEM_INIT_DONE_STAGE,
      PFM_RANGE_CONFIG_DONE_STAGE,
      PFM_RFFT_DONE_STAGE,
      PFM_DFFT_DONE_STAGE,
      PFM_SP_POST_DONE_STAGE,
      PFM_INVALID_STAGE,
   } PFM_Stage_T;

   typedef enum PFM_Flow_Status_Tag
   {
      PFM_NO_ERROR,
      PFM_INVALID_FLOW_ERROR,
   } PFM_Flow_Status_T;
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

   void PFM_Update_Stage(PFM_Stage_T stage, uint32_t buf_idx);
   PFM_Flow_Status_T PFM_Get_Status(void);
   uint32_t PFM_Get_Fail_Count(void);
   uint32_t PFM_Get_Success_Count(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif // PROGRAM_FLOW_MONITOR_H
