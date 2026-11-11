#ifndef RETENTION_RAM_DATA_H
#define RETENTION_RAM_DATA_H
/*===========================================================================*/
/**
 * @file retention_ram_data.h
 *
 * @todo Add a one line description of the header file here.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file provides information about the data stored in retention ram
 *
 * @section ABBR ABBREVIATIONS:
 *
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file: "None".
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
/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef struct Exception_Shared_Data_Tag
{
   uint32_t exception_causing_address;
   uint32_t exception_status_register;
   uint32_t memory_exception_address;
   uint32_t stack_pointer;
   uint16_t reset_number;
   uint8_t exception_type;
   bool memory_exception_occurred;
} Exception_Shared_Data_T;

typedef struct FHTI_Test_Shared_Data_Tag
{
   uint8_t failure_name;
   uint8_t reset_count;
   uint8_t repetative_reset_fault_type;
   uint8_t plt_usTime_freeze_pending; /* PlatformTime.usTime freeze fault: 1 = re-apply after reset, 0 = inactive */
} FHTI_Test_Shared_Data_T;

typedef struct Retention_Ram_Data_Tag
{
   Exception_Shared_Data_T Exception_data;
   FHTI_Test_Shared_Data_T fhti_test_data;
} Retention_Ram_Data_T;

extern Retention_Ram_Data_T Retention_Ram_Data __attribute__((section(".retention_ram_data")));
/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/
/*===========================================================================*
 * Exported Function Definitions and #define Function-Like Macros
 *===========================================================================*/
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 *
 \*===========================================================================*/
#endif /* RETENTION_RAM_DATA_H */
