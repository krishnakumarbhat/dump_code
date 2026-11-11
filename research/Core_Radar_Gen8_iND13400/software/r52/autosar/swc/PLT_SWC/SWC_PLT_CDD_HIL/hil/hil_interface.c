/*===========================================================================*/
/**
 * @file hil_interface.c
 *
 * Add a one line description of the implementation.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This fle contains the RDD processing implementation
 *
 * @section ABBR ABBREVIATIONS:
 *   -List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     -Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdlib.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_CDD_Logging.h"
#include "SWC_PLT_CDD_Logging.h"
//#include "SWC_TKEY_CDD_ECUSync_external.h"
#include "SoAd.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "dsp_setup.h"
#include "fixmac.h"
#include "hil_communication_handler.h"
#include "hil_interface.h"
#include "hil_types.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "platformtime.h"
#include "rdd_stream.h"
#include "reuse.h"
#include "sh_comm.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
//#define CONTIGUOUS_MEMORY /*This is enabled as per the project requirement*/
#ifdef CONTIGUOUS_MEMORY
   #define HIL_BUFFER_DEPTH (100U) /*100KB buffer storage*/
#endif
#define HIL_BUFFER_SIZE (ETH_DATA_PAYLOAD)
#define NUM_IPC_INDEX   (2U)
/*===========================================================================*
 * Local Preprocessor code
 *===========================================================================*/

/*===========================================================================*
 * Import function prototypes
 *===========================================================================*/
extern D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(void);
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef struct Stream_Memory_Map_Tag
{
   uint8_t stream_id;
   uint8_t *stream_addr;
} Stream_Memory_Map_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#define SWC_PLT_CDD_HIL_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*delcare all the variable within this macro */
volatile static Stream_Memory_Map_T Stream_Memory_Map[MAX_NUM_STRMS][NUM_IPC_INDEX];
volatile static uint8_t Number_Of_Streams_Initialized = 0U;

#ifdef CONTIGUOUS_MEMORY
uint8_t HIL_APP_BUF[HIL_BUFFER_DEPTH][HIL_BUFFER_SIZE]; /*HIL App Buffer array*/
#endif
static uint8_t HIL_Ipc_Index = 0U;

uint32_t HIL_Ping_Index     = 0U;
uint32_t HIL_Pong_Index     = 0U;
uint32_t HIL_Mem_Update     = 0U;
D2M_Msg_T *IPC_D2M_Buff_Ptr = NULL;

#define SWC_PLT_CDD_HIL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_PLT_CDD_HIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*===========================================================================*
 * Local function prototype
 *===========================================================================*/
static void Update_HIL_App_Buf_Addr(void);
void Update_HIL_Input_Interface(void);
static uint32_t Get_HIL_Timestamp_ms(void);
#ifndef CONTIGUOUS_MEMORY
static void Add_Stream_Map_Entry(uint8_t *stream_idx, uint8_t ipc_index, uint8_t stream_id, uint8_t *stream_addr);
#endif
/*===========================================================================*
 * import objects
 *===========================================================================*/

/*===========================================================================*
 * Local function Definitions
 *===========================================================================*/
#ifndef CONTIGUOUS_MEMORY
/******************************************************************************
 *. Name: Add_Stream_Map_Entry
 *.
 *. Description:
 *.    Helper to add a single entry to the Stream_Memory_Map table.
 *.    Checks that *stream_idx has not exceeded MAX_NUM_STRMS before writing.
 *.
 *. Parameters:
 *.    stream_idx  - pointer to the running stream index (incremented on success)
 *.    ipc_index   - current IPC ping/pong slot (0 or 1)
 *.    stream_id   - stream number from the stream configuration table
 *.    stream_addr - pointer to the backing IPC buffer for this stream
 *.
 *. Return Value: void
 ******************************************************************************/
static void Add_Stream_Map_Entry(uint8_t *stream_idx, uint8_t ipc_index, uint8_t stream_id, uint8_t *stream_addr)
{
   if (*stream_idx < MAX_NUM_STRMS)
   {
      Stream_Memory_Map[*stream_idx][ipc_index].stream_id   = stream_id;
      Stream_Memory_Map[*stream_idx][ipc_index].stream_addr = stream_addr;
      (*stream_idx)++;
   }
}
#endif

/******************************************************************************
 *. Name: Update_HIL_Input_Interface
 *.
 *. Description:
 *.    Central per-frame synchronisation function that keeps the HIL subsystem
 *.    consistent with the current R52 ↔ BBE32 IPC state. It is called from
 *.    HIL_Periodic_Handler() once per frame, immediately after the
 *.    DSP_SP_POST_PROCESSING_COMPLETE interrupt triggers the HIL runnable.
 *.
 *.    The function performs the following operations in order:
 *.
 *.    1. D2M Ping/Pong Buffer Selection
 *.          Reads Get_DSP_Write_IPC_Index() to determine which D2M buffer
 *.          (ping or pong) BBE32 has just finished writing to. The pointer
 *.          IPC_D2M_Buff_Ptr is set to the matching buffer via
 *.          Get_D2M_Ping_Buf_Addr() or Get_D2M_Pong_Buf_Addr(), and the
 *.          corresponding frame counter (HIL_Ping_Index / HIL_Pong_Index) is
 *.          incremented for diagnostics.
 *.
 *.    2. HIL_Input_T Population
 *.          Populates the HIL_Input_T structure (read by the HIL PC tool) with:
 *.            - hil_tx_message_fptr       : SoAd_IfTransmit (Ethernet Tx callback)
 *.            - hil_get_source_time_fptr  : Get_HIL_Timestamp_ms (timestamp source)
 *.            - stream_table_cfg_ptr      : pointer to the stream configuration table
 *.            - stream_info_ptr           : pointer to the stream information list
 *.
 *.    3. M2D IPC Buffer Update  [guard: ipc_m2d_buff_ptr != NULL]
 *.          Writes the HIL injection command for the NEXT frame into the
 *.          M2D IPC buffer (consumed by BBE32 on the following trigger):
 *.            - hil_mode_enabled          : global HIL enable flag
 *.            - hil_entry_point           : injection entry point selector
 *.            - hil_scanindex             : scan index to inject into BBE32
 *.            - hil_data_src_af/alignment/id/radar_capability : per-module
 *.                                          source selection (embedded algo vs.
 *.                                          HIL-injected data)
 *.            - hil_src_* fields          : vehicle data / timestamp / mounting
 *.                                          data source selectors
 *.            - hil_enabled_streams[]     : memcpy of the full stream-enable
 *.                                          bitmap from HIL_Output_T
 *.
 *.    4. Stream Memory Map Rebuild
 *.          [guard: both buffers valid, HIL_Ipc_Index == DSP_Write_IPC_Index,
 *.           stream_idx == 0 (first entry)]
 *.          Rebuilds the Stream_Memory_Map[stream][ipc_index] table that maps
 *.          each stream ID to its backing IPC buffer address for the current
 *.          ping/pong slot. Streams mapped (in order):
 *.            DETECTION, VSE, HEADER, RDD, ALIGNMENT, DRA,
 *.            RADAR_CAPABILITY, STATUS,
 *.            ROT_ISOOBJECT, ROT_VEHICLEINFO, ROT_PROCESSEDDETECTION,
 *.            ROT_SAFETY_FAULTS, ROT_TRACKERINFO  (#ifndef ROT_NONE),
 *.            DOWN_SELECTION  (#if DOWNSELECTION_ENABLE)
 *.          Number_Of_Streams_Initialized is updated with the final count.
 *.          Followed by Update_HIL_App_Buf_Addr() which resolves each
 *.          hil_init_table entry's buffer pointer from the rebuilt map.
 *.
 *.    5. Internal Pointer Update
 *.          Calls Update_HIL_Internal_Memory_Pointers() to propagate any
 *.          address changes into the HIL communication handler layer.
 *.
 *. Parameters:  void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
void Update_HIL_Input_Interface(void)
{
   HIL_Input_T *hil_input_data_ptr      = Get_HIL_Input_Data_Ptr();
   HIL_Output_T *hil_output_data_ptr    = Get_HIL_Output_Data_Ptr();
   uint8_t hil_m2d_buf_idx_injection    = Get_Fetch_M2D_Buffer_Idx_HIL_Injection();
   M2D_Msg_T *ipc_m2d_buff_ptr          = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buf_Addr(hil_m2d_buf_idx_injection);
   Stream_Cfg_T *stream_table_info_addr = Get_SH_Output_Data_Ptr()->sh_stream_table_cfg_ptr;
   Stream_Info_T *stream_list_info_addr = Get_SH_Output_Data_Ptr()->sh_stream_info_ptr;
   uint8_t stream_idx                   = 0U;

   if (0U == Get_DSP_Write_IPC_Index())
   {
      HIL_Ping_Index++;
      IPC_D2M_Buff_Ptr = (D2M_Msg_T *)(uintptr_t)Get_D2M_Ping_Buf_Addr();
      HIL_Ipc_Index    = 0U;
   }
   else
   {
      HIL_Pong_Index++;
      IPC_D2M_Buff_Ptr = (D2M_Msg_T *)(uintptr_t)Get_D2M_Pong_Buf_Addr();
      HIL_Ipc_Index    = 1U;
   }

   /* HIL Input */
   hil_input_data_ptr->hil_tx_message_fptr      = &SoAd_IfTransmit;
   hil_input_data_ptr->hil_get_source_time_fptr = &Get_HIL_Timestamp_ms;
   hil_input_data_ptr->stream_table_cfg_ptr     = stream_table_info_addr;
   hil_input_data_ptr->stream_info_ptr          = stream_list_info_addr;
   hil_input_data_ptr->hil_ipc_index            = HIL_Ipc_Index;

   if (NULL != IPC_D2M_Buff_Ptr)
   {
      HIL_Rx_Mailbox_T *const hil_rx_mailbox = &IPC_D2M_Buff_Ptr->payload.hil_rx_mailbox;
      /* If Wait_For_HIL_Rx_Complete() timed out but the final HIL frame arrives later,
         clear the flag at the start of the next cycle. */
      hil_rx_mailbox->hil_rx_complete_flag     = CODED_FALSE;
      hil_input_data_ptr->hil_rx_complete_flag = &(hil_rx_mailbox->hil_rx_complete_flag);
   }

   if (NULL != ipc_m2d_buff_ptr)
   {
      HIL_Ipc_Info_T *hil_ipc_ptr = &(ipc_m2d_buff_ptr->payload.hil_ipc_info);

      hil_input_data_ptr->current_radar_scan_index = ipc_m2d_buff_ptr->payload.look_Info.scan_index;

      /* HIL OUTPUT */
      hil_ipc_ptr->hil_mode_enabled              = hil_output_data_ptr->hil_mode_enabled;
      hil_ipc_ptr->hil_entry_point               = hil_output_data_ptr->hil_entry_point;
      hil_ipc_ptr->hil_scanindex                 = hil_output_data_ptr->hil_scanindex;
      hil_ipc_ptr->hil_data_src_af               = hil_output_data_ptr->hil_comp_data_output_src_cfg.hil_data_src_af;
      hil_ipc_ptr->hil_data_src_alignment        = hil_output_data_ptr->hil_comp_data_output_src_cfg.hil_data_src_alignment;
      hil_ipc_ptr->hil_data_src_id               = hil_output_data_ptr->hil_comp_data_output_src_cfg.hil_data_src_id;
      hil_ipc_ptr->hil_data_src_radar_capability = hil_output_data_ptr->hil_comp_data_output_src_cfg.hil_data_src_radar_capability;
      hil_ipc_ptr->hil_src_radar_mounting_data   = hil_output_data_ptr->hil_data_source_cfg.hil_src_radar_mounting_data;
      hil_ipc_ptr->hil_src_timestamp             = hil_output_data_ptr->hil_data_source_cfg.hil_src_timestamp;
      hil_ipc_ptr->hil_src_vehicle_data          = hil_output_data_ptr->hil_data_source_cfg.hil_src_vehicle_data;
      hil_ipc_ptr->hil_src_fusion_data           = hil_output_data_ptr->hil_data_source_cfg.hil_src_fusion_data;
      hil_ipc_ptr->hil_request_disable_fusion    = hil_output_data_ptr->hil_comp_data_output_src_cfg.hil_request_to_stop_fusion;

      /* MAX_STREAMS_SH macro size must be same in both ipc_data.h & hil_communication_stream.h */
      memcpy(hil_ipc_ptr->hil_enabled_streams, hil_output_data_ptr->hil_enabled_streams,
             sizeof(hil_output_data_ptr->hil_enabled_streams));
   }
   if ((NULL != IPC_D2M_Buff_Ptr) && (NULL != ipc_m2d_buff_ptr) && (HIL_Ipc_Index < NUM_IPC_INDEX) &&
       (0U == stream_idx)) /* GCOVR_EXCL_BR_LINE */
   {
#ifndef CONTIGUOUS_MEMORY
      HIL_Mem_Update++;
      /* all memory info must be initialized here for non contigeous memory allocation */
      /* stream_idx is important info never miss to update before add new stream details */
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[DETECTION].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.det_data));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[VSE].stream_num,
                           (uint8_t *)&(ipc_m2d_buff_ptr->payload.veh_data));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[HEADER].stream_num,
                           (uint8_t *)Get_Header_Stream_Ptr());
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[RDD].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.rdd_stream_data));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[SRA].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.alignment_stream_data));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[DRA].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.dynamic_alignment_log_stream));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[RADAR_CAPABILITY].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.radar_capability_data));
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[STATUS].stream_num,
                           (uint8_t *)Get_Status_Stream_Ptr());
   #ifdef TRACKER_ENABLED
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[PARTNER_SENSOR].stream_num,
                           (uint8_t *)&(ipc_m2d_buff_ptr->payload.partners_data));
   #endif /* TRACKER_ENABLED */
   #if (DOWNSELECTION_ENABLE)
      Add_Stream_Map_Entry(&stream_idx, HIL_Ipc_Index, (uint8_t)stream_table_info_addr[DOWN_SELECTION].stream_num,
                           (uint8_t *)&(IPC_D2M_Buff_Ptr->payload.downselection_data));
   #endif /* DOWNSELECTION_ENABLE */

      Number_Of_Streams_Initialized = stream_idx;
#endif /*endif for ifndef CONTIGUOUS_MEMORY*/
      /* Update stream buffer address. Function should call after Stream_Memory_Map init*/
      Update_HIL_App_Buf_Addr();
   }

   /*Update HIL internal pointers*/
   (void)Update_HIL_Internal_Memory_Pointers();
}

/******************************************************************************
 *. Name: Update_HIL_App_Buf_Addr
 *.
 *. Description:
 *.    Resolves and writes the backing IPC buffer address for every HIL-enabled
 *.    stream into the hil_init_table[] of HIL_Input_T. It is called by
 *.    Update_HIL_Input_Interface() immediately after the Stream_Memory_Map
 *.    table has been rebuilt for the current ping/pong slot, so the HIL
 *.    communication handler always references the correct frame buffer.
 *.
 *.    Operation depends on the memory allocation mode:
 *.
 *.    CONTIGUOUS_MEMORY mode  (#ifdef CONTIGUOUS_MEMORY):
 *.          Assigns sequential slices of the static HIL_APP_BUF[][]-array to
 *.          each enabled stream. A running offset (size_offset) advances by
 *.          HIL_req_Stream_length after each assignment so that each stream
 *.          occupies its own contiguous sub-region within the flat buffer.
 *.
 *.    Non-contiguous mode  (default, #ifndef CONTIGUOUS_MEMORY):
 *.          For each enabled stream entry in hil_init_table[] (iterated by
 *.          hil_strm_idx up to num_hil_enabled_streams), the function scans
 *.          the Stream_Memory_Map[0..Number_Of_Streams_Initialized-1][HIL_Ipc_Index]
 *.          table looking for a stream_id match against
 *.          hil_req_stream_num. When found:
 *.            - hil_req_stream_buff_ptr is set to the matching IPC buffer
 *.              address (direct pointer into D2M / M2D / status / header
 *.              stream memory).
 *.            - hil_stream_memory_init_failed is set to CODED_TRUE if the
 *.              resolved address is NULL, CODED_FALSE otherwise.
 *.          The per-stream NULL check is accumulated into hil_memory_init_failed
 *.          so that a single NULL address taints the whole initialisation.
 *.
 *.    After iterating all streams, hil_input_data_ptr->hil_init_failed is
 *.    updated with the accumulated failure status, allowing the HIL
 *.    communication handler to detect and report incomplete memory mapping.
 *.
 *. Parameters:  void  (uses module-static HIL_Ipc_Index and
 *.                     Number_Of_Streams_Initialized)
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static void Update_HIL_App_Buf_Addr(void)
{
#ifdef CONTIGUOUS_MEMORY
   uint32_t size_offset = 0U;
#endif
   uint8_t hil_strm_idx            = 0U;
   uint8_t idx                     = 0U;
   HIL_Input_T *hil_input_data_ptr = Get_HIL_Input_Data_Ptr();
   bool hil_memory_init_failed     = false;
   uint8_t l_hil_ipc_index         = HIL_Ipc_Index;

   for (hil_strm_idx = 0U; hil_strm_idx < hil_input_data_ptr->num_hil_enabled_streams; hil_strm_idx++)
   {
      /*address location for hil copy for each stream*/
#ifdef CONTIGUOUS_MEMORY
      hil_input_data_ptr->hil_init_table[hil_strm_idx].HIL_req_Stream_buff_ptr = ((uint8_t *)HIL_APP_BUF + size_offset);
      size_offset += hil_input_data_ptr->hil_init_table[hil_strm_idx].HIL_req_Stream_length;
#else
      /*  non contigeous memory allocation logic*/
      for (idx = 0; idx < Number_Of_Streams_Initialized; idx++)
      {
         /* Identify the matching stream nnumber before update ADDR*/
         if (hil_input_data_ptr->hil_init_table[hil_strm_idx].hil_req_stream_num ==
             Stream_Memory_Map[idx][l_hil_ipc_index].stream_id)
         {
            hil_input_data_ptr->hil_init_table[hil_strm_idx].hil_req_stream_buff_ptr =
               Stream_Memory_Map[idx][l_hil_ipc_index].stream_addr;
            /*check memory map fail*/
            hil_memory_init_failed = hil_memory_init_failed || (NULL == Stream_Memory_Map[idx][l_hil_ipc_index].stream_addr);
            /* update each stream failure*/
            hil_input_data_ptr->hil_init_table[hil_strm_idx].hil_stream_memory_init_failed =
               hil_memory_init_failed ? CODED_TRUE : CODED_FALSE;
         }
      }

#endif
   }
   /* Update HIL iniput for mem update status*/
   hil_input_data_ptr->hil_init_failed = hil_memory_init_failed;
}

/******************************************************************************
 *. Name: Get_HIL_Timestamp_ms(void)
 *.    Function to Get HIL Timestamp ms.
 *.
 *. Parameters:
 *. Return Value: hil_timestamp_ms
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
static uint32_t Get_HIL_Timestamp_ms(void)
{
   uint32_t hil_timestamp_ms = 0U;
   Get_Platform_mstime(&hil_timestamp_ms);
   return (hil_timestamp_ms);
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- -------- ------------------------------------------------------
 *29-Aug-2024   jjyb9k   DNP-4996: Initial Version of hil interface.
 *12-Dec-2024   PRIYAN   updated stream buffer update logic
 *============================================================================*/
