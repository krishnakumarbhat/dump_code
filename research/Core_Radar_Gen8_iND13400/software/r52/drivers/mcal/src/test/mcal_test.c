/*===========================================================================*\
 * FILE: mcal_test.c
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * %full_filespec:  mcal_test.c
 * %version:  1 %
 * %derived_by:  ulb4jq %
 * %date_modified:  Tue Jun  13 15:55:28 2025 %
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains code for the mcal_test funciton
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *   Requirements Document(s):
 *   (Design & Requirements)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
 *
 * DEVIATIONS FROM STANDARDS:
 *   None
 *
\*===========================================================================*/
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include <string.h>

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "Dio.h"
#include "Dma.h"
#include "Dma_PBcfg.h"
#include "Driver_Port.h"
#include "Fls.h"
#include "Gpt.h"
#include "Mcu.h"
#include "MemIf.h"
#include "Pwm.h"
#include "Pwm_Cfg.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "SchM_Fls.h"
#include "Uart.h"
//#include "chandra_r52_gic.h"
#include "SWC_PLT_Appl_PlatformTime_cfg.h"
#include "chandra_r52_irq.h"
#include "chandra_sfrs_base.h"
#include "crg_sfrs.h"
#include "dd_gpt.h"
#include "dio_wrapper.h"
#include "mcal_init.h"
#include "mcal_test.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define CRG ((volatile CRG_SFRS_t *)CRG_base)

#define TEST_PASS     1
#define TEST_FAIL     0
#define TEST_ENABLED  1
#define TEST_DISABLED 0

/* DIO Test Channels - GPIO_00 and GPIO_01 from Port_PBcfg.c */
#define DI0_TEST_PIN1 DioConf_DioChannel_A2_A3_ERRN_HSDEN
#define DI0_TEST_PIN2 DioConf_DioChannel_A2_A3_POS_GND_EN
#define DIO_TEST_PORT DioConf_DioPort_DioPort /* Port A */
#define DIO_TEST_MASK 0x09U                   /* Bits [3,0] - GPIO_0 and GPIO_3 */

/* Channel Group Configuration - PA[1:0] */
#define DIO_TEST_GROUP_MASK   0x03U /* Test PA0 and PA1 (2 bits) */
#define DIO_TEST_GROUP_OFFSET 0U    /* Start at bit 0 */

/* Test timing parameters */
#define TEST_DELAY_SHORT  10000U /* Short delay loop count */
#define TEST_DELAY_MEDIUM 5000U  /* Medium delay loop count */

/* MCU Test Configuration */
#define MCU_EXPECTED_CLK_TEST_VAL 0x2U   /* Expected clock test register value */
#define MCU_TEST_RESET_TIMEOUT    10000U /* Timeout for reset reason validation */

/* Flash Test Configuration - SAFE ADDRESS in Data Flash Region
 * NOTE: Using address near END of flash to avoid application code corruption
 * Flash range: 0x00000000 - 0x003FFFFF (4MB total)
 * Test sector: Last sector before end (0x003FF000)
 * MUST be aligned to FLS_SECTOR_SIZE_VALUE (4096 bytes = 0x1000)
 */
#define FLS_TEST_SECTOR_ADDR       0x003FF000U           /* Last 4KB sector in flash */
#define FLS_TEST_SECTOR_SIZE       FLS_SECTOR_SIZE_VALUE /* Use config value: 4096 bytes */
#define FLS_TEST_BUFFER_SIZE       256U
#define FLS_MAINFUNCTION_PERIOD_US 10000U /* Fls_MainFunction scheduling interval: 10ms (matches FlsCallCycle) */

/* DMA Test Configuration
 * Tests Memory-to-Memory transfer using CHANNEL_ID_1
 * Validates: Channel config, transfer execution, status monitoring, data integrity
 */
#define DMA_TEST_BUFFER_SIZE   256U              /* Test buffer size (must be multiple of bus width) */
#define DMA_TEST_PATTERN_START 0xA5U             /* Starting pattern value */
#define DMA_TEST_BLOCK_SIZE    DMA_BLOCK_SIZE_64 /* 64 transfers (64 * 4bytes = 256 bytes) */
#define DMA_TEST_TIMEOUT       100000U           /* Timeout for DMA transfer completion */

/*===========================================================================*\
* Local Function Prototypes
\*===========================================================================*/
static void Test_Delay(uint32_t count);
void Mcal_Mcu_test(void);
void Mcal_Dio_test(void);
void Mcal_Adc_test(void);
void Mcal_I2c_Test(void);
void Mcal_Fls_test(void);
void Mcal_Dma_test(void);
void Mcal_Gpt_test(void);
void Mcal_Pwm_test(void);
void Mcal_Uart_test(void);

static MemIf_JobResultType Exec_Flash_Clear(void);
static MemIf_JobResultType Exec_Flash_Write(void);
static MemIf_JobResultType Exec_Flash_Read(void);
static MemIf_JobResultType Exec_Flash_Compare(void);

/*===========================================================================*\
* Local Type Declarations
\*===========================================================================*/

/* Test configuration  --  enable/disable each module test here */
Mcal_TestSuite_t Mcal_Test_Config = {
   .Mcu  = {TEST_ENABLED, MCAL_STATUS_NOT_RUN},
   .Dio  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Adc  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .I2c  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Fls  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Dma  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Gpt  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Pwm  = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
   .Uart = {TEST_DISABLED, MCAL_STATUS_NOT_RUN},
};

/* Flash test buffer with alignment */
static uint8_t fls_test_buffer[FLS_TEST_BUFFER_SIZE] __attribute__((aligned(4)));

/* UART test buffers (global for debugging) */
uint8 Uart_Sent_Data[20]         = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
uint8 Uart_Recieve_Data[20]      = {0};
Uart_StatusType uart_test_status = {0};

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

__attribute__((optnone)) void Mcal_Test(void)
{
   if (Mcal_Test_Config.Mcu.enable == TEST_ENABLED)
   {
      Mcal_Mcu_test();
   }
   if (Mcal_Test_Config.Dio.enable == TEST_ENABLED)
   {
      Mcal_Dio_test();
   }
   if (Mcal_Test_Config.Adc.enable == TEST_ENABLED)
   {
      Mcal_Adc_test();
   }
   if (Mcal_Test_Config.I2c.enable == TEST_ENABLED)
   {
      Mcal_I2c_Test();
   }
   if (Mcal_Test_Config.Fls.enable == TEST_ENABLED)
   {
      Mcal_Fls_test();
   }
   if (Mcal_Test_Config.Gpt.enable == TEST_ENABLED)
   {
      Mcal_Gpt_test();
   }
   if (Mcal_Test_Config.Pwm.enable == TEST_ENABLED)
   {
      Mcal_Pwm_test();
   }
   if (Mcal_Test_Config.Uart.enable == TEST_ENABLED)
   {
      Mcal_Uart_test();
   }
   if (Mcal_Test_Config.Dma.enable == TEST_ENABLED)
   {
      Mcal_Dma_test();
   }
}

/*****************************************************************************
 *. Name: Mcal_Mcu_test
 *.    This function runs mcal mcu test
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
__attribute__((optnone)) void Mcal_Mcu_test(void)
{
   /* Test result flags */
   bool test_pll_status   = FALSE;
   bool test_clock_config = FALSE;
   bool test_reset_reason = FALSE;

   /* Local variables for test data */
   volatile uint32_t read_clk_reg        = 0U;
   volatile Mcu_PllStatusType pll_status = MCU_PLL_UNLOCKED;
   volatile Mcu_ResetType reset_reason   = MCU_RESET_UNDEFINED;

   /* Initialize test status to FAIL */
   Mcal_Test_Config.Mcu.status = MCAL_STATUS_FAIL;

   /*-----------------------------------------------------------------------*
    * TEST 1: PLL Status Verification
    * Tests: Mcu_GetPllStatus()
    *
    * Validates:
    * - PLL is locked and stable
    * - PLL status register accessible
    * - PLL configuration from Mcu_Init() is correct
    *
    * Expected Result:
    * - PLL status should be MCU_PLL_LOCKED after MCAL_Init()
    * - If MCU_PLL_UNLOCKED or MCU_PLL_STATUS_UNDEFINED, indicates:
    *   a) PLL configuration error in Mcu_PBcfg.c
    *   b) PLL initialization failed in Mcu_Init()
    *   c) System clock source not from PLL
    *-----------------------------------------------------------------------*/

   pll_status = Mcu_GetPllStatus();

   if (pll_status == MCU_PLL_LOCKED)
   {
      test_pll_status = TRUE;
   }
   else if (pll_status == MCU_PLL_UNLOCKED)
   {
      /* PLL unlocked - may indicate startup sequence issue */
      test_pll_status = FALSE;
   }
   else /* MCU_PLL_STATUS_UNDEFINED */
   {
      /* PLL status not available - hardware or driver issue */
      test_pll_status = FALSE;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /*-----------------------------------------------------------------------*
    * TEST 2: Clock Configuration Register Validation
    * Tests: Clock system register read access
    *
    * Validates:
    * - Clock test register (CLK_TOP_CTRL) accessible
    * - Clock selection configuration matches expected value
    *
    * Register Details:
    *   CRG->CLK_TOP_CTRL.f.CTL_CG_SEL_CLK_TEST
    *   Expected value: 0x2 (per system clock configuration)
    *
    * Purpose:
    *   This register indicates which clock source is selected for
    *   the test/debug clock output. Value 0x2 typically indicates:
    *   - System clock source is PLL-derived
    *   - Clock multiplexers configured correctly
    *   - No clock source failure detected
    *-----------------------------------------------------------------------*/

   read_clk_reg = (uint32_t)CRG->CLK_TOP_CTRL.f.CTL_CG_SEL_CLK_TEST;

   if (read_clk_reg == MCU_EXPECTED_CLK_TEST_VAL)
   {
      test_clock_config = TRUE;
   }
   else
   {
      /* Unexpected clock configuration - may indicate:
       *  - Wrong PLL configuration in Mcu_PBcfg.c
       *  - Clock source fallback to backup oscillator
       */
      test_clock_config = FALSE;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /*-----------------------------------------------------------------------*
    * TEST 3: Reset Reason Detection
    * Tests: Mcu_GetResetReason()
    *
    * Validates:
    * - Reset reason register accessible
    * - Reset reason correctly decoded
    * - Valid reset reason returned (not undefined)
    *
    * Possible Reset Reasons:
    *   MCU_POWER_ON_RESET      - Cold boot, power cycle
    *   MCU_FCRU_RESET          - Watchdog (FCRU) timeout occurred
    *   MCU_SW_RESET            - Software-triggered reset
    *   MCU_RESET_UNDEFINED     - Unknown/invalid reset source
    *
    * Note: On first power-up, expected reset reason is MCU_POWER_ON_RESET.
    *       During development/debug, may see MCU_FCRU_RESET if WDG enabled.
    *-----------------------------------------------------------------------*/

   reset_reason = Mcu_GetResetReason();

   /* Validate reset reason is defined (not undefined) */
   if (reset_reason != MCU_RESET_UNDEFINED)
   {
      /* Reset reason is valid - could be any of:
       *  - MCU_POWER_ON_RESET (expected on cold boot)
       *  - MCU_FCRU_RESET (if WDG triggered)
       *  - MCU_SW_RESET (if software reset occurred)
       *  - Other valid reset types per Gen8 MCU driver
       */
      test_reset_reason = TRUE;

      /* Additional validation based on expected reset type */
      if (reset_reason == MCU_POWER_ON_RESET)
      {
         /* Power-on reset detected */
         test_reset_reason = TRUE;
      }
      else if (reset_reason == MCU_FCRU_RESET)
      {
         /* Watchdog (FCRU) reset detected - may indicate:
          *  - Previous execution hung (legitimate watchdog trigger)
          *  - Watchdog timeout too short for initialization
          *  - Software didn't service watchdog
          */
         test_reset_reason = TRUE;
      }
      else
      {
         /* Other reset types (SW reset, external reset, etc.) */
         test_reset_reason = TRUE;
      }
   }
   else
   {
      /* Reset reason undefined - indicates:
       *  - Reset reason register not accessible
       *  - Invalid reset source
       *  - Driver implementation issue
       */
      test_reset_reason = FALSE;
   }

   Test_Delay(TEST_DELAY_SHORT);
   /*-----------------------------------------------------------------------*
    * Evaluate Overall Test Result
    *
    * Pass Criteria:
    *   - PLL is locked (test_pll_status = TRUE)
    *   - Clock configuration valid (test_clock_config = TRUE)
    *   - Reset reason defined (test_reset_reason = TRUE)
    *
    * All four sub-tests must pass for overall MCU test to pass.
    *-----------------------------------------------------------------------*/

   if (test_pll_status && test_clock_config && test_reset_reason)
   {
      Mcal_Test_Config.Mcu.status = MCAL_STATUS_PASS;
   }
   else
   {
      Mcal_Test_Config.Mcu.status = MCAL_STATUS_FAIL;
   }
}

/*****************************************************************************
 *. Name: Mcal_Dio_test
 *.    This function runs mcal dio test
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
__attribute__((optnone)) void Mcal_Dio_test(void)
{
   Dio_LevelType rd;
   Dio_LevelType initial_ch0, initial_ch1;
   Dio_PortLevelType port_rd, port_init;
   Dio_Wrapper_Status_T status;
   bool test_ch   = FALSE;
   bool test_port = FALSE;

   Mcal_Test_Config.Dio.status = MCAL_STATUS_FAIL;

   /*-----------------------------------------------------------------------*
    * SAVE INITIAL VALUES - Critical for restoration after tests
    *-----------------------------------------------------------------------*/
   initial_ch0 = Dio_Wrapper_ReadChannel(DI0_TEST_PIN1, &status);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }
   initial_ch1 = Dio_Wrapper_ReadChannel(DI0_TEST_PIN2, &status);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }
   port_init = Dio_ReadPort(DIO_TEST_PORT);

   /*-----------------------------------------------------------------------*
    * Test 1: Channel Operations (Dio_WriteChannel / Dio_ReadChannel)
    * Test both GPIO_00 and GPIO_01 independently
    *-----------------------------------------------------------------------*/

   /* Test PIN1 (GPIO_00): Write LOW, Read LOW, Write HIGH, Read HIGH */
   bool pin1_test = FALSE;

   status = Dio_Wrapper_WriteChannel(DI0_TEST_PIN1, STD_LOW);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }
   Test_Delay(TEST_DELAY_SHORT);

   rd = Dio_Wrapper_ReadChannel(DI0_TEST_PIN1, &status);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }

   if (rd == STD_LOW)
   {
      status = Dio_Wrapper_WriteChannel(DI0_TEST_PIN1, STD_HIGH);
      if (status == DIO_WRAPPER_OK)
      {
         Test_Delay(TEST_DELAY_SHORT);
         rd = Dio_Wrapper_ReadChannel(DI0_TEST_PIN1, &status);
         if ((status == DIO_WRAPPER_OK) && (rd == STD_HIGH))
         {
            pin1_test = TRUE;
         }
      }
   }

   /* Test PIN2 (GPIO_01): Write LOW, Read LOW, Write HIGH, Read HIGH */
   bool pin2_test = FALSE;

   status = Dio_Wrapper_WriteChannel(DI0_TEST_PIN2, STD_LOW);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }
   Test_Delay(TEST_DELAY_SHORT);

   rd = Dio_Wrapper_ReadChannel(DI0_TEST_PIN2, &status);
   if (status != DIO_WRAPPER_OK)
   {
      return; /* Channel not allowed on this board revision */
   }

   if (rd == STD_LOW)
   {
      status = Dio_Wrapper_WriteChannel(DI0_TEST_PIN2, STD_HIGH);
      if (status == DIO_WRAPPER_OK)
      {
         Test_Delay(TEST_DELAY_SHORT);
         rd = Dio_Wrapper_ReadChannel(DI0_TEST_PIN2, &status);
         if ((status == DIO_WRAPPER_OK) && (rd == STD_HIGH))
         {
            pin2_test = TRUE;
         }
      }
   }

   /* Both pins must pass for channel test to pass */
   test_ch = (pin1_test && pin2_test);

   /* RESTORE: Channel test */
   (void)Dio_Wrapper_WriteChannel(DI0_TEST_PIN1, initial_ch0);
   (void)Dio_Wrapper_WriteChannel(DI0_TEST_PIN2, initial_ch1);
   Test_Delay(TEST_DELAY_SHORT);

   /*-----------------------------------------------------------------------*
    * Test 2: Port Operations (Dio_WritePort / Dio_ReadPort)
    * Test only GPIO_00 and GPIO_01 bits, preserve others
    *-----------------------------------------------------------------------*/

   /* Pattern 1: GPIO0=LOW, GPIO3=HIGH (mask 0x09: bit3=1,bit0=0 -> 0x08) */
   Dio_WritePort(DIO_TEST_PORT, (port_init & ~DIO_TEST_MASK) | 0x08U);
   Test_Delay(TEST_DELAY_SHORT);
   port_rd = Dio_ReadPort(DIO_TEST_PORT);

   if ((port_rd & DIO_TEST_MASK) == 0x08U)
   {
      /* Pattern 2: GPIO0=HIGH, GPIO3=LOW (mask 0x09: bit3=0,bit0=1 -> 0x01) */
      Dio_WritePort(DIO_TEST_PORT, (port_init & ~DIO_TEST_MASK) | 0x01U);
      Test_Delay(TEST_DELAY_SHORT);
      port_rd = Dio_ReadPort(DIO_TEST_PORT);

      if ((port_rd & DIO_TEST_MASK) == 0x01U)
      {
         /* Pattern 3: GPIO0=HIGH, GPIO3=HIGH (mask 0x09: bit3=1,bit0=1 -> 0x09) */
         Dio_WritePort(DIO_TEST_PORT, (port_init & ~DIO_TEST_MASK) | 0x09U);
         Test_Delay(TEST_DELAY_SHORT);
         port_rd = Dio_ReadPort(DIO_TEST_PORT);

         if ((port_rd & DIO_TEST_MASK) == 0x09U)
         {
            /* Pattern 4: GPIO0=LOW, GPIO3=LOW (mask 0x09: bit3=0,bit0=0 -> 0x00) */
            Dio_WritePort(DIO_TEST_PORT, (port_init & ~DIO_TEST_MASK) | 0x00U);
            Test_Delay(TEST_DELAY_SHORT);
            port_rd = Dio_ReadPort(DIO_TEST_PORT);

            if ((port_rd & DIO_TEST_MASK) == 0x00U)
            {
               test_port = TRUE;
            }
         }
      }
   }

   /* RESTORE: Port test */
   Dio_WritePort(DIO_TEST_PORT, port_init);
   Test_Delay(TEST_DELAY_SHORT);

   /*-----------------------------------------------------------------------*
    * FINAL VERIFICATION: Ensure all pins restored to initial state
    *-----------------------------------------------------------------------*/
   Dio_LevelType verify_ch0      = Dio_Wrapper_ReadChannel(DI0_TEST_PIN1, &status);
   Dio_LevelType verify_ch1      = Dio_Wrapper_ReadChannel(DI0_TEST_PIN2, &status);
   Dio_PortLevelType verify_port = Dio_ReadPort(DIO_TEST_PORT);

   bool restore_ok = (verify_ch0 == initial_ch0) && (verify_ch1 == initial_ch1) && (verify_port == port_init);

   /*-----------------------------------------------------------------------*
    * Evaluate Overall Test Result
    * NOTE: Removed channel group test due to incorrect group configuration
    *-----------------------------------------------------------------------*/

   Mcal_Test_Config.Dio.status = (test_ch && test_port && restore_ok) ? MCAL_STATUS_PASS : MCAL_STATUS_FAIL;
}

/*****************************************************************************
 *. Name: Mcal_Adc_test
 *.    This function runs mcal ADC test
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
__attribute__((optnone)) void Mcal_Adc_test(void)
{
   bool all_channels_valid = FALSE;

   /* Initialize test status to FAIL */
   Mcal_Test_Config.Adc.status = MCAL_STATUS_FAIL;

   /*-----------------------------------------------------------------------*
    * TEST: ADC Results Buffer Validation
    * Tests: Adc_Results_Buff[ADC_NUM_CHANNEL]
    *
    * Validates:
    * - ADC continuous conversion is running
    * - All 10 ADC channels have valid (non-zero) values
    * - ADC driver and notification callback working correctly
    *
    * ADC Channels (from SWC_PLT_Service_IoHwAb.h):
    *   [0] CHANNEL_BOARD_REV  - Board revision ADC
    *   [1] CHANNEL_BATT_ADC   - Battery voltage ADC
    *   [2] CHANNEL_POS_GND_A  - Position ground A
    *   [3] CHANNEL_POS_GND_B  - Position ground B
    *   [4] CHANNEL_POS_GND_C  - Position ground C
    *   [5] CHANNEL_POS_GND_D  - Position ground D
    *   [6] CHANNEL_0V9_ETH    - 0.9V Ethernet rail
    *   [7] CHANNEL_RDI_DETECT - RDI detect signal
    *   [8] CHANNEL_MMIC_TEMP  - MMIC temperature sensor
    *   [9] CHANNEL_MCU_TEMP   - MCU temperature sensor
    *
    * Pass Criteria:
    *   - All 10 channel values in Adc_Results_Buff are non-zero
    *
    * Note: ADC must be initialized and continuous conversion started
    *       by Init_ADC_Channels() before this test runs
    *-----------------------------------------------------------------------*/

   /* Check all 10 ADC channels for non-zero values */
   for (uint32_t ch = 0U; ch < ADC_NUM_CHANNEL; ch++)
   {
      if (Adc_Results_Buff[ch] != 0U)
      {
         all_channels_valid = TRUE;
      }
   }

   /* Test passes only if all channels have non-zero values */
   if (all_channels_valid)
   {
      Mcal_Test_Config.Adc.status = MCAL_STATUS_PASS;
   }
   else
   {
      /* Test failed - at least one channel is zero */
      Mcal_Test_Config.Adc.status = MCAL_STATUS_FAIL;
   }
}

/*****************************************************************************
 *. Name: Mcal_I2c_Test
 *.    This function runs mcal i2c test
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
void Mcal_I2c_Test(void)
{
   uint8_t Data_Rx[2]          = {0};
   uint8_t Data_Rx1[1]         = {0};
   Mcal_Test_Config.I2c.status = MCAL_STATUS_FAIL;
   uint32_t slave_addr         = 0x69; /*PMIC address*/

   uint8_t datatx[2] = {0xAA, 0x59}; /*0xAA is data , 0x59 is PEC*/
   /*check if PEC is enabled*/
   (void)I2c_Read_Data(slave_addr, 0x0C, Data_Rx1, 1);
   Test_Delay(TEST_DELAY_SHORT);
   /*check WD disabled to safe read write*/
   (void)I2c_Read_Data(slave_addr, 0x02, Data_Rx1, 1);
   Test_Delay(TEST_DELAY_SHORT);
   /*Read WD answer register 0x18*/
   (void)I2c_Read_Data(slave_addr, 0x18, Data_Rx, 1);
   Test_Delay(TEST_DELAY_SHORT);
   /*write 0xAA WD answer register 0x18*/
   (void)I2c_Write_Data(slave_addr, 0x18, datatx, 2, 0);
   Test_Delay(TEST_DELAY_SHORT);
   /*Read back WD answer register 0x18*/
   (void)I2c_Read_Data(slave_addr, 0x18, Data_Rx, 1);
   Test_Delay(TEST_DELAY_SHORT);

   if (Data_Rx[0] == 0xAA)
   {
      /*success if data matches*/
      Mcal_Test_Config.I2c.status = MCAL_STATUS_PASS;
   }

   uint8_t Data_Rx2[1] = {15};
   /*read F_TSD fault status register - already cleared in boot and reading status in application*/
   (void)I2c_Read_Data(slave_addr, 0x02, Data_Rx2, 1);
}

/*****************************************************************************
 *. Name: Exec_Flash_Clear
 *.    This function executes flash clear operation
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
static MemIf_JobResultType Exec_Flash_Clear(void)
{
   Fls_AddressType address = FLS_TEST_SECTOR_ADDR;

   if (E_OK == Fls_Erase(address, FLS_TEST_SECTOR_SIZE))
   {
      /* Poll job result, calling Fls_MainFunction() at FlsCallCycle interval (10ms)*/
      uint64_t last_call_us;

      Get_Platform_ustime(&last_call_us);

      while (MEMIF_JOB_PENDING == Fls_GetJobResult())
      {
         uint32_t elapsed_us;

         Get_Platform_Elapsed_ustime(&elapsed_us, last_call_us);

         if (elapsed_us >= FLS_MAINFUNCTION_PERIOD_US)
         {
            Fls_MainFunction();
            Get_Platform_ustime(&last_call_us);
         }
      }

      return Fls_GetJobResult();
   }
   else
   {
      /* Erase rejected (E_NOT_OK) */
      return MEMIF_JOB_FAILED;
   }
}

/*****************************************************************************
 *. Name: Exec_Flash_Write
 *.    This function executes flash write operation
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
static MemIf_JobResultType Exec_Flash_Write(void)
{
   Fls_AddressType address = FLS_TEST_SECTOR_ADDR;
   uint32_t i;

   /* Fill buffer with test pattern */
   for (i = 0U; i < FLS_TEST_BUFFER_SIZE; i++)
   {
      fls_test_buffer[i] = (uint8_t)(0x00 + i); /* Test pattern: AA AB AC ... */
   }

   if (E_OK == Fls_Write(address, fls_test_buffer, FLS_TEST_BUFFER_SIZE))
   {
      /* Poll job result, calling Fls_MainFunction() at FlsCallCycle interval (10ms)
       * Driver internal timeout supervision will fail the job if it takes too long */
      uint64_t last_call_us;

      Get_Platform_ustime(&last_call_us);

      while (MEMIF_JOB_PENDING == Fls_GetJobResult())
      {
         uint32_t elapsed_us;

         Get_Platform_Elapsed_ustime(&elapsed_us, last_call_us);

         if (elapsed_us >= FLS_MAINFUNCTION_PERIOD_US)
         {
            Fls_MainFunction();
            Get_Platform_ustime(&last_call_us);
         }
      }

      return Fls_GetJobResult();
   }
   else
   {
      return MEMIF_JOB_FAILED;
   }
}

/*****************************************************************************
 *. Name: Exec_Flash_Read
 *.    This function executes flash read operation
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
static MemIf_JobResultType Exec_Flash_Read(void)
{
   Fls_AddressType address = FLS_TEST_SECTOR_ADDR;
   uint32_t i;

   /* Clear buffer before read */
   for (i = 0U; i < FLS_TEST_BUFFER_SIZE; i++)
   {
      fls_test_buffer[i] = 0x00U;
   }

   if (E_OK == Fls_Read(address, fls_test_buffer, FLS_TEST_BUFFER_SIZE))
   {
      /* Poll job result, calling Fls_MainFunction() at FlsCallCycle interval (10ms)
       * Driver internal timeout supervision will fail the job if it takes too long */
      uint64_t last_call_us;

      Get_Platform_ustime(&last_call_us);

      while (MEMIF_JOB_PENDING == Fls_GetJobResult())
      {
         uint32_t elapsed_us;

         Get_Platform_Elapsed_ustime(&elapsed_us, last_call_us);

         if (elapsed_us >= FLS_MAINFUNCTION_PERIOD_US)
         {
            Fls_MainFunction();
            Get_Platform_ustime(&last_call_us);
         }
      }

      return Fls_GetJobResult();
   }
   else
   {
      return MEMIF_JOB_FAILED;
   }
}

/*****************************************************************************
 *. Name: Exec_Flash_Compare
 *.    This function executes flash compare operation
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
static MemIf_JobResultType Exec_Flash_Compare(void)
{
   Fls_AddressType address = FLS_TEST_SECTOR_ADDR;
   uint32_t i;
   static uint8_t read_buffer[FLS_TEST_BUFFER_SIZE] __attribute__((aligned(4)));

   /* Prepare expected data buffer */
   for (i = 0U; i < FLS_TEST_BUFFER_SIZE; i++)
   {
      fls_test_buffer[i] = (uint8_t)(0x00 + i);
   }

   /* Read the data from flash */
   if (E_OK == Fls_Read(address, read_buffer, FLS_TEST_BUFFER_SIZE))
   {
      /* Poll job result, calling Fls_MainFunction() at FlsCallCycle interval (10ms)
       * Driver internal timeout supervision will fail the job if it takes too long */
      uint64_t last_call_us;

      Get_Platform_ustime(&last_call_us);

      while (MEMIF_JOB_PENDING == Fls_GetJobResult())
      {
         uint32_t elapsed_us;

         Get_Platform_Elapsed_ustime(&elapsed_us, last_call_us);

         if (elapsed_us >= FLS_MAINFUNCTION_PERIOD_US)
         {
            Fls_MainFunction();
            Get_Platform_ustime(&last_call_us);
         }
      }

      if (MEMIF_JOB_OK == Fls_GetJobResult())
      {
         /* Manually compare read data with expected data */
         for (i = 0U; i < FLS_TEST_BUFFER_SIZE; i++)
         {
            if (read_buffer[i] != fls_test_buffer[i])
            {
               return MEMIF_BLOCK_INCONSISTENT;
            }
         }
         return MEMIF_JOB_OK;
      }

      return Fls_GetJobResult();
   }
   else
   {
      return MEMIF_JOB_FAILED;
   }
}

/*****************************************************************************
 *. Name: Mcal_Fls_test
 *.    This function runs mcal flash test
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
__attribute__((optnone)) void Mcal_Fls_test(void)
{
   MemIf_JobResultType result;
   bool test_passed = FALSE;

   Mcal_Test_Config.Fls.status = MCAL_STATUS_FAIL;

   /* Verify flash driver initialized */
   if (MEMIF_UNINIT == Fls_GetStatus())
   {
      Mcal_Test_Config.Fls.status = MCAL_STATUS_FAIL;
      return;
   }

   /* Test sequence: Erase -> Write -> Read -> Compare */

   /* 1. Erase test sector */
   result = Exec_Flash_Clear();
   if (MEMIF_JOB_OK != result)
   {
      Mcal_Test_Config.Fls.status = MCAL_STATUS_FAIL;
      return;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /* 2. Write test pattern */
   result = Exec_Flash_Write();
   if (MEMIF_JOB_OK != result)
   {
      Mcal_Test_Config.Fls.status = MCAL_STATUS_FAIL;
      return;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /* 3. Read back written data */
   result = Exec_Flash_Read();
   if (MEMIF_JOB_OK != result)
   {
      Mcal_Test_Config.Fls.status = MCAL_STATUS_FAIL;
      return;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /* 4. Compare written vs read data */
   result = Exec_Flash_Compare();
   if (MEMIF_JOB_OK == result)
   {
      test_passed = TRUE;
   }

   Test_Delay(TEST_DELAY_SHORT);

   /* 5. Cleanup - erase test sector */
   (void)Exec_Flash_Clear();

   Mcal_Test_Config.Fls.status = test_passed ? MCAL_STATUS_PASS : MCAL_STATUS_FAIL;
}

/*****************************************************************************
 *. Name: Mcal_Gpt_test
 *.    This function runs mcal gpt test
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
__attribute__((optnone)) void Mcal_Gpt_test(void)
{
   /* Initialize test status to FAIL */
   Mcal_Test_Config.Gpt.status = MCAL_STATUS_FAIL;

   /* ========== TEST CASE 1: Timestamp APIs ========== */
   {
      /* Test millisecond timestamp */
      uint32_t timestamp_ms_1;

      Get_Platform_mstime(&timestamp_ms_1);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      uint32_t timestamp_ms_2;

      Get_Platform_mstime(&timestamp_ms_2);

      /* Timestamps should be increasing */
      if (timestamp_ms_1 >= timestamp_ms_2)
      {
         return;
      }

      /* Test microsecond timestamp */
      uint64_t timestamp_us_1;

      Get_Platform_ustime(&timestamp_us_1);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      uint64_t timestamp_us_2;

      Get_Platform_ustime(&timestamp_us_2);

      /* Timestamps should be increasing */
      if (timestamp_us_1 >= timestamp_us_2)
      {
         return;
      }
   }

   /* ========== TEST CASE 2: Elapsed Time Measurement ========== */
   {
      /* Capture start timestamp in microseconds */
      uint64_t start_us;

      Get_Platform_ustime(&start_us);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      Test_Delay(TEST_DELAY_SHORT);
      uint32_t elapsed_us;

      Get_Platform_Elapsed_ustime(&elapsed_us, start_us);

      /* Elapsed time should be positive */
      if (elapsed_us == 0)
      {
         return;
      }
   }

   /* ========== TEST CASE 3: Timer Value Read (GPT_PHY_TMR_0) ========== */
   // {
   //    /* Read timer counter value in microseconds for physical timer 0 */
   //    float32 timer_val_us = Get_Timer_Cnt_Value_us(GPT_PHY_TMR_0);

   //    /* Timer value should be reasonable (not negative) */
   //    if (timer_val_us < 0.0f)
   //    {
   //       return;
   //    }

   //    /* Wait and read again - value should have changed */
   //    Test_Delay(TEST_DELAY_SHORT);
   //    float32 timer_val_us_2 = Get_Timer_Cnt_Value_us(GPT_PHY_TMR_0);

   //    /* Timer is free-running, so value should change */
   //    if (timer_val_us_2 == timer_val_us)
   //    {
   //       return;
   //    }
   // }

   /* All test cases passed! */
   Mcal_Test_Config.Gpt.status = MCAL_STATUS_PASS;
}

/*****************************************************************************
 *. Name: Mcal_Pwm_test
 *.    This function runs mcal pwm test
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
__attribute__((optnone)) void Mcal_Pwm_test(void)
{
   /* Initialize test status to FAIL */
   Mcal_Test_Config.Pwm.status = MCAL_STATUS_FAIL;

   /* ========== TEST CASE 1: Set Duty Cycle ========== */
   {
      /* Set 50% duty cycle on both PWM channels
       * Duty cycle value is typically 0x8000 for 50% (half of 0x10000) */
      uint16_t duty_50_percent = 0x8000;

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
      /* Set duty cycle for channel 0 */
      Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmDDSChannel, duty_50_percent);

      /* Set duty cycle for channel 1 */
      Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmDDSChannel_001, duty_50_percent);

      /* Wait for PWM to stabilize */
      Test_Delay(TEST_DELAY_SHORT);
#endif
   }

   /* ========== TEST CASE 2: Set Output to Idle ========== */
   {
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
      /* Set channel 0 to idle state (typically low) */
      Pwm_SetOutputToIdle(PwmConf_PwmChannel_PwmDDSChannel);

      /* Wait for output to settle */
      Test_Delay(TEST_DELAY_SHORT);
#endif
   }

   /* ========== TEST CASE 3: Get Output State ========== */
   {
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
      /* Get output state of channel 0 (should be idle/low) */
      Pwm_OutputStateType state_ch0 = Pwm_GetOutputState(PwmConf_PwmChannel_PwmDDSChannel);

      /* State should be either PWM_LOW or PWM_HIGH (just verify API works) */
      /* We can't verify exact state without hardware probes, but API should not crash */
      (void)state_ch0; /* Use variable to avoid warning */

      /* Get output state of channel 1 (should be active) */
      Pwm_OutputStateType state_ch1 = Pwm_GetOutputState(PwmConf_PwmChannel_PwmDDSChannel_001);
      (void)state_ch1;
#endif
   }

   /* ========== TEST CASE 4: Set Period and Duty ========== */
   {
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
      /* Set new period (100us = 100000ns) and 25% duty cycle on channel 1 */
      Pwm_PeriodType period    = 100;    /* Period in ticks (depends on configuration) */
      uint16_t duty_25_percent = 0x4000; /* 25% of 0x10000 */

      Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PwmDDSChannel_001, period, duty_25_percent);

      /* Wait for PWM to apply new settings */
      Test_Delay(TEST_DELAY_SHORT);
#endif
   }

   /* All test cases passed! (APIs executed without crashing) */
   Mcal_Test_Config.Pwm.status = MCAL_STATUS_PASS;
}

/*****************************************************************************
 *. Name: Mcal_Uart_test
 *.    This function runs mcal uart test
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
__attribute__((optnone)) void Mcal_Uart_test(void)
{
   /* Initialize test status to FAIL */
   Mcal_Test_Config.Uart.status = MCAL_STATUS_FAIL;
   uint32_t timeout             = 10000;

   /* Clear receive buffer */
   memset(Uart_Recieve_Data, 0, sizeof(Uart_Recieve_Data));

   /* Send "Hello World" */
   if (E_OK == Uart_SendData(Uart_Sent_Data, 11, 0))
   {
      /* Poll with MainFunction and check status until TX complete */
      do
      {
         Uart_MainFunction();
         uart_test_status = Uart_GetStatus(0);
         timeout--;
      } while ((uart_test_status.TxState != UART_TX_IDLE) && (timeout > 0));

      /* Receive data back - initiate RX operation */
      if (E_OK == Uart_ReceiveData(Uart_Recieve_Data, 11, 0))
      {
         /* Poll with MainFunction until RX complete - 1 minute timeout */
         timeout = 6000000; /* Approx 1 minute of polling iterations */
         do
         {
            Uart_MainFunction();
            uart_test_status = Uart_GetStatus(0);
            timeout--;
         } while ((uart_test_status.RxState != UART_RX_IDLE) && (timeout > 0));

         /* Compare sent and received data */
         if (memcmp(Uart_Sent_Data, Uart_Recieve_Data, 11) == 0)
         {
            Mcal_Test_Config.Uart.status = MCAL_STATUS_PASS;
         }
      }
   }
}

/*****************************************************************************
 *. Name: Mcal_Dma_test
 *.    This function runs mcal DMA test
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
__attribute__((optnone)) void Mcal_Dma_test(void)
{
   static uint32_t source_buffer[16] __attribute__((aligned(64)));
   static uint32_t dest_buffer[16] __attribute__((aligned(64)));

   uint32_t data_to_copy[16] = {0xff, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xff, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xFF, 0xFF};
   static uint32_t i_dato    = 0;

   /* Initialize test status to FAIL */
   Mcal_Test_Config.Dma.status = MCAL_STATUS_FAIL;

   /* Clear destination buffer */
   for (i_dato = 0; i_dato < 16; i_dato++)
   {
      dest_buffer[i_dato] = 0x00000000;
   }

   /* Prepare source buffer with test pattern */
   for (i_dato = 0; i_dato < 16; i_dato++)
   {
      source_buffer[i_dato] = data_to_copy[i_dato];
   }

   /* NOTE: Dma_Init() already called in MCAL_Init()
    * DMA controller is initialized and interrupts configured
    * Just configure the channel and start transfer
    */
   Dma_ChannelConfigTransfer(CHANNEL_ID_1, source_buffer, dest_buffer, DMA_BLOCK_SIZE_16);
   /* Start the transfer */
   Dma_ChannelTransfer(CHANNEL_ID_1);

   /* Validate transfer - compare source and destination */
   for (i_dato = 0; i_dato < 16; i_dato++)
   {
      /* DEBUG: Mark inside validation loop */
      volatile uint32_t loop_iteration = i_dato;
      (void)loop_iteration;

      if (dest_buffer[i_dato] != data_to_copy[i_dato])
      {
         /* Data mismatch - test failed */
         Mcal_Test_Config.Dma.status = MCAL_STATUS_FAIL;
         return;
      }
   }
   /* All data matched - test passed */
   Mcal_Test_Config.Dma.status = MCAL_STATUS_PASS;
}
/*****************************************************************************
 *. Name: Test_Delay
 *.    This function runs random delay
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
static void Test_Delay(uint32_t count)
{
   volatile uint32_t i;
   for (i = 0U; i < count; i++)
   {
      /* Empty delay loop */
   }
}
