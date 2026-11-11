/*===========================================================================*\
 * FILE: mmic_interface.c
 *===========================================================================
 * Copyright (C) 2024 APTIV, All Rights Reserved.
 * APTIV Confidential (C)
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This file contains interfaces for initializing and updating the mmic device
 * drivers.
 *
 * ABBREVIATIONS:
 *
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *
 *   Requirements Document(s):
 *
 *
 *   Applicable Standards (in order of precedence: highest first):
 *   1. C Coding Standards SW REF 264.15D
 *
 * DEVIATIONS FROM STANDARDS:
 *
 *
\*===========================================================================*/
/*===========================================================================*\
 * Preprocessor #include directive(s) for standard header files
\*===========================================================================*/

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/
#include "mmic_interface.h"
#include "Rte_SWC_PLT_CDD_Radar_Control.h"
#include "crc_calc.h"
#include "crg_sfrs.h"
#include "dd_mipi.h"
#include "dd_mmic.h"
#include "ipc_mss.h"
#include "mipi_interrupt.h"
#include "mmic_common_types.h"
#include "mmic_error.h"
#include "platformtime.h"
#include "radar_data.h"
#include "radar_look_types.h"
#include "radar_sw_config.h"

/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/
#define CHIRPS_PER_CHIRPFRAME               (1020U)
#define MMIC_MIPI_FAILURE_CHIRPS_PER_FRAME  (CHIRPS_PER_CHIRPFRAME + 80U)
#define NUM_OF_INPUT_ADC_CHANNELS           (4U)
#define MMIC_INIT_THTRSHOLD_COUNT           (50U)
#define MMIC_SAFE_STATRUP_MAX_COUNT         (3U)
#define DAQ_FIT_INJECTION_THRESHOLD_TIME_US (6000U)

// To Do: Logic to be revisited after FLS read
#define MMIC_INIT_RETRY_COUNT                                                                                                     \
   (((MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status) ||                                                     \
     (XCP_MMIC_SAFE_STARTUP_FIT_TEST == XCP_MMIC_FIT_Enable)) ?                                                                   \
       MMIC_SAFE_STATRUP_MAX_COUNT :                                                                                              \
       MMIC_INIT_THTRSHOLD_COUNT)

#define MMIC_DAQ_OVER_FLOW_TOLERANCE (0.2F) /*increase tolerance to 20% from 5% to avoid false positives*/
#ifndef PLATFORMTIME_MAX
   #define PLATFORMTIME_MAX (343597383U)
#endif
#define ACQ_WINDOW_TIME_FACTOR_FIT (2.0F)
#ifndef US_2_MS
   #define US_2_MS (0.001F)
#endif
#if MIDDLE_OF_DWELL_TEST
static GLOB_TS_STRUCT_TYPE Mid_Prev;
static GLOB_TS_STRUCT_TYPE Mid_Curr;
static volatile uint64_t Mid_To_Mid     = 0U;
static volatile uint64_t Mid_To_Mid_Max = 0U;
static volatile uint64_t Mid_To_Mid_Min = UINT64_MAX;
#endif
/* Mss radar data status payload live counter */
static volatile uint16_t RFE_Radar_Status_CRC_Count = 0U;
extern volatile uint8_t Alive_Flag;
/*===========================================================================*\
 * Local preprocessor #define MACROS()
\*===========================================================================*/
#define Put_MMIC_Config_Ptr(ptr) (MMIC_Config_Ptr = ptr)
#ifndef MIDDLE_OF_DWELL_TEST // for testing the delta between two middle of dwell times
   #define MIDDLE_OF_DWELL_TEST (0U)
#endif

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef enum MMIC_System_Start_Error_Value_Tag
{
   NO_FAILURE   = 0U,
   MIPI_FAILURE = 1U,
   MARS_FAILURE = 2U,
} MMIC_System_Start_Error_Value_T;

/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/
MMIC_Config_T MMIC_Config[NUM_LOOKS];
MMIC_Config_T *MMIC_Config_Ptr = &MMIC_Config[0];

uint8_t MMIC_XCP_Enable_CW_Mode = CODED_FALSE;
IPC_MMIC_Radar_Data_Status_T __attribute__((aligned(32), used, section(".ipc_radar_data_status"))) Radar_Data_Status;
uint32_t Sensor_Dwell_Time_Duration_Ns;
extern volatile bool MIPI_Chp_FuSa_Flag;
extern MMIC_Error_Data_T MMIC_Error;
extern MMIC_FuSa_Faults_T Mars_FSM_Reg_State;
extern FuSa_Faults_Union_T MMIC_Fusa_Active_Fault;
/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
/* Data Acquisition Variables */
static volatile uint8_t MMIC_Daq_Over_Flow_Error_Cnt[NUM_LOOKS] = {0U, 0U, 0U, 0U, 0U, 0U};
static volatile uint32_t MMIC_Daq_Min_Time[NUM_LOOKS]           = {0U, 0U, 0U, 0U, 0U, 0U};
static volatile uint32_t MMIC_Daq_Max_Time[NUM_LOOKS]           = {0U, 0U, 0U, 0U, 0U, 0U};
static volatile uint8_t MMIC_Daq_Over_Flow_Err_Flag             = CODED_FALSE;
volatile uint32_t Acq_Window_Time[NUM_LOOKS]                    = {0U, 0U, 0U, 0U, 0U, 0U};
MIPI_Config_T MIPI_Config = {{MIPI_TEST_PATTERN_0x0_PULSE}, {0}, {0}, {0}, {0}, {0}, 0, 0, 0, 0, 0, 0, false};

/*===========================================================================*\
 * Local function prototypes
\*===========================================================================*/
static void Init_MMIC_Config(void);
static void Update_API_Fault_Status(API_Fault_Type_T fault_type);
static void MMIC_Daq_Cal_Min_Max_Time(void);
static void Update_Dwell_Timestamps(void);
void MMIC_Fault_Injection(XCP_MMIC_FIT_Enable_T fit_enable, Radar_Look_T look_id);
void Rfe_Nvm_Read(MMIC_Data_Logging_T *MMIC_Data_Ptr);
/*===========================================================================*\
 * Local inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/

/*===========================================================================*\
 * FUNCTION: MMIC_Reset_Init
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called during power on reset before the OS periodic
 * tasks start.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Reset_Init(void)
{
   Clr_MMIC_Faulted();
}
/*===========================================================================*\
 * FUNCTION: MMIC_Reset_MIPI
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called to reset the MIPI so that DSP can configure IDM/DC
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Reset_MIPI(void)
{
   MARS_Metadata_Read();
   volatile CRG_SFRS_t *const crg_ptr       = ((volatile CRG_SFRS_t *)CRG_base);
   crg_ptr->RESET_REQ.f.CTL_RG_REQ_MIPI_SYS = 1U; /* reset RA logic between frames */
   crg_ptr->RESET_REQ.f.CTL_RG_REQ_MIPI_SYS = 0U; /* reset RA logic between frames  */
}
/*===========================================================================*\
 * FUNCTION: MMIC_Config_MIPI
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    bool
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called to Configure the MIPI once after the DSP configured
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

void MMIC_Config_MIPI(void)
{
   bool ret_val                           = false;
   MIPI_Config.num_of_chirps_per_frame    = K_FRAME[Get_Radar_Look()]; // chirps per frame;
   MIPI_Config.symbols_per_chirp          = M_FRAME[Get_Radar_Look()]; // SYMBOLS_PER_CHIRP;
   MIPI_Config.num_of_active_adc_channels = NUM_OF_INPUT_ADC_CHANNELS;
   MIPI_Config.data_bits_size             = MIPI_INPUT_DATA_0x0_14_BITS;
   MIPI_Config.enable_debug_mode          = false;

   /* TODO : Need to change the placement of this code after Navi's discussion */
   ret_val = MIPI_Init(&MIPI_Config);

   if (!ret_val)
   {
      Set_MMIC_Error_Reinit(REINIT_ERROR_MIPI_CONFIG_RUN_TIME);
   }
}

/*===========================================================================*\
 * FUNCTION: MMIC_Config_Device
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called to initialize the MMIC device drivers.  It is
 * typically called one time.  The function may be called again if an error
 * is reported through the Set_MMIC_Error() interface.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Config_Device(void)
{
   MMIC_Result_T result                        = MMIC_SUCCESS;
   MMIC_System_Start_Error_Value_T error_value = NO_FAILURE;
   MIPI_Config.num_of_chirps_per_frame         = CHIRPS_PER_CHIRPFRAME;
   MIPI_Config.symbols_per_chirp               = SYMBOLS_PER_CHIRP;
   MIPI_Config.num_of_active_adc_channels      = NUM_OF_INPUT_ADC_CHANNELS;
   MIPI_Config.data_bits_size                  = MIPI_INPUT_DATA_0x0_14_BITS;
   MMIC_Fault_Status_T *mmic_fault_status      = &(MMIC_Stream.MMIC_Data.MMIC_fault_status);

   Radar_Look_T look;
   // Reinit_Error flag should be cleared before initializing MMIC configuration so that hysteresis value is not carried ahead
   MMIC_Error.reinit_error = false;

   Init_MMIC_Config();
   MMIC_Daq_Cal_Min_Max_Time();

   look = Get_Radar_Look();
   Put_MMIC_Config_Ptr(&MMIC_Config[look]);

   result &= MIPI_Init(&MIPI_Config);

   if (MMIC_FAIL == result)
   {
      Set_MMIC_Error_Reinit(REINIT_ERROR_MIPI_CONFIG_INIT);
      error_value = MIPI_FAILURE;
   }
   else
   {
#ifdef BETTER_TESTING_MODE
      Layer2_Init();
      Layer2_RunOnce();
#endif
      result &= RFE_Init();

      if (MMIC_FAIL == result)
      {
         Set_MMIC_Error_Reinit(REINIT_ERROR_MMIC_INIT);
         error_value = MARS_FAILURE;
      }
   }
   /* Check for MMIC and MIPI Initialization Failure */

   if (MMIC_FAIL == result)
   {
      mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt++;
   }
   else
   {
      mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt = 0U;
      Clr_MMIC_Error_Reinit();
   }

   /* logic for System Start fault */
   if (mmic_fault_status->MMIC_system_start_status.MMIC_startup_error_cnt >= MMIC_INIT_RETRY_COUNT)
   {
      mmic_fault_status->MMIC_system_start_status.MMIC_system_start_fault = CODED_TRUE;
   }
   else
   {
      mmic_fault_status->MMIC_system_start_status.MMIC_system_start_fault = CODED_FALSE;
   }

   // Set the error value to NO_FAILURE, MARS_FAILURE or MIPI_FAILURE
   mmic_fault_status->MMIC_system_start_status.MMIC_system_start_error_value = error_value;
}

/*===========================================================================*\
 * FUNCTION: MMIC_Fault_Injection
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    XCP_MMIC_FIT_Enable_T fit_enable
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Injects MMIC-related faults based on the XCP MMIC FIT enable value
 *    (e.g. safe start-up, DAQ min/max time, and FCCU fault tests) to
 *    support safety and diagnostic testing.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Fault_Injection(XCP_MMIC_FIT_Enable_T fit_enable, Radar_Look_T look_id)
{
   MMIC_Temperature_Status_T *current_temp_stat_ptr = &(MMIC_Stream.MMIC_Data.current_temp_status);
   MMIC_ID_Status_T *mmic_id_status_ptr             = Get_Mmic_Id_Ptr();
   static uint8_t i                                 = 0U;
   switch (fit_enable)
   {
      case XCP_MMIC_SAFE_STARTUP_FIT_TEST:
         mars_firmware_activation_type_smc = 0xFFU;
         Set_MMIC_Error_Reinit(REINIT_ERROR_MMIC_INIT);
         break;

      case XCP_MMIC_FUNCTION_CONFIG_FIT_TEST:
         mars_cfg_tx_config_tx_power_smc[look_id] = 16;
         break;

      case XCP_MMIC_DAQ_MIN_TIME_FIT_TEST:
         if (i <= 4)
         {
            i++;
            MMIC_Daq_Min_Time[look_id] += DAQ_FIT_INJECTION_THRESHOLD_TIME_US;
         }
         break;

      case XCP_MMIC_DAQ_MAX_TIME_FIT_TEST:
         if (i <= 4)
         {
            i++;
            MMIC_Daq_Max_Time[look_id] -= DAQ_FIT_INJECTION_THRESHOLD_TIME_US;
         }
         break;

      case XCP_MMIC_LOW_TEMP_FIT_TEST:
         current_temp_stat_ptr->state_pvt       = MARS_VAL_FRESH;
         current_temp_stat_ptr->temperature_pvt = LOW_Temperature_Threshold_SMC - 1;
         break;

      case XCP_MMIC_HIGH_TEMP_FIT_TEST:
         k_tx_threshold_temperature_smc = OVER_Temperature_Threshold_SMC + 1;
         break;

      case XCP_MMIC_MIPI_FAILURE_FIT_TEST:
         /* Configure more than CHIRPS_PER_CHIRPFRAME chirps per frame to cause MIPI failure */
         mars_cfg_chirp_config_chirps_per_frame_smc[look_id] = MMIC_MIPI_FAILURE_CHIRPS_PER_FRAME;
         break;

      case XCP_MMIC_ID_FIT_POS_TEST:
         Update_Usc_Mmic_Id(USC_CHIP_ID_ADDRESS, MMIC_RF_ID, CHIP_ID_LEN); // Set a specific MMIC ID value for positive test case

         if (CODED_FALSE == mmic_id_status_ptr->mmic_id_programmed)
         {
            MMIC_Error.reinit_error = true;
            XCP_MMIC_FIT_Enable =
               XCP_MMIC_NO_FIT_TEST; // Retain the FIT enable value to continue injecting the fault until the ID is programmed
         }
         break;

      case XCP_MMIC_ID_FIT_NEG_TEST:
         Update_Usc_Mmic_Id(USC_CHIP_ID_ADDRESS, MMIC_RF_ID, CHIP_ID_LEN); // Set a specific MMIC ID value for negative test case
         MMIC_Error.reinit_error = true;
         break;

      case XCP_MMIC_TX_BIST_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19]  = 0x40;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON      = 0x1 << 4;
         break;

      case XCP_MMIC_RX_BIST_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[4]   = 0x01;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON      = 0x1 << 4;
         break;
      case XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[18]  = 0x01;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON      = 0x1 << 4;
         break;
      case XCP_MMIC_SFT_NON_RECOVERABLE_ERROR_FIT_TEST:
      case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_CLOCK_FAULT_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_NON_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON =
            0x40000; // set the reference PLL lock bit to inject error in SFT monitor
         MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV0 = 0x101; // sm_028

         break;
      case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_MCU_FAULT_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_NON_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON      = 0x100000; // set the Handle_MCU_Subsystem_Error
         MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_0          = 0x10001;  // sm_001
         MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_3          = 0x10001000;
         break;
      case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_REGISTER_FAULT_FIT_TEST:
         MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected      = 1U;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG = MAF_NON_RECOVERABLE_FAULT;
         MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON =
            0x4; // set the reference PLL lock bit to inject error in SFT monitor
         MMIC_Stream.MMIC_Data.mmic_bist_status.CPLL_BANK_REFPLL_ERR = 0x101; // sm_014
         break;
      case XCP_MMIC_API_LOOK_TRIGGER_FIT_TEST:
      case XCP_MMIC_API_LOOK_COMPLETE_FIT_TEST:
         break;
      default:
         XCP_MMIC_FIT_Enable = XCP_MMIC_NO_FIT_TEST;
         break;
   }
}

/*===========================================================================*\
 * FUNCTION: MMIC_Config_Look
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function is called periodically to configure the next radar frame or
 * look.  MMIC_Config_Device will be called at least one time before this
 * interface is called.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Config_Look(void)
{
   MMIC_Result_T result = MMIC_SUCCESS;
   Radar_Look_T look    = Get_Radar_Look();
   Put_MMIC_Config_Ptr(&MMIC_Config[look]);

   if (XCP_MMIC_FIT_Enable != XCP_MMIC_NO_FIT_TEST)
   {
      /* Call the MMIC Fault Injection function to inject faults based on the XCP F1 12 input */
      MMIC_Fault_Injection(XCP_MMIC_FIT_Enable, look);
   }
   MMIC_Reset_MIPI();
   MIPI_Disable();

   MMIC_Config_MIPI();
   result &= RFE_Look_Configure();
   // result &= Csi2_Ppe_Look_Configure(); /*Link with MIPI configure func */
   if (MMIC_FAIL == result)
   {
      Set_MMIC_Error_Discard(DISCARD_ERROR_CONFIG_LOOK);
   }
   else
   {
      Clr_MMIC_Error_Discard();
   }
   if (API_ERROR_THRESHOLD <= API_Look_Config_Error)
   {
      Update_API_Fault_Status(API_FAULT_LOOK_CONFIG);
   }
   else
   {
      MMIC_API_Failure_Status[API_FAULT_LOOK_CONFIG] = CODED_FALSE;
   }
}
#ifdef MARS_RESET_MECHANISM_ENABLED
/*===========================================================================*\
 * FUNCTION: MMIC_Reset_MARS
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function is called when there is a reset within MARS regular execution
 * from the off state machine.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Reset_MARS(void)
{
   MMIC_Result_T result = MMIC_SUCCESS;
   result &= MARS_Reset();
   // result &= Csi2_Ppe_Look_Configure(); /* ToDo: Link with MIPI configure func */
   if (MMIC_FAIL == result)
   {
      Set_MMIC_Error_Discard(DISCARD_ERROR_RESET);
   }
   else
   {
      Clr_MMIC_Error_Discard();
   }
}
#endif

/*===========================================================================*\
 * FUNCTION: MMIC_Look_Trigger
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function is called to trigger the radar frame (look) that was
 * configured by the MMIC_Config_Look interface.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Look_Trigger(void)
{
   MMIC_Result_T result = MMIC_SUCCESS;
   MIPI_Enable(); /* enable MIPI */
   result = RFE_Trigger();

   if (MMIC_FAIL == result)
   {
      Set_MMIC_Error_Discard(DISCARD_ERROR_LOOK_TRIGGER);
   }
   if (API_ERROR_THRESHOLD <= API_Look_Trigger_Error)
   {
      Update_API_Fault_Status(API_FAULT_LOOK_TRIGGER);
   }
   else
   {
      MMIC_API_Failure_Status[API_FAULT_LOOK_TRIGGER] = CODED_FALSE;
   }
}

/*===========================================================================*\
 * FUNCTION: MMIC_Look_Complete
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function is called after the radar frame (look) has been transmitted.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Look_Complete(void)
{
   MMIC_Result_T result = MMIC_SUCCESS;
   Radar_Look_T look;
   MMIC_Data_Logging_T *MMIC_Data_Ptr = &MMIC_Stream.MMIC_Data;
   Radar_Ctl_State_T radar_ctl_state  = Get_Radar_Ctl_State();
   MMIC_Bist_Status_T *bist_stat_ptr  = &MMIC_Stream.MMIC_Data.mmic_bist_status;

   look = Get_Radar_Look();
   Put_MMIC_Config_Ptr(&MMIC_Config[look]);

   /* Populate start, end, and middle of dwell timestamps */
   Update_Dwell_Timestamps();
   result &= RFE_Look_Complete();

   /* Validate AoU related to CORE_BANK_MCU_STS_MCU_MSSG */
   if (((mars_sft_err_n_t)1U == bist_stat_ptr->safety_error_detected) &&
       (MAF_NON_RECOVERABLE_FAULT < bist_stat_ptr->CORE_BANK_MCU_STS_MCU_MSSG))
   {
      Set_MMIC_Error_Reinit(REINIT_ERROR_MARS_MCU_STS_MCU_MSSG);
   }

   /* Decode the MIPI FuSa Faults once ISR is triggered */
   if (MIPI_Chp_FuSa_Flag)
   {
      MIPI_FuSa_Fault_Processing();
      /* clear the MIPI FuSa Counter */
      MIPI_Chp_FuSa_Flag = false;
   }

   if (MMIC_FAIL != result)
   {
      Update_MMIC_Success();
   }
   Update_Radar_Data_Status();
   /* M7 Radar Data Status Payload CRC calculation */
   Compute_M7_Rdr_Data_Sts_Payload_CRC();
   /* don't check for LOOK_E(5th Look)(TODO for GEN8) , Degrade & Idle Mode*/
   if ((RADAR_CTL_DEGRADED != radar_ctl_state) && (RADAR_CTL_IDLE != radar_ctl_state))
   {
      /* Acquisition Overflow Check */
      Check_MMIC_DAQ_OverFlow_Time(look);
   }
   if (API_ERROR_THRESHOLD <= API_Look_Complete_Error)
   {
      Update_API_Fault_Status(API_FAULT_LOOK_COMPLETE);
   }
   else
   {
      MMIC_API_Failure_Status[API_FAULT_LOOK_COMPLETE] = CODED_FALSE;
   }
   Validate_MMIC_Error_Reinit_Count();
   /*Update data to stream from NVM*/
   Rfe_Nvm_Read(MMIC_Data_Ptr);
   /*Move these calls to respective place as needed */
   (void)Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream();
}

/*===========================================================================*\
 * FUNCTION: Compute_M7_Rdr_Data_Sts_Payload_CRC
 *===========================================================================*
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function updates the live counter and computes the CRC for the M7 radar
 * data status payload.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Compute_M7_Rdr_Data_Sts_Payload_CRC(void)
{
   if (Alive_Flag == CODED_FALSE)
   {
      Alive_Flag = CODED_TRUE; // updating the alive counter only once per radar cycle cleared in look trigger in next radar cycle
      Radar_Data_Status.radar_data_status_header.alive_counter = ++RFE_Radar_Status_CRC_Count;
   }
   Radar_Data_Status.radar_data_status_header.radar_data_status_crc = Compute_CRC32_SW(
      (uint8_t *)(&(Radar_Data_Status.radar_data_status_payload)), (uint32_t)(sizeof(Radar_Data_Status_Payload_T)), 0, true);
}
/*===========================================================================*\
 * FUNCTION: Init_MMIC_Config
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Initialize MMIC_Config data.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Init_MMIC_Config(void)
{
   uint8_t cnt;
   for (cnt = 0U; cnt < NUM_LOOKS; cnt++)
   {
      MMIC_Config[cnt].num_chirps  = K_FRAME[cnt];
      MMIC_Config[cnt].num_samples = M_FRAME[cnt];
   }
}
/*===========================================================================*\
 * FUNCTION: Update_Radar_Data_Status
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function updates radar status structure & DSS core will use to set Data qualifier
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Update_Radar_Data_Status(void)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard = (Get_MMIC_Error_Discard()) ? CODED_TRUE : CODED_FALSE;
}
/*===========================================================================*\
 * FUNCTION: Update_Mmic_Discard_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function update radar data status Discard error to CODED TRUE
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Update_Mmic_Discard_Error(void)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Data_Discard = CODED_TRUE;
}
/*===========================================================================*\
* FUNCTION: Get_MMIC_System_Start_Fault
 *===========================================================================
 * RETURN VALUE:
 * uint8_t MMIC_System_Start_Fault -
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Returns status of Safe start-up fault
 *
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_System_Start_Fault(void)
{
   return (MMIC_Stream.MMIC_Data.MMIC_fault_status.MMIC_system_start_status.MMIC_system_start_fault);
}
/*===========================================================================*\
 * FUNCTION: Check_MMIC_DAQ_OverFlow_Time
 *===========================================================================
 * RETURN VALUE:
 *   void
 *
 * PARAMETERS:
 *    Radar_Look_T look_var
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function checks the Data Acq Over Flow time or under flow and
 * increment/decrement error count based on the (min/max acquistion)condition
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Check_MMIC_DAQ_OverFlow_Time(Radar_Look_T look_var)
{
   uint64_t *Acq_End_Time_FE_Ptr   = Get_Acq_End_Time_FE_Ptr();
   uint64_t *Acq_Start_Time_FS_Ptr = Get_Acq_Start_Time_FS_Ptr();
   if (Acq_Start_Time_FS_Ptr[look_var] > Acq_End_Time_FE_Ptr[look_var])
   {
      Acq_Window_Time[look_var] = Acq_End_Time_FE_Ptr[look_var] + (PLATFORMTIME_MAX - Acq_Start_Time_FS_Ptr[look_var]);
   }
   else
   {
      Acq_Window_Time[look_var] = (Acq_End_Time_FE_Ptr[look_var] - Acq_Start_Time_FS_Ptr[look_var]);
   }

   /* Update the MMIC Stream with the acquisition timestamps and window time */
   MMIC_Stream.MMIC_Data.mmic_daq_status.acq_frame_end_time[look_var]   = Acq_End_Time_FE_Ptr[look_var];
   MMIC_Stream.MMIC_Data.mmic_daq_status.acq_frame_start_time[look_var] = Acq_Start_Time_FS_Ptr[look_var];
   MMIC_Stream.MMIC_Data.mmic_daq_status.acq_window_time[look_var]      = Acq_Window_Time[look_var];
   /* Clear the Flag before it Setting*/
   MMIC_Daq_Over_Flow_Err_Flag = CODED_FALSE;

   /*Check Data Acquisition Over Flow Condition &*/
   if ((Acq_Window_Time[look_var] >= MMIC_Daq_Max_Time[look_var]) || (Acq_Window_Time[look_var] <= MMIC_Daq_Min_Time[look_var]))
   {
      MMIC_Daq_Over_Flow_Error_Cnt[look_var]++;
      MMIC_Stream.MMIC_Data.mmic_daq_status.mmic_daq_over_flow_err_cnt[look_var] = MMIC_Daq_Over_Flow_Error_Cnt[look_var];
      /* set the Daq Over Flow error Flag*/
      MMIC_Daq_Over_Flow_Err_Flag                                       = CODED_TRUE;
      MMIC_Stream.MMIC_Data.mmic_daq_status.mmic_daq_over_flow_err_flag = CODED_TRUE;
   }
   else
   {
      MMIC_Daq_Over_Flow_Error_Cnt[look_var]                                     = 0U;
      MMIC_Stream.MMIC_Data.mmic_daq_status.mmic_daq_over_flow_err_cnt[look_var] = MMIC_Daq_Over_Flow_Error_Cnt[look_var];
   }

   /* clear once the validation is completed */
   Acq_Window_Time[look_var]       = 0U;
   Acq_End_Time_FE_Ptr[look_var]   = 0U;
   Acq_Start_Time_FS_Ptr[look_var] = 0U;
}
/*===========================================================================*\
 * FUNCTION: Get_MMIC_Daq_Over_Flow_Fault
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This Function Returns The Data Acq Over Flow Fault Based On The Threshold Value
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_Daq_Over_Flow_Fault(void)
{
   uint8_t ret_val = CODED_FALSE;
   uint8_t cnt;
   uint8_t MMIC_Daq_Total_Err_Cnt = 0U;

   for (cnt = 0U; cnt < NUM_LOOKS; cnt++)
   {
      MMIC_Daq_Total_Err_Cnt += (MMIC_Daq_Over_Flow_Error_Cnt[cnt]);
   }

   /* Debounce Check for MMIC_Daq_Over_Flow_Fault */
   if (MMIC_DAQ_OVER_FLOW_ERR_THRESH < MMIC_Daq_Total_Err_Cnt)
   {
      ret_val = CODED_TRUE;
   }

   return (ret_val);
}
/*===========================================================================*\
 * FUNCTION: Get_MMIC_Daq_Over_Flow_Err
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns the Data Acq Over Flow Fault Err Flag
 * --------------------------------------------------------------------------
 *
 \*===========================================================================*/
uint8_t Get_MMIC_Daq_Over_Flow_Err(void)
{
   return (MMIC_Daq_Over_Flow_Err_Flag);
}
/*===========================================================================*\
 * FUNCTION: MMIC_Daq_Cal_Min_Max_Time
 *===========================================================================
 * RETURN VALUE:
 *   void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function calculates Min & Max Daq time WRT look type
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void MMIC_Daq_Cal_Min_Max_Time(void)
{
   uint8_t cnt;

   for (cnt = 0U; cnt < NUM_LOOKS; cnt++)
   {
      MMIC_Daq_Max_Time[cnt] =
         (uint32_t)((k_frame_dwell_ms_smc[cnt] + (k_frame_dwell_ms_smc[cnt] * MMIC_DAQ_OVER_FLOW_TOLERANCE)) * MS_2_US);
      MMIC_Daq_Min_Time[cnt] =
         (uint32_t)((k_frame_dwell_ms_smc[cnt] - (k_frame_dwell_ms_smc[cnt] * MMIC_DAQ_OVER_FLOW_TOLERANCE)) * MS_2_US);
   }
}

/*===========================================================================*\
 * FUNCTION: Update_MMIC_Reinit_Request
 *===========================================================================
 * RETURN VALUE:
 *   void
 *
 * PARAMETERS:
 *    uint8_t
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function sets the MMIC Reinitialization Request flag in Radar Data Status Payload
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Update_MMIC_Reinit_Request(uint8_t request_flag)
{
   Radar_Data_Status.radar_data_status_payload.MMIC_Reinit_Request = request_flag;
}
/*===========================================================================*\
* FUNCTION: Update_API_Fault_Status
 *===========================================================================
 * RETURN VALUE:
 * API_Fault_Type_T fault_type
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:Updates the API fault status based on the fault type
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

static void Update_API_Fault_Status(API_Fault_Type_T fault_type)
{
   switch (fault_type)
   {
      case API_FAULT_LOOK_CONFIG:
         // Set platform active fault table for MMIC Look Config Error
         MMIC_API_Failure_Status[API_FAULT_LOOK_CONFIG] = CODED_TRUE;
         break;
      case API_FAULT_LOOK_TRIGGER:
         // Set platform active fault table for MMIC Look Trigger Error
         MMIC_API_Failure_Status[API_FAULT_LOOK_TRIGGER] = CODED_TRUE;
         break;
      case API_FAULT_LOOK_COMPLETE:
         // Set platform active fault table for MMIC Look Complete Error
         MMIC_API_Failure_Status[API_FAULT_LOOK_COMPLETE] = CODED_TRUE;
         break;

      default:
         return;
   }

   // MARS RESET
   Set_MMIC_Error_Reinit(REINIT_ERROR_API_RETURN_VAL_FAULT);
   // Clear API Look Fault Status counters
   Clr_MMIC_API_Look_Fault_Status();
}
/*===========================================================================*\
* FUNCTION: Validate_MMIC_Error_Reinit_Count
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: On occurence of  three API faults, this function will clear the MMIC reinit error count
 *
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

void Validate_MMIC_Error_Reinit_Count(void)
{
   if ((E_OK == (API_Look_Config_Error | API_Look_Trigger_Error | API_Look_Complete_Error)) && (!MMIC_Error.reinit_error))
   {
      Clr_MMIC_Reinit_Error_Count();
   }
}
/*===========================================================================*\
 * FUNCTION: Update_Dwell_Timestamps
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function populates the sensor's start, middle, and end of dwell
 * It is important this function is only called once per frame, as it
 * decrements counters inside EcuSync which are used for array indices
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Update_Dwell_Timestamps(void)
{
   GLOB_TS_STRUCT_TYPE *timestamp_start;
   GLOB_TS_STRUCT_TYPE *timestamp_end;
   GLOB_TS_STRUCT_TYPE timestamp_mid;
   //   MMIC_Stream_T *stream_ptr;
   //   stream_ptr                                                      = &MMIC_Stream;
   timestamp_start                                                 = GetGlobalTimestamp(TS_START_ACQ);
   Radar_Data_Status.radar_data_status_payload.start_dwell_sec     = timestamp_start->ts_secs;
   Radar_Data_Status.radar_data_status_payload.start_dwell_nanosec = timestamp_start->ts_nanosecs;
   Radar_Data_Status.radar_data_status_payload.start_dwell_status  = timestamp_start->ts_status;
   timestamp_end                                                   = GetGlobalTimestamp(TS_LOOK_COMP);
   Radar_Data_Status.radar_data_status_payload.end_dwell_sec       = timestamp_end->ts_secs;
   Radar_Data_Status.radar_data_status_payload.end_dwell_nanosec   = timestamp_end->ts_nanosecs;
   Radar_Data_Status.radar_data_status_payload.end_dwell_status    = timestamp_end->ts_status;
   (void)GetMidTimeStamps(timestamp_end, timestamp_start, &timestamp_mid, &Sensor_Dwell_Time_Duration_Ns);
   Radar_Data_Status.radar_data_status_payload.mid_dwell_nanosec = timestamp_mid.ts_nanosecs;
   Radar_Data_Status.radar_data_status_payload.mid_dwell_sec     = timestamp_mid.ts_secs;
   Radar_Data_Status.radar_data_status_payload.mid_dwell_status  = Radar_Data_Status.radar_data_status_payload.start_dwell_status;
#if MIDDLE_OF_DWELL_TEST
   static bool skip_first_look = true;
   if (!skip_first_look)
   {
      Mid_To_Mid =
         (timestamp_mid.ts_secs * S_2_NS + timestamp_mid.ts_nanosecs) - (Mid_Prev.ts_secs * S_2_NS + Mid_Prev.ts_nanosecs);
      if (Mid_To_Mid > Mid_To_Mid_Max)
      {
         Mid_To_Mid_Max = Mid_To_Mid;
      }
      else if (Mid_To_Mid < Mid_To_Mid_Min)
      {
         Mid_To_Mid_Min = Mid_To_Mid;
      }
      else
      {
         /* Do Nothing*/
      }
   }
   Mid_Prev        = timestamp_mid;
   skip_first_look = false;

#endif
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Low_Temperature_Fault
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *  Low Temperature Fault - true, No Fault - false
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: This function returns the Low Tempearture Fault of PVT
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_Low_Temperature_Fault(void)
{
   return (MMIC_Low_Temp_Fault);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_High_Temperature_Fault
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *  High Temperature Fault - true, No Fault - false
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: This function returns the High Tempearture Fault of PVT
 *
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_High_Temperature_Fault(void)
{
   return (MMIC_High_Temp_Fault);
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Apr-2025  ftoobg   EPB-3607: [Gen8] [SWE3] Data discard for the RFE faults - Implementation
 * 17-Jul-2025  ftoobg   EPB-3903: [Gen8][SWE3][R3.0] Use Case: Request Safe Start up: Transceiver and peripheral initialization
 and failure
 * 21-Jul-2025  qjgws1   EPB-3944: Bring in the mars reset mechanism from tiger team branch temporarily
 * 22-Jul-2025  jjrfgz   EPB-3984: TICS Coding Standard Improvement
 * 20-Aug-2025  ftoobg   EPB-4023: [GEN8]Implement Function Config Fault & Validate
 * 21-Aug-2025  ftoobg   EPB-3958: [Gen8][R3.0] Code flow check (API return values and sequence check)
 * 11-oct-2025  njsfs0   EPB-4224: [Gen8] MMIC DAQ Over Flow Fault Implementation
 * 20-Jan-2026  ftoobg   EPB-3952: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 29-Dec-2025  ftoobg   EPB-4264: [Gen8][SWE3]MARS safety: API return value handling
 * 29-Jan-2026  ftoobg   EPB-4354: [GEN8][CRD][SWE3] Provide Timestamp for Start of Acquisition
 * 12-Feb-2026  djdgwr   EPB-4387: Updated the functions related to Config error inside the MMIC_Config_Look function to inject
                                   faults using XCP F1 12
 * 18-Feb-2026  djdgwr   EPB-4459: [GEN8][SWE3] Implement & Integration of MIPI Diagnostic function
 * 23-Feb-2026  ftoobg   EPB-4461: [GNE8]Bring Radar Control SM changes similar to GEN7_V2/GEN7_V1 into GEN8 variant
 * 23-Feb-2026  ftoobg    EPB-4410 [Gen8][SWE6] Mars Safety: MMIC Safety Critical Errors Handling
 * 05-Feb-2026  djdgwr   EPB-4463: [GEN8][SWE3][R5.0]Implementation- Handling Sft_Mon_Reg and ERROR PIN
 * 09-Mar-2026  djdgwr   EPB-4391: [GEN8][SWE3_Implementation]-Common Function for Fault Injection
 * 10-Mar-2026  djdgwr   EPB-4477: [GEN8][SWE3][R5.0]Check the MIPI Return Value-added the XCP_FIT variable inside the
 *                                  MMIC_INIT_RETRY_COUNT, added MMIC_ID FIT in the common fault injection function
 * 16-Mar-2026  ftoobg   EPB-4434: [Gen8]Function names as per v2 in Gen8
 * 15-Apr-2026  djdgwr   EPB-4643: [Gen8][SWE3][R6.0]- Fix Level 1 to 4 warnings in dd_mmic.c and F1 12 Cmd Improvements.
 * 23-Apr-2026  njsfso   EPB-4549: [GEN8][SWE3][R6.0]- CRC computaion for radar data status.
 * 06-May-2026  njsfs0   EPB-4686: [GEN8][SWE3][R6.0] -Data Acq threshould changes and related code changes
 * 07-May-2026  djdgwr   EPB-4662: [Gen8] [SWE_3] [R6.0] -(F1 9B) Phase Rotator Calibration In Manufacturing -Implementation
 * 14-May-2026  ftoobg   EPB-4419:: [Gen8] [SWE3] Use Case: Monitor and report RFE MCU related faults
 * 03-Jun-2026  djdgwr   EPB-4540: [Gen8][SWE3] [R6.0]-High and Low Temperature Fault Decode and mapped to the Active Fault Table.
 * 01-Jun-2026  njsfs0   EPB-4612: [Gen8] Start and stop time are made zero to avoid false positive
 * 09-Jul-2026  ftoobg   EPB-4770: [Gen8] [R7][SWE3] Use Case: Thermal management and Fault Handling- New strategy (MARS)
 * 09-Jul-2026  djdgwr   EPB-4868: [Gen8] [R7][SWE3]: Added Daq data as part of the mmic stream.
 * 18-Aug-2026  jjrfgz   EPB-4864: [Gen8]BIST Application level FIT case updated
 \*===========================================================================*/
