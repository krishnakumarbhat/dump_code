#ifndef IPC_COMMANDS_H
#define IPC_COMMANDS_H
/*===========================================================================*/
/**
 * @file ipc_commands.h
 *
 * Provides Structure for IPC metadeta
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2024 Aptiv. All rights reserved.
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
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "reuse.h"

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/** To enable IPC notify acq check.
 * BBE will not trigger a new MSCM ISR until previous one is ACQ
 *
 * Set timeout for IPC messages.
 */
#define IPC_NOTIFY_ACQ_ENABLE
#define IPC_MESSAGE_TIMEOUT_IN_US (1000U)

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum Core_To_Core_ID_Tag
   {
      R52_TO_BBE_CORE  = 0,
      BBE_TO_R52_CORE  = 1,
      CORE_TO_CORE_MAX = 2,
   } Core_To_Core_ID_T;

   enum
   {
      /* Common Commands */
      NO_COMMAND = 0,
      CORE_INITIALIZED,

      /* R52 to DSP commands */
      R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION = 0x10000000,
      R52_RA_ERROR_FAULT,

      /* DSP to R52 commands */
      DSP_RANGE_CONFIGURATION_COMPLETE = 0x20000000,
      DSP_RANGE_PROCESSING_COMPLETE,
      DSP_DOPPLER_PROCESSING_COMPLETE,
      DSP_SP_POST_PROCESSING_COMPLETE,
   };

   typedef enum Error_Field_Tag
   {
      ERRORFIELD_NO_ERROR = 0,
      ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR,
      ERRORFIELD_RANGE_PROCESS_ERROR,
      ERRORFIELD_RANGE_PROCESS_TIMEOUT,

      ERRORFIELD_DOPPLER_PROCESS_NOT_RUN,
      ERRORFIELD_DOPPLER_PROCESS_TIMEOUT,
      ERRORFIELD_DOPPLER_PROCESS_ERROR,
      ERRORFIELD_DOPPLER_PROCESS_MEMPOOL_FAILED,

      ERRORFIELD_POST_SIG_PROC_ERROR,

      /*IPC R52 to BBE32 CRC error*/
      R52_TO_BBE32_CRC_ERROR = (0x70A0A0A0U),
   } Error_Field_T;

   typedef struct Ipc_Notify_Structure_Tag
   {
      uint32_t command;
      uint32_t lookIndex;
      uint32_t chirp_number;
      uint32_t errorField;
      uint32_t pingPongIndex;
      uintptr_t curIpcAddr;
      uint32_t buffer_addr;
      uint32_t buffer_index;
      uint32_t pfm_index;
   } Ipc_Notify_Structure_T;

   typedef enum ITF_Injection_Mode_Tag
   {
      ITF_DISABLED_NORMAL_MODE     = 0,
      ITF_ADC_INJECTION_MODE       = 0x11111111U,
      ITF_DATA_CUBE_INJECTION_MODE = 0x22222222U,
      ITF_TEST_COLLECTION_MODE     = 0x33333333U,
   } ITF_Injection_Mode_T;

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* IPC_COMMANDS_H */
