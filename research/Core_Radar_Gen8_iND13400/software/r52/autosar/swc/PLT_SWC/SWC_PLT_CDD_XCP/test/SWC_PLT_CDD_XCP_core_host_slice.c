#include <stddef.h>
#include <stdint.h>

typedef uint8_t uint8;

#define FUNC(rettype, memclass) rettype
#define SWC_PLT_CDD_XCP_CODE

#define XCP_CMD_OK      (0U)
#define CODED_TRUE      (1U)
#define CODED_FALSE     (0U)
#define XCP_CHANNEL_IDX (0U)

typedef struct
{
   uint8 b[8];
} ResponseFrame_T;

typedef struct
{
   ResponseFrame_T ResponseFrame;
   uint8 ResponseFrameLength;
} Xcp_ChannelInfo_T;

typedef void (*XCP_Fault_Trigger_Func_T)(uint8_t, uint8_t);

typedef struct
{
   XCP_Fault_Trigger_Func_T xcp_fault_trigger_rte_fun_ptr;
   uint8_t xcp_fault_id;
   uint8_t xcp_fault_start_range;
   uint8_t xcp_fault_end_range;
   uint8_t xcp_fault_control_mask;
   uint8_t xcp_fault_code;
} XCP_Fault_Inj_Handler_T;

#define XCP_MM3_MCU_STARTUP_FAULT            (0U)
#define XCP_MM3_REPETITIVE_RESET_FAULT       (1U)
#define XCP_MM3_SIGNAL_INTIGRITY_FAULT       (2U)
#define XCP_MM3_IPC_FAULT                    (3U)
#define XCP_MM3_PMIC_MCU_COMMUNICATION_FAULT (4U)
#define XCP_MM3_EXT_WATCHDOG_FAULT           (5U)

volatile uint8_t XCP_User_Cmnd_Received       = CODED_FALSE;
const uint8_t *xcp_cmd                        = 0;
static uint8 pending_cmd_status               = CODED_FALSE;
static uint8_t g_last_fault_handler_id        = 0U;
static uint8_t g_last_fault_injection_control = 0U;
static uint8_t g_last_fault_failure_type      = 0U;
static uint8_t g_last_fault_index             = 0U;

Xcp_ChannelInfo_T Xcp_ChannelInfo[1] = {0};

static void Test_External_Watchdog_Fault_Handler(uint8_t injection_control, uint8_t failure_type)
{
   g_last_fault_handler_id        = XCP_MM3_PMIC_MCU_COMMUNICATION_FAULT;
   g_last_fault_injection_control = injection_control;
   g_last_fault_failure_type      = failure_type;
}

static const XCP_Fault_Inj_Handler_T MM3_FaultHandlers[] = {
   {NULL, XCP_MM3_MCU_STARTUP_FAULT, 0x00, 0x00, 0x00, 0x01},
   {NULL, XCP_MM3_REPETITIVE_RESET_FAULT, 0x01, 0x01, 0x00, 0x06},
   {NULL, XCP_MM3_SIGNAL_INTIGRITY_FAULT, 0x02, 0x02, 0x00, 0x01},
   {NULL, XCP_MM3_IPC_FAULT, 0x03, 0x03, 0x00, 0x02},
   {Test_External_Watchdog_Fault_Handler, XCP_MM3_PMIC_MCU_COMMUNICATION_FAULT, 0x04, 0x04, 0x00, 0x03},
   {NULL, XCP_MM3_EXT_WATCHDOG_FAULT, 0x05, 0x05, 0x00, 0x01},
};

void Test_Trigger_MM3_Fault_Injection(uint8_t fault_index, uint8_t injection_control)
{
   g_last_fault_index = fault_index;
   if ((fault_index < (uint8_t)(sizeof(MM3_FaultHandlers) / sizeof(MM3_FaultHandlers[0]))) &&
       (NULL != MM3_FaultHandlers[fault_index].xcp_fault_trigger_rte_fun_ptr))
   {
      g_last_fault_handler_id = MM3_FaultHandlers[fault_index].xcp_fault_id;
      MM3_FaultHandlers[fault_index].xcp_fault_trigger_rte_fun_ptr(injection_control, fault_index);
   }
}

uint8_t Test_Get_Last_Fault_Handler_Id(void)
{
   return g_last_fault_handler_id;
}

uint8_t Test_Get_Last_Fault_Injection_Control(void)
{
   return g_last_fault_injection_control;
}

uint8_t Test_Get_Last_Fault_Failure_Type(void)
{
   return g_last_fault_failure_type;
}

uint8_t Test_Get_Last_Fault_Index(void)
{
   return g_last_fault_index;
}

void XCP_BB_Input_Params_Init(void)
{
}
uint8 SWC_Xcp_UserCommand(uint8 channel, const uint8 *cmd)
{
   (void)channel;
   (void)cmd;
   return XCP_CMD_OK;
}
void Xcp_SendCrm(uint8 channel)
{
   (void)channel;
}
uint8 Get_XCP_Pending_Cmnd_Status(void)
{
   return pending_cmd_status;
}
uint8 XCP_Periodic_Task(uint8_t *res, uint8_t *frame_length)
{
   (void)res;
   (void)frame_length;
   return XCP_CMD_OK;
}
void SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd(void)
{
}

void Test_Set_XCP_UserCommand_Received(uint8 value)
{
   XCP_User_Cmnd_Received = value;
}

void Test_Set_XCP_Pending_Status(uint8 value)
{
   pending_cmd_status = value;
}

#line 690 "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Source/SWC_PLT_CDD_XCP.c"
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_10ms(void)
{
   uint8 retValue = XCP_CMD_OK;

   XCP_BB_Input_Params_Init();

   if (CODED_TRUE == XCP_User_Cmnd_Received)
   {
      retValue = SWC_Xcp_UserCommand(XCP_CHANNEL_IDX, xcp_cmd);
      if (XCP_CMD_OK == retValue)
      {
         Xcp_SendCrm(XCP_CHANNEL_IDX);
      }
      XCP_User_Cmnd_Received = CODED_FALSE;
   }
}

#line 850 "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Source/SWC_PLT_CDD_XCP.c"
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_50ms(void)
{
   uint8 retValue        = XCP_CMD_OK;
   uint8_t *res          = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b;
   uint8_t *frame_length = &(Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength);

   if (CODED_TRUE == Get_XCP_Pending_Cmnd_Status())
   {
      retValue = XCP_Periodic_Task(res, frame_length);

      if (XCP_CMD_OK == retValue)
      {
         Xcp_SendCrm(XCP_CHANNEL_IDX);
      }
   }

   SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd();
}

#line 970 "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_XCP/Source/SWC_PLT_CDD_XCP.c"
FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_Init(void)
{
}
