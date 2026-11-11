#ifndef DD_PMIC_H
#define DD_PMIC_H

/*===========================================================================*\
 * FILE: dd_pmic.h
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
 *   This file contains the header files for PMIC functions.
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
#include "I2c.h"
#include "I2c_Types.h"
#include "reuse.h"
/*===========================================================================*
 * Exported Preprocessor defined Constants
 *===========================================================================*/

#define FEATURE_ENABLED  (1U)
#define FEATURE_DISABLED (0U)

#define PMIC_CLK_SYNC_ENABLE FEATURE_DISABLED
#define PMIC_WATCHDOG_ENABLE FEATURE_ENABLED /* Disable to test on ADC unit */

#define PMIC_SPREAD_SPECTRUM_ENABLE FEATURE_DISABLED
#define ENABLE_WDT_TEST             FEATURE_DISABLED

#define WD_SERVICE_DISABLE  CODED_TRUE
#define WD_SERVICE_ENABLE   (0U) /* Any value other than 0xA5A5A5A5 */
#define WD_SERVICE_INTERVAL (2U) /* 1 equals 50ms */

#define PMIC_ADDRESS                   (0x69U)
#define PMIC_ADDRESS_WRITE             (0xD2U)
#define PMIC_ADDRESS_READ              (0xD3U)
#define WD_MIN_PERIOD_REGISTER_ADDRESS (0x15U)
#define WD_MAX_PERIOD_REGISTER_ADDRESS (0x16U)
#define WD_Q_REGISTER_ADDRESS          (0x17U)
#define WD_A_REGISTER_ADDRESS          (0x18U)
#define WD_1_TICK_MS                   (16U)
#define WD_MIN_PERIOD_MS               (16U)
#define WD_MAX_PERIOD_MS               (496U)

#define PGMAP_REG_ADDR   (0x0DU)
#define FCMAP_REG_ADDR   (0x0FU)
#define PDMAP_REG_ADDR   (0x10U)
#define PROT_REG_ADDR    (0x20U)
#define FAULTB_REG_ADDR  (0x0EU)
#define STATUS2_REG_ADDR (0x02U)
#define STATUS1_REG_ADDR (0x01U)

#define PROT_REG_MASK    (0x01U)
#define PGMAP_REG_MASK   (0x40U)
#define FCMAP_REG_MASK   (0x04U)
#define PDMAP_REG_MASK   (0x04U)
#define FAULTB_REG_MASK  (0x40U)
#define STATUS2_REG_MASK (0x79U)
#define STATUS1_REG_MASK (0x3FU)

#define PMIC_ENSS_SUCCESS 1
#define PMIC_ENSS_FAIL    0

#define ONE_BYTE 1
typedef enum WdtTestCmd_Tag
{
   WDT_TEST_NONE = 0U,
   WDT_DISABLE_TEST,
   WDT_ENABLE_TEST,
   WDT_RESET_TEST,
} WdtTestCmd_T;

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
bool Pmic_Clk_Sync_Enable(void);
I2c_StatusType I2c_Write_Data(uint32_t slave_address, uint8_t reg_address, const uint8_t *datatx, uint32_t data_size,
                              boolean operation_pending);
I2c_StatusType I2c_Read_Data(uint32_t slave_address, uint8_t reg_address, uint8_t *datarx, uint32_t data_size);
void Pmic_Watchdog_Service(void);
#if (PMIC_WATCHDOG_ENABLE == FEATURE_ENABLED)
void Pmic_Watchdog_Init(void);
#endif /* PMIC_WATCHDOG_ENABLE */
uint8_t Pmic_Check_Wdg_Dis_Status(void);
bool Pmic_Spread_Spectrum_Enable(void);
bool Pmic_Spread_Spectrum_Disable(void);
void Get_Pmic_Enss_Status(uint8_t *enable, uint8_t *disable);
#if (STD_ON == XCP_FAULT_INJECTION)
void Pmic_Fault_Injection_XCP(uint8 Inj_ctrl);
#endif
/*===========================================================================*
 * Exported Variables
 *===========================================================================*/
extern volatile uint8_t PMIC_MCU_Comm_Fault;

#endif /* DD_PMIC_H */
