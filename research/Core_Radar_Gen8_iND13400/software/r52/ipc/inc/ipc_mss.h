#ifndef IPC_MSS_H
#define IPC_MSS_H
/*===========================================================================*/
/**
 * @file ipc_mss.h
 *
 * Provides Structure and APIs for Inter core communication
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
   /** R52 to DSP buffer ping pong index*/
   extern uint8_t R52_M2D_Buffer_Index;
   extern uint32_t R52_M2D_Msg_Header_Cnt;
   extern D2M_Msg_T *IPC_Sp_Post_Proc_Buf_Read_Addr;
   extern uint8_t IPC_Sp_Post_Proc_Buf_Read_Idx;

   /* DSP Configuration State */
   typedef enum DSP_Config_Type_Tag
   {
      DSP_CONFIG_NO_ERROR = 0,
      DSP_CONFIG_ERROR,
      DSP_CONFIG_WAITING_FOR_RESPONSE,
   } DSP_Config_Type_T;
   /*===========================================================================*
    * Exported Const Object Declarations
    *===========================================================================*/

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   void IPC_M2D_Buffer_Init(void);
   void IPC_M2D_One_Time_Buffer_Init(void);
   void Update_R52_IPC_Notify(void);
   D2M_Msg_T *Get_IPC_D2M_Sp_Post_Proc_Buffer(void);
   volatile M2D_Msg_T *Get_MSS_IPC_M2D_Msg_Buffer(void);
   volatile M2D_One_Time_Msg_T *Get_IPC_M2D_Onetime_Msg_Buffer(void);
   volatile M2D_Msg_T *Get_IPC_M2D_Msg_Buffer(uint8_t buf_cnt);
   uint8_t Check_D2M_Crc_Header(D2M_Msg_T *p_ipc_d2m_sp_post_msg);
   bool Get_DSP_Init_Status(void);
   void Set_DSP_Init_Status(bool val);
   D2M_Msg_T *Get_IPC_D2M_Dopp_RDD_Comp_Buf_Buffer(void);
   uint8_t Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx(void);
   bool R52_BBE_Trigger(void);
   bool Get_Is_Doppler_Comp_RDD_Stream_Ready(void);
   void Set_Is_Doppler_Comp_RDD_Stream_Ready(bool flag);
   bool Get_Received_Doppler_Done(void);
   void Set_Received_Doppler_Done(bool flag);
   uint32_t Get_M2D_Buffer_Full_Error_Counter(void);
   void Set_M2D_Buffer_Full_Error_Counter(uint32_t val);
   uint32_t Get_D2M_Ping_Buf_Addr(void);
   uint32_t Get_D2M_Pong_Buf_Addr(void);
   volatile uint8_t Get_DSP_Write_IPC_Index(void);
   uint8_t Get_R52_Current_PingPong_Index(void);
   uint32_t Get_IPC_M2D_Crc_Err_Cnt(void);
   uint32_t Get_IPC_D2M_Crc_Err_Cnt(void);
   volatile DSP_Config_Type_T Get_DSP_Cfg_Init(void);
   void Set_DSP_Cfg_Init(DSP_Config_Type_T val);
   IPC_Message_Counter_T Get_DSP_Range_Config_Counts(void);
   IPC_Message_Counter_T Get_DSP_Range_Process_Complete_Counts(void);
   IPC_Message_Counter_T Get_DSP_Doppler_Process_Complete_Counts(void);
   IPC_Message_Counter_T Get_DSP_Sp_Post_Complete_Counts(void);
   D2M_Msg_T *Get_IPC_Sp_Post_Buf_Read_Addr_Raw(void);
   uint8_t Get_IPC_Sp_Post_Buf_Read_Idx_Raw(void);
   uint16_t Get_DSP_No_Command_Cnt(void);
   void Reset_IPC_M2D_Buffer(volatile M2D_Msg_T *m2d_ptr);
   void Update_IPC_M2D_Header(volatile M2D_Msg_T *m2d_msg_ptr);
   uint32_t Get_R52_D2M_Msg_Header_Cnt(void);
   uint8_t Get_HW_Accel_Test_Fault(void);
   volatile M2D_Msg_T *Get_MSS_IPC_M2D_Msg_Buf_Addr(uint8_t ipc_buff_index);
#ifdef CDC_ENABLE
   extern volatile uint32_t Cdc_Frame_Interface_Addr;
#endif
#ifdef XCP_FAULT_INJECTION
   void Set_IPC_XCP_Fault_Injn_Var(uint8_t core_id);
   void Set_XCP_Fault_Inj(void);
#endif

   uint32_t Get_IPC_D2M_Max_Delta_Time_Us(void);
   uint32_t Get_IPC_D2M_Min_Delta_Time_Us(void);

   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* IPC_DATA_H */
