/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_OsCore_Qm.c
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Csm.h"
#include "Rte_Dcm.h"
#include "Rte_DemMaster_Invalid_OsApplication.h"
#include "Rte_DemSatellite_Invalid_OsApplication.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_SWC_Appl_Project.h"
#include "Rte_SWC_CDD_IPC.h"
#include "Rte_SWC_CMP_PRJ_UDSHandler.h"
#include "Rte_SWC_PLT_Appl_Communication.h"
#include "Rte_SWC_PLT_Appl_Diag.h"
#include "Rte_SWC_PLT_Appl_FaultMgr.h"
#include "Rte_SWC_PLT_Appl_IntWDG.h"
#include "Rte_SWC_PLT_Appl_IoHwAb.h"
#include "Rte_SWC_PLT_Appl_ModeManager.h"
#include "Rte_SWC_PLT_Appl_NvMHandler.h"
#include "Rte_SWC_PLT_Appl_PlatformTime.h"
#include "Rte_SWC_PLT_Appl_RTM.h"
#include "Rte_SWC_PLT_CDD_ECUSync.h"
#include "Rte_SWC_PLT_CDD_ExternalWdg.h"
#include "Rte_SWC_PLT_CDD_FCRU.h"
#include "Rte_SWC_PLT_CDD_FailSafe.h"
#include "Rte_SWC_PLT_CDD_HIL.h"
#include "Rte_SWC_PLT_CDD_Logging.h"
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "Rte_SWC_PLT_CDD_Radar_Control.h"
#include "Rte_SWC_PLT_CDD_TimeSync.h"
#include "Rte_SWC_PLT_CDD_WdgHandler.h"
#include "Rte_SWC_PLT_CDD_XCP.h"
#include "Rte_SWC_PLT_Radar_Alignment_Handler.h"
#include "Rte_SWC_PLT_Service_IoHwAb.h"
#include "Rte_SWC_PRJ_Appl_FaultMgr.h"
#include "Rte_SWC_PRJ_Appl_Power_Manager.h"
#include "Rte_SWC_PRJ_Appl_Security_Manager.h"
#include "Rte_SWC_PRJ_Appl_SensorPosition.h"
#include "Rte_StbM.h"
#include "Rte_WdgM_OsCore0_ASIL.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_CanTSyn.h"
#include "SchM_CanTp.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_ComXf.h"
#include "SchM_Crypto.h"
#include "SchM_Csm.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_E2EXf.h"
#include "SchM_EcuM.h"
#include "SchM_Eth.h"
#include "SchM_EthIf.h"
#include "SchM_EthSM.h"
#include "SchM_EthTSyn.h"
#include "SchM_EthTrcv_30_Rtl9010.h"
#include "SchM_EthTrcv_30_Tja1103.h"
#include "SchM_Eth_30_Wrapper.h"
#include "SchM_Fee_30_FlexNor.h"
#include "SchM_Fls.h"
#include "SchM_Gpt.h"
#include "SchM_I2c.h"
#include "SchM_J1939Dcm.h"
#include "SchM_J1939Tp.h"
#include "SchM_LdCom.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Rtm.h"
#include "SchM_Sd.h"
#include "SchM_SoAd.h"
#include "SchM_SomeIpTp.h"
#include "SchM_SomeIpXf.h"
#include "SchM_Spi.h"
#include "SchM_StbM.h"
#include "SchM_TcpIp.h"
#include "SchM_Uart.h"
#include "SchM_Wdg.h"
#include "SchM_WdgM.h"
#include "SchM_Xcp.h"

#include "Rte_Hook.h"

#include "Com.h"
#include "LdCom.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "ComXf.h"
#include "E2EXf.h"
#include "SomeIpXf.h" /* PRQA S 0828 */ /* MD_MSR_Dir1.1 */

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif

#ifndef Rte_ThreadFence
# define Rte_ThreadFence()
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_Cal_Version_Info_Type, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Customer_SW_Version, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Manual_Alignment_Execution_Data_CRC, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC = {
  {0U, 0U, 0, 0}, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_SensorPosition_Data_T, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status = {
  {255U, 255U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_SW_Version_Info_T, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_VAR_INIT) Rte_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC = {
  {0, 0, 120U}, 0U
};
/* PRQA L:L1 */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_VIN_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(AttempCounter_Type, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_AttemptCounter = {
  0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream 1U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream 1U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream 1U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream 1U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream 1U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream 1U
#define Rte_CS_ClientConfigIndex_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback 0U
#define Rte_CS_ClientConfigIndex_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation 0U
#define Rte_CS_ClientConfigIndex_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation 1U

#define RTE_Lib_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_CLEARED) ptr, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_PartialMemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32 dstSize, uint32 srcSize, uint32 dstOffset, uint32 srcOffset, uint32 len); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdClientServiceState(BswM_SDC_SdClientServiceState mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdConsumedEventGroupState(BswM_SDC_SdConsumedEventGroupState mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_Lib_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_OsCounter
# define RTE_USEC_OsCounter OS_US2TICKS_OsCounter
#else
# define RTE_USEC_OsCounter(val) ((TickType)RTE_CONST_USEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_OsCounter
# define RTE_MSEC_OsCounter OS_MS2TICKS_OsCounter
#else
# define RTE_MSEC_OsCounter(val) ((TickType)RTE_CONST_MSEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_OsCounter
# define RTE_SEC_OsCounter OS_SEC2TICKS_OsCounter
#else
# define RTE_SEC_OsCounter(val)  ((TickType)RTE_CONST_SEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_OsCounter_0U (0UL)
#define RTE_CONST_MSEC_OsCounter_10U (10UL)
#define RTE_CONST_MSEC_OsCounter_2U (2UL)
#define RTE_CONST_MSEC_OsCounter_20U (20UL)
#define RTE_CONST_MSEC_OsCounter_25U (25UL)
#define RTE_CONST_MSEC_OsCounter_5U (5UL)
#define RTE_CONST_MSEC_OsCounter_50U (50UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/


#define RTE_Lifecycle_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


FUNC(void, RTE_CODE) Rte_InitMemory_OsCore_Qm(void)
{
  /* set default values for internal data */
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info = Rte_C_Idt_Cal_Version_Info_Type_CD74C5DC964C6519DB93441640348751;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info = Rte_C_Dt_Customer_SW_Version_9316ED4AFE347AE2DF0E9A4964AAE922;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC = Rte_C_Dt_Manual_Alignment_Execution_Data_CRC_D239E83BEA087CE8D08EBACC2DD214A6;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status = Rte_C_SensorPos_default_Dt_SensorPosition_Data_T;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info = Rte_C_Idt_SW_Version_Info_T_96E8A160D9BF24D1E9053E1C9A155DCE;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Security_Access_Ath_Fault_De_Security_Access_Ath_Fault = 170U;
  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC = Rte_C_Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_5F1F99062FD261F0CC1D457494035164;

  /* initialize per-instance memory variables */
  Rte_MemCpy32(Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_VIN, Rte_C_VIN_T_Dt_VIN_T, sizeof(Dt_VIN_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDS_AttemptCounter = Rte_C_AttempCounter_Type_7D1FF15F18E3EC914DB76CAD74045F0B;
  /* initialize client-server connection variables */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, sizeof(Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback)); /* PRQA S 0315 */ /* MD_Rte_0315 */

}

#define RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/


/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info(P2CONST(Idt_Cal_Version_Info_Type, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info(P2CONST(Dt_Customer_SW_Version, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC(P2CONST(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(P2CONST(Dt_SensorPosition_Data_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info(P2CONST(Idt_SW_Version_Info_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(P2CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information(P2VAR(Dt_Auto_Alignment_Status_Information, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(P2VAR(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2VAR(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters(P2VAR(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters(P2VAR(Dt_Service_Alignment_Result_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T(P2VAR(DID_StaticAlignment_NonConfig_Param_T, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CMP_PRJ_UDSHandler_Rp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters(P2VAR(Dt_Static_Alignment_Engineering_Parameters, AUTOMATIC, RTE_SWC_CMP_PRJ_UDSHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_AlignmentAuto_De_AlignmentAuto(P2VAR(Dt_AlignmentAuto, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_AlignmentService_De_AlignmentService(P2VAR(Dt_AlignmentService, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_AlignmentShortTrack_De_AlignmentShortTrack(P2VAR(Dt_AlignmentShortTrack, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_AlignmentStatic_De_AlignmentStatic(P2VAR(Dt_AlignmentStatic, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_Alignment_Handler_De_Alignment_Handler(P2VAR(Dt_Alignment_Handler, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(P2VAR(Dt_Alignment_M2D_Data, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_CPU_Load_De_CPU_Load(P2VAR(Dt_CPU_Load, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version(P2VAR(Crypto_CustomFunctions_VersionStruct, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2VAR(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_LOGGING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Fast_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Task_Fast
 * Priority: 50
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Task_Fast) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_10ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_2ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_50ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_Task_Fast, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_10ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_2ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_50ms | Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_RDD_Populate_RDD_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Fast, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Logging_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Logging_2ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Logging_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_RE_Logging_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Logging_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Fast_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Appl_Task_Logging_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Task_Logging
 * Priority: 90
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Task_Logging) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Run_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms | Rte_Ev_Run_SWC_PLT_CDD_HIL_RE_HIL_Periodic_Handler_Rp_HIL_Periodic_Handler_Trigger | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_Task_Logging, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms | Rte_Ev_Run_SWC_PLT_CDD_HIL_RE_HIL_Periodic_Handler_Rp_HIL_Periodic_Handler_Trigger | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream | Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_ADC_Populate_ADC_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_Debug_Populate_Debug_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_Detection_Populate_Detection_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_Header_Populate_Header_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_MMIC_Populate_MMIC_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        TaskType waitingTask;
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_ClientId;
        ++cnt;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback(&Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.syncRecordTableBlock);

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        waitingTask = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback[clientId].Rte_WaitingTaskList[0];
        (void)SetEvent(waitingTask, RTE_TASK_WAITPOINT_EVENT_MASK); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_Status_Populate_Status_Stream();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_HIL_RE_HIL_Periodic_Handler_Rp_HIL_Periodic_Handler_Trigger) != (EventMaskType)0)
    {
      /* call runnable */
      RE_HIL_Periodic_Handler(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_SWC_CMP_PRJ_UDSHandler_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Appl_Task_Logging_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_OsCore0_QM_START_SEC_CODE_Init_Task_Qm_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Init_Task_Qm
 * Priority: 210
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Init_Task_Qm) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  RE_PLT_HIL_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Logging_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CODE_Init_Task_Qm_QM
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0314:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to void is performed.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1339:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
  Finite Execution Time Analysis justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

  \ID FETA_RTE_CLIENT_SERVER
  \DESCRIPTION    For client-server communication, new requests may be added to the server queue while the server is running.
                  This blocks the task and prevents other entities from running.
  \COUNTERMEASURE \R The server task handles only queue + 1 entries at once to allow the execution of other runnables in the same
                     task and tasks with higher priority in between.
                  \S SMI-2125

  \ID FETA_RTE_EXTENDED_TASK
  \DESCRIPTION    An extended task is used if more than one runnable entity is mapped to a task with different activation periods
  \COUNTERMEASURE \S SMI-2063

COV_JUSTIFICATION_END */
