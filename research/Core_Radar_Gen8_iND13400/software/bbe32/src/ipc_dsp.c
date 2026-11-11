/**
 * @file ipc_dsp.c
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Initialization and interrupt handler for IPC communication with ARM.
 *
 * @section ABBR ABBREVIATIONS:
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *   - Requirements Document(s):
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 * @section DFS DEVIATIONS FROM STANDARDS:
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
#include <string.h>
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "range_process_ifc.h"
/* range_process_ifc.h must be included before chandra_sfrs.h.
   Need to update the chandra library reference to complete the inclusion
   and remove the chandra sfrs from the application repository */

#include "api/bbe_helpers.h"
#include "api/idma_helpers.h"
#include "api/profiling_helpers.h"
#include "api/timing_helpers.h"
#include "chandra_sfrs_base.h"
#include "crc_calc.h"
#include "dsp_sfrs.h"
#include "fixmac.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "main_application.h"
#include "mipi_ifc.h"
#include "mmic_common_types.h"
#include "radar_sw_config.h"
#include "reuse.h"
#include "smc_cal.h"
#include "toi_algo_interface.h"
#include "usc_cal.h"
#ifdef __XTENSA__
   #include <xtensa/tie/xt_ioports.h>
   #include <xtensa/xtruntime.h>
#else
   #include "core-macros.h"
#endif
#ifdef CDC_ENABLE
   #include "cdc_packing.h"
#endif

#if DOWNSELECTION_ENABLE
   #include "toi_ds_stream.h"
#else
   #include "toi_stream.h"
#endif
/* ========================================================================== */
/*                   SWE5 Integration Testing Support                         */
/* ========================================================================== */
#include "dsp_it_macros_test.h"

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#define R52_TO_BBE_TRIGGER_TIME_CHECK
#define MAX_MESSAGE_TIME_TICKS ((uint32_t)(IPC_MESSAGE_TIMEOUT_IN_US / DSP_CLOCK_PERIOD_US))

#define DSP ((volatile DSP_SFRS_t *)DSP_base)

#if (DOWNSELECTION_ENABLE == 1U)
   #define Get_TOI_DATA_STATUS_DST_PTR(x) ((x)->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload)
   #define TOI_RADAR_DATA_PAYLOAD_T       TOI_Radar_Data_Status_Payload_DS_T
#else
   #define Get_TOI_DATA_STATUS_DST_PTR(x) ((x)->payload.toi_stream_data.toi_ip_data.toi_radar_data_status_payload)
   #define TOI_RADAR_DATA_PAYLOAD_T       TOI_Radar_Data_Status_Payload_T
#endif

/* This static check ensures that the size of Radar_Data_Status_Payload_T and TOI_Radar_Data_Status_T are the same*/
/* Do not comment this statement, rather make sure that the size of Radar_Data_Status_Payload_T &
 * TOI_Radar_Data_Status_Payload_T/TOI_DS_Radar_Data_Status_Payload_T structures are matching */
#define STATIC_ASSERT(COND, MSG) typedef char static_assertion_##MSG[(COND) ? 1 : -1]

STATIC_ASSERT(sizeof(Radar_Data_Status_Payload_T) == sizeof(TOI_RADAR_DATA_PAYLOAD_T), radar_data_status_payload_size_mismatch);

/** IPC BBE to R52 Fixed Trigger */
#define IPC_BBE_FIXED_TRIGGER_ENABLE
#ifdef IPC_BBE_FIXED_TRIGGER_ENABLE
   /** Fixed trigger debug macro */
   #define IPC_BBE_FIXED_TRIGGER_DEBUG_ENABLE
   #define ROUND_THRESHOLD_US           (999U)
   #define FIXED_TRIGGER_BUFFER_TIME_MS ((MAX_ALLOWED_CHIRP_TIME_INCREASE_US + ROUND_THRESHOLD_US) / 1000U)
   #define MAX_DWELL_TIME_MS            ((MAX_DWELL_TIME_US + ROUND_THRESHOLD_US) / 1000U)
   #define FIXED_BBE_TRIGGER_TIME_MS    (RADAR_CYCLE_MS_DSP + FIXED_TRIGGER_BUFFER_TIME_MS + (MAX_DWELL_TIME_MS)) /* ms */
   #define CORE_TIMER_MS_COUNT          (DSP_CLK_FREQ_HZ / 1000U)
   /**
    * @note This is for handling the Fixed Trigger value during a range process timeout condition.
    * MAX_DWELL_TIME_US can differ for variants.
    */
   #define GET_FIXED_TRIGGER_COUNT (FIXED_BBE_TRIGGER_TIME_MS * CORE_TIMER_MS_COUNT)

#endif

/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */
typedef enum State_Machine_Monitor_Tag
{
   READY_FOR_RANGE_PROCESSING = 0x87654321U,
   RUNNING_LOOK_PROCESSING    = 0x12345678U,
   INVALID_STATE,
} State_Machine_Monitor_T;

typedef enum Buffer_Index_Tag
{
   BUF_IDX_PING, /* BUF_IDX_PING */
   BUF_IDX_PONG, /* BUF_IDX_PONG */
   BUF_IDX_MAX
} Buffer_Index_T;

typedef struct Fixed_Trigger_Struct_Tag
{
   uint32_t trigger_timestamp;
   uint32_t trigger_offset_us;
   uint32_t timer_used;
   uint16_t buffer_index;
   uint16_t trigger_count;
} Fixed_Trigger_Struct_T;

/* ========================================================================== */
/*                   Exported External Variables                              */
/* ========================================================================== */
extern uint32_t xtos_enabled;
extern uint32_t xtos_vpri_enabled;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** Flag to indicate R52 to bbe trigger received*/
volatile Trigger_Received_T IPC_R52_To_BBE_Trigger_Received = NO_TRIGGER;

volatile uint32_t IPC_R52_Trigger_Failed = 0U;

/** Offline mode flag - Set in the interrupt context. */
volatile uint32_t Offline_Mode_Flag_DSP = ITF_DISABLED_NORMAL_MODE;

/** IPC M2D error counter*/
uint16_t IPC_M2D_Buffer_Err_Cnt = 0U;

/** Counter for waiting for trigger
 *  debug signal to indicate DSP is alive waiting for a frame start */
volatile uint32_t Waiting_For_Trigger = 0;

#ifdef ENABLE_IPC_CRC_PROFILING
/** CRC computation time tracking on DSP (in microseconds) */
volatile uint32_t __attribute__((section(".sram1.bss"))) DSP_M2D_CRC_Compute_Time_us      = 0U;
volatile uint32_t __attribute__((section(".sram1.bss"))) DSP_M2D_CRC_Compute_Time_Max_us  = 0U;
volatile uint32_t __attribute__((section(".sram1.data"))) DSP_M2D_CRC_Compute_Time_Min_us = UINT32_MAX;
volatile uint32_t __attribute__((section(".sram1.bss"))) DSP_D2M_CRC_Compute_Time_us      = 0U;
volatile uint32_t __attribute__((section(".sram1.bss"))) DSP_D2M_CRC_Compute_Time_Max_us  = 0U;
volatile uint32_t __attribute__((section(".sram1.data"))) DSP_D2M_CRC_Compute_Time_Min_us = UINT32_MAX;
#endif

/** Declaration of the BBE pointers to the SMC and USC Data Structures
 *  Populated after the CORE_INITIALIZED message is received.
 */
SMC_Cal_T *SMC_Cal_Data_Ptr = NULL;
USC_Cal_T *USC_Cal_Data_Ptr = NULL;

/*IPC D2M Buffer*/
D2M_Msg_T __attribute__((aligned(32), used, section(".ipc_dsp_to_r52"))) IPC_D2M_Buffer[IPC_PING_PONG_COUNT];

volatile M2D_One_Time_Msg_T *M2D_One_Time_Msg_Ptr = NULL;

ProfilingStruct_t __attribute__((used)) IPC_Profiling = {0};

/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */
/** DSP-R52 ping pong buffer header counters*/
#ifdef ENABLE_IPC_CRC
static uint32_t DSP_M2D_Msg_Header_Cnt = 0U;
#endif
static uint32_t DSP_D2M_Msg_Header_Cnt = 0U;
/* IPC M2D IPC Index */
static M2D_Msg_T *M2D_Buffer_Ptr = 0U;
/* Range Process state IPC Index */
static uint8_t RP_Buffer_Index = 0U;
/* Doppler Process + RDD state IPC Index */
static uint8_t DP_Rdd_Buffer_Index = 0U;
/* Angle Finding IPC Index */
static uint8_t SP_Post_Proc_Buffer_Index = 0U;
/* Used for PFM logic */
static uint32_t DSP_PFM_Index_Isr = 0U;
static uint32_t DSP_PFM_Index     = 0U;

/* These two variables are used to gate the processing.
   Mss_Init_Received - This must be set to true by the CORE_INITIALIZED method
                       This signals that the SMC/USC updated pointers are received and valid.
   Ready_For_New_Frame - This signals if the application can handle a new frame start. If not
                         ready, an error is sent to the R52 to indicate the processor is not ready.
*/
static volatile Trigger_Received_T Mss_Init_Received        = NO_TRIGGER;
static volatile State_Machine_Monitor_T Ready_For_New_Frame = INVALID_STATE;

/* Counter to store count of timeouts when sending a message to the R52. */
// uint32_t Dsp_Cfg_Error_Counter_DSP = 0;

uint32_t D2M_Buffer_Full_Error_Counter = 0;

uint16_t SP2DSP_LVL1_Handler_test_var = 0U; // test object

volatile DSP_SFRS_t *const Dsp_Ptr = ((volatile DSP_SFRS_t *const)DSP);

/* Dss radar data status payload live counter */
static uint16_t DSS_Radar_Status_CRC_Count = 0U;

#ifdef IPC_BBE_FIXED_TRIGGER_ENABLE

   #ifdef IPC_BBE_FIXED_TRIGGER_DEBUG_ENABLE
volatile bool Look_Type_Induce_Err = false;
   #endif

static volatile Ipc_Notify_Structure_T IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_MAX] = {0};

static volatile Fixed_Trigger_Struct_T Fixed_Trigger_Data[BUF_IDX_MAX] = {0};

#endif
static volatile uint8_t DSP_RA_Error_Flag = CODED_FALSE;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static uint8_t Check_R52_To_BBE32_Header(M2D_Msg_T *buf);
static void __attribute__((section(".sram0.text"))) SP2DSP_LVL1_Handler(void *arg);
static bool Appl_Range_Process_Trigger(Radar_Look_T look_type);
static uint8_t Compute_DSS_Rdr_Data_Sts_Payload_CRC(IPC_MMIC_Radar_Data_Status_T *m2d_rdr_data_sts_ptr);
#ifdef IPC_BBE_FIXED_TRIGGER_ENABLE
static void Trigger_BBE_TO_R52(uint16_t buffer_index);
static void Set_BBE_To_R52_Trigger_Timer(void);
static void Timer_ISR(void *arg);
#endif

/**
 *  @b Description
 *  @n
 *      Writeback the D2M block of data and trigger the BBE to R52 interrupt.
 */
static inline void Writeback_D2M_Send_R52_Notification(void *addr)
{
   /** Invoke BBE to R52 Trigger ISR*/
   xthal_dcache_block_writeback((void *)addr, sizeof(D2M_Msg_T));
   Dsp_Ptr->IRQ_ENA |= 0x01; // enable IRQ_ENA GPIO0 interrupt
   WUR_EXPSTATE(0x0001);     /* Write GPIO32 bit 0 */
}

/**
 *  @b Description
 *  @n
 *  When an exception is handled within the context of an interrupt handler the BBE will not come out
 *  of a software initiated reset cleanly, because the internal state of the XTOS interrupt mask is
 * configured to disable interrupts for handling the interrupt context.
 *
 * By setting @ref xtos_vpri_enabled back to all 1s, the interrupts will be appropriately handled.
 *
 */
static void Reset_XTOS_Internal_State(void)
{
   xtos_vpri_enabled = 0xFFFFFFFFU;
   xtos_enabled      = 0U;
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*===========================================================================*\
 * FUNCTION: Check_R52_To_BBE32_Header
 *===========================================================================
 * RETURN VALUE:
 * static uint8_t
 *
 * PARAMETERS:
 *            M2D_Msg_T * buf
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
uint8_t Check_R52_To_BBE32_Header(M2D_Msg_T *buf)
{
   uint8_t ret_val = CODED_FALSE;
#ifdef ENABLE_IPC_CRC
   uint32_t dsp_m2d_crc_calculated = 0U;
   /* increment expected message counter before check */
   DSP_M2D_Msg_Header_Cnt++;

   if ((buf != NULL) && (sizeof(M2D_Msg_T) == buf->header.size))
   {
      /* check message counter */
      if (buf->header.counter == DSP_M2D_Msg_Header_Cnt)
      {
   #ifdef ENABLE_IPC_CRC_PROFILING
         uint32_t crc_start_time = Timing_Helpers_Get_Timestamp();
   #endif

         dsp_m2d_crc_calculated = Calc_M2D_Buf_Crc(buf);

   #ifdef ENABLE_IPC_CRC_PROFILING
         DSP_M2D_CRC_Compute_Time_us = Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - crc_start_time);
         /* Track min/max M2D CRC computation time */
         if (DSP_M2D_CRC_Compute_Time_us > DSP_M2D_CRC_Compute_Time_Max_us)
         {
            DSP_M2D_CRC_Compute_Time_Max_us = DSP_M2D_CRC_Compute_Time_us;
         }
         if (DSP_M2D_CRC_Compute_Time_us < DSP_M2D_CRC_Compute_Time_Min_us)
         {
            DSP_M2D_CRC_Compute_Time_Min_us = DSP_M2D_CRC_Compute_Time_us;
         }
   #endif
         if (buf->header.crc == dsp_m2d_crc_calculated)
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
         DSP_M2D_Msg_Header_Cnt = buf->header.counter;
      }
   }
#else
   UNUSED_PARAM(buf);
   ret_val = CODED_TRUE;
#endif

   return (ret_val);
}
/**
 *  @b Description
 *  @n
 *      Initialize the D2M buffers to zero.
 */
void IPC_D2M_Buffer_Init(void)
{
   uint8_t index;
   for (index = 0; index < IPC_PING_PONG_COUNT; index++)
   {
      volatile D2M_Msg_T *d2m_ptr = Get_IPC_D2M_Msg_Buffer(index);

      volatile_memset((volatile void *)d2m_ptr, 0, sizeof(D2M_Msg_T));
      d2m_ptr->header.size = sizeof(D2M_Msg_T);
      d2m_ptr->header.crc  = 0;
   }
}

/**
 *  @b Description
 *  @n
 *      Send the @ref DSP_RANGE_PROCESSING_COMPLETE command to the R52 to signal RFFT completion.
 *
 *  @param[in]  void
 *
 *  @retval
 *      Not Applicable.
 */
void Send_Range_Proc_Complete(Error_Field_T error)
{
   if (Is_IPC_Notify_Buffer_Full(BBE_TO_R52_CORE) == false)
   {
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
      volatile D2M_Msg_T *d2m_msg_ptr                           = Get_RP_IPC_D2M_Msg_Buffer();

      DSP_PFM_Index = DSP_PFM_Index_Isr;

      ipc_notify_structure_ptr->command       = DSP_RANGE_PROCESSING_COMPLETE;
      ipc_notify_structure_ptr->curIpcAddr    = (uint32_t)d2m_msg_ptr;
      ipc_notify_structure_ptr->errorField    = error;
      ipc_notify_structure_ptr->pingPongIndex = RP_Buffer_Index;
      ipc_notify_structure_ptr->lookIndex     = d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index;
      ipc_notify_structure_ptr->pfm_index     = DSP_PFM_Index;

      /* Increment write index just before BBE_R52 Trigger to avoid race condition */
      Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
      Writeback_D2M_Send_R52_Notification((void *)ipc_notify_structure_ptr->curIpcAddr);
   }
   else
   {
      D2M_Buffer_Full_Error_Counter++;
   }

   DP_Rdd_Buffer_Index = RP_Buffer_Index;
}

/**
 *  @b Description
 *  @n
 *      Update the RDD stream and RDD debug stream headers' scan_index, size, and error_info fields.
 *
 *  @param[in]  d2m_msg_ptr - IPC D2M buffer whose stream headers are to be updated.
 *  @param[in]  error - Error field to stamp into the stream headers.
 *
 *  @retval
 *      Not Applicable.
 */
void Update_RDD_Stream_Header(volatile D2M_Msg_T *d2m_msg_ptr, Error_Field_T error)
{
   volatile Stream_Hdr_T *p_stream_hdr       = &d2m_msg_ptr->payload.rdd_stream_data.stream_hdr;
   volatile Stream_Hdr_T *p_debug_stream_hdr = &d2m_msg_ptr->payload.rdd_debug_data.stream_hdr;
   volatile Look_Data_T *p_look_data         = &d2m_msg_ptr->payload.rdd_stream_data.look_data;

   p_stream_hdr->scan_index = p_look_data->scan_index;
   p_stream_hdr->size       = sizeof(Rdd_Stream_T);
   p_stream_hdr->error_info = (uint16_t)error;

   p_debug_stream_hdr->scan_index = p_look_data->scan_index;
   p_debug_stream_hdr->size       = sizeof(Rdd_Debug_Stream_T);
   p_debug_stream_hdr->error_info = (uint16_t)error;
}

/**
 *  @b Description
 *  @n
 *      Send the @ref DSP_DOPPLER_PROCESSING_COMPLETE command to the R52 to signal DFFT-RDD completion.
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
void Send_Doppler_RDD_Proc_Complete(Error_Field_T error)
{
   if (Is_IPC_Notify_Buffer_Full(BBE_TO_R52_CORE) == false)
   {
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
      volatile D2M_Msg_T *d2m_msg_ptr                           = Get_DP_RDD_IPC_D2M_Msg_Buffer();

      ipc_notify_structure_ptr->command       = DSP_DOPPLER_PROCESSING_COMPLETE;
      ipc_notify_structure_ptr->curIpcAddr    = (uint32_t)d2m_msg_ptr;
      ipc_notify_structure_ptr->errorField    = error;
      ipc_notify_structure_ptr->pingPongIndex = DP_Rdd_Buffer_Index;
      ipc_notify_structure_ptr->lookIndex     = d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index;
      ipc_notify_structure_ptr->pfm_index     = DSP_PFM_Index;
      /* Increment write index just before BBE_R52 Trigger to avoid race condition */
      Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
      Writeback_D2M_Send_R52_Notification((void *)ipc_notify_structure_ptr->curIpcAddr);
   }
   else
   {
      D2M_Buffer_Full_Error_Counter++;
   }

   SP_Post_Proc_Buffer_Index = DP_Rdd_Buffer_Index;

   /** Assume overlapping AF and post processing with range processing. **/
   Ready_For_New_Frame = READY_FOR_RANGE_PROCESSING;
}

/**
 *  @b Description
 *  @n
 *      Send the @ref DSP_SP_POST_PROCESSING_COMPLETE command to the MSS to signal
 *         end of Signal Proc Post Algo processing completion.
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
void Send_SP_Post_Proc_Complete_to_R52(Error_Field_T error)
{
#ifdef ENABLE_IPC_CRC
   uint8_t chnl = ARM_CRC_CHANNEL1;
#endif
   if (Is_IPC_Notify_Buffer_Full(BBE_TO_R52_CORE) == false)
   {
      volatile D2M_Msg_T *d2m_msg_ptr = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
      // Disable all interrupts and save processor state

      DSP_D2M_Msg_Header_Cnt      = DSP_D2M_Msg_Header_Cnt + 1;
      d2m_msg_ptr->header.size    = sizeof(D2M_Msg_T);
      d2m_msg_ptr->header.counter = DSP_D2M_Msg_Header_Cnt;
      /* SWE5 Integration Testing: D2M send hook */
      SIT_IPC_TRANSFER_D2M_SEND((D2M_Payload_T *)&d2m_msg_ptr->payload);
#ifdef XCP_FAULT_INJECTION

      volatile M2D_Msg_T *m2d_msg_ptr = Get_IPC_M2D_Buffer();

      if (BBE_To_R52_Fault == m2d_msg_ptr->payload.xcp_fault_type)
      {
         d2m_msg_ptr->header.size = 0U;
      }
      else
      {
         /* Do Nothing */
      }
#endif
#ifdef ENABLE_IPC_CRC
   #ifdef ENABLE_IPC_CRC_PROFILING
      uint32_t crc_start_time = Timing_Helpers_Get_Timestamp();
   #endif
      d2m_msg_ptr->header.crc = Calc_D2M_Buf_Crc_Chn_X(d2m_msg_ptr, chnl);
   #ifdef ENABLE_IPC_CRC_PROFILING
      DSP_D2M_CRC_Compute_Time_us = Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - crc_start_time);

      /* Track min/max D2M CRC computation time */
      if (DSP_D2M_CRC_Compute_Time_us > DSP_D2M_CRC_Compute_Time_Max_us)
      {
         DSP_D2M_CRC_Compute_Time_Max_us = DSP_D2M_CRC_Compute_Time_us;
      }
      if (DSP_D2M_CRC_Compute_Time_us < DSP_D2M_CRC_Compute_Time_Min_us)
      {
         DSP_D2M_CRC_Compute_Time_Min_us = DSP_D2M_CRC_Compute_Time_us;
      }
   #endif
#else
      d2m_msg_ptr->header.crc                                   = 0U;
#endif

#ifndef IPC_BBE_FIXED_TRIGGER_ENABLE
      (void)xtos_interrupt_disable(SP2DSP_LVL1_INT);
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
      ipc_notify_structure_ptr->command                         = DSP_SP_POST_PROCESSING_COMPLETE;
      ipc_notify_structure_ptr->curIpcAddr                      = (uint32_t)d2m_msg_ptr;
      ipc_notify_structure_ptr->errorField                      = error;
      ipc_notify_structure_ptr->pingPongIndex                   = SP_Post_Proc_Buffer_Index;
      ipc_notify_structure_ptr->lookIndex                       = d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index;
      ipc_notify_structure_ptr->pfm_index                       = DSP_PFM_Index;
      /* Increment write index just before BBE_R52 Trigger to avoid race condition */
      Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
      Writeback_D2M_Send_R52_Notification((void *)ipc_notify_structure_ptr->curIpcAddr);
      /* Restore previous interrupt state */
      (void)xtos_interrupt_enable(SP2DSP_LVL1_INT);
#else
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = NULL;
      if (SP_Post_Proc_Buffer_Index < BUF_IDX_MAX)
      {
         ipc_notify_structure_ptr = &IPC_BBE2R52_Fixed_Notify_Msg[SP_Post_Proc_Buffer_Index];
      }
      else
      {
         /* Nothing*/
      }
      ipc_notify_structure_ptr->command       = DSP_SP_POST_PROCESSING_COMPLETE;
      ipc_notify_structure_ptr->curIpcAddr    = (uint32_t)d2m_msg_ptr;
      ipc_notify_structure_ptr->errorField    = error;
      ipc_notify_structure_ptr->pingPongIndex = SP_Post_Proc_Buffer_Index;
      ipc_notify_structure_ptr->lookIndex     = d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index;
      ipc_notify_structure_ptr->pfm_index     = DSP_PFM_Index;
#endif
   }
   else
   {
      D2M_Buffer_Full_Error_Counter++;
   }
}

/**
 *  @b Description
 *  @n
 *      Gives the IPC DSP to R52 local buffer address.
 *      Valid for Range and Doppler Processing. If needed for other processing blocks,
 *      will need to add a buffered copy of this, and return with a state copy, e.g. Get_IPC_M2D_Buffer_AF().
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
volatile M2D_Msg_T *Get_IPC_M2D_Buffer(void)
{
   return M2D_Buffer_Ptr;
}

/**
 *  @b Description
 *  @n
 *      Gives the IPC DSS to MSS ping or pong address to be used during Range Process process
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
volatile D2M_Msg_T *Get_RP_IPC_D2M_Msg_Buffer(void)
{
   return Get_IPC_D2M_Msg_Buffer(RP_Buffer_Index);
}

/**
 *  @b Description
 *  @n
 *      Gives the IPC DSS to MSS ping or pong address
 *       to be used during Doppler Process ,CFAR, RDD FP, RDD SP & Sweep BW processing.
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
D2M_Msg_T *Get_DP_RDD_IPC_D2M_Msg_Buffer(void)
{
   return Get_IPC_D2M_Msg_Buffer(DP_Rdd_Buffer_Index);
}

/**
 *  @b Description
 *  @n
 *      Gives the IPC DSS to MSS ping or pong address to be used during
 *       Angle Finding, Radar Capability and Alignment process.
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
volatile D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(void)
{
   return Get_IPC_D2M_Msg_Buffer(SP_Post_Proc_Buffer_Index);
}

/**
 *  @b Description
 *  @n
 *      Gives the IPC DSP to R52 One Time local buffer address.
 *
 *  @param[in]
 *
 *  @retval
 *      Not Applicable.
 */
volatile M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer(void)
{
   return M2D_One_Time_Msg_Ptr;
}

/**
 *  @b Description
 *  @n
 *      API to receive the R52 to DSP triggers
 *
 *
 */
void Update_DSP_IPC_Notify(void)
{
   while (Is_IPC_Notify_Buffer_Empty(R52_TO_BBE_CORE) == false)
   {
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_in_ptr = Get_IPC_Notify_Buffer(R52_TO_BBE_CORE, READ_BUFFER);

      switch (ipc_notify_structure_in_ptr->command)
      {
         case (R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION):
         {
            DSP_RA_Error_Flag = CODED_FALSE;
            if (Is_IPC_Notify_Buffer_Full(BBE_TO_R52_CORE) == false)
            {
               M2D_Msg_T *m2d_msg_ptr = (M2D_Msg_T *)ipc_notify_structure_in_ptr->curIpcAddr;
               volatile Ipc_Notify_Structure_T *ipc_notify_structure_out_ptr =
                  Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
               Profiling_Helpers_Update(&IPC_Profiling);

               /* CRC check*/
               if ((CODED_TRUE == Check_R52_To_BBE32_Header(m2d_msg_ptr)) ||
                   (CODED_TRUE == m2d_msg_ptr->payload.hil_ipc_info.hil_mode_enabled))
               {
                  Radar_Look_T look_type = m2d_msg_ptr->payload.look_Info.look_type;
                  D2M_Msg_T *d2m_msg_ptr = NULL;

                  M2D_Buffer_Ptr        = m2d_msg_ptr;
                  Offline_Mode_Flag_DSP = m2d_msg_ptr->payload.offline_mode_flag;

                  /* To receive IT data from M2D, for Integration Testing */
                  SIT_IPC_TRANSFER_M2D_RECEIVE((const M2D_Payload_T *)&m2d_msg_ptr->payload);

                  if ((ITF_ADC_INJECTION_MODE == Offline_Mode_Flag_DSP) ||
                      (ITF_DATA_CUBE_INJECTION_MODE == Offline_Mode_Flag_DSP) ||
                      (ITF_TEST_COLLECTION_MODE == Offline_Mode_Flag_DSP))
                  {
                     /* When offline mode is configured to a specific ITF test mode, then force the IPC D2M buffer to 0. */
                     RP_Buffer_Index = 0U;
                  }
                  else
                  {
                     /* Normal (default) operation is to swap the current IPC buffer. */
                     RP_Buffer_Index = RP_Buffer_Index ^ 1U;
                  }

                  d2m_msg_ptr = Get_IPC_D2M_Msg_Buffer(RP_Buffer_Index);

                  /*Reset the IPC RDD buffer*/
                  vector_clear(&(d2m_msg_ptr->payload.rdd_stream_data), sizeof(Rdd_Stream_T));
                  vector_clear(&(d2m_msg_ptr->payload.rdd_debug_data), sizeof(Rdd_Debug_Stream_T));
                  vector_clear(&(d2m_msg_ptr->payload.dsp_timing_data), sizeof(DSP_Timing_Data_T));
                  d2m_msg_ptr->payload.rdd_stream_data.look_data.look_id    = (uint16_t)look_type;
                  d2m_msg_ptr->payload.rdd_stream_data.look_data.mode       = (uint8_t)m2d_msg_ptr->payload.look_Info.mode;
                  d2m_msg_ptr->payload.rdd_stream_data.look_data.scan_index = m2d_msg_ptr->payload.look_Info.scan_index;

                  /* Update XCP info in the D2M structure. */
#if ENABLE_ADC_DATA_LOGGING == (1U)
                  d2m_msg_ptr->payload.xcp_data.xcp_adc_chirp         = m2d_msg_ptr->payload.xcp_info.xcp_adc_chirp_num;
                  d2m_msg_ptr->payload.xcp_data.xcp_adc_restore_chirp = m2d_msg_ptr->payload.xcp_info.xcp_adc_restore_chirp_num;
                  d2m_msg_ptr->payload.xcp_data.xcp_light_comp_range  = m2d_msg_ptr->payload.xcp_info.xcp_light_comp_range_num;
#endif
                  /*This is for testing fixed trigger design by introducing the range process timeout. There shall be no change in
                   * the delta time calc on R52 side.*/
#ifdef IPC_BBE_FIXED_TRIGGER_DEBUG_ENABLE
                  if (Look_Type_Induce_Err)
                  {
                     look_type = ((look_type + 1U) % MAX_NUM_LOOKS);
                  }
#endif
                  ipc_notify_structure_out_ptr->errorField =
                     Appl_Range_Process_Trigger(look_type) ? ERRORFIELD_NO_ERROR : ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR;
               }
               else
               {
                  /** Log IPC error*/
                  ipc_notify_structure_out_ptr->errorField = R52_TO_BBE32_CRC_ERROR;
                  IPC_M2D_Buffer_Err_Cnt++;
               }
               /* Increment the PFM counter */
               DSP_PFM_Index_Isr++;
               /** Invoke BBE to R52 Trigger using ISR*/
               ipc_notify_structure_out_ptr->command       = DSP_RANGE_CONFIGURATION_COMPLETE;
               ipc_notify_structure_out_ptr->pingPongIndex = RP_Buffer_Index;
               ipc_notify_structure_out_ptr->pfm_index     = DSP_PFM_Index_Isr;
               /* Increment write index just before BBE_R52 Trigger to avoid race condition */
               Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
               /* Enable IRQ_ENA GPIO0 interrupt */
               Dsp_Ptr->IRQ_ENA |= 0x01;
               /* Write GPIO32 bit 0 */
               WUR_EXPSTATE(0x0001);
            }
            else
            {
               D2M_Buffer_Full_Error_Counter++;
            }
         }
         break;
         case (R52_RA_ERROR_FAULT):
         {
            DSP_RA_Error_Flag = CODED_TRUE;
         }
         break;
         case CORE_INITIALIZED:
         {
            // At startup, Appl_DSP_Process_Onetime_Init() is called, which sends
            // CORE_INITIALIZED to the R52. That function is blocked until the R52 replies,
            // and the Mss_Init_Received is set to indicate that the R52 has done initialization
            // of the shared IPC buffers.
            Mss_Init_Received    = TRIGGER_RECEIVED;
            M2D_One_Time_Msg_Ptr = (M2D_One_Time_Msg_T *)ipc_notify_structure_in_ptr->curIpcAddr;
         }
         break;
      }
      Increment_IPC_Notify_ReadIndx(R52_TO_BBE_CORE);
   }
}

/**
 *  @b Description
 *  @n
 *      API to initiate range process
 *
 *
 */
static bool Appl_Range_Process_Trigger(Radar_Look_T look_type)
{
   bool appl_range_proc_success = false;

   /* Check that the CORE_INITIALIZED message was received. */

   if (Ready_For_New_Frame == READY_FOR_RANGE_PROCESSING)
   {
      appl_range_proc_success = Appl_Range_Process_Init(look_type);
      Ready_For_New_Frame     = RUNNING_LOOK_PROCESSING;
   }
   else
   {
      appl_range_proc_success = false;
   }

   if (appl_range_proc_success)
   {
      IPC_R52_To_BBE_Trigger_Received = TRIGGER_RECEIVED;
      Set_BBE_To_R52_Trigger_Timer();
   }
   else
   {
      IPC_R52_To_BBE_Trigger_Received = NO_TRIGGER;
      IPC_R52_Trigger_Failed++;
   }

   return appl_range_proc_success;
}

/**
 *  @b Description
 *  @n
 *      API to send Core Init trigger to R52
 *
 *
 */
void Send_Core_Initialization(void)
{
   if (Is_IPC_Notify_Buffer_Full(BBE_TO_R52_CORE) == false)
   {
      volatile Ipc_Notify_Structure_T *ipc_notify_structure_out_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
      /** Invoke BBE to R52 Trigger using ISR*/

      ipc_notify_structure_out_ptr->command = CORE_INITIALIZED;
#ifdef CDC_ENABLE
      ipc_notify_structure_out_ptr->curIpcAddr = (uint32_t)&Cdc_Frame_Interface;
#endif
      /* Increment write index just before BBE_R52 Trigger to avoid race condition */
      Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
      /* Enable IRQ_ENA GPIO0 interrupt */
      Dsp_Ptr->IRQ_ENA |= 0x01;
      /* Write GPIO32 bit 0 */
      WUR_EXPSTATE(0x0001);
   }
   else
   {
      D2M_Buffer_Full_Error_Counter++;
   }
}

static void __attribute__((section(".sram0.text"))) SP2DSP_LVL1_Handler(void *arg)
{
   /*
    * Buffer for saving coprocessor state.
    * This interrupt makes use of DSP vector instructions to improve its
    * execution speed. However, this has the side-effect of corrupting the BBE
    * coprocessor state and we need to manually restore it before returning
    * from the interrupt handler.
    */
   uint8_t sp2dsp_copro_save_buffer[XCHAL_CP1_SA_SIZE /* 1696 bytes */] __attribute__((aligned(XCHAL_CP1_SA_ALIGN)));
   UNUSED_PARAM(arg);

   /* save the DSP cp context */
   xthal_save_cpregs(sp2dsp_copro_save_buffer, XCHAL_CP_ID_CONNX_BBE32);
   /* begin interrupt body */

   xtos_interrupt_clear(SP2DSP_LVL1_INT);
   Update_DSP_IPC_Notify();
   SP2DSP_LVL1_Handler_test_var++;

   /* end interrupt body */
   /* restore the DSP cp context */
   xthal_restore_cpregs(sp2dsp_copro_save_buffer, XCHAL_CP_ID_CONNX_BBE32);
}

/**
 * @brief Wait up to @ref DEFAULT_TIMEOUT_US for a trigger signal to be set to triggered state.
 *
 * @param[in] trigger_ptr - pointer to trigger value that should get updated
 *
 *  @retval
 *      true - trigger happened, timeout reached
 **/
bool Wait_For_Trigger(volatile uint32_t *trigger_ptr)
{
   uint32_t timeout_start   = Timing_Helpers_Get_Timestamp();
   uint32_t time_elapsed_us = 0U;

   /* Wait up to timeout */
   while ((NO_TRIGGER == XT_L32AI(trigger_ptr, 0)) && //
          (DEFAULT_TIMEOUT_US >= time_elapsed_us))
   {
      Waiting_For_Trigger++;
      time_elapsed_us = Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - timeout_start);
   }

   return (DEFAULT_TIMEOUT_US >= time_elapsed_us);
}

/**
 *  @b Description
 *  @n
 *      Initialize OneTime DSP processing configuration
 *
 *
 */
void Appl_DSP_Process_Onetime_Init(void)
{
   Reset_XTOS_Internal_State();

   (void)xtos_set_interrupt_handler(SP2DSP_LVL1_INT, (xtos_handler)SP2DSP_LVL1_Handler, NULL, NULL);
   (void)xtos_interrupt_enable(SP2DSP_LVL1_INT);

   (void)xtos_set_interrupt_handler(RA_CMD_DONE_ISR, (xtos_handler)Appl_Range_Process_Chirp_Callback, NULL, NULL);

#ifdef IPC_BBE_FIXED_TRIGGER_ENABLE
   /** Register the Timer0 Isr */
   (void)xtos_set_interrupt_handler(XCHAL_TIMER0_INTERRUPT, (xtos_handler)Timer_ISR, (void *)&Fixed_Trigger_Data[BUF_IDX_PING],
                                    NULL);

   /** Register the Timer1 Isr */
   (void)xtos_set_interrupt_handler(XCHAL_TIMER1_INTERRUPT, (xtos_handler)Timer_ISR, (void *)&Fixed_Trigger_Data[BUF_IDX_PONG],
                                    NULL);
#endif

   Appl_MIPI_One_Time_Init();

   /** @note: DSP application communicates with R52 over IPC to get One time Init input data during Init phase.
    * Unless valid data is received, DSP application should not proceed further.
    * @todo If needed, this could be in future enhanced with max retries and then go into some permanent fault state.
    */

   Profiling_Helpers_Init(&IPC_Profiling, true);

   do
   {
      Ready_For_New_Frame = INVALID_STATE;
      Mss_Init_Received   = NO_TRIGGER;

      //  Send the CORE_INITIALIZED message to the R52, to clear and initialize the buffers.
      Send_Core_Initialization();
      Wait_For_Trigger((volatile uint32_t *)&Mss_Init_Received);

      if (NULL != M2D_One_Time_Msg_Ptr)
      {
         SMC_Cal_Data_Ptr = (SMC_Cal_T *)M2D_One_Time_Msg_Ptr->smc_sram_address;
         USC_Cal_Data_Ptr = (USC_Cal_T *)M2D_One_Time_Msg_Ptr->usc_sram_address;
      }

      if ((NULL == SMC_Cal_Data_Ptr) || (NULL == USC_Cal_Data_Ptr)) // TODO sandeep: Update USC ptr
      {
         Mss_Init_Received = NO_TRIGGER;
      }
   } while ((NULL == SMC_Cal_Data_Ptr) || (NULL == USC_Cal_Data_Ptr));

   Ready_For_New_Frame = READY_FOR_RANGE_PROCESSING;

   IPC_D2M_Buffer_Init();
   IDMA_Helper_Init();
}

/*****************************************************************************
 *. Name: Get_IPC_D2M_Msg_Buffer
 *. This function will get the pointer to ipc buffer
 *.
 *. Parameters:
 *. buf_cnt - 0 or 1
 *.
 *. Return Value: D2M_Msg_T*
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
D2M_Msg_T *Get_IPC_D2M_Msg_Buffer(uint8_t buf_cnt)
{
   return (D2M_Msg_T *)&IPC_D2M_Buffer[buf_cnt];
}
/**
 *  @b Description
 *  @n
 *
 *       This API resets Angle Finding IPC buffers every Radar cycle
 *
 *  @param[in]
 *
 *  @retval
 *      void
 */
void Reset_IPC_AF_Buffer(bool hil_detection_stream_injection_mode, bool hil_downselection_stream_injection_mode)
{
   volatile D2M_Msg_T *p_d2m_data = Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();

   if (hil_detection_stream_injection_mode | hil_downselection_stream_injection_mode)
   {
      /* Bypass memory clear during HIL mode. Allow memory clear during RDD injection*/
   }
   else
   {
      (void)vector_clear((void *)(uintptr_t) & (p_d2m_data->payload.xcp_af_data), sizeof(Angle_Data_XCP_T));
      (void)vector_clear((void *)(uintptr_t) & (p_d2m_data->payload.det_data), sizeof(Detection_Stream_T));
      (void)vector_clear((void *)(uintptr_t) & (p_d2m_data->payload.det_debug_data), sizeof(Detection_Debug_Stream_T));
      (void)vector_clear((void *)(uintptr_t) & (p_d2m_data->payload.dsp_timing_data.af_time), sizeof(Angle_Timing_Data_T));
#if (DOWNSELECTION_ENABLE == 1U)
      (void)vector_clear((void *)(uintptr_t) & (p_d2m_data->payload.downselection_data), sizeof(Down_selection_Stream_T));
#endif
   }
}

/**
 * FUNCTION:TOI_Radar_Status_Info_Init(TOI_Input_Params_T *toi_input_ptr)
 *    Returns void
 *
 * \param[in]     TOI_Input_Params_T *toi_input_ptr
 *
 * \return         none
 *
 * \ServID         xx
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 *
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 :
 *
 * SRD
 * WorkItem 1 :
 */
void TOI_Radar_Status_Info_Init(TOI_Input_Params_T *toi_input_ptr)
{
   D2M_Msg_T *d2m_ptr = (D2M_Msg_T *)(uintptr_t)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   M2D_Msg_T *m2d_ptr = (M2D_Msg_T *)(uintptr_t)Get_IPC_M2D_Buffer();

   if ((NULL != d2m_ptr) && (NULL != m2d_ptr))
   {
      toi_input_ptr->toi_data_status_dst_ptr = &Get_TOI_DATA_STATUS_DST_PTR(d2m_ptr);
      toi_input_ptr->radar_ip_sts_ptr        = m2d_ptr->payload.Radar_Sts_Ptr;
   }
}

/*===========================================================================*\
 * FUNCTION: Set_MMIC_Data_Discard_Info
 *          This function sets the data discard info received From MMIC
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * void
 *
 * EXTERNAL REFERENCES:
 * None.
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 *
 \*===========================================================================*/
void Set_MMIC_Data_Discard_Info(void)
{
   TOI_Input_Params_T *const toi_input_params_ptr          = Get_TOI_Init_Parameters();
   IPC_MMIC_Radar_Data_Status_T *m2d_radar_data_status_ptr = NULL;

   TOI_Radar_Status_Info_Init(toi_input_params_ptr);

   TOI_RADAR_DATA_PAYLOAD_T *p_toi_data_status_dst = NULL;
   p_toi_data_status_dst                           = (TOI_RADAR_DATA_PAYLOAD_T *)toi_input_params_ptr->toi_data_status_dst_ptr;

   m2d_radar_data_status_ptr = (IPC_MMIC_Radar_Data_Status_T *)toi_input_params_ptr->radar_ip_sts_ptr;

   toi_input_params_ptr->crc_mismatch = Compute_DSS_Rdr_Data_Sts_Payload_CRC(m2d_radar_data_status_ptr);

   if ((m2d_radar_data_status_ptr != NULL) && (toi_input_params_ptr->crc_mismatch == CODED_FALSE))
   {
      memcpy(p_toi_data_status_dst, &m2d_radar_data_status_ptr->radar_data_status_payload, sizeof(Radar_Data_Status_Payload_T));
   }
   else
   {
      /* Do nothing */
   }
}

/******************************************************************************
 *. Name: Compute_DSS_Rdr_Data_Sts_Payload_CRC
 *. This function computes CRC for DSS Radar Data Status Payload.
 *. Parameters: IPC_MMIC_Radar_Data_Status_T*
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues: DDR-4208
 ******************************************************************************/
static uint8_t Compute_DSS_Rdr_Data_Sts_Payload_CRC(IPC_MMIC_Radar_Data_Status_T *m2d_rdr_data_sts_ptr)
{
   uint32_t toi_radar_data_status_crc = 0U;
   uint8_t crc_mismatch               = CODED_FALSE;
   /* Increment dss crc counter every radar cycle*/
   DSS_Radar_Status_CRC_Count++;

   /* The size check between Radar_Data_Status_Payload_T and TOI_Radar_Data_Status_T structures is done using STATIC_ASSERT above
    */

   if (m2d_rdr_data_sts_ptr != NULL)
   {
      /* Count match to ensure DSS CRC validation done with the MSS crc calculated for the same radar cycle */
      if (m2d_rdr_data_sts_ptr->radar_data_status_header.alive_counter == DSS_Radar_Status_CRC_Count)
      {
         /* Re-calculation of CRC for Radar Data Status payload */
         toi_radar_data_status_crc = Compute_CRC32_SW((uint8_t *)(&(m2d_rdr_data_sts_ptr->radar_data_status_payload)),
                                                      (uint32_t)(sizeof(Radar_Data_Status_Payload_T)), 0, true);
         /* Check if CRC matches */
         if (toi_radar_data_status_crc == m2d_rdr_data_sts_ptr->radar_data_status_header.radar_data_status_crc)
         {
            crc_mismatch = CODED_FALSE;
         }
         else
         {
            crc_mismatch = CODED_TRUE;
         }
      }
      else
      {
         crc_mismatch               = CODED_TRUE;
         DSS_Radar_Status_CRC_Count = m2d_rdr_data_sts_ptr->radar_data_status_header.alive_counter;
      }
   }
   return crc_mismatch;
}

#ifdef IPC_BBE_FIXED_TRIGGER_ENABLE
/**
 *  @b Description
 *  @n
 *      Set the BBE to R52 trigger timer based on the range processing error status and the current look's dwell time delta.
 *
 *  @param[in]
 *
 *  @retval
 *      None
 */
static void Trigger_BBE_TO_R52(uint16_t buffer_index)
{
   volatile Ipc_Notify_Structure_T *ipc_notify_structure_ptr = Get_IPC_Notify_Buffer(BBE_TO_R52_CORE, WRITE_BUFFER);
   if (buffer_index < BUF_IDX_MAX)
   {
      (void)memcpy((void *)ipc_notify_structure_ptr, (const void *)&IPC_BBE2R52_Fixed_Notify_Msg[buffer_index],
                   sizeof(Ipc_Notify_Structure_T));
   }
   else
   {
      /* Nothing */
   }

   /* Increment write index just before BBE_R52 Trigger to avoid race condition */
   Increment_IPC_Notify_WriteIndx(BBE_TO_R52_CORE);
   Writeback_D2M_Send_R52_Notification((void *)ipc_notify_structure_ptr->curIpcAddr);
}

/**
 *  @b Description
 *  @n
 *      Set the BBE to R52 trigger timer based on the range processing error status and the current look's dwell time delta.
 *
 *  @param[in]
 *
 *  @retval
 *      None
 */
static void Set_BBE_To_R52_Trigger_Timer(void)
{
   uint16_t current_idx                                    = (BUF_IDX_PING == RP_Buffer_Index) ? BUF_IDX_PING : BUF_IDX_PONG;
   volatile Fixed_Trigger_Struct_T *fixed_trigger_data_ptr = &Fixed_Trigger_Data[current_idx];
   uint32_t start_timestamp                                = Timing_Helpers_Get_Timestamp();
   uint32_t end_timestamp                                  = start_timestamp + (uint32_t)GET_FIXED_TRIGGER_COUNT;

   fixed_trigger_data_ptr->trigger_timestamp = start_timestamp;
   fixed_trigger_data_ptr->buffer_index      = current_idx;

   if (BUF_IDX_PING == current_idx)
   {
      fixed_trigger_data_ptr->timer_used = XCHAL_TIMER0_INTERRUPT;
      xthal_set_ccompare0(end_timestamp);
      xtos_interrupt_enable(XCHAL_TIMER0_INTERRUPT);
   }
   else
   {
      fixed_trigger_data_ptr->timer_used = XCHAL_TIMER1_INTERRUPT;
      xthal_set_ccompare1(end_timestamp);
      xtos_interrupt_enable(XCHAL_TIMER1_INTERRUPT);
   }
}

/**
 *  @b Description
 *  @n
 *      xtensa timer0 for IPC_BBE2R52 Ping buffer trigger.
 *
 *  @param[in]
 *
 *  @retval
 *      None
 */
static void Timer_ISR(void *arg)
{
   Fixed_Trigger_Struct_T *data_ptr = (Fixed_Trigger_Struct_T *)arg;
   uint32_t interrupt_number        = data_ptr->timer_used;
   uint16_t buffer_index            = data_ptr->buffer_index;

   data_ptr->trigger_offset_us = Timing_Helpers_Get_Time_Microsec(Timing_Helpers_Get_Timestamp() - data_ptr->trigger_timestamp);

   xtos_interrupt_disable(interrupt_number);
   xtos_interrupt_clear(interrupt_number);

   data_ptr->trigger_count++;
   Trigger_BBE_TO_R52(buffer_index);
}
#endif
/******************************************************************************
 *. Name: Get_DSP_RA_Error_Status
 *. This function returns the RA Error status received from R52.
 *. Parameters:
 *. Return Value: uint8_t
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.

 ******************************************************************************/

uint8_t Get_DSP_RA_Error_Status(void)
{
   return DSP_RA_Error_Flag;
}
