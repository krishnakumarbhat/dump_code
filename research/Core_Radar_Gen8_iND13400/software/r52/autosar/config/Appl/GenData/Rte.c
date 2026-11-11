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
 *             File:  Rte.c
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
#define RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_01 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  0U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_02 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  1U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_03 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  2U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_04 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  3U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_05 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  4U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_06 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  5U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_07 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  6U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_08 = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  7U
};


#define RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

P2CONST(SchM_ConfigType, AUTOMATIC, RTE_VAR_CLEARED) Rte_VarCfgPtr;

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_CLEARED) Rte_InitState; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_CLEARED) Rte_StartTiming_InitState; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Fault_T, RTE_CONST) Rte_C_Fault_T_Dt_Fault_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_StaticRegCheckFailureInfo, RTE_CONST) Rte_C_Dt_StaticRegCheckFailureInfo_592DFB8E305146EF095876B202DE71F7 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_VIN_T, RTE_CONST) Rte_C_VIN_T_Dt_VIN_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(AttempCounter_Type, RTE_CONST) Rte_C_AttempCounter_Type_7D1FF15F18E3EC914DB76CAD74045F0B = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Crypto_CustomFunctions_VersionStruct, RTE_CONST) Rte_C_Crypto_CustomFunctions_VersionStruct_2B9911959C404BA1FFA8D0AED7E2279F = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DID_StaticAlignment_NonConfig_Param_T, RTE_CONST) Rte_C_DID_StaticAlignment_NonConfig_Param_T_823EC5FD85DD283D19FF63440986798A = {
  0U, 0U, 0U, 0, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0, 0, 0U, 0U, 0, 0U, 0, 0U, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_A2H_ErrorFlags, RTE_CONST) Rte_C_A2H_ErrorFlags_Dt_A2H_ErrorFlags = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_ALIGNMENT_STATUS, RTE_CONST) Rte_C_Snapshot_SupplierCode_Dt_ALIGNMENT_STATUS = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_AdcData_T, RTE_CONST) Rte_C_Dt_AdcData_T_497FFB561B06C50A6AEA9B6E5B7CE8EE = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_AlignmentAuto, RTE_CONST) Rte_C_Dt_AlignmentAuto_6251AFA51AD475336F055247A2E60C00 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_AlignmentService, RTE_CONST) Rte_C_Dt_AlignmentService_F3B6D2FEF62432E34D1714C7FDA38CD2 = {
  0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_AlignmentShortTrack, RTE_CONST) Rte_C_Dt_AlignmentShortTrack_E9ECF93705CBFDA821A07DF1419C2E8D = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_AlignmentStatic, RTE_CONST) Rte_C_Dt_AlignmentStatic_4B1BE51452D1304D84D948271488D584 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_Faults_T, RTE_CONST) Rte_C_Alignment_faults_Dt_Alignment_Faults_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_Handler, RTE_CONST) Rte_C_Dt_Alignment_Handler_F75BA9BCF079604D21DD8E6F13A16322 = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_IPC_Data, RTE_CONST) Rte_C_Dt_Alignment_IPC_Data_66F72BAABD9C644457CAA65FE1EC7928 = {
  {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F}, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U,
  0U, 0U, FALSE, 0U, 0U, 0U, 0.0F, 0.0F, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U}, {0.0F, 0.0F,
  0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U}, 0U, 0U, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_M2D_Data, RTE_CONST) Rte_C_Dt_Alignment_M2D_Data_06F3576E6E43DBD70FA8C6FA59A3A983 = {
  {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0U, 0U}, {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, {0.0F, 0.0F, 0.0F, 0.0F}, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_NVM_T, RTE_CONST) Rte_C_AutoAlignment_NvM_T_Dt_Alignment_NVM_T = {
  {0.0F, 0.0F, 0U}, {0U, 0U, 0.0F}, {0.0F, 0.0F}, {0U, 0U, 0.0F}, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Auto_Alignment_Result_T, RTE_CONST) Rte_C_Auto_Alignment_Result_Dt_Auto_Alignment_Result_T = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Auto_Alignment_Status_Information, RTE_CONST) Rte_C_Dt_Auto_Alignment_Status_Information_6F1C5CC42D3DD7770F10DA0DD06DF3C5 = {
  0U, 0U, 0U, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0U, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Battery_Tst_T, RTE_CONST) Rte_C_Battery_Tst_T_Dt_Battery_Tst_T = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_CPU_Load, RTE_CONST) Rte_C_Dt_CPU_Load_3ADA6DF3F33ECD59801CE9F45DA025DA = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_CustDegradation, RTE_CONST) Rte_C_CustDegradation_Dt_CustDegradation = {
  85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Customer_Domain_Errors, RTE_CONST) Rte_C_Customer_Domain_Faults_Dt_Customer_Domain_Errors = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Customer_SW_Version, RTE_CONST) Rte_C_Dt_Customer_SW_Version_9316ED4AFE347AE2DF0E9A4964AAE922 = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_D2H_ErrorFlags, RTE_CONST) Rte_C_D2H_ErrorFlags_Dt_D2H_ErrorFlags = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Dataset_ECU_Config_T, RTE_CONST) Rte_C_Dt_Dataset_ECU_Config_T_29E91F69E2FAE291DCAC176C8CB8268E = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_ECC_Correctable_Error_Counters, RTE_CONST) Rte_C_Dt_ECC_Correctable_Error_Counters_C9BEAC1F82ABA894768A4299B6145C05 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_ECC_Correctable_Error_Counters, RTE_CONST) Rte_C_ECC_Correctable_Error_Counters_Dt_ECC_Correctable_Error_Counters = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_FailSafe_ResetReason_T, RTE_CONST) Rte_C_FailSafe_ResetReason_T_Dt_FailSafe_ResetReason_T = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, FALSE, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Hardware_Fault_Error_Status, RTE_CONST) Rte_C_Dt_Hardware_Fault_Error_Status_D0B7641A8FB1DE09AA69E2A7F0AE9685 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_ID_data, RTE_CONST) Rte_C_ID_data_Dt_ID_data = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_IPC_Faults, RTE_CONST) Rte_C_Dt_IPC_Faults_4F2529105A8C946361997CF51C52C9DA = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Initial_Alignment_Performance_Result_T, RTE_CONST) Rte_C_Initial_Alignment_Performance_Result_Dt_Initial_Alignment_Performance_Result_T = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Initial_Alignment_Result_T, RTE_CONST) Rte_C_Initial_Alignment_Result_Dt_Initial_Alignment_Result_T = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_MMIC_B_ErrorFlags, RTE_CONST) Rte_C_MMIC_B_ErrorFlags_Dt_MMIC_B_ErrorFlags = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_MMIC_ErrorFlags, RTE_CONST) Rte_C_MMIC_ErrorFlags_Dt_MMIC_ErrorFlags = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Manual_Alignment_Execution_Data_CRC, RTE_CONST) Rte_C_Dt_Manual_Alignment_Execution_Data_CRC_D239E83BEA087CE8D08EBACC2DD214A6 = {
  {0U, 0U, 0, 0}, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Mcu_Startup_Fault, RTE_CONST) Rte_C_Dt_Mcu_Startup_Fault_49D25C89294F307D4B5291C6C54B4484 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Memory_Exception_Info_T, RTE_CONST) Rte_C_MemExceptionInfo_Dt_Memory_Exception_Info_T = {
  0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_OpModeShutdown, RTE_CONST) Rte_C_OpModeShutdown_init_T_Dt_OpModeShutdown = {
  85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_Alignment_Faults_T, RTE_CONST) Rte_C_PltToFltMgr_Alignment_Faults_Dt_PltToFltMgr_Alignment_Faults_T = {
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_Blockage_Detection_T, RTE_CONST) Rte_C_VldtnToFltMgr_Blockage_Detection_T_Dt_PltToFltMgr_Blockage_Detection_T = {
  85U, 85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_Host_Micro_Diag_T, RTE_CONST) Rte_C_VldtnToFltMgr_Host_Micro_Diag_T_Dt_PltToFltMgr_Host_Micro_Diag_T = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_InterProcessor_Commn_T, RTE_CONST) Rte_C_VldtnToFltMgr_InterProcessor_Commn_T_Dt_PltToFltMgr_InterProcessor_Commn_T = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T, RTE_CONST) Rte_C_VldtnToFltMgr_MMIC_A_MMIC_Diag_T_Dt_PltToFltMgr_MMIC_A_MMIC_Diag_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_MMIC_B_Diag_T, RTE_CONST) Rte_C_VldtnToFltMgr_MMIC_B_Diag_T_Dt_PltToFltMgr_MMIC_B_Diag_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_Memory_Diagnostics_T, RTE_CONST) Rte_C_VldtnToFltMgr_Memory_Diagnostics_T_Dt_PltToFltMgr_Memory_Diagnostics_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_PltToFltMgr_Micro_Temp_Fault_Status_T, RTE_CONST) Rte_C_VldtnToFltMgr_Micro_Temp_Fault_Status_T_Dt_PltToFltMgr_Micro_Temp_Fault_Status_T = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RadarCapability_Faults, RTE_CONST) Rte_C_RadarCapability_Dt_RadarCapability_Faults = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RadarCoreStatus, RTE_CONST) Rte_C_RadarCoreStatus_T_Dt_RadarCoreStatus = {
  2U, 85U, 170U, 3U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RadarDiagRequest, RTE_CONST) Rte_C_RadarDiagRequest_T_Dt_RadarDiagRequest = {
  85U, 85U, 85U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RawAdcDataFilt_T, RTE_CONST) Rte_C_Dt_RawAdcDataFilt_T_E8FAE26FA1700A19F80F778BF84DDF28 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RawAdcDataFilt_T, RTE_CONST) Rte_C_RawAdcDataFilt_T_Dt_RawAdcDataFilt_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_RawAdcData_T, RTE_CONST) Rte_C_Dt_RawAdcData_T_92BA6058537F7CFE01EA078001733C6C = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Rdr_Hw_Tst_T, RTE_CONST) Rte_C_Rdr_Hw_Tst_T_Dt_Rdr_Hw_Tst_T = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Rfe_REC_NREC_Fault, RTE_CONST) Rte_C_Dt_Rfe_REC_NREC_Fault_566B7755EC2A27546EBED05509161E47 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Rfe_REC_NREC_Fault, RTE_CONST) Rte_C_Rfe_R1R2_Fault_T_Dt_Rfe_REC_NREC_Fault = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_SensorPosition_Data_T, RTE_CONST) Rte_C_SensorPos_default_Dt_SensorPosition_Data_T = {
  {255U, 255U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Service_Alignment_Engineering_Non_Configuration_Parameters, RTE_CONST) Rte_C_Dt_Service_Alignment_Engineering_Non_Configuration_Parameters_65C795F7D4C420CB8A436E0237553F0B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Service_Alignment_Result_Parameters, RTE_CONST) Rte_C_Dt_Service_Alignment_Result_Parameters_F9AD1DFC4C071EAB3C19C60D85DAADE8 = {
  0U, 0U, 0U, 0, 0, 0, 0, 0, 0, 0, 0U, 0U, 0U, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0, 0
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_SignalTimeoutStatus_Group2_T, RTE_CONST) Rte_C_SignalTimeoutStatus_Group2_T_Dt_SignalTimeoutStatus_Group2_T = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Snapshot_received_signal_T, RTE_CONST) Rte_C_Snapshot_received_signal_T_Dt_Snapshot_received_signal_T = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Static_Alignment_Engineering_Parameters, RTE_CONST) Rte_C_Dt_Static_Alignment_Engineering_Parameters_7E345F8E8047AB1EF495C38D9D6F0715 = {
  0U, 0, 0U, 0, 0, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_CONST) Rte_C_Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_5F1F99062FD261F0CC1D457494035164 = {
  {0, 0, 120U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_CONST) Rte_C_Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC_CDCCBF02DA3C25359EC6D6D27E2A3DA2 = {
  {0, 0, 0U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_TR_ModeManager, RTE_CONST) Rte_C_TR_ModeManager_T_Dt_TR_ModeManager = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_VSE_NVM_Params, RTE_CONST) Rte_C_Dt_VSE_NVM_Params_0671719A05B77BCE683C6C16B951E137 = {
  0, 0, 0, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST) Rte_C_Dt_Write_Alignment_NvM_Data_T_390AD3A1856879CD56B5C82887E9216C = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST) Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_XCP_Set_Output, RTE_CONST) Rte_C_XCP_Output_State_Dt_XCP_Set_Output = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Xcp_Read_Write_Did_T, RTE_CONST) Rte_C_Dt_Xcp_Read_Write_Did_T_42D1DCC3F8BF6F5DC60D9C88450ACD3F = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_ADAS_FN_Enable_disable_sts_ALVCAN, RTE_CONST) Rte_C_I_SG_ADAS_FN_Enable_disable_sts_ALVCAN_73F8A3C3EFB2606717A8D717CA1899EE = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_CCVS1_ALVCAN, RTE_CONST) Rte_C_Ap_SG_CCVS1_adt_ALVCAN_199BC6E5B777D6A45F9DBECC48800316 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_CLS_Tx_16_ALVCAN, RTE_CONST) Rte_C_I_SG_CLS_Tx_16_ALVCAN_C5001DC4A8E18F6ECCB3CF4AF179D8CB = {
  FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_CLS_Tx_4_ALVCAN, RTE_CONST) Rte_C_I_SG_CLS_Tx_4_ALVCAN_09DB4C174D22D8D3C356FECFF89A446A = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_ETC2_00_ALVCAN, RTE_CONST) Rte_C_Ap_SG_ETC2_00_adt_ALVCAN_9D2304C396BEEAD6B786C2C5ADF23FDA = {
  250U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_ETC2_03_ALVCAN, RTE_CONST) Rte_C_Ap_SG_ETC2_03_adt_ALVCAN_A0C072C8F769CD33314B6AAF6003E11E = {
  125U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_AlignmentStatus1_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_AlignmentStatus1_adt_ALPCAN_5D09FF41B4AFB52F4334731F2EB13F60 = {
  0U, 0U, 0U, 15708U, 872U, 0, 0U, 0U, 0U, 10000U, 10000U, 0U, 0U, 0U, 0U, 0, 0, 0U, 0U, FALSE, 0U, 0U, 0, 0, 0U, 0U,
  0U, 0U, 0, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0, 0, 0, 0
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_AlignmentStatus2_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_AlignmentStatus2_adt_ALPCAN_229AA2CE31766849A6B5AA966649ED2A = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0, 0, 0U, 0, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_001_004_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_001_004_adt_AL_AB436285A03C826BA228B0C5F9E06990 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_005_008_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_005_008_adt_AL_6E79A3611DFEE8CADC30B8CF94E9D85D = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_009_012_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_009_012_adt_AL_A7BD56EF2BE2B00050115453E5154CBA = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_013_016_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_013_016_adt_AL_4AA6261ECDE0C27BEBBBA937DA4F0E98 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_017_020_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_017_020_adt_AL_B89AAA3E0AD4278D26434B633358014F = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_021_024_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_021_024_adt_AL_61A4DA6AE5939C059C3D9B559880A8AE = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_025_028_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_025_028_adt_AL_688ABB71BACEF71106FC0ACF7599258A = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_029_032_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_029_032_adt_AL_45E0FF28B3DB9E992DC97205C0E289C1 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_033_036_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_033_036_adt_AL_DD327878D7F5A4CB52A45E5EF32171ED = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_037_040_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_037_040_adt_AL_1EC6C278184F1EAED33B2CA70238C291 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_041_044_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_041_044_adt_AL_5662AE3C01105AFFE37F118F57F9DCFF = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_045_048_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_045_048_adt_AL_8619279037D3EACFE22137C92E58CC8A = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_049_052_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_049_052_adt_AL_FE8B757CF8E1F2CD34711AF679E15023 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_053_056_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_053_056_adt_AL_0181708F5CA2BB80C618E1AAFFDAB349 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_057_060_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_057_060_adt_AL_6786C0C4B0E3EF7BB1BF46AEC6152228 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_061_064_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_061_064_adt_AL_40CCEB7CBB5EE84237A4B4BF0F84F89C = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_065_068_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_065_068_adt_AL_30E9F6F292275676F54AD1A303456076 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_069_072_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_069_072_adt_AL_C6B6C377BE9322F6BD98D5258B959570 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_073_076_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_073_076_adt_AL_B5E72C24742AEB3A9454F86B7AD76B34 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_077_080_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_077_080_adt_AL_BA28F512582FA64473E37C3EB3357123 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_081_084_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_081_084_adt_AL_F35ED2A968FEE5D0119C66B757C7EE43 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_085_088_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_085_088_adt_AL_7D3C6B37D534C2DF83169BC19E4EFBDC = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_089_092_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_089_092_adt_AL_59E27500095F241B9AFC8C59710C5828 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_093_096_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_093_096_adt_AL_BBE48FD6C31F32AFE3662213F493FD7D = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_097_100_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_097_100_adt_AL_22A9C6F25CBCA1CF419DAE26F3C10C7E = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_101_104_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_101_104_adt_AL_94A5C03B2C83F6B03CC8200D115A88C3 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_105_108_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_105_108_adt_AL_A89AE1E429E82515C81621A0EE476462 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_109_112_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_109_112_adt_AL_F9A4BF2D2FF8D2E2297FD53B9FFAE79C = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_113_116_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_113_116_adt_AL_F1C68F4222B31C43A8152FF183DD9AEE = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_117_120_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_117_120_adt_AL_B09449783D8C64ADED8E9C837D4386AA = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_121_124_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_121_124_adt_AL_30B07C126E93D24E855FF586F5EE6DE5 = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_Detections_125_128_AL, RTE_CONST) Rte_C_Ap_SG_Fusion_Detections_125_128_adt_AL_A3AF6FC79C17F07DCBD407B5EC4A70CA = {
  3927U, 3927U, 3927U, 3927U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 127U, 127U, 127U, 127U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
  FALSE, FALSE, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U, 128U, 128U, 128U, 128U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_RadarCapability_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_RadarCapability_adt_ALPCAN_2649F66AA39B4A340ECACB41B4F16360 = {
  0, 0, FALSE, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U,
  0U, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_RadarHeader_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_RadarHeader_adt_ALPCAN_9AD395988C966A205479746095A6CD25 = {
  349U, 349U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 32768U, 32768U, 0U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 90U,
  0U, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_RadarStatus2_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_RadarStatus2_adt_ALPCAN_0B8FBC696FBD7681DBEE7436321B6949 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 0U, 0U, 0U, 50U, 50U, 50U, 50U, FALSE, 0U, 0U, 0U, FALSE,
  0U, FALSE, 0, 0U, 0U, FALSE, 0U, 0U, 0U, FALSE, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_Fusion_RadarStatus_ALPCAN, RTE_CONST) Rte_C_Ap_SG_Fusion_RadarStatus_adt_ALPCAN_65B0F7E7A8830F505F6E623465FC2E6C = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 7854U, 0, 8192U, 32768U, 32768U,
  FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN, RTE_CONST) Rte_C_I_SG_GW_ADAS_FN_Enable_disable_sts_ALPCAN_1E92A221B13C43277BDAD8E6906EF87B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_CCVS1_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_CCVS1_adt_ALPCAN_F2865E791257E31150A3DF17BB9FCCCB = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_CLS_Tx_16_ALPCAN, RTE_CONST) Rte_C_I_SG_GW_CLS_Tx_16_ALPCAN_2C98F1BA0407ED56CD7512B1FB221988 = {
  FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_CLS_Tx_4_ALPCAN, RTE_CONST) Rte_C_I_SG_GW_CLS_Tx_4_ALPCAN_241512708E80BB9659CC3782D6D420DD = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_ETC2_03_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_ETC2_03_adt_ALPCAN_E56B0027944EABDCD7DA43DD8B42B96B = {
  125U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_ETC2_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_ETC2_adt_ALPCAN_15D5BAC2232A3B0DFD9B011035CC49C8 = {
  125U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_OEL_ALPCAN, RTE_CONST) Rte_C_I_SG_GW_OEL_ALPCAN_B2FECD2EAC31A4F18C08D34E00637C4C = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_SAS_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_SAS_adt_ALPCAN_24DA758B8C9AFF8240A3CFB056C98F23 = {
  0U, 0U, 0U, 0U, 27523U, 27523U, 32U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_TD_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_TD_adt_ALPCAN_B299BE176683C795D89BD44FD36BBE62 = {
  0U, 0U, 125U, 125U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_VDC2_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_VDC2_adt_ALPCAN_BE4F8A3A21490E67FA9209F40E103198 = {
  32127U, 125U, 27523U, 32113U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_VD_ALPCAN, RTE_CONST) Rte_C_Ap_SG_GW_VD_adt_ALPCAN_8521E729A885D37CCF4C494A62A22389 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_GW_VI_ALPCAN, RTE_CONST) Rte_C_I_SG_GW_VI_ALPCAN_18B56A8B45E198787840069CC736EFD1 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_OEL_ALVCAN, RTE_CONST) Rte_C_I_SG_OEL_ALVCAN_D6F8A39A179562A2E15D70434C867E6C = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_SAS_ALVCAN, RTE_CONST) Rte_C_Ap_SG_SAS_adt_ALVCAN_4943EFE060C98B4C3658E6892658EF73 = {
  0U, 0U, 0U, 0U, 27523U, 27523U, 32U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_TD_ALVCAN, RTE_CONST) Rte_C_Ap_SG_TD_adt_ALVCAN_39A6B51DDDAED2C0473B2BE6B1487EF1 = {
  0U, 0U, 250U, 250U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_VDC2_ALVCAN, RTE_CONST) Rte_C_Ap_SG_VDC2_adt_ALVCAN_DCB9A33AEDFA3C319E70AA34D24DD4CD = {
  32127U, 125U, 32127U, 32113U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_VD_ALVCAN, RTE_CONST) Rte_C_Ap_SG_VD_adt_ALVCAN_BA9080CD78515C4F8148DFFFE93BF062 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_VI_ALVCAN, RTE_CONST) Rte_C_I_SG_VI_ALVCAN_0169A18E4765AB931552C7E3D70D823F = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_VehicleStatus_AL, RTE_CONST) Rte_C_Ap_SG_VehicleStatus_adt_AL_F115F1E0A0E76B99498B5A88064BA157 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U,
  0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 448U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(I_SG_XcpCTOReq_AL, RTE_CONST) Rte_C_I_SG_XcpCTOReq_AL_ECF484F46C5C5F5D7AF0B5DBE1414436 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_Cal_Version_Info_Type, RTE_CONST) Rte_C_Idt_Cal_Version_Info_Type_CD74C5DC964C6519DB93441640348751 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_SW_Version_Info_T, RTE_CONST) Rte_C_Idt_SW_Version_Info_T_96E8A160D9BF24D1E9053E1C9A155DCE = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_Type_MMIC_Temperature, RTE_CONST) Rte_C_Idt_Type_MMIC_Temperature_Idt_Type_MMIC_Temperature = {
  0, 0, 0, 0, 0, 0, 0
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_XCP_Fault_Override_T, RTE_CONST) Rte_C_XCP_Fault_Override_Idt_XCP_Fault_Override_T = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_XCP_RFBIST_Status_T, RTE_CONST) Rte_C_Idt_XCP_RFBIST_Status_T_15E3F9BF21B19D5CA8FB804F198F59EC = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_XCP_Single_Look_T, RTE_CONST) Rte_C_Idt_XCP_Single_Look_T_F486B559DB791688946611468EFC166A = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SR_VEHICLE_STATUS_RECORD, RTE_CONST) Rte_C_SR_VEHICLE_STATUS_RECORD_001B587F069B9748FB97201F8DA902CC = {
  {0.0F, FALSE, 0U, 0U, 0.0F, 0.0F, 0.0F, 0U, 0U, 0.0F, 0.0F, 0U}, {0U, FALSE, 0U, 0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U,
  0U, 0U, 0U, 0U}, {0ULL, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(StbM_TimeStampType, RTE_CONST) Rte_C_StbM_TimeStampType_1B1E9F570D8098D4CEDA8C1F0C53F421 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TR_AdcMeasurement_T, RTE_CONST) Rte_C_TR_AdcMeasurement_T_A13744F7BAD15CFDC387E03952E7B16B = {
  FALSE, FALSE
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Calibration Parameters (BSW local, SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/
#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_VIN_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_VIN_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(AttempCounter_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_CMP_PRJ_UDSHandler_SWC_UDSHandler_Attemptcounter_DefaultValue = {
  0U, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_EcuPosition_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_IoHwAb_ECU_Position_ROMDefault = {
  255U, 0U, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_Alignment_NvMBlock_DefaultValue;
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_ECC_Correctable_Error_Counters, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_Correctable_Fault_NvM_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Write_Alignment_NvM_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_NvMBringUp_DefaultValue;
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Rfe_REC_NREC_Fault, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_RFE_R1R2_Fault_NvM_DefaultValue;
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Manual_Alignment_Execution_Data_CRC, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_Manual_alignment_Execution_DefaultValue = {
  {0U, 0U, 0, 0}, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_FailSafe_ResetReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_PLT_CDD_FailSafe_DefaultValue;
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Static_Alignment_Engineering_Write_Configuration_Parameters_CRC, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_Static_Alignment_Write_Parameters_DefaultValue = {
  {0, 0, 0U}, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_VSE_NVM_Params, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SWC_VSE_NVM_Params_DefaultValue = {
  0, 0, 0, 0, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_SensorPosition_Data_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Appl_NvMHandler_SensorPos_NvM_DefaultValue = {
  {255U, 255U}, 0U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_FailSafe_ExceptionReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_DefaultValue = {
  {{255U, 255U, 65535U, {4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U}}, {255U, 255U, 65535U, {
  4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U}}, {255U, 255U, 65535U, {4294967295U, 4294967295U,
  4294967295U, 4294967295U, 4294967295U}}}, 255U
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_FailSafe_ResetReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_CDD_FailSafe_ResetReason_DefaultValue = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, FALSE, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dt_Alignment_NVM_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_Radar_Alignment_Handler_Appl_AutoAlignment_DefaultValue = {
  {0.0F, 0.0F, 0U}, {0U, 0U, 0.0F}, {0.0F, 0.0F}, {0U, 0U, 0.0F}, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
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

/* Queue definitions for internal C/S connections */
#define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_OsCore0_QM_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, RTE_VAR_CLEARED) Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueType_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, RTE_VAR_CLEARED) Rte_CS_ServerQueue_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ServerQueueInfoType_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, RTE_VAR_CLEARED) Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
VAR(Rte_CS_ClientQueueType_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, RTE_VAR_CLEARED) Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback; /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */

#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define RTE_EcucPartition_Core0_ASIL_START_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


CONST(Rte_CS_ClientConfigType_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback[1] = {
  Appl_Task_High_Prio
};

CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation
  }
};


#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_EcucPartition_OsCore0_QM_START_SEC_CONST_QM_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream[2] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    &Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream
  },
  {
    &Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream
  }
};


CONST(Rte_CS_ClientConfigType_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback, RTE_CONST) Rte_CS_ClientConfig_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback[1] = { /* PRQA S 1514, 1533 */ /* MD_Rte_1514, MD_Rte_1533 */
  {
    1,
    Rte_CS_WaitingTaskList_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback,
    &Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback
  }
};


#define RTE_EcucPartition_OsCore0_QM_STOP_SEC_CONST_QM_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
 * Helper functions for mode management
 *********************************************************************************************************************/
#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdClientServiceState(BswM_SDC_SdClientServiceState mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdConsumedEventGroupState(BswM_SDC_SdConsumedEventGroupState mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_SDC_SdEventHandlerState(BswM_SDC_SdEventHandlerState mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}


#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 4U;
  }
  else if (mode == 3U)
  {
    ret = 6U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else if (mode == 5U)
  {
    ret = 3U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else
  {
    ret = 7U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


#define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
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

#define RTE_Lib_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#ifndef RTE_ENABLE_CUSTOM_MEMCPY
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++) /* FETA_RTE_MEMCPY */
  {
    dst[i] = src[i];
  }
}
#endif

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1U)

#ifndef RTE_ENABLE_CUSTOM_MEMCPY32
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i = 0;

  if (num >= 16U)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0U) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0U)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3U); i += 4U) /* FETA_RTE_MEMCPY32 */
      {
        adst[i] = asrc[i];
        adst[i+1U] = asrc[i+1U];
        adst[i+2U] = asrc[i+2U];
        adst[i+3U] = asrc[i+3U];
      }

      while (i < asize) /* FETA_RTE_MEMCPY32 */
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15U) < num; i += 16U) /* FETA_RTE_MEMCPY32 */
      {
        dst[i] = src[i];
        dst[i+1U] = src[i+1U];
        dst[i+2U] = src[i+2U];
        dst[i+3U] = src[i+3U];
        dst[i+4U] = src[i+4U];
        dst[i+5U] = src[i+5U];
        dst[i+6U] = src[i+6U];
        dst[i+7U] = src[i+7U];
        dst[i+8U] = src[i+8U];
        dst[i+9U] = src[i+9U];
        dst[i+10U] = src[i+10U];
        dst[i+11U] = src[i+11U];
        dst[i+12U] = src[i+12U];
        dst[i+13U] = src[i+13U];
        dst[i+14U] = src[i+14U];
        dst[i+15U] = src[i+15U];
      }
    }

  }
  while (i < num) /* FETA_RTE_MEMCPY32 */
  {
    dst[i] = src[i];
    ++i;
  }
}
#endif

#ifndef RTE_ENABLE_CUSTOM_PARTIALMEMCPY
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(void, RTE_CODE) Rte_PartialMemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32 dstSize, uint32 srcSize, uint32 dstOffset, uint32 srcOffset, uint32 len)
{
  if (((dstOffset + len) > dstOffset) && ((dstOffset + len) <= dstSize) && ((srcOffset + len) > srcOffset) && ((srcOffset + len) <= srcSize))
  {
    P2VAR(uint8, AUTOMATIC, RTE_VAR_CLEARED) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_CLEARED))destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
    P2CONST(uint8, AUTOMATIC, RTE_VAR_CLEARED) src = (P2CONST(uint8, AUTOMATIC, RTE_VAR_CLEARED))source; /* PRQA S 0316 */ /* MD_Rte_0316 */
    Rte_MemCpy32(&dst[dstOffset], &src[srcOffset], len); /* PRQA S 0315 */ /* MD_Rte_0315 */
  }
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif

#ifndef RTE_ENABLE_CUSTOM_MEMCLR
FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_CLEARED) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_CLEARED) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_CLEARED))ptr; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++) /* FETA_RTE_MEMCLR */
  {
    dst[i] = 0;
  }
}
#endif

#define RTE_Lib_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_Lifecycle_START_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) SchM_Start(void)
{
  Rte_ThreadFence();
  Rte_InitState = RTE_STATE_SCHM_START;
}

FUNC(void, RTE_CODE) SchM_Init(P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) ConfigPtr)
{
  Rte_VarCfgPtr = ConfigPtr;
  /* activate the tasks */
  (void)ActivateTask(Appl_BackgroundTask); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Task_Communication); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Task_High_Prio); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(BSW_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Radar_Ctrl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_ThreadFence();
  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(void, RTE_CODE) SchM_StartTiming(void)
{
  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_Appl_Task_High_Prio_0_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Appl_Task_High_Prio_0_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Rtm_Rtm_MainFunction, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Appl_Task_Communication_0_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(25U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_Task_0_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_Task_0_20ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(20U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BSW_Task_0_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Appl_BackgroundTask_0_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* C/S queue initialization */
  Rte_CS_ServerQueueInfo_SWC_PLT_Appl_Communication_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_CAN_Tx_RE_Communication_Tx.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_ADC_Populate_ADC_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Debug_Populate_Debug_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Detection_Populate_Detection_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Header_Populate_Header_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Header_Populate_Header_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_MMIC_Populate_MMIC_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_RDD_Populate_RDD_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_PostRadarProcessing_Status_Populate_Status_Stream.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_Radar_Control_PostRadarProcessing_Status_Populate_Status_Stream.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Logging_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_Active = 0;
  Rte_CS_ClientQueue_StbM_StbM_MeasurementNotification_StbMSynchronizedTimeBase_TimeRecordBlock_Callback.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Free = 1;
  Rte_CS_ServerQueueInfo_SWC_PLT_CDD_Radar_Control_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_Active = 0;
  Rte_CS_ClientQueue_SWC_CDD_IPC_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted = TRUE;
  Rte_CS_ClientQueue_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Trigger_Operation.Rte_CallCompleted = TRUE;

  /* activate the tasks */
  (void)ActivateTask(Appl_IPC_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Init); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Task_Fast); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Appl_Task_Logging); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Init_Task_Qm); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Appl_IPC_Task_0_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Radar_Ctrl_Task_0_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST, RTE_MSEC_OsCounter(5U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Appl_Task_Communication_0_25ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(25U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(25U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(2U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Appl_Task_0_10ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Appl_Task_0_50ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Appl_Task_0_5ms, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task, RTE_MSEC_OsCounter(0U) + (TickType)1U, RTE_MSEC_OsCounter(25U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

  Rte_StartTiming_InitState = RTE_STATE_INIT;
  Rte_ThreadFence();
  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_Appl_IPC_Task_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_CDD_IPC_RE_IPC_VSE_Handler_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Appl_Task_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Appl_Task_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Appl_Task_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Appl_Task_Communication_0_25ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_Communication_RE_Communication_Tx_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Logging_RE_Logging_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_Diag_RE_PLT_Diag_PlatformTime_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_Main_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_CMP_PRJ_UDSHandler_RE_SWC_CMP_PRJ_UDSHandler_Main_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_IntWDG_RE_PLT_WDG_INTERNAL_WDG_BSW_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_Appl_NvMHandler_RE_PLT_Appl_NvMHandler_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Radar_Ctrl_Task_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Control_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_ThreadFence();
  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_Appl_BackgroundTask_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Appl_Task_Communication_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx_Periodic); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Appl_Task_High_Prio_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Appl_Task_High_Prio_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_Task_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_Task_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BSW_Task_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Rtm_Rtm_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_ThreadFence();
  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_OsCore0_ASIL();
  Rte_InitMemory_OsCore_Qm();
}

#define RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: Rule11.4
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
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

  \ID FETA_RTE_MEMCLR
  \DESCRIPTION    Iterations to initialize memory with zero.
  \COUNTERMEASURE \S SMI-322

  \ID FETA_RTE_MEMCPY
  \DESCRIPTION    Iterations to copy data from source to destination.
  \COUNTERMEASURE \S SMI-322

  \ID FETA_RTE_MEMCPY32
  \DESCRIPTION    Iterations to copy data from source to destination.
  \COUNTERMEASURE \S SMI-322

COV_JUSTIFICATION_END */
