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
 *            Module: StbM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: StbM_Cfg.c
 *   Generation Time: 2026-08-27 14:12:18
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

#define STBM_CFG_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "StbM.h"
#include "Rte_StbM.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Dummy symbolic name value for the shared memory memory section */
#define CommonSharedMemory                                 (0u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_GptClockConfig
**********************************************************************************************************************/
/** 
  \var    StbM_GptClockConfig
  \details
  Element                   Description
  MaxTickValue              Maximum value in ticks, the timer channel is able to count.
  GptChannelSymbolicName    Symbolic name of used Gpt channel as local reference clock.
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_GptClockConfigType, STBM_CONST) StbM_GptClockConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxTickValue  GptChannelSymbolicName                                     Referable Keys */
  { /*     0 */  4294967295u, GptConf_GptChannelConfiguration_StbM_Local_Timer_Ch }   /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalClockConfig
**********************************************************************************************************************/
/** 
  \var    StbM_LocalClockConfig
  \details
  Element                                     Description
  HwFrequency                                 Frequency of the hardware reference clock in Hz.
  ClockType                                   The type of local clock, which is used as hardware clock
  DenominatorOfFactorClockTicksToLocalTime    Pre calculated denominator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency.
  GptClockConfigIdx                           the index of the 0:1 relation pointing to StbM_GptClockConfig
  HwPrescaler                                 Prescaler of hardware reference clock.
  NumeratorOfFactorClockTicksToLocalTime      Pre calculated numerator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency.
  TimeBasePartitionMappingIdx                 the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_LocalClockConfigType, STBM_CONST) StbM_LocalClockConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwFrequency  ClockType                                        DenominatorOfFactorClockTicksToLocalTime  GptClockConfigIdx                                                                 HwPrescaler  NumeratorOfFactorClockTicksToLocalTime  TimeBasePartitionMappingIdx                                                                  Referable Keys */
  { /*     0 */  100000000u, STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG,                                       1u,                0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch */,          1u,                                    10u,                          0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */  100000000u, STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG,                                       1u,                0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch */,          1u,                                    10u,                          1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalTimeConfig
**********************************************************************************************************************/
/** 
  \var    StbM_LocalTimeConfig
  \brief  This table contains the local time information of all timebases.
  \details
  Element                        Description
  LocalClockConfigIdx            the index of the 0:1 relation pointing to StbM_LocalClockConfig
  TimeBaseConfigIdx              the index of the 1:1 relation pointing to StbM_TimeBaseConfig
  TimeBasePartitionMappingIdx    the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_LocalTimeConfigType, STBM_CONST) StbM_LocalTimeConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LocalClockConfigIdx                                                            TimeBaseConfigIdx                                                            TimeBasePartitionMappingIdx                                                                  Referable Keys */
  { /*     0 */                  0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                          0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */                  1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                          1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    StbM_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to StbM_PCPartitionConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PartitionIdentifiersType, STBM_CONST) StbM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV        PCPartitionConfigIdx                           */
  { /*     0 */ CommonSharedMemory,                   0u  /* CommonSharedMemory */ }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_StatusNotificationCustomerCallback
**********************************************************************************************************************/
/** 
  \var    StbM_StatusNotificationCustomerCallback
  \details
  Element     Description
  Callback    Name of the customer specific notification callback function, which shall be called, if the time previously set by the customer is reached.
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_StatusNotificationCustomerCallbackType, STBM_CONST) StbM_StatusNotificationCustomerCallback[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Callback                                                                                    Referable Keys */
  { /*     0 */ Rte_Write_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */ Rte_Write_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_CanTsync_eventNotification }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_StatusNotificationCustomerConfig
**********************************************************************************************************************/
/** 
  \var    StbM_StatusNotificationCustomerConfig
  \details
  Element                                  Description
  StatusNotificationEventMask              Defines the events for which the event notification callback function shall be called.
  StatusNotificationCustomerCallbackIdx    the index of the 1:1 relation pointing to StbM_StatusNotificationCustomerCallback
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_StatusNotificationCustomerConfigType, STBM_CONST) StbM_StatusNotificationCustomerConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    StatusNotificationEventMask  StatusNotificationCustomerCallbackIdx                                                                  Referable Keys */
  { /*     0 */                     0x0202u,                                    0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */                     0x0202u,                                    1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_SyncTimeRecordingHeader
**********************************************************************************************************************/
/** 
  \var    StbM_SyncTimeRecordingHeader
  \brief  Time recording header of synchronized timebase.
  \details
  Element        Description
  HwFrequency    Frequency of the hardware reference clock in Hz.
  HwPrescaler    Prescaler of hardware reference clock.
  TimeDomain     Frequency of the hardware reference clock in Hz.
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_SyncTimeRecordingHeaderType, STBM_CONST) StbM_SyncTimeRecordingHeader[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwFrequency  HwPrescaler  TimeDomain        Referable Keys */
  { /*     0 */  100000000u,          1u,         0u },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */  100000000u,          1u,         1u }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBaseConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBaseConfigRDR_01
  \brief  Configuration data from timebase. Contains all indirections to other tables.
  \details
  Element                                Description
  GlobalTimeMaster                       true if time base has the role of a global time master
  SynchronizedTimeBase                   Indicates if the time base is a synchronized time base.
  TimeSlave                              true if timebase has the role of a time slave
  LocalTimeConfigIdx                     the index of the 1:1 relation pointing to StbM_LocalTimeConfig
  PartitionConfigIdx                     the index of the 1:1 relation pointing to StbM_PCPartitionConfig
  StatusIdx                              the index of the 1:1 relation pointing to StbM_Status
  StatusNotificationCustomerConfigIdx    the index of the 0:1 relation pointing to StbM_StatusNotificationCustomerConfig
  TimeBaseId                             Id of the timebase.
  TimeLeapConfigIdx                      the index of the 0:1 relation pointing to StbM_TimeLeapConfig
  TimeRecordingConfigIdx                 the index of the 0:1 relation pointing to StbM_TimeRecordingConfig
  TimeoutConfigIdx                       the index of the 0:1 relation pointing to StbM_TimeoutConfig
  UserDataStateIdx                       the index of the 1:1 relation pointing to StbM_UserDataState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeBaseConfigType, STBM_CONST) StbM_TimeBaseConfigRDR_01[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    GlobalTimeMaster  SynchronizedTimeBase  TimeSlave  LocalTimeConfigIdx                                                            PartitionConfigIdx                            StatusIdx                                                            StatusNotificationCustomerConfigIdx                                                            TimeBaseId  TimeLeapConfigIdx                                                            TimeRecordingConfigIdx                                                            TimeoutConfigIdx                                                            UserDataStateIdx                                                                  Referable Keys */
  { /*     0 */            FALSE,                 TRUE,      TRUE,                 0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                 0u  /* CommonSharedMemory */,        0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                  0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,         0u,                0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                     0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,               0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,               0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */            FALSE,                 TRUE,      TRUE,                 1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                 0u  /* CommonSharedMemory */,        1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                  1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,         1u,                1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                     1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,               1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,               1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBaseConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBaseConfigRDR_05
  \brief  Configuration data from timebase. Contains all indirections to other tables.
  \details
  Element                                Description
  GlobalTimeMaster                       true if time base has the role of a global time master
  SynchronizedTimeBase                   Indicates if the time base is a synchronized time base.
  TimeSlave                              true if timebase has the role of a time slave
  LocalTimeConfigIdx                     the index of the 1:1 relation pointing to StbM_LocalTimeConfig
  PartitionConfigIdx                     the index of the 1:1 relation pointing to StbM_PCPartitionConfig
  StatusIdx                              the index of the 1:1 relation pointing to StbM_Status
  StatusNotificationCustomerConfigIdx    the index of the 0:1 relation pointing to StbM_StatusNotificationCustomerConfig
  TimeBaseId                             Id of the timebase.
  TimeLeapConfigIdx                      the index of the 0:1 relation pointing to StbM_TimeLeapConfig
  TimeRecordingConfigIdx                 the index of the 0:1 relation pointing to StbM_TimeRecordingConfig
  TimeoutConfigIdx                       the index of the 0:1 relation pointing to StbM_TimeoutConfig
  UserDataStateIdx                       the index of the 1:1 relation pointing to StbM_UserDataState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeBaseConfigType, STBM_CONST) StbM_TimeBaseConfigRDR_05[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    GlobalTimeMaster  SynchronizedTimeBase  TimeSlave  LocalTimeConfigIdx                                                            PartitionConfigIdx                            StatusIdx                                                            StatusNotificationCustomerConfigIdx                                                            TimeBaseId  TimeLeapConfigIdx                                                                                    TimeRecordingConfigIdx                                                                           TimeoutConfigIdx                                                                           UserDataStateIdx                                                                  Referable Keys */
  { /*     0 */            FALSE,                 TRUE,      TRUE,                 0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                 0u  /* CommonSharedMemory */,        0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                  0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,         0u,                                        0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                             0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */,                                       0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */,               0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */             TRUE,                 TRUE,     FALSE,                 1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                 0u  /* CommonSharedMemory */,        1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                  1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,         1u, STBM_NO_TIMELEAPCONFIGIDXOFTIMEBASECONFIG  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */, STBM_NO_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG  /* unusedIndex1 */                             , STBM_NO_TIMEOUTCONFIGIDXOFTIMEBASECONFIG  /* unusedIndex1 */                             ,               1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBasePartitionMapping
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBasePartitionMapping
  \brief  Time base to partition mapping
  \details
  Element                                           Description
  IndirectionToGptClockStateIdx                     the index of the 0:1 relation pointing to StbM_GptClockState
  IndirectionToGptClockStatePartitionIdx            the partition index of the 0:1 relation pointing to StbM_GptClockState
  IndirectionToLocalClockStateIdx                   the index of the 0:1 relation pointing to StbM_LocalClockState
  IndirectionToLocalClockStatePartitionIdx          the partition index of the 0:1 relation pointing to StbM_LocalClockState
  IndirectionToLocalTimeStateIdx                    the index of the 1:1 relation pointing to one of StbM_LocalTimeState
  IndirectionToLocalTimeStatePartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_LocalTimeState
  IndirectionToMainTimeStateIdx                     the index of the 1:1 relation pointing to one of StbM_MainTimeState
  IndirectionToMainTimeStatePartitionIdx            the partition index of the 1:1 relation pointing to one of StbM_MainTimeState
  IndirectionToTimeBaseConfigIdx                    the index of the 1:1 relation pointing to one of StbM_TimeBaseConfig
  IndirectionToTimeBaseConfigPartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_TimeBaseConfig
  IndirectionToVirtualLocalTimeStateIdx             the index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState
  IndirectionToVirtualLocalTimeStatePartitionIdx    the partition index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeBasePartitionMappingType, STBM_CONST) StbM_TimeBasePartitionMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IndirectionToGptClockStateIdx                                                                 IndirectionToGptClockStatePartitionIdx                            IndirectionToLocalClockStateIdx                                                            IndirectionToLocalClockStatePartitionIdx                            IndirectionToLocalTimeStateIdx                                                            IndirectionToLocalTimeStatePartitionIdx                            IndirectionToMainTimeStateIdx                                                            IndirectionToMainTimeStatePartitionIdx                            IndirectionToTimeBaseConfigIdx                                                            IndirectionToTimeBaseConfigPartitionIdx                            IndirectionToVirtualLocalTimeStateIdx                                                            IndirectionToVirtualLocalTimeStatePartitionIdx                                  Referable Keys */
  { /*     0 */                            0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch */,                                     0u  /* CommonSharedMemory */,                              0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                       0u  /* CommonSharedMemory */,                             0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                      0u  /* CommonSharedMemory */,                            0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                     0u  /* CommonSharedMemory */,                             0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                      0u  /* CommonSharedMemory */,                                    0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                                             0u  /* CommonSharedMemory */ },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */                            0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch */,                                     0u  /* CommonSharedMemory */,                              1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                       0u  /* CommonSharedMemory */,                             1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                      0u  /* CommonSharedMemory */,                            1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                     0u  /* CommonSharedMemory */,                             1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                      0u  /* CommonSharedMemory */,                                    1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                                             0u  /* CommonSharedMemory */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapConfig
  \details
  Element            Description
  FutureThreshold    Time leap threshold after which a future time leap is detected.
  PastThreshold      Time leap threshold after which a past time leap is detected.
  ClearCount         Counter after which the a time leap is deleted.
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeLeapConfigType, STBM_CONST) StbM_TimeLeapConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FutureThreshold  PastThreshold  ClearCount        Referable Keys */
  { /*     0 */       10000000u,     10000000u,         1u },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */       10000000u,     10000000u,         1u }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingConfig
  \brief  Configuration data for time recording unit.
  \details
  Element                           Description
  BlockCount                        Number of configured recording blocks
  SyncTimeRecordingBlockEndIdx      the end index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingBlockStartIdx    the start index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingHeaderIdx        the index of the 0:1 relation pointing to StbM_SyncTimeRecordingHeader
  TimeBaseConfigIdx                 the index of the 0:1 relation pointing to StbM_TimeBaseConfig
  TimeRecordingSyncCallbackIdx      the index of the 0:1 relation pointing to StbM_TimeRecordingSyncCallback
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeRecordingConfigType, STBM_CONST) StbM_TimeRecordingConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BlockCount  SyncTimeRecordingBlockEndIdx                                                            SyncTimeRecordingBlockStartIdx                                                            SyncTimeRecordingHeaderIdx                                                            TimeBaseConfigIdx                                                            TimeRecordingSyncCallbackIdx                                                                  Referable Keys */
  { /*     0 */         1u,                           1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                             0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                         0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */         ,                           0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */         1u,                           2u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                             1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                         1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */,                           1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingSyncCallback
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingSyncCallback
  \brief  Time recording callback for synchronized timebase.
  \details
  Element     Description
  Callback    This function is called, once all recording blocks are updated.
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeRecordingSyncCallbackType, STBM_CONST) StbM_TimeRecordingSyncCallback[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Callback                                                                                                Referable Keys */
  { /*     0 */ Rte_Call_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */ Rte_Call_StbM_MeasurementNotification_StbMSynchronizedTimeBase_CanTsync_TimeRecordTsync_Callback }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeoutConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeoutConfig
  \details
  Element                   Description
  SyncLossTimeoutCounter    Represents the amount of main functions until the timeout is expired. Calculated by Timeout(ns)/MainFunction(ns).
  TimeBaseConfigIdx         the index of the 1:1 relation pointing to StbM_TimeBaseConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_TimeoutConfigType, STBM_CONST) StbM_TimeoutConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SyncLossTimeoutCounter  TimeBaseConfigIdx                                                                  Referable Keys */
  { /*     0 */                   300u,                0u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase */          },  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  { /*     1 */                  1000u,                1u  /* /ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync */ }   /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_GptClockState
**********************************************************************************************************************/
/** 
  \var    StbM_GptClockState
  \brief  All relevant state data for Gpt local clock.
  \details
  Element             Description
  GptChannelActive    Indicates if the used Gpt channel is active.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_GptClockStateUType, STBM_VAR_NO_INIT) StbM_GptClockState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/Gpt/GptChannelConfigSet/StbM_Local_Timer_Ch] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_Initialized
**********************************************************************************************************************/
/** 
  \var    StbM_Initialized
  \brief  Initialization state of the StbM. TRUE, if StbM_Init() has been called, else FALSE.
*/ 
#define STBM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_InitializedType, STBM_VAR_CLEARED) StbM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define STBM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalClockState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalClockState
  \brief  State table for Local Time unit.
  \details
  Element         Description
  ElapsedTime     Elapsed time of the local clock since last synchronization event. This can be either a counter value or a real time.
  LastReadTime    Last read time of the local clock. This can be either a counter value or a real time.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_LocalClockStateUType, STBM_VAR_NO_INIT) StbM_LocalClockState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalTimeState
  \brief  Local time state table.
  \details
  Element             Description
  LocalTimeUpdated    Indicate if LocalTime is updated and therefore valid, hence can be used without recalculating it. (E_OK | E_NOT_OK)
  LocalTime           TL (current corrected local time).
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_LocalTimeStateUType, STBM_VAR_NO_INIT) StbM_LocalTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_MainTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_MainTimeState
  \brief  Main time state table.
  \details
  Element                 Description
  GlobalTimeSync          TGsync (local time after update).
  VirtualLocalTimeSync    TVsync (virtual local time at last synchronization event).
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_MainTimeStateUType, STBM_VAR_NO_INIT) StbM_MainTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_ReceivedTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_ReceivedTimeState
  \brief  Received time state table.
  \details
  Element               Description
  GlobalTimeRx          TGrx (received global time).
  LocalTimeSync         TLsync (local time before update).
  VirtualLocalTimeRx    TVrx (received virtual local time).
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_ReceivedTimeStateUType, STBM_VAR_NO_INIT) StbM_ReceivedTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_Status
**********************************************************************************************************************/
/** 
  \var    StbM_Status
  \brief  Table with timebase status
  \details
  Element             Description
  GlobalTimeStatus    Status of received global time.
  LocalTimeStatus     Status of local time.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_StatusUType, STBM_VAR_NO_INIT) StbM_Status;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_StatusNotificationState
**********************************************************************************************************************/
/** 
  \var    StbM_StatusNotificationState
  \brief  This table stores state related variables for the status notification.
  \details
  Element       Description
  Events        Current state of occurred events.
  LastStatus    Last analyzed timebase status.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_StatusNotificationStateUType, STBM_VAR_NO_INIT) StbM_StatusNotificationState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_SyncTimeRecordingBlock
**********************************************************************************************************************/
/** 
  \var    StbM_SyncTimeRecordingBlock
  \brief  Time recording blocks of synchronized timebase.
  \details
  Element                Description
  GlbNanoSeconds         Nanoseconds of global time after update.
  GlbSeconds             Seconds of global time after update.
  LocNanoSeconds         Nanoseconds of local time before update.
  LocSeconds             Seconds of local time before update.
  PathDelay              Received path delay.
  VirtualLocalTimeLow    Least significant 32 bit of the Virtual Local Time.
  TimeBaseStatus         TimeBaseStatus.
  RateDeviation          Rate deviation.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_SyncTimeRecordingBlockUType, STBM_VAR_NO_INIT) StbM_SyncTimeRecordingBlock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBaseState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBaseState
  \brief  Internal state of the Time Bases.
  \details
  Element          Description
  UpdateCounter    Actual counter value for immediate time synchronisation.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_TimeBaseStateUType, STBM_VAR_NO_INIT) StbM_TimeBaseState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapClearState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapClearState
  \details
  Element             Description
  ClearCountFuture    Clear counter to count until a detected timeleap to the future is reset.
  ClearCountPast      Clear counter to count until a detected timeleap to the past is reset.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_TimeLeapClearStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapClearState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapState
  \brief  Time leap state table.
  \details
  Element          Description
  TimeLeap         The last calculated time leap TGrx - TL.
  TimeLeapValid    Flag which indicates if the calculated time leap is valid.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_TimeLeapStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingState
  \brief  State table for time recording unit.
  \details
  Element                Description
  CurrentBlockIdx        Current index of the next free block in timebase time recording blocks.
  PathDelay              Received path delay on last synchronization event.
  RecordedBlocksCount    Number of recorded blocks.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_TimeRecordingStateUType, STBM_VAR_NO_INIT) StbM_TimeRecordingState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeoutState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeoutState
  \details
  Element                   Description
  SyncLossTimeoutCounter    Timeout for the synchronisation of the Time Base.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_TimeoutStateUType, STBM_VAR_NO_INIT) StbM_TimeoutState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_UserDataState
**********************************************************************************************************************/
/** 
  \var    StbM_UserDataState
  \brief  State table for user data.
  \details
  Element     Description
  UserData    User data.
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_UserDataStateUType, STBM_VAR_NO_INIT) StbM_UserDataState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_VirtualLocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_VirtualLocalTimeState
  \brief  Virtual local time state table.
  \details
  Element                                         Description
  VirtualLocalTime                                TV (current virtual local time).
  VirtualLocalTimeElapsedAfterAdaptionInterval    TV elapsed after adaption interval (virtual local time elapsed after offset correction adaption interval).
*/ 
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(StbM_VirtualLocalTimeStateUType, STBM_VAR_NO_INIT) StbM_VirtualLocalTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase] */
  /*     1 */  /* [/ActiveEcuC/StbM/StbMSynchronizedTimeBase_CanTsync] */

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PCConfig
**********************************************************************************************************************/
/** 
  \var    StbM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to StbM_PCPartitionConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PCConfigsType, STBM_CONST) StbM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_01 */
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_03 */
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_04 */
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      StbM_PCPartitionConfigRDR_05  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_05 */
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_06 */
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_07 */
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      StbM_PCPartitionConfigRDR_01  /**< the pointer to StbM_PCPartitionConfig in Config_RDR_08 */
  }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    StbM_PCPartitionConfigRDR_01
  \details
  Element                            Description
  TimeBaseConfig                     the pointer to StbM_TimeBaseConfig
  SizeOfSyncTimeRecordingBlock       the number of accomplishable value elements in StbM_SyncTimeRecordingBlock
  SizeOfSyncTimeRecordingHeader      the number of accomplishable value elements in StbM_SyncTimeRecordingHeader
  SizeOfTimeLeapConfig               the number of accomplishable value elements in StbM_TimeLeapConfig
  SizeOfTimeRecordingConfig          the number of accomplishable value elements in StbM_TimeRecordingConfig
  SizeOfTimeRecordingSyncCallback    the number of accomplishable value elements in StbM_TimeRecordingSyncCallback
  SizeOfTimeoutConfig                the number of accomplishable value elements in StbM_TimeoutConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PCPartitionConfigType, STBM_CONST) StbM_PCPartitionConfigRDR_01[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      StbM_TimeBaseConfigRDR_01        /**< the pointer to StbM_TimeBaseConfig in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_SyncTimeRecordingBlock in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_SyncTimeRecordingHeader in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_TimeLeapConfig in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_TimeRecordingConfig in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_TimeRecordingSyncCallback in Config_RDR_01 */
    , 2u                               /**< the number of elements in StbM_TimeoutConfig in Config_RDR_01 */
  }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    StbM_PCPartitionConfigRDR_05
  \details
  Element                            Description
  TimeBaseConfig                     the pointer to StbM_TimeBaseConfig
  SizeOfSyncTimeRecordingBlock       the number of accomplishable value elements in StbM_SyncTimeRecordingBlock
  SizeOfSyncTimeRecordingHeader      the number of accomplishable value elements in StbM_SyncTimeRecordingHeader
  SizeOfTimeLeapConfig               the number of accomplishable value elements in StbM_TimeLeapConfig
  SizeOfTimeRecordingConfig          the number of accomplishable value elements in StbM_TimeRecordingConfig
  SizeOfTimeRecordingSyncCallback    the number of accomplishable value elements in StbM_TimeRecordingSyncCallback
  SizeOfTimeoutConfig                the number of accomplishable value elements in StbM_TimeoutConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(StbM_PCPartitionConfigType, STBM_CONST) StbM_PCPartitionConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      StbM_TimeBaseConfigRDR_05        /**< the pointer to StbM_TimeBaseConfig in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_SyncTimeRecordingBlock in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_SyncTimeRecordingHeader in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_TimeLeapConfig in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_TimeRecordingConfig in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_TimeRecordingSyncCallback in Config_RDR_05 */
    , 1u                               /**< the number of elements in StbM_TimeoutConfig in Config_RDR_05 */
  }
};
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, STBM_VAR_NO_INIT) StbM_PreInitialized;
VAR(boolean, STBM_VAR_NO_INIT) StbM_PostInitialized;

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: StbM_Cfg.c
 *********************************************************************************************************************/
