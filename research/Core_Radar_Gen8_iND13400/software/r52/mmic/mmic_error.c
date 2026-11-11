/*===========================================================================*\
 * FILE: mmic_error.c
 *===========================================================================
 * Copyright (C) 2023 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential (C) Restricted Aptiv information. Do not disclose.
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 * This module tracks and reports errors related to the MMIC device drivers.
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *   1. C Coding Standards SW REF 264.15D
 *
 * DEVIATIONS FROM STANDARDS:
 *
\*===========================================================================*/
/*===========================================================================*\
 * Preprocessor #include directive(s) for standard header files
\*===========================================================================*/
#include <string.h>

/*===========================================================================*\
 * Preprocessor #include directive(s) for other header files
\*===========================================================================*/
#include "dd_mmic.h"
#include "mmic_error.h"
#include "mmic_interface.h"
/*===========================================================================*\
 * Local preprocessor #define CONSTANTS
\*===========================================================================*/
#define MMIC_REINIT_FLS_ERROR_MAX_COUNT   ((int8_t)50)
#define MMIC_REINIT_ERROR_COUNT_THRESHOLD ((int8_t)3) // change to 3
#define MMIC_REINIT_ERROR_MAX_COUNT                                                                                               \
   ((MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status) ? ((int8_t)MMIC_REINIT_ERROR_COUNT_THRESHOLD) :         \
                                                                            ((int8_t)MMIC_REINIT_FLS_ERROR_MAX_COUNT))
#define MMIC_REINIT_ERROR_UP_COUNT   ((int8_t)1)
#define MMIC_REINIT_ERROR_DOWN_COUNT ((int8_t)1)

#define MMIC_DISCARD_ERROR_MAX_COUNT  ((int8_t)8)
#define MMIC_DISCARD_ERROR_UP_COUNT   ((int8_t)2)
#define MMIC_DISCARD_ERROR_DOWN_COUNT ((int8_t)1)
#define INIT_ERROR_CLEAR_COUNT        ((int8_t)100)

#define MMIC_CONFIG_ERROR_MAX_COUNT  ((uint8_t)2)
#define MMIC_CONFIG_ERROR_UP_COUNT   ((uint8_t)1)
#define MMIC_CONFIG_ERROR_DOWN_COUNT ((uint8_t)1)
#define MIPI_DISCARD_ERROR_MAX_COUNT ((uint8_t)6)
/*===========================================================================*\
 * Local preprocessor #define MACROS()
\*===========================================================================*/

/*===========================================================================*\
 * Local type declarations (enum, struct, union, typedef)
\*===========================================================================*/

/*===========================================================================*\
 * Exported object definitions
\*===========================================================================*/
MMIC_Error_Data_T MMIC_Error             = {0};
volatile uint8_t API_Look_Config_Error   = 0U;
volatile uint8_t API_Look_Trigger_Error  = 0U;
volatile uint8_t API_Look_Complete_Error = 0U;
/*===========================================================================*
 * Local File Scope Variables
 *===========================================================================*/
static bool XCP_MMIC_Disable_Faults = false;
/*===========================================================================*\
 * Local function prototypes
\*===========================================================================*/
/*===========================================================================*\
 * Local inline function definitions and #define function-like macros
\*===========================================================================*/
/*===========================================================================*\
 * Function definitions
\*===========================================================================*/
/*===========================================================================*\
 * FUNCTION: Update_MMIC_Success
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function decrements the error counters after a successful look.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Update_MMIC_Success(void)
{
   MMIC_Error.reinit_clear_count++;

   if (MMIC_Error.reinit_clear_count >= INIT_ERROR_CLEAR_COUNT)
   {
      MMIC_Error.reinit_clear_count = 0;

      MMIC_Error.reinit_error_count -= MMIC_REINIT_ERROR_DOWN_COUNT;
      if (MMIC_Error.reinit_error_count <= 0)
      {
         MMIC_Error.reinit_error_count = 0;
      }
   }

   MMIC_Error.discard_error_count -= MMIC_DISCARD_ERROR_DOWN_COUNT;
   if (MMIC_Error.discard_error_count < 0)
   {
      MMIC_Error.discard_error_count = 0;
   }
}

/*===========================================================================*\
 * FUNCTION: Set_MMIC_Faulted
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Calling this function will cause the radar control state machine to go to
 * the faulted state.  This will result in all calls to the MMIC device
 * drivers to be halted.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Set_MMIC_Faulted(void)
{
   MMIC_Error.faulted = true;
}

/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Faulted
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Calling this function will clear the MMIC faulted state allowing the
 * return of normal operation.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clr_MMIC_Faulted(void)
{
   MMIC_Error.faulted             = false;
   MMIC_Error.reinit_error        = false;
   MMIC_Error.reinit_error_count  = 0;
   MMIC_Error.discard_error       = false;
   MMIC_Error.discard_error_count = 0;
}
/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Reinit_Error_Count
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC reinit error count.
 * --------------------------------------------------------------------------*/
void Clr_MMIC_Reinit_Error_Count(void)
{
   MMIC_Error.reinit_error_count = 0;
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Faulted
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returning TRUE from this function will cause the radar control state
 * machine to go to the faulted state.  This will result in all calls to
 * the MMIC device drivers to be halted.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Get_MMIC_Faulted(void)
{
   return (MMIC_Error.faulted);
}

/*===========================================================================*\
 * FUNCTION: Set_MMIC_Error_Reinit
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    MMIC_Error_ID_T error_id
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function sets the MMIC configuration error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Set_MMIC_Error_Reinit(MMIC_Error_ID_T error_id)
{
   // TO be removed once FLS read functions properly --- IGNORE ---
   Clr_MMIC_Reinit_Count_Post_Init();

   MMIC_Error.reinit_error_total++;
   MMIC_Error.error_counters.u16[error_id]++;

   if (!XCP_MMIC_Disable_Faults)
   {
      if (!MMIC_Error.reinit_error)
      {
         MMIC_Error.reinit_error       = true;
         MMIC_Error.reinit_clear_count = 0;
         MMIC_Reset_MARS();
      }
      MMIC_Error.reinit_error_count += MMIC_REINIT_ERROR_UP_COUNT;
   }

   if (MMIC_Error.reinit_error_count > MMIC_REINIT_ERROR_MAX_COUNT) // check if the var is true or not
   {
      MMIC_Error.faulted = true;
   }

   memcpy(&MMIC_Stream.MMIC_Data.MMIC_Reinit_Reset_Reason[0], &MMIC_Error.error_counters.u16[0],
          sizeof(MMIC_Stream.MMIC_Data.MMIC_Reinit_Reset_Reason));
}

/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Error_Reinit
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC configuration error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clr_MMIC_Error_Reinit(void)
{
   MMIC_Error.reinit_error        = false;
   MMIC_Error.discard_error       = false;
   MMIC_Error.discard_error_count = 0;
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_Reinit
 *===========================================================================
 * RETURN VALUE:
 *    bool MMIC Look Error is Active
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return true if a MMIC Configuration Error has been set.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Get_MMIC_Error_Reinit(void)
{
   return (MMIC_Error.reinit_error);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_Reinit_Count
 *===========================================================================
 * RETURN VALUE:
 *    uint16_t reinit_error_count - The total number of times a reinit error
 *                                  has occurred.
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return the total number of reinit errors that have occurred.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint16_t Get_MMIC_Error_Reinit_Count(void)
{
   return (MMIC_Error.reinit_error_total);
}

/*===========================================================================*\
 * FUNCTION: Set_MMIC_Error_Discard
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    MMIC_Error_ID_T error_id
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function sets the MMIC look error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Set_MMIC_Error_Discard(MMIC_Error_ID_T error_id)
{
   MMIC_Error.discard_error_total++;
   MMIC_Error.error_counters.u16[error_id]++;

   if (!XCP_MMIC_Disable_Faults)
   {
      MMIC_Error.discard_error = true;

      MMIC_Error.discard_error_count += MMIC_DISCARD_ERROR_UP_COUNT;

      if (MMIC_Error.discard_error_count >= MMIC_DISCARD_ERROR_MAX_COUNT)
      {
         MMIC_Error.discard_error_count = MMIC_DISCARD_ERROR_MAX_COUNT;
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Error_Discard
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC look error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clr_MMIC_Error_Discard(void)
{
   MMIC_Error.discard_error = false;
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_Discard
 *===========================================================================
 * RETURN VALUE:
 *    bool MMIC Look Error is Active
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return true if a MMIC Look Error has been set.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Get_MMIC_Error_Discard(void)
{
   return (MMIC_Error.discard_error);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_Discard_Count
 *===========================================================================
 * RETURN VALUE:
 *    uint16_t discard_error_count - The total number of times a discard error
 *                                   has occurred.
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return the total number of discard errors that have occurred.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint16_t Get_MMIC_Error_Discard_Count(void)
{
   return (MMIC_Error.discard_error_total);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_By_ID
 *===========================================================================
 * RETURN VALUE:
 *    uint16_t reinit_error_count - The total number of times the requested
 *                                  error has occurred.
 *
 * PARAMETERS:
 *    MMIC_Error_ID_T error_id
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return the total number of errors that have occurred for the
 * requested ID.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint16_t Get_MMIC_Error_By_ID(MMIC_Error_ID_T error_id)
{
   return (MMIC_Error.error_counters.u16[error_id]);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Error_Counters_ptr
 *===========================================================================
 * RETURN VALUE:
 *    uint16_t* Error_Counters - The ptr to list of error counters.
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return the total number of discard errors that have occurred.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint16_t *Get_MMIC_Error_Counters_ptr(void)
{
   return ((uint16_t *)(&MMIC_Error.error_counters));
}

/*===========================================================================*\
 * FUNCTION: Set_MMIC_Config_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    MMIC_Error_ID_T error_id
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function sets the MMIC Config error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Set_MMIC_Config_Error(MMIC_Config_Error_ID_T error_id)
{
   MMIC_Error.MMIC_config_error_counters.u16[error_id]++;

   if (!MMIC_Error.MMIC_config_error)
   {
      MMIC_Error.MMIC_config_error_count += MMIC_CONFIG_ERROR_UP_COUNT;
      MMIC_Error.MMIC_config_error = true;
   }
   if (MMIC_Error.MMIC_config_error_count >= MMIC_CONFIG_ERROR_MAX_COUNT)
   {
      MMIC_Error.function_config_fault   = CODED_TRUE;
      MMIC_Error.MMIC_config_error_count = MMIC_CONFIG_ERROR_MAX_COUNT;
   }
   /*In Gen 8 any issue during init is deemed a failure and needs a mars reset */
   MMIC_Error.faulted = true;
}
/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Config_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC Config error.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clr_MMIC_Config_Error(void)
{
   MMIC_Error.MMIC_config_error = false;
}

/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Config_Error_Cnt
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC Config error Count once Rfe Look and Csi2
 * Ppe configuration is SUCCESS
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clr_MMIC_Config_Error_Cnt(void)
{
   MMIC_Error.MMIC_config_error_count = 0U;
}
/*===========================================================================*\
 * FUNCTION: Get_MMIC_Config_Error
 *===========================================================================
 * RETURN VALUE:
 *    bool MMIC Config Error is Active
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return true if a MMIC Config Error has been set.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Get_MMIC_Config_Error(void)
{
   return (MMIC_Error.MMIC_config_error);
}

/*===========================================================================*\
 * FUNCTION: Get_Function_Config_Error
 *===========================================================================
 * RETURN VALUE:
 *    U8  MMIC/MIPI/CTE Config Error is Active
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return true if a MMIC/MIPI/CTE Config Error has been set.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_Function_Config_Error(void)
{
   return (MMIC_Error.function_config_fault);
}
/*===========================================================================*\
* FUNCTION: Clr_MMIC_API_Look_Fault_Status
*===========================================================================
* RETURN VALUE:
*    void
*
* PARAMETERS:
*    void
*
* --------------------------------------------------------------------------
* ABSTRACT:
* This function resets the API Look Fault Status counters.
* --------------------------------------------------------------------------
*
\*===========================================================================*/
void Clr_MMIC_API_Look_Fault_Status(void)
{
   API_Look_Config_Error   = 0U;
   API_Look_Trigger_Error  = 0U;
   API_Look_Complete_Error = 0U;
}

/*===========================================================================*\
 * FUNCTION: Get_MIPI_Fault
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t
 *
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function return the MIPI data fault status
 * of Radar
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MIPI_Fault(void)
{
   MIPI_FuSa_IRQ_Fault_Info_T *mipi_fusa_irq_ptr = &MMIC_Stream.MMIC_Data.MIPI_FuSa_fault_info;
   return mipi_fusa_irq_ptr->mipi_data_fault;
}

/*===========================================================================*\
 * FUNCTION: Clr_MMIC_Reinit_Count_Post_Init
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function clears the MMIC reinit error count after successful
 * initialization when the state machine is operational.
 * --------------------------------------------------------------------------
\*===========================================================================*/
void Clr_MMIC_Reinit_Count_Post_Init(void)
{
   // To-Do: Code should be removed once FLS read functions properly
   // Clear MMIC_Error.reinit_error_count right after initialization and before the first look trigger to avoid false faulting due
   // to any initialization errors
   if ((MMIC_Stream.MMIC_Data.mmic_config_status.mars_initialization_status) &&
       (MMIC_Error.reinit_error_count > MMIC_REINIT_ERROR_COUNT_THRESHOLD))
   {
      Clr_MMIC_Reinit_Error_Count();
   }
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------  ----------------------------------------------------
 * 09-Jul-2025  ftoobg  EPB-3725: [Gen8] [MMIC][R3.0][SWE_3][mmic_error.c]: Tics_Improvement
 * 17-Jul-2025  ftoobg  EPB-3903: [Gen8][SWE3][R3.0] Use Case: Request Safe Start up: Transceiver and peripheral initialization and
                                  failure
 * 29-Jul-2025  qjgws1  EPB-3943: Workaround for core freeze upon reset during init
 * 20-Aug-2025  ftoobg  EPB-4023: [GEN8]Implement Function Config Fault & Validate
 * 29-Dec-2025  ftoobg  EPB-4264: [Gen8][SWE3]MARS safety: API return value handling
 * 28-Nov-2025  ftoobg  EPB-4128: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 06-Jan-2026  qjgws1  EPB-4311: [GEN8][MMIC] Impriove MMIC fault handling during init
 * 23-Feb-2026  ftoobg EPB-4461 [GNE8]Bring Radar Control SM changes similar to GEN7_V2/GEN7_V1 into GEN8 variant
 * 12-Feb-2026  djdgwr  EPB-4387: [Gen8][MMIC] Added Clr_MMIC_Config_Error as part of fault injection using XCP F1 12
 * 23-Feb-2026  ftoobg  EPB-4410 [Gen8][SWE6] Mars Safety: MMIC Safety Critical Errors Handling
 * 16-June-2026 jjrfgz   EPB-4692 Reinit Error count check updated
 \*===========================================================================*/
