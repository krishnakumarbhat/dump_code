#include "SWC_PLT_Radar_Alignment_Handler_fake.h"

DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_IPC_D2M_Sp_Post_Proc_Buffer);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Xcp_Connect_Status);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Auto_Alignment_Data_Auto_Alignment_Data,
                       const Dt_Auto_Alignment_Result_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,
                       Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_initial_Alignment_Perform_Result_initial_Alignment_Perform,
                       const Dt_Initial_Alignment_Performance_Result_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,
                       Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Initial_Alignment_Result_Initial_Alignment_Result,
                       const Dt_Initial_Alignment_Result_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Faults_De_Alignment_Faults,
                       const Dt_Alignment_Faults_T *);

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_IPC_Data_De_Alignment_IPC_Data,
                       Dt_Alignment_IPC_Data *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentAuto_De_AlignmentAuto,
                       const Dt_AlignmentAuto *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentService_De_AlignmentService,
                       const Dt_AlignmentService *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentShortTrack_De_AlignmentShortTrack,
                       const Dt_AlignmentShortTrack *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_AlignmentStatic_De_AlignmentStatic,
                       const Dt_AlignmentStatic *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_Handler_De_Alignment_Handler,
                       const Dt_Alignment_Handler *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Alignment_M2D_Data_De_Alignment_M2D_Data,
                       const Dt_Alignment_M2D_Data *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_Radar_Alignment_Handler_Pp_Align_Write_Nvm_Record_Alignment_Record,
                       const Dt_Write_Alignment_NvM_Data_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_NvM_Data_Alignment_NvM_Data,
                       Dt_Write_Alignment_NvM_Data_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Radar_Alignment_Handler_Rp_Alignment_Write_NvM_Data_Write_Alignment_NvM,
                       Dt_Write_Alignment_NvM_Data_T *);

DEFINE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, uint8);

// External variables and constants
extern "C"
{
   // External variable definition
   uint8 Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = 0;
   uint8 Rte_SWC_PLT_CDD_XCP_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag              = 0;

   // Define the constant that was declared in Rte_Type.h
   const Dt_Write_Alignment_NvM_Data_T Rte_C_Write_Alignment_NvM_Data_Dt_Write_Alignment_NvM_Data_T = {0};
}
