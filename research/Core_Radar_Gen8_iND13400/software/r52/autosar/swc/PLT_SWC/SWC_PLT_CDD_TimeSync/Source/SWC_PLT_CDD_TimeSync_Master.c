/*===========================================================================*\
 * FILE: SWC_PLT_CDD_TimeSync_Master.c
 *===========================================================================
 * Copyright � 2020 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential � Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This file conatins Time Sync Master specific functions.
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/

#include "SWC_PLT_CDD_TimeSync_cfg.h"
#include "StbM.h"
#include "StbM_Cfg.h"
#include "sensor_position.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/
/*====================================================================================================================*\
* FUNCTION: EcuSync_SeedCanTSynTimeBaseIfNeeded
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* StbM_GetTimeBaseStatus()
* StbM_SetGlobalTime()
* Get_Radar_Position()
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* \\input{StbM_GetTimeBaseStatus, StbM_SetGlobalTime}
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* Initializes the CanTSync synchronized time base with a valid Global Time Base status when running on the configured
* Global Time master radar (RDR_05).
*
* The function checks the current time base status via StbM. If the Global Time Base bit is not set, it calls
* StbM_SetGlobalTime() with a zero-initialized timestamp and user data to initialize the time base.
*
* PRECONDITIONS:
* - StbM is initialized and the CanTSync time base is configured.
* - Get_Radar_Position() returns a valid radar position.
*
* POSTCONDITIONS:
* - If executed on RDR_05 and the Global Time Base bit is not set, an initialization request is issued via StbM_SetGlobalTime().
* - Otherwise no state is modified.
*
* ----------------------------------------------------------------------------------------------------------------------
* Traceability:
* ----------------------------------------------------------------------------------------------------------------------
* N/A
*
\*====================================================================================================================*/
Std_ReturnType EcuSync_SeedCanTSynTimeBaseIfNeeded(void)
{
   /* Default to success for no-op paths (non-master radar or already initialized). */
   Std_ReturnType result                        = E_OK;
   StbM_TimeBaseStatusType syncTimeBaseStatus   = 0u;
   StbM_TimeBaseStatusType offsetTimeBaseStatus = 0u;
   StbM_TimeStampType seedTimeStamp             = {0u, 0u, 0u, 0u};
   StbM_UserDataType userData                   = {0u, 0u, 0u, 0u};

   /* RDR_05 is the Global Time master in this project setup. */
   if (Get_Radar_Position() == 5u)
   {
      /* Query current StbM status before deciding whether initialization is needed. */
      Std_ReturnType timeBaseStatusResult = StbM_GetTimeBaseStatus(
         StbMConf_StbMSynchronizedTimeBase_StbMSynchronizedTimeBase_CanTsync, &syncTimeBaseStatus, &offsetTimeBaseStatus);

      /* Initialize only when status read is successful and Global Time Base flag is not set. */
      if ((timeBaseStatusResult == E_OK) && ((syncTimeBaseStatus & StbM_Global_Time_Base_BflMask) == 0u))
      {
         result =
            StbM_SetGlobalTime(StbMConf_StbMSynchronizedTimeBase_StbMSynchronizedTimeBase_CanTsync, &seedTimeStamp, &userData);
      }
      /* Propagate error when StbM status cannot be read on master radar. */
      else if (timeBaseStatusResult != E_OK)
      {
         result = E_NOT_OK;
      }
   }
   else
   {
      /* Non-master radar: no initialization required. */
   }

   return result;
}
