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
 *            Module: Rtm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Rtm_Cfg.c
 *   Generation Time: 2026-08-28 14:40:03
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
/* PRQA S 857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 1297 EOF */ /* MD_Rtm_1297 */
#include "Rtm.h"

/*lint -e546 */ /* Suppress ID546 because & is required for function pointer access */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
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
  LOCAL DATA
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
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Rtm_CommonConst
**********************************************************************************************************************/
/** 
  \var    Rtm_CommonConst
  \brief  List of common const data
  \details
  Element                                Description
  BSWCore                                This flag defines the BSW Core
  CPULoadAutostart                       The autostart flag of the respective MP
  CpuLoadNvMHandleUsed                   A flag indicating the availability of a handle
  TaskResponseTimeNvMHandleUsed          A flag indicating the availability of a handle
  ActivatedMPIdOfCPULoad                 The activated MP id of CPU load
  ConfiguredMPIdOfCPULoad                The configured MP id of CPU
  CoreId                                 The id of the respective CPU Load MP Core Id
  NumberofTaskResponseTimePercentiles    This is the number of percentiles for Response Time Data
  NvMCpuLoadBlockSnv                     The CPU Load NvM Block SNV
  NvMTaskResponseTimeBlockSnv            The Task Response Time NvM Block SNV
  OsTaskInfoEndIdx                       the end index of the 0:n relation pointing to Rtm_OsTaskInfo
  OsTaskInfoLength                       the number of relations pointing to Rtm_OsTaskInfo
  OsTaskInfoStartIdx                     the start index of the 0:n relation pointing to Rtm_OsTaskInfo
  PartitionIndexOfCslStringSNV           The Core index
  TaskResponseTimeDataPtr                This ptr defines the var struct of Response Time Data
*/ 
#define RTM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Rtm_CommonConstType, RTM_CONST) Rtm_CommonConst[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BSWCore  CPULoadAutostart  CpuLoadNvMHandleUsed  TaskResponseTimeNvMHandleUsed  ActivatedMPIdOfCPULoad  ConfiguredMPIdOfCPULoad  CoreId  NumberofTaskResponseTimePercentiles  NvMCpuLoadBlockSnv                      NvMTaskResponseTimeBlockSnv                      OsTaskInfoEndIdx  OsTaskInfoLength  OsTaskInfoStartIdx  PartitionIndexOfCslStringSNV                 TaskResponseTimeDataPtr        Referable Keys */
  { /*     0 */    TRUE,            FALSE,                FALSE,                         FALSE,                    14u,                     30u,     0u,                                  0u, RTM_NO_NVMCPULOADBLOCKSNVOFCOMMONCONST, RTM_NO_NVMTASKRESPONSETIMEBLOCKSNVOFCOMMONCONST,              13u,              13u,                 0u, RtmConf_RtmCoreDefinition_RtmCoreDefinition, NULL_PTR                }   /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
};
#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_OsTaskInfo
**********************************************************************************************************************/
/** 
  \var    Rtm_OsTaskInfo
  \brief  List of Os task Infos
  \details
  Element     Description
  MaxStack    This is the max stack for this task
  TaskId      This is the Os TaskId
*/ 
#define RTM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Rtm_OsTaskInfoType, RTM_CONST) Rtm_OsTaskInfo[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxStack  TaskId                         Referable Keys */
  { /*     0 */    1024u,     Appl_BackgroundTask },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     1 */    2048u,           Appl_IPC_Task },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     2 */    1024u,               Appl_Init },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     3 */    4096u,               Appl_Task },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     4 */    2048u, Appl_Task_Communication },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     5 */    2048u,          Appl_Task_Fast },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     6 */    1024u,     Appl_Task_High_Prio },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     7 */    2048u,       Appl_Task_Logging },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     8 */    2048u,                BSW_Task },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     9 */     512u,        IdleTask_OsCore0 },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*    10 */    1024u,               Init_Task },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*    11 */    1024u,            Init_Task_Qm },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*    12 */    4096u,         Radar_Ctrl_Task }   /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
};
#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_CpuLoadData
**********************************************************************************************************************/
/** 
  \var    Rtm_CpuLoadData
  \details
  Element                       Description
  CollectedTime                 Collected Time
  LastTicks                     Last Ticks
  StartTimeStamp                Start Timestamp
  Threshold                     Threshold
  IsCpuLoadMPResultOverflown    Result Overflown
  MeasurementActive             Measurement Active
  MeasurementWasStopped         Measurement was Stopped
  SendResult                    Send Result
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_CpuLoadDataType, RTM_VAR_NO_INIT) Rtm_CpuLoadData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_CpuLoadTime
**********************************************************************************************************************/
/** 
  \var    Rtm_CpuLoadTime
  \brief  CpuLoadTime
*/ 
#define RTM_START_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_CpuLoadTimeType, RTM_VAR_NO_INIT) Rtm_CpuLoadTime;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_HyperPeriodData
**********************************************************************************************************************/
/** 
  \var    Rtm_HyperPeriodData
  \details
  Element                Description
  AccumulatedTime        The accumulated time
  MainFunctionCounter    MainFunction Counter
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_HyperPeriodDataType, RTM_VAR_NO_INIT) Rtm_HyperPeriodData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_MainFunctionRuntimeData
**********************************************************************************************************************/
/** 
  \var    Rtm_MainFunctionRuntimeData
  \details
  Element           Description
  Average           Average
  Delta             Delta
  LastCall          Last Call
  AverageCounter    AverageCounter
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_MainFunctionRuntimeDataType, RTM_VAR_NO_INIT) Rtm_MainFunctionRuntimeData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



# define RTM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

VAR(uint8, RTM_VAR_INIT) Rtm_InitState[RTM_NUMBER_OF_CORES] = {
  RTM_UNINITIALIZED
};

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


#if (RTM_TIME_MEASUREMENT == STD_ON)
# define RTM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

VAR(sint8, RTM_VAR_INIT) Rtm_MeasurementNestingCtr[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  0x00 /* Measurement Id: 0 */, 
  0x00 /* Measurement Id: 1 */, 
  0x00 /* Measurement Id: 2 */, 
  0x00 /* Measurement Id: 3 */, 
  0x00 /* Measurement Id: 4 */, 
  0x00 /* Measurement Id: 5 */, 
  0x00 /* Measurement Id: 6 */, 
  0x00 /* Measurement Id: 7 */, 
  0x00 /* Measurement Id: 8 */, 
  0x00 /* Measurement Id: 9 */, 
  0x00 /* Measurement Id: 10 */, 
  0x00 /* Measurement Id: 11 */, 
  0x00 /* Measurement Id: 28 */, 
  0x00 /* Measurement Id: 29 */, 
  0x00 /* Measurement Id: 30 */
};



VAR(uint8, RTM_VAR_INIT) Rtm_Ctrl[RTM_CTRL_VECTOR_LEN] = 
{
  0x00u, 
  0x00u
};

VAR(uint8, RTM_VAR_INIT) Rtm_MeasurementConfig[RTM_CTRL_VECTOR_LEN] = 
{
  0x00, 
  0x00
};


VAR(Rtm_MeasurementTimestampType, RTM_VAR_INIT) Rtm_StartTimeStamps[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 0 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 1 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 2 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 3 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 4 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 5 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 6 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 7 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 8 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 9 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 10 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 11 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 28 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 29 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 30 */
};


VAR(Rtm_DataSet, RTM_VAR_INIT) Rtm_Results[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 2, Measurement Name: Rtm_Overhead_NetExecutionTime_EnableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 3, Measurement Name: Rtm_Overhead_NetExecutionTime_DisableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 4, Measurement Name: Appl_BackgroundTask */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 5, Measurement Name: Appl_IPC_Task */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 6, Measurement Name: Appl_Task */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 7, Measurement Name: Appl_Task_Communication */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 8, Measurement Name: Appl_Task_Fast */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 9, Measurement Name: Appl_Task_High_Prio */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 10, Measurement Name: Appl_Task_Logging */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 11, Measurement Name: BSW_Task */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 27, Measurement Name: IdleTask_OsCore0 */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 28, Measurement Name: Radar_Ctrl_Task */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 29, Measurement Name: Rtm_CpuLoadMeasurement */
};

VAR(Rtm_MeasurementPointInfoType, RTM_VAR_INIT) Rtm_MeasurementPointInfo[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 2, Measurement Name: Rtm_Overhead_NetExecutionTime_EnableISRs */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 3, Measurement Name: Rtm_Overhead_NetExecutionTime_DisableISRs */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 4, Measurement Name: Appl_BackgroundTask */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 5, Measurement Name: Appl_IPC_Task */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 6, Measurement Name: Appl_Task */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 7, Measurement Name: Appl_Task_Communication */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 8, Measurement Name: Appl_Task_Fast */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 9, Measurement Name: Appl_Task_High_Prio */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 10, Measurement Name: Appl_Task_Logging */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 11, Measurement Name: BSW_Task */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 27, Measurement Name: IdleTask_OsCore0 */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 28, Measurement Name: Radar_Ctrl_Task */, 
  {0xFFFFFFFFu, 0xFFFFFFFFu, 0u, RTM_NUMBER_OF_THREADS} /* Measurement Id: 29, Measurement Name: Rtm_CpuLoadMeasurement */
};

VAR(uint32, RTM_VAR_INIT) Rtm_NetActiveMeasurementId[RTM_NUMBER_OF_CORES]  = {0xFFFFFFFFu};

VAR(Rtm_ThreadContextInfoType, RTM_VAR_INIT) Rtm_ThreadContext[RTM_NUMBER_OF_THREADS] = 
{
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}
};

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_CONST_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
CONST(uint32, RTM_CONST) Rtm_ThresholdTimes[RTM_NUMBER_OF_ACTIVATED_MPS] =
{
  0x00000000u /* Measurement Id: 0 */, 
  0x00000000u /* Measurement Id: 1 */, 
  0x00000000u /* Measurement Id: 2 */, 
  0x00000000u /* Measurement Id: 3 */, 
  0x00000000u /* Measurement Id: 4 */, 
  0x00000000u /* Measurement Id: 5 */, 
  0x00000000u /* Measurement Id: 6 */, 
  0x00000000u /* Measurement Id: 7 */, 
  0x00000000u /* Measurement Id: 8 */, 
  0x00000000u /* Measurement Id: 9 */, 
  0x00000000u /* Measurement Id: 10 */, 
  0x00000000u /* Measurement Id: 11 */, 
  0x00000000u /* Measurement Id: 28 */, 
  0x00000000u /* Measurement Id: 29 */, 
  0x00000000u /* Measurement Id: 30 */
};

CONST(Rtm_ThresholdCbkFctType, RTM_CONST) Rtm_ThresholdCbkFctArr[RTM_NUMBER_OF_ACTIVATED_MPS] =
{
  NULL_PTR /* Measurement Id: 0 */, 
  NULL_PTR /* Measurement Id: 1 */, 
  NULL_PTR /* Measurement Id: 2 */, 
  NULL_PTR /* Measurement Id: 3 */, 
  NULL_PTR /* Measurement Id: 4 */, 
  NULL_PTR /* Measurement Id: 5 */, 
  NULL_PTR /* Measurement Id: 6 */, 
  NULL_PTR /* Measurement Id: 7 */, 
  NULL_PTR /* Measurement Id: 8 */, 
  NULL_PTR /* Measurement Id: 9 */, 
  NULL_PTR /* Measurement Id: 10 */, 
  NULL_PTR /* Measurement Id: 11 */, 
  NULL_PTR /* Measurement Id: 28 */, 
  NULL_PTR /* Measurement Id: 29 */, 
  NULL_PTR /* Measurement Id: 30 */
};

CONST(uint8, RTM_CONST) Rtm_CtrlConfig[RTM_CTRL_VECTOR_LEN] = 
{
  0x00u, 
  0x00u
};


CONST(Rtm_ThreadContextInfoType, RTM_CONST) Rtm_ThreadContextInit[RTM_NUMBER_OF_THREADS] = 
{
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}, 
  {0xFFFFFFFFu, 0u}
};



CONST(Rtm_MeasurementPointConfigType, RTM_CONST) Rtm_MeasurementPointConfigInfo[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  {FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  {TRUE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 2, Measurement Name: Rtm_Overhead_NetExecutionTime_EnableISRs */, 
  {TRUE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 3, Measurement Name: Rtm_Overhead_NetExecutionTime_DisableISRs */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 4, Measurement Name: Appl_BackgroundTask */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 5, Measurement Name: Appl_IPC_Task */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 6, Measurement Name: Appl_Task */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 7, Measurement Name: Appl_Task_Communication */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 8, Measurement Name: Appl_Task_Fast */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 9, Measurement Name: Appl_Task_High_Prio */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 10, Measurement Name: Appl_Task_Logging */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 11, Measurement Name: BSW_Task */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 27, Measurement Name: IdleTask_OsCore0 */, 
  {FALSE, RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0u} /* Measurement Id: 28, Measurement Name: Radar_Ctrl_Task */, 
  {FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_CPU_LOAD, 0u} /* Measurement Id: 29, Measurement Name: Rtm_CpuLoadMeasurement */
};

CONST(uint32, RTM_CONST) Rtm_ConfiguredToActivatedMPIds[RTM_NUMBER_OF_CONFIGURED_MPS] = 
{
  0x00000000u /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  0x00000001u /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  0x00000002u /* Measurement Id: 2, Measurement Name: Rtm_Overhead_NetExecutionTime_EnableISRs */, 
  0x00000003u /* Measurement Id: 3, Measurement Name: Rtm_Overhead_NetExecutionTime_DisableISRs */, 
  0x00000004u /* Measurement Id: 4, Measurement Name: Appl_BackgroundTask */, 
  0x00000005u /* Measurement Id: 5, Measurement Name: Appl_IPC_Task */, 
  0x00000006u /* Measurement Id: 6, Measurement Name: Appl_Task */, 
  0x00000007u /* Measurement Id: 7, Measurement Name: Appl_Task_Communication */, 
  0x00000008u /* Measurement Id: 8, Measurement Name: Appl_Task_Fast */, 
  0x00000009u /* Measurement Id: 9, Measurement Name: Appl_Task_High_Prio */, 
  0x0000000au /* Measurement Id: 10, Measurement Name: Appl_Task_Logging */, 
  0x0000000bu /* Measurement Id: 11, Measurement Name: BSW_Task */, 
  0xFFFFFFFFu /* Measurement Id: 12, Measurement Name: CANNM_SID_DISABLECOMMUNICATION */, 
  0xFFFFFFFFu /* Measurement Id: 13, Measurement Name: CANNM_SID_ENABLECOMMUNICATION */, 
  0xFFFFFFFFu /* Measurement Id: 14, Measurement Name: CANNM_SID_GETLOCALNODEIDENTIFIER */, 
  0xFFFFFFFFu /* Measurement Id: 15, Measurement Name: CANNM_SID_GETNODEIDENTIFIER */, 
  0xFFFFFFFFu /* Measurement Id: 16, Measurement Name: CANNM_SID_GETPDUDATA */, 
  0xFFFFFFFFu /* Measurement Id: 17, Measurement Name: CANNM_SID_GETSTATE */, 
  0xFFFFFFFFu /* Measurement Id: 18, Measurement Name: CANNM_SID_INIT */, 
  0xFFFFFFFFu /* Measurement Id: 19, Measurement Name: CANNM_SID_MAINFUNCTION */, 
  0xFFFFFFFFu /* Measurement Id: 20, Measurement Name: CANNM_SID_NETWORKRELEASE */, 
  0xFFFFFFFFu /* Measurement Id: 21, Measurement Name: CANNM_SID_NETWORKREQUEST */, 
  0xFFFFFFFFu /* Measurement Id: 22, Measurement Name: CANNM_SID_PASSIVESTARTUP */, 
  0xFFFFFFFFu /* Measurement Id: 23, Measurement Name: CANNM_SID_REPEATMESSAGEREQUEST */, 
  0xFFFFFFFFu /* Measurement Id: 24, Measurement Name: CANNM_SID_RXINDICATION */, 
  0xFFFFFFFFu /* Measurement Id: 25, Measurement Name: CANNM_SID_TXCONFIRMATION */, 
  0xFFFFFFFFu /* Measurement Id: 26, Measurement Name: EthTrcv_30_Rtl9010_TransceiverInit */, 
  0xFFFFFFFFu /* Measurement Id: 27, Measurement Name: EthTrcv_30_Tja1103_TransceiverInit */, 
  0x0000000cu /* Measurement Id: 28, Measurement Name: IdleTask_OsCore0 */, 
  0x0000000du /* Measurement Id: 29, Measurement Name: Radar_Ctrl_Task */, 
  0x0000000eu /* Measurement Id: 30, Measurement Name: Rtm_CpuLoadMeasurement */, 
  0xFFFFFFFFu /* Measurement Id: 31, Measurement Name: Sd_EventServer_Process */, 
  0xFFFFFFFFu /* Measurement Id: 32, Measurement Name: Sd_RxIndication */, 
  0xFFFFFFFFu /* Measurement Id: 33, Measurement Name: Sd_State_HandleRunMode */, 
  0xFFFFFFFFu /* Measurement Id: 34, Measurement Name: Sd_State_Process__ClientSMs */, 
  0xFFFFFFFFu /* Measurement Id: 35, Measurement Name: Sd_State_Process__ServerSMs */, 
  0xFFFFFFFFu /* Measurement Id: 36, Measurement Name: Sd_Tx_ProcessPendingMessages */, 
  0xFFFFFFFFu /* Measurement Id: 37, Measurement Name: Xcp_Event */, 
  0xFFFFFFFFu /* Measurement Id: 38, Measurement Name: Xcp_Init */, 
  0xFFFFFFFFu /* Measurement Id: 39, Measurement Name: Xcp_MainFunction */, 
  0xFFFFFFFFu /* Measurement Id: 40, Measurement Name: Xcp_TlRxIndication */, 
  0xFFFFFFFFu /* Measurement Id: 41, Measurement Name: Xcp_TlTxConfirmation */
};

#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


# define RTM_START_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Rtm_SetCpuLoadTimeOfCore()
 *********************************************************************************************************************/
/*!
 *
 * \internal
 * - #10 Set the cpu load time to new value.
 * \endinternal
 */
FUNC(void, RTM_CODE) Rtm_SetCpuLoadTimeOfCore(const uint16 CoreIndex, const uint32 NewCpuLoadTime)
{
  /* ----- Implementation -------------------------------------------------------------------- */
  /* #10 Set the cpu load time to new value. */
  Rtm_SetCpuLoadTime(NewCpuLoadTime);
  RTM_DUMMY_STATEMENT_CONST(CoreIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
} /* Rtm_SetCpuLoadTimeOfCore */

/**********************************************************************************************************************
 * Rtm_GetCpuLoadTimeOfCore()
 *********************************************************************************************************************/
/*!
 *
 * \internal
 * - #10 Get the cpu load time.
 * \endinternal
 */
FUNC(uint32, RTM_CODE) Rtm_GetCpuLoadTimeOfCore(const uint16 CoreIndex)
{
  /* ----- Implementation -------------------------------------------------------------------- */
  /* #10 Get the cpu load time. */
  RTM_DUMMY_STATEMENT_CONST(CoreIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return Rtm_GetCpuLoadTime();
} /* Rtm_GetCpuLoadTimeOfCore */


/**********************************************************************************************************************
 * Rtm_OsVthSchedule()
 *********************************************************************************************************************/
/*!
 *
 * \internal
 * - #30 If idle task is terminated, it waits for event, or is preempted, start the corresponding CPU load MP.
 * - #40 Handle net and flat execution time MPs.
 * - #50 If idle task is activated, its event is set, or it is resumed, stop the corresponding CPU load MP.
 * \endinternal
 */
/* PRQA S 6010 3 */ /* MD_Rtm_STPTH_Extended */
/* PRQA S 6030 2 */ /* MD_Rtm_STCYC_Extended */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, RTM_CODE) Rtm_OsVthSchedule(
  uint32 FromThreadId,
  uint32 FromThreadReason,
  uint32 ToThreadId,
  uint32 ToThreadReason,
  uint16 CallerCoreId)
{
  RTM_DUMMY_STATEMENT_CONST(FromThreadId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  RTM_DUMMY_STATEMENT_CONST(FromThreadReason); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  RTM_DUMMY_STATEMENT_CONST(ToThreadId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  RTM_DUMMY_STATEMENT_CONST(ToThreadReason); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  RTM_DUMMY_STATEMENT_CONST(CallerCoreId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */

  /* #30 If idle task is terminated, it waits for event, or is preempted, start the corresponding CPU load MP. */
  switch (FromThreadReason)
  {
    case(OS_VTHP_TASK_TERMINATION):
    case(OS_VTHP_TASK_WAITEVENT):
    case(OS_VTHP_THREAD_PREEMPT):
    {
      switch (FromThreadId)
      {
        case (IdleTask_OsCore0):
        {
          Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);
        }
        break;

        default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
        break;
      }
    }
    break;

    default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }

  /* #40 Handle net and flat execution time MPs. */
  Rtm_Schedule(FromThreadId, ToThreadId, CallerCoreId);

  /* #50 If idle task is activated, its event is set, or it is resumed, stop the corresponding CPU load MP. */
  switch (ToThreadReason)
  {
    case(OS_VTHP_TASK_ACTIVATION):
    case(OS_VTHP_TASK_SETEVENT):
    case(OS_VTHP_THREAD_RESUME):
    {
      switch (ToThreadId)
      {
         case (IdleTask_OsCore0):
         {
           Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement);
         }
         break;

         default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
         break;
      }
    }
    break;

    default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }
} /* Rtm_OsVthSchedule */


# define RTM_STOP_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* RTM_TIME_MEASUREMENT == STD_ON */



