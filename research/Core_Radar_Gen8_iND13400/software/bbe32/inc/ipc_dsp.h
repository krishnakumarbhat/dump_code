#ifndef IPC_DSP_H
#define IPC_DSP_H
/**
 * @file ipc_dsp.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * IPC function definitions for interaction with IPC.
 * @note This file should only contain constant definitions and NO INCLUDE files.
 *
 * @section ABBR ABBREVIATIONS:
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *   - Requirements Document(s):
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 * @section DFS DEVIATIONS FROM STANDARDS:
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/* ========================================================================== */
/*                         Xtensa Include Files                               */
/* ========================================================================== */

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "ipc_data.h"
#ifdef __XTENSA__
   #include <xtensa/tie/xt_sync.h>
#else
   #include "core-macros.h"
#endif
#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define SP2DSP_LVL1_INT 8U
/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
/** @note: It has been found that MMIC/RFE executable delay the chirp start every frame by constant 6ms.
 * Hence Range processing start is delayed by the same as a compensation.
 * This delay should be accurate since SPT during range processing should not miss out on the chirp ACQ.
 */
#define RANGE_PROCESS_DELAY_ENABLE
#define DEFAULT_TIMEOUT_US (200000U) /* Default timeout to 200ms */

   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/

   /** For BBE, need to define the trigger received as a uint32_t, so the L32AI instruction
    *  can be used to allow running with higher levels of optimization.
    */
   typedef enum
   {
      NO_TRIGGER = 0,
      TRIGGER_RECEIVED
   } Trigger_Received_T;

   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/
   /** Flag to indicate R52 to BBE trigger received to configure range process */
   extern volatile Trigger_Received_T IPC_R52_To_BBE_Trigger_Received;

   /** Offline mode flag*/
   extern volatile uint32_t Offline_Mode_Flag_DSP;
   /** IPC M2D error counter*/
   extern uint16_t IPC_M2D_Buffer_Err_Cnt;

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void Appl_DSP_Process_Onetime_Init(void);
   void __attribute__((section(".sram0.text"))) Send_Range_Proc_Complete(Error_Field_T error);
   void __attribute__((section(".sram0.text"))) Send_Doppler_RDD_Proc_Complete(Error_Field_T error);
   void Update_RDD_Stream_Header(volatile D2M_Msg_T *d2m_msg_ptr, Error_Field_T error);
   void Send_SP_Post_Proc_Complete_to_R52(Error_Field_T error);
   // void Send_SP_Post_Proc_Complete_to_M7(void);
   void Update_DSP_IPC_Notify(void);
   // void Reset_IPC_RDD_Buffer(void);
   void Reset_IPC_AF_Buffer(bool hil_detection_stream_injection_mode, bool hil_downselection_stream_injection_mode);
   volatile D2M_Msg_T *Get_RP_IPC_D2M_Msg_Buffer(void);
   D2M_Msg_T *Get_DP_RDD_IPC_D2M_Msg_Buffer(void);
   volatile D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(void);
   D2M_Msg_T *Get_IPC_D2M_Msg_Buffer(uint8_t buf_cnt);
   volatile M2D_Msg_T *Get_IPC_M2D_Buffer(void);
   volatile M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer(void);
   bool Wait_For_Trigger(volatile uint32_t *trigger_ptr);
   void Set_MMIC_Data_Discard_Info();
   uint8_t Get_DSP_RA_Error_Status(void);
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* IPC_DSP_H */
