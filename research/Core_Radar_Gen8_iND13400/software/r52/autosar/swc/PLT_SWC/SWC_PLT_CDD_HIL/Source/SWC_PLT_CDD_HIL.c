/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_CDD_HIL.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_HIL
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_HIL>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SWC_PLT_CDD_HIL.h"
#include "Os_Lcfg.h"
#include "Rte_SWC_PLT_CDD_HIL.h"
#include "SWC_PLT_CDD_Logging.h"
#include "hil_communication_handler.h"
#include "hil_interface.h"
#include "hil_types.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "sensor_position.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_HIL_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SH_COMP_FLT_EPSILON (0.00001F)

/*Local variables*/
static bool Periodic_Injection_Call = true;
/* Test-injectable override: allows unit tests to exercise both branches of
 * RE_HIL_Periodic_Handler. Defaults to CODED_TRUE, preserving runtime
 * behaviour. Will be removed once Rte_Read_Rp_Hil_Activation is connected. */
volatile uint8_t Test_HIL_MPU_Status_Override = CODED_TRUE;

/*Local Function prototypes*/
void HIL_Periodic_Handler(void);
static bool Compare_Float_Values(float32_t var1, float32_t var2);
static uint8_t Update_Mounting_Position_From_Status_Log(void);
#if (STD_ON == ENABLE_SIT_TEST_STUBS)
volatile uint8 XCP_Hil_Activation = 0;
#endif
#define SWC_PLT_CDD_HIL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_HIL_Periodic_Handler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by ExternalTriggerOccurredEvent of PortPrototype <Rp_HIL_Periodic_Handler>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_HIL_Periodic_Handler_doc
 *********************************************************************************************************************/
#define SWC_PLT_CDD_HIL_START_SEC_CODE
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_HIL_CODE) RE_HIL_Periodic_Handler(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_HIL_Periodic_Handler
    *********************************************************************************************************************/

   if (CODED_TRUE == (uint8_t)Get_MPU_Status_For_HIL_Trigger())
   {
      HIL_Periodic_Handler();
   }
   else
   {
      Periodic_Injection_Call = false;
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}
/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_HIL_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Hil_Activation_De_Hil_Activation(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_HIL_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_HIL_CODE) RE_PLT_HIL_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_HIL_Init
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_HIL_STOP_SEC_CODE
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
 *. Name: Update_Mounting_Position_From_Status_Log
 *.
 *.
 *. Parameters: None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint8_t Update_Mounting_Position_From_Status_Log(void)
{
   Status_Stream_T *stream_ptr              = Get_Status_Stream_Ptr();
   M2D_Msg_T *ipc_m2d_ptr                   = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   M2D_One_Time_Msg_T *ipc_one_time_msg_ptr = (M2D_One_Time_Msg_T *)Get_IPC_M2D_Onetime_Msg_Buffer();
   bool smc_update_found                    = false;
   uint8_t ret_val                          = CODED_FALSE;

   /* IF there is any change in mounting position then only update this.*/
   if ((HIL_EXECUTE_INJECTION_DATA == ipc_m2d_ptr->payload.hil_ipc_info.hil_src_radar_mounting_data) &&
       (NULL != ipc_one_time_msg_ptr))
   {
      smc_update_found =
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw,
                               stream_ptr->sensor_mount_ornt_yaw)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch,
                               stream_ptr->sensor_mount_ornt_pitch)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll,
                               stream_ptr->sensor_mount_ornt_roll)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x,
                               stream_ptr->sensor_mount_pos_x)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y,
                               stream_ptr->sensor_mount_pos_y)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z,
                               stream_ptr->sensor_mount_pos_z)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height,
                               stream_ptr->sensor_height)) ||
         (Compare_Float_Values(ipc_one_time_msg_ptr->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle,
                               stream_ptr->sensor_long_offset));

      if (smc_update_found)
      {
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw =
            stream_ptr->sensor_mount_ornt_yaw;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch =
            stream_ptr->sensor_mount_ornt_pitch;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll =
            stream_ptr->sensor_mount_ornt_roll;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x =
            stream_ptr->sensor_mount_pos_x;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y =
            stream_ptr->sensor_mount_pos_y;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z =
            stream_ptr->sensor_mount_pos_z;
         ipc_one_time_msg_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height = stream_ptr->sensor_height;
         ipc_one_time_msg_ptr->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle = stream_ptr->sensor_long_offset;

         ret_val = CODED_TRUE;
      }
   }

   return ret_val;
}

/******************************************************************************
 *. Name: Compare_Float_Values
 *.
 *.
 *. Parameters: float32_t var1, float32_t var2, float32_t epsilon
 *. Return Value: bool
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/

static bool Compare_Float_Values(float32_t var1, float32_t var2)
{
   bool ret_val = false;
   ret_val      = (fabsf(var1 - var2) > SH_COMP_FLT_EPSILON); /*if variables not matching means return true*/
   return ret_val;
}

/******************************************************************************
 *. Name: HIL_Periodic_Handler
 *.
 *. Description:
 *.    Periodic HIL (Hardware-In-the-Loop) handler executed once per radar frame
 *.    cycle. This function is the central coordinator for injecting HIL test data
 *.    into the R52 → BBE32 IPC pipeline and for keeping the HIL input interface
 *.    consistent with the current frame's processing state.
 *.
 *.    Execution context:
 *.      - Called from RE_HIL_Periodic_Handler (AUTOSAR Runnable) which itself is
 *.        triggered by Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger()
 *.        issued by dsp_setup.c at the DSP_SP_POST_PROCESSING_COMPLETE interrupt.
 *.      - Only invoked when the MPU protection for the HIL memory region has been
 *.        disabled (Get_MPU_Status_For_HIL_Trigger() == CODED_TRUE), ensuring that
 *.        the HIL tool has safe write access before data is consumed.
 *.
 *.    Operations performed (in order):
 *.      1. Update_HIL_Input_Interface()
 *.            - Selects the correct D2M IPC ping/pong buffer based on
 *.              Get_DSP_Write_IPC_Index() so R52 reads the buffer that BBE32
 *.              just finished writing.
 *.            - Populates the HIL_Input_T structure fields (hil_ipc_index,
 *.              current_hil_injected_scan_index, stream memory map pointers,
 *.              etc.) that the HIL PC tool reads to understand the current
 *.              frame's state.
 *.            - Writes hil_scanindex and hil_mode_enabled flags from the
 *.              HIL_Output_T structure into the M2D IPC buffer so BBE32
 *.              receives the HIL injection command for the next frame.
 *.
 *.      2. Update_Mounting_Position_From_Status_Log()  [conditional]
 *.            - Executed when HIL mode is active AND the STATUS stream is
 *.              enabled (hil_enabled_streams[STATUS] == CODED_TRUE).
 *.            - Copies the radar sensor mounting location from the Status
 *.              stream into the M2D IPC buffer (hil_request_reinit_module flag) so that
 *.              BBE32 can reinitialise the SMC calibration if the mounting
 *.              position has changed during HIL playback.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
#pragma clang optimize off
void HIL_Periodic_Handler(void)
{
   /*HIL related logic will be added here in future.*/
   HIL_Output_T *hil_output_data_ptr = Get_HIL_Output_Data_Ptr();
   M2D_Msg_T *ipc_m2d_ptr            = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();

   /* HIL_Periodic_Handler must call once the MPU disabled through the XCP command*/
   /* HIL Team to add logic inside this function */
   Update_HIL_Input_Interface();

   if ((CODED_TRUE == hil_output_data_ptr->hil_enabled_streams[STATUS]) && (CODED_TRUE == hil_output_data_ptr->hil_mode_enabled))
   {
      /* Flag sets CODED_TRUE when SMC changed, which triggers tracker reinit on BBE32 via Tracker_Handler */
      ipc_m2d_ptr->payload.hil_ipc_info.hil_request_reinit_module = Update_Mounting_Position_From_Status_Log();
   }

   /* Every Radar cycle once this function have to be called*/
   HIL_Injection_Request();
}
#pragma clang optimize on

/*****************************************************************************
 *. Name: Get_MPU_Status_For_HIL_Trigger
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_MPU_Status_For_HIL_Trigger(void)
{
   uint8_t mpu_status = Test_HIL_MPU_Status_Override; /* Defaults to CODED_TRUE. Will be replaced with Rte_Read_Rp_Hil_Activation
                                                         once F150 RTE is connected */
   uint8_t *req_to_stop_cdc_tx = (uint8_t *)Get_Req_En_Dis_CDC_Stream();

   /*Rte_Read_Rp_Hil_Activation_De_Hil_Activation(&mpu_status);*/ /* Temporarily made true. Will be rverted back once F150 RTE is
                                                                     connected*/
   *req_to_stop_cdc_tx = mpu_status;

   return mpu_status;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
