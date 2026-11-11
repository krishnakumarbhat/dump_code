#ifndef SWC_PLT_APPL_IOHWAB_CFG_H
#define SWC_PLT_APPL_IOHWAB_CFG_H
/*===========================================================================*\
 * FILE: SWC_PLT_Appl_IoHwAb_Cfg.h
 *===========================================================================
 * Copyright (C) 2020 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the configuration settings for the Hardware Analog to Digital Converters.
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
 *     SW REF 264.15D "Delphi C Coding Standards" [12-Mar-2006]
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
#include "Std_Types.h"
#include "board_revision.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

#ifndef ADC_ON
   #define ADC_ON 1u
#endif

#ifndef ADC_OFF
   #define ADC_OFF 0u
#endif

#define Gen8_IoHw_Disable
#define ENABLE_POS_GND_A_ADC ADC_ON
#define ENABLE_POS_GND_B_ADC ADC_ON
#define ENABLE_POS_GND_C_ADC ADC_ON
#define ENABLE_POS_GND_D_ADC ADC_ON
#define ENABLE_RDI_DETECT    ADC_ON
#define ENABLE_TEMP_ADC      ADC_ON
#define ENABLE_Eth_0V9       ADC_ON
#define ENABLE_ADC_IGN       ADC_ON
/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define ADC_VREF       ((float32)1.8)
#define ADC_BITS       ((uint16)12)
#define ADC_NUM_COUNTS ((uint16)0x01 << ADC_BITS)

#define ADC_COUNTS_TO_VOLTS (float32)(ADC_VREF / (float32_t)ADC_NUM_COUNTS)

#define HW_24V_CV_VARIANT                                                                                                         \
   ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||                                     \
    (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))

#define SCALE_FACTOR_BY_BOARD_REV(HW_24V_board_val, legacy_boards_val)                                                            \
   ((HW_24V_CV_VARIANT) ? (HW_24V_board_val) : (legacy_boards_val))

#define BATT_SCALE_FACTOR                                                                                                         \
   SCALE_FACTOR_BY_BOARD_REV((float32)(ADC_COUNTS_TO_VOLTS / (0.0303f)), (float32)(ADC_COUNTS_TO_VOLTS / (0.0396f)))

#define POSGND_CONVERSION_CONSTANT                                                                                                \
   SCALE_FACTOR_BY_BOARD_REV((float32)(ADC_COUNTS_TO_VOLTS / (0.02924f)), (float32)(ADC_COUNTS_TO_VOLTS / (0.038f)))

#define BATT_I_SENSE_SCALE_FACTOR                                                                                                 \
   SCALE_FACTOR_BY_BOARD_REV((float32)(ADC_COUNTS_TO_VOLTS / (1.0f)), (float32)(ADC_COUNTS_TO_VOLTS / (50.0f)))

#define ETH_0V9_SCALE_FACTOR        ((float32)(ADC_COUNTS_TO_VOLTS / (1.0f)))
#define RDI_DETECT_SCALE_FACTOR     ((float32)(ADC_COUNTS_TO_VOLTS / (1.0f)))
#define ADC_TEMP_SCALE_FACTOR       ((float32)(ADC_COUNTS_TO_VOLTS / (1.0f)))
#define IGN_SCALE_FACTOR            ((float32)(ADC_COUNTS_TO_VOLTS / (0.0303f)))
#define ENABLE_BATT_ADC             ADC_ON
#define Adc_Pos_Gnd_C_Temp          Adc_Pos_Gnd_C
#define Adc_Pos_GndD_Batt_ISense    Adc_Pos_Gnd_D
#define IOHWAB_ANALOG_CHANNEL_COUNT (24u)
/* Gen8 Chandra has 2 PVT Process, Voltage, and Temperature (PVT) monitors */
#define IOHWAB_TMU_SENSOR_COUNT (2u)
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *  Date        Name   (Description on following lines: SCR #, etc.)
 * --------     -----   ---------------------------------------------
 * 14-April-25  Keerthi  Appl_IoHwAb Bringup
\*===========================================================================*/

#endif /* } SWC_PLT_APPL_IOHWAB_CFG_H */
