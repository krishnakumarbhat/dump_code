#ifndef SWC_PLT_RADAR_ALIGNMENT_HANDLER_FAKE
#define SWC_PLT_RADAR_ALIGNMENT_HANDLER_FAKE
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include "fff.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "Rte_Type.h"
#include "ipc_data.h"

   /*===========================================================================*
    * FAKE VALUE FUNCTIONS for board_revision.c
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
   DECLARE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Xcp_Connect_Status);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data,
                           const Dt_Auto_Alignment_Result_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform,
                           const Dt_Initial_Alignment_Performance_Result_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result,
                           const Dt_Initial_Alignment_Result_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults,
                           const Dt_Alignment_Faults_T *);

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data,
                           Dt_Alignment_IPC_Data *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto,
                           const Dt_AlignmentAuto *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService,
                           const Dt_AlignmentService *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack,
                           const Dt_AlignmentShortTrack *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic,
                           const Dt_AlignmentStatic *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler,
                           const Dt_Alignment_Handler *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data,
                           const Dt_Alignment_M2D_Data *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record,
                           const Dt_Write_Alignment_NvM_Data_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_NvM_Data_Alignment_NvM_Data,
                           Dt_Write_Alignment_NvM_Data_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,
                           Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM,
                           Dt_Write_Alignment_NvM_Data_T *);

   DECLARE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, uint8);

   /*===========================================================================*
    * FAKE VOID FUNCTIONS for board_revision.c
    *===========================================================================*/

#ifdef __cplusplus
}
#endif

#endif
