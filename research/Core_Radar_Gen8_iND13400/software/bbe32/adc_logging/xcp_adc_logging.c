/*===========================================================================*/
/**
 * @file xcp_adc_logging.c
 *
 * APIs for ADC data logging implementation
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
#include "api/bbe_helpers.h"
#include "ipc_dsp.h"
#include "range_process.h"
#include "spbb_cfg.h"
#include "xcp_adc_logging.h"

// Exclude this if ADC logging is not enabled.
#if ENABLE_ADC_DATA_LOGGING == (1U)
   #ifdef __XTENSA__
      #include <xtensa/hal.h>
   #else
      #include "core-macros.h"
   #endif
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

/* This buffer is for the output of the chirp data from the RA.
   The data is 24 bits packed, so must be post processed to the output buffer. */
Range_Proc_XCP_Temp_T __attribute__((section(".sram1.bss"), aligned(32))) XCP_Range_Process_Data;

/*===========================================================================*\
 * Local object definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Local Inline Function Definitions and #define Function-Like Macros()
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/**
 *  @b Description
 *  @n Configure the range processing to output the XCP data
 *
 *    K_MAX is used for the selection, instead of num_chirps for the current look, so that if
 *    the xcp mode is selected for ADC output, it doesn't toggle between the two modes, which means
 *    that if chirp number 1020 is selected, and the look only has 1016 chirps, then the ADC output
 *    will be 0.
 *
 *    This implementation makes it deterministic what the behavior will be -
 *
 *    If the XCP ADC chirp number is below K_MAX, then ADC chirp output is enabled.
 *    If the XCP lightly compressed range bin is less than the max number of range bins, lightly compressed output is enabled.
 *    Otherwise, XCP outputs are disabled.
 *
 * @param[in] uint16_t selected chirp number to log
 *
 * @retval void
 *
 * @note Called in the interrupt context of the IPC interrupt.
 *
 */
void Configure_ADC_XCP_Output(void)
{
   volatile D2M_Msg_T *d2m_msg_ptr   = Get_RP_IPC_D2M_Msg_Buffer();
   volatile XCP_Data_T *xcp_data_ptr = &d2m_msg_ptr->payload.xcp_data;
   uint16_t chirp_number             = xcp_data_ptr->xcp_adc_chirp;
   uint16_t restore_chirp_number     = xcp_data_ptr->xcp_adc_restore_chirp;
   uint16_t range_bin                = xcp_data_ptr->xcp_light_comp_range;
   bool xcp_configured               = true;

   if (chirp_number < K_MAX)
   {
      restore_chirp_number = K_MAX;
      range_bin            = MAX_RANGE_BINS;
   }
   else if (restore_chirp_number < K_MAX)
   {
      chirp_number = K_MAX;
      range_bin    = MAX_RANGE_BINS;
   }
   else if (range_bin < MAX_RANGE_BINS)
   {
      restore_chirp_number = K_MAX;
      chirp_number         = K_MAX;
   }
   else
   {
      /* Neither mode is selected, no need to call XCP Init. */
      xcp_configured = false;
   }

   if (xcp_configured)
   {
      /* Clear the output buffer for the XCP logged data to clear out data from the previous frame data output */
      vector_clear((void *)(uintptr_t)&xcp_data_ptr->range_process_ra_output, sizeof(Range_Proc_XCP_Output_T));
      vector_clear(&XCP_Range_Process_Data, sizeof(XCP_Range_Process_Data));
      XCP_Range_Process_Data.range_output_ptr =
         (XCP_RFFT_Comp_Output_T *)(uintptr_t)&xcp_data_ptr->range_process_ra_output.compressed_range_bin;
      Range_Process_Xcp_Init(chirp_number, restore_chirp_number, range_bin, &XCP_Range_Process_Data);
      xthal_dcache_block_writeback_inv(&XCP_Range_Process_Data, sizeof(XCP_Range_Process_Data));
   }
   else
   {
      xcp_data_ptr->xcp_adc_chirp         = K_MAX;
      xcp_data_ptr->xcp_adc_restore_chirp = K_MAX;
      xcp_data_ptr->xcp_light_comp_range  = MAX_RANGE_BINS;
   }
}

/**
 *  @b Description
 *  @n Copy the ADC data from the temporary memory to the XCP ADC buffer.
 *
 *
 * @retval void
 */
void Post_Process_ADC_Data_Buffer(void)
{
   volatile D2M_Msg_T *d2m_msg_ptr = Get_RP_IPC_D2M_Msg_Buffer();

   /* Configure_ADC_XCP_Output sets xcp_adc_chirp to K_MAX if the mode is not enabled. */
   if (d2m_msg_ptr->payload.xcp_data.xcp_adc_chirp < K_MAX)
   {
      Range_Process_Xcp_Out_Post_Processing((int16_t *)(uintptr_t) &
                                            (d2m_msg_ptr->payload.xcp_data.range_process_ra_output.adc_chirp[0]));
   }
   else if (d2m_msg_ptr->payload.xcp_data.xcp_adc_restore_chirp < K_MAX)
   {
      Range_Process_Xcp_Adc_Restore_Out_Post_Processing(
         (int16_t *)(uintptr_t) & (d2m_msg_ptr->payload.xcp_data.range_process_ra_output.adc_restore_chirp[0]));
   }
   else
   {
      /* Do Nothing - ADC mode not enabled */
   }
}

/**
 *  @b Description
 *  @n Invalidate the memory that the RA is writing. Will have no impact if the memory is not cached.
 *
 *
 * @retval void
 */

void Invalidate_ADC_XCP_Cache(void)
{
   xthal_dcache_block_invalidate(&XCP_Range_Process_Data.xcp_data, sizeof(XCP_Range_Process_Data.xcp_data));
}

#endif
