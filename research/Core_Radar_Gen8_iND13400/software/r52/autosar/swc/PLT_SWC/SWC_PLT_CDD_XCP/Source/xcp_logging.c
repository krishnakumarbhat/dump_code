/*===========================================================================*/
/**
 * @file xcp_logging.c
 *
 * XCP logging utilities for memory access validation and connection status.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This module provides XCP (eXtendable Calibration Protocol) logging utilities
 * for memory access validation and XCP connection status monitoring. It includes
 * functions to verify RAM memory accessibility, validate IPC Doppler RDD
 * computation buffer ranges, and query the current XCP connection state. The
 * module maintains a list of accessible memory regions and enforces address
 * range validation for security and safety-critical operations.
 *
 * @section ABBR ABBREVIATIONS:
 *   - XCP: eXtendable Calibration Protocol
 *   - IPC: Inter-Processor Communication
 *   - RDD: Range Doppler Detection
 *   - RAM: Random Access Memory
 *   - TCM: Tightly Coupled Memory
 *   - DSP: Digital Signal Processor
 *   - BBE: Baseband Engine
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <stdint.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_XCP.h"
#include "Xcp.h"
#include "dsp_setup.h"
#include "ipc_mss.h"
#include "reuse.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef struct Memory_Regions_Tag
{
   uint32 start_addr;
   uint32 end_addr;
} Memory_Regions_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
/* the list is in the increasing order of their start addresses */
static const Memory_Regions_T Xcp_Accessible_RAM_Regions[] = {
   {R52TCMA_ADDR_START, R52TCMA_ADDR_END}, /* 0x00000000 - 0x00010000 */
   {R52TCM_ADDR_START, R52TCM_ADDR_END},   /* 0x7FFE0000 - 0x80000000 */
   {SYSMEM0_DATA_START, SYSMEM0_DATA_END}, /* 0x80000000 - 0x80020000 */
   {SYSMEM1_ADDR_START, SYSMEM1_ADDR_END}, /* 0x82000000 - 0x82200000 */
   {BBE32_DRAM_START, BBE32_DRAM_END},     /* 0x84020000 - 0x84040000 */
   {ARTIE_ADDR_START, ARTIE_ADDR_END}      /* 0x91800000 - 0x91820000 */
};

static const Memory_Regions_T Xcp_Accessible_RAM_Regions_Write[] = {
   {R52TCMA_ADDR_START_WRITE, R52TCMA_ADDR_END}, /* 0x00000040 - 0x00010000 */
   {R52TCM_ADDR_START, R52TCM_ADDR_END},         /* 0x7FFE0000 - 0x80000000 */
   {SYSMEM0_DATA_START, SYSMEM0_DATA_END},       /* 0x80000000 - 0x80020000 */
   {SYSMEM1_ADDR_START, SYSMEM1_ADDR_END},       /* 0x82000000 - 0x82200000 */
   {BBE32_DRAM_START, BBE32_DRAM_END},           /* 0x84020000 - 0x84040000 */
   {ARTIE_ADDR_START, ARTIE_ADDR_END}            /* 0x91800000 - 0x91820000 */
};
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/******************************************************************************
 * Name:  Xcp_Connect_Status
 *   This function returns the XCP connection status by checking the session
 *   state against the XCP_SESSION_CONNECTED flag.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: uint8 - CODED_TRUE if XCP is connected, CODED_FALSE otherwise
 *
 * Design Information:
 *  - Queries XCP session status for the configured channel
 *
 *  Change References:
 *  - Initial implementation
 ******************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_Connect_Status(void)
{
   uint16 session_state;
   uint8 ret_val;

   session_state = Xcp_GetSessionStatus(XCP_CHANNEL_IDX);
   if (0 != (session_state & XCP_SESSION_CONNECTED))
   {
      ret_val = CODED_TRUE;
   }
   else
   {
      ret_val = CODED_FALSE;
   }
   return ret_val;
}

/******************************************************************************
 * Name:  SWC_Xcp_RAM_Memorycheck
 *   This function validates whether the specified memory address range is
 *   accessible via XCP by checking against a list of allowed memory regions.
 *
 * Shared Variables: none
 *
 * Parameters:
 *   - addr: Pointer to the XCP address to validate
 *   - size: Size of the memory region in bytes
 *
 * Return Value: uint8 - XCP_CMD_OK if address range is valid,
 *                       XCP_CMD_DENIED otherwise
 *
 * Design Information:
 *  - Iterates through Xcp_Accessible_RAM_Regions to verify the requested
 *    address range falls completely within an allowed region
 *  - Checks that start_addr >= region start AND end_addr < region end
 *
 *  Change References:
 *  - Initial implementation
 ******************************************************************************/
FUNC(uint8, XCP_CODE) SWC_Xcp_RAM_Memorycheck(Xcp_AddressPtrType *addr, uint8 size)
{
   uint32 start_addr = (uint32)*addr;
   uint32 end_addr   = start_addr + size;
   uint8 ret_val     = (uint8)XCP_CMD_DENIED;
   uint8 i;

   /* check if the address range is within any of the accessible memory regions */
   for (i = 0U; i < NUM_ELEMS(Xcp_Accessible_RAM_Regions); i++)
   {
      if ((start_addr >= Xcp_Accessible_RAM_Regions[i].start_addr) && (end_addr < Xcp_Accessible_RAM_Regions[i].end_addr))
      {
         ret_val = (uint8)XCP_CMD_OK;
         break;
      }
   }
   return ret_val;
}

/*To be taken care in upcoming release deny XCP access to protected areas*/
FUNC(uint8, XCP_CODE) SWC_Xcp_RAM_Memorycheck_Write(Xcp_AddressPtrType *addr, uint8 size)
{
   uint32_t start_addr   = 0U;
   uint32_t end_addr     = 0U;
   uint8_t no_of_regions = sizeof(Xcp_Accessible_RAM_Regions_Write) / (sizeof(uint32_t) * 2);
   uint8_t index         = 0;
   uint8_t ret_value     = XCP_CMD_DENIED;

   start_addr = (uint32_t)*addr;
   end_addr   = start_addr + (size - 1U);

   /* memory region check for write*/
   for (index = 0; index < no_of_regions; index++)
   {
      if (Xcp_Accessible_RAM_Regions_Write[index].start_addr <= start_addr &&
          end_addr < Xcp_Accessible_RAM_Regions_Write[index].end_addr)
      {
         ret_value = (uint8_t)XCP_CMD_OK;
      }
   }

   return (ret_value);
}
/******************************************************************************
 * Name:  SWC_Xcp_Ipc_Memorycheck
 *   This function adjusts the XCP address pointer for IPC Doppler RDD
 *   computation buffers and validates access to the ping/pong buffer regions.
 *
 * Shared Variables:
 *   - Get_D2M_Ping_Buf_Addr: Start address of ping buffer
 *   - Get_D2M_Pong_Buf_Addr: Start address of pong buffer
 *   - Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx: Current read index for buffer offset
 *
 * Parameters:
 *   - addr: Pointer to the XCP address to adjust
 *   - size: Size of the memory region in bytes
 *
 * Return Value: uint8 - XCP_CMD_OK (always allows access to IPC buffers)
 *
 * Design Information:
 *  - Adjusts the provided address by offsetting it with the current buffer
 *    read index multiplied by message size
 *  - Allows access to ping buffer region only
 *  - Always returns success for IPC buffer access
 *
 *  Change References:
 *  - Initial implementation
 ******************************************************************************/
FUNC(uint8, XCP_CODE) SWC_Xcp_Ipc_Memorycheck(Xcp_AddressPtrType *addr, uint8 size)
{
   uint32 address = (uint32)*addr;

   if ((address >= Get_D2M_Ping_Buf_Addr()) && (address < Get_D2M_Pong_Buf_Addr()))
   {
      *addr += (sizeof(D2M_Msg_T) * Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx());
   }
   else
   {
      /* do nothing*/
      UNUSED_PARAM(size);
   }
   return (uint8)XCP_CMD_OK;
}
