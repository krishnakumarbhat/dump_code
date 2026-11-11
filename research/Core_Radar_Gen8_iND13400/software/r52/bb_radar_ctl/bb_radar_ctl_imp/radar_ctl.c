/*===========================================================================*\
 * FILE: radar_ctl.c
 *===========================================================================
 * Copyright (C) 2024 APTIV,, All Rights Reserved.
 * APTIV Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This module coordinates the initialization and triggering of radar frames or
 * looks.
 *
 * ABBREVIATIONS:
 *    CTL - Control
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
#include "radar_ctl.h"
#include "SWC_PLT_CDD_ECUSync_external.h"
#include "dd_mmic.h"
#include "platformtime.h"
// #include "dsp_setup.h"
#include "Rte_SWC_PLT_CDD_Radar_Control_Type.h"
#include "ipc_mss.h"
#include "mmic_error.h"
#include "mmic_interface.h"
#include "radar_data.h"
#include "radar_look.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/
#define ERROR_MAX_TRIGGER    (2)
#define ERROR_MAX_COMPLETE   (2)
#define PURE_CW_MODE         (1)
#define ERROR_MAX_DEGRADED   (3U)
#define MAX_TEST_TRIGGER_BUF (8U)
#ifdef MARS_RESET_MECHANISM_ENABLED
   #define MARS_MAX_RESET_COUNTER (20U) /*ToDo: come up with better strategy based on functional safety*/
#endif
#define MMIC_INIT_MEASURE_ENABLE (0U)
/*===========================================================================*\
 * Local preprocessor #define MACROS()
\*===========================================================================*/
#define Bitwise_Complement(x) ~((uintptr_t)(x))

#define Get_A2D_Online_Injection_Active()  false
#define Get_A2D_Online_Injection_Trigger() false
#define Clr_A2D_Online_Injection_Trigger()

/*Test Code. It needs to be removed once MMIC code are available*/
#if (RADAR_CONTROL_MODE_TEST)
   #define DISCARD_ERROR_LOOK_TRIGGER (27U)
#endif

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef enum Radar_Ctl_Event_Tag
{
   RADAR_CTL_EVENT_PERIODIC,
   RADAR_CTL_EVENT_LOOK_TRIGGER,
   RADAR_CTL_EVENT_LOOK_COMPLETE,
   RADAR_CTL_EVENT_NUM
} Radar_Ctl_Event_T;

/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
typedef void (*Radar_Ctl_State_Func_Ptr_T)(Radar_Ctl_Event_T event);

Radar_Ctl_State_Func_Ptr_T Radar_Ctl_State_Update;
uint32_t Radar_Ctl_State_Check                                  = 0U;
volatile uint32_t Delta_MMIC_Trigger_Time[MAX_TEST_TRIGGER_BUF] = {0U};
volatile uint32_t Mmic_Trig_Time_Max                            = 0U;
volatile uint32_t Mmic_Trig_Time_Min                            = 1000000U;
static uint8_t Trigger_Error_Count                              = 0U;
static uint8_t Complete_Error_Count                             = 0U;
volatile uint16_t State_Radar_Ctl_Configured_Err_Cnt            = 0U;
int32_t Offline_Data_Mode_Enabled_Counter                       = 0;
static bool Radar_Trigger_Sync                                  = false;
#ifdef MARS_RESET_MECHANISM_ENABLED
volatile uint8_t Fault_Reset_Counter = 0U;
#endif
volatile uint8_t Alive_Flag          = 0U;
Dt_RadarCoreStatus Radar_Core_Status = {CODED_FALSE};
// static uint16_t Degraded_Error_Count = 0U;

// static bool look_trigger_flag = false;
/*===========================================================================*\
 * Local function prototypes
\*===========================================================================*/
static void Trans_Radar_Ctl_Off(void);
static void State_Radar_Ctl_Off(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Faulted(void);
static void State_Radar_Ctl_Faulted(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Init(void);
static void State_Radar_Ctl_Init(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Ready(void);
static void State_Radar_Ctl_Ready(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Configured(void);
static void State_Radar_Ctl_Configured(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Transmitting(void);
static void State_Radar_Ctl_Transmitting(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_A2D_Injection(void);
static void State_Radar_Ctl_A2D_Injection(Radar_Ctl_Event_T event);
static void Trans_Radar_Ctl_Pure_CW(void);
static void State_Radar_Ctl_Pure_CW(Radar_Ctl_Event_T event);
static void Update_Radar_Cw_Mode_Status(uint8_t cw_mode_status);
// static void Trans_Radar_Ctl_Degraded(void);
// static void State_Radar_Ctl_Degraded(Radar_Ctl_Event_T event);
// static void Trans_Radar_Ctl_Idle(void);
// static void State_Radar_Ctl_Idle(Radar_Ctl_Event_T event);
// static void State_Radar_Ctl_Degraded_Periodic(void);
// static void State_Radar_Ctl_Degraded_Trigger(void);
// static void State_Radar_Ctl_Degraded_Complete(void);
static void Radar_Ctl_Look_Trigger_Start(void);
/*===========================================================================*\
 * Local inline function definitions and #define function-like macros
\*===========================================================================*/

/*===========================================================================*\
 * Function definitions
\*===========================================================================*/
/*===========================================================================*\
 * FUNCTION: Radar_ITF_Offline_Mode_Enabled
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function to increment a counter to allow setting a break
 *    point in the M7 to allow the SPT/BBE to process a frame of data without
 *    triggering any FuSa or watchdog errors.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#if 0 // ToDO
static void Radar_ITF_Offline_Mode_Enabled(void)
{
   Offline_Data_Mode_Enabled_Counter++;
}
#endif

/*Test Code. It needs to be removed once functions are available*/
#if (RADAR_CONTROL_MODE_TEST)
void ipc_mss_notify_rss_config(uint8_t look)
{
}
void ipc_mss_notify_dss_config(uint32_t look_idx, uint32_t look_cfg_id, uint32_t *rp_cfg)
{
}
#endif
/*===========================================================================*\
 * Radar Control Public Functions
\*===========================================================================*/

#if RESI_MODE_ENABLE
/*===========================================================================*\
 * FUNCTION: RESI_Mode_Put_Next_Look
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called in RESI mode to enable switching the state machine to different
 *    looks outside of the radar ctl state machine.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void RESI_Mode_Put_Next_Look(void)
{
   Next_Radar_Look();
}
#endif

/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Reset_Init
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
 * tasks start.  It is used to do power on initialization of radar look data.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Reset_Init(void)
{
#ifndef RESI_MODE_ENABLE
   Trans_Radar_Ctl_Off();
#endif

   Init_Radar_Look();
   MMIC_Reset_Init();
}

/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Periodic
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called periodically.  It initializes the MMIC device
 * drivers and updated the radar op mode.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Periodic(void)
{
   if (Radar_Ctl_State_Check != Bitwise_Complement(Radar_Ctl_State_Update))
   {
      Trans_Radar_Ctl_Init();
   }
   else
   {
      (*Radar_Ctl_State_Update)(RADAR_CTL_EVENT_PERIODIC);
   }
}

/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Look_Trigger
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function triggers a sequence of chirps based on the current look.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Look_Trigger(void)
{
   Alive_Flag = CODED_FALSE; // clearing the alive flag to update the alive counter only once per radar cycle updated in
                             // Compute_Rfe_Rdr_Data_Sts_Payload_CRC function
   if (Radar_Ctl_State_Check == Bitwise_Complement(Radar_Ctl_State_Update))
   {
      (*Radar_Ctl_State_Update)(RADAR_CTL_EVENT_LOOK_TRIGGER);
   }
}

/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Look_Complete
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called after all of the chirps are completed for the
 * configured look.  This function first calls the device drivers to
 * complete any necessary operations to complete the look.  It then configures
 * the next look.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Look_Complete(void)
{
   if (Radar_Ctl_State_Check == Bitwise_Complement(Radar_Ctl_State_Update))
   {
      (*Radar_Ctl_State_Update)(RADAR_CTL_EVENT_LOOK_COMPLETE);
   }
}

/*===========================================================================*\
 * Radar Control State Machine
\*===========================================================================*/

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Off
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_OFF state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Off(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_OFF);
   Radar_Ctl_State_Update = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Put_Radar_Ctl_Init_Status(RADAR_CTL_INIT_NOT_STARTED);
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Off
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_OFF state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Off(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
      if (Get_MMIC_Faulted())
      {
         Trans_Radar_Ctl_Faulted();
      }
      else if (Get_Radar_Radiate_Enable())
      {
         Trans_Radar_Ctl_Init();
         Radar_Core_Status.RadarInitializatonStatus = BUSY_RadarInitStatus;
         /* Execute state machine now to reduce start up time. */
         (*Radar_Ctl_State_Update)(RADAR_CTL_EVENT_PERIODIC);
      }
      else
      {
         /* Remain in Off State */
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Faulted
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_FAULTED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Faulted(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_FAULTED);
   Radar_Ctl_State_Update = State_Radar_Ctl_Faulted;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Put_Radar_Ctl_Init_Status(RADAR_CTL_INIT_FAIL);
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Off
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_OFF state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Faulted(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
      if (!Get_MMIC_Faulted())
      {
         Trans_Radar_Ctl_Off();
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Init
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_INIT state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Init(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_INIT);
   Radar_Ctl_State_Update = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Put_Radar_Ctl_Init_Status(RADAR_CTL_INIT_STARTED);
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Init
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_INIT state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Init(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
      if (!Get_Radar_Radiate_Enable())
      {
         Trans_Radar_Ctl_Off();
      }
      else
      {
         // MMIC_Reset_Flags(); /* ToDo: Enable if needed */
         MMIC_Config_Device();
#if MMIC_INIT_MEASURE_ENABLE
         IOCTRL->GPIO_11.f.FUNC_SEL = 0x0; /* DIO Mode */
         IOCTRL->GPIO_11.f.IE       = 1;   /* Output so IE buffer not needed */
         IOCTRL->GPIO_11.f.DS       = 0;
         IOCTRL->GPIO_11.f.ST       = 0;
         IOCTRL->GPIO_11.f.PE       = 0;
         IOCTRL->GPIO_11.f.PS       = 0;
         GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x08; /* As Output */
         GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x08u;
#endif
         if (!Get_MMIC_Error_Reinit())
         {
            /* Update Radar Init Status to true */
            Radar_Core_Status.RadarInitializatonStatus = RADAR_SUCCESS;
            Trans_Radar_Ctl_Ready();
         }
         else if (Get_MMIC_Faulted())
         {
            /* Update Radar Init Status to false */
            Radar_Core_Status.RadarInitializatonStatus = RADAR_INITIALIZATION_FAIL;
            Trans_Radar_Ctl_Faulted();
         }
         else
         {
            /* Retry init on next periodic */
         }
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Ready
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_READY state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Ready(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_READY);
   Radar_Ctl_State_Update = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Put_Radar_Ctl_Init_Status(RADAR_CTL_INIT_SUCCESS);

   Trigger_Error_Count = 0;
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Ready
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_READY state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Ready(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
      if (!Get_Radar_Radiate_Enable())
      {
         Trans_Radar_Ctl_Off();
      }
      else if (Get_A2D_Online_Injection_Active())
      {
         Trans_Radar_Ctl_A2D_Injection();
      }
      else if (PURE_CW_MODE == Get_MMIC_Operation_Mode())
      {
         Trans_Radar_Ctl_Pure_CW();
      }
      else
      {
         Trans_Radar_Ctl_Configured();
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Configured
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_CONFIGURED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Configured(void)
{
   // ToDo: Remove one time config for 4 look config
   Put_Radar_Ctl_State(RADAR_CTL_CONFIGURED);
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   Trigger_Error_Count = 0U;
   MMIC_Config_Look();
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Configured
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_CONFIGURED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Configured(Radar_Ctl_Event_T event)
{
   // static uint8_t mmic_trigger_index        = 0;
   // static float32_t start_mmic_trigger_time = 0;
   // static float32_t end_mmic_trigger_time   = 0;
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
#if ENABLE_TRIGGER_TASK_CHECK
      Trigger_Error_Count++;
      if (Trigger_Error_Count >= ERROR_MAX_TRIGGER)
      {
         Set_MMIC_Error_Reinit(REINIT_ERROR_TRIGGER_TIMEOUT);
         if (Get_MMIC_Error_Reinit())
         {
            Trans_Radar_Ctl_Off();
         }
      }
#endif
   }

   /* Look Trigger ***********************************************************/
   if (RADAR_CTL_EVENT_LOOK_TRIGGER == event)
   {
      Radar_Ctl_Look_Trigger_Start();

      if ((Get_MMIC_Error_Reinit()) || (Get_MMIC_Faulted()))
      {
         Update_MMIC_Reinit_Request(CODED_TRUE);
         /* M7 Radar Data Status Payload CRC calculation */
         Compute_M7_Rdr_Data_Sts_Payload_CRC();
         Trans_Radar_Ctl_Off();
      }
      else if (Get_MMIC_Error_Discard())
      {
         Update_Radar_Data_Status();
         Compute_M7_Rdr_Data_Sts_Payload_CRC();
         Trans_Radar_Ctl_Ready();
      }
      else
      {
         Update_MMIC_Reinit_Request(CODED_FALSE); // Clear reinit request
         Trans_Radar_Ctl_Transmitting();
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Transmitting
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_TRANSMITTING state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Transmitting(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_TRANSMITTING);
   Radar_Ctl_State_Update = State_Radar_Ctl_Transmitting;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   Complete_Error_Count = 0;
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Transmitting
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_TRANSMITTING state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Transmitting(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
#if ENABLE_COMPLETE_TASK_CHECK
      Complete_Error_Count++;
      if (Complete_Error_Count >= ERROR_MAX_COMPLETE)
      {
         Set_MMIC_Error_Reinit(REINIT_ERROR_LOOK_COMPLETE);
         if (Get_MMIC_Error_Reinit())
         {
            Trans_Radar_Ctl_Off();
         }
      }
#endif
   }

   /* Look Complete ***********************************************************/
   if (RADAR_CTL_EVENT_LOOK_COMPLETE == event)
   {
      MMIC_Look_Complete();
      if ((Get_MMIC_Error_Reinit()) || (Get_MMIC_Faulted()))
      {
         Update_MMIC_Reinit_Request(CODED_TRUE);
         Trans_Radar_Ctl_Off();
      }
      else
      {
         if (!Get_Radar_Radiate_Enable())
         {
            Trans_Radar_Ctl_Off();
         }
         else if ((PURE_CW_MODE == Get_MMIC_Operation_Mode()) || (Get_A2D_Online_Injection_Active()))
         {
            Trans_Radar_Ctl_Ready();
         }
         else
         {
            /* ToDo: enable if temperature faults are required */
            // if (CODED_TRUE == Get_Temperature_Hysteresis_Fault())
            // {
            //    /* Jump to Degraded Mode */
            //    Trans_Radar_Ctl_Degraded();
            // }
            // else
            // {
            Update_MMIC_Reinit_Request(CODED_FALSE); // Clear reinit request
            Next_Radar_Look();
            Trans_Radar_Ctl_Configured();
            // }
         }
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_A2D_Injection
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_A2D_INJECTION state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_A2D_Injection(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_A2D_INJECTION);
   Radar_Ctl_State_Update = State_Radar_Ctl_A2D_Injection;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_A2D_Injection
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_A2D_INJECTION state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_A2D_Injection(Radar_Ctl_Event_T event)
{
   /* Look Trigger ***********************************************************/
   if (RADAR_CTL_EVENT_LOOK_TRIGGER == event)
   {
      if (!Get_A2D_Online_Injection_Active())
      {
         Trans_Radar_Ctl_Off();
      }
      else if (Get_A2D_Online_Injection_Trigger())
      {
         Clr_A2D_Online_Injection_Trigger();
      }
      else
      {
         /* do nothing */
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Pure_CW
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the RADAR_CTL_PURE_CW state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Trans_Radar_Ctl_Pure_CW(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_PURE_CW);
   Radar_Ctl_State_Update = State_Radar_Ctl_Pure_CW;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   MMIC_Config_Look();
   // MMIC_Look_Trigger();
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Pure_CW
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the RADAR_CTL_PURE_CW state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Pure_CW(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (RADAR_CTL_EVENT_PERIODIC == event)
   {
      Update_Radar_Cw_Mode_Status(CODED_TRUE);
      if (PURE_CW_MODE != Get_MMIC_Operation_Mode())
      {
         Update_Radar_Cw_Mode_Status(CODED_FALSE);
         MMIC_Look_Complete();
         Trans_Radar_Ctl_Ready();
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Degraded
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the Degraded state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#if 0 // ToDo: Enable if degraded state is a requirement
static void Trans_Radar_Ctl_Degraded(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_DEGRADED);
   Radar_Ctl_State_Update = State_Radar_Ctl_Degraded;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Put_Radar_Init_Status(RADAR_INIT_SUCCESS);
   Update_Radar_Ctl_State_Degraded(CODED_TRUE);
   Update_Radar_Ctl_State_Idle(CODED_FALSE);
   Update_Radar_Ctl_State_Rad_Off(CODED_FALSE);
}
#endif
/*===========================================================================*\
 * FUNCTION: Trans_Radar_Ctl_Idle
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the Idle state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#if 0 // ToDO
static void Trans_Radar_Ctl_Idle(void)
{
   Put_Radar_Ctl_State(RADAR_CTL_IDLE);
   Radar_Ctl_State_Update = State_Radar_Ctl_Idle;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Put_Radar_Init_Status(RADAR_INIT_SUCCESS);
   Update_Radar_Ctl_State_Degraded(CODED_FALSE);
   Update_Radar_Ctl_State_Idle(CODED_TRUE);
   Update_Radar_Ctl_State_Rad_Off(CODED_FALSE);
}
#endif
/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Look_Trigger_Start
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    uint8_t flagcheck
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when there is an event while in the Radar Control
 * state machine is in the Radar_Ctl_Look_Trigger_Start state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#define TEST_STUB_PROFILE

#ifdef TEST_STUB_PROFILE
volatile static uint32_t Profile_Radar_Ctl_Look_Trigger_Start = 0U;
#endif

static void Radar_Ctl_Look_Trigger_Start(void)
{
#ifdef TEST_STUB_PROFILE
   static uint32_t temp3 = 0U;
   static uint32_t temp4 = 0U;
#endif
   static uint8_t mmic_trigger_index       = 0U;
   static uint32_t start_mmic_trigger_time = 0U;
   static uint32_t end_mmic_trigger_time   = 0U;
// bool get_offline_mode_flag_check  = 0U;
#ifdef TEST_STUB_PROFILE
   Get_Platform_mstime(&temp3);
   Profile_Radar_Ctl_Look_Trigger_Start = temp3 - temp4;
#endif
   if ((!Get_MMIC_Error_Reinit()) && (!Get_MMIC_Faulted()) && (!Get_MMIC_Error_Discard()))
   {
      ipc_mss_notify_rss_config(0);

      /* RSS/MMIC START trigger here, implement or replace */
      ipc_mss_notify_dss_config(Get_Radar_Scan_Index(), Get_Radar_Look(), NULL);

#ifndef ADC_TEST_PATTERN_GEN_MODE_ENABLED
      /** Do delta time check. This should be radar cycle rate*/
      Get_Platform_mstime(&start_mmic_trigger_time);
      Delta_MMIC_Trigger_Time[mmic_trigger_index] = start_mmic_trigger_time - end_mmic_trigger_time;
      if (Delta_MMIC_Trigger_Time[mmic_trigger_index] > Mmic_Trig_Time_Max)
      {
         Mmic_Trig_Time_Max = Delta_MMIC_Trigger_Time[mmic_trigger_index];
      }
      if (Delta_MMIC_Trigger_Time[mmic_trigger_index] < Mmic_Trig_Time_Min)
      {
         Mmic_Trig_Time_Min = Delta_MMIC_Trigger_Time[mmic_trigger_index];
      }
      mmic_trigger_index++;
      mmic_trigger_index = mmic_trigger_index % MAX_TEST_TRIGGER_BUF;
      Get_Platform_mstime(&end_mmic_trigger_time);

   #if 0 // ToDO: Enable as per DSP requirements
      /* RSS/MMIC START trigger here */
      if (Offline_Mode_Flag) // To ensure MSS not to communicate to DSS when Offline_mode_flag is enabled (ITF is
                             // triggerred)
      {
         Radar_ITF_Offline_Mode_Enabled();
      }
      else
      {
         /** Check for DSP application initialized and configured every radar cycle.
          * @todo: Can a check with added wrt the MMIC/RFE status?
          */

         /* we should not put bbe32 in while when we skip the look */
         DSP_Processing_Per_Look_Init();

         if (!DSP_Cfg_Init || !DSP_Init)
         {
            /* Do nothing*/
            State_Radar_Ctl_Configured_Err_Cnt++;
         }
         else
         {
   #endif
      MMIC_Look_Trigger();
      //         }
      //      }
   }
#endif
#ifdef TEST_STUB_PROFILE
   Get_Platform_mstime(&temp4);
#endif
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Idle
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when Over temperature Error is not recovered in Degraded Mode and
 * state machine is in the RADAR_CTL_IDLE state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
#if 0 // ToDo
static void State_Radar_Ctl_Idle(Radar_Ctl_Event_T event)
{
   /* Periodic ***************************************************************/
   if (event == RADAR_CTL_EVENT_PERIODIC)
   {
      MMIC_Look_Complete();

      /* Perform Diag */
      /* Read MMIC Diag and update logging stream */
      // MMIC_Read_Populate_Diag_Data(); //ToDo

      if ((Get_MMIC_Error_Reinit()) || (Get_MMIC_Faulted()))
      {
         // Update_Mmic_Reinit_Status(); //ToDo
         Trans_Radar_Ctl_Off();
         // MMIC_Stream.MMIC_Data.ot_handle.idle_mode_cnt = 0U; /* Clear Error counter if Re-Init is in progress */
      }
      else
      {
         /* do nothing */
      }

   #if 0 // ToDo: Enable if temperature faults/degraded state are required
      /* Check for Temperature ISM status */
      if (CODED_TRUE == Get_Temperature_Hysteresis_Fault())
      {
         MMIC_Stream.MMIC_Data.ot_handle.idle_mode_cnt++; /* Increment counter if Temperature Error is set */
      }
      else /* If Temp Error cleared, clear the Error Counter */
      {
         MMIC_Stream.MMIC_Data.ot_handle.idle_mode_cnt = 0U;
   #endif
         /* Wait for CMD_Radiate to be true for the Radar to resume Normal Mode */
         if (Get_Radar_Radiate_Enable())
         {
            /* Transit to Look Start state as Look Config is done for the cycle */
            Trans_Radar_Ctl_Configured();

            /* To Do - Temporary change. Idle to Normal is causing MMIC Error Code 20. So doing a Re-Init */
            /* this should be changed to Crl_Configured */
            // Trans_Radar_Ctl_Init();           /* Transit to Re-Init */
            Put_Skip_Look_State(CODED_FALSE); /* Core1 trigger via SPT RFFT Done */
         }
//      }
   }

   #if 0 // ToDo: Enable if temperature faults/degraded state are required
   /* If Error is still present */
   if (CODED_TRUE == Get_Temperature_Error_In_Degraded())
   {
      /* X secs in Idle to Faulty transition since ISM Error/Hysteresis is not recovered */
      if ((MMIC_Stream.MMIC_Data.ot_handle.idle_mode_cnt > (uint8_t)(IDLE_TO_FAULTY_TIME_LIMIT)*20U) ||
          (CODED_TRUE == Get_IPs_Over_Temperature_In_Degraded_Status((float)IDLE_TO_FAULTY_DEGC_LIMIT)))
      {
         /* Over Temperature Fault Set */
         MMIC_Stream.MMIC_Data.ot_handle.idle_timeout_status = CODED_TRUE;

         /* Transit to Off State as Radar dint recover in Idle Mode */
         /* to avoid jumping to faulty in case Mode Manager keeps Radar Radiate to True */
         Trans_Radar_Ctl_Off();

         MMIC_Stream.MMIC_Data.ot_handle.idle_mode_cnt = 0U;
      }
   }
   else
   {
      /* ISM Temperature Error is cleared, so stay in idle mode and wait for hysteresis condition to be met */
   }
   #endif
}
/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Degraded_Periodic
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Calling this function causes the Radar Control state machine to
 * transition to the Degraded state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

static void State_Radar_Ctl_Degraded_Periodic(void)
{
   Degraded_Error_Count++;

   /* Max set to 3 -> when Radar transits to Degraded,
      it takes 3 iterations of Degraded events to put
      the Radar in Look Complete */

   if (Degraded_Error_Count >= ERROR_MAX_DEGRADED)
   {
   #ifndef PC_RESIM
      Set_MMIC_Error_Reinit(MMIC_REINIT_ERROR_DEGRADED_TIMEOUT);
   #endif
      if (Get_MMIC_Error_Reinit())
      {
         Update_Mmic_Reinit_Status();
         Trans_Radar_Ctl_Off();
      }
      Degraded_Error_Count = 0U;
   }
   else
   {
      /* Stay in Degraded State to service next events */
      Trans_Radar_Ctl_Degraded();
   }
}

/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Degraded_Trigger
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when Over Temperature fault is raised by the MMIC
 * state machine is in the RADAR_CTL_DEGRADED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Degraded_Trigger(void)
{
   uint8_t flagcheck = 0u;

   MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt++;

   /* Data Acq in alternate Looks */
   if ((MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt % 2U) == 0U)
   {
      /* Core 1 Trigger via SPT RFFT Done */
      Put_Skip_Look_State(CODED_FALSE);

      /* raise flag when look is not skipped */
      look_trigger_flag = true;

      Radar_Ctl_Look_Trigger_Start();
   }
   else /* skip look */
   {
      /* Core0_Core1_Trigger */
      Put_Skip_Look_State(CODED_TRUE);

      /* Perform diag in case look is skipped */
      MMIC_Look_Complete();

      /* Read MMIC Diag and update logging stream */
      /* need to check this function */
      MMIC_Read_Populate_Diag_Data();

      /* Check for Temperature error status */
      if (CODED_TRUE == Get_Temperature_Hysteresis_Fault())
      {
         /* Look Config and Calibration in case look is skipped */
         MMIC_Config_Look();

         /* Stay in Degraded State if Temperature Error is present */
         Trans_Radar_Ctl_Degraded();
      }
      else
      {
         /* Clear Error counter when Temperature ISM status is cleared */
         MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0U;

         /* Jump to normal operational mode */
         Trans_Radar_Ctl_Configured();

         /* need to move here*/
         Degraded_Error_Count = 0U; /* Clear residue count */
      }
   }
   /* Take actions in case the setup has failed */
   if ((Get_MMIC_Error_Reinit()) || (Get_MMIC_Faulted()))
   {
      Update_Mmic_Reinit_Status();
      Trans_Radar_Ctl_Off();

      /* Clear Error counter if Re-Init is in progress */
      MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0U;
   }
   else
   {
      /* do nothing */
   }
}
/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Degraded_Complete
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when Over Temperature fault is raised by the MMIC
 * state machine is in the RADAR_CTL_DEGRADED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Degraded_Complete(void)
{
   /* Clear Error counter if Look Complete Event is received */
   Degraded_Error_Count = 0U;

   // can we replace this code ?
   MMIC_Look_Complete();

   /* Read MMIC Diag and update logging stream */
   MMIC_Read_Populate_Diag_Data();

   /* Increment Look Index and Type irrespective of whether Error was latched or not during DAQ */
   Next_Radar_Look();

   if ((Get_MMIC_Error_Reinit()) || (Get_MMIC_Faulted()))
   {
      // Update_Mmic_Reinit_Status();
      Trans_Radar_Ctl_Off();

      /* Clear Error counter if Re-Init is in progress */
      MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0U;
   }
   else
   {
      if (!Get_Radar_Radiate_Enable())
      {
         Trans_Radar_Ctl_Off();
      }
   #ifndef PC_RESIM
      else if (Get_A2D_Online_Injection_Active())
      {
         Trans_Radar_Ctl_Ready();
      }
   #else
         else if (Get_A2D_Online_Injection_Active())
         {
            Trans_Radar_Ctl_Ready();
         }
   #endif
      else
      {
         /* do nothing */
      }
      /* Check for Temperature ISM status */
      if (CODED_TRUE == Get_Temperature_Hysteresis_Fault())
      {
         MMIC_Config_Look();         /* Config next look */
         Trans_Radar_Ctl_Degraded(); /* Stay in Degraded State if Temperature Error is present */
      }
      else
      {
         /* Clear Error counter when Temperature ISM status is cleared */
         MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0U;

         /* Jump to Look Config state - Resuming normal operation. */
         Trans_Radar_Ctl_Configured();
      }
   }
}
/*===========================================================================*\
 * FUNCTION: State_Radar_Ctl_Degraded
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Radar_Ctl_Event_T event
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called when Over Temperature fault is raised by the MMIC
 * state machine is in the RADAR_CTL_DEGRADED state.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void State_Radar_Ctl_Degraded(Radar_Ctl_Event_T event)
{
   if (event == RADAR_CTL_EVENT_PERIODIC)
   {
      State_Radar_Ctl_Degraded_Periodic();
   }
   /* State Radar Ctl Look Configured */
   if (event == RADAR_CTL_EVENT_LOOK_TRIGGER)
   {
      State_Radar_Ctl_Degraded_Trigger();
   }
   if (event == RADAR_CTL_EVENT_LOOK_COMPLETE) /* Event shall be received only if Data Acq is done. Event not received in case look
                                                  is skipped */
   {
      /* condition check to enter into Degraded_Complete */
      if (look_trigger_flag)
      {
         State_Radar_Ctl_Degraded_Complete();
         look_trigger_flag = false;
      }
   }

   #if 0 // ToDo: Enable if temperature faults/degraded state are required
   if (CODED_TRUE == (Get_Temperature_Error_In_Degraded())) /* If Error is still present */
   {
      /* X secs In Degraded Mode if Error/Hysteresis is not cleared */
      if ((MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt > (uint8_t)(DEGRADED_TO_IDLE_TIME_LIMIT)*20U) //
          || (CODED_TRUE == Get_IPs_Over_Temperature_In_Degraded_Status((float)DEGRADED_TO_IDLE_DEGC_LIMIT)))
      {
         /* Set Idle Mode since Temperature scenario dint improve in 30 secs */
         Trans_Radar_Ctl_Idle();

         /* No Radar operation in Idle Mode */
         /* Core0_Core1_Trigger */

         Put_Skip_Look_State(CODED_TRUE);

         /* Clear Error counter to avoid transition from Degraded to Idle before the time limit in the 2nd instance */
         MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0U;
      }
   }
   else
   {
      /* ISM Temperature Error is cleared, so stay in degraded indefinitely and wait for hysteresis condition to be met */
   }
   #endif
}
#endif
/*===========================================================================*\
 * FUNCTION: Update_Radar_Cw_Mode_Status
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    uint8_t cw_mode_status
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    This function is called to update the Radar Control Pure CW Mode status.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

void Update_Radar_Cw_Mode_Status(uint8_t cw_mode_status)
{
   Radar_Data_Status.radar_data_status_payload.Radar_Ctl_Pure_CW_Mode = cw_mode_status;
   Compute_M7_Rdr_Data_Sts_Payload_CRC();
}
/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Look_Sync_Trig
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Sets internal flag to signal the need to skip the next look trigger
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Look_Sync_Trig(void)
{
   Radar_Trigger_Sync = true;
}

/*===========================================================================*\
 * FUNCTION: Radar_Ctl_Look_Sync_Trig_Tst
 *===========================================================================
 * RETURN VALUE:
 *    bool
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Returns true if the conditions are ok for triggering next look
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Radar_Ctl_Look_Sync_Trig_Tst(void)
{
   return Radar_Trigger_Sync;
}
/*===========================================================================*\

 * FUNCTION: Radar_Ctl_Look_Sync_Trig_Clear
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    clear Radar_Trigger_Sync
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Radar_Ctl_Look_Sync_Trig_Clear(void)
{
   Radar_Trigger_Sync = false;
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 15-May-2023 tjy9rb
 * + DDR-1972: Integrate radar control mode for SmartTRX.
 * 28-May-2024
 * + EPB-2725: [GEN7_V2][MMIC]Coding standard improvements
 * 26-Jul-2024
 * + EPB-3091: [GEN7_V2][Over Temperature Issue Fix]moved DSP_Processing_Per_Look_Init()from
               SWC_Plt_CDD_radar_ctl.c to Radar_ctl.c(inside the Radar_Ctl_Look_Trigger_Start())
* 30-April-2025 :jzrx03
* + EPB : 3774 [GEN8] Implement Radar_Ctl State Machine  Review comments into Gen8
* 21-July-2025 qjgws1  EPB- 3944: Bring the mars reset mechanism from tiger team branch: temporary
* 22-July-2025 jjrfgz  EPB-3984: TICS Coding Standard Improvement
* 20-Jan-2026 ftoobg   EPB-3952: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
* 22-Jan-2026  njsfs0  EPB-4254: CW mode status update in Radar Data Status message
* 23-Feb-2026  ftoobg  EPB-4461 [GNE8]Bring Radar Control SM changes similar to GEN7_V2/GEN7_V1 into GEN8 variant
* 23-Apr-2026  njsfso  EPB-4549: [GEN8][SWE3][R6.0]- CRC computaion for radar data status
* 19-Jun-2026  ftoobg  EPB-4722: [Gen8][SWE1] Update of Register based on OTP
\*===========================================================================*/
