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
 *             File:  SWC_PLT_CDD_Radar_Control.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_Radar_Control
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_Radar_Control>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Idt_XCP_Op_Mode_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_Radar_Control.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Os.h"
#include "Uart.h"
#include "dd_gpt.h"
#include "dd_mipi.h"
#include "dd_mmic.h"
#include "dsp_setup.h"
#include "mcal_init.h"
#include "mipi_wrapper.h"
#include "mmic_error.h"
#include "mmic_interface.h"
#include "mmic_stream.h"
#include "radar_ctl.h"
#include "radar_data.h"
#include "reuse.h"
#include <cstring>
#undef RTE_APPLICATION_HEADER_FILE
/*===========================================================================*\

 * Exported preprocessor #define constants (object-like macros)
\*===========================================================================*/
/*===========================================================================*
 * Local/User Commands  Preprocessor #define Constants
 *===========================================================================*/
#define RFBIST_COMPLETE_TIMEOUT (11U)

/* define number of mmic for NXP */
#define SAF_NUM_MMICS (1)

/*Macros for Fake Fault Injection F1 12 */
#define ACQ_OVERFLOW_FAILURE     0x01
#define MMIC_TEMPERATURE_FAILURE 0x02
#define MMIC_SENSOR_DEAD_FAILURE 0X03
/*Startup Failure tagged to MMIC ID Negative FIT*/
#define MMIC_SYSTEM_STARTUP_FAILURE  0x05
#define MMIC_UNDER_TEMP_FAILURE      0X07
#define MMIC_OVER_TEMP_FAILURE       0X08
#define MMIC_ID_FAILURE              0x09
#define MMIC_FUNCTION_CONFIG_FAILURE 0x10

#define ACQ_OVERFLOW_MIN 0x01
#define ACQ_OVERFLOW_MAX 0x02
#define NO_ACQ_OVERFLOW  0x03

#define MMIC_TEMP_DEGRADED 0x01
#define MMIC_TEMP_IDLE     0x02
#define MMIC_TEMP_NORMAL   0x03

#define MMIC_INJECT_FAULT 0x01
#define MMIC_REMOVE_FAULT 0x02

#define WDG_START_SEID 0x01
#define WDG_END_SEID   0x08

#define RADIATION_ON_MEASURE_ENABLE (0U)

/*===========================================================================*\
    * Exported type declarations (enum, struct, union, typedef)
   \*===========================================================================*/
typedef struct FIT_Info_Tag
{
   uint8_t failure_type;
   uint8_t injection_ctrl;
   XCP_MMIC_FIT_Enable_T fit_mode;
   uint8_t reserved;
} FIT_Info_T;
/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/
// This is defined in the radar_ctl.c file. MMIC_Helper_Function is to be moved there.
extern int32_t Offline_Data_Mode_Enabled_Counter;
extern bool Stream_Handler_Init_Flag;
uint32_t DSP_Skipped_Frame                       = 0U;
volatile uint8_t DSP_Skipped_Frame_Error_Counter = 0U;
/*TO DO - Define it local once the RTE is available*/
volatile uint8_t xcp_rfbist_calib_mode = 0U;
uint16_t MMIC_Not_Configured_Error     = 0U;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
volatile uint8_t XCP_IsRadiateForced;
volatile uint8_t Command_Radiate_Final;
volatile uint8_t Radar_Core_Status_Stub = 0U;
#endif
#if ((ENABLE_SQT_TEST_STUBS == STD_ON) || (ENABLE_SIT_TEST_STUBS == STD_ON))
void Test_MMIC_Error_Flags_Set(Dt_MMIC_ErrorFlags *MMIC_Errors);
void Disable_Wdg_Supervised_Entities(void);
#endif

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
#if RESI_MODE_ENABLE
   #define MAX_NUMBER_OF_RESI_FRAMES 100
#endif
/*===========================================================================*
 * Local File Scope Variables
 *===========================================================================*/
/* Assigning the different Fault Injection types */
static const FIT_Info_T FIT_Table[] = {
   {ACQ_OVERFLOW_FAILURE, ACQ_OVERFLOW_MIN, XCP_MMIC_DAQ_MIN_TIME_FIT_TEST, 0U},
   {ACQ_OVERFLOW_FAILURE, ACQ_OVERFLOW_MAX, XCP_MMIC_DAQ_MAX_TIME_FIT_TEST, 0U},
   {ACQ_OVERFLOW_FAILURE, NO_ACQ_OVERFLOW, XCP_MMIC_NO_FIT_TEST, 0U},
   {MMIC_TEMPERATURE_FAILURE, MMIC_TEMP_DEGRADED, XCP_MMIC_OT_DEGRADED_FIT_TEST, 0U},
   {MMIC_TEMPERATURE_FAILURE, MMIC_TEMP_IDLE, XCP_MMIC_OT_IDLE_FIT_TEST, 0U},
   {MMIC_TEMPERATURE_FAILURE, MMIC_TEMP_NORMAL, XCP_MMIC_NO_FIT_TEST, 0U},
   {MMIC_SENSOR_DEAD_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST, 0U},
   {MMIC_SENSOR_DEAD_FAILURE, MMIC_REMOVE_FAULT, XCP_MMIC_NO_FIT_TEST, 0U},
   {MMIC_UNDER_TEMP_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_LOW_TEMP_FIT_TEST, 0U},
   {MMIC_UNDER_TEMP_FAILURE, MMIC_REMOVE_FAULT, XCP_MMIC_NO_FIT_TEST, 0U},
   {MMIC_OVER_TEMP_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_OT_FAULTED_FIT_TEST, 0U},
   {MMIC_OVER_TEMP_FAILURE, MMIC_REMOVE_FAULT, XCP_MMIC_NO_FIT_TEST, 0U},
   {MMIC_FUNCTION_CONFIG_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_FUNCTION_CONFIG_FIT_TEST, 0U},
   {MMIC_SYSTEM_STARTUP_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_ID_FIT_NEG_TEST, 0U},
   {MMIC_ID_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_ID_FIT_NEG_TEST, 0U},
   {MMIC_ID_FAILURE, MMIC_INJECT_FAULT, XCP_MMIC_ID_FIT_POS_TEST, 0U},
};

static volatile uint32_t Rdr_Ctrl_Counter = 0U;
static uint8_t Wdg_SE_Dis_Status          = 0xFF;
static uint8_t NVM_Write_Status           = CODED_TRUE;
Dt_Rfe_REC_NREC_Fault Rfe_Nvm_Array;
Dt_Rfe_REC_NREC_Fault MMIC_RFE_Nvm_Data;
#if RESI_MODE_ENABLE
static bool Is_First_Time_Read_To_Load_Printed = true;
char TX_RESI[30];
volatile RESI_State_T RESI_State = RESI_STATE_DEFAULT;
   #if 0
volatile uint8_t Max_Number_Of_Resi_Frames; /*This can be updated outside the scope using XCP*/
static uint16_t Resi_Frame_Processed_Counter = 0;
   #endif
#endif

static volatile bool MIPI_Split_Init;
static uint8_t Test_RE_Radar_Ctl_Look_Trigger;
static volatile uint8_t Test_RE_Radar_Ctl_Look_Complete;

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
FUNC(void, RTE_CODE) Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger(void);
static void MMIC_Diagnostics(void);
static void Update_MMIC_XCP_CW_Mode_Cmd(void);
static void Update_MMIC_Phase_Rotator_Calib_Mode(void);
static void Handle_Wdg_SE_with_RadarState(uint8 RadarDisable_Req);
static void Update_XCP_RFBIST_Calib_Mode(void);

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
extern uint8_t *Get_XCP_Transceiver_Calib_Trigger(void);
/*===========================================================================*\

 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/
#if RESI_MODE_ENABLE
typedef enum RESI_State_Tag
{
   RESI_STATE_DEFAULT          = 0,
   RESI_STATE_READY_TO_LOAD    = 0x0000AAAA,
   RESI_STATE_LOADED           = 0x0000BBBB,
   RESI_STATE_CHECK_BBE_READY  = 0x0000CCCC,
   RESI_STATE_READY_TO_TRIGGER = 0x0000DDDD,
   RESI_STATE_TEST_1           = 0x0000EEEE,
   RESI_STATE_TEST             = 0x0000FFFF,
} RESI_State_T;
#endif

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
 * boolean: Boolean (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_ECU_ResetReasonType: Enumeration of integer in interval [0...65535] with enumerators
 * Dt_Nv_Caller_ID: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID (0U)
 *   CDD_FAIL_SAFE (1U)
 *   CDD_ESM (2U)
 *   APPL_DIAG (3U)
 *   CDD_ALIGNMENT (4U)
 *   DYNAMIC_ALIGNMENT (5U)
 *   RFE_R1R2_FAULT (6U)
 *   CDD_FAILSAFE_ECC (7U)
 * Idt_XCP_Op_Mode_T: Enumeration of integer in interval [0...255] with enumerators
 *   XCP_OP_MODE_NORMAL (1U)
 *   XCP_OP_MODE_MANF (2U)
 * Rte_DT_Dt_RadarCoreStatus_0: Enumeration of integer in interval [0...255] with enumerators
 *   RADAR_NOT_STARTED (0U)
 *   BUSY_RadarInitStatus (1U)
 *   RADAR_SUCCESS (2U)
 *   RADAR_INITIALIZATION_FAIL (3U)
 * Rte_DT_Dt_RadarCoreStatus_3: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   RADAR_INIT (1U)
 *   ERROR_RECOVERY (2U)
 *   FULLY_OPERATIONAL (3U)
 *   FAULTY (4U)
 *   ENVIRONMENTAL_DEGRADED (5U)
 *   TEMPERATURE_DEGRADED (6U)
 *   MANUFACTURING_MODE (7U)
 *
 * Record Types:
 * =============
 * Dt_MMIC_ErrorFlags: Record with elements
 *   temperature_max_err of type uint8
 *   chirp_pll_err of type uint8
 *   tx0_ball_brk_err of type uint8
 *   tx1_ball_brk_err of type uint8
 *   tx2_ball_brk_err of type uint8
 *   tx3_ball_brk_err of type uint8
 *   sensor_dead_err of type uint8
 *   safety_intergrity_err of type uint8
 *   MMIC_TemperatureLowFault of type uint8
 *   MMIC_SafeStartUp_Error of type uint8
 *   MMIC_Transmitter_ID_Fault of type uint8
 *   RF_BallBreak of type uint8
 *   MMIC_Loop_Back_Test_Fault of type uint8
 *   Data_Acquisition_err of type uint8
 *   RFE_Freq_Monitor_err of type uint8
 *   RFE_Power_Level_err of type uint8
 *   RFE_Lock_Step_err of type uint8
 *   RFE_CPU_err of type uint8
 *   RFE_Voltage_err of type uint8
 *   RFE_TX_RFBIST_err of type uint8
 *   RFE_RX_RFBIST_err of type uint8
 *   MMIC_Error_Recovery_Failure of type uint8
 *   MMIC_Id_Unprogrammed_Error of type uint8
 *   MMIC_Secondary_Clock_Fault of type uint8
 *   API_Look_Config_err of type uint8
 *   API_Look_Complete_err of type uint8
 *   API_Look_Trigger_err of type uint8
 *   MMIC_RFE_MCU_Fault of type uint8
 *   MMIC_RFE_Par_Redun_Fault of type uint8
 *   MMIC_RFE_PLL_Lock_Fault of type uint8
 *   MMIC_Sec_Thermal_monitoring_flt of type uint8
 *   MMIC_Secondary_MIPI_Fault of type uint8
 *   MMIC_Secondary_Register_Fault of type uint8
 *   MMIC_Secondary_MCU_Fault of type uint8
 * Dt_RadarCoreStatus: Record with elements
 *   RadarInitializatonStatus of type Rte_DT_Dt_RadarCoreStatus_0
 *   RadarReInitRequired of type uint8
 *   IsRadiating of type uint8
 *   OperationMode_Radar of type Rte_DT_Dt_RadarCoreStatus_3
 * Dt_Rfe_REC_NREC_Fault: Record with elements
 *   CORE_BANK_SFT_ERR_MON of type uint32
 *   CORE_BANK_SFT_ERR_STATUS of type uint32
 *   CORE_BANK_MCU_STS_MCU_MSSG of type uint32
 *   FUSA_IRQ0_FLAG_R of type uint32
 *   FUSA_IRQ1_FLAG_R of type uint32
 *   FUSA_IRQ2_FLAG_R of type uint32
 *   Api_ret_val of type uint32
 *   LOGEN_BANK_CHRP_GEN_ERROR of type uint32
 *   LOGEN_BANK_LOGEN_ERROR of type uint32
 *   CPU_SYS_MCU_ERR_0 of type uint32
 *   CPU_SYS_MCU_ERR_1 of type uint32
 *   CPU_SYS_MCU_ERR_2 of type uint32
 *   CPU_SYS_MCU_ERR_3 of type uint32
 *   ASYNC_BANK_ASYNC_ERR1 of type uint32
 *   PROF_BANK_PRF_ERR1 of type uint32
 *   PROF_BANK_PRF_ERR2 of type uint32
 *   RXADC_FUSAMON of type uint32
 *   maf_status of type uint8
 * Idt_Type_MMIC_Temperature: Record with elements
 *   MMIC_TX0_Temp of type sint16
 *   MMIC_TX1_Temp of type sint16
 *   MMIC_TX2_Temp of type sint16
 *   MMIC_TX3_Temp of type sint16
 *   MMIC_RX0_Temp of type sint16
 *   MMIC_PVT_Temp of type sint16
 *   MMIC_Quad_Temp of type sint16
 * Idt_XCP_Single_Look_T: Record with elements
 *   single_look_en of type uint8
 *   single_look_select of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_Radar_Control_START_SEC_CODE
#include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Function Name: Select_Fault_Injection_Mode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Purpose:
 *   - Map the requested fault type/control pair onto the corresponding MMIC FIT mode so that the
 *     diagnostic script can drive the intended behavior.
 *
 **********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Select_Fault_Injection_Mode_doc
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
static XCP_MMIC_FIT_Enable_T Select_Fault_Injection_Mode(const uint8_t failure_type, const uint8_t injection_ctrl)
{
   uint16_t idx;
   XCP_MMIC_FIT_Enable_T result = XCP_MMIC_NO_FIT_TEST;
   const FIT_Info_T *ptr        = &FIT_Table[0];

   for (idx = 0U; idx < NUM_ELEMS(FIT_Table); idx++)
   {
      if ((ptr[idx].failure_type == failure_type) && (ptr[idx].injection_ctrl == injection_ctrl))
      {
         result = ptr[idx].fit_mode;
         break;
      }
   }

   return result;
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Radar_control_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Radar_control_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Radar_control_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Radar_control_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE)
CS_Radar_control_Fault_Injection_Read(uint8 Injection_control,
                                      uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Radar_control_Fault_Injection_Read
    *********************************************************************************************************************/

   /*For sys-Domain (0x06 - Radar-core2) implementation as per WI-359416*/
   /*For sys-Domain (0x05 - Radar-core1) implementation as per WI-367336,WI-367334,WI-367335,WI-367336*/
   XCP_MMIC_FIT_Enable = Select_Fault_Injection_Mode(Failure_Type, Injection_control);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Control_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Control_10ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Control_10ms
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Control_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Op_Mode_De_XCP_Op_Mode(Idt_XCP_Op_Mode_T *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(boolean *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(Idt_XCP_Single_Look_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(const Dt_Rfe_REC_NREC_Fault *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation(uint8 disable_SE_Flag)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_FailSafe_Log_ResetReason_FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Control_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Control_50ms
    *********************************************************************************************************************/

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
   Disable_Wdg_Supervised_Entities();
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Control_Init
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
 *   Std_ReturnType Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(Dt_Rfe_REC_NREC_Fault *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Control_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Control_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Control_Init
    *********************************************************************************************************************/

   Put_Radar_Radiate_Enable(true);
   Radar_Ctl_Reset_Init();
   /* Cancel Post-RFBIST first activation done by RTE */
   (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST);
#if RESI_MODE_ENABLE
   // Max_Number_Of_Resi_Frames = MAX_NUMBER_OF_RESI_FRAMES;
   Initialize_Frame_Start_Output_Gpio();
   RESI_State = STATE_READY_TO_LOAD;
#endif
   Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data(&MMIC_RFE_Nvm_Data);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Ctl_Look_Complete
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by ExternalTriggerOccurredEvent of PortPrototype <Rp_Radar_Ctl_Look_Complete>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_IsRadiateForced_De_IsRadiateForced(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_MMIC_Count_De_MMIC_Count(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_MMIC_Temperature_De_MMIC_Temperature(const Idt_Type_MMIC_Temperature *data)
 *   Std_ReturnType Rte_Write_Pp_Radar_Init_Status_De_Radar_Init_Status(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Ctl_Look_Complete_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Ctl_Look_Complete(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Ctl_Look_Complete
    *********************************************************************************************************************/

   Test_RE_Radar_Ctl_Look_Complete++;
   (void)SetRelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST, RFBIST_COMPLETE_TIMEOUT,
                     RFBIST_COMPLETE_TIMEOUT);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Ctl_Look_Complete_Post_RFBIST
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Ctl_Look_Complete_Post_RFBIST_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE)
RE_Radar_Ctl_Look_Complete_Post_RFBIST(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Ctl_Look_Complete_Post_RFBIST
    *********************************************************************************************************************/
   (void)CancelAlarm(Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST);
#ifndef RESI_MODE_ENABLE
   Radar_Ctl_Look_Complete();
#endif

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   (void)Rte_Read_Rp_IsRadiateForced_De_IsRadiateForced(&XCP_IsRadiateForced);
   (void)Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final(&Command_Radiate_Final);
   if (1 == Radar_Core_Status_Stub)
   {
      Radar_Core_Status.RadarInitializatonStatus = RADAR_SUCCESS;
      Radar_Core_Status.RadarReInitRequired      = CODED_TRUE;
   }
   else
   {
      Radar_Core_Status.RadarInitializatonStatus = RADAR_NOT_STARTED;
      Radar_Core_Status.RadarReInitRequired      = CODED_FALSE;
   }
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Radar_Ctl_Look_Trigger
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Pp_Radar_Ctl_Look_Trigger>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(const Dt_MMIC_ErrorFlags *data)
 *   Std_ReturnType Rte_Write_Pp_RadarCoreStatus_De_RadarCoreStatus(const Dt_RadarCoreStatus *data)
 *   Std_ReturnType Rte_Write_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Radar_Init_Status_De_Radar_Init_Status(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM(uint8 u8_ImmidieteWrite,
 *Dt_Nv_Caller_ID dt_Nv_Caller_Id) Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_Radar_Ctl_Look_Trigger(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Radar_Ctl_Look_Trigger_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Radar_Ctl_Look_Trigger(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Radar_Ctl_Look_Trigger
    *********************************************************************************************************************/

   uint8_t Command_Radiate_Final;
   Test_RE_Radar_Ctl_Look_Trigger++;
   /* volatile uint32_t udp_periodic_go = 0;  TODO:Unused variable needs a review */
   static uint32_t wait_for_5cycles = 0;
   static bool check_rdi_connection = 0;
   static bool send_periodic_stream = 0;

   check_rdi_connection = Get_RDI_Log_Board_Connected();

   if (check_rdi_connection == true)
   {
      if ((1 == MIPI_Split_Init) || (Timestamp_Seconds >= 10))
      {
         send_periodic_stream = true;
      }
   }
   else
   {
      send_periodic_stream = true;
   }

   if (send_periodic_stream)
   {
      if (Stream_Handler_Init_Flag && (wait_for_5cycles > 5))
      {
         Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream();
         Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream();

         /* Transmitting MMIC and Header stream in Radar radiation disabled for debugging */
         if ((!Get_Radar_Radiate_Enable()) || (RADAR_CTL_FAULTED == Radar_Ctl_State) || (RADAR_CTL_OFF == Radar_Ctl_State))
         {
            Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream();
            Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream();
         }
      }
      else
      {
         /* TODO: Wait 5 cycles for Ethernet to be initialized and running - 5 is Random, Need to add proper API to get the Eth
          * status*/
         wait_for_5cycles++;
      }
   }
   (void)Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final(&Command_Radiate_Final);
   if (CODED_TRUE == Command_Radiate_Final)
   {
#if RADIATION_ON_MEASURE_ENABLE
      IOCTRL->GPIO_11.f.FUNC_SEL = 0x0; /* DIO Mode */
      IOCTRL->GPIO_11.f.IE       = 1;   /* Output so IE buffer not needed */
      IOCTRL->GPIO_11.f.DS       = 0;
      IOCTRL->GPIO_11.f.ST       = 0;
      IOCTRL->GPIO_11.f.PE       = 0;
      IOCTRL->GPIO_11.f.PS       = 0;
      GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x08; /* As Output */
      GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x08u;
#endif
      Put_Radar_Radiate_Enable(true);
      /* Request to enable Wdg SE */
      Handle_Wdg_SE_with_RadarState(false);
   }
   else
   {
      Put_Radar_Radiate_Enable(false);
      /* Request to Disable Wdg SE */
      Handle_Wdg_SE_with_RadarState(true);
   }
   Update_XCP_RFBIST_Calib_Mode();

   Update_MMIC_XCP_CW_Mode_Cmd();

   Update_MMIC_Phase_Rotator_Calib_Mode();

#if RESI_MODE_ENABLE
   MMIC_Resi_Helper_Function();
#else
   MMIC_Helper_Function();
#endif
   Rdr_Ctrl_Counter++;

   if (Is_Triggered_Once && (0 == MIPI_Split_Init))
   {
      MIPI_Split_Init = 1;
      if (check_rdi_connection)
      {
         (void)Deassert_Reset_Mipi();
      }
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Test
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PostRadarProcessing_ADC_Populate_ADC_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream(void)
 *     Asynchronous Server Invocation
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Test_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_Radar_Control_CODE) RE_Test(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Test
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_Radar_Control_STOP_SEC_CODE
#include "SWC_PLT_CDD_Radar_Control_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if RESI_MODE_ENABLE
void MMIC_Resi_Helper_Function(void)
{
   bool enable_debug_mode = (Offline_Mode_Flag == ITF_ADC_INJECTION_MODE);
   switch (RESI_State)
   {
      case STATE_READY_TO_LOAD:
         if (Is_First_Time_Read_To_Load_Printed)
         {
            strcpy(TX_RESI, "ready_to_load\n");
            Uart_SendData(TX_RESI, sizeof(TX_RESI), 0);
            Is_First_Time_Read_To_Load_Printed = false;
         }
         /*Do nothing here and wait for the external feedback to tell to move state*/
         break;
      case STATE_LOADED:
         strcpy(TX_RESI, "load_acked\n");
         Uart_SendData(TX_RESI, sizeof(TX_RESI), 0);
         RESI_State = STATE_CHECK_BBE_READY;
         break;
      case STATE_CHECK_BBE_READY:
         if (DSP_Done_Processing())
         {
            RESI_State = STATE_READY_TO_TRIGGER;
            MMIC_Reset_MIPI();
            MIPI_Disable();
         }
         else
         {
            DSP_Skipped_Frame++;
         }
         break;
      case STATE_READY_TO_TRIGGER:
         DSP_Processing_Per_Look_Init();
         MMIC_Config_MIPI(enable_debug_mode);
         Trigger_Frame_Start_To_Resi();
         RESI_Mode_Put_Next_Look();
         RESI_State = STATE_READY_TO_LOAD;
         // Resi_Frame_Processed_Counter++;
         // if (Resi_Frame_Processed_Counter <= Max_Number_Of_Resi_Frames)
         // {
         //    RESI_State = STATE_CHECK_BBE_READY;
         // }
         // else /*Removing this since it is only one frame at a time due to RESI limitation */
         // {

         // Resi_Frame_Processed_Counter = 0;
         // }
         Is_First_Time_Read_To_Load_Printed = true;
         break;
      default:
         // Error state or reset
         break;
   }
}
#endif

void MMIC_Helper_Function(void)
{
   Radar_Ctl_State_T radar_ctl_state = Get_Radar_Ctl_State();
   if ((radar_ctl_state != RADAR_CTL_CONFIGURED) && (radar_ctl_state != RADAR_CTL_TRANSMITTING) &&
       (radar_ctl_state != RADAR_CTL_PURE_CW))
   {
      Radar_Ctl_Periodic();
      MMIC_Diagnostics();
      MMIC_Not_Configured_Error++;
   }
   else if (Run_DSP_Interaction_State_Machine())
   {
      DSP_Skipped_Frame_Error_Counter = 0;

      if (ITF_ADC_INJECTION_MODE == Offline_Mode_Flag)
      {
         MIPI_Debugmode_Enable();
         MIPI_Enable();
         Offline_Data_Mode_Enabled_Counter++;
      }
      else
      {
         Radar_Ctl_Look_Trigger();
         Radar_Ctl_Periodic();
         MMIC_Diagnostics();
      }
   }
   else
   {
      DSP_Skipped_Frame++;
      DSP_Skipped_Frame_Error_Counter++;
   }

   /* ADC Unit - 5 Sec before deasserting the MIPI Lines
      Reset the error counters*/
   if (MIPI_Split_Init == 0)
   {
      DSP_Skipped_Frame_Error_Counter = 0;
   }
   else
   {
      if (DSP_Skipped_Frame_Error_Counter >= 2)
      {
         Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream();
         Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream();
         Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream();
         Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
      }
   }
}
void Rfe_Nvm_Read(MMIC_Data_Logging_T *MMIC_Data_Ptr)
{
   if (NULL_PTR != MMIC_Data_Ptr)
   {
      MMIC_Data_Ptr->NVM_Data_Read.CORE_BANK_SFT_ERR_MON      = MMIC_RFE_Nvm_Data.CORE_BANK_SFT_ERR_MON;
      MMIC_Data_Ptr->NVM_Data_Read.CORE_BANK_SFT_ERR_STATUS   = MMIC_RFE_Nvm_Data.CORE_BANK_SFT_ERR_STATUS;
      MMIC_Data_Ptr->NVM_Data_Read.CORE_BANK_MCU_STS_MCU_MSSG = MMIC_RFE_Nvm_Data.CORE_BANK_MCU_STS_MCU_MSSG;
      MMIC_Data_Ptr->NVM_Data_Read.FUSA_IRQ0_FLAG_R           = MMIC_RFE_Nvm_Data.FUSA_IRQ0_FLAG_R;
      MMIC_Data_Ptr->NVM_Data_Read.FUSA_IRQ1_FLAG_R           = MMIC_RFE_Nvm_Data.FUSA_IRQ1_FLAG_R;
      MMIC_Data_Ptr->NVM_Data_Read.FUSA_IRQ2_FLAG_R           = MMIC_RFE_Nvm_Data.FUSA_IRQ2_FLAG_R;
      MMIC_Data_Ptr->NVM_Data_Read.Api_ret_val                = MMIC_RFE_Nvm_Data.Api_ret_val;
      MMIC_Data_Ptr->NVM_Data_Read.LOGEN_BANK_CHRP_GEN_ERROR  = MMIC_RFE_Nvm_Data.LOGEN_BANK_CHRP_GEN_ERROR;
      MMIC_Data_Ptr->NVM_Data_Read.LOGEN_BANK_LOGEN_ERROR     = MMIC_RFE_Nvm_Data.LOGEN_BANK_LOGEN_ERROR;
      MMIC_Data_Ptr->NVM_Data_Read.CPU_SYS_MCU_ERR_0          = MMIC_RFE_Nvm_Data.CPU_SYS_MCU_ERR_0;
      MMIC_Data_Ptr->NVM_Data_Read.CPU_SYS_MCU_ERR_1          = MMIC_RFE_Nvm_Data.CPU_SYS_MCU_ERR_1;
      MMIC_Data_Ptr->NVM_Data_Read.CPU_SYS_MCU_ERR_2          = MMIC_RFE_Nvm_Data.CPU_SYS_MCU_ERR_2;
      MMIC_Data_Ptr->NVM_Data_Read.CPU_SYS_MCU_ERR_3          = MMIC_RFE_Nvm_Data.CPU_SYS_MCU_ERR_3;
      MMIC_Data_Ptr->NVM_Data_Read.ASYNC_BANK_ASYNC_ERR1      = MMIC_RFE_Nvm_Data.ASYNC_BANK_ASYNC_ERR1;
      MMIC_Data_Ptr->NVM_Data_Read.PROF_BANK_PRF_ERR1         = MMIC_RFE_Nvm_Data.PROF_BANK_PRF_ERR1;
      MMIC_Data_Ptr->NVM_Data_Read.PROF_BANK_PRF_ERR2         = MMIC_RFE_Nvm_Data.PROF_BANK_PRF_ERR2;
      MMIC_Data_Ptr->NVM_Data_Read.RXADC_FUSAMON              = MMIC_RFE_Nvm_Data.RXADC_FUSAMON;
      MMIC_Data_Ptr->NVM_Data_Read.maf_status                 = MMIC_RFE_Nvm_Data.maf_status;
   }
}

void Rfe_Nvm_Write(void)
{
   FuSa_Faults_Union_T *fusa_backup_flt_ptr = Get_Mmic_Fusa_Backup_Fault_Ptr();
   MMIC_Data_Logging_T *MMIC_Data_Ptr       = &(MMIC_Stream.MMIC_Data);
   Rfe_Nvm_Array.CPU_SYS_MCU_ERR_3 =
      ((uint32_t)fusa_backup_flt_ptr->arr_val[0]) | ((uint32_t)fusa_backup_flt_ptr->arr_val[1] << 8) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[2] << 16) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[3] << 24); // MMIC_Data_Ptr->mmic_bist_status.CORE_BANK_SFT_ERR_MON;
   Rfe_Nvm_Array.CORE_BANK_SFT_ERR_STATUS =
      ((uint32_t)fusa_backup_flt_ptr->arr_val[4]) | ((uint32_t)fusa_backup_flt_ptr->arr_val[5] << 8) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[6] << 16) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[7] << 24); // MMIC_Data_Ptr->mmic_bist_status.CORE_BANK_SFT_ERR_STATUS;
   Rfe_Nvm_Array.CORE_BANK_MCU_STS_MCU_MSSG =
      ((uint32_t)fusa_backup_flt_ptr->arr_val[8]) | ((uint32_t)fusa_backup_flt_ptr->arr_val[9] << 8) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[10] << 16) |
      ((uint32_t)fusa_backup_flt_ptr->arr_val[11] << 24); // MMIC_Data_Ptr->mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG;
   Rfe_Nvm_Array.FUSA_IRQ0_FLAG_R          = MMIC_Data_Ptr->MIPI_FuSa_fault_info.mipi_fusa_irq0_reg;
   Rfe_Nvm_Array.FUSA_IRQ1_FLAG_R          = MMIC_Data_Ptr->MIPI_FuSa_fault_info.mipi_fusa_irq1_reg;
   Rfe_Nvm_Array.FUSA_IRQ2_FLAG_R          = MMIC_Data_Ptr->MIPI_FuSa_fault_info.mipi_fusa_irq2_reg;
   Rfe_Nvm_Array.Api_ret_val               = MMIC_Data_Ptr->mmic_bist_api_ret_val;
   Rfe_Nvm_Array.LOGEN_BANK_CHRP_GEN_ERROR = MMIC_Data_Ptr->mmic_bist_status.LOGEN_BANK_CHRP_GEN_ERROR;
   Rfe_Nvm_Array.LOGEN_BANK_LOGEN_ERROR    = MMIC_Data_Ptr->mmic_bist_status.LOGEN_BANK_LOGEN_ERROR;
   Rfe_Nvm_Array.CPU_SYS_MCU_ERR_0         = MMIC_Data_Ptr->mmic_bist_status.CPU_SYS_MCU_ERR_0;
   Rfe_Nvm_Array.CPU_SYS_MCU_ERR_1         = MMIC_Data_Ptr->mmic_bist_status.CPU_SYS_MCU_ERR_1;
   Rfe_Nvm_Array.CPU_SYS_MCU_ERR_2         = MMIC_Data_Ptr->mmic_bist_status.CPU_SYS_MCU_ERR_2;
   Rfe_Nvm_Array.CORE_BANK_SFT_ERR_MON     = MMIC_Data_Ptr->mmic_bist_status.CORE_BANK_SFT_ERR_MON;
   Rfe_Nvm_Array.ASYNC_BANK_ASYNC_ERR1     = MMIC_Data_Ptr->mmic_bist_status.ASYNC_BANK_ASYNC_ERR1;
   Rfe_Nvm_Array.PROF_BANK_PRF_ERR1        = MMIC_Data_Ptr->mmic_bist_status.PROF_BANK_PRF_ERR1;
   Rfe_Nvm_Array.PROF_BANK_PRF_ERR2        = MMIC_Data_Ptr->mmic_bist_status.PROF_BANK_PRF_ERR2;
   Rfe_Nvm_Array.RXADC_FUSAMON             = MMIC_Data_Ptr->mmic_bist_status.RXADC_FUSAMON;
   Rfe_Nvm_Array.maf_status                = MMIC_Data_Ptr->mmic_bist_status.maf_status;
   (void)Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data(&Rfe_Nvm_Array);
   /*Trigger NVM write handler*/
   (void)Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM(CODED_FALSE, 6U);
}
void MMIC_Diagnostics(void)
{
   Dt_MMIC_ErrorFlags MMIC_Errors;
   Idt_Type_MMIC_Temperature MMIC_temp = {0};
   (void)memset(&MMIC_Errors, CODED_FALSE, sizeof(Dt_MMIC_ErrorFlags));

   /* Temperature Error Mapping */
   MMIC_Errors.temperature_max_err      = Get_MMIC_High_Temperature_Fault(); /* Mapping Over Temperature Error */
   MMIC_Errors.MMIC_TemperatureLowFault = Get_MMIC_Low_Temperature_Fault();
   /* Mapping Data Acquisition Error */
   MMIC_Errors.Data_Acquisition_err = Get_MMIC_Daq_Over_Flow_Err();
   /*Mapping MIPI CSI2 Fault(this is Secondary Fault)*/
   MMIC_Errors.MMIC_Secondary_MIPI_Fault = Get_MIPI_Fault();

   if ((Get_MMIC_Faulted() == true))
   {
      MMIC_Errors.MMIC_Error_Recovery_Failure = CODED_TRUE;
   }
   /*Fetching the error data from MMIC Driver*/
   MMIC_Errors.MMIC_SafeStartUp_Error = Get_MMIC_System_Start_Fault();

   /* Tranmsitter Id Fault mapping */
   MMIC_Errors.MMIC_Transmitter_ID_Fault = Get_Tx_Id_Fault();
   /* sensor dead fault */
   MMIC_Errors.sensor_dead_err = Get_MMIC_Sensor_Dead_Fault(); // FuSa faults to be enabled . To allow the state machine to run
   /* API failure Status*/
   MMIC_Errors.API_Look_Config_err   = Get_MMIC_API_Fault(API_FAULT_LOOK_CONFIG);
   MMIC_Errors.API_Look_Trigger_err  = Get_MMIC_API_Fault(API_FAULT_LOOK_TRIGGER);
   MMIC_Errors.API_Look_Complete_err = Get_MMIC_API_Fault(API_FAULT_LOOK_COMPLETE);
   if (CODED_TRUE == MMIC_Errors.sensor_dead_err)
   {
      MMIC_Errors.RFE_TX_RFBIST_err = Get_MMIC_Secondary_Fault(MMIC_Secondary_TX_RFBIST_Fault);
      MMIC_Errors.RFE_RX_RFBIST_err = Get_MMIC_Secondary_Fault(MMIC_Secondary_RX_RFBIST_Fault);
   }

   if (CODED_TRUE == MMIC_Errors.MMIC_Error_Recovery_Failure)
   {
      MMIC_Errors.MMIC_Secondary_Clock_Fault    = Get_MMIC_Secondary_Fault(MMIC_Secondary_Clock_Fault);
      MMIC_Errors.MMIC_Secondary_MCU_Fault      = Get_MMIC_Secondary_Fault(MMIC_Secondary_MCU_Fault);
      MMIC_Errors.MMIC_Secondary_Register_Fault = Get_MMIC_Secondary_Fault(MMIC_Secondary_Register_Fault);
   }

   MMIC_temp.MMIC_TX0_Temp  = Get_MMIC_Temp_Tx0();
   MMIC_temp.MMIC_TX1_Temp  = Get_MMIC_Temp_Tx1();
   MMIC_temp.MMIC_TX2_Temp  = Get_MMIC_Temp_Tx2();
   MMIC_temp.MMIC_TX3_Temp  = Get_MMIC_Temp_Tx3();
   MMIC_temp.MMIC_PVT_Temp  = Get_MMIC_Temp_PVT();
   MMIC_temp.MMIC_RX0_Temp  = Get_MMIC_Temp_Rx0();
   MMIC_temp.MMIC_Quad_Temp = Get_MMIC_Temp_QUAD(); /* Rte write for MMIC Temperature */
   (void)Rte_Write_Pp_MMIC_Temperature_De_MMIC_Temperature(&MMIC_temp);
#if ((ENABLE_SQT_TEST_STUBS == STD_ON) || (ENABLE_SIT_TEST_STUBS == STD_ON))
   /* MMIC Errors SQT/SIT function call */
   Test_MMIC_Error_Flags_Set(&MMIC_Errors);
#endif
   /* Rte write for MMIC Error Flags to Diagnostic */
   (void)Rte_Write_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags(&MMIC_Errors);
   (void)Rte_Write_Pp_RadarCoreStatus_De_RadarCoreStatus(&Radar_Core_Status);
   if (((CODED_TRUE == MMIC_Errors.sensor_dead_err) || (CODED_TRUE == MMIC_Errors.MMIC_Error_Recovery_Failure) ||
        (CODED_TRUE == MMIC_Errors.MMIC_SafeStartUp_Error)) &&
       (CODED_TRUE == NVM_Write_Status))
   {
      Rfe_Nvm_Write();
      NVM_Write_Status = CODED_FALSE;
   }
}

/*====================================================================================================================*\
 * FUNCTION: Update_XCP_RFBIST_Calib_Mode
 *=======================================================================================================================
 * RETURN VALUE: void
 *
 * PARAMETERS: void
 *
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------------------------------------------------
 * This function will update the RFBIST Calib mode  from XCP command
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * Traceability:
 * ----------------------------------------------------------------------------------------------------------------------
 *
\*====================================================================================================================*/
static void Update_XCP_RFBIST_Calib_Mode(void)
{
   uint8_t xcp_rfbist_calib_mode = 0U;

   uint8_t *xcp_trigger_rfbist_calibration_ptr = Get_XCP_Transceiver_Calib_Trigger();
   Rte_Read_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(&xcp_rfbist_calib_mode);

   if (1U == xcp_rfbist_calib_mode)
   {
      Put_Mmic_Bist_Calib_Trigger_Mode(true);
      *xcp_trigger_rfbist_calibration_ptr = FALSE;
   }
   else
   {
      /*do nothing*/
   }
}

/*====================================================================================================================*\
 * FUNCTION: Update_MMIC_XCP_CW_Mode_Cmd
 *=======================================================================================================================
 * RETURN VALUE: void
 *
 * PARAMETERS: void
 *
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------------------------------------------------
 * This function will update the MMIC CW mode command to Radar_control_bb
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * Traceability:
 * ----------------------------------------------------------------------------------------------------------------------
 *
\*====================================================================================================================*/
static void Update_MMIC_XCP_CW_Mode_Cmd(void)
{
   uint8_t radar_cw_mode_cmd;
   Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode(&radar_cw_mode_cmd);
   Put_MMIC_CW_Mode_Flag(radar_cw_mode_cmd);
}

/*====================================================================================================================*\
 * FUNCTION: Update_MMIC_Phase_Rotator_Calib_Mode
 *=======================================================================================================================
 * RETURN VALUE: void
 *
 * PARAMETERS: void
 *
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------------------------------------------------
 * This function reads the XCP phase rotator calibration mode command and updates the MMIC phase
 * rotator calibration flag. It enables or disables the phase rotator calibration mode based on the
 * external command received through the RTE interface.
 *
 * PRECONDITIONS:
 * RTE interface for XCP phase rotator calibration must be properly initialized.
 *
 * POSTCONDITIONS:
 * MMIC phase rotator calibration flag is updated with the latest command value.
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * Traceability:
 * ----------------------------------------------------------------------------------------------------------------------
 *
\*====================================================================================================================*/
static void Update_MMIC_Phase_Rotator_Calib_Mode(void)
{
   uint8_t radar_phase_rotator_calib_mode;
   Rte_Read_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(&radar_phase_rotator_calib_mode);
   Put_MMIC_Phase_Rotator_Calib_Flag(radar_phase_rotator_calib_mode);
}

/*====================================================================================================================*\
 * FUNCTION: Handle_Wdg_SE_with_RadarState
 *=======================================================================================================================
 * RETURN VALUE: void
 *
 * PARAMETERS: uint8_t
 *
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ----------------------------------------------------------------------------------------------------------------------
 * In This function is used to disable or Enable wdg SE based on radar state
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 * ----------------------------------------------------------------------------------------------------------------------
 * Traceability:
 * ----------------------------------------------------------------------------------------------------------------------
 *
\*====================================================================================================================*/
void Handle_Wdg_SE_with_RadarState(uint8 RadarDisable_Req)
{
   if ((true == RadarDisable_Req) && (CODED_TRUE != Wdg_SE_Dis_Status))
   {
      /* if Radar Disable is requested and Wdg SE are not disabled then request IntWdg Component to Disable Wdg SE */
      Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation(CODED_TRUE);
      Wdg_SE_Dis_Status = CODED_TRUE;
   }
   else if ((false == RadarDisable_Req) && (RADAR_CTL_INIT_SUCCESS == Get_Radar_Ctl_Init_Status()) &&
            (CODED_FALSE != Wdg_SE_Dis_Status))
   {
      /* Once Radae Init status is Success and Wdg SE are not Enabled then request IntWdg Component to Enable Wdg SE */
      Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation(CODED_FALSE);
      Wdg_SE_Dis_Status = CODED_FALSE;
   }
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/
/***  End of saved code  ************************************************************************************/
#endif
#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Select_Fault_Injection_Mode_doc)  *********************/

/***  End of saved code  ************************************************************************************/
#endif

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
