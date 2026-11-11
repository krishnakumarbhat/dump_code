/*===========================================================================*/
/**
 * @file ipc_mss.c
 *
 * APIs for ipc implementation
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2025 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * API definition for ipc module
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
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 *
 * @defgroup template Provide API description and define/delete next line
 * @ingroup <parent_API> (OPTIONAL USE if part of another API, else delete)
 * @{
 */
/*==========================================================================*/

/*===========================================================================*\
 * Preprocessor #include directive(s) for <standard header files>
\*===========================================================================*/
#include <string.h>

/*===========================================================================*\
 * Preprocessor #include directive(s) for "other header files"
\*===========================================================================*/
#include "FS_IntHndlr.h"
#include "Os.h"
#include "Rte_SWC_PLT_CDD_Radar_Control.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "SWC_PLT_Radar_Alignment_Handler.h"
#include "chandra_sfrs_base.h"
#include "crc_calc.h"
#include "dsp_setup.h"
#include "dsp_sfrs.h"
#include "hil_communication_handler.h"
#include "ipc_mss.h"
#include "mmic_common_types.h"
#include "platformtime.h"
#include "program_flow_monitor.h"
/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "master_it_macros_test.h"

/*===========================================================================*\
 * External function declarations
\*===========================================================================*/
extern FUNC(void, RTE_CODE) Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger(void);
extern FUNC(void, RTE_CODE) Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger(void);
extern FUNC(void, RTE_CODE)
   Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete(void);
extern IPC_MMIC_Radar_Data_Status_T Radar_Data_Status;
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS (object-like MACROS)
\*===========================================================================*/
#define DSP                ((volatile DSP_SFRS_t *)DSP_base)
#define TIME_45MS          (45000U)
#define TIME_55MS          (55000U)
#define MAX_TIMEFAIL_COUNT (100U)
/*===========================================================================*\
 * Local preprocessor #define MACROS() (i.e., those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Global Object Definitions
\*===========================================================================*/
/** IPC buffer for R52 to BBE */
volatile IPC_M2D_Buffers_T __attribute__((aligned(32), used, section(".ipc_r52_to_dsp"))) IPC_M2D_Buffers;

uint32_t Ping_Buf_Addr = 0U; /* Var to store the address of the ping buffer, used for XCP to implement ping-pong */
uint32_t Pong_Buf_Addr = 0U; /* Var to store the address of the pong buffer, used for XCP to implement ping-pong */

/** DSP configuration state variable */
volatile DSP_Config_Type_T DSP_Cfg_Init;
volatile bool DSP_Init = false; /** Signal Processing Init flag*/
volatile bool Received_Doppler_Done;
volatile bool Received_Doppler_Stream = false;

uint32_t M2D_Buffer_Full_Error_Counter = 0U;
/* Pointer to the current IPC D2M buffer*/
D2M_Msg_T *IPC_Dopp_RDD_Comp_Buf_Read_Addr = NULL;
uint8_t IPC_Dopp_RDD_Comp_Buf_Read_idx;
/* Pointer to the validated SP post-processing IPC buffer and its ping-pong index */
D2M_Msg_T *IPC_Sp_Post_Proc_Buf_Read_Addr = NULL;
uint8_t IPC_Sp_Post_Proc_Buf_Read_Idx     = 0U;

#ifndef UNIT_TEST
/** IPC M2D error counter*/
volatile uint32_t IPC_M2D_Crc_Err_Cnt = 0U;
/** IPC D2M error counter*/
volatile uint32_t IPC_D2M_Crc_Err_Cnt = 0U;
#endif
#ifdef XCP_FAULT_INJECTION
volatile static uint8_t Ipc_Xcp_Fault_Injn_Var = NO_Fault;
#endif

#ifdef ENABLE_IPC_CRC_PROFILING
uint32_t M2D_CRC_Compute_Time_us              = 0U;
uint32_t D2M_CRC_Compute_Time_us              = 0U;
volatile uint32_t M2D_CRC_Compute_Time_Max_us = 0U;
volatile uint32_t M2D_CRC_Compute_Time_Min_us = UINT32_MAX;
volatile uint32_t D2M_CRC_Compute_Time_Max_us = 0U;
volatile uint32_t D2M_CRC_Compute_Time_Min_us = UINT32_MAX;
#endif

#ifdef CDC_ENABLE
volatile uint32_t Cdc_Frame_Interface_Addr;
#endif

uint64_t IPC_D2M_Start_Time_Us     = 0U;
uint32_t IPC_D2M_Delta_Time_Us     = 0U;
uint32_t IPC_D2M_Max_Delta_Time_Us = 0U;
uint32_t IPC_D2M_Min_Delta_Time_Us = 1000000U;

/* DSP_Write_IPC_Index is used for HIL syn purpose */
volatile uint8_t DSP_Write_IPC_Index = 0U;
/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
/** DSP-R52 ping pong buffer header counters*/
static uint32_t R52_D2M_Msg_Header_Cnt = 0U;
static uint16_t DSP_No_Command_Cnt     = 0U;

static D2M_Msg_T *IPC_Sp_Post_Buf_Read_Addr_Raw = NULL;
static uint8_t IPC_Sp_Post_Buf_Read_Idx_Raw     = 0U;

/* DSP process completion counters */
static IPC_Message_Counter_T DSP_Range_Config_Counts             = {0, 0};
static IPC_Message_Counter_T DSP_Range_Process_Complete_Counts   = {0, 0};
static IPC_Message_Counter_T DSP_Doppler_Process_Complete_Counts = {0, 0};
static IPC_Message_Counter_T DSP_Sp_Post_Complete_Counts         = {0, 0};
/* Mss radar data status payload live counter */
// static volatile uint16_t MSS_Radar_Status_CRC_Count = 0U;
static volatile uint8_t HW_Accel_Test_Fault = CODED_FALSE;
#ifdef ENABLE_COMFREEZE_DEBUG
volatile uint32_t Time_IPC_ISR[MAX_TIMEFAIL_COUNT] = {0};
#endif
volatile uint32_t FailCnt_IPC_ISR = 0;
/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
void Update_HW_Accel_Fault_Status(void);
/*===========================================================================*\
 * Local Inline Function Definitions and #define Function-Like Macros()
\*===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Check_BBE32_To_R52_Header
 *===========================================================================
 * RETURN VALUE:
 * static uint8_t
 *
 * PARAMETERS:
 *            D2M_Msg_T * buf
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *
 *
\*===========================================================================*/
static uint8_t __attribute__((noinline)) Check_BBE32_To_R52_Header(D2M_Msg_T *buf)
{
   uint8_t ret_val = CODED_FALSE;
#ifdef ENABLE_IPC_CRC
   uint8_t chnl                = ARM_CRC_CHANNEL0;
   uint32_t d2m_crc_calculated = 0U;
   if (sizeof(D2M_Msg_T) == buf->header.size)
   {
      /* increment expected message counter before check */
      R52_D2M_Msg_Header_Cnt++;

      /* check message counter */
      if (buf->header.counter == R52_D2M_Msg_Header_Cnt)
      {
   /* Measure D2M CRC computation time and store calculated CRC */
   #ifdef ENABLE_IPC_CRC_PROFILING
         uint64_t crc_start_time_us = 0U;
         Get_Platform_ustime(&crc_start_time_us);
   #endif
         d2m_crc_calculated = Calc_D2M_Buf_Crc_Chn_X(buf, chnl);
   #ifdef ENABLE_IPC_CRC_PROFILING
         Get_Platform_Elapsed_ustime(&D2M_CRC_Compute_Time_us, crc_start_time_us);
         /* Track min/max D2M CRC computation time */
         if (D2M_CRC_Compute_Time_us > D2M_CRC_Compute_Time_Max_us)
         {
            D2M_CRC_Compute_Time_Max_us = D2M_CRC_Compute_Time_us;
         }
         if (D2M_CRC_Compute_Time_us < D2M_CRC_Compute_Time_Min_us)
         {
            D2M_CRC_Compute_Time_Min_us = D2M_CRC_Compute_Time_us;
         }
   #endif
         if (buf->header.crc == d2m_crc_calculated)
         {
            ret_val = CODED_TRUE;
         }
         else
         {
            /*CRC error*/
         }
      }
      else
      {
         /* in case of fault, update expected message counter with received message counter */
         R52_D2M_Msg_Header_Cnt = buf->header.counter;
      }
   }
#else
   ret_val = CODED_TRUE;
#endif

   return (ret_val);
}

/******************************************************************************
 * Name:  R52_BBE_Trigger
 *   This function initiates interrupt from R52 to BBE
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: true for success, false for timeout.
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
bool R52_BBE_Trigger(void)
{
   bool ret_val = true;

   if (DSP_Init)
   {
      /* To make sure one time init message is sent first in CORE_INITIALIZED command */
      DSP->SP2DSP_INT.f.SP2DSP_LVL1_IRQ |= 0x01; /* Enable SP2DSP_LVL1_IRQ interrupt */
   }
   else
   {
      ret_val = false;
   }

   return ret_val;
}
/*****************************************************************************
 *. Name: Get_IPC_M2D_Onetime_Msg_Buffer
 *. This function will get the pointer to ipc buffer
 *.
 *. Parameters:
 *. buf_cnt - 0 or 1
 *.
 *. Return Value: M2D_Msg_T*
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
volatile M2D_One_Time_Msg_T *Get_IPC_M2D_Onetime_Msg_Buffer(void)
{
   return (volatile M2D_One_Time_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;
}

/*****************************************************************************
 *. Name: Get_IPC_M2D_Msg_Buffer
 *. This function will get the pointer to ipc buffer
 *.
 *. Parameters:
 *. buf_cnt - 0 or 1
 *.
 *. Return Value: M2D_Msg_T*
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
volatile M2D_Msg_T *Get_IPC_M2D_Msg_Buffer(uint8_t buf_cnt)
{
   return (volatile M2D_Msg_T *)&IPC_M2D_Buffers.IPC_M2D_Buffer[buf_cnt];
}

/*****************************************************************************
 *. Name: Reset_IPC_M2D_Buffer
 *. This function will reset the MSS to DSS IPC buffer
 *.
 *. Parameters:
 *. m2d_ptr - pointer to buffer
 *.
 *. Return Value:none
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *. APO-266: Functional safety requirement
 *.
 ******************************************************************************/
void Reset_IPC_M2D_Buffer(volatile M2D_Msg_T *m2d_ptr)
{
   volatile_memset((volatile void *)m2d_ptr, 0, sizeof(M2D_Msg_T));
   m2d_ptr->header.size = sizeof(M2D_Msg_T);
   m2d_ptr->header.crc  = 0;
}
/*****************************************************************************
 *. Name: IPC_M2D_Buffer_Init
 *. This function will initialize all the IPC ping pong buffers
 *.
 *. Parameters:None
 *.
 *. Return Value:none
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *. APO-266: Functional safety requirement
 *.
 ******************************************************************************/
void IPC_M2D_Buffer_Init(void)
{
   uint8_t index;
   for (index = 0; index < IPC_PING_PONG_COUNT; index++)
   {
      Reset_IPC_M2D_Buffer(&IPC_M2D_Buffers.IPC_M2D_Buffer[index]);
   }
}

/*****************************************************************************
 *. Name: IPC_M2D_One_Time_Buffer_Init
 *. This function will initialize IPC_M2D_Buffers.ipc_m2d_one_time_init_data
 *.
 *. Parameters:None
 *.
 *. Return Value:none
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *. APO-266: Functional safety requirement
 *.
 ******************************************************************************/
void IPC_M2D_One_Time_Buffer_Init(void)
{
   memset((void *)&IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data, 0, sizeof(M2D_One_Time_Msg_T));
}
/******************************************************************************
 * Name:  Update_R52_IPC_Notify
 *   API to receive the DSP to R52 triggers
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
void Update_R52_IPC_Notify(void)
{
   static uint8_t local_count      = 0;
   static bool FirstFailureSkipped = false;
   while (Is_IPC_Notify_Buffer_Empty(BBE_TO_R52_CORE) == false)
   {
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_in_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, READ_BUFFER);
      uint32_t buffer_index                                        = ipc_notify_structure_in_ptr->pfm_index;
      /*Check for R52 to BBE32 crc error*/
      if (R52_TO_BBE32_CRC_ERROR == ipc_notify_structure_in_ptr->errorField)
      {
         IPC_M2D_Crc_Err_Cnt++;
      }

      switch (ipc_notify_structure_in_ptr->command)
      {
         case DSP_RANGE_CONFIGURATION_COMPLETE:
         {
            if (ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR == ipc_notify_structure_in_ptr->errorField)
            {
               DSP_Range_Config_Counts.error_count++;
               DSP_Cfg_Init = DSP_CONFIG_ERROR;
            }
            else
            {
               DSP_Cfg_Init = DSP_CONFIG_NO_ERROR;
            }
            /* DSP_Write_IPC_Index used inside HIL BB to select the right ping and pong index */
            DSP_Write_IPC_Index = ipc_notify_structure_in_ptr->pingPongIndex;

            DSP_Range_Config_Counts.rx_count++;
            PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, buffer_index);
            (void)CaptureGlobalTimestamp(TS_START_ACQ, NULL);
         }
         break;
         case DSP_RANGE_PROCESSING_COMPLETE:
         {
            if (ipc_notify_structure_in_ptr->errorField != ERRORFIELD_NO_ERROR)
            {
               DSP_Range_Process_Complete_Counts.error_count++;
            }
            else
            {
               /* Do Nothing */
            }

            DSP_Range_Process_Complete_Counts.rx_count++;
            PFM_Update_Stage(PFM_RFFT_DONE_STAGE, buffer_index);
            /* XCP DAQ Event for ADC data*/
            Rte_Call_PostRadarProcessing_ADC_Populate_ADC_Stream();
            (void)CaptureGlobalTimestamp(TS_LOOK_COMP, NULL);
            Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger();

            /* Trigger the HIL periodic runnable at LOOK_COMPLETE (DSP_RANGE_PROCESSING_COMPLETE). */
            Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger();

            /** TODO: Read Range processing IPC data */
         }
         break;
         case DSP_DOPPLER_PROCESSING_COMPLETE:
         {
            Received_Doppler_Done = true;
            DSP_Doppler_Process_Complete_Counts.rx_count++;
            PFM_Update_Stage(PFM_DFFT_DONE_STAGE, buffer_index);
            IPC_Dopp_RDD_Comp_Buf_Read_Addr = (D2M_Msg_T *)ipc_notify_structure_in_ptr->curIpcAddr;
            IPC_Dopp_RDD_Comp_Buf_Read_idx  = ipc_notify_structure_in_ptr->pingPongIndex;
            if (0U == IPC_Dopp_RDD_Comp_Buf_Read_idx)
            {
               Ping_Buf_Addr = (uint32_t)IPC_Dopp_RDD_Comp_Buf_Read_Addr;
            }
            else
            {
               Pong_Buf_Addr = (uint32_t)IPC_Dopp_RDD_Comp_Buf_Read_Addr;
            }
            if (ipc_notify_structure_in_ptr->errorField != ERRORFIELD_NO_ERROR)
            {
               DSP_Doppler_Process_Complete_Counts.error_count++;
            }
            else
            {
               /* Do Nothing */
            }

            Received_Doppler_Stream = true;
            Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream();
         }
         break;
         case DSP_SP_POST_PROCESSING_COMPLETE:
         {
            static bool d2m_delta_time_available = false;
            if (d2m_delta_time_available)
            {
               Get_Platform_Elapsed_ustime(&IPC_D2M_Delta_Time_Us, IPC_D2M_Start_Time_Us);

               if (IPC_D2M_Delta_Time_Us > IPC_D2M_Max_Delta_Time_Us)
               {
                  IPC_D2M_Max_Delta_Time_Us = IPC_D2M_Delta_Time_Us;
               }
               if ((IPC_D2M_Delta_Time_Us < IPC_D2M_Min_Delta_Time_Us) && (d2m_delta_time_available))
               {
                  IPC_D2M_Min_Delta_Time_Us = IPC_D2M_Delta_Time_Us;
               }
            }
            else
            {
               d2m_delta_time_available = true;
            }

            Get_Platform_ustime(&IPC_D2M_Start_Time_Us);
            if (((IPC_D2M_Delta_Time_Us < TIME_45MS) || (IPC_D2M_Delta_Time_Us > TIME_55MS)))
            {
               if (!FirstFailureSkipped)
               {
                  FirstFailureSkipped = true;
               }
               else
               {
#ifdef ENABLE_COMFREEZE_DEBUG
                  Time_IPC_ISR[local_count++] = IPC_D2M_Delta_Time_Us;
#endif
                  FailCnt_IPC_ISR++;
                  if (local_count >= MAX_TIMEFAIL_COUNT)
                  {
                     local_count = 0u;
                  }
               }
            }

            if (ipc_notify_structure_in_ptr->errorField != ERRORFIELD_NO_ERROR)
            {
               DSP_Sp_Post_Complete_Counts.error_count++;
            }
            else
            {
               /* Do Nothing */
            }
            /** Read Signal Proc Post processing IPC data */
            /*Trigger XCp DAQ event for RDD and AF data */
            DSP_Sp_Post_Complete_Counts.rx_count++;
            PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, buffer_index);
            IPC_Sp_Post_Buf_Read_Addr_Raw = (D2M_Msg_T *)ipc_notify_structure_in_ptr->curIpcAddr;
            IPC_Sp_Post_Buf_Read_Idx_Raw  = ipc_notify_structure_in_ptr->pingPongIndex;
            Update_Frame_Time_For_Look(ipc_notify_structure_in_ptr->lookIndex, ipc_notify_structure_in_ptr->pingPongIndex);

            /* To receive IT Data from D2M, for Integration Testing */
            SIT_IPC_TRANSFER_D2M_RECEIVE((const D2M_Payload_T *)&IPC_Sp_Post_Buf_Read_Addr_Raw->payload);

            Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete();

            /* Trigger CAN Transmission */
            Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx(); // TO-DO move to Dsp_sp_post_processing_complete
         }
         break;
         case CORE_INITIALIZED:
         {
#ifdef CDC_ENABLE
            Cdc_Frame_Interface_Addr = ipc_notify_structure_in_ptr->curIpcAddr;
#endif
            /** When the R52 receives a CORE_INITIALIZED message, ALWAYS respond and just echo back the received command.
             *  This allows initialization of the pointers on the DSS side. **/
            if (Is_IPC_Notify_Buffer_Full(R52_TO_BBE_CORE) == false)
            {
               volatile Ipc_Notify_Structure_T *r52_to_bbe_notify_ptr = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, WRITE_BUFFER);
               r52_to_bbe_notify_ptr->curIpcAddr                      = (uint32_t)Get_IPC_M2D_Onetime_Msg_Buffer();
               r52_to_bbe_notify_ptr->command                         = CORE_INITIALIZED;
               DSP_Init                                               = true;
               Increment_IPC_Notify_WriteIndx(
                  R52_TO_BBE_CORE); /* Increment write index just before R52_BBE_Trigger to avoid race condition*/
               R52_BBE_Trigger();
            }
            else
            {
               M2D_Buffer_Full_Error_Counter++;
            }
         }
         break;
         default:
         {
            /* Ignore other commands*/
            DSP_No_Command_Cnt++;
         }
         break;
      }
      Increment_IPC_Notify_ReadIndx(BBE_TO_R52_CORE);
   }
}

/******************************************************************************
 *. Name: Get_IPC_D2M_Max_Delta_Time_Us
 *. This function returns the maximum delta time in microseconds for IPC D2M communication.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: EUR-2882
 ******************************************************************************/
uint32_t Get_IPC_D2M_Max_Delta_Time_Us(void)
{
   return IPC_D2M_Max_Delta_Time_Us;
}

/******************************************************************************
 *. Name: Get_IPC_D2M_Min_Delta_Time_Us
 *. This function returns the minimum delta time in microseconds for IPC D2M communication.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: EUR-2882
 ******************************************************************************/
uint32_t Get_IPC_D2M_Min_Delta_Time_Us(void)
{
   return IPC_D2M_Min_Delta_Time_Us;
}

/******************************************************************************
 *. Name: Check_D2M_Crc_Header
 *. This function check the CRC,Size and Counter
 *.
 *. Parameters:  None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-3245
 ******************************************************************************/
uint8_t Check_D2M_Crc_Header(D2M_Msg_T *p_ipc_d2m_sp_post_msg)
{
   uint8_t ret_val = CODED_FALSE;

   /*IPC D2M crc check*/
   if (CODED_TRUE == Check_BBE32_To_R52_Header(p_ipc_d2m_sp_post_msg))
   {
      ret_val = CODED_TRUE;
   }
   else
   {
      /*Increment counter in case of IPC D2M buffer CRC error*/
      IPC_D2M_Crc_Err_Cnt++;
   }

   return (ret_val);
}

/******************************************************************************
 * FUNCTION:Get_IPC_D2M_Sp_Post_Proc_Buffer
 * Return pointer to current IPC read buffer
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return        D2M_Msg_T * pointer to IPC buf
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{get_ipc_d2m_buffer}
 ******************************************************************************/
D2M_Msg_T *Get_IPC_D2M_Sp_Post_Proc_Buffer(void)
{
   return IPC_Sp_Post_Proc_Buf_Read_Addr;
}

/******************************************************************************
 * FUNCTION: Get_MSS_IPC_M2D_Msg_Buffer
 * Return pointer to current  ipc_m2d_buffer
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return        M2D_Msg_T* pointer to ipc_m2d_buffer
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Get_MSS_IPC_M2D_Msg_Buffer}
 ******************************************************************************/
volatile M2D_Msg_T *Get_MSS_IPC_M2D_Msg_Buffer(void)
{
   return Get_IPC_M2D_Msg_Buffer(R52_M2D_Buffer_Index);
}

/******************************************************************************
 * FUNCTION: Get_MSS_IPC_M2D_Msg_Buf_Addr
 * Return pointer to current  ipc_m2d_buffer address
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return        M2D_Msg_T* pointer to ipc_m2d_buffer
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{Get_MSS_IPC_M2D_Msg_Buf_Addr}
 ******************************************************************************/
volatile M2D_Msg_T *Get_MSS_IPC_M2D_Msg_Buf_Addr(uint8_t ipc_buff_index)
{
   return Get_IPC_M2D_Msg_Buffer(ipc_buff_index);
}

/******************************************************************************
 * FUNCTION: Get_DSP_Init_Status
 * Return pointer to Return BBE init status
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return        DSP_Init
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{void}
 ******************************************************************************/
bool Get_DSP_Init_Status(void)
{
   return DSP_Init;
}

/******************************************************************************
 *. Name: Set_DSP_Init_Status
 *. Sets the DSP initialisation flag.
 *. Set to true when CORE_INITIALIZED is received from BBE32;
 *. cleared to false when a BBE32 reset is issued.
 *.
 *. Parameters:  bool val - true = DSP initialised, false = not initialised
 *. Return Value: None
 ******************************************************************************/
void Set_DSP_Init_Status(bool val)
{
   DSP_Init = val;
}

/******************************************************************************
 * FUNCTION: Update_IPC_M2D_Header
 * Update header and Trigger IPC M7 to BBE
 *
 * LIMITATIONS:
 *
 * \param[in]     M2D_Msg_T* m2d_msg_ptr
 *
 * \return
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{void}
 ******************************************************************************/
void Update_IPC_M2D_Header(volatile M2D_Msg_T *m2d_msg_ptr)
{
   uint32_t m2d_crc_calculated = 0U;
   R52_M2D_Msg_Header_Cnt      = R52_M2D_Msg_Header_Cnt + 1U;
   m2d_msg_ptr->header.size    = sizeof(M2D_Msg_T);

   m2d_msg_ptr->header.counter = R52_M2D_Msg_Header_Cnt;

   /* CRITICAL FIX: Use SW CRC to avoid hardware contention hang.
    * HW CRC (Crc_CalculateCRC32_HW) hangs at ptr_crc->POLY_SEL_CH1
    * when ISR and task contexts both access the shared CRC engine.
    * Switching to software CRC eliminates the deadlock. */
#ifdef ENABLE_IPC_CRC_PROFILING
   uint64_t crc_start_time_us = 0U;
   Get_Platform_ustime(&crc_start_time_us);
#endif

   m2d_crc_calculated = Calc_M2D_Buf_Crc(m2d_msg_ptr);
#ifdef ENABLE_IPC_CRC_PROFILING
   Get_Platform_Elapsed_ustime(&M2D_CRC_Compute_Time_us, crc_start_time_us);
   /* Track min/max CRC computation time */
   if (M2D_CRC_Compute_Time_us > M2D_CRC_Compute_Time_Max_us)
   {
      M2D_CRC_Compute_Time_Max_us = M2D_CRC_Compute_Time_us;
   }
   if (M2D_CRC_Compute_Time_us < M2D_CRC_Compute_Time_Min_us)
   {
      M2D_CRC_Compute_Time_Min_us = M2D_CRC_Compute_Time_us;
   }
#endif

   m2d_msg_ptr->header.crc = m2d_crc_calculated;
#ifdef XCP_FAULT_INJECTION
   if (R52_To_BBE_Fault == m2d_msg_ptr->payload.xcp_fault_type)
   {
      m2d_msg_ptr->header.size = 0U;
   }
   else
   {
      /* Do Nothing */
   }
#endif
}

/******************************************************************************
 * FUNCTION:Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer
 * Return pointer to current IPC read buffer
 * LIMITATIONS:
 *
 * \param[in]     none
 *
 * \return        D2M_Msg_T * pointer to IPC buf
 *
 * \remark
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 * \reqtrace
 * \\input{get_ipc_d2m_buffer}
 ******************************************************************************/
D2M_Msg_T *Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer(void)
{
   return IPC_Dopp_RDD_Comp_Buf_Read_Addr;
}

/******************************************************************************
 *. Name: Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx
 *. Returns the current Doppler/RDD completed IPC buffer ping-pong read index.
 *. Updated each time a DSP_DOPPLER_PROCESSING_COMPLETE notification is received.
 *.
 *. Parameters:  None
 *. Return Value: uint8_t - ping-pong buffer index (0 or 1)
 ******************************************************************************/
uint8_t Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx(void)
{
   return IPC_Dopp_RDD_Comp_Buf_Read_idx;
}

/******************************************************************************
 * Name:  Is_Doppler_Comp_RDD_Stream_Ready
 *   Check if new frame of Doppler stream available.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: bool - true for DSP ready, false otherwise
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
bool Get_Is_Doppler_Comp_RDD_Stream_Ready(void)
{
   return Received_Doppler_Stream;
}

/******************************************************************************
 *
 * Name:  Set_Is_Doppler_Comp_RDD_Stream_Ready
 *   Clear Doppler stream available flag.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: bool - true for DSP ready, false otherwise
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
void Set_Is_Doppler_Comp_RDD_Stream_Ready(bool flag)
{
   Received_Doppler_Stream = flag;
}

/******************************************************************************
 *. Name: Get_Received_Doppler_Done
 *. Returns the Received_Doppler_Done flag.
 *. Set to true when DSP_DOPPLER_PROCESSING_COMPLETE is received from BBE32
 *. or when DSP core initialization completes;
 *. cleared to false when a new per-look IPC trigger is sent.
 *.
 *. Parameters:  None
 *. Return Value: bool - true if doppler processing is done, false otherwise
 ******************************************************************************/
bool Get_Received_Doppler_Done(void)
{
   return Received_Doppler_Done;
}

/******************************************************************************
 *. Name: Set_Received_Doppler_Done
 *. Sets the Received_Doppler_Done flag.
 *.
 *. Parameters:  bool flag - true = doppler done, false = not done
 *. Return Value: None
 ******************************************************************************/
void Set_Received_Doppler_Done(bool flag)
{
   Received_Doppler_Done = flag;
}

/******************************************************************************
 *. Name: Get_M2D_Buffer_Full_Error_Counter
 *. Returns the M2D buffer full error counter.
 *. Incremented each time the R52-to-BBE notify ring buffer is full
 *. when attempting to send a message.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t - accumulated buffer full error count
 ******************************************************************************/
uint32_t Get_M2D_Buffer_Full_Error_Counter(void)
{
   return M2D_Buffer_Full_Error_Counter;
}

/******************************************************************************
 *. Name: Set_M2D_Buffer_Full_Error_Counter
 *. Sets the M2D buffer full error counter.
 *.
 *. Parameters:  uint32_t val - new counter value
 *. Return Value: None
 ******************************************************************************/
void Set_M2D_Buffer_Full_Error_Counter(uint32_t val)
{
   M2D_Buffer_Full_Error_Counter = val;
}

/******************************************************************************
 *. Name: Get_D2M_Ping_Buf_Addr
 *. This function returns ping buffer value(address)
 *.
 *. Parameters:  None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint32_t Get_D2M_Ping_Buf_Addr(void)
{
   return Ping_Buf_Addr;
}

/******************************************************************************
 *. Name: Get_D2M_Pong_Buf_Addr
 *. This function returns pong buffer value(address)
 *.
 *. Parameters:  None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint32_t Get_D2M_Pong_Buf_Addr(void)
{
   return Pong_Buf_Addr;
}

/******************************************************************************
 *. Name: Get_DSP_Write_IPC_Index
 *. This function returns the DSP_Write_IPC_Index
 *.
 *. Parameters:  None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
volatile uint8_t Get_DSP_Write_IPC_Index(void)
{
   return DSP_Write_IPC_Index;
}

/******************************************************************************
 *. Name: Get_R52_Current_PingPong_Index
 *. This function returns the R52_M2D_Buffer_Index
 *.
 *. Parameters:  None
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
uint8_t Get_R52_Current_PingPong_Index(void)
{
   return R52_M2D_Buffer_Index;
}

/******************************************************************************
 *. Name: Get_IPC_M2D_Crc_Err_Cnt
 *. Returns the IPC Master-to-DSP (M2D) CRC error counter.
 *. Incremented each time a CRC error is detected on a message sent from
 *. R52 to BBE32 via the M2D IPC channel.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t - accumulated M2D CRC error count
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 ******************************************************************************/
uint32_t Get_IPC_M2D_Crc_Err_Cnt(void)
{
   return IPC_M2D_Crc_Err_Cnt;
}

/******************************************************************************
 *. Name: Get_IPC_D2M_Crc_Err_Cnt
 *. Returns the IPC DSP-to-Master (D2M) CRC error counter.
 *. Incremented each time a CRC error is detected on a message received from
 *. BBE32 to R52 via the D2M IPC channel.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t - accumulated D2M CRC error count
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 ******************************************************************************/
uint32_t Get_IPC_D2M_Crc_Err_Cnt(void)
{
   return IPC_D2M_Crc_Err_Cnt;
}

/******************************************************************************
 *. Name: Get_R52_D2M_Msg_Header_Cnt
 *. Returns the R52 DSP-to-Master (D2M) message header counter.
 *. Incremented each time a D2M message header check is performed.
 *.
 *. Parameters:  None
 *. Return Value: uint32_t - current D2M message header counter value
 ******************************************************************************/
uint32_t Get_R52_D2M_Msg_Header_Cnt(void)
{
   return R52_D2M_Msg_Header_Cnt;
}

/******************************************************************************
 *. Name: Get_DSP_Cfg_Init
 *. Returns the current DSP configuration state.
 *.
 *. Parameters:  None
 *. Return Value: volatile DSP_Config_Type_T
 ******************************************************************************/
volatile DSP_Config_Type_T Get_DSP_Cfg_Init(void)
{
   return DSP_Cfg_Init;
}

/******************************************************************************
 *. Name: Set_DSP_Cfg_Init
 *. Sets the DSP configuration state.
 *. Called by dsp_setup when initiating a configuration sequence or on error.
 *.
 *. Parameters:  DSP_Config_Type_T val - new configuration state
 *. Return Value: None
 ******************************************************************************/
void Set_DSP_Cfg_Init(DSP_Config_Type_T val)
{
   DSP_Cfg_Init = val;
}

/******************************************************************************
 *. Name: Get_DSP_Range_Config_Counts
 *. Returns the DSP range configuration message counters.
 *. rx_count is incremented each time a DSP_RANGE_CONFIGURATION_COMPLETE
 *. notification is received from BBE32.
 *. error_count is incremented when the notification carries
 *. ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR.
 *.
 *. Parameters:  None
 *. Return Value: IPC_Message_Counter_T - copy of DSP_Range_Config_Counts
 ******************************************************************************/
IPC_Message_Counter_T Get_DSP_Range_Config_Counts(void)
{
   return DSP_Range_Config_Counts;
}

/******************************************************************************
 *. Name: Get_DSP_Range_Process_Complete_Counts
 *. Returns the DSP range processing completion message counters.
 *. rx_count is incremented each time a DSP_RANGE_PROCESSING_COMPLETE
 *. notification is received from BBE32.
 *. error_count is incremented when the notification carries a non-zero
 *. errorField.
 *.
 *. Parameters:  None
 *. Return Value: IPC_Message_Counter_T - copy of DSP_Range_Process_Complete_Counts
 ******************************************************************************/
IPC_Message_Counter_T Get_DSP_Range_Process_Complete_Counts(void)
{
   return DSP_Range_Process_Complete_Counts;
}

/******************************************************************************
 *. Name: Get_DSP_Doppler_Process_Complete_Counts
 *. Returns the DSP Doppler processing completion message counters.
 *. rx_count is incremented each time a DSP_DOPPLER_PROCESSING_COMPLETE
 *. notification is received from BBE32.
 *. error_count is incremented when the notification carries a non-zero
 *. errorField.
 *.
 *. Parameters:  None
 *. Return Value: IPC_Message_Counter_T - copy of DSP_Doppler_Process_Complete_Counts
 ******************************************************************************/
IPC_Message_Counter_T Get_DSP_Doppler_Process_Complete_Counts(void)
{
   return DSP_Doppler_Process_Complete_Counts;
}

/******************************************************************************
 *. Name: Get_DSP_Sp_Post_Complete_Counts
 *. Returns the DSP signal-processing post-processing completion message counters.
 *. rx_count is incremented each time a DSP_SP_POST_PROCESSING_COMPLETE
 *. notification is received from BBE32.
 *. error_count is incremented when the notification carries a non-zero
 *. errorField.
 *.
 *. Parameters:  None
 *. Return Value: IPC_Message_Counter_T - copy of DSP_Sp_Post_Complete_Counts
 ******************************************************************************/
IPC_Message_Counter_T Get_DSP_Sp_Post_Complete_Counts(void)
{
   return DSP_Sp_Post_Complete_Counts;
}

/******************************************************************************
 *. Name: Get_IPC_Sp_Post_Buf_Read_Addr_Raw
 *. Returns the raw (unvalidated) pointer to the D2M IPC buffer most recently
 *. indicated by the BBE32 DSP_SP_POST_PROCESSING_COMPLETE notification.
 *. This pointer is captured directly from the IPC notify structure before any
 *. CRC or header validation is performed.
 *.
 *. Parameters:  None
 *. Return Value: D2M_Msg_T * - pointer to the raw SP post-processing IPC buffer,
 *.              or NULL if no notification has been received yet
 ******************************************************************************/
D2M_Msg_T *Get_IPC_Sp_Post_Buf_Read_Addr_Raw(void)
{
   return IPC_Sp_Post_Buf_Read_Addr_Raw;
}

/******************************************************************************
 *. Name: Get_IPC_Sp_Post_Buf_Read_Idx_Raw
 *. Returns the raw ping-pong buffer index associated with the most recently
 *. received BBE32 DSP_SP_POST_PROCESSING_COMPLETE notification.
 *. This index is captured directly from the IPC notify structure before any
 *. CRC or header validation is performed.
 *.
 *. Parameters:  None
 *. Return Value: uint8_t - ping-pong buffer index (0 or 1)
 ******************************************************************************/
uint8_t Get_IPC_Sp_Post_Buf_Read_Idx_Raw(void)
{
   return IPC_Sp_Post_Buf_Read_Idx_Raw;
}

/******************************************************************************
 *. Name: Get_DSP_No_Command_Cnt
 *. Returns the count of unrecognised IPC commands received from the BBE32.
 *. Incremented each time Update_R52_IPC_Notify processes a notify entry
 *. whose command field does not match any known DSP command code.
 *.
 *. Parameters:  None
 *. Return Value: uint16_t - accumulated unknown-command count
 ******************************************************************************/
uint16_t Get_DSP_No_Command_Cnt(void)
{
   return DSP_No_Command_Cnt;
}
#ifdef XCP_FAULT_INJECTION
/*****************************************************************************
 *. Name: Set_IPC_XCP_Fault_Injn_Var
 *. This function will set the global variable for xcp fault injection
 *.
 *. Parameters:
 *. buf_cnt - 0 or 1
 *.
 *. Return Value: M2D_Msg_T*
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Set_IPC_XCP_Fault_Injn_Var(uint8_t core_id)
{
   Ipc_Xcp_Fault_Injn_Var = core_id;
}

/*****************************************************************************
 *. Name: Set_IPC_XCP_Fault_Injn_Var
 *. This function will set the global variable for xcp fault injection
 *.
 *. Parameters:
 *. buf_cnt - 0 or 1
 *.
 *. Return Value: M2D_Msg_T*
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Set_XCP_Fault_Inj(void)
{
   volatile M2D_Msg_T *m2d_msg_ptr = Get_MSS_IPC_M2D_Msg_Buffer();
   if (R52_To_BBE_Fault == Ipc_Xcp_Fault_Injn_Var)
   {
      m2d_msg_ptr->payload.xcp_fault_type = R52_To_BBE_Fault;
   }
   else if (BBE_To_R52_Fault == Ipc_Xcp_Fault_Injn_Var)
   {
      m2d_msg_ptr->payload.xcp_fault_type = BBE_To_R52_Fault;
   }
   else if (NO_Fault == Ipc_Xcp_Fault_Injn_Var)
   {
      m2d_msg_ptr->payload.xcp_fault_type = NO_Fault;
   }
   else
   {
      /*Do nothing*/
   }
}

#endif
/*****************************************************************************
 *. Name: Update_HW_Accel_Fault_Status
 *. This function will read the HW Accelerator related Interrupt flags and send their status
    to TOI and Diag.
 *.
 *. Parameters:
 *.
 *.
 *. Return Value:
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
void Update_HW_Accel_Fault_Status(void)
{
   uint8_t hw_accel_err_flg                                  = CODED_FALSE;
   uint8_t hw_accel_fusa_err_flg                             = CODED_FALSE;
   volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, WRITE_BUFFER);

   hw_accel_err_flg      = Get_RA_R52_ERROR_Failure_State();
   hw_accel_fusa_err_flg = Get_RA_R52_FUSA_Failure_State();
   Set_RA_R52_ERROR_Failure_State(CODED_FALSE);
   Set_RA_R52_FUSA_Failure_State(CODED_FALSE);

   if ((CODED_TRUE == hw_accel_err_flg) || (CODED_TRUE == hw_accel_fusa_err_flg))
   {
      FS_RA_Process_Failure_Cnts();
      ipc_notify_structure_ptr->command = R52_RA_ERROR_FAULT;
      /* Increment write index just before R52_BBE_Trigger to avoid race condition*/
      Increment_IPC_Notify_WriteIndx(R52_TO_BBE_CORE);
      /* Trigger BBE */
      (void)R52_BBE_Trigger();
      HW_Accel_Test_Fault = CODED_TRUE;
   }
   else
   {
      HW_Accel_Test_Fault = CODED_FALSE;
   }
}
/*****************************************************************************
 *. Name: Get_HW_Accel_Test_fault
 *. This function will return the RA Fault Status.
 *.
 *. Parameters:
 *.
 *.
 *. Return Value: uint8_t
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/

uint8_t Get_HW_Accel_Test_Fault(void)
{
   return HW_Accel_Test_Fault;
}
