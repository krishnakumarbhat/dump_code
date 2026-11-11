/*===========================================================================*\
 * FILE: mipi_wrapper.c
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
 *   This file contains Mipi Wrapper functions to perform MIPI reset and other operations related to MIPI.
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
#include "mipi_wrapper.h"
#include "Driver_Port.h"
#include "I2c.h"
#include "I2c_Types.h"
#include "Port.h"
#include "SWC_PLT_Appl_PlatformTime_cfg.h"
#include "board_revision.h"
#include "dd_gpt.h"
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define MIPI_SUCCESS                  (1U)
#define MIPI_FAIL                     (0U)
#define I2C_OP_PENDING_FALSE_CMD_STOP (false)
#define I2C_TIMEOUT_US                (5000U)   /*Total poll window in us */
#define I2C_DELAY_MS                  (1U)      /* Polling interval in ms */
#define I2C_DELAY_US                  (500U)    /* Polling interval in us */
#define I2C_MAX_BUFFER_SIZE           (64U)     /*I2C Maximum buffer size */
#define DELAY_LOOP_COUNT_PER_MS       (0x4FFFU) /* Calibrated loop iterations for ~1ms delay */
#define MIPI_SLAVE_ADRS               (0x54U)   /*Mipi slave device address*/
#define MIPI_SLAVE_REG_ADRS           (0x00U)   /*Mipi slave register address*/
#define ASSERT_RESET_MIPI             (0x0U)    /*value to assert reset the Mipi*/
#define DEASSERT_RESET_MIPI           (0x1U)    /*value to deassert reset the Mipi*/
/*===========================================================================*\
 * External Type Declarations
\*===========================================================================*/
extern ARM_DRIVER_PORT Driver_Port0;

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/
static ARM_DRIVER_PORT *Port = &Driver_Port0;

/*===========================================================================*\
 * Local Variables
\*===========================================================================*/
#if (DEBUG_VARIABLES_ENABLED == (1U))
static Mipi_I2c_Debug_Counters_T Mipi_Debug_Counters = {0, 0, 0, 0, 0, 0};
#endif /* DEBUG_VARIABLES_ENABLED */

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/
#if (I2C_POLLING_MODE == I2C_TRANSFER_MODE)
static I2c_StatusType I2C_Polling(void);
#endif
static inline void Delay_in_us(uint32_t delay);
static void Configure_Port_Pins(void);
/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*****************************************************************************
 *. Name: Deassert_Reset_Mipi
 *.    This function will de-assert reset the MIPI Splitter
 *.
 *. Parameters: void
 *.
 *. Return Value: bool
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
bool Deassert_Reset_Mipi(void)
{
   bool mipi_reset_status          = MIPI_FAIL;
   uint8_t tx_wr_data[2]           = {MIPI_SLAVE_REG_ADRS, DEASSERT_RESET_MIPI};
   I2c_StatusType status_operation = {I2C_STATUS_IDLE};

   /*Check if RDI log board is connected or not, if connected only then proceed with MIPI reset deassertion*/
   Configure_Port_Pins();
   /* Write to MIPI slave to deassert reset */
   (void)I2c_MasterTransmit((uint32_t)MIPI_SLAVE_ADRS, tx_wr_data, sizeof(tx_wr_data), I2C_OP_PENDING_FALSE_CMD_STOP);
#if (I2C_POLLING_MODE == I2C_TRANSFER_MODE)
   /* Poll for transfer completion */
   status_operation = I2C_Polling();
#else
   Delay_in_us(I2C_DELAY_US);
   status_operation = I2c_GetStatus();
#endif
   if (status_operation != I2C_STATUS_COMPLETED)
   {
      COUNT_MIPI_RESET_FAILED();
      mipi_reset_status = MIPI_FAIL;
   }
   else
   {
      COUNT_MIPI_RESET_VERIFIED();
      mipi_reset_status = MIPI_SUCCESS;
   }
   return mipi_reset_status;
}

/*****************************************************************************
 *. Name: Assert_Reset_Mipi
 *.    This function will assert reset the MIPI Splitter
 *.
 *. Parameters: void
 *.
 *. Return Value: bool
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
bool Assert_Reset_Mipi(void)
{
   bool mipi_reset_status          = MIPI_FAIL;
   uint8_t tx_wr_data[2]           = {MIPI_SLAVE_REG_ADRS, ASSERT_RESET_MIPI};
   I2c_StatusType status_operation = {I2C_STATUS_IDLE};

   Configure_Port_Pins();
   /* Write assert-reset command to MIPI device */
   (void)I2c_MasterTransmit((uint32_t)MIPI_SLAVE_ADRS, tx_wr_data, sizeof(tx_wr_data), I2C_OP_PENDING_FALSE_CMD_STOP);
#if (I2C_POLLING_MODE == I2C_TRANSFER_MODE)
   /* Poll for transfer completion */
   status_operation = I2C_Polling();
#else
   Delay_in_us(I2C_DELAY_US);
   status_operation = I2c_GetStatus();
#endif
   if (status_operation != I2C_STATUS_COMPLETED)
   {
      COUNT_MIPI_RESET_FAILED();
      mipi_reset_status = MIPI_FAIL;
   }
   else
   {
      COUNT_MIPI_RESET_VERIFIED();
      mipi_reset_status = MIPI_SUCCESS;
   }
   return mipi_reset_status;
}

/******************************************************************************
 *. Name: Configure_Port_Pins
 *.    Configure Port Pins based on board revision.
 *.
 *. Parameters: void
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.
 ******************************************************************************/
static void Configure_Port_Pins(void)
{
   Board_Revision_T read_board_revision;

   read_board_revision = Get_Board_Revision();
   switch (read_board_revision)
   {
      case BOARD_REV_EDU:
         Port->SetMode(ARM_PORT_A1B6, ARM_PIN_MODE_DIO, ARM_PORT_CFG_INPUT);
         Port->SetMode(ARM_PORT_A1B7, ARM_PIN_MODE_DIO, ARM_PORT_CFG_INPUT);
         break;
      case BOARD_REV_A0:
         break;
      case BOARD_REV_A2P0:
      case BOARD_REV_A2P1:
         break;
      default:
         break;
   }
}
#if (I2C_POLLING_MODE == I2C_TRANSFER_MODE)
/*****************************************************************************
 *. Name: I2C_Polling
 *.    This function polls the I2C operation status until completion or timeout
 *.
 *. Parameters: None
 *.
 *. Return Value: I2c_StatusType - I2C_STATUS_COMPLETED on success, other value on timeout
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
static I2c_StatusType I2C_Polling(void)
{
   I2c_StatusType status_operation;
   uint32_t elapsed = 0U;
   do
   {
      I2c_MainFunction();
      status_operation = I2c_GetStatus();
      if (I2C_STATUS_COMPLETED == status_operation)
      {
         break;
      }
      Delay_in_us(I2C_DELAY_US);
      elapsed += I2C_DELAY_US;
   } while (elapsed < I2C_TIMEOUT_US);

   return status_operation;
}
#endif
/*****************************************************************************
 *. Name: Delay_in_ms
 *.    This function provides delay in ms using software busy-wait.
 *.
 *. Parameters: delay - needed in ms
 *.
 *. Return Value: void
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    Uses nested loops to create calibrated delay.
 *.    More efficient than modulo-based approach.
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
static inline void Delay_in_us(uint32_t delay)
{
#ifndef UNIT_TEST
   uint64 start_time_us = 0ULL;
   uint32_t elapsed_us  = 0U;

   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */

   /* Poll until target delay reached */
   do
   {
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < delay);
#endif
}
