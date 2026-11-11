#ifndef SWC_PLT_APPL_INTWDG_HANDLER_H_
   #define SWC_PLT_APPL_INTWDG_HANDLER_H_
/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_IntWDG.h
 *
 * @todo This file contains declarations used in SWC_PLT_APPL_INTWDG
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * @todo This file contains declarations used in SWC_PLT_APPL_INTWDG
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
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
   #include "WdgM.h"
   #include "WdgM_Cfg.h"
   #include "radar_data.h"
   #include "reuse.h"
   #include "smc_cal.h"
   /*===========================================================================*
    * Other Header Files
    *===========================================================================*/
   /*===========================================================================*
    * Exported Preprocessor #define Constants
    *===========================================================================*/

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
   #define DISABLE_WDG_SMC 1
   #define ENABLE_WDG_SMC  0
/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
void Appl_Task_Monitoring(uint16 se_id_info);
   #if (STD_ON == ENABLE_SQT_TEST_STUBS)
void Perform_SWT_SQT_Test(void);
uint16 Test_WDG_Task_Monitoring(uint16 se_id_info);
   #endif
   #if (STD_ON == ENABLE_SIT_TEST_STUBS)
void Deactivate_SE_On_Req(void);
void Disable_Internal_Wdg_Sit(void);
   #endif
/*===========================================================================*
 * Exported Const Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/
#endif
/*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
