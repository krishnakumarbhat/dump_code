/*===========================================================================*\
 * FILE: radar_look.c
 *===========================================================================
 * Copyright (C) 2020 APTIV, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This software component updates the look and operating mode of the radar
 * system.
 *
 * ABBREVIATIONS:
 *    RMM - Radar Mode Manager
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
#include "Rte_Type.h"
#include "radar_ctl.h"
#include "reuse.h"
#include "smc_cal.h"
/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/
#include "Rte_SWC_PLT_CDD_Radar_Control.h"
#include "dd_mmic.h"
#include "radar_data.h"
#include "radar_look.h"
#include "xcp_bb.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/

/*===========================================================================*\
 * Local preprocessor #define MACROS()
\*===========================================================================*/

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef enum Look_Dir_Tag
{
   LOOK_DOWN = 0,
   LOOK_UP,
   LOOK_NO_CHANGE,
   LOOK_UNDEFINED,
} Look_Dir_T;
typedef enum Look_Sync_Action_Tag
{
   ForceLookOrderSkip = 0,
   NoActionNeeded,
} Look_Sync_Action_T;
/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
static uint8_t Next_Look_Index;
volatile uint8_t XCP_Cmd_Single_look_Invoked = 0U;
volatile Look_Sync_Status_T Look_Sync_Status = NotAvailable;
volatile Look_Sync_Action_T Look_Sync_Action = NoActionNeeded;
volatile Look_Sync_Enable_T Look_Sync        = Look_Sync_Enable; /* ftoobg: this variable to be replaced with SMC parameter */
/*===========================================================================*\
 * Local function prototypes
\*===========================================================================*/
static XCP_Single_Look_Type_Enable_T Get_Force_Look_Type_Enable(void);
static Radar_Look_T Get_Force_Look_Type(void);
static volatile uint32_t Look_No_Sync_Cntr = 0U;
/*===========================================================================*\
 * Local inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/
static Look_Dir_T Look_Dir_Mapping(uint8_t look_id);
extern uint8_t Get_Radar_Position(void);
/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type_Enable
 *===========================================================================
 * RETURN VALUE:
 *    XCP_Single_Look_Type_Enable
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns XCP_Single_Look_Type_Enable.
\* --------------------------------------------------------------------------*/
XCP_Single_Look_Type_Enable_T Get_Force_Look_Type_Enable(void)
{
   Idt_XCP_Single_Look_T force_look_type_flag;

   if ((RADAR_CTL_NO_FORCE_LOOK_TYPE == XCP_Single_Look_Type_Enable) || (1U == XCP_Cmd_Single_look_Invoked))
   {
      /* Rte Read For Force Look type Enable */
      Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(&force_look_type_flag);

      /* check to enter into force enabled */
      if ((CODED_TRUE == force_look_type_flag.single_look_en))
      {
         XCP_Single_Look_Type_Enable = XCP_FORCE_LOOK_TYPE;
         XCP_Cmd_Single_look_Invoked = 1U;
      }
      else
      {
         XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
         XCP_Cmd_Single_look_Invoked = 0U;
      }
   }
   return (XCP_Single_Look_Type_Enable);
}

/*===========================================================================*\
 * FUNCTION: Get_Force_Look_Type
 *===========================================================================
 * RETURN VALUE:
 *    XCP_Single_Look_Type
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns the xcp_single look type.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Radar_Look_T Get_Force_Look_Type(void)
{
   Idt_XCP_Single_Look_T force_look_type_flag;
   /* Rte Read For Force Look type Enable */
   (void)Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(&force_look_type_flag);
   /* Check for the look coming from XCP Command(F1 0B),single_look_select between 1 and 4(LOOK D)*/

   if ((force_look_type_flag.single_look_select) > 0)
   {
      /*To Match the XCP enum with Look type starting from 1u */
      XCP_Single_Look_Type = (Radar_Look_T)(force_look_type_flag.single_look_select - 1U);
   }
   return (XCP_Single_Look_Type);
}

/*===========================================================================*\
 * FUNCTION: Init_Radar_Look
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function initializes the radar control logic after core 1 reset.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Init_Radar_Look(void)
{
   Radar_Look_T next_look;
   Radar_Mode_T next_mode;

   Next_Look_Index = 0;
   next_mode       = (Radar_Mode_T)k_mode_smc;

   /* Uncomment it once calibration module is available in repo*/
   /* needs to be updated to use SMC, for now use 0-1-2-3
   next_look = (Radar_Look_T)k_Data_Acq_Look_Order_SMC[Next_Look_Index]; */
   next_look = RADAR_LOOK_A;
   Put_Radar_Mode(next_mode);
   Put_Radar_Next_Look(next_look);

   Next_Radar_Look();
   Put_Radar_Scan_Index(0);
}

/*===========================================================================*\
 * FUNCTION: Next_Radar_Look
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Determine next look.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Next_Radar_Look(void)
{
   Radar_Look_T this_look;
   Radar_Look_T next_look;
   Radar_Mode_T next_mode;
   Scan_Index_T scan_index;

   if (RADAR_CTL_NO_FORCE_LOOK_TYPE == Get_Force_Look_Type_Enable())
   {
      next_mode = (Radar_Mode_T)k_mode_smc;
      Put_Radar_Mode(next_mode);
      if (Radar_Ctl_Look_Sync_Trig_Tst())
      {
         this_look = Get_Radar_Look();
         Radar_Ctl_Look_Sync_Trig_Clear();
      }
      else
      {
#ifdef XCP_FAULT_INJECTION
         if (XCP_MMIC_TIME_LOOK_SYNC_FIT_TEST == XCP_MMIC_FIT_Enable)
         {
            this_look = Get_Radar_Look();
         }
         else
         {
            this_look = Get_Radar_Next_Look();
            Next_Look_Index++;
         }
#else
         this_look = Get_Radar_Next_Look();
         Next_Look_Index++;
#endif
      }
      if (Next_Look_Index >= MAX_NUM_LOOKS)
      {
         Next_Look_Index = 0U;
      }
      next_look = (Radar_Look_T)k_look_order_smc[next_mode][Next_Look_Index];
   }
   else
   {
      /*Range check for the forced look type*/
      if ((Get_Force_Look_Type() >= RADAR_LOOK_A) && (Get_Force_Look_Type() < NUM_LOOKS))
      {
         this_look = Get_Force_Look_Type();
         next_look = this_look;
      }
      /*Switching back to Normal look run if the forced look type is not within range*/
      else
      {
         this_look = Get_Radar_Next_Look();
         next_mode = (Radar_Mode_T)k_mode_smc;
         Put_Radar_Mode(next_mode);
         /*Increment Look Index to update Next look with look order as per SMC*/
         Next_Look_Index++;
         if (Next_Look_Index >= MAX_NUM_LOOKS)
         {
            Next_Look_Index = 0U;
         }
         next_look                   = (Radar_Look_T)k_look_order_smc[next_mode][Next_Look_Index];
         XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
      }
   }

   /* Write Local Core Data */
   scan_index = Get_Radar_Scan_Index();
   scan_index++;

   Put_Radar_Look(this_look);
   Put_Radar_Next_Look(next_look);
   Put_Radar_Scan_Index(scan_index);
}
/*===========================================================================*\
 * FUNCTION: Radar_Look_Sync_Test
 *===========================================================================
 * RETURN VALUE:
 *    bool
 *
 * PARAMETERS:
 *    timesync status: true, sensor in sync with master, false otherwise
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function checks if we need to stall radar triggering because
 *    of look direction out of sync
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Radar_Look_Sync_Test(bool tsyn_status)
{
   Look_Sync_Status         = NotAvailable;
   bool look_sync           = true;
   Look_Dir_T current_look  = Look_Dir_Mapping(Get_Radar_Look());
   Look_Dir_T expected_look = Look_Dir_Mapping(k_sensor_init_look_list_smc[Get_Radar_Position() - 1]);

   if (tsyn_status && (expected_look != current_look))
   {
      look_sync = false;
      Look_No_Sync_Cntr++;
      Look_Sync_Action = ForceLookOrderSkip;
      Look_Sync_Status = OutOfSync;
   }
   else
   {
      Look_Sync_Action = NoActionNeeded;
      Look_Sync_Status = InSync;
   }

   return look_sync;
}

/*===========================================================================*\
 * FUNCTION: Look_Dir_Mapping
 *===========================================================================
 * RETURN VALUE:
 *    Look_Dir_T
 *
 * PARAMETERS:
 *     look_id
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function translates the look type to the direction based on
 *    smc parameters
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static Look_Dir_T Look_Dir_Mapping(uint8_t look_id)
{
   Look_Dir_T ret_val = LOOK_UNDEFINED;

   if (k_fr2_smc[look_id] < 0)
   {
      ret_val = LOOK_DOWN;
   }
   else if (k_fr2_smc[look_id] > 0)
   {
      ret_val = LOOK_UP;
   }
   else
   {
      ret_val = LOOK_NO_CHANGE;
   }
   return ret_val;
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 15-May-2023 tjy9rb  DDR-1972: Integrate radar control mode for SmartTRX.
 * 28-Feb-2025 djdgwr  EPB-3577: Implemented XCP Force Look related to changes.
 * 20-Mar-2025 djdgwr  EPB-3559: Enable Force Look through global variables related to changes.
 * 08-jul-2025 njsfs0 EPB-3699 Aptiv coding standards warnings fix
 * 23-Jul-2026 jjrfgz EPB-4574 Next_Radar_Look function Updated
 * 03-Sept-2026 ftoobg EPB-4810 [Gen8] Time/Look Synchronization SWE areas
\*===========================================================================*/
