

/**\file
 * \brief Header file for RTM SW-C
 *
 * This file contains user defined function calls
 *
 * \b Application:        SRR7p \n
 * \b File-Revision:      %version: 1 %\n
 * \b Last-Changed-by:    %derived_by: g1oq86 % \n
 * \b Classification:     CONFIDENTIAL \n
 */

/*============================================================================*\
*
* Copyright 2022 Aptiv, All Rights Reserved
* It is not allowed to reproduce or utilize parts of this document in any form
* or by any means, including photocopying and microfilm, without permission in
* written by Aptiv.
*
\*============================================================================*/

/*============================================================================*
 * PREPROCESSOR DIRECTIVES
 *============================================================================*/

/* INCLUDE DIRECTIVES FOR STANDARD HEADERS -----------------------------------*/

/* INCLUDE DIRECTIVES FOR OTHER HEADERS --------------------------------------*/

/* local standard types */

/* EXPORTED DEFINE MACROS (#, ##) --------------------------------------------*/

/* LOCAL DEFINE MACROS (#, ##) -----------------------------------------------*/

/* CONFIGURATION DEFINE MACROS (#, ##) ---------------------------------------*/

#ifdef OS_VTH_SCHEDULE
   #undef OS_VTH_SCHEDULE
#endif
#define OS_VTH_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId)                                 \
   {                                                                                                                              \
      (void)FromThreadId;                                                                                                         \
      (void)FromThreadReason;                                                                                                     \
      (void)ToThreadId;                                                                                                           \
      (void)ToThreadReason;                                                                                                       \
      (void)CallerCoreId;                                                                                                         \
      switch (FromThreadReason)                                                                                                   \
      {                                                                                                                           \
         case (OS_VTHP_TASK_TERMINATION):                                                                                         \
         case (OS_VTHP_TASK_WAITEVENT):                                                                                           \
         {                                                                                                                        \
            switch (FromThreadId)                                                                                                 \
            {                                                                                                                     \
               case (Appl_BackgroundTask):                                                                                        \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_BackgroundTask);                                                      \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                  \
               }                                                                                                                  \
               break;                                                                                                             \
               case (IdleTask_OsCore0):                                                                                           \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_IdleTask_OsCore0);                                                         \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                  \
               }                                                                                                                  \
               break;                                                                                                             \
               case (BSW_Task):                                                                                                   \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_BSW_Task);                                                                 \
               }                                                                                                                  \
               case (Appl_Task):                                                                                                  \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_Task);                                                                \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Communication):                                                                                    \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_Task_Communication);                                                  \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Fast):                                                                                             \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_Task_Fast);                                                           \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_High_Prio):                                                                                        \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_Task_High_Prio);                                                      \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Logging):                                                                                          \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_Task_Logging);                                                        \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Radar_Ctrl_Task):                                                                                            \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Radar_Ctrl_Task);                                                          \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_IPC_Task):                                                                                              \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Appl_IPC_Task);                                                            \
               }                                                                                                                  \
               break;                                                                                                             \
                  break;                                                                                                          \
               default:                                                                                                           \
                  break;                                                                                                          \
            }                                                                                                                     \
         }                                                                                                                        \
         break;                                                                                                                   \
         case (OS_VTHP_THREAD_PREEMPT):                                                                                           \
         {                                                                                                                        \
            switch (FromThreadId)                                                                                                 \
            {                                                                                                                     \
               case (Appl_BackgroundTask):                                                                                        \
               case (IdleTask_OsCore0):                                                                                           \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                  \
               }                                                                                                                  \
                                                                                                                                  \
               break;                                                                                                             \
               default:                                                                                                           \
                  break;                                                                                                          \
            }                                                                                                                     \
         }                                                                                                                        \
         break;                                                                                                                   \
         default:                                                                                                                 \
            break;                                                                                                                \
      }                                                                                                                           \
      Rtm_Schedule((uint32)(FromThreadId), (uint32)(ToThreadId), (uint16)(CallerCoreId));                                         \
      switch (ToThreadReason)                                                                                                     \
      {                                                                                                                           \
         case (OS_VTHP_TASK_ACTIVATION):                                                                                          \
         case (OS_VTHP_TASK_SETEVENT):                                                                                            \
         {                                                                                                                        \
            switch (ToThreadId)                                                                                                   \
            {                                                                                                                     \
               case (Appl_BackgroundTask):                                                                                        \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_BackgroundTask);                                                     \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                   \
               }                                                                                                                  \
               break;                                                                                                             \
               case (IdleTask_OsCore0):                                                                                           \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_IdleTask_OsCore0);                                                        \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                   \
               }                                                                                                                  \
               break;                                                                                                             \
               case (BSW_Task):                                                                                                   \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_BSW_Task);                                                                \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task):                                                                                                  \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_Task);                                                               \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Communication):                                                                                    \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_Task_Communication);                                                 \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Fast):                                                                                             \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_Task_Fast);                                                          \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_High_Prio):                                                                                        \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_Task_High_Prio);                                                     \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_Task_Logging):                                                                                          \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_Task_Logging);                                                       \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Radar_Ctrl_Task):                                                                                            \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Radar_Ctrl_Task);                                                         \
               }                                                                                                                  \
               break;                                                                                                             \
               case (Appl_IPC_Task):                                                                                              \
               {                                                                                                                  \
                  Rtm_Start(RtmConf_RtmMeasurementPoint_Appl_IPC_Task);                                                           \
               }                                                                                                                  \
               break;                                                                                                             \
               default:                                                                                                           \
                  break;                                                                                                          \
            }                                                                                                                     \
         }                                                                                                                        \
         break;                                                                                                                   \
         case (OS_VTHP_THREAD_RESUME):                                                                                            \
         {                                                                                                                        \
            switch (ToThreadId)                                                                                                   \
            {                                                                                                                     \
               case (Appl_BackgroundTask):                                                                                        \
               case (IdleTask_OsCore0):                                                                                           \
               {                                                                                                                  \
                  Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);                                                   \
               }                                                                                                                  \
               break;                                                                                                             \
               default:                                                                                                           \
                  break;                                                                                                          \
            }                                                                                                                     \
         }                                                                                                                        \
         break;                                                                                                                   \
         default:                                                                                                                 \
            break;                                                                                                                \
      }                                                                                                                           \
   }

/* EXPORTED DEFINES FOR CONSTANTS --------------------------------------------*/

/*============================================================================*\
* EXPORTED TYPEDEF DECLARATIONS
\*============================================================================*/

/* ENUMS ---------------------------------------------------------------------*/

/* STRUCTS -------------------------------------------------------------------*/

/* UNIONS --------------------------------------------------------------------*/

/* OTHER TYPEDEFS ------------------------------------------------------------*/

/*============================================================================*\
* EXPORTED OBJECT DECLARATIONS
\*============================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

/*====================================================================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*======================================================================================================================
*
* Date(dd-mm-yyyy)        userid                            (Description on following lines: SCR #, etc.)
*
* 04-21-2025             g1oq86
\*===================================================================================================================*/
