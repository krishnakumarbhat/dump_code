
/*===========================================================================*/
/**
 * @file ipc_data.c
 *
 * Types and APIs for ipc implementation
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo Add full description here
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
#include "ipc_data.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS (object-like MACROS)
\*===========================================================================*/

/*===========================================================================*\
 * Local preprocessor #define MACROS() (i.e., those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Global Object Definitions
 * These buffers must be marked USED so they are not optimized away.
 * For each section of memory, these should be the only buffers allocated, so
 * the memory maps are the same in the different core compilations and get
 * linked into the correct location in memory for each core.
\*===========================================================================*/
volatile IPC_Shared_Buffers_T __attribute__((aligned(32), used, section(".ipc_metadata_section"))) Ipc_Shared_Buffer;
static uint32_t Next_Ring_Buffer_Index(uint32_t index);
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*****************************************************************************
 *. Name: Get_IPC_Notify_Buffer
 *. This function will get the pointer to ipc notify metadata buffer
 *.
 *. Parameters:
 *.
 *. Return Value: Ipc_Notify_Structure_T*
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
volatile Ipc_Notify_Structure_T *Get_IPC_Notify_Buffer(Core_To_Core_ID_T core_to_core_id, Ring_Buffer_RW_T readWrite)
{
   if (readWrite == READ_BUFFER)
   {
      return &Ipc_Shared_Buffer.Ipc_Notify_Buffers[core_to_core_id][Ipc_Shared_Buffer.ReadIndx[core_to_core_id]];
   }
   else
   {
      return &Ipc_Shared_Buffer.Ipc_Notify_Buffers[core_to_core_id][Ipc_Shared_Buffer.WriteIndx[core_to_core_id]];
   }
}

/*****************************************************************************
 *. Name: IPC_Notify_Buffer_Init
 *. This function will initialize Ipc_Shared_Buffer to all zeros.
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
void IPC_Notify_Buffer_Init(void)
{
   volatile_memset((volatile void *)&Ipc_Shared_Buffer, 0, sizeof(Ipc_Shared_Buffer));
   Ipc_Shared_Buffer.Crc_ModuleState.Crc_EngineBusy = CRC_CH_STATUS_FREE;
}

/*****************************************************************************
 *. Name: Get_Ipc_Shared_Buffer_Base_Address
 *. This function will return the base address of the shared IPC buffer.
 *. Added to facilitate the MPU setup in the BBE to set this part of SRAM
 *. to non-cacheable.
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
uint32_t Get_Ipc_Shared_Buffer_Base_Address(void)
{
   return (uint32_t)(uint64_t)&Ipc_Shared_Buffer;
}

/*****************************************************************************
 *. Name: Get_Ipc_Shared_Buffer_Base_Address
 *. This function will return the base address of the shared IPC buffer.
 *. Added to facilitate the MPU setup in the BBE to set this part of SRAM
 *. to non-cacheable.
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
uint8_t Is_IPC_Notify_Buffer_Empty(Core_To_Core_ID_T coreid)
{
   return Ipc_Shared_Buffer.ReadIndx[coreid] == Ipc_Shared_Buffer.WriteIndx[coreid];
}

/*****************************************************************************
 *. Name: Is_IPC_Notify_Buffer_Full
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
uint8_t Is_IPC_Notify_Buffer_Full(Core_To_Core_ID_T coreid)
{
   return Next_Ring_Buffer_Index(Ipc_Shared_Buffer.WriteIndx[coreid]) == Ipc_Shared_Buffer.ReadIndx[coreid];
}

/*****************************************************************************
 *. Name: Increment_IPC_Notify_ReadIndx
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
void Increment_IPC_Notify_ReadIndx(Core_To_Core_ID_T coreid)
{
   Ipc_Shared_Buffer.ReadIndx[coreid] = Next_Ring_Buffer_Index(Ipc_Shared_Buffer.ReadIndx[coreid]);
}

/*****************************************************************************
 *. Name: Increment_IPC_Notify_WriteIndx
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
void Increment_IPC_Notify_WriteIndx(Core_To_Core_ID_T coreid)
{
   Ipc_Shared_Buffer.WriteIndx[coreid] = Next_Ring_Buffer_Index(Ipc_Shared_Buffer.WriteIndx[coreid]);
}

/*****************************************************************************
 *. Name: Next_Ring_Buffer_Index
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
uint32_t Next_Ring_Buffer_Index(uint32_t index)
{
   if (index + 1 == SIZE_OF_RING_BUFFER)
   {
      return 0;
   }
   else
   {
      return index + 1;
   }
}

/*****************************************************************************
 *. Name: volatile_memset
 *. This function is used to memeset volatile structures
 *. Parameters: volatile void *s, int c, size_t n
 *.
 *. Return Value: volatile void
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
volatile void *volatile_memset(volatile void *s, int c, size_t n)
{
   volatile unsigned char *p = (volatile unsigned char *)s;
   while (n--)
   {
      *p++ = (unsigned char)c;
   }

   return s;
}
