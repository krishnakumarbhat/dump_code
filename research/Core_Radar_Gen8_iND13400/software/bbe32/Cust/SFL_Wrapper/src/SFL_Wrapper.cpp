/**************************************************************************************************\
* File: SFL_Adapter.cpp
***************************************************************************************************
* Copyright 2026 Aptiv, Inc., All Rights Reserved.
* Aptiv Confidential
*-------------------------------------------------------------------------------------------------
* Created on: Feb 11, 2026
* Author: Hari Kailash M M (3dm38i)
*-------------------------------------------------------------------------------------------------
*
* Description:
* Embedded Adapter for SFL features for RNA SRR7p customer.
*
\**************************************************************************************************/

/**************************************************************************************************\
* Standard Header Includes
\**************************************************************************************************/
#include <string.h>

/**************************************************************************************************\
* Project Header Includes
\**************************************************************************************************/
#include "SFL_Wrapper.h"
#include "ipc_dsp.h"

#include "BSIS_Wrapper.h"
#include "MOIS_Wrapper.h"
#include "bsis_output_t.h"
#include "bsis_stream.h"
#include "mois_output_t.h"
#include "mois_stream.h"

/* headers from mode manager */
#include "SFL_Calibration.h"
#include "SFL_InputProcessing_iface.h"
#include "SFL_OutputProcessing_iface.h"

/* headers from toi */
#include "radar_data_quality.h"

/* headers from OLP */
#include "OLP_wrapper.h"

/* headers from FBK */
#include "fbk_core_calibration_t.h"
#include "fbk_iface.h"
#include "fbk_index_lookup.h"
#include "fbk_instance.h"
#include "fbk_macros.h"
#include "fbk_object_data_t.h"
#include "fbk_output.h"
#include "fbk_ref_point.h"
#include "fbk_vehicle_data_t.h"

/* headers from PA */
#include "pa_context.h"
#include "pa_obj_in.h"
#include "pa_shared_types.h"
#include "pa_vehicle_in.h"

/* headers from ML Library */
#include "ml_angle_range.h"
#include "ml_angle_t.h"
#include "ml_checked_rounding.h"
#include "ml_interval.h"
#include "ml_math.h"
#include "ml_math_infinity_silent.h"
#include "ml_trigonometry.h"
#include "ml_vector_2d.h"
#include "ml_vector_2d_angle.h"
#include "ml_vector_2d_t.h"

#if defined(SFL_OBJ_SIM_TEST)
   /* headers from sfl object simulation test */
   #include "SFL_Object_Simulator.h"
#endif

#if defined(SFL_UT)
   /* headers from sfl ut */
   #include "SFL_Adapter_Unit_Test.h"
#endif

/**************************************************************************************************\
* File scope Type Definitions
\**************************************************************************************************/

#ifndef DEG_TO_RAD
   #define DEG_TO_RAD (0.01745329252f)
#endif

/**************************************************************************************************\
* File scope variable Definitions
\**************************************************************************************************/
static uint32_t SFL_FF_50ms_Cntr = 0u;

static Fbk_Instance_T SFL_Fbk_Instance;
static Fbk_Output_T SFL_Fbk_Output;
static Pa_Context_T SFL_Pa_Context;

#if defined(SFL_ADAPTER_USED_MEM_POOL)
static Pa_Data_T *SFL_Pa_Data_GPtr = nullptr;
#else
static Pa_Data_T SFL_Pa_Data;
static Pa_Data_T *SFL_Pa_Data_GPtr = &SFL_Pa_Data;
#endif

/*Mode manager related variable definitions*/

/*Input Processing related*/
static VnetInSideFeatureMM_T VnetInSideFeatureMM;
static Calibrations_SFMM Calibrations_SFL_MM;
static SIM_SFMM_T SIM_SFMM;
static NVM_SFMM_T NVM_SFMM;
static VSE_SFMM_T VSE_SFMM;
static MM_SFLCore_T MM_SFLCore;
static MM_OutputProcessing_T MM_OutputProcessing;

/*Output related*/
static OutputProcessing_Out_T OutputProcessing_Out;
static SFLCORE_OP_T SFLCORE_OP;
static VnetInSideFeature_OP_T VnetInSideFeature_OP;
/**************************************************************************************************\
* Global extern Function Prototypes
\**************************************************************************************************/

/**************************************************************************************************\
* FBK Local Function Prototypes
\**************************************************************************************************/
static void SFL_ModeManager_Input_Main(VnetInSideFeatureMM_T *p_VnetInSideFeatureMM, Calibrations_SFMM *p_Calibrations_SFMM,
                                       SIM_SFMM_T *p_SIM_SFMM, const NVM_SFMM_T *p_NVM_SFMM, const VSE_SFMM_T *p_VSE_SFMM,
                                       MM_SFLCore_T *p_MM_SFLCore, MM_OutputProcessing_T *p_MM_OutputProcessing);

static void SFL_ModeManager_Output_Main(OutputProcessing_Out_T *p_OutputProcessing_Out, SFLCORE_OP_T *p_SFLCORE_OP,
                                        const VnetInSideFeature_OP_T *p_VnetInSideFeature_OP,
                                        const Calibrations_SFMM *p_Calibrations_SFMM,
                                        const MM_OutputProcessing_T *p_MM_OutputProcessing);

static void SFL_Reset_Cust_IPC(void);

static void SFL_Set_Cust_IPC(OutputProcessing_Out_T *p_OutputProcessing_Out);

static void SFL_Fbk_Init(Pa_Context_T *SFL_Pa_Context_Ptr, Fbk_Instance_T *SFL_Fbk_Instance_Ptr, Pa_Data_T *SFL_Pa_Data_Ptr);

static void SFL_Fbk_Run(Fbk_Instance_T *SFL_Fbk_Instance_Ptr, Fbk_Output_T *SFL_Fbk_Output_Ptr, Pa_Context_T *SFL_Pa_Context_Ptr);

static Pa_Veh_Prndl_State_T SFL_Map_Veh_Prndl_State(uint8_t in_prndl_state);

static void SFL_Fill_Vehicle_Data(Fbk_Vehicle_Data_T *SFL_Fbk_Vehicle_Data_Ptr);

static Pa_Obj_Status_T SFL_Map_Object_Status(Olp_Obj_Status_T olp_status);

static Pa_Obj_Curvi_Calc_Method_T SFL_Map_Curvi_Calc_Method(Olp_Obj_Curvi_Calc_Method_T olp_curvi_calc_method);

static Pa_Obj_Class_T SFL_Map_Object_Class(Olp_Obj_Class_T olp_obj_class);

static void SFL_Fill_Object_Data_List(Fbk_Object_Data_T *SFL_Fbk_Object_Data_Ptr, const Olp_Data_T *SFL_OLP_Obj_Ptr);

static void SFL_Fill_Object_Data(const Olp_InOut_Object_Data_T *olp_object, Fbk_Object_Data_T *sfl_object);

/**************************************************************************************************\
* Start of Global Scope Function Definitions
\**************************************************************************************************/

#if defined(SFL_ADAPTER_USED_MEM_POOL)
/*===========================================================================*\
 * Function: Feature_Handler_SFL_Adapter_Memory_Init
 *===========================================================================
 * Return Value:
 *  - boolean value indicating buffer allocation completed
 *
 * Parameters:
 *  - pointer to memory pool which can be used(Mem_Pool_T*)
 *
 * External References:
 *  - none
 *
 * Description:
 *    allocates the static variables to the memory pool buffer for feature function
 *
\*===========================================================================*/
bool Feature_Handler_SFL_Adapter_Memory_Init(Mem_Pool_T *mem_pool)
{
   bool mem_alloc_success = false;

   mem_alloc_success = mem_pool_alloc(mem_pool, sizeof(*SFL_Pa_Data_GPtr), (void **)&SFL_Pa_Data_GPtr);

   #if defined(SFL_CTA_FEATURE) || defined(SFL_CED_FEATURE)
   if (mem_alloc_success)
   {
      mem_alloc_success = mem_pool_alloc(mem_pool, sizeof(*SFL_Pt_Output_GPtr), (void **)&SFL_Pt_Output_GPtr);
   }
   #endif

   if (mem_alloc_success)
   {
      /* Reset mempool area pionted by feature function data pointers*/
      (void *)memset(SFL_Pa_Data_GPtr, 0, sizeof(*SFL_Pa_Data_GPtr));

   #if defined(SFL_CTA_FEATURE) || defined(SFL_CED_FEATURE)
      (void *)memset(SFL_Pt_Output_GPtr, 0, sizeof(*SFL_Pt_Output_GPtr));
   #endif
   }

   return mem_alloc_success;
}
#endif

/*================================================================================================
* Function: Feature_Function_Init()
*================================================================================================
* Parameters: void
*
* Return Value: void
*
* Description:
*   This function implements the initialization of Feature Functions.
*
================================================================================================*/
void Feature_Function_Init()
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();

   /*SFL Feature building kit init*/
   (void)SFL_Fbk_Init(&SFL_Pa_Context, &SFL_Fbk_Instance, SFL_Pa_Data_GPtr);

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      (void)SFL_Bsis_Init();
   }

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      (void)SFL_Mois_Init();
   }
}

/*================================================================================================
* Function: Feature_Function_Run_50ms()
*================================================================================================
* Parameters: void
*
* Return Value: void
*
* Description:
*   This function implements the periodic execution of Feature Functions.
*
================================================================================================*/
void Feature_Function_Run_50ms(void)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();

   /*SFL Feature building kit periodic execution*/
   (void)SFL_Fbk_Run(&SFL_Fbk_Instance, &SFL_Fbk_Output, &SFL_Pa_Context);

   (void)SFL_ModeManager_Input_Main(&VnetInSideFeatureMM, &Calibrations_SFL_MM, &SIM_SFMM, &NVM_SFMM, &VSE_SFMM, &MM_SFLCore,
                                    &MM_OutputProcessing);

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      (void)SFL_Bsis_Main(&SFL_Fbk_Output, &MM_SFLCore);
   }

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      (void)SFL_Mois_Main(&SFL_Fbk_Output, &MM_SFLCore);
   }

   (void)SFL_ModeManager_Output_Main(&OutputProcessing_Out, &SFLCORE_OP, &VnetInSideFeature_OP, &Calibrations_SFL_MM,
                                     &MM_OutputProcessing);

   SFL_Reset_Cust_IPC();

   SFL_Set_Cust_IPC(&OutputProcessing_Out);

   SFL_FF_50ms_Cntr++;
}
/**************************************************************************************************\
* End of Global Scope Function Definitions
\**************************************************************************************************/

/*Start of the mode manager main*/

SFL_Fail_Status_T Map_Fail_status(void)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();

   volatile Dynamic_Alignment_Data_T *m2d_dyn_align_data_master_sensor_ptr =
      &(Get_IPC_M2D_Buffer()->payload.alignment_Info.dynamic_alignment_data);

   volatile PS_Diagnostics_T *ps_diagnostics_partner_sensor_ptr =
      &(Get_IPC_M2D_Buffer()->payload.partners_data.partner_sensor_diag_data[0]);

   /*Blockage check for the feature suppress*/
   SFL_Fail_Status_T SFL_System_Fail_State = SFL_System_Fail_Not_Present;

   bool to_block_feature = SFL_System_Fail_Not_Present;

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      uint8_t operation_mode_partner_sensor = ps_diagnostics_partner_sensor_ptr->operation_mode + FBK_ONE_UINT;

      to_block_feature = ((m2d_dyn_align_data_master_sensor_ptr->operation_mode_status == SFL_Faulty_Sts) ||
                          (operation_mode_partner_sensor == SFL_Faulty_Sts));
   }
   else if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      to_block_feature = (m2d_dyn_align_data_master_sensor_ptr->operation_mode_status == SFL_Faulty_Sts);
   }
   else
   {
      // do nothing
   }

   if (to_block_feature)
   {
      SFL_System_Fail_State = SFL_System_Fail_Present;
   }

   return SFL_System_Fail_State;
}

SFL_Blind_Status_T Map_Blind_status(void)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();

   volatile Blockage_Output_Stream_T *d2m_blockage_data_master_sensor_ptr =
      &(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer()->payload.radar_capability_data.blockage);

   volatile PS_Blockage_Info_T *ps_blockage_info_partner_sensor_ptr =
      &(Get_IPC_M2D_Buffer()->payload.partners_data.partner_sensor_blockage_info[0]);

   /*Blockage check for the feature suppress*/
   SFL_Blind_Status_T SFL_System_Blind_State = SFL_System_Not_Blind;

   bool to_block_feature = SFL_System_Not_Blind;

   SFL_Blockage_Value_T Blockage_Value_master   = (SFL_Blockage_Value_T)(d2m_blockage_data_master_sensor_ptr->blockage.value);
   SFL_Blockage_Status_T Blockage_Status_master = (SFL_Blockage_Status_T)(d2m_blockage_data_master_sensor_ptr->blockage_status);

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      SFL_Blockage_Value_T Blockage_Value_partner = (SFL_Blockage_Value_T)(ps_blockage_info_partner_sensor_ptr->blockage_value);
      SFL_Blockage_Status_T Blockage_Status_partner =
         (SFL_Blockage_Status_T)(ps_blockage_info_partner_sensor_ptr->blockage_status);

      to_block_feature =
         ((Blockage_Status_master == SFL_BLOCKAGE_STATUS_FAULTY) || (Blockage_Status_master == SFL_BLOCKAGE_STATUS_INVALID) ||
          (Blockage_Status_partner == SFL_BLOCKAGE_STATUS_FAULTY) || (Blockage_Status_partner == SFL_BLOCKAGE_STATUS_INVALID) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_HIGHLY_BLOCKED) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_FULLY_BLOCKED) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_LIMITED_SIGHT) ||
          (Blockage_Value_partner == SFL_BLOCKAGE_VALUE_HIGHLY_BLOCKED) ||
          (Blockage_Value_partner == SFL_BLOCKAGE_VALUE_FULLY_BLOCKED) ||
          (Blockage_Value_partner == SFL_BLOCKAGE_VALUE_LIMITED_SIGHT));
   }
   else if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      to_block_feature =
         ((Blockage_Status_master == SFL_BLOCKAGE_STATUS_FAULTY) || (Blockage_Status_master == SFL_BLOCKAGE_STATUS_INVALID) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_HIGHLY_BLOCKED) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_FULLY_BLOCKED) ||
          (Blockage_Value_master == SFL_BLOCKAGE_VALUE_LIMITED_SIGHT));
   }
   else
   {
      // do nothing
   }

   if (to_block_feature)
   {
      SFL_System_Blind_State = SFL_System_Blind;
   }

   return SFL_System_Blind_State;
}

static void SFL_ModeManager_Input_Main(VnetInSideFeatureMM_T *p_VnetInSideFeatureMM, Calibrations_SFMM *p_Calibrations_SFMM,
                                       SIM_SFMM_T *p_SIM_SFMM, const NVM_SFMM_T *p_NVM_SFMM, const VSE_SFMM_T *p_VSE_SFMM,
                                       MM_SFLCore_T *p_MM_SFLCore, MM_OutputProcessing_T *p_MM_OutputProcessing)
{
   /*Need to map from IPC later*/
   volatile Veh_Raw_Misc_T *m2d_raw_misc_ptr        = &(Get_IPC_M2D_Buffer()->payload.veh_data.veh_raw_misc);
   volatile Feature_Input_T *m2d_feature_input_ptr  = &(Get_IPC_M2D_Buffer()->payload.feature_input);
   volatile Vehicle_Info_Stream_T *d2m_veh_info_ptr = &(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer()->payload.vehicle_info_stream);
   volatile HIL_Ipc_Info_T *m2d_hil_ipc_info_ptr    = &(Get_IPC_M2D_Buffer()->payload.hil_ipc_info);

   SFL_Fail_Status_T SFL_FailSts = Map_Fail_status();

   SFL_Blind_Status_T SFL_Blind_Sts = Map_Blind_status();

   p_VnetInSideFeatureMM->MOIS_OnOff_Setting =
      ((m2d_feature_input_ptr->mois_fn_enable_disable_sts == SFL_MOIS_enable) ? MOIS_OnOff_Settings_Enable_LED_Chime :
                                                                                MOIS_OnOff_Settings_Disabled);
   p_VnetInSideFeatureMM->BSIS_OnOff_Setting = BSIS_OnOff_Settings_Enable_LED_Chime;
   p_VnetInSideFeatureMM->Ego_Vehicle_Speed  = d2m_veh_info_ptr->vcs_speed;
   p_VnetInSideFeatureMM->GearBox_Pos        = (GearBox_Pos_T)m2d_raw_misc_ptr->gear_pos;
   p_VnetInSideFeatureMM->VEH_IgnitionSts =
      ((m2d_feature_input_ptr->ignition_sts == SFL_Ignition_On) ? VEH_IgnitionSts_Run : VEH_IgnitionSts_Initialization);

   p_SIM_SFMM->dtc_disable_bsis = (bool)SFL_FailSts;
   p_SIM_SFMM->dtc_disable_mois = (bool)SFL_FailSts;
   p_SIM_SFMM->dtc_limit_bsis   = (bool)SFL_Blind_Sts;
   p_SIM_SFMM->dtc_limit_mois   = (bool)SFL_Blind_Sts;

   /*In HIL mode the vehicle network and diagnostic inputs are not driven, which keeps the mode manager
     suppressed so BSIS_Alert/MOIS_Alert stay zero on CAN while the raw core alerts are still visible in
     the UDP streams. Force the mode manager enable conditions in HIL only.*/

   if (CODED_TRUE == m2d_hil_ipc_info_ptr->hil_mode_enabled)
   {
      p_VnetInSideFeatureMM->MOIS_OnOff_Setting = MOIS_OnOff_Settings_Enable_LED_Chime;
      p_VnetInSideFeatureMM->BSIS_OnOff_Setting = BSIS_OnOff_Settings_Enable_LED_Chime;
      p_VnetInSideFeatureMM->VEH_IgnitionSts    = VEH_IgnitionSts_Run;

      p_SIM_SFMM->dtc_disable_bsis = false;
      p_SIM_SFMM->dtc_disable_mois = false;
      p_SIM_SFMM->dtc_limit_bsis   = false;
      p_SIM_SFMM->dtc_limit_mois   = false;
   }

   /*SFL default calibration update*/
   (void)SFL_Cal_Update_Defaults(p_Calibrations_SFMM);
   p_Calibrations_SFMM->k_bsis_host_speed_max           = 8.33f;  // as per polarion req
   p_Calibrations_SFMM->k_mois_active_ego_speed_max     = 2.78f;  // as per polarion req
   p_Calibrations_SFMM->k_mois_active_ego_speed_max_hys = 0.278f; // as per polarion req

   /*State machine input processing for the features*/
   SFL_Input_Processing_Step(p_VnetInSideFeatureMM, p_Calibrations_SFMM, p_SIM_SFMM, p_NVM_SFMM, p_VSE_SFMM, p_MM_SFLCore,
                             p_MM_OutputProcessing);
}

static void SFL_ModeManager_Output_Main(OutputProcessing_Out_T *p_OutputProcessing_Out, SFLCORE_OP_T *p_SFLCORE_OP,
                                        const VnetInSideFeature_OP_T *p_VnetInSideFeature_OP,
                                        const Calibrations_SFMM *p_Calibrations_SFMM,
                                        const MM_OutputProcessing_T *p_MM_OutputProcessing)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      Bsis_Output_T *p_BSIS_output     = SFL_Bsis_Output_Ptr();
      p_SFLCORE_OP->BSIS_Warning_Left  = (Bsis_Alert_Level_T)p_BSIS_output->bsis_alert_left;
      p_SFLCORE_OP->BSIS_Warning_Right = (Bsis_Alert_Level_T)p_BSIS_output->bsis_alert_right;
   }

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      Mois_Output_T *p_MOIS_output = SFL_Mois_Output_Ptr();
      p_SFLCORE_OP->mois_alert     = (Mois_Alert_Level_T)p_MOIS_output->mois_alert_level;
   }

   SFL_Output_Processing_Step(p_OutputProcessing_Out, p_SFLCORE_OP, p_VnetInSideFeature_OP, p_Calibrations_SFMM,
                              p_MM_OutputProcessing);
}

/*IPC output handling*/

static void SFL_Reset_Cust_IPC(void)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();
   D2M_Msg_T *p_ipc_d2m_msg                        = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      Bsis_Stream_T *ipc_bsis_cust_stream_p            = &(p_ipc_d2m_msg->payload.Bsis_IPC_Output);
      Bsis_Instance_Stream_T *ipc_bsis_cust_instance_p = &(p_ipc_d2m_msg->payload.Bsis_IPC_Output.bsis_instance);

      if (nullptr != ipc_bsis_cust_stream_p && nullptr != ipc_bsis_cust_instance_p)
      {
         ipc_bsis_cust_stream_p->stream_hdr.size       = FBK_ZERO_UINT;
         ipc_bsis_cust_stream_p->stream_hdr.scan_index = FBK_ZERO_UINT;

         SFL_Bsis_Reset_Cust_IPC(ipc_bsis_cust_stream_p, ipc_bsis_cust_instance_p);
      }
   }

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      Mois_Stream_T *ipc_mois_cust_stream_p            = &(p_ipc_d2m_msg->payload.Mois_IPC_Output);
      Mois_Instance_Stream_T *ipc_mois_cust_instance_p = &(p_ipc_d2m_msg->payload.Mois_IPC_Output.mois_instance);

      if (nullptr != ipc_mois_cust_stream_p && nullptr != ipc_mois_cust_instance_p)
      {
         ipc_mois_cust_stream_p->stream_hdr.size       = FBK_ZERO_UINT;
         ipc_mois_cust_stream_p->stream_hdr.scan_index = FBK_ZERO_UINT;

         SFL_Mois_Reset_Cust_IPC(ipc_mois_cust_stream_p, ipc_mois_cust_instance_p);
      }
   }
}

static void SFL_Set_Cust_IPC(OutputProcessing_Out_T *p_OutputProcessing_Out)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();
   D2M_Msg_T *p_ipc_d2m_msg                        = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_REAR_LEFT)
   {
      Bsis_Stream_T *ipc_bsis_cust_stream_p            = &(p_ipc_d2m_msg->payload.Bsis_IPC_Output);
      Bsis_Instance_Stream_T *ipc_bsis_cust_instance_p = &(p_ipc_d2m_msg->payload.Bsis_IPC_Output.bsis_instance);

      if (nullptr != ipc_bsis_cust_stream_p && nullptr != ipc_bsis_cust_instance_p)
      {
         ipc_bsis_cust_stream_p->stream_hdr.size       = sizeof(Bsis_Stream_T);
         ipc_bsis_cust_stream_p->stream_hdr.scan_index = p_ipc_d2m_msg->payload.det_data.det_list_property.scanindex;

         /*Mode Manager Ouput of the feature*/
         ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Alert     = (uint8_t)p_OutputProcessing_Out->BSIS_Warning_Left;
         ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Systemsts = (uint8_t)p_OutputProcessing_Out->BSIS_Systemsts;
         ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_OnOff_Setting_FBK =
            (uint8_t)p_OutputProcessing_Out->BSIS_OnOff_Setting_Fbk;
         ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_FailSts = (uint8_t)p_OutputProcessing_Out->BSIS_FailSts;
         ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Blind   = (uint8_t)p_OutputProcessing_Out->BSIS_Blind;

         SFL_Bsis_Set_Cust_IPC(ipc_bsis_cust_stream_p, ipc_bsis_cust_instance_p);
      }
   }

   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_CENTER)
   {
      Mois_Stream_T *ipc_mois_cust_stream_p            = &(p_ipc_d2m_msg->payload.Mois_IPC_Output);
      Mois_Instance_Stream_T *ipc_mois_cust_instance_p = &(p_ipc_d2m_msg->payload.Mois_IPC_Output.mois_instance);

      if (nullptr != ipc_mois_cust_stream_p && nullptr != ipc_mois_cust_instance_p)
      {
         ipc_mois_cust_stream_p->stream_hdr.size       = sizeof(Mois_Stream_T);
         ipc_mois_cust_stream_p->stream_hdr.scan_index = p_ipc_d2m_msg->payload.det_data.det_list_property.scanindex;

         /*Mode Manager Ouput of the feature*/
         ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Alert     = (uint8_t)p_OutputProcessing_Out->MOIS_Alert;
         ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Systemsts = (uint8_t)p_OutputProcessing_Out->MOIS_Systemsts;
         ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_OnOff_Setting_FBK =
            (uint8_t)p_OutputProcessing_Out->MOIS_OnOff_Setting_Fbk;
         ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_FailSts = (uint8_t)p_OutputProcessing_Out->MOIS_FailSts;
         ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Blind   = (uint8_t)p_OutputProcessing_Out->MOIS_Blind;

         SFL_Mois_Set_Cust_IPC(ipc_mois_cust_stream_p, ipc_mois_cust_instance_p);
      }
   }
}

/*Start of FBK related function definitions*/

/*================================================================================================*\
* Function: SFL_Fbk_Init()
*================================================================================================
* Parameters: Pa_Context_T*, Fbk_Instance_T*, Pa_Data_T*
*
* Return Value: void
*
* Description: This function implements the initialization of FBK Feature.
*
\*================================================================================================*/
static void SFL_Fbk_Init(Pa_Context_T *SFL_Pa_Context_Ptr, Fbk_Instance_T *SFL_Fbk_Instance_Ptr, Pa_Data_T *SFL_Pa_Data_Ptr)
{
   if ((nullptr != SFL_Pa_Context_Ptr) && (nullptr != SFL_Fbk_Instance_Ptr))
   {
      (void)Fbk_Init_Platform(SFL_Fbk_Instance_Ptr, SFL_Pa_Data_Ptr);

      SFL_Pa_Context_Ptr->p_data = SFL_Fbk_Instance_Ptr->p_pa_data;
   }
}

/*================================================================================================*\
* Function: SFL_Fbk_Run()
*================================================================================================
* Parameters: Fbk_Instance_T*, Fbk_Output_T*, Pa_Context_T*
*
* Return Value: void
*
* Description: This function implements the periodic execution of FBK Feature.
*
\*================================================================================================*/
static void SFL_Fbk_Run(Fbk_Instance_T *SFL_Fbk_Instance_Ptr, Fbk_Output_T *SFL_Fbk_Output_Ptr, Pa_Context_T *SFL_Pa_Context_Ptr)
{
   Olp_Data_T *SFL_OLP_Obj_Ptr = Get_Olp_Objects_Data();

#if defined(SFL_OBJ_SIM_TEST)
   (void)SFL_Object_Data_Simulator(SFL_OLP_Obj_Ptr);
#endif

   if ((nullptr != SFL_OLP_Obj_Ptr) && (nullptr != SFL_Fbk_Instance_Ptr) && (nullptr != SFL_Fbk_Output_Ptr) &&
       (nullptr != SFL_Pa_Context_Ptr))
   {
      SFL_Pa_Context_Ptr->p_data->time_diff_to_last_cycle = SFL_EXECUTION_TIME;

      /*Populate vehicle and object data to SFL*/
      (void)SFL_Fill_Vehicle_Data(&SFL_Pa_Context_Ptr->p_data->vehicle_data);
      (void)SFL_Fill_Object_Data_List(&SFL_Pa_Context_Ptr->p_data->object_data[0], SFL_OLP_Obj_Ptr);

      (void)Fbk_Run_Platform(SFL_Fbk_Instance_Ptr, SFL_Fbk_Output_Ptr, SFL_Pa_Context_Ptr);
   }
}

/*================================================================================================*\
* Function: SFL_Map_Veh_Prndl_State()
*================================================================================================
* Parameters: uint8_t
*
* Return Value: Pa_Veh_Prndl_State_T
*
* Description: In this function PRNDL status from VSE is mapped to SFL.
*
\*================================================================================================*/
static Pa_Veh_Prndl_State_T SFL_Map_Veh_Prndl_State(uint8_t in_prndl_state)
{
   Pa_Veh_Prndl_State_T pa_veh_prndl_state;

   switch (in_prndl_state)
   {
      case PA_VEH_PRNDL_STATE_PARK:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_PARK;
         break;
      case PA_VEH_PRNDL_STATE_REVERSE:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_REVERSE;
         break;
      case PA_VEH_PRNDL_STATE_NEUTRAL:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_NEUTRAL;
         break;
      case PA_VEH_PRNDL_STATE_DRIVE:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_DRIVE;
         break;
      case PA_VEH_PRNDL_STATE_LOW:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_LOW;
         break;
      default:
         pa_veh_prndl_state = PA_VEH_PRNDL_STATE_PARK;
         break;
   }
   return pa_veh_prndl_state;
}

/*================================================================================================*\
* Function: SFL_Fill_Vehicle_Data()
*================================================================================================
* Parameters: Fbk_Vehicle_Data_T*
*
* Return Value: void
*
* Description: In this function vehicle data is populated to SFL.
*
\*================================================================================================*/
static void SFL_Fill_Vehicle_Data(Fbk_Vehicle_Data_T *SFL_Fbk_Vehicle_Data_Ptr)
{
   D2M_Msg_T *p_ipc_d2m                            = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();
   volatile Vse_Output_T *m2d_vse_output_ptr       = &(Get_IPC_M2D_Buffer()->payload.veh_data.vse_output);
   volatile Veh_Raw_Misc_T *m2d_raw_misc_ptr       = &(Get_IPC_M2D_Buffer()->payload.veh_data.veh_raw_misc);
   if ((nullptr != p_ipc_d2m) && (nullptr != p_ipc_m2d_one_time) && (nullptr != m2d_vse_output_ptr) &&
       (nullptr != m2d_raw_misc_ptr))
   {
#if defined(SFL_OBJ_SIM_TEST)
      m2d_vse_output_ptr = (Vse_Output_T *)Get_Obj_Sim_Veh_Info_ptr();
#endif

      SFL_Fbk_Vehicle_Data_Ptr->host_length = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_length;
      SFL_Fbk_Vehicle_Data_Ptr->host_width  = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_width;
      SFL_Fbk_Vehicle_Data_Ptr->rear_axle_position =
         -FBK_ONE_F * p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
      SFL_Fbk_Vehicle_Data_Ptr->wheelbase = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_wheelbase;

      SFL_Fbk_Vehicle_Data_Ptr->host_speed = p_ipc_d2m->payload.vehicle_info_stream.vcs_speed;
      SFL_Fbk_Vehicle_Data_Ptr->yawrate    = p_ipc_d2m->payload.vehicle_info_stream.filtered_yaw_rate_rad;
      SFL_Fbk_Vehicle_Data_Ptr->long_vel   = p_ipc_d2m->payload.vehicle_info_stream.vcs_speed;
      SFL_Fbk_Vehicle_Data_Ptr->long_acc   = p_ipc_d2m->payload.vehicle_info_stream.vcs_long_acceleration;
      SFL_Fbk_Vehicle_Data_Ptr->lat_acc    = p_ipc_d2m->payload.vehicle_info_stream.vcs_lat_acceleration;
      SFL_Fbk_Vehicle_Data_Ptr->curvature  = p_ipc_d2m->payload.vehicle_info_stream.curvature_rear;

      SFL_Fbk_Vehicle_Data_Ptr->steering_angle = (m2d_vse_output_ptr->comp_steering_angle_deg * DEG_TO_RAD);
      SFL_Fbk_Vehicle_Data_Ptr->prndl          = SFL_Map_Veh_Prndl_State(m2d_raw_misc_ptr->gear_pos);
      SFL_Fbk_Vehicle_Data_Ptr->f_reverse = (PA_VEH_PRNDL_STATE_REVERSE == SFL_Fbk_Vehicle_Data_Ptr->prndl) ? FBK_TRUE : FBK_FALSE;
      SFL_Fbk_Vehicle_Data_Ptr->lane_width         = 0.0f;
      SFL_Fbk_Vehicle_Data_Ptr->lane_center_offset = 0.0f;
      SFL_Fbk_Vehicle_Data_Ptr->turn_signal        = m2d_raw_misc_ptr->turn_signal;
   }
}

/*================================================================================================*\
* Function: SFL_Map_Vector_2d()
*================================================================================================
* Parameters: const Olp_Vector_2d_T
*
* Return Value: Vector_2d_T
*
* Description: This functin maps one 2d vector to another
*
\*================================================================================================*/
static inline Vector_2d_T SFL_Map_Vector_2d(const Olp_Vector_2d_T olp_vector)
{
   Vector_2d_T result = {olp_vector.x, olp_vector.y};
   return result;
}

/*================================================================================================*\
* Function: SFL_Map_Object_Status()
*================================================================================================
* Parameters: Olp_Obj_Status_T
*
* Return Value: Pa_Obj_Status_T
*
* Description: This functin converts object status from olp to sfl
*
\*================================================================================================*/
static Pa_Obj_Status_T SFL_Map_Object_Status(Olp_Obj_Status_T olp_status)
{
   Pa_Obj_Status_T pa_status;

   switch (olp_status)
   {
      case OLP_OBJ_STATUS_INVALID:
         pa_status = PA_OBJ_STATUS_INVALID;
         break;
      case OLP_OBJ_STATUS_NEW:
         pa_status = PA_OBJ_STATUS_NEW;
         break;
      case OLP_OBJ_STATUS_MATURE:
         pa_status = PA_OBJ_STATUS_MATURE;
         break;
      case OLP_OBJ_STATUS_COASTED:
         pa_status = PA_OBJ_STATUS_COASTED;
         break;
      case OLP_OBJ_STATUS_COASTED_IMPLAUSIBLE:
         pa_status = PA_OBJ_STATUS_COASTED_IMPLAUSIBLE;
         break;
      default:
         pa_status = PA_OBJ_STATUS_INVALID;
         break;
   }
   return pa_status;
}

/*================================================================================================*\
* Function: SFL_Map_Curvi_Calc_Method()
*================================================================================================
* Parameters: Olp_Obj_Curvi_Calc_Method_T
*
* Return Value: Pa_Obj_Curvi_Calc_Method_T
*
* Description: This functin converts object curvi calculation method from olp to sfl
*
\*================================================================================================*/
static Pa_Obj_Curvi_Calc_Method_T SFL_Map_Curvi_Calc_Method(Olp_Obj_Curvi_Calc_Method_T olp_curvi_calc_method)
{
   Pa_Obj_Curvi_Calc_Method_T pa_curvi_calc_method;

   switch (olp_curvi_calc_method)
   {
      case OLP_OBJ_CURVI_COORDINATES_UNKNOWN:
         pa_curvi_calc_method = PA_OBJ_CURVI_COORDINATES_UNKNOWN;
         break;
      case OLP_OBJ_CURVI_COORDINATES_BASED_ON_VCS:
         pa_curvi_calc_method = PA_OBJ_CURVI_COORDINATES_BASED_ON_VCS;
         break;
      case OLP_OBJ_CURVI_COORDINATES_SNAIL_TRAIL:
         pa_curvi_calc_method = PA_OBJ_CURVI_COORDINATES_SNAIL_TRAIL;
         break;
      case OLP_OBJ_CURVI_COORDINATES_DISTANCE_BASED_CURVATURE:
         pa_curvi_calc_method = PA_OBJ_CURVI_COORDINATES_DISTANCE_BASED_CURVATURE;
         break;
      default:
         pa_curvi_calc_method = PA_OBJ_CURVI_COORDINATES_UNKNOWN;
         break;
   }
   return pa_curvi_calc_method;
}

/*================================================================================================*\
* Function: SFL_Map_Object_Class()
*================================================================================================
* Parameters: Olp_Obj_Class_T
*
* Return Value: Pa_Obj_Class_T
*
* Description: This functin converts object class from olp to sfl
*
\*================================================================================================*/
static Pa_Obj_Class_T SFL_Map_Object_Class(Olp_Obj_Class_T olp_obj_class)
{
   Pa_Obj_Class_T pa_obj_class;

   switch (olp_obj_class)
   {
      case OLP_OBJ_CLASS_UNKNOWN:
         pa_obj_class = PA_OBJ_CLASS_UNKNOWN;
         break;
      case OLP_OBJ_CLASS_PEDESTRIAN:
         pa_obj_class = PA_OBJ_CLASS_PEDESTRIAN;
         break;
      case OLP_OBJ_CLASS_2WHEEL:
         pa_obj_class = PA_OBJ_CLASS_2WHEEL;
         break;
      case OLP_OBJ_CLASS_CAR:
         pa_obj_class = PA_OBJ_CLASS_CAR;
         break;
      case OLP_OBJ_CLASS_TRUCK:
         pa_obj_class = PA_OBJ_CLASS_TRUCK;
         break;
      default:
         pa_obj_class = PA_OBJ_CLASS_UNKNOWN;
         break;
   }
   return pa_obj_class;
}

/*================================================================================================*\
* Function: SFL_Fill_Object_Data()
*================================================================================================
* Parameters: const Olp_InOut_Object_Data_T*, Fbk_Object_Data_T*
*
* Return Value: void
*
* Description: This functin fills object from olp to SFL Fbk
*
\*================================================================================================*/
static void SFL_Fill_Object_Data(const Olp_InOut_Object_Data_T *olp_object, Fbk_Object_Data_T *sfl_object)
{
   if ((nullptr != olp_object) && (nullptr != sfl_object))
   {
      sfl_object->id                    = olp_object->id;
      sfl_object->unique_id             = olp_object->unique_id;
      sfl_object->index                 = olp_object->index;
      sfl_object->status                = SFL_Map_Object_Status(olp_object->status);
      sfl_object->age                   = olp_object->age;
      sfl_object->stage_age             = olp_object->stage_age;
      sfl_object->fbk_stage_age         = olp_object->stage_age;
      sfl_object->existence_probability = olp_object->existence_probability;
      sfl_object->speed                 = olp_object->speed;

      sfl_object->vcs_pos     = SFL_Map_Vector_2d(olp_object->vcs_pos);
      sfl_object->vcs_vel     = SFL_Map_Vector_2d(olp_object->vcs_vel);
      sfl_object->vcs_vel_rel = SFL_Map_Vector_2d(olp_object->vcs_vel_rel);
      sfl_object->vcs_accel   = SFL_Map_Vector_2d(olp_object->vcs_accel);

      sfl_object->vcs_heading  = olp_object->vcs_heading;
      sfl_object->heading_rate = olp_object->heading_rate;

      sfl_object->length = olp_object->length;
      sfl_object->width  = olp_object->width;

      sfl_object->curvature = olp_object->curvature;

      sfl_object->obj_class             = SFL_Map_Object_Class(olp_object->obj_class);
      sfl_object->class_prob_pedestrian = olp_object->class_prob_pedestrian;
      sfl_object->class_prob_2wheel     = olp_object->class_prob_2wheel;
      sfl_object->class_prob_car        = olp_object->class_prob_car;
      sfl_object->class_prob_truck      = olp_object->class_prob_truck;

      sfl_object->curvi_coordinates_calc_method = SFL_Map_Curvi_Calc_Method(olp_object->curvi_coordinates_calc_method);
      sfl_object->curvi_pos                     = SFL_Map_Vector_2d(olp_object->curvi_pos);
      sfl_object->curvi_vel                     = SFL_Map_Vector_2d(olp_object->curvi_vel);
      sfl_object->curvi_vel_rel                 = SFL_Map_Vector_2d(olp_object->curvi_vel_rel);
      sfl_object->curvi_heading                 = olp_object->curvi_heading;

      sfl_object->f_moving             = olp_object->f_moving;
      sfl_object->f_moveable           = olp_object->f_moveable;
      sfl_object->f_stationary_clutter = olp_object->f_stationary_clutter;

      sfl_object->f_is_fl_origin_sensor = olp_object->f_is_fl_origin_sensor;
      sfl_object->f_is_fr_origin_sensor = olp_object->f_is_fr_origin_sensor;
      sfl_object->f_is_rl_origin_sensor = olp_object->f_is_rl_origin_sensor;
      sfl_object->f_is_rr_origin_sensor = olp_object->f_is_rr_origin_sensor;

      sfl_object->f_is_in_fl_sensor_fov = olp_object->f_is_in_fl_sensor_fov;
      sfl_object->f_is_in_fr_sensor_fov = olp_object->f_is_in_fr_sensor_fov;
      sfl_object->f_is_in_rl_sensor_fov = olp_object->f_is_in_rl_sensor_fov;
      sfl_object->f_is_in_rr_sensor_fov = olp_object->f_is_in_rr_sensor_fov;
   }
}

/*================================================================================================*\
* Function: SFL_Fill_Object_Data_List()
*================================================================================================
* Parameters: Fbk_Object_Data_T*, const Olp_Data_T*
*
* Return Value: void
*
* Description: This functin fills object from olp to SFL Fbk
*
\*================================================================================================*/
static void SFL_Fill_Object_Data_List(Fbk_Object_Data_T *SFL_Fbk_Object_Data_Ptr, const Olp_Data_T *SFL_OLP_Obj_Ptr)
{
   uint8_t obj_indx = 0u;

   if (SFL_OLP_Obj_Ptr->no_of_valid_objects <= PA_OBJ_NUMBER_OF_OBJECTS)
   {
      for (obj_indx = 0u; obj_indx < SFL_OLP_Obj_Ptr->no_of_valid_objects; obj_indx++)
      {
         SFL_Fill_Object_Data(&(SFL_OLP_Obj_Ptr->olp_inout_obj_data[obj_indx]), &(SFL_Fbk_Object_Data_Ptr[obj_indx]));
      }
      for (obj_indx = SFL_OLP_Obj_Ptr->no_of_valid_objects; obj_indx < PA_OBJ_NUMBER_OF_OBJECTS; obj_indx++)
      {
         memset(&(SFL_Fbk_Object_Data_Ptr[obj_indx]), 0, sizeof(Fbk_Object_Data_T));
      }
   }
}

/*End of FBK related function definitions*/
/*================================================================================================*\
* Revision History
*================================================================================================
*    Date          By                     Description
* MM/DD/YYYY  Name/Initials            JIRA AAA-#### Explanation of changes
* ----------  -------------            ----------------------------------------------------------
* 11/02/2026  Hari Kailash M M
\*================================================================================================*/
