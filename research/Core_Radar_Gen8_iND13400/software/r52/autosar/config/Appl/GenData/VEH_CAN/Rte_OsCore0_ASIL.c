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
 *             File:  Rte_OsCore0_ASIL.c
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

#include "Rte_Cbk.h"

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

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Alignment_IPC_Data, RTE_VAR_INIT) Rte_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data = {
  {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F}, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U,
  0U, 0U, FALSE, 0U, 0U, 0U, 0.0F, 0.0F, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U}, {0.0F, 0.0F,
  0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U}, 0U, 0U, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_name_FHTI, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_IPC_Faults, RTE_VAR_INIT) Rte_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_RadarCapability_Faults, RTE_VAR_INIT) Rte_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_StaticRegCheckFailureInfo, RTE_VAR_INIT) Rte_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_VSE_NVM_Params, RTE_VAR_INIT) Rte_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params = {
  0, 0, 0, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(I_SG_VehicleStatus_AL, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U,
  0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 448U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_SDC_SdClientServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_SDC_SdConsumedEventGroupRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_SDC_SdServerServiceRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_Alignment_Faults_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults = {
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_DTC_Status_Type, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_IPC_Faults, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Mcu_Startup_Fault, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Battery_Tst_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_Host_Micro_Diag_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_InterProcessor_Commn_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_MMIC_B_Diag_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_Memory_Diagnostics_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_PltToFltMgr_Blockage_Detection_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts = {
  85U, 85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Rdr_Hw_Tst_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_TR_ModeManager, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_RadarDiagRequest, RTE_VAR_INIT) Rte_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest = {
  85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AdcData_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_RawAdcDataFilt_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_RawAdcData_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_FailSafe_ResetReason_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, FALSE, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Rfe_REC_NREC_Fault, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_CPU_Load, RTE_VAR_INIT) Rte_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FCRU_Pp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_ECC_Correctable_Error_Counters, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_FailSafe_ResetReason_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, FALSE, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Hardware_Fault_Error_Status, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_ID_data, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Memory_Exception_Info_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo = {
  0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_InitializationStatus, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_StaticRegCheckFailureInfo, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_MMIC_ErrorFlags, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_Type_MMIC_Temperature, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature = {
  0, 0, 0, 0, 0, 0, 0
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Rfe_REC_NREC_Fault, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_RadarCoreStatus, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus = {
  2U, 85U, 170U, 3U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_STS_No_TSyn_Error, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Time_Stamp_Delta, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta = 0;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AlignmentModeIn_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_XCP_Fault_Override_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_ForceRadiate, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate = 2U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_XCP_Op_Mode_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger = 85U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_XCP_Set_Output, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Idt_XCP_Single_Look_T, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AlignmentAuto, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AlignmentService, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService = {
  0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AlignmentShortTrack, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_AlignmentStatic, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Alignment_Faults_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Alignment_Handler, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Alignment_M2D_Data, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data = {
  {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0U, 0U}, {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, {0.0F, 0.0F, 0.0F, 0.0F}, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Auto_Alignment_Result_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Auto_Alignment_Status_Information, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information = {
  0U, 0U, 0U, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0U, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Initial_Alignment_Result_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Manual_Alignment_Execution_Data_CRC, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC = {
  {0U, 0U, 0, 0}, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Service_Alignment_Result_Parameters, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters = {
  0U, 0U, 0U, 0, 0, 0, 0, 0, 0, 0, 0U, 0U, 0U, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0, 0
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DID_StaticAlignment_NonConfig_Param_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T = {
  0U, 0U, 0U, 0, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0, 0, 0U, 0U, 0, 0U, 0, 0U, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Static_Alignment_Engineering_Parameters, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters = {
  0U, 0, 0U, 0, 0, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Initial_Alignment_Performance_Result_T, RTE_VAR_INIT) Rte_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_Fault_T, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_CustDegradation, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation = {
  85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Dt_OpModeShutdown, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown = {
  85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Crypto_CustomFunctions_VersionStruct, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(StbM_TimeBaseNotificationType, RTE_VAR_INIT) Rte_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification = 0U;
/* PRQA L:L1 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Dt_FailSafe_ExceptionReason_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_PIM; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_ECC_Correctable_Error_Counters, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_PIM = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_FailSafe_ResetReason_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_FailSafe_ResetReason_PIM = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, FALSE, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_Manual_Alignment_Execution_Data_CRC, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Manual_Alignment_Execution_Data_PIM = {
  {0U, 0U, 0, 0}, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_Write_Alignment_NvM_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_Rfe_REC_NREC_Fault, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_PIM = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_SensorPosition_Data_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Sensorpos_PIM_UDS = {
  {255U, 255U}, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM = {
  {0, 0, 0U}, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dt_VSE_NVM_Params, RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT) Rte_SWC_PLT_Appl_NvMHandler_VSE_NVM_Params_PIM = {
  0, 0, 0, 0, 0U
}; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_DEFAULT_RTE_PIM_GROUP_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsCore0_ASIL_AckFlagsType, RTE_VAR_INIT) Rte_OsCore0_ASIL_AckFlags = {
  1,
};

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsCore0_ASIL_AckFlagsInit() (Rte_MemClr(&Rte_OsCore0_ASIL_AckFlags, sizeof(Rte_OsCore0_ASIL_AckFlagsType)))
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Busy Flags for LdCom TP
 *********************************************************************************************************************/

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsCore0_ASIL_LdComTpBusyFlagsType, RTE_VAR_CLEARED) Rte_OsCore0_ASIL_LdComTpBusyFlags;

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsCore0_ASIL_LdComTpBusyFlagsInit() (Rte_MemClr(&Rte_OsCore0_ASIL_LdComTpBusyFlags, sizeof(Rte_OsCore0_ASIL_LdComTpBusyFlagsType)))


/**********************************************************************************************************************
 * Index variables for LdCom TP
 *********************************************************************************************************************/

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsCore0_ASIL_LdComTpIndicesType, RTE_VAR_CLEARED) Rte_OsCore0_ASIL_LdComTpIndices;

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsCore0_ASIL_LdComTpIndicesInit() (Rte_MemClr(&Rte_OsCore0_ASIL_LdComTpIndices, sizeof(Rte_OsCore0_ASIL_LdComTpIndicesType)))


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
 * Buffers for data transformation
 *********************************************************************************************************************/

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_CLEARED) Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx[22140]; /* PRQA S 1514 */ /* MD_Rte_1514 */
VAR(uint8, RTE_VAR_CLEARED) Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx[79]; /* PRQA S 1514 */ /* MD_Rte_1514 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint32, RTE_VAR_CLEARED) Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length;
VAR(uint32, RTE_VAR_CLEARED) Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx_Length;

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/
#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(BswM_SDC_SdClientServiceState, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = RTE_MODE_BswM_SDC_SdClientServiceState_SDC_CLIENT_DOWN; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(BswM_SDC_SdConsumedEventGroupState, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = RTE_MODE_BswM_SDC_SdConsumedEventGroupState_SDC_CEG_DOWN; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(BswM_SDC_SdEventHandlerState, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(BswM_SDC_SdEventHandlerState, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(BswM_SDC_SdEventHandlerState, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(Dcm_EcuResetType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
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


FUNC(void, RTE_CODE) Rte_InitMemory_OsCore0_ASIL(void)
{
  /* reset LdCom TP Busy Flags */
  Rte_OsCore0_ASIL_LdComTpBusyFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx, 22140); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx, 79); /* PRQA S 0315 */ /* MD_Rte_0315 */
  /* reset indices for LdCom TP */
  Rte_OsCore0_ASIL_LdComTpIndicesInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  /* set default values for internal data */
  Rte_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data = Rte_C_Dt_Alignment_IPC_Data_66F72BAABD9C644457CAA65FE1EC7928;
  Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI = 0U;
  Rte_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults = Rte_C_Dt_IPC_Faults_4F2529105A8C946361997CF51C52C9DA;
  Rte_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults = Rte_C_RadarCapability_Dt_RadarCapability_Faults;
  Rte_MemCpy32(Rte_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, Rte_C_Dt_StaticRegCheckFailureInfo_592DFB8E305146EF095876B202DE71F7, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params = Rte_C_Dt_VSE_NVM_Params_0671719A05B77BCE683C6C16B951E137;
  Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Pcan_Communication_ETE_fault_De_Communication_ETE_fault = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL = Rte_C_Ap_SG_VehicleStatus_adt_AL_F115F1E0A0E76B99498B5A88064BA157;
  Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = 170U;
  Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode = 0U;
  Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode = 0U;
  Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode = 0U;
  Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode = 0U;
  Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults = Rte_C_PltToFltMgr_Alignment_Faults_Dt_PltToFltMgr_Alignment_Faults_T;
  Rte_SWC_PLT_Appl_Diag_Pp_DTC_Status_De_DTC_Status = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults = Rte_C_Dt_IPC_Faults_4F2529105A8C946361997CF51C52C9DA;
  Rte_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status = Rte_C_Dt_Mcu_Startup_Fault_49D25C89294F307D4B5291C6C54B4484;
  Rte_SWC_PLT_Appl_Diag_Pp_MicroTemp_Low_Deb_Reset_De_MicroTemp_Low_Deb_Reset = 85U;
  Rte_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst = Rte_C_Battery_Tst_T_Dt_Battery_Tst_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Bus_Off_Fault_Status_De_PltToFltMgr_Can_Bus_Off_Fault_Status = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Can_Controller_Fault_Status_De_PltToFltMgr_Can_Controller_Fault_Status = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag = Rte_C_VldtnToFltMgr_Host_Micro_Diag_T_Dt_PltToFltMgr_Host_Micro_Diag_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T = Rte_C_VldtnToFltMgr_InterProcessor_Commn_T_Dt_PltToFltMgr_InterProcessor_Commn_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T = Rte_C_VldtnToFltMgr_MMIC_A_MMIC_Diag_T_Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T = Rte_C_VldtnToFltMgr_MMIC_B_Diag_T_Dt_PltToFltMgr_MMIC_B_Diag_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics = Rte_C_VldtnToFltMgr_Memory_Diagnostics_T_Dt_PltToFltMgr_Memory_Diagnostics_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status = Rte_C_VldtnToFltMgr_Micro_Temp_Fault_Status_T_Dt_PltToFltMgr_Micro_Temp_Fault_Status_T;
  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Mirror_Ram_Int_Flt_Sts_PltToFltMgr_Mirror_Ram_Int_Flt_Sts = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_RFE_Repetitive_Fault_Status_De_RFE_Repetitive_Fault_Status = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts = Rte_C_VldtnToFltMgr_Blockage_Detection_T_Dt_PltToFltMgr_Blockage_Detection_T;
  Rte_SWC_PLT_Appl_Diag_Pp_Radar_Interference_Flt_Sts_De_Radar_Interference_Flt_Sts = 0U;
  Rte_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst = Rte_C_Rdr_Hw_Tst_T_Dt_Rdr_Hw_Tst_T;
  Rte_SWC_PLT_Appl_Diag_Pp_TR_PlatformTime_De_PlatformTime = 0U;
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager = Rte_C_TR_ModeManager_T_Dt_TR_ModeManager;
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest = Rte_C_RadarDiagRequest_T_Dt_RadarDiagRequest;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_Analog_Channel_Count_De_Analog_Channel_Count = 0U;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp = 0U;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count = 0U;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData = Rte_C_Dt_AdcData_T_497FFB561B06C50A6AEA9B6E5B7CE8EE;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData = Rte_C_Dt_RawAdcDataFilt_T_E8FAE26FA1700A19F80F778BF84DDF28;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered = Rte_C_Dt_RawAdcData_T_92BA6058537F7CFE01EA078001733C6C;
  Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State = 0U;
  Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final = 170U;
  Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced = 85U;
  Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0U;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = Rte_C_FailSafe_ResetReason_T_Dt_FailSafe_ResetReason_T;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_NvM_flag_status_Pim_write_status = 0U;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data = Rte_C_Dt_Rfe_REC_NREC_Fault_566B7755EC2A27546EBED05509161E47;
  Rte_SWC_PLT_Appl_NvMHandler_Pp_Sensor_NvM_Corruption_Fault_De_Sensor_NvM_Corruption_Fault = 170U;
  Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = 85U;
  Rte_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load = Rte_C_Dt_CPU_Load_3ADA6DF3F33ECD59801CE9F45DA025DA;
  Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault = 0U;
  Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status = 0U;
  Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus = 0U;
  Rte_SWC_PLT_CDD_FCRU_Pp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat = 0U;
  Rte_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault = Rte_C_Dt_ECC_Correctable_Error_Counters_C9BEAC1F82ABA894768A4299B6145C05;
  Rte_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = Rte_C_FailSafe_ResetReason_T_Dt_FailSafe_ResetReason_T;
  Rte_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status = Rte_C_Dt_Hardware_Fault_Error_Status_D0B7641A8FB1DE09AA69E2A7F0AE9685;
  Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status = 0U;
  Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status = 85U;
  Rte_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data = Rte_C_ID_data_Dt_ID_data;
  Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts = 0U;
  Rte_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo = Rte_C_MemExceptionInfo_Dt_Memory_Exception_Info_T;
  Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus = 0U;
  Rte_MemCpy32(Rte_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, Rte_C_Dt_StaticRegCheckFailureInfo_592DFB8E305146EF095876B202DE71F7, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail = 85U;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags = Rte_C_MMIC_ErrorFlags_Dt_MMIC_ErrorFlags;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Count_De_MMIC_Count = 0U;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature = Rte_C_Idt_Type_MMIC_Temperature_Idt_Type_MMIC_Temperature;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data = Rte_C_Dt_Rfe_REC_NREC_Fault_566B7755EC2A27546EBED05509161E47;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus = Rte_C_RadarCoreStatus_T_Dt_RadarCoreStatus;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate = 0U;
  Rte_SWC_PLT_CDD_Radar_Control_Pp_Radar_Init_Status_De_Radar_Init_Status = 0U;
  Rte_SWC_PLT_CDD_TimeSync_Pp_TimeSync_Status_No_Tsyn_Error_De_STS_No_TSyn_Error = 0U;
  Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Stamp_Delta_De_Time_Stamp_Delta = 0;
  Rte_SWC_PLT_CDD_TimeSync_Pp_Time_Synchronization_Fault_Status_De_Time_Synchronization_Fault_Status = 170U;
  Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status = 0U;
  Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request = 0U;
  Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_ADC_XCP_Req_De_ADC_XCP_Req = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Type_Alignment_Type = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override = 1U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag = 85U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_CW_Mode_De_XCP_CW_Mode = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override = Rte_C_XCP_Fault_Override_Idt_XCP_Fault_Override_T;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate = 2U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Op_Mode_De_XCP_Op_Mode = 0U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration = FALSE;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Program_Mode_De_XCP_Program_Mode = FALSE;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger = 85U;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output = Rte_C_XCP_Output_State_Dt_XCP_Set_Output;
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable = Rte_C_Idt_XCP_Single_Look_T_F486B559DB791688946611468EFC166A;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto = Rte_C_Dt_AlignmentAuto_6251AFA51AD475336F055247A2E60C00;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService = Rte_C_Dt_AlignmentService_F3B6D2FEF62432E34D1714C7FDA38CD2;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack = Rte_C_Dt_AlignmentShortTrack_E9ECF93705CBFDA821A07DF1419C2E8D;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic = Rte_C_Dt_AlignmentStatic_4B1BE51452D1304D84D948271488D584;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults = Rte_C_Alignment_faults_Dt_Alignment_Faults_T;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler = Rte_C_Dt_Alignment_Handler_F75BA9BCF079604D21DD8E6F13A16322;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data = Rte_C_Dt_Alignment_M2D_Data_06F3576E6E43DBD70FA8C6FA59A3A983;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data = Rte_C_Auto_Alignment_Result_Dt_Auto_Alignment_Result_T;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information = Rte_C_Dt_Auto_Alignment_Status_Information_6F1C5CC42D3DD7770F10DA0DD06DF3C5;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result = Rte_C_Initial_Alignment_Result_Dt_Initial_Alignment_Result_T;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC = Rte_C_Dt_Manual_Alignment_Execution_Data_CRC_D239E83BEA087CE8D08EBACC2DD214A6;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters = Rte_C_Dt_Service_Alignment_Engineering_Non_Configuration_Parameters_65C795F7D4C420CB8A436E0237553F0B;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters = Rte_C_Dt_Service_Alignment_Result_Parameters_F9AD1DFC4C071EAB3C19C60D85DAADE8;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T = Rte_C_DID_StaticAlignment_NonConfig_Param_T_823EC5FD85DD283D19FF63440986798A;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters = Rte_C_Dt_Static_Alignment_Engineering_Parameters_7E345F8E8047AB1EF495C38D9D6F0715;
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform = Rte_C_Initial_Alignment_Performance_Result_Dt_Initial_Alignment_Performance_Result_T;
  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, Rte_C_Fault_T_Dt_Fault_T, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation = Rte_C_CustDegradation_Dt_CustDegradation;
  Rte_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown = Rte_C_OpModeShutdown_init_T_Dt_OpModeShutdown;
  Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode = 0U;
  Rte_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version = Rte_C_Crypto_CustomFunctions_VersionStruct_2B9911959C404BA1FFA8D0AED7E2279F;
  Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status = 0U;
  Rte_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification = 0U;

  /* reset Tx Ack Flags */
  Rte_OsCore0_ASIL_AckFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_OsCore0_ASIL_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;

  /* initialize transformation buffers */
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//  Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length = 0;
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//  Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx_Length = 0;

  /* initialize per-instance memory variables */
  Rte_MemClr(&Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_PIM, sizeof(Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_PIM)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_SWC_PLT_Appl_NvMHandler_Appl_Alignment_PIM = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_PIM = Rte_C_ECC_Correctable_Error_Counters_Dt_ECC_Correctable_Error_Counters;
  Rte_SWC_PLT_Appl_NvMHandler_FailSafe_ResetReason_PIM = Rte_C_FailSafe_ResetReason_T_Dt_FailSafe_ResetReason_T;
  Rte_SWC_PLT_Appl_NvMHandler_Manual_Alignment_Execution_Data_PIM = Rte_C_Dt_Manual_Alignment_Execution_Data_CRC_D239E83BEA087CE8D08EBACC2DD214A6;
  Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_PIM = Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T;
  Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_PIM = Rte_C_Rfe_R1R2_Fault_T_Dt_Rfe_REC_NREC_Fault;
  Rte_SWC_PLT_Appl_NvMHandler_Sensorpos_PIM_UDS = Rte_C_SensorPos_default_Dt_SensorPosition_Data_T;
  Rte_SWC_PLT_Appl_NvMHandler_Static_Alignment_Engineering_Write_Configuration_Parameters_PIM = Rte_C_Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_CDCCBF02DA3C25359EC6D6D27E2A3DA2;
  Rte_SWC_PLT_Appl_NvMHandler_VSE_NVM_Params_PIM = Rte_C_Dt_VSE_NVM_Params_0671719A05B77BCE683C6C16B951E137;
  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = RTE_MODE_BswM_SDC_SdClientServiceState_SDC_CLIENT_DOWN;

  Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = RTE_MODE_BswM_SDC_SdConsumedEventGroupState_SDC_CEG_DOWN;

  Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED;

  Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED;

  Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = RTE_MODE_BswM_SDC_SdEventHandlerState_SDC_EH_RELEASED;

  Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE;

  /* initialize client-server connection variables */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, sizeof(Rte_CS_ServerQueue_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, sizeof(Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, sizeof(Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation, sizeof(Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation)); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_MemClr(&Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation, sizeof(Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation)); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* initialize configuration variant pointer */
  Rte_VarCfgPtr = NULL_PTR;
}

#define RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/


/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data(P2CONST(Dt_Alignment_IPC_Data, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults(P2CONST(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults(P2CONST(Dt_RadarCapability_Faults, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, data, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params(P2CONST(Dt_VSE_NVM_Params, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_PCAN_Timeout_Faults_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_PCAN_Timeout_Faults_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event(P2CONST(SR_DETECTIONS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_OsCore0_ASIL_LdComTpBusyFlags.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx == 0U)
  {
    PduInfoType pduInfo = RTE_PDUINFOTYPE_INIT;
    Rte_OsCore0_ASIL_LdComTpBusyFlags.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = SomeIpXf_LdCom_signalPdu_RDR_1_Detections_52b391ee_Tx(&(Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length = lengthBuffer;
    if ((Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length <= 22140U) && (!Rte_IsHardTransformerError(ret)))
    {
      pduInfo.SduDataPtr = &(Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx[0]);
      pduInfo.SduLength = (PduLengthType)Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length;
      ret |= LdCom_Transmit(LdComConf_LdComIPdu_signalPdu_RDR_1_Detections_52b391ee_Tx, &pduInfo); /* PRQA S 2986 */ /* MD_Rte_2986 */
      if (ret != E_OK) /* PRQA S 1863 */ /* MD_Rte_Os */
      {
        Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 0U;
        Rte_OsCore0_ASIL_LdComTpBusyFlags.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 0;
        ret = RTE_E_COM_STOPPED; /* PRQA S 2983 */ /* MD_Rte_2983 */
      }
    }
    else
    {
      Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      Rte_OsCore0_ASIL_LdComTpBusyFlags.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 0;
      Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  else
  {
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_COM_BUSY;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info(P2CONST(SR_RADAR_SW_INFO_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[90U];

  ret = SomeIpXf_LdCom_signalPdu_RDR_1_SW_Info_b4e751e3_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 90U) && (!Rte_IsHardTransformerError(ret)))
  {
    PduInfoType pduInfo = RTE_PDUINFOTYPE_INIT;
    pduInfo.SduDataPtr = &(transformationBuffer_0[0]);
    pduInfo.SduLength = (PduLengthType)lengthBuffer;
    ret |= LdCom_Transmit(LdComConf_LdComIPdu_signalPdu_RDR_1_SW_Info_b4e751e3_Tx, &pduInfo); /* PRQA S 2986 */ /* MD_Rte_2986 */
    if (ret != RTE_E_OK)
    {
      ret = RTE_E_COM_STOPPED; /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status(P2CONST(SR_RADAR_STATUS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[269U];

  ret = SomeIpXf_LdCom_signalPdu_RDR_1_Status_9d482741_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 269U) && (!Rte_IsHardTransformerError(ret)))
  {
    PduInfoType pduInfo = RTE_PDUINFOTYPE_INIT;
    pduInfo.SduDataPtr = &(transformationBuffer_0[0]);
    pduInfo.SduLength = (PduLengthType)lengthBuffer;
    ret |= LdCom_Transmit(LdComConf_LdComIPdu_signalPdu_RDR_1_Status_9d482741_Tx, &pduInfo); /* PRQA S 2986 */ /* MD_Rte_2986 */
    if (ret != RTE_E_OK)
    {
      ret = RTE_E_COM_STOPPED; /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_PCAN_Timeout_Faults_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_PCAN_Timeout_Faults_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_PCAN_Timeout_Faults_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL(P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[64U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_Com_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus1_oRDR_ALIGNMENT_STATUS_001_oPCAN_RADAR_7714a623_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL(P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[41U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 41U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_Com_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 41U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_AlignmentStatus2_oRDR_ALIGNMENT_STATUS_002_oPCAN_RADAR_1945d616_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL(P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_001_004_oRDR_DETECTION_001_004_oPCAN_RADAR_df4895a5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_001_004_oRDR_DETECTION_001_004_oPCAN_RADAR_df4895a5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_005_008_AL_Vdp_SG_Detections_005_008_AL(P2CONST(I_SG_Detections_005_008_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_005_008_oRDR_DETECTION_005_008_oPCAN_RADAR_ae8ba1f7_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_005_008_oRDR_DETECTION_005_008_oPCAN_RADAR_ae8ba1f7_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_009_012_AL_Vdp_SG_Detections_009_012_AL(P2CONST(I_SG_Detections_009_012_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_009_012_oRDR_DETECTION_009_012_oPCAN_RADAR_37f1858c_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_009_012_oRDR_DETECTION_009_012_oPCAN_RADAR_37f1858c_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_013_016_AL_Vdp_SG_Detections_013_016_AL(P2CONST(I_SG_Detections_013_016_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_013_016_oRDR_DETECTION_013_016_oPCAN_RADAR_05faeda4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_013_016_oRDR_DETECTION_013_016_oPCAN_RADAR_05faeda4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_017_020_AL_Vdp_SG_Detections_017_020_AL(P2CONST(I_SG_Detections_017_020_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_017_020_oRDR_DETECTION_017_020_oPCAN_RADAR_e956bb2e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_017_020_oRDR_DETECTION_017_020_oPCAN_RADAR_e956bb2e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_021_024_AL_Vdp_SG_Detections_021_024_AL(P2CONST(I_SG_Detections_021_024_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_021_024_oRDR_DETECTION_021_024_oPCAN_RADAR_ea3d35f7_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_021_024_oRDR_DETECTION_021_024_oPCAN_RADAR_ea3d35f7_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_025_028_AL_Vdp_SG_Detections_025_028_AL(P2CONST(I_SG_Detections_025_028_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_025_028_oRDR_DETECTION_025_028_oPCAN_RADAR_9bfe01a5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_025_028_oRDR_DETECTION_025_028_oPCAN_RADAR_9bfe01a5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_029_032_AL_Vdp_SG_Detections_029_032_AL(P2CONST(I_SG_Detections_029_032_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_029_032_oRDR_DETECTION_029_032_oPCAN_RADAR_028425de_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_029_032_oRDR_DETECTION_029_032_oPCAN_RADAR_028425de_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_033_036_AL_Vdp_SG_Detections_033_036_AL(P2CONST(I_SG_Detections_033_036_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_033_036_oRDR_DETECTION_033_036_oPCAN_RADAR_308f4df6_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_033_036_oRDR_DETECTION_033_036_oPCAN_RADAR_308f4df6_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_037_040_AL_Vdp_SG_Detections_037_040_AL(P2CONST(I_SG_Detections_037_040_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_037_040_oRDR_DETECTION_037_040_oPCAN_RADAR_abdcc2d8_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_037_040_oRDR_DETECTION_037_040_oPCAN_RADAR_abdcc2d8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_041_044_AL_Vdp_SG_Detections_041_044_AL(P2CONST(I_SG_Detections_041_044_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_041_044_oRDR_DETECTION_041_044_oPCAN_RADAR_b5a3d501_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_041_044_oRDR_DETECTION_041_044_oPCAN_RADAR_b5a3d501_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_045_048_AL_Vdp_SG_Detections_045_048_AL(P2CONST(I_SG_Detections_045_048_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_045_048_oRDR_DETECTION_045_048_oPCAN_RADAR_c460e153_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_045_048_oRDR_DETECTION_045_048_oPCAN_RADAR_c460e153_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_049_052_AL_Vdp_SG_Detections_049_052_AL(P2CONST(I_SG_Detections_049_052_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_049_052_oRDR_DETECTION_049_052_oPCAN_RADAR_5d1ac528_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_049_052_oRDR_DETECTION_049_052_oPCAN_RADAR_5d1ac528_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_053_056_AL_Vdp_SG_Detections_053_056_AL(P2CONST(I_SG_Detections_053_056_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_053_056_oRDR_DETECTION_053_056_oPCAN_RADAR_6f11ad00_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_053_056_oRDR_DETECTION_053_056_oPCAN_RADAR_6f11ad00_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_057_060_AL_Vdp_SG_Detections_057_060_AL(P2CONST(I_SG_Detections_057_060_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_057_060_oRDR_DETECTION_057_060_oPCAN_RADAR_83bdfb8a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_057_060_oRDR_DETECTION_057_060_oPCAN_RADAR_83bdfb8a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_061_064_AL_Vdp_SG_Detections_061_064_AL(P2CONST(I_SG_Detections_061_064_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_061_064_oRDR_DETECTION_061_064_oPCAN_RADAR_80d67553_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_061_064_oRDR_DETECTION_061_064_oPCAN_RADAR_80d67553_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_065_068_AL_Vdp_SG_Detections_065_068_AL(P2CONST(I_SG_Detections_065_068_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_065_068_oRDR_DETECTION_065_068_oPCAN_RADAR_f1154101_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_065_068_oRDR_DETECTION_065_068_oPCAN_RADAR_f1154101_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_069_072_AL_Vdp_SG_Detections_069_072_AL(P2CONST(I_SG_Detections_069_072_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_069_072_oRDR_DETECTION_069_072_oPCAN_RADAR_686f657a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_069_072_oRDR_DETECTION_069_072_oPCAN_RADAR_686f657a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_073_076_AL_Vdp_SG_Detections_073_076_AL(P2CONST(I_SG_Detections_073_076_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_073_076_oRDR_DETECTION_073_076_oPCAN_RADAR_5a640d52_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_073_076_oRDR_DETECTION_073_076_oPCAN_RADAR_5a640d52_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_077_080_AL_Vdp_SG_Detections_077_080_AL(P2CONST(I_SG_Detections_077_080_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_077_080_oRDR_DETECTION_077_080_oPCAN_RADAR_2ec83134_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_077_080_oRDR_DETECTION_077_080_oPCAN_RADAR_2ec83134_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_081_084_AL_Vdp_SG_Detections_081_084_AL(P2CONST(I_SG_Detections_081_084_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_081_084_oRDR_DETECTION_081_084_oPCAN_RADAR_0a9e14ed_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_081_084_oRDR_DETECTION_081_084_oPCAN_RADAR_0a9e14ed_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_085_088_AL_Vdp_SG_Detections_085_088_AL(P2CONST(I_SG_Detections_085_088_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_085_088_oRDR_DETECTION_085_088_oPCAN_RADAR_7b5d20bf_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_085_088_oRDR_DETECTION_085_088_oPCAN_RADAR_7b5d20bf_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_089_092_AL_Vdp_SG_Detections_089_092_AL(P2CONST(I_SG_Detections_089_092_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_089_092_oRDR_DETECTION_089_092_oPCAN_RADAR_e22704c4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_089_092_oRDR_DETECTION_089_092_oPCAN_RADAR_e22704c4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_093_096_AL_Vdp_SG_Detections_093_096_AL(P2CONST(I_SG_Detections_093_096_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_093_096_oRDR_DETECTION_093_096_oPCAN_RADAR_d02c6cec_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_093_096_oRDR_DETECTION_093_096_oPCAN_RADAR_d02c6cec_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_097_100_AL_Vdp_SG_Detections_097_100_AL(P2CONST(I_SG_Detections_097_100_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_097_100_oRDR_DETECTION_097_100_oPCAN_RADAR_dcf343f6_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_097_100_oRDR_DETECTION_097_100_oPCAN_RADAR_dcf343f6_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_101_104_AL_Vdp_SG_Detections_101_104_AL(P2CONST(I_SG_Detections_101_104_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_101_104_oRDR_DETECTION_101_104_oPCAN_RADAR_9de0b719_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_101_104_oRDR_DETECTION_101_104_oPCAN_RADAR_9de0b719_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_105_108_AL_Vdp_SG_Detections_105_108_AL(P2CONST(I_SG_Detections_105_108_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_105_108_oRDR_DETECTION_105_108_oPCAN_RADAR_ec23834b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_105_108_oRDR_DETECTION_105_108_oPCAN_RADAR_ec23834b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_109_112_AL_Vdp_SG_Detections_109_112_AL(P2CONST(I_SG_Detections_109_112_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_109_112_oRDR_DETECTION_109_112_oPCAN_RADAR_7559a730_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_109_112_oRDR_DETECTION_109_112_oPCAN_RADAR_7559a730_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_113_116_AL_Vdp_SG_Detections_113_116_AL(P2CONST(I_SG_Detections_113_116_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_113_116_oRDR_DETECTION_113_116_oPCAN_RADAR_4752cf18_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_113_116_oRDR_DETECTION_113_116_oPCAN_RADAR_4752cf18_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_117_120_AL_Vdp_SG_Detections_117_120_AL(P2CONST(I_SG_Detections_117_120_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_117_120_oRDR_DETECTION_117_120_oPCAN_RADAR_abfe9992_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_117_120_oRDR_DETECTION_117_120_oPCAN_RADAR_abfe9992_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_121_124_AL_Vdp_SG_Detections_121_124_AL(P2CONST(I_SG_Detections_121_124_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_121_124_oRDR_DETECTION_121_124_oPCAN_RADAR_a895174b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_121_124_oRDR_DETECTION_121_124_oPCAN_RADAR_a895174b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_125_128_AL_Vdp_SG_Detections_125_128_AL(P2CONST(I_SG_Detections_125_128_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_125_128_oRDR_DETECTION_125_128_oPCAN_RADAR_d9562319_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_125_128_oRDR_DETECTION_125_128_oPCAN_RADAR_d9562319_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_129_132_AL_Vdp_SG_Detections_129_132_AL(P2CONST(I_SG_Detections_129_132_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_129_132_oRDR_DETECTION_129_132_oPCAN_RADAR_402c0762_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_129_132_oRDR_DETECTION_129_132_oPCAN_RADAR_402c0762_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_133_136_AL_Vdp_SG_Detections_133_136_AL(P2CONST(I_SG_Detections_133_136_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_133_136_oRDR_DETECTION_133_136_oPCAN_RADAR_72276f4a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_133_136_oRDR_DETECTION_133_136_oPCAN_RADAR_72276f4a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_137_140_AL_Vdp_SG_Detections_137_140_AL(P2CONST(I_SG_Detections_137_140_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_137_140_oRDR_DETECTION_137_140_oPCAN_RADAR_e974e064_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_137_140_oRDR_DETECTION_137_140_oPCAN_RADAR_e974e064_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_141_144_AL_Vdp_SG_Detections_141_144_AL(P2CONST(I_SG_Detections_141_144_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_141_144_oRDR_DETECTION_141_144_oPCAN_RADAR_f70bf7bd_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_141_144_oRDR_DETECTION_141_144_oPCAN_RADAR_f70bf7bd_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_145_148_AL_Vdp_SG_Detections_145_148_AL(P2CONST(I_SG_Detections_145_148_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_145_148_oRDR_DETECTION_145_148_oPCAN_RADAR_86c8c3ef_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_145_148_oRDR_DETECTION_145_148_oPCAN_RADAR_86c8c3ef_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_149_152_AL_Vdp_SG_Detections_149_152_AL(P2CONST(I_SG_Detections_149_152_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_149_152_oRDR_DETECTION_149_152_oPCAN_RADAR_1fb2e794_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_149_152_oRDR_DETECTION_149_152_oPCAN_RADAR_1fb2e794_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_153_156_AL_Vdp_SG_Detections_153_156_AL(P2CONST(I_SG_Detections_153_156_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_153_156_oRDR_DETECTION_153_156_oPCAN_RADAR_2db98fbc_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_153_156_oRDR_DETECTION_153_156_oPCAN_RADAR_2db98fbc_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_157_160_AL_Vdp_SG_Detections_157_160_AL(P2CONST(I_SG_Detections_157_160_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_157_160_oRDR_DETECTION_157_160_oPCAN_RADAR_c115d936_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_157_160_oRDR_DETECTION_157_160_oPCAN_RADAR_c115d936_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_161_164_AL_Vdp_SG_Detections_161_164_AL(P2CONST(I_SG_Detections_161_164_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_161_164_oRDR_DETECTION_161_164_oPCAN_RADAR_c27e57ef_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_161_164_oRDR_DETECTION_161_164_oPCAN_RADAR_c27e57ef_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_165_168_AL_Vdp_SG_Detections_165_168_AL(P2CONST(I_SG_Detections_165_168_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_165_168_oRDR_DETECTION_165_168_oPCAN_RADAR_b3bd63bd_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_165_168_oRDR_DETECTION_165_168_oPCAN_RADAR_b3bd63bd_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_169_172_AL_Vdp_SG_Detections_169_172_AL(P2CONST(I_SG_Detections_169_172_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_169_172_oRDR_DETECTION_169_172_oPCAN_RADAR_2ac747c6_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_169_172_oRDR_DETECTION_169_172_oPCAN_RADAR_2ac747c6_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_173_176_AL_Vdp_SG_Detections_173_176_AL(P2CONST(I_SG_Detections_173_176_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_173_176_oRDR_DETECTION_173_176_oPCAN_RADAR_18cc2fee_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_173_176_oRDR_DETECTION_173_176_oPCAN_RADAR_18cc2fee_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_177_180_AL_Vdp_SG_Detections_177_180_AL(P2CONST(I_SG_Detections_177_180_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_177_180_oRDR_DETECTION_177_180_oPCAN_RADAR_6c601388_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_177_180_oRDR_DETECTION_177_180_oPCAN_RADAR_6c601388_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_181_184_AL_Vdp_SG_Detections_181_184_AL(P2CONST(I_SG_Detections_181_184_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_181_184_oRDR_DETECTION_181_184_oPCAN_RADAR_48363651_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_181_184_oRDR_DETECTION_181_184_oPCAN_RADAR_48363651_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_185_188_AL_Vdp_SG_Detections_185_188_AL(P2CONST(I_SG_Detections_185_188_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_185_188_oRDR_DETECTION_185_188_oPCAN_RADAR_39f50203_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_185_188_oRDR_DETECTION_185_188_oPCAN_RADAR_39f50203_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_189_192_AL_Vdp_SG_Detections_189_192_AL(P2CONST(I_SG_Detections_189_192_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_189_192_oRDR_DETECTION_189_192_oPCAN_RADAR_a08f2678_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_189_192_oRDR_DETECTION_189_192_oPCAN_RADAR_a08f2678_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_193_196_AL_Vdp_SG_Detections_193_196_AL(P2CONST(I_SG_Detections_193_196_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_193_196_oRDR_DETECTION_193_196_oPCAN_RADAR_92844e50_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_193_196_oRDR_DETECTION_193_196_oPCAN_RADAR_92844e50_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_197_200_AL_Vdp_SG_Detections_197_200_AL(P2CONST(I_SG_Detections_197_200_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_197_200_oRDR_DETECTION_197_200_oPCAN_RADAR_f6bd2d5e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_197_200_oRDR_DETECTION_197_200_oPCAN_RADAR_f6bd2d5e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_201_204_AL_Vdp_SG_Detections_201_204_AL(P2CONST(I_SG_Detections_201_204_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_201_204_oRDR_DETECTION_201_204_oPCAN_RADAR_5a18d0dd_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_201_204_oRDR_DETECTION_201_204_oPCAN_RADAR_5a18d0dd_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_205_208_AL_Vdp_SG_Detections_205_208_AL(P2CONST(I_SG_Detections_205_208_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_205_208_oRDR_DETECTION_205_208_oPCAN_RADAR_2bdbe48f_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_205_208_oRDR_DETECTION_205_208_oPCAN_RADAR_2bdbe48f_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_209_212_AL_Vdp_SG_Detections_209_212_AL(P2CONST(I_SG_Detections_209_212_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_209_212_oRDR_DETECTION_209_212_oPCAN_RADAR_b2a1c0f4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_209_212_oRDR_DETECTION_209_212_oPCAN_RADAR_b2a1c0f4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_213_216_AL_Vdp_SG_Detections_213_216_AL(P2CONST(I_SG_Detections_213_216_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_213_216_oRDR_DETECTION_213_216_oPCAN_RADAR_80aaa8dc_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_213_216_oRDR_DETECTION_213_216_oPCAN_RADAR_80aaa8dc_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_217_220_AL_Vdp_SG_Detections_217_220_AL(P2CONST(I_SG_Detections_217_220_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_217_220_oRDR_DETECTION_217_220_oPCAN_RADAR_6c06fe56_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_217_220_oRDR_DETECTION_217_220_oPCAN_RADAR_6c06fe56_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_221_224_AL_Vdp_SG_Detections_221_224_AL(P2CONST(I_SG_Detections_221_224_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_221_224_oRDR_DETECTION_221_224_oPCAN_RADAR_6f6d708f_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_221_224_oRDR_DETECTION_221_224_oPCAN_RADAR_6f6d708f_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_225_228_AL_Vdp_SG_Detections_225_228_AL(P2CONST(I_SG_Detections_225_228_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_225_228_oRDR_DETECTION_225_228_oPCAN_RADAR_1eae44dd_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_225_228_oRDR_DETECTION_225_228_oPCAN_RADAR_1eae44dd_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_229_232_AL_Vdp_SG_Detections_229_232_AL(P2CONST(I_SG_Detections_229_232_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_229_232_oRDR_DETECTION_229_232_oPCAN_RADAR_87d460a6_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_229_232_oRDR_DETECTION_229_232_oPCAN_RADAR_87d460a6_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_233_236_AL_Vdp_SG_Detections_233_236_AL(P2CONST(I_SG_Detections_233_236_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_233_236_oRDR_DETECTION_233_236_oPCAN_RADAR_b5df088e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_233_236_oRDR_DETECTION_233_236_oPCAN_RADAR_b5df088e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_237_240_AL_Vdp_SG_Detections_237_240_AL(P2CONST(I_SG_Detections_237_240_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_237_240_oRDR_DETECTION_237_240_oPCAN_RADAR_2e8c87a0_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_237_240_oRDR_DETECTION_237_240_oPCAN_RADAR_2e8c87a0_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_241_244_AL_Vdp_SG_Detections_241_244_AL(P2CONST(I_SG_Detections_241_244_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_241_244_oRDR_DETECTION_241_244_oPCAN_RADAR_30f39079_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_241_244_oRDR_DETECTION_241_244_oPCAN_RADAR_30f39079_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_245_248_AL_Vdp_SG_Detections_245_248_AL(P2CONST(I_SG_Detections_245_248_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_245_248_oRDR_DETECTION_245_248_oPCAN_RADAR_4130a42b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_245_248_oRDR_DETECTION_245_248_oPCAN_RADAR_4130a42b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_249_252_AL_Vdp_SG_Detections_249_252_AL(P2CONST(I_SG_Detections_249_252_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_249_252_oRDR_DETECTION_249_252_oPCAN_RADAR_d84a8050_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_249_252_oRDR_DETECTION_249_252_oPCAN_RADAR_d84a8050_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_253_256_AL_Vdp_SG_Detections_253_256_AL(P2CONST(I_SG_Detections_253_256_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_253_256_oRDR_DETECTION_253_256_oPCAN_RADAR_ea41e878_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_253_256_oRDR_DETECTION_253_256_oPCAN_RADAR_ea41e878_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_257_260_AL_Vdp_SG_Detections_257_260_AL(P2CONST(I_SG_Detections_257_260_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_257_260_oRDR_DETECTION_257_260_oPCAN_RADAR_06edbef2_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_257_260_oRDR_DETECTION_257_260_oPCAN_RADAR_06edbef2_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_261_264_AL_Vdp_SG_Detections_261_264_AL(P2CONST(I_SG_Detections_261_264_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_261_264_oRDR_DETECTION_261_264_oPCAN_RADAR_0586302b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_261_264_oRDR_DETECTION_261_264_oPCAN_RADAR_0586302b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_265_268_AL_Vdp_SG_Detections_265_268_AL(P2CONST(I_SG_Detections_265_268_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_265_268_oRDR_DETECTION_265_268_oPCAN_RADAR_74450479_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_265_268_oRDR_DETECTION_265_268_oPCAN_RADAR_74450479_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_269_272_AL_Vdp_SG_Detections_269_272_AL(P2CONST(I_SG_Detections_269_272_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_269_272_oRDR_DETECTION_269_272_oPCAN_RADAR_ed3f2002_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_269_272_oRDR_DETECTION_269_272_oPCAN_RADAR_ed3f2002_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_273_276_AL_Vdp_SG_Detections_273_276_AL(P2CONST(I_SG_Detections_273_276_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_273_276_oRDR_DETECTION_273_276_oPCAN_RADAR_df34482a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_273_276_oRDR_DETECTION_273_276_oPCAN_RADAR_df34482a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_277_280_AL_Vdp_SG_Detections_277_280_AL(P2CONST(I_SG_Detections_277_280_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_277_280_oRDR_DETECTION_277_280_oPCAN_RADAR_ab98744c_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_277_280_oRDR_DETECTION_277_280_oPCAN_RADAR_ab98744c_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_281_284_AL_Vdp_SG_Detections_281_284_AL(P2CONST(I_SG_Detections_281_284_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_281_284_oRDR_DETECTION_281_284_oPCAN_RADAR_8fce5195_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_281_284_oRDR_DETECTION_281_284_oPCAN_RADAR_8fce5195_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_285_288_AL_Vdp_SG_Detections_285_288_AL(P2CONST(I_SG_Detections_285_288_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_285_288_oRDR_DETECTION_285_288_oPCAN_RADAR_fe0d65c7_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_285_288_oRDR_DETECTION_285_288_oPCAN_RADAR_fe0d65c7_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_289_292_AL_Vdp_SG_Detections_289_292_AL(P2CONST(I_SG_Detections_289_292_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_289_292_oRDR_DETECTION_289_292_oPCAN_RADAR_677741bc_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_289_292_oRDR_DETECTION_289_292_oPCAN_RADAR_677741bc_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_293_296_AL_Vdp_SG_Detections_293_296_AL(P2CONST(I_SG_Detections_293_296_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_293_296_oRDR_DETECTION_293_296_oPCAN_RADAR_557c2994_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_293_296_oRDR_DETECTION_293_296_oPCAN_RADAR_557c2994_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_297_300_AL_Vdp_SG_Detections_297_300_AL(P2CONST(I_SG_Detections_297_300_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_297_300_oRDR_DETECTION_297_300_oPCAN_RADAR_59a3068e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_297_300_oRDR_DETECTION_297_300_oPCAN_RADAR_59a3068e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_301_304_AL_Vdp_SG_Detections_301_304_AL(P2CONST(I_SG_Detections_301_304_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_301_304_oRDR_DETECTION_301_304_oPCAN_RADAR_18b0f261_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_301_304_oRDR_DETECTION_301_304_oPCAN_RADAR_18b0f261_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_305_308_AL_Vdp_SG_Detections_305_308_AL(P2CONST(I_SG_Detections_305_308_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_305_308_oRDR_DETECTION_305_308_oPCAN_RADAR_6973c633_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_305_308_oRDR_DETECTION_305_308_oPCAN_RADAR_6973c633_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_309_312_AL_Vdp_SG_Detections_309_312_AL(P2CONST(I_SG_Detections_309_312_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_309_312_oRDR_DETECTION_309_312_oPCAN_RADAR_f009e248_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_309_312_oRDR_DETECTION_309_312_oPCAN_RADAR_f009e248_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_313_316_AL_Vdp_SG_Detections_313_316_AL(P2CONST(I_SG_Detections_313_316_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_313_316_oRDR_DETECTION_313_316_oPCAN_RADAR_c2028a60_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_313_316_oRDR_DETECTION_313_316_oPCAN_RADAR_c2028a60_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_317_320_AL_Vdp_SG_Detections_317_320_AL(P2CONST(I_SG_Detections_317_320_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_317_320_oRDR_DETECTION_317_320_oPCAN_RADAR_2eaedcea_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_317_320_oRDR_DETECTION_317_320_oPCAN_RADAR_2eaedcea_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_321_324_AL_Vdp_SG_Detections_321_324_AL(P2CONST(I_SG_Detections_321_324_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_321_324_oRDR_DETECTION_321_324_oPCAN_RADAR_2dc55233_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_321_324_oRDR_DETECTION_321_324_oPCAN_RADAR_2dc55233_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_325_328_AL_Vdp_SG_Detections_325_328_AL(P2CONST(I_SG_Detections_325_328_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_325_328_oRDR_DETECTION_325_328_oPCAN_RADAR_5c066661_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_325_328_oRDR_DETECTION_325_328_oPCAN_RADAR_5c066661_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_329_332_AL_Vdp_SG_Detections_329_332_AL(P2CONST(I_SG_Detections_329_332_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_329_332_oRDR_DETECTION_329_332_oPCAN_RADAR_c57c421a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_329_332_oRDR_DETECTION_329_332_oPCAN_RADAR_c57c421a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_333_336_AL_Vdp_SG_Detections_333_336_AL(P2CONST(I_SG_Detections_333_336_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_333_336_oRDR_DETECTION_333_336_oPCAN_RADAR_f7772a32_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_333_336_oRDR_DETECTION_333_336_oPCAN_RADAR_f7772a32_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_337_340_AL_Vdp_SG_Detections_337_340_AL(P2CONST(I_SG_Detections_337_340_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_337_340_oRDR_DETECTION_337_340_oPCAN_RADAR_6c24a51c_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_337_340_oRDR_DETECTION_337_340_oPCAN_RADAR_6c24a51c_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_341_344_AL_Vdp_SG_Detections_341_344_AL(P2CONST(I_SG_Detections_341_344_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_341_344_oRDR_DETECTION_341_344_oPCAN_RADAR_725bb2c5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_341_344_oRDR_DETECTION_341_344_oPCAN_RADAR_725bb2c5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_345_348_AL_Vdp_SG_Detections_345_348_AL(P2CONST(I_SG_Detections_345_348_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_345_348_oRDR_DETECTION_345_348_oPCAN_RADAR_03988697_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_345_348_oRDR_DETECTION_345_348_oPCAN_RADAR_03988697_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_349_352_AL_Vdp_SG_Detections_349_352_AL(P2CONST(I_SG_Detections_349_352_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_349_352_oRDR_DETECTION_349_352_oPCAN_RADAR_9ae2a2ec_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_349_352_oRDR_DETECTION_349_352_oPCAN_RADAR_9ae2a2ec_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_353_356_AL_Vdp_SG_Detections_353_356_AL(P2CONST(I_SG_Detections_353_356_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_353_356_oRDR_DETECTION_353_356_oPCAN_RADAR_a8e9cac4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_353_356_oRDR_DETECTION_353_356_oPCAN_RADAR_a8e9cac4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_357_360_AL_Vdp_SG_Detections_357_360_AL(P2CONST(I_SG_Detections_357_360_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_357_360_oRDR_DETECTION_357_360_oPCAN_RADAR_44459c4e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_357_360_oRDR_DETECTION_357_360_oPCAN_RADAR_44459c4e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_361_364_AL_Vdp_SG_Detections_361_364_AL(P2CONST(I_SG_Detections_361_364_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_361_364_oRDR_DETECTION_361_364_oPCAN_RADAR_472e1297_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_361_364_oRDR_DETECTION_361_364_oPCAN_RADAR_472e1297_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_365_368_AL_Vdp_SG_Detections_365_368_AL(P2CONST(I_SG_Detections_365_368_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_365_368_oRDR_DETECTION_365_368_oPCAN_RADAR_36ed26c5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_365_368_oRDR_DETECTION_365_368_oPCAN_RADAR_36ed26c5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_369_372_AL_Vdp_SG_Detections_369_372_AL(P2CONST(I_SG_Detections_369_372_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_369_372_oRDR_DETECTION_369_372_oPCAN_RADAR_af9702be_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_369_372_oRDR_DETECTION_369_372_oPCAN_RADAR_af9702be_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_373_376_AL_Vdp_SG_Detections_373_376_AL(P2CONST(I_SG_Detections_373_376_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_373_376_oRDR_DETECTION_373_376_oPCAN_RADAR_9d9c6a96_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_373_376_oRDR_DETECTION_373_376_oPCAN_RADAR_9d9c6a96_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_377_380_AL_Vdp_SG_Detections_377_380_AL(P2CONST(I_SG_Detections_377_380_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_377_380_oRDR_DETECTION_377_380_oPCAN_RADAR_e93056f0_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_377_380_oRDR_DETECTION_377_380_oPCAN_RADAR_e93056f0_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_381_384_AL_Vdp_SG_Detections_381_384_AL(P2CONST(I_SG_Detections_381_384_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_381_384_oRDR_DETECTION_381_384_oPCAN_RADAR_cd667329_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_381_384_oRDR_DETECTION_381_384_oPCAN_RADAR_cd667329_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_385_388_AL_Vdp_SG_Detections_385_388_AL(P2CONST(I_SG_Detections_385_388_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_385_388_oRDR_DETECTION_385_388_oPCAN_RADAR_bca5477b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_385_388_oRDR_DETECTION_385_388_oPCAN_RADAR_bca5477b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_389_392_AL_Vdp_SG_Detections_389_392_AL(P2CONST(I_SG_Detections_389_392_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_389_392_oRDR_DETECTION_389_392_oPCAN_RADAR_25df6300_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_389_392_oRDR_DETECTION_389_392_oPCAN_RADAR_25df6300_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_393_396_AL_Vdp_SG_Detections_393_396_AL(P2CONST(I_SG_Detections_393_396_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_393_396_oRDR_DETECTION_393_396_oPCAN_RADAR_17d40b28_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_393_396_oRDR_DETECTION_393_396_oPCAN_RADAR_17d40b28_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_397_400_AL_Vdp_SG_Detections_397_400_AL(P2CONST(I_SG_Detections_397_400_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[60U];

  ret = ComXf_Com_SG_Detections_397_400_oRDR_DETECTION_397_400_oPCAN_RADAR_a221f00e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 60U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_Detections_397_400_oRDR_DETECTION_397_400_oPCAN_RADAR_a221f00e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_GW_prop_ADAS_BSIS_info_ALPCAN_Vdp_SG_GW_prop_ADAS_BSIS_info_ALPCAN(P2CONST(I_SG_GW_prop_ADAS_BSIS_info_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[1U];

  ret = ComXf_Com_SG_GW_prop_ADAS_BSIS_info_oGW_prop_ADAS_BSIS_info_oPCAN_RADAR_e9da8865_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 1U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_GW_prop_ADAS_BSIS_info_oGW_prop_ADAS_BSIS_info_oPCAN_RADAR_e9da8865_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_MOIS_ALVCAN_Vdp_SG_MOIS_ALVCAN(P2CONST(I_SG_MOIS_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[1U];

  ret = ComXf_Com_SG_MOIS_oMOIS_oVCAN_RADAR_f9ec408e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 1U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_MOIS_oMOIS_oVCAN_RADAR_f9ec408e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RDR_BSD1_Tx_ALPCAN_Vdp_SG_RDR_BSD1_Tx_ALPCAN(P2CONST(I_SG_RDR_BSD1_Tx_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[1U];

  ret = ComXf_Com_SG_RDR_BSD1_Tx_oRDR_BSD1_Tx_oPCAN_RADAR_bd131ac1_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 1U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RDR_BSD1_Tx_oRDR_BSD1_Tx_oPCAN_RADAR_bd131ac1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL(P2CONST(I_SG_RadarCapability_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[27U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 27U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_Com_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 27U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarCapability_oRDR_CAPABILITY_oPCAN_RADAR_be2920f1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN(P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[64U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 64U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_Com_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 64U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarHeader_oRDR_HEADER_001_oPCAN_RADAR_48334d97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN(P2CONST(I_SG_RadarStatus1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 63U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_Com_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus1_oRDR_STATUS_001_oPCAN_RADAR_4935b1b8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL(P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[50U];

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    retTransformer = ComXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      lengthBuffer = 50U;
      retTransformer |= E2EXf_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_Com_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    lengthSendBuffer = lengthBuffer;
    if ((lengthSendBuffer <= 50U) && (!Rte_IsHardTransformerError(retTransformer)))
    {
      ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_RadarStatus2_oRDR_STATUS_002_oPCAN_RADAR_51f7b61a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      if ((ret == RTE_E_OK) && (retTransformer != RTE_E_OK))
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
    else
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader(P2CONST(SG_TrackerHeader_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[20U];

  ret = ComXf_Com_SG_TrackerHeader_oRDR_OBJ_HEADER_002_oPCAN_RADAR_563ddea3_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 20U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerHeader_oRDR_OBJ_HEADER_002_oPCAN_RADAR_563ddea3_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject001_oRDR_TRACKER_OBJ_001_oPCAN_RADAR_a5be7e9d_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject002_Vdp_SG_TrackerObject002(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject002_oRDR_TRACKER_OBJ_002_oPCAN_RADAR_75f2e109_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject002_oRDR_TRACKER_OBJ_002_oPCAN_RADAR_75f2e109_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject003_Vdp_SG_TrackerObject003(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject003_oRDR_TRACKER_OBJ_003_oPCAN_RADAR_8ce669ba_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject003_oRDR_TRACKER_OBJ_003_oPCAN_RADAR_8ce669ba_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject004_Vdp_SG_TrackerObject004(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject004_oRDR_TRACKER_OBJ_004_oPCAN_RADAR_0e1ad860_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject004_oRDR_TRACKER_OBJ_004_oPCAN_RADAR_0e1ad860_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject005_Vdp_SG_TrackerObject005(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject005_oRDR_TRACKER_OBJ_005_oPCAN_RADAR_f70e50d3_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject005_oRDR_TRACKER_OBJ_005_oPCAN_RADAR_f70e50d3_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject006_Vdp_SG_TrackerObject006(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject006_oRDR_TRACKER_OBJ_006_oPCAN_RADAR_2742cf47_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject006_oRDR_TRACKER_OBJ_006_oPCAN_RADAR_2742cf47_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject007_Vdp_SG_TrackerObject007(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject007_oRDR_TRACKER_OBJ_007_oPCAN_RADAR_de5647f4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject007_oRDR_TRACKER_OBJ_007_oPCAN_RADAR_de5647f4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject008_Vdp_SG_TrackerObject008(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject008_oRDR_TRACKER_OBJ_008_oPCAN_RADAR_f9caaab2_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject008_oRDR_TRACKER_OBJ_008_oPCAN_RADAR_f9caaab2_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject009_Vdp_SG_TrackerObject009(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject009_oRDR_TRACKER_OBJ_009_oPCAN_RADAR_00de2201_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject009_oRDR_TRACKER_OBJ_009_oPCAN_RADAR_00de2201_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject010_Vdp_SG_TrackerObject010(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject010_oRDR_TRACKER_OBJ_010_oPCAN_RADAR_0e3b0090_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject010_oRDR_TRACKER_OBJ_010_oPCAN_RADAR_0e3b0090_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject011_Vdp_SG_TrackerObject011(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject011_oRDR_TRACKER_OBJ_011_oPCAN_RADAR_f72f8823_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject011_oRDR_TRACKER_OBJ_011_oPCAN_RADAR_f72f8823_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject012_Vdp_SG_TrackerObject012(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject012_oRDR_TRACKER_OBJ_012_oPCAN_RADAR_276317b7_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject012_oRDR_TRACKER_OBJ_012_oPCAN_RADAR_276317b7_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject013_Vdp_SG_TrackerObject013(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject013_oRDR_TRACKER_OBJ_013_oPCAN_RADAR_de779f04_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject013_oRDR_TRACKER_OBJ_013_oPCAN_RADAR_de779f04_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject014_Vdp_SG_TrackerObject014(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject014_oRDR_TRACKER_OBJ_014_oPCAN_RADAR_5c8b2ede_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject014_oRDR_TRACKER_OBJ_014_oPCAN_RADAR_5c8b2ede_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject015_Vdp_SG_TrackerObject015(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject015_oRDR_TRACKER_OBJ_015_oPCAN_RADAR_a59fa66d_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject015_oRDR_TRACKER_OBJ_015_oPCAN_RADAR_a59fa66d_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject016_Vdp_SG_TrackerObject016(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject016_oRDR_TRACKER_OBJ_016_oPCAN_RADAR_75d339f9_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject016_oRDR_TRACKER_OBJ_016_oPCAN_RADAR_75d339f9_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject017_Vdp_SG_TrackerObject017(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject017_oRDR_TRACKER_OBJ_017_oPCAN_RADAR_8cc7b14a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject017_oRDR_TRACKER_OBJ_017_oPCAN_RADAR_8cc7b14a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject018_Vdp_SG_TrackerObject018(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject018_oRDR_TRACKER_OBJ_018_oPCAN_RADAR_ab5b5c0c_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject018_oRDR_TRACKER_OBJ_018_oPCAN_RADAR_ab5b5c0c_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject019_Vdp_SG_TrackerObject019(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject019_oRDR_TRACKER_OBJ_019_oPCAN_RADAR_524fd4bf_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject019_oRDR_TRACKER_OBJ_019_oPCAN_RADAR_524fd4bf_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject020_Vdp_SG_TrackerObject020(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject020_oRDR_TRACKER_OBJ_020_oPCAN_RADAR_f9891b52_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject020_oRDR_TRACKER_OBJ_020_oPCAN_RADAR_f9891b52_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject021_Vdp_SG_TrackerObject021(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject021_oRDR_TRACKER_OBJ_021_oPCAN_RADAR_009d93e1_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject021_oRDR_TRACKER_OBJ_021_oPCAN_RADAR_009d93e1_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject022_Vdp_SG_TrackerObject022(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject022_oRDR_TRACKER_OBJ_022_oPCAN_RADAR_d0d10c75_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject022_oRDR_TRACKER_OBJ_022_oPCAN_RADAR_d0d10c75_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject023_Vdp_SG_TrackerObject023(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject023_oRDR_TRACKER_OBJ_023_oPCAN_RADAR_29c584c6_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject023_oRDR_TRACKER_OBJ_023_oPCAN_RADAR_29c584c6_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject024_Vdp_SG_TrackerObject024(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject024_oRDR_TRACKER_OBJ_024_oPCAN_RADAR_ab39351c_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject024_oRDR_TRACKER_OBJ_024_oPCAN_RADAR_ab39351c_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject025_Vdp_SG_TrackerObject025(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject025_oRDR_TRACKER_OBJ_025_oPCAN_RADAR_522dbdaf_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject025_oRDR_TRACKER_OBJ_025_oPCAN_RADAR_522dbdaf_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject026_Vdp_SG_TrackerObject026(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject026_oRDR_TRACKER_OBJ_026_oPCAN_RADAR_8261223b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject026_oRDR_TRACKER_OBJ_026_oPCAN_RADAR_8261223b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject027_Vdp_SG_TrackerObject027(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject027_oRDR_TRACKER_OBJ_027_oPCAN_RADAR_7b75aa88_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject027_oRDR_TRACKER_OBJ_027_oPCAN_RADAR_7b75aa88_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject028_Vdp_SG_TrackerObject028(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject028_oRDR_TRACKER_OBJ_028_oPCAN_RADAR_5ce947ce_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject028_oRDR_TRACKER_OBJ_028_oPCAN_RADAR_5ce947ce_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject029_Vdp_SG_TrackerObject029(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject029_oRDR_TRACKER_OBJ_029_oPCAN_RADAR_a5fdcf7d_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject029_oRDR_TRACKER_OBJ_029_oPCAN_RADAR_a5fdcf7d_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject030_Vdp_SG_TrackerObject030(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject030_oRDR_TRACKER_OBJ_030_oPCAN_RADAR_ab18edec_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject030_oRDR_TRACKER_OBJ_030_oPCAN_RADAR_ab18edec_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject031_Vdp_SG_TrackerObject031(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject031_oRDR_TRACKER_OBJ_031_oPCAN_RADAR_520c655f_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject031_oRDR_TRACKER_OBJ_031_oPCAN_RADAR_520c655f_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject032_Vdp_SG_TrackerObject032(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject032_oRDR_TRACKER_OBJ_032_oPCAN_RADAR_8240facb_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject032_oRDR_TRACKER_OBJ_032_oPCAN_RADAR_8240facb_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject033_Vdp_SG_TrackerObject033(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject033_oRDR_TRACKER_OBJ_033_oPCAN_RADAR_7b547278_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject033_oRDR_TRACKER_OBJ_033_oPCAN_RADAR_7b547278_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject034_Vdp_SG_TrackerObject034(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject034_oRDR_TRACKER_OBJ_034_oPCAN_RADAR_f9a8c3a2_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject034_oRDR_TRACKER_OBJ_034_oPCAN_RADAR_f9a8c3a2_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject035_Vdp_SG_TrackerObject035(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject035_oRDR_TRACKER_OBJ_035_oPCAN_RADAR_00bc4b11_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject035_oRDR_TRACKER_OBJ_035_oPCAN_RADAR_00bc4b11_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject036_Vdp_SG_TrackerObject036(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject036_oRDR_TRACKER_OBJ_036_oPCAN_RADAR_d0f0d485_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject036_oRDR_TRACKER_OBJ_036_oPCAN_RADAR_d0f0d485_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject037_Vdp_SG_TrackerObject037(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject037_oRDR_TRACKER_OBJ_037_oPCAN_RADAR_29e45c36_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject037_oRDR_TRACKER_OBJ_037_oPCAN_RADAR_29e45c36_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject038_Vdp_SG_TrackerObject038(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject038_oRDR_TRACKER_OBJ_038_oPCAN_RADAR_0e78b170_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject038_oRDR_TRACKER_OBJ_038_oPCAN_RADAR_0e78b170_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject039_Vdp_SG_TrackerObject039(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject039_oRDR_TRACKER_OBJ_039_oPCAN_RADAR_f76c39c3_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject039_oRDR_TRACKER_OBJ_039_oPCAN_RADAR_f76c39c3_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject040_Vdp_SG_TrackerObject040(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject040_oRDR_TRACKER_OBJ_040_oPCAN_RADAR_cd9c2a97_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject040_oRDR_TRACKER_OBJ_040_oPCAN_RADAR_cd9c2a97_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject041_Vdp_SG_TrackerObject041(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject041_oRDR_TRACKER_OBJ_041_oPCAN_RADAR_3488a224_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject041_oRDR_TRACKER_OBJ_041_oPCAN_RADAR_3488a224_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject042_Vdp_SG_TrackerObject042(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject042_oRDR_TRACKER_OBJ_042_oPCAN_RADAR_e4c43db0_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject042_oRDR_TRACKER_OBJ_042_oPCAN_RADAR_e4c43db0_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject043_Vdp_SG_TrackerObject043(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject043_oRDR_TRACKER_OBJ_043_oPCAN_RADAR_1dd0b503_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject043_oRDR_TRACKER_OBJ_043_oPCAN_RADAR_1dd0b503_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject044_Vdp_SG_TrackerObject044(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject044_oRDR_TRACKER_OBJ_044_oPCAN_RADAR_9f2c04d9_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject044_oRDR_TRACKER_OBJ_044_oPCAN_RADAR_9f2c04d9_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject045_Vdp_SG_TrackerObject045(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject045_oRDR_TRACKER_OBJ_045_oPCAN_RADAR_66388c6a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject045_oRDR_TRACKER_OBJ_045_oPCAN_RADAR_66388c6a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject046_Vdp_SG_TrackerObject046(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject046_oRDR_TRACKER_OBJ_046_oPCAN_RADAR_b67413fe_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject046_oRDR_TRACKER_OBJ_046_oPCAN_RADAR_b67413fe_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject047_Vdp_SG_TrackerObject047(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject047_oRDR_TRACKER_OBJ_047_oPCAN_RADAR_4f609b4d_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject047_oRDR_TRACKER_OBJ_047_oPCAN_RADAR_4f609b4d_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject048_Vdp_SG_TrackerObject048(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject048_oRDR_TRACKER_OBJ_048_oPCAN_RADAR_68fc760b_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject048_oRDR_TRACKER_OBJ_048_oPCAN_RADAR_68fc760b_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject049_Vdp_SG_TrackerObject049(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject049_oRDR_TRACKER_OBJ_049_oPCAN_RADAR_91e8feb8_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject049_oRDR_TRACKER_OBJ_049_oPCAN_RADAR_91e8feb8_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject050_Vdp_SG_TrackerObject050(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject050_oRDR_TRACKER_OBJ_050_oPCAN_RADAR_9f0ddc29_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject050_oRDR_TRACKER_OBJ_050_oPCAN_RADAR_9f0ddc29_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject051_Vdp_SG_TrackerObject051(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject051_oRDR_TRACKER_OBJ_051_oPCAN_RADAR_6619549a_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject051_oRDR_TRACKER_OBJ_051_oPCAN_RADAR_6619549a_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject052_Vdp_SG_TrackerObject052(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject052_oRDR_TRACKER_OBJ_052_oPCAN_RADAR_b655cb0e_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject052_oRDR_TRACKER_OBJ_052_oPCAN_RADAR_b655cb0e_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject053_Vdp_SG_TrackerObject053(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject053_oRDR_TRACKER_OBJ_053_oPCAN_RADAR_4f4143bd_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject053_oRDR_TRACKER_OBJ_053_oPCAN_RADAR_4f4143bd_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject054_Vdp_SG_TrackerObject054(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject054_oRDR_TRACKER_OBJ_054_oPCAN_RADAR_cdbdf267_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject054_oRDR_TRACKER_OBJ_054_oPCAN_RADAR_cdbdf267_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject055_Vdp_SG_TrackerObject055(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject055_oRDR_TRACKER_OBJ_055_oPCAN_RADAR_34a97ad4_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject055_oRDR_TRACKER_OBJ_055_oPCAN_RADAR_34a97ad4_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject056_Vdp_SG_TrackerObject056(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject056_oRDR_TRACKER_OBJ_056_oPCAN_RADAR_e4e5e540_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject056_oRDR_TRACKER_OBJ_056_oPCAN_RADAR_e4e5e540_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject057_Vdp_SG_TrackerObject057(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject057_oRDR_TRACKER_OBJ_057_oPCAN_RADAR_1df16df3_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject057_oRDR_TRACKER_OBJ_057_oPCAN_RADAR_1df16df3_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject058_Vdp_SG_TrackerObject058(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject058_oRDR_TRACKER_OBJ_058_oPCAN_RADAR_3a6d80b5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject058_oRDR_TRACKER_OBJ_058_oPCAN_RADAR_3a6d80b5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject059_Vdp_SG_TrackerObject059(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject059_oRDR_TRACKER_OBJ_059_oPCAN_RADAR_c3790806_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject059_oRDR_TRACKER_OBJ_059_oPCAN_RADAR_c3790806_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject060_Vdp_SG_TrackerObject060(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject060_oRDR_TRACKER_OBJ_060_oPCAN_RADAR_68bfc7eb_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject060_oRDR_TRACKER_OBJ_060_oPCAN_RADAR_68bfc7eb_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject061_Vdp_SG_TrackerObject061(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject061_oRDR_TRACKER_OBJ_061_oPCAN_RADAR_91ab4f58_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject061_oRDR_TRACKER_OBJ_061_oPCAN_RADAR_91ab4f58_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject062_Vdp_SG_TrackerObject062(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject062_oRDR_TRACKER_OBJ_062_oPCAN_RADAR_41e7d0cc_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject062_oRDR_TRACKER_OBJ_062_oPCAN_RADAR_41e7d0cc_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject063_Vdp_SG_TrackerObject063(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject063_oRDR_TRACKER_OBJ_063_oPCAN_RADAR_b8f3587f_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject063_oRDR_TRACKER_OBJ_063_oPCAN_RADAR_b8f3587f_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject064_Vdp_SG_TrackerObject064(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[63U];

  ret = ComXf_Com_SG_TrackerObject064_oRDR_TRACKER_OBJ_064_oPCAN_RADAR_3a0fe9a5_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 63U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerObject064_oRDR_TRACKER_OBJ_064_oPCAN_RADAR_3a0fe9a5_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus(P2CONST(SG_TrackerStatus_impdt, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[13U];

  ret = ComXf_Com_SG_TrackerStatus_oRDR_OBJ_STATUS_003_oPCAN_RADAR_3d577421_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 13U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_TrackerStatus_oRDR_OBJ_STATUS_003_oPCAN_RADAR_3d577421_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2CONST(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Appl_Communication_Pp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_prop_ADAS_MOIS_info_ALVCAN_Vdp_SG_prop_ADAS_MOIS_info_ALVCAN(P2CONST(I_SG_prop_ADAS_MOIS_info_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer = 0U;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[1U];

  ret = ComXf_Com_SG_prop_ADAS_MOIS_info_oprop_ADAS_MOIS_info_oVCAN_RADAR_cb191e50_Tx(&(transformationBuffer_0[0]), &lengthBuffer, data); /* PRQA S 1340 */ /* MD_Rte_1340 */
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 1U) && (!Rte_IsHardTransformerError(ret)))
  {
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_prop_ADAS_MOIS_info_oprop_ADAS_MOIS_info_oVCAN_RADAR_cb191e50_Tx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RE_VCAN_Timeout_Faults_100ms_1000ms_Event */
  (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(P2CONST(Dt_PltToFltMgr_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults(P2CONST(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(P2CONST(Dt_Mcu_Startup_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst(P2CONST(Dt_Battery_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(P2CONST(Dt_PltToFltMgr_Host_Micro_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(P2CONST(Dt_PltToFltMgr_InterProcessor_Commn_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(P2CONST(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(P2CONST(Dt_PltToFltMgr_MMIC_B_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(P2CONST(Dt_PltToFltMgr_Memory_Diagnostics_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(P2CONST(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(P2CONST(Dt_PltToFltMgr_Blockage_Detection_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(P2CONST(Dt_Rdr_Hw_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager(P2CONST(Dt_TR_ModeManager, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_SWC_PLT_Appl_FaultMgr_Pp_Platform_FaultTestComplete_Table_De_FaultTestCompleteTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest(P2CONST(Dt_RadarDiagRequest, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData(P2CONST(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData(P2CONST(Dt_RawAdcDataFilt_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(P2CONST(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2CONST(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data(P2CONST(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load(P2CONST(Dt_CPU_Load, AUTOMATIC, RTE_SWC_PLT_APPL_RTM_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(P2CONST(Dt_ECC_Correctable_Error_Counters, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2CONST(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status(P2CONST(Dt_Hardware_Fault_Error_Status, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data(P2CONST(Dt_ID_data, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo(P2CONST(Dt_Memory_Exception_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, data, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(P2CONST(Dt_MMIC_ErrorFlags, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature(P2CONST(Idt_Type_MMIC_Temperature, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data(P2CONST(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus(P2CONST(Dt_RadarCoreStatus, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override(P2CONST(Idt_XCP_Fault_Override_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output(P2CONST(Dt_XCP_Set_Output, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(P2CONST(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record(P2CONST(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto(P2CONST(Dt_AlignmentAuto, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService(P2CONST(Dt_AlignmentService, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack(P2CONST(Dt_AlignmentShortTrack, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic(P2CONST(Dt_AlignmentStatic, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults(P2CONST(Dt_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler(P2CONST(Dt_Alignment_Handler, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data(P2CONST(Dt_Alignment_M2D_Data, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data(P2CONST(Dt_Auto_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information(P2CONST(Dt_Auto_Alignment_Status_Information, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Status_Information_De_Auto_Alignment_Status_Information = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result(P2CONST(Dt_Initial_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC(P2CONST(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Manual_Alignment_Execution_Read_From_Alignment_Data_CRC_De_Manual_Alignment_Execution_Data_CRC = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters(P2CONST(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Engineering_Non_Configuration_Parameters_De_Service_Alignment_Engineering_Non_Configuration_Parameters = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters(P2CONST(Dt_Service_Alignment_Result_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Service_Alignment_Result_Parameters_De_Service_Alignment_Result_Parameters = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T(P2CONST(DID_StaticAlignment_NonConfig_Param_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_StaticAlignment_NonConfig_Param_De_DID_StaticAlignment_NonConfig_Param_T = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters(P2CONST(Dt_Static_Alignment_Engineering_Parameters, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Static_Alignment_Engineering_Parameters_De_Static_Alignment_Engineering_Parameters = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform(P2CONST(Dt_Initial_Alignment_Performance_Result_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable(P2CONST(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, data, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation(P2CONST(Dt_CustDegradation, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown(P2CONST(Dt_OpModeShutdown, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version(P2CONST(Crypto_CustomFunctions_VersionStruct, AUTOMATIC, RTE_SWC_PRJ_APPL_SECURITY_MANAGER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_PRJ_Appl_Security_Manager_Pp_Crypto_customfuntions_version_De_Crypto_CustomFunctions_Version = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification(StbM_TimeBaseNotificationType data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_eventNotification = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: DRE_StatusNotification_Callback */
  (void)SetEvent(BSW_Task, Rte_Ev_Run_SWC_PLT_CDD_TimeSync_DRE_StatusNotification_Callback); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StbM_GlobalTime_StatusEvent_StbMSynchronizedTimeBase_CanTsync_eventNotification(StbM_TimeBaseNotificationType data) /* PRQA S 1505, 3206, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_2982 */
{
  data = data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return RTE_E_OK;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode(P2VAR(BswM_SDC_SdClientServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode(P2VAR(BswM_SDC_SdConsumedEventGroupRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Request_SDC_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Detections_89f78c9f_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_SW_Info_c2745ec9_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode(P2VAR(BswM_SDC_SdServerServiceRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Communication_Request_SDC_S_provService_RDR_1_Status_d2069d01_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output(P2VAR(Dt_XCP_Set_Output, AUTOMATIC, RTE_SWC_APPL_PROJECT_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Set_Output_State_De_XCP_Set_Output; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data(P2VAR(Dt_Alignment_M2D_Data, AUTOMATIC, RTE_SWC_CDD_IPC_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_RP_RDR_Vehicle_Status_Vehicle_Status(P2VAR(SR_VEHICLE_STATUS_RECORD, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[79U];

  if (Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx_Length == 0U)
  {
    *data = Rte_C_SR_VEHICLE_STATUS_RECORD_001B587F069B9748FB97201F8DA902CC;
  }
  else
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    lengthBuffer = Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx_Length;
    if (lengthBuffer > 79U)
    {
      lengthBuffer = 79U;
    }
    Rte_MemCpy32(transformationBuffer_0, Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx, lengthBuffer); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = SomeIpXf_Inv_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  }
  if (Rte_IsHardTransformerError(ret))
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ADAS_FN_Enable_disable_sts_ALVCAN_Vdp_SG_ADAS_FN_Enable_disable_sts_ALVCAN(P2VAR(I_SG_ADAS_FN_Enable_disable_sts_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_BSIS_Fn_Switch_Sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_8602f31d_Rx, &(*(data)).BSIS_Fn_Switch_Sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MOIS_Fn_Switch_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_ebefa562_Rx, &(*(data)).MOIS_Fn_Switch_sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageAliveCounter_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_2a6971aa_Rx, &(*(data)).MessageAliveCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageCRC_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_332c8084_Rx, &(*(data)).MessageCRC); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CCVS1_ALVCAN_Vdp_SG_CCVS1_ALVCAN(P2VAR(I_SG_CCVS1_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_BrakeSwitch_oCCVS1_oVCAN_RADAR_1059096c_Rx, &(*(data)).BrakeSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_ParkingBrakeSwitch_oCCVS1_oVCAN_RADAR_fe400b10_Rx, &(*(data)).ParkingBrakeSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_WheelBasedVehicleSpeed_oCCVS1_oVCAN_RADAR_c435b4dd_Rx, &(*(data)).WheelBasedVehicleSpeed); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_16_ALVCAN_Vdp_SG_CLS_Tx_16_ALVCAN(P2VAR(I_SG_CLS_Tx_16_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Crawler_confi_status_info_oCLS_Tx_16_oVCAN_RADAR_9635d3b9_Rx, &(*(data)).Crawler_confi_status_info); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Transmission_type_info_oCLS_Tx_16_oVCAN_RADAR_d6d97de8_Rx, &(*(data)).Transmission_type_info); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_CLS_Tx_4_ALVCAN_Vdp_SG_CLS_Tx_4_ALVCAN(P2VAR(I_SG_CLS_Tx_4_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Ignition_oCLS_Tx_4_oVCAN_RADAR_cb871f88_Rx, &(*(data)).Ignition); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_ReverseSwitchInfo_oCLS_Tx_4_oVCAN_RADAR_b4b1941a_Rx, &(*(data)).ReverseSwitchInfo); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_00_ALVCAN_Vdp_SG_ETC2_00_ALVCAN(P2VAR(I_SG_ETC2_00_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TransCurrentGear_00_oETC2_00_oVCAN_RADAR_3087ec57_Rx, &(*(data)).TransCurrentGear_00); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_ETC2_03_ALVCAN_Vdp_SG_ETC2_03_ALVCAN(P2VAR(I_SG_ETC2_03_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TransCurrentGear_03_oETC2_03_oVCAN_RADAR_b4352dd9_Rx, &(*(data)).TransCurrentGear_03); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN(P2VAR(I_SG_Fusion_AlignmentStatus1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[64U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus1_ALPCAN_Vdp_SG_Fusion_AlignmentStatus1_ALPCAN_Com_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN(P2VAR(I_SG_Fusion_AlignmentStatus2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[41U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 41U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_AlignmentStatus2_ALPCAN_Vdp_SG_Fusion_AlignmentStatus2_ALPCAN_Com_SG_Fusion_AlignmentStatus2_oRDR_FUSION_ALIGNMENT_STATUS_002_oPCAN_RADAR_13cf0319_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_001_004_AL_Vdp_SG_Fusion_Detections_001_004_AL(P2VAR(I_SG_Fusion_Detections_001_004_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_Fusion_Detections_001_004_oRDR_FUSION_DET_001_004_oPCAN_RADAR_4a788d9f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_5993bb11_Rx, &(*(data)).DET_AZIMUTH_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_732f0b99_Rx, &(*(data)).DET_AZIMUTH_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_dc6b99de_Rx, &(*(data)).DET_AZIMUTH_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_26566a89_Rx, &(*(data)).DET_AZIMUTH_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_ERR_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_5bfa1a93_Rx, &(*(data)).DET_AZIMUTH_ERR_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_ERR_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_7146aa1b_Rx, &(*(data)).DET_AZIMUTH_ERR_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_ERR_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_de02385c_Rx, &(*(data)).DET_AZIMUTH_ERR_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_AZIMUTH_ERR_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_243fcb0b_Rx, &(*(data)).DET_AZIMUTH_ERR_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BELOW_RAIN_THOLD_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_3f2944a4_Rx, &(*(data)).DET_BELOW_RAIN_THOLD_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BELOW_RAIN_THOLD_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_1595f42c_Rx, &(*(data)).DET_BELOW_RAIN_THOLD_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BELOW_RAIN_THOLD_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_bad1666b_Rx, &(*(data)).DET_BELOW_RAIN_THOLD_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BELOW_RAIN_THOLD_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_40ec953c_Rx, &(*(data)).DET_BELOW_RAIN_THOLD_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BI_STATIC_FLAG_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_48b7efb7_Rx, &(*(data)).DET_BI_STATIC_FLAG_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BI_STATIC_FLAG_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_620b5f3f_Rx, &(*(data)).DET_BI_STATIC_FLAG_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BI_STATIC_FLAG_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_cd4fcd78_Rx, &(*(data)).DET_BI_STATIC_FLAG_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_BI_STATIC_FLAG_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_37723e2f_Rx, &(*(data)).DET_BI_STATIC_FLAG_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_AZIMUTH_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_abde05e3_Rx, &(*(data)).DET_CONFD_AZIMUTH_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_AZIMUTH_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_8162b56b_Rx, &(*(data)).DET_CONFD_AZIMUTH_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_AZIMUTH_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2e26272c_Rx, &(*(data)).DET_CONFD_AZIMUTH_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_AZIMUTH_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_d41bd47b_Rx, &(*(data)).DET_CONFD_AZIMUTH_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_ELEVATION_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_a1ff8664_Rx, &(*(data)).DET_CONFD_ELEVATION_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_ELEVATION_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_8b4336ec_Rx, &(*(data)).DET_CONFD_ELEVATION_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_ELEVATION_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2407a4ab_Rx, &(*(data)).DET_CONFD_ELEVATION_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_CONFD_ELEVATION_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_de3a57fc_Rx, &(*(data)).DET_CONFD_ELEVATION_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_abac699d_Rx, &(*(data)).DET_ELEVATION_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_8110d915_Rx, &(*(data)).DET_ELEVATION_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2e544b52_Rx, &(*(data)).DET_ELEVATION_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_d469b805_Rx, &(*(data)).DET_ELEVATION_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_ERR_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_79154b42_Rx, &(*(data)).DET_ELEVATION_ERR_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_ERR_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_53a9fbca_Rx, &(*(data)).DET_ELEVATION_ERR_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_ERR_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_fced698d_Rx, &(*(data)).DET_ELEVATION_ERR_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_ELEVATION_ERR_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_06d09ada_Rx, &(*(data)).DET_ELEVATION_ERR_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_EXISTENCE_PROB_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_8e0d33d7_Rx, &(*(data)).DET_EXISTENCE_PROB_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_EXISTENCE_PROB_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_a4b1835f_Rx, &(*(data)).DET_EXISTENCE_PROB_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_EXISTENCE_PROB_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_0bf51118_Rx, &(*(data)).DET_EXISTENCE_PROB_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_EXISTENCE_PROB_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_f1c8e24f_Rx, &(*(data)).DET_EXISTENCE_PROB_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_HVC_FLAG_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_53d3de98_Rx, &(*(data)).DET_HVC_FLAG_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_HVC_FLAG_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_796f6e10_Rx, &(*(data)).DET_HVC_FLAG_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_HVC_FLAG_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_d62bfc57_Rx, &(*(data)).DET_HVC_FLAG_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_HVC_FLAG_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2c160f00_Rx, &(*(data)).DET_HVC_FLAG_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_IDM_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_661227d0_Rx, &(*(data)).DET_IDM_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_IDM_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_4cae9758_Rx, &(*(data)).DET_IDM_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_IDM_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_e3ea051f_Rx, &(*(data)).DET_IDM_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_IDM_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_19d7f648_Rx, &(*(data)).DET_IDM_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MH_CRC16_001_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_7ff0d781_Rx, &(*(data)).DET_MH_CRC16_001_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MH_CYCLE_COUNTER_001_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_722bea44_Rx, &(*(data)).DET_MH_CYCLE_COUNTER_001_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MH_SCAN_INDEX_4LSB_001_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_169b257f_Rx, &(*(data)).DET_MH_SCAN_INDEX_4LSB_001_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MTD_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_db9111a0_Rx, &(*(data)).DET_MTD_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MTD_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_f12da128_Rx, &(*(data)).DET_MTD_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MTD_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_5e69336f_Rx, &(*(data)).DET_MTD_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_MTD_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_a454c038_Rx, &(*(data)).DET_MTD_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_PROB_1STAZHYPO_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_11e80f21_Rx, &(*(data)).DET_PROB_1STAZHYPO_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_PROB_1STAZHYPO_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_3b54bfa9_Rx, &(*(data)).DET_PROB_1STAZHYPO_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_PROB_1STAZHYPO_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_94102dee_Rx, &(*(data)).DET_PROB_1STAZHYPO_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_PROB_1STAZHYPO_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_6e2ddeb9_Rx, &(*(data)).DET_PROB_1STAZHYPO_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_4a55e736_Rx, &(*(data)).DET_RANGE_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_60e957be_Rx, &(*(data)).DET_RANGE_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_cfadc5f9_Rx, &(*(data)).DET_RANGE_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_359036ae_Rx, &(*(data)).DET_RANGE_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_ERR_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_1aa76bd6_Rx, &(*(data)).DET_RANGE_ERR_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_ERR_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_301bdb5e_Rx, &(*(data)).DET_RANGE_ERR_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_ERR_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_9f5f4919_Rx, &(*(data)).DET_RANGE_ERR_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_ERR_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_6562ba4e_Rx, &(*(data)).DET_RANGE_ERR_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_97a064c8_Rx, &(*(data)).DET_RANGE_VELOCITY_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_bd1cd440_Rx, &(*(data)).DET_RANGE_VELOCITY_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_12584607_Rx, &(*(data)).DET_RANGE_VELOCITY_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_e865b550_Rx, &(*(data)).DET_RANGE_VELOCITY_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_ERR_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_0ec4140a_Rx, &(*(data)).DET_RANGE_VELOCITY_ERR_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_ERR_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2478a482_Rx, &(*(data)).DET_RANGE_VELOCITY_ERR_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_ERR_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_8b3c36c5_Rx, &(*(data)).DET_RANGE_VELOCITY_ERR_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RANGE_VELOCITY_ERR_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_7101c592_Rx, &(*(data)).DET_RANGE_VELOCITY_ERR_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RCS_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_5a6bf6d3_Rx, &(*(data)).DET_RCS_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RCS_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_70d7465b_Rx, &(*(data)).DET_RCS_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RCS_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_df93d41c_Rx, &(*(data)).DET_RCS_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_RCS_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_25ae274b_Rx, &(*(data)).DET_RCS_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SNR_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_5331873a_Rx, &(*(data)).DET_SNR_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SNR_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_798d37b2_Rx, &(*(data)).DET_SNR_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SNR_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_d6c9a5f5_Rx, &(*(data)).DET_SNR_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SNR_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_2cf456a2_Rx, &(*(data)).DET_SNR_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SUPER_RES_TARGET_001_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_98caa63a_Rx, &(*(data)).DET_SUPER_RES_TARGET_001_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SUPER_RES_TARGET_002_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_b27616b2_Rx, &(*(data)).DET_SUPER_RES_TARGET_002_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SUPER_RES_TARGET_003_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_1d3284f5_Rx, &(*(data)).DET_SUPER_RES_TARGET_003_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DET_SUPER_RES_TARGET_004_Rx_oRDR_FUSION_DET_001_004_oPCAN_RADAR_e70f77a2_Rx, &(*(data)).DET_SUPER_RES_TARGET_004_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_005_008_AL_Vdp_SG_Fusion_Detections_005_008_AL(P2VAR(I_SG_Fusion_Detections_005_008_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_005_008_oRDR_FUSION_DET_005_008_oPCAN_RADAR_0783a66c_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_005_008_oRDR_FUSION_DET_005_008_oPCAN_RADAR_0783a66c_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_009_012_AL_Vdp_SG_Fusion_Detections_009_012_AL(P2VAR(I_SG_Fusion_Detections_009_012_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_009_012_oRDR_FUSION_DET_009_012_oPCAN_RADAR_85b0e384_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_009_012_oRDR_FUSION_DET_009_012_oPCAN_RADAR_85b0e384_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_013_016_AL_Vdp_SG_Fusion_Detections_013_016_AL(P2VAR(I_SG_Fusion_Detections_013_016_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_013_016_oRDR_FUSION_DET_013_016_oPCAN_RADAR_713b89f4_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_013_016_oRDR_FUSION_DET_013_016_oPCAN_RADAR_713b89f4_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_017_020_AL_Vdp_SG_Fusion_Detections_017_020_AL(P2VAR(I_SG_Fusion_Detections_017_020_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_017_020_oRDR_FUSION_DET_017_020_oPCAN_RADAR_3121649c_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_017_020_oRDR_FUSION_DET_017_020_oPCAN_RADAR_3121649c_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_021_024_AL_Vdp_SG_Fusion_Detections_021_024_AL(P2VAR(I_SG_Fusion_Detections_021_024_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_021_024_oRDR_FUSION_DET_021_024_oPCAN_RADAR_f7a0d0a9_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_021_024_oRDR_FUSION_DET_021_024_oPCAN_RADAR_f7a0d0a9_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_025_028_AL_Vdp_SG_Fusion_Detections_025_028_AL(P2VAR(I_SG_Fusion_Detections_025_028_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_025_028_oRDR_FUSION_DET_025_028_oPCAN_RADAR_ba5bfb5a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_025_028_oRDR_FUSION_DET_025_028_oPCAN_RADAR_ba5bfb5a_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_029_032_AL_Vdp_SG_Fusion_Detections_029_032_AL(P2VAR(I_SG_Fusion_Detections_029_032_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_029_032_oRDR_FUSION_DET_029_032_oPCAN_RADAR_3868beb2_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_029_032_oRDR_FUSION_DET_029_032_oPCAN_RADAR_3868beb2_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_033_036_AL_Vdp_SG_Fusion_Detections_033_036_AL(P2VAR(I_SG_Fusion_Detections_033_036_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_033_036_oRDR_FUSION_DET_033_036_oPCAN_RADAR_cce3d4c2_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_033_036_oRDR_FUSION_DET_033_036_oPCAN_RADAR_cce3d4c2_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_037_040_AL_Vdp_SG_Fusion_Detections_037_040_AL(P2VAR(I_SG_Fusion_Detections_037_040_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_037_040_oRDR_FUSION_DET_037_040_oPCAN_RADAR_cee54bfa_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_037_040_oRDR_FUSION_DET_037_040_oPCAN_RADAR_cee54bfa_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_041_044_AL_Vdp_SG_Fusion_Detections_041_044_AL(P2VAR(I_SG_Fusion_Detections_041_044_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_041_044_oRDR_FUSION_DET_041_044_oPCAN_RADAR_eab931b2_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_041_044_oRDR_FUSION_DET_041_044_oPCAN_RADAR_eab931b2_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_045_048_AL_Vdp_SG_Fusion_Detections_045_048_AL(P2VAR(I_SG_Fusion_Detections_045_048_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_045_048_oRDR_FUSION_DET_045_048_oPCAN_RADAR_a7421a41_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_045_048_oRDR_FUSION_DET_045_048_oPCAN_RADAR_a7421a41_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_049_052_AL_Vdp_SG_Fusion_Detections_049_052_AL(P2VAR(I_SG_Fusion_Detections_049_052_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_049_052_oRDR_FUSION_DET_049_052_oPCAN_RADAR_25715fa9_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_049_052_oRDR_FUSION_DET_049_052_oPCAN_RADAR_25715fa9_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_053_056_AL_Vdp_SG_Fusion_Detections_053_056_AL(P2VAR(I_SG_Fusion_Detections_053_056_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_053_056_oRDR_FUSION_DET_053_056_oPCAN_RADAR_d1fa35d9_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_053_056_oRDR_FUSION_DET_053_056_oPCAN_RADAR_d1fa35d9_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_057_060_AL_Vdp_SG_Fusion_Detections_057_060_AL(P2VAR(I_SG_Fusion_Detections_057_060_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_057_060_oRDR_FUSION_DET_057_060_oPCAN_RADAR_91e0d8b1_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_057_060_oRDR_FUSION_DET_057_060_oPCAN_RADAR_91e0d8b1_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_061_064_AL_Vdp_SG_Fusion_Detections_061_064_AL(P2VAR(I_SG_Fusion_Detections_061_064_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_061_064_oRDR_FUSION_DET_061_064_oPCAN_RADAR_57616c84_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_061_064_oRDR_FUSION_DET_061_064_oPCAN_RADAR_57616c84_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_065_068_AL_Vdp_SG_Fusion_Detections_065_068_AL(P2VAR(I_SG_Fusion_Detections_065_068_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_065_068_oRDR_FUSION_DET_065_068_oPCAN_RADAR_1a9a4777_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_065_068_oRDR_FUSION_DET_065_068_oPCAN_RADAR_1a9a4777_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_069_072_AL_Vdp_SG_Fusion_Detections_069_072_AL(P2VAR(I_SG_Fusion_Detections_069_072_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_069_072_oRDR_FUSION_DET_069_072_oPCAN_RADAR_98a9029f_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_069_072_oRDR_FUSION_DET_069_072_oPCAN_RADAR_98a9029f_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_073_076_AL_Vdp_SG_Fusion_Detections_073_076_AL(P2VAR(I_SG_Fusion_Detections_073_076_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_073_076_oRDR_FUSION_DET_073_076_oPCAN_RADAR_6c2268ef_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_073_076_oRDR_FUSION_DET_073_076_oPCAN_RADAR_6c2268ef_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_077_080_AL_Vdp_SG_Fusion_Detections_077_080_AL(P2VAR(I_SG_Fusion_Detections_077_080_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_077_080_oRDR_FUSION_DET_077_080_oPCAN_RADAR_ea1c1377_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_077_080_oRDR_FUSION_DET_077_080_oPCAN_RADAR_ea1c1377_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_081_084_AL_Vdp_SG_Fusion_Detections_081_084_AL(P2VAR(I_SG_Fusion_Detections_081_084_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_081_084_oRDR_FUSION_DET_081_084_oPCAN_RADAR_d08af384_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_081_084_oRDR_FUSION_DET_081_084_oPCAN_RADAR_d08af384_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_085_088_AL_Vdp_SG_Fusion_Detections_085_088_AL(P2VAR(I_SG_Fusion_Detections_085_088_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_085_088_oRDR_FUSION_DET_085_088_oPCAN_RADAR_9d71d877_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_085_088_oRDR_FUSION_DET_085_088_oPCAN_RADAR_9d71d877_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_089_092_AL_Vdp_SG_Fusion_Detections_089_092_AL(P2VAR(I_SG_Fusion_Detections_089_092_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_089_092_oRDR_FUSION_DET_089_092_oPCAN_RADAR_1f429d9f_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_089_092_oRDR_FUSION_DET_089_092_oPCAN_RADAR_1f429d9f_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_093_096_AL_Vdp_SG_Fusion_Detections_093_096_AL(P2VAR(I_SG_Fusion_Detections_093_096_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_093_096_oRDR_FUSION_DET_093_096_oPCAN_RADAR_ebc9f7ef_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_093_096_oRDR_FUSION_DET_093_096_oPCAN_RADAR_ebc9f7ef_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_097_100_AL_Vdp_SG_Fusion_Detections_097_100_AL(P2VAR(I_SG_Fusion_Detections_097_100_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_097_100_oRDR_FUSION_DET_097_100_oPCAN_RADAR_f997174e_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_097_100_oRDR_FUSION_DET_097_100_oPCAN_RADAR_f997174e_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_101_104_AL_Vdp_SG_Fusion_Detections_101_104_AL(P2VAR(I_SG_Fusion_Detections_101_104_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_101_104_oRDR_FUSION_DET_101_104_oPCAN_RADAR_2dfb2b7d_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_101_104_oRDR_FUSION_DET_101_104_oPCAN_RADAR_2dfb2b7d_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_105_108_AL_Vdp_SG_Fusion_Detections_105_108_AL(P2VAR(I_SG_Fusion_Detections_105_108_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_105_108_oRDR_FUSION_DET_105_108_oPCAN_RADAR_6000008e_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_105_108_oRDR_FUSION_DET_105_108_oPCAN_RADAR_6000008e_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_109_112_AL_Vdp_SG_Fusion_Detections_109_112_AL(P2VAR(I_SG_Fusion_Detections_109_112_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_109_112_oRDR_FUSION_DET_109_112_oPCAN_RADAR_e2334566_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_109_112_oRDR_FUSION_DET_109_112_oPCAN_RADAR_e2334566_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_113_116_AL_Vdp_SG_Fusion_Detections_113_116_AL(P2VAR(I_SG_Fusion_Detections_113_116_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_113_116_oRDR_FUSION_DET_113_116_oPCAN_RADAR_16b82f16_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_113_116_oRDR_FUSION_DET_113_116_oPCAN_RADAR_16b82f16_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_117_120_AL_Vdp_SG_Fusion_Detections_117_120_AL(P2VAR(I_SG_Fusion_Detections_117_120_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_117_120_oRDR_FUSION_DET_117_120_oPCAN_RADAR_56a2c27e_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_117_120_oRDR_FUSION_DET_117_120_oPCAN_RADAR_56a2c27e_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_121_124_AL_Vdp_SG_Fusion_Detections_121_124_AL(P2VAR(I_SG_Fusion_Detections_121_124_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_121_124_oRDR_FUSION_DET_121_124_oPCAN_RADAR_9023764b_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_121_124_oRDR_FUSION_DET_121_124_oPCAN_RADAR_9023764b_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_Detections_125_128_AL_Vdp_SG_Fusion_Detections_125_128_AL(P2VAR(I_SG_Fusion_Detections_125_128_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[60U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_Detections_125_128_oRDR_FUSION_DET_125_128_oPCAN_RADAR_ddd85db8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_Fusion_Detections_125_128_oRDR_FUSION_DET_125_128_oPCAN_RADAR_ddd85db8_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN(P2VAR(I_SG_Fusion_RadarCapability_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[27U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 27U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarCapability_ALPCAN_Vdp_SG_Fusion_RadarCapability_ALPCAN_Com_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN(P2VAR(I_SG_Fusion_RadarHeader_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[64U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 64U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarHeader_ALPCAN_Vdp_SG_Fusion_RadarHeader_ALPCAN_Com_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN(P2VAR(I_SG_Fusion_RadarStatus2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[50U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 50U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus2_ALPCAN_Vdp_SG_Fusion_RadarStatus2_ALPCAN_Com_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN(P2VAR(I_SG_Fusion_RadarStatus_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[63U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_RDR_01)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_01(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_02)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_02(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_03)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_03(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_04)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_04(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_05)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_05(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_06)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_06(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_07)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_07(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_RDR_08)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = 63U;
    retTransformer = E2EXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_SWC_PLT_Appl_Communication_Rp_SG_Fusion_RadarStatus_ALPCAN_Vdp_SG_Fusion_RadarStatus_ALPCAN_Com_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_RDR_08(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_Vdp_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN(P2VAR(I_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_AEBS_FN_Switch_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_319f3146_Rx, &(*(data)).AEBS_FN_Switch_sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_BSIS_fn_Switch_Sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_5e1d7109_Rx, &(*(data)).BSIS_fn_Switch_Sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DDAW_fn_switch_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_a583cbd8_Rx, &(*(data)).DDAW_fn_switch_sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DDAW_warning_suppression_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_e90c956f_Rx, &(*(data)).DDAW_warning_suppression); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LDWS_FN_Switch_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_c735f110_Rx, &(*(data)).LDWS_FN_Switch_sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MOIS_Fn_Switch_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_37aa4c7c_Rx, &(*(data)).MOIS_Fn_Switch_sts); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageAliveCounter_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_4999ad4b_Rx, &(*(data)).MessageAliveCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageCRC_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_705ba35b_Rx, &(*(data)).MessageCRC); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CCVS1_ALPCAN_Vdp_SG_GW_CCVS1_ALPCAN(P2VAR(I_SG_GW_CCVS1_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_BrakeSwitch_oGW_CCVS1_oPCAN_RADAR_4705a3bc_Rx, &(*(data)).BrakeSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_ParkingBrakeSwitch_oGW_CCVS1_oPCAN_RADAR_4cb3f824_Rx, &(*(data)).ParkingBrakeSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_WheelBasedVehicleSpeed_oGW_CCVS1_oPCAN_RADAR_96f6cac9_Rx, &(*(data)).WheelBasedVehicleSpeed); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_16_ALPCAN_Vdp_SG_GW_CLS_Tx_16_ALPCAN(P2VAR(I_SG_GW_CLS_Tx_16_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Crawler_confi_status_info_oGW_CLS_Tx_16_oPCAN_RADAR_698927ba_Rx, &(*(data)).Crawler_confi_status_info); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Transmission_type_info_oGW_CLS_Tx_16_oPCAN_RADAR_9dcf5c49_Rx, &(*(data)).Transmission_type_info); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_CLS_Tx_4_ALPCAN_Vdp_SG_GW_CLS_Tx_4_ALPCAN(P2VAR(I_SG_GW_CLS_Tx_4_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Ignition_oGW_CLS_Tx_4_oPCAN_RADAR_6b7ac456_Rx, &(*(data)).Ignition); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_ReverseSwitchInfo_oGW_CLS_Tx_4_oPCAN_RADAR_82207cae_Rx, &(*(data)).ReverseSwitchInfo); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_03_ALPCAN_Vdp_SG_GW_ETC2_03_ALPCAN(P2VAR(I_SG_GW_ETC2_03_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TransCurrentGear_03_oGW_ETC2_03_oPCAN_RADAR_e4621163_Rx, &(*(data)).TransCurrentGear_03); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_ETC2_ALPCAN_Vdp_SG_GW_ETC2_ALPCAN(P2VAR(I_SG_GW_ETC2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TransCurrentGear_00_oGW_ETC2_oPCAN_RADAR_2bdb78e8_Rx, &(*(data)).TransCurrentGear_00); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_OEL_ALPCAN_Vdp_SG_GW_OEL_ALPCAN(P2VAR(I_SG_GW_OEL_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_HazardLightSwitch_oGW_OEL_oPCAN_RADAR_5efed0a6_Rx, &(*(data)).HazardLightSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_HighLowBeamSwitch_oGW_OEL_oPCAN_RADAR_5e6caf50_Rx, &(*(data)).HighLowBeamSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TurnSignalSwitch_oGW_OEL_oPCAN_RADAR_ae279c7f_Rx, &(*(data)).TurnSignalSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_SAS_ALPCAN_Vdp_SG_GW_SAS_ALPCAN(P2VAR(I_SG_GW_SAS_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageChecksum_oGW_SAS_oPCAN_RADAR_87a8a844_Rx, &(*(data)).MessageChecksum); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageCounter_oGW_SAS_oPCAN_RADAR_f51168b6_Rx, &(*(data)).MessageCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerAngleSensorActiveMode_oGW_SAS_oPCAN_RADAR_8c83afe6_Rx, &(*(data)).SteerAngleSensorActiveMode); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerAngleSensorCalibrated_oGW_SAS_oPCAN_RADAR_883db374_Rx, &(*(data)).SteerAngleSensorCalibrated); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngle_oGW_SAS_oPCAN_RADAR_a582dc0a_Rx, &(*(data)).SteerWheelAngle); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngleRange_oGW_SAS_oPCAN_RADAR_fe08ddff_Rx, &(*(data)).SteerWheelAngleRange); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngleRangeCounter_oGW_SAS_oPCAN_RADAR_e6274286_Rx, &(*(data)).SteerWheelAngleRangeCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngleRangeCounterType_oGW_SAS_oPCAN_RADAR_30be95a7_Rx, &(*(data)).SteerWheelAngleRangeCounterType); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_TD_ALPCAN_Vdp_SG_GW_TD_ALPCAN(P2VAR(I_SG_GW_TD_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Day_oGW_TD_oPCAN_RADAR_5e7337eb_Rx, &(*(data)).Day); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Hours_oGW_TD_oPCAN_RADAR_70f4ea38_Rx, &(*(data)).Hours); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LocalHourOffset_oGW_TD_oPCAN_RADAR_ed7302cc_Rx, &(*(data)).LocalHourOffset); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LocalMinuteOffset_oGW_TD_oPCAN_RADAR_6576cfca_Rx, &(*(data)).LocalMinuteOffset); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Minutes_oGW_TD_oPCAN_RADAR_f3505ea9_Rx, &(*(data)).Minutes); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Month_oGW_TD_oPCAN_RADAR_9592e5da_Rx, &(*(data)).Month); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Seconds_oGW_TD_oPCAN_RADAR_930edb8a_Rx, &(*(data)).Seconds); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Year_oGW_TD_oPCAN_RADAR_0a7d8ada_Rx, &(*(data)).Year); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VDC2_ALPCAN_Vdp_SG_GW_VDC2_ALPCAN(P2VAR(I_SG_GW_VDC2_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LateralAcceleration_oGW_VDC2_oPCAN_RADAR_d68a0cd8_Rx, &(*(data)).LateralAcceleration); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LongitudinalAcceleration_oGW_VDC2_oPCAN_RADAR_c0095fa4_Rx, &(*(data)).LongitudinalAcceleration); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngle_oGW_VDC2_oPCAN_RADAR_4fddc2e4_Rx, &(*(data)).SteerWheelAngle); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_YawRate_oGW_VDC2_oPCAN_RADAR_f47de610_Rx, &(*(data)).YawRate); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VD_ALPCAN_Vdp_SG_GW_VD_ALPCAN(P2VAR(I_SG_GW_VD_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TotalVehicleDistance_oGW_VD_oPCAN_RADAR_55cc86c5_Rx, &(*(data)).TotalVehicleDistance); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_GW_VI_ALPCAN_Vdp_SG_GW_VI_ALPCAN(P2VAR(I_SG_GW_VI_ALPCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_GW_VI_oGW_VI_oPCAN_RADAR_5c723f37_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VehicleIdentification_oGW_VI_oPCAN_RADAR_d901cf94_Rx, &(*(data)).VehicleIdentification); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_OEL_ALVCAN_Vdp_SG_OEL_ALVCAN(P2VAR(I_SG_OEL_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_HazardLightSwitch_oOEL_oVCAN_RADAR_6e3514e2_Rx, &(*(data)).HazardLightSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_HighLowBeamSwitch_oOEL_oVCAN_RADAR_71269e88_Rx, &(*(data)).HighLowBeamSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_TurnSignalSwitch_oOEL_oVCAN_RADAR_e6019fee_Rx, &(*(data)).TurnSignalSwitch); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_SAS_ALVCAN_Vdp_SG_SAS_ALVCAN(P2VAR(I_SG_SAS_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_ActiveMode_oSAS_oVCAN_RADAR_d0796acb_Rx, &(*(data)).ActiveMode); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Calibrated_oSAS_oVCAN_RADAR_ebf0ded0_Rx, &(*(data)).Calibrated); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageChecksum_oSAS_oVCAN_RADAR_61fa3dc9_Rx, &(*(data)).MessageChecksum); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_MessageCounter_oSAS_oVCAN_RADAR_bad50fe2_Rx, &(*(data)).MessageCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteeringWheelAngle_oSAS_oVCAN_RADAR_17cf9abd_Rx, &(*(data)).SteeringWheelAngle); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteeringWheelAngleRange_oSAS_oVCAN_RADAR_2ef6c42e_Rx, &(*(data)).SteeringWheelAngleRange); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteeringWheelAngleRangeCounter_oSAS_oVCAN_RADAR_5300a9ef_Rx, &(*(data)).SteeringWheelAngleRangeCounter); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteeringWheelAngleRangeCounterType_oSAS_oVCAN_RADAR_7889a4bc_Rx, &(*(data)).SteeringWheelAngleRangeCounterType); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_TD_ALVCAN_Vdp_SG_TD_ALVCAN(P2VAR(I_SG_TD_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Day_oTD_oVCAN_RADAR_d9e1ba53_Rx, &(*(data)).Day); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Hours_oTD_oVCAN_RADAR_408d2c34_Rx, &(*(data)).Hours); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LocalHourOffset_oTD_oVCAN_RADAR_82942db5_Rx, &(*(data)).LocalHourOffset); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LocalMinuteOffset_oTD_oVCAN_RADAR_074fc4ab_Rx, &(*(data)).LocalMinuteOffset); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Minutes_oTD_oVCAN_RADAR_2546db9e_Rx, &(*(data)).Minutes); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Month_oTD_oVCAN_RADAR_d8bc3ad5_Rx, &(*(data)).Month); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Seconds_oTD_oVCAN_RADAR_b2a2ca59_Rx, &(*(data)).Seconds); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Year_oTD_oVCAN_RADAR_b229b348_Rx, &(*(data)).Year); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VDC2_ALVCAN_Vdp_SG_VDC2_ALVCAN(P2VAR(I_SG_VDC2_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LateralAcceleration_oVDC2_oVCAN_RADAR_b3e7a398_Rx, &(*(data)).LateralAcceleration); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_LongitudinalAcceleration_oVDC2_oVCAN_RADAR_f355ad7e_Rx, &(*(data)).LongitudinalAcceleration); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_SteerWheelAngle_oVDC2_oVCAN_RADAR_c890bb33_Rx, &(*(data)).SteerWheelAngle); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_YawRate_oVDC2_oVCAN_RADAR_bf77bc8a_Rx, &(*(data)).YawRate); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VD_ALVCAN_Vdp_SG_VD_ALVCAN(P2VAR(I_SG_VD_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_Total_vehicle_distance_oVD_oVCAN_RADAR_7583597c_Rx, &(*(data)).Total_vehicle_distance); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VI_ALVCAN_Vdp_SG_VI_ALVCAN(P2VAR(I_SG_VI_ALVCAN, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_SG_VI_oVI_oVCAN_RADAR_7241e1af_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VehicleIdentification_oVI_oVCAN_RADAR_4b86485f_Rx, &(*(data)).VehicleIdentification); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL(P2VAR(I_SG_VehicleStatus_AL, AUTOMATIC, RTE_SWC_PLT_APPL_COMMUNICATION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[64U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_VehicleStatus_oSYS_VEHICLE_STATUS_oPCAN_RADAR_0411a809_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = ComXf_Inv_Com_SG_VehicleStatus_oSYS_VEHICLE_STATUS_oPCAN_RADAR_0411a809_Rx(&(transformationBuffer_0[0]), lengthBuffer, data);
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Alignment_Faults_De_Alignment_Faults(P2VAR(Dt_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(P2VAR(Dt_MMIC_ErrorFlags, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_Hardware_Fault_Status_De_Hardware_Fault_Status(P2VAR(Dt_Hardware_Fault_Error_Status, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_IPC_Faults_De_IPC_Faults(P2VAR(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_Diag_Rp_RadarCapability_Faults_De_RadarCapability_Faults(P2VAR(Dt_RadarCapability_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_DIAG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults(P2VAR(Dt_PltToFltMgr_Alignment_Faults_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_Alignment_Flt_Sts_De_PltToFltMgr_Alignment_Faults; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_IPC_Faults_sts_De_IPC_Faults(P2VAR(Dt_IPC_Faults, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_IPC_Faults_sts_De_IPC_Faults; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status(P2VAR(Dt_Mcu_Startup_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_MCU_Startup_Fault_Status_MCU_Startup_Fault_Status; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Platform_Battery_Tst_De_Platform_Battery_Tst(P2VAR(Dt_Battery_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_Platform_Battery_Tst_De_Platform_Battery_Tst; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag(P2VAR(Dt_PltToFltMgr_Host_Micro_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Host_Micro_Diag_De_PltToFltMgr_Host_Micro_Diag; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T(P2VAR(Dt_PltToFltMgr_InterProcessor_Commn_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_InterProcessor_Commn_De_PltToFltMgr_InterProcessor_Commn_T; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T(P2VAR(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_A_MMIC_Diag_De_PltToFltMgr_MMIC_A_MMIC_Diag_T; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T(P2VAR(Dt_PltToFltMgr_MMIC_B_Diag_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_MMIC_B_Diag_De_PltToFltMgr_MMIC_B_Diag_T; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics(P2VAR(Dt_PltToFltMgr_Memory_Diagnostics_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Memory_Diagnostics_De_PltToFltMgr_Memory_Diagnostics; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status(P2VAR(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_PltToFltMgr_Micro_Temp_Fault_Status_De_PltToFltMgr_Micro_Temp_Fault_Status; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts(P2VAR(Dt_PltToFltMgr_Blockage_Detection_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_Radar_Blockage_Flt_Sts_De_Radar_Blockage_Flt_Sts; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_Rdr_Hw_Tst_De_Rdr_Hw_Tst(P2VAR(Dt_Rdr_Hw_Tst_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_Diag_Pp_Rdr_Hw_Tst_De_Rdr_Hw_Tst; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_FaultMgr_Rp_XCP_Fault_Override_De_XCP_Fault_Override(P2VAR(Idt_XCP_Fault_Override_T, AUTOMATIC, RTE_SWC_PLT_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Fault_Override_De_XCP_Fault_Override; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_CustDegradation_De_CustDegradation(P2VAR(Dt_CustDegradation, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_OpModeShutdown_De_OpModeShutdown(P2VAR(Dt_OpModeShutdown, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarCoreStatus_De_RadarCoreStatus(P2VAR(Dt_RadarCoreStatus, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_RadarCoreStatus_De_RadarCoreStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarDiagRequest_De_RadarDiagRequest(P2VAR(Dt_RadarDiagRequest, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_FaultMgr_Pp_RadarDiagRequestInterface_De_RadarDiagRequest; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_TR_ModeManager_De_TR_ModeManager(P2VAR(Dt_TR_ModeManager, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_FaultMgr_Pp_ModeManagerTestResultInterface_De_TR_ModeManager; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_Align_Write_Nvm_Record_Alignment_Record(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(P2VAR(Dt_ECC_Correctable_Error_Counters, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2VAR(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status(P2VAR(Dt_SensorPosition_Data_T, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_NvM_lock_Unclock_Status_De_NvM_lock_Unclock_Status; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_RFE_NvM_Data_De_RFE_NvM_Data(P2VAR(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_RFE_NvM_Data_De_RFE_NvM_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_NvMHandler_Rp_VSE_NVM_Params_De_VSE_NVM_Params(P2VAR(Dt_VSE_NVM_Params, AUTOMATIC, RTE_SWC_PLT_APPL_NVMHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CDD_IPC_Pp_VSE_NVM_Params_De_VSE_NVM_Params; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2VAR(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_MemExceptionInfo_De_MemExceptionInfo(P2VAR(Dt_Memory_Exception_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(data, Rte_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo, sizeof(Dt_StaticRegCheckFailureInfo)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_RFE_NvM_Data_De_RFE_NvM_Data(P2VAR(Dt_Rfe_REC_NREC_Fault, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_RFE_NvM_Data_De_RFE_NvM_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_Radar_Control_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(P2VAR(Idt_XCP_Single_Look_T, AUTOMATIC, RTE_SWC_PLT_CDD_RADAR_CONTROL_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultLatchTable_De_ActiveFaultLatchTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Active_Fault_Table_De_ActiveFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PRJ_Appl_FaultMgr_Pp_ActiveFaultTable_De_ActiveFaultTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Auto_Alignment_Data_Auto_Alignment_Data(P2VAR(Dt_Auto_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Calibration_Version_Info_De_Calibration_Version_Info(P2VAR(Idt_Cal_Version_Info_Type, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_Calibration_Version_Info_De_Calibration_Version_Info; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Customer_SW_Version_Info_De_Customer_SW_Version_Info(P2VAR(Dt_Customer_SW_Version, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_Customer_SW_Version_Info_De_Customer_SW_Version_Info; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PRJ_Appl_FaultMgr_Pp_FaultTestCompleteTable_De_FaultTestCompleteTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(data, Rte_SWC_PRJ_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_ID_data_De_ID_data(P2VAR(Dt_ID_data, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_Initial_Alignment_Result_Initial_Alignment_Result(P2VAR(Dt_Initial_Alignment_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_MMIC_Temperature_De_MMIC_Temperature(P2VAR(Idt_Type_MMIC_Temperature, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_CDD_Radar_Control_Pp_MMIC_Temperature_De_MMIC_Temperature; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_Filtered_De_RawAdcData(P2VAR(Dt_RawAdcDataFilt_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_Filtered_De_RawAdcData; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(P2VAR(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_SW_Version_Info_De_SW_Version_Info(P2VAR(Idt_SW_Version_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_SW_Version_Info_De_SW_Version_Info; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_XCP_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform(P2VAR(Dt_Initial_Alignment_Performance_Result_T, AUTOMATIC, RTE_SWC_PLT_CDD_XCP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data(P2VAR(Dt_Alignment_IPC_Data, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_NvM_Data_Alignment_NvM_Data(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_Appl_NvMHandler_Pp_Alignment_NvM_Data_Alignment_NvM_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM(P2VAR(Dt_Write_Alignment_NvM_Data_T, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_SWC_PLT_CDD_XCP_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC(P2VAR(Dt_Manual_Alignment_Execution_Data_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_Manual_Alignment_Execution_Data_From_UDS_CRC_De_Manual_Alignment_Execution_Data_CRC; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC(P2VAR(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, AUTOMATIC, RTE_SWC_PLT_RADAR_ALIGNMENT_HANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_CMP_PRJ_UDSHandler_Pp_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_De_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultLatchTable_De_ActiveFaultLatchTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_ActiveFaultTable_De_ActiveFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_Appl_FaultMgr_Pp_Active_Fault_Table_De_ActiveFaultTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_FaultTestCompleteTable_De_FaultTestCompleteTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_Appl_FaultMgr_Pp_Fault_Test_Complete_Table_De_FaultTestCompleteTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_FaultMgr_Rp_HistoryFaultTable_De_HistoryFaultTable(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_FAULTMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(data, Rte_SWC_PLT_Appl_FaultMgr_Pp_HistoryFaultTable_De_HistoryFaultTable, sizeof(Dt_Fault_T)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_PhysicalAdcData_De_PhysicalAdcData; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckProgDep_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckProgDep_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Out_ResData = Out_ResData; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_CheckSig_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_CheckSig_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Out_ResData = Out_ResData; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_Routine_EraseMem_Start_Start(P2CONST(Dcm_StartDataIn_Routine_EraseMem_Start_In_ReqDataArrayType, AUTOMATIC, RTE_DCM_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_EraseMem_Start_Out_ResDataArrayType, AUTOMATIC, RTE_DCM_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  In_ReqData = In_ReqData; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Out_ResData = Out_ResData; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Debug_Populate_Debug_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Detection_Populate_Detection_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Header_Populate_Header_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_RDD_Populate_RDD_Stream */
    (void)SetEvent(Appl_Task_Fast, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Status_Populate_Status_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RE_Radar_Ctl_Look_Trigger */
    (void)SetEvent(Radar_Ctrl_Task, Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: RE_Radar_Ctl_Look_Trigger */
    (void)SetEvent(Radar_Ctrl_Task, Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_Active = 1;
    Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream;
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_ADC_Populate_ADC_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_Active = 1;
    Rte_CS_ServerQueue_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx;
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_CAN_Tx_RE_Communication_Tx */
    (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Debug_Populate_Debug_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Detection_Populate_Detection_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Header_Populate_Header_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_CallCompleted = FALSE;
    Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_Active = 1;
    Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream;
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_MMIC_Populate_MMIC_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_RDD_Populate_RDD_Stream */
    (void)SetEvent(Appl_Task_Fast, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream(void) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean callCompleted;

  SuspendOSInterrupts();
  callCompleted = Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted;
  if (callCompleted == TRUE)
  {
    if (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free > 0U)
    {
      Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted = FALSE;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free = 0;
      Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Active = 1;
      Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_ClientId = Rte_CS_ClientConfigIndex_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream;
    }
    else
    {
      ret = RTE_E_TIMEOUT;
    }
  }
  else
  {
    ret = RTE_E_LIMIT;
  }
  ResumeOSInterrupts();

  if (ret == RTE_E_OK)
  {

    /* scheduled trigger for runnables: PostRadarProcessing_Status_Populate_Status_Stream */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream); /* PRQA S 3417 */ /* MD_Rte_Os */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_PLT_Radar_Alignment_Handler_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Trigger_Write_to_NVM(u8_ImmidieteWrite, dt_Nv_Caller_Id);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_CanTsync_TimeRecordTsync_Callback(P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, RTE_STBM_APPL_DATA) syncRecordTableBlock) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  syncRecordTableBlock = syncRecordTableBlock; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback(P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, RTE_STBM_APPL_DATA) syncRecordTableBlock) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  EventMaskType ev;
  boolean callCompleted;

  SuspendOSInterrupts();
  Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_CallCompleted = FALSE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_Active = 1;
  ResumeOSInterrupts();
  Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_ClientId = Rte_CS_ClientConfigIndex_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback;

  Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.syncRecordTableBlock = *syncRecordTableBlock;

  {

    /* scheduled trigger for runnables: StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback */
    (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback); /* PRQA S 3417 */ /* MD_Rte_Os */

    {
      do /* FETA_RTE_BLOCKING */
      {
        (void)WaitEvent(Rte_Ev_WP_Appl_Task_High_Prio); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)GetEvent(Appl_Task_High_Prio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
        (void)ClearEvent(ev & (Rte_Ev_WP_Appl_Task_High_Prio)); /* PRQA S 3417 */ /* MD_Rte_Os */
        callCompleted = Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_CallCompleted;
      }
      while (callCompleted == FALSE);
    }

    {

      ret = Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_Result; /* PRQA S 2983 */ /* MD_Rte_2983 */
    }

  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Inter-runnable triggering (Rte_IrTrigger API)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
}

FUNC(void, RTE_CODE) Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{

  /* scheduled trigger for runnables: Dsp_sp_post_processing_complete */
  (void)SetEvent(Appl_IPC_Task, Rte_Ev_Run_SWC_CDD_IPC_Dsp_sp_post_processing_complete); /* PRQA S 3417 */ /* MD_Rte_Os */
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState(BswM_SDC_SdClientServiceState nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_SDC_SdClientServiceState(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_SDC_SdClientServiceState currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_SDC_SdClientServiceState(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState(BswM_SDC_SdConsumedEventGroupState nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_SDC_SdConsumedEventGroupState(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_SDC_SdConsumedEventGroupState currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_SDC_SdConsumedEventGroupState(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_SDC_SdEventHandlerState currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_SDC_SdEventHandlerState currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_SDC_SdEventHandlerState currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(Dcm_EcuResetType, RTE_CODE) Rte_Mode_BswM_Notification_BswMModeRequestPort_DCMECUReset_DcmEcuReset(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  Dcm_EcuResetType curMode;
  curMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  return curMode;
}


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_EcuResetType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(currentMode);
  if (internalIndexNextMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;
    Rte_OsCore0_ASIL_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Rte Trigger API (Rte_Trigger)
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  /* scheduled trigger for runnables: RE_HIL_Periodic_Handler */
  (void)SetEvent(Appl_Task_Logging, Rte_Ev_Run_SWC_PLT_CDD_HIL_RE_HIL_Periodic_Handler_Rp_HIL_Periodic_Handler_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */

}



/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_BswM_MDGP_SDC_SdClientServiceState;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_C_consService_RDR_1_ADAS_Vehicle_Status_2b1e055b_CEG_consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85_BswM_MDGP_SDC_SdConsumedEventGroupState;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Detections_89f78c9f_EH_EventGroup_RDR_1_ca62382d_BswM_MDGP_SDC_SdEventHandlerState;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_SW_Info_c2745ec9_EH_EventGroup_RDR_1_653e2581_BswM_MDGP_SDC_SdEventHandlerState;
  return curMode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_SWC_PLT_Appl_Communication_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_BswM_Switch_SDC_Mode_S_provService_RDR_1_Status_d2069d01_EH_EventGroup_RDR_1_f7c73cae_BswM_MDGP_SDC_SdEventHandlerState;
  return curMode;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Rte Trigger API (Rte_Trigger)
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  /* scheduled trigger for runnables: RE_Radar_Ctl_Look_Complete */
  (void)SetEvent(Radar_Ctrl_Task, Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Rp_Radar_Ctl_Look_Complete_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */

}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_globalmode_Core0_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Alive_Program_Flow_Monitoring_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_Appl_IPC_Task_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_Appl_Task_Communication_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_Appl_Task_Radar_Control_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_BSW_Task_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_Dummy_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_OsCore0_ASIL_mode_SE_Internal_Wdg_PLT_Appl_Task_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}


/**********************************************************************************************************************
 * LDCOM-Callbacks for TP CopyTxData
 *********************************************************************************************************************/

FUNC(BufReq_ReturnType, RTE_CODE) Rte_LdComCbkCopyTxData_signalPdu_RDR_1_Detections_52b391ee_Tx(P2CONST(PduInfoType, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr, P2VAR(RetryInfoType, AUTOMATIC, RTE_APPL_VAR) RetryInfoPtr, P2VAR(PduLengthType, AUTOMATIC, RTE_APPL_VAR) TxDataCntPtr) /* PRQA S 0850, 3673 */ /* MD_MSR_MacroArgumentEmpty, MD_MSR_Rule8.13 */
{
  BufReq_ReturnType ret = BUFREQ_E_NOT_OK;

  if ((Rte_InitState == RTE_STATE_INIT)
      && ((RetryInfoPtr == NULL_PTR) || (RetryInfoPtr->TpDataState != TP_DATARETRY)))
  {
    uint32 sduLength = PduInfoPtr->SduLength;
    if((sduLength <= sizeof(Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx)) && ((sduLength + Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx) <= Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length))
    {
      Rte_PartialMemCpy(PduInfoPtr->SduDataPtr, Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx, sduLength, sizeof(Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx), 0, Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx, sduLength); /* PRQA S 0315 */ /* MD_Rte_0315 */
      Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx += sduLength;
      ret = BUFREQ_OK;
    }

    *TxDataCntPtr = (PduLengthType)(Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx_Length - Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx);
  }

  return ret;
}


/**********************************************************************************************************************
 * LDCOM-Callbacks for TP Tx Confirmation
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_LdComCbkTpTxConfirmation_signalPdu_RDR_1_Detections_52b391ee_Tx(Std_ReturnType Result) /* PRQA S 3206 */ /* MD_Rte_3206 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Result = Result; /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

    Rte_OsCore0_ASIL_LdComTpIndices.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 0;
    Rte_ThreadFence();
    Rte_OsCore0_ASIL_LdComTpBusyFlags.Rte_LdComTp_signalPdu_RDR_1_Detections_52b391ee_Tx = 0;
  }
}


/**********************************************************************************************************************
 * LDCOM Callbacks for Rx Indication
 *********************************************************************************************************************/

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_LdComCbkRxIndication_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx(P2CONST(PduInfoType, AUTOMATIC, RTE_APPL_DATA) PduInfoPtr)
{

  if ((Rte_InitState == RTE_STATE_INIT) && (PduInfoPtr->SduLength >= 79U))
  {
    uint32 lengthBuffer;

    SuspendOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    lengthBuffer = (uint32)PduInfoPtr->SduLength;
    if (lengthBuffer > 79U)
    {
      lengthBuffer = 79U;
    }
    Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx_Length = lengthBuffer;
    Rte_MemCpy32(Rte_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx, PduInfoPtr->SduDataPtr, lengthBuffer); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
    ResumeOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */

  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_BackgroundTask_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_BackgroundTask
 * Priority: 1
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_BackgroundTask) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Appl_BackgroundTask_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_BackgroundTask, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Appl_BackgroundTask_0_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_Appl_BackgroundTask_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      NvM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Fee_30_FlexNor_MainFunction();

      /* call schedulable entity */
      Fls_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_BackgroundTask_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_IPC_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_IPC_Task
 * Priority: 130
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_IPC_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms | Rte_Ev_Run_SWC_CDD_IPC_Dsp_sp_post_processing_complete | Rte_Ev_Run_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_IPC_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms | Rte_Ev_Run_SWC_CDD_IPC_Dsp_sp_post_processing_complete | Rte_Ev_Run_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_IPC_Rx_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_IPC_Trigger_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_IPC_Tx_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_CDD_IPC_Dsp_sp_post_processing_complete) != (EventMaskType)0)
    {
      /* call runnable */
      Dsp_sp_post_processing_complete(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_IPC_VSE_Handler_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_IPC_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_IPC_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Init_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Init
 * Priority: 190
 * Schedule: NON
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Init) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  RE_XCP_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SWC_PLT_Appl_NvMHandler_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Radar_Control_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Communication_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_PlatformTime_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Evaluate_Plt_Time_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_Service_IoHwAb_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_FailSafe_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_IoHwAb_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_ExternalWdg_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_FCRU_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_MCU_Safety_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_Diag_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_Fault_Mgr_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Power_Manager_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_Mode_Manager_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_ECUSync_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PRJ_FaultMgr_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_RTM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_Wdg_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_WdgHandler_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Alignment_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_CDD_IPC_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PLT_TimeSync_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Security_Manager_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Init_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Task
 * Priority: 40
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic_Appl_Task_0_10ms | Rte_Ev_Cyclic_Appl_Task_0_50ms | Rte_Ev_Cyclic_Appl_Task_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_Appl_Task_0_10ms | Rte_Ev_Cyclic_Appl_Task_0_50ms | Rte_Ev_Cyclic_Appl_Task_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_XCP_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_XCP_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_Alignment_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_SensorPosition_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_Appl_Project_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_PlatformTime_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_RTM_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_Service_IoHwAb_Main_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Service_IoHwAb_ADCFilter_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_IoHwAb_Main_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_IoHwAb_Main_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_Mode_Manager_StateMachine_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_Power_Manager_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_CDD_Ext_Wdg_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_Fault_Mgr_Main_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_IoHwAb_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PRJ_FaultMgr_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Battery_Fault_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Host_Microcontroller_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Memory_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Microprocessor_Temp_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Radar_Hardware_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Diag_Alignment_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Alignment_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Battery_Fault_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Can_Bus_Off_Fault_Test_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Host_Microcontroller_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Interprocessor_Comm_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Memory_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Microprocessor_Temp_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Radar_Blockage_Detection_Test_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_FailSafe_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_FCRU_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Radar_Hardware_Tests_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Radar_Transceiver_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_Watchdog_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Fault_Mgr_General_Diagnostics_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Mode_Manager_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_CDD_Ext_Wdg_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_MCU_Safety_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_WDG_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_Appl_NvMHandler_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_TimeSync_Main_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PRJ_FaultMgr_DEM_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_Security_Manager_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Communication_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_Communication_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Task_Communication
 * Priority: 80
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Task_Communication) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms | Rte_Ev_Cyclic_Appl_Task_Communication_0_25ms | Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic | Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx | Rte_Ev_Run_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_Task_Communication, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms | Rte_Ev_Cyclic_Appl_Task_Communication_0_25ms | Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic | Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx | Rte_Ev_Run_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event | Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//      Com_MainFunctionTx_ComMainFunctionTx_Event();
    }

    if ((ev & Rte_Ev_Run_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionTx_ComMainFunctionTx_Periodic();
    }

    if ((ev & Rte_Ev_Cyclic2_Appl_Task_Communication_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionRx_ComMainFunctionRx();
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_ClientId;
        ++cnt;
        if (clientId >= 1U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx[clientId].Rte_ClientQueue;
        /* call runnable */
        ClientQueue->Rte_Result = PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Appl_Task_Communication, Rte_Ev_Run_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Communication_Tx_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_PCAN_Timeout_Faults_Event) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PCAN_Timeout_Faults_Event(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_100ms_1000ms_Event) != (EventMaskType)0)
    {
      /* call runnable */
      RE_VCAN_Timeout_Faults_100ms_1000ms_Event(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PRJ_Appl_FaultMgr_RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event) != (EventMaskType)0)
    {
      /* call runnable */
      RE_VCAN_Timeout_Faults_10ms_20ms_50ms_Event(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Appl_Task_Communication_0_25ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_Communication_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Appl_Task_High_Prio_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Appl_Task_High_Prio
 * Priority: 150
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Appl_Task_High_Prio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_10ms | Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Appl_Task_High_Prio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_10ms | Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_Diag_PlatformTime_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      WdgM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_WDG_Main_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Appl_Task_High_Prio_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTSyn_MainFunction();

      /* call runnable */
      StbM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Appl_Task_High_Prio_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_BSW_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     BSW_Task
 * Priority: 50
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(BSW_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_BSW_Task_0_10ms | Rte_Ev_Cyclic2_BSW_Task_0_20ms | Rte_Ev_Cyclic2_BSW_Task_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task | Rte_Ev_Run_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms | Rte_Ev_Run_SWC_PLT_CDD_TimeSync_DRE_StatusNotification_Callback); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(BSW_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_BSW_Task_0_10ms | Rte_Ev_Cyclic2_BSW_Task_0_20ms | Rte_Ev_Cyclic2_BSW_Task_0_5ms | Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task | Rte_Ev_Run_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms | Rte_Ev_Run_SWC_PLT_CDD_TimeSync_DRE_StatusNotification_Callback)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      BswM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call runnable */
      Dem_MasterMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_2(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      ComM_MainFunction_1(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      EthSM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      SoAd_MainFunction();

      /* call schedulable entity */
      TcpIp_MainFunction();

      /* call schedulable entity */
      Xcp_MainFunction();

      /* call schedulable entity */
      TcpIpXcp_MainFunction();

      /* call schedulable entity */
      CanXcp_MainFunction();

      /* call schedulable entity */
      EthIf_MainFunctionTx();

      /* call schedulable entity */
      EthIf_MainFunctionRx();

      /* call schedulable entity */
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//      Sd_MainFunction();

      /* call schedulable entity */
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//      SomeIpTp_MainFunctionRx();

      /* call schedulable entity */
/* Commented out via Post Gen script for (CAN/SomeIP/Tracker)Variant specific changes*/
//      SomeIpTp_MainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Crypto_182_iND13400_MainFunction();

      /* call runnable */
      Csm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_SatelliteMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTp_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BSW_Task_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Dcm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_TimeSync_DRE_StatusNotification_Callback) != (EventMaskType)0)
    {
      /* call runnable */
      DRE_StatusNotification_Callback(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_Appl_NvMHandler_5ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task) != (EventMaskType)0)
    {
      /* call runnable */
      RE_PLT_WDG_INTERNAL_WDG_BSW_Task(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_BSW_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_Radar_Ctrl_Task_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Radar_Ctrl_Task
 * Priority: 100
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(Radar_Ctrl_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms | Rte_Ev_Run_Rtm_Rtm_MainFunction | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Rp_Radar_Ctl_Look_Complete_Trigger | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Radar_Ctrl_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms | Rte_Ev_Run_Rtm_Rtm_MainFunction | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Rp_Radar_Ctl_Look_Complete_Trigger | Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Radar_Control_50ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger) != (EventMaskType)0)
    {
      uint32 cnt;
      cnt = 0U;
      while ((cnt < 2U) && (Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Active > 0U)) /* FETA_RTE_CLIENT_SERVER */
      {
        P2VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, TYPEDEF, RTE_VAR_CLEARED) ClientQueue;
        uint8 clientId;
        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Active = 0;
        clientId = Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_ClientId;
        ++cnt;
        if (clientId >= 2U)
        {
          continue;
        }
        ClientQueue = Rte_CS_ClientConfig_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation[clientId].Rte_ClientQueue;
        /* call runnable */
        /* RE_Communication_RX is removed from Appl_Task_Communication task and added Manually here, Don't remove it*/
        RE_Communication_Rx();
        RE_Radar_Ctl_Look_Trigger();

        Rte_ThreadFence();
        ClientQueue->Rte_CallCompleted = TRUE;

        Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free = 1;
      }
      if (cnt == 2U)
      {
        (void)SetEvent(Radar_Ctrl_Task, Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Trigger); /* PRQA S 3417 */ /* MD_Rte_Os */
      }
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Rp_Radar_Ctl_Look_Complete_Trigger) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Radar_Ctl_Look_Complete(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Radar_Ctl_Look_Complete_Post_RFBIST(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Radar_Control_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Rtm_Rtm_MainFunction) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Rtm_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_Radar_Ctrl_Task_0_50ms) != (EventMaskType)0)
    {
      /* call runnable */
      RE_Test(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_Radar_Ctrl_Task_ASIL_B
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

   MD_Rte_1340:  MISRA rule: Rule17.8
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

   MD_Rte_2986:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
  Finite Execution Time Analysis justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

  \ID FETA_RTE_BLOCKING
  \DESCRIPTION    The RTE supports the configuration of blocking APIs without timeout. When they do not receive any answer
                  they can prevent other entities from running.
  \COUNTERMEASURE \S Blocking APIs without timeouts must not be used for fail-operational systems SMI-2125 SMI-466082
                  \M RTE Analyzer lists blocking APIs without timeout in the configuration feedback

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
