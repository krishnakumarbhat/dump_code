/*===========================================================================*/
/**
 * @file mipi_irq.c
 *
 * MIPI module
 *
 * @date    date created:   28-02-2024
 *
 * @section DESCRIPTION:
 *
 * MIPI module
 *------------------------------------------------------------------------------
 *
 * @copyright 2023 indie Semiconductor.
 *
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor
 *
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * MIPI module IRQ part
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - None
 *
 *   - Requirements Document(s):
 *     - None
 *
 *   - Applicable Standards:
 *     - None
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - None
 *
 */
/*===========================================================================*/

/*===========================================================================*
 * Includes
 *===========================================================================*/
#include "mipi_interrupt.h"
#include "Std_Types.h"
#include "chandra_r52.h"
#include "chandra_r52_irq.h"
#include "dd_mipi.h"
#include "system_chandra.h"

/*===========================================================================*
 * Local Constant Macros
 *===========================================================================*/
#define NUM_OF_VECTOR_SAMPLES_PER_CHANNEL 4U
#define NUM_OF_VECTOR_SAMPLES             (MIPI_MAX_INPUT_CHANNELS * NUM_OF_VECTOR_SAMPLES_PER_CHANNEL)
/*===========================================================================*
 * Local Function Macros
 *===========================================================================*/

/*===========================================================================*
 * Local Datatypes and Structures
 *===========================================================================*/
typedef __attribute__((ext_vector_type(NUM_OF_VECTOR_SAMPLES))) uint16_t uint16x16;
typedef __attribute__((aligned(32))) union Mipi_4ch_4samples_Vector_Tag
{ /* polyspace MISRA-C3:19.2 "used for the write re" */
   int16_t samples_data[NUM_OF_VECTOR_SAMPLES];
   uint16x16 vec_sample_data; /* vector of 4 channels of 4 samples of MIPI output data (256 bits) */
} Mipi_4ch_4samples_Vector_T;

/* ===========================================================================*
 * Global Data
 *===========================================================================*/
volatile int16_t __attribute__((aligned(32))) Generated_Chirp_Data_Samples[4][SYMBOLS_PER_CHIRP] = {0};
volatile uint32_t Chirp_Counter                                                                  = 0;
volatile uint32_t Number_Rx_To_Copy             = 0; // If this is set to 4 (as it should be) - the test will crash.
volatile uint32_t Max_Wait_Count_For_RA_Request = 0;
volatile uint32_t Min_Wait_Count_For_RA_Request = 0xFFFFFFFF;

/*===========================================================================*
 * Imported Data
 *===========================================================================*/

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/
static volatile Mipi_4ch_4samples_Vector_T mipi_4samples_vector;
static mipi_ithandler MIPI_Frm_Start_Handler      = NULL_PTR;
static mipi_ithandler MIPI_Frm_End_Handler        = NULL_PTR;
static mipi_ithandler MIPI_Chp_Start_Handler      = NULL_PTR;
static mipi_ithandler MIPI_Chp_End_Handler        = NULL_PTR;
static mipi_ithandler MIPI_Chp_Fusa_Irq_Handler   = NULL_PTR;
static volatile bool MIPI_Frame_Start_Flag        = false;
static volatile bool MIPI_Frame_End_Flag          = false;
static volatile bool MIPI_Chirp_Start_Flag        = false;
static volatile bool MIPI_Chirp_End_Flag          = false;
static volatile bool MIPI_Fusa_Irq_Flag           = false;
static volatile uint32_t MIPI_Chirp_Start_Irq_Cnt = 0U;
static volatile uint32_t MIPI_Chirp_End_Irq_Cnt   = 0U;
static volatile uint32_t MIPI_Frame_Start_Irq_Cnt = 0U;
static volatile uint32_t MIPI_Frame_End_Irq_Cnt   = 0U;
static volatile uint32_t MIPI_FuSa_Irq_Cnt        = 0U;
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Function Definitions
 *===========================================================================*/
/*===========================================================================*\
 * FUNCTION: MIPI_Irq_Setup
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - E_OK on success, aggregated error flags otherwise
 *
 * PARAMETERS:
 *    const mipi_ithandler frm_start_handler - optional frame start callback
 *    const mipi_ithandler frm_end_handler   - optional frame end callback
 *    const mipi_ithandler chp_start_handler - optional chirp start callback
 *    const mipi_ithandler chp_end_handler   - optional chirp end callback
 *    const mipi_ithandler mipi_FuSa_IRQ_handler - optional FuSa callback
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Configure the interrupt controller and MIPI block for requested IRQ
 *    callbacks, enabling or disabling each source per handler presence
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Irq_Setup(const mipi_ithandler frm_start_handler, const mipi_ithandler frm_end_handler,
                              const mipi_ithandler chp_start_handler, const mipi_ithandler chp_end_handler,
                              const mipi_ithandler MIPI_FuSa_IRQ_handler)
{
   uint32_t return_value     = (uint32_t)E_OK;
   MIPI_Frm_Start_Handler    = frm_start_handler;
   MIPI_Frm_End_Handler      = frm_end_handler;
   MIPI_Chp_Start_Handler    = chp_start_handler;
   MIPI_Chp_End_Handler      = chp_end_handler;
   MIPI_Chp_Fusa_Irq_Handler = MIPI_FuSa_IRQ_handler;

   if (NULL_PTR != MIPI_FuSa_IRQ_handler)
   {
      /* Enable the below Interrupts based on the Indie */
      ptrMIPI->FUSA_IRQ0_EN.r = MIPI_FUSA_IRQ0_ENABLE_MASK;
      ptrMIPI->FUSA_IRQ1_EN.r = MIPI_FUSA_IRQ1_ENABLE_MASK;
      ptrMIPI->FUSA_IRQ2_EN.r = MIPI_FUSA_IRQ2_ENABLE_MASK;

      /* Clearing the MIPI FuSa Status flag Status Interrupt */

      MIPI_Fusa_Irq_Flag = false;
   }
   else
   {
      /* Disable and clear the MIPI FuSa interrupts when no handler is registered */
      ptrMIPI->FUSA_IRQ0_EN.r   = 0U;
      ptrMIPI->FUSA_IRQ1_EN.r   = 0U;
      ptrMIPI->FUSA_IRQ2_EN.r   = 0U;
      ptrMIPI->FUSA_IRQ0_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;
      ptrMIPI->FUSA_IRQ1_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;
      ptrMIPI->FUSA_IRQ2_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;
   }

   if (NULL_PTR != frm_start_handler)
   {
      MIPI_Frame_Start_Flag     = false;
      ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_START_FLAG_msk;
      ptrMIPI->FRAME_IRQ_EN.r |= MIPI_FRAME_IRQ_EN_FRAME_START_EN_msk; /* Enable IRQ for frame start */
   }
   else
   {
      ptrMIPI->FRAME_IRQ_EN.r &= ~MIPI_FRAME_IRQ_EN_FRAME_START_EN_msk; /* Disable IRQ for frame start */
   }

   if (NULL_PTR != frm_end_handler)
   {
      MIPI_Frame_End_Flag       = false;
      ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_END_FLAG_msk;
      ptrMIPI->FRAME_IRQ_EN.r |= MIPI_FRAME_IRQ_EN_FRAME_END_EN_msk; /* Enable IRQ for frame end */
   }
   else
   {
      ptrMIPI->FRAME_IRQ_EN.r &= ~MIPI_FRAME_IRQ_EN_FRAME_END_EN_msk; /* Disable IRQ for frame end */
   }

   if (NULL_PTR != chp_start_handler)
   {
      MIPI_Chirp_Start_Flag     = false;
      ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk;
      ptrMIPI->CHIRP_IRQ_EN.r |= MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk; /* Enable IRQ for chirp start */
   }
   else
   {
      ptrMIPI->CHIRP_IRQ_EN.r &= ~MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk; /* Disable IRQ for chirp start */
   }

   if (NULL_PTR != chp_end_handler)
   {
      MIPI_Chirp_End_Flag       = false;
      ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;
      ptrMIPI->CHIRP_IRQ_EN.r |= MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk; /* Enable IRQ for chirp end */
   }
   else
   {
      ptrMIPI->CHIRP_IRQ_EN.r &= ~MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;
      ;
   }
   /* For signal processing, the chirp end interrupt must be enabled in the MIPI. */
   ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;
   ptrMIPI->CHIRP_IRQ_EN.r |= MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk; /* Enable IRQ for chirp end */

   ensureInterruptsNotMasked();
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Get_Frm_End_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - E_OK on success, E_NOT_OK for null pointer
 *
 * PARAMETERS:
 *    volatile bool *flag - output pointer updated with frame end indication
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Retrieve the current frame end status flag sourced either from ISR state
 *    or directly from the hardware register when no handler is installed
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Get_Frm_End_Flag(volatile bool *flag)
{
   uint32_t return_value = (uint32_t)E_NOT_OK;
   if (NULL_PTR != flag)
   {
      return_value = (uint32_t)E_OK;
      if (NULL_PTR == MIPI_Frm_End_Handler)
      {
         *flag = (FALSE != ptrMIPI->FRAME_IRQ_FLAG.f.FRAME_END_FLAG);
      }
      else
      {
         *flag = MIPI_Frame_End_Flag;
      }
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: Mipi_Clear_Frm_End_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - always E_OK after clearing the indication
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Clear the frame end flag by either writing the hardware register or
 *    resetting the cached ISR flag when a callback is registered
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Clear_Frm_End_Flag(void)
{
   uint32_t return_value = (uint32_t)E_OK;

   if (NULL_PTR == MIPI_Frm_End_Handler)
   {
      ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_END_FLAG_msk;
   }
   else
   {
      MIPI_Frame_End_Flag = FALSE;
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Get_Frm_Start_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - E_OK when flag is valid, E_NOT_OK if pointer null
 *
 * PARAMETERS:
 *    volatile bool *flag - output pointer receiving frame start state
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Read the frame start flag sourced from ISR-managed cache or hardware
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Get_Frm_Start_Flag(volatile bool *flag)
{
   uint32_t return_value = (uint32_t)E_NOT_OK;

   if (NULL_PTR != flag)
   {
      if (NULL_PTR == MIPI_Frm_Start_Handler)
      {
         *flag = (FALSE != ptrMIPI->FRAME_IRQ_FLAG.f.FRAME_START_FLAG);
      }
      else
      {
         *flag = MIPI_Frame_Start_Flag;
      }
      return_value = (uint32_t)E_OK;
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Clear_Frm_Start_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - always E_OK after clearing
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Reset the frame start flag through register write or cached value clear
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Clear_Frm_Start_Flag(void)
{
   uint32_t return_value = (uint32_t)E_OK;
   if (NULL_PTR == MIPI_Frm_Start_Handler)
   {
      ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_START_FLAG_msk;
   }
   else
   {
      MIPI_Frame_Start_Flag = false;
   }

   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Get_Chp_Start_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - E_OK when flag read succeeds, E_NOT_OK for null pointer
 *
 * PARAMETERS:
 *    volatile bool *flag - output pointer capturing chirp start state
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Acquire the chirp start flag from ISR state or hardware register
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Get_Chp_Start_Flag(volatile bool *flag)
{
   uint32_t return_value = (uint32_t)E_NOT_OK;
   if (NULL_PTR != flag)
   {
      return_value = (uint32_t)E_OK;
      if (NULL_PTR == MIPI_Chp_Start_Handler)
      {
         *flag = (FALSE != ptrMIPI->CHIRP_IRQ_FLAG.f.CHIRP_START_FLAG);
      }
      else
      {
         *flag = MIPI_Chirp_Start_Flag;
      }
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Clear_Chp_Start_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - always E_OK after clearing
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Clear the chirp start status via register write or cached flag reset
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Clear_Chp_Start_Flag(void)
{
   uint32_t return_value = (uint32_t)E_OK;
   if (NULL_PTR == MIPI_Chp_Start_Handler)
   {
      ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk;
      return_value              = (uint32_t)E_OK;
   }
   else
   {
      MIPI_Chirp_Start_Flag = false;
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Get_Chp_End_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - E_OK when output flag is valid, E_NOT_OK otherwise
 *
 * PARAMETERS:
 *    volatile bool *flag - pointer updated with chirp end indication
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Return the chirp end status flag from ISR cache or hardware register
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Get_Chp_End_Flag(volatile bool *flag)
{
   uint32_t return_value = (uint32_t)E_NOT_OK;
   if (NULL_PTR != flag)
   {
      return_value = (uint32_t)E_OK;
      if (NULL_PTR == MIPI_Chp_End_Handler)
      {
         *flag = (FALSE != ptrMIPI->CHIRP_IRQ_FLAG.f.CHIRP_END_FLAG);
      }
      else
      {
         *flag = MIPI_Chirp_End_Flag;
      }
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Clear_Chp_End_Flag
 *===========================================================================
 * RETURN VALUE:
 *    Std_ReturnType - always E_OK after flag clear
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Acknowledge the chirp end condition via register write or cached flag reset
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Std_ReturnType MIPI_Clear_Chp_End_Flag(void)
{
   uint32_t return_value = (uint32_t)E_OK;
   if (NULL_PTR == MIPI_Chp_End_Handler)
   {
      ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;
   }
   else
   {
      MIPI_Chirp_End_Flag = false;
   }
   return (Std_ReturnType)return_value;
}

/*===========================================================================*\
 * FUNCTION: Mipi_Frame_Start_Handler
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    ISR entry for frame start that updates the cached flag and invokes callback
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_Frame_Start_Handler(void)
{
   MIPI_Frame_Start_Flag = true;
   if (NULL_PTR != MIPI_Frm_Start_Handler)
   {
      MIPI_Frm_Start_Handler();
   }
   ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_START_FLAG_msk;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Frame_End_Handler
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    ISR entry for frame end that records state and invokes registered callback
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_Frame_End_Handler(void)
{
   MIPI_Frame_End_Flag = true;
   if (NULL_PTR != MIPI_Frm_End_Handler)
   {
      MIPI_Frm_End_Handler();
   }
   ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_END_FLAG_msk;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Chirp_Start_Handler
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    ISR for chirp start that sets the cached flag and executes callback
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_Chirp_Start_Handler(void)
{
   MIPI_Chirp_Start_Flag = true;
   if (NULL_PTR != MIPI_Chp_Start_Handler)
   {
      MIPI_Chp_Start_Handler();
   }
   ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Chirp_End_Handler
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    ISR for chirp end that updates cached state and calls optional handler
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_Chirp_End_Handler(void)
{
   MIPI_Chirp_End_Flag = true;
   if (NULL_PTR != MIPI_Chp_End_Handler)
   {
      MIPI_Chp_End_Handler();
   }
   ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;
}

/*===========================================================================*\
 * FUNCTION: Mipi_FuSa_Irq_Handler
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    ISR for MIPI FuSa interrupt that sets flag and triggers registered callback
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_FuSa_Irq_Handler(void)
{
   MIPI_Fusa_Irq_Flag = true;

   /* Clear the hardware FuSa flag registers to acknowledge the interrupt and prevent re-assertion */
   ptrMIPI->FUSA_IRQ0_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;
   ptrMIPI->FUSA_IRQ1_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;
   ptrMIPI->FUSA_IRQ2_FLAG.r = MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK;

   if (NULL_PTR != MIPI_Chp_Fusa_Irq_Handler)
   {
      MIPI_Chp_Fusa_Irq_Handler();
   }
}

/*===========================================================================*\
 * FUNCTION: Start_MIPI_Chirp
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Count a chirp start event for diagnostics or profiling
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Start_MIPI_Chirp(void)
{
   MIPI_Chirp_Start_Irq_Cnt++;
}

/*===========================================================================*\
 * FUNCTION: End_MIPI_Chirp
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Handle chirp completion bookkeeping and copy debug samples when required
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void End_MIPI_Chirp(void)
{
   MIPI_Chirp_End_Irq_Cnt++;
   volatile uint16x16 *ptr2mipi_ocp_mem = (volatile uint16x16 *)((MIPI_OCP_MEM_SFRS_t *const)MIPI_OCP_MEM_base);
   uint32_t i                           = 0;
   uint32_t rx_ant;
   // MIPI_4ch_4samples_Vector_T mipi_4samples_vector;

   // Profiling_Helpers_Update(&Chirp_Profiling);

   /* samples_data is the output data of the MIPI wrapper */
   int16_t *mipi_out_data = (int16_t *)&mipi_4samples_vector.vec_sample_data;
   // uint32_t wait_cycles_for_ra_request = 0;

   Chirp_Counter++;
   MIPI_Clear_Chp_End_Flag();
   /* Disable this, with the test pattern disabled during chirp end processing. */
   // while (false && !MIPI_Helpers_Get_RA_Read_Request_Flag())
   // {
   //    wait_cycles_for_ra_request++;
   // }

   // if (wait_cycles_for_ra_request > Max_Wait_Count_For_RA_Request)
   // {
   //    Max_Wait_Count_For_RA_Request = wait_cycles_for_ra_request;
   // }
   // else
   // {
   //    /* Do Nothing */
   // }

   // if (wait_cycles_for_ra_request < Min_Wait_Count_For_RA_Request)
   // {
   //    Min_Wait_Count_For_RA_Request = wait_cycles_for_ra_request;
   // }
   // else
   // {
   //    /* Do Nothing */
   // }

   for (rx_ant = 0; rx_ant < Number_Rx_To_Copy; rx_ant++)
   {
      for (i = 0; i < SYMBOLS_PER_CHIRP / 16; i++)
      {
         uint32_t j;
         mipi_4samples_vector.vec_sample_data = *ptr2mipi_ocp_mem;

         for (j = 0; j < 4; j++)
         {
            uint32_t mipi_index = j * 4;
            uint32_t index      = 4 * i + j;

            Generated_Chirp_Data_Samples[rx_ant][index] = mipi_out_data[mipi_index++];
            index += SYMBOLS_PER_CHIRP / 4;
            Generated_Chirp_Data_Samples[rx_ant][index] = mipi_out_data[mipi_index++];
            index += SYMBOLS_PER_CHIRP / 4;
            Generated_Chirp_Data_Samples[rx_ant][index] = mipi_out_data[mipi_index++];
            index += SYMBOLS_PER_CHIRP / 4;
            Generated_Chirp_Data_Samples[rx_ant][index] = mipi_out_data[mipi_index++];
         }
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Start_Mipi_Frame
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Increment the frame start counter for monitoring
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Start_MIPI_Frame(void)
{
   MIPI_Frame_Start_Irq_Cnt++;
}

/*===========================================================================*\
 * FUNCTION: End_MIPI_Frame
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Increment the frame end counter for diagnostics
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void End_MIPI_Frame(void)
{
   MIPI_Frame_End_Irq_Cnt++;
}

/*===========================================================================*\
 * FUNCTION: Mipi_FuSa_IRQ
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Increment the FuSa interrupt counter used for monitoring
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_FuSa_IRQ(void)
{
   MIPI_FuSa_Irq_Cnt++;
}

#ifdef __arm__
/*===========================================================================*\
 * FUNCTION: ensureInterruptsNotMasked
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Ensure CPSR IRQ/FIQ bits are cleared so interrupts remain enabled
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void ensureInterruptsNotMasked(void)
{ // TODO: [captain] move this elsewhere?
   CPSR_Type cpsr = (CPSR_Type){.w = __get_CPSR()};
   // no-stdio-here printf("CPSR:0x%8x Thumb:%s\n", cpsr.w, cpsr.b.T? "1":"0"); // debug only
   if ((cpsr.b.F != 0U) || (cpsr.b.I != 0U))
   {
      // no-stdio-here printf("WARNING: ");
      // no-stdio-here if      (cpsr.b.F && cpsr.b.I) printf("Both IRQ and FIQ were masked\n");
      // no-stdio-here else if (cpsr.b.F)             printf("FIQ was masked (but not IRQ)\n");
      // no-stdio-here else                           printf("IRQ was masked (but not FIQ)\n");
      cpsr.b.F = 0U;
      cpsr.b.I = 0U;
      __set_CPSR(cpsr.w);
      __ISB(); // TODO: o [captain] always(?) prudent after writing to CPSR (? = need to check)
   }
}
#endif
