#ifndef SWC_PRJ_APPL_POWER_MANAGER_H /* { */
#define SWC_PRJ_APPL_POWER_MANAGER_H
/*===========================================================================*\
 * FILE: SWC_PRJ_Appl_Power_Manager.h
 *===========================================================================
 * Copyright 2022 Aptiv, Inc., All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  SWC_PRJ_Appl_Power_Manager.h
 * %version:  1 %
 * %derived_by:   %
 * %date_modified:  %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *  This file contains functions & object definitions for SWC_PRJ_Appl_Power_Manager.
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *       TODO: Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Dio.h"
#include "board_revision.h"
#include "mcu_reset_wrapper.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define Low_IGN_THRESHOLD_VOLTAGE       (5.5f)
#define RECOVERED_IGN_THRESHOLD_VOLTAGE (6.5f)
#define LOW_IGN_DEBOUNCE_CNT            (20U) /* 20 x 5ms = 100ms debounce wait time */

#endif /*SWC_PRJ_APPL_POWER_MANAGER_H*/
