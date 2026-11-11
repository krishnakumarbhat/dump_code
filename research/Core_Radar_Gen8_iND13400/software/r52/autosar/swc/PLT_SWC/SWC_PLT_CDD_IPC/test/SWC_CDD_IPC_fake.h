/*===========================================================================*/
/**
 * @file SWC_CDD_IPC_fake.h
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
 * Fake/Mock header file for SWC_CDD_IPC unit testing
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef SWC_CDD_IPC_FAKE_H
#define SWC_CDD_IPC_FAKE_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

/*===========================================================================*
 * Pre-define include guards to block headers that drag in heavy dependencies.
 * The fake header provides all needed types, macros, and FFF fakes instead.
 * NOTE: ipc_mss.h is resolved via //software/r52/ipc:ipc_mss_h dep added to
 *       SWC_CDD_IPC_unit_test_support_lib.  The real header's extern variable
 *       declarations (IPC_Sp_Post_Proc_Buf_Read_Idx, IPC_Sp_Post_Proc_Buf_Read_Addr)
 *       are satisfied by definitions in SWC_CDD_IPC_fake.cc.
 * NOTE: SWC_CDD_IPC_MemMap.h has no include guard (AUTOSAR MemMap pattern);
 *       a stub file in the test directory provides an empty replacement.
 * NOTE: Rte_SWC_CDD_IPC.h remaps short RTE names (e.g.
 *       Rte_Write_Pp_IPC_Faults_De_IPC_Faults) to long SWC-prefixed names
 *       (Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults). The FFF fakes
 *       therefore use the long (fully-qualified) names to match.
 *===========================================================================*/
#define CRC_CALC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Rte_Type.h"
#include "ipc_data.h"
#include "program_flow_monitor.h"

   /*===========================================================================*
    * Constants and Macros
    *===========================================================================*/

#define DRA_NUM_SANITY_CHECK_DETS (8U)
#define DRA_BITFIELD_LEN          (24U)
#define DRA_MAX_DETS_PER_CLUSTER  (16U)
#define DRA_MAX_NUM_CLUSTERS      (8U)

   /*===========================================================================*
    * IPC Data Functions
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_Sp_Post_Buf_Read_Addr_Raw);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_Sp_Post_Buf_Read_Idx_Raw);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_M2D_Crc_Err_Cnt);
   DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_IPC_D2M_Crc_Err_Cnt);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Check_D2M_Crc_Header, D2M_Msg_T *);
   DECLARE_FAKE_VALUE_FUNC(volatile Ipc_Notify_Structure_T *, Get_IPC_Notify_Buffer, Core_To_Core_ID_T, Ring_Buffer_RW_T);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_HW_Accel_Test_Fault);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_CheckpointReached, WdgM_SupervisedEntityIdType, WdgM_CheckpointIdType);
   DECLARE_FAKE_VALUE_FUNC(PFM_Flow_Status_T, PFM_Get_Status);
   /*===========================================================================*
    * RTE Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data,
                           Dt_Alignment_M2D_Data *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data,
                           const Dt_Alignment_IPC_Data *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults, const Dt_IPC_Faults *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI, Dt_Fault_name_FHTI);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults,
                           const Dt_RadarCapability_Faults *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo,
                           const uint8_t *);

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached,
                           WdgM_CheckpointIdType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Wdg_Disable_Read, Dt_Wdg_Type);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation);

   DECLARE_FAKE_VOID_FUNC(Set_IPC_XCP_Fault_Injn_Var, uint8_t);
   DECLARE_FAKE_VOID_FUNC(Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger);
   DECLARE_FAKE_VOID_FUNC(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms);
   DECLARE_FAKE_VOID_FUNC(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete);

#ifdef __cplusplus
}
#endif

#endif /* SWC_CDD_IPC_FAKE_H */
