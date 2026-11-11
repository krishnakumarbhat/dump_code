/**
 * @file dsp_setup.c
 *
 * API definition for signal processing application
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * API definition for signal processing application
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <math.h>
#include <string.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#if defined(FEATURE_ENABLE)
   #include "Fault_Lib_Plt.h"
#endif
#include "Rte_SWC_PLT_CDD_Radar_Control.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "afbb_cfg.h" // for AF_FASCIA_COMPENSATION_ENABLE
#include "chandra_sfrs_base.h"
#include "crc_calc.h"
#include "crg_sfrs.h"
#include "dsp_setup.h"
#include "dsp_sfrs.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "platformtime.h"
#include "radar_ctl.h"
#include "radar_data.h"
#include "radar_sw_config.h"
#include "reuse.h"
#include "smc_cal.h"
#include "timers_sfrs.h"
#include "usc_cal.h"

#include "dd_mmic.h"
#include "mmic_interface.h"
#include "program_flow_monitor.h"
#include "sh_comm.h"
#include "vid_stream.h"
#include "vse_stream.h"

#include "emb_tracker_project_parameters.h"

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "master_it_macros_test.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
/* IPC timeout is measured by reading a millisecond timer using an integer. Need to adjust the timeout
   value to allow for up to an additional ms of timeout, since the millisecond precision is not aligned to microseconds. */
#define IPC_MESSAGE_TIMEOUT_IN_MS ((IPC_MESSAGE_TIMEOUT_IN_US + 1000U) / 1000U)
#define FRAME_TIME_BUFFER_DEPTH   (2U)
#define RAD_TO_DEG_F32            (57.2957795F)

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/** The 'section' attribute are for placing the buffers part of APP_SRAM_DSP sections
 * The 'aligned' attribute are for making the address 16byte aligned for SPT PDMAs
 */

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

typedef enum
{
   DSP_CORE_INITIALIZE,
   DSP_CORE_INITIALIZING,
   DSP_CORE_NORMAL_OPERATION,
} DSP_Interaction_State_T;
typedef struct Frame_Time_Buffer_Tag
{
   uint64_t start_time_us;
   uint64_t end_time_us;
   uint32_t frame_time_us;
   uint32_t lookindex;
} Frame_Time_Buffer_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/

uint32_t M2D_DSP_Not_Ready_Counter = 0U;

#if ENABLE_ADC_DATA_LOGGING == (1U)
volatile uint16_t XCP_ADC_Log_Chirp_Num     = K_MAX;
volatile uint16_t XCP_ADC_Restore_Chirp_Num = K_MAX;
volatile uint16_t XCP_Light_Comp_Range_Num  = MAX_RANGE_BINS;
#endif

volatile uint16_t XCP_Range_Idx     = MAX_RANGE_BINS;
volatile uint16_t XCP_Doppler_Idx   = MAX_DOPPLER_FFT_SIZE;
volatile uint16_t XCP_Angle_Idx     = ANGLE_BINS_USED;
volatile bool XCP_CFAR_Select_CI    = false;
volatile uint32_t Offline_Mode_Flag = ITF_DISABLED_NORMAL_MODE;

/*Set XCP_Range_Idx_BeamVector_Variance to the selected range bin index.*/
volatile uint16_t XCP_Range_Idx_BV_Variance = MAX_RANGE_BINS;

/* DSP Interaction State and error counters*/
DSP_Interaction_State_T DSP_Current_State = DSP_CORE_INITIALIZE;

// If the DSP encounters processing errors more than DSP_Processing_Error_Counter_Max times, trigger a reset of the BBE
uint8_t DSP_Processing_Error_Counter              = 0U;
volatile uint8_t DSP_Processing_Error_Counter_Max = 5U;

// If the DSP is reset more than DSP_Reset_Counter_Max times, trigger a reset of Chandra
uint8_t DSP_Reset_Counter              = 0U;
volatile uint8_t DSP_Reset_Counter_Max = 10U;

/** Related to Max Varying Xput simulation*/

/*Flag to enable or disable the variable throughput RDD test case*/
volatile uint8_t XCP_RDD_Vary_Xput_Flag       = CODED_FALSE;
volatile float32_t XCP_RDD_Vary_Xput_Cfar_Cal = 0.90000f;

/*Flag to enable constant max target/throughput case*/
volatile uint8_t XCP_Max_Static_Target_Case_Enable = CODED_FALSE;
/*Flag to enable varying spe_gain testing in vary xput scenario */
volatile static float32_t XCP_Spe_Gain                = 0.2F; /* Saturate to 512 max target*/
volatile static uint8_t XCP_Spe_Gain_Vary_Enable_Flag = CODED_FALSE;
volatile static float32_t XCP_Spe_Gain_Min            = 0.1F;
volatile static float32_t XCP_Spe_Gain_Max            = 1.0F;

volatile static uint16_t XCP_Rngidx_Target_start = 0U;
/** Control for Max FP targets per RBin*/
volatile static uint16_t XCP_Max_Fp_Per_Rbin_Target_Cnt = SPBB_FP_MAX_DETECT;
/** Control for Max FP targets per look*/
volatile static uint16_t XCP_Max_Fp_Tgt_Cnt = SPBB_FP_MAX_DETECT;

/** R52 to DSP buffer ping pong index*/
uint8_t R52_M2D_Buffer_Index    = 0U;
uint32_t R52_M2D_Msg_Header_Cnt = 0U;

uint32_t Dsp_Cfg_Error_Counter = 0U;

static Frame_Time_Buffer_T Frame_Time_Buffer[FRAME_TIME_BUFFER_DEPTH] = {0};

volatile DSP_SFRS_t *const Dsp_Base_Ptr                    = ((volatile DSP_SFRS_t *const)DSP_base);
volatile CRG_SFRS_t *const Crg_Ptr                         = ((volatile CRG_SFRS_t *const)CRG_base);
volatile static uint8_t fetch_m2d_buffer_idx_hil_injection = 0U;

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
void DSP_Processing_Onetime_Init(void);
bool DSP_Processing_Per_Look_Init(void);

static void Populate_Onetime_Calib_Data_From_SMC(volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
/*===========================================================================*
 * Extern Function Definitions and Function-Like Macros
 *===========================================================================*/

extern FUNC(void, RTE_CODE) Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger(void);

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/******************************************************************************
 * Name:  Record_Frame_Start_Time
 *   Captures frame time when R52 triggers R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION message
 *   to BBE.
 *
 *
 *
 * Parameters: lookindex : stores the frame lookindex of the frame for any consumers to request start time based on lookindex
 *             ping_pong_index : ipc ping pong index to switch between 0/1
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void Record_Frame_Start_Time(uint32_t lookindex, uint8_t ping_pong_index)
{
   Frame_Time_Buffer_T *time_buff = &Frame_Time_Buffer[ping_pong_index];

   Get_Platform_ustime(&time_buff->start_time_us);
   time_buff->end_time_us   = 0U;
   time_buff->frame_time_us = 0U;
   time_buff->lookindex     = lookindex;
}

/******************************************************************************
 * Name:  Update_Frame_Time_For_Look
 *   captures end time and calculates the elapsed frame time after R52 receives SIG_POST_PROCESSING or SIG_POST_ERROR
 *
 *
 *
 * Parameters: lookindex : uses the frame lookindex of the frame to validate the ping pong buffer belongs to requested frame or not
 *             ping_pong_index : ipc ping pong index to switch between 0/1
 *
 * TODO: Logic have to be updated to use pingpongindex directly without the for loop instead of finding it.
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void Update_Frame_Time_For_Look(uint32_t lookindex, uint8_t ping_pong_index)
{
   for (uint8_t idx = 0; idx < FRAME_TIME_BUFFER_DEPTH; idx++)
   {
      Frame_Time_Buffer_T *time_buff = &Frame_Time_Buffer[idx];

      if (time_buff->lookindex == lookindex)
      {
         Get_Platform_ustime(&time_buff->end_time_us);
         Get_Platform_Elapsed_ustime(&time_buff->frame_time_us, time_buff->start_time_us);
      }
   }
}

/******************************************************************************
 * Name:  Get_Frame_Time
 *   API to read corresponding frame time. if the frame is not found in the buffer, function returns 0.
 *
 * Parameters: lookindex : uses the frame lookindex of the frame to validate the ping pong buffer belongs to requested frame or not
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
uint32_t Get_Frame_Time(uint32_t lookindex)
{
   uint32_t frame_time = 0;

   for (uint8_t idx = 0; idx < FRAME_TIME_BUFFER_DEPTH; idx++)
   {
      if (Frame_Time_Buffer[idx].lookindex == lookindex)
      {
         frame_time = Frame_Time_Buffer[idx].frame_time_us;
         break;
      }
   }
   return frame_time;
}

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
/******************************************************************************
 *
 * Name:  Load_Fascia_Compensation_Coeffs
 *   Populates one-time-init buffer fascia compensation params using SMC and
 *   Radar Sensor Position.
 *
 * Shared Variables:
 * - SMC_Cal_Data_Ptr->Slope_Correction_Cal [in]
 *
 * Parameters:
 *  - fascia_compensation_params [out]
 *  - sensor_posn [in]
 *
 * Return Value: none
 *
 ******************************************************************************/
static void Load_Fascia_Compensation_Coeffs(volatile Fascia_Comp_Data_T *fascia_compensation_params, uint8_t sensor_posn)
{
   bool error                              = false;
   fascia_compensation_params->axis_enable = (FC_Enable_Flag_T)k_slope_correction_enable_smc;

   memset((void *)fascia_compensation_params->az_coefficients, 0, sizeof(fascia_compensation_params->az_coefficients));
   memset((void *)fascia_compensation_params->el_coefficients, 0, sizeof(fascia_compensation_params->el_coefficients));

   if (sensor_posn > 0U)
   {
      sensor_posn -= 1U;
      if (sensor_posn < NUM_ELEMS(k_az_coef_list_smc))
      {
         memcpy((void *)fascia_compensation_params->az_coefficients, k_az_coef_list_smc[sensor_posn],
                sizeof(fascia_compensation_params->az_coefficients));
      }
      else
      {
         error = true;
      }
      if (sensor_posn < NUM_ELEMS(k_el_coef_list_smc))
      {
         memcpy((void *)fascia_compensation_params->el_coefficients, k_el_coef_list_smc[sensor_posn],
                sizeof(fascia_compensation_params->el_coefficients));
      }
      else
      {
         error = true;
      }
   }
   else
   {
      error = true;
   }

   if (error)
   {
      /* on error disable fascia compensation entirely to avoid problems */
      fascia_compensation_params->axis_enable = NO_SLOPE_CORRECTION;
   }
}
#endif

/******************************************************************************
 *
 * Name:  DSP_Processing_Onetime_Init
 *   API for One time initialization of DSP application.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void DSP_Processing_Onetime_Init(void)
{
   volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr = Get_IPC_M2D_Onetime_Msg_Buffer();

   /** Initialize IPC Buffers */
   IPC_M2D_Buffer_Init();
   IPC_M2D_One_Time_Buffer_Init();
   IPC_Notify_Buffer_Init();

   /** Add onetime init for signal processing.
    * This includes setting up all the buffers needed for SPT range and doppler processing.
    * Creating One time Init structure holding buffer address and other data to be used inside BBE application onetime Init.
    */
   /*TODO Sandeep: Add other onetime init variables */
   if (NULL != m2d_one_time_init_ptr)
   {
      m2d_one_time_init_ptr->smc_sram_address = (uint32_t)Get_SMC_Cal_Data();
      m2d_one_time_init_ptr->usc_sram_address = (uint32_t)Get_USC_Cal_Data();
      m2d_one_time_init_ptr->radar_position   = Get_Radar_Position();
      Populate_Onetime_Calib_Data_From_SMC(m2d_one_time_init_ptr);

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
      Load_Fascia_Compensation_Coeffs(&(m2d_one_time_init_ptr->fascia_compensation_params), m2d_one_time_init_ptr->radar_position);
#endif

      /* Providing m2d_one_time_init_ptr info, for Integration Testing */
      SIT_M2D_ONETIME((M2D_One_Time_Msg_T *)m2d_one_time_init_ptr);
   }
   else
   {
      /* Do Nothing*/
   }
}

/******************************************************************************
 * Name:  Populate_Onetime_Calib_Data_From_SMC
 *   Populate one-time calibration payload in M2D IPC message from SMC.
 *
 * Shared Variables: none
 *
 * Parameters: m2d_one_time_init_ptr - pointer to one-time IPC payload.
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
static void Populate_Onetime_Calib_Data_From_SMC(volatile M2D_One_Time_Msg_T *m2d_one_time_init_ptr)
{
   /* Populate vehicle calibration data */
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle =
      k_distance_front_bumper_to_rear_axle_smc;
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_rear_cornering_compliance = k_rear_cornering_complicane_smc;
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_steering_gear_ratio       = k_steering_gear_ratio_smc;
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_wheelbase                 = k_wheelbase_smc;
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_vehicle_width             = k_vehicle_width_smc;
   m2d_one_time_init_ptr->calib_data.vehicle_calib_data.k_vehicle_length            = k_vehicle_length_smc;

   /* Populate sensor calibration data */
   uint8_t smc_index           = 0;
   uint8_t this_radar_position = 0;
   uint8_t main_radar_position = m2d_one_time_init_ptr->radar_position;

   if ((uint8_t)BIT_0 != main_radar_position)
   {
      this_radar_position = main_radar_position;

      smc_index = this_radar_position - (uint8_t)BIT_1;

      /* Populate sensor mounting data */
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x =
         k_sensor_mount_pos_x_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y =
         k_sensor_mount_pos_y_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z =
         k_sensor_mount_pos_z_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height =
         k_sensor_mount_height_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw =
         k_sensor_mount_ornt_yaw_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch =
         k_sensor_mount_ornt_pitch_list_smc[smc_index];
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll =
         k_sensor_mount_ornt_roll_list_smc[smc_index];

      /* Populate look specific values */
      for (uint8_t look_id = 0; look_id < 4; look_id++)
      {
         m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_vwrapping[look_id] =
            fabsf(Fix2Float(k_vwrapping_smc[look_id], s10p21_T));
         m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_rwrapping[look_id] =
            fabsf((float)(k_rwrapping_smc[look_id] / (float32_t)(1ULL << 31)));
         m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_detection_range_max[look_id] =
            Fix2Float(k_detection_range_max_smc[look_id], u9p7_T);
      }
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_rdotmin       = Fix2Float(k_rdotmin_smc, s10p21_T);
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_fov_hor_begin = Fix2Float(k_fov_hor_begin_smc, s2p13_T);
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_fov_hor_end   = Fix2Float(k_fov_hor_end_smc, s2p13_T);
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_fov_ver_begin = Fix2Float(k_fov_ver_begin_smc, s2p13_T);
      m2d_one_time_init_ptr->calib_data.sensor_calib_data.k_fov_ver_end   = Fix2Float(k_fov_ver_end_smc, s2p13_T);
      m2d_one_time_init_ptr->calib_data.data_availability_status          = CODED_TRUE;
   }
   else
   {
      m2d_one_time_init_ptr->calib_data.data_availability_status = CODED_FALSE;
   }

   /* Mark availability flag */
}

/******************************************************************************
 * Name:  Release_BBE32_From_Stall
 *   Clear the stall bit in the DSP CTRL register to allow BBE to run.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void Release_BBE32_From_Stall(void)
{
   Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL = 0U; /* release BBE32 core from stall */
}

/******************************************************************************
 * Name:  Perform_Chandra_Reset
 *   Initiate the CRG controlled reset of the Chandra.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void Perform_Chandra_Reset(void)
{
   Crg_Ptr->RESET_ALL = 1U; // Reset Chandra
}

/******************************************************************************
 * Name:  DSP_Done_Processing
 *   Check if the DSP is available to process a new chirp.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
bool DSP_Done_Processing(void)
{
   return Get_Received_Doppler_Done();
}
/******************************************************************************
 * Name:  Perform_BBE32_Reset
 *   Initiate the CRG controlled reset of the BBE32, including the core, bank, and XOCD.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
bool Perform_BBE32_Reset(void)
{
   CRG_RESET_REQ_t reset_req;
   reset_req.r = Crg_Ptr->RESET_REQ.r;

   Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL = 1U; /* stall BBE32 core */

   reset_req.f.CTL_RG_REQ_DSP_CORE = 1U; /* reset BBE32 core */
   reset_req.f.CTL_RG_REQ_DSP_BANK = 1U; /* reset BBE32 bank */
   reset_req.f.CTL_RG_REQ_DSP_XOCD = 1U; /* reset BBE32 XOCD */

   Crg_Ptr->RESET_REQ = reset_req; /* initiate reset */

   reset_req.f.CTL_RG_REQ_DSP_CORE = 0U; /* reset BBE32 core */
   reset_req.f.CTL_RG_REQ_DSP_BANK = 0U; /* reset BBE32 bank */
   reset_req.f.CTL_RG_REQ_DSP_XOCD = 0U; /* reset BBE32 XOCD */

   Crg_Ptr->RESET_REQ = reset_req;

   Set_DSP_Init_Status(false);

   return (true);
}

/******************************************************************************
 * Name:  Handle_Missed_DSP_Frame
 *   Handle missed DSP frames by initiating a reset if necessary.
 *
 * Shared Variables:
 *   - DSP_Reset_Counter
 *   - DSP_Processing_Error_Counter
 *   - DSP_Current_State
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
void Handle_Missed_DSP_Frame(void)
{
   DSP_Processing_Error_Counter++;

   if (DSP_Processing_Error_Counter >= DSP_Processing_Error_Counter_Max)
   {
      DSP_Current_State = DSP_CORE_INITIALIZE;
      if (DSP_Reset_Counter >= DSP_Reset_Counter_Max)
      {
         Perform_Chandra_Reset();
      }
      else
      {
         Perform_BBE32_Reset();

         DSP_Reset_Counter++;
      }
   }
   else
   {
      /* Do Nothing */
   }
}

/******************************************************************************
 * Name:  Run_DSP_Interaction_State_Machine
 *   API for updating per look DSP application data.
 *
 * Shared Variables:
 *   - DSP_Reset_Counter
 *   - DSP_Processing_Error_Counter
 *   - DSP_Current_State
 *
 * Parameters: none
 *
 * Return Value: bool - true for success, false for error
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
bool Run_DSP_Interaction_State_Machine(void)
{
   bool ret_val = false;

   switch (DSP_Current_State)
   {
      case DSP_CORE_INITIALIZE:
         DSP_Processing_Onetime_Init();
         Release_BBE32_From_Stall();
         DSP_Current_State = DSP_CORE_INITIALIZING;
         break;

      case DSP_CORE_INITIALIZING:
         // Waiting for the DSP to send the CORE_INITIALIZED message
         if (Get_DSP_Init_Status())
         {
            DSP_Current_State = DSP_CORE_NORMAL_OPERATION;
            Set_Received_Doppler_Done(true); // Set Received Doppler Done to true when the DSP responds.

            // Return the status of the DSP trigger to the caller, but ignore the value in this state.
            // Calling the per look init here allows the DSP to be triggered earlier, even though this
            // call does not get included in the error handling counts.
            // If this call fails, then the normal processing state will catch it and handle it.
            ret_val = DSP_Processing_Per_Look_Init();
         }
         else
         {
            Handle_Missed_DSP_Frame();
         }

         break;

      case DSP_CORE_NORMAL_OPERATION:
      default:
         // Running code
         ret_val = DSP_Processing_Per_Look_Init();
         if (!ret_val)
         {
            Handle_Missed_DSP_Frame();
         }
         else
         {
            /* If DSP responds to a request, then reset counts to 0.*/
            DSP_Processing_Error_Counter = 0;
            DSP_Reset_Counter            = 0;
         }

         break;
   }

   return ret_val;
}

/******************************************************************************
 * Name:  DSP_Processing_Per_Look_Init
 *   API for updating per look DSP application data.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: bool - true for success, false for error
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
/* debug_dsp_count is defined in r52/main.c; declare extern if needed elsewhere */
extern volatile uint32_t debug_dsp_count;
bool DSP_Processing_Per_Look_Init(void)
{
   SH_Output_T *sh_output_data_ptr    = Get_SH_Output_Data_Ptr();
   Vid_Stream_T *const vid_stream_ptr = (Vid_Stream_T *)(sh_output_data_ptr->sh_get_stream_rx_info_data_fptr(VID_STREAM_NUMBER));

   bool return_value                     = false;
   uint32_t start_time                   = 0U;
   uint32_t elapsed_time                 = 0U;
   uint8_t hil_mode_enabled              = 0U;
   uint8_t hil_veh_data_src              = 0U;
   GLOB_TS_STRUCT_TYPE r52_time_for_sync = {0};
#if defined(FEATURE_ENABLE)
   Platform_fault_T *pflttbl_ptr = Get_Platform_Active_Fault_Table();
#endif
   if (Is_IPC_Notify_Buffer_Full(R52_TO_BBE_CORE) == false)
   {
      if (Get_Received_Doppler_Done())
      {
         volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, WRITE_BUFFER);
         volatile M2D_Msg_T *m2d_msg_ptr                           = Get_IPC_M2D_Msg_Buffer(R52_M2D_Buffer_Index);
         /** Update IPC metadata*/
         ipc_notify_structure_ptr->command       = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
         ipc_notify_structure_ptr->curIpcAddr    = (uint32_t)m2d_msg_ptr;
         ipc_notify_structure_ptr->pingPongIndex = R52_M2D_Buffer_Index;
         fetch_m2d_buffer_idx_hil_injection      = R52_M2D_Buffer_Index;
         R52_M2D_Buffer_Index                    = R52_M2D_Buffer_Index ^ 1U;
         ipc_notify_structure_ptr->lookIndex     = Get_Radar_Scan_Index();
         // ipc_notify_structure_ptr->lookIndex     = Get_Radar_Scan_Index();
         m2d_msg_ptr->payload.offline_mode_flag = Offline_Mode_Flag;

#if defined(FEATURE_ENABLE)
         m2d_msg_ptr->payload.feature_input.temp_init_align_no_calib_flag =
            pflttbl_ptr->Platform_Bits.alignment_no_initial_calibration_error_fault;
#endif

         /** Update data for signal processing per look*/
         m2d_msg_ptr->payload.look_Info.scan_index = Get_Radar_Scan_Index();
         m2d_msg_ptr->payload.look_Info.look_type  = Get_Radar_Look();
         m2d_msg_ptr->payload.look_Info.mode       = Get_Radar_Mode();
         // m2d_msg_ptr->payload.radar_status         = Get_Radar_Ctl_Init_Status();

         /* Record current R52 time and ticks to be able to estimate R52 time from BBE32 */
         CaptureGlobalTimestamp(TS_NO_BUFF, &r52_time_for_sync);
         m2d_msg_ptr->payload.r52_time_for_sync.ts_nanosecs = r52_time_for_sync.ts_nanosecs;
         m2d_msg_ptr->payload.r52_time_for_sync.ts_secs     = r52_time_for_sync.ts_secs;
         m2d_msg_ptr->payload.r52_time_for_sync.ts_status   = r52_time_for_sync.ts_status;
         m2d_msg_ptr->payload.r52_ticks_for_sync            = ((volatile TIMERS_SFRS_t *)TIMERS_base)->TIMER1CURRENTVAL;

         /*TODO Sandeep: Add other DSP_Processing_Per_Look init variables */

         /** Update instrumentation variables for RDD processing*/
         /**
          * XCP_Range_Idx and XCP_Doppler_Idx instrumentation variables for Doppler-RDD processing.
          * Based on the Range and Doppler indices values, following IPC xcp data is made ready for instrumentation purpose:
          * float32_t rdd2_xcp_snr;
          * s10p21_T rdd2_xcp_range_rate;
          * s10p21_T rdd2_xcp_range;
          * uint16_t rdd1_xcp_rdop_avg_dbin[MAX_RANGE_BINS];
          * uint16_t rdd1_xcp_rdop_avg_rbin[MAX_DOPPLER_FFT_SIZE];
          * uint64_t rdd1_xcp_compressed_bv[SPBB_COMPRESSED_BV_SIZE];
          * BV_Decomp_Type_T rdd1_xcp_decompressed_bv[NUM_RX_CHANNELS * NUM_TX_CHANNELS];
          */

#if ENABLE_ADC_DATA_LOGGING == (1U)
         m2d_msg_ptr->payload.xcp_info.xcp_adc_chirp_num         = XCP_ADC_Log_Chirp_Num;
         m2d_msg_ptr->payload.xcp_info.xcp_adc_restore_chirp_num = XCP_ADC_Restore_Chirp_Num;
         m2d_msg_ptr->payload.xcp_info.xcp_light_comp_range_num  = XCP_Light_Comp_Range_Num;
#endif
         m2d_msg_ptr->payload.xcp_info.xcp_range_idx_bv_variance = XCP_Range_Idx_BV_Variance;
         m2d_msg_ptr->payload.xcp_info.xcp_range_idx             = XCP_Range_Idx;
         m2d_msg_ptr->payload.xcp_info.xcp_doppler_idx           = XCP_Doppler_Idx;
         m2d_msg_ptr->payload.xcp_info.xcp_angle_idx             = XCP_Angle_Idx;
         m2d_msg_ptr->payload.xcp_info.xcp_cfar_out_select_ci    = XCP_CFAR_Select_CI;

         /** Update Max Xput simulation variables*/
         m2d_msg_ptr->payload.xcp_info.xcp_rdd_vary_xput_flag            = XCP_RDD_Vary_Xput_Flag;
         m2d_msg_ptr->payload.xcp_info.xcp_rdd_vary_xput_cfar_cal        = XCP_RDD_Vary_Xput_Cfar_Cal;
         m2d_msg_ptr->payload.xcp_info.xcp_max_static_target_case_enable = XCP_Max_Static_Target_Case_Enable;
         m2d_msg_ptr->payload.xcp_info.xcp_max_fp_tgt_cnt                = XCP_Max_Fp_Tgt_Cnt;
         m2d_msg_ptr->payload.xcp_info.xcp_rngidx_target_start           = XCP_Rngidx_Target_start;
         m2d_msg_ptr->payload.xcp_info.xcp_max_fp_per_rbin_target_cnt    = XCP_Max_Fp_Per_Rbin_Target_Cnt;
         m2d_msg_ptr->payload.xcp_info.xcp_spe_gain                      = XCP_Spe_Gain;
         m2d_msg_ptr->payload.xcp_info.xcp_spe_gain_vary_enable_flag     = XCP_Spe_Gain_Vary_Enable_Flag;
         m2d_msg_ptr->payload.xcp_info.xcp_spe_gain_min                  = XCP_Spe_Gain_Min;
         m2d_msg_ptr->payload.xcp_info.xcp_spe_gain_max                  = XCP_Spe_Gain_Max;
         hil_mode_enabled                                                = m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled;
         hil_veh_data_src                                                = m2d_msg_ptr->payload.hil_ipc_info.hil_src_vehicle_data;

         if ((NULL != vid_stream_ptr) &&
             ((CODED_TRUE != hil_mode_enabled) ||
              ((CODED_TRUE == hil_mode_enabled) && (HIL_EXECUTE_VEHICLE_COM_DATA == hil_veh_data_src))))
         {
            static bool Steering_Whl_Angle_Initialized   = false;
            static float32_t Prev_Steering_Whl_Angle_Deg = 0.0F;

            D2M_Msg_T *const p_ipc_d2m = Get_IPC_D2M_Sp_Post_Proc_Buffer();
            M2D_Msg_T *const p_ipc_m2d = (M2D_Msg_T *const)Get_MSS_IPC_M2D_Msg_Buffer();

            static uint8_t write_idx               = 0U;
            Veh_Raw_Data_T *const veh_raw          = &p_ipc_m2d->payload.veh_data.veh_raw_data[write_idx];
            Veh_Raw_Misc_T *const veh_misc         = &p_ipc_m2d->payload.veh_data.veh_raw_misc;
            Veh_Params_T *const veh_params         = &p_ipc_m2d->payload.veh_data.veh_params;
            Last_Key_Cycle_T *const last_key_cycle = &p_ipc_m2d->payload.veh_data.last_key_cycle;

            veh_raw->system_time_secs     = vid_stream_ptr->Veh_Input_Timestamp.global_ts_seconds;
            veh_raw->system_time_nanosecs = vid_stream_ptr->Veh_Input_Timestamp.global_ts_nanosecs;

            veh_raw->ego_yaw_rate = vid_stream_ptr->veh_params.veh_yaw;
            // veh_misc->vehicle_standstill    = UpdateVehicleStandstill(&Vehicle_Standstill_State, veh_raw->ego_vehicle_speed);
            // veh_raw->ego_lateral_accel = ???;
            // veh_raw->ego_longitudinal_accel = ???;
            veh_misc->ego_vehicle_speed_qf = vid_stream_ptr->veh_params.veh_speed_qf;
            veh_misc->ego_yaw_rate_qf      = vid_stream_ptr->veh_params.veh_yaw_qf;
            veh_misc->ego_lateral_accel_qf =
               3; // valid value (3) is used since the signals are not available from the vid_stream_ptr
            veh_misc->ego_longitudinal_accel_qf =
               3; // valid value (3) is used since the signals are not available from the vid_stream_ptr
            veh_misc->steering_whl_angle_qf =
               3; // valid value (3) is used since the signals are not available from the vid_stream_ptr

            veh_raw->steering_whl_angle = vid_stream_ptr->veh_params.veh_steering_angle;
            veh_raw->ego_vehicle_speed  = vid_stream_ptr->veh_params.veh_speed;
            veh_misc->gear_pos          = vid_stream_ptr->veh_params.gear_position;
            veh_misc->turn_signal       = 0;

            /* Need to take these values from the DRA stream if it is available */
            /* Otherwise, keep the previous values (or defaults if DRA hasn't been available once yet) */
            static float32_t speed_comp  = 1.0F;
            static uint8_t speed_comp_qf = 3U;
            if (p_ipc_d2m != NULL && p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode != 0U)
            {
               speed_comp    = p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated;
               speed_comp_qf = p_ipc_d2m->payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf;
            }
            veh_misc->vehspeedcompfac_ka    = speed_comp;
            veh_misc->vehspeedcompfac_ka_qf = speed_comp_qf;

            const float32_t steering_whl_angle_deg = (veh_raw->steering_whl_angle * RAD_TO_DEG_F32);
            if (!Steering_Whl_Angle_Initialized)
            {
               veh_raw->steering_whl_speed_deg_per_s = 0.0F;
               Steering_Whl_Angle_Initialized        = true;
            }
            else
            {
               veh_raw->steering_whl_speed_deg_per_s = (steering_whl_angle_deg - Prev_Steering_Whl_Angle_Deg) / .05;
            }
            Prev_Steering_Whl_Angle_Deg = steering_whl_angle_deg;

            p_ipc_m2d->payload.veh_data.latest_raw_index = write_idx;
            write_idx                                    = (uint8_t)((write_idx + 1U) % VSE_STREAM_RAW_INSTANCES);

            veh_params->k_wheel_base                      = k_wheelbase_smc;
            veh_params->k_dist_rear_axle_to_vcs           = k_distance_front_bumper_to_rear_axle_smc;
            veh_params->k_steering_gear_ratio             = k_steering_gear_ratio_smc;
            veh_params->k_understeer_coefficient          = k_rear_cornering_complicane_smc;
            veh_params->k_rear_cornering_compliance       = k_rear_cornering_complicane_smc;
            veh_params->k_vehicle_length                  = k_vehicle_length_smc;
            veh_params->k_vehicle_width                   = k_vehicle_width_smc;
            veh_params->k_cog_x                           = 0.0F;
            veh_params->k_cog_y                           = 0.0F;
            veh_params->k_front_track_width               = 0.0F;
            veh_params->k_steering_ratio_rack_pinion_type = 0.0F;

            uint8_t sts_radar_pos                      = Get_Radar_Position();
            uint8_t smc_index                          = sts_radar_pos - (uint8_t)BIT_1;
            veh_params->k_long_dist_radar_to_rear_axle = k_sensor_mount_pos_x_list_smc[smc_index];
            veh_params->k_lat_dist_radar_to_rear_axle  = k_sensor_mount_pos_y_list_smc[smc_index];

            last_key_cycle->nvm_f_last_rem_swa_bias                    = 0u;
            last_key_cycle->nvm_last_rem_stop_yaw_bias_secondary_radps = 0.0F;
            last_key_cycle->nvm_last_rem_stop_yaw_bias_primary_radps   = 0.0F;
            last_key_cycle->nvm_last_rem_speed_comp                    = 0.0F;
            last_key_cycle->nvm_last_rem_swa_bias_deg                  = 0.0F;

            /* Temporary fix for platform satellite builds until VSE ethernet population is confirmed fixed */
            p_ipc_m2d->payload.veh_data.vse_output.raw_speed_mps           = fabsf(vid_stream_ptr->veh_params.veh_speed);
            p_ipc_m2d->payload.veh_data.vse_output.raw_yaw_rate_rps        = vid_stream_ptr->veh_params.veh_yaw;
            p_ipc_m2d->payload.veh_data.vse_output.comp_steering_angle_deg = vid_stream_ptr->veh_params.veh_steering_angle;
            p_ipc_m2d->payload.veh_data.vse_output.reverse_status          = vid_stream_ptr->veh_params.veh_speed < 0.0F ? 1 : 0;
            p_ipc_m2d->payload.veh_data.vse_output.yaw_rate_bias           = vid_stream_ptr->veh_params.yaw_rate_bias;
            p_ipc_m2d->payload.veh_data.vse_output.comp_yaw_rate_filtered  = vid_stream_ptr->veh_params.veh_yaw;
            p_ipc_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground = vid_stream_ptr->veh_params.veh_speed;
            p_ipc_m2d->payload.veh_data.vse_output_valid                             = CODED_TRUE;
            veh_misc->gear_pos = vid_stream_ptr->veh_params.veh_speed < 0.0F ? 1 : 3;
         }

         m2d_msg_ptr->payload.avg_mmic_onchip_temp = Compute_MMIC_On_Chip_Temperature();

         m2d_msg_ptr->payload.Radar_Sts_Ptr = (uint32_t)&Radar_Data_Status;

         /* Providing MMIC onchip temp data, for Integration Testing */
         SIT_MMIC_ONCHIP_DATA((M2D_Msg_T *)m2d_msg_ptr);

         /* Providing M2D_msg_ptr info, for Integration Testing */
         SIT_M2D_PERLOOK((M2D_Payload_T *)&m2d_msg_ptr->payload);

         /* To send IT Data from M2D, for Integration Testing */
         SIT_IPC_TRANSFER_M2D_SEND((M2D_Payload_T *)&m2d_msg_ptr->payload);
#ifdef XCP_FAULT_INJECTION
         Set_XCP_Fault_Inj();
#endif
         /* TO-DO : Move to HW CRC from SW CRC */
         Update_IPC_M2D_Header(m2d_msg_ptr);

         // DSP_Last_Trigger_Timestamp = Get_Timestamp_us();
         Set_DSP_Cfg_Init(DSP_CONFIG_WAITING_FOR_RESPONSE);
         Set_Received_Doppler_Done(false);
         /* Increment write index just before R52_BBE_Trigger to avoid race condition*/
         Increment_IPC_Notify_WriteIndx(R52_TO_BBE_CORE);
         Record_Frame_Start_Time(ipc_notify_structure_ptr->lookIndex, ipc_notify_structure_ptr->pingPongIndex);
         /** Trigger BBE */
         if (R52_BBE_Trigger())
         {
            /** Check for Range Process Config Init completion */
            Get_Platform_mstime(&start_time);
            do
            {
               Get_Platform_Elapsed_mstime(&elapsed_time, start_time);
            } while ((Get_DSP_Cfg_Init() == DSP_CONFIG_WAITING_FOR_RESPONSE) && (elapsed_time < IPC_MESSAGE_TIMEOUT_IN_MS));

            if (Get_DSP_Cfg_Init() != DSP_CONFIG_NO_ERROR)
            {
               Dsp_Cfg_Error_Counter++;
            }
            else
            {
               return_value = true;
               /* Do Nothing */
            }
         }
         else
         {
            /* Do Nothing */
         }
      }
      else
      {
         M2D_DSP_Not_Ready_Counter++;
      }
   }
   else
   {
      Set_M2D_Buffer_Full_Error_Counter(Get_M2D_Buffer_Full_Error_Counter() + 1U);
   }

   return return_value;
}

/******************************************************************************
 * Name:  Get_Fetch_M2D_Buffer_Idx_HIL_Injection
 *   API for fetching the M2D buffer index used for HIL injection.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: uint8_t - M2D buffer index used for HIL injection
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
uint8_t Get_Fetch_M2D_Buffer_Idx_HIL_Injection(void)
{
   return fetch_m2d_buffer_idx_hil_injection;
}
