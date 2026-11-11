/*===========================================================================*/
/**
 * @file SWC_CDD_IPC_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock implementation file for SWC_CDD_IPC unit testing
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#include "SWC_CDD_IPC_fake.h"

/*===========================================================================*
 * External Variable Definitions
 *===========================================================================*/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint8_t test_ipc_crc_var           = 0;
volatile uint8_t test_Injection_control_ipc = 0;
volatile uint8_t test_Failure_Type_ipc      = 0;
Dt_IPC_Faults ipc_crc_faults                = {0};
#endif

/* Storage for extern variables declared in the stub ipc_mss.h */
uint8_t IPC_Sp_Post_Proc_Buf_Read_idx     = 0;
uint32_t IPC_Sp_Post_Proc_Buf_Read_Idx    = 0;
uint32_t PSP_Ping_Buf_Addr                = 0;
uint32_t PSP_Pong_Buf_Addr                = 0;
D2M_Msg_T *IPC_Sp_Post_Proc_Buf_Read_Addr = NULL;

/*===========================================================================*
 * IPC Data Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_Sp_Post_Buf_Read_Addr_Raw);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_Sp_Post_Buf_Read_Idx_Raw);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_M2D_Crc_Err_Cnt);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_D2M_Crc_Err_Cnt);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Check_D2M_Crc_Header, D2M_Msg_T *);
DEFINE_FAKE_VALUE_FUNC(volatile Ipc_Notify_Structure_T *, Get_IPC_Notify_Buffer, Core_To_Core_ID_T, Ring_Buffer_RW_T);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_HW_Accel_Test_Fault);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_CheckpointReached, WdgM_SupervisedEntityIdType, WdgM_CheckpointIdType);
DEFINE_FAKE_VALUE_FUNC(PFM_Flow_Status_T, PFM_Get_Status);
/*===========================================================================*
 * RTE Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data, Dt_Alignment_M2D_Data *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults, const Dt_IPC_Faults *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI, Dt_Fault_name_FHTI);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults,
                       const Dt_RadarCapability_Faults *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data,
                       const Dt_Alignment_IPC_Data *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo,
                       const uint8_t *);

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached,
                       WdgM_CheckpointIdType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Wdg_Disable_Read, Dt_Wdg_Type);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation);

DEFINE_FAKE_VOID_FUNC(Set_IPC_XCP_Fault_Injn_Var, uint8_t);
DEFINE_FAKE_VOID_FUNC(Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger);
DEFINE_FAKE_VOID_FUNC(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms);
DEFINE_FAKE_VOID_FUNC(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete);
