#ifndef APP_CHKSUM_H
#define APP_CHKSUM_H
/*===========================================================================*/
/**
 * @file app_chksum.h
 *
 * @todo Add a one line description of the header file here.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2023 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
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
#include "reuse.h"

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
// #include "dd_crc.h"

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

/* Test Macro to check the functionality of CRC32.
   Shall be removed on actually using the crc functions for IPC or other cases */
/* #define TEST_CRC32 */

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
#if 0
   typedef struct CRC_Cfg_Tag
   {
      /**
       * @brief   The field is base address of CRC module.
       */
      uint32_t crc_base_addr;

      /**
       * @brief   The field is valid only if the CRC Driver is being used else
       * this is ignored.
       */
      crcChannel_t crc_channel;
   } CRC_Cfg_T;
#endif
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   uint16_t CalcSum16(const uint8_t *ptr, uint32_t len);
   // int32_t Compute_CRC32_Ch2(uint32_t *data, uint32_t data_len, uint32_t *crc);
   void Calculate_Checksum(uint8_t *ptr, uint32_t len);

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  XXX         Firstname Lastname
 *  qjrdfk      Venkatesh G
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY - To be filled by the project team
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  yy-mm-dd      x.xx        XXX          12345
 *      First revision
 *  22-12-02      1.00        qjrdfk       DDR-1907
 *      Create application specific common crc function
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
#endif /* APP_CHKSUM_H */
