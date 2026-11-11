#ifndef VERSIONS_H
#define VERSIONS_H
/*===========================================================================*/
/**
 * @file versions.h
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
 * This file provides versioning information
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
typedef struct Application_Version_Tag
{
   uint8_t output_type;     /* sat/standalone */
   uint8_t output_sub_type; /* DET/OBJ/CDC    */
   uint8_t veh_com_type;    /* CAN/ETH  etc   */
   uint8_t board_type;      /* B3/A1/A2  etc  */
   uint8_t rsvd;
   uint8_t appl_type;  /* srr/flr/img etc*/
   uint8_t generation; /* generation     */
   uint8_t variant;    /* variant        */
   uint8_t major;      /* major revision */
   uint8_t minor;      /* minor revision */
   uint8_t patch;      /* patch revision */
   uint8_t pre_rel;    /* pre-release    */
} Application_Version_T;
typedef struct Bootloader_Version_Tag
{
   uint8_t major;
   uint8_t minor;
   uint8_t patch;
} Bootloader_Version_T;
const Application_Version_T *Get_Application_Version(void);
const Bootloader_Version_T *Get_Bootloader_Version(void);
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
#endif /* VERSIONS_H */
