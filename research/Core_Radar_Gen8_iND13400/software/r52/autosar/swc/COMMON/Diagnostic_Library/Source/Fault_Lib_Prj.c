/***********************************************************************************************************************
 * Copyright 2020 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 * Version Tracking Header
 * %file_name: Fault_Lib_Prj.c
 * %version: 1 %
 * %last_modified_by:  %
 * %date_modified:  %
 *
 ***********************************************************************************************************************
 *
 * Module Name:
 *    Fault_Lib_Prj.c
 *
 * Description:
 *    This module contains the Fault_Lib implementation.
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
#include "Fault_Lib_Prj.h"

/*===========================================================================*/

/*===========================================================================*/
/*===========================================================================*\
 External Object Definitions
\*===========================================================================*/

Customer_fault_T Customer_Active_Fault_Table;
Customer_fault_T Customer_Active_Fault_Latched_Table;
Customer_fault_T Customer_History_Fault_Table;
Customer_fault_T Customer_Fault_Test_Completed;
const Customer_fault_Latch_Enable_T Customer_Latch_Enable_Table = {CUSTOMER_LATCH_ENABLE_TABLE_SET_VALUES};
Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table       = {CUSTOMER_FAULT_ENABLE_TABLE_VALUES};

/* Global variables for handling the PASS/FAULT Count */
uint16 PRJ_Fail_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];
uint16 PRJ_Pass_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];

/* TODO: Remove after Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable */
extern Customer_fault_T *SWC_Appl_History_Fault_Table;
/*===========================================================================*\
 * File Scope Variables
\*===========================================================================*/
/* Mask value to set or clear the fault in faultbit table */
const uint8_t Bit_Position_Table_Prj[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
/*===========================================================================*\
 * Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

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
void Clear_Platform_Fault_Arrays_Prj(void)
{
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
void Clear_Platform_Fault_Information_Prj(uint16 fault_name)
{
}

/*====================================================================================================================*/
/**
 * FUNCTION: Clear_Fault_If_Enabled_and_Not_Latched
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
void Clear_Fault_If_Enabled_and_Not_Latched(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table_Prj[fault_name % BYTE_SIZE];

   if ((Customer_Fault_Enable_Table.Customer_byte[byte_position] & bit_mask) &&
       !(Customer_Latch_Enable_Table.Customer_byte[byte_position] & bit_mask))
   {
      Customer_Active_Fault_Table.Customer_byte[byte_position] &= ~bit_mask;
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Set_Fault_If_Enabled
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
void Set_Fault_If_Enabled(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table_Prj[fault_name % BYTE_SIZE];

   if (Customer_Fault_Enable_Table.Customer_byte[byte_position] & bit_mask)
   {
      Customer_Active_Fault_Table.Customer_byte[byte_position] |= bit_mask;
      Customer_Active_Fault_Latched_Table.Customer_byte[byte_position] |= bit_mask;
      Customer_History_Fault_Table.Customer_byte[byte_position] |= Customer_Active_Fault_Table.Customer_byte[byte_position];
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Set_Test_Completed_If_Enabled
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
void Set_Test_Completed_If_Enabled(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table_Prj[fault_name % BYTE_SIZE];

   if (Customer_Fault_Enable_Table.Customer_byte[byte_position] & bit_mask)
   {
      Customer_Fault_Test_Completed.Customer_byte[byte_position] |= bit_mask;
   }
}
/*====================================================================================================================*/
/**
 * FUNCTION: Customer_Get_Fault_Status
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
uint8 Customer_Get_Fault_Status(uint16 fault_name)
{
   uint8 ReturnType;
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table_Prj[fault_name % BYTE_SIZE];

   if (Customer_Active_Fault_Table.Customer_byte[byte_position] & bit_mask)
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
 * FUNCTION: Clear_Cust_Fault_Arrays
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
void Clear_Cust_Fault_Arrays(void)
{
   uint8 loop_count;
   for (loop_count = 0; loop_count < sizeof(Customer_fault_T); loop_count++)
   {
      *((uint8_t *)(&Customer_Active_Fault_Table) + loop_count)         = 0;
      *((uint8_t *)(&Customer_Active_Fault_Latched_Table) + loop_count) = 0;
      *((uint8_t *)(&Customer_History_Fault_Table) + loop_count)        = 0;
      *((uint8_t *)(&Customer_Fault_Test_Completed) + loop_count)       = 0;
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Clear_Cust_Fault_Information
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
void Clear_Cust_Fault_Information(uint16 fault_name)
{
   uint8 byte_position = (uint8)(fault_name / BYTE_SIZE);
   uint8 bit_mask      = Bit_Position_Table_Prj[fault_name % BYTE_SIZE];

   Customer_Active_Fault_Table.Customer_byte[byte_position] &= ~bit_mask;
   Customer_Active_Fault_Latched_Table.Customer_byte[byte_position] &= ~bit_mask;
   Customer_History_Fault_Table.Customer_byte[byte_position] &= ~bit_mask;
   Customer_Fault_Test_Completed.Customer_byte[byte_position] &= ~bit_mask;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Cust_Check_Fault_If_Enabled
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
bool Cust_Check_Fault_If_Enabled(Prj_Fault_Name_T fault_name)
{
   boolean_T fault_enabled = FALSE;
   uint8 byte_position     = (uint8)((uint8)fault_name / BYTE_SIZE);
   uint8 bit_mask          = Bit_Position_Table_Prj[(uint8)fault_name % BYTE_SIZE];
   if ((uint8)FALSE != (Customer_Fault_Enable_Table.Customer_byte[byte_position] & bit_mask))
   {
      fault_enabled = TRUE;
   }
   return fault_enabled;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Cust_Fault_Enabled_Disable
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
bool Cust_Fault_Enabled_Disable(Prj_Fault_Name_T fault_name, uint8 enable_status)
{
   boolean_T fault_Op_Status = TRUE;
   uint8 byte_position       = (uint8)((uint8)fault_name / BYTE_SIZE);
   uint8 bit_mask            = Bit_Position_Table_Prj[(uint8)fault_name % BYTE_SIZE];
   if (DIAG_ENABLE_FAULT == enable_status)
   {
      Customer_Fault_Enable_Table.Customer_byte[byte_position] |= bit_mask;
   }
   else if (DIAG_DISABLE_FAULT == enable_status)
   {
      Customer_Fault_Enable_Table.Customer_byte[byte_position] &= ~bit_mask;
   }
   else
   {
      fault_Op_Status = FALSE;
   }
   return fault_Op_Status;
}

/*====================================================================================================================*/
/**
 * FUNCTION: Diagnostics_Filter_Test
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
void Diagnostics_Filter_Test(uint8 test_status, uint16 fault_name, uint16 fault_fail_limit, uint16 fault_pass_limit,
                             uint16 *fail_counter_ptr, uint16 *pass_counter_ptr)
{
   uint16 fault_count_temp;
   uint16 pass_count_temp;
   if (MAX_NUMBER_OF_PLATFORM_TYPES <= fault_name)
   {
      if (DIAG_TEST_PASS == test_status)
      {
         *fail_counter_ptr = 0;
         (*pass_counter_ptr)++;
         pass_count_temp = *pass_counter_ptr;
         if (pass_count_temp >= fault_pass_limit)
         {
            *pass_counter_ptr = fault_pass_limit;
            Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
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
            Set_Fault_If_Enabled(fault_name);
         }
      }

      if ((*fail_counter_ptr >= fault_fail_limit) || (*pass_counter_ptr >= fault_pass_limit))
      {
         Set_Test_Completed_If_Enabled(fault_name);
      }
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Diag_No_Filter_Test
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
void Diag_No_Filter_Test(uint8 test_status, uint16 fault_name)
{
   if (MAX_NUMBER_OF_PLATFORM_TYPES <= fault_name)
   {
      /*Any value other than DIAG_TEST_PASS is considered as FAIL, not just DIAG_TEST_FAIL*/
      if (DIAG_TEST_PASS == test_status)
      {
         Clear_Fault_If_Enabled_and_Not_Latched(fault_name);
      }
      else
      {
         Set_Fault_If_Enabled(fault_name);
      }
      Set_Test_Completed_If_Enabled(fault_name);
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Customer_Active_Fault_Table
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
Customer_fault_T *Get_Customer_Active_Fault_Table(void)
{
   return (&Customer_Active_Fault_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Customer_Active_Fault_Latched_Table
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
 * This function will provide the address of the active fault latched table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Customer_fault_T *Get_Customer_Active_Fault_Latched_Table(void)
{
   return (&Customer_Active_Fault_Latched_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Customer_History_Fault_Table
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
 * This function will provide the address of the History fault table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Customer_fault_T *Get_Customer_History_Fault_Table(void)
{
   return (&Customer_History_Fault_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Customer_Fault_Test_Completed_Table
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
Customer_fault_T *Get_Customer_Fault_Test_Completed_Table(void)
{
   return (&Customer_Fault_Test_Completed);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Customer_Fault_Enable_Table
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
 * This function will provide the address of the customer fault enable table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Customer_fault_Latch_Enable_T *Get_Customer_Fault_Enable_Table(void)
{
   return (&Customer_Fault_Enable_Table);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_SWC_Appl_History_Fault_Table
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
 * This function will provide the address of the History fault table
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
/* TODO: Remove after Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable */
Customer_fault_T *Get_SWC_Appl_History_Fault_Table(void)
{
   return (SWC_Appl_History_Fault_Table);
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
