#ifndef DSP_SETUP_H
#define DSP_SETUP_H
/*===========================================================================*/
/**
 * @file dsp_setup.h
 *
 * APIs to setup signal processing application
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * APIs to setup signal processing application
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

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "ipc_data.h"

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

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/
   extern uint8_t IPC_Dopp_RDD_Comp_Buf_Read_idx;
   extern uint32_t Ping_Buf_Addr; /* Var to store the address of the ping buffer, used for XCP to implement ping-pong */
   extern uint32_t Pong_Buf_Addr; /* Var to store the address of the pong buffer, used for XCP to implement ping-pong */
   extern volatile uint32_t Offline_Mode_Flag;

   /* Debug counters for DSP trigger tracking */
   extern uint32_t M2D_Trigger_While_DSP_Busy_Counter; /* Counter for triggers sent while DSP not ready */
   extern uint32_t M2D_Successful_Trigger_Counter;     /* Counter for successful triggers */

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   bool Run_DSP_Interaction_State_Machine(void);
   void DSP_Processing_Onetime_Init(void);
   bool DSP_Processing_Per_Look_Init(void);
   bool DSP_Done_Processing(void);
   uint8_t Get_Fetch_M2D_Buffer_Idx_HIL_Injection(void);
   bool Send_DSP_Start_Notification(void);
   void Record_Frame_Start_Time(uint32_t lookindex, uint8_t ping_pong_index);

   void Update_Frame_Time_For_Look(uint32_t lookindex, uint8_t ping_pong_index);
   uint32_t Get_Frame_Time(uint32_t lookindex);

   void IPC_M2D_Buffer_Init(void);
   void IPC_M2D_One_Time_Buffer_Init(void);
   extern bool Perform_BBE32_Reset(void);
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* DSP_SETUP_H */
