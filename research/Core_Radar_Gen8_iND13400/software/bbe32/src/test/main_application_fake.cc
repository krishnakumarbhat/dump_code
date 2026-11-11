/*===========================================================================*/
/**
 * @file main_application_fake.cc
 *
 * FFF fake definitions for main_application.c unit tests.
 */
/*==========================================================================*/

#include "main_application_fake.h"

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Extern variable definitions
 *===========================================================================*/
volatile Trigger_Received_T IPC_R52_To_BBE_Trigger_Received = NO_TRIGGER;
Offline_Mode_T Offline_Mode_Flag_DSP                        = 0U;

/*===========================================================================*
 * FFF function definitions
 *===========================================================================*/

/* Memory pool */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Init, Mem_Pool_T *, void *, uint32_t);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Mem_Pool_Alloc, Mem_Pool_T *, uint32_t, void **);
DEFINE_FAKE_VOID_FUNC(Mem_Pool_Reset, Mem_Pool_T *);

/* IPC communication */
DEFINE_FAKE_VOID_FUNC(Appl_DSP_Process_Onetime_Init);
DEFINE_FAKE_VOID_FUNC(Reset_IPC_AF_Buffer, bool, bool);
DEFINE_FAKE_VOID_FUNC(Send_Range_Proc_Complete, uint32_t);
DEFINE_FAKE_VOID_FUNC(Send_Doppler_RDD_Proc_Complete, uint32_t);
DEFINE_FAKE_VOID_FUNC(Send_SP_Post_Proc_Complete_to_R52, uint32_t);
DEFINE_FAKE_VOID_FUNC(Update_DSP_IPC_Notify);
DEFINE_FAKE_VOID_FUNC(Send_Core_Initialization);
DEFINE_FAKE_VALUE_FUNC(bool, Wait_For_Trigger, volatile uint32_t *);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Ipc_Shared_Buffer_Base_Address);

void Update_RDD_Stream_Header(volatile D2M_Msg_T *d2m_msg_ptr, int error)
{
   if (d2m_msg_ptr == nullptr)
   {
      return;
   }

   volatile Stream_Hdr_T *p_stream_hdr       = &d2m_msg_ptr->payload.rdd_stream_data.stream_hdr;
   volatile Stream_Hdr_T *p_debug_stream_hdr = &d2m_msg_ptr->payload.rdd_debug_data.stream_hdr;
   volatile Look_Data_T *p_look_data         = &d2m_msg_ptr->payload.rdd_stream_data.look_data;

   p_stream_hdr->scan_index = p_look_data->scan_index;
   p_stream_hdr->size       = sizeof(Rdd_Stream_T);
   p_stream_hdr->error_info = static_cast<uint16_t>(error);

   p_debug_stream_hdr->scan_index = p_look_data->scan_index;
   p_debug_stream_hdr->size       = sizeof(Rdd_Debug_Stream_T);
   p_debug_stream_hdr->error_info = static_cast<uint16_t>(error);
}

/* IPC buffer getters — return pointers to static buffers */
static D2M_Msg_T g_d2m_stub_rp               = {};
static D2M_Msg_T g_d2m_stub_dp               = {};
static D2M_Msg_T g_d2m_stub_sp               = {};
static M2D_Msg_T g_m2d_stub                  = {};
static M2D_One_Time_Msg_T g_m2d_onetime_stub = {};

/* TOI stubs — Get_TOI_Init_Parameters needs a valid object with a valid toi_data_status_dst_ptr */
static TOI_Radar_Data_Status_Payload_T g_toi_radar_data_status_stub = {};
static TOI_Input_Params_T g_toi_input_params_stub                   = {};
static TOI_Output_Params_T g_toi_output_params_stub                 = {};

TOI_Input_Params_T *Get_TOI_Init_Parameters_custom(void)
{
   g_toi_input_params_stub.toi_data_status_dst_ptr = &g_toi_radar_data_status_stub;
   return &g_toi_input_params_stub;
}
TOI_Output_Params_T *Get_TOI_Output_Parameters_custom(void)
{
   return &g_toi_output_params_stub;
}

D2M_Msg_T *Get_RP_IPC_D2M_Msg_Buffer_custom(void)
{
   return &g_d2m_stub_rp;
}
D2M_Msg_T *Get_DP_RDD_IPC_D2M_Msg_Buffer_custom(void)
{
   return &g_d2m_stub_dp;
}
D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer_custom(void)
{
   return &g_d2m_stub_sp;
}
M2D_Msg_T *Get_IPC_M2D_Buffer_custom(void)
{
   return &g_m2d_stub;
}
M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer_custom(void)
{
   return &g_m2d_onetime_stub;
}

DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_RP_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_DP_RDD_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(D2M_Msg_T *, Get_SP_Post_Proc_IPC_D2M_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(M2D_Msg_T *, Get_IPC_M2D_Buffer);
DEFINE_FAKE_VALUE_FUNC(M2D_One_Time_Msg_T *, Get_IPC_M2D_One_Time_Buffer);

/* Range processing */
DEFINE_FAKE_VALUE_FUNC(Appl_Range_Return_Values_T, Check_For_Range_Process_Complete_Timeout_Check, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Range_Procesing_Done_Time);

/* Doppler processing */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Doppler_Dram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Doppler_Sram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(Appl_Doppler_Return_Values_T, Appl_Doppler_Rdd_Processing, Radar_Look_T);
DEFINE_FAKE_VOID_FUNC(Set_MMIC_Data_Discard_Info);

/* RDD sub-module init */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Dram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_Rdd_Sram1_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Rdd_Fp_Init, uint32_t);
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Second_Pass_Init, uint32_t);
DEFINE_FAKE_VALUE_FUNC(bool, Appl_Sweep_Bw_Init, uint32_t);

/* FuSa BBE self-test */
DEFINE_FAKE_VOID_FUNC(Enable_Dsp_Ecc);
DEFINE_FAKE_VOID_FUNC(Enable_Dsp_Parity);
DEFINE_FAKE_VOID_FUNC(RA_ESTMEM_ECC_Enable);
extern "C"
{
   DEFINE_FAKE_VOID_FUNC(Set_RA_SEC_Threshold);
   DEFINE_FAKE_VOID_FUNC(RA_Fault_Injection_Execute);
}
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Appl_BBE_Self_Test_Memory_Init, Mem_Pool_T *, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Fusa_BBE_Check_Execute);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Update_FUSA_BBE_Self_Test_Fault_Flag, uint32_t);

/* Angle finding */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Anglefinding_Memory_Init, Mem_Pool_T *, Mem_Pool_T *);
DEFINE_FAKE_VALUE_FUNC(AF_Retval_T, Appl_Angle_Finding_Process, AF_Appl_Input_T *, AF_Appl_Output_T *);

/* Radar capability */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Capability_Handler_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VOID_FUNC(rc_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* TOI / radar data quality */
DEFINE_FAKE_VOID_FUNC(TOI_Init);
DEFINE_FAKE_VOID_FUNC(TOI_Parameters_Init);
DEFINE_FAKE_VOID_FUNC(Determine_Data_Quality, TOI_Input_Params_T *, TOI_Output_Params_T *);
DEFINE_FAKE_VALUE_FUNC(TOI_Input_Params_T *, Get_TOI_Init_Parameters);
DEFINE_FAKE_VALUE_FUNC(TOI_Output_Params_T *, Get_TOI_Output_Parameters);
DEFINE_FAKE_VOID_FUNC(TOI_Radar_Status_Info_Init, TOI_Input_Params_T *);

/* Static alignment */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, SA_Alignment_Handler_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VOID_FUNC(static_align_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* Dynamic alignment */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Alignment_Handler_Memory_Init, Mem_Pool_T *);
DEFINE_FAKE_VOID_FUNC(dyn_align_wrapper, D2M_Msg_T *, M2D_Msg_T *, M2D_One_Time_Msg_T *);

/* Tracker wrapper */
DEFINE_FAKE_VALUE_FUNC(Memory_Pool_Return_T, Emb_Tracker_Mem_Init, Mem_Pool_T *, D2M_Msg_T *);
DEFINE_FAKE_VOID_FUNC(Init_Emb_Tracker, volatile M2D_One_Time_Msg_T *, M2D_Msg_T *);
DEFINE_FAKE_VOID_FUNC(Run_Emb_Tracker, D2M_Msg_T *, M2D_Msg_T *, volatile M2D_One_Time_Msg_T *);

/* BBE32 static register validation */
DEFINE_FAKE_VOID_FUNC(Bbe32_Static_Register_Safety_Check);

/* Profiling / timing helpers */
DEFINE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Time_Microsec, uint32_t);
DEFINE_FAKE_VOID_FUNC(Profiling_Helpers_Init, void *, bool);
DEFINE_FAKE_VOID_FUNC(Profiling_Helpers_Update, ProfilingStruct_t *);

/* Performance monitor */
DEFINE_FAKE_VOID_FUNC(Initialize_Perfmon_Info);
DEFINE_FAKE_VOID_FUNC(Update_IPC_Perfmon_Info, BBE_Cache_Info_T *, BBE_Cache_Info_T *);
/* Interference detection */
DEFINE_FAKE_VOID_FUNC(interference_detection_wrapper, M2D_Msg_T *, D2M_Msg_T *);
DEFINE_FAKE_VOID_FUNC(ID_Init_BB_Params, ID_INPUT_T *);
DEFINE_FAKE_VOID_FUNC(ID_Populate_Logging_Structure, ID_INPUT_T *);
DEFINE_FAKE_VOID_FUNC(ID_Clear_Logging_Data);
DEFINE_FAKE_VALUE_FUNC(ID_BB_Input_Params_T *, Get_ID_Init_Parameters);
DEFINE_FAKE_VALUE_FUNC(ID_MDF_BB_Internals_T *, Get_ID_BB_Internals);
DEFINE_FAKE_VOID_FUNC(ID_Init);
DEFINE_FAKE_VOID_FUNC(Interference_Detection);
/* Custom fake functions for interference detection */
static ID_BB_Input_Params_T g_id_bb_input_params_stub = {};
static ID_MDF_BB_Internals_T g_id_bb_internals_stub   = {};
ID_BB_Input_Params_T *Get_ID_Init_Parameters_custom(void)
{
   return &g_id_bb_input_params_stub;
}
ID_MDF_BB_Internals_T *Get_ID_BB_Internals_custom(void)
{
   return &g_id_bb_internals_stub;
}
