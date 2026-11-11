/*===========================================================================*\
 * FILE: dd_pmic.c
 *===========================================================================
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2026 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the PMIC driver functions to perform various operations related to the PMIC.
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/GlobalRegional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards </a>
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "dd_pmic.h"
#include "SWC_PLT_Appl_PlatformTime_cfg.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "dd_gpt.h"
#include <string.h>
#if (TRUE == XCP_FAULT_INJECTION)
   #include "retention_ram_data.h"
   #define MCU_STARTUP_FAULT (13U)
#endif

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
#define PMIC_SYNC_CTRL_REG_ADDR (0x01U)
#define PMIC_SYNC_EN            (0x01U)
#define PMIC_SYNC_CRC           (0xEBU)
#define CLOCK_SYNC_COMPLETE     (0x03U)
#define WD_STATUS_REG_ADDRESS   ((uint8_t)(0x02U))

#define WD_DIS_STATUS_MASK       ((uint8_t)(0x80U))
#define WD_DIS_COUNTER_THRESHOLD ((uint8_t)(0x2U))
#define PMIC_WATCHDOG_TEST       FEATURE_DISABLED

#define PMIC_SUCCESS (1U)
#define PMIC_FAIL    (0U)

#define CRC_MASK (0x80U)
#define POLY     (0x07U)

#define CLEAR_BIT   ((uint8_t)0U)
#define SET_BIT_VAL ((uint8_t)1U)
#define WRITE_REG   ((uint8_t)0xFFU)

#define I2C_MAX_BUFFER_SIZE                 (64U)
#define I2C_OP_PENDING_FALSE_CMD_STOP       ((bool)0U)
#define I2C_OP_PENDING_TRUE_CMD_REPEATSTART ((bool)1U)
#define I2C_SLAVE_REGISTER_COUNT            (1U)

/* I2C Read / Write Bit */
#define I2C_RW_BIT_WRITE        ((uint8_t)(0))
#define I2C_RW_BIT_READ         ((uint8_t)(1))
#define I2C_CRC_OFFSET_FOR_DATA (3)

/* I2C Polling Configuration */
#define I2C_POLLING_DEBUG_ENABLE (1U) /* Enable debug mode: GPT timing + statistics (set 0 for production) */
#define I2C_POLLING_HISTORY_SIZE (10U)

/* TODO Ideally 250us timeout and 100us delay should suffice for 3 bytes of I2C at 400KHz
  increased due to IR-1654 issues */
#define I2C_TOTAL_TIMEOUT_US    (500U) /* 500us total timeout for PMIC I2C operations. */
#define I2C_READ_SETUP_DELAY_US (200U) /* 200us delay before read to allow PMIC data preparation */
#define I2C_RUNTIME_DELAY_US    ((is_rdi_connected) ? (I2C_TOTAL_TIMEOUT_US) : (I2C_READ_SETUP_DELAY_US))

/* I2C Hardware Register Addresses for NACK Detection */
#define IC_TX_ABRT_SOURCE_ADDR (0x91920080U) /* Transmit Abort Source Register */
#define IC_CLR_TX_ABRT_ADDR    (0x91920054U) /* Clear TX Abort Register */
#define IC_ENABLE_ADDR         (0x9192006CU) /* I2C Enable Register */
#define ABRT_7B_ADDR_NOACK_BIT (1U << 0U)    /* Bit 0: 7-bit address NACK'd */
#define ABRT_TXDATA_NOACK_BIT  (1U << 3U)    /* Bit 3: Data byte NACK'd */
#define I2C_RETRY_COUNT        (2U)          /* Consecutive failures to trigger flag */
#define I2C_RETRY_DELAY_MS     (2U)          /* Delay between retry attempts */

/* I2C Enable Register Control Values */
#define I2C_DISABLE (0U) /* Value to disable I2C peripheral */
#define I2C_ENABLE  (1U) /* Value to enable I2C peripheral */

#define PMIC_GEN_PROT_REG_ADDR   0x20
#define PMIC_GEN_CONFIG_REG_ADDR 0x0C
#define PMIC_GEN_CONFIG_ENSS_EN  0x01

#define MCU_PMIC_CRC_FAIL      0
#define PMIC_MCU_CRC_FAIL      1
#define CORRUPT_STS_REG        2
#define REMOVE_FAULT_INJECTION 3
/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
#if (I2C_POLLING_DEBUG_ENABLE == 1U)
typedef struct
{
   uint32_t min_time_us;                       /* Minimum polling time observed (microseconds) */
   uint32_t max_time_us;                       /* Maximum polling time observed (microseconds) */
   uint32_t avg_time_us;                       /* Running average polling time (microseconds) */
   uint32_t sample_count;                      /* Total I2C operations (success + failures) */
   uint32_t history[I2C_POLLING_HISTORY_SIZE]; /* Circular buffer for last N values (μs) */
   uint32_t failure_count;                     /* Total I2C operation failures */
   uint32_t i2c_write_executed_count;          /* Count of I2C write operations executed */
   uint32_t i2c_read_executed_count;           /* Count of I2C read operations executed */
   uint32_t i2c_write_fail_count;              /* Count of I2C write failures */
   uint32_t i2c_read_fail_count;               /* Count of I2C read failures */
   uint32_t i2c_write_skip_count;           /* Count of I2C write skip as I2C is not I2C_STATUS_IDLE / not I2C_STATUS_COMPLETED */
   uint32_t i2c_read_skip_count;            /* Count of I2C read skip as I2C is not I2C_STATUS_IDLE / not I2C_STATUS_COMPLETED */
   uint32_t i2c_fail_status_pend_count;     /* Count of I2C read/write failed due to I2C_STATUS_PENDING */
   uint32_t i2c_fail_status_busy_count;     /* Count of I2C read/write failed due to I2C_STATUS_BUSY */
   uint32_t i2c_fail_status_busy_addr_NACK; /* Count of I2C read/write failed due to I2C_STATUS_ADDRESS_NACK */
   uint32_t i2c_cb_total_count;             /* Total JobEndNotification callbacks fired */
   uint32_t i2c_cb_success_count;           /* I2C_EVENT_TRANSFER_COMPLETED callbacks */
   uint32_t i2c_cb_nack_count;              /* I2C_EVENT_ADDRESS_NACK callbacks */
   uint32_t i2c_cb_transfer_fail_count;     /* I2C_EVENT_TRANSFER_FAILED callbacks */
   uint32_t i2c_cb_arb_lost_count;          /* I2C_EVENT_ARBITRATION_LOST callbacks */
   uint32_t i2c_cb_consecutive_fail_count;  /* Current consecutive failure streak */
   uint8_t history_index;                   /* Current index in circular buffer (moved to end for alignment) */
} I2c_Polling_Stats_T;

   #define CRC_MISMATCH_HISTORY_SIZE (10U)
typedef struct
{
   uint8_t pmic_data_byte[CRC_MISMATCH_HISTORY_SIZE]; /* Data bytes read from PMIC */
   uint8_t calculated_crc[CRC_MISMATCH_HISTORY_SIZE]; /* Expected CRC calculated by MCU */
   uint8_t received_crc[CRC_MISMATCH_HISTORY_SIZE];   /* Actual CRC received from PMIC */
   uint8_t history_index;                             /* Current index in circular buffer */
   uint32_t mismatch_count;                           /* Total number of CRC mismatches */
} Crc_Mismatch_Debug_T;

   #if (STD_ON == XCP_FAULT_INJECTION)
typedef struct
{
   uint8_t slave_addr;
   uint8_t reg_addr;
   uint8_t datatx[2];
   uint8_t Data_Rx[2];
} Pmic_Fault_Injection_Data_T;
   #endif

volatile Crc_Mismatch_Debug_T Crc_Mismatch_Debug = {{0}, {0}, {0}, 0U, 0U};
#endif
static uint8_t enss_disable_result = 3; /*default - invalid*/
static uint8_t enss_enable_result  = 3; /*default - invalid*/
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static uint8_t Calc_Crc_8(const uint8_t *data, uint8_t len);
static void Pmic_Enable_Watchdog(void);
static void Pmic_Write_Register_Bits(uint8_t reg_address, uint8_t value, uint8_t task);
static uint8_t Pmic_Get_Write_Value(uint8_t reg_address, uint8_t value, uint8_t task);
static void Verify_Crc_Result(uint32_t slave_address, uint8_t reg_address, const uint8_t *data, uint8_t len, uint8_t received_crc);
#if (I2C_TRANSFER_MODE == I2C_POLLING_MODE)
static I2c_StatusType I2C_Polling(void);
#endif
static void Delay_in_us_GPT(uint32_t delay_us);
#if (ENABLE_WDT_TEST == FEATURE_ENABLED)
volatile uint8_t Ext_Watchdog_En_Dis_TestVar = 0U;
volatile bool Watchdog_Reset_Test            = (bool)PMIC_FAIL;
static void Pmic_Watchdog_Test(void);
static void Pmic_Disable_Watchdog(void);
#endif
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if (PMIC_WATCHDOG_ENABLE == FEATURE_ENABLED)
I2c_StatusType Watchdog_Read_Status = I2C_STATUS_IDLE;
static uint8_t WD_Service_Status    = WD_SERVICE_DISABLE;
#endif /* PMIC_WATCHDOG_ENABLE */

#if (TRUE == ENABLE_SQT_TEST_STUBS)
static volatile uint8_t pmic_mcu_comm_fault_test_stub = 0;
#endif

#if (I2C_POLLING_DEBUG_ENABLE == 1U)
volatile I2c_Polling_Stats_T I2c_Polling_Stats = {
   .min_time_us                    = 0xFFFFFFFFU,
   .max_time_us                    = 0U,
   .avg_time_us                    = 0U,
   .sample_count                   = 0U,
   .history                        = {0},
   .failure_count                  = 0U,
   .i2c_write_executed_count       = 0U,
   .i2c_read_executed_count        = 0U,
   .i2c_write_fail_count           = 0U,
   .i2c_read_fail_count            = 0U,
   .i2c_write_skip_count           = 0U,
   .i2c_read_skip_count            = 0U,
   .i2c_fail_status_pend_count     = 0U,
   .i2c_fail_status_busy_count     = 0U,
   .i2c_fail_status_busy_addr_NACK = 0U,
   .i2c_cb_total_count             = 0U,
   .i2c_cb_success_count           = 0U,
   .i2c_cb_nack_count              = 0U,
   .i2c_cb_transfer_fail_count     = 0U,
   .i2c_cb_arb_lost_count          = 0U,
   .i2c_cb_consecutive_fail_count  = 0U,
   .history_index                  = 0U,
};
#endif
/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/
volatile uint8_t PMIC_MCU_Comm_Fault = CODED_FALSE; /* PMIC communication fault flag */
static uint8_t Watchdog_Dis_Count    = (uint8_t)0;
static bool pmic_sync_result         = false;
static bool is_rdi_connected         = false;
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*****************************************************************************
 *. Name: Pmic_Clk_Sync_Enable
 *.    This function enables the pmic to switch to external generated clock
 *.
 *. Parameters: void
 *.
 *. Return Value:bool
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/

bool Pmic_Clk_Sync_Enable(void)
{
   uint8_t write_buffer[2] = {PMIC_SYNC_EN, PMIC_SYNC_CRC};
   uint8_t read_buffer[2]  = {0U};

   (void)I2c_Write_Data(PMIC_ADDRESS, PMIC_SYNC_CTRL_REG_ADDR, write_buffer, NUM_ELEMS(write_buffer),
                        I2C_OP_PENDING_FALSE_CMD_STOP);

   Delay_in_us_GPT(I2C_RUNTIME_DELAY_US);

   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_SYNC_CTRL_REG_ADDR, read_buffer, NUM_ELEMS(read_buffer));

   if (CLOCK_SYNC_COMPLETE == read_buffer[0])
   {
      pmic_sync_result = true;
   }
   return pmic_sync_result;
}
#if (PMIC_WATCHDOG_ENABLE == FEATURE_ENABLED)
/*****************************************************************************
 *. Name: Pmic_Watchdog_Init
 *. This function is used to set watchdog service status.
 *.
 *. Parameters: void
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Pmic_Watchdog_Init(void)
{
   is_rdi_connected        = Get_RDI_Log_Board_Connected();
   uint8_t crc_input[3]    = {PMIC_ADDRESS_WRITE, WD_A_REGISTER_ADDRESS, 0U};
   uint8_t write_buffer[2] = {0x00U, 0x00U};

   write_buffer[0] = WD_MIN_PERIOD_MS / WD_1_TICK_MS; /* WD Minimum period Setting */
   crc_input[2]    = write_buffer[0];
   crc_input[1]    = WD_MIN_PERIOD_REGISTER_ADDRESS;
   write_buffer[1] = Calc_Crc_8(&crc_input[0], NUM_ELEMS(crc_input));
   I2c_Write_Data(PMIC_ADDRESS, WD_MIN_PERIOD_REGISTER_ADDRESS, write_buffer, NUM_ELEMS(write_buffer),
                  I2C_OP_PENDING_FALSE_CMD_STOP);

   write_buffer[0] = WD_MAX_PERIOD_MS / WD_1_TICK_MS; /* WD Maximum period Setting */
   crc_input[2]    = write_buffer[0];
   crc_input[1]    = WD_MAX_PERIOD_REGISTER_ADDRESS;
   write_buffer[1] = Calc_Crc_8(&crc_input[0], NUM_ELEMS(crc_input));
   I2c_Write_Data(PMIC_ADDRESS, WD_MAX_PERIOD_REGISTER_ADDRESS, write_buffer, NUM_ELEMS(write_buffer),
                  I2C_OP_PENDING_FALSE_CMD_STOP);
   Pmic_Enable_Watchdog();
   WD_Service_Status = WD_SERVICE_ENABLE;
}
#endif /* PMIC_WATCHDOG_ENABLE */

#if (ENABLE_WDT_TEST == FEATURE_ENABLED)

/*===========================================================================*\
 * FUNCTION: Pmic_Watchdog_Test
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *Test function for verifying watchdog functionalities
\*===========================================================================*/

static void Pmic_Watchdog_Test(void)
{
   switch (Ext_Watchdog_En_Dis_TestVar)
   {
      case WDT_DISABLE_TEST:
         Ext_Watchdog_En_Dis_TestVar = 0U;
         Pmic_Disable_Watchdog();
         break;

      case WDT_ENABLE_TEST:
         Ext_Watchdog_En_Dis_TestVar = 0U;
         Pmic_Enable_Watchdog();
         break;

      default:
         /* Do Nothing */
         break;
   }
   if ((bool)PMIC_SUCCESS == Watchdog_Reset_Test)
   {
      Watchdog_Reset_Test = (bool)PMIC_FAIL;
      WD_Service_Status   = WD_SERVICE_DISABLE;
   }
}
/*****************************************************************************
 *. Name: Pmic_Disable_Watchdog
 *.    This function disables the watchdog timer.
 *.
 *. Parameters: void
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/

static void Pmic_Disable_Watchdog(void)
{
   Pmic_Write_Register_Bits(PROT_REG_ADDR, PROT_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(PGMAP_REG_ADDR, PGMAP_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(FCMAP_REG_ADDR, FCMAP_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(PDMAP_REG_ADDR, PDMAP_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(FAULTB_REG_ADDR, FAULTB_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(PROT_REG_ADDR, PROT_REG_MASK, SET_BIT_VAL);
   WD_Service_Status = WD_SERVICE_DISABLE;
}
#endif
/*****************************************************************************
 *. Name: Pmic_Write_Register_Bits
 *.    This function writes/sets/clears bits in pmic register.
 *.
 *. Parameters: reg_address - register address,
 *.             value - value to be written,
 *.             task - task to be performed (SET_BIT_VAL, CLEAR_BIT, WRITE_REG)
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static void Pmic_Write_Register_Bits(uint8_t reg_address, uint8_t value, uint8_t task)
{
   uint8_t crc_input[3]    = {PMIC_ADDRESS_WRITE, reg_address, 0U};
   uint8_t write_buffer[2] = {0x00U, 0x00U};

   write_buffer[0] = Pmic_Get_Write_Value(reg_address, value, task);
   crc_input[2]    = write_buffer[0];
   write_buffer[1] = Calc_Crc_8(&crc_input[0], NUM_ELEMS(crc_input));
   I2c_Write_Data(PMIC_ADDRESS, reg_address, write_buffer, NUM_ELEMS(write_buffer), I2C_OP_PENDING_FALSE_CMD_STOP);
}

/*****************************************************************************
 *. Name: Pmic_Get_Write_Value
 *.    This function return the value to be written to pmic register..
 *.
 *. Parameters: reg_address - register address,
 *.             value - value to be written,
 *.             task - task to be performed (SET_BIT_VAL, CLEAR_BIT, WRITE_REG)
 *.
 *. Return Value:uint8_t
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static uint8_t Pmic_Get_Write_Value(uint8_t reg_address, uint8_t value, uint8_t task)
{
   uint8_t wdt_read_buffer[2] = {0xFFU, 0xFFU};

   (void)I2c_Read_Data(PMIC_ADDRESS, reg_address, wdt_read_buffer, NUM_ELEMS(wdt_read_buffer));

   switch (task)
   {
      case SET_BIT_VAL:
         SET_BITS(wdt_read_buffer[0], value);
         break;

      case CLEAR_BIT:
         CLR_BITS(wdt_read_buffer[0], value);
         break;

      case WRITE_REG:
         wdt_read_buffer[0] = value;
         break;

      default:
         /* Do nothing */
         break;
   }

   return wdt_read_buffer[0];
}

/*****************************************************************************
 *. Name: Pmic_Enable_Watchdog
 *.    This function enables the watchdog.
 *.
 *. Parameters: void
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static void Pmic_Enable_Watchdog(void)
{
   Pmic_Write_Register_Bits(PROT_REG_ADDR, PROT_REG_MASK, CLEAR_BIT);
   Pmic_Write_Register_Bits(STATUS1_REG_ADDR, STATUS1_REG_MASK, WRITE_REG);
   Pmic_Write_Register_Bits(STATUS2_REG_ADDR, STATUS2_REG_MASK, WRITE_REG);
   Pmic_Write_Register_Bits(PGMAP_REG_ADDR, PGMAP_REG_MASK, SET_BIT_VAL);
   Pmic_Write_Register_Bits(FCMAP_REG_ADDR, FCMAP_REG_MASK, SET_BIT_VAL);
   Pmic_Write_Register_Bits(PDMAP_REG_ADDR, PDMAP_REG_MASK, SET_BIT_VAL);
   Pmic_Write_Register_Bits(FAULTB_REG_ADDR, FAULTB_REG_MASK, SET_BIT_VAL);
   Pmic_Write_Register_Bits(PROT_REG_ADDR, PROT_REG_MASK, SET_BIT_VAL);
   WD_Service_Status = WD_SERVICE_ENABLE;
}

/*****************************************************************************
 *. Name: Pmic_Watchdog_Service
 *.    This function is used to service watchdog..
 *.
 *. Parameters: void
 *.
 *. Return Value:void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Pmic_Watchdog_Service(void)
{
#if (PMIC_WATCHDOG_ENABLE == FEATURE_ENABLED)
   if (WD_Service_Status != WD_SERVICE_DISABLE)
   {
      uint8_t crc_input[3]       = {PMIC_ADDRESS_WRITE, WD_A_REGISTER_ADDRESS, 0U};
      uint8_t write_buffer[2]    = {0x00U, 0x00U};
      uint8_t wdt_read_buffer[2] = {0U};
   #ifndef UNIT_TEST
      Watchdog_Read_Status = I2c_Read_Data(PMIC_ADDRESS, WD_Q_REGISTER_ADDRESS, wdt_read_buffer, NUM_ELEMS(wdt_read_buffer));
      if (I2C_STATUS_COMPLETED == Watchdog_Read_Status)
   #else
      (void)I2c_Read_Data(PMIC_ADDRESS, WD_Q_REGISTER_ADDRESS, wdt_read_buffer, NUM_ELEMS(wdt_read_buffer));
   #endif
      {
         /*Calculate answer byte from question read from PMIC. Same CRC polynomial is used to calculate answer bytes and for
          * communication protection*/
         write_buffer[0] = Calc_Crc_8(&wdt_read_buffer[0], ONE_BYTE); /*Do not change this line*/
         crc_input[2]    = write_buffer[0];
         /*Caculate CRC for communication protection*/
         write_buffer[1] = Calc_Crc_8(&crc_input[0], NUM_ELEMS(crc_input));
         I2c_Write_Data(PMIC_ADDRESS, WD_A_REGISTER_ADDRESS, write_buffer, NUM_ELEMS(write_buffer), I2C_OP_PENDING_FALSE_CMD_STOP);
      }
   }
   #if (ENABLE_WDT_TEST == FEATURE_ENABLED)
   Pmic_Watchdog_Test();
   #endif

#endif /* PMIC_WATCHDOG_ENABLE */
}

/*****************************************************************************
 *. Name: Calc_Crc_8
 *.    This function returns checksum for crc8 algorithm with INIT as 0x00 & POLY as 0x07
 *.
 *. Parameters: *data -> data to calculate CRC
 *.             len -> length of data
 *. Return Value:uint8_t - CRC-8 checksum value (0-255)
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static uint8_t Calc_Crc_8(const uint8_t *data, uint8_t len)
{
   uint8_t crc = 0x00U;
   uint8_t i;
   uint8_t j;

   for (i = 0U; i < len; i++)
   {
      crc ^= data[i];
      for (j = 0U; j < 8U; j++)
      {
         if ((crc & CRC_MASK) != 0U)
         {
            crc = (uint8_t)((crc << 1) ^ POLY);
         }
         else
         {
            crc <<= 1;
         }
      }
   }
   return crc;
}
/*****************************************************************************
 *. Name: I2c_Write_Data
 *.    This function will act as master and Transmit data to given slave device
 *.
 *. Parameters: slave_address - slave device address
 *.              reg_address - register address of slave device
 *.              *datatx - Data to be transfered
 *.              data_size - Size of the data
 *.              operation_pending - 0 (Start Stop), 1 (Start REPEAT) refer IR-1829
 *.              LT3398 PMIC ADI recommends read with START_REPEAT instead of STOP
 *. Return Value:I2c_StatusType
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
I2c_StatusType I2c_Write_Data(uint32_t slave_address, uint8_t reg_address, const uint8_t *datatx, uint32_t data_size,
                              boolean operation_pending)
{
#ifndef UNIT_TEST
   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
   I2c_Polling_Stats.i2c_write_executed_count++;
   #endif
   /* Parameter validation - allow data_size=0 for register-only transmission (used in reads) */
   if (((NULL == datatx) && (data_size != 0U)) || (data_size > (I2C_MAX_BUFFER_SIZE - I2C_SLAVE_REGISTER_COUNT)))
   {
      return I2C_STATUS_IDLE;
   }

   /* Build transmit buffer: [reg_address][data...] */
   uint8_t buf[I2C_MAX_BUFFER_SIZE] = {0U}; /* Initialize entire buffer to 0 */
   buf[0]                           = reg_address;
   for (uint8_t i = 0U; i < data_size; i++)
   {
      buf[i + 1U] = datatx[i];
   }

   I2c_StatusType status_operation = {I2C_STATUS_IDLE};
   status_operation                = I2c_GetStatus();
   /* Allow new transfer for all terminal states (IDLE, COMPLETED, ADDRESS_NACK, TRANSFER_FAILURE,
    * ARBITRATION_LOST). The SIP driver clears i2c->status.busy on any of these, so MasterTransmit
    * is safe. Only block when a transfer is actually in-flight (BUSY or PENDING). */
   if ((I2C_STATUS_BUSY != status_operation) && (I2C_STATUS_PENDING != status_operation))
   {
      /* Initiate I2C transmit (setup only, does not start HW transfer) */
      (void)I2c_MasterTransmit(slave_address, buf, (uint8_t)(data_size + I2C_SLAVE_REGISTER_COUNT), operation_pending);
   }
   else
   {
   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
      I2c_Polling_Stats.i2c_write_skip_count++;
   #endif
   }
   #if (I2C_TRANSFER_MODE == I2C_POLLING_MODE)
   /* Poll for transfer completion */
   status_operation = I2C_Polling();
   #else
   Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Wait for I2C transfer to complete */
   status_operation = I2c_GetStatus();
   #endif
   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
   if (status_operation != I2C_STATUS_COMPLETED)
   {
      I2c_Polling_Stats.i2c_write_fail_count++;
   }
   #endif

   #if I2C_ABRT_CLEAR_TODO /* TODO: disable this for now. discuss if Driver handles it. Impacts clearing PMIC_MCU_Comm_Fault */
   static uint8_t retry_attempt = 0U; /* Static: persists across calls to track consecutive failures */

   /* I2C abort status register */
   volatile uint32_t *ic_tx_abrt_source_reg = (volatile uint32_t *)IC_TX_ABRT_SOURCE_ADDR;
   volatile uint32_t *ic_clr_tx_abrt_reg    = (volatile uint32_t *)IC_CLR_TX_ABRT_ADDR;
   volatile uint32_t *ic_enable_reg         = (volatile uint32_t *)IC_ENABLE_ADDR;
   uint32_t abrt_source                     = 0U;

   /* Check for I2C NACK: read abort source and clear it */
   abrt_source = *ic_tx_abrt_source_reg;
   (void)(*ic_clr_tx_abrt_reg); /* Clear by reading */

   /* Check if frame was NACK'd (address or data) or ACK'd (register == 0) */
   if (((abrt_source & ABRT_7B_ADDR_NOACK_BIT) != 0U) || ((abrt_source & ABRT_TXDATA_NOACK_BIT) != 0U))
   {
      retry_attempt++;
      /* I2C bus recovery: disable and re-enable peripheral before retry */
      *ic_enable_reg = I2C_DISABLE;          /* Disable I2C */
      Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Allow bus to settle */
      *ic_enable_reg = I2C_ENABLE;           /* Re-enable I2C */
      Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Allow peripheral to stabilize */
   }
   else
   {
      /* Transfer ACK'd successfully - reset counter */
      retry_attempt       = 0U;
      PMIC_MCU_Comm_Fault = CODED_FALSE; /* Clear global flag for comms failure */
   }

   /* Check if consecutive failure threshold reached */
   if (retry_attempt >= I2C_RETRY_COUNT)
   {
      PMIC_MCU_Comm_Fault = CODED_TRUE; /* Set global flag for comms failure */
   }
   #endif /* I2C_ABRT_CLEAR_TODO */

   return status_operation;
#else
   /* UNIT_TEST mode: return success to allow mocked I2C functions to control behavior */
   return I2C_STATUS_COMPLETED;
#endif /* UNIT_TEST */
}

/*****************************************************************************
 *. Name: I2c_Read_Data
 *.    This function reads data from PMIC slave device and verifies PEC
 *.
 *. Parameters: slave_address - slave device address
 *.              reg_address - register address of slave device
 *.              *datarx - Data buffer to receive data
 *.              data_size - Size of data (including PEC byte if LT3398)
 *.
 *. Return Value: I2c_StatusType
 *.
 *. Shared Variables: PMIC_MCU_Comm_Fault
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
I2c_StatusType I2c_Read_Data(uint32_t slave_address, uint8_t reg_address, uint8_t *datarx, uint32_t data_size)
{
   static uint8_t rx_shadow[I2C_MAX_BUFFER_SIZE];
#if (I2C_POLLING_DEBUG_ENABLE == 1U)
   I2c_Polling_Stats.i2c_read_executed_count++;
#endif
   /* Parameter validation */
   if ((NULL == datarx) || (0U == data_size) || (data_size > I2C_MAX_BUFFER_SIZE))
   {
      return I2C_STATUS_IDLE;
   }

   I2c_StatusType status_operation = {I2C_STATUS_IDLE};

   /* Step 1: Send register address using I2c_Write_Data (reuses NACK detection + retry) */
   /* LT3398 PMIC ADI recommends read with START_REPEAT instead of STOP, Refer IR-1829 for details */
   (void)I2c_Write_Data(slave_address, reg_address, NULL, 0U, I2C_OP_PENDING_TRUE_CMD_REPEATSTART);

   /* Step 2: Receive data from slave (data + PEC byte) */
   status_operation = I2c_GetStatus();
   /* Same gate logic as I2c_Write_Data: only block if transfer is in-flight (BUSY/PENDING). */
   if ((I2C_STATUS_BUSY != status_operation) && (I2C_STATUS_PENDING != status_operation))
   {
      (void)I2c_MasterReceive(slave_address, rx_shadow, data_size, I2C_OP_PENDING_FALSE_CMD_STOP);
   }
   else
   {
#if (I2C_POLLING_DEBUG_ENABLE == 1U)
      I2c_Polling_Stats.i2c_read_skip_count++;
#endif
   }

#if (I2C_TRANSFER_MODE == I2C_POLLING_MODE)
   status_operation = I2C_Polling();
#else
   Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Wait for I2C transfer to complete */
   status_operation = I2c_GetStatus();
#endif
#if (I2C_POLLING_DEBUG_ENABLE == 1U)
   if (status_operation != I2C_STATUS_COMPLETED)
   {
      I2c_Polling_Stats.i2c_read_fail_count++;
   }
#endif

   if ((I2C_STATUS_COMPLETED == status_operation))
   {
      (void)memcpy(datarx, rx_shadow, data_size);
      /* Step 3: Verify PEC if data_size >= 2 (data + PEC byte) */
      Verify_Crc_Result(slave_address, reg_address, datarx, (uint8_t)data_size, datarx[data_size - 1U]);
   }

   return status_operation;
}

#if (I2C_TRANSFER_MODE == I2C_POLLING_MODE)
/*****************************************************************************
 *. Name: I2C_Polling_Status
 *.     I2C polling function to wait for I2C transfer completion with timeout and optional debug statistics
 *.
 *. Parameters: None
 *.
 *. Return Value: I2c_StatusType - I2C_STATUS_COMPLETED on success, timeout otherwise
 *.
 *. Shared Variables:
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static I2c_StatusType I2C_Polling(void)
{
   I2c_StatusType status_operation = {I2C_STATUS_IDLE};

   uint64 start_time_us = 0ULL;
   uint32_t elapsed_us  = 0U;

   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */

   /* Poll until completion or timeout (250us) */
   do
   {
      I2c_MainFunction();
      status_operation = I2c_GetStatus();

      if (I2C_STATUS_COMPLETED == status_operation)
      {
         break; /* Success - exit early */
      }
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);

   } while (elapsed_us < I2C_RUNTIME_DELAY_US);

   #if (I2C_POLLING_DEBUG_ENABLE == 1U)

   /* Count ALL operations (success + failures) */
   I2c_Polling_Stats.sample_count++;

   if (I2C_STATUS_COMPLETED != status_operation)
   {
      I2c_Polling_Stats.failure_count++;

      if (I2C_STATUS_PENDING == status_operation)
      {
         I2c_Polling_Stats.i2c_fail_status_pend_count++;
      }
      else if (I2C_STATUS_BUSY == status_operation)
      {
         I2c_Polling_Stats.i2c_fail_status_busy_count++;
      }
      else if (I2C_STATUS_ADDRESS_NACK == status_operation)
      {
         I2c_Polling_Stats.i2c_fail_status_busy_addr_NACK++;
      }
   }
   else
   {
      /* Success case */
      if (elapsed_us < I2c_Polling_Stats.min_time_us)
      {
         I2c_Polling_Stats.min_time_us = elapsed_us;
      }
      if (elapsed_us > I2c_Polling_Stats.max_time_us)
      {
         I2c_Polling_Stats.max_time_us = elapsed_us;
      }
      I2c_Polling_Stats.history[I2c_Polling_Stats.history_index] = elapsed_us;
      I2c_Polling_Stats.history_index = (I2c_Polling_Stats.history_index + 1U) % I2C_POLLING_HISTORY_SIZE;
   }
   #endif /* I2C_POLLING_DEBUG_ENABLE */

   return status_operation;
}
#endif

#ifndef UNIT_TEST
/*****************************************************************************
 *. Name: Pmic_I2c_JobEndNotification
 *.    I2C job-end callback registered in I2c_PBcfg. Called from ISR context by the
 *.    MCAL I2C driver on every transfer outcome (success or failure).
 *.    Sets PMIC_MCU_Comm_Fault immediately on any error event.
 *.
 *. Parameters: event - I2C_EVENT_TRANSFER_COMPLETED, I2C_EVENT_ADDRESS_NACK,
 *.                      I2C_EVENT_TRANSFER_FAILED, or I2C_EVENT_ARBITRATION_LOST
 *.                      (I2C_Event_t from I2c_Types.h)
 *.
 *. Return Value: void
 *.
 *. Shared Variables: PMIC_MCU_Comm_Fault
 *.
 ******************************************************************************/
void Pmic_I2c_JobEndNotification(I2c_StatusType event)
{
   static uint8_t retry_attempt = 0U;

   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
   I2c_Polling_Stats.i2c_cb_total_count++;
   #endif

   if (I2C_STATUS_COMPLETED != event)
   {
      retry_attempt++;

   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
      I2c_Polling_Stats.i2c_cb_consecutive_fail_count = retry_attempt;

      if (I2C_STATUS_ADDRESS_NACK == event)
      {
         I2c_Polling_Stats.i2c_cb_nack_count++;
      }
      else if (I2C_STATUS_TRANSFER_FAILURE == event)
      {
         I2c_Polling_Stats.i2c_cb_transfer_fail_count++;
      }
      else if (I2C_STATUS_ARBITRATION_LOST == event)
      {
         I2c_Polling_Stats.i2c_cb_arb_lost_count++;
      }
      else
      {
         /* Do nothing */
      }
   #endif

      if (retry_attempt >= I2C_RETRY_COUNT)
      {
         PMIC_MCU_Comm_Fault = CODED_TRUE;
      }
   }
   else
   {
      retry_attempt = 0U;

   #if (I2C_POLLING_DEBUG_ENABLE == 1U)
      I2c_Polling_Stats.i2c_cb_success_count++;
      I2c_Polling_Stats.i2c_cb_consecutive_fail_count = 0U;
   #endif
   }
}
#endif /* UNIT_TEST */
/*****************************************************************************
 *. Name: Verify_Crc_Result
 *.    This function verifies the CRC (PEC) of the received I2C data
 *.
 *. Parameters: slave_address - slave device address
 *.             reg_address - register address of slave device
 *.             data - Pointer to the received data buffer
 *.             len - Length of the received data (including PEC byte)
 *.             received_crc - Received CRC (PEC) byte
 *.              operation_pending - 0 (Start Stop), 1 (Start REPEAT) refer IR-1829
 *.              LT3398 PMIC ADI recommends read with START_REPEAT instead of STOP
 *.              to ensure register pointer is  protected when register is sent on Write command.
 *.              With REPEAT START LT3398 PEC CRC is calcualted on 4 bytes for 1 register read:
 *.              [S, slave_addr Write, Reg Address, Sr,  slave_addr Read, <data>, <PEC>, P].
 *. Return Value: None
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static void Verify_Crc_Result(uint32_t slave_address, uint8_t reg_address, const uint8_t *data, uint8_t len, uint8_t received_crc)
{
   if (len >= 2U) /* Ensure data_size is sufficient to include PEC byte (min: 1 data byte + 1 PEC) */
   {
      /* For LT3398: With Repeat Start, PEC calculated for all bytes from First Start to Stop */
      uint8_t pec_input[I2C_MAX_BUFFER_SIZE] = {0U};
      pec_input[0] = (uint8_t)(((uint8_t)(slave_address << 1)) | (I2C_RW_BIT_WRITE)); /* 0xD2 = (0x69 << 1) | 0x00 / Write */
      pec_input[1] = reg_address;
      pec_input[2] = (uint8_t)(((uint8_t)(slave_address << 1)) | (I2C_RW_BIT_READ)); /* 0xD3 = (0x69 << 1) | 0x01 / Read */

      /* Copy received data bytes (excluding last PEC byte) */
      uint8_t data_byte_count = (uint8_t)(len - 1U);
      for (uint8_t i = 0U; i < data_byte_count; i++)
      {
         pec_input[(I2C_CRC_OFFSET_FOR_DATA) + i] = data[i];
      }

      /* Calculate expected PEC */
      uint8_t expected_crc = Calc_Crc_8(&pec_input[0], (uint8_t)(I2C_CRC_OFFSET_FOR_DATA + data_byte_count));

      if (expected_crc != received_crc)
      {
#if (I2C_POLLING_DEBUG_ENABLE == 1U)
         /* Capture debug information when CRC mismatch occurs (last 10 occurrences) */
         Crc_Mismatch_Debug.pmic_data_byte[Crc_Mismatch_Debug.history_index] = data[0];      /* First data byte from PMIC */
         Crc_Mismatch_Debug.calculated_crc[Crc_Mismatch_Debug.history_index] = expected_crc; /* CRC calculated by MCU */
         Crc_Mismatch_Debug.received_crc[Crc_Mismatch_Debug.history_index]   = received_crc; /* CRC received from PMIC */
         Crc_Mismatch_Debug.mismatch_count++;                                                /* Increment mismatch counter */
         Crc_Mismatch_Debug.history_index = (Crc_Mismatch_Debug.history_index + 1U) % CRC_MISMATCH_HISTORY_SIZE;
#endif
         PMIC_MCU_Comm_Fault = CODED_TRUE; /* PEC mismatch - data corruption */
      }

#if (TRUE == ENABLE_SQT_TEST_STUBS)
      if (pmic_mcu_comm_fault_test_stub == 1)
      {
         PMIC_MCU_Comm_Fault = CODED_TRUE;
      }
      else if (pmic_mcu_comm_fault_test_stub == 2)
      {
         PMIC_MCU_Comm_Fault = CODED_FALSE;
      }
#endif
      /* else: PEC matches - keep current PMIC_MCU_Comm_Fault value (don't clear fault flag) */
   }
   /* else: No PEC verification for single byte reads - keep current PMIC_MCU_Comm_Fault value */
}

/*===========================================================================*\
 * FUNCTION: Pmic_Check_Wdg_Dis_Status
 *===========================================================================
 * RETURN VALUE:
 *    uint8_t
 *
 * PARAMETERS:
 *    NONE
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * --------------------------------------------------------------------------
 *This function periodically check watchdog disable status
\*===========================================================================*/
uint8_t Pmic_Check_Wdg_Dis_Status(void)
{
   uint8_t result       = CODED_FALSE;
   uint8_t rd_buffer[2] = {0xFFU, 0xFFU};
   if (WD_Service_Status != WD_SERVICE_DISABLE)
   {
      I2c_Read_Data(PMIC_ADDRESS, WD_STATUS_REG_ADDRESS, rd_buffer, NUM_ELEMS(rd_buffer));
      rd_buffer[0] = (uint8_t)(rd_buffer[0] & WD_DIS_STATUS_MASK);

      if (rd_buffer[0])
      {
         Watchdog_Dis_Count++;
      }
      else
      {
         Watchdog_Dis_Count = 0;
      }
      if (Watchdog_Dis_Count > WD_DIS_COUNTER_THRESHOLD)
      {
         /*Do not remove this line. its needed to prevent Watchdog_Dis_Count from overflowing and return to '0 */
         Watchdog_Dis_Count = WD_DIS_COUNTER_THRESHOLD;
         result             = CODED_TRUE;
      }
   }
   return result;
}

/*****************************************************************************
 *. Name: Delay_in_us_GPT
 *.    Provides delay in microseconds using platform timer
 *.
 *. Parameters: delay_us - delay needed in microseconds
 *.
 *. Return Value: void
 *.
 *. Design Information:
 *.    Uses Get_Platform_ustime and Get_Platform_Elapsed_ustime for precise delays.
 *.
 *.
 ******************************************************************************/
static void Delay_in_us_GPT(uint32_t delay_us)
{
#ifndef UNIT_TEST
   uint64 start_time_us = 0ULL;
   uint32_t elapsed_us  = 0U;

   #if (TRUE == XCP_FAULT_INJECTION)
   if (Retention_Ram_Data.fhti_test_data.failure_name == MCU_STARTUP_FAULT)
   {
      return;
   }
   #endif

   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */

   /* Poll until target delay reached */
   do
   {
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < delay_us);
#endif
}

#if (PMIC_SPREAD_SPECTRUM_ENABLE == FEATURE_ENABLED)
/*****************************************************************************
 *. Name: Pmic_spread_spectrum_Enable
 *.  This function enables pmic LT3398A / AD / to enable spread spectrum
 *.  Writes I2C device 0x69, Reg address 0x0C, Bit2 ENSS to 1 to enable.
 *. Parameters: void
 *.
 *. Return Value:bool
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
__attribute__((optnone)) bool Pmic_Spread_Spectrum_Enable(void)
{
   uint8_t write_buffer_pcfg[2]     = {0x00, 0x57}; /*0x00 - disable all protection , 0x57 - Precalculated PEC value*/
   uint8_t write_buffer_enss[2]     = {0x00, 0x00};
   uint8_t crc_write_buffer_enss[3] = {0xD2, 0x0C, 0x00};
   uint8_t prot_read_buffer[2]      = {0XFF}; /*0xFF - Invalid value*/
   uint8_t cfg_read_buffer[2]       = {0xFF}; /*0xFF - Invalid value*/

   (void)I2c_Write_Data(PMIC_ADDRESS, PMIC_GEN_PROT_REG_ADDR, write_buffer_pcfg, NUM_ELEMS(write_buffer_pcfg),
                        I2C_OP_PENDING_FALSE_CMD_STOP);
   /*Read PROT register address 0x20*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_PROT_REG_ADDR, prot_read_buffer, NUM_ELEMS(prot_read_buffer));
   /*Read CONFIG register address 0xC0*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, cfg_read_buffer, NUM_ELEMS(cfg_read_buffer));
   /*Write to CONFIG(0xC0) make sense only if PROT register(0x20) is unset*/

   crc_write_buffer_enss[2] = cfg_read_buffer[0] | (PMIC_GEN_CONFIG_ENSS_EN << 2);
   write_buffer_enss[0]     = crc_write_buffer_enss[2];
   write_buffer_enss[1]     = Calc_Crc_8(&crc_write_buffer_enss[0], NUM_ELEMS(crc_write_buffer_enss));

   (void)I2c_Write_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, write_buffer_enss, NUM_ELEMS(write_buffer_enss),
                        I2C_OP_PENDING_FALSE_CMD_STOP);
   Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Allow PMIC to apply config before readback */
   cfg_read_buffer[0] = 0x00;             /*making it to invalid value before we read actual data  from PMIC.*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, cfg_read_buffer, NUM_ELEMS(cfg_read_buffer));

   if ((cfg_read_buffer[0] & (PMIC_GEN_CONFIG_ENSS_EN << 2)) == (PMIC_GEN_CONFIG_ENSS_EN << 2))
   {
      enss_enable_result = PMIC_ENSS_SUCCESS;
   }
   else
   {
      enss_enable_result = PMIC_ENSS_FAIL;
   }
   return enss_enable_result;
}
#endif /* PMIC_SPREAD_SPECTRUM_ENABLE */

/*****************************************************************************
 *. Name: Pmic_spread_spectrum_Disable
 *.  This function Disables pmic LT3398A / AD / to disable spread spectrum explicitly
 *.  Writes I2C device 0x69, Reg address 0x0C, Bit2 ENSS to 0 to disable.
 *. Parameters: void
 *.
 *. Return Value:bool
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
__attribute__((optnone)) bool Pmic_Spread_Spectrum_Disable(void)
{
   uint8_t write_buffer_pcfg[2]     = {0x00, 0x57}; /*0x00 - disable all protection , 0x57 - Precalculated PEC value*/
   uint8_t write_buffer_enss[2]     = {0x00, 0x00};
   uint8_t crc_write_buffer_enss[3] = {0xD2, 0x0C, 0x00};
   uint8_t prot_read_buffer[2]      = {0xFF}; /*0xFF - Invalid value*/
   uint8_t cfg_read_buffer[2]       = {0xFF};

   (void)I2c_Write_Data(PMIC_ADDRESS, PMIC_GEN_PROT_REG_ADDR, write_buffer_pcfg, NUM_ELEMS(write_buffer_pcfg),
                        I2C_OP_PENDING_FALSE_CMD_STOP);
   /*Read PROT register address 0x20*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_PROT_REG_ADDR, prot_read_buffer, NUM_ELEMS(prot_read_buffer));
   /*Read CONFIG register address 0xC0*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, cfg_read_buffer, NUM_ELEMS(cfg_read_buffer));
   /*Write to CONFIG(0xC0) make sense only if PROT register(0x20) is unset*/

   crc_write_buffer_enss[2] = cfg_read_buffer[0] & ~(PMIC_GEN_CONFIG_ENSS_EN << 2);
   write_buffer_enss[0]     = crc_write_buffer_enss[2];
   write_buffer_enss[1]     = Calc_Crc_8(&crc_write_buffer_enss[0], NUM_ELEMS(crc_write_buffer_enss));

   (void)I2c_Write_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, write_buffer_enss, NUM_ELEMS(write_buffer_enss),
                        I2C_OP_PENDING_FALSE_CMD_STOP);
   Delay_in_us_GPT(I2C_RUNTIME_DELAY_US); /* Allow PMIC to apply config before readback */
   cfg_read_buffer[0] = 0xFF;             /*making it to invalid value before we read actual data  from PMIC.*/
   (void)I2c_Read_Data(PMIC_ADDRESS, PMIC_GEN_CONFIG_REG_ADDR, cfg_read_buffer, NUM_ELEMS(cfg_read_buffer));

   if ((cfg_read_buffer[0] & (PMIC_GEN_CONFIG_ENSS_EN << 2)) == 0)
   {
      enss_disable_result = PMIC_ENSS_SUCCESS;
   }
   else
   {
      enss_disable_result = PMIC_ENSS_FAIL;
   }
   return enss_disable_result;
}

/*****************************************************************************
 *. Name: Get_Pmic_Enss_Status
 *.  This function retrieves the current status of the PMIC ENSS (spread spectrum) enable and disable results.
 *. Parameters: *enable, *disable - pointers to store the enable and disable results
 *.
 *. Return Value:bool
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Get_Pmic_Enss_Status(uint8_t *enable, uint8_t *disable)
{
   *enable  = (uint8_t)enss_enable_result;
   *disable = (uint8_t)enss_disable_result;
}
#ifndef UNIT_TEST
   /*****************************************************************************
    *. Name: Pmic_Fault_Injection_XCP
    *.  This function is used to inject faults in PMIC communication for testing purposes.
    *.
    *. Return Value: None
    *.
    *. Shared Variables: None.
    *.
    *. Design Information:
    *.    (xxx is version no.)
    *.
    *. SCR Information:
    *.
    *.
    ******************************************************************************/
   #if (STD_ON == XCP_FAULT_INJECTION)
void Pmic_Fault_Injection_XCP(uint8 Inj_ctrl)
{
   Pmic_Fault_Injection_Data_T Pmic_Fault_Injection_Data;
   Pmic_Fault_Injection_Data.slave_addr = 0x69;
   Pmic_Fault_Injection_Data.reg_addr   = 0x07;
   uint8_t addr_0x07_default_val = 0x05; /*writing 1 to register 0x07 will give back 0x05 -> for reference read LT3398 documnet*/
   if (MCU_PMIC_CRC_FAIL == Inj_ctrl)
   {
      Pmic_Fault_Injection_Data.datatx[0]  = 0x01;
      Pmic_Fault_Injection_Data.datatx[1]  = 0x96; /*Injecting CRC error by changing the last byte of datatx*/
      Pmic_Fault_Injection_Data.Data_Rx[0] = 0;
      Pmic_Fault_Injection_Data.Data_Rx[1] = 0;
      (void)I2c_Write_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                           Pmic_Fault_Injection_Data.datatx, 2, I2C_OP_PENDING_FALSE_CMD_STOP);
      (void)I2c_Read_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                          Pmic_Fault_Injection_Data.Data_Rx, 2);
      if (Pmic_Fault_Injection_Data.Data_Rx[0] != addr_0x07_default_val)
      {
         PMIC_MCU_Comm_Fault = CODED_TRUE;
      }
   }
   else if (PMIC_MCU_CRC_FAIL == Inj_ctrl)
   {
      Pmic_Fault_Injection_Data.datatx[0]  = 0x01;
      Pmic_Fault_Injection_Data.datatx[1]  = 0x95;
      Pmic_Fault_Injection_Data.Data_Rx[0] = 0;
      Pmic_Fault_Injection_Data.Data_Rx[1] = 0;
      (void)I2c_Write_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                           Pmic_Fault_Injection_Data.datatx, 2, I2C_OP_PENDING_FALSE_CMD_STOP);
      (void)I2c_Read_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                          Pmic_Fault_Injection_Data.Data_Rx, 2);
      Pmic_Fault_Injection_Data.Data_Rx[1] =
         0xFF; /*No way for PMIC to send wrong CRC , we need to simlulate this test case by manually modifying received CRC*/
      if (Pmic_Fault_Injection_Data.Data_Rx[0] == addr_0x07_default_val && Pmic_Fault_Injection_Data.Data_Rx[1] == 0xFF)
      {
         PMIC_MCU_Comm_Fault = CODED_TRUE;
      }
   }
   /*We can actually corrupt status register because it is read only, reset occurs by changing any other I2C register
   that triggeres status register , even sending wrong slave address we cannot trigger the actual fault because every 30ms external
   watchdog is triggering that would modify the bus status quikly before we read here , so instead of real scenarion
   just simulating the test case*/
   else if (CORRUPT_STS_REG == Inj_ctrl)
   {
      I2c_StatusType status_operation_test = {I2C_STATUS_IDLE};
      Pmic_Fault_Injection_Data.datatx[0]  = 0x01;
      Pmic_Fault_Injection_Data.datatx[1]  = 0x95;
      Pmic_Fault_Injection_Data.Data_Rx[0] = 0;
      Pmic_Fault_Injection_Data.Data_Rx[1] = 0;
      Pmic_Fault_Injection_Data.slave_addr =
         0xFF; /*write to invalid address so that sts register will automatically corrupt , since it is read only cant modify it*/
      (void)I2c_Write_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                           Pmic_Fault_Injection_Data.datatx, 2, I2C_OP_PENDING_FALSE_CMD_STOP);
      (void)I2c_Read_Data(Pmic_Fault_Injection_Data.slave_addr, Pmic_Fault_Injection_Data.reg_addr,
                          Pmic_Fault_Injection_Data.Data_Rx, 2);
      status_operation_test = I2c_GetStatus();
      status_operation_test =
         I2C_STATUS_ADDRESS_NACK; /*Simulating the status register corruption by manually modifying the status register value*/
      if (status_operation_test != I2C_STATUS_COMPLETED)
      {
         PMIC_MCU_Comm_Fault = CODED_TRUE;
      }
   }
   else if (REMOVE_FAULT_INJECTION == Inj_ctrl)
   {
      PMIC_MCU_Comm_Fault = CODED_FALSE;
   }
   else
   {
      /*do nothing*/
   }
}
   #endif
#endif
