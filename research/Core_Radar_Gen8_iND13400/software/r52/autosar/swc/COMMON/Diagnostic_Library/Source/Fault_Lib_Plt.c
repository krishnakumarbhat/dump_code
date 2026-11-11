/***********************************************************************************************************************
 * Copyright 2020 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 * Version Tracking Header
 * %file_name: Fault_Lib_Plt.c
 * %version: 1 %
 * %last_modified_by:  %
 * %date_modified:  %
 *
 ***********************************************************************************************************************
 *
 * Module Name:
 *    Fault_Lib_Plt.c
 *
 * Description:
 *    This module contains the Fault_Lib_Plt implementation.
 *
 * Traces to Software Architecture/Design Document:
 *    SAD_...
 *
 * Implements following software requirements:
 *    WI-xxxxx,...
 *
 * Deviations/Justifications from software standards:
 *    None
 *
 **********************************************************************************************************************/

/*===========================================================================*\
 * Includes
\*===========================================================================*/
#include "Fault_Lib_Plt.h"
#include "Rte_SWC_PLT_Appl_FaultMgr_Type.h"
/*===========================================================================*\
 * #defines
\*===========================================================================*/
/*===========================================================================*\
 External Object Definitions
\*===========================================================================*/
Platform_fault_T Platform_Active_Fault_Table;
Platform_fault_T Platform_Active_Fault_Latch_Table;
Platform_fault_T Platform_Fault_Test_Completed;
const Platform_fault_T Platform_Latch_Enable_Table = {PLATFORM_LATCH_ENABLE_TABLE_SET_VALUES};
Platform_fault_T Platform_Fault_Enable_Table       = {PLATFORM_FAULT_ENABLE_TABLE_VALUES};

/*===========================================================================*\
 * File Scope Variables
\*===========================================================================*/
/* Mask value to set or clear the fault in faultbit table */
const uint8_t Bit_Position_Table[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

/* Global variable to freeze the fault table */
uint8 Plt_Fault_Table_Freeze = CODED_TRUE;
/*===========================================================================*\
 * Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Diagnostics_Filter_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * test_status: This variable indicates weather the fault is passsed/failed
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 * fault_fail_limit: These are the thresholds in the case of fault need to be set
 * fault_pass_limit: These are the thresholds in the case of fault need to be clear
 * fail_counter_ptr: This global variable is a counter to maintain the debouncing
 * pass_counter_ptr: This global variable is a counter to maintain the debouncing
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for setting/clearing of the fault in the fault manager based on the Test_Status without debouncing
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_Diagnostics_Filter_Test(uint8 test_status, uint16 fault_name, uint16 fault_fail_limit, uint16 fault_pass_limit,
                                      uint16 *fail_counter_ptr, uint16 *pass_counter_ptr)
{
   uint16 fault_count_temp;
   uint16 pass_count_temp;
   if ((MAX_NUMBER_OF_PLATFORM_TYPES > fault_name) && (Plt_Fault_Table_Freeze != CODED_FALSE))
   {
      if (DIAG_TEST_PASS == test_status)
      {
         *fail_counter_ptr = 0;
         (*pass_counter_ptr)++;
         pass_count_temp = *pass_counter_ptr;
         if (pass_count_temp >= fault_pass_limit)
         {
            *pass_counter_ptr = fault_pass_limit;
            Platform_Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
         }
      }
      else
      {
         /* clamp fault counter if fault counter is ready to wrap
          * or fault counter is above fault limit
          */
         *pass_counter_ptr = 0;
         (*fail_counter_ptr)++;
         fault_count_temp = *fail_counter_ptr;
         if (fault_count_temp >= fault_fail_limit)
         {
            *fail_counter_ptr = fault_fail_limit;
            Platform_Set_Fault_If_Enabled(fault_name);
         }
      }

      if ((*fail_counter_ptr >= fault_fail_limit) || (*pass_counter_ptr >= fault_pass_limit))
      {
         Platform_Set_Test_Completed_If_Enabled(fault_name);
      }
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Clear_Fault_If_Enabled_and_Not_Latched
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for the filter(debouncing) of the fault in the fault manager
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_Clear_Fault_If_Enabled_and_Not_Latched(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   if ((Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask) &&
       !(Platform_Latch_Enable_Table.Platform_byte[byte_position] & bit_mask))
   {
      Platform_Active_Fault_Table.Platform_byte[byte_position] &= ~bit_mask;
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Set_Fault_If_Enabled
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for the filter(debouncing) of the fault in the fault manager
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_Set_Fault_If_Enabled(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   if (Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask)
   {
      Platform_Active_Fault_Table.Platform_byte[byte_position] |= bit_mask;
      Platform_Active_Fault_Latch_Table.Platform_byte[byte_position] |= bit_mask;
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Fault_Table_Override_XCP
 *======================================================================================================================
 * RETURN VALUE: uint8
 *
 * PARAMETERS:
 * XXCP_Fault_Override_T* XCP_Fault_Override
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for Overriding the Fault Table from XCP
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
uint8 Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override)
{
   /* Local variables for fetching xcp fault override structure */
   uint8 ReturnType    = CODED_FALSE;
   uint8 byte_position = Plt_XCP_Fault_Override->byte_pos;
   uint8 bit_position  = Plt_XCP_Fault_Override->bit_pos;
   uint8 bit_mask      = Bit_Position_Table[bit_position];
   /* To Run without any freeze */
   if (PLTFORM_AUTO_MODE == Plt_XCP_Fault_Override->action)
   {
      Plt_Fault_Table_Freeze = CODED_TRUE;
      ReturnType             = CODED_TRUE;
   }
   /* To Set and Freeze the Active Fault Table */
   else if (PLATFORM_SET_FAULT_MODE == Plt_XCP_Fault_Override->action)
   {
      Plt_Fault_Table_Freeze = CODED_FALSE;
      /* To Check Fault is Enable */
      if (Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask)
      {
         Platform_Active_Fault_Table.Platform_byte[byte_position] |= bit_mask;
      }
      ReturnType = CODED_TRUE;
   }
   /* To Clear and Freeze the Active Fault Table */
   else if (PLATFORM_CLEAR_FAULT_MODE == Plt_XCP_Fault_Override->action)
   {
      Plt_Fault_Table_Freeze = CODED_FALSE;
      /* To Check Fault is Enable */
      if ((Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask) &&
          (!(Platform_Latch_Enable_Table.Platform_byte[byte_position] & bit_mask)))
      {
         Platform_Active_Fault_Table.Platform_byte[byte_position] &= ~bit_mask;
      }
      ReturnType = CODED_TRUE;
   }
   else
   {
      /*do nothing*/
   }
   return ReturnType;
}
/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Set_Test_Completed_If_Enabled
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for the filter(debouncing) of the fault in the fault manager
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_Set_Test_Completed_If_Enabled(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   if (Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask)
   {
      Platform_Fault_Test_Completed.Platform_byte[byte_position] |= bit_mask;
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Diag_No_Filter_Test
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * test_status: This variable indicates weather the fault is passsed/failed
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is for setting/clearing of the fault in the fault manager based on the Test_Status without debouncing
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_Diag_No_Filter_Test(uint8 test_status, uint16 fault_name)
{
   if ((MAX_NUMBER_OF_PLATFORM_TYPES > fault_name) && (Plt_Fault_Table_Freeze != CODED_FALSE))
   {
      /*Any value other than DIAG_TEST_PASS is considered as FAIL, not just DIAG_TEST_FAIL*/
      if (DIAG_TEST_PASS == test_status)
      {
         Platform_Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
      }
      else
      {
         Platform_Set_Fault_If_Enabled(fault_name);
      }
      Platform_Set_Test_Completed_If_Enabled(fault_name);
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Get_Fault_Status
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall provide the status of the fault in active fault table.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
uint8 Platform_Get_Fault_Status(uint16 fault_name)
{
   uint8 ReturnType;
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   if (Platform_Active_Fault_Table.Platform_byte[byte_position] & bit_mask)
   {
      ReturnType = CODED_TRUE;
   }
   else
   {
      ReturnType = CODED_FALSE;
   }
   return ReturnType;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Clear_Platform_Fault_Arrays
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall clear all bits in all the platform tables.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Clear_Platform_Fault_Arrays(void)
{
   uint8 loop_count;
   for (loop_count = 0; loop_count < sizeof(Platform_fault_T); loop_count++)
   {
      *((uint8_t *)(&Platform_Active_Fault_Table) + loop_count)       = 0;
      *((uint8_t *)(&Platform_Fault_Test_Completed) + loop_count)     = 0;
      *((uint8_t *)(&Platform_Active_Fault_Latch_Table) + loop_count) = 0;
   }
   /* Clear the Pass and Fail counter */
   (void)memset(Fail_Count_Debounce, 0, sizeof(Fail_Count_Debounce));
   (void)memset(Pass_Count_Debounce, 0, sizeof(Pass_Count_Debounce));
}

/*====================================================================================================================*/
/**
 * FUNCTION: Clear_Platform_Fault_Information
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall clear the bits in all the tables corresponding to a particular fault.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Clear_Platform_Fault_Information(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table[fault_name % BYTE_SIZE];

   Platform_Active_Fault_Table.Platform_byte[byte_position] &= ~bit_mask;
   Platform_Fault_Test_Completed.Platform_byte[byte_position] &= ~bit_mask;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Check_Fault_If_Enabled
 *======================================================================================================================
 * RETURN VALUE
 * fault_enabled:
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is to check the status of the fault is it enable/disabled.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
boolean Platform_Check_Fault_If_Enabled(fault_name_T fault_name)
{
   boolean_T fault_enabled = FALSE;
   uint8 byte_position     = (uint8)((uint8)fault_name / BYTE_SIZE);
   uint8 bit_mask          = Bit_Position_Table[(uint8)fault_name % BYTE_SIZE];
   if ((uint8)FALSE != (Platform_Fault_Enable_Table.Platform_byte[byte_position] & bit_mask))
   {
      fault_enabled = TRUE;
   }
   return fault_enabled;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Fault_Enabled_Disable
 *======================================================================================================================
 * RETURN VALUE
 * fault_Op_Status: States weather the requested operation was sucessful/unsucessful
 *
 * PARAMETERS:
 * fault_name: This is the name of the fault that given from the ENUM fault_name_T
 * enable_status
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is to enable/disable fault based on the user request.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
boolean Platform_Fault_Enabled_Disable(fault_name_T fault_name, uint8 enable_status)
{
   boolean_T fault_Op_Status = TRUE;
   uint8 byte_position       = (uint8)((uint8)fault_name / BYTE_SIZE);
   uint8 bit_mask            = Bit_Position_Table[(uint8)fault_name % BYTE_SIZE];
   if (DIAG_ENABLE_FAULT == enable_status)
   {
      Platform_Fault_Enable_Table.Platform_byte[byte_position] |= bit_mask;
   }
   else if (DIAG_DISABLE_FAULT == enable_status)
   {
      Platform_Fault_Enable_Table.Platform_byte[byte_position] &= ~bit_mask;
   }
   else
   {
      fault_Op_Status = FALSE;
   }
   return fault_Op_Status;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_Active_Fault_Table
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function will provide the address of the active fault table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Platform_fault_T *Get_Platform_Active_Fault_Table(void)
{
   return (&Platform_Active_Fault_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_Active_Fault_Latch_Table
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function will provide the address of the active fault table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Platform_fault_T *Get_Platform_Active_Fault_Latch_Table(void)
{
   return (&Platform_Active_Fault_Latch_Table);
}
/*
 * Backwards-compatible wrapper: some files reference the misspelled
 * 'Get_Platform_Active_Fault_Latched_Table' (with a trailing 'd').
 * Provide a thin alias so older callers/linkage succeed.
 */
Platform_fault_T *Get_Platform_Active_Fault_Latched_Table(void)
{
   return Get_Platform_Active_Fault_Latch_Table();
}
/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_Fault_Test_Completed_Table
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function will provide the address of the platform test completed table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Platform_fault_T *Get_Platform_Fault_Test_Completed_Table(void)
{
   return (&Platform_Fault_Test_Completed);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_Fault_Enable_Table
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function will provide the address of the platform fault enable table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Platform_fault_T *Get_Platform_Fault_Enable_Table(void)
{
   return (&Platform_Fault_Enable_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Clear_Debounce_Fault_Counters
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * NA
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall clear debouncing count of all the platform Faults.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Clear_Debounce_Fault_Counters(void)
{
   /* Clear the Pass and Fail counter */
   (void)memset(Fail_Count_Debounce, 0, sizeof(Fail_Count_Debounce));
   (void)memset(Pass_Count_Debounce, 0, sizeof(Pass_Count_Debounce));
}

/* THIS THINGS NEEDED TO BE MODIFIED AS WE CREATE THE CFM GJY4D3*/

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_memory_Copy
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 * destination: address off the destination location
 * source: address off the destination location
 * num: Nuber of bytes that are required to be copied
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function will provide the address of the platform test completed table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
void Platform_memory_Copy(void *destination, void *source, uint8 num)
{
   const uint8 *src = (uint8 *)source;
   uint8 *dst       = (uint8 *)destination;
   uint8 i;
   for (i = 0; i < num; i++)
   {
      dst[i] = src[i];
   }
}
/*====================================================================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *======================================================================================================================
 *
 * Date(dd-mm-yyyy)        userid                (Description on following lines: SCR #, etc.)
 *
 * 24-03-2021              gjy4d3(Vijayendra)              Initial version
 * 31-05-2021              gjy4d3(Vijayendra)              EEG-384: Implementation ticket for Nissan SRR6 DV faults (Mcu Temp Low
 fault)
 * 09-06-2021              gjy4d3(Vijayendra)              EEG-562: Disable Radar based on MMIC and MCU Temp High faults
 * 28-09-2021              gjy4d3(Vijayendra)              EEG-590: Clearing of the debouncing filters on the request of the
 customer domain[SRR6/FLR4/FLR4+]
 * 23-02-2022              vj1jjy(Sathvika)                EEG-878: Implementation of Fault Table override over XCP
 \*===================================================================================================================*/
